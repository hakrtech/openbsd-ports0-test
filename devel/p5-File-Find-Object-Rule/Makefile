# $OpenBSD: Makefile,v 1.5 2016/09/15 22:15:33 bluhm Exp $

COMMENT =		alternative interface to File::Find::Object

DISTNAME =		File-Find-Object-Rule-0.0306

CATEGORIES =		devel

MAINTAINER =		Alexander Bluhm <bluhm@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		cpan
PKG_ARCH =		*
RUN_DEPENDS =		devel/p5-Class-XSAccessor \
			devel/p5-File-Find-Object>=0.2.1 \
			devel/p5-Number-Compare \
			textproc/p5-Text-Glob
TEST_DEPENDS =		devel/p5-Test-Pod>=1.14 \
			devel/p5-Test-Pod-Coverage>=1.04

CONFIGURE_STYLE =	modbuild

.include <bsd.port.mk>
