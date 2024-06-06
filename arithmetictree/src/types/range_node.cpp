#include "range_node.h"

#ifdef DEBUG
void RangeOperationNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::RANGEOP);
    if(operation_==RANGE_OP::PROD)
        std::cout<<ENUM_NAME(RANGE_OP::PROD);
    if(operation_==RANGE_OP::SUM)
        std::cout<<ENUM_NAME(RANGE_OP::SUM);
    std::cout<<'}'<<std::endl;
}
#endif

Value_t RangeOperationNode::execute(){
    Value_t result;
    if(!__checking_childs__())
        throw std::invalid_argument("Invalid input of variables");
    if(operation_==RANGE_OP::SUM)
        result = 0.;
    else if(operation_==RANGE_OP::PROD)
        result = 1.;
    for(size_t i=0;i<range_size;++i){
        if(operation_==RANGE_OP::SUM)
            result+=execute(i);
        else if(operation_==RANGE_OP::PROD)
            result*=execute(i);
    }
    return result;
}

Value_t RangeOperationNode::execute(size_t index){
    return range_expression.execute(index);
}

ranges::ArithmeticTree& RangeOperationNode::expression(){
    return range_expression;
}

const ranges::ArithmeticTree& RangeOperationNode::expression() const{
    return range_expression;
}

//can has only one parent (unlike the variable node)
void RangeOperationNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        parent_->refresh();
        caller_ = false;
    }
}

const std::unordered_set<VariableNode*>& RangeOperationNode::get_dependencies() const{
    return expression().get_dependencies();
}

std::ostream& RangeOperationNode::operator<<(std::ostream& stream){
    if(operation_==RANGE_OP::PROD)
        stream<<"prod_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    for(auto child:childs_){
        stream<<child;
    stream<<")";
    return stream;
    }
}
