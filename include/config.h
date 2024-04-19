#pragma once
#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>
#include <boost/static_string/static_string.hpp>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <boost/math/differentiation/autodiff.hpp>

//#include <boost/json/parse.hpp>
#include "def.h"

#ifdef unix
    static const std::string ROOT_DIR = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("/"));
#else
    static const std::string ROOT_DIR = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("\\"));
#endif

using namespace boost::json;

class JsonConfigInit{
    public:
    JsonConfigInit(){
        std::ifstream config_stream(ROOT_DIR+"/Data/config.json");
        boost::json::value configs = std::move(boost::json::parse(config_stream));
        
        if(configs.is_object())
            for(const auto& [type, dir]: configs.as_object()){
                if(dir.is_string())
                    paths_dir_data_[types_by_names.at(type)] = dir.as_string();
            }
    }

    std::filesystem::path GetPath(TypeFile type) const{
        return ROOT_DIR + paths_dir_data_.at(type);
    }

    const std::unordered_map<TypeFile,std::string>& GetDataDirs() const{
        return paths_dir_data_;
    }

    private:
    std::unordered_map<TypeFile,std::string> paths_dir_data_;
};