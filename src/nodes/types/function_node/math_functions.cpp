#include "function_node/math_functions.h"
#include "aux_functions.h"
#include "array_node.h"
#include "var_node.h"
#include "exception.h"
#include "func_node.h"
#include <algorithm>
#include <numeric>
#include <arithmetic_types.h>

using childs_t = std::decay_t<decltype(std::declval<Node>().childs())>;

Result node_function::functions::math::Sum(const FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){        
        Value_t result = 0.;

        SizeDepthMeasure sz_depth_measure;
        if(!node->childs().empty()){
            if(!is_rectangle_array_node(node->childs().front()))
                return std::make_shared<exceptions::InvalidSizeArrays>("square at all dimensions");
            sz_depth_measure = init_sz_depth_measure(node->childs().front());
        }
        else return std::make_shared<exceptions::InvalidNumberOfArguments>(">0");
        
        if(!::functions::auxiliary::equal_morphology_nodes(node->childs()))
            return std::make_shared<exceptions::UnequalSizeArrays>("Sum");

        for(const std::shared_ptr<Node>& array:node->childs()){
            while(true)
            {
                std::shared_ptr<Node> node = first_node_not_var(array);
                for(size_t depth=0; depth<sz_depth_measure.dimensions();++depth){
                    //std::cout<<"Iterator: "<<sz_depth_measure.current_iterator(depth)<<std::endl;
                    node = first_node_not_var(node->child(sz_depth_measure.current_iterator(depth)));
                }
                //std::cout<<"Iterator: "<<sz_depth_measure.seq_iterator(array_depth-1)<<std::endl;
                result+=node->execute().get<Value_t>();
                if(sz_depth_measure.is_iterable())
                    ++sz_depth_measure;
                else break;
            }
            sz_depth_measure.reset_all_iterators();
        }
        return result;
    }
    else if(check_type_container_nodes(TYPE_VAL::VALUE,node->childs())){
        Value_t init = 0.;
        std::for_each(node->childs().begin(),node->childs().end(),[&](const std::shared_ptr<Node>& child)->Result{
            return init+=child->execute().get<Value_t>();
        });
        return init;
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric arrays/value");
}

Result node_function::functions::math::SumProduct(const FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){        
        Value_t result = 0.;
        std::vector<Value_t> value_vector;
        SizeDepthMeasure sz_depth_measure;
        if(!node->childs().empty()){
            if(!is_rectangle_array_node(node->childs().front()))
                return std::make_shared<exceptions::InvalidSizeArrays>("square at all dimensions");
            sz_depth_measure = init_sz_depth_measure(node->childs().front());
        }
        else return std::make_shared<exceptions::InvalidNumberOfArguments>(">0");
        
        if(!::functions::auxiliary::equal_morphology_nodes(node->childs()))
            return std::make_shared<exceptions::UnequalSizeArrays>("SumProduct");

        value_vector.resize(sz_depth_measure.max_seq_iterator(),1);

        for(const std::shared_ptr<Node>& array:node->childs()){
            while(true)
            {
                std::shared_ptr<Node> node = first_node_not_var(array);
                for(size_t depth=0; depth<sz_depth_measure.dimensions();++depth){
                    //std::cout<<"Iterator: "<<sz_depth_measure.current_iterator(depth)<<std::endl;
                    node = first_node_not_var(node->child(sz_depth_measure.current_iterator(depth)));
                }
                //std::cout<<"Iterator: "<<sz_depth_measure.seq_iterator(array_depth-1)<<std::endl;
                value_vector.at(sz_depth_measure.seq_iterator(sz_depth_measure.dimensions()-1))*=node->execute().get<Value_t>();
                if(sz_depth_measure.is_iterable())
                    ++sz_depth_measure;
                else break;
            }
            sz_depth_measure.reset_all_iterators();
        }

        result = std::accumulate(value_vector.begin(),value_vector.end(),Value_t(0));
        return result;
    }
    else if(check_type_container_nodes(TYPE_VAL::VALUE,node->childs())){
        Value_t init = 0.;
        std::for_each(node->childs().begin(),node->childs().end(),[&](const std::shared_ptr<Node>& child)->Result{
            return init+=child->execute().get<Value_t>();
        });
        return init;
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric arrays/value");
}

Result node_function::functions::math::Product(const FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){        
        Value_t result = 1.;
                SizeDepthMeasure sz_depth_measure;
        if(!node->childs().empty()){
            if(!is_rectangle_array_node(node->childs().front()))
                return std::make_shared<exceptions::InvalidSizeArrays>("square at all dimensions");
            sz_depth_measure = init_sz_depth_measure(node->childs().front());
        }
        else return std::make_shared<exceptions::InvalidNumberOfArguments>(">0");
        
        if(!::functions::auxiliary::equal_morphology_nodes(node->childs()))
            return std::make_shared<exceptions::UnequalSizeArrays>("Product");

        for(const std::shared_ptr<Node>& array:node->childs()){
            while(true){
                std::shared_ptr<Node> node = first_node_not_var(array);
                for(size_t depth=0; depth<sz_depth_measure.dimensions();++depth){
                    //std::cout<<"Iterator: "<<sz_depth_measure.current_iterator(depth)<<std::endl;
                    node = first_node_not_var(node->child(sz_depth_measure.current_iterator(depth)));
                }
                //std::cout<<"Iterator: "<<sz_depth_measure.seq_iterator(array_depth-1)<<std::endl;
                result*=node->execute().get<Value_t>();
                if(sz_depth_measure.is_iterable())
                    ++sz_depth_measure;
                else break;
            }
            sz_depth_measure.reset_all_iterators();
        }
        return result;
    }
    else if(check_type_container_nodes(TYPE_VAL::VALUE,node->childs())){
        Value_t init = 1.;
        std::for_each(node->childs().begin(),node->childs().end(),[&](const std::shared_ptr<Node>& child)->Result{
            return init*=child->execute().get<Value_t>();
        });
        return init;
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric arrays/value");
}

#include <correlation.h>

Result node_function::functions::math::CorrelationCoefficient(const std::shared_ptr<ArrayNode>& arr_1,
                                                                const std::shared_ptr<ArrayNode>& arr_2){
    return node_function::functions::math::CorrelationCoefficient(std::execution::seq,arr_1,arr_2);
}