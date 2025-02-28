#include "unary_node.h"
#include "def.h"
#include "node_manager.h"

UnaryNode::~UnaryNode(){
    //std::cout<<"UnaryNode deleted: "<<this<<std::endl;
    rel_mng_->delete_node(this);
}

NODE_TYPE UnaryNode::type() const{
    return NODE_TYPE::UNARY;
}

void UnaryNode::print_text(std::ostream& stream) const{
    if(operation_==UNARY_OP::ADD){
        stream<<"+";
        childs().at(0)->print_text(stream);
    }
    else if(operation_==UNARY_OP::SUB){
        stream<<"-";
        childs().at(0)->print_text(stream);
    }
    else if(operation_==UNARY_OP::PARENS){
        stream<<"(";
        childs().at(0)->print_text(stream);
        stream<<")";
    }
    else if(operation_==UNARY_OP::NOTHING){
        childs().at(0)->print_text(stream);
    }
    else stream<<"";
}

void UnaryNode::print_result(std::ostream& stream) const{
    stream<<execute();
}

Result UnaryNode::execute() const{
    switch (operation_)
        {
        case UNARY_OP::ADD:
            return childs().at(0)->execute();
            break;
        case UNARY_OP::SUB:
            return (-1)*(childs().at(0)->execute().get<Value_t>());
            break;
        case UNARY_OP::PARENS:
            return childs().at(0)->execute();
            break;
        case UNARY_OP::NOTHING:
            return childs().at(0)->execute();
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}

bool UnaryNode::is_numeric() const{
    if(!has_child(0))
        return false;
    return childs().at(0)->is_numeric();
}

bool UnaryNode::is_string() const{
    if(!has_child(0))
        return false;
    return childs().at(0)->is_string();
}

bool UnaryNode::is_array() const{
    if(!has_child(0))
        return false;
    return childs().at(0)->is_array();
}

bool UnaryNode::is_empty() const{
    return false;
}

UNARY_OP UnaryNode::operation() const{
    return operation_;
}

Result UnaryNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    switch (operation_)
    {
    case UNARY_OP::ADD:
        return child()->execute_for_array_variables(structure);
        break;
    case UNARY_OP::SUB:
        return (-1)*child()->execute_for_array_variables(structure);
        break;
    case UNARY_OP::PARENS:
        return child()->execute_for_array_variables(structure);
        break;
    case UNARY_OP::NOTHING:
        return child()->execute_for_array_variables(structure);
    default:
        throw std::invalid_argument("Unknown type of unary expression");
        break;
    }
}

TYPE_VAL UnaryNode::type_val() const{
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