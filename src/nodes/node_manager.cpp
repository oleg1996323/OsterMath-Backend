#include "node_manager.h"
#include "core/settings.h"
#include "data.h"

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
            if(info.parent->type()==NODE_TYPE::VARIABLE || info.parent->type()==NODE_TYPE::REF){
                while (info.parent->type()==NODE_TYPE::VARIABLE || info.parent->type()==NODE_TYPE::REF){
                    if(info.parent->type()==NODE_TYPE::REF)
                        assert(info.parent->has_child(0));
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
                }
                else return INFO_NODE();
            }
            assert(info.has_node());
        }
        //ignoring the variables sequence. TODO: check cyclic references
        while(info.has_node() && 
        info.node()->type()==NODE_TYPE::REF && 
        static_cast<ReferenceNode*>(info.node())->child(0)->type()==NODE_TYPE::VARIABLE){
            info.parent = static_cast<VariableNode*>(static_cast<ReferenceNode*>(info.node())->child(0));
            info.id = 0;
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
    static std::unique_ptr<AbstractNode> empty;
    return empty;
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
    AbstractNode* tmp = at_insert_back->insert_back<EmptyNode>();
    move_node(tmp,inserted);
    return inserted;
}
AbstractNode* NodeManager::insert_back_copy(AbstractNode* at_insert_back, AbstractNode* inserted){
    AbstractNode* tmp = at_insert_back->insert_back<EmptyNode>();
    copy_node(tmp,inserted);
    return inserted;
}
#include "func_node.h"
AbstractNode* NodeManager::insert_back(AbstractNode* node,std::unique_ptr<AbstractNode>&& new_child){
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
                if(node->has_childs()){
                    if(node->child(0)!=new_child.get())
                        erase_child(node,0);
                    else break;
                }
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
                if(!static_cast<FunctionNode*>(node)->is_array_function())
                    if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity()){
                        return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
                        break;
                    }
                    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
                else return_ptr = node->relation_manager()->childs_[node].emplace_back(new_child.get());
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
AbstractNode* NodeManager::insert(AbstractNode* node,size_t id,std::unique_ptr<AbstractNode>&& new_child){
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
//TODO
AbstractNode* NodeManager::replace(AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child){
    switch (node->type())
    {
        case NODE_TYPE::ARRAY:{
            swap_node(new_child.get(),node);
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
void NodeManager::move_node(AbstractNode* at_move, AbstractNode* to_move){
    assert(to_move->type()!=NODE_TYPE::VARIABLE && at_move->type()!=NODE_TYPE::VARIABLE);
    if(at_move && to_move && at_move!=to_move){
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
        
        typename decltype(nodes_)::node_type at_move_node = std::move(at_move->relation_manager()->nodes_.extract(at_move->relation_manager()->nodes_.find(at_move)));
        //swap node unique ptrs
        if(at_move->relation_manager()!=to_move->relation_manager())
            at_move->relation_manager()->nodes_.insert(std::move(to_move->relation_manager()->nodes_.extract(to_move->relation_manager()->nodes_.find(to_move))));

        //swap references
        if(at_move->relation_manager()->references_.contains(at_move)){
            for(const ReferenceNode* ref:at_move->relation_manager()->references_.at(at_move))
                ref->relation_manager()->childs_.at(ref).at(0)=to_move;
            at_move->relation_manager()->references_[to_move].swap(at_move->relation_manager()->references_.at(at_move));
            at_move->relation_manager()->references_.erase(at_move);
        }
        if(to_move->relation_manager()->references_.contains(to_move)){
            AbstractNode* empty_node = add_node(to_move->relation_manager(),std::make_unique<EmptyNode>());
            for(const ReferenceNode* ref:to_move->relation_manager()->references_.at(to_move))
                ref->relation_manager()->childs_.at(ref).at(0)=empty_node;
            to_move->relation_manager()->references_[empty_node].swap(to_move->relation_manager()->references_.at(to_move));
            to_move->relation_manager()->references_.erase(to_move);
        }

        //swap childs
        NodeManager::release_childs(at_move);
        if(to_move->has_childs()){
            if(at_move->relation_manager()!=to_move->relation_manager())
                std::swap(at_move->relation_manager()->childs_[to_move],
                    to_move->relation_manager()->childs_.at(to_move));
            for(size_t i = 0;i<to_move->relation_manager()->childs_.at(to_move).size();++i)
                update_child(to_move->relation_manager()->childs_.at(to_move).at(i),to_move);
        }

        //swap owners
        at_move->relation_manager()->childs_.at(at_move->owner().parent).at(at_move->owner().id)=to_move;
        at_move->relation_manager()->owner_.at(at_move).parent = to_move->relation_manager()->owner_.at(to_move).parent;

        at_move->set_relation_manager(to_move->relation_manager());
    }
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