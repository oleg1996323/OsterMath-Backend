#pragma once
#include <BaseErrorListener.h>
#include <DefaultErrorStrategy.h>
#include <stdexcept>
    /// <summary>
    /// Instead of recovering from exception {@code e}, re-throw it wrapped
    ///  in a <seealso cref="ParseCancellationException"/> so it is not caught by the
    ///  rule function catches.  Use <seealso cref="Exception#getCause()"/> to get the
    ///  original <seealso cref="RecognitionException"/>.
    /// </summary>
class ParsingStrategy;

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

class ErrorListener: public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) override {
        throw ParsingError("Error when lexing: " + msg);
    }
};