#include "function_node/math_functions.h"
#include "aux_functions.h"
#include "array_node.h"
#include "var_node.h"
#include "exception.h"
#include <algorithm>
#include <numeric>
#include <arithmetic_types.h>

Value_t node_function::functions::math::SumProduct(const std::vector<ArrayNode*>& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    std::vector<Value_t> value_vector;
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!::functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
                throw exceptions::UnequalSizeArrays("Sumproduct");
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    value_vector.resize(proxy_array_iterator->total_size_childs(),1);
    size_t array_depth = proxy_array_iterator->depth();

    for(auto array:arrays){
        do
        {
            Node* node = array;
            for(size_t depth=0; depth<array_depth;++depth){
                //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                node = node->child(proxy_array_iterator->current_iterator(depth)).get();
            }
            //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))*=node->execute().get<Value_t>();
            //std::cout<<value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))<<std::endl;
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    result = std::accumulate(value_vector.begin(),value_vector.end(),Value_t(0));
    return result;
}

Value_t node_function::functions::math::Sum(const std::vector<ArrayNode*>& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!::functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
                throw exceptions::UnequalSizeArrays("Sum");
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    size_t array_depth = proxy_array_iterator->depth();
    //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(0)<<std::endl;

    for(auto& array:arrays){
        do
        {
            Node* node = array;
            for(size_t depth=0; depth<array_depth;++depth){
                //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                node = node->child(proxy_array_iterator->current_iterator(depth)).get();
            }
            //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            result+=node->execute().get<Value_t>();
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    return result;
}

Value_t node_function::functions::math::Product(const std::vector<ArrayNode*>& arrays){
    Value_t result = 1.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!::functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
                throw exceptions::UnequalSizeArrays("Product");
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    size_t array_depth = proxy_array_iterator->depth();
    //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(0)<<std::endl;

    for(auto& array:arrays){
        do
        {
            Node* node = array;
            for(size_t depth=0; depth<array_depth;++depth){
                //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                node = node->child(proxy_array_iterator->current_iterator(depth)).get();
            }
            //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            result*=node->execute().get<Value_t>();
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    return result;
}

#include <correlation.h>

Value_t node_function::functions::math::CorrelationCoefficient(const ArrayNode* arr_1,const ArrayNode* arr_2){
    return CorrelationCoefficient(std::execution::seq,arr_1,arr_2);
}
