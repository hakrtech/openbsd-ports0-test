# $OpenBSD: cmake.port.mk,v 1.17 2013/04/18 22:54:50 sthen Exp $

BUILD_DEPENDS+=	devel/cmake>=2.8.0

# XXX if a library is not listed in SHARED_LIBS, it will be created
# with *no* version suffix.
.for _n _v in ${SHARED_LIBS}
CONFIGURE_ENV+=LIB${_n}_VERSION=${_v}
MAKE_ENV+=LIB${_n}_VERSION=${_v}
.endfor

CONFIGURE_ENV +=	MODJAVA_VER=${MODJAVA_VER} \
			MODLUA_VERSION=${MODLUA_VERSION} \
			MODLUA_BIN=${MODLUA_BIN} \
			MODLUA_INCL_DIR=${MODLUA_INCL_DIR} \
			MODPY_VERSION=${MODPY_VERSION} \
			MODPY_BIN=${MODPY_BIN} \
			MODPY_INCDIR=${MODPY_INCDIR} \
			MODPY_LIBDIR=${MODPY_LIBDIR} \
			MODTCL_VERSION=${MODTCL_VERSION} \
			MODTK_VERSION=${MODTK_VERSION} \
			MODTCL_INCDIR=${MODTCL_INCDIR} \
			MODTK_INCDIR=${MODTK_INCDIR} \
			MODTCL_LIBDIR=${MODTCL_LIBDIR} \
			MODTK_LIBDIR=${MODTK_LIBDIR} \
			MODTCL_LIB=${MODTCL_LIB} \
			MODTK_LIB=${MODTK_LIB}

.if empty(CONFIGURE_STYLE)
CONFIGURE_STYLE=	cmake
.endif
MODCMAKE_configure=	cd ${WRKBUILD} && ${_SYSTRACE_CMD} ${SETENV} \
	CC="${CC}" CFLAGS="${CFLAGS}" \
	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
	${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake \
		-DCMAKE_SKIP_INSTALL_ALL_DEPENDENCY:Bool=True \
			${CONFIGURE_ARGS} ${WRKSRC}

SEPARATE_BUILD ?=	Yes

TEST_TARGET ?=	test

MODCMAKE_WANTCOLOR ?= No
MODCMAKE_VERBOSE ?= Yes

.if ${MODCMAKE_WANTCOLOR:L} == "yes" && defined(TERM)
MAKE_ENV += TERM=${TERM}
.endif

.if ${MODCMAKE_VERBOSE:L} == "yes"
MAKE_ENV += VERBOSE=1
.endif

# XXX cmake include parser is bogus
DPB_PROPERTIES += nojunk
