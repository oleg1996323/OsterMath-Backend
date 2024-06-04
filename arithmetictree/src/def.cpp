#include "def.h"
#include "arithmetic_types.h"
#include <string>

Result_t& Result::get(){
    return *this;
}

const Result_t& Result::get() const{
    return *this;
}

bool Result::is_array() const{
    return std::holds_alternative<std::shared_ptr<ArrayNode>>(*this);
}

bool Result::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool Result::is_string() const{
    return std::holds_alternative<std::string>(*this);
}

bool Result::is_variable() const{
    return std::holds_alternative<std::shared_ptr<VariableNode>>(*this);
}

bool Result::has_value() const{
    return !std::holds_alternative<std::monostate>(*this);
}