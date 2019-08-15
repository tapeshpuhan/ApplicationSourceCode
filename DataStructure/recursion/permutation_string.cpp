#include <iostream>
#include <string>
#include <vector>

template<typename T>
void print(T var)
{
    for(auto& at : var)
    {
        std::cout<<at<<" ";
    }
    std::cout<<std::endl;
}

void Perm(const std::string& input, int k)
{
    static std::vector<int> flag(input.size());
    static std::vector<char> result(input.size());
    
    std::cout<<"Called k : "<<k<<std::endl;
    
    if(k == input.size())
    {
        std::cout<<" *** Result *** : ";
        print(result);
    }
    else
    {
        for(int i = 0; i < input.size(); ++i)
        {
            if(flag[i] == 0)
            { 
                std::cout<<"k : "<<k<<" i : "<<i<<std::endl;               
                result[k] = input[i];
                flag[i] = 1;
                Perm(input,k+1);
                flag[i] = 0;
               std::cout<<" --- Flag --- : "<<i<<std::endl;
            //    print(flag);
            }
         
        }
    }
}

int main()
{
    Perm("ABC",0);
    return 0;
}
