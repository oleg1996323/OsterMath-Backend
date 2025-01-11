#include "node_manager.h"
#include "core/settings.h"
#include "data.h"

const Childs_t NodeManager::empty_childs_{};
const References_t NodeManager::empty_references_{};

NodeManager::~NodeManager(){
    std::cout<<"NodeManager deleted"<<std::endl;
}

void NodeManager::reserve_childs(const AbstractNode* node,size_t size){
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
//get the node which is not intermediate (ValueNode, StringNode, RangeNode, FunctionNode, VariableNode, ArrayNode)
INFO_NODE NodeManager::child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept{
    if(node->type()==NODE_TYPE::VARIABLE || node->type()==NODE_TYPE::ARRAY){ //only valuable node
        INFO_NODE info{node,*first};
        std::vector<int>::const_iterator iter;
        for(iter=first;iter<last;++iter){
            if(info.parent->type()==NODE_TYPE::VARIABLE){
                while (info.parent->type()==NODE_TYPE::VARIABLE)
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
            else{
                if(info.has_node()){
                    info.parent = info.node();
                    info.id = *iter;
                    if(!info.has_node())
                        return INFO_NODE();
                }
                else return INFO_NODE();
            }
            assert(info.has_node());
        }
        if(kernel::settings::Model::show_through_var_nodes()){
            while (info.node()->type()==NODE_TYPE::VARIABLE)
                if(info.node()->has_child(0)){
                    info.parent = info.node();
                    info.id = 0;
                }
                else
                    return INFO_NODE();
            return info; 
        }
        return info;
    }
    else return INFO_NODE();
}
const std::unique_ptr<AbstractNode>& NodeManager::get_node(NodeManager* rel_mng, const AbstractNode* node_ptr){
    if(rel_mng->nodes_.contains(node_ptr)){
        return *rel_mng->nodes_.find(node_ptr);
    }
}

AbstractNode* NodeManager::insert_back_ref(const ReferenceNode* node,AbstractNode* new_child){
    if(node && new_child){
        assert(node->type()==NODE_TYPE::REF);
        if(node->has_child(0))
            node->relation_manager()->childs_.at(node).clear();
        return node->relation_manager()->childs_[node].emplace_back(new_child);
    }
    else
        return nullptr;
}
AbstractNode* NodeManager::insert_back(const AbstractNode* node,std::unique_ptr<AbstractNode>&& new_child){
    if(node){
        node->flush_cache();
        AbstractNode* return_ptr = nullptr;
        switch (node->type())
        {
            case NODE_TYPE::ARRAY:{
                return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                break;
            }
            case NODE_TYPE::VARIABLE:
            case NODE_TYPE::RANGEOP:{
                if(node->has_childs())
                    node->child(0)->relation_manager()->nodes_.erase(node->child(0)->relation_manager()->nodes_.find(node->child(0)));
                return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                break;
            }
            case NODE_TYPE::REF:{
                throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
            }
            
            case NODE_TYPE::UNARY:{
                assert(node->relation_manager()->childs_[node].size()<1);
                return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                break;
            }
            case NODE_TYPE::BINARY:{
                assert(node->relation_manager()->childs_[node].size()<2);
                return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                break;
            }
            case NODE_TYPE::FUNCTION:{
                if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity())
                    return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
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
        }
        assert(!node->childs().empty());
        __add_owner__(new_child.get(),node, node->childs().size()-1);
        assert(!node->relation_manager()->nodes_.contains(new_child));
        new_child->set_relation_manager(node->relation_manager());
        node->relation_manager()->nodes_.insert(std::move(new_child));
        return return_ptr;
    }
    else
        return nullptr;
}

//insert before value at id
AbstractNode* NodeManager::insert(const AbstractNode* node,size_t id,std::unique_ptr<AbstractNode>&& new_child){
    if(node){
        assert(id<=node->relation_manager()->childs_[node].size());
        node->flush_cache();
        switch (node->type())
        {
            case NODE_TYPE::ARRAY:{
                node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::VARIABLE:
                assert(node->relation_manager()->bd_);
            case NODE_TYPE::REF:
            case NODE_TYPE::RANGEOP:{
                if(has_child(node,0))
                    node->relation_manager()->childs_.at(node).at(0)=new_child.get();
                else node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::UNARY:{
                assert(id<1);
                assert(node->relation_manager()->childs_[node].size()<1);
                node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::BINARY:{
                assert(id<2);
                assert(node->relation_manager()->childs_[node].size()<2);
                node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                break;
            }
            case NODE_TYPE::FUNCTION:{
                node->flush_cache();
                if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity())
                    node->relation_manager()->childs_[node].emplace(node->relation_manager()->childs_[node].cbegin()+id,new_child.get());
                else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
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
        __add_owner__(node->child(id),node, id);
    }
}
AbstractNode* NodeManager::replace(const AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child){
    switch (node->type())
    {
        case NODE_TYPE::ARRAY:{
            swap_childs(new_child.get(),node);
            __add_owner__(new_child.get(),node, id);
            break;
        }
        case NODE_TYPE::RANGEOP:/*{
            if(has_child(node,0))
                childs_.at(node).at(0)=new_child;
            else childs_.at(node).push_back(new_child);
            __add_reference__(new_child.get(),node, childs_.at(node).size()-1);
            break;
        }*/
        case NODE_TYPE::UNARY:
        case NODE_TYPE::BINARY:
        case NODE_TYPE::FUNCTION:
        case NODE_TYPE::VARIABLE:
        case NODE_TYPE::REF:
        case NODE_TYPE::VALUE:
        case NODE_TYPE::STRING:
        case NODE_TYPE::UNDEF:
        case NODE_TYPE::CUSTOM:
            //will be added further at next version with lambda functions
            throw std::logic_error("Invalid replacing. Prompt: Unvalailable to replace child to this type of node");
            break;
        default:
            break;
    }
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
    assert(owner->child(index)==node_to_add);
}

void NodeManager::__add_reference__(const AbstractNode* node_to_add, ReferenceNode* ref_node, int index) noexcept{
    //variable type cannot has owner (only BaseData class object)
    assert(node_to_add);
    assert(ref_node);
    node_to_add->relation_manager()->references_[node_to_add].insert(ref_node);
}
bool NodeManager::has_references(const AbstractNode* node) noexcept{
    return node->relation_manager()->references_.contains(node);
}
bool NodeManager::has_owner(const AbstractNode* node) noexcept{
    return node->relation_manager()->owner_.contains(node) && node->relation_manager()->owner_.at(node).has_node();
}
void NodeManager::refresh_parent_links(const AbstractNode* node) noexcept{
    //TODO
    // if(type()==NODE_TYPE::VARIABLE){
    //     for(const auto&[parent,ids]:references())
    //         if(!parent || parent->type()==NODE_TYPE::UNDEF)
    //             rel_mng_->erase_parent(this,parent);
    // }
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
                    node->relation_manager()->childs_.at(node).at(i)
                );
                assert(found!=node->relation_manager()->childs_.at(node).at(i)->relation_manager()->nodes_.end());
                node->relation_manager()->childs_.at(node).at(i)->relation_manager()->nodes_.erase(found);
            }
        }
        node->relation_manager()->childs_.erase(node);
    }
}
const References_t& NodeManager::references(const AbstractNode* node) noexcept{
    if(node->relation_manager()->references_.contains(node))
        return node->relation_manager()->references_.at(node);
    else return NodeManager::empty_references_;
}
void NodeManager::erase_child(const AbstractNode* node, size_t id) noexcept{
    if(node->has_child(id)) //TODO: check if it is reference or owned node (then must be deleted)
        node->relation_manager()->childs_.at(node).erase(node->relation_manager()->childs_.at(node).cbegin()+id);
}
#include <cassert>
void NodeManager::delete_node(const AbstractNode* node){
    //++node->relation_manager()->destructed;
    for(auto& ref:node->relation_manager()->references_[node])
        erase_child(ref,0);
    node->relation_manager()->references_.erase(node);
    release_childs(node);
    node->relation_manager()->owner_.erase(node);
}
#include "arithmetic_types.h"

void NodeManager::swap_childs(const AbstractNode* lhs, const AbstractNode* rhs){
    if(lhs && rhs){
        std::function<void(const AbstractNode*, const AbstractNode*)> swap_child = [](const AbstractNode* child, const AbstractNode* owner){
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
            }
        };
        if(lhs->has_childs() && rhs->has_childs()){
            std::swap(lhs->relation_manager()->childs_.at(lhs),
                rhs->relation_manager()->childs_.at(rhs));
            for(size_t i = 0;i<lhs->relation_manager()->childs_.at(lhs).size();++i)
                swap_child(lhs->relation_manager()->childs_.at(lhs).at(i),lhs);
            for(size_t i = 0;i<rhs->relation_manager()->childs_.at(rhs).size();++i)
                swap_child(rhs->relation_manager()->childs_.at(rhs).at(i),rhs);
        }
        else if(lhs->has_childs()){
            rhs->relation_manager()->childs_[rhs].swap(lhs->relation_manager()->childs_.at(lhs));
            lhs->relation_manager()->childs_.erase(lhs);
            for(size_t i = 0;i<rhs->relation_manager()->childs_.at(rhs).size();++i)
                swap_child(rhs->relation_manager()->childs_.at(rhs).at(i),rhs);
        }
        else if(rhs->has_childs()){
            lhs->relation_manager()->childs_[lhs].swap(rhs->relation_manager()->childs_.at(rhs));
            rhs->relation_manager()->childs_.erase(rhs);
            for(size_t i = 0;i<lhs->relation_manager()->childs_.at(lhs).size();++i)
                swap_child(lhs->relation_manager()->childs_.at(lhs).at(i),lhs);
        }
        else{}

    }
}
void NodeManager::copy_childs(AbstractNode* node, const Childs_t& childs){
    release_childs(node);
    for(const AbstractNode* child:childs){
        switch(child->type()){
            case NODE_TYPE::ARRAY:{
                node->insert_back(node->relation_manager()->bd_->make_node<ArrayNode>(*static_cast<const ArrayNode*>(child))); //need to check
                break;
            }
            case NODE_TYPE::BINARY :{
                node->insert_back(node->relation_manager()->bd_->make_node<BinaryNode>(*static_cast<const BinaryNode*>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::RANGEOP :{
                node->insert_back(node->relation_manager()->bd_->make_node<RangeOperationNode>(*static_cast<const RangeOperationNode*>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::FUNCTION :{
                node->insert_back(node->relation_manager()->bd_->make_node<FunctionNode>(*static_cast<const FunctionNode*>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::STRING :{
                node->insert_back(node->relation_manager()->bd_->make_node<StringNode>(*static_cast<const StringNode*>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::UNARY :{
                node->insert_back(node->relation_manager()->bd_->make_node<UnaryNode>(*static_cast<const UnaryNode*>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::VALUE :{
                node->insert_back(node->relation_manager()->bd_->make_node<ValueNode>(*static_cast<const ValueNode*>(child))); //need to check
                break;
            }
            case NODE_TYPE::REF:{
                node->insert_back(node->relation_manager()->bd_->make_node<ReferenceNode>(*static_cast<const ReferenceNode*>(child))); //need to check
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
                node->insert_back(std::make_unique<EmptyNode>()); //need to check
                break;
            }
        }
    }
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