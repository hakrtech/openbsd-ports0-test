/* Copyright (C) 1998 Joshua Sled
   This file is part of LibGTop 1.0.

   Contributed by Joshua Sled <jsled@xcf.berkeley.edu>, July 1998.

   LibGTop is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

   LibGTop is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with LibGTop; see the file COPYING. If not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>
#include <glibtop.h>
#include <glibtop/error.h>
#include <glibtop/procstate.h>

#include <glibtop_suid.h>

#if !defined(__OpenBSD__)
/* && (!defined __bsdi__) */
#include <sys/user.h>
#endif

static const unsigned long _glibtop_sysdeps_proc_state =
(1L << GLIBTOP_PROC_STATE_CMD) + (1L << GLIBTOP_PROC_STATE_UID) +
(1L << GLIBTOP_PROC_STATE_GID);

static const unsigned long _glibtop_sysdeps_proc_state_new =
0;

/* Init function. */

void
_glibtop_init_proc_state_p (glibtop *server)
{
	server->sysdeps.proc_state = _glibtop_sysdeps_proc_state |
		_glibtop_sysdeps_proc_state_new;
}

/* Provides detailed information about a process. */

void
glibtop_get_proc_state_p (glibtop *server,
			  glibtop_proc_state *buf,
			  pid_t pid)
{
#if defined(__OpenBSD__)
	struct kinfo_proc2 *pinfo;
#else
	struct kinfo_proc *pinfo;
#endif
	int count = 0;

	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_STATE), 0);

	memset (buf, 0, sizeof (glibtop_proc_state));

	/* It does not work for the swapper task. */
	if (pid == 0) return;

	/* Get the process information */
#if defined(__OpenBSD__)
	pinfo = kvm_getproc2 (server->machine.kd, KERN_PROC_PID, pid,
			      sizeof (*pinfo), &count);
#else
	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
#endif
	if ((pinfo == NULL) || (count != 1)) {
		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
		return;
	}

#if (defined(__FreeBSD__) && (__FreeBSD_version >= 500013)) || defined(__FreeBSD_kernel__)
#define	PROC_COMM	ki_comm
#define	PROC_SVUID	ki_svuid
#define	PROC_SVGID	ki_svgid
#define	PROC_RUID	ki_ruid
#define	PROC_RGID	ki_rgid
#define PROC_STAT	ki_stat

#elif defined(__OpenBSD__)

#define PROC_COMM	p_comm
#define PROC_SVUID	p_svuid
#define PROC_SVGID	p_svgid
#define PROC_STAT	p_stat

#else
#define	PROC_COMM	kp_proc.p_comm
#define	PROC_SVUID	kp_eproc.e_pcred.p_svuid
#define	PROC_SVGID	kp_eproc.e_pcred.p_svgid
#define	PROC_RUID	kp_eproc.e_pcred.p_ruid
#define	PROC_RGID	kp_eproc.e_pcred.p_rgid
#define	PROC_STAT	kp_proc.p_stat

#endif

	g_strlcpy (buf->cmd, pinfo [0].PROC_COMM, sizeof buf->cmd);

	buf->uid = pinfo [0].PROC_SVUID;
	buf->gid = pinfo [0].PROC_SVGID;

	/* Set the flags for the data we're about to return*/
	buf->flags = _glibtop_sysdeps_proc_state |
		_glibtop_sysdeps_proc_state_new;

#if LIBGTOP_VERSION_CODE >= 1001000
	switch (pinfo [0].PROC_STAT) {
	case SIDL:
		buf->state = 0;
		break;
	case SRUN:
		buf->state = GLIBTOP_PROCESS_RUNNING;
		break;
#ifdef SSLEEP
	case SSLEEP:
		buf->state = GLIBTOP_PROCESS_INTERRUPTIBLE;
		break;
#endif
	case SSTOP:
		buf->state = GLIBTOP_PROCESS_STOPPED;
		break;
	case SZOMB:
		buf->state = GLIBTOP_PROCESS_ZOMBIE;
		break;
	default:
		return;
	}
#else
	switch (pinfo [0].PROC_STAT) {
	case SIDL:
		buf->state = 'D';
		break;
	case SRUN:
		buf->state = 'R';
		break;
#ifdef SSLEEP
	case SSLEEP:
		buf->state = 'S';
		break;
#endif
	case SSTOP:
		buf->state = 'T';
		break;
	case SZOMB:
		buf->state = 'Z';
		break;
	default:
		return;
	}
#endif

	buf->flags |= (1L << GLIBTOP_PROC_STATE_STATE);
}
