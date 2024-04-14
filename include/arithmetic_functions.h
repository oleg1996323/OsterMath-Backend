#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "types.h"

bool Checking_Egal_Size_Arrays(std::initializer_list<const Array>& arrays){
    size_t fst_arr_sz;
    if(arrays.size()!=0 && !arrays.begin()->empty())
        fst_arr_sz = arrays.begin()->size();
    for(const Array& arr: arrays){
        if(arr.size()!=fst_arr_sz)
            return false;
    }
    return true;
};

Value_t SumProduct(std::initializer_list<const Array>& arrays){
    Value_t result = 0.;
    if(Checking_Egal_Size_Arrays(arrays)){
        for(size_t i=0;i<arrays.begin()->size();++i){
            Value_t product = 1.;
            for(const Array& arr: arrays)
                product *= arr.at(i);
            result+=product;
        }
    }
    return result;      
}