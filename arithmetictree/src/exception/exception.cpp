#include <exception.h>
#include <ParseRulesParser.h>
#include <BaseErrorListener.h>
#include <DefaultErrorStrategy.h>

namespace exceptions{
    const char* Exception::get_prompt() const{
        return what();
    }

    ParsingError::ParsingError(const std::string& error):
    Exception(error){}
    const char* ParsingError::error_abbr(){
        return "#NAME?";
    }
    const char* ParsingError::get_error() const{
        return "Parsing error";
    }
    EXCEPTION_TYPE ParsingError::type() const{
        return EXCEPTION_TYPE::PARSING;
    }
    const char* ParsingError::get_prompt() const{
        return what();
    }

    UnequalSizeArrays::UnequalSizeArrays(const std::string& function_name):
    Exception(std::string()+"Unequal sizes of arrays in function "+function_name){}
    const char* UnequalSizeArrays::error_abbr(){
        return "#VAL!";
    }
    const char* UnequalSizeArrays::get_error() const{
        return "Function array argument error";
    }
    EXCEPTION_TYPE UnequalSizeArrays::type() const{
        return EXCEPTION_TYPE::UNQEQUAL_ARRAYS;
    }
    const char* UnequalSizeArrays::get_prompt() const{
        return what();
    }

    UnknownTypeArray::UnknownTypeArray():
    Exception("Unavaible to use array of unknown (not defined) type"){}
    const char* UnknownTypeArray::error_abbr(){
        return "#TYPE!";
    }
    const char* UnknownTypeArray::get_error() const{
        return "Unknown type of array";
    }
    EXCEPTION_TYPE UnknownTypeArray::type() const{
        return EXCEPTION_TYPE::UNKNOWN_TYPE_ARRAY;
    }
    const char* UnknownTypeArray::get_prompt() const{
        return what();
    }

    IncorrectTypeArrays::IncorrectTypeArrays(const std::string& type_expected):
    Exception("Incorrect type. Should be "+type_expected){}
    const char* IncorrectTypeArrays::error_abbr(){
        return "#TYPE!";
    }
    const char* IncorrectTypeArrays::get_error() const{
        return "Incorrect type of array";
    }
    EXCEPTION_TYPE IncorrectTypeArrays::type() const{
        return EXCEPTION_TYPE::INCORRECT_TYPE_ARRAYS;
    }
    const char* IncorrectTypeArrays::get_prompt() const{
        return what();
    }

    CyclicReference::CyclicReference(const std::string& var_name):
    Exception("Var "+var_name+" is self-refered"){}
    const char* CyclicReference::error_abbr(){
        return "#CYCLE!";
    }
    const char* CyclicReference::get_error() const{
        return "Cyclic reference";
    }
    EXCEPTION_TYPE CyclicReference::type() const{
        return EXCEPTION_TYPE::CYCLIC;
    }
    const char* CyclicReference::get_prompt() const{
        return what();
    }

    DivisionZero::DivisionZero():
    Exception("Division by 0"){}
    const char* DivisionZero::error_abbr(){
        return "#DIV/0";
    }
    const char* DivisionZero::get_error() const{
        return "Zero division";
    }
    EXCEPTION_TYPE DivisionZero::type() const{
        return EXCEPTION_TYPE::DIVISION_ZERO;
    }
    const char* DivisionZero::get_prompt() const{
        return what();
    }

    InvalidTypeOfArgument::InvalidTypeOfArgument(const std::string& expected_type):
    Exception("Invalid argument. Prompt: expected "+expected_type){}

    const char* InvalidTypeOfArgument::error_abbr(){
        return "#TYPE!";
    }
    const char* InvalidTypeOfArgument::get_error() const{
        return "Invalid type of argument";
    }
    EXCEPTION_TYPE InvalidTypeOfArgument::type() const{
        return EXCEPTION_TYPE::INVALID_TYPE_ARG;
    }
    const char* InvalidTypeOfArgument::get_prompt() const{
        return what();
    }

    InvalidNumberOfArguments::InvalidNumberOfArguments(size_t expected_number_args):
    Exception("Invalid number of arguments. Prompt: expected "+std::to_string(expected_number_args)+" arguments"){}

    const char* InvalidNumberOfArguments::error_abbr(){
        return "#ARG!";
    }
    const char* InvalidNumberOfArguments::get_error() const{
        return "Invalid number of arguments";
    }
    EXCEPTION_TYPE InvalidNumberOfArguments::type() const{
        return EXCEPTION_TYPE::INVALID_NUMBER_ARGS;
    }
    const char* InvalidNumberOfArguments::get_prompt() const{
        return what();
    }

    const char* get_except_abbr(EXCEPTION_TYPE type){
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
        case EXCEPTION_TYPE::UNQEQUAL_ARRAYS:
            return UnequalSizeArrays::error_abbr();
            break;
        case EXCEPTION_TYPE::INVALID_TYPE_ARG:
            return InvalidTypeOfArgument::error_abbr();
            break;
        case EXCEPTION_TYPE::INVALID_NUMBER_ARGS:
            return InvalidNumberOfArguments::error_abbr();
            break;
        default:
            assert(true);
            return "";
            break;
        }
    }
}