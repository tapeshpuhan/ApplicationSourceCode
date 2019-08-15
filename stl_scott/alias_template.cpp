#include <iostream>
#include <vector>

template<typename T>
using ListType = std::vector<T>;

template<typename T>
struct MyListType
{
    typedef std::vector<T> type;
};

int main()
{
    //ListType<int> a{1,2,3};
    MyListType<int>::type a{2,3,4}; 
    for(auto& at : a)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
