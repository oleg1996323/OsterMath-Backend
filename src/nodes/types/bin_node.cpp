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
    child(0)->flush_cache();
    child(1)->flush_cache();



    if(operation_==BINARY_OP::DIV && cached_result(index).get_value()==0.)
        return std::make_shared<exceptions::DivisionZero>();
    switch (operation_)
    {
        case BINARY_OP::ADD:
        #ifdef DEBUG
            //std::cout<<"Add: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
        #endif
            if(!ErrorChecking(index).is_error())
                return child(0)->cached_result(index).get<Value_t>()+child(1)->cached_result(index).get<Value_t>();
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

#include "aux_functions.h"
Result BinaryNode::execute(){
    using namespace functions::auxiliary;
    //full calculation if child exists and are arrays
    if(has_child(0) && has_child(1) && childs_.size()==2){
        
        if(check_arguments(TYPE_VAL::NUMERIC_ARRAY,child(0),child(1))){
            if(std::dynamic_pointer_cast<ArrayNode>(child(0))->size()==
                std::dynamic_pointer_cast<ArrayNode>(child(1))->size() &&
                std::dynamic_pointer_cast<ArrayNode>(child(0))->size()!=0)
                for(size_t i = 0;i < std::dynamic_pointer_cast<ArrayNode>(child(0))->size();++i){

                }
        }
        else if(functions::auxiliary::check_arguments(TYPE_VAL::VALUE,child(0),child(1)))
            cache_ = execute(0);
        else{
            cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("numeric array/value");
        }
    }
    else{
        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("numeric array/value");
    }
    return cache_;
}

Result BinaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(child(0) && child(1)){
        if(child(0)->caller() || child(1)->caller())
            cached_result(index) = child(0)->execute(index);
        else if(child(1)->caller())
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