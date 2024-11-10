#pragma once
#include <iostream>

class FunctionNode;

namespace node_function::functions::print{

void print_text(const FunctionNode* node,std::ostream& stream);
}