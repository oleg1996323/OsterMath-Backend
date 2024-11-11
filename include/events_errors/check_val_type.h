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

//Checking if all arguments are same type
template<typename... ARGS>
concept SameTypeArguments = (std::is_same_v<ARGS,ARGS...> && ...);

#include "node.h"

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

template<typename CONT, typename Tc>
struct __container_make__;

// template<template<typename> typename CONT, typename Tc,typename Uc>
// struct __container_make__{
//     typedef CONT<Uc> container;
//     typedef Uc value_type;
// };


template<template<typename> class CONT, typename OldType, typename NewType>
struct __container_make__<CONT<OldType>, NewType> {
    using type = CONT<NewType>;
};