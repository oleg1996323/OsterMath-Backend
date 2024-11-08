#pragma once
#include <cstddef>

enum EVENT_TYPE{
    EXCEPTION,
    WARNING
};

class AbstractEvent{
    protected:
    EVENT_TYPE event_t_;
    public:
    virtual ~AbstractEvent() = default;
    static const char* get_abbr();
    EVENT_TYPE get_event_type() const;
    virtual const char* __get_title__() const{};
    virtual size_t __type__() const{};
    virtual const char* __get_prompt__() const{};
};

EVENT_TYPE AbstractEvent::get_event_type() const{
    return event_t_;
}