#pragma once
#include <string>
#include <stdexcept>
#include "codes.h"

namespace kernel{
    class FatalError:public std::runtime_error{
        public:
        using std::runtime_error::runtime_error;
        FatalError(const std::string& prompt, codes::CODES err_code):runtime_error(prompt){
            kernel::System::get_logger().log_error_and_exit(prompt,err_code);
        }
    };
}
