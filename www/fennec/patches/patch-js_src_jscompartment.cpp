$OpenBSD: patch-js_src_jscompartment.cpp,v 1.1 2012/01/11 03:42:40 nigel Exp $
https://bugzilla.mozilla.org/show_bug.cgi?id=703534
--- js/src/jscompartment.cpp	Wed Dec 21 00:28:22 2011
+++ js/src/jscompartment.cpp	Sat Dec 24 11:21:34 2011
@@ -50,7 +50,6 @@
 #include "jswatchpoint.h"
 #include "jswrapper.h"
 #include "assembler/wtf/Platform.h"
-#include "assembler/jit/ExecutableAllocator.h"
 #include "yarr/BumpPointerAllocator.h"
 #include "methodjit/MethodJIT.h"
 #include "methodjit/PolyIC.h"
