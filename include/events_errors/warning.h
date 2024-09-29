#pragma once
#include "abstract_event.h"
#include <string>
namespace warnings{

enum WARNING_TYPE{
    NOWARNING,
    WARNING,
    INFINITE
};

//rename folder to events

class AbstractWarning: public AbstractEvent{
    public:
    AbstractWarning();
    static const char* warning_abbr();
    virtual const char* get_warning() const = 0;
    virtual WARNING_TYPE type() const = 0;
    virtual const char* get_prompt() const;
    private:
    virtual const char* __get_title__() const override;
    virtual size_t __type__() const override;
    virtual const char* __get_prompt__() const override;
};

class Warning: public AbstractWarning{
    public:
    static const char* warning_abbr();
    virtual const char* get_warning() const{
        return "";
    };
    virtual WARNING_TYPE type() const{
        return WARNING;
    };
    virtual const char* get_prompt() const;
};

class Infinite : public Warning {
    public:
    static const char* warning_abbr();
    virtual const char* get_warning() const;
    virtual WARNING_TYPE type() const;
    virtual const char* get_prompt() const;
};

const char* get_warning_abbr(WARNING_TYPE);
}