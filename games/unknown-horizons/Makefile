# $OpenBSD: Makefile,v 1.1.1.1 2017/11/04 22:04:20 bentley Exp $

COMMENT =	economic historical real-time strategy game

MODPY_EGG_VERSION =	2017.2
PKGNAME =		unknown-horizons-${MODPY_EGG_VERSION}

GH_ACCOUNT =	unknown-horizons
GH_PROJECT =	unknown-horizons
GH_TAGNAME =	${MODPY_EGG_VERSION}

CATEGORIES =	games

HOMEPAGE =	http://www.unknown-horizons.org/

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python \
			textproc/intltool
MODPY_ADJ_FILES =	unknown-horizons
BUILD_DEPENDS =		devel/gettext-tools
RUN_DEPENDS =		devel/desktop-file-utils \
			games/fifengine
TEST_DEPENDS =		devel/py-greenlet \
			devel/py-mock \
			devel/py-nose \
			textproc/py-polib \
			textproc/py-yaml

do-test:
	cd ${WRKSRC} && ${MODPY_BIN} run_tests.py

.include <bsd.port.mk>
