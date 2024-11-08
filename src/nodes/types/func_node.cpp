#include "def.h"
#include "node.h"
#include "func_node.h"
#include "var_node.h"
#include "array_node.h"
#include "arithmetic_functions.h"
#include "warning.h"
#include "events_errors/check_val_type.h"
#include <boost/math/statistics/bivariate_statistics.hpp>
#include <boost/math/special_functions/gamma.hpp>

FunctionNode::FunctionNode(const FunctionNode& other):
Node(other),
operation_(other.operation_),
cache_(other.cache_),
array_type_function(other.array_type_function){}

bool FunctionNode::is_numeric() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_numeric();
    });
}

bool FunctionNode::is_string() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_string();
    });
}

bool FunctionNode::is_array() const{
    return false;
}

std::shared_ptr<Node> FunctionNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}

FUNCTION_OP FunctionNode::operation() const{
    return operation_;
}

#include <numeric>

Result FunctionNode::execute(){ //TODO add checking for arrays size comparision
    using namespace boost::math::policies;
    if(array_type_function){
        if(!cache_.has_value()){
            if(childs_.size()>0){
                if(std::all_of(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child){
                    return child->is_array();
                })){
                    std::vector<ArrayNode*> arrays;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->is_numeric()){
                            ArrayNode* push_node;
                            if(child->type()==NODE_TYPE::VARIABLE && child->childs().size()==1)
                                push_node = reinterpret_cast<ArrayNode*>(child->child(0).get());
                            else 
                                push_node = reinterpret_cast<ArrayNode*>(child.get());
                            arrays.push_back(push_node);
                        }
                        else throw exceptions::InvalidTypeOfArgument("numeric value or numeric array");
                    }
                    switch(operation_){
                        case FUNCTION_OP::SUMPRODUCT:
                            cache_ = functions::Arithmetic::SumProduct(arrays);
                            break;
                        case FUNCTION_OP::SUM:
                            cache_ = functions::Arithmetic::Sum(arrays);
                            break;
                        case FUNCTION_OP::PROD:
                            cache_ = functions::Arithmetic::Product(arrays);
                            break;
                        default:
                            throw std::invalid_argument("Unknown function operation");
                    }
                }
                else{
                    if(std::all_of(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child){
                        return !child->is_array() && child->is_numeric();
                    })){
                        Value_t init;
                        
                        switch(operation_){
                            case FUNCTION_OP::SUMPRODUCT:
                                init = 1.;
                                std::for_each(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child)->Result{
                                    return init*=child->execute().get<Value_t>();
                                });
                                cache_ = init;
                                break;
                            case FUNCTION_OP::SUM:
                                init = 0.;
                                std::for_each(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child)->Result{
                                    return init+=child->execute().get<Value_t>();
                                });
                                cache_ = init;
                                break;
                            case FUNCTION_OP::PROD:
                                init = 1.;
                                std::for_each(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child)->Result{
                                    return init*=child->execute().get<Value_t>();
                                });
                                cache_ = init;
                                break;
                            default:
                                throw std::invalid_argument("Unknown function operation");
                        }
                    }
                    else throw exceptions::InvalidTypeOfArgument("numeric value or numeric array");
                }
                
            }
            else cache_=0;
        }
    }
    else{
        if(childs_.size()==childs_.capacity()){
            if(!cache_.has_value()){
                if(childs_.size()!=NUMBER_OF_ARGUMENT[(size_t)operation_]){
                    cache_ = std::make_shared<AbstractEvent>(exceptions::InvalidNumberOfArguments(childs_.size()));
                    return cache_;
                }

                for(size_t child_i = 0;child_i<childs_.size();++child_i){
                    cache_ = childs_.at(child_i)->execute();
                    if(cache_.is_event()){
                        return cache_;
                    }
                    if(!(childs_[child_i]->type_val()&TYPE_OF_ARGUMENTS[(size_t)operation_].ARGS_[child_i])){
                        cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(NAMES_OF_ARGUMENT[childs_[child_i]->type_val()]);
                        return cache_;
                    }
                }
                if(std::all_of(childs_.begin(),childs_.end(),[&](const std::shared_ptr<Node>& child){
                    return child->is_numeric() && !child->is_array();
                })){
                    switch (operation_){
                        case FUNCTION_OP::LN:
                            if(child(0)->is_array() || !child(0)->is_numeric()){
                                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("not array and numeric type");
                                return cache_;
                            }
                            cache_ =  log(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::LG10:
                            if(!(child(0)->type_val()&TYPE_VAL::VALUE)){
                                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                                return cache_;
                            }
                            cache_ =  log10(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::EXP:
                            if(!(child(0)->type_val()&TYPE_VAL::VALUE)){
                                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                                return cache_;
                            }
                            cache_ = exp(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::LOG_BASE:
                            if(!(child(0)->type_val()&TYPE_VAL::VALUE) && !(child(1)->type_val()&TYPE_VAL::VALUE)){
                                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                                return cache_;
                            }
                            cache_ = log(child(0)->execute().get<Value_t>())/log(child(1)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::SIN:
                            if(!(child(0)->type_val()&TYPE_VAL::VALUE)){
                                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                                return cache_;
                            }
                            cache_ = sin(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::COS:
                            cache_ = cos(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::ASIN:
                            cache_ = asin(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::ACOS:
                            cache_ = acos(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::FACTORIAL:
                            try{
                                cache_ = boost::math::factorial<Value_t>(static_cast<unsigned int>(child(0)->execute().get<Value_t>()),policy<digits10<0>>());
                            }
                            catch(const std::overflow_error& err){
                                cache_ = std::make_shared<warnings::Infinite>();
                                return cache_;
                            }
                            break;
                        case FUNCTION_OP::PEARSON:
                            //may be optimized 
                            cache_ = boost::math::statistics::correlation_coefficient(
                                std::execution::seq,
                                child(0)->execute().get<ArrayNode>().childs(),
                                child(1)->execute().get<ArrayNode>().childs()
                                )->execute();
                            return cache_;
                            break;
                        case FUNCTION_OP::GAMMA:
                            cache_ = boost::math::tgamma(child(0)->execute().get<Value_t>());
                            return cache_;
                            break;
                        case FUNCTION_OP::SUM:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        case FUNCTION_OP::PROD:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        case FUNCTION_OP::SUMPRODUCT:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        case FUNCTION_OP::CONCAT:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        case FUNCTION_OP::CONTAIN_TEXT:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        case FUNCTION_OP::GAUSS:
                            exceptions::InvalidTypeOfArgument("Invalid type of function");
                            break;
                        // default:
                        //     throw std::invalid_argument("Unknown function operation");
                    }
                }
                else exceptions::InvalidTypeOfArgument("numeric value");
            }
        }
        else exceptions::InvalidNumberOfArguments(childs_.capacity());
    }
    return cache_;
}

Result FunctionNode::execute(size_t index){
    //because function is like a constant
    return execute();
}

#include "types.h"

void FunctionNode::print_text(std::ostream& stream) const{
    switch (operation_){
        case FUNCTION_OP::ACOS:{
            stream<<"acos(";
            break;
        }
        case FUNCTION_OP::COS:{
            stream<<"cos(";
            break;
        }
        case FUNCTION_OP::ASIN:{
            stream<<"asin(";
            break;
        }
        case FUNCTION_OP::SIN:{
            stream<<"sin(";
            break;
        }
        case FUNCTION_OP::EXP:{
            stream<<"exp(";
            break;
        }
        case FUNCTION_OP::FACTORIAL:{
            stream<<"factorial(";
            break;
        }
        case FUNCTION_OP::LG10:{
            stream<<"lg10(";
            break;
        }
        case FUNCTION_OP::LN:{
            stream<<"ln(";
            break;
        }
        case FUNCTION_OP::LOG_BASE:{
            stream<<"log_x(";
            break;
        }
        case FUNCTION_OP::PROD:{
            stream<<"product(";
            break;
        }
        case FUNCTION_OP::SUM:{
            stream<<"sum(";
            break;
        }
        case FUNCTION_OP::SUMPRODUCT:{
            stream<<"sumproduct(";
            break;
        }
        case FUNCTION_OP::CONCAT:{
            stream<<"concat(";
            break;
        }
        case FUNCTION_OP::CONTAIN_TEXT:{
            stream<<"contain.text(";
            break;
        }
        case FUNCTION_OP::SEARCH_TEXT:{
            stream<<"search.text(";
            break;
        }
        case FUNCTION_OP::PEARSON:{
            stream<<"pearson(";
            break;
        }
        case FUNCTION_OP::WEIBULL_DIST:{
            stream<<"weibull(";
            break;
        }
        case FUNCTION_OP::GAMMA:{
            stream<<"gamma(";
            break;
        }
        case FUNCTION_OP::GAMMA_REV:{
            stream<<"gamma.rev(";
            break;
        }
        case FUNCTION_OP::GAUSS:{
            stream<<"gauss(";
            break;
        }
        case FUNCTION_OP::STD_NORM_DISTRIB:{
            stream<<"std.norm.dist(";
            break;
        }
        case FUNCTION_OP::NORM_DISTRIB:{
            stream<<"norm.dist(";
            break;
        }
        case FUNCTION_OP::ROOT_MEAN_SQUARE:{
            stream<<"RMS(";
            break;
        }
        case FUNCTION_OP::ROOT_MEAN_SQUARE_ERROR:{
            stream<<"RMSE(";
            break;
        }
        case FUNCTION_OP::AVERAGE:{
            stream<<"average(";
            break;
        }
        case FUNCTION_OP::MEDIAN:{
            stream<<"median(";
            break;
        }
        default:{
            std::runtime_error("Unknown type operation");
        }
    }

    if(has_childs())
        for(auto child:childs_){
            child->print_text(stream);
        }
    else {
        Node node;
        node.print_text(stream);
    }
    stream<<")";
}

void FunctionNode::print_result(std::ostream& stream) const{
    stream<<const_cast<FunctionNode*>(this)->execute();
}

void FunctionNode::insert_back(std::shared_ptr<Node> node){
    if(childs_.size()<childs_.capacity()){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
}