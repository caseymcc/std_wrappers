This repo provides wrappers for standard library templates so that they can be exported from libs and dlls.

The needed templates are expected to be include in both a header and source as follows (preferable in a namspace to reduce conflicts).
You will also need to handle exporting/importing, this can be seen in the example below.

userDefined.h
```c
#include <vector>

#ifdef USER_EXPORTS
#define USER_EXTERN
#else//USER_EXPORTS
#define USER_EXTERN extern
#endif//USER_EXPORTS

#ifdef USER_EXPORTS
#define STD_WRAPPER_EXPORT
#endif//USER_EXPORTS

namespace userDefined
{

#include "std_wrappers\vector.h"

USER_EXTERN template class OPENCL_UTIL_EXPORT vector<::size_t>;
USER_EXTERN template class OPENCL_UTIL_EXPORT vector_iterator<std::vector<::size_t>, typename std::vector<::size_t>::iterator>;
USER_EXTERN template class OPENCL_UTIL_EXPORT vector_const_iterator<std::vector<::size_t>, typename std::vector<::size_t>::const_iterator>;

}//namespace userDefined
```

userDefined.cpp
```c
#include "userDefined.h"

#include <vector>

namespace userDefined
{

#include "std_wrappers\vector.cpp"

}}//namespace userDefined
```

Declaring STD_WRAPPER_EXPORT allows you to set this wrapper directly equal to a std template (and even use the move operations) to minimize performance hits. The wrappers themselves will inclure extra function calls on every call that is made to the lower std template but it allows for easy exchange on the libraries interface at the cost of this overhead.

Currently I have only wrapped std::vector (and its iterators), I plan to do a few more very soon and will update this as I get them working. Also I will create a macro so that the template instantiation is easier than the three lines in the example. 

This is a really rough draft.
