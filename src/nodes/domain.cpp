#include "abstract_node.h"
#include "domain.h"
#include "types.h"
#include "arithmetic_types.h"

bool Domain::is() const{
    if(lhs_->execute().is_value() && rhs_->execute().is_value()){
        switch (type_)
        {
        case COMP_T::LARGER_OR_EQUAL:
            if(lhs_->cached_result().get_value()>=rhs_->cached_result().get_value())
                return true;
            break;
        case COMP_T::LARGER:
            if(lhs_->cached_result().get_value()>rhs_->cached_result().get_value())
                return true;
            break;
        case COMP_T::EQUAL:
            if(lhs_->cached_result().get_value()==rhs_->cached_result().get_value())
                return true;
            break;
        case COMP_T::LESS:
            if(lhs_->cached_result().get_value()<rhs_->cached_result().get_value())
                return true;
            break;
        case COMP_T::LESS_OR_EQUAL:
            if(lhs_->cached_result().get_value()<=rhs_->cached_result().get_value())
                return true;
            break;
        default:
            return false;
            break;
        }
    }
    return false;
}

void Domain::print_text(std::ostream& stream) const{
    stream<<"if";
    lhs_->print_text(stream);
    switch (type_)
    {
    case COMP_T::LESS:
        stream<<"<";
        break;
    case COMP_T::LESS_OR_EQUAL:
        stream<<"<=";
        break;
    case COMP_T::EQUAL:
        stream<<"=";
        break;
    case COMP_T::LARGER_OR_EQUAL:
        stream<<">=";
        break;
    case COMP_T::LARGER:
        stream<<">";
        break;    
    default:
        break;
    }
    rhs_->print_text(stream);
    stream<<"then";
    if(value_if_true_)
        value_if_true_->print_result(stream);
    else stream<<"#NAN";
}

VariableDomain::VariableDomain(const VariableNode* var_node):
    default_expression_(var_node){}
    
void VariableDomain::add_domain(Domain&& domain){
    domains_.push_back(std::move(domain));
}

void VariableDomain::unset_domain(size_t id){
    if(domains_.size()>id)
        domains_.erase(std::next(domains_.begin(),id));
}

void VariableDomain::clear(){
    domains_.clear();
}

// std::optional<Domain> VariableDomain::get_domain(size_t id){
//     if(domains_.size()>id)
//         return *std::next(domains_.begin(),id);
//     return std::nullopt;
// }

// std::optional<Domain> VariableDomain::get_domain(size_t id) const{
//     return get_domain(id);
// }

Result VariableDomain::execute() const{
    for(const auto& domain:domains_)
        if(domain.is()){
            if(domain.value_if_true_->type()!=NODE_TYPE::UNDEF)
                return domain.value_if_true_->execute();
            else return std::monostate();
        }
    return default_expression_->execute();
}

const std::list<Domain>& VariableDomain::get_domains() const{
    return domains_;
}

std::list<Domain>& VariableDomain::get_domains(){
    return domains_;
}