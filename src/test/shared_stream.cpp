#include "include/test/shared_stream.h"

const char* cpp_to_c_openmode(std::ios_base::openmode om){
    switch((int)om){
        case std::ios::in:
        return "r";
        case std::ios_base::binary | std::ios_base::in:
        return "rb";
        case std::ios_base::in | std::ios_base::out:
        return "r+";
        case std::ios_base::binary | std::ios_base::in |
                std::ios_base::out:
        return "r+b";
        case std::ios_base::out:
        return "w";
        case std::ios_base::out | std::ios_base::trunc:
        return "w";
        case std::ios_base::binary | std::ios_base::out:
        return "wb";
        case std::ios_base::binary | std::ios_base::out | 
                std::ios_base::trunc:
        return "wb";
        case std::ios_base::in | std::ios_base::out |
                std::ios_base::trunc:
        return "w+";
        case std::ios_base::binary | std::ios_base::in |
                std::ios_base::out | std::ios_base::trunc:
        return "w+b";
        #ifdef __cplusplus 
        #if __cplusplus > 202300L
        case std::ios_base::out | std::ios_base::noreplace:
        return "wx";
        case std::ios_base::out | std::ios_base::trunc | std::ios_base::noreplace:
        return "wx";
        case std::ios_base::binary | std::ios_base::out | std::ios_base::noreplace:
        return "wbx";
        case std::ios_base::binary | std::ios_base::out |
                std::ios_base::trunc | std::ios_base::noreplace:
        return "wbx";
        case std::ios_base::in | std::ios_base::out | std::ios_base::trunc |
                std::ios_base::noreplace:
        return "w+x";
        case std::ios_base::binary | std::ios_base::in | std::ios_base::out |
                std::ios_base::trunc | std::ios_base::noreplace:
        return "w+bx";
        #endif
        #endif
        case std::ios_base::out | std::ios_base::app:
        return "a";
        case std::ios_base::app:
        return "a";
        case std::ios_base::binary | std::ios_base::out | std::ios_base::app:
        return "ab";
        case std::ios_base::binary | std::ios_base::app:
        return "ab";
        case std::ios_base::in | std::ios_base::out | std::ios_base::app:
        return "a+";
        case std::ios_base::in | std::ios_base::app:
        return "a+";
        case std::ios_base::binary | std::ios_base::in | std::ios_base::out |
                std::ios_base::app:
        return "a+b";
        case std::ios_base::binary | std::ios_base::in | std::ios_base::app:
        return "a+b";
        default:{
            return "";
        }
    }
}
#include <stdexcept>
SharedStream::SharedStream(FILE*& stream):
use_count_(1){
    if(stream){
        c_.insert({stream,__C_F__{*stream,&stream}});
        newbuf();
        if(!f_)
            f_ = stream;
        std::setbuf(f_,buf_->data()); //f_ is nullptr (must be implemented as memory or filebuf)
        std::setbuf(stream,buf_->data());
    }
}
SharedStream::SharedStream(const SharedStream& other):
std::streambuf(other),
buf_(other.buf_){}
SharedStream& SharedStream::operator=(const SharedStream& other){
    if(&other!=this){
        std::streambuf::operator=(other);
        buf_=other.buf_;
        release();
        for(auto& [ptr,dt]:other.c_){
            if(*dt.f_)
                c_[ptr] = __C_F__{dt.old_f_data_,&dt.ptr,++dt.use_count}; //make reference to structure of streams
                std::setbuf(ptr,buf_->data());
            else 
        }
        for(auto& [ptr,dt]:cpp_)

    }
    return *this;
}
SharedStream::SharedStream(SharedStream&& other):{

}
SharedStream& SharedStream::operator=(SharedStream&& other){

}
SharedStream::~SharedStream(){
    for(auto& [c_f,c_dt]:c_)
        if(*c_dt.f_)
            *c_f = c_dt.old_f_data_;
}
// bool SharedStream::is_opened() const{
//     return fs.;
// }
#include <iostream>
#include <stdexcept>

