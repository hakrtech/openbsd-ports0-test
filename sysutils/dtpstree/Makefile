# $OpenBSD: Makefile,v 1.11 2017/07/26 22:45:30 sthen Exp $

COMMENT =		display a tree of processes

DISTNAME =		dtpstree-1.0.3
REVISION =		2
CATEGORIES =		sysutils

HOMEPAGE =		http://code.douglasthrift.net/trac/dtpstree

MAINTAINER =		Douglas William Thrift <douglas@douglasthrift.net>

# Apache 2.0
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c kvm m ncurses ${COMPILER_LIBCXX}

MASTER_SITES =		http://code.douglasthrift.net/files/dtpstree/ \
			http://apt.douglasthrift.net/files/dtpstree/
EXTRACT_SUFX =		.tar.bz2

SEPARATE_BUILD =	Yes

MAKE_FILE =		GNUmakefile
USE_GMAKE =		Yes
CONFIGURE_STYLE =	autoconf no-autoheader
AUTOCONF_VERSION =	2.65

NO_TEST =		Yes

post-patch:
	@cd ${WRKDIST}; cat check_gnu_make.m4 >> aclocal.m4

.include <bsd.port.mk>
