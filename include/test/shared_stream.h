#pragma once
#include <streambuf>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>

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
class SharedStream : public std::streambuf {
    std::streampos pos_base;
public:
    explicit SharedStream(FILE* f) : f_(f) {
        // Можно завести свой буфер в памяти, если надо
        // setp(buf_, buf_ + sizeof(buf_));
        setp(f->_IO_buf_base,f->_IO_buf_end);
    }

    explicit SharedStream(FILE* stream){
        //save old buffer
    }

    explicit SharedStream(const std::string& filename, std::ios_base::openmode om = std::ios_base::out | std::ios_base::in){
        open(filename,om);
    }

    explicit SharedStream(const char* filename, std::ios_base::openmode om = std::ios_base::out | std::ios_base::in){
        open(filename,om);
    }

    bool is_opened() const{
        return f_;
    }

    bool open(const char* filename, std::ios_base::openmode om = std::ios_base::in){
        f_ = std::fopen(filename,cpp_to_c_openmode(om));
        if(f_){
            try{
                buf_ = std::make_shared<std::vector<char_type>>(BUFSIZ);
                return true;
            }
            catch(const std::bad_alloc& err){
                std::cerr << err.what();
                exit(1);
            }
        }
        return false;
    }
    bool open(const std::string& filename, std::ios_base::openmode om = std::ios_base::in){
        return open(filename.c_str(),om);
    }
protected:
    // Запись одного символа
    virtual int_type overflow(int_type ch) override {
        if (ch != traits_type::eof()) {
            // Просто записываем байт в FILE*
            if (std::fputc(ch, f_) == EOF) {
                return traits_type::eof();
            }
        }
        return ch;
    }

    // Синхронизация (например, при std::endl)
    virtual int sync() override {
        return std::fflush(f_) == 0 ? 0 : -1;
    }

    virtual pos_type seekoff(off_type off, std::ios_base::seekdir dir,
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

    virtual int pbackfail(int c) override {
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

    SharedStream* newbuf(std::streamsize sz = 0){
        buf_=std::make_shared<std::vector<char_type>>(sz);
        return this;
    }

    SharedStream* setbuf(const SharedStream& sh_b){
        buf_ = sh_b.buf_;
        return this;
    }

private:
    std::streampos __read_init__(std::streampos newpos, int dir = SEEK_SET){
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

    std::shared_ptr<std::vector<char_type>> buf_; // Можно организовать свой буфер
    FILE* f_=nullptr;
    const char* old_buf_ = nullptr;
};