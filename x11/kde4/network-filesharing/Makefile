# $OpenBSD: Makefile,v 1.5 2017/07/27 11:57:50 sthen Exp $

COMMENT =	KDE network file sharing components
DISTNAME =	kdenetwork-filesharing-${MODKDE4_VERSION}
REVISION =	2

CATEGORIES =	net
HOMEPAGE =	http://projects.kde.org/projects/kde/kdenetwork/kdenetwork-filesharing

WANTLIB =  m pthread
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtGui lib/qt4/QtNetwork lib/qt4/QtSvg
WANTLIB += lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/kdeui ${KDE4LIB}/kio

MODKDE4_USE =	libs

RUN_DEPENDS =	net/samba

CONFIGURE_ARGS =	-DSAMBA_INSTALL:Bool=No

.include <bsd.port.mk>
