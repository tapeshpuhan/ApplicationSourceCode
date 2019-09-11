#include <iostream>
#include <memory>

class Shape
{
};

class custom_delete_type
{
  public:
  void operator()(Shape* ptr)
  {
            std::cout<<"Custorm Deleter functor"<<std::endl;
            delete ptr;   
  }  
};

int main()
{
    
    {
        auto cust_delete = [&](Shape* ptr){
            std::cout<<"Custorm Deleter"<<std::endl;
            delete ptr;
        };
        custom_delete_type obj;
        std::unique_ptr<Shape,custom_delete_type> shape(new Shape, obj); 
    }
    
    {
        custom_delete_type obj;
        std::shared_ptr<Shape> shape(new Shape,obj);
    }   
    return 0;
}
