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
    c_.insert({stream,*stream});
    newbuf();
    std::setbuf(f_,buf_->data()); //f_ is nullptr (must be implemented as memory or filebuf)
    std::setbuf(stream,buf_->data());
}
SharedStream::SharedStream(const SharedStream& other):
std::streambuf(other),
buf_(other.buf_){
    if(this!=&other)
        use_count_ = other.use_count_;
}

SharedStream& SharedStream::operator=(const SharedStream& other){
    if(&other!=this){
        std::streambuf::operator=(other);
        buf_=other.buf_;
    }
    return *this;
}

SharedStream::~SharedStream(){
    for(auto& [c_f,c_dt]:c_)
        *c_f = c_dt;
    
}
// bool SharedStream::is_opened() const{
//     return fs.;
// }
#include <iostream>
#include <stdexcept>

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
        std::fflush(f_) == 0 ? 0 : -1;

}

std::streambuf::pos_type SharedStream::seekoff(off_type off, std::ios_base::seekdir dir,
    std::ios_base::openmode which = std::ios_base::in | std::ios_base::out){
    if (!(buf_ || which & std::ios_base::in))
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