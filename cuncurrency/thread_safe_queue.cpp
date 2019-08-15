#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
#include <deque>
#include <condition_variable>

template<typename T>
class SafeQueue
{
    public:
    SafeQueue()=default;
    ~SafeQueue()=default;
    
    void Push(const T& value)
    {
        std::lock_guard<std::mutex> lk(lock_);
     std::cout<<"push value "<<value<<std::endl;
        queue_.push_back(std::move(std::make_unique<T>(value)));
        condition_.notify_all();
    }
    T Pop()
    {
        std::unique_lock<std::mutex> lk(lock_);
        condition_.wait(lk, [this]{return !queue_.empty();});
        
        tDataType value = std::move(queue_.front());
        queue_.pop_front();
        std::cout<<"*value "<<*value<<std::endl;
        return *value;        
    }
    private:
    
    using tDataType = std::unique_ptr<T>;
    std::deque<tDataType> queue_;
    std::mutex lock_;
    std::condition_variable condition_;
    
};

struct Mythread
{
    Mythread()=default;
    ~Mythread()=default;
    
    void Add()
    {
        std::thread th([&]{
                stare_.Push(a++);
            });
        if(th.joinable())
        {
            th.detach();
        }
    }
    
    int Get()
    {
        int x;
        std::thread th([&]{
              x =  stare_.Pop();
            });
        if(th.joinable())
        {
            th.detach();
        }
        return x;
    }
    private:
  
    SafeQueue<int> stare_;
    int a{0};
};

int main()
{
    Mythread obj;
    int cout = 0;
    
    while(1)
    {
        obj.Add();
        std::cout<<obj.Get()<<std::endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout<<obj.Get()<<std::endl;
        std::cout<<obj.Get()<<std::endl;
    }
    return 0;
}
