#include "function_node/print_functions.h"
#include "func_node.h"
#include "node.h"

void node_function::functions::print::print_text(const FunctionNode* node,std::ostream& stream){
    switch (node->operation()){
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

    if(node->has_childs())
        for(auto child:node->childs()){
            child->print_text(stream);
        }
    else {
        EmptyNode node;
        node.print_text(stream);
    }
    stream<<")";
}