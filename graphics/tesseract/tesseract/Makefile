# $OpenBSD: Makefile,v 1.14 2017/12/03 13:59:46 ajacoutot Exp $

COMMENT=	OCR Engine developed at HP Labs

GH_PROJECT=	tesseract
GH_TAGNAME=	3.05.01

SHARED_LIBS +=  tesseract            3.2      # 3.5

WANTLIB += X11 Xext Xrender c cairo expat ffi fontconfig freetype
WANTLIB += gif glib-2.0 gobject-2.0 graphite2 gthread-2.0 harfbuzz
WANTLIB += iconv icudata icui18n icuuc intl jpeg lept m openjp2
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png pthread ${LIBCXX} tiff webp xcb xcb-render
WANTLIB += xcb-shm z

# c++11: needed to build the training tools
COMPILER =		base-clang ports-gcc

ALL_TARGET=		training

LIB_DEPENDS=		devel/pango \
			graphics/leptonica \
			textproc/icu4c

RUN_DEPENDS=		graphics/tesseract/tessdata,-main

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
 
ALL_TARGET=		all training
INSTALL_TARGET=		install training-install

###
AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15
BUILD_DEPENDS +=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool
pre-configure:
	cd ${WRKSRC} && ${SETENV} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		autoreconf -fi
###

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tesseract
	${INSTALL_DATA} ${WRKSRC}/testing/{eurotext.tif,phototest.tif} \
		${PREFIX}/share/examples/tesseract

.include <bsd.port.mk>
