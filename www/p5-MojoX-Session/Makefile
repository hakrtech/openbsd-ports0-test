# $OpenBSD: Makefile,v 1.10 2016/03/20 19:57:21 naddy Exp $

COMMENT =	session management for Mojo

MODULES =	cpan
PKG_ARCH =	*
DISTNAME =	MojoX-Session-0.33
CATEGORIES =	www

# Perl
PERMIT_PACKAGE_CDROM =		Yes

CPAN_AUTHOR =	VTI

RUN_DEPENDS =	www/p5-Mojo

TEST_DEPENDS+=	databases/p5-DBD-SQLite \
		databases/p5-DBIx-Class-Schema-Loader

.include <bsd.port.mk>
