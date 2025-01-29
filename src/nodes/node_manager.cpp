#include "node_manager.h"
#include "core/settings.h"
#include "data.h"
#include <ranges>

const Childs_t NodeManager::empty_childs_{};
const References_t NodeManager::empty_references_{};

NodeManager::~NodeManager(){
    std::cout<<"NodeManager deleted"<<std::endl;
    nodes_.clear();
    log_state();
    assert(references_.empty());
    assert(childs_.empty());
    assert(owner_.empty());
}

void NodeManager::__reserve_childs__(const AbstractNode* node,size_t size){
    node->relation_manager()->childs_[node].reserve(size);
}

AbstractNode* NodeManager::child(const AbstractNode* node,size_t id){
    if(node->relation_manager()->childs_.contains(node) && id<node->relation_manager()->childs_.at(node).size())
        return node->relation_manager()->childs_.at(node).at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}
AbstractNode* NodeManager::child(AbstractNode* node,size_t id){
    return node->relation_manager()->childs_.at(node).at(id);
}
#include "var_node.h"
//get the node which is not intermediate (ValueNode, StringNode, RangeNode, FunctionNode, VariableNode, ArrayNode)
INFO_NODE NodeManager::child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept{
    if(node->type()==NODE_TYPE::VARIABLE || node->type()==NODE_TYPE::ARRAY || node->type()==NODE_TYPE::REF){ //only valuable node
        INFO_NODE info{node,*first};
        for(std::vector<int>::const_iterator iter=first;iter<last;++iter){
            if(info.parent->type()==NODE_TYPE::VARIABLE || info.parent->type()==NODE_TYPE::REF)
            {
                while (info.parent->type()==NODE_TYPE::VARIABLE || info.parent->type()==NODE_TYPE::REF)
                {
                    if(info.parent->has_child(0)){
                        info.parent = info.parent->child(0);
                        info.id = *iter;
                        if(info.has_node())
                            continue;
                        else return INFO_NODE();
                    }
                    else
                        return INFO_NODE();
                }
            }
            else{
                if(info.has_node()){
                    info.parent = info.node();
                    info.id = *iter;
                    if(!info.has_node())
                        return INFO_NODE();
                    while (info.parent->type()==NODE_TYPE::VARIABLE || info.parent->type()==NODE_TYPE::REF)
                    {
                        if(info.parent->has_child(0)){
                            info.parent = info.parent->child(0);
                            info.id = *iter;
                            if(info.has_node())
                                continue;
                            else return INFO_NODE();
                        }
                        else
                            return INFO_NODE();
                    }
                }
                else return INFO_NODE();
            }
            assert(info.has_node());
        }
        return info;
    }
    else return INFO_NODE();
}
const std::unique_ptr<AbstractNode>& NodeManager::get_node(NodeManager* rel_mng, const AbstractNode* node_ptr){
    if(rel_mng->nodes_.contains(node_ptr)){
        return *rel_mng->nodes_.find(node_ptr);
    }
    static std::unique_ptr<AbstractNode> empty;
    return empty;
}
INFO_NODE NodeManager::owner(const AbstractNode* node) noexcept{
    if(node->relation_manager()->owner_.contains(node))
        return node->relation_manager()->owner_.at(node);
    else return INFO_NODE();
}
void NodeManager::__add_owner__(const AbstractNode* node_to_add, const AbstractNode* owner, int index) noexcept{
    assert(node_to_add->type()!=NODE_TYPE::VARIABLE);
    assert(!node_to_add->relation_manager()->owner_.contains(node_to_add));
    //++node_to_add->relation_manager()->constructed;
    INFO_NODE info;
    info.parent = const_cast<AbstractNode*>(owner);
    info.id = index;
    node_to_add->relation_manager()->owner_[node_to_add] = info;
    assert(node_to_add->owner().parent==owner);
}

