#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include "abstract_node.h"
#include "node/hash.h"
#include "ref_node.h"

class BaseData;

using References_t = std::unordered_set<ReferenceNode*>;
using Childs_t = std::vector<AbstractNode*>;

class NodeManager{
    friend class ArrayNodeNMProxy;
    std::unordered_map<const AbstractNode*,References_t> references_; //referencing, but not owning parents
    public:
    std::unordered_map<const AbstractNode*,Childs_t> childs_;
    private:
    std::unordered_map<const AbstractNode*,INFO_NODE> owner_; //parent, which own this node
    std::unordered_set<std::unique_ptr<AbstractNode>,NodeHash<std::unique_ptr<AbstractNode>>,NodeEq<std::unique_ptr<AbstractNode>>> nodes_;
    static const Childs_t empty_childs_;
    static const References_t empty_references_;
    // int constructed = 0;
    // int refered = 0;
    // int destructed = 0;
    const BaseData* bd_ = nullptr;
    bool modifyable_=false;
    //NodeManager* modifyable_node_mng_ = nullptr; make static maybe?
    public:
    NodeManager() = default;
    NodeManager(const BaseData* bd):bd_(bd){}
    ~NodeManager();
    NodeManager(const NodeManager& other):
    references_(other.references_),
    //childs_(other.childs_),
    owner_(other.owner_){
        //TODO: create variable-copies in copied relation_manager
    }

    NodeManager(NodeManager&& other):
    references_(std::move(other.references_)),
    childs_(std::move(other.childs_)),
    owner_(std::move(other.owner_)){}

    void log_state() const{
        // std::cout<<"Constructed: "<<constructed<<std::endl;
        // std::cout<<"Refered: "<<refered<<std::endl;
        // std::cout<<"Destructed: "<<destructed<<std::endl;
        std::cout<<"references_ size: "<<references_.size()<<std::endl;
        std::cout<<"childs_ size: "<<childs_.size()<<std::endl;
        std::cout<<"owner_ size: "<<owner_.size()<<std::endl;
    }

    static INFO_NODE owner(const AbstractNode* node) noexcept;

    static const Childs_t& childs(const AbstractNode* node) noexcept{
        if(node->relation_manager()->childs_.contains(node))
            return node->relation_manager()->childs_.at(node);
        else return empty_childs_;
    }
    //TODO (maybe)
    static void begin(NodeManager*); //use anonymous NodeManager for safe inclusions
    static void end(NodeManager*); //safe_merge if no one exception was thrown
    void begin(); //use anonymous NodeManager for safe inclusions
    void end(); //safe_merge if no one exception was thrown

    static void reserve_childs(const AbstractNode* node,size_t size);
    static void erase_child(const AbstractNode* node, size_t id) noexcept;
    static void empty_child(const AbstractNode* node, size_t id) noexcept;
    static AbstractNode* child(const AbstractNode* node,size_t id);
    static AbstractNode* child(AbstractNode* node,size_t id);
    static INFO_NODE child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept;
    static AbstractNode* insert_back(const AbstractNode* node,std::unique_ptr<AbstractNode>&& new_child);
    static AbstractNode* insert_back_ref(const ReferenceNode* node,AbstractNode* new_child);

    //insert before value at id
    static AbstractNode* insert(const AbstractNode* node,size_t id,std::unique_ptr<AbstractNode>&& new_child);
    static AbstractNode* replace(const AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child);

    //does not delete the replaced pointer's node
    static AbstractNode* replace_child_wo_delete_in_owner_by(const AbstractNode* owner, size_t id, AbstractNode* val){
        assert(val && owner && owner->has_child(id) && val->relation_manager()==owner->relation_manager());
        owner->relation_manager()->childs_.at(owner).at(id)=val;
        return val;
    }
    static AbstractNode* add_node(NodeManager*,std::unique_ptr<AbstractNode>&& node);
    static void delete_node(const AbstractNode* node);
    static const std::unique_ptr<AbstractNode>& get_node(NodeManager*, const AbstractNode*);
    static bool has_references(const AbstractNode* node) noexcept;
    static bool is_reference_of(const AbstractNode* from, AbstractNode* node);
    static bool has_owner(const AbstractNode* node) noexcept;
    static void refresh_parent_links(const AbstractNode* node) noexcept;
    static std::set<const VariableNode*> refer_to_vars(const AbstractNode* node) noexcept;
    static std::set<const AbstractNode*> refer_to_node_of_type(const AbstractNode* node, NODE_TYPE type) noexcept;
    static bool has_childs(const AbstractNode* node) noexcept;
    static bool has_child(const AbstractNode* node, size_t id) noexcept;
    static void release_childs(const AbstractNode* node) noexcept;
    static const References_t& references(const AbstractNode* node) noexcept;
    static void swap_parents(const AbstractNode* lhs, const AbstractNode* rhs);
    static void swap_childs(const AbstractNode* lhs, const AbstractNode* rhs);
    static void copy_parents(const AbstractNode* from, const AbstractNode* to);
    static void copy_childs(AbstractNode* node, const Childs_t& childs);
    static bool is_modifying(NodeManager* from);
    bool is_empty() const{
        return owner_.empty()
        && childs_.empty()
        && references_.empty()
        && nodes_.empty();
    }
    private:
    void __clear__();
    void __safe_merge__(NodeManager* from) noexcept;
    static void __erase_reference__(AbstractNode* from_node, const AbstractNode* parent);
    static void __add_reference__(const AbstractNode* node_to_add, ReferenceNode* ref_node, int index) noexcept;
    static void __add_owner__(const AbstractNode* node_to_add, const AbstractNode* owner, int index) noexcept;
};
