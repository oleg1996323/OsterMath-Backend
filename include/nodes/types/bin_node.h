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

    inline virtual Result cached_result() override{
        return cached_result(0);
    }
    inline virtual Result cached_result(size_t index) override{
        return __calculate__(index);
    }
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
    Result& lhs_cache() const{
        return bin_cache_.at(0).first;
    }
    Result& rhs_cache() const{
        return bin_cache_.at(0).second;
    }
    Result& lhs_cache(size_t index) const{
        return bin_cache_.at(index).first;
    }
    Result& rhs_cache(size_t index) const{
        return bin_cache_.at(index).second;
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
        if(lhs_cache(index).is_error())
            return lhs_cache(index);
        if(rhs_cache(index).is_error())
            return rhs_cache(index);
        if(!lhs_cache(index).is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        if(!rhs_cache(index).is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        return std::monostate();
    }

    Result __calculate__();
    Result __calculate__(size_t index);

    //cannot be returned reference because of resizing cache-vector (invalidation possible)
    Result& lhs_cache(size_t index){
        if(bin_cache_.size()-1<index)
            bin_cache_.resize(index+1);
        return bin_cache_[index].first;
    }
    //cannot be returned reference because of resizing cache-vector (invalidation possible)
    Result& rhs_cache(size_t index){
        if(bin_cache_.size()-1<index)
            bin_cache_.resize(index+1);
        return bin_cache_[index].second;
    }

    mutable std::vector<std::pair<Result,Result>> bin_cache_=[](){std::vector<std::pair<Result,Result>> res;
                                                res.resize(1);
                                                return res;}();
    BINARY_OP operation_;
};
