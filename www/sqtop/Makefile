# $OpenBSD: Makefile,v 1.9 2017/12/07 13:12:44 espie Exp $

COMMENT=		top-like monitor for Squid

DISTNAME=		sqtop-2011-11-01
PKGNAME=		sqtop-2011.11.01
REVISION=		2
CATEGORIES=		www
FIX_EXTRACT_PERMISSIONS=Yes

MAINTAINER=		Gonzalo L. R. <gonzalo@openbsd.org>

HOMEPAGE=		https://code.google.com/p/sqtop/
EXTRACT_SUFX=		.tar.bz2

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c m ncurses pthread ${COMPILER_LIBCXX}

MASTER_SITES=		${MASTER_SITE_GOOGLECODE:=sqtop/}

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
