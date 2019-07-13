#include <vector>
#include <iostream>
#include <string>

// swap adjucent values is they are in not in correct order
template<typename Type>
void Sort(std::vector<Type>& list)
{
    for(int index=0; index < list.size(); ++index)
    {
        for(int j = 0; j < list.size(); ++j)
        {
            if(list[index] < list[j])
            {
                    Type val = list[index];
                    list[index] = list[j];
                    list[j] = val;                
            }
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
