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
    MULTIARG,
    RANGEOP,
    FUNCTION
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
    PARENS,
    COS,
    ACOS,
    SIN,
    ASIN,
    FACTORIAL
};

enum MULTI_ARG_OP{
    SUMPRODUCT,
    SUM,
    PROD,
    LOG_BASE
};

enum class RANGE_OP{
    SUM,
    PROD
};

class Node;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;
class RangeOperationNode;

class Node{
    public:
    Node() = default;

    virtual ARITHM_NODE_TYPE type() const = 0;

    virtual Node* first_undefined_child_node() = 0;

    virtual Value_t execute() = 0;

    virtual Value_t execute(size_t index) = 0;

    virtual void refresh();

    #ifdef DEBUG
    virtual void print() const{
        std::cout<<"Undef node"<<std::endl;
    }
    #endif

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

    virtual Value_t execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    private:
    Value_t __calculate__(Value_t&& child_exec);

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

    virtual Value_t execute(size_t index) override;

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
        return cache_.at(0).lhs_;
    }

    Value_t& rhs_cache() const{
        return cache_.at(0).rhs_;
    }

    Value_t& lhs_cache(size_t index) const{
        return cache_.at(index).lhs_;
    }

    Value_t& rhs_cache(size_t index) const{
        return cache_.at(index).rhs_;
    }

    BINARY_OP operation() const{
        return operation_;
    }

    #ifdef DEBUG
    virtual void print() const;
    #endif

    private:
    class __cache__{
        public:
        __cache__() = default;

        __cache__(const __cache__& other){
            *this = other;
        }

        __cache__(__cache__&& other){
            *this=other;
        }

        __cache__& operator=(const __cache__& other){
            if(&other != this){
                lhs_ = other.lhs_;
                rhs_ = other.rhs_;
            }
            return *this;
        }

        __cache__& operator=(__cache__&& other){
            if(&other != this){
                std::swap(lhs_,other.lhs_);
                std::swap(rhs_,other.rhs_);
            }
            return *this;
        }

        Value_t lhs_;
        Value_t rhs_;
    };
    Value_t __calculate__();
    Value_t __calculate__(size_t index);

    Value_t& lhs_cache(size_t index){
        if(cache_.size()-1<index)
            cache_.resize(index+1);
        return cache_[index].lhs_;
    }

    Value_t& rhs_cache(size_t index){
        if(cache_.size()-1<index)
            cache_.resize(index+1);
        return cache_[index].rhs_;
    }

    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    mutable std::vector<__cache__> cache_=[](){std::vector<__cache__> res;
    res.resize(1);
    return res;}();
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

    virtual Value_t execute(size_t index) override{
        return val_;
    }

    #ifdef DEBUG
    virtual void print() const;
    #endif

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

    VariableBase* variable() const;

    virtual Value_t execute() override;

    virtual Value_t execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    virtual void add_parent(Node* parent) override; 

    private:
    mutable std::unordered_set<Node*> parents_;
    VariableBase* var_;

    void refresh_parent_links() const;
};

constexpr bool ARRAY_TYPE_MULTIARG [MULTI_ARG_OP::LOG_BASE+1] = 
{
    /*SUMPRODUCT*/{true}, 
    /*SUM*/{true}, 
    /*PROD*/{true}, 
    /*LOG_X*/{false}};

class MultiArgumentNode:public Node{
    public:
    MultiArgumentNode(MULTI_ARG_OP op):operation_(op){
        array_type_function = ARRAY_TYPE_MULTIARG[op];
    }

    const std::vector<Node*>& childs() const{
        return childs_;
    }

    Node* child(size_t id) const;

    void add_child(Node*);

    virtual void refresh() override;

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::MULTIARG;
    }

    bool is_array_function() const{
        return array_type_function;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Value_t execute() override;

    virtual Value_t execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    private:
    std::vector<Node*> childs_;
    MULTI_ARG_OP operation_;
    std::optional<Value_t> cache_;
    bool array_type_function;

    auto __register_array_input__();
};

//calculate some expressions by range of input values.
//Childs should be only numeric variable-arrays and have same length
class RangeOperationNode:public Node{
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    void add_child(VariableNode*);

    virtual ARITHM_NODE_TYPE type() const override{
        return ARITHM_NODE_TYPE::RANGEOP;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual void refresh() override;

    virtual Value_t execute() override;

    virtual Value_t execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    ranges::ArithmeticTree& expression();

    size_t range_length() const{
        return range_size;
    }

    private:

    //checks the childs types and them correct vals types
    //Childs should be only numeric variable-arrays and have same length
    bool __checking_childs__() const{
        for( auto& child:childs_){
            if(child->variable()){
                if(child->variable()->is_array()){
                    if(range_size==0)
                        if((range_size=child->variable()->get<Array_t>().size())==0)
                            throw std::invalid_argument("Null size array input in range function");
                        else continue;
                    else{
                        if(range_size!=child->variable()->get<Array_t>().size())
                            throw std::invalid_argument("Unequal size array input in range function");
                        else continue;
                    }
                }
                else if(child->variable()->is_numeric())
                    continue;
                else return false;
            }
            else return 0L;

            //checking same range-length. If not return false (NULL val)
            if(!child->variable() || !child->variable()->is_array())
                return 0L;

            //checking same range-length. If not return false (NULL val)
            if(range_size!=child->variable()->get<Array_t>().size())
                return 0L;
        }
        return range_size;
    }

    std::unordered_set<VariableNode*> childs_;
    mutable size_t range_size = 0;
    ranges::ArithmeticTree range_expression;
    RANGE_OP operation_;
    std::optional<Value_t> cache_;
};