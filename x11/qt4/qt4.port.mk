# $OpenBSD: qt4.port.mk,v 1.4 2008/11/29 12:15:57 ajacoutot Exp $

# This fragment defines MODQT_* variables to make it easier to substitute
# qt1/qt2/qt3 in a port.
MODQT_OVERRIDE_UIC ?= Yes
MODQT4_OVERRIDE_UIC ?= ${MODQT_OVERRIDE_UIC}

MODQT4_LIBDIR =	${LOCALBASE}/lib/qt4
MODQT_LIBDIR ?= ${MODQT4_LIBDIR}
MODQT4_INCDIR =	${LOCALBASE}/include/X11/qt4
MODQT_INCDIR ?= ${MODQT4_INCDIR}
MODQT_PKG_CONFIG_PATH ?= ${LOCALBASE}/lib/qt4/pkgconfig
MODQT4_CONFIGURE_ARGS =	--with-qt-includes=${MODQT4_INCDIR} \
			--with-qt-libraries=${MODQT4_LIBDIR}
MODQT_CONFIGURE_ARGS ?= ${MODQT4_CONFIGURE_ARGS}
_MODQT4_SETUP =	MOC=${MODQT4_MOC} \
		MODQT_INCDIR=${MODQT4_INCDIR} \
		MODQT_LIBDIR=${MODQT4_LIBDIR} \
		PKG_CONFIG_PATH=${PKG_CONFIG_PATH}:${MODQT_PKG_CONFIG_PATH}
.if ${MODQT4_OVERRIDE_UIC:L} == "yes"
_MODQT4_SETUP +=UIC=${MODQT4_UIC}
.endif

LIB_DEPENDS += lib/qt4/QtCore::x11/qt4
# may be needed to find plugins
MODQT4_MOC =	${LOCALBASE}/bin/moc4
MODQT_MOC ?=	${MODQT4_MOC}
MODQT4_UIC =	${LOCALBASE}/bin/uic4
MODQT_UIC ?=	${MODQT4_UIC}
MODQT4_QTDIR =	${LOCALBASE}/lib/qt4
MODQT_QTDIR ?=	${MODQT4_QTDIR}

CONFIGURE_ENV +=${_MODQT4_SETUP}
MAKE_ENV +=	${_MODQT4_SETUP}
MAKE_FLAGS +=	${_MODQT4_SETUP}
