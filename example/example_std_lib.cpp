#include "example_std_lib.h"

namespace example_std
{

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

}//namespace example_std

