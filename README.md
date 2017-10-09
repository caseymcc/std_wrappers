This repo provides wrappers for standard library templates so that they can be exported from libs and dlls. So far the following are included.

* shared_ptr
* string
* vector
* map

The templates are expected to be included in the library (lib or dll) by including both a header and source file for the template (preferable in a namspace to reduce conflicts). You need to include the actuall stand library class as well as handle import/exporting of the new classes. There are also provided macros to help with the import/export along with the class instantiation. This all can be seen in the example provided with the source.

example_std.h
```c
#ifndef _example_std_h_
#define _example_std_h_

#include "example_std_export.h"

#include <string>
#include <vector>
#include <memory>
#include <map>

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

#include "std_wrappers/map.h"

STD_WRAP_MAP(EXAMPLE_STD_EXTERN, EXAMPLE_STD_EXPORT, string, int);

}//namespace example_std

#endif//_example_std_h_
```

example_std.cpp
```c
#include "example_std.h"

namespace example_std
{

#include "std_wrappers\shared_ptr.cpp"
#include "std_wrappers\string.cpp"
#include "std_wrappers\vector.cpp"
#include "std_wrappers\map.cpp"

}//namespace example_std
```

Setting up the wrappers this way allows the stand library implementation to be compiled into the library without going through the effort of creating a similar c interface. The wrapped classes can be used like thier base counter parts with some limitations. The should be accesible to an std library algorithm that works off iterators. 

```c
example_std::vector<size_t> vec;

auto iter=std::find(vec.begin(), vec.end(), 2);
```

They can be readily converted to their std counter parts using copy constructors

```c
example_std::vector<size_t> vec;

std::vector<size_t> values(vec.begin(), vec.end());
```

On the library side if you declare STD_WRAPPER_EXPORT this will allow the wrappers to use all of the the functionality of the std versions as well as to allow the wrappers to copy or move directly from the std version.

```c
vector<size_t> testVectorReturnFromBase()
{
    std::vector<size_t> values;

    values.push_back(10);
    values.push_back(20);
 
    return vector<size_t>(values);
}
```

The wrappers themselves will inclure extra function calls on every call that is made to the lower std template but it allows for easy exchange on the libraries interface at the cost of this overhead.

This is a rough draft, feel free to add any support or give feedback.
