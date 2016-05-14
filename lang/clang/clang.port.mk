# $OpenBSD: clang.port.mk,v 1.17 2016/05/14 20:37:32 ajacoutot Exp $

MODCLANG_VERSION=	3.8.0

MODCLANG_ARCHS ?=
MODCLANG_LANGS ?=

.if !${MODCLANG_LANGS:L:Mc}
# Always include support for this
MODCLANG_LANGS += c
.endif

_MODCLANG_OKAY = c c++
.for _l in ${MODCLANG_LANGS:L}
.  if !${_MODCLANG_OKAY:M${_l}}
ERRORS += "Fatal: unknown language ${_l}"
.  endif
.endfor

_MODCLANG_ARCH_USES = No

.if ${MODCLANG_ARCHS:L} != ""
.  for _i in ${MODCLANG_ARCHS}
.    if !empty(MACHINE_ARCH:M${_i})
_MODCLANG_ARCH_USES = Yes
.    endif
.  endfor
.endif

_MODCLANG_LINKS =
.if ${_MODCLANG_ARCH_USES:L} == "yes"

BUILD_DEPENDS += devel/llvm>=${MODCLANG_VERSION}
_MODCLANG_LINKS = clang gcc clang cc

.  if ${MODCLANG_LANGS:L:Mc++}
_MODCLANG_LINKS += clang++ g++ clang++ c++
# uses libestdc++
MODULES += gcc4
MODCLANG_CPPLIBDEP = ${MODGCC4_CPPLIBDEP}
LIB_DEPENDS += ${MODCLANG_CPPLIBDEP}
MODCLANG_CPPWANTLIB = ${MODGCC4_CPPWANTLIB}
WANTLIB += ${MODCLANG_CPPWANTLIB}
.  endif
.endif

.if !empty(_MODCLANG_LINKS)
.  if "${USE_CCACHE:L}" == "yes" && "${NO_CCACHE:L}" != "yes"
.    for _src _dest in ${_MODCLANG_LINKS}
MODCLANG_post-patch +=	rm -f ${WRKDIR}/bin/${_dest};
MODCLANG_post-patch +=	echo '\#!/bin/sh' >${WRKDIR}/bin/${_dest};
MODCLANG_post-patch +=	echo exec ccache ${LOCALBASE}/bin/${_src} \"\$$@\"
MODCLANG_post-patch +=	>>${WRKDIR}/bin/${_dest};
MODCLANG_post-patch +=	chmod +x ${WRKDIR}/bin/${_dest};
.    endfor
.  else
.    for _src _dest in ${_MODCLANG_LINKS}
MODCLANG_post-patch += ln -sf ${LOCALBASE}/bin/${_src} ${WRKDIR}/bin/${_dest};
.    endfor
.  endif
.endif

SUBST_VARS+=	MODCLANG_VERSION
