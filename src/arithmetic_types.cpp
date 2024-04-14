#include "arithmetic_types.h"

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
}

Value_t VariableNode::execute(){
    std::shared_ptr<VariableBase> ptr = var_.lock();
    var_.expired();
    if(ptr){
        VAR_TYPE type = ptr->type();
        if(type==VAR_TYPE::FUNCTION){
            Variable* func_var = reinterpret_cast<Variable*>(ptr.get());
            return func_var->execute();
        }
    }
}

Node* MultiArgumentNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}