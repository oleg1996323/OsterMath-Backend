#pragma once
#include "def.h"
#include "abstract_node.h"
#include "range_node/def.h"
#include <unordered_set>

using namespace node_range_operation;
class ValueNode:public AbstractNode{
    Result cache_;
    public:
    ValueNode()=default;

    ValueNode(const ValueNode& value,NodeManager* mng):AbstractNode(value,mng){
        cache_ = value.cache_;
    }
    ValueNode(ValueNode&& value,NodeManager* mng):AbstractNode(value,mng){
        cache_.swap(value.cache_);
    }
    ValueNode(Value_t&& value,NodeManager* mng):AbstractNode(mng){
        cache_ = std::move(value);
    }
    ValueNode(const Value_t& value,NodeManager* mng):AbstractNode(mng){
        cache_ = value;
    }
    ValueNode(std::string&& value,NodeManager* mng):AbstractNode(mng){
        cache_ = Value_t(value);
    }
    ~ValueNode();
    virtual NODE_TYPE type() const override;
    inline virtual TYPE_VAL type_val() const override{
        return TYPE_VAL::VALUE;
    }
    inline virtual Result execute() const override{
        return cache_;
    }
    inline virtual Result cached_result() const override{
        return cache_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual bool is_empty() const override;
    //virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    inline virtual bool __is_not_cycled__(const AbstractNode*) const override{
        return true;
    }
    inline virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override{
        return cache_;
    }
};