# $OpenBSD: Makefile,v 1.3 2018/03/17 21:57:08 sthen Exp $

COMMENT-main=		vSphere CLI built on top of govmomi
COMMENT-vcsim=		vCenter and ESXi API based simulator

GH_TAGNAME=		v0.17.0
GH_ACCOUNT=		vmware
GH_PROJECT=		govmomi

PKGNAME-main=		govc-${GH_TAGNAME:C/^v//}
PKGNAME-vcsim=		vcsim-${GH_TAGNAME:C/^v//}

CATEGORIES=		sysutils

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# Apache-2.0
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c pthread

MODULES=		lang/go

MULTI_PACKAGES=		-main -vcsim

pre-patch:
	cp ${MODGO_SUBDIR}/toolbox/hgfs/hgfs_{darwin,openbsd}.go
	cp ${MODGO_SUBDIR}/toolbox/toolbox_{darwin,openbsd}.go

post-configure:
	mkdir -p ${MODGO_WORKSPACE}/src/github.com/vmware
	mv ${WRKSRC} ${MODGO_WORKSPACE}/src/github.com/vmware/

do-build:
.for _d in govc vcsim
	cd ${WRKSRC}/${_d} && ${MODGO_BUILD_CMD}
.endfor

.include <bsd.port.mk>
