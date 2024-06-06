#include "node.h"

void Node::refresh(){
    execute();
    caller_ = true;
    for(auto parent:parents_)
        parent->refresh();
    caller_ = false;
}

void Node::add_parent(Node* parent){
    parents_.insert(parent);
}

bool Node::has_parents() const{
    return !parents_.empty();
}

const std::vector<std::shared_ptr<Node>>& Node::childs() const{
    return childs_;
}

std::ostream& Node::print_result(std::ostream& stream) const{
    stream<<execute();
    return stream;
}

std::ostream& Node::print_text(std::ostream& stream) const{
    stream<<"#NaN"<<std::endl;
    return stream;
}