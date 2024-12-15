#pragma once
#include <execution>
#include <string>
#include "include/nodes/def.h"
#include "events_errors/exception.h"
#include "types.h"
#include "aux_functions.h"
#include "array_node.h"
#include "check_val_type.h"

class ArrayNode;

namespace node_function::functions{
    namespace string{
        template<typename... STRS>
        requires (std::is_convertible_v<&STRS::value_type,const char*> && ...)
        std::string Concatenate(STRS&&... strs){
            std::string result;
            return (result + ... + strs);
        }

        Result Concatenate(const ArrayNode* arr){
            using namespace ::functions::auxiliary;
            std::string result;
            for(const std::shared_ptr<AbstractNode>& child:arr->childs()){
                if(!child->execute().is_error()){
                    if(check_arguments(TYPE_VAL::STRING_ARRAY,child) && child->cached_result().is_array())
                        result+=Concatenate(child->cached_result().get_array_node()).get<std::string>();
                    else if(check_arguments(TYPE_VAL::STRING,child))
                        result+=child->cached_result().get<std::string>();
                    else return std::make_shared<exceptions::InvalidTypeOfArgument>("string array/string");
                }
                else{
                    return child->cached_result();
                }
            }
            return result;
        }

        Result Concatenate(const std::vector<std::shared_ptr<AbstractNode>>& nodes){
            using namespace ::functions::auxiliary;
            std::string result;
            for(const std::shared_ptr<AbstractNode>& node:nodes){
                if(!node->execute().is_error()){
                    if(check_arguments(TYPE_VAL::STRING_ARRAY,node)){
                        Result tmp = Concatenate(dynamic_cast<const ArrayNode*>(node.get()));
                        if(tmp.is_string())
                            result+=tmp.get<std::string>();
                        else return tmp.get<std::shared_ptr<AbstractEvent>>();
                    }
                    else if(check_arguments(TYPE_VAL::STRING,node))
                        result+=node->cached_result().get<std::string>();
                }
                else{
                    return node->cached_result().get_exception();
                }
            }
            return result;
        }
    }
}