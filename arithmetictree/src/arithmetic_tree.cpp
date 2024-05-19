#include "arithmetic_tree.h"
#include "arithmetic_types.h"
#include "types.h"

ArithmeticTree::ArithmeticTree(const ArithmeticTree& other){
    if(this!=&other){
        *this = other;
    }
}

ArithmeticTree::ArithmeticTree(VariableBase* owner):owner_(owner){}

ArithmeticTree::ArithmeticTree(ArithmeticTree&& other) noexcept{
    if(this!=&other){
        this->root_ = std::move(other.root_);
        this->cache_ = std::move(other.cache_);
        this->owner_ = other.owner_;
        this->last_incomplete_ = other.last_incomplete_;
    }
}

ArithmeticTree& ArithmeticTree::operator=(const ArithmeticTree& other){
    if(this!=&other){
        this->root_ = other.root_;
        this->cache_=other.cache_;
        this->owner_ = other.owner_;
        last_incomplete_ = other.last_incomplete_;
    }
    return *this;
}

ArithmeticTree& ArithmeticTree::operator=(ArithmeticTree&& other) noexcept{
    if(this!=&other){
        this->root_ = std::move(other.root_);
        this->cache_=std::move(other.cache_);
        this->owner_ = other.owner_;
        last_incomplete_ = other.last_incomplete_;
    }
    return *this;
}

const Value_t& ArithmeticTree::value() const{
    if(!cache_.has_value())
        cache_.emplace(execute());
    return cache_.value();
}

VariableBase* ArithmeticTree::owner() const{
    return owner_;
}

const Value_t& ranges::ArithmeticTree::value(size_t index) const{
    if(!cache_.has_value())
        cache_.emplace(execute(index));
    return cache_.value();
}

Value_t ArithmeticTree::execute() const{
    if(root_){
        if(std::all_of(var_dependence_.begin(),var_dependence_.end(),[this](const VariableNode* node){
            if(!node->variable()->is_undef())
                return owner_->is_in_bounds(node->variable()->get_data_base_name(), node->variable()->name());
            else return true;
        }))
            return root_->execute();
        else return 0.;
    }
    else return 0.;
}

#ifdef DEBUG
void ArithmeticTree::print() const{
    root_->print();
}
#endif

const std::unordered_set<VariableNode*>& ArithmeticTree::get_dependecies() const{
    return var_dependence_;
}

void ArithmeticTree::insert(const std::shared_ptr<Node>& node){
    if(node->type() == ARITHM_NODE_TYPE::VARIABLE){
        var_dependence_.insert(reinterpret_cast<VariableNode*>(node.get()));
    }
    else if(node->type() == ARITHM_NODE_TYPE::FUNCTION){
        for(auto it:reinterpret_cast<FunctionNode*>(node.get())->get_dependecies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::RANGEOP){
        for(auto it:reinterpret_cast<RangeOperationNode*>(node.get())->get_dependecies())
            var_dependence_.insert(it);
    }

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