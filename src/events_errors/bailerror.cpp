#include "events_errors/bailerror.h"
#include "exception.h"

namespace bailerror{
    void BailErrorListener::syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) {
        throw exceptions::ParsingError(std::string()+"Error when lexing: " + msg);
    }

    void ErrorListener::syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) {
        throw exceptions::ParsingError(std::string()+"Error when lexing: " + msg);
    }
}