#include "ros_timer.h"
#include <memory>
#include <iostream>

void handler()
{
    std::cout<<"Time handler"<<std::endl;
}


int main()
{
    std::unique_ptr<TimerCustom> timer_ = std::make_unique<RosTimerCustom>();
    timer_->RegisterTime(handler);
    timer_->StartTimer(100);
    std::cout<<"call stop"<<std::endl;
    timer_->StopTimer();
   
    return 0;
}
