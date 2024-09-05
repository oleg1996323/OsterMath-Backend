#include "test/testing.h"
#include "data.h"
#include "arithmetic_types.h"
#include "exception/exception.h"

#ifdef DEBUG

bool CalculationsCheck(const std::string& input_str, const std::string& check_val){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::istringstream input(input_str);
    data->setstream(input);
    data->read_new();
    std::ostringstream output;
    data->get("I")->set_stream(output);
    // data->get("A")->set_stream(output);
    // data->get("B")->set_stream(output);
    // data->get("C")->set_stream(output);
    // data->get("D")->set_stream(output);
    try{
        // data->get("I")->print_text();
        // std::cout<<output.str()<<std::endl;
        // output.str("");
        // data->get("A")->print_text();
        // std::cout<<output.str()<<std::endl;
        // output.str("");
        // data->get("B")->print_text();
        // std::cout<<output.str()<<std::endl;
        // output.str("");
        // data->get("C")->print_text();
        // std::cout<<output.str()<<std::endl;
        // output.str("");
        // data->get("D")->print_text();
        // std::cout<<output.str()<<std::endl;
        // output.str("");
        data->get("I")->print_result();
        std::cout<<output.str()<<std::endl;
        std::cout.setf(std::ios::boolalpha);
        std::cout<<"any exists: "<<pool.exists("any")<<std::endl;
        std::cout<<"other exists: "<<pool.exists("other")<<std::endl;
        std::string out = output.str();
        std::string check = check_val;
        std::cout<<output.str()<<std::endl;
        std::cout<<check_val<<std::endl;
        assert(output.str() == check_val);
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
        return false;
    }
    catch(const exceptions::InvalidNumberOfArguments& err){
        std::cout<<err.what()<<std::endl;
        return false;
    }
    catch(const exceptions::InvalidTypeOfArgument& err){
        std::cout<<err.what()<<std::endl;
        return false;
    }

    return true;
}

