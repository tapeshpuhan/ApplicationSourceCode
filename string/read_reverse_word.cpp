#include <iostream>
#include <string>

int main()
{
    const std::string  delm = " ;/t,;";
    std::string line;
    
    while(std::getline(std::cin,line))
    {
        size_t pos_first = line.find_first_not_of(delm);
        size_t pos_last;
        
        while(pos_first != std::string::npos)
        {
            //std::cout<<"pos_first "<<pos_first<<std::endl;
            pos_last = line.find_first_of(delm,pos_first);
            std::cout<<"pos_last "<<pos_last<<std::endl;
            std::string sub_str;
            if(pos_last != std::string::npos)
            {
                sub_str= line.substr(pos_first,pos_last-pos_first+1);
            }
            else
            {
                sub_str= line.substr(pos_first);
            }
            std::cout<<sub_str<<std::endl;
            
            pos_first = line.find_first_not_of(delm,pos_last);
        }
    }
    return 0;
}
