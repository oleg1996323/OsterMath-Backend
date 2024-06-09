#include "serialize.h"
#include "data.h"
#include <iostream>

namespace serialization{

void serialize_to(const std::filesystem::path& path,DataPool* pool){
    SerialData serial_data;
    serial_data.open_to_write(path);
    serial_data.data_stream_.write("#FORMAT_OMB\n",12);
    pool->serialize(file);
    file.close();
}

void serialize_to(std::filesystem::path&& path,DataPool* pool){
    serialize_to(path,pool);
}

}