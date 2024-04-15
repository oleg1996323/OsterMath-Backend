#include "arithmetic_types.h"
#include "types.h"

Node* UnaryNode::first_undefined_child_node(){
    if(!child_)
        return this;
    else return child_->first_undefined_child_node();
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
}

void UnaryNode::refresh(){
    
}

Node* BinaryNode::first_undefined_child_node(){
    if(!lhs_ || !rhs_)
        return this;
    else{
        Node* lhs_ptr = lhs_->first_undefined_child_node();
        if(lhs_ptr)
            return lhs_ptr;
        else{
            Node* rhs_ptr = rhs_->first_undefined_child_node();
            return rhs_ptr?rhs_ptr:nullptr;
        }
    }
}

Value_t BinaryNode::execute(){
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        switch (operation)
        {
        case BINARY_OP::ADD:
            return lhs_->execute()+rhs_->execute();
            break;
        case BINARY_OP::SUB:
            return lhs_->execute()-rhs_->execute();
            break;
        case BINARY_OP::MUL:
            return lhs_->execute()*rhs_->execute();
            break;
        case BINARY_OP::DIV:
            return lhs_->execute()/rhs_->execute();
            break;
        case BINARY_OP::POW:
            return pow(lhs_->execute(),rhs_->execute());
            break;
        default:
            break;
        }
    }
    else
        throw std::runtime_error("Undefined binary operation");
}

void BinaryNode::refresh(){
    execute();
    if(parent())
        parent()->refresh();
}

Value_t VariableNode::execute(){
    std::shared_ptr<VariableBase> ptr = var_.lock();
    if(!ptr->is_arithmetic_tree() || ptr->is_value()){
        return ptr->get<Value_t>();
    }
    else throw std::invalid_argument("Invalid type of variable");
}

Node* MultiArgumentNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}