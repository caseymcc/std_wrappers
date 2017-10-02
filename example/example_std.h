#ifndef _example_std_h_
#define _example_std_h_

#include "example_std_export.h"

#include <string>
#include <vector>

#ifdef EXAMPLE_STD_EXPORTS
#define EXAMPLE_STD_EXTERN
#define STD_WRAPPER_EXPORT
#else
#define EXAMPLE_STD_EXTERN extern
#endif

#include "std_wrappers/macro.h"

namespace example_std
{

#include "std_wrappers/string.h"
#include "std_wrappers/vector.h"

STD_WRAP_STRING(EXAMPLE_STD_EXTERN, EXAMPLE_STD_EXPORT);
STD_WRAP_VECTOR(EXAMPLE_STD_EXTERN, EXAMPLE_STD_EXPORT, size_t);

}//namespace example_std

#endif//_example_std_h_
