#ifndef __MY_PLAYER__
#define __MY_PLAYER__

#include "ros_event_handler.h"
#include <memory>
#include <iostream>

class MyPlayer
{
    public:
    
    MyPlayer() =  default;
    
    void Init();
    void Play();
    void Pause();
    void Slow();
    void DeInit();
    ~MyPlayer() = default;
    private:
    void player_handler();
    void pause_handler();
    void slow_handler();
    
    std::unique_ptr<EventHandler> event_handler_ptr_;
};

#endif
