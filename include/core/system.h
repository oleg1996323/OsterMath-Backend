#pragma once
#include <thread>

namespace kernel{
    class System{
        public:
        static int get_accessible_cores(){
            return std::thread::hardware_concurrency();
        }
        //add static method for accessible RAM

        //add static method for accessible disk memory
    };
}