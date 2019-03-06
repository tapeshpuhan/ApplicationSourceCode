#ifndef ROS_TIMER_H_INCLUDED
#define ROS_TIMER_H_INCLUDED

#include <condition_variable>
#include <atomic>
#include "timer.h"
#include "ros_event_handler.h"
#include <mutex>
#include <memory>
#include <string>
#include <chrono>

class RosTimerCustom : public TimerCustom
{
public:
    RosTimerCustom()=default;

     void RegisterTime(const TimeHandlerType handler) override;
     void StartTimer(const uint32_t time_ms) override;
     void StopTimer() override;
    ~RosTimerCustom()=default;

private:
    std::mutex timer_lock_;
    std::mutex start_lock_;
    std::condition_variable wakeup_with_condition_;
    std::atomic<bool> stop_timer_;
    TimeHandlerType time_handler_=nullptr;
    std::unique_ptr<RosEventHandler> event_handler_ = nullptr;
    std::atomic<uint32_t> time_ms_;
    void ExicuteTimer();
};


#endif // ROS_TIMER_H_INCLUDED
