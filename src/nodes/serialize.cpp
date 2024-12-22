// #include "serialize.h"
// #include "data.h"
// #include "arithmetic_types.h"
// #include "domain.h"
// #include <iostream>

// namespace serialization{

// void serialize_to(const std::filesystem::path& path,DataPool* pool){
//     SerialData serial_data;
//     serial_data.open_to_write(path);
//     serial_data.serialize_header(pool);
//     serial_data.serialize_body(pool);
//     serial_data.data_stream_.close();
// }

// DataPool deserialize_from(const std::filesystem::path& path){
//     SerialData serial_data;
//     serial_data.open_to_read(path);
//     DataPool pool = serial_data.deserialize_header();
//     serial_data.deserialize_body();
//     serial_data.data_stream_.close();
//     return pool;
// }

// void SerialData::insert_var(uint64_t var_id, const std::shared_ptr<VariableNode>& node) noexcept{
//     if(node)
//         nodes_[var_id]=node;

//     for(auto ref:node->references()){
//         //add_dependency((uint64_t)parent,var_id);
//     }
//     if(node->childs().size()>0)
//         nodes_dependencies_[var_id].reserve(node->childs().size());
// }

// void SerialData::serialize_header(DataPool* pool){
//     uint32_t sz=0;
//     uint8_t name_sz = 0;
//     uint64_t pool_id = 0;
//     uint64_t db_id = 0;

//     data_stream_.write("/OMB\n",5);
//     //pool name size and pool name
//     name_sz = pool->name().size();
//     data_stream_.write(reinterpret_cast<const char*>(&name_sz),sizeof(name_sz));
//     data_stream_.write(pool->name().data(),pool->name().size());
//     //pool hash
//     pool_id = (uint64_t)pool;
//     data_stream_.write(reinterpret_cast<const char*>(&pool_id),sizeof(pool_id));

//     //number of data_bases
//     sz = pool->data_bases().size();
//     data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
//     //data_stream_.write("\n", 1);
//     for(auto& data_base:pool->data_bases()){
//         //database name size and database name
//         name_sz = data_base->name().size();
//         data_stream_.write(reinterpret_cast<const char*>(&name_sz),sizeof(name_sz));
//         data_stream_.write(data_base->name().data(), data_base->name().size());
//         //database hash
//         db_id = (uint64_t)data_base.get();
//         data_stream_.write(reinterpret_cast<const char*>(&db_id),sizeof(db_id));

//         //number of variables
//         sz = data_base->variables().size();
//         data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
//         if(!data_base->variables().empty()){
//             std::function<void(const std::shared_ptr<AbstractNode>&)> nodes_size;
//             sz=0;
//             nodes_size=[&sz](const std::shared_ptr<AbstractNode>& node)->void
//             {
//                 ++sz;
//             };

//             std::function<void(const std::shared_ptr<AbstractNode>&)> nodes_to_header;
//             nodes_to_header=[this](const std::shared_ptr<AbstractNode>& node)->void
//             {
//                 if(node){
//                     NodeProperties props;
//                     props.id = (uint64_t)node.get();
//                     for(auto child:node->childs()){
//                         add_dependency(props.id,(uint64_t)child.get());
//                     }
//                     props.type = (uint8_t)node->type();
//                     props.sz = node->childs().size();
//                     switch((NODE_TYPE)props.type){
//                         case NODE_TYPE::ARRAY:
//                             break;
//                         case NODE_TYPE::BINARY:
//                             props.operation = (uint8_t)std::dynamic_pointer_cast<BinaryNode>(node)->operation();
//                             break;
//                         case NODE_TYPE::FUNCTION:
//                             props.operation = (uint8_t)std::dynamic_pointer_cast<FunctionNode>(node)->operation();
//                             break;
//                         case NODE_TYPE::RANGEOP:
//                             props.operation = (uint8_t)std::dynamic_pointer_cast<RangeOperationNode>(node)->operation();
//                             break;
//                         case NODE_TYPE::STRING:
//                             break;
//                         case NODE_TYPE::UNARY:
//                             props.operation = (uint8_t)std::dynamic_pointer_cast<UnaryNode>(node)->operation();
//                             break;
//                         case NODE_TYPE::VALUE:
//                             props.cache = node->execute();
//                             break;
//                         case NODE_TYPE::VARIABLE:
//                             break;
//                         default:
//                             throw std::runtime_error("Unknown data of node");
//                     }
//                     data_stream_.write(reinterpret_cast<const char*>(&props),sizeof(props));
//                     //data_stream_.write("\n", 1);
//                 }
//                 else throw std::runtime_error("Fatal error when saving variable data");
//                 return;
//             };

//             for(auto& [var_name,var]:data_base->variables()){
//                 VarProperties props;

