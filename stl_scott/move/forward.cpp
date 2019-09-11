#include <iostream>
using namespace std;


void f(int& a)
{
    cout<<"lvalue "<<a<<endl;
}
void f(int&& a)
{
    cout<<"rvalue "<<a<<endl;
}

template<typename T>
void func(T&& arg)
{
    f(std::forward<T>(arg));
}

int main()
{
    int a = 100;
    func(100);
    return 0;
}
