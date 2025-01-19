#include "range_node.h"
#include "def.h"
#include <memory>

RangeOperationNode::RangeOperationNode(const RangeOperationNode& other):
AbstractNode(other),
cache_(other.cache_),
sz_iteration(other.sz_iteration),
operation_(other.operation_)
{
    if(this!=&other){
        rel_mng_->copy_node(this,&other);
    }
}

#include "types.h"
#include "test/log_duration.h"

NODE_TYPE RangeOperationNode::type() const{
    return NODE_TYPE::RANGEOP;
}

RangeOperationNode::~RangeOperationNode(){
    std::cout<<"RangeOperationNode deleted: "<<this<<std::endl;
    rel_mng_->delete_node(this);
}

Result RangeOperationNode::execute() const{
    using namespace ::functions::auxiliary;
    flush_cache();
    if(!has_expression()){
        cache_ =  std::make_shared<exceptions::Exception>("Missing expression at range node");
        return cache_;
    }
    if(has_cyclic_references(this)){
        cache_=std::make_shared<exceptions::CyclicReference>("");
        return cache_;
    }
    std::set<const VariableNode*> ref_vars = define_array_type_variables();
    
    {
        LOG_DURATION("Checking arrays");
        for(const VariableNode* var_id:ref_vars){
            if(var_id && ((is_filled_rectangle_array_node_of_type(TYPE_VAL::NUMERIC_ARRAY,var_id)) || check_arguments(TYPE_VAL::VALUE,var_id)))
                continue;
            else{
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(std::string()+
                "variable with numeric value or filled numeric rectangle array");
                return cache_;
            }
        }
    }
    execute_for_array_variables_t structure;
    if(!check_variables_sizes_and_define_size_iteration(0,structure)){
        return cache_;
    }
    if(structure.empty() || !std::all_of(structure.begin(),structure.end(),[this](const auto& str){
        if(str.second.sz_depth_measure.dimensions() != str.second.order.size()){
            cache_ = std::make_shared<exceptions::Exception>(std::string("Variable's \"")+str.first->variable()->name()+"\" array has "+
                std::to_string(str.second.sz_depth_measure.dimensions())+" dimension size. Expected: "+std::to_string(str.second.order.size()));
            return false;
        }
        return true;
    }))
        return false;
        
    return execute_for_array_variables(structure);
}

#include "empty_node.h"
void RangeOperationNode::print_text(std::ostream& stream) const{
    if(operation_==RANGE_OP::PROD)
        stream<<"product_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    if(has_expression())
        get_expression()->print_text(stream);
    else {
        EmptyNode node;
        node.print_text(stream);
    }
    stream<<")";
}

RANGE_OP RangeOperationNode::operation() const{
    return operation_;
}

void RangeOperationNode::print_result(std::ostream& stream) const{
    stream<<cached_result();
}

bool RangeOperationNode::is_numeric() const{
    if(has_expression())
        return get_expression()->is_numeric();
    else return false;
}

bool RangeOperationNode::is_string() const{
    if(has_expression())
        return get_expression()->is_string();
    else return false;
}

bool RangeOperationNode::is_array() const{
    return false;
}

bool RangeOperationNode::is_empty() const{
    return false;
}

#include "aux_functions.h"

