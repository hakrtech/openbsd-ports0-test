# $OpenBSD: Makefile,v 1.30 2017/10/23 17:11:03 sthen Exp $

COMMENT=	gtk+3 spelling checker

DISTNAME=	gtkspell3-3.0.9
EXTRACT_SUFX=	.tar.xz
REVISION=	1

SHARED_LIBS +=  gtkspell3-3          0.3      # 2.0

CATEGORIES=	textproc x11

HOMEPAGE=	http://gtkspell.sourceforge.net/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE SM X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender atk-1.0 atk-bridge-2.0 atspi
WANTLIB += cairo cairo-gobject dbus-1 enchant epoxy expat ffi
WANTLIB += fontconfig freetype gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 gtk-3
WANTLIB += harfbuzz iconv intl m pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread ${COMPILER_LIBCXX} xcb
WANTLIB += xcb-render xcb-shm z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkspell/}

MODULES=	textproc/intltool \
		x11/gnome

MODGNOME_TOOLS=	gobject-introspection vala

BUILD_DEPENDS=	devel/iso-codes
RUN_DEPENDS=	devel/iso-codes

USE_GMAKE=	Yes

LIB_DEPENDS=	textproc/enchant \
		x11/gtk+3

CONFIGURE_STYLE=gnu

PORTHOME=	${WRKBUILD}

.include <bsd.port.mk>
