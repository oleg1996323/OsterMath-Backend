#pragma once
#include "def.h"
#include <unordered_set>

class Node;

namespace node_range_operation::functions{
    namespace math{
        Result Sum(std::shared_ptr<Node> expr,const std::set<VariableNodeIndexInRangeOperation>& order_vars = {}) noexcept{
            return Result();
        }

        Result Product(std::shared_ptr<Node> expr,const std::set<VariableNodeIndexInRangeOperation>& order_vars = {}) noexcept{
            return Result();
        }
    }
}