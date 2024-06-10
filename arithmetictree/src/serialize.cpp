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

DataPool deserialize_from(const std::filesystem::path& path){
    SerialData serial_data;
    serial_data.open_to_read(path);
    DataPool pool = serial_data.deserialize_header();
    serial_data.data_stream_.close();
    return pool;
}

void SerialData::serialize_header(DataPool* pool){
    uint32_t sz=0;
    data_stream_.write("/OMB\n",5);
    //pool name size and pool name
    sz = pool->name().size();
    data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
    data_stream_.write(pool->name().data(),pool->name().size());
    //pool hash
    uint64_t pool_ptr = (uint64_t)pool;
    std::cout<<"Pool pointer: "<<pool_ptr<<std::endl;
    data_stream_.write(reinterpret_cast<const char*>(&pool_ptr),sizeof(uint64_t));

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
        uint64_t db_ptr = (uint64_t)&data_base;
        std::cout<<"DataBase id:"<<db_ptr<<std::endl;
        data_stream_.write(reinterpret_cast<const char*>(&db_ptr),sizeof(uint64_t));

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
                uint64_t var_ptr = (uint64_t)var.get();
                std::cout<<"Variable id:"<<var_ptr<<std::endl;
                data_stream_.write(reinterpret_cast<const char*>(&var_ptr),sizeof(uint64_t));
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
    {
        std::string fmt_ctrl(5,0);
        data_stream_.read(fmt_ctrl.data(),5);
        if(fmt_ctrl!="/OMB\n")
            throw std::runtime_error("Incorrect format");
    }

    //pool name size and pool name
    data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));

    std::string pool_name(sz,0);
    data_stream_.read(pool_name.data(),sz);

    DataPool pool(pool_name);
    //pool hash
    uint64_t pool_ptr;
    data_stream_.read(reinterpret_cast<char*>(&pool_ptr),sizeof(uint64_t));
    

    //number of data_bases
    uint32_t sz_db=0;
    data_stream_.read(reinterpret_cast<char*>(&sz_db),sizeof(sz_db));
    
    for(decltype(sz_db) iter = 0; iter<sz_db;++iter){
        uint64_t t_pool_ptr;

        data_stream_.read(reinterpret_cast<char*>(&t_pool_ptr),sizeof(uint64_t));
        data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(uint32_t));

        std::string db_name(sz,0);

        data_stream_.read(db_name.data(), sz);

        BaseData* db = pool.add_data(db_name);

        //database hash
        uint64_t db_ptr;
        
        data_stream_.read(reinterpret_cast<char*>(&db_ptr),sizeof(uint64_t));
        std::cout<<"DataBase id:"<<db_ptr<<std::endl;
        //insert in serial data base

        //number of variables
        uint32_t sz_var;
        data_stream_.read(reinterpret_cast<char*>(&sz_var),sizeof(uint32_t));
        if(sz!=0){
            for(decltype(sz_var) iter_2=0;iter_2<sz_var;++iter_2){
                //variable name size and variable name
                data_stream_.read(reinterpret_cast<char*>(&sz),sizeof(sz));
                std::string var_name(sz,0);
                data_stream_.read(var_name.data(),sz);
                db->add_variable(std::move(var_name));
                //variable hash
                uint64_t var_ptr;
                data_stream_.read(reinterpret_cast<char*>(&var_ptr),sizeof(var_ptr));
                char cr;
                char lf;
                data_stream_.get(cr);
                data_stream_.get(lf);
                if(cr!='\r' || lf!='\n')
                    throw std::runtime_error(std::string("OMB file ")+path_.string()+" corrupted");

                std::cout<<"Variable id:"<<var_ptr<<std::endl;
                
                //insert_node(reinterpret_cast<const std::shared_ptr<Node> &>(var->node()));
            }
        }
        else {
            char cr;
            char lf;
            data_stream_.get(cr);
            data_stream_.get(lf);
            if(cr!='\r' || lf!='\n')
                throw std::runtime_error(std::string("OMB file ")+path_.string()+" corrupted");
        }
    }

    return pool;
}

DataPool SerialData::deserialize_body(){

}

void serialize_to(std::filesystem::path&& path,DataPool* pool){
    serialize_to(path,pool);
}

}