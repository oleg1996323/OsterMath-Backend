#include "range_node.h"
#include "def.h"

RangeOperationNode::RangeOperationNode(const RangeOperationNode& other):
Node(other),
cache_(other.cache_),
vars_(other.vars_),
range_expression(other.range_expression),
operation_(other.operation_)
{}

Result RangeOperationNode::execute() const{
    using namespace ::functions::auxiliary;
    if(!range_expression)
        throw std::runtime_error("Missing expression at range node");
    RangeNodeExecuteStruct range_node_execute_struct;
    range_node_execute_struct.variables = vars_;
    range_node_execute_struct.range_operators_called = 0;
    std::set<std::shared_ptr<VariableNode>> ref_vars = range_expression->refer_to_vars();

    if(!std::all_of(ref_vars.begin(),ref_vars.end(),[&](const std::shared_ptr<Node>& var_id){
        return var_id && ((check_arguments(TYPE_VAL::NUMERIC_ARRAY,var_id) && is_rectangle_array_node(var_id)) || check_arguments(TYPE_VAL::VALUE,var_id));
    })){
        return std::make_shared<exceptions::InvalidTypeOfArgument>(std::string()+
        "variable with numeric value or rectangle numeric array");
    }
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

Result RangeOperationNode::execute_for_array_variables(const RangeNodeExecuteStruct& through_struct) const{
    /*  std::set<VariableNodeIndexInRangeOperation> vars_;
        std::shared_ptr<Node> range_expression;*/
    using namespace ::functions::auxiliary;
    RangeNodeExecuteStruct range_node_execute_struct = through_struct;
    ++range_node_execute_struct.range_operators_called;
    if(!range_expression)
        throw std::runtime_error("Missing expression at range node");
    std::set<std::shared_ptr<VariableNode>> ref_vars = define_range_node_array_type_variables();

    //complete and check overriding of order indexes
    for(std::shared_ptr<VariableNode> var:ref_vars){
        if(!range_node_execute_struct.variables.contains(var.get())){
            VariableNodeIndexInRangeOperation tmp;
            tmp.var_node = std::dynamic_pointer_cast<VariableNode>(var);
            tmp.sz_depth_measure = std::make_shared<SizeDepthMeasure>(init_sz_depth_measure(var));
            for(size_t order_checker = 0;order_checker<tmp.sz_depth_measure->dimensions();++order_checker)
                tmp.order_id.push_back(order_checker);
            range_node_execute_struct.variables.insert(tmp);
        }
        else if(range_node_execute_struct.variables.find(var.get())->order_id.size()<
                range_node_execute_struct.variables.find(var.get())->sz_depth_measure->dimensions())
        {
            std::vector<size_t> missing_orders;
            size_t dims = range_node_execute_struct.variables.find(var.get())->sz_depth_measure->dimensions();
            std::vector<size_t>& order_id = range_node_execute_struct.variables.find(var.get())->order_id;
            //std::vector<size_t>& this_order_id = this->vars_.find(var.get())->order_id;
            missing_orders.reserve(dims-order_id.size());
            for(size_t order_checker = 0;order_checker<dims;++order_checker){
                size_t count = std::count(order_id.begin(),order_id.end(),order_checker);
                if(count == 0)
                    missing_orders.push_back(order_checker);
                else if(count == 1)
                    continue;
                else return std::make_shared<exceptions::Exception>("Double defined variable index in range function");
            }
            order_id.insert(order_id.end(),missing_orders.begin(),missing_orders.end());
        }
        else if(range_node_execute_struct.variables.find(var.get())->order_id.size()>
                range_node_execute_struct.variables.find(var.get())->sz_depth_measure->dimensions()){
            return std::make_shared<exceptions::InvalidNumberOfArguments>(
                    range_node_execute_struct.variables.find(var.get())->sz_depth_measure->dimensions());
        }
        else continue;
    }
    //check if there is not repetitions of variables with order overriding at extension
    for(const VariableNodeIndexInRangeOperation& iter:range_node_execute_struct.variables)
    {
        if(vars_.count(iter)){
            auto tmp_var = vars_.find(iter);
            if(tmp_var->order_id>iter.order_id && 
            [this,&through_struct, &tmp_var]()->bool
            { //check if child range_node doesn't override previously overriden indexes
                size_t count = 0;
                for(size_t id:through_struct.variables.find(*tmp_var)->order_id){
                    if(id !=tmp_var->order_id.at(count))
                        return false;
                    ++count;
                }
                return true; 
            }())
            {
                iter.order_id = tmp_var->order_id;
                if(!iter.sz_depth_measure)
                    throw std::runtime_error("Not defined sizes of previously defined array-type variable");
            }
            else{
                return std::make_shared<exceptions::InvalidTypeOfArgument>(std::string()+"variable iteration indexes must be bigger previously defined indexes\n"+
                                                    "and mustn't override previously defined indexes");
            }
        }
        else
            vars_.insert(iter);
    }
    {
        decltype(vars_) res;
        std::set_intersection(vars_.begin(),vars_.end(),
                range_node_execute_struct.variables.begin(),
                range_node_execute_struct.variables.end(),
                std::inserter(res,res.end()),
                [](const VariableNodeIndexInRangeOperation& lhs,const VariableNodeIndexInRangeOperation& rhs)
                {return lhs.var_node.get()<rhs.var_node.get();});
        vars_ = res;
    }
    
    //check variables by size and square array
    if(operation_==RANGE_OP::SUM)
        cache_ =  0.;
    else if(operation_==RANGE_OP::PROD)
        cache_ = 1.;
    
    std::for_each(range_node_execute_struct.variables.begin(),range_node_execute_struct.variables.end(),[&range_node_execute_struct](const VariableNodeIndexInRangeOperation& v){
        if(range_node_execute_struct.range_operators_called<v.sz_depth_measure->dimensions())
            v.sz_depth_measure->lock(range_node_execute_struct.range_operators_called-1);
            //lock at order index (not the call rangenode order)
    });
    while(true)
    {
        if(operation_==RANGE_OP::SUM)
            cache_ += range_expression->execute_for_array_variables(range_node_execute_struct);
        else if(operation_==RANGE_OP::PROD)
            cache_ *= range_expression->execute_for_array_variables(range_node_execute_struct);
        if(cache_.is_error()){
            return cache_;
        }
        
        if(!std::all_of(range_node_execute_struct.variables.begin(),
        range_node_execute_struct.variables.end(),
        [&range_node_execute_struct](const VariableNodeIndexInRangeOperation& v){
            bool iterable = v.sz_depth_measure->is_iterable();
            if(range_node_execute_struct.range_operators_called<=v.sz_depth_measure->dimensions())
                ++(*v.sz_depth_measure.get());
            return iterable;
        }))
            break;
    }
    std::for_each(range_node_execute_struct.variables.begin(),range_node_execute_struct.variables.end(),[&range_node_execute_struct](const VariableNodeIndexInRangeOperation& v){
        if(range_node_execute_struct.range_operators_called<v.sz_depth_measure->dimensions())
            v.sz_depth_measure->unlock(range_node_execute_struct.range_operators_called-1);
    });

    #ifdef DEBUG
        assert(!std::all_of(range_node_execute_struct.variables.begin(),range_node_execute_struct.variables.end(),[](const VariableNodeIndexInRangeOperation& v){
            return v.sz_depth_measure->is_iterable();
        }));
    #endif
    return cache_;
}