#undef EXAMPLE_STD_EXPORTS

#include "example_std_lib.h"
#include <iostream>

void testStringIter(example_std::string &value)
{
    std::cout<<"  Test indexing: ";
    if(!value.empty())
    {
        std::cout<<value[0];
        for(size_t i=1; i<value.size(); ++i)
            std::cout<<", "<<value[i];
        std::cout<<std::endl;
    }

    std::cout<<"  Test iterator: ";
    example_std::string::iterator iter=value.begin();
    if(iter!=value.end())
    {
        std::cout<<*iter;
        ++iter;
        for(; iter!=value.end(); ++iter)
            std::cout<<", "<<*iter;
        std::cout<<std::endl;
    }

    std::string values(value.begin(), value.end());
    std::cout<<"  Test native iterator constructor copy: "<<values;
    std::cout<<std::endl;

    std::string values2;
    values2.assign(value.begin(), value.end());
    std::cout<<"  Test native assign copy: "<<values2;
    std::cout<<std::endl;
}

template<typename _Type>
void listVector(example_std::vector<_Type> &vec)
{
    if(!vec.empty())
    {
        std::cout<<vec[0];
        for(size_t i=1; i<vec.size(); ++i)
            std::cout<<", "<<vec[i];
    }
}

template<typename _Type>
void testVectorIter(example_std::vector<_Type> &vec)
{
    std::cout<<"  Test indexing: ";
    if(!vec.empty())
    {
        std::cout<<vec[0];
        for(size_t i=1; i<vec.size(); ++i)
            std::cout<<", "<<vec[i];
        std::cout<<std::endl;
    }

    std::cout<<"  Test iterator: ";
    example_std::vector<_Type>::iterator iter=vec.begin();
    if(iter!=vec.end())
    {
        std::cout<<*iter;
        ++iter;
        for(; iter!=vec.end(); ++iter)
            std::cout<<", "<<*iter;
        std::cout<<std::endl;
    }

    std::vector<_Type> values(vec.begin(), vec.end());
    std::cout<<"  Test native iterator constructor copy: ";
    if(!values.empty())
    {
        std::cout<<values[0];
        for(size_t i=1; i<values.size(); ++i)
            std::cout<<", "<<values[i];
        std::cout<<std::endl;
    }

    std::vector<_Type> values2;
    
    values2.assign(vec.begin(), vec.end());
    std::cout<<"  Test native assign copy: ";
    if(!values2.empty())
    {
        std::cout<<values2[0];
        for(size_t i=1; i<values2.size(); ++i)
            std::cout<<", "<<values2[i];
        std::cout<<std::endl;
    }
}

int main(int argc, char **argv)
{
////////////////////////////////////////////////////////////////////////
//string test
////////////////////////////////////////////////////////////////////////
    example_std::string returnString=example_std::testStringReturn();
    std::cout<<"Test string return"<<std::endl;
    testStringIter(returnString);

    example_std::string returnStringBase=example_std::testStringReturnFromBase();
    std::cout<<"Test string return from base"<<std::endl;
    testStringIter(returnStringBase);

    std::cout<<"Test vector edit by ref"<<std::endl;
    example_std::string testString("Test string");
    std::cout<<"  Before edit: "<<testString.c_str()<<std::endl;
    example_std::testStringEdit(testString);
    std::cout<<"  After edit: "<<testString.c_str()<<std::endl;

    std::cout<<std::endl;

////////////////////////////////////////////////////////////////////////
//vector test
////////////////////////////////////////////////////////////////////////
    example_std::vector<size_t> returnVec=example_std::testVectorReturn();

    std::cout<<"Test vector return"<<std::endl;
    testVectorIter(returnVec);
    
    example_std::vector<size_t> returnVecBase=example_std::testVectorReturnFromBase();

    std::cout<<"Test vector return from base"<<std::endl;
    testVectorIter(returnVecBase);

    example_std::vector<size_t> testVec;

    testVec.push_back(11);
    testVec.push_back(22);
    testVec.push_back(33);
    testVec.push_back(44);
    testVec.push_back(55);

    std::cout<<"Test vector edit by ref"<<std::endl;
    std::cout<<"  Before edit: ";
    listVector(testVec);
    std::cout<<std::endl;

    example_std::testVectorEdit(testVec);
    std::cout<<"  After edit: ";
    listVector(testVec);
    std::cout<<std::endl;

//    void testVectorEditByType(vector<size_t> &vec);

#if(defined(_WINDOWS))
    system("pause");
#endif

    return 0;
}


