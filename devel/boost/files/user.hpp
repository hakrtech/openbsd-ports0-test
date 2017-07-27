//  (C) Copyright Boost.org 2001.
//  Do not check in modified versions of this file,
//  This file may be customised by the end user, but not by boost.

//
//  Use this file to define a site and compiler specific
//  configuration policy, this version was auto-generated by
//  configure on Sun May 28 16:40:11 MSK 2017
//  With the following options:
//    CXX      = c++
//    CXXFLAGS = -I./../.. -I./../../libs/config/test -O2 -pipe  -Wno-c++11-extensions -Wno-keyword-macro  -Wno-expansion-to-defined -Wno-unused-local-typedef  -DBOOST_NO_CONFIG
//    LDFLAGS  = 
//    LIBS     = -lm -lpthread 
//

// define this to disable all config options,
// excluding the user config.  Use if your
// setup is fully ISO complient, and has no
// useful extentions, or for autoconf generated
// setups:
#ifndef BOOST_NO_CONFIG
#  define BOOST_NO_CONFIG
#endif


// define if you want to disable threading support, even
// when available:
// #define BOOST_DISABLE_THREADS

// define if you want the regex library to use the C locale
// even on Win32:
// #define BOOST_REGEX_USE_C_LOCALE

// define this is you want the regex library to use the C++
// locale:
// #define BOOST_REGEX_USE_CPP_LOCALE


//
// clang autoconf'd values, sorted
//
#define BOOST_HAS_CLOCK_GETTIME
#define BOOST_HAS_DIRENT_H
#define BOOST_HAS_EXPM1
#define BOOST_HAS_GETTIMEOFDAY
#if defined(_SIZEOF_INT_128_)
# define BOOST_HAS_INT128
#endif
#define BOOST_HAS_LOG1P
#define BOOST_HAS_LONG_LONG
#define BOOST_HAS_NANOSLEEP
#define BOOST_HAS_NL_TYPES_H
#define BOOST_HAS_NRVO
#define BOOST_HAS_PARTIAL_STD_ALLOCATOR
#define BOOST_HAS_PTHREADS
#define BOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#define BOOST_HAS_PTHREAD_YIELD
#define BOOST_HAS_RVALUE_REFS
#define BOOST_HAS_SCHED_YIELD
#define BOOST_HAS_SIGACTION
#define BOOST_HAS_STDINT_H
#define BOOST_HAS_TR1_COMPLEX_OVERLOADS
#define BOOST_HAS_UNISTD_H
#define BOOST_HAS_VARIADIC_TMPL
#define BOOST_MSVC6_MEMBER_TEMPLATES
#define BOOST_NO_CXX11_ALIGNAS
#define BOOST_NO_CXX11_ALLOCATOR
#define BOOST_NO_CXX11_CHAR16_T
#define BOOST_NO_CXX11_CHAR32_T
#define BOOST_NO_CXX11_CONSTEXPR
#define BOOST_NO_CXX11_DECLTYPE
#define BOOST_NO_CXX11_DECLTYPE_N3276
#define BOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define BOOST_NO_CXX11_DELETED_FUNCTIONS
#define BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#define BOOST_NO_CXX11_HDR_ATOMIC
#define BOOST_NO_CXX11_HDR_FUNCTIONAL
#define BOOST_NO_CXX11_HDR_FUTURE
#define BOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define BOOST_NO_CXX11_HDR_TUPLE
#define BOOST_NO_CXX11_HDR_TYPE_TRAITS
#define BOOST_NO_CXX11_LAMBDAS
#define BOOST_NO_CXX11_NOEXCEPT
#define BOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS
#define BOOST_NO_CXX11_NULLPTR
#define BOOST_NO_CXX11_RAW_LITERALS
#define BOOST_NO_CXX11_STATIC_ASSERT
#define BOOST_NO_CXX11_TRAILING_RESULT_TYPES
#define BOOST_NO_CXX11_UNICODE_LITERALS
#define BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#define BOOST_NO_CXX11_USER_DEFINED_LITERALS
#define BOOST_NO_CXX14_AGGREGATE_NSDMI
#define BOOST_NO_CXX14_CONSTEXPR
#define BOOST_NO_CXX14_DECLTYPE_AUTO
#define BOOST_NO_CXX14_DIGIT_SEPARATORS
#define BOOST_NO_CXX14_GENERIC_LAMBDAS
#define BOOST_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES
#define BOOST_NO_CXX14_RETURN_TYPE_DEDUCTION
#define BOOST_NO_MS_INT64_NUMERIC_LIMITS

// not autoconf'd removed because of various issues
#define BOOST_NO_CXX11_RVALUE_REFERENCES
#define BOOST_NO_CXX11_SCOPED_ENUMS
#define BOOST_NO_CXX11_SMART_PTR
#define BOOST_NO_CXX11_VARIADIC_TEMPLATES

// not autoconfiged but necessary
#define BOOST_ASIO_HAS_UNISTD_H
#define BOOST_HAS_THREADS
// prevent some warnings all over the place
#define BOOST_PP_VARIADICS_MSVC 0
