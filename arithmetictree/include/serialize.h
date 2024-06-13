#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <functional>
#include "node.h"
#include "def.h"

class DataPool;
class BaseData;

namespace serialization{

class SerialData{
    public:
    std::fstream data_stream_;

    void open_to_write(const std::filesystem::path& path){
        data_stream_.open(path, std::ios::out | std::ios::binary);
        if(data_stream_.is_open())
            path_=std::move(path);
        else throw std::runtime_error(std::string("Impossible to open the file ")+path.string());
    }

    void open_to_write(std::filesystem::path&& path){
        open_to_write(path);
    }

    void insert_node(uint64_t id, std::shared_ptr<Node> node){
        if(node)
            nodes_[id]=node;
    }

    void insert_data(uint64_t id, BaseData* db){
        if(db!=nullptr)
            data_bases_[id]=db;
    }

    void insert_pool(uint64_t id, DataPool* pool){
        if(pool!=nullptr)
            pools_[id]=pool;
    }

    bool contains_pool(uint64_t pool_id){
        return pools_.contains(pool_id);
    }

    bool contains_node(uint64_t node_id){
        return nodes_.contains(node_id);
    }

    bool contains_data(uint64_t db_id){
        return data_bases_.contains(db_id);
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

    DataPool* get_pool(uint16_t hash){
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

    void add_dependency(uint64_t parent_id, uint64_t child_id) noexcept{
        nodes_dependencies_[parent_id].push_back(child_id);
    }

    void insert_var(uint64_t var_id, const std::shared_ptr<VariableNode>& node) noexcept;

    void serialize_header(DataPool* pool);

    void serialize_body(DataPool* pool);

    DataPool deserialize_header();

    void deserialize_body();
    
    private:
    std::filesystem::path path_;
    //add std::unordered_map for search and inserting at deserialization
    std::unordered_map<uint64_t,DataPool*> pools_;
    std::unordered_map<uint64_t,BaseData*> data_bases_;
    std::unordered_map<uint64_t,std::shared_ptr<Node>> nodes_;
    std::unordered_map<uint64_t,std::vector<uint64_t>> nodes_dependencies_;

    struct VarProperties{
        uint64_t id;
        uint8_t sz_name;
    };

    struct NodeProperties{
        Result cache = 0;
        uint64_t id;
        size_t sz;
        uint8_t type;
        uint8_t operation=0;
    };
};

// template <typename T>
// void serialize_structure(const SerialData& serial_data, T val){
//     stream.write(reinterpret_cast<const char*>(&val), sizeof(val));
// }

void serialize_to(const std::filesystem::path& path,DataPool* pool);
void serialize_to(std::filesystem::path&& path,DataPool* pool);
DataPool deserialize_from(const std::filesystem::path& path);
}