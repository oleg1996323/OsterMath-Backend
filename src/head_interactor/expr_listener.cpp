// #include "types.h"
// #include "data.h"
// #include "arithmetic_types.h"
// #include "expr_listener.h"
// #include "exception.h"
// #include "node_manager.h"

// using namespace std::string_view_literals;

// bool BaseListener::is_function_operation() const{
//     return !mode_.empty() && mode_.top()==MODE::FUNCTIONOPERATION;
// }

// bool BaseListener::is_variable_definition() const{
//     return !mode_.empty() && mode_.top()==MODE::VARDEF;
// }

// bool BaseListener::is_range_operation() const{
//     return !mode_.empty() && mode_.top()==MODE::RANGEOPERATION;
// }

// bool BaseListener::is_domain_definition() const{
//     return !mode_.empty() && mode_.top()==MODE::DOMAIN_DEFINITION;
// }

// bool BaseListener::is_expression_definition() const{
//     return !mode_.empty() && mode_.top()==MODE::EXPRESSION;
// }

// bool BaseListener::is_array_definition() const{
//     return !mode_.empty() && mode_.top()==MODE::ARRAY_DEFINITION;
// }

// bool BaseListener::is_array_item_definition() const{
//     return !mode_.empty() && mode_.top()==MODE::ARRAY_ITEM_DEFINITION;
// }

// void BaseListener::__insert_to_prec_node__(MODE mode_assert_check){
//     assert(mode_.top()&mode_assert_check);
//     mode_.pop();
//     assert(!anonymous_node_.empty());
//     auto node = anonymous_node_.top();
//     anonymous_node_.pop();
//     assert(!anonymous_node_.empty());
//     if(info && anonymous_node_.size()==1){
//         if(anonymous_node_.top()->type()==NODE_TYPE::VARIABLE)
//             anonymous_node_.top()->insert_back(node);
//         else{
//             //Node* tmp_node = info->parent->replace(info->id,node).get();
//             //tmp_node->relation_manager()->erase_parent(tmp_node, info->parent);
//         }
//     }
//     else anonymous_node_.top()->insert_back(node);
// }

// BaseData* BaseListener::__insert_new_data_base__(std::string&& name){
//     return data_base_->get_pool()->add_data(name);
// }

// BaseListener::MODE operator|(BaseListener::MODE lhs,BaseListener::MODE rhs){
//     return static_cast<BaseListener::MODE>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); 
// }
// BaseListener::MODE operator&(BaseListener::MODE lhs,BaseListener::MODE rhs){
//     return static_cast<BaseListener::MODE>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); 
// }

// void BaseListener::enterParens(head_interactor::ParensContext* ctx){
//     assert(!mode_.empty());
//     mode_.push(MODE::EXPRESSION);
//     if(ctx)
//         anonymous_node_.push(std::make_unique<UnaryNode>(UNARY_OP::PARENS));
//     else assert(false);
// }

// void BaseListener::exitParens(head_interactor::ParensContext* ctx){
//     __insert_to_prec_node__(MODE::EXPRESSION);
// }

// void BaseListener::enterVariable(head_interactor::VariableContext *ctx) {
//     assert(!mode_.empty());
//     BaseData* db_tmp;
//     auto node_ctx = ctx->node_access();
//     if(!ctx->VARIABLE())
//         throw exceptions::ParsingError("Error parsing variable name");
//     if(node_ctx){
//         if(node_ctx->UINT().size()==0){
//             if(ctx->DATABASE())
//                 db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
//             else db_tmp = data_base_;
//             mode_.push(MODE::VALUE);
//             VariableBase* ptr = db_tmp->add_variable(ctx->VARIABLE()->getText()).get();
//             anonymous_node_.push(ptr->node());
//         }
//         else{
//             if(ctx->DATABASE()){
//                 if(!data_base_->get_pool()->exists(ctx->DATABASE()->getText()))
//                     throw exceptions::VariableDontExists(ctx->VARIABLE()->getText());
//                 else
//                     db_tmp = data_base_->get_pool()->get(ctx->DATABASE()->getText());
//             }
//             else{
//                 db_tmp = data_base_;
//             }
            
