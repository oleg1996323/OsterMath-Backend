#pragma once
#include <cstdlib>

enum EVENT_TYPE{
    EXCEPTION,
    WARNING
};

class AbstractEvent{
    protected:
    EVENT_TYPE event_t_;
    public:
    AbstractEvent();
    virtual ~AbstractEvent();
    virtual const char* __get_abbr__() const = 0;
    inline EVENT_TYPE get_event_type() const{
        return event_t_;
    }
    virtual const char* __get_title__() const = 0;
    virtual size_t __type__() const = 0;
    virtual const char* __get_prompt__() const = 0;
};