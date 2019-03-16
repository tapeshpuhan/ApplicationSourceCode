#include "stl_for_each_algorithm.hpp"
#include <memory>
#include <iostream>

int main()
{
std::vector<std::string> value =  {"1","2","3","4","5","7"};
std::unique_ptr<TestStlAlgorithm> obj_ptr = std::make_unique<TestForEach<std::string>>(value);    

obj_ptr->ProcessInput();
std::cout<<obj_ptr->GetInfo()<<std::endl;
std::cout<<obj_ptr->PrintOutput()<<std::endl;
    return 0;
}