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

Result UnaryNode::__calculate__() const{
    return __calculate__(0);
}

Result UnaryNode::__calculate__(size_t index) const{
    switch (operation_)
        {
        case UNARY_OP::ADD:
            return childs_.at(0)->execute(index);
            break;
        case UNARY_OP::SUB:
            return (-1)*(childs_.at(0)->execute(index).get<Value_t>());
            break;
        case UNARY_OP::PARENS:
            return childs_.at(0)->execute(index);
            break;
        case UNARY_OP::NOTHING:
            return childs_.at(0)->execute(index);
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}

Result UnaryNode::execute() const{
    return execute(0);
}

Result UnaryNode::execute(size_t index) const{
    using namespace boost::multiprecision;
    if(!childs_.empty()){
        return __calculate__(index);
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
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