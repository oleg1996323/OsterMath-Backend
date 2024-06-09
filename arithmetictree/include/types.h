#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "def.h"
#include "data.h"
#include "format.h"
#include "bound.h"
#include "serialize.h"

class VariableNode;
class VariableBase;
class Array_val;

struct Variable_ref{
    std::string_view var_name_;
    std::string_view db_name_;
};

using namespace std::string_literals;
using namespace std::string_view_literals;

class VariableBase: public FormattingData{

    public:

    virtual ~VariableBase();

    explicit VariableBase(std::string_view name, BaseData* data_base);

    template<typename T>
    void define(T&& value);

    std::string_view name() const;
    void refresh() const;

    const std::shared_ptr<VariableNode>& node() const;
    const std::shared_ptr<VariableNode>& node();

    bool is_expression() const;
    bool is_value() const;
    bool is_string() const;
    bool is_array() const;
    bool is_undef() const;
    bool is_numeric() const;

    void print_result();

    void print_text();

    std::string text();

    std::string text() const;

    void set_bottom_bound_value(std::string_view,std::string_view,std::shared_ptr<Node> value, BOTTOM_BOUND_T type);

    void set_top_bound_value(std::string_view,std::string_view,std::shared_ptr<Node> value, TOP_BOUND_T type);

    bool is_in_bounds(std::string_view,std::string_view) const;

    std::optional<Value_t> get_top_bound(std::string_view data_base,std::string_view var_name);

    std::optional<Value_t> get_bottom_bound(std::string_view data_base,std::string_view var_name);

    std::string_view get_data_base_name() const;

    Result result();

    Result result() const;
    
    void serialize(std::ostream& stream){
        stream<<"#TEXT";
        {
            std::ostream& prec_stream = get_stream();
            set_stream(stream);
            print_text();
            set_stream(prec_stream);
        }
        serialization::serialize_structure(stream,show_reinterpret_);
        stream<<std::endl;
    }

    void deserialize(std::istream& stream);

    protected:
    void set_data_base(BaseData* data_pool);
    BaseData* get_data_base() const;

    private:
    std::unordered_map<std::string_view,std::unordered_map<std::string_view,VariableBounds>> bounds_;
    std::shared_ptr<VariableNode> node_; //shared, так как может быть передан в любое арифметическое дерево
    std::string_view name_;
    std::string text_;
    bool show_reinterpret_=true; //show a reinterpreted formula
    BaseData* data_base_;
};