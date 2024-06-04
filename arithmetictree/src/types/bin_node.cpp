#include "bin_node.h"

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
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        if(lhs_->caller()) //left branch call refreshing
            lhs_->execute();
        else if(rhs_->caller()) //right branch call refreshing
            rhs_->execute();
        else{
            lhs_cache() = lhs_->execute().get<Value_t>();
            rhs_cache() = rhs_->execute().get<Value_t>();
            std::cout<<"lhs: "<<lhs_cache()<<std::endl;
            std::cout<<"rhs: "<<rhs_cache()<<std::endl;
        }
        if(operation_==BINARY_OP::DIV && rhs_cache()==0.)
            throw std::logic_error("Division by 0 (NULL)");
        else return __calculate__();
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

Result BinaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        if(lhs_->caller()) //left branch call refreshing
            lhs_->execute(index);
        else if(rhs_->caller()) //right branch call refreshing
            rhs_->execute(index);
        else{
            lhs_cache(index) = lhs_->execute(index).get<Value_t>();
            rhs_cache(index) = rhs_->execute(index).get<Value_t>();
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