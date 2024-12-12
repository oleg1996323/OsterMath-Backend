#include "model_threads.h"
#include "settings.h"

using namespace kernel::model::threads;

std::vector<ModelThread> ThreadExecuteControl::threads_ = []()->std::vector<ModelThread>
        {
            std::vector<ModelThread> result;
            for(int i=0; i<kernel::settings::Model::active_cores();++i)
                result.push_back(std::move(ModelThread()));
            return result;
        }();