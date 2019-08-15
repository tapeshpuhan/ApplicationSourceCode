#include "reader_task.h"
#include <memory>
#include <iostream>
void handel(const std::string& name)
{
    std::cout<<"handel "<<name<<std::endl;
}


int main()
{
    std::unique_ptr<CreateTask> tash_ptr = std::make_unique<CreateTask>();
    tash_ptr->RegisterTask([&](const std::string& name){
            handel(name);
        });
    tash_ptr->StartTask("mytask");
    int flag = 0;
    
    while(1){
        char ch;
        
            std::cin>>ch;
            if(ch =='s')
            {
              tash_ptr->StopTask();  
              flag = 1;
            }
            else if(flag == 1 )
            {
              tash_ptr->StartTask("new mytask");  
              flag = 0;
            }
    }
    return 0;
}
