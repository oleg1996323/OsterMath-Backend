#pragma once
#include "detect_type_functionParser.h"
#include <functional>

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
        std::vector<PARSING_INFO*> childs_;
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
        uint32_t get_start() const;
        uint32_t get_stop() const;
        void set_start(uint32_t);
        void set_stop(uint32_t);
        PARSING_INFO* push_back_child(PARSING_INFO*);
        PARSING_INFO* push_back_next(PARSING_INFO*);
        bool operator==(const PARSING_INFO&);
    };

    __ParseSegmentation__(const std::string&);
    private:
    std::string expression_{};
    PARSING_INFO* parse_result_;
};

class ExpressionDynamicChangeManager{
    public:
    //any new result struct put("")
    void set_pos(uint32_t);
    void pos() const;

    private:
    uint32_t pos_=0;
};
class ExpressionSegmentModifyManager:
public __ParseSegmentation__,
public ExpressionDynamicChangeManager{
    private:
    public:
    ExpressionSegmentModifyManager(const std::string&,uint32_t);
    ExpressionSegmentModifyManager(const std::string&);
    template<typename... FUNC_ARGS>
    ExpressionSegmentModifyManager& modify_at_current_pos(std::function<void(FUNC_ARGS...)>);
};

__ParseSegmentation__::PARSING_INFO parse(const std::string&);
}

using ItemsParsingInfo = detail::__ParseSegmentation__::PARSING_INFO;
using ParseExpressionManager = detail::__ParseSegmentation__;