#include "range_node.h"
#include "def.h"
#include <memory>

RangeOperationNode::RangeOperationNode(const RangeOperationNode& other):
Node(other),
cache_(other.cache_),
range_expression(other.range_expression),
sz_iteration(other.sz_iteration),
operation_(other.operation_)
{}

#include "types.h"

Result RangeOperationNode::execute() const{
    using namespace ::functions::auxiliary;
    if(!range_expression)
        throw std::runtime_error("Missing expression at range node");
    std::set<std::shared_ptr<VariableNode>> ref_vars = define_array_type_variables();
    
    if(!std::all_of(ref_vars.begin(),ref_vars.end(),[&](const std::shared_ptr<Node>& var_id){
        return var_id && ((check_arguments(TYPE_VAL::NUMERIC_ARRAY,var_id) && is_rectangle_array_node(var_id)) || check_arguments(TYPE_VAL::VALUE,var_id));
    })){
        return std::make_shared<exceptions::InvalidTypeOfArgument>(std::string()+
        "variable with numeric value or rectangle numeric array");
    }
    if(!check_variables_sizes_and_define_size_iteration(0)){
        return std::make_shared<exceptions::Exception>("Invalid arguments");
    }
    std::vector<size_t> range_node_execute_struct;
    return execute_for_array_variables(range_node_execute_struct);
}

void RangeOperationNode::print_text(std::ostream& stream) const{
    if(operation_==RANGE_OP::PROD)
        stream<<"product_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    if(has_childs())
        range_expression->print_text(stream);
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
    stream<<const_cast<RangeOperationNode*>(this)->execute();
}

bool RangeOperationNode::is_numeric() const{
    if(range_expression)
        return range_expression->is_numeric();
    else return false;
}

bool RangeOperationNode::is_string() const{
    if(range_expression)
        return range_expression->is_string();
    else return false;
}

bool RangeOperationNode::is_array() const{
    return false;
}

#include "aux_functions.h"

bool RangeOperationNode::check_variables_sizes_and_define_size_iteration(size_t depth) const{
    using namespace functions::auxiliary;
    std::set<std::shared_ptr<VariableNode>> arr_vars = define_range_node_array_type_variables();
    if(arr_vars.empty() && define_array_type_variables().empty())
        return false;
    if(!std::all_of(arr_vars.begin(),arr_vars.end(),[](const std::shared_ptr<VariableNode>& var){
        return is_rectangle_array_node(var);
    }) || !equal_morphology_nodes(std::vector<std::shared_ptr<Node>>(arr_vars.begin(),arr_vars.end())))
        return false;
    else{
        auto found = this->var_ids_.find(*arr_vars.begin());
        std::optional<size_t> sz_tmp;
        if(found->order_id.has_value())
            sz_tmp = init_sz_depth_measure(*arr_vars.begin()).size(found->order_id.value());
        if(std::all_of(arr_vars.begin(),arr_vars.end(),[](const std::shared_ptr<VariableNode>& var){
            return init_sz_depth_measure(var).dimensions()==1;
        }))
            sz_iteration = init_sz_depth_measure(*arr_vars.begin()).size(depth);
        else if(std::all_of(arr_vars.begin(),arr_vars.end(),[this,&sz_tmp](const std::shared_ptr<VariableNode>& var){
            if(!this->var_ids_.contains(var))
                return false;
            else{
                if(!sz_tmp.has_value())
                    return false;
                return  sz_tmp.value()==init_sz_depth_measure(var).size(this->var_ids_.find(var)->order_id.value());
            }
        })){
            sz_iteration = sz_tmp.value();
        }
        else{
            return false;
        }
    }
    std::set<std::shared_ptr<Node>> range_nodes = define_range_node_range_nodes();
    if(range_nodes.empty())
        return true;
    else return std::all_of(range_nodes.begin(),range_nodes.end(),[depth](const std::shared_ptr<Node>& node){
        return std::dynamic_pointer_cast<RangeOperationNode>(node)->check_variables_sizes_and_define_size_iteration(depth+1);
    });

    return true;
}

std::set<std::shared_ptr<VariableNode>> RangeOperationNode::define_range_node_array_type_variables() const{
    std::set<std::shared_ptr<VariableNode>> ref_vars = range_expression->refer_to_vars();
    { //filtering this range node variables
        std::set<std::shared_ptr<Node>> ref_range_nodes = range_expression->refer_to_node_of_type(NODE_TYPE::RANGEOP);
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
        std::set<std::shared_ptr<Node>> ref_range_nodes = range_expression->refer_to_node_of_type(NODE_TYPE::RANGEOP);
        if(!ref_range_nodes.empty())
        {
            std::set<std::shared_ptr<Node>> all_refered_range_nodes_by_child_range_node;
            std::set<std::shared_ptr<Node>> diff;
            for(const auto& range_node:ref_range_nodes)
                all_refered_range_nodes_by_child_range_node.merge(std::dynamic_pointer_cast<RangeOperationNode>(range_node)->
                                                    range_expression->refer_to_node_of_type(NODE_TYPE::RANGEOP));
            std::set_difference(all_refered_range_nodes_by_child_range_node.begin(),
                                all_refered_range_nodes_by_child_range_node.end(),
                                ref_range_nodes.begin(),
                                ref_range_nodes.end(),
                                std::inserter(diff,diff.end()),
                                [](const std::shared_ptr<Node>& lhs,const std::shared_ptr<Node>& rhs)
                                {return lhs.get()<rhs.get();});
            result=diff;
        }
    }
    return result;
}

std::set<std::shared_ptr<VariableNode>> RangeOperationNode::define_array_type_variables() const{
    std::set<std::shared_ptr<VariableNode>> ref_vars = range_expression->refer_to_vars();
    std::erase_if(ref_vars,[](const std::shared_ptr<VariableNode>& var){
                return ::functions::auxiliary::check_arguments(TYPE_VAL::VALUE,var);
    });
    return ref_vars;
}

Result RangeOperationNode::execute_for_array_variables(const std::vector<size_t>& ids) const{
    using namespace ::functions::auxiliary;    
    if(operation_==RANGE_OP::SUM)
        cache_ =  0.;
    else if(operation_==RANGE_OP::PROD)
        cache_ = 1.;

    std::vector<size_t> indexes = ids;
    indexes.push_back(0);

    for(;indexes.back()<sz_iteration;++indexes.back()) //add defined size of dimension size variable
    {
        if(operation_==RANGE_OP::SUM)
            cache_ += range_expression->execute_for_array_variables(indexes);
        else if(operation_==RANGE_OP::PROD)
            cache_ *= range_expression->execute_for_array_variables(indexes);
        if(cache_.is_error()){
            return cache_;
        }
    }
    return cache_;
}