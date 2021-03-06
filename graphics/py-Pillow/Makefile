# $OpenBSD: Makefile,v 1.23 2017/09/19 10:22:46 ajacoutot Exp $

COMMENT=		Python Imaging Library (maintained fork of PIL)

MODPY_EGG_VERSION=	3.4.2
DISTNAME=		Pillow-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
CATEGORIES=		graphics
REVISION=		1

HOMEPAGE=		http://python-pillow.org/

# PIL Software License
# Permission to use, copy, modify and distribute freely.
PERMIT_PACKAGE_CDROM=   Yes

FLAVORS=		python3
FLAVOR?=

MODPY_PI =		Yes
EXTRACT_SUFX=		.zip

WANTLIB=		freetype jpeg lcms2 pthread tiff webp z \
			webpdemux webpmux \
			${MODPY_WANTLIB} ${MODTK_WANTLIB}

MODULES=		lang/python \
			x11/tk

BUILD_DEPENDS=		${MODPY_TKINTER_DEPENDS}
TEST_DEPENDS=		${FULLPKGNAME}:${BUILD_PKGPATH} \
			devel/py-nose${MODPY_FLAVOR}
RUN_DEPENDS=		${MODPY_RUN_DEPENDS}

# Is Tk image support actually useful?
LIB_DEPENDS=		graphics/lcms2 \
			graphics/libwebp \
			${MODTK_LIB_DEPENDS}

MODPY_SETUPTOOLS=	Yes
MAKE_ENV=		C_INCLUDE_PATH="${X11BASE}/include:${LOCALBASE}/include:${MODTK_INCDIR}:${MODTCL_INCDIR}" \
			LIBRARY_PATH="${X11BASE}/lib:${LOCALBASE}/lib"

MODPY_ADJ_FILES=	Scripts/*.py

SUBST_VARS+=		INCL_DIR MODPY_FLAVOR
INCL_DIR=		${MODPY_INCDIR:S/${LOCALBASE}\///}

MODPY_DISTUTILS_BUILD=	build_ext --disable-jpeg2000

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}${MODPY_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/libImaging/{ImPlatform,Imaging}.h ${WRKINST}${MODPY_INCDIR}
	for s in ${PREFIX}/bin/*; do mv $$s $$s${MODPY_BIN_SUFFIX}; done

do-test:
	cd ${WRKSRC}; ${MODPY_BIN} ./selftest.py --installed

.include <bsd.port.mk>
