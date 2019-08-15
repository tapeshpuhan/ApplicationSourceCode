#include <iostream>
#include <vector>

template<class T>
// (a) a primary template
void f(T)
{
    std::cout<<"f(T)"<<std::endl;
}
template<class T>
void f(T*)
{
    std::cout<<"f(T*)"<<std::endl;
} 
// (b) a primary template, overloads (a)�function templates
// can't be partially specialized; they overload instead
template<>
void f<int>(int*)
{
    std::cout<<"f<int>(int*)"<<std::endl;
}

int main()
{
    #if 0
    std::vector<int> v;
    v.reserve(2);
    
    v[0] = 1;
    v[1] = 2;
    //v.resize(2,1);
    std::cout<<"Size "<<v.size()<<std::endl;
    std::cout<<"Capacity "<<v.capacity()<<std::endl;
    std::cout<<"value "<<v[0]<<std::endl;
    
    for(auto at = v.begin(); at < v.end(); at++)
    {
        std::cout<<*at<<std::endl;
    }
    #endif
    int *p;
    f(p);
    return 0;
}
