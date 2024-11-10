#pragma once
#include <string>
#include "abstract_event.h"

namespace warnings{

enum WARNING_TYPE{
    NOWARNING,
    INFINITE
};

//rename folder to events

class Warning: public AbstractEvent{
    virtual const char* __get_abbr__() const override final;
    public:
    Warning();
    ~Warning() = default;
    static const char* warning_abbr();
    virtual const char* get_warning() const = 0;
    virtual WARNING_TYPE type() const = 0;
    virtual const char* get_prompt() const = 0;
    private:
    virtual const char* __get_title__() const override;
    virtual size_t __type__() const override;
    virtual const char* __get_prompt__() const override;
};

class Infinite final: public Warning {
    public:
    static const char* warning_abbr();
    virtual const char* get_warning() const override;
    virtual WARNING_TYPE type() const override;
    virtual const char* get_prompt() const;
};

const char* get_warning_abbr(WARNING_TYPE);
}