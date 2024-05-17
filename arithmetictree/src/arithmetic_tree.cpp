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

const Value_t& ranges::ArithmeticTree::value(size_t index) const{
    if(!cache_.has_value())
        cache_.emplace(execute(index));
    return cache_.value();
}

Value_t ArithmeticTree::execute() const{
    if(root_)
        return root_->execute();
    else return 0.;
}

#ifdef DEBUG
void ArithmeticTree::print() const{
    root_->print();
}
#endif

void ArithmeticTree::insert(const std::shared_ptr<Node>& node){
    if(node->type() == ARITHM_NODE_TYPE::VARIABLE)
        var_dependence_.insert(reinterpret_cast<VariableNode*>(node.get())->variable()->name());

    if(!root_){
        std::cout<<"Add to root: ";

#ifdef DEBUG
        node->print();
#endif
        root_=node;
        last_incomplete_=root_.get();
        return;
    }
    if(!is_ready()){
        if(last_incomplete_->type()==ARITHM_NODE_TYPE::UNARY){
            std::cout<<"Add to unary: ";
#ifdef DEBUG
            node->print();
#endif
            reinterpret_cast<UnaryNode*>(last_incomplete_)->child() = node;
        }
        else if(last_incomplete_->type()==ARITHM_NODE_TYPE::BINARY){
            BinaryNode* ptr = reinterpret_cast<BinaryNode*>(last_incomplete_);
            if(!ptr->lhs()){
                std::cout<<"Add to binary left: ";
#ifdef DEBUG
                node->print();
#endif
                ptr->lhs() = node;
            }
            else {
                std::cout<<"Add to binary right: ";
#ifdef DEBUG
                node->print();
#endif
                ptr->rhs() = node;
            }
        }
        node->add_parent(last_incomplete_);
    }
    else{
        if(node->type()==ARITHM_NODE_TYPE::UNARY){
            root_->add_parent(node.get());
            reinterpret_cast<UnaryNode*>(node.get())->child()=root_;
            root_=node;
        }
        else if(node->type()==ARITHM_NODE_TYPE::BINARY){
            root_->add_parent(node.get());
            const std::shared_ptr<BinaryNode>& ptr = reinterpret_cast<const std::shared_ptr<BinaryNode>&>(node);
            ptr->lhs() = root_;
            root_=node;
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

Value_t ranges::ArithmeticTree::execute(size_t index) const{
    return root_->execute(index);
}