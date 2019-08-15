#include <iostream>
using namespace std;

/*void foo(int a)
{
    cout<<"foo(int a)"<<endl;
}*/
void foo(int& a)
{
    cout<<"foo(int& a)"<<endl;
}
void foo(const int& a)
{
    cout<<"foo(const int& a)"<<endl;
}
void foo(int&& a)
{
    cout<<"foo(int&& a)"<<endl;
}

constexpr int add(int x){return x + x;} 

int main()
{
    int a = 10;
    foo(a);
    foo(100);
    foo(move(a));
    int b;
  
    cout<<"add "<<add(b)<<endl;
    return 0;
}