ReferenceNode* NodeManager::__add_reference__(const AbstractNode* node_to_add, ReferenceNode* ref_node) noexcept{
    //variable type cannot has owner (only BaseData class object)
    assert(node_to_add);
    assert(ref_node);
    return *node_to_add->relation_manager()->references_[node_to_add].insert(ref_node).first;
}
bool NodeManager::has_references(const AbstractNode* node) noexcept{
    return node->relation_manager()->references_.contains(node);
}
bool NodeManager::has_owner(const AbstractNode* node) noexcept{
    return node->relation_manager()->owner_.contains(node) && node->relation_manager()->owner_.at(node).has_node();
}
AbstractNode* NodeManager::add_node(NodeManager* mng,std::unique_ptr<AbstractNode>&& node){
    if(mng && node)
        return mng->nodes_.insert(std::move(node)).first->get();
    else return nullptr;
}
#include "var_node.h"
std::set<const VariableNode*> NodeManager::refer_to_vars(const AbstractNode* node) noexcept{
    std::set<const VariableNode*> vars_;
    for(const AbstractNode* child:node->childs()){
        if(child->type()==NODE_TYPE::VARIABLE)
            vars_.insert(static_cast<const VariableNode*>(child));
        else
            vars_.merge(child->refer_to_vars());
    }
    return vars_;
}
std::set<const AbstractNode*> NodeManager::refer_to_node_of_type(const AbstractNode* node, NODE_TYPE type) noexcept{
    std::set<const AbstractNode*> nodes_;
    for(const AbstractNode* child:node->childs()){
        if(child->type()==type)
            nodes_.insert(child);
        else
            nodes_.merge(child->refer_to_node_of_type(type));
    }
    return nodes_;
}
bool NodeManager::is_reference_of(const AbstractNode* from, AbstractNode* node){
    return from->relation_manager()->references_.contains(from) && std::find_if(
                                    from->relation_manager()->references_.at(from).begin(),
                                    from->relation_manager()->references_.at(from).end(),
                                    [node](ReferenceNode* ref_node){return ref_node->owner().parent && ref_node->owner().parent==node;})!=
                                    from->relation_manager()->references_.at(from).end();
}
bool NodeManager::has_childs(const AbstractNode* node) noexcept{
    return node->relation_manager()->childs_.contains(node) &&
        !node->relation_manager()->childs_.at(node).empty();
}
bool NodeManager::has_child(const AbstractNode* node, size_t id) noexcept{
    if(node->childs().size()>id)
        return true;
    return false;
    return node->relation_manager()->childs_.contains(node) && node->relation_manager()->childs_.at(node).size()>id;
}
void NodeManager::release_childs(const AbstractNode* node) noexcept{
    if(node->has_childs()){
        for(size_t i = 0;i<node->relation_manager()->childs_.at(node).size();++i){
            if(node->relation_manager()->childs_.at(node).at(i)->owner().parent==node){
                auto found = node->relation_manager()->childs_.at(node).at(i)->relation_manager()->nodes_.find(
                    node->relation_manager()->childs_.at(node).at(i));
                assert(found!=node->relation_manager()->childs_.at(node).at(i)->relation_manager()->nodes_.end());
                if(node->type()==NODE_TYPE::REF)
                    (found->get())->relation_manager()->references_.at(found->get()).erase((ReferenceNode*)(node));
                node->relation_manager()->childs_.at(node).at(i)->relation_manager()->nodes_.erase(found);
            }
        }
        node->relation_manager()->childs_.erase(node); //value contains childs (need to check)
    }
    node->relation_manager()->childs_.erase(node); //value contains childs (need to check)
}
const References_t& NodeManager::references(const AbstractNode* node) noexcept{
    if(node->relation_manager()->references_.contains(node))
        return node->relation_manager()->references_.at(node);
    else return NodeManager::empty_references_;
}
//TODO: write test
void NodeManager::erase_child(const AbstractNode* node, size_t id) noexcept{
    if(node->has_child(id)){ //TODO: check if it is reference or owned node (then must be deleted)
        if(node->type()!=NODE_TYPE::REF){
            auto tmp = node->child(id);
            node->relation_manager()->childs_.at(node).erase(node->relation_manager()->childs_.at(node).begin()+id);
            node->relation_manager()->nodes_.erase(
                get_node(node->relation_manager(),tmp));
        }
        else{
            static_cast<const ReferenceNode*>(node)->child(0)->relation_manager()->references_.at(node->child(0)).erase((ReferenceNode*)node);
            node->relation_manager()->childs_.erase(node);
        }
    }
}
//TODO: write test (compare childs before and childs after, nodes before and after)
void NodeManager::erase_childs(const AbstractNode* node, size_t first_id, size_t last_id) noexcept{
    assert(node);
    NodeManager* rel_mng = node->relation_manager();
    auto childs_iter = rel_mng->childs_.find(node);
    if(childs_iter!=rel_mng->childs_.end()){
        Childs_t& childs = childs_iter->second;
        if(first_id>last_id)
            std::swap(first_id,last_id);
        Childs_t::const_iterator first_iter = first_id<(size_t)std::distance(childs.begin(),childs.end())?childs.begin()+first_id:childs.end();
        Childs_t::const_iterator last_iter = first_iter!=childs.end() && last_id<(size_t)std::distance(childs.begin(),childs.end())?childs.begin()+last_id:childs.end();
        Childs_t tmp;
        std::cout<<std::distance(first_iter,last_iter)<<std::endl;
        if(std::distance(first_iter,last_iter)>0){
            tmp.resize(std::distance(first_iter,last_iter));
            std::copy(first_iter,last_iter,tmp.begin());
        }
        childs.erase(first_iter,last_iter);
        for(auto to_delete:tmp)
            rel_mng->nodes_.erase(get_node(rel_mng,to_delete));
    }
    else return;
}
void NodeManager::delete_node(const AbstractNode* node){
    //++node->relation_manager()->destructed;
    auto found = node->relation_manager()->references_.find(node);
    if(found!=node->relation_manager()->references_.end()){
        for(auto ref:found->second)
            ref->relation_manager()->childs_.at(ref).resize(0); //the refs may be already deleted (should be deleted in references_ of childs in release_childs())
        node->relation_manager()->references_.erase(node);
    }
    release_childs(node);
    node->relation_manager()->owner_.erase(node);
}
#include "arithmetic_types.h"
#include <algorithm>

