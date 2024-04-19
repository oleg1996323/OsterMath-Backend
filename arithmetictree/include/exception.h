#pragma once
#include <stdexcept>

class ParsingError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class EmptyVal: public std::logic_error{
    using std::logic_error::logic_error;
};

class EmptyArray: public std::logic_error{
    using std::logic_error::logic_error;
};

class UndefinedFunction: public std::logic_error{
    using std::logic_error::logic_error;
};

class VariableAlreadyExists: public std::logic_error{
    using std::logic_error::logic_error;
};