//                 //variable name size and variable name
//                 props.id = (uint64_t)var->node().get();
//                 props.sz_name = var_name.size();

//                 data_stream_.write(reinterpret_cast<const char*>(&props),sizeof(props));
//                 data_stream_.write(var_name.data(),var_name.size());
                
//                 //data_stream_.write("\n", 1);
//                 if(!var->node()->childs().empty())
//                     nodes_dependencies_[props.id].reserve(var->node()->childs().size());

//                 for(const auto& child:var->node()->childs()){
//                     nodes_dependencies_[(uint64_t)var->node().get()].push_back((uint64_t)child.get());
//                 }

//                 uint32_t sz_domains = var->get_domains().get_domains().size();
//                 data_stream_.write(reinterpret_cast<const char*>(&sz_domains),sizeof(sz_domains));
//                 for(auto& domain:var->get_domains().get_domains()){
//                     nodes_to_header(domain.lhs_);
//                     nodes_to_header(domain.rhs_);
//                     nodes_to_header(domain.value_if_true_);
//                     data_stream_.write(reinterpret_cast<const char*>(&domain.type_),sizeof(uint8_t));
//                 }
//             }

//             //get number of non-variable nodes
//             for(auto& [var_name,var]:data_base->variables()){
//                 var->node()->recursive_function_applied_to_all_childs(nodes_size);
//                 for(auto& domain:var->get_domains().get_domains()){
//                     domain.lhs_->recursive_function_applied_to_all_childs(nodes_size);
//                     domain.rhs_->recursive_function_applied_to_all_childs(nodes_size);
//                     domain.value_if_true_->recursive_function_applied_to_all_childs(nodes_size);
//                 }
//             }
            
//             //writing number of non-variable nodes
//             data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));

//             //writing non-variable nodes info
//             for(auto& [var_name,var]:data_base->variables()){
//                 var->node()->recursive_function_applied_to_all_childs(nodes_to_header);
//                 for(auto& domain:var->get_domains().get_domains()){
//                     domain.lhs_->recursive_function_applied_to_all_childs(nodes_to_header);
//                     domain.rhs_->recursive_function_applied_to_all_childs(nodes_to_header);
//                     domain.value_if_true_->recursive_function_applied_to_all_childs(nodes_to_header);
//                 }
//             }
//             //data_stream_.seekp(-1,std::ostream::end);                
//         }
//         //else data_stream_.write("\n", 1);
//     }
// }

// void SerialData::serialize_body(DataPool* pool){
//     uint64_t sz_dependencies = nodes_dependencies_.size();
//     data_stream_.write(reinterpret_cast<const char*>(&sz_dependencies),sizeof(sz_dependencies));
//     for(auto& [parent_id, childs]:nodes_dependencies_){
//         data_stream_.write(reinterpret_cast<const char*>(&parent_id),sizeof(parent_id));
//         size_t sz = childs.size();
//         data_stream_.write(reinterpret_cast<const char*>(&sz),sizeof(sz));
//         data_stream_.write(reinterpret_cast<const char*>(childs.data()),childs.size()*sizeof(childs.data()));
//     }
// }

// DataPool SerialData::deserialize_header(){
//     uint8_t name_sz = 0;
//     uint64_t pool_id = 0;
//     uint64_t db_id = 0;
//     {
//         std::string fmt_ctrl(5,0);
//         data_stream_.read(fmt_ctrl.data(),5);
//         if(fmt_ctrl!="/OMB\n")
//             throw std::runtime_error("Incorrect format");
//     }

//     //pool name size and pool name
//     data_stream_.read(reinterpret_cast<char*>(&name_sz),sizeof(name_sz));

//     std::string pool_name(name_sz,0);
//     data_stream_.read(pool_name.data(),name_sz);

//     DataPool pool(pool_name);
//     insert_pool(pool_id,&pool);
//     //pool hash
//     data_stream_.read(reinterpret_cast<char*>(&pool_id),sizeof(pool_id));
    

//     //number of data_bases
//     uint32_t sz_db=0;
//     data_stream_.read(reinterpret_cast<char*>(&sz_db),sizeof(sz_db));
    
//     for(decltype(sz_db) iter = 0; iter<sz_db;++iter){     
//         data_stream_.read(reinterpret_cast<char*>(&name_sz),sizeof(name_sz));
//         std::string db_name(name_sz,0);

//         data_stream_.read(db_name.data(), name_sz);

//         BaseData* db=nullptr;
        
//         data_stream_.read(reinterpret_cast<char*>(&db_id),sizeof(db_id));
        
//         if(!contains_data(db_id)){
//             db = pool.add_data(db_name);
//             insert_data(db_id,db);
//         }
//         else std::runtime_error("Incorrect reading OMB file. Prompt: failure when reading database " +std::to_string(db_id));
//         //insert in serial data base

