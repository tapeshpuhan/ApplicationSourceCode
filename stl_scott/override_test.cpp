#include <iostream>
#include <memory>

class Base
{
    public :
    virtual float func() &&
    {
        std::cout<<"Base : Func called"<<std::endl;
    }
};

class Derive : public Base
{
    public:
    float func() && override
    {
        std::cout<<"Derive : Func called"<<std::endl;
    }
};

int main()
{
    std::unique_ptr<Base> obj = std::make_unique<Derive>();
    //obj->func();
    return 0;
}
