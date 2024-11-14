#pragma once
#include "include/nodes/def.h"
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
    BinaryNode(const BinaryNode& other);
    BinaryNode(BinaryNode&&) =delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::BINARY;
    }
    virtual Result execute() override;
    virtual Result execute(size_t index) override;

    std::shared_ptr<Node> lhs(){
        return child(0);
    }
    std::shared_ptr<Node> rhs(){
        return child(1);
    }
    const std::shared_ptr<Node> lhs() const {
        return child(0);
    }
    const std::shared_ptr<Node> rhs() const {
        return child(1);
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual Result cached_result() override{
        return execute();
    }
    inline virtual Result cached_result(size_t index) noexcept override{
        return execute(index);
    }

    BINARY_OP operation() const{
        return operation_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:

    inline Result ErrorChecking(size_t index){
        if(!(has_child(0) && has_child(1) && !childs_.size()==2)){
            cache_ = std::make_shared<exceptions::InvalidNumberOfArguments>(2);
            return cache_;
        }
        if(child(0)->execute().is_error()){
            cache_ = child(0)->cached_result();
            return cache_;
        }
        if(child(1)->execute().is_error()){
            cache_ = child(1)->cached_result();
            return cache_;
        }
        if(!child(0)->cached_result(index).is_value() || !child(1)->cached_result(index).is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        return std::monostate();
    }

    Result __calculate__();
    Result __calculate__(size_t index);
    BINARY_OP operation_;
};
