#pragma once
#include <memory>
#include <optional>
#include "def.h"
#include "arithmetic_functions.h"

enum class ARITHM_NODE_TYPE{
    UNARY,
    BINARY, 
    VALUE, 
    VARIABLE,
    MULTIARG
};

enum class BINARY_OP{
    ADD,
    SUB,
    MUL,
    DIV,
    POW
};

enum class UNARY_OP{
    LN,
    LG10,
    EXP,
    ADD,
    SUB,
    PARENS
};

enum class MULTI_ARG_OP{
    SUMPRODUCT,
    CONCAT,
    LOG_BASE
};

class Node;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;

class Node{
    public:
    Node() = default;

    virtual ARITHM_NODE_TYPE type() const = 0;

    virtual Node* first_undefined_child_node() = 0;

    virtual Value_t execute() = 0;

    virtual void refresh();

    virtual void print() const{
        std::cout<<"Undef node"<<std::endl;
    }

    virtual ~Node(){}

    virtual void add_parent(Node*);

    virtual bool has_parent() const;

    bool caller() const{
        return caller_;
    }

    protected:
    Node* parent_;
    bool caller_ = false;
};

class UnaryNode:public Node{
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP op):operation(op){}

    virtual Node* first_undefined_child_node() override;

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::UNARY;
    }

    std::shared_ptr<Node>& child(){
        return child_;
    }

    const std::shared_ptr<Node>& child() const{
        return child_;
    }

    virtual Value_t execute() override;

    virtual void print() const override;

    private:
    std::shared_ptr<Node> child_;
    UNARY_OP operation;
};

class BinaryNode:public Node{
    friend UnaryNode;
    friend MultiArgumentNode;
    friend ValueNode;
    friend VariableNode;
    public:
    BinaryNode(BINARY_OP op):operation_(op){}

    Value_t get(){
        return 0.;
    }

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::BINARY;
    }

    virtual Node* first_undefined_child_node() override;

    virtual Value_t execute() override;

    std::shared_ptr<Node>& lhs(){
        return lhs_;
    }

    std::shared_ptr<Node>& rhs(){
        return rhs_;
    }

    const std::shared_ptr<Node>& lhs() const {
        return lhs_;
    }

    const std::shared_ptr<Node>& rhs() const {
        return rhs_;
    }

    Value_t& lhs_cache() const{
        return cache_.first;
    }

    Value_t& rhs_cache() const{
        return cache_.second;
    }

    BINARY_OP operation() const{
        return operation_;
    }

    virtual void print() const override;

    private:
    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    mutable std::pair<Value_t,Value_t> cache_;
    BINARY_OP operation_;
};

class ValueNode:public Node{
    public:   
    ValueNode(Value_t&& value):val_(std::move(value)){}

    ValueNode(const Value_t& value):val_(value){}

    ValueNode(std::string&& value):val_(value){}

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::VALUE;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Value_t execute() override{
        return val_;
    }

    virtual void print() const;

    private:
    Value_t val_;
};

class VariableNode:public Node{
    public:
    VariableNode(VariableBase* variable);
    
    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::VARIABLE;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual void refresh() override;

    const VariableBase* variable() const;

    virtual Value_t execute() override;

    virtual void print() const;

    virtual void add_parent(Node* parent) override; 

    private:
    mutable std::unordered_set<Node*> parents_;
    VariableBase* var_;

    void refresh_parent_links() const;
};

class MultiArgumentNode:public Node{
    public:
    MultiArgumentNode(MULTI_ARG_OP op):operation_(op){}

    const std::vector<Node*>& childs() const{
        return childs_;
    }

    Node* child(size_t id) const;

    void add_child(Node*);

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::MULTIARG;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Value_t execute() override;

    virtual void print() const;

    private:
    std::vector<Node*> childs_;
    MULTI_ARG_OP operation_;
    std::optional<Value_t> cache_;
};