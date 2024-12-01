#pragma once
#include <memory>
#include <vector>
#include <set>
#include <optional>
#include <memory>
#include "nodes/def.h"

class VariableNode;

namespace node_range_operation{

struct ThroughVarStruct{
    mutable SizeDepthMeasure sz_depth_measure;
    mutable std::vector<size_t> order;

    // struct Hasher{
    //     size_t operator()(const std::shared_ptr<VariableNode>& rhs) const
    //     {
    //         return std::hash<VariableNode*>()(rhs.get());
    //     }
    // };

    // struct Comparator{
    //     using is_transparent = std::true_type;
    //     bool operator()(const VariableNode* lhs, const std::shared_ptr<VariableNode>& rhs) const
    //     {
    //         return lhs == rhs.get();
    //     }
    //     bool operator()(const std::shared_ptr<VariableNode>& lhs, const VariableNode* rhs) const
    //     {
    //         return lhs.get() == rhs;
    //     }
    //     bool operator()(const std::shared_ptr<VariableNode>& lhs, const std::shared_ptr<VariableNode>& rhs) const
    //     {
    //         return lhs.get() == rhs.get();
    //     }
    //     bool operator()(const VariableNode* lhs, const VariableNode* rhs) const
    //     {
    //         return lhs == rhs;
    //     }
    // };
};
using execute_for_array_variables_t = std::unordered_map<const VariableNode*,ThroughVarStruct>;
// struct VariableNodeIndex{
//     mutable std::optional<size_t> order_id;
//     std::shared_ptr<VariableNode> var_node;

//     // inline bool operator<(const VariableNodeIndex& v) noexcept{
//     //     return var_node.get()<v.var_node.get();
//     // }

//     // inline bool operator==(const VariableNodeIndex& other) noexcept{
//     //     return var_node.get() == other.var_node.get();
//     // }

//     // struct Comparator{
//     //     using is_transparent = std::true_type;
//     //     bool operator()(const VariableNode* lhs, const VariableNodeIndex& rhs) const
//     //     {
//     //         return lhs < rhs.var_node.get();
//     //     }
//     //     bool operator()(const VariableNodeIndex& lhs, const VariableNode* rhs) const
//     //     {
//     //         return lhs.var_node.get() < rhs;
//     //     }
//     //     bool operator()(const std::shared_ptr<VariableNode>& lhs, const VariableNodeIndex& rhs) const
//     //     {
//     //         return lhs.get() < rhs.var_node.get();
//     //     }
//     //     bool operator()(const VariableNodeIndex& lhs, const std::shared_ptr<VariableNode>& rhs) const
//     //     {
//     //         return lhs.var_node.get() < rhs.get();
//     //     }
//     //     bool operator()(const VariableNodeIndex& lhs, const VariableNodeIndex& rhs) const
//     //     {
//     //         return lhs.var_node.get()<rhs.var_node.get();
//     //     }
//     // };
// };

// inline bool operator<(const VariableNodeIndex& lhs, const VariableNodeIndex& rhs) noexcept{
//     return lhs.var_node.get()<rhs.var_node.get();
// }

// inline bool operator==(const VariableNodeIndex& lhs, const VariableNodeIndex& rhs) noexcept{
//     return lhs.var_node.get()==rhs.var_node.get();
// }

// struct ExecuteStruct{
//     std::set<ThroughVarStruct,ThroughVarStruct::Comparator> variables;
//     size_t range_operators_called = 0;
// };

}