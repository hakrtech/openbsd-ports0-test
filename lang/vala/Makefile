# $OpenBSD: Makefile,v 1.103 2018/02/17 07:44:38 jasper Exp $

COMMENT-main=		compiler for the GObject type system
COMMENT-valadoc=	Vala documentation generator

GNOME_PROJECT=		vala
GNOME_VERSION=		0.38.8

PKGNAME-main=		${DISTNAME}
PKGNAME-valadoc=	valadoc-${GNOME_VERSION}

# XXX API_V is used by x11/gnome/libgda
API_V=			0.38
SHARED_LIBS +=  vala-${API_V}               0.0      # 0.0
SHARED_LIBS +=  valadoc-${API_V}            0.0      # 0.0

CATEGORIES=		lang

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c ffi glib-2.0 gmodule-2.0 gobject-2.0 iconv intl pcre pthread

WANTLIB-valadoc += ${WANTLIB}
WANTLIB-valadoc += cdt cgraph expat gvc ltdl m pathplan vala-0.38 xdot
WANTLIB-valadoc += z

MODULES=		x11/gnome

BUILD_DEPENDS=		textproc/libxslt

MULTI_PACKAGES=		-main -valadoc

LIB_DEPENDS-main=	devel/glib2

LIB_DEPENDS-valadoc=	${BASE_PKGPATH},-main=${GNOME_VERSION} \
		math/graphviz

TEST_DEPENDS=		shells/bash

SUBST_VARS+=		API_V

CONFIGURE_STYLE=	autoconf
AUTOCONF_VERSION=	2.69

# multiple dep loops like:
# lang/vala -> math/graphviz -> x11/gnome/librsvg -> lang/vala
PSEUDO_FLAVORS=		no_valadoc bootstrap
FLAVOR?=		no_valadoc bootstrap

.include <bsd.port.arch.mk>

.if !${BUILD_PACKAGES:M-valadoc}
PATCH_LIST=		patch-* no_valadoc-*
.endif

post-install:
	rm ${PREFIX}/lib/vala-${API_V}/*.{a,la}
.if ${BUILD_PACKAGES:M-valadoc}
	rm ${PREFIX}/lib/valadoc/doclets/devhelp/*.{a,la}
.endif

.include <bsd.port.mk>
