#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include "def.h"
#include "expr_listener.h"
#include "expr_lexer.h"

class Parser: public ParseRulesParser{
public:
    Parser(std::istream& stream, TypeFile type):
        ParseRulesParser((lexer_ = std::make_unique<Lexer>((antlr_stream_=antlr4::ANTLRInputStream(stream))))->GetCommonTokenStream()),
        type_(type),
        stream_(stream)
    {
        input_ = lexer_->GetCommonTokenStream();
        auto error_handler = std::make_shared<antlr4::BailErrorStrategy>();
        this->setErrorHandler(error_handler);
        this->removeErrorListeners();

        switch (type_)
        {
        case TypeFile::ZONE:
            tree_ = std::unique_ptr<ZoneContext>(this->zone());
            listener_ = std::make_unique<ZoneListener>();
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
            break;
        case TypeFile::BOUNDS:
            tree_ = std::unique_ptr<Bound_temperatureContext>(this->bound_temperature());
            listener_ = std::make_unique<BoundTempListener>();
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
            break;
        default:
            tree_ = std::unique_ptr<ZoneContext>(this->zone());
            listener_ = std::make_unique<ZoneListener>();
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_.get(),tree_.get());
            break;
        }
    }

    Parser(Parser&& other):ParseRulesParser(other.input_),
        type_(other.type_),
        stream_(other.stream_)
    {
        lexer_ = std::move(other.lexer_);
        listener_ = std::move(other.listener_);
        err_listener_ = std::move(other.err_listener_);
        tree_ = std::move(other.tree_);
    }
    
    antlr4::ANTLRInputStream antlr_stream_;

    antlr4::CommonTokenStream* input_;
    std::unique_ptr<Lexer> lexer_;
    std::unique_ptr<BaseListener> listener_;
    std::unique_ptr<ErrorListener> err_listener_;
    std::unique_ptr<antlr4::tree::ParseTree> tree_;
    TypeFile type_;
    std::istream& stream_;
};