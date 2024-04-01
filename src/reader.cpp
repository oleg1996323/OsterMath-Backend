#include <reader.h>

void DataInitialize::InitializeZones(const std::string& path){
        std::filesystem::path file(path);
        parsers_.at(0)
}

void DataInitialize::InitializeBounds(){

}

class DataInitialize::Lexer::ErrorListener: public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) override {
        throw ParsingError("Error when lexing: " + msg);
    }
};

