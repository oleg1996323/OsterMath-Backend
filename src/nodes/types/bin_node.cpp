#include "bin_node.h"
#include "def.h"
#include "events_errors/exception.h"

BinaryNode::BinaryNode(const BinaryNode& other):
Node(other),
operation_(other.operation_){}

void BinaryNode::insert_back(std::shared_ptr<Node> node){
    if(childs_.size()<2){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else std::logic_error("Invalid inserting. Prompt: Unvalailable to insert more than 2 nodes to binary node");
}

Result BinaryNode::__calculate__(){
    return __calculate__(0);
}

Result BinaryNode::__calculate__(size_t index){
    if(!rhs_cache(index).is_value() || !lhs_cache(index).is_value())
        return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");

    if(operation_==BINARY_OP::DIV && rhs_cache(index).get<Value_t>()==0.)
        return std::make_shared<exceptions::DivisionZero>();
    switch (operation_)
    {
        case BINARY_OP::ADD:
        #ifdef DEBUG
            //std::cout<<"Add: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return lhs_cache(index).get<Value_t>()+rhs_cache(index).get<Value_t>();
            break;
        case BINARY_OP::SUB:
        #ifdef DEBUG
            //std::cout<<"Sub: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return lhs_cache(index).get<Value_t>()-rhs_cache(index).get<Value_t>();
            break;
        case BINARY_OP::MUL:
        #ifdef DEBUG
            //std::cout<<"Mul: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return lhs_cache(index).get<Value_t>()*rhs_cache(index).get<Value_t>();
            break;
        case BINARY_OP::DIV:
        #ifdef DEBUG
            //std::cout<<"Div: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return lhs_cache(index).get<Value_t>()/rhs_cache(index).get<Value_t>();
            break;
        case BINARY_OP::POW:
        #ifdef DEBUG
            //std::cout<<"Pow: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return pow(lhs_cache(index).get<Value_t>(),rhs_cache(index).get<Value_t>());
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
    return Result();
}

Result BinaryNode::execute(){
    //full calculation if child exists and are arrays
    cache_ = execute(0);
    return cache_;
}

Result BinaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(child(0) && child(1)){
        if(child(0)->caller()) //left branch call refreshing
            lhs_cache(index) = child(0)->execute(index);
        else if(child(1)->caller()) //right branch call refreshing
            rhs_cache(index) = child(1)->execute(index);
        else{
            lhs_cache(index) = child(0)->execute(index);
            rhs_cache(index) = child(1)->execute(index);
        }
        return __calculate__(index);
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

void BinaryNode::print_text(std::ostream& stream) const{
    if(has_child(0))
        childs_.at(0)->print_text(stream);
    else{
        Node node;
        node.print_text(stream);
    }
    stream<<(char)operation_;
    if(has_child(1))
        childs_.at(1)->print_text(stream);
    else {
        Node node;
        node.print_text(stream);
    }
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