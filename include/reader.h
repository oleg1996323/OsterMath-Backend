#include <fstream>
#include "def.h"
#include "ParseRulesLexer.h"
#include "ParseRulesListener.h"
#include "ParseRulesParser.h"

enum class TypeFile{

};

class DataInitialize{

    void InitializeZones(){

    }

    void InitializeBounds(){

    }

    private:
    class Parser;
    class Lexer;
    class Listener;

    class FileReader;
    
    std::vector<std::unique_ptr<Parser>> parsers_;

};

class DataInitialize::Parser{
    Parser(std::ifstream& file, TypeFile type){
        antlr4::ANTLRInputStream stream(file);
        
        
        
    }

    std::unique_ptr<ParseRulesParser> parser_;
    antlr4::TokenStream* input;
};

class DataInitialize::Lexer: public ParseRulesLexer, public antlr4::Token{
    public:
    Lexer(std::ifstream& file, TypeFile type):ParseRulesLexer(&antlr4::ANTLRInputStream(file)){
        token_stream_ = std::make_unique<antlr4::CommonTokenStream>(this);
    }

    void SetStdInputStream(std::istream& stream){
        this->setInputStream(&antlr4::ANTLRInputStream(stream))
    }

    private:
    std::unique_ptr<antlr4::CommonTokenStream> token_stream_;
};

class DataInitialize::Listener: public ParseRulesListener{
    
};

class DataInitialize::FileReader: public DataInitialize::Parser, public DataInitialize::Lexer, public DataInitialize::Listener
{
    
};