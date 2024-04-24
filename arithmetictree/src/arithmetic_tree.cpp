#include "arithmetic_tree.h"
#include "arithmetic_types.h"

ArithmeticTree::ArithmeticTree(const ArithmeticTree& other){
    if(this!=&other){
        *this = other;
    }
}

ArithmeticTree::ArithmeticTree(ArithmeticTree&& other) noexcept{
    if(this!=&other){
        this->root_ = std::move(other.root_);
        this->cache_ = std::move(other.cache_);
        this->last_incomplete_ = other.last_incomplete_;
    }
}

ArithmeticTree& ArithmeticTree::operator=(const ArithmeticTree& other){
    if(this!=&other){
        this->root_ = other.root_;
        this->cache_=other.cache_;
        last_incomplete_ = other.last_incomplete_;
    }
    return *this;
}

ArithmeticTree& ArithmeticTree::operator=(ArithmeticTree&& other) noexcept{
    if(this!=&other){
        this->root_ = std::move(other.root_);
        this->cache_=std::move(other.cache_);
        last_incomplete_ = other.last_incomplete_;
    }
    return *this;
}

const Value_t& ArithmeticTree::value() const{
    if(!cache_.has_value())
        cache_.emplace(execute());
    return cache_.value();
}

Value_t ArithmeticTree::execute() const{
    if(root_)
        return root_->execute();
    else return 0.;
}

void ArithmeticTree::insert(const std::shared_ptr<Node>& node){
    if(!root_){
        root_=node;
        return;
    }
    if(!is_ready()){
        if(last_incomplete_->type()==ARITHM_NODE_TYPE::UNARY)
            reinterpret_cast<UnaryNode*>(last_incomplete_)->child() = node;
        else if(last_incomplete_->type()==ARITHM_NODE_TYPE::BINARY){
            BinaryNode* ptr = reinterpret_cast<BinaryNode*>(last_incomplete_);
            if(!ptr->lhs()){
                ptr->lhs() = node;
            }
            else ptr->rhs() = node;
        }
        node->parent()=last_incomplete_;
    }
    else{
        if(node->type()==ARITHM_NODE_TYPE::UNARY){
            root_->parent() = node.get();
            reinterpret_cast<UnaryNode*>(node.get())->child() = std::shared_ptr<Node>(root_);
            root_ = std::shared_ptr<Node>(node);
        }
        else if(node->type()==ARITHM_NODE_TYPE::BINARY){
            root_->parent() = node.get();
            BinaryNode* ptr = reinterpret_cast<BinaryNode*>(node.get());
            ptr->lhs() = root_;
            root_ = std::shared_ptr<Node>(ptr);
        }
        else throw std::invalid_argument("Error function definition");
    }
    last_incomplete_=nullptr;
}

bool ArithmeticTree::is_ready() const{
    if(!last_incomplete_)
        last_incomplete_ = root_->first_undefined_child_node();
    if(last_incomplete_==nullptr)
        return true;
    else
        return false;
}

const std::shared_ptr<Node>& ArithmeticTree::root() const{
    return root_;
}