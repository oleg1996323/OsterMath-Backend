#pragma once
#include <stdexcept>
#include <BaseErrorListener.h>

class ParsingError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class EmptyVal: public std::logic_error{
    using std::logic_error::logic_error;
};

class EmptyArray: public std::logic_error{
    using std::logic_error::logic_error;
};

class UndefinedFunction: public std::logic_error{
    using std::logic_error::logic_error;
};

class VariableAlreadyExists: public std::logic_error{
    using std::logic_error::logic_error;
};

class BailErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) override {
        throw ParsingError("Error when lexing: " + msg);
    }
};