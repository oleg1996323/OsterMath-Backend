#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "array_node.h"
#include <def.h>
#include <optional>
#include <type_traits>
#include "events_errors/exception.h"
#include <execution>
#include "events_errors/check_val_type.h"
#include "concept.h"
#include <deque>
#include <list>
#include <boost/math/statistics/linear_regression.hpp>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        template<typename CHECK_VAL,template<typename> typename CONT,typename T>
        requires std::is_same_v<typename std::decay_t<CONT<T>>::value_type,std::shared_ptr<typename T::element_type>> ||
        __comparable_check_values_ptr_t__<CHECK_VAL, T> || 
        __comparable_check_values_val_t__<CHECK_VAL, T>
        bool check_type_container_nodes(CHECK_VAL check, CONT<T> args);
        template<typename CHECK_VAL,typename... ARGS>
        requires __comparable_check_values_ptr__<CHECK_VAL, ARGS...> || __comparable_check_values_val__<CHECK_VAL, ARGS...>
        bool check_arguments(CHECK_VAL check, ARGS&&... args);

        //void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array);
        
        template<typename T>
        void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, T node);

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,CONT<T> nodes, size_t& loc_c);

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,CONT<T> nodes) noexcept;

        bool all_numeric(decltype(std::declval<Node>().childs()) arrays);
        bool all_string(decltype(std::declval<Node>().childs()) arrays);

        bool check_sizes_arrays(const std::vector<Node*>& arrays);
        bool check_sizes_arrays(const std::list<Node*>& arrays);
        bool check_sizes_arrays(const std::deque<Node*>& arrays);
        bool check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& arrays);
        bool check_sizes_arrays(const std::list<std::shared_ptr<Node>>& arrays);
        bool check_sizes_arrays(const std::deque<std::shared_ptr<Node>>& arrays);

        std::shared_ptr<ArrayNode> to_array_node(const std::shared_ptr<Node>& node) noexcept;
        std::shared_ptr<ValueNode> to_value_node(const std::shared_ptr<Node>& node) noexcept;
        //TODO: StringNode* to_string_node(const std::shared_ptr<Node>& node);

    }
}

template<typename CHECK_VAL,typename... ARGS>
requires __comparable_check_values_ptr__<CHECK_VAL, ARGS...> || __comparable_check_values_val__<CHECK_VAL, ARGS...>
bool functions::auxiliary::check_arguments(CHECK_VAL check, ARGS&&... args){
    if constexpr (__comparable_check_values_ptr__<CHECK_VAL,ARGS...>){
        if(((check == args->type_val()) && ...))
            return true;
        else return false;
    }
    else{
        if(((check == args.type_val()) && ...))
            return true;
        else return false;
    }
};

template<typename CHECK_VAL,template<typename> typename CONT,typename T>
requires std::is_same_v<typename std::decay_t<CONT<T>>::value_type,std::shared_ptr<typename T::element_type>> ||
__comparable_check_values_ptr_t__<CHECK_VAL, T> || 
__comparable_check_values_val_t__<CHECK_VAL, T>
bool functions::auxiliary::check_type_container_nodes(CHECK_VAL check, CONT<T> args){
    return std::all_of(args.begin(),args.end(),[&check](const std::decay_t<T>& node){
        return node->type_val() == check;
    });
}

template<typename T>
void functions::auxiliary::init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, T array){
    sz_depth_measure.push_back(array->size());
    if(array->size()!=0 && array->child(0)->type()==NODE_TYPE::ARRAY){
        if constexpr (std::is_same_v<std::shared_ptr<ArrayNode>,std::decay_t<T>>)
            init_sz_depth_measure(sz_depth_measure,reinterpret_cast<const std::decay_t<T>&>(array->child(0)));
        else if (std::is_same_v<ArrayNode*,std::decay_t<T>>)
            init_sz_depth_measure(sz_depth_measure,reinterpret_cast<std::decay_t<T>>(array->child(0).get()));
    }
}

template<template<typename> typename CONT, typename T>
requires __container_array_node_req__<CONT,T>
bool functions::auxiliary::check_sizes_arrays(std::vector<size_t>& sz_depth_measure,CONT<T> nodes, size_t& loc_c){
    if(std::all_of(nodes.begin(),nodes.end(),[&sz_depth_measure, &loc_c](const T& array){
        //происходит дублирование при каждом прохождении последующих массивов после 1-го
        if(std::all_of(array->begin(),array->end(),[](std::shared_ptr<Node>& node){return node->is_array();}))
        {
            std::vector<ArrayNode*> in_arrays;
            in_arrays.reserve(array->size());
            for(std::shared_ptr<Node> item_array:*array){
                in_arrays.push_back(reinterpret_cast<ArrayNode*>(item_array.get()));
            }
            if(array->size()==sz_depth_measure.at(loc_c)){
                ++loc_c;
                if(check_sizes_arrays(sz_depth_measure,in_arrays,loc_c)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else return false;
        }
        else if(!std::any_of(array->begin(),array->end(),[](std::shared_ptr<Node>& node){return node->is_array();}))
            return array->size()==sz_depth_measure.at(loc_c);
        else return false;
    })){
        --loc_c;
        return true;
    }
    else{
        --loc_c;
        return false;
    }
}

template<template<typename> typename CONT, typename T>
requires __container_array_node_req__<CONT,T>
bool functions::auxiliary::check_sizes_arrays(std::vector<size_t>& sz_depth_measure,CONT<T> nodes) noexcept{
    size_t loc_c=0;
    if(sz_depth_measure.size()==0){
        if(nodes.size()!=0 && !nodes.front()->empty()){
            loc_c = 0;
            init_sz_depth_measure(sz_depth_measure,nodes.front());
        }
        else loc_c = 0;
    }
    if constexpr (std::is_pointer_v<std::decay_t<T>>){
        using type = std::decay_t<CONT<ArrayNode*>>;
        return check_sizes_arrays<CONT,T>(sz_depth_measure,reinterpret_cast<const type&>(nodes),loc_c);
    }
    else{
        using type = std::decay_t<CONT<std::shared_ptr<ArrayNode>>>;
        return check_sizes_arrays<CONT,T>(sz_depth_measure,reinterpret_cast<const type&>(nodes),loc_c);
    }
}