# $Id: essentials.mk,v 1.3 2000/11/02 16:05:15 brad Exp $ 

SUBDIR += archivers/bzip2
SUBDIR += archivers/gshar+gunshar
SUBDIR += archivers/gtar
SUBDIR += archivers/unzip
SUBDIR += audio/sox
SUBDIR += audio/tosha
SUBDIR += benchmarks/iozone
SUBDIR += devel/autoconf
SUBDIR += devel/automake
SUBDIR += devel/bison
SUBDIR += devel/gettext
SUBDIR += devel/glib
SUBDIR += devel/gmake
SUBDIR += devel/id-utils
SUBDIR += devel/m4
SUBDIR += devel/mm
SUBDIR += editors/emacs
SUBDIR += editors/jove
SUBDIR += graphics/aalib
SUBDIR += graphics/compface
SUBDIR += graphics/gimp
SUBDIR += graphics/jpeg
SUBDIR += graphics/mpeg-lib
SUBDIR += graphics/png
SUBDIR += graphics/tiff
SUBDIR += lang/tcl/8.0
SUBDIR += mail/fetchmail
SUBDIR += mail/metamail
SUBDIR += mail/nmh
SUBDIR += mail/pine
SUBDIR += mail/postfix
SUBDIR += math/gnuplot
SUBDIR += misc/cdrecord
SUBDIR += misc/screen
SUBDIR += net/ethereal
SUBDIR += net/epic4
SUBDIR += net/netpipe
SUBDIR += net/samba
SUBDIR += net/sniffit
SUBDIR += net/wget
SUBDIR += print/enscript
SUBDIR += print/ghostscript/gnu
SUBDIR += print/gv
SUBDIR += shells/bash2
SUBDIR += shells/tcsh
SUBDIR += shells/zsh
SUBDIR += sysutils/xntpd
SUBDIR += x11/Xaw3d
SUBDIR += x11/gtk+
SUBDIR += x11/tk/8.0
SUBDIR += x11/xcolors

.include <bsd.port.subdir.mk>
