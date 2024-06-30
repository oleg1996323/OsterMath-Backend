#pragma once
#include <stdexcept>
    /// <summary>
    /// Instead of recovering from exception {@code e}, re-throw it wrapped
    ///  in a <seealso cref="ParseCancellationException"/> so it is not caught by the
    ///  rule function catches.  Use <seealso cref="Exception#getCause()"/> to get the
    ///  original <seealso cref="RecognitionException"/>.
    /// </summary>

namespace exceptions{

enum EXCEPTION_TYPE{
    NOEXCEPT,
    PARSING,
    CYCLIC,
    UNQEQUAL_ARRAYS,
    UNKNOWN_TYPE_ARRAY,
    INCORRECT_TYPE_ARRAYS,
    DIVISION_ZERO,
    INVALID_TYPE_ARG,
    INVALID_NUMBER_ARGS
};

class Exception: public std::runtime_error{
    public:
    using std::runtime_error::runtime_error;
    //error abbreviation
    static const char* error_abbr();
    virtual const char* get_error() const = 0;
    virtual EXCEPTION_TYPE type() const = 0;
    virtual const char* get_prompt() const;
};

class ParsingError : public Exception {
    public:
    using Exception::Exception;
    ParsingError(const std::string& error);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class UnequalSizeArrays: public Exception{
    public:
    UnequalSizeArrays(const std::string& function_name);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class UnknownTypeArray: public Exception{
    public:
    UnknownTypeArray();
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class IncorrectTypeArrays: public Exception{
    public:
    using Exception::Exception;
    IncorrectTypeArrays(const std::string& type_expected);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class CyclicReference: public Exception{
    public:
    using Exception::Exception;
    CyclicReference(const std::string& var_name);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class DivisionZero: public Exception{
    public:
    using Exception::Exception;
    DivisionZero();
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class InvalidTypeOfArgument:public Exception{
    public:
    using Exception::Exception;
    InvalidTypeOfArgument(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class InvalidNumberOfArguments:public Exception{
    public:
    using Exception::Exception;
    InvalidNumberOfArguments(size_t);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

const char* get_except_abbr(EXCEPTION_TYPE);
}