void Test_Correct_Sum_Result_For_Array(){
    std::string str_in = 
R"(VAR(!('any')#I)=[VAR(!('any')#A);VAR(#B)]
VAR(!('any')#A)=sum(VAR(!('any')#C);VAR(#D))
VAR(!('any')#B)=2
VAR(!('any')#C)=[2;2;2]
VAR(!('any')#D)=[2;2;2]
)";
    std::string equal = R"([12; 2])";
    CalculationsCheck(str_in,equal);
}

void Test_Correct_SumProduct_Result_For_Array(){
    std::string str_in = 
R"(VAR(#I)=[VAR(#A);VAR(#B)]
VAR(#A)=sumproduct(VAR(!('other')#C);VAR(#D))
VAR(#B)=2
VAR(!('other')#C)=[500;200;100]
VAR(#D)=[500;200;100]
)";
    std::string equal = R"([300000; 2])";
    CalculationsCheck(str_in,equal);
}

void Test_Serialization(){
    std::string str_in = 
R"(VAR(#I)=[VAR(#A);VAR(#B)]
VAR(#I) :  VAR(#A) > 299999 : 2
VAR(#A)=sumproduct(VAR(!('other')#C);VAR(#D))
VAR(#B)=2
VAR(!('other')#C)=[500;200;100]
VAR(#D)=[500;200;100]
)";
    std::string equal = R"(2)";


    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::istringstream input(str_in);
    data->setstream(input);
    data->read_new();
    std::ostringstream output;
    data->get("I")->set_stream(output);
    data->get("A")->set_stream(output);
    data->get("B")->set_stream(output);
    try{
        data->get("I")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("A")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("B")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("I")->print_result();
        std::cout<<output.str()<<std::endl;
        std::cout.setf(std::ios::boolalpha);
        std::cout<<"any exists: "<<pool.exists("any")<<std::endl;
        std::cout<<"other exists: "<<pool.exists("other")<<std::endl;
        assert(output.str() == equal);
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }

    serialization::serialize_to("./TestSerialization.omb",&pool);
    DataPool other = serialization::deserialize_from("./TestSerialization.omb");
    for(auto& data:other.data_bases())
        std::cout<<data->name()<<std::endl;
    assert(other.exists("any"));
    assert(other.exists("other"));
    assert(other.get("any")->exists("I"));
    assert(other.get("any")->exists("A"));
    assert(other.get("other")->exists("C"));
    return;
}

void Test_Deserialization(){
    std::string equal = R"([300000; 2])";

    DataPool pool=serialization::deserialize_from("./TestSerialization.omb");
    BaseData* data = pool.get("any");
    assert(pool.exists("any"));
    assert(pool.exists("other"));
    assert(pool.get("any")->exists("I"));
    assert(pool.get("any")->exists("A"));
    assert(pool.get("other")->exists("C"));
    std::ostringstream output;
    data->get("I")->set_stream(output);
    data->get("A")->set_stream(output);
    data->get("B")->set_stream(output);
    try{
        data->get("I")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("A")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("B")->print_text();
        std::cout<<output.str()<<std::endl;
        output.str("");
        data->get("I")->print_result();
        std::cout<<output.str()<<std::endl;
        std::cout.setf(std::ios::boolalpha);
        std::cout<<"any exists: "<<pool.exists("any")<<std::endl;
        std::cout<<"other exists: "<<pool.exists("other")<<std::endl;
        assert(output.str() == equal);
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }
}

void Test_Correct_Product_Result_For_Array(){
    std::string str_in = 
R"(VAR(#I)=[VAR(#A);VAR(#B)]
VAR(#A)=product(VAR(#C);VAR(#D))
VAR(#B)=2
VAR(#C)=[10;10;10]
VAR(#D)=[10;10;10]
)";
    std::string equal = R"([1e+06; 2])";
    CalculationsCheck(str_in,equal);
}

void Test_Simple_Arithmetic_With_Variable(){
    std::string str_in = 
R"(VAR(!('any')#I)=3*2+3^2
)";
    std::string equal = R"(15)";
    CalculationsCheck(str_in,equal);
}

void Test_Range_Operation_With_Var_Arrays(){
    std::string str_in = 
R"(VAR(!('any')#I)=PRODUCT_I(VAR(!('any')#A)+VAR(!('any')#B))
VAR(!('any')#A)=[2;2;2]
VAR(#B)=[2;2;2]
)";
    std::string equal = R"(64)";
    CalculationsCheck(str_in,equal);

    str_in = 
R"(#I=SUM_I(#A+#B*#C)
#A=[1;1;1]
#B=[1;1;1]
#C=3
)";
    equal = R"(12)";
    CalculationsCheck(str_in,equal);

str_in = R"(VAR(#I)=SUM_I(#A+(#B*#C)^#D)
VAR(#A)=[1;1;1]
VAR(#B)=[1;1;LOG_X(EXP(2);pi)]
VAR(#C)=3
VAR(#D)=[2;3;4]
)";

    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::istringstream input(str_in);
    data->setstream(input);
    std::ostringstream output;
    try{
        data->get("I")->set_stream(output);
        data->get("I")->print_result();
        std::cout<<output.str()<<std::endl;
        data->get("I")->print_text();
        std::cout<<output.str()<<std::endl;
        //assert(output.str() == check_val);
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }
}

void Testing_compare_vars_1(){
    std::string str_in = 
R"(VAR(#I) :  VAR(#A) < 2 : 2
VAR(#I) : VAR(#A) > 3 : 1
VAR(#I) = 5
VAR(#A) = 2.5
)";
    std::string equal = R"(5)";
    CalculationsCheck(str_in,equal);
}

void Testing_compare_vars_2(){
        std::string str_in = 
R"(VAR(#I) :  VAR(#A) < 2 : 2
VAR(#I) : VAR(#A) > 3 : 1.1
VAR(#A) = 4
VAR(#I) = 5
)";
    std::string equal = R"(1.1)";
    CalculationsCheck(str_in,equal);
}

void Testing_input_node_assign_1(){
    std::string str_in = 
R"(VAR(#I)=[1;1;1;1;1]
VAR(#I)(1) = 2
)";
    std::string equal = R"([1; 2; 1; 1; 1])";
    CalculationsCheck(str_in,equal);
}

void Testing(){
    Test_Correct_Sum_Result_For_Array();
    Test_Correct_SumProduct_Result_For_Array();
    Test_Correct_Product_Result_For_Array();
    Test_Simple_Arithmetic_With_Variable();
    Test_Range_Operation_With_Var_Arrays();
    Test_Serialization();
    Test_Deserialization();
    Testing_compare_vars_1();
    Testing_compare_vars_2();
    Testing_input_node_assign_1();
}

#endif