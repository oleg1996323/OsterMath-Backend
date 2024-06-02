#pragma once
#include <string>
#include <fstream>

class DataPool;

namespace serialization{

template <typename T>
void serialize(std::ostream& stream, T val){
    stream.write(reinterpret_cast<const char*>(&val), sizeof(val));
}

void serialize_to(const std::string& path,DataPool* pool);

}