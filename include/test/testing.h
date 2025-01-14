#pragma once
#ifdef DEBUG
#include "log_duration.h"
#include <gtest/gtest.h>
#include <type_traits>

// template<typename L_T,typename R_T>
// requires (std::declval<std::decay_t<L_T>>()==std::declval<std::decay_t<R_T>>())
// testing::AssertionResult is_equal(const char* expr,L_T&& lhs,R_T&& rhs){
//     if(lhs==rhs)
//         return testing::AssertionSuccess();
//     else{
//         testing::AssertionResult res = testing::AssertionFailure();
//         res << "Expected: " << lhs << " = "<< rhs"\n  Actual: it's " << n;
//         return  res;
//     }
// }

// #define EXPECT_EQ_LOGGER(stream,lhs,rhs) EXPECT_PRED_FORMAT2(is_equal, val1, val2);
// EXPECT_PRED_FORMAT1

// To use this class with EXPECT_PRED_FORMAT assertions such as:
//
//   // Verifies that Foo() returns an even number.
//   EXPECT_PRED_FORMAT1(IsEven, Foo());
//
// you need to define:
//
//   testing::AssertionResult IsEven(const char* expr, int n) {
//     if ((n % 2) == 0)
//       return testing::AssertionSuccess();
//     else
//       return testing::AssertionFailure()
//         << "Expected: " << expr << " is even\n  Actual: it's " << n;



void Test_Correct_Sum_Result_For_Array();

void Test_Correct_SumProduct_Result_For_Array();

void Test_Correct_Product_Result_For_Array();

void Test_Simple_Arithmetic_With_Variable();

void Test_Range_Operation_With_Var_Arrays();

void Testing();

#endif