#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED



#include <functional>
#include <cstdint>
#include <iostream>

struct TimerCustom
{
using TimeHandlerType = std::function<void()>;
    TimerCustom()=default;

    virtual void RegisterTime(const TimeHandlerType handler) = 0;
    virtual void StartTimer(const uint32_t time_ms) = 0;
    virtual void StopTimer() = 0;
    virtual ~TimerCustom()=default;

};

#endif // TIMER_H_INCLUDED
