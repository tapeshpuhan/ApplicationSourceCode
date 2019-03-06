#include "my_player.h"
#include <chrono>
    
    void MyPlayer::Init()
    {
        event_handler_ptr_ = std::make_unique<RosEventHandler>();
        
        if(nullptr != event_handler_ptr_)
        {
            event_handler_ptr_->RegisterEvents("play",[&]()
            {
                player_handler();
            });
            event_handler_ptr_->RegisterEvents("pause",[&]()
            {
                pause_handler();
            });
            event_handler_ptr_->RegisterEvents("slow",[&]()
            {
                slow_handler();
            });
        }
    }
    void MyPlayer::Play()
    {
        if(nullptr != event_handler_ptr_)
        {
            event_handler_ptr_->ExecuteEvent("play");
        }
    }
    void MyPlayer::Pause()
    {
        if(nullptr != event_handler_ptr_)
        {
            event_handler_ptr_->ExecuteEvent("pause");
        }
    }

    void MyPlayer::Slow()
    {
        if(nullptr != event_handler_ptr_)
        {
            event_handler_ptr_->ExecuteEvent("slow");
        }
    }
        
    void MyPlayer::player_handler()
    {
        std::cout<<"player_handler "<<std::this_thread::get_id()<<std::endl;
        
    }
    
    void MyPlayer::pause_handler()
    {
        std::cout<<"pause_handler "<<std::this_thread::get_id()<<std::endl;
    }
    
        void MyPlayer::slow_handler()
    {
        std::cout<<"slow_handler "<<std::this_thread::get_id()<<std::endl;
    }
    
    void MyPlayer::DeInit()
    {
        if(nullptr != event_handler_ptr_)
        {
            event_handler_ptr_->UnRegisterEvents("play");
            event_handler_ptr_->UnRegisterEvents("pause");
            event_handler_ptr_->UnRegisterEvents("slow");
        }
    }

int main()
{
    std::unique_ptr<MyPlayer> player_ = std::make_unique<MyPlayer>();
   
 
    player_->Init();
       while(1)
   {
    player_->Play();
    player_->Pause();
    player_->Slow();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
    player_->DeInit();
    std::cout<<"main "<<std::this_thread::get_id()<<std::endl;
    //while(1){}
    return 0;
}
