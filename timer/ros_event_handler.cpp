#include "ros_event_handler.h"

RosEventHandler::RosEventHandler()
{
    event_handler_map_.clear();
}
RosEventHandler::~RosEventHandler()
{
     event_handler_map_.clear();
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
        std::thread thread_handler([&](){
                    ExicuteEventHandler(name);});
        if(thread_handler.joinable())
        {
            thread_handler.join();
        }
        result = true;
    }
    return result;
}

void RosEventHandler::ExicuteEventHandler(const std::string& event_name)
{
    std::lock_guard<std::mutex> local_lock(lock_event_handler_);
    
    auto execute_function  = event_handler_map_.at(event_name);
    execute_function();
}
