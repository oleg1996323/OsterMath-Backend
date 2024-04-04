#include <fstream>
#include <filesystem>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <functional>
#include <memory>
#include <execution>
#include <future>
#include <string_view>
#include <unordered_map>

#include "config.h"

#include "exception.h"
#include "def.h"
#include "ParseRulesLexer.h"
#include "ParseRulesListener.h"
#include "ParseRulesParser.h"

using namespace boost::multiprecision;



//в парсер рассмотреть вложенные функции func(func()) с рекурсией парсинга

struct CallbackEquation{

    template<typename... ARGS>
    std::function<cpp_dec_float_50(ARGS...)> function(ARGS...);
};

class BaseListener: public ParseRulesListener{

    protected:
    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx);
    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext *ctx);

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx);
    virtual void exitVariable(ParseRulesParser::VariableContext *ctx);

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx);
    virtual void exitNumber(ParseRulesParser::NumberContext *ctx);

    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx);
    virtual void exitParens(ParseRulesParser::ParensContext *ctx);

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(ParseRulesParser::ConstantContext *ctx);
    virtual void exitConstant(ParseRulesParser::ConstantContext *ctx);

    //a function parser for definition any callback function for further calculations
    //{for example: Lg(sumproduct(__Ivs__, __n__))}
    virtual void enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx);
    virtual void exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx);

    //power operator {for example: __Ivs__^__j12__}
    virtual void enterPowerOp(ParseRulesParser::PowerOpContext *ctx);
    virtual void exitPowerOp(ParseRulesParser::PowerOpContext *ctx);

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx);
    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx);

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx);
    virtual void exitArray(ParseRulesParser::ArrayContext *ctx);

    //natural logarithm function {for example: Ln(Expr)}
    virtual void enterNatlog(ParseRulesParser::NatlogContext *ctx);
    virtual void exitNatlog(ParseRulesParser::NatlogContext *ctx);

    //decimal logarithm function {for example: Lg(Expr)}
    virtual void enterDeclog(ParseRulesParser::DeclogContext *ctx);
    virtual void exitDeclog(ParseRulesParser::DeclogContext *ctx);

    //based logarithm function {for example: Log(Expr, Expr)}
    virtual void enterBaselog(ParseRulesParser::BaselogContext *ctx);
    virtual void exitBaselog(ParseRulesParser::BaselogContext *ctx);

    //exponent function {for example: Exp(Expr)}
    virtual void enterExponent(ParseRulesParser::ExponentContext *ctx);
    virtual void exitExponent(ParseRulesParser::ExponentContext *ctx);

    //root square function {for example: Sqrt(Expr)}
    virtual void enterSquareroot(ParseRulesParser::SquarerootContext *ctx);
    virtual void exitSquareroot(ParseRulesParser::SquarerootContext *ctx);

    //sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
    //Variables are accepted, if are implemented as arrays.
    virtual void enterSumproduct(ParseRulesParser::SumproductContext *ctx);
    virtual void exitSumproduct(ParseRulesParser::SumproductContext *ctx);

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx);
    virtual void exitHdr(ParseRulesParser::HdrContext *ctx);
};

class ZoneListener: public BaseListener{
    ZoneListener(){

    }

    virtual void enterZone(ParseRulesParser::ZoneContext *ctx);
    virtual void exitZone(ParseRulesParser::ZoneContext *ctx);

    virtual void enterData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx);
    virtual void exitData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx);

    virtual void enterConst_volume(ParseRulesParser::Const_volumeContext *ctx);
    virtual void exitConst_volume(ParseRulesParser::Const_volumeContext *ctx);

    virtual void enterVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx);
    virtual void exitVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx);

    virtual void enterValues_volume(ParseRulesParser::Values_volumeContext *ctx);
    virtual void exitValues_volume(ParseRulesParser::Values_volumeContext *ctx);

    virtual void enterBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx);
    virtual void exitBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx);
};

class BoundTempListener: public BaseListener{
    BoundTempListener(){

    }

