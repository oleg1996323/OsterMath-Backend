#pragma once

namespace node_function::test{
    bool Test_Operation_Constructor();
    bool Test_Size_Operation_Constructor();
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

    std::shared_ptr<Node> child(size_t id) const;
    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }
    inline bool is_array_function() const{
        return array_type_function;
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() override;
    virtual Result execute(size_t index) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    FUNCTION_OP operation() const;
    private:
    FUNCTION_OP operation_;
    bool array_type_function;