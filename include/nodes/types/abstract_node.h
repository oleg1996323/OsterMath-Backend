// #pragma once

// class AbstractNode{
// public:
//     AbstractNode(size_t sz);
//     AbstractNode();
//     AbstractNode(const Node& other){
//         *this = other;
//     }

//     AbstractNode& operator=(const AbstractNode& other);
//     AbstractNode& operator=(AbstractNode&& other);
//     TYPE_VAL type_val() const;
//     const std::shared_ptr<AbstractNode>& child(size_t id) const;
//     std::shared_ptr<AbstractNode>& child(size_t id);
//     INFO_NODE child(const std::vector<size_t>& indexes);
//     INFO_NODE child(const std::vector<size_t>& indexes) const;
//     virtual void release_childs();
//     inline virtual bool has_childs() const{
//         return false;
//     }
//     inline virtual bool has_child(size_t id) const{
//         return false;
//     }
//     virtual NODE_TYPE type() const;
//     virtual Result execute() const;
//     virtual Result execute_for_array_variables(const std::vector<size_t>& variables) const;
//     inline virtual Result cached_result() const{
//         return std::monostate();
//     }
//     virtual bool is_numeric() const;
//     virtual bool is_string() const;
//     virtual bool is_array() const;
//     virtual bool is_empty() const;
    
//     template<typename T>
//     requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
//     void insert_back(T&& arg);

//     virtual void insert_back(std::shared_ptr<AbstractNode>);
//     //insert before value at id
//     virtual std::shared_ptr<AbstractNode> insert(size_t,std::shared_ptr<AbstractNode>);
//     virtual std::shared_ptr<AbstractNode> replace(size_t,std::shared_ptr<AbstractNode>);
//     virtual void print_text(std::ostream& stream) const;
//     virtual void print_result(std::ostream& stream) const;
//     std::string get_result() const;
//     std::string get_text() const;
//     virtual ~Node();
//     void add_parent(Node*);
//     bool has_parents() const;
//     //virtual void get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const;
//     void refresh_parent_links() const;
//     void refresh();
//     const std::set<Node*>& parents() const;
//     std::set<Node*>& parents();
//     virtual bool refer_to(std::string_view var_name) const;
//     virtual std::set<std::shared_ptr<VariableNode>> refer_to_vars() const;
//     virtual std::set<std::shared_ptr<Node>> refer_to_node_of_type(NODE_TYPE) const;
//     inline bool caller() const{
//         return caller_;
//     }
//     template<typename T, typename... U>
//     void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func);
    
//     virtual const std::vector<std::shared_ptr<Node>>& childs() const;

//     virtual void flush_cache() const{}
// protected:
//     //friend class RangeOperationNode;
//     mutable std::set<Node*> parents_; //is less memory expensive than unordered_set
//     bool caller_ = false;
//     virtual std::vector<std::shared_ptr<Node>>& childs();
// private:
//     template<typename T, typename... U>
//     void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root);
//     void __insert_back_string_node__(const std::string& string);
//     void __insert_back_string_node__(std::string&& string);
//     void __insert_back_value_node__(const Value_t& val);
//     void __insert_back_value_node__(Value_t&& val);
//     INFO_NODE child(const std::vector<size_t>& indexes, const Node* caller) const;
//     INFO_NODE child(const std::vector<size_t>& indexes, Node* caller);
// };