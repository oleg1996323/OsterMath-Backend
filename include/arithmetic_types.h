#pragma once
#include <memory>
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
    Node(Node* parent):parent_(std::unique_ptr<Node>(parent)){}

    virtual Node* next() = 0;

    virtual ARITHM_NODE_TYPE type() const = 0;

    virtual Node* first_undefined_child_node() = 0;

    virtual Value_t execute() = 0;

    virtual ~Node(){}

    std::shared_ptr<Node>& parent(){
        return parent_;
    }

    const std::shared_ptr<Node>& parent() const{
        return parent_;
    }

    private:
    std::shared_ptr<Node> parent_;
};

class UnaryNode:public Node{
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP operation, Node* parent = nullptr):Node(parent){}

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
    BinaryNode(Node* lhs, BINARY_OP op, Node* rhs, Node* parent = nullptr):Node(parent){}

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

    private:
    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    BINARY_OP operation;
};

class ValueNode:public Node{
    public:   
    ValueNode(Value_t&& value, Node* parent = nullptr):Node(parent){}

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::VALUE;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Value_t execute() override{
        return val_;
    }

    private:
    Value_t val_;
};

class VariableNode:public Node{
    public:
    VariableNode(const std::shared_ptr<VariableBase>& variable, Node* parent = nullptr):
    Node(parent),
    var_(variable){}
    
    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::VARIABLE;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Value_t execute() override;

    private:
    std::weak_ptr<VariableBase> var_;
    mutable std::optional<Value_t> cache_;
};

class MultiArgumentNode:public Node{
    public:
    MultiArgumentNode(Node* parent = nullptr):Node(parent){}

    const std::vector<Node*>& childs() const{
        return childs_;
    }

    Node* child(size_t id) const;

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::MULTIARG;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    private:
    std::vector<Node*> childs_;
};