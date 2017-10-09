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

template<typename _Type>
void testListIter(example_std::list<_Type> &list)
{
    std::cout<<"  Test iterator: ";
    example_std::list<_Type>::iterator iter=list.begin();
    if(iter!=list.end())
    {
        std::cout<<*iter;
        ++iter;
        for(; iter!=list.end(); ++iter)
            std::cout<<", "<<*iter;
        std::cout<<std::endl;
    }

    std::list<_Type> values(list.begin(), list.end());
    std::cout<<"  Test native iterator constructor copy: ";
    std::list<_Type>::iterator nativeIter=values.begin();
    if(nativeIter!=values.end())
    {
        std::cout<<*nativeIter;
        ++nativeIter;
        for(; nativeIter!=values.end(); ++nativeIter)
            std::cout<<", "<<*nativeIter;
        std::cout<<std::endl;
    }

    std::list<_Type> values2;

    values2.assign(list.begin(), list.end());
    std::cout<<"  Test native assign copy: ";
    nativeIter=values2.begin();
    if(nativeIter!=values2.end())
    {
        std::cout<<*nativeIter;
        ++nativeIter;
        for(; nativeIter!=values2.end(); ++nativeIter)
            std::cout<<", "<<*nativeIter;
        std::cout<<std::endl;
    }
}

template<typename _Type>
void listList(example_std::list<_Type> &list)
{
    example_std::list<_Type>::iterator iter=list.begin();
    if(iter!=list.end())
    {
        std::cout<<*iter;
        ++iter;
        for(; iter!=list.end(); ++iter)
            std::cout<<", "<<*iter;
//        std::cout<<std::endl;
    }
}

template<typename _KeyType, typename _ValueType>
void testMapIter(example_std::map<_KeyType, _ValueType> &map)
{
    std::cout<<"  Test iterator: ";
    example_std::map<_KeyType, _ValueType>::iterator iter=map.begin();
    if(iter!=map.end())
    {
        std::cout<<iter->first<<":"<<iter->second;
        ++iter;
        for(; iter!=map.end(); ++iter)
            std::cout<<", "<<iter->first<<":"<<iter->second;;
        std::cout<<std::endl;
    }

    std::map<_KeyType, _ValueType> values(map.begin(), map.end());
    std::cout<<"  Test native iterator constructor copy: ";

    std::map<_KeyType, _ValueType>::iterator nativeIter=values.begin();
    if(nativeIter!=values.end())
    {
        std::cout<<nativeIter->first<<":"<<nativeIter->second;
        ++nativeIter;
        for(; nativeIter!=values.end(); ++nativeIter)
            std::cout<<", "<<nativeIter->first<<":"<<nativeIter->second;;
        std::cout<<std::endl;
    }
}

int main(int argc, char **argv)
{
////////////////////////////////////////////////////////////////////////
//shared_ptr
////////////////////////////////////////////////////////////////////////
    example_std::shared_ptr<example_std::TestStruct> ptr=example_std::testSharedPtrReturn();

    std::cout<<"Test shared_ptr return "<<ptr->number<<", "<<ptr->value.c_str()<<std::endl;
    std::cout<<std::endl;
////////////////////////////////////////////////////////////////////////
//string test
////////////////////////////////////////////////////////////////////////
    example_std::string returnString=example_std::testStringReturn();
    std::cout<<"Test string return"<<std::endl;
    testStringIter(returnString);

    example_std::string returnStringBase=example_std::testStringReturnFromBase();
    std::cout<<"Test string return from base"<<std::endl;
    testStringIter(returnStringBase);

    std::cout<<"Test string edit by ref"<<std::endl;
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

    std::cout<<std::endl;

//    void testVectorEditByType(vector<size_t> &vec);

////////////////////////////////////////////////////////////////////////
//list test
////////////////////////////////////////////////////////////////////////
    example_std::list<size_t> returnList=example_std::testListReturn();

    std::cout<<"Test list return"<<std::endl;
    testListIter(returnList);

    example_std::list<size_t> returnListBase=example_std::testListReturnFromBase();

    std::cout<<"Test list return from base"<<std::endl;
    testListIter(returnListBase);

    example_std::list<size_t> testList;

    testList.push_back(11);
    testList.push_back(22);
    testList.push_back(33);
    testList.push_back(44);
    testList.push_back(55);

    std::cout<<"Test list edit by ref"<<std::endl;
    std::cout<<"  Before edit: ";
    listList(testList);
    std::cout<<std::endl;
    example_std::testListEdit(testList);
    std::cout<<"  After edit: ";
    listList(testList);
    std::cout<<std::endl;

    std::cout<<std::endl;

////////////////////////////////////////////////////////////////////////
//map test
////////////////////////////////////////////////////////////////////////
    example_std::map<example_std::string, int> returnMap=example_std::testMapReturn();

    std::cout<<"Test map return"<<std::endl;
    testMapIter(returnMap);

    example_std::map<example_std::string, int> returnMapBase=example_std::testMapReturnFromBase();

    std::cout<<"Test map base return"<<std::endl;
    testMapIter(returnMapBase);

//    std::map<std::string, int> testMap;
    #if(defined(_WINDOWS))
    system("pause");
#endif

    return 0;
}



