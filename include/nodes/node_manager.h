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
using Nodes_t = std::unordered_set<std::unique_ptr<AbstractNode>,NodeHash<std::unique_ptr<AbstractNode>>,NodeEq<std::unique_ptr<AbstractNode>>>;

class NodeManager{
    friend class ArrayNodeNMProxy;
    friend class ReferenceNodeNMProxy;
    friend class AbstractNodeNMProxy;
    std::unordered_map<const AbstractNode*,References_t> references_; //referencing, but not owning parents
    public:
    std::unordered_map<const AbstractNode*,Childs_t> childs_;
    private:
    std::unordered_map<const AbstractNode*,INFO_NODE> owner_; //parent, which own this node
    Nodes_t nodes_;
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

    const Nodes_t& nodes() const{
        return nodes_;
    }

    static void erase_child(const AbstractNode* node, size_t id) noexcept;
    static void erase_childs(const AbstractNode* node, size_t first_id, size_t last_id) noexcept;
    static AbstractNode* child(const AbstractNode* node,size_t id);
    static AbstractNode* child(AbstractNode* node,size_t id);
    static INFO_NODE child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept;
    
    template<typename T, typename... ARGS>
    static T* insert_back(AbstractNode* node, ARGS&&... val){
        assert(node->relation_manager());
        return node->relation_manager()->insert_back(node,std::make_unique<T>(std::forward<ARGS>(val)...));
    }
    static AbstractNode* insert_back_move(AbstractNode* at_insert_back, AbstractNode* inserted);
    static AbstractNode* insert_back_copy(AbstractNode* at_insert_back, AbstractNode* inserted);
    static AbstractNode* insert_back_ref(ReferenceNode* node,AbstractNode* new_child);

    static AbstractNode* insert_move(AbstractNode* at_insertion,size_t id,AbstractNode* to_insert);
    static AbstractNode* insert_copy(AbstractNode* at_insertion,size_t id,AbstractNode* to_insert);
    static AbstractNode* replace_move(AbstractNode* at_replacing,size_t id,AbstractNode* to_replace);
    static AbstractNode* replace_copy(AbstractNode* at_replacing,size_t id,AbstractNode* to_replace);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> insert_back_move(AbstractNode* at_insertion,Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> insert_back_copy(AbstractNode* at_insertion,Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> insert_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> insert_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> replace_move(AbstractNode* at_replacing,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> replace_copy(AbstractNode* at_replacing,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);

    static void delete_node(const AbstractNode* node);
    static bool has_references(const AbstractNode* node) noexcept;
    static bool is_reference_of(const AbstractNode* from, AbstractNode* node);
    static bool has_owner(const AbstractNode* node) noexcept;
    static std::set<const VariableNode*> refer_to_vars(const AbstractNode* node) noexcept;
    static std::set<const AbstractNode*> refer_to_node_of_type(const AbstractNode* node, NODE_TYPE type) noexcept;
    static bool has_childs(const AbstractNode* node) noexcept;
    static bool has_child(const AbstractNode* node, size_t id) noexcept;
    static void release_childs(const AbstractNode* node) noexcept;
    static const References_t& references(const AbstractNode* node) noexcept;
    static void swap_node(AbstractNode* lhs, AbstractNode* rhs);
    static void move_node(AbstractNode* at_move, AbstractNode* to_move);
    static void copy_node(AbstractNode* to_replace_by_copy, const AbstractNode* to_copy);
    static std::unique_ptr<AbstractNode> extract_node(AbstractNode* node);
    static std::vector<std::unique_ptr<AbstractNode>> extract_nodes(Childs_t::const_iterator,Childs_t::const_iterator);
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> move_nodes(AbstractNode* at_move, size_t id, Childs_t::const_iterator to_move_first, Childs_t::const_iterator to_move_last) noexcept;
    static std::pair<Childs_t::const_iterator,Childs_t::const_iterator> copy_nodes(AbstractNode* at_move, size_t id, Childs_t::const_iterator to_copy_first, Childs_t::const_iterator to_copy_last);
    static bool is_modifying(NodeManager* from);
    bool is_empty() const{
        return owner_.empty()
        && childs_.empty()
        && references_.empty()
        && nodes_.empty();
    }
    static bool is_directly_owned_by(const AbstractNode* owner, const AbstractNode* node) noexcept;
    template<typename T, typename... ARGS>
    static std::unique_ptr<T> make_node(NodeManager* rel_mng,ARGS&&... node_val){
        std::unique_ptr<T> n_res;
        if constexpr((std::is_lvalue_reference_v<ARGS...> && std::is_const_v<ARGS...>) || std::is_rvalue_reference_v<ARGS...>){
            n_res = std::make_unique<T>(std::forward<ARGS>(node_val)...);
            n_res->set_relation_manager(rel_mng);
        }
        else{
            n_res = std::make_unique<T>(std::forward<ARGS>(node_val)...,rel_mng);
        }
        return n_res;
    }
    static bool is_refered_by(const AbstractNode* ref_owner, const AbstractNode* refered) noexcept;
    template<typename T, typename... ARGS>
    std::unique_ptr<T> make_node(ARGS&&... node_val){
        std::unique_ptr<T> n_res;
        if constexpr((std::is_lvalue_reference_v<ARGS...> && std::is_const_v<ARGS...>) || std::is_rvalue_reference_v<ARGS...>)
            n_res = std::make_unique<T>(std::forward<ARGS>(node_val)...);
        else
            n_res = std::make_unique<T>(std::forward<ARGS>(node_val)...,(NodeManager*)this);
        return n_res;
    }
    protected:
    static AbstractNode* insert_back(AbstractNode* node,std::unique_ptr<AbstractNode>&& new_child);
    //insert before value at id
    static AbstractNode* insert(AbstractNode* node,size_t id,std::unique_ptr<AbstractNode>&& new_child);
    static AbstractNode* replace(AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child);

    static AbstractNode* add_node(NodeManager*,std::unique_ptr<AbstractNode>&& node);
    private:
    static const std::unique_ptr<AbstractNode>& get_node(NodeManager*, const AbstractNode*);
    void __clear__();
    void __safe_merge__(NodeManager* from) noexcept;
    static Childs_t& __childs__(const AbstractNode* node);
    static ReferenceNode* __erase_reference__(const AbstractNode* from_node, ReferenceNode* ref) noexcept;
    static ReferenceNode* __add_reference__(const AbstractNode* node_to_add, ReferenceNode* ref_node) noexcept;
    static void __add_owner__(const AbstractNode* node_to_add, const AbstractNode* owner, int index) noexcept;
    static void __reserve_childs__(const AbstractNode* node,size_t size);

};
