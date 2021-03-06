# $OpenBSD: Makefile,v 1.56 2018/01/23 13:57:02 pea Exp $

COMMENT =	GNU privacy guard - a free PGP replacement

DISTNAME =	gnupg-2.2.4
CATEGORIES = 	security

MASTER_SITES =	${MASTER_SITE_GNUPG:=gnupg/}

HOMEPAGE = 	https://www.gnupg.org/

MAINTAINER = 	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM = 	Yes

WANTLIB += assuan bz2 c gcrypt gnutls gpg-error iconv intl ksba
WANTLIB += npth pthread readline sqlite3 usb-1.0 z curses

EXTRACT_SUFX = 		.tar.bz2

FLAVORS = 		ldap
FLAVOR ?=

LIB_DEPENDS =		archivers/bzip2 \
			databases/sqlite3 \
			devel/gettext \
			devel/libusb1 \
			devel/npth>=1.5 \
			security/gnutls \
			security/libassuan>=2.4.3 \
			security/libgcrypt \
			security/libksba>=1.3.4

.if ${FLAVOR:Mldap}
CONFIGURE_ARGS +=	--enable-ldap
WANTLIB +=		lber ldap
LIB_DEPENDS +=		databases/openldap
.else
CONFIGURE_ARGS +=	--disable-ldap
.endif

RUN_DEPENDS = 		security/pinentry

TEST_DEPENDS = 	${FULLPKGNAME}:${BUILD_PKGPATH}
PORTHOME=${WRKDIR}

USE_GMAKE = 		Yes

CONFIGURE_STYLE = 	gnu
CONFIGURE_ENV = 	CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS += 	docdir=${LOCALBASE}/share/doc/gnupg2 \
			--enable-gpgtar \
			--enable-wks-tools \
			--enable-gpg-is-gpg2

# Avoid conflict with gnupg-1.x
post-install:
	@mv ${PREFIX}/man/man7/gnupg.7 ${PREFIX}/man/man7/gnupg2.7

.include <bsd.port.mk>
