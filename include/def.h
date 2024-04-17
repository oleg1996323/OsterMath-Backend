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

using Value_t = boost::multiprecision::cpp_dec_float_50;
using Array_t = std::vector<Value_t>;

class ArithmeticTree;

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree);

std::ostream& operator<<(std::ostream& stream, const Array_t& arr);

#include <variant>
std::ostream& operator<<(std::ostream& stream, std::monostate empty);