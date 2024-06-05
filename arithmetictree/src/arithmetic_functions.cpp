#include "arithmetic_functions.h"
#include "array_node.h"
#include "var_node.h"
#include "exception.h"

#include <algorithm>
#include <numeric>
#include <arithmetic_types.h>

size_t pow(size_t base, size_t pow){
    if(pow>0){
        for(;pow>0;--pow){
            base*=base;
        }
        return base;
    }
    else return 1;    
}

std::optional<std::invalid_argument> functions::auxiliary::check_sizes_arrays(std::vector<size_t>& sz_depth_measure,std::vector<std::shared_ptr<ArrayNode>>& arrays){
    if(arrays.size()!=0 && !arrays.front()->empty())
        sz_depth_measure.push_back(arrays.front()->size());
    else return std::nullopt;

    if(!std::all_of(arrays.begin(),arrays.end(),[&sz_depth_measure](const std::shared_ptr<ArrayNode>& array){

        if(std::all_of(array->begin(),array->end(),[](std::shared_ptr<Node>& node){return node->type()==NODE_TYPE::ARRAY;}))
        {
            std::vector<std::shared_ptr<ArrayNode>> in_arrays;
            in_arrays.reserve(array->size());
            for(std::shared_ptr<Node>& item_array:*array.get()){
                in_arrays.push_back(reinterpret_cast<std::shared_ptr<ArrayNode>&>(item_array));
            }
            return array->size()==sz_depth_measure.back() && check_sizes_arrays(sz_depth_measure,in_arrays);
        }
        return array->size()==sz_depth_measure.back();
    }))
        return UnequalSizeArrays("The sizes of arrays are not equal");
    else return std::nullopt;
}

std::optional<std::invalid_argument> functions::auxiliary::arrays_numeric(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    if(!std::all_of(arrays.begin(),arrays.end(),[](const std::shared_ptr<ArrayNode>& node){
        return node->is_numeric();
    }))
        return UnknownTypeArrays("The array must be numeric");
    else return std::nullopt;
}

std::optional<std::invalid_argument> functions::auxiliary::arrays_string(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    if(!std::all_of(arrays.begin(),arrays.end(),[](const std::shared_ptr<ArrayNode>& node){
        return node->is_string();
    }))
        return UnknownTypeArrays("The array must be literal (string)");
    else return std::nullopt;
}

TYPE_VAL functions::auxiliary::getting_arrays_type(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    if(arrays_numeric(arrays))
        return TYPE_VAL::NUMERIC;
    else if(arrays_string(arrays))
        return TYPE_VAL::STRING;
    else throw std::invalid_argument("Unknown type of array");
}

Value_t functions::Arithmetic::SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    std::vector<Value_t> value_vector;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            std::optional<std::exception> err_handler;

            err_handler = functions::auxiliary::arrays_numeric(arrays);
            if(err_handler.has_value())
                throw err_handler.value();

            err_handler = functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays);
            if(err_handler.has_value())
                throw err_handler.value();
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    value_vector.resize(proxy_array_iterator->total_size_childs());
    size_t array_depth = proxy_array_iterator->depth();

    for(auto array:arrays){
        for(;proxy_array_iterator->is_iterable();++*proxy_array_iterator.get()){
            std::shared_ptr<Node> node;
            for(size_t depth=1; depth<array_depth;++depth){
                node = array->child(proxy_array_iterator->current_iterator(depth));
            }
            value_vector.at(proxy_array_iterator->seq_iterator(1))*=node->execute().get<Value_t>();
        }
    }

    result = std::accumulate(value_vector.begin(),value_vector.end(),0);
    return result;
    // for(size_t i=0;i<arrays.front()->size();++i){
    //     Value_t product = 1.;
    //     //добавить std::inner_product и std::accumulate
    //     for(std::shared_ptr<ArrayNode>& arr: arrays){
    //         product *= arr->child(i)->execute();
    //     }
    //     result+=product;
    // }
    // return result;
}

Value_t functions::Arithmetic::Sum(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            std::optional<std::exception> err_handler;

            err_handler = functions::auxiliary::arrays_numeric(arrays);
            if(err_handler.has_value())
                throw err_handler.value();

            err_handler = functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays);
            if(err_handler.has_value())
                throw err_handler.value();
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    size_t array_depth = proxy_array_iterator->depth();

    for(auto array:arrays){
        for(;proxy_array_iterator->is_iterable();++*proxy_array_iterator.get()){
            std::shared_ptr<Node> node;
            for(size_t depth=1; depth<array_depth;++depth){
                node = array->child(proxy_array_iterator->current_iterator(depth));
            }
            result+=node->execute().get<Value_t>();
        }
    }

    return result;
}

Value_t functions::Arithmetic::Product(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    Value_t result = 1.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            std::optional<std::exception> err_handler;

            err_handler = functions::auxiliary::arrays_numeric(arrays);
            if(err_handler.has_value())
                throw err_handler.value();

            err_handler = functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays);
            if(err_handler.has_value())
                throw err_handler.value();
        }

        for(auto sz:sz_depth_measure){
            if(!proxy_array_iterator)
                proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
            else proxy_array_iterator->push(sz);
        }
    }

    size_t array_depth = proxy_array_iterator->depth();

    for(auto array:arrays){
        for(;proxy_array_iterator->is_iterable();++*proxy_array_iterator.get()){
            std::shared_ptr<Node> node;
            for(size_t depth=1; depth<array_depth;++depth){
                node = array->child(proxy_array_iterator->current_iterator(depth));
            }
            result+=node->execute().get<Value_t>();
        }
    }

    return result;
}