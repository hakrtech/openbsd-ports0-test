# $Id: essentials.mk,v 1.2 2000/04/18 10:51:00 turan Exp $ 

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
SUBDIR += graphics/tiff34
SUBDIR += lang/tcl80
SUBDIR += mail/fetchmail
SUBDIR += mail/metamail
SUBDIR += mail/nmh
SUBDIR += mail/pine
SUBDIR += mail/postfix
SUBDIR += math/gnuplot
SUBDIR += misc/cdrecord
SUBDIR += misc/screen
SUBDIR += net/ethereal
SUBDIR += net/ircii-epic
SUBDIR += net/netpipe
SUBDIR += net/samba
SUBDIR += net/sniffit
SUBDIR += net/wget
SUBDIR += print/enscript
SUBDIR += print/ghostscript5
SUBDIR += print/gv
SUBDIR += shells/bash2
SUBDIR += shells/tcsh
SUBDIR += shells/zsh
SUBDIR += sysutils/xntpd
SUBDIR += x11/Xaw3d
SUBDIR += x11/gtk+
SUBDIR += x11/tk80
SUBDIR += x11/xcolors

.include <bsd.port.subdir.mk>
