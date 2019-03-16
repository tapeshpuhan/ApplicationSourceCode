#ifndef STL_ALGORITHM_FOR_EACH_H
#define STL_ALGORITHM_FOR_EACH_H

#include "stl_algorithm.h"
#include <iostream>

template<typename for_each_type>
class  TestForEach : public TestStlAlgorithm
{
    public: 
    explicit TestForEach(const std::vector<for_each_type>& var);
	std::string GetInfo() override;
	void ProcessInput() override;
	std::string PrintOutput() override;
    
    private:
    std::stringstream output_;
    std::vector<for_each_type> test_type_;
};

template<typename for_each_type>
 TestForEach<for_each_type>::TestForEach(const std::vector<for_each_type>& var):test_type_{var}
 {
     
 }
 
template<typename for_each_type>
std::string  TestForEach<for_each_type>::GetInfo() 
 {
     std::stringstream str_info;
     
     str_info<<"test for for each algorithm"<<std::endl;
     str_info<<"This algorithm is to test how for each can be used to \n \
     add all the element of the stl type and diaply the sum "<<std::endl;
     return str_info.str();
 }

  template<typename for_each_type>
void TestForEach<for_each_type>::ProcessInput() 
 {
     for_each_type result ;
     
     std::for_each(test_type_.cbegin(), test_type_.cend(), [&](const for_each_type &var)
     {
         result += var;
         std::cout<<var<<std::endl;
     });
     output_<<result<<std::endl;
 }
   template<typename for_each_type>
 std::string TestForEach<for_each_type>::PrintOutput() 
 {
     return output_.str();
 }


#endif //STL_ALGORITHM_FOR_EACH_H