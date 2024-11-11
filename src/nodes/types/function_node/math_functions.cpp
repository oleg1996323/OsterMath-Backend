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

Result node_function::functions::math::SumProduct(FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){
        using T = __container_make__<childs_t,
                                    std::shared_ptr<ArrayNode>>::type;
        
        Value_t result = 0.;
        std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
        std::vector<Value_t> value_vector;
        {
            std::vector<size_t> sz_depth_measure;
            {
                if(!::functions::auxiliary::all_numeric(node->childs()))
                    return std::make_shared<exceptions::IncorrectTypeArrays>("numeric");

                if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,reinterpret_cast<const T&>(node->childs())))
                    throw exceptions::UnequalSizeArrays("Sumproduct");
            }

            for(auto sz:sz_depth_measure){
                if(!proxy_array_iterator)
                    proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
                else proxy_array_iterator->push(sz);
            }
        }

        value_vector.resize(proxy_array_iterator->total_size_childs(),1);
        size_t array_depth = proxy_array_iterator->depth();

        for(const std::shared_ptr<Node>& array:node->childs()){
            do
            {
                std::shared_ptr<Node> node = array;
                for(size_t depth=0; depth<array_depth;++depth){
                    //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                    node = node->child(proxy_array_iterator->current_iterator(depth));
                }
                //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
                value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))*=node->execute().get<Value_t>();
                //std::cout<<value_vector.at(proxy_array_iterator->seq_iterator(array_depth-1))<<std::endl;
            } while (++*proxy_array_iterator.get());
            proxy_array_iterator->reset_iterator();
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

Result node_function::functions::math::Sum(FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){
        using T = __container_make__<childs_t,
                                    std::shared_ptr<ArrayNode>>::type;
        
        Value_t result = 0.;
        std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
        {
            std::vector<size_t> sz_depth_measure;
            {
                if(!::functions::auxiliary::all_numeric(node->childs()))
                    return std::make_shared<exceptions::IncorrectTypeArrays>("numeric");

                if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,reinterpret_cast<const T&>(node->childs())))
                    throw exceptions::UnequalSizeArrays("Sum");
            }

            for(auto sz:sz_depth_measure){
                if(!proxy_array_iterator)
                    proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
                else proxy_array_iterator->push(sz);
            }
        }

        size_t array_depth = proxy_array_iterator->depth();

        for(const std::shared_ptr<Node>& array:node->childs()){
            do
            {
                std::shared_ptr<Node> node = array;
                for(size_t depth=0; depth<array_depth;++depth){
                    //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                    node = node->child(proxy_array_iterator->current_iterator(depth));
                }
                //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
                result+=node->execute().get<Value_t>();
            } while (++*proxy_array_iterator.get());
            proxy_array_iterator->reset_iterator();
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

Result node_function::functions::math::Product(FunctionNode* node){
    using namespace ::functions::auxiliary;
    if(check_type_container_nodes(TYPE_VAL::NUMERIC_ARRAY,node->childs())){
        using T = __container_make__<childs_t,
                                    std::shared_ptr<ArrayNode>>::type;
        
        Value_t result = 1.;
        std::unique_ptr<ProxySizeDepthMeasure> proxy_array_iterator;
    
        {
            std::vector<size_t> sz_depth_measure;
            {
                if(!::functions::auxiliary::all_numeric(node->childs()))
                    return std::make_shared<exceptions::IncorrectTypeArrays>("numeric");

                if(!::functions::auxiliary::check_sizes_arrays(sz_depth_measure,reinterpret_cast<const T&>(node->childs())))
                    throw exceptions::UnequalSizeArrays("Product");
            }

            for(auto sz:sz_depth_measure){
                if(!proxy_array_iterator)
                    proxy_array_iterator = std::make_unique<ProxySizeDepthMeasure>(sz);
                else proxy_array_iterator->push(sz);
            }
        }

        size_t array_depth = proxy_array_iterator->depth();
        //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(0)<<std::endl;

        for(const std::shared_ptr<Node>& array:node->childs()){
            do
            {
                std::shared_ptr<Node> node = array;
                for(size_t depth=0; depth<array_depth;++depth){
                    //std::cout<<"Iterator: "<<proxy_array_iterator->current_iterator(depth)<<std::endl;
                    node = node->child(proxy_array_iterator->current_iterator(depth));
                }
                //std::cout<<"Iterator: "<<proxy_array_iterator->seq_iterator(array_depth-1)<<std::endl;
                result*=node->execute().get<Value_t>();
            } while (++*proxy_array_iterator.get());
            proxy_array_iterator->reset_iterator();
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
