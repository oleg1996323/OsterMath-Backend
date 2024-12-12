#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "node.h"

class BaseData;

using Parents_t = std::unordered_map<const Node *, std::vector<int>>&;
using Childs_t = std::vector<std::shared_ptr<Node>>;

class RelationManager{
    std::unordered_map<const Node*,std::unordered_map<const Node*,std::vector<int>>> referent_parents_; //referencing, but not owning parents
    std::unordered_map<const Node*,std::vector<std::shared_ptr<Node>>> childs_;
    std::unordered_map<const Node*,INFO_NODE> owners_; //parent, which own this node
    static std::vector<std::shared_ptr<Node>>& get_empty_childs(){
        static std::vector<std::shared_ptr<Node>> empty_childs_;
        return empty_childs_;
    }

    BaseData* bd_ = nullptr;
    public:
    RelationManager() = default;
    RelationManager(BaseData* bd):bd_(bd){}

    RelationManager(const RelationManager& other):
    referent_parents_(other.referent_parents_),
    childs_(other.childs_),
    owners_(other.owners_){}

    RelationManager(RelationManager&& other):
    referent_parents_(std::move(other.referent_parents_)),
    childs_(std::move(other.childs_)),
    owners_(std::move(other.owners_)){}

    INFO_NODE owner(const Node* node) const noexcept{
        if(owners_.contains(node))
            return owners_.at(node);
        else return INFO_NODE();
    }

    Childs_t& childs(Node* node) noexcept{
        if(childs_.contains(node))
            return childs_.at(node);
        else return get_empty_childs();
    }
    void reserve_childs(const Node* node,size_t size);
    const Childs_t& childs(const Node* node) const noexcept{
        if(childs_.contains(node))
            return childs_.at(node);
        else return get_empty_childs();
    }
    void erase_parent(const Node* node, const Node* parent);
    void erase_child(const Node* node, size_t id);
    void delete_node(const Node* node);
    const std::shared_ptr<Node>& child(const Node* node,size_t id) const;
    std::shared_ptr<Node>& child(Node* node,size_t id);
    INFO_NODE child(Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept;
    INFO_NODE child(const Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) const noexcept;
    void insert_back(const Node* node,std::shared_ptr<Node> new_child) noexcept;
    //insert before value at id
    std::shared_ptr<Node> insert(const Node* node,size_t id,std::shared_ptr<Node> new_child) noexcept;
    std::shared_ptr<Node> replace(const Node* node, size_t id,std::shared_ptr<Node> new_child) noexcept;
    void add_parent(const Node* node_to_add, const Node* parent, int index) noexcept;
    bool has_parents(const Node* node) const noexcept;
    void refresh_parent_links(Node* node) noexcept;
    std::set<std::shared_ptr<VariableNode>> refer_to_vars(const Node* node) const noexcept;
    std::set<std::shared_ptr<Node>> refer_to_node_of_type(const Node* node, NODE_TYPE type) const noexcept;
    bool has_childs(const Node* node) const noexcept;
    bool has_child(const Node* node, size_t id) const noexcept;
    void release_childs(Node* node) noexcept;
    const Parents_t& parents(const Node* node) const noexcept;
    void swap_parents(const Node* lhs, const Node* rhs);
    void swap_childs(const Node* lhs, const Node* rhs);
    void copy_parents(const Node* from, const Node* to);
    void copy_childs(Node* node, const Childs_t& childs);
};