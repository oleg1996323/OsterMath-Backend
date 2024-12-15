#pragma once
#include <memory>
#include <vector>

class AbstractNode;

struct INFO_NODE{
    AbstractNode* parent = nullptr;
    int id = -1;

    std::shared_ptr<AbstractNode> node() const;
    bool has_node() const;
    bool is_valid() const;

    bool operator<(const INFO_NODE& v) const noexcept;
    bool operator==(const INFO_NODE& other) const noexcept;
    bool operator<(AbstractNode* v) const noexcept;
    bool operator==(AbstractNode* other) const noexcept;
};

struct Parent_ref{
    AbstractNode* parent = nullptr;
    std::vector<int> id;

    std::shared_ptr<AbstractNode> node() const;
    bool has_node() const;
    bool is_valid() const;

    bool operator<(const INFO_NODE& v) const noexcept;
    bool operator==(const INFO_NODE& other) const noexcept;
    bool operator<(AbstractNode* v) const noexcept;
    bool operator==(AbstractNode* other) const noexcept;
};

struct INFO_NODE_Comparator{
    using is_transparent = std::true_type;
    bool operator()(const INFO_NODE& lhs,const INFO_NODE& rhs) const noexcept;
    bool operator()(const AbstractNode* lhs, const INFO_NODE& rhs) const noexcept;
    bool operator()(const INFO_NODE& lhs,const AbstractNode* rhs) const noexcept;
};