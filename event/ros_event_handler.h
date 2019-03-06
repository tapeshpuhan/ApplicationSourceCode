#ifndef __ROS_EVENT_HANDLER__
#define __ROS_EVENT_HANDLER__

#include "event_handler.h"
#include <map>
#include <thread>
#include <mutex>
#include <cstdint>
#include <vector>
#include <algorithm>


class RosEventHandler : public EventHandler
{
    public:
    explicit RosEventHandler(const int32_t& max_number_event);
    
    RosEventHandler(const RosEventHandler&)=delete;
    RosEventHandler& operator==(const RosEventHandler&)=delete;
    
    RosEventHandler(RosEventHandler&&)=delete;
    RosEventHandler& operator==(RosEventHandler&&)=delete;
    
    bool RegisterEvents(const std::string& event_name, const evant_handler_type& handler)override;
    bool UnRegisterEvents(const std::string& event_name)override;
    bool ExecuteEvent(const std::string& name)override;
    
    ~RosEventHandler();
    private:
    
    std::mutex lock_event_handler_;
    std::map<std::string, evant_handler_type> event_handler_map_;
    int32_t max_number_event_;
    
    std::vector<std::thread> event_thread_pool_;
    
    void ExicuteEventHandler(const std::string& event_name);
};


#endif //__ROS_EVENT_HANDLER__