bool NodeManager::is_directly_owned_by(const AbstractNode* owner, const AbstractNode* node) noexcept{
    assert(node);
    assert(owner);
    if(node->has_owner())
        if(owner==node->owner().parent)
            return true;
        else return is_directly_owned_by(owner,node->owner().parent);
    else return false;
}
bool NodeManager::is_refered_by(const AbstractNode* ref_owner, const AbstractNode* refered) noexcept{
    assert(ref_owner);
    assert(refered);
    if(!refered->relation_manager()->references_.contains(refered))
        return false;
    for(auto ref:refered->relation_manager()->references_.at(refered))
        if(ref->owner().parent==ref_owner)
            return true;
        else continue;
    return false;
}
ReferenceNode* NodeManager::__erase_reference__(const AbstractNode* from_node, ReferenceNode* ref) noexcept{
    auto found = from_node->relation_manager()->references_.at(from_node).find(ref);
    assert(found!=from_node->relation_manager()->references_.at(from_node).end());
    return from_node->relation_manager()->references_.at(from_node).extract(found).value();
}
void NodeManager::__safe_merge__(NodeManager* from) noexcept{
    nodes_.merge(from->nodes_);
    for(auto& pair:from->references_)
        references_[pair.first].merge(pair.second);
    for(auto& pair:from->childs_){
        assert(!childs_.contains(pair.first));
        std::move(pair.second.begin(),pair.second.end(),childs_[pair.first].begin());
    }
    owner_.merge(from->owner_);
    from->__clear__();
}
void NodeManager::__clear__(){
    nodes_.clear();
    references_.clear();
    childs_.clear();
    owner_.clear();
}
//use anonymous NodeManager for safe inclusions
void NodeManager::begin(NodeManager* mng){
    assert(mng);
    mng->begin();
}
//safe_merge if no one exception was thrown
void NodeManager::end(NodeManager* mng){
    assert(mng);
    mng->end();
}
bool NodeManager::is_modifying(NodeManager* from){
    return from->modifyable_;
}
void NodeManager::begin(){
    assert(!modifyable_);
    modifyable_ = true;
}
void NodeManager::end(){
    assert(modifyable_);
    __safe_merge__(BaseData::get_anonymous_relation_manager());
    modifyable_ = false;
}
AbstractNode* NodeManager::insert_back_ref(ReferenceNode* node,AbstractNode* new_child){
    if(node && new_child){
        assert(node->type()==NODE_TYPE::REF);
        if(node->has_child(0)){
            node->relation_manager()->childs_.at(node).clear();
            __erase_reference__(node->child(0),node);
        }
        __add_reference__(new_child,node);
        return node->relation_manager()->childs_[node].emplace_back(new_child);
    }
    else
        return nullptr;
}
#include "empty_node.h"
AbstractNode* NodeManager::insert_back_move(AbstractNode* at_insert_back, AbstractNode* inserted){
    return insert_move(at_insert_back,at_insert_back->childs().size(),inserted);
}
AbstractNode* NodeManager::insert_back_copy(AbstractNode* at_insert_back, AbstractNode* inserted){
    return insert_copy(at_insert_back,at_insert_back->childs().size(),inserted);
}
Childs_Iter_t NodeManager::insert_back_move(AbstractNode* at_insertion,Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    return insert_move(at_insertion,at_insertion->childs().size(),to_move_first,to_move_last);
}
Childs_Iter_t NodeManager::insert_back_copy(AbstractNode* at_insertion,Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    return insert_copy(at_insertion,at_insertion->childs().size(),to_copy_first,to_copy_last);
}
Childs_Iter_t NodeManager::insert_back_empty_nodes(AbstractNode* at_insertion, size_t count){
    return insert_empty_nodes(at_insertion,at_insertion->childs().size(),count);
}
#include "func_node.h"
AbstractNode* NodeManager::insert_back(AbstractNode* node,std::unique_ptr<AbstractNode>&& new_child){
    if(node && new_child)
        return insert(node,node->childs().size(),std::move(new_child));
    else return nullptr;
}
//insert before value at id
AbstractNode* NodeManager::insert(AbstractNode* node,size_t id,std::unique_ptr<AbstractNode>&& new_child){
    if(node){
        assert(id<=node->relation_manager()->childs_[node].size());
        assert(node->relation_manager()==new_child->relation_manager());
        node->flush_cache();
        AbstractNode* return_ptr = nullptr;
        switch (node->type())
        {
            case NODE_TYPE::ARRAY:{
                return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::VARIABLE:
                assert(node->relation_manager()->bd_);
            case NODE_TYPE::REF:
            case NODE_TYPE::RANGEOP:{
                if(has_child(node,0))
                    node->relation_manager()->childs_.at(node).at(0)=new_child.get();
                else return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::UNARY:{
                assert(id<1);
                assert(node->relation_manager()->childs_[node].size()<1);
                return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::BINARY:{
                assert(id<2);
                assert(node->relation_manager()->childs_[node].size()<2);
                return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::FUNCTION:{
                if(!static_cast<FunctionNode*>(node)->is_array_function())
                    if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity()){
                        return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                        break;
                    }
                    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
                else return_ptr = *node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::VALUE:
            case NODE_TYPE::STRING:
            case NODE_TYPE::UNDEF:
            case NODE_TYPE::CUSTOM:{
                //will be added further at next version with lambda functions
                throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert back child to this type of node");
                break;
            }
            default:
                break;
        }
        assert(!node->childs().empty());
        __add_owner__(new_child.get(),node, id);
        assert(!node->relation_manager()->nodes_.contains(new_child));
        node->relation_manager()->nodes_.insert(std::move(new_child));
        return return_ptr;
    }
    return nullptr;
}
AbstractNode* NodeManager::insert_move(AbstractNode* at_insertion,size_t id,AbstractNode* to_insert){
    AbstractNode* tmp = at_insertion->insert<EmptyNode>(id);
    move_node(tmp,to_insert);
    return to_insert;
}
#include "array_node.h"
#include "bin_node.h"
#include "range_node.h"
#include "ref_node.h"
#include "string_node.h"
#include "val_node.h"
#include "unary_node.h"
AbstractNode* NodeManager::insert_copy(AbstractNode* at_insertion,size_t id,AbstractNode* to_insert){
    AbstractNode* tmp;
    assert(to_insert->type()!=NODE_TYPE::VARIABLE);
    switch(to_insert->type()){
        case NODE_TYPE::ARRAY:{
            tmp = at_insertion->insert<ArrayNode>(id,*static_cast<const ArrayNode*>(to_insert));
            break;
        }
        case NODE_TYPE::BINARY:{
            tmp = at_insertion->insert<BinaryNode>(id,*static_cast<const BinaryNode*>(to_insert));
            break;
        }
        case NODE_TYPE::FUNCTION:{
            tmp = at_insertion->insert<FunctionNode>(id,*static_cast<const FunctionNode*>(to_insert));
            break;
        }
        case NODE_TYPE::RANGEOP:{
            tmp = at_insertion->insert<RangeOperationNode>(id,*static_cast<const RangeOperationNode*>(to_insert));
            break;
        }
        case NODE_TYPE::REF:{
            tmp = at_insertion->insert<ReferenceNode>(id,*static_cast<const ReferenceNode*>(to_insert));
            break;
        }
        case NODE_TYPE::STRING:{
            tmp = at_insertion->insert<StringNode>(id,*static_cast<const StringNode*>(to_insert));
            break;
        }
        case NODE_TYPE::UNARY:{
            tmp = at_insertion->insert<UnaryNode>(id,*static_cast<const UnaryNode*>(to_insert));
            break;
        }
        case NODE_TYPE::UNDEF:{
            tmp = at_insertion->insert<EmptyNode>(id,*static_cast<const EmptyNode*>(to_insert));
            break;
        }
        case NODE_TYPE::VALUE:{
            tmp = at_insertion->insert<ValueNode>(id,*static_cast<const ValueNode*>(to_insert));
            break;
        }
        default:{
            throw std::runtime_error("Unable to insert");
            break;
        }
    }
    return tmp;
}
Childs_Iter_t NodeManager::insert_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    static const Childs_Iter_t empty;
    if(id==0 || (at_insertion->has_childs() && at_insertion->childs().size()>=id)){
        Childs_Iter_t tmp_empty_nodes = insert_empty_nodes(at_insertion,id,std::distance(to_move_first,to_move_last));
        return move_nodes(tmp_empty_nodes.first,to_move_first,to_move_last);
    }
    else return empty;
}
Childs_Iter_t NodeManager::insert_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    static const Childs_Iter_t empty;
    if(id==0 || (at_insertion->has_childs() && at_insertion->childs().size()>=id)){
        Childs_Iter_t tmp_empty_nodes = insert_empty_nodes(at_insertion,id,std::distance(to_copy_first,to_copy_last));
        return copy_nodes(tmp_empty_nodes.first,to_copy_first,to_copy_last);
    }
    else return empty;
}
AbstractNode* NodeManager::replace_move(AbstractNode* at_replacing,size_t id,AbstractNode* to_replace){
    if(at_replacing->has_child(id))
        move_node(at_replacing->child(id),to_replace);
    return to_replace;
}
AbstractNode* NodeManager::replace_copy(AbstractNode* at_replacing,size_t id,AbstractNode* to_replace){
    if(at_replacing->has_child(id))
        copy_node(at_replacing->child(id),to_replace);
    return to_replace;
}
Childs_Iter_t NodeManager::replace_move(AbstractNode* at_replacing,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    static const Childs_Iter_t empty;
    if(at_replacing->childs().size()>=id){
        auto& childs = at_replacing->childs();
        return move_nodes(childs.begin()+id,to_move_first,to_move_last);
    }
    else return empty;
}
Childs_Iter_t NodeManager::replace_copy(AbstractNode* at_replacing,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    static const Childs_Iter_t empty;
    if(at_replacing->childs().size()>=id){
        auto& childs = at_replacing->childs();
        return copy_nodes(childs.begin()+id,to_copy_first,to_copy_last);
    }
    else return empty;
}
AbstractNode* NodeManager::replace(AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child){
    if(node){
        assert(id<node->relation_manager()->childs_[node].size());
        assert(node->relation_manager()==new_child->relation_manager());
        node->flush_cache();
        AbstractNode* return_ptr = nullptr;
        switch (node->type())
        {
            case NODE_TYPE::FUNCTION:
                if(!static_cast<FunctionNode*>(node)->is_array_function()){
                    if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity()){}
                    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
                }
            case NODE_TYPE::RANGEOP:{
                assert(id==0);
            }
            case NODE_TYPE::ARRAY:{
                return_ptr = new_child.get();
                node->relation_manager()->nodes_.insert(std::move(new_child));
                move_node(new_child.get(),node);
                break;
            }
            case NODE_TYPE::REF:
                //TODO
                assert(false);
                break;
            case NODE_TYPE::UNARY:
            case NODE_TYPE::BINARY:
            case NODE_TYPE::VARIABLE:            
            case NODE_TYPE::VALUE:
            case NODE_TYPE::STRING:
            case NODE_TYPE::UNDEF:
                assert(false);
                break;
            case NODE_TYPE::CUSTOM:
                //will be added further at next version with lambda functions
                throw std::logic_error("Invalid replacing. Prompt: Unvalailable to replace child to this type of node");
                break;
            default:
                break;
        }
        return return_ptr;
    }
    return nullptr;
}
//@at_move - which is removed; @to_move - which is moved to position of at_move
void NodeManager::move_node(AbstractNode* at_move, AbstractNode* to_move){
    assert(at_move->type()!=NODE_TYPE::VARIABLE);
    if(at_move && to_move && at_move!=to_move){
        References_t loc_references_; //referencing, but not owning parents
        Childs_t loc_childs_;
        INFO_NODE loc_owner; //parent, which own this node
        NodeManager* loc_rel_mng = to_move->relation_manager();
        std::function<void(const AbstractNode*, const AbstractNode*)> update_child = [&update_child,&loc_owner,loc_rel_mng](const AbstractNode* child, const AbstractNode* owner){
            if(owner->relation_manager()!=child->relation_manager()){
                if(owner->type()!=NODE_TYPE::REF){
                    assert(child->relation_manager()->owner_.contains(child) && child->relation_manager()->owner_.at(child).is_valid());
                    loc_rel_mng->owner_[child] = std::move(child->relation_manager()->owner_.extract(child).mapped());
                    if(child->has_references()){
                        loc_rel_mng->references_[child].swap(child->relation_manager()->references_.at(child));
                        child->relation_manager()->references_.erase(child);
                    }
                    if(owner->type()!=NODE_TYPE::REF){
                        loc_rel_mng->nodes_.insert(std::move(child->relation_manager()->nodes_.extract(*child->relation_manager()->nodes_.find(child))));
                        child->relation_manager()->nodes_.erase(*child->relation_manager()->nodes_.find(child));
                        child->set_relation_manager(loc_rel_mng);
                        std::for_each(child->childs().begin(), child->childs().end(),[child, &update_child](const AbstractNode* sub_child){
                            update_child(sub_child,child);
                        });
                    }
                }
                else{
                    if(child->type()!=NODE_TYPE::VARIABLE && child->relation_manager()->childs_.contains(child))
                        loc_rel_mng->childs_.insert(child->relation_manager()->childs_.extract(child));
                }
            }
        };
        //temporaly saving further removed node
        std::unique_ptr<AbstractNode> at_move_node = std::move(at_move->relation_manager()->nodes_.extract(
                at_move->relation_manager()->nodes_.find(at_move)).value());
        //move to local nodes container temporaly before merge (for safety)
        std::unique_ptr<AbstractNode> to_move_node = std::move(to_move->relation_manager()->nodes_.extract(
                get_node(to_move->relation_manager(),to_move)).value());
        //erasing @to_move's references
        if(to_move->has_references()){
            loc_references_.swap(to_move->relation_manager()->references_.at(to_move));
        }
        //move references of @at_move to @to_move
        if(at_move->has_references()){
            for(const ReferenceNode* ref:at_move->relation_manager()->references_.at(at_move))
                ref->relation_manager()->childs_.erase(ref); //delete the refs childs (to the @at_move)
            at_move->relation_manager()->references_.erase(at_move);
            if(at_move->relation_manager()!=to_move->relation_manager())
                to_move->relation_manager()->references_.erase(to_move);
        }
        assert(!at_move->relation_manager()->references_.contains(at_move));
        //swap owners
        if(to_move->type()!=NODE_TYPE::VARIABLE){
            loc_owner = std::move(to_move->relation_manager()->owner_.extract(to_move).mapped());
            auto& tmp_child = to_move->relation_manager()->childs_.at(loc_owner.parent);
            tmp_child.erase(loc_owner.id+tmp_child.begin()); //delete @to_move from parent
            if(tmp_child.empty()) //if empty, delete childs fully
                to_move->relation_manager()->childs_.erase(loc_owner.parent);
            loc_owner = at_move->owner();
            at_move->relation_manager()->childs_.at(at_move->owner().parent).at(at_move->owner().id)=to_move; //replace child pointer
            at_move->relation_manager()->owner_.erase(at_move);
        }
        //swap childs and NodeManager pointer
        if(to_move->has_childs())
            loc_childs_.swap(to_move->relation_manager()->childs_.extract(to_move).mapped());
        if(at_move->relation_manager()!=to_move->relation_manager()){
            to_move->set_relation_manager(at_move->relation_manager());
            at_move->set_relation_manager(loc_rel_mng);
        }
        for(AbstractNode* child:loc_childs_)
            update_child(child,to_move);
        
        //TODO: add case when to_move is variable node (need to add referencenode)
        to_move->relation_manager()->nodes_.insert(std::move(to_move_node));
        to_move->relation_manager()->references_[to_move].swap(loc_references_);
        to_move->relation_manager()->childs_[to_move].swap(loc_childs_);
        to_move->relation_manager()->owner_[to_move].swap(loc_owner);
    }
}

Childs_Iter_t NodeManager::move_nodes(Childs_t::const_iterator at_move_first, Childs_t::const_iterator to_move_first, Childs_t::const_iterator to_move_last){
    static Childs_Iter_t empty;
    INFO_NODE at_ptr = (*at_move_first)->owner();
    if(at_ptr.node() && at_ptr.node()->type()!=NODE_TYPE::VARIABLE){
        Childs_t& at_childs = at_ptr.parent->relation_manager()->childs_.at(at_ptr.parent);
        if(at_childs.end()-at_move_first+at_childs.capacity()-at_childs.size()<to_move_last-to_move_first){
            at_childs.reserve(to_move_last-to_move_first);
            at_move_first=at_childs.begin()+at_ptr.id;
        }
        for()
    }
    return empty;
}
Childs_Iter_t NodeManager::copy_nodes(Childs_t::const_iterator at_copy_first, Childs_t::const_iterator to_copy_first, Childs_t::const_iterator to_copy_last){
    static Childs_Iter_t empty;
    if(*at_copy_first && *to_copy_first && *to_copy_last && 
        (*at_copy_first)->owner().parent->childs().end()<to_copy_last &&
        (*at_copy_first)->owner().parent->childs().begin()>to_copy_first)
    {
        AbstractNode* loc_parent_ = (*to_copy_first)->owner().parent;
        AbstractNode* at_parent = (*at_copy_first)->owner().parent;
        const Childs_t& at_childs = at_parent->childs();
        loc_parent_->relation_manager()->childs_.at(loc_parent_).erase(to_copy_first,to_copy_last);
        if(at_childs.end()-at_copy_first<to_copy_last-to_copy_first)
            insert_back_empty_nodes(at_parent,(to_copy_last-to_copy_first)-(at_childs.end()-at_copy_first));
        for(Childs_t::const_iterator iter = to_copy_first;iter!=to_copy_last;++iter){
            loc_parent_->relation_manager()->owner_.erase(*iter);
            copy_node(*(at_copy_first+(iter-to_copy_first)),*iter);
        }
        return Childs_Iter_t{at_copy_first,at_copy_first+(to_copy_last-to_copy_first)};
    }
    return empty;
}

void NodeManager::swap_node(AbstractNode* lhs, AbstractNode* rhs){
    assert(lhs->type()!=NODE_TYPE::VARIABLE && rhs->type()!=NODE_TYPE::VARIABLE);
    if(lhs && rhs && lhs!=rhs){
        std::function<void(const AbstractNode*, const AbstractNode*)> update_child = [&update_child](const AbstractNode* child, const AbstractNode* owner){
            if(child->type()!=NODE_TYPE::VARIABLE){
                assert(child->relation_manager()->owner_.contains(child) && child->relation_manager()->owner_.at(child).is_valid());
                child->relation_manager()->owner_.at(child).parent = const_cast<AbstractNode*>(owner);
            }
            if(owner->relation_manager()!=child->relation_manager()){
                if(child->has_references()){
                    owner->relation_manager()->references_[child].swap(child->relation_manager()->references_.at(child));
                    child->relation_manager()->references_.erase(child);
                }
                owner->relation_manager()->nodes_.insert(std::move(child->relation_manager()->nodes_.extract(*child->relation_manager()->nodes_.find(child))));
                child->relation_manager()->nodes_.erase(*child->relation_manager()->nodes_.find(child));
                std::for_each(child->childs().begin(), child->childs().end(),[child, &update_child](const AbstractNode* sub_child){
                    update_child(sub_child,child);
                });
            }
        };
        //swap node unique ptrs
        if(lhs->relation_manager()!=rhs->relation_manager()){
            lhs->relation_manager()->nodes_.insert(std::move(rhs->relation_manager()->nodes_.extract(rhs->relation_manager()->nodes_.find(rhs))));
            rhs->relation_manager()->nodes_.insert(std::move(lhs->relation_manager()->nodes_.extract(lhs->relation_manager()->nodes_.find(lhs))));
            lhs->relation_manager()->nodes_.erase(lhs->relation_manager()->nodes_.find(lhs));
            rhs->relation_manager()->nodes_.erase(rhs->relation_manager()->nodes_.find(rhs));
        }
        //swap references
        if(lhs->relation_manager()->references_.contains(lhs)){
            for(const ReferenceNode* ref:lhs->relation_manager()->references_.at(lhs))
                ref->relation_manager()->childs_.at(ref).at(0)=rhs;
            lhs->relation_manager()->references_[rhs].swap(lhs->relation_manager()->references_.at(lhs));
            lhs->relation_manager()->references_.erase(lhs);
        }
        if(rhs->relation_manager()->references_.contains(rhs)){
            for(const ReferenceNode* ref:rhs->relation_manager()->references_.at(rhs))
                ref->relation_manager()->childs_.at(ref).at(0)=lhs;
            rhs->relation_manager()->references_[lhs].swap(rhs->relation_manager()->references_.at(rhs));
            rhs->relation_manager()->references_.erase(rhs);
        }

        //swap childs
        if(lhs->has_childs() && rhs->has_childs()){
            std::swap(lhs->relation_manager()->childs_.at(lhs),
                rhs->relation_manager()->childs_.at(rhs));
            for(size_t i = 0;i<lhs->relation_manager()->childs_.at(lhs).size();++i)
                update_child(lhs->relation_manager()->childs_.at(lhs).at(i),lhs);
            for(size_t i = 0;i<rhs->relation_manager()->childs_.at(rhs).size();++i)
                update_child(rhs->relation_manager()->childs_.at(rhs).at(i),rhs);
        }
        else if(lhs->has_childs()){
            rhs->relation_manager()->childs_[rhs].swap(lhs->relation_manager()->childs_.at(lhs));
            lhs->relation_manager()->childs_.erase(lhs);
            for(size_t i = 0;i<rhs->relation_manager()->childs_.at(rhs).size();++i)
                update_child(rhs->relation_manager()->childs_.at(rhs).at(i),rhs);
        }
        else if(rhs->has_childs()){
            lhs->relation_manager()->childs_[lhs].swap(rhs->relation_manager()->childs_.at(rhs));
            rhs->relation_manager()->childs_.erase(rhs);
            for(size_t i = 0;i<lhs->relation_manager()->childs_.at(lhs).size();++i)
                update_child(lhs->relation_manager()->childs_.at(lhs).at(i),lhs);
        }
        else{}

        //swap owners
        {
            lhs->relation_manager()->childs_.at(lhs->owner().parent).at(lhs->owner().id)=rhs;
            rhs->relation_manager()->childs_.at(rhs->owner().parent).at(rhs->owner().id)=lhs;
            AbstractNode* tmp_parent = lhs->relation_manager()->owner_.at(lhs).parent;
            lhs->relation_manager()->owner_.at(lhs).parent = rhs->relation_manager()->owner_.at(rhs).parent;
            rhs->relation_manager()->owner_.at(rhs).parent = tmp_parent;
        }

        //setting node managers
        {
            NodeManager* tmp_nm = lhs->relation_manager();
            lhs->set_relation_manager(rhs->relation_manager());
            rhs->set_relation_manager(tmp_nm);
        }
    }
}
void NodeManager::copy_node(AbstractNode* to_replace_by_copy, const AbstractNode* to_copy){
    //decltype(to_replace_by_copy->relation_manager()->childs_) tmp_childs;
    std::vector<std::unique_ptr<AbstractNode>> tmp_nodes = [to_copy](){std::vector<std::unique_ptr<AbstractNode>> vector;vector.reserve(to_copy->childs().size());return vector;}();
    for(const AbstractNode* child:to_copy->childs()){
        std::unique_ptr<AbstractNode> tmp_node;
        switch(child->type()){
            case NODE_TYPE::ARRAY:{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<ArrayNode>(*static_cast<const ArrayNode*>(child)); //need to check
                break;
            }
            case NODE_TYPE::BINARY :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<BinaryNode>(*static_cast<const BinaryNode*>(child)); //need to check
                break;                        
            }
            case NODE_TYPE::RANGEOP :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<RangeOperationNode>(*static_cast<const RangeOperationNode*>(child)); //need to check
                break;                        
            }
            case NODE_TYPE::FUNCTION :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<FunctionNode>(*static_cast<const FunctionNode*>(child)); //need to check
                break;                        
            }
            case NODE_TYPE::STRING :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<StringNode>(*static_cast<const StringNode*>(child)); //need to check
                break;                        
            }
            case NODE_TYPE::UNARY :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<UnaryNode>(*static_cast<const UnaryNode*>(child)); //need to check
                break;                        
            }
            case NODE_TYPE::VALUE :{
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<ValueNode>(*static_cast<const ValueNode*>(child)); //need to check
                break;
            }
            case NODE_TYPE::REF:{
                //mustn't copy child (need check)
                tmp_node = to_replace_by_copy->relation_manager()->bd_->make_node<ReferenceNode>(*static_cast<const ReferenceNode*>(child)); //need to check
                break;
            }
            case NODE_TYPE::CUSTOM :{
                //TODO: integrate further
                assert(true);
                break;
            }
            case NODE_TYPE::VARIABLE:{
                //TODO: put reference
                //node->insert_back(child);
                break;
            }
            default:{
                tmp_node = std::make_unique<EmptyNode>(); //need to check
                break;
            }
        }
        tmp_nodes.push_back(std::move(tmp_node));
    }
    release_childs(to_replace_by_copy);
    for(size_t id=0;id<tmp_nodes.size();++id)
        insert_back(to_replace_by_copy,std::move(tmp_nodes.at(id)));
}

