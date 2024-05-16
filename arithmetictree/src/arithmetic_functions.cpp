#include "arithmetic_functions.h"

bool functions::auxiliary::checking_egal_size_arrays(std::vector<std::reference_wrapper<const Array_t>>& arrays){
    size_t fst_arr_sz;
    if(arrays.size()!=0 && !arrays.front().get().empty())
        fst_arr_sz = arrays.front().get().size();
    for(const Array_t& arr: arrays){
        if(arr.size()!=fst_arr_sz)
            return false;
    }
    return true;
}

TYPE functions::auxiliary::getting_arrays_type(std::vector<std::reference_wrapper<const Array_t>>& arrays){
    TYPE type = TYPE::UNKNOWN;
    for(auto& arr:arrays){
        if(type == TYPE::UNKNOWN){
            if(arr.get().type()!=TYPE::UNKNOWN){
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

bool functions::Arithmetic::checking(std::vector<std::reference_wrapper<const Array_t>>& arrays){
    if(auxiliary::getting_arrays_type(arrays)==TYPE::NUMERIC)
        return auxiliary::checking_egal_size_arrays(arrays);
    else throw std::invalid_argument("Arrays must be numeric");
}

Value_t functions::Arithmetic::SumProduct(std::vector<std::reference_wrapper<const Array_t>>&& arrays){
    Value_t result = 0.;
    checking(arrays);
    for(size_t i=0;i<arrays.front().get().size();++i){
        Value_t product = 1.;
        //добавить std::inner_product и std::accumulate
        for(const Array_t& arr: arrays){
            if(arr.at(i).is_value())
                product *= arr.at(i).get<Value_t>();
            else if(arr.at(i).is_variable()){
                auto ptr = arr.at(i).get<VariableBase*>();
                if(ptr){
                    if(ptr->is_arithmetic_tree())
                        product *= ptr->get<ArithmeticTree>().execute();
                    else product *= ptr->get<Value_t>();
                }
                else throw std::invalid_argument("Variable don't exists");
            }
        }
        result+=product;
    }
    return result;
}

#include <algorithm>
#include <numeric>
#include <arithmetic_types.h>

Value_t functions::Arithmetic::Sum(std::vector<std::reference_wrapper<const Array_t>>&& arrays){
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

Value_t functions::Arithmetic::Product(std::vector<std::reference_wrapper<const Array_t>>&& arrays){
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