//             if(db_tmp->exists(ctx->VARIABLE()->getText())){
//                 std::vector<int> ids;
//                 ids.reserve(node_ctx->UINT().size());
//                 for(auto id : node_ctx->UINT()){
//                     std::stringstream sstream(id->getText());
//                     size_t result;
//                     sstream >> result;
//                     ids.push_back(result);
//                 }
//                 info = std::make_unique<INFO_NODE>(db_tmp->get(ctx->VARIABLE()->getText())->node()->child(ids.begin(),ids.end()));
//                 if(!info || !info->parent || info->id==-1 || !info->parent->has_child(info->id) || !info->parent->child(info->id)){
//                     exceptions::NodeChildDontExists(ctx->getText());
//                     return;
//                 }
//                 anonymous_node_.push(info->parent->child(info->id));
//             }
//             else{
//                 throw exceptions::VariableDontExists(ctx->VARIABLE()->getText());
//             }
//             mode_.push(MODE::NODE);
//         }
//     }
//     else{
//         if(ctx->DATABASE())
//             db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
//         else db_tmp = data_base_;
//         mode_.push(MODE::VALUE);
//         VariableBase* ptr = db_tmp->add_variable(ctx->VARIABLE()->getText()).get();
//         anonymous_node_.push(ptr->node());
//     }
// }

// void BaseListener::exitVariable(head_interactor::VariableContext *ctx) {
//     __insert_to_prec_node__(MODE::VALUE | MODE::NODE);
// }

// void BaseListener::enterUnaryOp(head_interactor::UnaryOpContext *ctx) {
//     assert(!mode_.empty());
//     mode_.push(MODE::EXPRESSION);
//     if(ctx->ADD())
//         anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::ADD));
//     else if(ctx->SUB())
//         anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::SUB));
//     else assert(false);
// }

// void BaseListener::exitUnaryOp(head_interactor::UnaryOpContext* ctx)  {
//     __insert_to_prec_node__(MODE::EXPRESSION);
// }

// void BaseListener::enterLiteral(head_interactor::LiteralContext *ctx) {
//     return;
// }

// void BaseListener::exitLiteral(head_interactor::LiteralContext *ctx) {
//     return;
// }

// //a connstant definition {for example: Lg(Expr)}
// void BaseListener::enterConstant(head_interactor::ConstantContext *ctx) {
//     assert(!mode_.empty());
//     mode_.push(MODE::VALUE);
//     if(ctx->EXP()){
//         anonymous_node_.push(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
//     }
//     else if(ctx->PI()){
//         anonymous_node_.push(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
//     }
//     else
//         throw std::runtime_error("Error parsing constant");
//     return;
// }

// void BaseListener::exitConstant(head_interactor::ConstantContext *ctx) {
//     __insert_to_prec_node__(MODE::VALUE);
// }

// //binary operator {for example: Expr + Expr or Expr / Expr}
// void BaseListener::enterBinaryOp(head_interactor::BinaryOpContext *ctx) {
//     assert(!mode_.empty());
//     mode_.push(MODE::EXPRESSION);
//     if(ctx->ADD())
//         anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::ADD));
//     else if(ctx->SUB())
//         anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::SUB));
//     else if(ctx->MUL())
//         anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::MUL));
//     else if(ctx->DIV())
//         anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     else
//         anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::POW));
//     return;
// }

// void BaseListener::exitBinaryOp(head_interactor::BinaryOpContext *ctx) {
//     __insert_to_prec_node__(MODE::EXPRESSION);
// }

// //an array definition {for example: [1,2,3,...]}
// void BaseListener::enterArray(head_interactor::ArrayContext *ctx) {
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     anonymous_node_.push(std::make_shared<ArrayNode>(ctx->input_array().size()));
//     mode_.push(MODE::ARRAY_DEFINITION);
// }

