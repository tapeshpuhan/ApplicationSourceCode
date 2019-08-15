#include <string>
#include <iostream>
using namespace std;

int f(int a)
{
    cout<<a<<endl;
}
int main()
{
    int a =100;
    f(a);
    f(a++);
        f(++a);
    return 0;
}
