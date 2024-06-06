#pragma once
#include "def.h"
#include "node.h"

enum class BINARY_OP{
    ADD='+',
    SUB='-',
    MUL='*',
    DIV='/',
    POW='^'
};

class BinaryNode:public Node{
    friend UnaryNode;
    friend MultiArgumentNode;
    friend ValueNode;
    friend VariableNode;
    public:
    BinaryNode(BINARY_OP op):operation_(op){}

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::BINARY;
    }

    virtual Node* first_undefined_child_node() override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    std::shared_ptr<Node>& lhs(){
        return child(0);
    }

    std::shared_ptr<Node>& rhs(){
        return child(1);
    }

    const std::shared_ptr<Node>& lhs() const {
        return child(0);
    }

    const std::shared_ptr<Node>& rhs() const {
        return child(1);
    }

    virtual void insert(std::shared_ptr<Node> node) override;

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

    virtual void serialize(std::ostream& stream) override {

    }

    virtual void deserialize(std::ostream& stream) override {

    }

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    virtual std::ostream& print_text(std::ostream& stream) const override;

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

    mutable std::vector<__cache__> cache_=[](){std::vector<__cache__> res;
                                                res.resize(1);
                                                return res;}();
    BINARY_OP operation_;
};
