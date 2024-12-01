#include "def.h"
#include "node.h"
#include "func_node.h"
#include "function_node/math_functions.h"
#include "function_node/print_functions.h"
#include "warning.h"
#include "exception.h"
#include "events_errors/check_val_type.h"
#include <boost/math/statistics/bivariate_statistics.hpp>
#include <boost/math/special_functions/gamma.hpp>

FunctionNode::FunctionNode(const FunctionNode& other):
Node(other),
operation_(other.operation_),
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

FUNCTION_OP FunctionNode::operation() const{
    return operation_;
}

#include <numeric>
#include "correlation.h"
#include "function_node/string_functions.h"
using namespace functions::auxiliary;

Result FunctionNode::execute() const{ //TODO add checking for arrays size comparision
    using namespace boost::math::policies;
    flush_cache();
    if(is_not_cycled())
        cache_=std::make_shared<exceptions::CyclicReference>("");
    if(NUMBER_OF_ARGUMENT[(size_t)operation_]!=-1 && childs_.size()!=(size_t)NUMBER_OF_ARGUMENT[(size_t)operation_]){
        cache_ = std::make_shared<exceptions::InvalidNumberOfArguments>(childs_.size());
        return cache_;
    }
    for(size_t child_i = 0;child_i<childs_.size();++child_i){
        cache_ = childs_.at(child_i)->execute();
        if(cache_.is_error()){
            return cache_;
        }
        cache_ = std::monostate();
        if(NUMBER_OF_ARGUMENT[(size_t)operation_]!=-1 && !(childs_[child_i]->type_val()&TYPE_OF_ARGUMENTS[(size_t)operation_].ARGS_[child_i])){
            cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>(NAMES_OF_ARGUMENT[childs_[child_i]->type_val()]);
            return cache_;
        }
    }
    switch (operation_){
        case FUNCTION_OP::LN:{
            if(child(0)->is_array() || !child(0)->is_numeric()){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("not array, value type");
                return cache_;
            }
            cache_ =  log(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::LG10:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ =  log10(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::EXP:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = exp(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::LOG_BASE:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0),child(1))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = log(child(0)->execute().get<Value_t>())/log(child(1)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::SIN:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = sin(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::COS:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = cos(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::ASIN:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = asin(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::ACOS:{
            if(!check_arguments(TYPE_VAL::VALUE,child(0))){
                cache_ = std::make_shared<exceptions::InvalidTypeOfArgument>("value type");
                return cache_;
            }
            cache_ = acos(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::FACTORIAL:{
            try{
                cache_ = boost::math::factorial<Value_t>(static_cast<unsigned int>(child(0)->execute().get<Value_t>()),policy<digits10<0>>());
            }
            catch(const std::overflow_error& err){
                cache_ = std::make_shared<warnings::Infinite>();
                return cache_;
                break;
            }
            return cache_;
            break;
        }
        case FUNCTION_OP::PEARSON:{
            //may be optimized
            if(!check_arguments(TYPE_VAL::NUMERIC_ARRAY,child(0),child(1))){
                cache_ = std::make_shared<exceptions::IncorrectTypeArrays>("numeric array");
                return cache_;
            }
            if(check_arguments_size(to_array_node(child(0)).get(),to_array_node(child(1)).get())){
                cache_ = std::make_shared<exceptions::UnequalSizeArrays>("PEARSON()");
                return cache_;
            }
            cache_ = node_function::functions::math::CorrelationCoefficient(
                std::execution::seq,
                to_array_node(child(0)),
                to_array_node(child(1))
                );
            return cache_;
            break;
        }
        case FUNCTION_OP::GAMMA:{
            cache_ = check_arguments(TYPE_VAL::VALUE,child(0));
            if(cache_.is_error())
                return cache_;
            cache_ = boost::math::tgamma(child(0)->execute().get<Value_t>());
            return cache_;
            break;
        }
        case FUNCTION_OP::SUM:{
            cache_ = node_function::functions::math::Sum(this);
            return cache_;
            break;
        }
        case FUNCTION_OP::PROD:
            cache_ = node_function::functions::math::Product(this);
            return cache_;
            break;
        case FUNCTION_OP::SUMPRODUCT:
            cache_ = node_function::functions::math::SumProduct(this);
            return cache_;
            break;
        case FUNCTION_OP::CONTAIN_TEXT:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::GAUSS:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::WEIBULL_DIST:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::STD_NORM_DISTRIB:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::NORM_DISTRIB:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::GAMMA_REV:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::ROOT_MEAN_SQUARE:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::ROOT_MEAN_SQUARE_ERROR:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::AVERAGE:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::MEDIAN:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::SEARCH_TEXT:
            throw exceptions::InvalidTypeOfArgument("Invalid type of function");
            break;
        case FUNCTION_OP::CONCAT:
            cache_ = node_function::functions::string::Concatenate(childs());
            break;
        // default:
        //     throw std::invalid_argument("Unknown function operation");
    }
    return cache_;
}

#include "types.h"
#include "function_node/print_functions.h"

void FunctionNode::print_text(std::ostream& stream) const{
    node_function::functions::print::print_text(this,stream);
}

void FunctionNode::print_result(std::ostream& stream) const{
    using namespace functions::auxiliary;
    stream<<const_cast<FunctionNode*>(this)->execute();
}

void FunctionNode::insert_back(std::shared_ptr<Node> node){
    flush_cache();
    __invalidate_type_val__();
    if(childs_.size()<childs_.capacity()){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
}