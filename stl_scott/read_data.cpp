#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream file("data.dat");
    
    if(file.is_open())
    {
        //std::vector<int> data(std::istream_iterator<int>(file),std::istream_iterator<int>());
        //std::istream_iterator<int> dbegin(file);
        //std::istream_iterator<int> dend;
        //std::vector<int> data(dbegin,dend);
        std::vector<int> data{std::istream_iterator<int> (file),std::istream_iterator<int>()};
       // std::copy(dbegin,dend,std::back_inserter(data));
        
        for(auto& at : data)
        {
            std::cout<<at<<std::endl;
        }
        
       /* while(dbegin != dend)
        {
            std::cout<<*dbegin<<std::endl;
            dbegin++;
        }*/
    }
    return 0;
}
