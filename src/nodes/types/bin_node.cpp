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

inline bool BinaryNode::IsError(size_t index){
    // if(!(has_child(0) && has_child(1) && childs_.size()==2)){
    //     cache_ = std::make_shared<exceptions::InvalidNumberOfArguments>(2);
    //     return true;
    // }
    // if(child(0)->execute().is_error()){
    //     cache_ = child(0)->cached_result();
    //     return true;
    // }
    // if(child(1)->execute().is_error()){
    //     cache_ = child(1)->cached_result();
    //     return true;
    // }
    // // if(!child(0)->cached_result(index).is_value() || !child(1)->cached_result(index).is_value()){
    // //     cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
    // //     return true;
    // // }
    // if(operation_==BINARY_OP::DIV && child(1)->cached_result(index).get_value()==0.){
    //     cache_ = std::make_shared<exceptions::DivisionZero>();
    //     return true;
    // }
    // return false;
}

#include "aux_functions.h"
Result BinaryNode::execute() const{
    using namespace functions::auxiliary;    
    if(check_arguments(TYPE_VAL::NUMERIC_ARRAY,child(0),child(1))){
        if(std::dynamic_pointer_cast<ArrayNode>(child(0))->size()==
            std::dynamic_pointer_cast<ArrayNode>(child(1))->size()){
            Value_t result;
            for(size_t i = 0;i < std::dynamic_pointer_cast<ArrayNode>(child(0))->size();++i){
                result =+ execute(i).get_value();
            }
        }
    }
    else if(functions::auxiliary::check_arguments(TYPE_VAL::VALUE,child(0),child(1)))
        return execute();
    else
        return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric array/value");

    flush_cache();
    if(!(has_child(0) && has_child(1) && childs_.size()==2))
        return std::make_shared<exceptions::InvalidNumberOfArguments>(2);
    if(child(0)->execute().is_error())
        return child(0)->cached_result();
    if(child(1)->execute().is_error())
        return child(1)->cached_result();
    // if(!child(0)->cached_result(index).is_value() || !child(1)->cached_result(index).is_value()){
    //     cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
    //     return true;
    // }
    if(operation_==BINARY_OP::DIV && child(1)->cached_result(index).get_value()==0.)
        return std::make_shared<exceptions::DivisionZero>();
    switch (operation_)
    {
        case BINARY_OP::ADD:
            return child(0)->cached_result(index).get<Value_t>()+child(1)->cached_result(index).get<Value_t>();
            break;
        case BINARY_OP::SUB:
            return child(0)->cached_result(index).get<Value_t>()-child(1)->cached_result(index).get<Value_t>();
            break;
        case BINARY_OP::MUL:
            return child(0)->cached_result(index).get<Value_t>()*child(1)->cached_result(index).get<Value_t>();
            break;
        case BINARY_OP::DIV:
            return child(0)->cached_result(index).get<Value_t>()/child(1)->cached_result(index).get<Value_t>();
            break;
        case BINARY_OP::POW:
            return pow(child(0)->cached_result(index).get<Value_t>(),child(1)->cached_result(index).get<Value_t>());
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
    return Result();
}

Result BinaryNode::execute(const std::vector<std::shared_ptr<VariableNode>>& variables, const std::vector<size_t>& order) const{
    
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
    stream<<execute();
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