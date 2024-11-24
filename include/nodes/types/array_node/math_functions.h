#pragma once
#include "array_node.h"
#include "aux_functions.h"

namespace node_array::functions{
    namespace math{
        //permits to extract indexed submatrix from major matrix
        std::shared_ptr<ArrayNode> extract_from_matrix(size_t index, const std::shared_ptr<ArrayNode>& array, size_t dimension) noexcept{
            if(array && 
                array->type_val()&TYPE_VAL::NUMERIC_ARRAY &&
                ::functions::auxiliary::is_rectangle_array_node(array))
            {
                SizeDepthMeasure sz_depth_measure = ::functions::auxiliary::init_sz_depth_measure(array);
                if(!sz_depth_measure.set_iterator(dimension-1,index))
                    return std::shared_ptr<ArrayNode>();
                std::shared_ptr<ArrayNode> result;
                if(dimension>sz_depth_measure.dimensions())
                    return std::shared_ptr<ArrayNode>();
                while(sz_depth_measure.is_iterable())
                    result->insert_back(::functions::auxiliary::first_node_not_var_by_ids(array,sz_depth_measure));
                return result;
            }
            return std::shared_ptr<ArrayNode>();
        }
    }
}