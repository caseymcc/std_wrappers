#ifndef _example_std_h_
#define _example_std_h_

#include "example_std_export.h"

#include <string>
#include <vector>
#include <memory>

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

struct EXAMPLE_STD_EXPORT TestStruct
{
    int number;
    string value;
};

#include "std_wrappers/shared_ptr.h"

STD_WRAP_SHARED_PTR(EXAMPLE_STD_EXTERN, EXAMPLE_STD_EXPORT, TestStruct);

}//namespace example_std

#endif//_example_std_h_
