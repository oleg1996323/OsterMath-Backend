#pragma once
#include "def.h"
#include "exception.h"
#include <stdexcept>
#include <string>
#include <type_traits>

template<typename T>
const char* generate_string_exception(T value){
    if constexpr (std::is_same_v<T,TYPE_VAL>){
        switch(value){
            case TYPE_VAL::ARRAY:
                return "array type";
                break;
            case TYPE_VAL::NUMERIC_ARRAY:
                return "numeric array";
                break;
            case TYPE_VAL::STRING:
                return "string";
                break;
            case TYPE_VAL::STRING_ARRAY:
                return "string array";
                break;
            case TYPE_VAL::VALUE:
                return "numeric value";
            default:
                throw exceptions::InvalidTypeOfArgument("TYPE_VAL::{NOT UNKNOWN}");
        }
    }
    else if constexpr(std::is_same_v<T,size_t>){
        return std::to_string(value).c_str();
    }
    else{
        throw std::runtime_error("Error at runtime");
    }
}

template<typename CHECK_VAL,typename... ARGS>
concept ComparableCheckValues = requires(CHECK_VAL ch, ARGS... args){
    ((ch==args) && ...);
    ((ch!=args) && ...);
};

template<typename ARG, typename... ARGS>
concept SameTypeArguments = (std::is_same_v<ARG,ARGS> && ...);

#include "node.h"

template<typename... ARGS>
concept NodeRequirements = requires(ARGS... args){
    ((std::is_base_of_v<std::decay_t<ARGS>,Node>) && ...);
    requires (((args.type_val()) && ...) || ((args->type_val()) && ...));
};

template<typename CHECK_VAL,typename... ARGS>
requires ComparableCheckValues<CHECK_VAL, ARGS...>
Result_t check_arguments(CHECK_VAL check, ARGS&&... args){
    if(((check!=args) && ...))
        return std::make_shared<AbstractEvent>(exceptions::InvalidTypeOfArgument(generate_string_exception(check)));
};

template<typename CHECK_VAL,typename... ARGS>
requires (ComparableCheckValues<CHECK_VAL, ARGS...> && NodeRequirements<ARGS...>)
Result_t check_arguments_for_node(CHECK_VAL check, ARGS&&... args){
    if(((check!=args) && ...))
        return std::make_shared<AbstractEvent>(exceptions::InvalidTypeOfArgument(generate_string_exception(check)));
}

template<typename... ARGS, size_t SIZE>
bool check_arguments_size(ARGS&&... args){
    return ((args.size() == SIZE) && ...);
}

template<typename ARG,typename... ARGS>
requires ((SameTypeArguments<ARG,ARGS>) && ...)
Result_t check_arguments_size(ARG arg,ARGS&&... args, size_t sz){
    return ((args.size() == sz) && ...);
}
