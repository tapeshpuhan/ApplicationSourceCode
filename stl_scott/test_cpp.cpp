#include <iostream>
#include <string>
#include <vector>

void f(long int a)
{
  std::cout<<"f(int a)"<<a<<std::endl;
}

void f(bool a)
{
  std::cout<<"f(bool a)"<<a<<std::endl;
}

void f(void* a)
{
  std::cout<<"f(void* a)"<<a<<std::endl;
}

int fun()
{
    int a;
    return  a;
}

class Test
{
    public:
    int func(int a){}
    int func(bool a)=delete;
    int func(double a)=delete;
    int func(char a)=delete;
};

class Widget
{
    public:

    //template<> void Process(void* parm)=delete;
private:
    template<typename T> void Process(T* parm){
        std::cout<<" called "<<std::endl;
    }
//template<> void Process(void* parm){}

};

int main()
{
Test t;
//t.func('d');

Widget y;
void* a;
y.Process(a);
    return 0;
}
