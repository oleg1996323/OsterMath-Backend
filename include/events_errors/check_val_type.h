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
concept __comparable_check_values_ptr__ = requires(CHECK_VAL ch, ARGS... args){
    ((ch==args->type_val()) && ...);
    ((ch!=args->type_val()) && ...);
};

template<typename CHECK_VAL,typename... ARGS>
concept __comparable_check_values_val__ = requires(CHECK_VAL ch, ARGS... args){
    ((ch==args.type_val()) && ...);
    ((ch!=args.type_val()) && ...);
};

//Checking if all arguments are same type
template<typename... ARGS>
concept SameTypeArguments = (std::is_same_v<ARGS,ARGS...> && ...);

#include "node.h"

template<typename... ARGS>
concept NodeRequirements = requires(ARGS... args){
    ((std::is_base_of_v<std::decay_t<ARGS>,Node>) && ...);
    requires (((args.type_val()) && ...) || ((args->type_val()) && ...));
};

template<typename CHECK_VAL,typename... ARGS>
requires __comparable_check_values_ptr__<CHECK_VAL, ARGS...> || __comparable_check_values_val__<CHECK_VAL, ARGS...>
bool check_arguments(CHECK_VAL check, ARGS&&... args){
    if constexpr (__comparable_check_values_ptr__<CHECK_VAL,ARGS...>){
        if(((!(check&args->type_val())) && ...))
            return false;
        else return true;
    }
    else{
        if(((!(check&args.type_val())) && ...))
            return false;
        else return true;
    }
    
};

bool check_type_arguments_for_node(TYPE_VAL check, const std::vector<std::shared_ptr<Node>>& args){
    return std::all_of(args.begin(),args.end(),[&check](const std::shared_ptr<Node>& node){
        return node->type_val() && check;
    });
}

//Checking for rvalue- or lvalue-type having size() method
template<typename T>
concept __has_size_func_val__ = requires(T arg) {
    { arg.size() } -> std::convertible_to<size_t>;
};

//Checking for pointer-type value having size() method
template<typename T>
concept __has_size_func_ptr__ = std::is_pointer_v<T> && requires(T arg) {
    { arg->size() } -> std::convertible_to<size_t>;
};

//Checking if arguments has same types and the size() method with result convertible to size_t (unsigned long)
template<typename... ARGS>
concept __has_size__ = SameTypeArguments<ARGS...> &&
(... && __has_size_func_val__<ARGS>) ||
(... && __has_size_func_ptr__<ARGS>);

template<template<typename> typename CONT,typename T>
concept __container_array_node_req__ = requires (CONT<T> container){
    container.begin();
    container.end();
    container.cbegin();
    container.cend();
    {std::declval<T>()->size()}->std::convertible_to<size_t>;
};

//Check if all arguments having size() method are same size
//Accessible for pointer-values, rvalues and lvalues
template<typename F_ARG,typename... ARGS>
requires __has_size__<ARGS...> && __has_size__<F_ARG>
bool check_arguments_size(F_ARG&& f_arg, ARGS&&... args){
    if (sizeof...(ARGS)!=0){
        if constexpr (std::is_pointer_v<std::decay_t<F_ARG>> && 
        (... && std::is_pointer_v<std::decay_t<ARGS[sizeof...(ARGS)]>>)){ 
            size_t sz = f_arg->size();
            return ((args->size() == sz) && ...);
        }
        else if (!(std::is_pointer_v<std::decay_t<F_ARG>> && 
        (... && std::is_pointer_v<std::decay_t<ARGS[sizeof...(ARGS)]>>))){ 
            size_t sz = f_arg.size();
            return ((args.size() == sz) && ...);
        }
        else{
            return false;
        }
    }
    else {
        return true;
    }
}