// void BaseListener::exitArray(head_interactor::ArrayContext *ctx) {
//     __insert_to_prec_node__(MODE::ARRAY_DEFINITION);
// }

// void BaseListener::enterNumber(head_interactor::NumberContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::VALUE);
//     anonymous_node_.push(std::make_shared<ValueNode>(ctx->getText()));
// }

// void BaseListener::exitNumber(head_interactor::NumberContext* ctx){
//     __insert_to_prec_node__(MODE::VALUE);
// }

// void BaseListener::enterMultiargfunction(head_interactor::MultiargfunctionContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::MULTIARGFUNCTION);
//     std::cout<<ctx->getStart()->getType()<<std::endl;
//     switch (ctx->getStart()->getType()){
//         case head_interactor::SUMPRODUCT:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SUMPRODUCT,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::PRODUCT:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::PROD,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::SUM:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SUM,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::AVERAGE:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::AVERAGE,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::ROOT_MEAN_SQUARE:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SUMPRODUCT,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::ROOT_MEAN_SQUARE_ERROR:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ROOT_MEAN_SQUARE_ERROR,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::MEDIAN:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::MEDIAN,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::CONCAT:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::CONCAT,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::SEARCH_STRING:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SEARCH_TEXT,ctx->expr().size()));
//             break;
//         }
//         case head_interactor::CONTAIN_TEXT:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::CONTAIN_TEXT,ctx->expr().size()));
//             break;
//         }
//         default:{
//             throw std::runtime_error("Unknown input of function context");
//         }
//     }
// }

// void BaseListener::enterFunction(head_interactor::FunctionContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::FUNCTIONOPERATION);
//     switch (ctx->getStart()->getType()){
//         case head_interactor::EXP:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::EXP));
//             break;
//         }
//         case head_interactor::LG:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LG10));
//             break;
//         }
//         case head_interactor::LN:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LN));
//             break;
//         }
//         case head_interactor::LOG_X:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LOG_BASE));
//             break;
//         }
//         case head_interactor::SIN:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SIN));
//             break;
//         }
//         case head_interactor::COS:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::COS));
//             break;
//         }
//         case head_interactor::ASIN:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ASIN));
//             break;
//         }
//         case head_interactor::ACOS:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ACOS));
//             break;
//         }
//         case head_interactor::FACTORIAL:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::FACTORIAL));
//             break;
//         }
//         case head_interactor::WEIBULL_DISTRIB:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::STD_NORM_DISTRIB));
//             break;
//         }
//         case head_interactor::GAUSS:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::GAUSS));
//             break;
//         }
//         case head_interactor::STD_NORM_DISTRIB:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::STD_NORM_DISTRIB));
//             break;
//         }
//         case head_interactor::NORM_DISTRIB:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::NORM_DISTRIB));
//             break;
//         }
//         case head_interactor::PEARSON:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::PEARSON));
//             break;
//         }
//         case head_interactor::GAMMA:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::GAMMA));
//             break;
//         }
//         case head_interactor::GAMMA_REV:{
//             anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::GAMMA_REV));
//             break;
//         }
//         default:{
//             throw std::runtime_error("Unknown input of function context");
//         }
//     }
// }

// void BaseListener::enterRangefunction(head_interactor::RangefunctionContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::RANGEOPERATION);
//     if(ctx->SUM_I())
//         anonymous_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::SUM));
//     else if(ctx->PRODUCT_I())
//         anonymous_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::PROD));
//     else throw std::invalid_argument("Invalid type of function");
// }

// void BaseListener::exitFunction(head_interactor::FunctionContext* ctx){
//     __insert_to_prec_node__(MODE::FUNCTIONOPERATION);
// }

// void BaseListener::exitMultiargfunction(head_interactor::MultiargfunctionContext* ctx){
//     __insert_to_prec_node__(MODE::MULTIARGFUNCTION);
// }

