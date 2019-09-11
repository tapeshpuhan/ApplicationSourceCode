#include <iostream>
#include <vector>

template<typename TYPE>
class CircularQueue
{
    public:
    explicit CircularQueue(const size_t size):size_{size},coll_(size){
        if(size_)
        {
           rear_ =  front_+1;
        }
    }
    
    bool EnQueue(const TYPE& value)
    {
        bool sucess = false;
        //std::cout<<front_<<" : "<<rear_<<std::endl;
        if(!IsFull())
        {            
            coll_[rear_] = value;
            rear_ = GetNext(rear_);
            sucess = true;
        }
        return sucess;
    }
    
    TYPE DeQueue()
    {
        TYPE value;
        
        if(!IsEmpty())
        {
           front_ = GetNext(front_);
           
           value = coll_[front_];
        }
    }
        
    private:
    
    bool IsEmpty()const 
    {
        //std::cout<<front_<<" : "<<rear_<<std::endl;
        return GetNext(front_) == rear_;
    }
    bool IsFull()const 
    {
        return front_ == GetNext(front_);
    }
    size_t GetNext(const size_t index) const
    {
        return (((size_+index+1)%size_));
    }
    
    size_t front_{0};
    size_t rear_{0};
    size_t size_;
    std::vector<TYPE> coll_;
};

int main()
{
    CircularQueue<int> queue_(5);
    queue_.EnQueue(1);
    queue_.EnQueue(2);
    queue_.EnQueue(3);
    
    std::cout<<queue_.DeQueue()<<std::endl;
    queue_.EnQueue(4);
    std::cout<<queue_.DeQueue()<<std::endl;
    queue_.EnQueue(5);
    std::cout<<queue_.DeQueue()<<std::endl;
    std::cout<<queue_.DeQueue()<<std::endl;
    std::cout<<queue_.DeQueue()<<std::endl;
    std::cout<<queue_.DeQueue()<<std::endl;
    std::cout<<queue_.DeQueue()<<std::endl;
    std::cout<<queue_.DeQueue()<<std::endl;
    return 0;
}
