#include "include/test/shared_fstream.h"
SharedFstream::SharedFstream():SharedStream(){}
SharedFstream::SharedFstream(const std::string& filename, std::ios_base::openmode om):SharedStream(){
    open(filename,om);
}
SharedFstream::SharedFstream(const char* filename, std::ios_base::openmode om):SharedStream(){
    open(filename,om);
}
SharedFstream::~SharedFstream(){
    if(f_)
        std::fclose(f_);
}
bool SharedFstream::is_open() const{
    return f_;
}
bool SharedFstream::open(const char* filename, std::ios_base::openmode om){
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
bool SharedFstream::open(const std::string& filename, std::ios_base::openmode om){
    return open(filename.c_str());
}