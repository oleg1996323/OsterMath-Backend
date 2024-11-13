#pragma once
#include <memory>
#include <optional>
#include <vector>
#include <unordered_set>
#include <functional>
#include "nodes/def.h"

class Node;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;
class RangeOperationNode;

enum class NODE_TYPE{
    UNARY,
    BINARY,
    VALUE,
    VARIABLE,
    RANGEOP,
    FUNCTION,
    ARRAY,
    STRING,
    UNDEF,
    CUSTOM
};

struct INFO_NODE{
    Node* parent = nullptr;
    //std::shared_ptr<INFO_NODE> parent_info;
    int id = -1;

    std::shared_ptr<Node> node() const;
    bool has_node() const;
    bool is_valid() const;
};

class Node{
    public:
    Node(size_t sz);
    Node();
    Node(const Node& other){
        *this = other;
    }

    inline Node& operator=(const Node& other);
    inline Node& operator=(Node&& other);
    TYPE_VAL type_val() const;
    inline const std::shared_ptr<Node>& child(size_t id) const{
        if(id<childs_.size())
            return childs_.at(id);
        else
            throw std::invalid_argument("Incorrect child's id");
    }
    inline std::shared_ptr<Node>& child(size_t id){
        if(id<childs_.size())
            return childs_.at(id);
        else
            throw std::invalid_argument("Incorrect child's id");
    }
    INFO_NODE child(const std::vector<size_t>& indexes);
    INFO_NODE child(const std::vector<size_t>& indexes) const;
    inline void release_childs(){
        for(std::shared_ptr<Node>& child:childs_)
            if(child)
                child->parents_.erase(this);
        childs_.clear();
    }
    inline bool has_childs() const{
        return !childs_.empty();
    }

    inline bool has_child(size_t id) const{
        return childs_.size()>id;
    }
    virtual NODE_TYPE type() const;
    virtual Result execute();
    virtual Result execute(size_t index);
    inline virtual Result cached_result(){
        return std::monostate();
    }
    inline virtual Result cached_result(size_t index){
        return std::make_shared<exceptions::InvalidTypeOfArgument>(std::to_string(index).c_str());
    }
    virtual bool is_numeric() const;
    virtual bool is_string() const;
    virtual bool is_array() const;
    virtual bool is_empty() const;
    virtual void insert_back(std::shared_ptr<Node>);
    //insert before value at id
    virtual std::shared_ptr<Node> insert(size_t,std::shared_ptr<Node>);
    virtual std::shared_ptr<Node> replace(size_t,std::shared_ptr<Node>);
    virtual void print_text(std::ostream& stream) const;
    virtual void print_result(std::ostream& stream) const;
    virtual ~Node();
    void add_parent(Node*);
    bool has_parents() const;
    virtual void get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const;
    void replace_move_child_to(Node*,size_t,size_t);
    void replace_copy_child_to(Node*,size_t,size_t);
    void refresh_parent_links() const;
    void refresh();
    const std::unordered_set<Node*>& parents() const;
    std::unordered_set<Node*>& parents();
    bool refer_to(std::string_view var_name) const;
    inline bool caller() const{
        return caller_;
    }
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func);
    const std::vector<std::shared_ptr<Node>>& childs() const;
    protected:
    Result cache_;
    mutable std::unordered_set<Node*> parents_;
    std::vector<std::shared_ptr<Node>> childs_;
    bool caller_ = false;
    private:
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root);
    INFO_NODE child(const std::vector<size_t>& indexes, const Node* caller) const;
    INFO_NODE child(const std::vector<size_t>& indexes, Node* caller);
};

template<typename T, typename... U>
void Node::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func){
    for(auto& child:childs_){
        if(child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
    }
}

template<typename T, typename... U>
void Node::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root){
    for(auto& child:childs_)
        if(child.get()!=root && child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
}

Node& Node::operator=(Node&& other){
    if(&other!=this){
        childs_.swap(other.childs_);
        std::swap(cache_,other.cache_);
    }
    return *this;
}

Node& Node::operator=(const Node& other){
    if(&other!=this){
        release_childs();
        for(const std::shared_ptr<Node>& child:other.childs_){
            if(child->type()!=NODE_TYPE::VARIABLE)
                childs_.push_back(std::make_shared<Node>(*child.get()));
            else childs_.push_back(child);
        }
    }
    return *this;
}