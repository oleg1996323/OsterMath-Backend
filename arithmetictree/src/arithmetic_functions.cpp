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

void functions::auxiliary::init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array){
    sz_depth_measure.push_back(array->size());
    if(array->size()!=0 && array->child(0)->type()==NODE_TYPE::ARRAY)
        init_sz_depth_measure(sz_depth_measure,reinterpret_cast<ArrayNode*>(array->child(0).get()));
}

bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays, size_t& loc_c){
    if(std::all_of(arrays.begin(),arrays.end(),[&sz_depth_measure, &loc_c](ArrayNode* array){
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

bool functions::auxiliary::check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays){
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

bool functions::auxiliary::arrays_numeric(const std::vector<ArrayNode*>& arrays){
    return std::all_of(arrays.begin(),arrays.end(),[](ArrayNode* node){
        return node->is_numeric();
    });
}

bool functions::auxiliary::arrays_string(const std::vector<ArrayNode*>& arrays){
    return std::all_of(arrays.begin(),arrays.end(),[](ArrayNode* node){
        return node->is_string();
    });
}

TYPE_VAL functions::auxiliary::getting_arrays_type(const std::vector<ArrayNode*>& arrays){
    if(arrays_numeric(arrays))
        return TYPE_VAL::NUMERIC_ARRAY;
    else if(arrays_string(arrays))
        return TYPE_VAL::STRING_ARRAY;
    else return TYPE_VAL::UNKNOWN;
}

Value_t functions::Arithmetic::SumProduct(const std::vector<ArrayNode*>& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    std::vector<Value_t> value_vector;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
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
            std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))*=node->execute().get<Value_t>();
            std::cout<<value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))<<std::endl;
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    result = std::accumulate(value_vector.begin(),value_vector.end(),Value_t(0));
    return result;
}

Value_t functions::Arithmetic::Sum(const std::vector<ArrayNode*>& arrays){
    Value_t result = 0.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
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
            std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            result+=node->execute().get<Value_t>();
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    return result;
}

Value_t functions::Arithmetic::Product(const std::vector<ArrayNode*>& arrays){
    Value_t result = 1.;
    std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
    {
        std::vector<size_t> sz_depth_measure;
        {
            if(!functions::auxiliary::arrays_numeric(arrays))
                throw exceptions::IncorrectTypeArrays("numeric");

            if(!functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays))
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
            std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
            result*=node->execute().get<Value_t>();
        } while (++*proxy_array_iterator.get());
        proxy_array_iterator->reset_iterator();
    }

    return result;
}
