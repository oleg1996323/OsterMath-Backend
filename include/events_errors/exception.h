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

class Exception: public std::runtime_error, public AbstractEvent{
    virtual const char* __get_abbr__() const override final;
    public:
    using std::runtime_error::runtime_error;
    //error abbreviation
    explicit Exception(const char* arg);
    explicit Exception(const std::string& arg);
    virtual ~Exception() = default;
    inline static const char* error_abbr(){
        return "#ERR!";
    }
    inline virtual const char* get_error() const{
        return "Error occured!";
    };
    inline virtual EXCEPTION_TYPE type() const{
        return EXCEPTION;
    };
    virtual const char* get_prompt() const;
    private:
    virtual const char* __get_title__() const override;
    virtual size_t __type__() const override;
    virtual const char* __get_prompt__() const override;
};

class ParsingError : public Exception {
    public:
    using Exception::Exception;
    ParsingError(const std::string& error);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class UnequalSizeArrays: public Exception{
    public:
    UnequalSizeArrays(const std::string& function_name);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class UnknownTypeArray: public Exception{
    public:
    UnknownTypeArray();
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class IncorrectTypeArrays: public Exception{
    public:
    using Exception::Exception;
    IncorrectTypeArrays(const std::string& type_expected);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class CyclicReference: public Exception{
    public:
    using Exception::Exception;
    CyclicReference(const std::string& var_name);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class DivisionZero: public Exception{
    public:
    using Exception::Exception;
    DivisionZero();
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class InvalidTypeOfArgument:public Exception{
    public:
    using Exception::Exception;
    InvalidTypeOfArgument(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class InvalidNumberOfArguments:public Exception{
    public:
    using Exception::Exception;
    InvalidNumberOfArguments(size_t);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class VariableDontExists:public Exception{
    public:
    using Exception::Exception;
    VariableDontExists(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

class NodeChildDontExists:public Exception{
    public:
    using Exception::Exception;
    NodeChildDontExists(const std::string&);
    static const char* error_abbr();
    virtual const char* get_error() const override;
    virtual EXCEPTION_TYPE type() const override;
    virtual const char* get_prompt() const override;
};

const char* get_except_abbr(EXCEPTION_TYPE);
}