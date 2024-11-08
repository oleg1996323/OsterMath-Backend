#pragma once
#include <type_traits>
#include <vector>
#include "array_node.h"

template<typename Container>
concept ContainersRequirements = requires(Container&& cont){
    { cont.begin() } -> std::same_as<decltype(cont.begin())>;
    { cont.end() } -> std::same_as<decltype(cont.end())>;
    { cont.cbegin() } -> std::same_as<decltype(cont.cbegin())>;
    { cont.cend() } -> std::same_as<decltype(cont.cend())>;
} && 
requires {
    typename std::decay_t<Container>::value_type;
};

template<typename Cont_1, typename Cont_2>
requires ContainersRequirements<Cont_1> && ContainersRequirements<Cont_2>
std::vector<Value_t> CovariationMatrix(Cont_1&& arr_1, Cont_2&& arr_2){

}