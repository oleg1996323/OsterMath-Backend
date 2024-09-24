#include "format.h"
#include <iomanip>

void FormattingData::set_precision(uint8_t prec){
    *stream_.get()<<std::setprecision(prec);
}

void FormattingData::set_format(OUTPUT_TYPE fmt){
    if(fmt==OUTPUT_TYPE::DEFAULT)
        *stream_.get()<<std::defaultfloat;
    else if(fmt==OUTPUT_TYPE::FIXED)
        *stream_.get()<<std::fixed;
    else if(fmt==OUTPUT_TYPE::SCIENTIFIC)
        *stream_.get()<<std::scientific;
}

void FormattingData::set_stream(std::ostream& stream){
    if(&stream!=stream_.get()){
        stream.copyfmt(*stream_.get());
        stream<<std::setprecision(get_precision());
        stream_->rdbuf(stream.rdbuf());
    }
}

uint8_t FormattingData::get_precision() const{
    return stream_->precision();
}

FormattingData::OUTPUT_TYPE FormattingData::get_type() const{
    auto flags = stream_->flags();
    if(flags&std::ios_base::floatfield)
        return OUTPUT_TYPE::DEFAULT;
    else if(flags&std::ios_base::fixed)
        return OUTPUT_TYPE::FIXED;
    else if(flags&std::ios_base::scientific)
        return OUTPUT_TYPE::SCIENTIFIC;
    else throw std::runtime_error("Unknown format");
}

std::ostream& FormattingData::get_stream() const{
    return *stream_.get();
}