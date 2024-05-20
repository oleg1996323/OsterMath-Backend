#pragma once
#include <stdexcept>
#include <BaseErrorListener.h>

//     /// <summary>
//     /// Instead of recovering from exception {@code e}, re-throw it wrapped
//     ///  in a <seealso cref="ParseCancellationException"/> so it is not caught by the
//     ///  rule function catches.  Use <seealso cref="Exception#getCause()"/> to get the
//     ///  original <seealso cref="RecognitionException"/>.
//     /// </summary>
// class ParsingStrategy: public antlr4::BailErrorStrategy{
//     public:
//     virtual void recover(antlr4::Parser *recognizer, std::exception_ptr e) override;

//     /// Make sure we don't attempt to recover inline; if the parser
//     ///  successfully recovers, it won't throw an exception.
//     virtual antlr4::Token* recoverInline(antlr4::Parser *recognizer) override;

//     /// <summary>
//     /// Make sure we don't attempt to recover from problems in subrules. </summary>
//     virtual void sync(antlr4::Parser *recognizer) override;
// };

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