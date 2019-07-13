#include "prio_queue.h"

int main()
{
    PrioQueue<int> queue_;
    queue_.Push(4);
    queue_.Push(10);
    queue_.Push(3);
    queue_.Push(5);    
    queue_.Push(1);
    queue_.Push(100);
    queue_.Push(25);
    queue_.Push(67);
    queue_.Push(23);
    queue_.Push(5);    
   // queue_.print();
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    std::cout<<queue_.Pop()<<std::endl;
    
    
    return 0;
}
