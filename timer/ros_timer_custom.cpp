#include "ros_timer.h"

void RosTimerCustom::RegisterTime(const TimeHandlerType handler)
{
    if(nullptr == time_handler_)
    {
        time_handler_ = handler;
    }

    event_handler_ = std::make_unique<RosEventHandler>();
    if(nullptr != event_handler_)
    {
     event_handler_->RegisterEvents("start_timer",[&](){ExicuteTimer();});
    }
}

void RosTimerCustom::StartTimer(const uint32_t time_ms)
{
    std::lock_guard<std::mutex> lk(start_lock_);
    
    time_ms_.store(time_ms);
    stop_timer_.store(false);
    if(nullptr != event_handler_)
    {
        event_handler_->ExecuteEvent("start_timer");
    }
}

void RosTimerCustom::StopTimer()
{
    std::lock_guard<std::mutex> lock(timer_lock_);
    stop_timer_.store(true);
    wakeup_with_condition_.notify_one();
}

void RosTimerCustom::ExicuteTimer()
{
	std::cout<<"Execute time"<<std::endl;
    std::unique_lock<std::mutex> lock(timer_lock_);
    if(false == wakeup_with_condition_.wait_for(lock,std::chrono::milliseconds(100*time_ms_.load()),[&]()
                    {
                        return stop_timer_.load() == true;
                    }))
    {            
        if(nullptr != time_handler_)
        {            
            time_handler_();
        }
    }
}
