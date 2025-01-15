#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <filesystem>
#include <cassert>
#include <vector>
#include "shared_stream.h"

class TestLogger{
    static TestLogger test_logger;
    static std::filesystem::directory_entry log_dir_;
    SharedStream sh_buf_;
    std::ostream stream_;
    public:
    TestLogger(std::ostream& stream);
    TestLogger(const TestLogger& logger) = delete;
    TestLogger(TestLogger&& logger);
    TestLogger& operator=(const TestLogger& logger) = delete;
    TestLogger& operator=(TestLogger&& logger);
    TestLogger(const std::filesystem::path& log_dir, const char* test_name);
    static TestLogger& instance();
    void set_log_stream(const std::string& test_name);
    void set_log_stream(const char* test_name);
    void set_log_stream(std::ostream& stream);
    void set_log_directory(const std::filesystem::path& directory);
    template<typename T>
    TestLogger& operator<<(T item){
        stream_<<item;
        return *this;
    }
};