#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "exception.h"
#include "def.h"
#include "data.h"
#include "expr_listener.h"
#include "expr_lexer.h"

class Parser{
struct ParseItems{
    ParseItems(std::istream& stream, BaseData* data_base):
        antlr_stream_(stream),
        lexer_(antlr_stream_),
        input_(lexer_.GetCommonTokenStream()),
        base_parser_(input_),
        listener_(data_base){
            lexer_.removeErrorListeners();
            lexer_.addErrorListener(&err_listener_);
            auto error_handler = std::make_shared<antlr4::DefaultErrorStrategy>();
            base_parser_.setErrorHandler(error_handler);
            base_parser_.removeErrorListeners();
            tree_ = base_parser_.input();
        }

    antlr4::ANTLRInputStream antlr_stream_;
    Lexer lexer_;
    antlr4::CommonTokenStream* input_;
    ParseRulesParser base_parser_;
    BailErrorListener error_listener;
    BaseListener listener_;
    ErrorListener err_listener_;
    antlr4::tree::ParseTree* tree_;
};

public:
    Parser(std::istream& stream, BaseData* data_base):
        data_(data_base)
{
    set_stream(stream);
    parse_entry();
}

void set_stream(std::istream& stream){
    stream_->rdbuf(stream.rdbuf());
}

void parse_entry(){
    __init__();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&items_->listener_,items_->tree_);
}

    std::unique_ptr<ParseItems> items_;
    BaseData* data_;
    std::unique_ptr<std::istream> stream_=std::make_unique<std::istringstream>(std::istringstream{});

    private:

    void __init__(){
        items_ = std::make_unique<ParseItems>(*stream_.get(), data_);
    }
};