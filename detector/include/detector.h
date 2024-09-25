#pragma once
#include "detect_type_functionParser.h"

namespace detail{
namespace item{
    enum class ITEM_TYPE{
        NONE,
        UNKNOWN,
        VARIABLE,
        PARENTHESES,
        UNARY,
        BINARY,
        RANGE_FUNCTION,
        FUNCTION,
        ARRAY,
        VALUE,
        LITERAL,
        STRING
    };
    enum class FUNCTION{
        NONE,
        LN,
        LG,
        LOG_X,
        FACTORIAL,
        SIN,
        COS,
        ASIN,
        ACOS,
        SQRT,
        EXP,
        SUM,
        PRODUCT,
        SUMPRODUCT,
        SUM_I,
        PRODUCT_I
    };
}
class __ParseSegmentation__{
    public:
    struct PARSING_INFO{
        private:
        
        uint32_t start_ = 0;
        uint32_t stop_ = 0;
        public:
        PARSING_INFO* prev_ = nullptr;
        PARSING_INFO* next_ = nullptr;
        bool initialized_ = false;
        item::ITEM_TYPE type_=item::ITEM_TYPE::NONE;
        item::FUNCTION func_=item::FUNCTION::NONE;

        PARSING_INFO(PARSING_INFO*);
        ~PARSING_INFO();
        PARSING_INFO& init(uint32_t start, uint32_t stop);
        void push_back(PARSING_INFO*);
        bool operator==(const PARSING_INFO&);
    };

    __ParseSegmentation__(const std::string&);
    private:
    std::string expression_{};
    PARSING_INFO* parse_result_;
};

class ExpressionDynamicChangeManager:public __ParseSegmentation__{
    public:
    //any new result struct put("")
    void setPos();
};

__ParseSegmentation__::PARSING_INFO parse(const std::string&);
}

using ItemsParsingInfo = detail::__ParseSegmentation__::PARSING_INFO;
using ParseExpressionManager = detail::__ParseSegmentation__;