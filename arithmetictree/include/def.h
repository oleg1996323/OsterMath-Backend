#pragma once
constexpr double sat_deriv = 3.727888004; //derivative of the saturation-temperature equation
constexpr double crit_pres = 22.064; // water critical pressure
constexpr double crit_temp = 647.096; // water critical temperature

using Temperature = double; //K
using Pressure = double; //MPa

enum class TempBoundName{
    crt_t,ab,ef,op,cd,gh,ij,jk,mn,qu,rx,uv,wx,B23,sat_t
};

enum class TypeFile{
    ZONE,
    BOUNDS    
};

#include <string>
#include <map>

static const std::map<std::string,TypeFile> types_by_names = {
    {"zones",TypeFile::ZONE},
    {"bounds",TypeFile::BOUNDS}
};

#include <type_traits>

template<typename... T>
  struct all_same : std::false_type { };

template<>
  struct all_same<> : std::true_type { };

template<typename T>
  struct all_same<T> : std::true_type { };

template<typename T, typename... Ts>
  struct all_same<T, T, Ts...> : all_same<T, Ts...> { };

#include <boost/multiprecision/cpp_dec_float.hpp>

class Array_val;
class VariableBase;
class ArithmeticTree;
class Array_t;

#include <variant>

using Value_t = boost::multiprecision::cpp_dec_float_50;

//needed for using variables and values in array
using Arr_value = std::variant<std::monostate,Value_t,std::string, VariableBase*, ArithmeticTree>;
using __types__ = std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree>;

// class __types_proxy__:private __types__{
//     public:
//     bool is_arithmetic_tree() const;
//     bool is_value() const;
//     bool is_string() const;
//     bool is_array() const;
//     bool is_undef() const;

//     __types__& get();

//     const __types__& get() const;

//     template<typename T>
//     const T& get() const;

//     template<typename T>
//     T& get();
// };

// template<typename T>
// T& __types_proxy__::get(){
//     return std::get<T>(get());
// }

// template<typename T>
// const T& __types_proxy__::get() const{
//     return std::get<T>(get());
// }

// std::ostream& operator<<(std::ostream& stream, const __types_proxy__& var);