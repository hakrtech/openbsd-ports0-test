# $OpenBSD: Makefile,v 1.1.1.1 2018/03/18 12:12:34 ajacoutot Exp $

COMMENT=		system resources status

GNOME_PROJECT=		gnome-usage
GNOME_VERSION=		3.28.0

CATEGORIES=		sysutils

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c cairo gdk-3 gio-2.0 glib-2.0 gobject-2.0 gtk-3 gtop-2.0
WANTLIB += intl m pango-1.0

MODULES=		devel/dconf \
			devel/meson \
			x11/gnome

MODGNOME_TOOLS= 	desktop-file-utils gtk-update-icon-cache vala

LIB_DEPENDS=		devel/libgtop2 \
			x11/gtk+3

.include <bsd.port.mk>
