# $OpenBSD: Makefile,v 1.15 2017/12/01 14:04:13 awolk Exp $

COMMENT =		lightweight C library for fast bi-directional websockets

GH_ACCOUNT =		warmcat
GH_PROJECT =		libwebsockets
GH_TAGNAME =		v2.4.1

SHARED_LIBS =		websockets 9.0 # 12

CATEGORIES =		www

HOMEPAGE =		https://libwebsockets.org

MAINTAINER =		Adam Wolk <awolk@openbsd.org>

# LGPL2 + static link exception
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += 		crypto m ssl z

MODULES =		devel/cmake

CONFIGURE_ARGS +=	-DLWS_WITHOUT_TESTAPPS=ON \
			-DLWS_WITHOUT_TEST_SERVER=ON

NO_TEST =		Yes

post-install:
	@rm -r ${WRKINST}/usr/local/share/libwebsockets-test-server

.include <bsd.port.mk>
