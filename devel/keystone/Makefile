# $OpenBSD: Makefile,v 1.8 2017/11/16 23:20:37 naddy Exp $

COMMENT =	multi-platform, multi-architecture assembler framework

GH_ACCOUNT =	keystone-engine
GH_PROJECT =	keystone
GH_TAGNAME =	0.9.1
REVISION =	1

SHARED_LIBS =	keystone	1.0

CATEGORIES =	devel

HOMEPAGE =	http://www.keystone-engine.org/

MAINTAINER =	Frederic Cambus <fcambus@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB +=	c m
WANTLIB += ${COMPILER_LIBCXX}

MODULES =	devel/cmake \
		lang/python
MODPY_RUNDEP =	No

# atomics
COMPILER =	base-clang ports-clang


CONFIGURE_ARGS = -DBUILD_SHARED_LIBS=ON

NO_TEST =	Yes

.include <bsd.port.mk>
