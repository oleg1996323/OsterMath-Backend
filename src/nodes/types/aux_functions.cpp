#include "aux_functions.h"
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

std::shared_ptr<ArrayNode> functions::auxiliary::to_array_node(const std::shared_ptr<Node>& node) noexcept{
    return reinterpret_cast<const std::shared_ptr<ArrayNode>&>(node);
}
std::shared_ptr<ValueNode> functions::auxiliary::to_value_node(const std::shared_ptr<Node>& node) noexcept{
    return reinterpret_cast<const std::shared_ptr<ValueNode>&>(node);
}

bool functions::auxiliary::check_sizes_arrays(const std::vector<ArrayNode*>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,arrays);
}
