# $OpenBSD: Makefile,v 1.14 2018/01/03 10:39:00 bentley Exp $

PORTROACH =		limit:[0-9]\.tar\.gz

COMMENT =		command line client application for Mega

DISTNAME =		megatools-1.9.98
REVISION =		2

CATEGORIES =		net

HOMEPAGE =		https://megatools.megous.com/

MAINTAINER =		Anthony J. Bentley <anthony@anjbe.name>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =  c crypto curl gio-2.0 glib-2.0 gobject-2.0 iconv intl pthread
WANTLIB += ssl

MASTER_SITES =		https://megatools.megous.com/builds/

BUILD_DEPENDS =		devel/gobject-introspection \
			textproc/asciidoc
LIB_DEPENDS =		devel/glib2 \
			net/curl

USE_GMAKE =		Yes
CONFIGURE_STYLE =	gnu

CONFIGURE_ARGS =	--disable-introspection

.include <bsd.port.mk>
