#include <iostream>
#include <unordered_map>
#include <string_view>
#include <memory>
#include <sstream>


//one object class must be as global for anonymous expressions and for DEFAULT cases
class FormattingData{
    
public:
    enum class OUTPUT_TYPE{
        DEFAULT,
        SCIENTIFIC,
        FIXED
    };
    //for numbers with forced floating points (like 10.000)
    void set_precision(uint8_t prec);

    void set_format(OUTPUT_TYPE fmt);

    void set_stream(std::ostream& stream);

    uint8_t get_precision() const;

    OUTPUT_TYPE get_type() const;

    std::ostream& get_stream() const;

protected:
    std::unique_ptr<std::ostream> stream_=std::make_unique<std::ostringstream>(std::ostringstream{});
};