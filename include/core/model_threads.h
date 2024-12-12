#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <memory>
#include "settings.h"

namespace kernel::model::threads{
    class ModelThread{
        std::thread thread_;
        float progress_ = 0.;
        public:
        ModelThread() = default;
        ModelThread(const ModelThread&) = delete;
        ModelThread(ModelThread&& other):
        thread_(std::move(other.thread_)),
        progress_(other.progress_){}
        ~ModelThread(){
            thread_.join();
        }
        template<typename R_T, typename... ARGS>
        R_T execute(std::function<R_T(ARGS...)> function,ARGS... args);
        private:
        
    };

    template<typename R_T, typename... ARGS>
    R_T ModelThread::execute(std::function<R_T(ARGS...)> function, ARGS... args){
        thread_ = std::move(std::thread(function, args...));
    }

    class ThreadExecuteControl{
        public:

        private:
        static std::vector<ModelThread> threads_;
    };
}