// void BaseListener::exitRangefunction(head_interactor::RangefunctionContext* ctx){
//     __insert_to_prec_node__(MODE::RANGEOPERATION);
// }

// void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
//     throw exceptions::ParsingError(node->getText());
// }

// void BaseListener::enterLhs_comp(head_interactor::Lhs_compContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::LHS_DOMAIN);
//     //by default the database from which we define variable must exists
//     anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::NOTHING));
// }

// void BaseListener::exitLhs_comp(head_interactor::Lhs_compContext* ctx){
//     if(ctx){
//         assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//         assert(mode_.top()==MODE::LHS_DOMAIN);
//         mode_.pop();
//         assert(anonymous_node_.size()==1);
//         domain_->lhs_ = anonymous_node_.top();
//         anonymous_node_.pop();
//     }
// }

// void BaseListener::enterRhs_comp(head_interactor::Rhs_compContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     mode_.push(MODE::RHS_DOMAIN);
//     //by default the database from which we define variable must exists
//     anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::NOTHING));
// }

// void BaseListener::exitRhs_comp(head_interactor::Rhs_compContext* ctx){
//     if(ctx){
//         assert(!mode_.empty());
//         assert(mode_.top()==MODE::RHS_DOMAIN);
//         mode_.pop();
//         assert(anonymous_node_.size()==1);
//         domain_->rhs_ = anonymous_node_.top();
//         anonymous_node_.pop();
//     }
// }

// void BaseListener::enterExpr_comp(head_interactor::Expr_compContext* ctx){
//     assert(!mode_.empty() && (current_node_ || anonymous_node_.size()!=0));
//     assert(anonymous_node_.empty());
//     mode_.push(MODE::EXPR_DOMAIN);
//     //by default the database from which we define variable must exists
//     anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::NOTHING));
// }

// void BaseListener::exitExpr_comp(head_interactor::Expr_compContext* ctx){
//     if(ctx){
//         assert(!mode_.empty());
//         assert(mode_.top()==MODE::EXPR_DOMAIN);
//         mode_.pop();
//         assert(anonymous_node_.size()==1);
//         domain_->value_if_true_ = anonymous_node_.top();
//         anonymous_node_.pop();
//     }
// }

// void BaseListener::enterVardefinition(head_interactor::VardefinitionContext * ctx){
//     assert(mode_.empty());
//     assert(anonymous_node_.empty());
//     mode_.push(MODE::VARDEF);
//     //by default the database from which we define variable must exists
//     BaseData* db_tmp;
//     auto node_ctx = ctx->node_access();
//     if(!ctx->VARIABLE())
//         throw exceptions::ParsingError("Error parsing variable name");

//     if(node_ctx){
//         if(node_ctx->UINT().size()==0){
//             if(ctx->DATABASE())
//                 db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
//             else db_tmp = data_base_;
//             current_node_ = db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
//             current_node_->relation_manager()->release_childs(current_node_.get());
//             if(!ctx->value_type())
//                 current_node_->insert_back(std::make_shared<EmptyNode>());
//             anonymous_node_.push(current_node_);
//         }
//         else{
//             if(ctx->DATABASE()){
//                 if(!data_base_->get_pool()->exists(ctx->DATABASE()->getText()))
//                     throw exceptions::VariableDontExists(ctx->VARIABLE()->getText());
//                 else
//                     db_tmp = data_base_->get_pool()->get(ctx->DATABASE()->getText());
//             }
//             else{
//                 db_tmp = data_base_;
//             }
            
//             if(db_tmp->exists(ctx->VARIABLE()->getText())){
//                 std::vector<int> ids;
//                 ids.reserve(node_ctx->UINT().size());
//                 for(auto id : node_ctx->UINT()){
//                     if(id){
//                         std::stringstream sstream(id->getText());
//                         size_t result;
//                         sstream >> result;
//                         ids.push_back(result);
//                     }
//                 }
//                 info = std::make_unique<INFO_NODE>(db_tmp->get(ctx->VARIABLE()->getText())->node()->child(ids.begin(),ids.end()));
//                 if(!info || !info->parent || info->id==-1 || !info->parent->has_child(info->id) || !info->parent->child(info->id)){
//                     exceptions::NodeChildDontExists(ctx->getText());
//                     return;
//                 }
//                 // anonymous_node_.push(info->parent->child(info->id));
                
