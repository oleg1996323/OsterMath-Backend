#include <fstream>
#include <filesystem>
#include "exception.h"
#include "def.h"
#include "ParseRulesLexer.h"
#include "ParseRulesListener.h"
#include "ParseRulesParser.h"

enum class TypeFile{

};



//в парсер рассмотреть вложенные функции func(func()) с рекурсией парсинга

class DataInitialize{

    void InitializeZones(const std::string& path);

    void InitializeBounds();

    private:
    class Parser;
    class Lexer;
    class Listener;

    class FileReader;
    
    std::vector<std::unique_ptr<Parser>> parsers_;
};

/*
    using namespace antlr4;

    ANTLRInputStream input(in);

    FormulaLexer lexer(&input);
    ASTImpl::BailErrorListener error_listener;
    lexer.removeErrorListeners();
    lexer.addErrorListener(&error_listener);

    CommonTokenStream tokens(&lexer);

    FormulaParser parser(&tokens);
    auto error_handler = std::make_shared<BailErrorStrategy>();
    parser.setErrorHandler(error_handler);
    parser.removeErrorListeners();

    tree::ParseTree* tree = parser.main();
    ASTImpl::ParseASTListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return FormulaAST(listener.MoveRoot(), listener.MoveCells());
*/

class DataInitialize::Parser{
    Parser(std::ifstream& file, TypeFile type){
        antlr4::ANTLRInputStream stream(file);
        
    }

    std::unique_ptr<ParseRulesParser> parser_;
    antlr4::TokenStream* input;
};

class DataInitialize::Lexer: public ParseRulesLexer{
    public:
    Lexer(std::ifstream& file, TypeFile type):ParseRulesLexer(&antlr4::ANTLRInputStream(file)){
        token_stream_ = std::make_unique<antlr4::CommonTokenStream>(this);
    }

    void SetStdInputStream(std::istream& stream){
        this->setInputStream(&antlr4::ANTLRInputStream(stream)); 
    }

    private:
    class ErrorListener;

    std::unique_ptr<antlr4::CommonTokenStream> token_stream_;
};

class DataInitialize::Listener: public ParseRulesListener{
    
};

class DataInitialize::FileReader: public DataInitialize::Parser, public DataInitialize::Lexer, public DataInitialize::Listener
{
    
};