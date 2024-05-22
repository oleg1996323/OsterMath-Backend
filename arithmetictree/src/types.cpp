#include "def.h"
#include "types.h"
#include "arithmetic_types.h"
#include "arithmetic_tree.h"
#include "data.h"

bool Array_val::is_undef() const{
    return std::holds_alternative<std::monostate>(*this) || (is_variable() && get<VariableBase*>());
}

bool Array_val::is_variable() const{
    return std::holds_alternative<VariableBase*>(*this);
}

bool Array_val::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool Array_val::is_numeric() const{
    if(is_variable()){
        auto ptr = get<VariableBase*>();
        if(ptr && (ptr->is_arithmetic_tree() || ptr->is_value())){
            return true;
        }
    }
    return is_value() || is_expression();
}

bool Array_val::is_string() const{
    if(is_variable()){
        auto ptr = get<VariableBase*>();
        if(ptr && ptr->is_string()){
            return true;
        }
    }
    return std::holds_alternative<std::string>(*this);
}

bool Array_val::is_expression() const{
    return std::holds_alternative<ArithmeticTree>(*this);
}

void Array_t::define_back(const Array_val& val){
    if(!back().is_undef()){
        throw std::invalid_argument("Array item already defined");
        return;
    }

    if(val.is_variable()){
        VariableBase* var_node = val.get<VariableBase*>();
        if(var_node->is_arithmetic_tree())
            for(auto it:var_node->get<ArithmeticTree>().get_dependencies())
                var_dependence_.insert(it);
        else if(var_node->is_array())
            for(auto it:var_node->get<Array_t>().get_dependencies())
                var_dependence_.insert(it);
    }
    else if(val.is_expression()){
        for(auto it:val.get<ArithmeticTree>().get_dependencies())
            var_dependence_.insert(it);
    }

    if(val.is_variable())
        val.get<VariableBase*>()->node()->add_parent(parent_->node().get());

    back() = val; //при вводе неопределённой переменной тип определяется неверно
}

