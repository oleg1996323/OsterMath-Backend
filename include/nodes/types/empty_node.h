#pragma once
#include <memory>
#include <optional>
#include <vector>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include "def.h"
#include "range_node/def.h"
#include "node/def.h"
#include "abstract_node.h"

using namespace node_range_operation;
class EmptyNode:public AbstractNode{
public:
    EmptyNode(NodeManager* mng = nullptr);
    EmptyNode(const EmptyNode& other,NodeManager* mng):AbstractNode(other,mng){}
    EmptyNode(EmptyNode&& other,NodeManager* mng):AbstractNode(other,mng){}
    ~EmptyNode();
    virtual TYPE_VAL type_val() const override final;    
    virtual NODE_TYPE type() const override final;
    virtual Result execute() const override;
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
    inline virtual Result cached_result() const override final{
        return std::monostate();
    }
    virtual bool is_numeric() const override final;
    virtual bool is_string() const override final;
    virtual bool is_array() const override final;
    virtual bool is_empty() const override final;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
private:
    virtual bool __is_not_cycled__(const AbstractNode*) const override;
};