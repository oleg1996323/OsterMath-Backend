#include "exception.h"
#include <cassert>

namespace exceptions{
    std::string Exception::__get_abbr__() const{
        return error_abbr();
    }

    Exception::Exception(const char* arg):
    std::runtime_error(arg), AbstractEvent(){
        event_t_ = EVENT_TYPE::EXCEPTION;
    }

    Exception::Exception(const std::string& arg):
    std::runtime_error(arg), AbstractEvent(){
        event_t_ = EVENT_TYPE::EXCEPTION;
    }

    std::string Exception::get_prompt() const{
        return what();
    }

    std::string Exception::__get_title__() const{
        return get_error();
    }
    size_t Exception::__type__() const{
        return (size_t)type();
    }

    std::string Exception::__get_prompt__() const{
        return get_prompt();
    }

    ParsingError::ParsingError(const std::string& error):
    Exception(error){}
    std::string ParsingError::error_abbr(){
        return "#NAME?";
    }
    std::string ParsingError::get_error() const{
        return "Parsing error";
    }
    EXCEPTION_TYPE ParsingError::type() const{
        return EXCEPTION_TYPE::PARSING;
    }
    std::string ParsingError::get_prompt() const{
        return what();
    }

    UnequalSizeArrays::UnequalSizeArrays(const std::string& function_name):
    Exception(std::string()+"Unequal sizes of arrays in function "+function_name){}
    std::string UnequalSizeArrays::error_abbr(){
        return "#VAL!";
    }
    std::string UnequalSizeArrays::get_error() const{
        return "Function array argument error";
    }
    EXCEPTION_TYPE UnequalSizeArrays::type() const{
        return EXCEPTION_TYPE::UNEQUAL_ARRAYS;
    }
    std::string UnequalSizeArrays::get_prompt() const{
        return what();
    }

    InvalidSizeArrays::InvalidSizeArrays(const std::string& expected_size):
    Exception(std::string()+"Invalid sizes of arrays in range function. Expected: "+expected_size){}
    std::string InvalidSizeArrays::error_abbr(){
        return "#VAL!";
    }
    std::string InvalidSizeArrays::get_error() const{
        return "Invalid size of arrays";
    }
    EXCEPTION_TYPE InvalidSizeArrays::type() const{
        return EXCEPTION_TYPE::INVALID_SIZE_ARRAYS;
    }
    std::string InvalidSizeArrays::get_prompt() const{
        return what();
    }

    UnknownTypeArray::UnknownTypeArray():
    Exception("Unavaible to use array of unknown (not defined) type"){}
    std::string UnknownTypeArray::error_abbr(){
        return "#TYPE!";
    }
    std::string UnknownTypeArray::get_error() const{
        return "Unknown type of array";
    }
    EXCEPTION_TYPE UnknownTypeArray::type() const{
        return EXCEPTION_TYPE::UNKNOWN_TYPE_ARRAY;
    }
    std::string UnknownTypeArray::get_prompt() const{
        return what();
    }

    IncorrectTypeArrays::IncorrectTypeArrays(const std::string& type_expected):
    Exception("Incorrect type. Should be "+type_expected){}
    std::string IncorrectTypeArrays::error_abbr(){
        return "#TYPE!";
    }
    std::string IncorrectTypeArrays::get_error() const{
        return "Incorrect type of array";
    }
    EXCEPTION_TYPE IncorrectTypeArrays::type() const{
        return EXCEPTION_TYPE::INCORRECT_TYPE_ARRAYS;
    }
    std::string IncorrectTypeArrays::get_prompt() const{
        return what();
    }

    CyclicReference::CyclicReference(const std::string& var_name):
    Exception("Var "+var_name+" is self-refered"){}
    std::string CyclicReference::error_abbr(){
        return "#CYCLE!";
    }
    std::string CyclicReference::get_error() const{
        return "Cyclic reference";
    }
    EXCEPTION_TYPE CyclicReference::type() const{
        return EXCEPTION_TYPE::CYCLIC;
    }
    std::string CyclicReference::get_prompt() const{
        return what();
    }

