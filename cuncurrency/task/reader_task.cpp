#include "reader_task.h"

void CreateTask::RegisterTask(HandlerType&& task_handel)
{
    handler_ = std::move(task_handel); 
}

void CreateTask::StartTask(const std::string& name)
{
    std::lock_guard<std::mutex> lk(lock_);
    count_.store(1);
    
    std::thread thread_handel([&]{
            RunTask(name);
        });
        
    if(thread_handel.joinable())
    {
        thread_handel.detach();
    }
}

void CreateTask::StopTask()
{
    std::lock_guard<std::mutex> lk(lock_);
    count_.store(0);
}

void CreateTask::RunTask(const std::string& name)
{
    while(count_.load())
    {
        if(handler_ != nullptr)
        {
            handler_(name);
        }
    }
}
