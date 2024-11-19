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

bool functions::auxiliary::check_sizes_arrays(const std::vector<Node*>& arrays){
    SizeDepthMeasure sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::vector<ArrayNode*>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::list<Node*>& arrays){
    SizeDepthMeasure sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::list<ArrayNode*>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::deque<Node*>& arrays){
    SizeDepthMeasure sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::deque<ArrayNode*>&>(arrays));
}

// bool functions::auxiliary::check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& arrays){
//     SizeDepthMeasure sz_depth_measure;
//     return check_sizes_arrays(sz_depth_measure,
//                             reinterpret_cast<const std::vector<std::shared_ptr<ArrayNode>>&>(arrays));
// }

bool functions::auxiliary::check_sizes_arrays(const std::list<std::shared_ptr<Node>>& arrays){
    SizeDepthMeasure sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::list<std::shared_ptr<ArrayNode>>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::deque<std::shared_ptr<Node>>& arrays){
    SizeDepthMeasure sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::deque<std::shared_ptr<ArrayNode>>&>(arrays));
}

bool same_result_type(const Result& first,const Result& second){
    return first.index() == second.index();
}

bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure&,const std::vector<Node*>& arrays){return true;}
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure&,const std::list<Node*>& arrays){return true;}
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure&,const std::deque<Node*>& arrays){return true;}
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure&,const std::list<std::shared_ptr<Node>>& arrays){return true;}
bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure&,const std::deque<std::shared_ptr<Node>>& arrays){return true;}

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
Node* functions::auxiliary::first_node_not_var(Node* node) noexcept{
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
Node* functions::auxiliary::first_node_not_var_by_ids(Node* node, const std::vector<size_t>& seq_iterators) noexcept{
    Node* child = first_node_not_var(node);
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


bool functions::auxiliary::check_sizes_arrays(SizeDepthMeasure& sz_depth_measure,const std::vector<std::shared_ptr<Node>>& nodes) noexcept{
    // Node* node;

    // while(){

    // }
    return true;
}

//independent form of array (may not be ideal form (depth and sizes per childs at different depths may variate))
bool functions::auxiliary::check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& nodes) noexcept{
    //Node* node;
    if(nodes.size()<=1)
        return false;
    // if(std::any_of(nodes.begin(),nodes.end(),[](const std::shared_ptr<Node>& node){
    //     return node->cached_result().is_error();
    // }))
    //     return false;

    std::shared_ptr<Node> first_node = first_node_not_var(nodes.front());
    // int32_t depth = -1;
    std::vector<size_t> seq_iterators;
    size_t root_iter = 0;
    if(!first_node)
        return false;

    if(!std::all_of(nodes.begin()+1,nodes.end(),[first_node](const std::shared_ptr<Node>& node){
        return node->childs().size() == first_node->childs().size() && node->type_val() == first_node->type_val();
    ;}))
        return false;
    size_t count = 0;
    while(root_iter<nodes.front()->childs().size()){
        for(size_t iter = 1;iter<nodes.size();++iter){
            std::shared_ptr<Node> seq_node_child = first_node_not_var_by_ids(nodes.front(),seq_iterators);
            if(!seq_node_child)
            {
                return false;
            }
            std::shared_ptr<Node> other_child_node = seq_iterators.empty()?first_node_not_var(nodes.at(iter)):first_node_not_var_by_ids(nodes.at(iter),seq_iterators);

            if(!other_child_node)
            {
                return false;
            }
            if(seq_node_child->type_val() != other_child_node->type_val() || 
                other_child_node->childs().size()!=seq_node_child->childs().size())
            {
                std::cout<<other_child_node->get_text()<<std::endl<<seq_node_child->get_text()<<std::endl;
                return false;
            }
            std::cout<<other_child_node->get_text()<<std::endl<<seq_node_child->get_text()<<std::endl;
            ++count;
        }
        std::shared_ptr<Node> tmp_node = first_node_not_var_by_ids(nodes.front(),seq_iterators);
        if(seq_iterators.empty() && nodes.front()->has_childs())
            seq_iterators.push_back(root_iter);
        else if(tmp_node && tmp_node->has_childs())
            seq_iterators.push_back(seq_iterators.empty()?root_iter:0);
        else{
            if(!seq_iterators.empty())
                seq_iterators.pop_back();
            if(!seq_iterators.empty())
                ++seq_iterators.back();
            if(seq_iterators.empty())
                ++root_iter;
        }
    }
    assert(count==nodes.size()*5*3);
    return true;
}