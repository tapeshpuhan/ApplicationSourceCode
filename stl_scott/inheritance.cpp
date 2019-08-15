#include <string>
#include <iostream>
using namespace std;
class A {
public:
A(const string& s) { /* ... */ }
string f() { 
        std::cout<<"called f()"<<std::endl;
    return string("hello, world"); 
    }
};
class B : public A {
public:
B() : A(s = f()) 
{
    std::cout<<"called b()"<<std::endl;
}
private:
string s;
};
int main() {
B b;
return 0;
}
