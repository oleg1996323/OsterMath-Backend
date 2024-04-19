#include "zonebound.h"

using namespace Bound;

Temperature TemperatureBound::GetTempByPressure(Pressure pres) const{
    return equations.at(name_)(pres,param_);
}

void TemperatureBound::Init(){
    std::ifstream stream(paths.at(name_),std::ifstream::out);
    std::vector<std::string> header;
    while(stream>>header.emplace_back()){}
    
    std::string buf;
    std::getline(stream, buf);

    int header_count = 0;
    while (stream>>buf){
        while(stream>>buf){
            switch (header_count)
            {
            case 1:
                param_.Ii.emplace_back(std::stod(buf));
                break;
            
            case 2:
                param_.ni.emplace_back(std::stod(buf));
            default:
                break;
            }
            ++header_count;
        }
        std::getline(stream, buf);
    }
}

TemperatureBound::TemperatureBound(TempBoundName name):name_(name){
    Init();
}