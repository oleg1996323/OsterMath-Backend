#include "settings.h"
#include "system.h"
#include <thread>

namespace kernel::settings{

int Model::numCPU = System::get_accessible_cores();
bool Model::function_filling_arrays = false; //for sum/sumproduct/product functionnodes
bool Model::var_nodes_through_search = true; //for indexed child search at Node method

bool Model::show_through_var_nodes(){
    return Model::var_nodes_through_search;
}
bool Model::auto_filling_arrays(){
    return Model::function_filling_arrays;
}
}