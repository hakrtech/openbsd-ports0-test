$OpenBSD: patch-ltmain.sh,v 1.3 2001/09/18 17:27:44 naddy Exp $
--- ltmain.sh.orig	Tue Sep 18 18:36:29 2001
+++ ltmain.sh	Tue Sep 18 18:40:45 2001
@@ -1079,6 +1079,10 @@ compiler."
 	    # These systems don't actually have c library (as such)
 	    continue
 	    ;;
+	  *-*-openbsd*)
+	    # Do not include libc due to us having libc/libc_r.
+	    continue
+	    ;;
 	  esac
 	elif test "$arg" = "-lm"; then
 	  case "$host" in
@@ -1091,6 +1095,10 @@ compiler."
 	deplibs="$deplibs $arg"
 	;;
 
+      -?thread)
+	deplibs="$deplibs $arg"
+	;;
+
       -module)
 	module=yes
 	continue
@@ -1795,6 +1803,9 @@ compiler."
 	*-*-cygwin* | *-*-mingw* | *-*-os2* | *-*-beos*)
 	  # these systems don't actually have a c library (as such)!
 	  ;;
+	*-*-openbsd*)
+	  # Do not include libc due to us having libc/libc_r.
+	  ;;
 	*)
 	  # Add libc to deplibs on all other systems.
 	  deplibs="$deplibs -lc"
@@ -3555,40 +3566,6 @@ libdir='$install_libdir'\
     # Exit here if they wanted silent mode.
     test "$show" = : && exit 0
 
-    echo "----------------------------------------------------------------------"
-    echo "Libraries have been installed in:"
-    for libdir in $libdirs; do
-      echo "   $libdir"
-    done
-    echo
-    echo "If you ever happen to want to link against installed libraries"
-    echo "in a given directory, LIBDIR, you must either use libtool, and"
-    echo "specify the full pathname of the library, or use \`-LLIBDIR'"
-    echo "flag during linking and do at least one of the following:"
-    if test -n "$shlibpath_var"; then
-      echo "   - add LIBDIR to the \`$shlibpath_var' environment variable"
-      echo "     during execution"
-    fi
-    if test -n "$runpath_var"; then
-      echo "   - add LIBDIR to the \`$runpath_var' environment variable"
-      echo "     during linking"
-    fi
-    if test -n "$hardcode_libdir_flag_spec"; then
-      libdir=LIBDIR
-      eval flag=\"$hardcode_libdir_flag_spec\"
-
-      echo "   - use the \`$flag' linker flag"
-    fi
-    if test -n "$admincmds"; then
-      echo "   - have your system administrator run these commands:$admincmds"
-    fi
-    if test -f /etc/ld.so.conf; then
-      echo "   - have your system administrator add LIBDIR to \`/etc/ld.so.conf'"
-    fi
-    echo
-    echo "See any operating system documentation about shared libraries for"
-    echo "more information, such as the ld(1) and ld.so(8) manual pages."
-    echo "----------------------------------------------------------------------"
     exit 0
     ;;
 
