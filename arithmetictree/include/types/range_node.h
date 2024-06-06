#pragma once
#include "def.h"
#include "var_node.h"
#include "array_node.h"

enum class RANGE_OP{
    SUM,
    PROD
};

//calculate some expressions by range of input values.
//Childs should be only numeric variable-arrays and have same length
class RangeOperationNode:public Node{
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::RANGEOP;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void insert(std::shared_ptr<Node> node) override;

    const std::unordered_set<VariableNode*>& get_dependencies() const;

    virtual void printText() const;

    std::shared_ptr<Node>& expression();

    const std::shared_ptr<Node>& expression() const;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    size_t range_length() const{
        return range_size;
    }

    virtual std::ostream& operator<<(std::ostream& stream) override;

    private:

    //checks the childs types and them correct vals types
    //Childs should be only numeric variable-arrays and have same length
    bool __checking_childs__() const{
        for(auto& child:childs_){
            if(child->type()==NODE_TYPE::ARRAY){
                ArrayNode* ptr = reinterpret_cast<ArrayNode*>(child.get());
                if(ptr->first_undefined_child_node()!=nullptr)
                    throw std::runtime_error("Incorrect initialization of array");
                if(ptr->is_numeric()){
                    if(range_size==0){
                        if((range_size=ptr->size())==0)
                            throw std::invalid_argument("Null size array input in range function");
                        else continue;
                    }
                    else {
                        if(range_size!=ptr->size())
                            throw std::invalid_argument("Unequal size array input in range function");
                        else continue;
                    }
                }
                else {
                    throw std::invalid_argument("Not numeric array data");
                    return false;
                }

            }
            else return false;
        }
        return range_size;
    }

    mutable size_t range_size = 0;
    std::shared_ptr<Node> range_expression;
    mutable std::unordered_set<VariableNode*> var_dependence_;
    RANGE_OP operation_;
    std::optional<Value_t> cache_;
};
