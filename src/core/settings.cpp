#include "settings.h"
#include "system.h"
#include <thread>

namespace kernel::settings{

int Model::numCPU = System::get_accessible_cores();
bool Model::function_filling_arrays = false; //for sum/sumproduct/product functionnodes
bool Model::var_nodes_through_search = true; //for indexed child search at Node method
bool Model::automatic_execution = true; //auto execution after every change

bool Model::show_through_var_nodes(){
    return Model::var_nodes_through_search;
}
void Model::set_show_through_var_nodes(bool v){
    Model::var_nodes_through_search = v;
}
bool Model::auto_filling_arrays(){
    return Model::function_filling_arrays;
}
bool Model::auto_execution(){
    return automatic_execution;
}
void Model::set_auto_execution(bool v){
    automatic_execution = v;
}
}