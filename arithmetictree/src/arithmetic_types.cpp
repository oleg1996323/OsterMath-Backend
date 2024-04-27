#include "arithmetic_types.h"
#include "types.h"

#define ENUM_NAME(p) #p;

void Node::refresh(){
    execute();
    if(parent()){
        caller_ = true;
        parent()->refresh();
        caller_ = false;
    }
}

Node* UnaryNode::first_undefined_child_node(){
    if(!child_)
        return this;
    else return child_->first_undefined_child_node();
}

Node*& Node::parent(){
    return parent_;
}

void UnaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::UNARY);
    std::cout<<'}'<<std::endl;
}

Value_t UnaryNode::execute(){
    using namespace boost::multiprecision;
    if(child_){
        switch (operation)
        {
        case UNARY_OP::LN:
            return log(child_->execute());
            break;
        case UNARY_OP::LG10:
            return log10(child_->execute());
            break;
        case UNARY_OP::ADD:
            return child_->execute();
            break;
        case UNARY_OP::SUB:
            return (-1)*(child_->execute());
            break;
        case UNARY_OP::EXP:
            return exp(child_->execute());
            break;
        case UNARY_OP::PARENS:
            return child_->execute();
            break;
        default:
            break;
        }
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
}

Node* BinaryNode::first_undefined_child_node(){
    Node* ptr;
    if(!lhs_)
        return this;
    else if((ptr = lhs_->first_undefined_child_node()))
        return ptr;
    else if(!rhs_)
        return this;
    else if((ptr = rhs_->first_undefined_child_node()))
        return ptr;
    return nullptr;
}

void BinaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::BINARY);
    std::cout<<"; ";
    if(operation_==BINARY_OP::ADD){
        std::cout<<ENUM_NAME(BINARY_OP::ADD);}
    else if(operation_==BINARY_OP::SUB){
        std::cout<<ENUM_NAME(BINARY_OP::SUB);}
    else if(operation_==BINARY_OP::MUL){
        std::cout<<ENUM_NAME(BINARY_OP::MUL);}
    else if(operation_==BINARY_OP::DIV){
        std::cout<<ENUM_NAME(BINARY_OP::DIV);}
    else std::cout<<ENUM_NAME(BINARY_OP::POW);
    std::cout<<'}'<<std::endl;
}

void BinaryNode::refresh(){
    execute();
    if(parent()){
        caller_ = true;
        parent()->refresh();
        caller_ = false;
    }
}

Value_t BinaryNode::execute(){
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        if(lhs_->caller()) //left branch call refreshing
            lhs_->execute();
        else if(rhs_->caller()) //right branch call refreshing
            rhs_->execute();
        else{
            lhs_cache() = lhs_->execute();
            rhs_cache() = rhs_->execute();
        }
        switch (operation_)
        {
            case BINARY_OP::ADD:
                return lhs_cache()+rhs_cache();
                break;
            case BINARY_OP::SUB:
                return lhs_cache()-rhs_cache();
                break;
            case BINARY_OP::MUL:
                return lhs_cache()*rhs_cache();
                break;
            case BINARY_OP::DIV:
                return lhs_cache()/rhs_cache();
                break;
            case BINARY_OP::POW:
                return pow(lhs_cache(),rhs_cache());
                break;
            default:
                break;
        }
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

void ValueNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VALUE);
    std::cout<<"; "<<val_<<'}'<<std::endl;
}

VariableNode::VariableNode(VariableBase* variable):
    var_(variable){}

const VariableBase* VariableNode::variable() const{
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

void VariableNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VARIABLE);
    std::cout<<var_->name()<<'}'<<std::endl;
}

Value_t VariableNode::execute(){
    if(var_){
        if(var_->is_value()){
            return var_->get<Value_t>();
        }
        else if(var_->is_arithmetic_tree()){
            return var_->get<ArithmeticTree>().execute();
        }
        else if(var_->is_undef())
            return 0.;
        else
        throw std::invalid_argument("Invalid type of variable");
    }
    else throw std::runtime_error("Uninitialized variable");
}

Node* MultiArgumentNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}

void MultiArgumentNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::MULTIARG);
    std::cout<<ENUM_NAME(operation());
    std::cout<<'}'<<std::endl;
}

Value_t MultiArgumentNode::execute(){
    
}