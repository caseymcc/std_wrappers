#include "example_std_lib.h"

namespace example_std
{

shared_ptr<TestStruct> testSharedPtrReturn()
{
    shared_ptr<TestStruct> ptr(new TestStruct);

    ptr->number=1;
    ptr->value="test shared";

    return ptr;
}

string testStringReturn()
{
    string value="example from string";

    return value;
}

string testStringReturnFromBase()
{
    std::string value="example from std::string";

    return string(value);
}

void testStringEdit(string &value)
{
    value+=" edit";
}


vector<size_t> testVectorReturn()
{
    vector<size_t> values;

    values.push_back(10);
    values.push_back(20);
    values.push_back(30);
    values.push_back(40);
    values.push_back(50);
    values.push_back(60);
    values.push_back(70);
    values.push_back(80);
    values.push_back(90);
    values.push_back(100);

    return values;
}

vector<size_t> testVectorReturnFromBase()
{
    std::vector<size_t> values;

    values.push_back(10);
    values.push_back(20);
    values.push_back(30);
    values.push_back(40);
    values.push_back(50);
    values.push_back(60);
    values.push_back(70);
    values.push_back(80);
    values.push_back(90);
    values.push_back(100);

    return vector<size_t>(values);
}

void testVectorEdit(vector<size_t> &vec)
{
    if(!vec.empty())
        vec.erase(vec.begin());

    vec.push_back(99);
}

void testVectorEditByType(vector<size_t> &vec)
{
//    std::vector<size_t> &values=vec.base();
//
//    if(!values.empty())
//        values.erase(values.begin());
//
//    values.push_back(99);
}

map<string, int> testMapReturn()
{
    map<string, int>  values;

    values["test1"]=1;
    values["test2"]=2;
    values["test3"]=3;
    values["test4"]=4;
    values["test5"]=5;

    return values;
}

map<string, int> testMapReturnFromBase()
{
    std::map<string, int>  values;

    values["test6"]=6;
    values["test7"]=7;
    values["test8"]=8;
    values["test9"]=9;
    values["test10"]=10;

    return map<string, int>(values);
}

void testMapEdit(map<string, int> &values)
{
    values["test11"]=11;
    values["test12"]=12;
}

}//namespace example_std

