#include <iostream>
#include <vector>

void Reverse(std::vector<int>& array)
{
    for(int i = 0, j = array.size()-1; i < j; i++, j--)
    {
        auto temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }    
}

int main()
{
    std::vector<int> v{1,2,3,4};
    Reverse(v);
    for(auto& at : v)
    {
        std::cout<<at<<std::endl;
    }
}
