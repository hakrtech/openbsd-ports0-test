#ifndef SINGLE_SOURCE_COMPILE

/* license */

#include "MidiSndio.h"

#ifdef LMMS_HAVE_SNDIO

#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

#ifdef LMMS_HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include <poll.h>

#include "config_mgr.h"
#include "gui_templates.h"


MidiSndio::MidiSndio( void ) :
	MidiClientRaw(),
	m_quit( FALSE )
{
	QString dev = probeDevice();

	if (dev == "")
	{
		m_hdl = mio_open( NULL, MIO_IN | MIO_OUT, 0 );
	}
	else
	{
		m_hdl = mio_open( dev.toAscii().data(), MIO_IN | MIO_OUT, 0 );
	}

	if( m_hdl == NULL )
	{
		printf( "sndio: failed opening sndio midi device\n" );
		return;
	}

	start( QThread::LowPriority );
}


MidiSndio::~MidiSndio()
{
	if( isRunning() )
	{
		m_quit = TRUE;
		wait( 1000 );
		terminate();
	}
}


QString MidiSndio::probeDevice( void )
{
	QString dev = configManager::inst()->value( "midisndio", "device" );

	return( dev );
}


void MidiSndio::sendByte( const Uint8 _c )
{
	mio_write( m_hdl, &_c, 1 );
}


void MidiSndio::run( void )
{
	struct pollfd pfd;
	nfds_t nfds;
	char buf[0x100], *p;
	size_t n;
	int ret;
	while( m_quit == FALSE && m_hdl )
	{
		nfds = mio_pollfd( m_hdl, &pfd, POLLIN );
		ret = poll( &pfd, nfds, 100 );
		if ( ret < 0 )
			break;
		if ( !ret || !( mio_revents( m_hdl, &pfd ) & POLLIN ) )
			continue;
		n = mio_read( m_hdl, buf, sizeof(buf) );
		if ( !n )
		{
			break;
		}
		for (p = buf; n > 0; n--, p++)
		{
			parseData( *p );
		}
	}
}


MidiSndio::setupWidget::setupWidget( QWidget * _parent ) :
	MidiClientRaw::setupWidget( MidiSndio::name(), _parent )
{
	m_device = new QLineEdit( MidiSndio::probeDevice(), this );
	m_device->setGeometry( 10, 20, 160, 20 );

	QLabel * dev_lbl = new QLabel( tr( "DEVICE" ), this );
	dev_lbl->setFont( pointSize<6>( dev_lbl->font() ) );
	dev_lbl->setGeometry( 10, 40, 160, 10 );
}


MidiSndio::setupWidget::~setupWidget()
{
}


void MidiSndio::setupWidget::saveSettings( void )
{
	configManager::inst()->setValue( "midisndio", "device",
	    m_device->text() );
}

#endif	/* LMMS_HAVE_SNDIO */

#endif	/* SINGLE_SOURCE_COMPILE */
