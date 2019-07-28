#include <iostream>
#include <vector>


std::vector<int> FindMissing(const std::vector<int> input)
{
    std::vector<int> missing;
    int low = *(input.begin());
    int end = *(input.rbegin());
    
    int num = end - low;
    int index = 0;
    //std::cout<<low<<std::endl;
    //std::cout<<num<<std::endl;
    
    for(int i = 0; i < input.size(); ++i)
    {
        if(input.at(i)-index > low)
        {
            int diff = (input.at(i)-index) - low;
            for(int j =0; j < diff; j++)
            {
                missing.push_back(low+index);
                index++;
            }
        }
        index++;
    }
    return missing;
}

int main()
{
    std::vector<int>  input{6,7,8,9,11,12,15,16,17,18,19,25};
    auto missing = FindMissing(input);
    
    for(auto& at : missing)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
