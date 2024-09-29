#pragma once
#include <stdexcept>
#include "abstract_event.h"
    /// <summary>
    /// Instead of recovering from exception {@code e}, re-throw it wrapped
    ///  in a <seealso cref="ParseCancellationException"/> so it is not caught by the
    ///  rule function catches.  Use <seealso cref="Exception#getCause()"/> to get the
    ///  original <seealso cref="RecognitionException"/>.
    /// </summary>

namespace exceptions{

enum EXCEPTION_TYPE{
    NOEXCEPT,
    EXCEPTION,
    PARSING,
    CYCLIC,
    UNQEQUAL_ARRAYS,
    UNKNOWN_TYPE_ARRAY,
    INCORRECT_TYPE_ARRAYS,
    DIVISION_ZERO,
    INVALID_TYPE_ARG,
    INVALID_NUMBER_ARGS,
    VARIABLE_DONT_EXISTS,
    NODE_DONT_EXISTS
};

class AbstractException: public std::runtime_error, public AbstractEvent{
    public:
    using std::runtime_error::runtime_error;
    AbstractException(const char* arg);
    virtual ~AbstractException() = default;
    //error abbreviation
    static const char* error_abbr();
    virtual const char* get_error() const = 0;
    virtual EXCEPTION_TYPE type() const = 0;
    virtual const char* get_prompt() const;
    private:
    virtual const char* __get_title__() const override;
    virtual size_t __type__() const override;
    virtual const char* __get_prompt__() const override;
};

class Exception: public AbstractException{
    public:
    using AbstractException::AbstractException;
    //error abbreviation
    static const char* error_abbr();
    virtual const char* get_error() const{
        return "";
    };
    virtual EXCEPTION_TYPE type() const{
        return EXCEPTION;
    };
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

class VariableDontExists:public Exception{
    public:
    using Exception::Exception;
    VariableDontExists(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

class NodeChildDontExists:public Exception{
    public:
    using Exception::Exception;
    NodeChildDontExists(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const;
    virtual EXCEPTION_TYPE type() const;
    virtual const char* get_prompt() const;
};

const char* get_except_abbr(EXCEPTION_TYPE);
}