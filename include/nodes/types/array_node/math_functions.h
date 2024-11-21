#pragma once
#include "array_node.h"
#include "aux_functions.h"

namespace node_array::functions{
    namespace math{
        std::vector<std::shared_ptr<ArrayNode>> extract_from_matrix(size_t index, const std::shared_ptr<ArrayNode>& array, size_t depth){
            if(array && array->type_val()&TYPE_VAL::NUMERIC_ARRAY){
                if(::functions::auxiliary::is_rectangle_array_node(array)){
                    SizeDepthMeasure sz_depth_measure = ::functions::auxiliary::init_sz_depth_measure(array);
                    if(!sz_depth_measure.set_iterator(depth,index))
                        return std::vector<std::shared_ptr<ArrayNode>>();
                    std::shared_ptr<ArrayNode> result;
                    if(depth>=sz_depth_measure.dimensions())
                        return std::vector<std::shared_ptr<ArrayNode>>();
                    

                    
                }
            }
        }
    }
}