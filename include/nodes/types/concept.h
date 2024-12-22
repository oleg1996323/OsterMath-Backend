#pragma once
#include <type_traits>

template<typename... ARGS>
concept NodeRequirements = requires(ARGS... args){
    ((std::is_base_of_v<AbstractNode,std::decay_t<ARGS>>) && ...);
    requires (((args.type_val()) && ...) || ((args->type_val()) && ...));
};

template<typename CHECK_VAL,typename... ARGS>
concept __comparable_check_values_ptr__ = requires(CHECK_VAL ch, ARGS... args){
    ((ch==args->type_val()) && ...);
    ((ch!=args->type_val()) && ...);
};

template<typename CHECK_VAL,typename T>
concept __comparable_check_values_ptr_t__ = requires(CHECK_VAL ch, T arg){
    (ch==arg->type_val());
    (ch!=arg->type_val());
};

template<typename CHECK_VAL,typename... ARGS>
concept __comparable_check_values_val__ = requires(CHECK_VAL ch, ARGS... args){
    ((ch==args.type_val()) && ...);
    ((ch!=args.type_val()) && ...);
};

template<typename CHECK_VAL,typename T>
concept __comparable_check_values_val_t__ = requires(CHECK_VAL ch, T arg){
    (ch==arg.type_val());
    (ch!=arg.type_val());
};

template<template<typename> typename CONT,typename T>
concept __container_array_node_req__ = requires (CONT<T> container, T arg){
    container.begin();
    container.end();
    container.cbegin();
    container.cend();
    {arg->size()}->std::convertible_to<size_t>;
};
