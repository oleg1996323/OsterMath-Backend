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
        void init_sz_depth_measure(SizeDepthMeasure& sz_depth_measure, T node);

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,CONT<T> nodes, size_t& loc_c);

        bool check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,const std::vector<std::shared_ptr<Node>>& nodes) noexcept;

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,CONT<T> nodes) noexcept;
        bool check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& nodes) noexcept;

        bool all_numeric(decltype(std::declval<Node>().childs()) arrays);
        bool all_string(decltype(std::declval<Node>().childs()) arrays);

        std::shared_ptr<Node> first_node_not_var(const std::shared_ptr<Node>& node) noexcept;
        Node* first_node_not_var(Node* node) noexcept;
        std::shared_ptr<Node> first_node_not_var_by_ids(const std::shared_ptr<Node>& node, const std::vector<size_t>& seq_iterators) noexcept;
        Node* first_node_not_var_by_ids(Node* node, const std::vector<size_t>& seq_iterators) noexcept;

        bool check_sizes_arrays(const std::vector<Node*>& arrays);
        bool check_sizes_arrays(const std::list<Node*>& arrays);
        bool check_sizes_arrays(const std::deque<Node*>& arrays);
        //bool check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& arrays);
        bool check_sizes_arrays(const std::list<std::shared_ptr<Node>>& arrays);
        bool check_sizes_arrays(const std::deque<std::shared_ptr<Node>>& arrays);

        //temporary at testing TODO: delete
        bool check_sizes_arrays(SizeDepthMeasure&,const std::vector<Node*>& arrays);
        bool check_sizes_arrays(SizeDepthMeasure&,const std::list<Node*>& arrays);
        bool check_sizes_arrays(SizeDepthMeasure&,const std::deque<Node*>& arrays);
        bool check_sizes_arrays(SizeDepthMeasure&,const std::list<std::shared_ptr<Node>>& arrays);
        bool check_sizes_arrays(SizeDepthMeasure&,const std::deque<std::shared_ptr<Node>>& arrays);

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
void functions::auxiliary::init_sz_depth_measure(SizeDepthMeasure& sz_depth_measure, T array){
    Node* node;
    if constexpr (std::is_same_v<std::shared_ptr<ArrayNode>,std::decay_t<T>>)
        node = array.get();
    else if (std::is_same_v<ArrayNode*,std::decay_t<T>>)
        node = array;
    else assert(true);
    
    while(node->type()!=NODE_TYPE::ARRAY && node->has_child(0)){
        node = node->child(0).get();
    }
    if(reinterpret_cast<ArrayNode*>(node)->size()!=0 && node->type()==NODE_TYPE::ARRAY){
        sz_depth_measure.push_depth(reinterpret_cast<ArrayNode*>(node)->size());
        if(node->has_child(0) && node->child(0)->type()==NODE_TYPE::ARRAY)
            init_sz_depth_measure(sz_depth_measure,reinterpret_cast<ArrayNode*>(node->child(0).get()));
    }
}

template<template<typename> typename CONT, typename T>
requires __container_array_node_req__<CONT,T>
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,CONT<T> nodes, size_t& loc_c){
    if(std::all_of(nodes.begin(),nodes.end(),[&sz_depth_measure, &loc_c](const T& array){
        if(std::all_of(array->begin(),array->end(),[](std::shared_ptr<Node>& node){return node->is_array();}))
        {
            std::vector<ArrayNode*> in_arrays;
            in_arrays.reserve(array->size());
            for(std::shared_ptr<Node> item_array:*array){
                in_arrays.push_back(reinterpret_cast<ArrayNode*>(item_array.get()));
            }
            if(array->size()==sz_depth_measure.size(loc_c)){
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
            return array->size()==sz_depth_measure.size(loc_c);
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


bool same_result_type(const Result& first,const Result& second);

template<template<typename> typename CONT, typename T>
requires __container_array_node_req__<CONT,T>
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,CONT<T> nodes) noexcept{
    size_t loc_c=0;
    if(sz_depth_measure.dimensions()==0){
        if(nodes.size()!=0 && !nodes.front()->empty()){
            loc_c = 0;
            Node* node;
            if constexpr (std::is_pointer_v<std::decay_t<T>>){
                node = reinterpret_cast<Node*>(nodes.front());
            }
            else if(std::is_same_v<CONT<std::shared_ptr<ArrayNode>>,CONT<T>>){
                node = reinterpret_cast<Node*>(nodes.front().get());
            }
            while(node->cached_result().is_array()){
                sz_depth_measure.push_depth(node->cached_result().get_array_node()->size());
                node = node->child(0).get();
            }
        }
        else loc_c = 0;
    }
    if constexpr (std::is_pointer_v<std::decay_t<T>>){
        using type = std::decay_t<CONT<ArrayNode*>>;
        return check_sizes_arrays<CONT,T>(sz_depth_measure,reinterpret_cast<const type&>(nodes),loc_c);
    }
    else if(std::is_same_v<CONT<std::shared_ptr<ArrayNode>>,CONT<T>>){
        using type = std::decay_t<CONT<std::shared_ptr<ArrayNode>>>;
        return check_sizes_arrays<CONT,T>(sz_depth_measure,reinterpret_cast<const type&>(nodes),loc_c);
    }
    else{
        assert(!(std::is_pointer_v<std::decay_t<T>> || std::is_same_v<CONT<std::shared_ptr<ArrayNode>>,CONT<T>>));
    }
}