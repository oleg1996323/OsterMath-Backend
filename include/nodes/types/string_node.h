#pragma once
#include <iostream>
#include "def.h"
#include "abstract_node.h"
#include "range_node/def.h"

class StringNode:public AbstractNode{
    std::string cache_;
    public:
    inline StringNode()=default;
    inline StringNode(Value_t&& value,NodeManager* mng):AbstractNode(mng){
        cache_ = value.str();
    }
    inline StringNode(const Value_t& value,NodeManager* mng):AbstractNode(mng){
        cache_ = value.str();
    }
    inline StringNode(const std::string& str,NodeManager* mng):AbstractNode(mng){
        cache_ = str;
    }
    inline StringNode(std::string&& str,NodeManager* mng):AbstractNode(mng){
        cache_ = str;
    }
    inline StringNode(const StringNode& other,NodeManager* mng):AbstractNode(other,mng){
        cache_ = other.cache_;
    }
    StringNode(StringNode&& other,NodeManager* mng):AbstractNode(other,mng){
        cache_.swap(other.cache_);
    }
    ~StringNode();

    virtual NODE_TYPE type() const override;
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
    // virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    inline virtual bool __is_not_cycled__(const AbstractNode*) const override{
        return true;
    }
};