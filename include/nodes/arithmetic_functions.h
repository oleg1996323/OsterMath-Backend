#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>
#include <def.h>
#include <optional>
#include "events_errors/exception.h"
#include <execution>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array);
        bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays);
        TYPE_VAL getting_arrays_type(const std::vector<ArrayNode*>& arrays);

        bool arrays_numeric(const std::vector<ArrayNode*>& arrays);
        bool arrays_string(const std::vector<ArrayNode*>& arrays);
    }

    namespace Arithmetic{
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays);

        //calculate the summ of production till the defined dimension.
        //For example, if the array present a cubic dimention data for the dimensions = 2 there will be 
        //calculated only the square base of these array. Althought the calculation may depends of arrays order.
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays, size_t dimensions);

        
        Value_t Sum(const std::vector<ArrayNode*>& arrays);
        Value_t Product(const std::vector<ArrayNode*>& arrays);

        Value_t CorrelationCoefficient(const ArrayNode*, const ArrayNode*)
        template<typename ExecutionPolicy>
        Value_t CorrelationCoefficient(ExecutionPolicy&& exec,const ArrayNode* arr_1, const ArrayNode* arr_2){
            if constexpr (std::is_same_v<std::remove_reference_t<decltype(exec)>, decltype(std::execution::seq)>){
                using Real = typename std::tuple_element<0, ReturnType>::type;
                using std::sqrt;

                Real cov = 0;
                ForwardIterator u_it = u_begin;
                ForwardIterator v_it = v_begin;
                Real mu_u = *u_it++;
                Real mu_v = *v_it++;
                Real Qu = 0;
                Real Qv = 0;
                std::size_t i = 1;

                while(u_it != u_end && v_it != v_end)
                {
                    Real u_tmp = *u_it++ - mu_u;
                    Real v_tmp = *v_it++ - mu_v;
                    Qu = Qu + (i*u_tmp*u_tmp)/(i+1);
                    Qv = Qv + (i*v_tmp*v_tmp)/(i+1);
                    cov += i*u_tmp*v_tmp/(i+1);
                    mu_u = mu_u + u_tmp/(i+1);
                    mu_v = mu_v + v_tmp/(i+1);
                    ++i;
                }


                // If one dataset is constant, then the correlation coefficient is undefined.
                // See https://stats.stackexchange.com/questions/23676/normalized-correlation-with-a-constant-vector
                // Thanks to zbjornson for pointing this out.
                if (Qu == 0 || Qv == 0)
                {
                    return std::make_tuple(mu_u, Qu, mu_v, Qv, cov, std::numeric_limits<Real>::quiet_NaN(), Real(i));
                }

                // Make sure rho in [-1, 1], even in the presence of numerical noise.
                Real rho = cov/sqrt(Qu*Qv);
                if (rho > 1) {
                    rho = 1;
                }
                if (rho < -1) {
                    rho = -1;
                }

                return std::make_tuple(mu_u, Qu, mu_v, Qv, cov, rho, Real(i));
            }
            else{
                
            }
        }

        size_t pow(size_t base, size_t pow);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}