#include "relation_manager.h"
#include "core/settings.h"
#include "node.h"

const std::vector<std::shared_ptr<Node>> RelationManager::empty_childs_{};

void RelationManager::reserve_childs(const Node* node,size_t size){
    childs_[node].reserve(size);
}

const std::shared_ptr<Node>& RelationManager::child(const Node* node,size_t id) const{
    if(childs_.contains(node) && id<childs_.at(node).size())
        return childs_.at(node).at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}
std::shared_ptr<Node>& RelationManager::child(Node* node,size_t id){
    return childs_.at(node).at(id);
}
INFO_NODE RelationManager::child(Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) noexcept{
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
INFO_NODE RelationManager::child(const Node* node,const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) const noexcept{
    if(node)
        return node->child(first,last);
    else return INFO_NODE();
}
void RelationManager::insert_back(const Node* node,std::shared_ptr<Node> new_child){
    switch (node->type())
    {
    case NODE_TYPE::UNDEF:
        throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert back child to this type of node");
        break;
    case NODE_TYPE::ARRAY:{
        childs_[node].push_back(new_child);
        add_parent(new_child.get(),node, childs_.at(node).size()-1);
        break;
    }
    default:
        break;
    }
}

/*std::shared_ptr<Node> ArrayNode::insert(size_t id,std::shared_ptr<Node> node){
    if(node){
        flush_cache();
        if(type_val_.has_value() && !(type_val_.value()&node->type_val()))
            __invalidate_type_val__();
        else
            type_val_.emplace(node->type_val() | TYPE_VAL::ARRAY);
        if(!(id<childs().size()))
            rel_mng_->childs(this).resize(id+1);
        rel_mng_->childs(this).insert(childs().begin()+id,node);
        rel_mng_->add_parent(childs()[id].get(),this, id);
        return node;
    }
    else return std::make_shared<Node>();
}

std::shared_ptr<Node> ArrayNode::replace(size_t id,std::shared_ptr<Node> node){
    if(node){
        flush_cache();
        if(type_val_.has_value() && !(type_val_.value()&node->type_val()))
            __invalidate_type_val__();
        else
            type_val_.emplace(node->type_val() | TYPE_VAL::ARRAY);
        if(!(id<childs().size()))
            rel_mng_->childs(this).resize(id+1);
        rel_mng_->childs(this)[id].swap(node);
        rel_mng_->add_parent(childs()[id].get(),this,id);
        return node;
    }
    else return std::make_shared<Node>();
}*/

//insert before value at id
std::shared_ptr<Node> RelationManager::insert(const Node* node,size_t id,std::shared_ptr<Node> new_child) noexcept{
    if(!(id<childs(node).size()))
        childs_.at(node).resize(id+1);
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert child to this type of node");
}
std::shared_ptr<Node> RelationManager::replace(const Node* node, size_t id,std::shared_ptr<Node> new_child) noexcept{
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to replace child to this type of node");
}
bool RelationManager::__add_parent__(const Node* node_to_add, const Node* parent, int index) noexcept{
    //variable type cannot has owner (only BaseData class object)
    assert(node_to_add);
    if(!owner(node_to_add).parent && node_to_add->type()!=NODE_TYPE::VARIABLE){
        INFO_NODE info;
        info.parent = const_cast<Node*>(parent);
        info.id = index;
        owner_[node_to_add] = info;
        references_[node_to_add][parent].push_back(index);
        return true;
    }
    else return false;
}
bool RelationManager::__add_reference__(const Node* node_to_add, const ReferenceNode* parent, int index) noexcept{
    assert(node_to_add);
    references_[node_to_add][parent].push_back(index);
}
bool RelationManager::has_parents(const Node* node) const noexcept{
    references_.contains(node);
}
bool RelationManager::has_owner(const Node* node) const noexcept{
    ow
}
void RelationManager::refresh_parent_links(Node* node) noexcept{

}
std::set<std::shared_ptr<VariableNode>> RelationManager::refer_to_vars(const Node* node) const noexcept{

}
std::set<std::shared_ptr<Node>> RelationManager::refer_to_node_of_type(const Node* node, NODE_TYPE type) const noexcept{

}
bool RelationManager::has_childs(const Node* node) const noexcept{
    return !childs_.empty();
}
bool RelationManager::has_child(const Node* node, size_t id) const noexcept{
    return childs_.size()>id;
}
void RelationManager::release_childs(Node* node) noexcept{
    for(std::shared_ptr<Node>& child:childs_.at(node))
        if(child){
            erase_parent(child.get(),node);
            INFO_NODE child_infonode = owner(child.get());
            if(child_infonode.parent == node)
                owners_.erase(child.get());
        }
    childs_.at(node).clear();
}
const Parents_t& RelationManager::parents(const Node* node) const noexcept{
    //maybe empty
}

void RelationManager::erase_parent(const Node* node, const Node* parent){
    references_.at(node).erase(parent);
    INFO_NODE info = owner(node);
    if(info.parent == parent && info.has_node())
        info.parent->erase_child(info.id);
}
void RelationManager::erase_child(const Node* node, size_t id){
    if(childs_.contains(node)){
        if(childs_.at(node).size()>id)
            childs_.at(node).erase(childs_.at(node).begin()+id);
        else throw std::invalid_argument("Invalid id at deletion");
    }
    else throw std::invalid_argument("Node doesn't exists");
}

void RelationManager::delete_node(const Node* node){
    owners_.erase(node);
    //release also childs with deletion but without make_shared
    if(references_.contains(node)){
        for(auto& [reference,ids]:references_.at(node))
            for(int id:ids)
                reference->relation_manager()->erase_child(reference,id);
        references_.erase(node);
    }
}

#include "arithmetic_types.h"

// void RelationManager::swap_parents(const Node* lhs, const Node* rhs){
//     if(references_.contains(lhs))
//         if(references_.contains(rhs))
//             references_.at(lhs).swap(references_.at(rhs));
//         else{
//             references_.at(lhs).swap(references_[rhs]);
//             references_.erase(lhs);
//             //erase owner also
//         }
//     else{
//         if(references_.contains(rhs))
//     }
// }
void RelationManager::swap_childs(const Node* lhs, const Node* rhs){
    if(lhs->relation_manager()->childs_.contains(lhs))
        if(rhs->relation_manager()->childs_.contains(rhs)){
            // for(auto child:lhs->relation_manager()->childs_.at(lhs))
            //     lhs->relation_manager()->owners_.at()
            lhs->relation_manager()->childs_.at(lhs).swap(childs_.at(rhs));
        }
        else{
            childs_.at(lhs).swap(childs_[rhs]);
            references_.erase(lhs);
            //erase owner also
        }
    else{
        //if(references_.contains(rhs))
    }
}
// void RelationManager::copy_parents(const Node* node, const Parents_t& parents){
//     if(node && )

// }

#include "string_node.h"
void RelationManager::copy_childs(Node* node, const Childs_t& childs){
    for(const std::shared_ptr<Node>& child:childs){
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
                node->insert_back(std::make_shared<Node>()); //need to check
                break;
            }
        }
        add_parent(this->childs(node).back().get(),node,this->childs(node).size()-1);
    }
}