//                 // if(!ctx->value_type())
//                 //     info->parent->replace(info->id,std::make_shared<Node>());

//                 if(ctx->value_type())
//                     anonymous_node_.push(info->parent->child(info->id));
//                 else {
//                     info->parent->replace(info->id,std::make_shared<EmptyNode>());
//                     anonymous_node_.push(info->parent->child(info->id));
//                 }
//             }
//             else{
//                 throw exceptions::VariableDontExists(ctx->VARIABLE()->getText());
//             }
//         }
//     }
//     else{
//         if(ctx->DATABASE())
//                 db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
//         else db_tmp = data_base_;
//         current_node_ = db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
//         current_node_->relation_manager()->release_childs(current_node_.get());
//         if(!ctx->value_type())
//             current_node_->insert_back(std::make_shared<EmptyNode>());
//         anonymous_node_.push(current_node_);
//     }
// }

// void BaseListener::exitVardefinition(head_interactor::VardefinitionContext * ctx){ 
//     assert(mode_.top()==MODE::VARDEF);
//     assert(anonymous_node_.size()==1);
//     current_node_.reset();
//     anonymous_node_.pop();
//     mode_.pop();
// }

// void BaseListener::enterItemArray(head_interactor::ItemArrayContext *ctx){
//     assert(!mode_.empty());
//     assert(mode_.top()==MODE::ARRAY_DEFINITION);
//     mode_.push(MODE::ARRAY_ITEM_DEFINITION);
// }

// void BaseListener::exitItemArray(head_interactor::ItemArrayContext *ctx){
//     assert(!mode_.empty());
//     assert(mode_.top()==MODE::ARRAY_ITEM_DEFINITION);
//     mode_.pop();
// }

// void BaseListener::enterComparision(head_interactor::ComparisionContext* ctx){
//     assert(mode_.empty());
//     assert(anonymous_node_.empty());
//     domain_.emplace(Domain());
//     if(ctx->comparator()){
//         if(ctx->comparator()->LESS())
//             domain_->type_ = COMP_T::LESS;
//         else if(ctx->comparator()->LESS_EQUAL())
//             domain_->type_ = COMP_T::LESS_OR_EQUAL;
//         else if(ctx->comparator()->EQUAL())
//             domain_->type_ = COMP_T::EQUAL;
//         else if(ctx->comparator()->LARGER_EQUAL())
//             domain_->type_ = COMP_T::LARGER_OR_EQUAL;
//         else if(ctx->comparator()->LARGER())
//             domain_->type_ = COMP_T::LARGER;
//         else throw std::runtime_error("Undefined node");
//     }
//     else throw std::runtime_error("Undefined node");

//     mode_.push(MODE::DOMAIN_DEFINITION);
//     if(ctx->VARIABLE()){
//         //creating in active sheet
//         BaseData* c_var_db_tmp;
//         if(ctx->DATABASE())
//             c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
//         else c_var_db_tmp = data_base_;
//         current_node_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
//     }
//     else assert(false);
// }

// void BaseListener::exitComparision(head_interactor::ComparisionContext* ctx){
//     assert(is_domain_definition());
//     mode_.pop();
//     assert(anonymous_node_.empty());
//     assert(current_node_);
//     assert(domain_.has_value());
//     if(current_node_->type()==NODE_TYPE::VARIABLE)
//         reinterpret_cast<VariableNode*>(current_node_.get())->variable()->add_domain(std::move(domain_.value()));
//     current_node_.reset();
// }

// void BaseListener::enterString(head_interactor::StringContext* ctx){

// }

// void BaseListener::exitString(head_interactor::StringContext* ctx){
    
// }