# $OpenBSD: Makefile,v 1.63 2017/11/21 00:13:03 naddy Exp $

COMMENT=	format files for printing on PostScript printers

DISTNAME=	a2ps-4.14
REVISION=	13

SHARED_LIBS +=  a2ps                 2.0      # 2.0

CATEGORIES=	print

HOMEPAGE=	https://www.gnu.org/software/a2ps/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv3 or later, includes AFM files from Adobe with still unclear
# terms (see ${WRKSRC}/afm/MustRead.html).
PERMIT_PACKAGE_CDROM=	without charge
PERMIT_PACKAGE_FTP=	Yes

WANTLIB =  c iconv intl m paper

MASTER_SITES=	${MASTER_SITE_GNU:=a2ps/}

BUILD_DEPENDS=	devel/gperf \
		print/psutils

RUN_DEPENDS=	print/psutils

LIB_DEPENDS=	devel/gettext \
		print/libpaper

MODGNU_CONFIG_GUESS_DIRS=	${WRKSRC} ${WRKSRC}/auxdir

CONFIGURE_STYLE=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_prog_EMACS=no \
		lispdir=${PREFIX}/share/a2ps/emacs

.for p in bzip2 gv ghostview dvips pdf2ps tex latex ps2pdf \
	  bzip distill netscape html2ps grog convert
CONFIGURE_ENV+= ac_cv_prog_COM_$p=no
.endfor

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure \
		${WRKSRC}/etc/a2ps_cfg.in \
		${WRKSRC}/etc/a2ps-site.cfg.in

pre-build:
	/usr/bin/touch $(WRKSRC)/doc/*.info
	/usr/bin/touch $(WRKSRC)/doc/*.dvi

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/a2ps
	mv ${WRKINST}${SYSCONFDIR}/a2ps.cfg ${PREFIX}/share/examples/a2ps
	mv ${WRKINST}${SYSCONFDIR}/a2ps-site.cfg ${PREFIX}/share/examples/a2ps

.include <bsd.port.mk>
