#include "range_node.h"
#include "def.h"
#include <memory>

RangeOperationNode::RangeOperationNode(const RangeOperationNode& other):
Node(other),
cache_(other.cache_),
sz_iteration(other.sz_iteration),
operation_(other.operation_)
{
    set_expression(other.get_expression());
}

#include "types.h"

Result RangeOperationNode::execute() const{
    using namespace ::functions::auxiliary;
    if(!has_expression()){
        cache_ =  std::make_shared<exceptions::Exception>("Missing expression at range node");
        return cache_;
    }
    std::set<std::shared_ptr<VariableNode>> ref_vars = define_array_type_variables();
    
    if(!std::all_of(ref_vars.begin(),ref_vars.end(),[&](const std::shared_ptr<Node>& var_id){
        return var_id && ((check_arguments(TYPE_VAL::NUMERIC_ARRAY,var_id) && is_rectangle_array_node(var_id)) || check_arguments(TYPE_VAL::VALUE,var_id));
    })){
        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(std::string()+
        "variable with numeric value or rectangle numeric array");
        return cache_;
    }
    std::set<ThroughVarStruct,ThroughVarStruct::Comparator> structure;
    if(!check_variables_sizes_and_define_size_iteration(0,structure)){
        return cache_;
    }
    std::vector<size_t> range_node_execute_struct;
    return execute_for_array_variables(range_node_execute_struct,structure);
}

void RangeOperationNode::print_text(std::ostream& stream) const{
    if(operation_==RANGE_OP::PROD)
        stream<<"product_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    if(has_expression())
        get_expression()->print_text(stream);
    else {
        Node node;
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

#include "aux_functions.h"

bool RangeOperationNode::check_variables_sizes_and_define_size_iteration(size_t depth,
                                std::set<ThroughVarStruct,ThroughVarStruct::Comparator>& structure) const{
    using namespace functions::auxiliary;
    std::set<std::shared_ptr<VariableNode>> arr_vars = define_range_node_array_type_variables();
    if(arr_vars.empty() || define_array_type_variables().empty()){
        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("at least 1 rectangle numeric array-type or value-type variable");
        return false;
    }
    if(!std::all_of(arr_vars.begin(),arr_vars.end(),[](const std::shared_ptr<VariableNode>& var){
        return is_rectangle_array_node(var);
    })){
        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("rectangle numeric array-type or value-type variable");
        return false;
    }
    else{
        std::optional<size_t> sz_tmp;
        {
            auto found = this->var_ids_.find(*arr_vars.begin());
            if(found->order_id.has_value())
                sz_tmp = init_sz_depth_measure(*arr_vars.begin()).size(found->order_id.value()-1);
        }
        if(std::all_of(arr_vars.begin(),arr_vars.end(),[](const std::shared_ptr<VariableNode>& var){
            return init_sz_depth_measure(var).dimensions()==1;
        }) && equal_morphology_nodes(arr_vars)){
            std::for_each(arr_vars.begin(),arr_vars.end(),[&structure, &arr_vars,depth,this](const std::shared_ptr<VariableNode>& var){
                if(structure.contains(var))
                    structure.find(var)->sz_depth_measure = init_sz_depth_measure(*arr_vars.begin());
                else structure.insert(ThroughVarStruct({init_sz_depth_measure(*arr_vars.begin()), var,{}}));
            });
            //order_id may not contains value
            sz_iteration = structure.begin()->sz_depth_measure.size(0);
        }
        else if(std::all_of(arr_vars.begin(),arr_vars.end(),[this,&sz_tmp, &structure,&arr_vars, depth](const std::shared_ptr<VariableNode>& var){
            if(!this->var_ids_.contains(var)){
                cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined indexes for variable ")+var->variable()->name()+".");
                return false;
            }
            else{//check indexes repetition std::count()==1 && structure.find(var)->order.size()>depth && 
                    //structure.find(var)->order.at(depth)==this->var_ids_.find(var)->order_id.value()-1
                std::set<VariableNodeIndex, VariableNodeIndex::Comparator>::iterator found_var_id = this->var_ids_.find(var);
                if(!sz_tmp.has_value()){
                    cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+(*arr_vars.begin())->variable()->name()+
                                                                        "\nat "+std::to_string(depth+1)+" range operator.");
                    return false;
                }
                else if(!found_var_id->order_id.has_value()){
                    cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+var->variable()->name()+
                                                                        "\nat "+std::to_string(depth+1)+" range operator.");
                    return false;
                }
                else{
                    std::set<ThroughVarStruct, ThroughVarStruct::Comparator>::iterator found_structure;
                    if(structure.contains(var)){
                        found_structure = structure.find(var);
                        found_structure->sz_depth_measure = init_sz_depth_measure(*arr_vars.begin());
                    }
                    else found_structure = structure.insert(ThroughVarStruct({init_sz_depth_measure(*arr_vars.begin()), var,{}})).first;
                    if(sz_tmp.value()==found_structure->sz_depth_measure.size(found_var_id->order_id.value()-1)){
                        //check indexes repetition 
                        auto found_structure = structure.find(var);
                        size_t cnt = std::count(found_structure->order.begin(),found_structure->order.end(),found_var_id->order_id.value()-1);
                        if(cnt==1){
                            if(found_structure->order.size()>depth && 
                                found_structure->order.at(depth)==found_var_id->order_id.value()-1)
                                return true;
                            else{
                                this->cache_ = std::make_shared<exceptions::Exception>(std::string("Redefinition of index ")+
                                    std::to_string(found_var_id->order_id.value()-1)+" for variable "+var->variable()->name());
                                return false;
                            }
                        }
                        else if(cnt == 0){
                            found_structure->order.push_back(found_var_id->order_id.value()-1);
                        }
                        else return false;
                        return true;
                    }
                    else{
                        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(std::string("Not equal array sizes of variables."));
                        return false;
                    }
                }
            }
        })){
            if(!sz_tmp.has_value()){
                cache_ = std::make_shared<exceptions::Exception>(std::string("Not defined index for variable ")+(*arr_vars.begin())->variable()->name()+
                                                                    "\nat "+std::to_string(depth+1)+" range operator.");
                return false;
            }
            else 
                sz_iteration = sz_tmp.value();
        }
        else{
            return false;
        }
    }
    std::set<std::shared_ptr<Node>> range_nodes = define_range_node_range_nodes();
    if(range_nodes.empty())
        return true;
    else return std::all_of(range_nodes.begin(),range_nodes.end(),[&structure,depth](const std::shared_ptr<Node>& node){
        return std::dynamic_pointer_cast<RangeOperationNode>(node)->
        check_variables_sizes_and_define_size_iteration(depth+1,structure);
    });

    return true;
}

