# $OpenBSD: Makefile,v 1.33 2018/01/14 10:03:54 rsadowski Exp $

COMMENT=	GNU awk

V=		4.2.0
DISTNAME=	gawk-$V
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

HOMEPAGE=	https://www.gnu.org/software/gawk/

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c curses gmp iconv intl m mpfr readline sigsegv

LIB_DEPENDS=	devel/gettext \
		devel/gmp \
		devel/libsigsegv \
		devel/mpfr

SUBST_VARS=	V

MAKE_ENV +=	RM="rm -f"

CONFIGURE_STYLE=gnu
LIBTOOL_FLAGS=	--tag=disable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man3am
	mv ${PREFIX}/man/man3/*.3am ${PREFIX}/man/man3am

.include <bsd.port.mk>
