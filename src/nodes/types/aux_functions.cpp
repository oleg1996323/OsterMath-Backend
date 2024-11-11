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
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::vector<ArrayNode*>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::list<Node*>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::list<ArrayNode*>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::deque<Node*>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::deque<ArrayNode*>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::vector<std::shared_ptr<Node>>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::vector<std::shared_ptr<ArrayNode>>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::list<std::shared_ptr<Node>>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::list<std::shared_ptr<ArrayNode>>&>(arrays));
}

bool functions::auxiliary::check_sizes_arrays(const std::deque<std::shared_ptr<Node>>& arrays){
    std::vector<size_t> sz_depth_measure;
    return check_sizes_arrays(sz_depth_measure,
                            reinterpret_cast<const std::deque<std::shared_ptr<ArrayNode>>&>(arrays));
}