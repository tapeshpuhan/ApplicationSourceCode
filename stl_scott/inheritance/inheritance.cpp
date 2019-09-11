#include <iostream>
class Base {
private:
int x;
public:
virtual void mf1() = 0;
virtual void mf1(int){std::cout<<"Base::mf1"<<std::endl;}
virtual void mf2(){std::cout<<"Base::mf2"<<std::endl;}
void mf3(){std::cout<<"Base::mf3"<<std::endl;}
void mf3(double){std::cout<<"Base::mf3 double"<<std::endl;}
};
class Derived: public Base {
public:
using Base::mf1;
using Base::mf3;
virtual void mf1(){std::cout<<"Dir::mf1"<<std::endl;}
void mf3(){std::cout<<"Dir::mf3"<<std::endl;}
void mf4(){std::cout<<"Dir::mf4"<<std::endl;}
};

int main()
{
    Derived d;
    int x;
    
    d.mf1();
    d.mf1(x);
    d.mf2();
    d.mf3();
    d.mf3(x);
    return 0;
}
