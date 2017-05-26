# $OpenBSD: Makefile,v 1.1.1.1 2017/05/26 19:43:03 jung Exp $

COMMENT =		standards based terminal calendar

MODPY_EGG_VERSION =	0.9.5
DISTNAME =		khal-${MODPY_EGG_VERSION}

CATEGORIES =		productivity

HOMEPAGE =		http://lostpackets.de/khal/

MAINTAINER =		Joerg Jung <jung@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =         ${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-atomicwrites${MODPY_FLAVOR} \
			devel/py-click${MODPY_FLAVOR} \
			devel/py-configobj${MODPY_FLAVOR} \
			devel/py-dateutil${MODPY_FLAVOR} \
			devel/py-setproctitle${MODPY_FLAVOR} \
			devel/py-tz${MODPY_FLAVOR} \
			devel/py-tzlocal${MODPY_FLAVOR} \
			devel/py-urwid${MODPY_FLAVOR} \
			devel/py-xdg${MODPY_FLAVOR} \
			devel/py-icalendar${MODPY_FLAVOR} \
			productivity/vdirsyncer
TEST_DEPENDS =		${RUN_DEPENDS} \
			devel/py-test${MODPY_FLAVOR} \
			devel/py-test-cov${MODPY_FLAVOR} \
			devel/py-test-capturelog${MODPY_FLAVOR} \
			devel/py-freezegun${MODPY_FLAVOR}

do-test:
			cd ${WRKSRC} && ${MODPY_BIN} -m pytest

.include <bsd.port.mk>