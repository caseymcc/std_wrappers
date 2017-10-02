
#ifndef EXAMPLE_STD_EXPORT_H
#define EXAMPLE_STD_EXPORT_H

#ifdef EXAMPLE_STD_STATIC_DEFINE
#  define EXAMPLE_STD_EXPORT
#  define EXAMPLE_STD_NO_EXPORT
#else
#  ifndef EXAMPLE_STD_EXPORT
#    ifdef EXAMPLE_STD_EXPORTS
        /* We are building this library */
#      define EXAMPLE_STD_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define EXAMPLE_STD_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef EXAMPLE_STD_NO_EXPORT
#    define EXAMPLE_STD_NO_EXPORT 
#  endif
#endif

#ifndef EXAMPLE_STD_DEPRECATED
#  define EXAMPLE_STD_DEPRECATED __declspec(deprecated)
#endif

#ifndef EXAMPLE_STD_DEPRECATED_EXPORT
#  define EXAMPLE_STD_DEPRECATED_EXPORT EXAMPLE_STD_EXPORT EXAMPLE_STD_DEPRECATED
#endif

#ifndef EXAMPLE_STD_DEPRECATED_NO_EXPORT
#  define EXAMPLE_STD_DEPRECATED_NO_EXPORT EXAMPLE_STD_NO_EXPORT EXAMPLE_STD_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define EXAMPLE_STD_NO_DEPRECATED
#endif

#endif
