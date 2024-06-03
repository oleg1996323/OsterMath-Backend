#include "unary_node.h"

#ifdef DEBUG
void UnaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::UNARY);
    std::cout<<'}'<<std::endl;
}
#endif

Node* UnaryNode::first_undefined_child_node(){
    if(childs_.empty())
        return this;
    else
        return childs_.at(0)->first_undefined_child_node();
}

Result UnaryNode::__calculate__(){
    switch (operation)
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