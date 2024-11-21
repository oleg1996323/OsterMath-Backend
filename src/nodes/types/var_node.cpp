#include "types.h"
#include "var_node.h"
#include "events_errors/exception.h"
#include "aux_functions.h"

VariableNode::VariableNode(VariableBase* variable):Node(),
    var_(variable){}

const VariableBase* VariableNode::variable() const noexcept{
    return var_;
}

VariableBase* VariableNode::variable() noexcept{
    return var_;
}

Result VariableNode::execute() const{
    if(has_childs())
        if(!refer_to(var_->name()))
            return childs_.at(0)->execute();
        else {
            throw exceptions::CyclicReference(var_->name());
            return 0;
        }
    else return 0;
}

Result VariableNode::execute(const std::vector<std::shared_ptr<VariableNode>>& variables, const std::vector<size_t>& order) const{
    if(std::count(variables.begin(),variables.end(),[this](std::shared_ptr<VariableNode> var){
        var.get() == this;
    })!=0){
        Node* child = nullptr;
        if((child = functions::auxiliary::first_node_not_var(this))){
            if(!order.empty() && this->type_val()&TYPE_VAL::ARRAY){
                if(!child->execute().is_error()){

                }
            }
        }
    }
    return ;
}

inline Result VariableNode::cached_result(){
    if(has_childs()){
        if(!refer_to(var_->name()))
            return childs_.at(0)->cached_result();
        else {
            return std::make_shared<exceptions::CyclicReference>(var_->name());
        }
    }
    else return std::monostate();
}
inline Result VariableNode::cached_result(size_t index){
    if(has_childs()){
        if(!refer_to(var_->name()))
            return childs_.at(0)->cached_result(index);
        else {
            return std::make_shared<exceptions::CyclicReference>(var_->name());
        }
    }
    else return std::monostate();
}

bool VariableNode::is_numeric() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_numeric();
    }
    else return false;
}

bool VariableNode::is_string() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_string();
    }
    else return false;
}

bool VariableNode::is_array() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_array();
    }
    else return false;
}

void VariableNode::print_text(std::ostream& stream) const{
    stream<<"VAR(!('"<<var_->get_data_base_name()<<"\')#"<<var_->name()<<")";
}

void VariableNode::print_result(std::ostream& stream) const{
    if(childs_.size()==1)
        childs_.at(0)->print_result(stream);
}

void VariableNode::insert_back(std::shared_ptr<Node> node){
    if(node){
        if(childs_.size()<1){
            childs_.push_back(node);
            node->add_parent(this);
        }
        else {
            if(node->type()!=NODE_TYPE::VARIABLE)
                node->parents().clear();
            childs_.at(0)=node;
            node->add_parent(this);
        }
    }
}