void Array_t::define_back(const std::shared_ptr<Node> & node){
    if(back().is_undef()){
        back() = ArithmeticTree();
    }
    else if(back().is_value())
        __value_to_tree_for_last__();

    if(node->type() == ARITHM_NODE_TYPE::FUNCTION){
        for(auto it:reinterpret_cast<FunctionNode*>(node.get())->get_dependencies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::RANGEOP){
        for(auto it:reinterpret_cast<RangeOperationNode*>(node.get())->get_dependencies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::VARIABLE){
        VariableNode* var_node = reinterpret_cast<VariableNode*>(node.get());
        if(var_node->variable()->is_arithmetic_tree())
            for(auto it:var_node->variable()->get<ArithmeticTree>().get_dependencies())
                var_dependence_.insert(it);
        else if(var_node->variable()->is_array())
            for(auto it:var_node->variable()->get<Array_t>().get_dependencies())
                var_dependence_.insert(it);
    }
        

    assert(back().is_expression());
        back().get<ArithmeticTree>().insert(node);
    return;
}

void Array_t::__value_to_tree_for_last__(){
    assert(back().is_value());
    ArithmeticTree tree;
    tree.insert(std::make_shared<ValueNode>(std::move(back().get<Value_t>())));
    back().get()=std::move(tree);
}

std::ostream& VariableBase::operator<<(std::ostream& stream){
    if(get_type()!=FormattingData::OUTPUT_TYPE::DEFAULT){
        stream<<std::setprecision(get_precision());
        if(get_type()==FormattingData::OUTPUT_TYPE::SCIENTIFIC)
            stream<<std::scientific;
        else if(get_type()==FormattingData::OUTPUT_TYPE::FIXED)
            stream<<std::fixed;
        else throw std::runtime_error("Unknown format");
    }
    stream<<*this;
    return stream;
}

void VariableBase::print(){
    get_stream()<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Arr_value& val){
    std::visit([&stream](const auto& x) { stream << x; }, val);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Array_t& arr){
    stream<<'[';
    if(!arr.empty()){
        if(arr.front().is_variable() && arr.front().get<VariableBase*>()!=nullptr)
            stream<<arr.front().get<VariableBase*>()->get();
        else
            stream<<arr.front().get();
        for(size_t i=1;i<arr.size();++i){
            if(arr.at(i).is_variable() && arr.at(i).get<VariableBase*>()!=nullptr)
                stream<<' '<<arr.at(i).get<VariableBase*>()->get();
            else
            stream<<' '<<arr.at(i).get();
        }
    }
    stream<<']';
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::monostate empty){
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Variable_t& var){
    std::visit([&stream](const auto& x) { stream << std::defaultfloat<<x; }, var);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree){
    stream<<std::defaultfloat<<tree.value();
    return stream;
}

VariableBase::VariableBase(std::string_view name, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{
    node_=std::make_shared<VariableNode>(this);
}

std::string_view VariableBase::name() const{
    return name_;
}

#include "arithmetic_types.h"

void VariableBase::refresh() const{
    node_->refresh();
}

void VariableBase::set_data_base(BaseData* data_base){
    data_base_=data_base;
}

BaseData* VariableBase::get_data_base() const{
    return data_base_;
}

Variable_t& VariableBase::get(){
    return *this;
}

const Variable_t& VariableBase::get() const{
    return *this;
}

const std::shared_ptr<VariableNode>& VariableBase::node() const{
    return node_;
}

const std::shared_ptr<VariableNode>& VariableBase::node(){
    return node_;
}

bool VariableBase::is_arithmetic_tree() const{
    return std::holds_alternative<ArithmeticTree>(get());
}

bool VariableBase::is_value() const{
    return std::holds_alternative<Value_t>(get());
}

bool VariableBase::is_string() const{
    return std::holds_alternative<std::string>(get());
}

bool VariableBase::is_array() const{
    return std::holds_alternative<Array_t>(get());
}

bool VariableBase::is_undef() const{
    return std::holds_alternative<std::monostate>(get());
}

bool VariableBase::is_numeric() const{
    return !is_undef() && !is_string() && !(is_array() && this->get<Array_t>().type()!=TYPE::STRING);
}

void VariableBase::value_to_tree(){
    if(is_value()){
        ArithmeticTree tree(this);
        tree.insert(std::make_shared<ValueNode>(std::move(get<Value_t>())));
        this->get()=std::move(tree);
    }
}

void VariableBase::tree_to_value(){
    if(is_arithmetic_tree())
        get() = get<ArithmeticTree>().value();
}

VariableBase::~VariableBase(){}

bool VariableBase::is_in_bounds(std::string_view data_base,std::string_view name) const{
    if(bounds_.contains(data_base) && bounds_.at(data_base).contains(name)){
        const VariableBase& var = *data_base_->get_pool()->get(data_base)->get(name);
        if(var.is_arithmetic_tree())
            return bounds_.at(data_base).at(name).is_in_bounds(var);
        else if(var.is_value())
            return bounds_.at(data_base).at(name).is_in_bounds(var);
        else return true;
    }
    else return true;
}

std::optional<Value_t> VariableBase::get_top_bound(std::string_view data_base,std::string_view var_name){
    if(bounds_.contains(data_base)){
        if(bounds_.at(data_base).contains(var_name)){
            return bounds_.at(data_base).at(var_name).get_top_bound_value();
        }
        else return std::nullopt;
    }
    else return std::nullopt;
}

std::optional<Value_t> VariableBase::get_bottom_bound(std::string_view data_base,std::string_view var_name){
    if(bounds_.contains(data_base)){
        if(bounds_.at(data_base).contains(var_name)){
            return bounds_.at(data_base).at(var_name).get_bottom_bound_value();
        }
        else return std::nullopt;
    }
    else return std::nullopt;
}

std::string_view VariableBase::get_data_base_name() const{
    return data_base_->name();
}

const std::unordered_set<VariableNode*>& Array_t::get_dependencies() const{
    return var_dependence_;
}