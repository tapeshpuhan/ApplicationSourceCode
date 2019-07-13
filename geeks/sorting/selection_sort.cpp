#include <vector>
#include <iostream>
#include <string>

// find the minimul elemets from the list and swap to the position .
template<typename Type>
void Sort(std::vector<Type>& list)
{
    Type min;
    int pos = 0;
    
    for(int index=0; index < list.size(); ++index)
    {
        min = list[index];
        for(int j = index+1; j < list.size(); ++j)
        {
            if(min > list[j])
            {
                min = list[j];
                pos = j;
            }
        }
        if(min != list[index])
        {
            Type val = list[index];
            list[index] = list[pos];
            list[pos] = val;
        }
    }
}

int main()
{
    std::vector<int> list{65,25,12,22,11,12};
    Sort(list);
    for(auto&at : list)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
