#pragma once
#include "types.h"
#include <functional>
#include <tuple>
#include <unordered_set>
#include <vector>

template<typename... ARGS>
using Function_t = std::function<Value_t(ARGS...)>;

template <typename T>
struct function_traits;

template<typename RETURN,typename... ARGS>
struct function_traits<std::function<RETURN(ARGS...)>>{
    static constexpr size_t arity = sizeof...(ARGS);

    template <size_t N>
    struct arg {
        static_assert(N < arity, "index is out of range");
        using type = typename std::tuple_element<N, std::tuple<ARGS...>>::type;
    };
};

template<typename... ARGS>
struct function_traits<Function_t<ARGS...>>{
    static constexpr size_t arity = sizeof...(ARGS);

    template <size_t N>
    struct arg {
        static_assert(N < arity, "index is out of range");
        using type = typename std::tuple_element<N, std::tuple<ARGS...>>::type;
    };
};

struct FunctionProxy{
    template<typename... ARGS>    
    void SetFunction(ARGS...){
        function_ = std::make_unique<Function_t<ARGS...>>();
    }

    template<typename... ARGS>
    Function_t<ARGS...>* GetFunction() const{
        return static_cast<Function_t<ARGS...>*>(function_.get());
    }

    std::unique_ptr<void> function_;
    std::unordered_set<std::string_view> vars_;
};