#include "bin_node.h"
#include "def.h"
#include "exception/exception.h"

void BinaryNode::insert(std::shared_ptr<Node> node){
    if(childs_.size()<2){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else std::logic_error("Invalid inserting. Prompt: Unvalailable to insert vjre than 2 nodes to binary node");
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
            throw exceptions::DivisionZero();
        return __calculate__(index);
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

void BinaryNode::print_text(std::ostream& stream) const{
    childs_.at(0)->print_text(stream);
    stream<<(char)operation_;
    childs_.at(1)->print_text(stream);
}

void BinaryNode::print_result(std::ostream& stream) const{
    stream<<const_cast<BinaryNode*>(this)->execute();
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