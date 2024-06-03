#pragma once
#include <vector>
#include <memory>
#include "def.h"
#include "node.h"

enum class FUNCTION_OP{
    LN,
    LG10,
    EXP,
    COS,
    ACOS,
    SIN,
    ASIN,
    FACTORIAL,
    LOG_BASE,
    SUM,
    PROD,
    SUMPRODUCT
};

constexpr bool ARRAY_TYPE_FUNCTION [int(FUNCTION_OP::SUMPRODUCT)+1] = 
{   
    /*LN*/{false},
    /*LG10*/{false},
    /*EXP*/{false},
    /*SIN*/{false},
    /*COS*/{false},
    /*ACOS*/{false},
    /*ASIN*/{false},
    /*FACTORIAL*/{false},
    /*LOG_X*/{false},
    /*SUM*/{true}, 
    /*PROD*/{true}, 
    /*SUMPRODUCT*/{true}};

//0 - if 1 or more
constexpr size_t NUMBER_OF_ARGUMENT [int(FUNCTION_OP::SUMPRODUCT)+1] = {
    /*LN*/{1},
    /*LG10*/{1},
    /*EXP*/{1},
    /*SIN*/{1},
    /*COS*/{1},
    /*ACOS*/{1},
    /*ASIN*/{1},
    /*FACTORIAL*/{1},
    /*LOG_X*/{2},
    /*SUM*/{0}, 
    /*PROD*/{0}, 
    /*SUMPRODUCT*/{0}};

class FunctionNode:public Node{
    public:
    FunctionNode(FUNCTION_OP op):
    Node(int(op)),
    operation_(op),
    array_type_function(ARRAY_TYPE_FUNCTION[int(op)])
    {}

    std::shared_ptr<Node> child(size_t id) const;

    void add_child(const std::shared_ptr<Node>&);

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }

    bool is_array_function() const{
        return array_type_function;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    private:

    bool __is_variable_node__(size_t index) const{
        return childs_.at(index)->type()==NODE_TYPE::VARIABLE;
    }

    bool __is_simple_node__(size_t index) const{
        return !(childs_.at(index)->type()==NODE_TYPE::VARIABLE);
    }

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    
    FUNCTION_OP operation_;
    mutable std::unordered_set<VariableNode*> var_dependence_;
    std::optional<Value_t> cache_;
    bool array_type_function;
    
    //auto __register_array_input__();
};