    virtual void enterBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx);
    virtual void exitBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx);

    virtual void enterEquations_bound(ParseRulesParser::Equations_boundContext *ctx);
    virtual void exitEquations_bound(ParseRulesParser::Equations_boundContext *ctx);

    virtual void enterBound_coefs(ParseRulesParser::Bound_coefsContext *ctx);
    virtual void exitBound_coefs(ParseRulesParser::Bound_coefsContext *ctx);

    virtual void enterValues_bound(ParseRulesParser::Values_boundContext* ctx);
    virtual void exitValues_bound(ParseRulesParser::Values_boundContext *ctx);

    
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

class Lexer: public ParseRulesLexer{
public:
    explicit Lexer(antlr4::ANTLRInputStream& stream):ParseRulesLexer(&stream)
    {
        token_stream_ = std::make_unique<antlr4::CommonTokenStream>(this);
    }

    void SetStdInputStream(antlr4::ANTLRInputStream& stream){
        this->setInputStream(&stream); 
    }

    antlr4::CommonTokenStream* GetCommonTokenStream() const{
        return token_stream_.get();
    }

private:
    std::unique_ptr<antlr4::CommonTokenStream> token_stream_;
    TypeFile type_;
};

class Parser: public ParseRulesParser{
public:
    Parser(std::istream& stream, TypeFile type):
        ParseRulesParser((lexer_ = std::make_unique<Lexer>(stream))->GetCommonTokenStream()),
        type_(type),
        stream_(stream)
        {
        input = lexer_->GetCommonTokenStream();

        switch (type_)
        {
        case TypeFile::ZONE:
            tree = std::unique_ptr<ZoneContext>(this->zone());
            listener_ = std::make_unique<ZoneListener>();
            break;
        case TypeFile::BOUNDS:
            tree = std::unique_ptr<Bound_temperatureContext>(this->bound_temperature());
            listener_ = std::make_unique<BoundTempListener>();
            break;
        default:
            listener_ = std::make_unique<ZoneListener>();
            break;
        }
        
        auto error_handler = std::make_shared<antlr4::ANTLRErrorStrategy>();
        this->setErrorHandler(error_handler);
        this->removeErrorListeners();

        tree = std::make_unique<antlr4::ParserRuleContext>();
    }

    std::istream& stream_;
    antlr4::ANTLRInputStream antlr_stream_;

    antlr4::CommonTokenStream* input;
    std::unique_ptr<Lexer> lexer_;
    std::unique_ptr<BaseListener> listener_;
    std::unique_ptr<ErrorListener> err_listener_;
    TypeFile type_;
    std::unique_ptr<antlr4::tree::ParseTree> tree;
};

#include <boost/json.hpp>
#include <boost/json/src.hpp>

class DataInitialize{

    DataInitialize(){

    }

    void Configure(){

    }

    void InitializeZones(){
        std::vector<std::future<Parser>> futures;
        for(std::string_view file:paths_.find(TypeFile::ZONE)->second){
            futures.push_back(std::async(std::launch::async,[&file](){
                std::ifstream&& stream = std::move(std::ifstream(std::filesystem::path(file)));
                return Parser(stream,TypeFile::ZONE);
            }));
        }
    }

    void InitializeBounds(){
        std::vector<std::future<Parser>> futures;
        for(std::string_view file:paths_.find(TypeFile::ZONE)->second){
            futures.push_back(std::async(std::launch::async,[&file](){
                std::ifstream&& stream = std::move(std::ifstream(std::filesystem::path(file)));
                return Parser(stream,TypeFile::ZONE);
            }));
        }
    }

    void SetStream(std::istream& stream){
        stream_.rdbuf(stream.rdbuf());
        antlr_stream_ = antlr4::ANTLRInputStream(stream_);
    }

    private:

    //vector for multithreading by-directory recursive file parsing with different specifications
    std::unordered_map<TypeFile,std::vector<std::string_view>> paths_;
    std::vector<Parser> parser_; 
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























