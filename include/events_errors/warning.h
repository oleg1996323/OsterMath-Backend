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
    virtual std::string __get_abbr__() const override final;
    public:
    Warning();
    ~Warning() = default;
    static std::string warning_abbr();
    virtual std::string get_warning() const = 0;
    virtual WARNING_TYPE type() const = 0;
    virtual std::string get_prompt() const = 0;
    private:
    virtual std::string __get_title__() const override;
    virtual size_t __type__() const override;
    virtual std::string __get_prompt__() const override;
};

class Infinite final: public Warning {
    public:
    static std::string warning_abbr();
    virtual std::string get_warning() const override;
    virtual WARNING_TYPE type() const override;
    virtual std::string get_prompt() const;
};

std::string get_warning_abbr(WARNING_TYPE);
}