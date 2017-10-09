#ifndef _example_std_lib_h_
#define _example_std_lib_h_

#include "example_std.h"

namespace example_std
{
shared_ptr<TestStruct> testSharedPtrReturn();

string testStringReturn();
string testStringReturnFromBase();

void testStringEdit(string &value);

vector<size_t> testVectorReturn();
vector<size_t> testVectorReturnFromBase();

void testVectorEdit(vector<size_t> &vec);
void testVectorEditByType(vector<size_t> &vec);

map<string, int> testMapReturn();
map<string, int> testMapReturnFromBase();

void testMapEdit(map<string, int> &values);

}//namespace example_std

#endif //_example_std_lib_h_
