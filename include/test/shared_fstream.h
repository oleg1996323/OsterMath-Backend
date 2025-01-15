#pragma once
#include "shared_stream.h"
#include <cstdio>
#include <iostream>

class SharedFstream: public SharedStream{
public:
    SharedFstream(const SharedFstream& other):
    SharedStream(other){}

    SharedFstream(const std::string& filename, std::ios_base::openmode om):SharedStream(){
        open(filename,om);
        ;
    }
    SharedFstream(const char* filename, std::ios_base::openmode om):SharedStream(){
        open(filename,om);
    }

    bool is_open() const;
    bool open(const char* filename, std::ios_base::openmode om = std::ios_base::in){
        if(f_)
            std::fclose(f_);

        f_ = std::fopen(filename,cpp_to_c_openmode(om));
        if(f_){
            try{
                if(!has_buf())
                    newbuf();
                return true;
            }
            catch(const std::bad_alloc& err){
                std::cerr << err.what();
            }
        }
        return false;
    }
    bool open(const std::string& filename, std::ios_base::openmode om = std::ios_base::in){
        return open(filename.c_str());
    }
};