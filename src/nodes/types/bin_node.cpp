#include "bin_node.h"
#include "def.h"
#include "events_errors/exception.h"

BinaryNode::BinaryNode(const BinaryNode& other):
Node(other),
operation_(other.operation_){}

void BinaryNode::insert_back(std::shared_ptr<Node> node){
    flush_cache();
    __invalidate_type_val__();
    if(childs_.size()<2){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else std::logic_error("Invalid inserting. Prompt: Unvalailable to insert more than 2 nodes to binary node");
}

#include "aux_functions.h"
Result BinaryNode::execute() const{
    if(!(has_child(0) && has_child(1) && childs_.size()==2))
        return std::make_shared<exceptions::InvalidNumberOfArguments>(2);
    switch (operation_)
    {
        case BINARY_OP::ADD:
            return child(0)->execute()+child(1)->execute();
            break;
        case BINARY_OP::SUB:
            return child(0)->execute()-child(1)->execute();
            break;
        case BINARY_OP::MUL:
            return child(0)->execute()*child(1)->execute();
            break;
        case BINARY_OP::DIV:
            return child(0)->execute()/child(1)->execute();
            break;
        case BINARY_OP::POW:
            return child(0)->execute()^child(1)->execute();
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
    return Result();
}

#include "test/log_duration.h"

Result BinaryNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    //LOG_DURATION("Binary. Example 2");
    if(!(has_child(0) && has_child(1) && childs_.size()==2))
        return std::make_shared<exceptions::InvalidNumberOfArguments>(2);
    switch (operation_)
    {
        case BINARY_OP::ADD:
            return child(0)->execute_for_array_variables(structure)+
                child(1)->execute_for_array_variables(structure);
            break;
        case BINARY_OP::SUB:
            return child(0)->execute_for_array_variables(structure)-
                child(1)->execute_for_array_variables(structure);
            break;
        case BINARY_OP::MUL:
            return child(0)->execute_for_array_variables(structure)*
                child(1)->execute_for_array_variables(structure);
            break;
        case BINARY_OP::DIV:
            return child(0)->execute_for_array_variables(structure)/
                child(1)->execute_for_array_variables(structure);
            break;
        case BINARY_OP::POW:
            return child(0)->execute_for_array_variables(structure)^
                child(1)->execute_for_array_variables(structure);
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
    return Result();
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
    if(!has_child(0) && !has_child(1))
        return false;
    return childs_.at(0)->is_numeric() && childs_.at(1)->is_numeric();
}

bool BinaryNode::is_string() const{
    if(!has_child(0) && !has_child(1))
        return false;
    return childs_.at(0)->is_string() && childs_.at(1)->is_string();
}

bool BinaryNode::is_array() const{
    if(!has_child(0) && !has_child(1))
        return false;
    return childs_.at(0)->is_array() && childs_.at(1)->is_array();
}

TYPE_VAL BinaryNode::type_val() const{
    if(is_numeric()){
        if(is_array()) return TYPE_VAL::NUMERIC_ARRAY;   
        else return TYPE_VAL::VALUE;
    }
    else if(is_string()){
        if(is_array()) return TYPE_VAL::STRING_ARRAY;
        else return TYPE_VAL::STRING;
    }
    else if(is_array()){
        if(is_array()) return TYPE_VAL::ARRAY;
        else return TYPE_VAL::UNKNOWN;
    }
    else return TYPE_VAL::UNKNOWN;
}