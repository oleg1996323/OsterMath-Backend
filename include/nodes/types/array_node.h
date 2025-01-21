#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "abstract_node.h"
#include "func_node.h"
#include "concept.h"

class ArrayNodeNMProxy{
    friend ArrayNode;
    template<typename T>
    requires __Array_Impl_By_Val__<T>
    static ArrayNode* __implement_by__(T* val);

    static ArrayNode* __implement_by_var__(AbstractNode* array_owner,int id,VariableNode* var);

    static ArrayNode* __implementation__(AbstractNode* val);
};

#include "core/system.h"
#include "core/sys_exceptions.h"

template<typename T>
    requires __Array_Impl_By_Val__<T>
ArrayNode* ArrayNodeNMProxy::__implement_by__(T* val){
    return __implementation__(val);
}

class ArrayNode:public AbstractNode{
    mutable Result cache_;
public:
    typedef AbstractNode* value_type;
    ArrayNode(size_t sz, NodeManager* mng);

    ArrayNode(const ArrayNode& arr, NodeManager* mng);
    ArrayNode(ArrayNode&& arr, NodeManager* mng);
    ~ArrayNode();

    //return the replaced ArrayNode pointer
    template<typename T>
    requires __Array_Impl_By_Val__<T>
    static ArrayNode* implement_by(T* val){
        return ArrayNodeNMProxy::__implement_by__(val);
    }

    static ArrayNode* implement_by_var(AbstractNode* array_owner,int id,VariableNode* var){
        return ArrayNodeNMProxy::__implement_by_var__(array_owner,id,var);
    }
    
    AbstractNode* discard();

    virtual NODE_TYPE type() const override;
    virtual Result execute() const override;
    inline virtual Result cached_result() const override{
        return cache_;
    }
    size_t size() const;
    bool empty() const;
    Childs_t::const_iterator begin() const;
    Childs_t::const_iterator end() const;
    Childs_t::const_iterator cbegin() const;
    Childs_t::const_iterator cend() const;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual bool is_empty() const override;
    virtual TYPE_VAL type_val() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }
};