std::set<std::shared_ptr<VariableNode>> RangeOperationNode::define_range_node_array_type_variables() const{
    std::set<std::shared_ptr<VariableNode>> ref_vars = get_expression()->refer_to_vars();
    { //filtering this range node variables
        std::set<std::shared_ptr<Node>> ref_range_nodes = get_expression()->refer_to_node_of_type(NODE_TYPE::RANGEOP);
        if(!ref_range_nodes.empty())
        {
            std::set<std::shared_ptr<VariableNode>> all_refered_vars_by_child_range_node;
            std::set<std::shared_ptr<VariableNode>> diff;
            for(const auto& range_node:ref_range_nodes)
                all_refered_vars_by_child_range_node.merge(range_node->refer_to_vars());
            std::set_difference(all_refered_vars_by_child_range_node.begin(),
                                all_refered_vars_by_child_range_node.end(),
                                ref_vars.begin(),
                                ref_vars.end(),
                                std::inserter(diff,diff.end()),
                                [](const std::shared_ptr<VariableNode>& lhs,const std::shared_ptr<VariableNode>& rhs)
                                {return lhs.get()<rhs.get();});
            std::erase_if(diff,[](const std::shared_ptr<VariableNode>& var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
            });
            ref_vars=diff;
        }
        else{
            std::erase_if(ref_vars,[](const std::shared_ptr<VariableNode>& var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
            });
        }
    }
    return ref_vars;
}

std::set<std::shared_ptr<Node>> RangeOperationNode::define_range_node_range_nodes() const{
    std::set<std::shared_ptr<Node>> result;
    { //filtering this range node variables
        std::set<std::shared_ptr<Node>> ref_range_nodes = refer_to_node_of_type(NODE_TYPE::RANGEOP);
        if(!ref_range_nodes.empty())
        {
            std::set<std::shared_ptr<Node>> all_refered_range_nodes_by_child_range_node;
            std::set<std::shared_ptr<Node>> diff;
            for(const auto& range_node:ref_range_nodes)
                all_refered_range_nodes_by_child_range_node.merge(std::dynamic_pointer_cast<RangeOperationNode>(range_node)->
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

std::set<std::shared_ptr<VariableNode>> RangeOperationNode::define_array_type_variables() const{
    std::set<std::shared_ptr<VariableNode>> ref_vars = get_expression()->refer_to_vars();
    std::erase_if(ref_vars,[](const std::shared_ptr<VariableNode>& var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
    });
    return ref_vars;
}

Result RangeOperationNode::execute_for_array_variables(const std::vector<size_t>& ids,
                const std::set<ThroughVarStruct,ThroughVarStruct::Comparator>& structure) const{
    using namespace ::functions::auxiliary;    
    if(operation_==RANGE_OP::SUM)
        cache_ =  0.;
    else if(operation_==RANGE_OP::PROD)
        cache_ = 1.;

    std::vector<size_t> indexes = ids;
    indexes.push_back(0);

    for(;indexes.back()<sz_iteration;++indexes.back(), 
        std::for_each(structure.begin(),structure.end(),[this](const ThroughVarStruct& id){
            ++id.sz_depth_measure;
        })) //add defined size of dimension size variable
    {
        std::for_each(structure.begin(),structure.end(),[this](const ThroughVarStruct& id){
            id.sz_depth_measure.lock(var_ids_.find(id.var_node)->order_id.value()-1);
            std::cout<<"At depth 0: "<<id.sz_depth_measure.current_iterator(0)<<std::endl;
            std::cout<<"At depth 1: "<<id.sz_depth_measure.current_iterator(1)<<std::endl;
        });
        if(operation_==RANGE_OP::SUM)
            cache_ += get_expression()->execute_for_array_variables(indexes,structure);
        else if(operation_==RANGE_OP::PROD)
            cache_ *= get_expression()->execute_for_array_variables(indexes,structure);
        if(cache_.is_error()){
            return cache_;
        }
        std::cout<<cache_<<std::endl;
        std::for_each(structure.begin(),structure.end(),[this](const ThroughVarStruct& id){
            id.sz_depth_measure.unlock(var_ids_.find(id.var_node)->order_id.value()-1);
        });
    }
    std::for_each(structure.begin(),structure.end(),[this](const ThroughVarStruct& id){
        id.sz_depth_measure.reset_iterator(var_ids_.find(id.var_node)->order_id.value()-1);
    });
    return cache_;
}