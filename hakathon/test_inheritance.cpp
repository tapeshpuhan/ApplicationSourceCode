#include <iostream>
#include <memory>

template<typename T>
class Base
{
    public:
    virtual void call(T a)
    {
        update(a);
    }
    virtual void update(T a) = 0;
};

class Dir : public Base<int>
{
    public:
    virtual void update(int a) override;
};


void Dir::update(int a)
{
    std::cout<<a<<std::endl;
}

int main()
{
    std::unique_ptr<Dir> obj = std::make_unique<Dir>();
    obj->call(100); 
    return 0;
}
