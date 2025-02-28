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

#ifndef AUX_FUNCTIONS
#define AUX_FUNCTIONS
class ArrayNode;

namespace functions{
    namespace auxiliary{
        template<typename CHECK_VAL,template<typename> typename CONT,typename T>
        requires std::is_same_v<typename std::decay_t<CONT<T>>::value_type,T> ||
        __comparable_check_values_ptr_t__<CHECK_VAL, T> || 
        __comparable_check_values_val_t__<CHECK_VAL, T>
        bool check_type_container_nodes(CHECK_VAL check, CONT<T> args);
        template<typename CHECK_VAL,typename... ARGS>
        requires __comparable_check_values_ptr__<CHECK_VAL, ARGS...> || __comparable_check_values_val__<CHECK_VAL, ARGS...>
        bool check_arguments(CHECK_VAL check, ARGS&&... args);

        //void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array);

        template<typename T>
        SizeDepthMeasure init_sz_depth_measure(T array);
        bool check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,const std::vector<AbstractNode*>& nodes) noexcept;
        bool is_filled_array_node(const AbstractNode* node) noexcept;
        bool is_filled_rectangle_array_node_of_type(TYPE_VAL,const AbstractNode* node) noexcept;
        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,CONT<T> nodes) noexcept;
        bool is_rectangle_array_node(const AbstractNode* node) noexcept;
        bool equal_morphology_nodes(const std::vector<AbstractNode*>& nodes) noexcept;
        bool equal_morphology_nodes(const std::set<const AbstractNode*>& nodes) noexcept;

        bool all_numeric(const Childs_t& arrays);
        bool all_string(const Childs_t& arrays);
        bool has_cyclic_references(const AbstractNode* checked) noexcept;
        bool has_cyclic_references(const AbstractNode* node) noexcept;
        const AbstractNode* first_node_not_var_or_ref(const AbstractNode* node) noexcept;
        AbstractNode* first_node_not_var_or_ref(AbstractNode* node) noexcept;
        AbstractNode* first_node_not_var_or_ref_by_ids(AbstractNode* node, const std::vector<size_t>::const_iterator& first,const std::vector<size_t>::const_iterator& last) noexcept;
        AbstractNode* first_node_not_var_or_ref_by_ids(AbstractNode* node, const SizeDepthMeasure& seq_iterators) noexcept;
        const AbstractNode* first_node_not_var_or_ref_by_ids(const AbstractNode* node, const std::vector<size_t>::const_iterator& first,const std::vector<size_t>::const_iterator& last) noexcept;
        const AbstractNode* first_node_not_var_or_ref_by_ids(const AbstractNode* node, const SizeDepthMeasure& seq_iterators) noexcept;

        const ArrayNode* to_array_node(const AbstractNode* node) noexcept;
        const ValueNode* to_value_node(const AbstractNode* node) noexcept;
        const StringNode* to_string_node(const AbstractNode* node);

    }
}

//check if all arguments in have same type value
template<typename CHECK_VAL,typename... ARGS>
requires __comparable_check_values_ptr__<CHECK_VAL, ARGS...> || __comparable_check_values_val__<CHECK_VAL, ARGS...>
bool functions::auxiliary::check_arguments(CHECK_VAL check, ARGS&&... args){
    if constexpr (__comparable_check_values_ptr__<CHECK_VAL,ARGS...>){
        if(((check & args->type_val()) && ...))
            return true;
        else return false;
    }
    else{
        if(((check & args.type_val()) && ...))
            return true;
        else return false;
    }
};

//check if values in container have same type value
template<typename CHECK_VAL,template<typename> typename CONT,typename T>
requires std::is_same_v<typename std::decay_t<CONT<T>>::value_type,T> ||
__comparable_check_values_ptr_t__<CHECK_VAL, T> || 
__comparable_check_values_val_t__<CHECK_VAL, T>
bool functions::auxiliary::check_type_container_nodes(CHECK_VAL check, CONT<T> args){
    return std::all_of(args.begin(),args.end(),[&check](const std::decay_t<T>& node){
        return node->type_val() == check;
    });
}

template<typename T>
SizeDepthMeasure functions::auxiliary::init_sz_depth_measure(T array){
    SizeDepthMeasure sz_depth_measure;
    auto node = first_node_not_var_or_ref(array);
    if(!array)
        return sz_depth_measure;
    while(node->type()==NODE_TYPE::ARRAY && node->childs().size()!=0){
        sz_depth_measure.push_depth(node->childs().size());
        std::vector<size_t> tmp{0};
        node = first_node_not_var_or_ref_by_ids(node,tmp.begin(),tmp.end());
    }
    return sz_depth_measure;
}

bool same_result_type(const Result& first,const Result& second);

#endif