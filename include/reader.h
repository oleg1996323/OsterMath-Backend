#include <fstream>
#include <filesystem>
#include "exception.h"
#include "def.h"
#include "ParseRulesLexer.h"
#include "ParseRulesListener.h"
#include "ParseRulesParser.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <functional>
#include <memory>

using namespace boost::multiprecision;

enum class TypeFile{

    
};



//в парсер рассмотреть вложенные функции func(func()) с рекурсией парсинга

struct CallbackEquation{

    template<typename... ARGS>
    std::function<cpp_dec_float_50(ARGS...)> function(ARGS...);
};

class DataInitialize{

    void InitializeZones(const std::string& path);

    void InitializeBounds();

    private:

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
    Lexer(std::ifstream& file, TypeFile type):ParseRulesLexer(&antlr4::ANTLRInputStream(file)){
        token_stream_ = std::make_unique<antlr4::CommonTokenStream>(this);
    }

    void SetStdInputStream(std::istream& stream){
        this->setInputStream(&antlr4::ANTLRInputStream(stream)); 
    }

private:

    std::unique_ptr<antlr4::CommonTokenStream> token_stream_;
};

class Parser: public ParseRulesParser{
public:
    Parser(std::ifstream& file, TypeFile type):lexer_(file, type), ParseRulesParser(&antlr4::CommonTokenStream(&lexer_)){
        auto error_handler = std::make_shared<antlr4::ANTLRErrorStrategy>();
        this->setErrorHandler(error_handler);
        this->removeErrorListeners();
    }

    antlr4::TokenStream* input;
    Lexer lexer_;
    antlr4::tree::ParseTree* tree = this->zone();
};



class BaseListener: public ParseRulesListener{

    protected:
    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx);
    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext *ctx);

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) = 0;
    virtual void exitVariable(ParseRulesParser::VariableContext *ctx) = 0;

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx) = 0;
    virtual void exitNumber(ParseRulesParser::NumberContext *ctx) = 0;

    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx) = 0;
    virtual void exitParens(ParseRulesParser::ParensContext *ctx) = 0;

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(ParseRulesParser::ConstantContext *ctx) = 0;
    virtual void exitConstant(ParseRulesParser::ConstantContext *ctx) = 0;

    //a function parser for definition any callback function for further calculations
    //{for example: Lg(sumproduct(__Ivs__, __n__))}
    virtual void enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) = 0;
    virtual void exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) = 0;

    //power operator {for example: __Ivs__^__j12__}
    virtual void enterPowerOp(ParseRulesParser::PowerOpContext *ctx) = 0;
    virtual void exitPowerOp(ParseRulesParser::PowerOpContext *ctx) = 0;

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) = 0;
    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) = 0;

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) = 0;
    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) = 0;

    //parentheses for function's arithmetic priorities definition
    virtual void enterPares(ParseRulesParser::ParesContext *ctx) = 0;
    virtual void exitPares(ParseRulesParser::ParesContext *ctx) = 0;

    //natural logarithm function {for example: Ln(Expr)}
    virtual void enterNatlog(ParseRulesParser::NatlogContext *ctx) = 0;
    virtual void exitNatlog(ParseRulesParser::NatlogContext *ctx) = 0;

    //decimal logarithm function {for example: Lg(Expr)}
    virtual void enterDeclog(ParseRulesParser::DeclogContext *ctx) = 0;
    virtual void exitDeclog(ParseRulesParser::DeclogContext *ctx) = 0;

    //based logarithm function {for example: Log(Expr, Expr)}
    virtual void enterBaselog(ParseRulesParser::BaselogContext *ctx) = 0;
    virtual void exitBaselog(ParseRulesParser::BaselogContext *ctx) = 0;

    //exponent function {for example: Exp(Expr)}
    virtual void enterExponent(ParseRulesParser::ExponentContext *ctx) = 0;
    virtual void exitExponent(ParseRulesParser::ExponentContext *ctx) = 0;

    //root square function {for example: Sqrt(Expr)}
    virtual void enterSquareroot(ParseRulesParser::SquarerootContext *ctx) = 0;
    virtual void exitSquareroot(ParseRulesParser::SquarerootContext *ctx) = 0;

    //sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
    //Variables are accepted, if are implemented as arrays.
    virtual void enterSumproduct(ParseRulesParser::SumproductContext *ctx) = 0;
    virtual void exitSumproduct(ParseRulesParser::SumproductContext *ctx) = 0;

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx) = 0;
    virtual void exitHdr(ParseRulesParser::HdrContext *ctx) = 0;
};

class ZoneListener: public BaseListener{
    ZoneListener(){

    }

    virtual void enterZone(ParseRulesParser::ZoneContext *ctx) = 0;
    virtual void exitZone(ParseRulesParser::ZoneContext *ctx) = 0;

    virtual void enterData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx) = 0;
    virtual void exitData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx) = 0;

    virtual void enterConst_volume(ParseRulesParser::Const_volumeContext *ctx) = 0;
    virtual void exitConst_volume(ParseRulesParser::Const_volumeContext *ctx) = 0;

    virtual void enterVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx) = 0;
    virtual void exitVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx) = 0;

    virtual void enterValues_volume(ParseRulesParser::Values_volumeContext *ctx) = 0;
    virtual void exitValues_volume(ParseRulesParser::Values_volumeContext *ctx) = 0;

    virtual void enterBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx) = 0;
    virtual void exitBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx) = 0;
};

class BoundTempListener: public BaseListener{
    BoundTempListener(){

    }

    virtual void enterBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) = 0;
    virtual void exitBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) = 0;

    virtual void enterEquations_bound(ParseRulesParser::Equations_boundContext *ctx) = 0;
    virtual void exitEquations_bound(ParseRulesParser::Equations_boundContext *ctx) = 0;

    virtual void enterBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) = 0;
    virtual void exitBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) = 0;

    virtual void enterValues(ParseRulesParser::ValuesContext *ctx) = 0;
    virtual void exitValues(ParseRulesParser::ValuesContext *ctx) = 0;

    
};





















