# $OpenBSD: Makefile,v 1.22 2017/11/21 00:13:00 naddy Exp $

COMMENT =		infinite-world block sandbox game
V =			0.4.14
DISTNAME =		minetest-${V}
CATEGORIES =		games x11
REVISION =		2

HOMEPAGE =		http://www.minetest.net/

# source LGPLv2.1/ datas CC BY-SA 3.0
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL GLU ICE Irrlicht SM X11 Xext Xxf86vm bz2 c curl freetype 
WANTLIB += iconv intl jpeg m ogg openal png pthread spatialindex sqlite3 
WANTLIB += ${COMPILER_LIBCXX} vorbis vorbisfile z
WANTLIB += luajit-${MODLUA_VERSION}

MASTER_SITES =		https://github.com/minetest/

DISTFILES =		minetest-{minetest/archive/}${V}${EXTRACT_SUFX} \
			minetest-game-{minetest_game/archive/}${V}${EXTRACT_SUFX}

MODULES =		devel/cmake \
			lang/lua

CONFIGURE_ARGS =	-DENABLE_GETTEXT=ON -DCUSTOM_MANDIR=${PREFIX}/man
CONFIGURE_ARGS+=	-DENABLE_REDIS=FALSE -DENABLE_LEVELDB=FALSE
CONFIGURE_ENV +=	CXXFLAGS="-I${X11BASE}/include"

BUILD_DEPENDS =		devel/gettext-tools

RUN_DEPENDS =		devel/desktop-file-utils \
			x11/gtk+3,-guic

LIB_DEPENDS =		audio/openal \
			databases/sqlite3 \
			geo/spatialindex \
			audio/libvorbis \
			lang/luajit \
			net/curl \
			x11/irrlicht

NO_TEST =		Yes

post-install:
	mv ${WRKDIR}/minetest_game-${V}/ \
	${PREFIX}/share/minetest/games/minetest_game
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/minetest/games/minetest_game

.include <bsd.port.mk>
