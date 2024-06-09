#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include "node.h"

class DataPool;

namespace serialization{

class SerialData{
    public:
    std::fstream data_stream_;

    void open_to_write(const std::filesystem::path& path){
        data_stream_.open(path, std::ios::out | std::ios_base::binary);
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

    void serialize_header(){
        for(std::shared_ptr<Node>& node:dict_){
            data_stream_.write((char*)node.get(), sizeof(uint32_t));
            //data_stream_. //add type, operation type and maybe size if array, function or rangeoperation
            //may be necessary to use virtual serialize_header and serialize (for body)
        }
        data_stream_.write("\n/h",3); //header and body separator
    }

    void serialize_body(){
        for(std::shared_ptr<Node>& node:dict_){
            data_stream_.write()
        }
    }
    
    private:
    std::filesystem::path path_;
    //add std::unordered_map for search and inserting at deserialization
    std::unordered_set<std::shared_ptr<Node>> dict_;
    
};

// template <typename T>
// void serialize_structure(const SerialData& serial_data, T val){
//     stream.write(reinterpret_cast<const char*>(&val), sizeof(val));
// }

void serialize_to(const std::filesystem::path& path,DataPool* pool);
void serialize_to(std::filesystem::path&& path,DataPool* pool);
}