#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "node.h"
#include "ref_node.h"

class BaseData;

using References_t = std::unordered_map<const ReferenceNode*, std::vector<int>>;
using Childs_t = std::vector<std::shared_ptr<Node>>;

class RelationManager{
    std::unordered_map<const Node*,References_t> references_; //referencing, but not owning parents
    std::unordered_map<const Node*,Childs_t> childs_;
    std::unordered_map<const Node*,INFO_NODE> owner_; //parent, which own this node
    static const std::vector<std::shared_ptr<Node>> empty_childs_;

    BaseData* bd_ = nullptr;
    public:
    RelationManager() = default;
    RelationManager(BaseData* bd):bd_(bd){}

    RelationManager(const RelationManager& other):
    references_(other.references_),
    childs_(other.childs_),
    owner_(other.owner_){}

    RelationManager(RelationManager&& other):
    references_(std::move(other.references_)),
    childs_(std::move(other.childs_)),
    owner_(std::move(other.owner_)){}

    INFO_NODE owner(const Node* node) const noexcept{
        if(owner_.contains(node))
            return owner_.at(node);
        else return INFO_NODE();
    }

    const Childs_t& childs(Node* node) noexcept{
        if(childs_.contains(node))
            return childs_.at(node);
        else return empty_childs_;
    }
    const Childs_t& childs(const Node* node) const noexcept{
        if(childs_.contains(node))
            return childs_.at(node);
        else return empty_childs_;
    }
    void reserve_childs(const Node* node,size_t size);
    void erase_parent(const Node* node, const Node* parent);
    void erase_child(const Node* node, size_t id);
    void delete_node(const Node* node);
    const std::shared_ptr<Node>& child(const Node* node,size_t id) const;
    std::shared_ptr<Node>& child(Node* node,size_t id);
    INFO_NODE child(Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept;
    INFO_NODE child(const Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) const noexcept;
    void insert_back(const Node* node,std::shared_ptr<Node> new_child);
    //insert before value at id
    std::shared_ptr<Node> insert(const Node* node,size_t id,std::shared_ptr<Node> new_child) noexcept;
    std::shared_ptr<Node> replace(const Node* node, size_t id,std::shared_ptr<Node> new_child) noexcept;
    
    bool has_references(const Node* node) const noexcept;
    bool has_owner(const Node* node) const noexcept;
    void refresh_parent_links(Node* node) noexcept;
    std::set<std::shared_ptr<VariableNode>> refer_to_vars(const Node* node) const noexcept;
    std::set<std::shared_ptr<Node>> refer_to_node_of_type(const Node* node, NODE_TYPE type) const noexcept;
    bool has_childs(const Node* node) const noexcept;
    bool has_child(const Node* node, size_t id) const noexcept;
    void release_childs(Node* node) noexcept;
    const References_t& parents(const Node* node) const noexcept;
    void swap_parents(const Node* lhs, const Node* rhs);
    void swap_childs(const Node* lhs, const Node* rhs);
    void copy_parents(const Node* from, const Node* to);
    void copy_childs(Node* node, const Childs_t& childs);
    private:
    bool __add_parent__(const Node* node_to_add, const Node* parent, int index) noexcept;
    bool __add_reference__(const Node* node_to_add, const ReferenceNode* ref_node, int index) noexcept;
};