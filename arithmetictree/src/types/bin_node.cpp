#include "bin_node.h"

Node* BinaryNode::first_undefined_child_node(){
    Node* ptr;
    if(!child(0))
        return this;
    else if((ptr = child(0)->first_undefined_child_node()))
        return ptr;
    else if(!child(1))
        return this;
    else if((ptr = child(1)->first_undefined_child_node()))
        return ptr;
    return nullptr;
}

Value_t BinaryNode::__calculate__(){
    return __calculate__(0);
}

Value_t BinaryNode::__calculate__(size_t index){
    switch (operation_)
    {
        case BINARY_OP::ADD:
        #ifdef DEBUG
            std::cout<<"Add: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            return lhs_cache(index)+rhs_cache(index);
            break;
        case BINARY_OP::SUB:
        #ifdef DEBUG
            std::cout<<"Sub: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            return lhs_cache(index)-rhs_cache(index);
            break;
        case BINARY_OP::MUL:
        #ifdef DEBUG
            std::cout<<"Mul: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            return lhs_cache(index)*rhs_cache(index);
            break;
        case BINARY_OP::DIV:
        #ifdef DEBUG
            std::cout<<"Div: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            return lhs_cache(index)/rhs_cache(index);
            break;
        case BINARY_OP::POW:
        #ifdef DEBUG
            std::cout<<"Pow: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            return pow(lhs_cache(index),rhs_cache(index));
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
}

Result BinaryNode::execute(){
    return execute(0);
}

Result BinaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(child(0) && child(1)){
        if(child(0)->caller()) //left branch call refreshing
            child(0)->execute(index);
        else if(child(1)->caller()) //right branch call refreshing
            child(1)->execute(index);
        else{
            lhs_cache(index) = child(0)->execute(index).get<Value_t>();
            rhs_cache(index) = child(1)->execute(index).get<Value_t>();
        }
        if(operation_==BINARY_OP::DIV && rhs_cache(index)==0.)
            throw std::logic_error("Division by 0 (NULL)");
        return __calculate__(index);
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

std::ostream& BinaryNode::print_text(std::ostream& stream) const{
    stream<<childs_.at(0)<<(char)operation_<<childs_.at(1);
    return stream;
}

bool BinaryNode::is_numeric() const{
    return childs_.at(0)->is_numeric() && childs_.at(1)->is_numeric();
}

bool BinaryNode::is_string() const{
    return childs_.at(0)->is_string() && childs_.at(1)->is_string();
}

bool BinaryNode::is_array() const{
    return childs_.at(0)->is_array() && childs_.at(1)->is_array();
}