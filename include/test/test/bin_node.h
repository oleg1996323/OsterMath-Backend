#pragma once

namespace node_bin::test{
    bool Test_Operation_Constructor();
    bool Test_Copy_Constructor();
    bool Test_Move_Constructor(); //check constantly if deleted
    bool Test_Type();
    bool Test_Execute();
    bool Test_Execute_id();
    bool Test_LhsRhs_Cache();
    bool Test_LhsRhs_Cache_id();
    bool Test_Operation();
    bool Test_Exceptions();
    bool Test_Insert_Back();
    bool Test_Insert();
    bool Test_Replace();
    bool Test_Begins();
    bool Test_Ends();
    bool Test_is_Numeric();
    bool Test_is_String();
    bool Test_is_Array();
    bool Test_Print_Text();
    bool Test_Print_Result();
    bool Test_Error_Checking();
    bool Test_Calculate();
}