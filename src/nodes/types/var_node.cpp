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
    flush_cache();
    if(!is_not_cycled())
        cache_=std::make_shared<exceptions::CyclicReference>(var_->name());
    if(has_childs())
        return childs_.at(0)->execute();
    else return Node::execute();
}

inline Result VariableNode::cached_result() const{
    if(!is_not_cycled())
        cache_=std::make_shared<exceptions::CyclicReference>(var_->name());
    if(has_childs()){
        return childs_.at(0)->cached_result();
    }
    else return Node::execute();
}

void VariableNode::flush_cache() const{
    cache_.reset();
}

bool VariableNode::is_empty() const{
    return childs_.size()==0;
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

#include "test/log_duration.h"
Result VariableNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    //LOG_DURATION("get variable value");
    using namespace ::functions::auxiliary;
    if(structure.contains(this)){
        const Node* found_node;
        {
            //LOG_DURATION("first_node_not_var_by_ids");
            found_node = first_node_not_var_by_ids(this,structure.at(this).sz_depth_measure);
        }
        // if(!found_node)
        //     throw std::runtime_error(std::string("Not found child node in array type variable ")+this->var_->name());
        // if(found_node->type_val()!=TYPE_VAL::VALUE)
        //     throw std::runtime_error(std::string("Invalid type value of returned child node in array type variable ")+this->var_->name());
        //std::cout<<"Var \""<< variable()->name()<<"\" value: "<<found_node->execute()<<std::endl;
        return found_node->execute();
    }
    else
        return execute();
}