#include "var_node.h"
#include "types.h"

std::ostream& VariableNode::print_text(std::ostream& stream) const{
    stream<<"VAR(!('"<<var_->get_data_base_name()<<"\')#"<<var_->name()<<"\'="<<!childs_.empty()?child(0)->print_text():"NaN";
    return stream;
}

VariableNode::VariableNode(VariableBase* variable):
    var_(variable){}

const VariableBase* VariableNode::variable() const{
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

VariableBase* VariableNode::variable(){
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

void VariableNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        refresh_parent_links();
        for(auto parent:parents_){
            parent->refresh();
        }
        caller_ = false;
    }
}

Value_t VariableNode::execute(){
    if(var_){
        if(var_->is_value()){
            return var_->get<Value_t>();
        }
        else if(var_->is_arithmetic_tree()){
            return var_->get<ArithmeticTree>().execute();
        }
        else if(var_->is_undef())
            return 0.;
        else
        throw std::invalid_argument("Invalid type of variable: not calculable");
    }
    else throw std::runtime_error("Uninitialized variable");
}

Value_t VariableNode::execute(size_t index){
    if(var_){
        if(var_->is_array()){
            const Array_val& val = var_->get<Array_t>().at(index);
            if(val.is_expression())
                return val.get<ArithmeticTree>().execute();
            else if(val.is_value())
                return val.get<Value_t>();
            else throw std::invalid_argument("Invalid type of array item");
        }
        else if(var_->is_numeric()){
            if(var_->is_value())
                return var_->get<Value_t>();
            else if(var_->is_arithmetic_tree())
                return var_->get<ArithmeticTree>().value();
            else throw std::invalid_argument("Invalid type of variable");
        }
        throw std::invalid_argument("Invalid type of variable: not array or numeric");
    }
    else throw std::runtime_error("Uninitialized variable");

}

void VariableNode::refresh_parent_links() const{
    for(auto iterator_node = parents_.begin();iterator_node!=parents_.end();++iterator_node)
        if(!(*iterator_node))
            parents_.erase(iterator_node);
}

bool VariableNode::is_numeric() const{
    if(childs_.size()==1){
        childs_.at(0)->is_numeric();
    }
    else return false;
}

bool VariableNode::is_string() const{
    if(childs_.size()==1){
        childs_.at(0)->is_string();
    }
    else return false;
}

bool VariableNode::is_array() const{
    if(childs_.size()==1){
        childs_.at(0)->is_array();
    }
    else return false;
}