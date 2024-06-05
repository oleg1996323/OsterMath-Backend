#include "arithmetic_functions.h"
#include "array_node.h"
#include "var_node.h"
#include "exception.h"

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

Value_t SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays, size_t dimensions){
    Value_t result = 0.;
    std::vector<size_t> sz_depth_measure;
    std::vector<Value_t> value_vector;
    size_t measure_depth = 0;
    
    std::optional<std::exception> err_handler;

    err_handler = functions::auxiliary::arrays_numeric(arrays);
    if(err_handler.has_value())
        throw err_handler.value();

    err_handler = functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays);
    if(err_handler.has_value())
        throw err_handler.value();

    {
        size_t seq_sz = 1;
        for(size_t sz:sz_depth_measure){
            seq_sz*=sz;
        }
        value_vector.resize(seq_sz);
        measure_depth = sz_depth_measure.size();
    }

    // std::vector<std::shared_ptr<ArrayNode>> def;
    // std::vector<std::shared_ptr<ArrayNode>> cache;
    for(std::shared_ptr<ArrayNode>& array:arrays){
        for(size_t id_zero_depth = 0;id_zero_depth<array->size();++id_zero_depth){
            auto node = array->child(id_zero_depth);
            for(size_t depth=1;depth<measure_depth;++depth){
                
            }
                for(size_t id = 0;id<sz_depth_measure.at(iter);++id)
                    node = array->child(id);
        }
        
        std::vector<std::shared_ptr<ArrayNode>> cached;
        for(size_t iter=0;iter<measure_depth;++iter)
            for(size_t id = 0;id<sz_depth_measure.at(iter);++id)
                node = array->child(id);
    }

    // for(size_t depth=0;depth<measure_depth;++depth){
    //     for()
    //     if(depth==measure_depth-1)
    //         value_vector
    // }

    // {
    //     for(size_t depth = 0;depth<sz_depth_measure.size();++depth){
    //         for(auto array:arrays)
                
    //     }
    //     std::vector<Value_t> cache(sz_depth_measure.back(),1);
    //     for(auto array:arrays)
    //         for(size_t i = 0;i<array.size();++i)
    //             array->child(i);
    //     for(size_t i = 0;i<arrays.size();++i)
    //         a

    //     for(size_t depth = 0; depth<value_vector.size();++depth){
            
    //     }
    // }

    for(size_t i=0;i<arrays.front()->size();++i){
        Value_t product = 1.;
        //добавить std::inner_product и std::accumulate
        for(std::shared_ptr<ArrayNode>& arr: arrays){
            product *= arr->child(i)->execute();
        }
        result+=product;
    }
    return result;
}

Value_t functions::Arithmetic::SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    Value_t result = 0.;
    std::vector<size_t> sz_depth_measure;
    std::vector<Value_t> value_vector;
    
    std::optional<std::exception> err_handler;

    err_handler = functions::auxiliary::arrays_numeric(arrays);
    if(err_handler.has_value())
        throw err_handler.value();

    err_handler = functions::auxiliary::check_sizes_arrays(sz_depth_measure,arrays);
    if(err_handler.has_value())
        throw err_handler.value();

    {
        size_t seq_sz = 1;
        for(size_t sz:sz_depth_measure){
            seq_sz*=sz;
        }
        value_vector.resize(seq_sz);
    }

    for(size_t depth = 0; depth<value_vector.size();++depth){
        if(depth==value_vector.size()-1){
            for()
        }
    }

    for(size_t i=0;i<arrays.front()->size();++i){
        Value_t product = 1.;
        //добавить std::inner_product и std::accumulate
        for(std::shared_ptr<ArrayNode>& arr: arrays){
            product *= arr->child(i)->execute();
        }
        result+=product;
    }
    return result;
}

#include <algorithm>
#include <numeric>
#include <arithmetic_types.h>

Value_t functions::Arithmetic::Sum(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    using namespace std;
    Value_t result = 0.;
    std::vector<size_t> sz_depth_measure;
    checking(sz_depth_measure,arrays);
    for(auto array:arrays){
        
        result = accumulate(array.get().begin(), array.get().end(),result,[](const Array_val& lhs, const Array_val& rhs){
            Value_t res;
            if(lhs.is_expression())
                res = lhs.get<ArithmeticTree>().value();
            else if(lhs.is_value()){
                res = lhs.get<Value_t>();
            }
            else{
                auto var = lhs.get<VariableBase*>();
                if(var->is_arithmetic_tree())
                    res = var->node()->execute();
                else if(var->is_value())
                    res = var->get<Value_t>();
                else throw std::invalid_argument("Invalid type of variable");
            }

            if(rhs.is_expression())
                res += rhs.get<ArithmeticTree>().value();
            else if(rhs.is_value()){
                res += rhs.get<Value_t>();
            }
            else{
                auto var = rhs.get<VariableBase*>();
                if(var->is_arithmetic_tree())
                    res += var->node()->execute();
                else if(var->is_value())
                    res += var->get<Value_t>();
                else throw std::invalid_argument("Invalid type of variable");
            }

            return res;
        });
    }
    return result;
}

Value_t functions::Arithmetic::Product(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    using namespace std;
    Value_t result = 1.;
    checking(arrays);
    for(auto array:arrays){
        
        result = accumulate(array.get().begin(), array.get().end(),result,[](const Array_val& lhs, const Array_val& rhs){
            Value_t res;
            if(lhs.is_expression())
                res = lhs.get<ArithmeticTree>().value();
            else if(lhs.is_value()){
                res = lhs.get<Value_t>();
            }
            else{
                auto var = lhs.get<VariableBase*>();
                if(var->is_arithmetic_tree())
                    res = var->node()->execute();
                else if(var->is_value())
                    res = var->get<Value_t>();
                else throw std::invalid_argument("Invalid type of variable");
            }

            if(rhs.is_expression())
                res *= rhs.get<ArithmeticTree>().value();
            else if(rhs.is_value()){
                res *= rhs.get<Value_t>();
            }
            else{
                auto var = rhs.get<VariableBase*>();
                if(var->is_arithmetic_tree())
                    res *= var->node()->execute();
                else if(var->is_value())
                    res *= var->get<Value_t>();
                else throw std::invalid_argument("Invalid type of variable");
            }

            return res;
        });
    }
    return result;
}