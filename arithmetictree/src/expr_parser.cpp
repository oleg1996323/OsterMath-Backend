#include "expr_parser.h"
#include "exception.h"
#include "expr_listener.h"
#include "expr_lexer.h"
#include "data.h"

Parser::ParseItems::ParseItems(std::istream& stream, BaseData* data_base):
    antlr_stream_(new antlr4::ANTLRInputStream(stream)),
    lexer_(new Lexer(*antlr_stream_)),
    input_(lexer_->GetCommonTokenStream()),
    base_parser_(new ParseRulesParser(input_)),
    listener_(new BaseListener(data_base)),
    err_listener_(new ErrorListener()){
        lexer_->removeErrorListeners();
        lexer_->addErrorListener(err_listener_);
        auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
        base_parser_->setErrorHandler(error_handler);
        base_parser_->removeErrorListeners();
        tree_ = base_parser_->input();
    }

Parser::ParseItems::~ParseItems(){
    delete antlr_stream_;
    delete lexer_;
    delete base_parser_;
    delete listener_;
    delete err_listener_;
}

void Parser::__init__(){
    items_ = std::make_unique<ParseItems>(*stream_.get(), data_);
}

Parser::Parser(std::istream& stream, BaseData* data_base):
        data_(data_base),
        stream_(std::make_unique<std::istringstream>(std::istringstream{}))
{
    set_stream(stream);
    try{
        parse_entry();
    }
    catch(const ParsingError& err){
        std::cout<<"Input error. Prompt: "<<err.what()<<std::endl;
    }
    catch(const antlr4::ParseCancellationException& err){
        std::cout<<"Input error."<<std::endl;
    }
}

void Parser::parse_entry(){
    __init__();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(items_->listener_,items_->tree_);
}

void Parser::set_stream(std::istream& stream){
    stream_->rdbuf(stream.rdbuf());
}