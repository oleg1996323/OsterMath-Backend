#pragma once
#include "arithmetic_types.h"
#include "detect_type_functionParser.h"

namespace expression{
namespace item{
    enum ITEM_TYPE{
        UNKNOWN,
        VARIABLE,
        PARENTHESES,
        UNARY,
        BINARY,
        RANGE_FUNCTION,
        FUNCTION,
        ARRAY,
        VALUE
    };
}
class __ParseSegmentation__{
    struct PARSING_INFO{
        uint32_t start_ = 0;
        uint32_t stop_ = 0-1;
        std::unique_ptr<PARSING_INFO> next_;
        item::ITEM_TYPE;
    }
    public:
    
    __ParseSegmentation__(){
        Node node = Node();
    }
    private:
    
};
//TODO add enums from arithmetic_types.h

item::ITEM_TYPE parse(std::string expression);
}