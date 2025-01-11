#pragma once

namespace node::test{
    bool Test_Size_Constructor();
    bool Test_Default_Constructor();
bool Test_Copy_Constructor();
bool Test_Move_Constructor(); //check constantly if deleted
//bool Test_Move_SharedPtrVal_Constructor();
//bool Test_Copy_SharedPtrVal_Constructor();
bool Child_WhenCalled_ReturnChildNode();
bool Child_WhenCalled_ReturnChildNodeAtId();
bool Child_WhenCalled_ReturnChildNodeAtSomeIds();
bool ReleaseChilds_WhenCalled();
bool HasChildAtId_WhenCalled_Return();
bool Test_Type();
bool Test_Execute();
bool Test_Execute_id();
bool Test_Cached_Result();
bool Test_Cached_Result_id();
bool Test_Insert_Back();
bool Test_Insert();
bool Test_Replace();
bool Test_Begins();
bool Test_Ends();
bool Test_is_Numeric();
bool Test_is_String();
bool Test_is_Array();
bool Test_is_Empty();
bool Test_Print_Text();
bool Test_Print_Result();

    virtual bool is_numeric() const;
    virtual bool is_string() const;
    virtual bool is_array() const;
    virtual bool is_empty() const;
    virtual void insert_back(std::shared_ptr<Node>);
    //insert before value at id
    virtual std::shared_ptr<Node> insert(size_t,std::shared_ptr<Node>);
    virtual std::shared_ptr<Node> replace(size_t,std::shared_ptr<Node>);
    virtual void print_text(std::ostream& stream) const;
    virtual void print_result(std::ostream& stream) const;
    virtual ~Node();
    void add_parent(Node*);
    bool has_parents() const;
    virtual void get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const;
    void replace_move_child_to(Node*,size_t,size_t);
    void replace_copy_child_to(Node*,size_t,size_t);
    void refresh_parent_links() const;
    void refresh();
    const std::unordered_set<Node*>& parents() const;
    std::unordered_set<Node*>& parents();
    bool refer_to(std::string_view var_name) const;
    inline bool caller() const{
        return caller_;
    }
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func);
    const std::vector<std::shared_ptr<Node>>& childs() const;
    protected:
    Result cache_;
    mutable std::unordered_set<Node*> parents_;
    std::vector<std::shared_ptr<Node>> childs_;
    bool caller_ = false;
    private:
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root);
    INFO_NODE child(const std::vector<size_t>& indexes, const Node* caller) const;
    INFO_NODE child(const std::vector<size_t>& indexes, Node* caller);
};
}