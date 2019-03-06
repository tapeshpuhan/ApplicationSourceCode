#ifndef __EVENT_HANDLER__
#define __EVENT_HANDLER__

#include <string>
#include <functional>

struct EventHandler
{
    EventHandler() = default;
    using evant_handler_type = std::function<void()>;
    virtual bool RegisterEvents(const std::string& event_name, const evant_handler_type& handler) = 0;
    virtual bool UnRegisterEvents(const std::string& event_name) = 0;
    virtual bool ExecuteEvent(const std::string& name) = 0;
    virtual ~EventHandler() = default;
};


#endif //__EVENT_HANDLER__
