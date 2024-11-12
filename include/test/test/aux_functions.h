#pragma once

class ArrayNode;

namespace functions::auxiliary::test{
        bool check_type_container_nodes();
        bool check_arguments();
        bool init_sz_depth_measure();
        bool check_sizes_arrays();
        bool all_numeric(decltype(std::declval<Node>().childs()) arrays);
        bool all_string(decltype(std::declval<Node>().childs()) arrays);

        std::shared_ptr<ArrayNode> to_array_node(const std::shared_ptr<Node>& node) noexcept;
        std::shared_ptr<ValueNode> to_value_node(const std::shared_ptr<Node>& node) noexcept;
}