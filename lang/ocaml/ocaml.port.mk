# $OpenBSD: ocaml.port.mk,v 1.5 2005/08/09 15:22:54 robert Exp $

# regular file usage for bytecode:
# PLIST               -- bytecode base files
# PFRAG.foo           -- bytecode files for FLAVOR == foo
# PFRAG.no-foo        -- bytecode files for FLAVOR != foo
# extended file usage for nativecode:
# PFRAG.native        -- nativecode base files
# PFRAG.foo-native    -- nativecode files for FLAVOR == foo
# PFRAG.no-foo-native -- nativecode files for FLAVOR != foo

.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "i386" || \
	${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "amd64" || \
	${MACHINE_ARCH} == "powerpc"
MODOCAML_NATIVE=Yes

# include nativecode base files
PKG_ARGS+=-Dnative=1

.else

MODOCAML_NATIVE=No
RUN_DEPENDS+=	::lang/ocaml

# remove native base file entry from PLIST
PKG_ARGS+=-Dnative=0
.endif

BUILD_DEPENDS+=	::lang/ocaml
