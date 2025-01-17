#pragma once
#include <streambuf>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

const char* cpp_to_c_openmode(std::ios_base::openmode om);

/*template<__gnu_cxx::_Lock_policy _Lp = __gnu_cxx::__default_lock_policy>
class _stream_counted_base: public _Mutex_base<_Lp>{
public:
    _stream_counted_base() noexcept: _M_use_count(1), _M_weak_count(1){
    }

    virtual ~_stream_counted_base() noexcept{
    }

    // Called when _M_use_count drops to zero, to release the resources
    // managed by *this.
    virtual void _M_dispose() noexcept = 0;

    // Called when _M_weak_count drops to zero.
    virtual void _M_destroy() noexcept{
        delete this;
    }

    virtual void* _M_get_deleter(const std::type_info&) noexcept = 0;

    void _M_add_ref_copy(){
        __gnu_cxx::__atomic_add_dispatch(&_M_use_count, 1);
    }

    void _M_add_ref_lock(){
        if (!_M_add_ref_lock_nothrow())
            __throw_bad_weak_ptr();
    }

    bool _M_add_ref_lock_nothrow() noexcept;

    void
    _M_release() noexcept{
        // Be race-detector-friendly.  For more info see bits/c++config.
        _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(&_M_use_count);
        if (__gnu_cxx::__exchange_and_add_dispatch(&_M_use_count, -1) == 1){
            _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(&_M_use_count);
            _M_dispose();
            // There must be a memory barrier between dispose() and destroy()
            // to ensure that the effects of dispose() are observed in the
            // thread that runs destroy().
            if (_Mutex_base<_Lp>::_S_need_barriers){
            __atomic_thread_fence (__ATOMIC_ACQ_REL);
            }

            // Be race-detector-friendly.  For more info see bits/c++config.
            _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(&_M_weak_count);
            if (__gnu_cxx::__exchange_and_add_dispatch(&_M_weak_count,-1) == 1){
                    _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(&_M_weak_count);
                _M_destroy();
            }
        }
    }

    void _M_weak_add_ref() noexcept{
        __gnu_cxx::__atomic_add_dispatch(&_M_weak_count, 1);
    }

    void _M_weak_release() noexcept{
        // Be race-detector-friendly. For more info see bits/c++config.
        _GLIBCXX_SYNCHRONIZATION_HAPPENS_BEFORE(&_M_weak_count);
        if (__gnu_cxx::__exchange_and_add_dispatch(&_M_weak_count, -1) == 1){
            _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(&_M_weak_count);
        if (_Mutex_base<_Lp>::_S_need_barriers)
            {
            // See _M_release(),
            // destroy() must observe results of dispose()
        __atomic_thread_fence (__ATOMIC_ACQ_REL);
            }
        _M_destroy();
        }
    }

    long _M_get_use_count() const noexcept
    {
        // No memory barrier is used here so there is no synchronization
        // with other threads.
        return __atomic_load_n(&_M_use_count, __ATOMIC_RELAXED);
    }

private:
    _stream_counted_base(_Sp_counted_base const&) = delete;
    _stream_counted_base& operator=(_Sp_counted_base const&) = delete;

    int  _M_use_count;     // #shared
};*/

template<typename T>
class __STREAM_DATA__
{
    friend class SharedStream;
    std::vector<T> buf_;
    struct __C_F__{
        FILE& old_f_data_;
        int use_count_ = 0;
    };
    struct __CPP_F__{
        std::iostream& stream_;
        int use_count_ = 0;
    };
    __STREAM_DATA__() = default;
    __STREAM_DATA__(size_t sz):buf_([sz](){std::vector<T> v;v.resize(sz);return v;}()){}
    __STREAM_DATA__(const __STREAM_DATA__<T>& other){
        for(auto& [ptr,dt]:other.c_){
            if(*dt.f_){
                //not copy (use reference on existing __C_F__ if correct)
                c_[ptr] = __C_F__{dt.old_f_data_,dt.use_count_}; //make reference to structure of streams
                std::setbuf(ptr,buf_->data());
            }
            else{}
        }
        for(auto& [ptr,dt]:cpp_){

        }
    }
    
    void __add_stream__(FILE*& c_stream);
    void __add_stream__(std::iostream& stream);
    void __merge_streams_from__(const __STREAM_DATA__& other);
    void __release__();
    FILE* __release_stream__(FILE*& c_stream);
    std::iostream* __release_stream__(std::iostream& stream);
    std::unordered_map<FILE*,__C_F__> c_;
    std::unordered_map<std::iostream*,__CPP_F__> cpp_;
    
};  

class SharedStream : public std::streambuf {
    std::shared_ptr<__STREAM_DATA__<char_type>> ref_;
protected:
    FILE* f_;
private:
    std::streampos pos_base;
public:
    SharedStream(const SharedStream& other);
    SharedStream& operator=(const SharedStream& other);
    SharedStream() = default;
    SharedStream(SharedStream&& other);
    SharedStream& operator=(SharedStream&& other);
    ~SharedStream();
    bool is_opened() const;
    void add_stream(FILE*& c_stream);
    void add_stream(std::iostream& stream);

    void release();
    FILE* release_stream(FILE*& c_stream);
    std::iostream* release_stream(std::iostream& stream);
protected:
    // Запись одного символа
    virtual int_type overflow(int_type ch) override;

    // Синхронизация (например, при std::endl)
    virtual int sync() override;
    virtual pos_type seekoff(off_type off, std::ios_base::seekdir dir,
        std::ios_base::openmode which) override;
    virtual pos_type seekpos(pos_type pos,
        std::ios_base::openmode which) override;
    virtual int pbackfail(int c) override;
private:
    std::streampos __read_init__(std::streampos newpos, int dir = SEEK_SET);
};