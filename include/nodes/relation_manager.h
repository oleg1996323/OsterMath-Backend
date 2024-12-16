#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "node.h"
#include "ref_node.h"

class BaseData;

using References_t = std::unordered_set<const ReferenceNode*>;
using Childs_t = std::vector<std::shared_ptr<AbstractNode>>;

class RelationManager{
    std::unordered_map<const AbstractNode*,References_t> references_; //referencing, but not owning parents
    std::unordered_map<const AbstractNode*,Childs_t> childs_;
    std::unordered_map<const AbstractNode*,INFO_NODE> owner_; //parent, which own this node
    static const Childs_t empty_childs_;
    static const References_t empty_references_;
    int constructed = 0;
    int refered = 0;
    int destructed = 0;
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

    void log_state() const{
        std::cout<<"Constructed: "<<constructed<<std::endl;
        std::cout<<"Refered: "<<refered<<std::endl;
        std::cout<<"Destructed: "<<destructed<<std::endl;
        std::cout<<"references_ size: "<<references_.size()<<std::endl;
        std::cout<<"childs_ size: "<<childs_.size()<<std::endl;
        std::cout<<"owner_ size: "<<owner_.size()<<std::endl;
    }

    static INFO_NODE owner(const AbstractNode* node) noexcept{
        if(node->relation_manager()->owner_.contains(node))
            return node->relation_manager()->owner_.at(node);
        else return INFO_NODE();
    }

    static const Childs_t& childs(AbstractNode* node) noexcept{
        if(node->relation_manager()->childs_.contains(node))
            return node->relation_manager()->childs_.at(node);
        else return empty_childs_;
    }
    static const Childs_t& childs(const AbstractNode* node) noexcept{
        if(node->relation_manager()->childs_.contains(node))
            return node->relation_manager()->childs_.at(node);
        else return empty_childs_;
    }
    static void reserve_childs(const AbstractNode* node,size_t size);
    static void erase_child(const AbstractNode* node, size_t id) noexcept;
    static void delete_node(const AbstractNode* node);
    static const std::shared_ptr<AbstractNode>& child(const AbstractNode* node,size_t id);
    static std::shared_ptr<AbstractNode>& child(AbstractNode* node,size_t id);
    static INFO_NODE child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept;
    static void insert_back(const AbstractNode* node,std::shared_ptr<AbstractNode> new_child);
    //insert before value at id
    static std::shared_ptr<AbstractNode> insert(const AbstractNode* node,size_t id,std::shared_ptr<AbstractNode> new_child);
    static std::shared_ptr<AbstractNode> replace(const AbstractNode* node, size_t id,std::shared_ptr<AbstractNode> new_child);
    
    static bool has_references(const AbstractNode* node) noexcept;
    static bool has_owner(const AbstractNode* node) noexcept;
    static void refresh_parent_links(const AbstractNode* node) noexcept;
    static std::set<std::shared_ptr<VariableNode>> refer_to_vars(const AbstractNode* node) noexcept;
    static std::set<std::shared_ptr<AbstractNode>> refer_to_node_of_type(const AbstractNode* node, NODE_TYPE type) noexcept;
    static bool has_childs(const AbstractNode* node) noexcept;
    static bool has_child(const AbstractNode* node, size_t id) noexcept;
    static void release_childs(const AbstractNode* node) noexcept;
    static const References_t& references(const AbstractNode* node) noexcept;
    static void swap_parents(const AbstractNode* lhs, const AbstractNode* rhs);
    static void swap_childs(const AbstractNode* lhs, const AbstractNode* rhs);
    static void copy_parents(const AbstractNode* from, const AbstractNode* to);
    static void copy_childs(AbstractNode* node, const Childs_t& childs);
    private:
    static void __erase_reference__(AbstractNode* from_node, const AbstractNode* parent);
    static void __add_reference__(AbstractNode* node_to_add, const AbstractNode* ref_node, int index) noexcept;
};