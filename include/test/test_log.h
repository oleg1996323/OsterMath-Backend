#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <filesystem>
#include <cassert>

class TestLogger{
    static TestLogger test_logger;
    static std::filesystem::directory_entry log_dir_;
    static std::streambuf* out_buf;
    static std::streambuf* err_buf;
    static std::streambuf* log_buf;
    std::unique_ptr<std::ostream> stream_;
    public:
    TestLogger(std::ostream& stream);
    TestLogger(const TestLogger& logger) = delete;
    TestLogger(TestLogger&& logger) = default;
    TestLogger& operator=(const TestLogger& logger) = delete;
    TestLogger& operator=(TestLogger&& logger) = default;
    ~TestLogger(){
        stream_.reset();
        std::cout.rdbuf(out_buf);
        std::cerr.rdbuf(err_buf);
        std::clog.rdbuf(log_buf);
    }
    TestLogger(const std::filesystem::path& log_dir, const char* test_name);
    static TestLogger& instance();
    void set_log_stream(const std::string& test_name);
    void set_log_stream(const char* test_name);
    void set_log_stream(std::ostream& stream);
    void set_log_directory(const std::filesystem::path& directory);
    template<typename T>
    std::ostream& operator<<(T item){
        assert(stream_);
        *stream_.get()<<item;
        return *stream_.get();
    }
};