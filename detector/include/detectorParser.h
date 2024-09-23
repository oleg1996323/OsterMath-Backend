#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "def.h"
#include "g"

class Lexer;
namespace bailerror{
class ErrorListener;
}
class BaseListener;
class BailErrorListener;
class BaseData;
class head_interactorParser;

namespace antlr4{
    class ParseTree;
    class CommonTokenStream;
    class ANTLRInputStream;
    namespace tree{
        class ParseTree;
    }
}

class Parser{
public:
    Parser(std::istream& stream, BaseData* data_base);

    void set_stream(std::istream& stream);

    void parse_entry();

    private:
    struct ParseItems{
        ParseItems(std::istream& stream, BaseData* data_base);

        ~ParseItems();

        antlr4::ANTLRInputStream* antlr_stream_;
        Lexer* lexer_;
        antlr4::CommonTokenStream* input_;
        head_interactorParser* base_parser_;
        BailErrorListener* error_listener;
        BaseListener* listener_;
        bailerror::ErrorListener* err_listener_;
        antlr4::tree::ParseTree* tree_;
    };
    std::unique_ptr<ParseItems> items_;
    BaseData* data_;
    std::unique_ptr<std::istream> stream_;
    void __init__();
};