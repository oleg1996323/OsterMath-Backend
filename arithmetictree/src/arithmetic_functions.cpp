#include "arithmetic_functions.h"

bool checking_egal_size_arrays(std::vector<std::reference_wrapper<const Array_t>>& arrays){
    size_t fst_arr_sz;
    if(arrays.size()!=0 && !arrays.front().get().empty())
        fst_arr_sz = arrays.front().get().size();
    for(const Array_t& arr: arrays){
        if(arr.size()!=fst_arr_sz)
            return false;
    }
    return true;
};

Array_t::TYPE getting_arrays_type(std::vector<std::reference_wrapper<const Array_t>>& arrays){
    Array_t::TYPE type = Array_t::TYPE::UNKNOWN;
    for(auto& arr:arrays){
        if(arr.get().type()==type && type!=Array_t::TYPE::UNKNOWN)
            continue;
        else if(type==Array_t::TYPE::UNKNOWN && arr.get().type()!=Array_t::TYPE::UNKNOWN)
            type = arr.get().type();
        else throw std::invalid_argument("Incorrect array type");
    }
    return type;
}

Value_t SumProduct(std::vector<std::reference_wrapper<const Array_t>>&& arrays){
    if(getting_arrays_type(arrays)==Array_t::TYPE::NUMERIC){
        Value_t result = 0.;
        if(checking_egal_size_arrays(arrays)){
            for(size_t i=0;i<arrays.front().get().size();++i){
                Value_t product = 1.;
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
        }
        return result;
    }
    else{
        throw std::invalid_argument("Arrays must be numeric");
    }
}