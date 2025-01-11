#pragma once
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "codes.h"
#include "error.h"

namespace kernel{
    class Logger{
        public:
        Logger(){
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std:: chrono::system_clock::to_time_t(now);
            std::stringstream tmp_stream;
            tmp_stream << std::put_time(std::localtime(&now_c), "%F %T");
            log_file_name_ = tmp_stream.str();
        }

        void log_error_and_exit(const std::string& what_error, int error_code) const{
            log_file_.open(log_file_name_,std::fstream::trunc);
            assert(log_file_.is_open());
            log_file_<<what_error<<std::endl;
            log_file_<<"Error code: "<<error_code<<std::endl;
            log_file_.close();
            exit(error_code);
        }

        std::string log_file_name_;
        mutable std::fstream log_file_;
    };

    class System{
        static Logger logger_;
        public:
        static int get_accessible_cores(){
            return std::thread::hardware_concurrency();
        }

        static const Logger& get_logger(){
            return logger_;
        }
        //add static method for accessible RAM

        //add static method for accessible disk memory
    };
}