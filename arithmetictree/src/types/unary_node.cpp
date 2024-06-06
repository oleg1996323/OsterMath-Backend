#include "unary_node.h"

std::ostream& UnaryNode::print_text(std::ostream& stream) const{
    if(operation_==UNARY_OP::ADD)
        stream<<"+"<<childs_.at(0);
    else if(operation_==UNARY_OP::SUB)
        stream<<"-"<<childs_.at(0);
    else if(operation_==UNARY_OP::PARENS)
        stream<<"("<<childs_.at(0)<<")";
    else stream<<"";
    return stream;
}

virtual std::ostream& UnaryNode::print_result(std::ostream& stream) const{
    stream<<execute();
    return stream;
}

Node* UnaryNode::first_undefined_child_node(){
    if(childs_.empty())
        return this;
    else
        return childs_.at(0)->first_undefined_child_node();
}

Result UnaryNode::__calculate__(){
    switch (operation_)
        {
        case UNARY_OP::ADD:
            return childs_.at(0)->execute();
            break;
        case UNARY_OP::SUB:
            return (-1)*(childs_.at(0)->execute());
            break;
        case UNARY_OP::PARENS:
            return childs_.at(0)->execute();
            break;
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}

Value_t UnaryNode::execute(){
    using namespace boost::multiprecision;
    if(!childs_.empty()){
        return __calculate__(std::move(child_->execute()));
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
}

Value_t UnaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(!childs_.empty()){
        return __calculate__(std::move(child_->execute(index)));
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
}

bool UnaryNode::is_numeric() const{
    return childs_.at(0)->is_numeric();
}

bool UnaryNode::is_string() const{
    return childs_.at(0)->is_string();
}

bool UnaryNode::is_array() const{
    return childs_.at(0)->is_array();
}
