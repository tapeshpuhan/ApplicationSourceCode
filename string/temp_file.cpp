#include <iostream>
#include <string>

std::string CreateTempFile(const std::string& name)
{
    std::string temp_file;
    
    auto index = name.find(".");
    if(index != std::string::npos)
    {
        std::string ext = name.substr(index+1);
        std::string temp_filename = name.substr(0,index+1);
        if(ext != "tmp")
        {            
            temp_file = temp_filename + "tmp";
        }
        else
        {
               temp_file = temp_filename + "xxx";
        }
    }
    else
    {
        temp_file = name +".tmp";        
    }
    
    return temp_file;
}


int main(int argc, char** argv)
{
    if(argc > 1)
    {
        for(int i  =1 ;  i < argc; ++i)
        {
            std::cout<<CreateTempFile(argv[i])<<std::endl;
        }
    }
    
    return 0;
}