//         //number of variables
//         uint32_t sz_var;
//         data_stream_.read(reinterpret_cast<char*>(&sz_var),sizeof(sz_var));
//         if(sz_var!=0){

//             std::function<std::shared_ptr<AbstractNode>()> nodes_from_header;
//             nodes_from_header = [this]()->std::shared_ptr<AbstractNode> {
//                 NodeProperties props;
//                 data_stream_.read(reinterpret_cast<char*>(&props),sizeof(props));
//                 switch ((NODE_TYPE)props.type){
//                     case NODE_TYPE::ARRAY:
//                         insert_node(props.id,std::make_shared<ArrayNode>(props.sz));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::BINARY:
//                         insert_node(props.id,std::make_shared<BinaryNode>((BINARY_OP)props.operation));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::FUNCTION:
//                         insert_node(props.id,std::make_shared<FunctionNode>((FUNCTION_OP)props.operation, props.sz));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::RANGEOP:
//                         insert_node(props.id,std::make_shared<RangeOperationNode>((RANGE_OP)props.operation));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::STRING:
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::UNARY:
//                         insert_node(props.id,std::make_shared<UnaryNode>((UNARY_OP)props.operation));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::VALUE:
//                         insert_node(props.id,std::make_shared<ValueNode>(props.cache.get<Value_t>()));
//                         return nodes_.at(props.id);
//                         break;
//                     case NODE_TYPE::VARIABLE:
//                         return nodes_.at(props.id);
//                         break;
//                     default:
//                         throw std::runtime_error("Unknown data of node");
//                         return nodes_.at(props.id);
//                 }
//             };

//             //definition of variables
//             for(decltype(sz_var) var_iter=0;var_iter<sz_var;++var_iter){
//                 VarProperties props;

//                 data_stream_.read(reinterpret_cast<char*>(&props),sizeof(props));

//                 std::string var_name(props.sz_name,0);
//                 data_stream_.read(var_name.data(),props.sz_name);

//                 if(!contains_node(props.id) && db)
//                     insert_var(props.id,db->add_variable(std::move(var_name))->node());
//                 else assert(false);

//                 uint32_t sz_domains;
//                 data_stream_.read(reinterpret_cast<char*>(&sz_domains),sizeof(sz_domains));
//                 for(decltype(sz_domains) domain_iter=0;domain_iter<sz_domains;++domain_iter){
//                     Domain domain;
//                     domain.lhs_ = nodes_from_header();
//                     domain.rhs_ = nodes_from_header();
//                     domain.value_if_true_ = nodes_from_header();
//                     data_stream_.read(reinterpret_cast<char*>(&domain.type_),sizeof(uint8_t));
//                     std::dynamic_pointer_cast<VariableNode>(nodes_.at(props.id))->variable()->add_domain(std::move(domain));
//                 }
//             }
//             uint32_t sz_nodes;

//             //definition of nodes
//             data_stream_.read(reinterpret_cast<char*>(&sz_nodes),sizeof(sz_nodes));
//             for(decltype(sz_nodes) nodes_iter=0;nodes_iter<sz_nodes;++nodes_iter){
//                 nodes_from_header();
//             }
//         }
//     }
//     return pool;
// }

// void SerialData::deserialize_body(){
//     uint64_t sz_line = 0;
//     uint64_t parent_id = 0;
//     data_stream_.read(reinterpret_cast<char*>(&sz_line),sizeof(sz_line));
//     for(decltype(sz_line) iter_line = 0; iter_line<sz_line;++iter_line){
//         data_stream_.read(reinterpret_cast<char*>(&parent_id),sizeof(parent_id));

//         //header must already init all nodes
//         if(!contains_node(parent_id))
//             throw std::runtime_error("Incorrect reading OMB file. Prompt: not found node " +std::to_string(parent_id));

//         size_t sz_dep;
//         data_stream_.read(reinterpret_cast<char*>(&sz_dep),sizeof(sz_dep));

//         if(sz_dep>0)
//             nodes_dependencies_[parent_id].resize(sz_dep,0);
//         for(decltype(sz_dep) iter_dep = 0; iter_dep<sz_dep;++iter_dep){
//             uint64_t node_id = 0;
//             data_stream_.read(reinterpret_cast<char*>(&node_id),sizeof(node_id));
//             nodes_dependencies_.at(parent_id)[iter_dep]=node_id;
//             nodes_.at(parent_id)->insert_back(nodes_.at(node_id));
//         }
//     }
// }

// void serialize_to(std::filesystem::path&& path,DataPool* pool){
//     serialize_to(path,pool);
// }

// }