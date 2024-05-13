#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
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
        data_(data_base),
        listener_(data_base)
{
    set_stream(stream);
    auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
    base_parser_.setErrorHandler(error_handler);
    base_parser_.removeErrorListeners();
    tree_ = base_parser_.input();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener_,tree_);
}

void set_stream(std::istream& stream){
    stream_->rdbuf(stream.rdbuf());
}

void parse_entry(){
    lexer_.reset();
    base_parser_.reset();

    antlr_stream_.load(*stream_.get());
    lexer_.setInputStream(&antlr_stream_);
    input_=lexer_.GetCommonTokenStream();
    base_parser_.setTokenStream(input_);
    tree_=base_parser_.input();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener_,tree_);
}
    
    antlr4::ANTLRInputStream antlr_stream_;
    Lexer lexer_;
    antlr4::CommonTokenStream* input_;
    ParseRulesParser base_parser_;

    BaseData* data_;

    BaseListener listener_;
    ErrorListener err_listener_;
    antlr4::tree::ParseTree* tree_;
    std::unique_ptr<std::istream> stream_=std::make_unique<std::istringstream>(std::istringstream{});
};
/*#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "def.h"
#include "data.h"
#include "expr_listener.h"
#include "expr_lexer.h"

//SignalizerStream (если finished() и переданы данные)

class Parser{
struct ParseItems{
    ParseItems(std::istream& stream):
        antlr_stream_(stream),
        lexer_(antlr_stream_),
        input_(lexer_.GetCommonTokenStream()),
        base_parser_(input_),
        listener_(data_base){}

    antlr4::ANTLRInputStream antlr_stream_;
    Lexer lexer_;
    antlr4::CommonTokenStream* input_;
    ParseRulesParser base_parser_;

    BaseListener listener_;
    ErrorListener err_listener_;
    antlr4::tree::ParseTree* tree_;
};

public:
    Parser(std::istream& stream, BaseData* data_base):
        data_(data_base)
{
    items_=std::make_unique<ParseItems>(stream);
    set_stream(stream);
    auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
    base_parser_.setErrorHandler(error_handler);
    base_parser_.removeErrorListeners();
    tree_ = base_parser_.input();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener_,tree_);
}

void set_stream(std::istream& stream){
    stream_->rdbuf(stream.rdbuf());
}

void read_new(){
    lexer_.reset();
    
    if(tree_!=nullptr)
        delete tree_->;
    parse_entry();
}

void parse_entry(){
    __init__();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener_,tree_);
}

    std::unique_ptr<ParseItems> items_;
    BaseData* data_;
    std::unique_ptr<std::istream> stream_=std::make_unique<std::istringstream>(std::istringstream{});

    private:

    void __init__(){
        antlr_stream_.load(*stream_.get());
        lexer_.reset();
        lexer_.setInputStream(&antlr_stream_);
        input_=lexer_.GetCommonTokenStream();
        base_parser_.setTokenStream(input_);
        
    }
};*/