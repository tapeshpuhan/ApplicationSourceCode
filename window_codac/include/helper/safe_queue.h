//
// Created by Tapeswar on 2/13/20.
//
#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <list>
#include <thread>
#include <vector>
namespace encoder
{

template <typename TYPE_MSG>
class SafeQueue
{
  public:
    SafeQueue()= default;
    void Push(const TYPE_MSG& param);
    void Push(const std::vector<TYPE_MSG>& param);
    TYPE_MSG Pop();
    void ShutDown();
    bool IsEmpty()const ;
    size_t Size() const { return queue_.size(); }
    ~SafeQueue() { ShutDown(); }

  private:
    std::list<TYPE_MSG> queue_;
    std::mutex queue_lock_;
    std::condition_variable lock_cond_;
    std::atomic_bool shut_down_{false};
};

template <typename TYPE_MSG>
void SafeQueue<TYPE_MSG>::Push(const TYPE_MSG& param)
{
    std::unique_lock<std::mutex> lk(queue_lock_);

    queue_.emplace_back(param);
    lk.unlock();
    lock_cond_.notify_one();
}

template <typename TYPE_MSG>
void SafeQueue<TYPE_MSG>::Push(const std::vector<TYPE_MSG>& param)
{
    std::unique_lock<std::mutex> lk(queue_lock_);
    std::copy(begin(param),end(param),std::back_inserter(queue_));
    lk.unlock();
    lock_cond_.notify_one();
}

template <typename TYPE_MSG>
TYPE_MSG SafeQueue<TYPE_MSG>::Pop()
{
    std::unique_lock<std::mutex> lk(queue_lock_);
    lock_cond_.wait(lk, [this]() { return !queue_.empty() || shut_down_.load(); });
    auto task  = queue_.front();
    queue_.pop_front();
    return task;
}

template <typename TYPE_MSG>
void SafeQueue<TYPE_MSG>::ShutDown()
{
    std::unique_lock<std::mutex> lk(queue_lock_);
    shut_down_.store(true);
    queue_.clear();
    lk.unlock();
    lock_cond_.notify_all();
}

template <typename TYPE_MSG>
bool SafeQueue<TYPE_MSG>::IsEmpty()const
{
    return queue_.empty();
}

}  // namespace
#endif  // SAFE_QUEUE_H
