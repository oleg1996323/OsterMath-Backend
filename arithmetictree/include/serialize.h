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
        if(node)
            nodes_[(uint64_t)node.get()]=node;
    }

    void insert_data(BaseData* db){
        if(db!=nullptr)
            data_bases_[(uint64_t)db]=db;
    }

    void insert_pool(DataPool* pool){
        if(pool!=nullptr)
            pools_[(uint64_t)pool]=pool;
    }

    bool contains_node(const std::shared_ptr<Node>& node){
        return nodes_.contains((uint64_t)node.get());
    }

    bool contains_data(const BaseData* data){
        return data_bases_.contains((uint64_t)data);
    }

    std::shared_ptr<Node> get_node(uint64_t hash){
        if(nodes_.contains(hash))
            return nodes_.at(hash);
        else throw std::runtime_error("Undefined hash of node");
    }

    BaseData* get_db(uint64_t hash){
        if(data_bases_.contains(hash))
            return data_bases_.at(hash);
        else throw std::runtime_error("Undefined hash of data base");
    }

    DataPool* get_pool(uint64_t hash){
        if(pools_.contains(hash))
            return pools_.at(hash);
        else throw std::runtime_error("Undefined hash of data base");
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

    void serialize_body(DataPool* pool);

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