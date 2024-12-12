#pragma once
#include <memory>
#include <vector>

class Node;

struct INFO_NODE{
    Node* parent = nullptr;
    int id = -1;

    std::shared_ptr<Node> node() const;
    bool has_node() const;
    bool is_valid() const;

    bool operator<(const INFO_NODE& v) const noexcept;
    bool operator==(const INFO_NODE& other) const noexcept;
    bool operator<(Node* v) const noexcept;
    bool operator==(Node* other) const noexcept;
};

struct Parent_ref{
    Node* parent = nullptr;
    std::vector<int> id;

    std::shared_ptr<Node> node() const;
    bool has_node() const;
    bool is_valid() const;

    bool operator<(const INFO_NODE& v) const noexcept;
    bool operator==(const INFO_NODE& other) const noexcept;
    bool operator<(Node* v) const noexcept;
    bool operator==(Node* other) const noexcept;
};

struct INFO_NODE_Comparator{
    using is_transparent = std::true_type;
    bool operator()(const INFO_NODE& lhs,const INFO_NODE& rhs) const noexcept;
    bool operator()(const Node* lhs, const INFO_NODE& rhs) const noexcept;
    bool operator()(const INFO_NODE& lhs,const Node* rhs) const noexcept;
};