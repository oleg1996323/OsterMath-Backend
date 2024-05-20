#include "test/testing.h"
#include "data.h"

#ifdef DEBUG

void Test_Correct_Sum_Result_For_Array(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(VAR(!('any')#I)=[VAR(#A),VAR(#B)]
VAR(#A)=sum(VAR(#C),VAR(#D))
VAR(#B)=2
VAR(#C)=[2,2,2]
VAR(#D)=[2,2,2]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    output<<data->get("I")->get()<<std::endl;
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
R"(VAR(#I)=[VAR(#A),VAR(#B)]
VAR(#A)=sumproduct(VAR(#C),VAR(#D))
VAR(#B)=2
VAR(#C)=[500,200,100]
VAR(#D)=[500,200,100]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    // output<<data->get("I")->get()<<std::endl;
    data->get("I")->set_stream(output);
    data->get("I")->print();
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
R"(#I=[#A,#B]
#A=product(#C,#D)
#B=2
#C=[10,10,10]
#D=[10,10,10]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("I")->print();
    data->get("I")->set_stream(output);
    data->get("I")->set_format(FormattingData::OUTPUT_TYPE::FIXED);
    data->get("I")->set_precision(0);
    data->get("I")->print();
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
R"(#I=3*2+3^2
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("I")->print();
    data->get("I")->set_stream(output);
    data->get("I")->print();
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
R"(#I=PRODUCT_I(#A+#B)
#A=[2,2,2]
#B=[2,2,2]
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("I")->print();
    data->get("I")->set_stream(output);
    data->get("I")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(output.str() == 
R"(64
)");
    input.clear();
str_in = R"(#I=SUM_I(#A+#B*#C)
#A=[1,1,1]
#B=[1,1,1]
#C=3
)";/**LOG_X(2,3)*/
    input.str(str_in);
    //std::cout<<input.str()<<std::endl;
    output.str("");
    data->read_new();
    data->get("I")->print();
    std::cout<<output.str()<<std::endl;
    //std::cout<<3*(1+log(2)/log(3));
    assert(output.str() == 
R"(12
)");
str_in = R"(#I=SUM_I(#A+(#B*#C)^#D)
#A=[1,1,1]
#B=[1,1,LOG_X(EXP(2),pi)]
#C=3
#D=[2,3,4]
)";/**LOG_X(2,3)*/
    input.str(str_in);
    //std::cout<<input.str()<<std::endl;
    output.str("");
    data->read_new();
    data->get("I")->print();
    std::cout<<output.str()<<std::endl;
    //std::cout<<3*(1+log(2)/log(3));
//     assert(output.str() == 
// R"(12
// )");

str_in = R"(    #I=SUM_I(#A^(*)+(#B*#C)^#D)
#A^(*)=[1,1,1]
#B=[1,1,LOG_X(EXP(2),pi)]
#C=3
#D=[2,3,4,5]
)";/**LOG_X(2,3)*/
    input.str(str_in);
    //std::cout<<input.str()<<std::endl;
    output.str("");
    try{
        data->read_new();
        data->get("I")->print();
        std::cout<<output.str()<<std::endl;
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }
}

void Testing_compare_vars_1(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(#I :  #A < 2
#I : #A > 3
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("I")->print();
    data->get("I")->set_stream(output);
    data->get("I")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(data->get("I")->get_bottom_bound("any","A").has_value());
    assert(data->get("I")->get_top_bound("any","A").has_value());
    assert(data->get("I")->get_top_bound("any","A").value()==2);
    assert(data->get("I")->get_bottom_bound("any","A").value()==3);
}

void Testing_compare_vars_2(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string str_in = 
R"(#I :  #A < 2
)";
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    //data->get("I")->print();
    data->get("I")->set_stream(output);
    data->get("I")->print();
    std::string str = output.str();
    std::cout<<str<<std::endl;
    assert(!data->get("I")->get_bottom_bound("any","A").has_value());
    assert(data->get("I")->get_top_bound("any","A").has_value());
    assert(data->get("I")->get_top_bound("any","A").value()==2);
    assert(data->get("I")->get_bottom_bound("any","A")==std::nullopt);
}

void Testing(){
    Test_Correct_Sum_Result_For_Array();
    Test_Correct_SumProduct_Result_For_Array();
    // Test_Correct_Product_Result_For_Array();
    // Test_Simple_Arithmetic_With_Variable();
    // Test_Range_Operation_With_Var_Arrays();
    // Testing_compare_vars_1();
    // Testing_compare_vars_2();
}

#endif