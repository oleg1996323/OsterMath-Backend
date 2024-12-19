#include "node_manager.h"
#include "core/settings.h"
#include "node.h"
#include "data.h"

const Childs_t RelationManager::empty_childs_{};
const References_t RelationManager::empty_references_{};

RelationManager::~RelationManager(){
}

void RelationManager::reserve_childs(const AbstractNode* node,size_t size){
    node->relation_manager()->childs_[node].reserve(size);
}

const std::shared_ptr<AbstractNode>& RelationManager::child(const AbstractNode* node,size_t id){
    if(node->relation_manager()->childs_.contains(node) && id<node->relation_manager()->childs_.at(node).size())
        return node->relation_manager()->childs_.at(node).at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}
std::shared_ptr<AbstractNode>& RelationManager::child(AbstractNode* node,size_t id){
    return node->relation_manager()->childs_.at(node).at(id);
}
//get the node which is not intermediate (ValueNode, StringNode, RangeNode, FunctionNode, VariableNode, ArrayNode)
INFO_NODE RelationManager::child(AbstractNode* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept{
    if(node->type()==NODE_TYPE::VARIABLE || node->type()==NODE_TYPE::ARRAY){ //only valuable node
        INFO_NODE info{node,*first};
        std::vector<int>::const_iterator iter;
        for(iter=first;iter<last;++iter){
            if(info.parent->type()==NODE_TYPE::VARIABLE){
                while (info.parent->type()==NODE_TYPE::VARIABLE)
                    if(info.parent->has_child(0)){
                        info.parent = info.parent->child(0).get();
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
                    info.parent = info.node().get();
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
                    info.parent = info.node().get();
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

void RelationManager::insert_back(const AbstractNode* node,std::shared_ptr<AbstractNode> new_child){
    if(node){
        node->flush_cache();
        switch (node->type())
        {
            case NODE_TYPE::ARRAY:{
                node->relation_manager()->childs_[node].push_back(new_child);
                break;
            }
            case NODE_TYPE::VARIABLE:
                assert(node->relation_manager()->bd_);
            case NODE_TYPE::REF:
            case NODE_TYPE::RANGEOP:{
                if(node->has_child(0))
                    node->relation_manager()->childs_.at(node).clear();
                node->relation_manager()->childs_[node].push_back(new_child);
                break;
            }
            case NODE_TYPE::UNARY:{
                assert(node->relation_manager()->childs_[node].size()<1);
                node->relation_manager()->childs_[node].push_back(new_child);
                break;
            }
            case NODE_TYPE::BINARY:{
                assert(node->relation_manager()->childs_[node].size()<2);
                node->relation_manager()->childs_[node].push_back(new_child);
                break;
            }
            case NODE_TYPE::FUNCTION:{
                node->flush_cache();
                if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity())
                    node->relation_manager()->childs_[node].push_back(new_child);
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
        assert(!node->childs().empty());
        __add_reference__(node->childs().at(node->childs().size()-1).get(),node, node->childs().size()-1);
    }
}

//insert before value at id
std::shared_ptr<AbstractNode> RelationManager::insert(const AbstractNode* node,size_t id,std::shared_ptr<AbstractNode> new_child){
    if(node){
        assert(id<=node->relation_manager()->childs_[node].size());
        node->flush_cache();
        switch (node->type())
        {
            case NODE_TYPE::ARRAY:{
                node->relation_manager()->childs_[node].insert(node->relation_manager()->childs_[node].cbegin()+id,new_child);
                break;
            }
            case NODE_TYPE::VARIABLE:
                assert(node->relation_manager()->bd_);
            case NODE_TYPE::REF:
            case NODE_TYPE::RANGEOP:{
                if(has_child(node,0))
                    node->relation_manager()->childs_.at(node).at(0)=new_child;
                else node->relation_manager()->childs_[node].insert(node->relation_manager()->childs_[node].cbegin()+id,new_child);
                break;
            }
            case NODE_TYPE::UNARY:{
                assert(id<1);
                assert(node->relation_manager()->childs_[node].size()<1);
                node->relation_manager()->childs_[node].insert(node->relation_manager()->childs_[node].cbegin()+id,new_child);
                break;
            }
            case NODE_TYPE::BINARY:{
                assert(id<2);
                assert(node->relation_manager()->childs_[node].size()<2);
                node->relation_manager()->childs_[node].insert(node->relation_manager()->childs_[node].cbegin()+id,new_child);
                break;
            }
            case NODE_TYPE::FUNCTION:{
                node->flush_cache();
                if(node->relation_manager()->childs_[node].size()<node->relation_manager()->childs_[node].capacity())
                    node->relation_manager()->childs_[node].insert(node->relation_manager()->childs_[node].cbegin()+id,new_child);
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
        __add_reference__(node->relation_manager()->childs_.at(node)[id].get(),node, id);
    }
}
std::shared_ptr<AbstractNode> RelationManager::replace(const AbstractNode* node, size_t id,std::shared_ptr<AbstractNode> new_child){
    switch (node->type())
    {
        case NODE_TYPE::ARRAY:{
            swap_childs(new_child.get(),node);
            __add_reference__(new_child.get(),node, id);
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
void RelationManager::__add_reference__(AbstractNode* node_to_add, const AbstractNode* parent, int index) noexcept{
    //variable type cannot has owner (only BaseData class object)
    assert(node_to_add);
    if(parent->type()!=NODE_TYPE::REF){
        if(node_to_add->type()!=NODE_TYPE::VARIABLE && !owner(node_to_add).has_node()){
                ++node_to_add->relation_manager()->constructed;
                INFO_NODE info;
                info.parent = const_cast<AbstractNode*>(parent);
                info.id = index;
                node_to_add->relation_manager()->owner_[node_to_add] = info;
        }
        else{
            ++node_to_add->relation_manager()->refered;
            std::shared_ptr<AbstractNode> tmp = parent->childs().at(index);
            std::shared_ptr<ReferenceNode> ref_node = std::make_shared<ReferenceNode>(tmp);
            parent->relation_manager()->childs_.at(parent).at(index)=ref_node;
            {
                ++node_to_add->relation_manager()->constructed;
                INFO_NODE info;
                info.parent = const_cast<AbstractNode*>(parent);
                info.id = index;
                ref_node->relation_manager()->owner_[ref_node.get()] = info;
            }
            //delete ex-reference to the child, if it was deleted
            assert(tmp->references().contains(ref_node.get()));
            assert(ref_node->owner()==parent);
            assert(ref_node.get()==parent->childs().at(index).get());
        }
    }
    else{
        node_to_add->relation_manager()->references_[node_to_add].insert(static_cast<const ReferenceNode*>(parent));
    }
}
bool RelationManager::has_references(const AbstractNode* node) noexcept{
    return node->relation_manager()->references_.contains(node);
}
bool RelationManager::has_owner(const AbstractNode* node) noexcept{
    return node->relation_manager()->owner_.contains(node) && node->relation_manager()->owner_.at(node).has_node();
}
void RelationManager::refresh_parent_links(const AbstractNode* node) noexcept{
    //TODO
    // if(type()==NODE_TYPE::VARIABLE){
    //     for(const auto&[parent,ids]:references())
    //         if(!parent || parent->type()==NODE_TYPE::UNDEF)
    //             rel_mng_->erase_parent(this,parent);
    // }
}
std::set<std::shared_ptr<VariableNode>> RelationManager::refer_to_vars(const AbstractNode* node) noexcept{
    std::set<std::shared_ptr<VariableNode>> vars_;
    for(const std::shared_ptr<AbstractNode>& child:node->childs()){
        if(child->type()==NODE_TYPE::VARIABLE)
            vars_.insert(std::dynamic_pointer_cast<VariableNode>(child));
        else
            vars_.merge(child->refer_to_vars());
    }
    return vars_;
}
std::set<std::shared_ptr<AbstractNode>> RelationManager::refer_to_node_of_type(const AbstractNode* node, NODE_TYPE type) noexcept{
    std::set<std::shared_ptr<AbstractNode>> nodes_;
    for(const std::shared_ptr<AbstractNode>& child:childs(node)){
        if(child->type()==type)
            nodes_.insert(child);
        else
            nodes_.merge(child->refer_to_node_of_type(type));
    }
    return nodes_;
}
bool RelationManager::has_childs(const AbstractNode* node) noexcept{
    return node->relation_manager()->childs_.contains(node) &&
        !node->relation_manager()->childs_.at(node).empty();
}
bool RelationManager::has_child(const AbstractNode* node, size_t id) noexcept{
    if(node->childs().size()>id)
        return true;
    return false;
    return node->relation_manager()->childs_.contains(node) && node->relation_manager()->childs_.at(node).size()>id;
}
void RelationManager::release_childs(const AbstractNode* node) noexcept{
    // for(std::shared_ptr child:childs(node)){
    //     if(child->owner()==node || child->owner()==nullptr)
    //         child->relation_manager()->release_childs(child.get());
    //     else{
    //         if(!child->references().empty()){
    //             assert(node->type()==NODE_TYPE::REF);
    //             node->relation_manager()->childs_.erase(node);
    //             child->relation_manager()->references_.at(child.get()).erase(static_cast<const ReferenceNode*>(node));
    //         }
    //         //maybe replace child (delete or make EmptyNode()?)
    //     }
    // }
    if(node->has_childs())
        node->relation_manager()->childs_.erase(node);
}
const References_t& RelationManager::references(const AbstractNode* node) noexcept{
    if(node->relation_manager()->references_.contains(node))
        return node->relation_manager()->references_.at(node);
    else return RelationManager::empty_references_;
}
void RelationManager::erase_child(const AbstractNode* node, size_t id) noexcept{
    if(node->has_child(id)) //TODO: check if it is reference or owned node (then must be deleted)
        node->relation_manager()->childs_.at(node).erase(node->relation_manager()->childs_.at(node).cbegin()+id);
}
#include <cassert>
void RelationManager::delete_node(const AbstractNode* node){
    ++node->relation_manager()->destructed;
    release_childs(node);
    for(auto& ref:node->relation_manager()->references_[node])
        erase_child(ref,0);
    node->relation_manager()->references_.erase(node);
    INFO_NODE owner_tmp = owner(node);
    node->relation_manager()->owner_.erase(node);
    if(owner_tmp.has_node())
        erase_child(owner_tmp.parent,owner_tmp.id);
}
#include "arithmetic_types.h"

void RelationManager::swap_childs(const AbstractNode* lhs, const AbstractNode* rhs){
    if(lhs && rhs){
        assert(lhs->type()!=NODE_TYPE::VARIABLE && rhs->type()!=NODE_TYPE::VARIABLE);
        assert(lhs->has_owner());
        assert(rhs->has_owner());
        owner(lhs).parent->child(owner(lhs).id).swap(owner(rhs).parent->child(owner(rhs).id));
        INFO_NODE owner_lhs = owner(lhs);
        if(rhs->has_owner())
            lhs->relation_manager()->owner_[lhs] = owner(rhs);
        else lhs->relation_manager()->owner_.erase(lhs);
        if(owner_lhs.has_node())
            rhs->relation_manager()->owner_[rhs] = owner_lhs;
        else rhs->relation_manager()->owner_.erase(rhs);

        if(lhs->relation_manager()->references_.contains(lhs) && rhs->relation_manager()->references_.contains(rhs))
            lhs->relation_manager()->references_.at(lhs).swap(rhs->relation_manager()->references_.at(rhs));
        else if(lhs->relation_manager()->references_.contains(lhs)){
            rhs->relation_manager()->references_[rhs].swap(lhs->relation_manager()->references_.at(lhs));
            lhs->relation_manager()->references_.erase(lhs);
        }
        else if(rhs->relation_manager()->references_.contains(rhs)){
            lhs->relation_manager()->references_[lhs].swap(rhs->relation_manager()->references_.at(rhs));
            rhs->relation_manager()->references_.erase(rhs);
        }
        else{
            rhs->relation_manager()->references_.erase(rhs);
            lhs->relation_manager()->references_.erase(lhs);
        }
    }
}
void RelationManager::copy_childs(AbstractNode* node, const Childs_t& childs){
    for(const std::shared_ptr<AbstractNode>& child:childs){
        switch(child->type()){
            case NODE_TYPE::ARRAY:{
                node->insert_back(std::make_shared<ArrayNode>(*std::dynamic_pointer_cast<ArrayNode>(child))); //need to check
                break;
            }
            case NODE_TYPE::BINARY :{
                node->insert_back(std::make_shared<BinaryNode>(*std::dynamic_pointer_cast<BinaryNode>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::RANGEOP :{
                node->insert_back(std::make_shared<RangeOperationNode>(*std::dynamic_pointer_cast<RangeOperationNode>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::FUNCTION :{
                node->insert_back(std::make_shared<FunctionNode>(*std::dynamic_pointer_cast<FunctionNode>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::STRING :{
                node->insert_back(std::make_shared<StringNode>(*std::dynamic_pointer_cast<StringNode>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::UNARY :{
                node->insert_back(std::make_shared<UnaryNode>(*std::dynamic_pointer_cast<UnaryNode>(child))); //need to check
                break;                        
            }
            case NODE_TYPE::VALUE :{
                node->insert_back(std::make_shared<ValueNode>(*std::dynamic_pointer_cast<ValueNode>(child))); //need to check
                break;
            }
            case NODE_TYPE::REF:{
                node->insert_back(std::make_shared<ReferenceNode>(*std::dynamic_pointer_cast<ReferenceNode>(child))); //need to check
                break;
            }
            case NODE_TYPE::CUSTOM :{
                //TODO: integrate further
                assert(true);
                break;
            }
            case NODE_TYPE::VARIABLE:{
                node->insert_back(child);
                break;
            }
            default:{
                node->insert_back(std::make_shared<EmptyNode>()); //need to check
                break;
            }
        }
    }
}