# $OpenBSD: Makefile,v 1.15 2017/11/21 00:13:00 naddy Exp $

COMMENT=	interactive game for young children

DISTNAME=	gamine-1.1
REVISION=	11

CATEGORIES=	games

HOMEPAGE=	http://gnunux.info/projets/gamine/

# DWTFYWTPL
# (DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE)
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB =  GL X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender Xxf86vm atk-1.0 c cairo drm expat
WANTLIB += fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gstreamer-0.10 gthread-2.0
WANTLIB += gtk-x11-2.0 iconv intl m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pixman-1 png pthread xcb xcb-render xcb-shm xml2
WANTLIB += z

MASTER_SITES=	${HOMEPAGE}

MODULES=	devel/gconf2

BUILD_DEPENDS=	devel/gettext-tools

RUN_DEPENDS=	devel/desktop-file-utils \
		multimedia/gstreamer-0.10/plugins-good \
		x11/gtk+3,-guic

LIB_DEPENDS=	multimedia/gstreamer-0.10/core \
		x11/gtk+2

USE_GMAKE=	Yes
ALL_TARGET=	# empty

MODGCONF2_SCHEMAS_DIR= gamine

MAKE_FLAGS=	PREFIX=${PREFIX} CC=${CC} CFLAGS="${CFLAGS}" \
		GCONFTOOL=/usr/bin/true \
		GCONF_SCHEMA_FILE_DIR=${LOCALBASE}/${SCHEMAS_INSTDIR} \
		sysconfdir=${SYSCONFDIR}

FAKE_FLAGS=	PREFIX=${WRKINST}${PREFIX} \
		GCONF_SCHEMA_FILE_DIR=${WRKINST}${PREFIX}/${SCHEMAS_INSTDIR} \
		sysconfdir=${PREFIX}/share/examples/gamine

.include <bsd.port.mk>
