# $OpenBSD: Makefile,v 1.24 2018/01/20 11:34:16 ajacoutot Exp $

COMMENT =		common testing tools used in the Salt Stack projects

MODPY_EGG_VERSION =	2018.1.16
DISTNAME =		SaltTesting-${MODPY_EGG_VERSION}
PKGNAME =		salt-testing-${MODPY_EGG_VERSION}

CATEGORIES =		sysutils

HOMEPAGE =		http://saltstack.org/

MAINTAINER =		Antoine Jacoutot <ajacoutot@openbsd.org>

# Apache 2.0
PERMIT_PACKAGE_CDROM =	Yes

MODPY_PI =		Yes

MODULES =		lang/python
NO_TEST =		Yes

RUN_DEPENDS =		devel/py-mock \
			sysutils/py-psutil \
			sysutils/salt

.include <bsd.port.mk>
