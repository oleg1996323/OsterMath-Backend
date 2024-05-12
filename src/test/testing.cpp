#include "test/testing.h"
#include "data.h"

#ifdef DEBUG

void Test_Correct_Sum_Result_For_Array(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(__I__=[__A__,__B__]
__A__=sum(__C__,__D__)
__B__=2
__C__=[2,2,2]
__D__=[2,2,2]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    output<<data->get("__I__")->get()<<std::endl;
    std::cout<<output.str()<<std::endl;
    assert(output.str() == 
R"([12 2]
)");
}

void Test_Correct_SumProduct_Result_For_Array(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(__I__=[__A__,__B__]
__A__=sumproduct(__C__,__D__)
__B__=2
__C__=[500,200,100]
__D__=[500,200,100]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    // output<<data->get("__I__")->get()<<std::endl;
    data->get("__I__")->set_stream(output);
    data->get("__I__")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(output.str() == 
R"([300000 2]
)");
}

void Test_Correct_Product_Result_For_Array(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(__I__=[__A__,__B__]
__A__=product(__C__,__D__)
__B__=2
__C__=[10,10,10]
__D__=[10,10,10]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("__I__")->print();
    data->get("__I__")->set_stream(output);
    data->get("__I__")->set_format(FormattingData::OUTPUT_TYPE::FIXED);
    data->get("__I__")->set_precision(0);
    data->get("__I__")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(output.str() == 
R"([1000000 2]
)");
}

void Test_Simple_Arithmetic_With_Variable(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(__I__=3*2+3^2
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("__I__")->print();
    data->get("__I__")->set_stream(output);
    data->get("__I__")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(output.str() == 
R"(15
)");
}

void Test_Range_Operation_With_Var_Arrays(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(__I__=SUMPRODUCT_I(__A__,__B__)
__A__=[2,2,2]
__B__=[2,2,2]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("__I__")->print();
    data->get("__I__")->set_stream(output);
    data->get("__I__")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(output.str() == 
R"(12
)");
}

void Testing(){
    Test_Correct_Sum_Result_For_Array();
    Test_Correct_SumProduct_Result_For_Array();
    Test_Correct_Product_Result_For_Array();
    Test_Simple_Arithmetic_With_Variable();
    Test_Range_Operation_With_Var_Arrays();
}

#endif