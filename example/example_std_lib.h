#ifndef _example_std_lib_h_
#define _example_std_lib_h_

#include "example_std.h"

namespace example_std
{

string testStringReturn();
string testStringReturnFromBase();

void testStringEdit(string &value);

vector<size_t> testVectorReturn();
vector<size_t> testVectorReturnFromBase();

void testVectorEdit(vector<size_t> &vec);
void testVectorEditByType(vector<size_t> &vec);

}//namespace example_std

#endif //_example_std_lib_h_
