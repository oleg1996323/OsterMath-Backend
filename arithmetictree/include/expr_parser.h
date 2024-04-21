#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "def.h"
#include "data.h"
#include "expr_listener.h"
#include "expr_lexer.h"

//SignalizerStream (если finished() и переданы данные)

class Parser{
public:
    Parser(std::istream& stream, BaseData* data_base):
        antlr_stream_(stream),
        lexer_(antlr_stream_),
        input_(lexer_.GetCommonTokenStream()),
        base_parser_(input_),
        data_(std::move(std::shared_ptr<BaseData>(data_base))),
        stream_(stream)
{
    auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
    base_parser_.setErrorHandler(error_handler);
    base_parser_.removeErrorListeners();
    tree_ = std::unique_ptr<ParseRulesParser::ExpressionsContext>(base_parser_.expressions());
    listener_ = std::make_unique<BaseListener>(data_.get());
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
}

void parse_entry(){
    
    antlr_stream_.load(stream_);
    lexer_.setInputStream(&antlr_stream_);
    input_=lexer_.GetCommonTokenStream();
    base_parser_.setTokenStream(input_);
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
}
    
    antlr4::ANTLRInputStream antlr_stream_;
    Lexer lexer_;
    antlr4::CommonTokenStream* input_;
    ParseRulesParser base_parser_;

    std::shared_ptr<BaseData> data_;

    std::unique_ptr<BaseListener> listener_;
    std::unique_ptr<ErrorListener> err_listener_;
    std::unique_ptr<antlr4::tree::ParseTree> tree_;
    std::istream& stream_;
};