bool RangeOperationNode::check_variables_sizes_and_define_size_iteration(size_t depth,
                                execute_for_array_variables_t& structure) const{
    using namespace functions::auxiliary;
    if(!has_expression()){
        cache_ =  std::make_shared<exceptions::Exception>("Missing expression at range node");
        return false;
    }
    std::set<const VariableNode*> arr_vars = define_array_type_variables();
    if(arr_vars.empty()){
        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(std::string("at least 1 rectangle numeric array-type or value-type variable ")+
                                    "at range operator "+std::to_string(depth+1));
        return false;
    }
    for(const VariableNode* var:arr_vars){
        if(!is_rectangle_array_node(var)){
            cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("rectangle numeric array-type or value-type variable");
            return false;
        }
    }
    std::optional<size_t> sz_tmp;
    {
        if(var_ids_.contains((*arr_vars.begin())) && var_ids_.at((*arr_vars.begin())).has_value()){
            SizeDepthMeasure first = init_sz_depth_measure(*arr_vars.begin());
            if(first.dimensions()>var_ids_.at((*arr_vars.begin())).value()-1)
                sz_tmp = init_sz_depth_measure(*arr_vars.begin()).size(var_ids_.at((*arr_vars.begin())).value()-1);
        }
        if(!sz_tmp.has_value()){
            if(var_ids_.contains((*arr_vars.begin()))){
                if(var_ids_.at((*arr_vars.begin())).has_value())
                    cache_ = std::make_shared<exceptions::Exception>(std::string("Variable's ")+(*arr_vars.begin())->variable()->name()+" array dimension is lesser than indicated index "+
                                    std::to_string(var_ids_.at((*arr_vars.begin())).value()));
                else
                    cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+(*arr_vars.begin())->variable()->name()+
                                                        "\nat "+std::to_string(depth+1)+" range operator.");
            }
            else{
                    cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+(*arr_vars.begin())->variable()->name()+
                                            "\nat "+std::to_string(depth+1)+" range operator.");
            }
            return false;
        }
        else if(sz_tmp.value()==0){
            cache_ = std::make_shared<exceptions::Exception>("Variable's "+(*arr_vars.begin())->variable()->name()+" array is empty.");
            return false;
        }
    }
    for(const VariableNode* var:arr_vars){
        if(!this->var_ids_.contains(var)){
            cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined indexes for variable ")+var->variable()->name()+".");
            return false;
        }
        else{//check indexes repetition std::count()==1 && structure.find(var)->order.size()>depth && 
                //structure.find(var)->order.at(depth)==this->var_ids_.find(var)->order_id.value()-1
            if(!var_ids_.at(var).has_value()){
                cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+var->variable()->name()+
                                                                    "\nat "+std::to_string(depth+1)+" range operator.");
                return false;
            }
            else{
                if(structure.contains(var))
                    structure.at(var).sz_depth_measure = init_sz_depth_measure(var);
                else structure[var] = ThroughVarStruct({init_sz_depth_measure(var), {}});
                if(structure.at(var).sz_depth_measure.dimensions()<=var_ids_.at(var).value()-1)
                {
                    if(structure.at(var).sz_depth_measure.dimensions()==0)
                        cache_ = std::make_shared<exceptions::Exception>("Variable's "+var->variable()->name()+" array is empty.");
                    else
                        cache_ = std::make_shared<exceptions::Exception>(std::string("Variable's ")+var->variable()->name()+" array dimension is lesser than indicated index "+
                                            std::to_string(var_ids_.at(var).value()));
                    return false;
                }
                if(sz_tmp.value()==structure.at(var).sz_depth_measure.size(var_ids_.at(var).value()-1)){
                    //check indexes repetition 
                    size_t cnt = std::count(structure.at(var).order.begin(),structure.at(var).order.end(),var_ids_.at(var).value()-1);
                    if(cnt==1){
                        if(!(structure.at(var).order.size()>depth || 
                            structure.at(var).order.at(depth)==var_ids_.at(var).value()-1))
                        {
                            this->cache_ = std::make_shared<exceptions::Exception>(std::string("Redefinition of index ")+
                                std::to_string(var_ids_.at(var).value()-1)+" for variable "+var->variable()->name());
                            return false;
                        }
                    }
                    else if(cnt == 0){
                        structure.at(var).order.push_back(var_ids_.at(var).value()-1);
                    }
                    else return false;
                }
                else{
                    cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(std::string("Not equal array sizes of variables."));
                    return false;
                }
            }
        }
    }
    sz_iteration = sz_tmp.value();
    std::set<const AbstractNode*> range_nodes = define_range_node_range_nodes();
    if(range_nodes.empty())
        return true;
    else{
        if(!std::all_of(range_nodes.begin(),range_nodes.end(),[&structure,depth](const AbstractNode* node){
            return static_cast<const RangeOperationNode*>(node)->
            check_variables_sizes_and_define_size_iteration(depth+1,structure);
        })){
            auto found = std::find_if(range_nodes.begin(),range_nodes.end(),[](const AbstractNode* node)->bool
            {
                return node->cached_result().is_error();
            });
            if(found!=range_nodes.end())
                cache_ = (*found)->cached_result();
            return false;
        }
    }
    return true;
}

