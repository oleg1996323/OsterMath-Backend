#include "def.h"
#include "types.h"
#include "arithmetic_tree.h"

// bool __types_proxy__::is_arithmetic_tree() const{
//     return std::holds_alternative<ArithmeticTree>(get());
// }

// bool __types_proxy__::is_value() const{
//     return std::holds_alternative<Value_t>(get());
// }

// bool __types_proxy__::is_string() const{
//     return std::holds_alternative<std::string>(get());
// }

// bool __types_proxy__::is_array() const{
//     return std::holds_alternative<Array_t>(get());
// }

// bool __types_proxy__::is_undef() const{
//     return std::holds_alternative<std::monostate>(get());
// }

// __types__& __types_proxy__::get(){
//     return *this;
// }

// const __types__& __types_proxy__::get() const{
//     return *this;
// }

// std::ostream& operator<<(std::ostream& stream, const __types_proxy__& var)
// {
//     std::visit([&stream](const auto& x) { stream << x; }, var);
//     return stream;
// }