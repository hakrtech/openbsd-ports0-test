#ifndef _VARARGS_H_
#define _VARARGS_H_

/* These macros implement traditional (non-ANSI) varargs
   for GNU C.  */

#define va_alist  __builtin_va_alist

#define	__va_ellipsis	...

/* ??? We don't process attributes correctly in K&R argument context.  */
typedef int __builtin_va_alist_t __attribute__((__mode__(__word__)));

/* ??? It would be nice to get rid of the ellipsis here.  It causes
   current_function_varargs to be set in cc1.  */
#define va_dcl		__builtin_va_alist_t __builtin_va_alist; ...

/* Define __gnuc_va_list, just as in stdarg.h.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

#define va_start(v)	__builtin_varargs_start((v))
#define va_end		__builtin_va_end
#define va_arg		__builtin_va_arg
#define __va_copy(d,s)	__builtin_va_copy((d),(s))

/* Define va_list from __gnuc_va_list.  */

typedef __gnuc_va_list va_list;

#endif /* _VARARGS_H_ */
