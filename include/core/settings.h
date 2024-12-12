#pragma once
#include <stdint.h>
#include "threads.h"
namespace kernel::settings{

class Model{
static int numCPU; //user choosen active cores
static bool function_filling_arrays; //for sum/sumproduct/product functionnodes
static bool var_nodes_through_search; //for indexed child search at Node method

public:
    static int active_cores();
    static bool show_through_var_nodes();
    static bool auto_filling_arrays();
    //add method for disk memory caching for enourmous data
private:

};

}