#include "test/testing.h"
#include "data.h"

#ifdef DEBUG

bool CalculationsCheck(const std::string& input_str, const std::string& check_val){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::istringstream input(input_str);
    data->setstream(input);
    std::ostringstream output;
    try{
        output<<data->get("I")->get()<<std::endl;
        std::cout<<output.str()<<std::endl;
        std::cout.setf(std::ios::boolalpha);
        std::cout<<"any exists: "<<pool.exists("any")<<std::endl;
        std::cout<<"other exists: "<<pool.exists("other")<<std::endl;
        assert(output.str() == check_val);
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
        return false;
    }

    return true;
}

void Test_Correct_Sum_Result_For_Array(){
    std::string str_in = 
R"(VAR(!('any')#I)=[VAR(!('any')#A),VAR(#B)]
VAR(!('any')#A)=sum(VAR(!('any')#C),VAR(#D))
VAR(!('any')#B)=2
VAR(!('any')#C)=[2,2,2]
VAR(!('any')#D)=[2,2,2]
)";
    std::string equal = R"([12 2]
)";
    CalculationsCheck(str_in,equal);
}

void Test_Correct_SumProduct_Result_For_Array(){
    std::string str_in = 
R"(VAR(#I)=[VAR(#A),VAR(#B)]
VAR(#A)=sumproduct(VAR(#C),VAR(#D))
VAR(#B)=2
VAR(#C)=[500,200,100]
VAR(#D)=[500,200,100]
)";
    std::string equal = R"([300000 2]
)";
    CalculationsCheck(str_in,equal);
}

void Test_Correct_Product_Result_For_Array(){
    std::string str_in = 
R"(VAR(#I)=[VAR(#A),VAR(#B)]
VAR(#A)=product(VAR(#C),VAR(#D))
VAR(#B)=2
VAR(#C)=[10,10,10]
VAR(#D)=[10,10,10]
)";
    std::string equal = R"([1e+06 2]
)";
    CalculationsCheck(str_in,equal);
}

void Test_Simple_Arithmetic_With_Variable(){
    std::string str_in = 
R"(VAR(!('any')#I)=3*2+3^2
)";
    std::string equal = R"(15
)";
    CalculationsCheck(str_in,equal);
}

void Test_Range_Operation_With_Var_Arrays(){
    std::string str_in = 
R"(VAR(!('any')#I)=PRODUCT_I(VAR(!('other')#A)+VAR(!('any')#B))
VAR(!('other')#A)=[2,2,2]
VAR(#B)=[2,2,2]
)";
    std::string equal = R"(64
)";
    CalculationsCheck(str_in,equal);

    str_in = 
R"(#I=SUM_I(#A+#B*#C)
#A=[1,1,1]
#B=[1,1,1]
#C=3
)";
    equal = R"(12
)";
    CalculationsCheck(str_in,equal);

str_in = R"(VAR(#I)=SUM_I(VAR(#A)+(VAR(#B)*VAR(#C))^VAR(#D))
VAR(#A)=[1,1,1]
VAR(#B)=[1,1,LOG_X(EXP(2),pi)]
VAR(#C)=3
VAR(#D)=[2,3,4]
)";

    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    try{
        output<<data->get("I")->get()<<std::endl;
        std::cout<<output.str()<<std::endl;
        //assert(output.str() == check_val);
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
R"(VAR(#I) :  VAR(#A) < 2
VAR(#I) : VAR(#A) > 3
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
R"(VAR(#I) :  VAR(#A) < 2
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
    Test_Correct_Product_Result_For_Array();
    Test_Simple_Arithmetic_With_Variable();
    Test_Range_Operation_With_Var_Arrays();
    Testing_compare_vars_1();
    Testing_compare_vars_2();
}

#endif