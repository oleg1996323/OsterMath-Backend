#pragma once
#include <memory>
#include <vector>
#include <set>
#include "nodes/def.h"

class VariableNode;

struct VariableNodeIndexInRangeOperation{
    mutable std::vector<size_t> order_id;
    std::shared_ptr<SizeDepthMeasure> sz_depth_measure;
    std::shared_ptr<VariableNode> var_node;

    inline bool operator<(const VariableNodeIndexInRangeOperation& v) noexcept{
        return var_node.get()<v.var_node.get();
    }

    inline bool operator==(const VariableNodeIndexInRangeOperation& other) noexcept{
        return var_node.get() == other.var_node.get();
    }

    struct Comparator{
        using is_transparent = std::true_type;
        bool operator()(const VariableNode* lhs, const VariableNodeIndexInRangeOperation& rhs) const
        {
            return lhs < rhs.var_node.get();
        }
        bool operator()(const VariableNodeIndexInRangeOperation& lhs, const VariableNode* rhs) const
        {
            return lhs.var_node.get() < rhs;
        }
        bool operator()(const VariableNodeIndexInRangeOperation& lhs, const VariableNodeIndexInRangeOperation& rhs) const
        {
            return lhs.var_node.get()<rhs.var_node.get();
        }
    };
};

inline bool operator<(const VariableNodeIndexInRangeOperation& lhs, const VariableNodeIndexInRangeOperation& rhs) noexcept{
    return lhs.var_node.get()<rhs.var_node.get();
}

inline bool operator==(const VariableNodeIndexInRangeOperation& lhs, const VariableNodeIndexInRangeOperation& rhs) noexcept{
    return lhs.var_node.get()==rhs.var_node.get();
}

struct RangeNodeExecuteStruct{
    std::set<VariableNodeIndexInRangeOperation,VariableNodeIndexInRangeOperation::Comparator> variables;
    size_t range_operators_called = 0;
};