#include "detector.h"
#include "detectorLexer.h"
#include "detectorListener.h"
#include "BaseErrorListener.h"
#include "BailErrorStrategy.h"
#include "def.h"

namespace detail{
    __ParseSegmentation__::__ParseSegmentation__(const std::string& text):
    expression_(text){

    }
    
    ItemsParsingInfo::PARSING_INFO::PARSING_INFO(ItemsParsingInfo* prev):
    prev_(prev){
        ++count;
        std::cout<<count<<std::endl;
    }

    ItemsParsingInfo& ItemsParsingInfo::init(uint32_t start, uint32_t stop){
        start_ = start;
        stop_ = stop;
        initialized_ = true;
        return *this;
    }

    bool ItemsParsingInfo::operator==(const ItemsParsingInfo& other){
        return  initialized_ || other.initialized_?
                (initialized_&&other.initialized_?
                (start_==other.start_ &&
                stop_==other.stop_ &&
                type_==other.type_ &&
                (next_ || other.next_)?(next_&&other.next_?*next_==*other.next_:false):true):false):true;
    }

    ItemsParsingInfo* ItemsParsingInfo::push_back_next(ItemsParsingInfo* ptr){
        assert(ptr);
        if(next_)
            return next_->push_back_next(ptr);
        else next_ = ptr;
        return next_;
    }

    ItemsParsingInfo* ItemsParsingInfo::push_back_child(ItemsParsingInfo* ptr){
        assert(ptr);
        return childs_.emplace_back(ptr);
    }

    void ItemsParsingInfo::set_start(uint32_t start_pos){
        start_ = start_pos;
    }
    void ItemsParsingInfo::set_stop(uint32_t stop_pos){
        stop_ = stop_pos;
    }

    ItemsParsingInfo::~PARSING_INFO(){
        --count;
        std::cout<<count<<std::endl;
        if(next_)
            delete next_;
        if(!childs_.empty()){
            for(ItemsParsingInfo* child:childs_)
                delete child;
        }
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
        tree_ = base_parser_->line_input();
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener_,tree_);
        ItemsParsingInfo* result = nullptr;
        listener_->swap_info(&result);
        delete antlr_stream_;
        delete lexer_;
        delete base_parser_;
        delete listener_;
        delete error_listener;
        return *result;
    }
}