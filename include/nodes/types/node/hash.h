#pragma once
#include <memory>
#include <type_traits>

class AbstractNode;

template<typename T>
struct NodeHash{
    size_t operator()(const T& val) const;
};

template<typename T>
struct NodeEq{
    template<typename Lhs,typename Rhs>
    bool operator()(Lhs&& lhs,Rhs&& rhs) const;
};

template<>
struct NodeHash<std::unique_ptr<AbstractNode>>
{
    using is_transparent = std::true_type;
    size_t operator()(const std::unique_ptr<AbstractNode>& node_ptr) const{
        return std::hash<AbstractNode*>{}(node_ptr.get());
    }
};

template<>
struct NodeEq<std::unique_ptr<AbstractNode>>
{
    using is_transparent = std::true_type;
    bool operator()(const std::unique_ptr<AbstractNode>& lhs, const std::unique_ptr<AbstractNode>& rhs) const{
        return lhs.get()==rhs.get();
    }

    bool operator()(const std::unique_ptr<AbstractNode>& lhs, const AbstractNode* rhs) const{
        return lhs.get()==rhs;
    }

    bool operator()(const AbstractNode* lhs, const std::unique_ptr<AbstractNode>& rhs) const{
        return lhs==rhs.get();
    }
};
