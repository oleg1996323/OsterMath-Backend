#include "serialize.h"
#include "data.h"
#include "arithmetic_types.h"
#include <iostream>

namespace serialization{

void serialize_to(const std::filesystem::path& path,DataPool* pool){
    SerialData serial_data;
    serial_data.open_to_write(path);
    serial_data.serialize_header(pool);
    //pool->serialize(file);
    serial_data.data_stream_.close();
}

void SerialData::serialize_header(DataPool* pool){
    uint32_t sz=0;
    data_stream_.write("/OMB\n",5);
    //pool name size and pool name
    sz = pool->name().size();
    data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
    data_stream_.write(pool->name().data(),pool->name().size());
    //pool hash
    uint32_t pool_ptr = (uint32_t)pool;
    data_stream_.write(reinterpret_cast<const char*>(&pool_ptr),sizeof(uint32_t));

    //number of data_bases
    sz = pool->data_bases().size();
    data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
    
    for(auto& [db_name,data_base]:pool->data_bases()){
        data_stream_.write((char*)pool,sizeof(pool_ptr));

        //database name size and database name
        sz = db_name.size();
        data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
        data_stream_.write(db_name.data(), db_name.size());
        //database hash
        uint16_t db_id = data_base.id();
        std::cout<<"DataBase id:"<<db_id<<std::endl;
        data_stream_.write(reinterpret_cast<const char*>(&db_id),sizeof(uint16_t));

        //number of variables
        sz = data_base.variables().size();
        data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
        if(!data_base.variables().empty()){

            for(auto& [var_name,var]:data_base.variables()){
                //variable name size and variable name
                sz = var_name.size();
                data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
                data_stream_.write(var_name.data(),var_name.size());
                //variable hash
                uint32_t var_id = var->node()->id();
                std::cout<<"Variable id:"<<var_id<<std::endl;
                data_stream_.write(reinterpret_cast<const char*>(&var_id),sizeof(uint32_t));
                data_stream_.write("\r\n", 2);
                insert_node(reinterpret_cast<const std::shared_ptr<Node> &>(var->node()));
            }
            data_stream_.seekp(-2,std::ostream::end);
        }
        data_stream_.write("\r\n", 2);
    }

    //add type, operation type and maybe size if array, function or rangeoperation
    //may be necessary to use virtual serialize_header and serialize (for body)
}

DataPool SerialData::deserialize_header(){
    uint32_t sz=0;
    char* fmt_ctrl;
    data_stream_.read(fmt_ctrl,5);
    //pool name size and pool name
    data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));

    std::string pool_name(sz,0);
    data_stream_.read(pool_name.data(),sz);

    DataPool pool(pool_name);
    //pool hash
    uint32_t pool_ptr;
    data_stream_.read(reinterpret_cast<char*>(&pool_ptr),sizeof(uint32_t));
    

    //number of data_bases
    data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));
    
    for(decltype(sz) iter = 0; iter<sz;++iter){
        uint32_t t_pool_id;
        
        data_stream_.read(reinterpret_cast<char*>(&t_pool_id),sizeof(t_pool_id));
        
        data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));
        std::string db_name(sz,0);
        data_stream_.read(db_name_ch.data(), sz);

        BaseData* db = pool.add_data(db_name);

        //database hash
        uint16_t db_id;
        
        data_stream_.read(reinterpret_cast<char*>(&db_id),sizeof(uint16_t));
        std::cout<<"DataBase id:"<<db_id<<std::endl;
        //insert in serial data base

        //number of variables
        data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));
        if(sz!=0){
            for(auto& [var_name,var]:data_base.variables()){
                //variable name size and variable name
                data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));
                std::string var_name(sz,0);
                data_stream_.read(var_name.data(),sz);
                db->add_variable(std::move(var_name));
                //variable hash
                uint32_t var_id ;
                data_stream_.read(reinterpret_cast<char*>(&var_id),sizeof(uint32_t));
                std::cout<<"Variable id:"<<var_id<<std::endl;
                data_stream_.read(void*, 2);
                //insert_node(reinterpret_cast<const std::shared_ptr<Node> &>(var->node()));
            }
        }
        else data_stream_.read("\r\n", 2);
    }

    return pool;
}

DataPool SerialData::deserialize_body(){

}

void serialize_to(std::filesystem::path&& path,DataPool* pool){
    serialize_to(path,pool);
}

}