void SharedStream::add_stream(FILE*& c_stream){
    if(c_stream){
        c_.insert({c_stream,__C_F__{*c_stream,&c_stream}});
        newbuf();
        if(!f_)
            f_ = c_stream;
        std::setbuf(f_,buf_->data()); //f_ is nullptr (must be implemented as memory or filebuf)
        std::setbuf(c_stream,buf_->data());
    }
}
void SharedStream::add_stream(std::iostream& stream){

}
void SharedStream::release(){
    //TODO: add condition if use_count is more than 1. Else restore previous buffers
    for(auto& [c_f,c_dt]:c_)
        if(*c_dt.f_)
            *c_f = c_dt.old_f_data_;
}
FILE* SharedStream::release_stream(FILE*& c_stream){
    if(c_stream && c_.contains(c_stream))
        return c_.extract(c_stream).key();
    else return nullptr;
}
std::iostream* SharedStream::release_stream(std::iostream& stream){
    if(cpp_.contains(&stream))
        return &cpp_.extract(&stream).mapped().stream_;
    else return nullptr;
}

// Запись одного символа
std::streambuf::int_type SharedStream::overflow(int_type ch){
    if (ch != traits_type::eof()) {
        // Просто записываем байт в FILE*
        if (std::fputc(ch, f_) == EOF) {
            return traits_type::eof();
        }
    }
    return ch;
}
// Синхронизация (например, при std::endl)
int SharedStream::sync(){
    if(f_)
        return std::fflush(f_) == 0 ? 0 : -1;
    return -1;
}
std::streambuf::pos_type SharedStream::seekoff(off_type off, std::ios_base::seekdir dir,
    std::ios_base::openmode which = std::ios_base::in | std::ios_base::out){
    if (!(buf_ || which & std::ios_base::in || which & std::ios_base::out))
        return off_type(-1);
    
    switch (off){
        default:
        case std::ios_base::beg: return __read_init__(off, SEEK_SET);
        case std::ios_base::cur: return __read_init__(pos_base + gptr() - eback() + off, SEEK_SET); //учитываем позицию от начала в нашем буфере
        case std::ios_base::end: return __read_init__(off, SEEK_END);
    }
}
std::streambuf::pos_type SharedStream::seekpos(pos_type pos,
        std::ios_base::openmode which = std::ios_base::in | std::ios_base::out){
    if (!(buf_ || which & std::ios_base::in || which & std::ios_base::out))
        return off_type(-1);

    return __read_init__(pos);
}
int SharedStream::pbackfail(int c){
    //символ не совпал
    if (pos_base <= 0 || gptr() > eback())
        return traits_type::eof();

    //загружаем в буфер данные, начиная с предыдущего символа
    if (__read_init__(pos_base - 1L) == -1)
        return traits_type::eof();

    if (*gptr() != c){
        gbump(1);
        return traits_type::eof();
    }
    return *gptr();
}
SharedStream* SharedStream::newbuf(std::streamsize sz){
    buf_=std::make_shared<std::vector<char_type>>(sz);
    return this;
}
SharedStream* SharedStream::setbuf(const SharedStream& sh_b){
    buf_ = sh_b.buf_;
    return this;
}
std::streampos SharedStream::__read_init__(std::streampos newpos, int dir){
    using namespace std;
    if (!f_ || fseek(f_, newpos, dir) == -1)
        return -1;
    
    long pos = ftell(f_);
    if (pos < 0)
        return -1;
    pos_base = pos;
    
    char_type *start = eback();
    if(!buf_)
        buf_ = std::make_shared<std::vector<char_type>>(BUFSIZ);
    size_t rd = fread(start, sizeof(char_type), buf_->size(), f_);
    setg(start, start, start + rd);
    return rd > 0 && pos_base >= 0 ? pos_base : streampos(-1);
}