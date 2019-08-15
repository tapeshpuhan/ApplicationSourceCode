#ifndef READER_TASK_H
#define READER_TASK_H

#include <thread>
#include <future>
#include <atomic>
#include <functional>
#include <mutex>

using  HandlerType = std::function<void(const std::string&)>;

struct CreateTask
{
    CreateTask()=default;
    ~CreateTask()=default;
    void RegisterTask(HandlerType&& task);
    void StartTask(const std::string& name);
    void StopTask();
    private:
     
    void RunTask(const std::string& name);
    
    std::atomic<std::int32_t> count_;
    HandlerType handler_;
    std::mutex lock_;
};

#endif //READER_TASK_H
