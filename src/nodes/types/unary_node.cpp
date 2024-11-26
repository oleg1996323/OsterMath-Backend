#include "unary_node.h"
#include "def.h"

void UnaryNode::print_text(std::ostream& stream) const{
    if(operation_==UNARY_OP::ADD){
        stream<<"+";
        childs_.at(0)->print_text(stream);
    }
    else if(operation_==UNARY_OP::SUB){
        stream<<"-";
        childs_.at(0)->print_text(stream);
    }
    else if(operation_==UNARY_OP::PARENS){
        stream<<"(";
        childs_.at(0)->print_text(stream);
        stream<<")";
    }
    else if(operation_==UNARY_OP::NOTHING){
        childs_.at(0)->print_text(stream);
    }
    else stream<<"";
}

void UnaryNode::print_result(std::ostream& stream) const{
    stream<<const_cast<UnaryNode*>(this)->execute();
}

void UnaryNode::insert_back(std::shared_ptr<Node> node){
    assert(childs_.size()==0);
    childs_.push_back(node);
    node->add_parent(this);
}

Result UnaryNode::execute() const{
    switch (operation_)
        {
        case UNARY_OP::ADD:
            return childs_.at(0)->execute();
            break;
        case UNARY_OP::SUB:
            return (-1)*(childs_.at(0)->execute().get<Value_t>());
            break;
        case UNARY_OP::PARENS:
            return childs_.at(0)->execute();
            break;
        case UNARY_OP::NOTHING:
            return childs_.at(0)->execute();
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}

bool UnaryNode::is_numeric() const{
    return childs_.at(0)->is_numeric();
}

bool UnaryNode::is_string() const{
    return childs_.at(0)->is_string();
}

bool UnaryNode::is_array() const{
    return childs_.at(0)->is_array();
}

UNARY_OP UnaryNode::operation() const{
    return operation_;
}

Result UnaryNode::execute_for_array_variables(const std::vector<size_t>& variables) const{
    switch (operation_)
        {
        case UNARY_OP::ADD:
            return child()->execute_for_array_variables(variables);
            break;
        case UNARY_OP::SUB:
            return (-1)*child()->execute_for_array_variables(variables);
            break;
        case UNARY_OP::PARENS:
            return child()->execute_for_array_variables(variables);
            break;
        case UNARY_OP::NOTHING:
            return child()->execute_for_array_variables(variables);
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}