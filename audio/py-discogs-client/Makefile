# $OpenBSD: Makefile,v 1.8 2017/06/11 21:17:44 sthen Exp $

COMMENT =	Python interface to Discogs website

MODPY_EGG_VERSION = 2.2.1
DISTNAME =	discogs-client-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}
CATEGORIES =	audio
MAINTAINER =	Johan Huldtgren <jhuldtgren@gmail.com>
REVISION =	0

HOMEPAGE =	https://github.com/discogs/discogs_client

# MIT
PERMIT_PACKAGE_CDROM =  Yes

MODPY_PI =	Yes

MODULES =	lang/python
MODPY_SETUPTOOLS = Yes

FLAVORS =	python3
FLAVOR ?=

RUN_DEPENDS =	devel/py-six${MODPY_FLAVOR} \
		security/py-oauthlib${MODPY_FLAVOR} \
		www/py-requests${MODPY_FLAVOR}

TEST_DEPENDS =	${RUN_DEPENDS}

.include <bsd.port.mk>
