#include "abstract_node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"
#include "relation_manager.h"

AbstractNode::AbstractNode():
rel_mng_(BaseData::get_anonymous_relation_manager()){}

AbstractNode::AbstractNode(const std::shared_ptr<BaseData>& bd):
rel_mng_(bd->relation_manager()){}

AbstractNode::AbstractNode(RelationManager* rel_mng):
rel_mng_(rel_mng?rel_mng:BaseData::get_anonymous_relation_manager()){}

const std::shared_ptr<AbstractNode>& AbstractNode::child(size_t id) const{
    return rel_mng_->child(this,id);
}
std::shared_ptr<AbstractNode>& AbstractNode::child(size_t id){
    return rel_mng_->child(this,id);
}

bool AbstractNode::has_owner() const{
    return rel_mng_->has_owner(this);
}
AbstractNode* AbstractNode::owner() const{
    return rel_mng_->owner(this).parent;
}

std::shared_ptr<AbstractNode> AbstractNode::get_this() const{
    if(type()==NODE_TYPE::VARIABLE)
        return reinterpret_cast<const VariableNode*>(this)->variable()->node();
    else{
        assert(has_owner());
        return rel_mng_->owner(this).node();
    }
}

AbstractNode::~AbstractNode(){
    //rel_mng_-> call delete method for destructed node
}

AbstractNode::AbstractNode(size_t sz):
rel_mng_(BaseData::get_anonymous_relation_manager()){
    rel_mng_->reserve_childs(this,sz);
}

void AbstractNode::refresh() const{
    execute();
    refresh_parent_links();
    caller_ = true;
    for(auto& [parent,ids]:references())
        parent->refresh();
    caller_ = false;
}

bool AbstractNode::has_references() const{
    if(type()==NODE_TYPE::VARIABLE)
        return !references().empty();
    else return references().size()>0;
}
const std::vector<std::shared_ptr<AbstractNode>>& AbstractNode::childs() const{
    return rel_mng_->childs(this);
}
bool AbstractNode::has_childs() const noexcept{
    return rel_mng_->has_childs(this);
}
bool AbstractNode::has_child(size_t id) const noexcept{
    return rel_mng_->has_child(this,id);
}

TYPE_VAL AbstractNode::type_val() const{
    if(is_numeric()){
        if(is_array()) return TYPE_VAL::NUMERIC_ARRAY;   
        else return TYPE_VAL::VALUE;
    }
    else if(is_string()){
        if(is_array())
            return TYPE_VAL::STRING_ARRAY;
        else return TYPE_VAL::STRING;
    }
    else if(is_array()){
        if(is_array())
            return TYPE_VAL::ARRAY;
        else return TYPE_VAL::UNKNOWN;
    }
    else return TYPE_VAL::UNKNOWN;
}

Result AbstractNode::execute() const{
    return std::monostate();
}

Result AbstractNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    return std::make_shared<exceptions::InvalidTypeOfArgument>("objective numeric-result node");
}

std::string AbstractNode::get_result() const{
    std::stringstream result;
    print_result(result);
    return result.str();
}
std::string AbstractNode::get_text() const{
    std::stringstream result;
    print_text(result);
    return result.str();
}

bool AbstractNode::is_empty() const{
    return true;
}

bool AbstractNode::is_array() const{
    return false;
}

bool AbstractNode::is_numeric() const{
    return false;
}

bool AbstractNode::is_string() const{
    return false;
}

bool AbstractNode::refer_to(std::string_view var_name) const{
    if(childs().empty()){
        return false;
    }
    else {
        return std::any_of(childs().begin(),childs().end(),[var_name](const std::shared_ptr<AbstractNode>& child){
            if(child->type()==NODE_TYPE::VARIABLE && 
                std::dynamic_pointer_cast<VariableNode>(child)->variable()->name()==var_name)
                return true;
            else return child->refer_to(var_name);
        });
    }
}

