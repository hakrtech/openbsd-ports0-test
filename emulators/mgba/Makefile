# $OpenBSD: Makefile,v 1.21 2017/11/16 23:20:38 naddy Exp $

COMMENT-main =		Game Boy Color/Advance emulator
COMMENT-qt =		Game Boy Color/Advance emulator with GUI
COMMENT-libretro =	Game Boy Color/Advance core for retroarch

V =			0.6.1
DISTNAME =		mgba-$V
PKGNAME-main =		mgba-$V
PKGNAME-qt =		mgba-qt-$V
PKGNAME-libretro =	libretro-mgba-$V

MULTI_PACKAGES =	-main -qt -libretro

.include <bsd.port.arch.mk>

SHARED_LIBS +=  mgba                      1.0 # 0.1

CATEGORIES =		emulators

HOMEPAGE =		https://mgba.io/

MAINTAINER =		Anthony J. Bentley <anthony@anjbe.name>

# MPL 2.0
PERMIT_PACKAGE_CDROM =	Yes

cWANTLIB =		GL GLU MagickCore-6.Q16 MagickWand-6.Q16 SDL2 \
			avcodec avformat avresample avutil c edit m png \
			pthread sqlite3 swscale termcap z zip epoxy
WANTLIB-main =		${cWANTLIB}
WANTLIB-qt =		${cWANTLIB} Qt5Core Qt5Gui Qt5Multimedia \
			Qt5Network Qt5OpenGL Qt5Widgets ${COMPILER_LIBCXX} mgba
WANTLIB-libretro =	m pthread

GH_ACCOUNT =		mgba-emu
GH_PROJECT =		mgba
GH_TAGNAME =		$V

MODULES =		devel/cmake
COMPILER =		base-clang ports-gcc
LIB_DEPENDS-main =	archivers/libzip \
			graphics/ImageMagick \
			graphics/ffmpeg \
			devel/sdl2
LIB_DEPENDS-qt =	${LIB_DEPENDS-main} \
			${MODQT_LIB_DEPENDS} \
			emulators/mgba,-main \
			x11/qt5/qtmultimedia
LIB_DEPENDS-libretro =
RUN_DEPENDS-qt =	devel/desktop-file-utils \
			x11/gtk+3,-guic

CONFIGURE_ARGS +=	-DBUILD_LIBRETRO=ON

.if ${BUILD_PACKAGES:M-qt}
MODULES +=		x11/qt5
.endif

NO_TEST =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/libretro
	mv ${PREFIX}/lib/mgba_libretro.so ${PREFIX}/lib/libretro

.include <bsd.port.mk>