std::unique_ptr<AbstractNode> NodeManager::extract_node(AbstractNode* node){
    // auto found = node->relation_manager()->references_.find(node);
    // if(found!=node->relation_manager()->references_.end()){
    //     for(auto ref:found->second)
    //         ref->relation_manager()->childs_.at(ref).resize(0); //the refs may be already deleted (should be deleted in references_ of childs in release_childs())
    //     node->relation_manager()->references_.erase(node);
    // }
    // release_childs(node);
    assert(node->type()!=NODE_TYPE::VARIABLE);
    INFO_NODE owner = node->relation_manager()->owner_.at(node);
    Childs_t& childs = node->relation_manager()->childs_.at(owner.parent);
    childs.erase(childs.begin()+owner.id);
    node->relation_manager()->owner_.erase(node);
    return std::move(node->relation_manager()->nodes_.extract(get_node(node->relation_manager(),node)).value());
}
std::vector<std::unique_ptr<AbstractNode>> NodeManager::extract_nodes(Childs_t::const_iterator first,Childs_t::const_iterator last){
    //assert(node->type()!=NODE_TYPE::VARIABLE);
    std::vector<std::unique_ptr<AbstractNode>> result;
    for(auto node:std::ranges::subrange(first,last)){
        result.push_back(std::move(node->relation_manager()->nodes_.extract(get_node(node->relation_manager(),node)).value()));
    }
    Childs_t& childs = node->relation_manager()->childs_.at(owner.parent);
}