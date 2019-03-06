#include "ros_event_handler.h"

 RosEventHandler::RosEventHandler(const int32_t& max_number_event):max_number_event_{max_number_event}
{
    event_handler_map_.clear();
    event_thread_pool_.reserve(max_number_event_);
}
RosEventHandler::~RosEventHandler()
{
     event_handler_map_.clear();

    for(auto& thread_h : event_thread_pool_)
    {
        if(thread_h.joinable())
        {
            thread_h.join();
        }
    }
}

bool RosEventHandler::RegisterEvents(const std::string& event_name, const evant_handler_type& handler)
{
    bool result = false;
    
    auto map_return = event_handler_map_.insert(std::make_pair(event_name,handler));
    result = map_return.second;
    
    return result;
}

bool RosEventHandler::UnRegisterEvents(const std::string& event_name)
{
    bool result = false;
    
    auto size = event_handler_map_.erase(event_name);
    
    if(size)
    {
        result = true;
    }
    return result;
}
bool RosEventHandler::ExecuteEvent(const std::string& name)
{
    bool result = false;
    
    if(event_handler_map_.find(name) != event_handler_map_.end())
    {
        if(event_thread_pool_.size() < max_number_event_)
        {
            std::thread th([&](){
                    ExicuteEventHandler(name);});
            if(th.joinable())
            {
               // th.join();
            }
            event_thread_pool_.push_back(std::move(th));
            result = true;
        }
    }
    return result;
}

void RosEventHandler::ExicuteEventHandler(const std::string& event_name)
{
    std::lock_guard<std::mutex> local_lock(lock_event_handler_);
    
    auto execute_function  = event_handler_map_.at(event_name);
    execute_function();
}
