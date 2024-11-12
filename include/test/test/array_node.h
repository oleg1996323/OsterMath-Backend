#pragma once
#include <gtest/gtest.h>


namespace node_array::test{
bool Size_Constructor();
bool Copy_Constructor();
bool Move_Constructor(); //check constantly if deleted
bool Move_SharedPtrVal_Constructor();
bool Copy_SharedPtrVal_Constructor();
bool Operator_Eq();
bool Type();
bool Execute();
bool Execute_id();
bool Cached_Result();
bool Cached_Result_id();
bool Insert_Back();
bool Insert();
bool Replace();
bool Begins();
bool Ends();
bool is_Numeric();
bool is_String();
bool is_Array();
bool Print_Text();
bool Print_Result();

void Test(){
    TEST(ArrayNode__SizeConstructor,SizeConstructor);
    
}
}

