# $OpenBSD: Makefile,v 1.55 2018/03/13 02:54:45 bcallah Exp $

COMMENT =	translate common internet acronyms

DISTNAME =	wtf-20180307
CATEGORIES =	games

MAINTAINER =	Brian Callahan <bcallah@openbsd.org>

# Public Domain
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=bsdwtf/}

NO_BUILD =	Yes
NO_TEST =	Yes

PKG_ARCH =	*

do-configure:
	@perl -pi -e "s#/usr#${PREFIX}#" ${WRKSRC}/wtf{,.6}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/acronyms{,.comp} ${PREFIX}/share/misc
	${INSTALL_DATA} ${WRKSRC}/acronyms-o.real ${PREFIX}/share/misc/acronyms-o

.include <bsd.port.mk>
