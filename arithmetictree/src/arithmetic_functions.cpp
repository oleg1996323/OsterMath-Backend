#include "arithmetic_functions.h"
#include "arithmetic_types.h"

bool functions::auxiliary::checking_egal_size_arrays(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    size_t first_arr_sz;
    if(arrays.size()!=0 && !arrays.front().get().empty())
        first_arr_sz = arrays.front().get().size();
    else throw std::invalid_argument("Invalid input arrays");
    for(const Array_t& arr: arrays){
        if(arr.size()!=first_arr_sz)
            return false;
    }
    return true;
}

TYPE_VAL functions::auxiliary::getting_arrays_type(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    TYPE_VAL type = TYPE_VAL::UNKNOWN;
    for(auto& arr:arrays){
        if(type == TYPE_VAL::UNKNOWN){
            if(arr.get().type()!=TYPE_VAL::UNKNOWN){
                type=arr.get().type();
                continue;
            }
            else throw std::invalid_argument("Unknown type of array");
        }
        if(type!=arr.get().type())
            throw std::invalid_argument("Invalid type of array");
    }
    return type;
}

bool functions::Arithmetic::checking(std::vector<std::shared_ptr<ArrayNode>>& arrays){
    if(auxiliary::getting_arrays_type(arrays)==TYPE_VAL::NUMERIC)
        return auxiliary::checking_egal_size_arrays(arrays);
    else throw std::invalid_argument("Arrays must be numeric");
}

Value_t functions::Arithmetic::SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays){
    Value_t result = 0.;
    checking(arrays);
    for(size_t i=0;i<arrays.front().childs().size();++i){
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