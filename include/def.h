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