    DivisionZero::DivisionZero():
    Exception("Division by 0"){}
    std::string DivisionZero::error_abbr(){
        return "#DIV/0";
    }
    std::string DivisionZero::get_error() const{
        return "Zero division";
    }
    EXCEPTION_TYPE DivisionZero::type() const{
        return EXCEPTION_TYPE::DIVISION_ZERO;
    }
    std::string DivisionZero::get_prompt() const{
        return what();
    }

    InvalidTypeOfArgument::InvalidTypeOfArgument(const std::string& expected_type):
    Exception("Invalid argument. Prompt: expected "+expected_type){}

    std::string InvalidTypeOfArgument::error_abbr(){
        return "#TYPE!";
    }
    std::string InvalidTypeOfArgument::get_error() const{
        return "Invalid type of argument";
    }
    EXCEPTION_TYPE InvalidTypeOfArgument::type() const{
        return EXCEPTION_TYPE::INVALID_TYPE_ARG;
    }
    std::string InvalidTypeOfArgument::get_prompt() const{
        return what();
    }

    InvalidNumberOfArguments::InvalidNumberOfArguments(size_t expected_number_args):
    Exception("Invalid number of arguments. Prompt: expected "+std::to_string(expected_number_args)+" arguments"){}

    std::string InvalidNumberOfArguments::error_abbr(){
        return "#ARG!";
    }
    std::string InvalidNumberOfArguments::get_error() const{
        return "Invalid number of arguments";
    }
    EXCEPTION_TYPE InvalidNumberOfArguments::type() const{
        return EXCEPTION_TYPE::INVALID_NUMBER_ARGS;
    }
    std::string InvalidNumberOfArguments::get_prompt() const{
        return what();
    }

    std::string get_except_abbr(EXCEPTION_TYPE type){
        switch (type)
        {
        case EXCEPTION_TYPE::PARSING:
            return ParsingError::error_abbr();
            break;
        case EXCEPTION_TYPE::CYCLIC:
            return CyclicReference::error_abbr();
            break;
        case EXCEPTION_TYPE::DIVISION_ZERO:
            return DivisionZero::error_abbr();
            break;
        case EXCEPTION_TYPE::INCORRECT_TYPE_ARRAYS:
            return IncorrectTypeArrays::error_abbr();
            break;
        case EXCEPTION_TYPE::UNKNOWN_TYPE_ARRAY:
            return UnknownTypeArray::error_abbr();
            break;
        case EXCEPTION_TYPE::UNEQUAL_ARRAYS:
            return UnequalSizeArrays::error_abbr();
            break;
        case EXCEPTION_TYPE::INVALID_TYPE_ARG:
            return InvalidTypeOfArgument::error_abbr();
            break;
        case EXCEPTION_TYPE::INVALID_NUMBER_ARGS:
            return InvalidNumberOfArguments::error_abbr();
            break;
        case EXCEPTION_TYPE::VARIABLE_DONT_EXISTS:
            return VariableDontExists::error_abbr();
            break;
        case EXCEPTION_TYPE::NODE_DONT_EXISTS:
            return NodeChildDontExists::error_abbr();
            break;
        case EXCEPTION_TYPE::INVALID_SIZE_ARRAYS:
            return InvalidSizeArrays::error_abbr();
            break;
        case EXCEPTION_TYPE::EXCEPTION:
            return Exception::error_abbr();
            break;
        default:
            assert(true);
            return "";
            break;
        }
    }

    VariableDontExists::VariableDontExists(const std::string& name):
    Exception("Variable "+name+"don't exists"){}

    std::string VariableDontExists::error_abbr(){
        return "#NAME?";
    }
    std::string VariableDontExists::get_error() const{
        return "Variable don't exists";
    }
    EXCEPTION_TYPE VariableDontExists::type() const{
        return EXCEPTION_TYPE::PARSING;
    }
    std::string VariableDontExists::get_prompt() const{
        return what();
    }

    NodeChildDontExists::NodeChildDontExists(const std::string& error):
    Exception(error){}
    std::string NodeChildDontExists::error_abbr(){
        return "#NAME?";
    }
    std::string NodeChildDontExists::get_error() const{
        return "Node don't exists";
    }
    EXCEPTION_TYPE NodeChildDontExists::type() const{
        return EXCEPTION_TYPE::NODE_DONT_EXISTS;
    }
    std::string NodeChildDontExists::get_prompt() const{
        return what();
    }
}