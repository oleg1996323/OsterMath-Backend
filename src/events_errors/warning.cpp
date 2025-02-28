#include "warning.h"

namespace warnings{
    std::string Warning::__get_abbr__() const{
        return warning_abbr();
    }

    Warning::Warning(){
        event_t_ = EVENT_TYPE::WARNING;
    }

    std::string Warning::warning_abbr(){
        return "#WARN";
    }

    std::string Warning::__get_title__() const{
        return get_warning();
    }
    size_t Warning::__type__() const{
        return (size_t)type();
    }

    std::string Warning::__get_prompt__() const{
        return get_prompt();
    }

    std::string Infinite::warning_abbr(){
        return "#INF!";
    }
    std::string Infinite::get_warning() const{
        return "Infinite value";
    }
    WARNING_TYPE Infinite::type() const{
        return WARNING_TYPE::INFINITE;
    }
    std::string Infinite::get_prompt() const{
        return "This result is very large (i.e. infinite)";
    }

    std::string UndefinedRef::warning_abbr(){
        return "#REF!";
    }
    std::string UndefinedRef::get_warning() const{
        return "Undefined reference";
    }
    WARNING_TYPE UndefinedRef::type() const{
        return WARNING_TYPE::UNDEF_REF;
    }
    std::string UndefinedRef::get_prompt() const{
        return "The refered node is not defined";
    }
}