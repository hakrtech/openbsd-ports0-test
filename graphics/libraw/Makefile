# $OpenBSD: Makefile,v 1.35 2018/03/05 14:53:40 rsadowski Exp $

COMMENT =		library for reading RAW files

DISTNAME =		LibRaw-0.18.8
PKGNAME =		${DISTNAME:L}
CATEGORIES =		graphics

SHARED_LIBS +=  raw                  3.0      # 15.0
SHARED_LIBS +=  raw_r                3.0      # 15.0

HOMEPAGE =		https://www.libraw.org/

MAINTAINER =		Rafael Sadowski <rsadowski@openbsd.org>

# LGPL v2.1 OR CDDL v1.0 OR their own
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c jasper jpeg lcms2 m pthread ${COMPILER_LIBCXX}

MASTER_SITES =		https://www.libraw.org/data/

COMPILER =		base-clang ports-gcc base-gcc
# for atomic builtins (__sync_fetch_and_add_4)
MODGCC4_ARCHS =		hppa

LIB_DEPENDS =		graphics/jasper \
			graphics/lcms2

SEPARATE_BUILD = 	Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