std::set<const VariableNode*> RangeOperationNode::define_range_node_array_type_variables() const{
    std::set<const VariableNode*> ref_vars = get_expression()->refer_to_vars();
    { //filtering this range node variables
        std::set<const AbstractNode*> ref_range_nodes = get_expression()->refer_to_node_of_type(NODE_TYPE::RANGEOP);
        if(!ref_range_nodes.empty())
        {
            std::set<const VariableNode*> all_refered_vars_by_child_range_node;
            std::set<const VariableNode*> diff;
            for(const auto& range_node:ref_range_nodes)
                all_refered_vars_by_child_range_node.merge(range_node->refer_to_vars());
            std::set_difference(ref_vars.begin(),
                                ref_vars.end(),
                                all_refered_vars_by_child_range_node.begin(),
                                all_refered_vars_by_child_range_node.end(),
                                std::inserter(diff,diff.end()),
                                [](const VariableNode* lhs,const VariableNode* rhs)
                                {return lhs<rhs;});
            std::erase_if(diff,[](const VariableNode* var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
            });
            ref_vars=diff;
        }
        else{
            std::erase_if(ref_vars,[](const VariableNode* var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
            });
        }
    }
    return ref_vars;
}

std::set<const AbstractNode*> RangeOperationNode::define_range_node_range_nodes() const{
    std::set<const AbstractNode*> result;
    { //filtering this range node variables
        std::set<const AbstractNode*> ref_range_nodes = refer_to_node_of_type(NODE_TYPE::RANGEOP);
        if(!ref_range_nodes.empty())
        {
            std::set<const AbstractNode*> all_refered_range_nodes_by_child_range_node;
            std::set<const AbstractNode*> diff;
            for(const AbstractNode* range_node:ref_range_nodes)
                all_refered_range_nodes_by_child_range_node.merge(static_cast<const RangeOperationNode*>(range_node)->
                                                    refer_to_node_of_type(NODE_TYPE::RANGEOP));
            std::set_difference(ref_range_nodes.begin(),
                                ref_range_nodes.end(),
                                all_refered_range_nodes_by_child_range_node.begin(),
                                all_refered_range_nodes_by_child_range_node.end(),
                                std::inserter(diff,diff.end()));
            result.insert(diff.begin(),diff.end());
        }
    }
    return result;
}

std::set<const VariableNode*> RangeOperationNode::define_array_type_variables() const{
    std::set<const VariableNode*> ref_vars = get_expression()->refer_to_vars();
    std::erase_if(ref_vars,[](const VariableNode* var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
    });
    return ref_vars;
}

#include "test/log_duration.h"

Result RangeOperationNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    using namespace ::functions::auxiliary;    
    if(operation_==RANGE_OP::SUM)
        cache_ =  0.;
    else if(operation_==RANGE_OP::PROD)
        cache_ = 1.;

    for(size_t iter = 0;iter<sz_iteration;++iter) //add defined size of dimension size variable
    {
        for(auto& [var,order]:var_ids_){
            structure.at(var).sz_depth_measure.lock(order.value()-1);
            //std::cout<<"Locked var \""<< id.var_node->variable()->name()<<"\" at "<<var_ids_.find(id.var_node)->order_id.value()-1<<std::endl;
            // std::cout<<"Iterator at depth 0 for var \""<< id.var_node->variable()->name()<<"\": "<<id.sz_depth_measure.current_iterator(0)<<std::endl;
            // if(id.sz_depth_measure.dimensions()==2)
            //     std::cout<<"Iterator at depth 1 for var \""<< id.var_node->variable()->name()<<"\": "<<id.sz_depth_measure.current_iterator(1)<<std::endl;
        }
        
        if(operation_==RANGE_OP::SUM)
            cache_ += get_expression()->execute_for_array_variables(structure);
        else if(operation_==RANGE_OP::PROD)
            cache_ *= get_expression()->execute_for_array_variables(structure);

        //std::cout<<"Cache: "<<cache_<<std::endl;
        if(cache_.is_error())
            return cache_;
        for(auto& [var,order]:var_ids_){
            structure.at(var).sz_depth_measure.unlock(order.value()-1);
            ++structure.at(var).sz_depth_measure;
        }
    }
    for(auto& [var,order]:var_ids_){
        structure.at(var).sz_depth_measure.reset_iterator(order.value()-1);}
    return cache_;
}