bool AbstractNode::is_not_cycled() const{
    if(references().empty()){
        return true;
    }
    else {
        for(auto& [parent,id]:references()){
            if(!parent->__is_not_cycled__(this))
                return false;
        }
        return true;
    }
}

bool AbstractNode::__is_not_cycled__(const AbstractNode* node_cycled_search) const{
    if(this == node_cycled_search)
        return false;
    if(references().empty()){
        return true;
    }
    else {
        for(auto& [parent,id]:references()){
            if(!parent->__is_not_cycled__(node_cycled_search))
                return false;
        }
        return true;
    }
}

#include "aux_functions.h"

std::set<std::shared_ptr<VariableNode>> AbstractNode::refer_to_vars() const{
    return rel_mng_->refer_to_vars(this);
}

std::set<std::shared_ptr<AbstractNode>> AbstractNode::refer_to_node_of_type(NODE_TYPE t) const{
    return rel_mng_->refer_to_node_of_type(this,t);
}

void AbstractNode::refresh_parent_links() const{
    relation_manager()->refresh_parent_links(this);
}

const std::unordered_map<const AbstractNode*,std::vector<int>>& AbstractNode::references() const{
    return rel_mng_->references(this);
}
void AbstractNode::insert_back(std::shared_ptr<AbstractNode> node){
    rel_mng_->insert_back(this, node);
}
std::shared_ptr<AbstractNode> AbstractNode::insert(size_t id,std::shared_ptr<AbstractNode> node){
    return rel_mng_->insert(this, id, node);
}
std::shared_ptr<AbstractNode> AbstractNode::replace(size_t id,std::shared_ptr<AbstractNode> node){
    return rel_mng_->replace(this,id,node);
}
void AbstractNode::print_text(std::ostream& stream) const{
}
void AbstractNode::print_result(std::ostream& stream) const{
    stream<<0;
}
INFO_NODE AbstractNode::child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last){
    return rel_mng_->child(this,first,last);
}
void AbstractNode::__insert_back_string_node__(const std::string& string){
    insert_back(std::make_shared<StringNode>(string));
}
void AbstractNode::__insert_back_string_node__(std::string&& string){
    insert_back(std::make_shared<StringNode>(std::move(string)));
}
void AbstractNode::__insert_back_value_node__(const Value_t& val){
    insert_back(std::make_shared<ValueNode>(val));
}
void AbstractNode::__insert_back_value_node__(Value_t&& val){
    insert_back(std::make_shared<ValueNode>(std::move(val)));
}

#include "func_node.h"
#include "bin_node.h"
#include "range_node.h"
#include "unary_node.h"

//only copies childs. The owner and references will be set manually by insert/replace methods
AbstractNode::AbstractNode(const AbstractNode& other):
rel_mng_(other.rel_mng_),
caller_(other.caller_)
{
    if(&other!=this)
        rel_mng_->copy_childs(this,other.childs());
}

AbstractNode::AbstractNode(AbstractNode&& other):
rel_mng_(std::move(other.rel_mng_)),
caller_(other.caller_)
{
    if(&other!=this)
        rel_mng_->swap_childs(this,&other);
}
AbstractNode& AbstractNode::operator=(const AbstractNode& other){
    if(&other!=this)
        rel_mng_->copy_childs(this,other.childs());
    return *this;
}
AbstractNode& AbstractNode::operator=(AbstractNode&& other){
    if(&other!=this){
        rel_mng_->swap_childs(this,&other);
        caller_ = other.caller_;
    }
    return *this;
}

void AbstractNode::erase_child(size_t id) const{
    if(childs().size()>id)
        rel_mng_->erase_child(this,id);
    else throw std::invalid_argument("Invalid id for child delete");
}

void AbstractNode::__rel_tmp_forward_insert_back__(std::shared_ptr<AbstractNode> node){
    rel_mng_->insert_back(this,node);
}