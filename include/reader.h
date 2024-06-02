#pragma once
#include <fstream>
#include <filesystem>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <functional>
#include <memory>
#include <execution>
#include <future>
#include <string_view>
#include <unordered_map>

#include "config.h"

#include "exception/exception.h"
#include "def.h"
#include "expr_parser.h"

using namespace boost::multiprecision;

//в парсер рассмотреть вложенные функции func(func()) с рекурсией парсинга

struct CallbackEquation{

    template<typename... ARGS>
    std::function<cpp_dec_float_50(ARGS...)> function(ARGS...);
};

// class DataInitialize{

//     DataInitialize(){}

//     void Configure() const{
//         using namespace std::filesystem;
//         JsonConfigInit inition_;
//         const auto& data_ = inition_.GetDataDirs();
//         for(const auto& [type,dir]:data_){
//             for(const auto& entry: directory_iterator(ROOT_DIR+dir)){
//                 if(entry.is_regular_file())
//                     paths_[type].push_back(entry.path());
//             }
//         }
//     }

//     void InitializeZones(){
//         std::vector<std::future<Parser>> futures;
//         for(std::string_view file:paths_.find(TypeFile::ZONE)->second){
//             futures.push_back(std::async(std::launch::async,[&file]()->Parser{
//                 std::ifstream&& stream = std::move(std::ifstream(std::filesystem::path(file)));
//                 return Parser(stream,TypeFile::ZONE);
//             }));
//         }
//     }

//     void InitializeBounds(){
//         std::vector<std::future<Parser>> futures;
//         for(std::string_view file:paths_.find(TypeFile::BOUNDS)->second){
//             futures.push_back(std::async(std::launch::async,[&file](){
//                 std::ifstream&& stream = std::move(std::ifstream(std::filesystem::path(file)));
//                 return Parser(stream,TypeFile::BOUNDS);
//             }));
//         }
//     }

//     private:

//     //vector for multithreading by-directory recursive file parsing with different specifications
//     mutable std::unordered_map<TypeFile,std::vector<std::string>> paths_;
//     std::vector<Parser> parser_; 
    
// };