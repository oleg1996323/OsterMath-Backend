#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "array_node.h"
#include <def.h>
#include <optional>
#include <type_traits>
#include "events_errors/exception.h"
#include <execution>
#include "events_errors/check_val_type.h"
#include <boost/math/statistics/linear_regression.hpp>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array);
        
        bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays);
        TYPE_VAL getting_arrays_type(const std::vector<ArrayNode*>& arrays);

        bool arrays_numeric(const std::vector<ArrayNode*>& arrays);
        bool arrays_string(const std::vector<ArrayNode*>& arrays);

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool functions::auxiliary::check_sizes_arrays(std::vector<size_t>& sz_depth_measure,CONT<T>&& arrays){
            size_t loc_c=0;
            if(sz_depth_measure.size()==0){
                if(arrays.size()!=0 && !arrays.front()->empty()){
                    loc_c = 0;
                    init_sz_depth_measure(sz_depth_measure,arrays.front());
                }
                else loc_c = 0;
            }

            return check_sizes_arrays(sz_depth_measure,arrays,loc_c);
        }

        template<template<typename> typename CONT, typename T>
        requires __container_array_node_req__<CONT,T>
        bool functions::auxiliary::check_sizes_arrays(CONT<T>&& arrays){
            
        }

        bool check_sizes_arrays(const std::vector<ArrayNode*>& arrays);

        std::shared_ptr<ArrayNode> to_array_node(const std::shared_ptr<Node>& node) noexcept;
        std::shared_ptr<ValueNode> to_value_node(const std::shared_ptr<Node>& node) noexcept;
        //TODO: StringNode* to_string_node(const std::shared_ptr<Node>& node);

    }
}