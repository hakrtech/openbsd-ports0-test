#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4 sw=4 filetype=make:
#	from: @(#)bsd.subdir.mk	5.9 (Berkeley) 2/1/91
#	$OpenBSD: bsd.port.subdir.mk,v 1.58 2003/08/04 14:45:31 espie Exp $
#	FreeBSD Id: bsd.port.subdir.mk,v 1.20 1997/08/22 11:16:15 asami Exp
#
# The include file <bsd.port.subdir.mk> contains the default targets
# for building ports subdirectories. 
#
#
# +++ variables +++
#
# STRIP		The flag passed to the install program to cause the binary
#		to be stripped.  This is to be used when building your
#		own install script so that the entire system can be made
#		stripped/not-stripped using a single knob. [-s]
#
# ECHO_MSG	Used to print all the '===>' style prompts - override this
#		to turn them off [echo].
#
# OPSYS		Get the operating system type [`uname -s`]
#
# SUBDIR	A list of subdirectories that should be built as well.
#		Each of the targets will execute the same target in the
#		subdirectories.
#
#
# +++ targets +++
#
#	README.html:
#		Creating README.html for package.
#
#	afterinstall, all, beforeinstall, build, checksum, clean,
#	configure, depend, describe, extract, fetch, fetch-list,
#	install, package, readmes, deinstall, reinstall,
#	tags
#

# recent /usr/share/mk/* should include bsd.own.mk, guard for older versions
.if !defined(BSD_OWN_MK)
.  include <bsd.own.mk>
.endif

.if defined(show)
.MAIN: show
.elif defined(clean)
.MAIN: clean
.else
.MAIN: all
.endif

.if !defined(DEBUG_FLAGS)
STRIP?=	-s
.endif

.if !defined(OPSYS)	# XXX !!
OPSYS=	OpenBSD
.endif

.include "${PORTSDIR}/infrastructure/mk/pkgpath.mk"

ECHO_MSG?=	echo

REPORT_PROBLEM?=exit 1

# create a full list of SUBDIRS...
.if empty(PKGPATH)
_FULLSUBDIR:=${SUBDIR}
.else
_FULLSUBDIR:=${SUBDIR:S@^@${PKGPATH}/@g}
.endif

_SKIPPED=
.for i in ${SKIPDIR}
_SKIPPED+=${_FULLSUBDIR:M$i}
_FULLSUBDIR:=${_FULLSUBDIR:N$i}
.endfor


_SUBDIRUSE: .USE
.  for i in ${_SKIPPED}
	@echo "===> $i skipped"
.  endfor
.  for d in ${_FULLSUBDIR}
	@dir=$d; ${_flavor_fragment}; \
	${ECHO_MSG} "===> $d"; \
	set +e; \
	if eval  $$toset ${MAKE} ${.TARGET}; then :; \
	else ${REPORT_PROBLEM}; fi
.endfor

_SUBDIRUSE_DEP: .USE
.  for i in ${_SKIPPED}
	@echo "===> $i skipped"
.  endfor
	@${_depfile_fragment}; for d in ${_FULLSUBDIR}; do \
		dir=$$d; \
		${_flavor_fragment}; \
		${ECHO_MSG} "===> $$d"; \
		set +e; \
		if ! eval  $$toset ${MAKE} ${.TARGET}; then \
			${REPORT_PROBLEM}; \
		fi; \
	done

.for __target in all fetch package fake extract configure \
		 build describe distclean deinstall install \
		 reinstall checksum show fetch-makefile \
		 link-categories unlink-categories regress lib-depends-check \
		 homepage-links manpages-check

${__target}: _SUBDIRUSE
.endfor

.for __target in all-dir-depends build-dir-depends run-dir-depends

${__target}: _SUBDIRUSE_DEP
.endfor

.if defined(clean) && ${clean:L:Mdepends}
clean:
.  for i in ${_SKIPPED}
	@echo "===> $i skipped"
.  endfor
	@${_depfile_fragment}; for d in ${_FULLSUBDIR}; do \
		dir=$$d; \
		${_flavor_fragment}; \
		set +e; \
		if ! eval  $$toset ${MAKE} all-dir-depends ECHO_MSG=:; then \
			${REPORT_PROBLEM}; \
		fi; \
	done| tsort -r|while read dir; do \
		unset FLAVOR SUBPACKAGE || true; \
		${_flavor_fragment}; \
		eval $$toset ${MAKE} _CLEANDEPENDS=No clean; \
	done
.else
clean: _SUBDIRUSE
.endif
.if defined(clean) && ${clean:L:Mreadmes}
	rm -f ${.CURDIR}/README.html
.endif

readmes: _SUBDIRUSE
	@rm -f ${.CURDIR}/README.html
	@cd ${.CURDIR} && exec ${MAKE} README.html

TEMPLATES ?= ${PORTSDIR}/infrastructure/templates
.if defined(PORTSTOP)
README=	${TEMPLATES}/README.top
.else
README=	${TEMPLATES}/README.category
.endif

README.html:
	@>$@.tmp
.for d in ${_FULLSUBDIR}
	@dir=$d; ${_flavor_fragment}; \
	name=`eval $$toset ${MAKE} _print-packagename`; \
	case $$name in \
		README) comment='';; \
		*) comment=`eval $$toset ${MAKE} show=_COMMENT|sed -e 's,^",,' -e 's,"$$,,' |${HTMLIFY}`;; \
	esac; \
	cd ${.CURDIR}; \
	echo "<dt><a href=\"${PKGDEPTH}$$dir/$$name.html\">$d</a><dd>$$comment" >>$@.tmp
.endfor
	@cat ${README} | \
		sed -e 's%%CATEGORY%%'`echo ${.CURDIR} | sed -e 's.*/\([^/]*\)$$\1'`'g' \
			-e '/%%DESCR%%/r${.CURDIR}/pkg/DESCR' -e '//d' \
			-e '/%%SUBDIR%%/r$@.tmp' -e '//d' \
		> $@
	@rm $@.tmp

_print-packagename:
	@echo "README"

.PHONY: all fetch fetch-list package extract configure build clean \
	describe distclean deinstall reinstall checksum mirror-distfiles \
	list-distfiles show readmes \
	install fake \
	all-packages cdrom-packages ftp-packages packageinstall \
	link-categories unlink-categories dir-depends package-dir-depends \
	regress lib-depends-check homepage-links manpages-check \
	print-packagename
