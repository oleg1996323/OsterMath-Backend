#include "arithmetic_tree.h"

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
        if(other.root_)
            this->root_ = std::make_shared<Node>(*other.root_.get());
        else this->root_.reset();

        this->cache_=other.cache_;

        if(root_)
            last_incomplete_ = root_->first_undefined_child_node();
    }
    return *this;
}

const Value_t& ArithmeticTree::value() const{
    return cache_;
}

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree){
    stream<<tree.value();
    return stream;
}

Value_t ArithmeticTree::execute() const{
    if(root_)
        return root_->execute();
    else return 0.;
}

void ArithmeticTree::insert(Node* node){
    if(!is_ready()){
        if(node->type()==ARITHM_NODE_TYPE::UNARY)
            reinterpret_cast<UnaryNode*>(last_incomplete_)->child() = std::shared_ptr<Node>(node);
        else {
            BinaryNode* ptr = reinterpret_cast<BinaryNode*>(last_incomplete_);
            if(!ptr->lhs())
                ptr->lhs() = std::make_shared<Node>(node);
            else ptr->rhs() = std::make_shared<Node>(node);
        }
    }
    else{
        root_->parent() = std::make_shared<Node>(node);
        if(node->type()==ARITHM_NODE_TYPE::UNARY){
            reinterpret_cast<UnaryNode*>(node)->child() = std::shared_ptr<Node>(root_);
            root_ = std::shared_ptr<Node>(node);
        }
        else if(node->type()==ARITHM_NODE_TYPE::BINARY){
            BinaryNode* ptr = reinterpret_cast<BinaryNode*>(node);
            ptr->lhs() = std::make_shared<Node>(root_);
            root_ = std::shared_ptr<Node>(ptr);
        }
        else throw std::invalid_argument("Error function definition");
    }
}

bool ArithmeticTree::is_ready() const{
    if(!last_incomplete_)
        last_incomplete_ = root_->first_undefined_child_node();
    if(last_incomplete_==nullptr)
        return true;
    else
        return false;
}