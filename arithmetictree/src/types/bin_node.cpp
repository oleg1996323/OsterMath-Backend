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
    execute(0);
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


#ifdef DEBUG
void BinaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(NODE_TYPE::BINARY);
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
#endif