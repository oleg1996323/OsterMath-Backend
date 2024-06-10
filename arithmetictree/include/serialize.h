#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include "node.h"

class DataPool;
class BaseData;

namespace serialization{

class SerialData{
    public:
    std::fstream data_stream_;

    void open_to_write(const std::filesystem::path& path){
        data_stream_.open(path, std::ios::out );
        if(data_stream_.is_open())
            path_=std::move(path);
        else throw std::runtime_error(std::string("Impossible to open the file ")+path.string());
    }

    void open_to_write(std::filesystem::path&& path){
        open_to_write(path);
    }

    void insert_node(std::shared_ptr<Node> node){
        dict_.insert(node);
    }

    bool contains_node(const std::shared_ptr<Node>& node){
        return dict_.contains(node);
    }

    void open_to_read(const std::filesystem::path& path){
        data_stream_.open(path, std::ios::in | std::ios_base::binary);
        if(data_stream_.is_open())
            path_=std::move(path);
        else throw std::runtime_error(std::string("Impossible to open the file ")+path.string());
    }

    void open_to_read(std::filesystem::path&& path){
        open_to_read(path);
    }

    void serialize_header(DataPool* pool);

    void serialize_body(DataPool* pool){
        // for(const std::shared_ptr<Node>& node:dict_){
            
        // }
    }

    DataPool deserialize_header();

    DataPool deserialize_body();
    
    private:
    std::filesystem::path path_;
    //add std::unordered_map for search and inserting at deserialization
    std::unordered_map<uint64_t,DataPool*> pools_;
    std::unordered_map<uint64_t,BaseData*> data_bases_;
    std::unordered_map<uint64_t,std::shared_ptr<Node>> nodes_;
    
};

// template <typename T>
// void serialize_structure(const SerialData& serial_data, T val){
//     stream.write(reinterpret_cast<const char*>(&val), sizeof(val));
// }

void serialize_to(const std::filesystem::path& path,DataPool* pool);
void serialize_to(std::filesystem::path&& path,DataPool* pool);
DataPool deserialize_from(const std::filesystem::path& path);
}