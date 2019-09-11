#include <iostream>
#include <memory>
#include <vector>

/*class Widget : public std::enable_shared_from_this<Widget>
{
    public:
    std::shared_ptr<Widget> Get()
    {
         i++;
         return this->shared_from_this();
    }
    int i{100};
    private:    
};
int main()
{
    std::shared_ptr<Widget> ptr1 = std::make_shared<Widget>();
    /*
     * 
     * std::cout<<ptr1->Get()->i<<std::endl;
    std::shared_ptr<Widget> ptr2 = ptr1->Get();
    std::cout<<ptr2->Get()->i<<std::endl;
    return 0;
}

/*struct S: std::enable_shared_from_this<S> {
    std::shared_ptr<S> get_object() {
        return this->shared_from_this();
    };
    int a{100};
};

int main() {
    std::shared_ptr<S> ptr1 = std::make_shared<S>();
    std::shared_ptr<S> ptr2 = ptr1->get_object();
    std::cout<<ptr1->a<<std::endl;
    std::cout<<ptr2->a<<std::endl;
    // ...
}*/

class Widget{};

int main()
{
    std::shared_ptr<Widget> sp =std::make_shared<Widget>();
    std::weak_ptr<Widget> wp(sp);
    sp = nullptr;
    if(wp.expired())
    {
        std::cout<<"No valid pointer"<<std::endl;
    }
}
