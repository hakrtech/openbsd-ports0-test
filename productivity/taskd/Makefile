# $OpenBSD: Makefile,v 1.13 2018/01/11 19:27:08 rpe Exp $

COMMENT =	lightweight server providing access to task data

DISTNAME =	taskd-1.1.0
CATEGORIES =	productivity net
REVISION =	2

HOMEPAGE =	http://www.taskwarrior.org/

MAINTAINER =	Kent R. Spillner <kspillner@openbsd.org>

MASTER_SITES =	${HOMEPAGE}/download/

# MIT
PERMIT_PACKAGE_CDROM =		Yes

MODULES =	devel/cmake

COMPILER =	base-clang ports-gcc

WANTLIB += c gnutls m pthread ${COMPILER_LIBCXX}

LIB_DEPENDS =	security/gnutls

CONFIGURE_ARGS +=	-DTASKD_DOCDIR=share/taskd \
			-DTASKD_MAN1DIR=man/man1 \
			-DTASKD_MAN5DIR=man/man5

CONFIGURE_ENV +=	CFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

NO_TEST =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/taskd/pki/
	${INSTALL_SCRIPT} ${WRKSRC}/pki/generate!(*.orig) \
		${PREFIX}/share/examples/taskd/pki/
	${INSTALL_DATA} ${WRKSRC}/pki/README \
		${PREFIX}/share/examples/taskd/pki/
	${INSTALL_DATA} ${WRKSRC}/pki/vars \
		${PREFIX}/share/examples/taskd/pki/vars.dist
	${SUBST_DATA} ${FILESDIR}/config \
		${PREFIX}/share/examples/taskd/config

.include <bsd.port.mk>
