#	$OpenBSD: Makefile,v 1.33 2018/03/18 08:56:21 jsg Exp $

BROKEN-sparc64=	Error: the specified option is not accepted in ISB at operand 1 -- isb sy

FLAVORS=	aarch64 arm
FLAVOR?=	arm

COMMENT=	U-Boot firmware
VERSION=	2018.03
REVISION=	0
DISTNAME=	u-boot-${VERSION}
PKGNAME=	u-boot-${FLAVOR}-${VERSION:S/-//}
FULLPKGNAME=	${PKGNAME}
CATEGORIES=	sysutils
HOMEPAGE=	http://www.denx.de/wiki/U-Boot
MAINTAINER=	Jonathan Gray <jsg@openbsd.org>

PATCHFILES=		u-boot-bcm2835_sdhost_freq.patch:1 \
			u-boot-rpi3_lan78xx.patch:2 \
			u-boot-rpi3_32b_lan8xx.patch:3 \
			u-boot-rpi3bp_ident.patch:4 \
			u-boot-net_is_active.patch:5 \
			u-boot-lan7xxx_phylib.patch:6 \
			u-boot-mvebu_8k_distro_boot.patch:7 \
			u-boot-pine64_add_gigabit_fix.patch:8 \
			u-boot-pine64_use_gigabit_fix.patch:9

MASTER_SITES1=		https://patchwork.ozlabs.org/patch/887255/mbox/?/
MASTER_SITES2=		https://patchwork.ozlabs.org/patch/886254/mbox/?/
MASTER_SITES3=		https://patchwork.ozlabs.org/patch/886622/mbox/?/
MASTER_SITES4=		https://patchwork.ozlabs.org/patch/886253/mbox/?/
MASTER_SITES5=		https://patchwork.ozlabs.org/patch/886255/mbox/?/
MASTER_SITES6=		https://patchwork.ozlabs.org/patch/886258/mbox/?/
MASTER_SITES7=		https://patchwork.ozlabs.org/patch/887264/mbox/?/
MASTER_SITES8=		https://patchwork.ozlabs.org/patch/873752/mbox/?/
MASTER_SITES9=		https://patchwork.ozlabs.org/patch/873751/mbox/?/
PATCH_DIST_STRIP=	-p1

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
EXTRACT_SUFX=	.tar.bz2
PKG_ARCH=	*

BUILD_DEPENDS=	devel/dtc \
		devel/swig \
		textproc/gsed

MODULES=	lang/python
MODPY_RUNDEP=	No

MAKE_ENV=	KBUILD_VERBOSE=1 \
		PYTHON="${MODPY_BIN}"

.if "${FLAVOR}" == "aarch64"
BUILD_DEPENDS+=	devel/arm-none-eabi/gcc-linaro,aarch64 \
		sysutils/atf-allwinner
MAKE_ENV+=	CROSS_COMPILE="aarch64-none-elf-"
SUNXI_BL31=	"${LOCALBASE}/share/atf-allwinner/bl31.bin"
.elif "${FLAVOR}" == "arm"
BUILD_DEPENDS+=	devel/arm-none-eabi/gcc-linaro
MAKE_ENV+=	CROSS_COMPILE="arm-none-eabi-"
.endif

USE_GMAKE=	Yes
NO_TEST=	Yes

.if "${FLAVOR}" == "aarch64"
SUNXI64=\
	a64-olinuxino \
	bananapi_m64 \
	nanopi_a64 \
	nanopi_neo2 \
	orangepi_pc2 \
	orangepi_prime \
	orangepi_win \
	pine64_plus \
	sopine_baseboard
BOARDS=\
	mvebu_espressobin-88f3720 \
	mvebu_mcbin-88f8040 \
	qemu_arm64 \
	rpi_3
.elif "${FLAVOR}" == "arm"
OMAP=\
	omap3_beagle \
	omap4_panda \
	am335x_boneblack \
	am57xx_evm
SUNXI64=
SUNXI=\
	A10-OLinuXino-Lime \
	A10s-OLinuXino-M \
	A20-OLinuXino-Lime \
	A20-OLinuXino-Lime2 \
	A20-OLinuXino-Lime2-eMMC \
	A20-OLinuXino_MICRO \
	Bananapi \
	Bananapi_m2m \
	Bananapro \
	CHIP \
	CHIP_pro \
	Cubieboard \
	Cubieboard2 \
	Cubieboard4 \
	Cubietruck \
	Lamobo_R1 \
	Linksprite_pcDuino \
	Linksprite_pcDuino3 \
	Linksprite_pcDuino3_Nano \
	nanopi_neo \
	Orangepi \
	Orangepi_mini \
	orangepi_2 \
	orangepi_lite \
	orangepi_one \
	orangepi_pc \
	orangepi_pc_plus \
	orangepi_plus \
	orangepi_plus2e \
	orangepi_zero \
	Sinovoip_BPI_M2_Plus
IMX=\
	cm_fx6 \
	mx6cuboxi \
	mx6qsabrelite \
	nitrogen6q \
	novena \
	riotboard \
	udoo \
	usbarmory \
	wandboard
BOARDS=\
	${OMAP} \
	${SUNXI} \
	${IMX} \
	clearfog \
	qemu_arm \
	rpi_2 \
	rpi_3_32b \
	tinker-rk3288 \
	turris_omnia \
	vexpress_ca15_tc2 \
	vexpress_ca9x4
.endif

FILES=\
	MLO \
	SPL \
	u-boot \
	u-boot.img \
	u-boot.bin \
	u-boot-sunxi-with-spl.bin \
	u-boot.imx \
	u-boot-spl.kwb \
	u-boot-with-spl.bin \
	u-boot.itb \
	spl/sunxi-spl.bin

pre-build:
.for f in ${MODPY_ADJ_FILES}
	${MODPY_BIN_ADJ} ${WRKSRC}/${f}
.endfor

do-build:
.for BOARD in ${BOARDS}
	cd ${WRKSRC} && \
	    mkdir -p build/${BOARD} && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
	        O="build/${BOARD}" \
	        -f ${MAKE_FILE} "${BOARD}"_defconfig && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
	        O="build/${BOARD}" \
	        -f ${MAKE_FILE} ${ALL_TARGET}
.if "${BOARD}" == "tinker-rk3288"
	cd ${WRKSRC}/build/${BOARD} && \
	    tools/mkimage -n rk3288 -T rksd -d spl/u-boot-spl-dtb.bin \
	    u-boot-with-spl.bin && \
	    cat u-boot-dtb.bin >> u-boot-with-spl.bin
.endif
.endfor
.for BOARD in ${SUNXI64}
	cd ${WRKSRC} && \
	    mkdir -p build/${BOARD} && \
	    ${SETENV} ${MAKE_ENV} BL31=${SUNXI_BL31} ${MAKE_PROGRAM} \
	        ${MAKE_FLAGS} O="build/${BOARD}" \
	        -f ${MAKE_FILE} "${BOARD}"_defconfig && \
	    ${SETENV} ${MAKE_ENV} BL31=${SUNXI_BL31} ${MAKE_PROGRAM} \
	        ${MAKE_FLAGS} O="build/${BOARD}" \
	        -f ${MAKE_FILE} ${ALL_TARGET}
	if [[ -f ${WRKSRC}/build/${BOARD}/spl/sunxi-spl.bin && \
	      -f ${WRKSRC}/build/${BOARD}/u-boot.itb ]]; then \
		cd ${WRKSRC}/build/${BOARD} && \
		    cat spl/sunxi-spl.bin u-boot.itb > u-boot-sunxi-with-spl.bin ; \
	fi
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/u-boot
.for BOARD in ${BOARDS} ${SUNXI64}
	${INSTALL_DATA_DIR} ${PREFIX}/share/u-boot/${BOARD}
	-cd ${WRKSRC}/build/${BOARD} && \
	    cp ${FILES} ${PREFIX}/share/u-boot/${BOARD}/
.endfor

.include <bsd.port.mk>
