#include "aux_functions.h"
#include "array_node.h"
#include "var_node.h"
#include "exception.h"
#include <algorithm>
#include <numeric>
#include <set>
#include <list>
#include <deque>
#include <arithmetic_types.h>

size_t pow(size_t base, size_t pow){
    if(pow>0){
        for(;pow>0;--pow){
            base*=base;
        }
        return base;
    }
    else return 1;    
}

bool functions::auxiliary::all_numeric(decltype(std::declval<Node>().childs()) arrays){
    return std::all_of(arrays.begin(),arrays.end(),[](const std::decay_t<decltype(std::declval<Node>().childs())>::value_type& node){
        return node->is_numeric();
    });
}

bool functions::auxiliary::all_string(decltype(std::declval<Node>().childs()) arrays){
    return std::all_of(arrays.begin(),arrays.end(),[](const std::decay_t<decltype(std::declval<Node>().childs())>::value_type& node){
        return node->is_string();
    });
}

std::shared_ptr<ArrayNode> functions::auxiliary::to_array_node(const std::shared_ptr<Node>& node) noexcept{
    return reinterpret_cast<const std::shared_ptr<ArrayNode>&>(node);
}
std::shared_ptr<ValueNode> functions::auxiliary::to_value_node(const std::shared_ptr<Node>& node) noexcept{
    return reinterpret_cast<const std::shared_ptr<ValueNode>&>(node);
}

std::shared_ptr<Node> functions::auxiliary::first_node_not_var(const std::shared_ptr<Node>& node) noexcept{
    if(node){
        if(node->type()!=NODE_TYPE::VARIABLE)
            return node;
        std::shared_ptr<Node> child;
        if(node->has_child(0))
            child = node->child(0);
        else return std::shared_ptr<Node>();
        while(child->has_child(0) && child->type()==NODE_TYPE::VARIABLE){
            child = child->child(0);
        }
        if(child->type()==NODE_TYPE::VARIABLE){
            return std::shared_ptr<Node>();
        }
        return child;
    }
    return std::shared_ptr<Node>();
}
const Node* functions::auxiliary::first_node_not_var(const Node* node) noexcept{
    if(node){
        if(node->type()!=NODE_TYPE::VARIABLE)
            return node;
        std::shared_ptr<Node> child;
        if(node->has_child(0))
            child = node->child(0);
        else return nullptr;
        while(child->has_child(0) && child->type()==NODE_TYPE::VARIABLE){
            child = child->child(0);
        }
        if(child->type()==NODE_TYPE::VARIABLE){
            return nullptr;
        }
        return child.get();
    }
    return nullptr;
}

std::shared_ptr<Node> functions::auxiliary::first_node_not_var_by_ids(const std::shared_ptr<Node>& node, const std::vector<size_t>& seq_iterators) noexcept{
    std::shared_ptr<Node> child = first_node_not_var(node);
    if(child){
        for(size_t i:seq_iterators){
            if(child->has_child(i))
                child = child->child(i);
            else return std::shared_ptr<Node>();
            child = first_node_not_var(child);
            if(!child)
                return std::shared_ptr<Node>();
        }
        return child;
    }
    return nullptr;
}
const Node* functions::auxiliary::first_node_not_var_by_ids(const Node* node, const std::vector<size_t>& seq_iterators) noexcept{
    const Node* child = first_node_not_var(node);
    if(child){
        for(size_t i:seq_iterators){
            if(child->has_child(i))
                child = child->child(i).get();
            else return nullptr;
            child = first_node_not_var(child);
            if(!child)
                return nullptr;
        }
        return child;
    }
    return nullptr;
}
std::shared_ptr<Node> functions::auxiliary::first_node_not_var_by_ids(const std::shared_ptr<Node>& node, const SizeDepthMeasure& seq_iterators) noexcept{
    std::shared_ptr<Node> child = first_node_not_var(node);
    if(child){
        for(const size_iterator& i:seq_iterators){
            if(child->has_child(i.current_iterator_))
                child = child->child(i.current_iterator_);
            else return std::shared_ptr<Node>();
            child = first_node_not_var(child);
            if(!child)
                return std::shared_ptr<Node>();
        }
        return child;
    }
    return nullptr;
}

const Node* functions::auxiliary::first_node_not_var_by_ids(const Node* node, const SizeDepthMeasure& seq_iterators) noexcept{
    const Node* child = first_node_not_var(node);
    if(child){
        for(const size_iterator& i:seq_iterators){
            if(child->has_child(i.current_iterator_))
                child = child->child(i.current_iterator_).get();
            else return nullptr;
            child = first_node_not_var(child);
            if(!child)
                return nullptr;
        }
        return child;
    }
    return nullptr;
}

#include "test/log_duration.h"
//check if array has rectangular morphology (all childs have same sizes in all dimensions)
bool functions::auxiliary::is_rectangle_array_node(const std::shared_ptr<Node>& node) noexcept{
    std::shared_ptr<Node> first_node = first_node_not_var(node);
    if(!first_node)
        return false;
    if(first_node->type()!=NODE_TYPE::ARRAY || first_node->childs().size()==0)
        return true;

    return std::all_of(first_node->childs().begin(),first_node->childs().end(),[first_node](std::shared_ptr<Node> child){
        if(first_node->child(0)->childs().size() == child->childs().size() && is_rectangle_array_node(child))
            return true;
        return false;
    });
}

