#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>

class MyThread
{
    public:
    MyThread()=default;
    void ThreadHandler(int a);
    void ThreadHandler1(int a);
    ~MyThread()= default;
    private:
    int count{1};
    std::recursive_mutex lock_;
    std::mutex lock1_;
};

void MyThread::ThreadHandler(int a)
{
    std::cout<<"I am in a thread ThreadHandler "<<std::this_thread::get_id()<<" a "<<a<<std::endl;
    std::lock_guard<std::recursive_mutex> lk(lock_);
    
    count = a;
    while(1)
    {
        count++;
        std::cout<<count<<" :: "<<std::this_thread::get_id()<<std::endl;
         	
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void MyThread::ThreadHandler1(int a)
{
    //std::lock_guard<std::mutex> lk(lock1_);
    std::cout<<"I am in a thread ThreadHandler1 "<<std::this_thread::get_id()<<" a "<<a<<std::endl;
    count = a;
    while(1)
    {
        count++;
        std::cout<<count<<" :: "<<std::this_thread::get_id()<<std::endl;
         	
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main()
{
    std::unique_ptr<MyThread> obj = std::make_unique<MyThread>();
    //std::unique_ptr<MyThread> obj1 = std::make_unique<MyThread>();
    std::thread th(&MyThread::ThreadHandler,std::move(obj),100);
    //std::thread th2(&MyThread::ThreadHandler,std::move(obj),1000);
    if(th.joinable())
     //   th.join();
        th.detach();
        
    //if(th2.joinable())
      //  th2.join();
        //th2.detach();
        
    while(1)
    {
        std::cout<<"main thread "<<std::this_thread::get_id()<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}
