#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "def.h"
#include "data.h"
#include "expr_listener.h"
#include "expr_lexer.h"

class Parser: public ParseRulesParser{
public:
    Parser(std::istream& stream, BaseData* data_base):
    ParseRulesParser((lexer_ = std::make_unique<Lexer>((antlr_stream_=antlr4::ANTLRInputStream(stream))))->GetCommonTokenStream()),
    data_(data_base),
    stream_(stream)
{
    input_ = lexer_->GetCommonTokenStream();
    auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
    this->setErrorHandler(error_handler);
    this->removeErrorListeners();
    tree_ = std::unique_ptr<ExprContext>(this->expr());
    listener_ = std::make_unique<BaseListener>(data_.get());
}

    Parser(Parser&& other):ParseRulesParser(other.input_),
    stream_(other.stream_)
{
    lexer_ = std::move(other.lexer_);
    listener_ = std::move(other.listener_);
    err_listener_ = std::move(other.err_listener_);
    tree_ = std::move(other.tree_);
    data_ = std::move(other.data_);
}

void parse_entry(){
    return antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
}
    
    antlr4::ANTLRInputStream antlr_stream_;
    antlr4::CommonTokenStream* input_;

    std::shared_ptr<BaseData> data_;
    std::unique_ptr<Lexer> lexer_;
    std::unique_ptr<BaseListener> listener_;
    std::unique_ptr<ErrorListener> err_listener_;
    std::unique_ptr<antlr4::tree::ParseTree> tree_;
    std::istream& stream_;
};