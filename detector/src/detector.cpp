#include "detector.h"
#include "detectorLexer.h"
#include "detectorListener.h"
#include "BaseErrorListener.h"
#include "BailErrorStrategy.h"

namespace detail{
    __ParseSegmentation__::__ParseSegmentation__(const std::string&){

    }
    
    ItemsParsingInfo::PARSING_INFO::PARSING_INFO(PARSING_INFO* prev):
    prev_(prev){}

    ItemsParsingInfo& ItemsParsingInfo::init(uint32_t start, uint32_t stop){
        start_ = start;
        stop_ = stop;
        initialized_ = true;
        return *this;
    }

    bool ItemsParsingInfo::operator==(const PARSING_INFO& other){
        return  initialized_ || other.initialized_?
                (initialized_&&other.initialized_?
                (start_==other.start_ &&
                stop_==other.stop_ &&
                type_==other.type_ &&
                (next_ || other.next_)?(next_&&other.next_?*next_==*other.next_:false):true):false):true;
    }

    void ItemsParsingInfo::push_back(PARSING_INFO* ptr){
        assert(ptr);
        if(next_)
            next_->push_back(ptr);
        else next_ = ptr;
    }

    ItemsParsingInfo::~PARSING_INFO(){
        if(next_)
            delete next_;
    }

    ItemsParsingInfo parse(const std::string& expression){
        std::stringstream stream;
        stream<<expression;
        antlr4::ANTLRInputStream* antlr_stream_ = new antlr4::ANTLRInputStream(stream);
        Lexer* lexer_ = new Lexer(*antlr_stream_);
        antlr4::CommonTokenStream* input_;
        detect_type_functionParser* base_parser_;
        antlr4::BaseErrorListener* error_listener;
        BaseListener* listener_;
        antlr4::tree::ParseTree* tree_;
        input_ = lexer_->GetCommonTokenStream();
        base_parser_ = new detect_type_functionParser(input_);
        listener_ = new BaseListener();
        error_listener = new antlr4::BaseErrorListener();
        lexer_->removeErrorListeners();
        lexer_->addErrorListener(error_listener);
        auto error_handler = std::make_shared<antlr4::DefaultErrorStrategy>();
        base_parser_->setErrorHandler(error_handler);
        base_parser_->removeErrorListeners();
        tree_ = base_parser_->input();
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_,tree_);
        ItemsParsingInfo result = *reinterpret_cast<ItemsParsingInfo*>(listener_->get_info());
        delete antlr_stream_;
        delete lexer_;
        delete base_parser_;
        delete listener_;
        delete error_listener;
        return result;
    }
}