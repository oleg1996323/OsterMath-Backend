#include "events_errors/warning.h"

namespace warnings{
    AbstractWarning::AbstractWarning(){
        event_t_ = EVENT_TYPE::WARNING;
    }

    const char* warnings::Warning::get_prompt() const{
        return "";
    }

    const char* AbstractWarning::__get_title__() const{
        return get_warning();
    }
    size_t AbstractWarning::__type__() const{
        return (size_t)type();
    }

    const char* AbstractWarning::__get_prompt__() const{
        return get_prompt();
    }

    const char* Infinite::warning_abbr(){
        return "#NAME?";
    }
    const char* Infinite::get_warning() const{
        return "Parsing error";
    }
    WARNING_TYPE Infinite::type() const{
        return WARNING_TYPE::INFINITE;
    }
    const char* Infinite::get_prompt() const{
        return "This result is very large (i.e. infinite)";
    }
}