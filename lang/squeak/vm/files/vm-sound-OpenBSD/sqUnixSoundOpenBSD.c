/* sqUnixSoundOpenBSD.c -- sound support for OpenBSD
 *
 *   Copyright (C) 1996-2003 Ian Piumarta and other authors/contributors
 *     as listed elsewhere in this file.
 *   All rights reserved.
 *   
 *     You are NOT ALLOWED to distribute modified versions of this file
 *     under its original name.  If you want to modify it and then make
 *     your modifications available publicly, rename the file first.
 * 
 *   This file is part of Unix Squeak.
 * 
 *   This file is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *   
 *   You may use and/or distribute this file ONLY as part of Squeak, under
 *   the terms of the Squeak License as described in `LICENSE' in the base of
 *   this distribution, subject to the following additional restrictions:
 * 
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software.  If you use this software
 *      in a product, an acknowledgment to the original author(s) (and any
 *      other contributors mentioned herein) in the product documentation
 *      would be appreciated but is not required.
 * 
 *   2. You must not distribute (or make publicly available by any
 *      means) a modified copy of this file unless you first rename it.
 * 
 *   3. This notice must not be removed or altered in any source distribution.
 * 
 *   Using (or modifying this file for use) in any context other than Squeak
 *   changes these copyright conditions.  Read the file `COPYING' in the
 *   directory `platforms/unix/doc' before proceeding with any such use.
 *
 * Authors: Marc.Espie@OpenBSD.org, Ian.Piumarta@inria.fr and 
 *    Lex Spoon <lex@cc.gatech.edu>
 * 
 */

#include "sq.h"

#undef	DEBUG

#include "aio.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/audioio.h>
#include <errno.h>

#ifdef DEBUG
# define PRINTF(ARGS) printf ARGS
# define TRACE 1
#else
# define PRINTF(ARGS)
#endif

static int sound_Stop(void);

static int auFd=	       -1;   /* open on /dev/dsp */
static int fmtStereo=		0;   /* whether we are playing in stereo or not */
static int auPlaySemaIndex=	0;   /* an index to signal when new data may be played */
static int auBufBytes=		0;   /*  buffer size to use for playback.
					 unfortunately, this bears no relationship to
					 whatever the kernel and soundcard are using  */

static unsigned int hwbufSize;
static unsigned int threshold;
static unsigned long totalWritten = 0;

static int sound_AvailableSpace(void);

static void auHandle(int fd, void *data, int flags)
{
  if (auFd < 0) return;
  if (sound_AvailableSpace() > 0)
    signalSemaphoreWithIndex(auPlaySemaIndex);
  aioHandle(fd, auHandle, flags);
}


/*** exported sound output functions ***/


static int sound_Stop(void)
{
  if (auFd == -1) return;

  aioDisable(auFd);
  close(auFd);
  auFd= -1;
  totalWritten = 0;

  return 0;
}


static int sound_Start(int frameCount, int samplesPerSec, int stereo, int semaIndex)
{
  int bytesPerFrame=	(stereo ? 4 : 2);
  int bufferBytes=	((frameCount * bytesPerFrame) / 8) * 8;
  struct audio_info info;
  int err;
     
  if (auFd != -1) sound_Stop();
  auPlaySemaIndex= semaIndex;
  fmtStereo= stereo;
  auBufBytes= bytesPerFrame * frameCount;
  totalWritten = 0;

  if ((auFd= open("/dev/audio", O_WRONLY)) == -1)
    {
      perror("/dev/audio");
      return false;
    }
  AUDIO_INITINFO(&info);
  info.play.precision= 16;
  info.play.encoding = AUDIO_ENCODING_SLINEAR;
  info.play.channels= fmtStereo ? 2 : 1;
  info.play.sample_rate= samplesPerSec;
  if (ioctl(auFd, AUDIO_SETINFO, &info))
    {
      perror("AUDIO_SETINFO");
      goto closeAndFail;
    }
  if (ioctl(auFd, AUDIO_GETINFO, &info))
    {
      perror("AUDIO_GETINFO");
      goto closeAndFail;
    }
  hwbufSize = info.play.buffer_size;
  threshold = (hwbufSize * 3) / 4;

  aioEnable(auFd, 0, 0);
  aioHandle(auFd, auHandle, AIO_RX);


  return true;
  
 closeAndFail:
  close(auFd);
  auFd= -1;
  return false;
}


static int sound_AvailableSpace(void)
{
  struct audio_info info;
  unsigned long fill;

  if (auFd < 0) return 0;

  if (ioctl(auFd, AUDIO_GETINFO, &info))
    {
      perror("AUDIO_GETINFO");
      sound_Stop();
    }
  fill = totalWritten - info.play.samples;
  if (fill >= threshold)
    {
      return 0;
    }
  else
    {
      return threshold - fill;
    }
}


static int sound_PlaySamplesFromAtLength(int frameCount, int arrayIndex, int startIndex)
{
  short *src= (short *) (arrayIndex + 4*startIndex);
  short buf[2*frameCount];
  int i;
  int bytes;

  if (auFd < 0) return -1;

  if (fmtStereo)
    {
      bytes= 4 * frameCount;
      for (i= 0;  i < 2 * frameCount;  i++)
	buf[i]= src[i];
    }
  else
    {
      bytes= 2 * frameCount;
      for (i= 0;  i < frameCount;  i++)
	buf[i]= src[2*i];
    }
  /* write data to device from auBuf to dst */
  while (bytes > 0)
    {
      int len;
      char *pos= (char *) buf;
	  
      len= write(auFd, pos, bytes);
      if (len < 0)
	{
	  perror("/dev/audio");
	  return 0;
	}
      bytes -= len;
      pos += len;
      totalWritten += len;
    }
  
  return frameCount;
}


static int sound_InsertSamplesFromLeadTime(int frameCount, int srcBufPtr,
				  int samplesOfLeadTime)
{
  return 0;
}


static int sound_PlaySilence(void)
{
     return 0;
}


/** recording not supported **/
static int sound_SetRecordLevel(int level)
{
  success(false);
  return;
}


static int sound_StartRecording(int desiredSamplesPerSec, int stereo, int semaIndex)
{
  success(false);
  return;
}


static int sound_StopRecording(void)
{
  return;
}


static double sound_GetRecordingSampleRate(void)
{
  success(false);
  return 0.0;
}


static int sound_RecordSamplesIntoAtLength(int buf, int startSliceIndex, int bufferSizeInBytes)
{
  success(false);
  return 0;
}



static void sound_Volume(double *left, double *right)
{
  success(false);
  return;
}


static void sound_SetVolume(double left, double right)
{
  success(false);
  return;
}



#include "SqSound.h"

SqSoundDefine(OpenBSD);


#include "SqModule.h"

static void  sound_parseEnvironment(void) {}
static int   sound_parseArgument(int argc, char **argv) { return 0; }
static void  sound_printUsage(void) {}
static void  sound_printUsageNotes(void) {}
static void *sound_makeInterface(void) { return &sound_OpenBSD_itf; }

SqModuleDefine(sound, OpenBSD);