bool functions::auxiliary::is_filled_array_node(const std::shared_ptr<Node>& node) noexcept{
    std::shared_ptr<Node> first_node = first_node_not_var(node);
    if(!first_node)
        return false;
    if(first_node->type()!=NODE_TYPE::ARRAY)
        return true;
    else{
        if(first_node->childs().size()==0)
            return false;
        else{
            return std::all_of(first_node->childs().begin(),first_node->childs().end(),[first_node](std::shared_ptr<Node> child){
                return is_filled_array_node(child);
            });
        }
    }
}
bool functions::auxiliary::is_filled_rectangle_array_node_of_type(TYPE_VAL type_value,const std::shared_ptr<Node>& node) noexcept{
    std::shared_ptr<Node> first_node = first_node_not_var(node);
    if(!first_node)
        return false;
    if(first_node->type()!=NODE_TYPE::ARRAY)
        return true;
    else{
        if(first_node->childs().size()==0)
            return false;
        else{
            return std::all_of(first_node->childs().begin(),first_node->childs().end(),[first_node, type_value](std::shared_ptr<Node> child){
                return first_node->child(0)->childs().size() == child->childs().size() && type_value&child->type_val() && is_filled_rectangle_array_node_of_type(type_value,child);
            });
        }
    }
}

bool functions::auxiliary::has_cyclic_references(const std::shared_ptr<Node>& node) noexcept{
    if(node->is_not_cycled()){
        for(const std::shared_ptr<Node>& child: node->childs()){
            if(has_cyclic_references(child))
                return true;
        };
        return false;
    }
    else return true;
}

bool functions::auxiliary::has_cyclic_references(const Node* node) noexcept{
    if(!node)
        return false;
    if(node->is_not_cycled()){
        for(const std::shared_ptr<Node>& child: node->childs()){
            if(has_cyclic_references(child))
                return true;
        };
        return false;
    }
    else return true;
}

//independent form of nodes (compare value types, number childs, number depth)
//add exclusion of function, range_function nodes
bool functions::auxiliary::equal_morphology_nodes(const std::vector<std::shared_ptr<Node>>& nodes) noexcept{
    if(nodes.size()==0)
        return false;
    if(nodes.size()==1)
        return true;
    std::shared_ptr<Node> first_node = first_node_not_var(nodes.front());
    std::vector<size_t> seq_iterators;
    std::vector<std::shared_ptr<Node>> ex_nodes;
    size_t count = 0;
    if(!first_node)
        return false;
    if(!std::all_of(nodes.begin()+1,nodes.end(),[first_node](const std::shared_ptr<Node>& node){
        std::shared_ptr<Node> cl_node = first_node_not_var(node);
        if(!cl_node)
            return false;
        return cl_node->childs().size() == first_node->childs().size() && cl_node->type_val() == first_node->type_val();
    ;}))
        return false;
    else
        if(first_node->has_childs() && first_node->type_val()&TYPE_VAL::ARRAY)
            seq_iterators.push_back(0);
    if(!seq_iterators.empty())
        while(seq_iterators.front()<first_node->childs().size()){
            for(size_t iter = 1;iter<nodes.size();++iter){
                std::shared_ptr<Node> seq_node_child = first_node_not_var_by_ids(first_node,seq_iterators);
                if(!seq_node_child)
                    return false;
                std::shared_ptr<Node> other_child_node = first_node_not_var_by_ids(nodes.at(iter),seq_iterators);
                if(!other_child_node)
                    return false;
                if(seq_node_child->type_val() != other_child_node->type_val() || (other_child_node->type_val()&TYPE_VAL::ARRAY &&
                seq_node_child->type_val()&TYPE_VAL::ARRAY &&
                    other_child_node->childs().size()!=seq_node_child->childs().size())){
                    return false;
                }
                ++count;
            }
            std::shared_ptr<Node> tmp_node = first_node_not_var_by_ids(first_node,seq_iterators);
            if(seq_iterators.empty() && first_node->has_childs() && 
            first_node->type_val()&TYPE_VAL::ARRAY){
                seq_iterators.push_back(0);
                ex_nodes.push_back(tmp_node);
            }
            else if(tmp_node = first_node_not_var_by_ids(first_node,seq_iterators))
                if(tmp_node->has_childs() && 
                    tmp_node->type_val()&TYPE_VAL::ARRAY){
                    seq_iterators.push_back(0);
                    ex_nodes.push_back(tmp_node);
                }
                else{
                    if(!ex_nodes.empty() && seq_iterators.back()+1<ex_nodes.back()->childs().size())
                        ++seq_iterators.back();
                    else{
                        while(!(ex_nodes.empty() || !(seq_iterators.back()+1>=ex_nodes.back()->childs().size()) || !(seq_iterators.size()>1))){
                            seq_iterators.pop_back();
                            ex_nodes.pop_back();
                        }
                        ++seq_iterators.back();
                    }
                }
            else
                return false;
        }
    std::cout<<count<<std::endl;
    return true;
}