#include <iostream>

template<typename T>
void fun( T&& arg)
{
    std::cout<<"univarsal referance"<<std::endl;
    
}

void fun(int&& arg)
{
    std::cout<<"rvalue referance"<<std::endl;
    
}

void fun(int& arg)
{
    std::cout<<"lvalue referance"<<std::endl;
    
}

int main()
{
    int a;
    int&  b =a;    
    const int& c =b;
    
    fun(100);
    fun(a);
    fun(std::move(b));
    fun(b);
    fun(c);
    auto& & at = b;
    return 0;
}
