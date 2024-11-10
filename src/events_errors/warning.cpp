#include "warning.h"

namespace warnings{
    const char* Warning::__get_abbr__() const{
        return warning_abbr();
    }

    Warning::Warning(){
        event_t_ = EVENT_TYPE::WARNING;
    }

    const char* Warning::warning_abbr(){
        return "#WARN";
    }

    const char* Warning::__get_title__() const{
        return get_warning();
    }
    size_t Warning::__type__() const{
        return (size_t)type();
    }

    const char* Warning::__get_prompt__() const{
        return get_prompt();
    }

    const char* Infinite::warning_abbr(){
        return "#INF!";
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