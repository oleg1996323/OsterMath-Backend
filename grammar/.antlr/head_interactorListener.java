// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link head_interactor}.
 */
public interface head_interactorListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link head_interactor#value_type}.
	 * @param ctx the parse tree
	 */
	void enterValue_type(head_interactor.Value_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#value_type}.
	 * @param ctx the parse tree
	 */
	void exitValue_type(head_interactor.Value_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#input}.
	 * @param ctx the parse tree
	 */
	void enterInput(head_interactor.InputContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#input}.
	 * @param ctx the parse tree
	 */
	void exitInput(head_interactor.InputContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#line_input}.
	 * @param ctx the parse tree
	 */
	void enterLine_input(head_interactor.Line_inputContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#line_input}.
	 * @param ctx the parse tree
	 */
	void exitLine_input(head_interactor.Line_inputContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#vardefinition}.
	 * @param ctx the parse tree
	 */
	void enterVardefinition(head_interactor.VardefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#vardefinition}.
	 * @param ctx the parse tree
	 */
	void exitVardefinition(head_interactor.VardefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#comparator}.
	 * @param ctx the parse tree
	 */
	void enterComparator(head_interactor.ComparatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#comparator}.
	 * @param ctx the parse tree
	 */
	void exitComparator(head_interactor.ComparatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#comparision}.
	 * @param ctx the parse tree
	 */
	void enterComparision(head_interactor.ComparisionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#comparision}.
	 * @param ctx the parse tree
	 */
	void exitComparision(head_interactor.ComparisionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterLhs_comp(head_interactor.Lhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitLhs_comp(head_interactor.Lhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterRhs_comp(head_interactor.Rhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitRhs_comp(head_interactor.Rhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#expr_comp}.
	 * @param ctx the parse tree
	 */
	void enterExpr_comp(head_interactor.Expr_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#expr_comp}.
	 * @param ctx the parse tree
	 */
	void exitExpr_comp(head_interactor.Expr_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(head_interactor.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(head_interactor.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link head_interactor#input_array}.
	 * @param ctx the parse tree
	 */
	void enterItemArray(head_interactor.ItemArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link head_interactor#input_array}.
	 * @param ctx the parse tree
	 */
	void exitItemArray(head_interactor.ItemArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#node_access}.
	 * @param ctx the parse tree
	 */
	void enterNode_access(head_interactor.Node_accessContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#node_access}.
	 * @param ctx the parse tree
	 */
	void exitNode_access(head_interactor.Node_accessContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(head_interactor.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(head_interactor.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(head_interactor.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(head_interactor.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(head_interactor.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(head_interactor.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(head_interactor.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(head_interactor.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(head_interactor.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(head_interactor.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariableInExpr(head_interactor.VariableInExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariableInExpr(head_interactor.VariableInExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(head_interactor.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link head_interactor#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(head_interactor.BinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(head_interactor.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(head_interactor.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(head_interactor.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(head_interactor.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(head_interactor.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(head_interactor.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void enterMultiargfunction(head_interactor.MultiargfunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void exitMultiargfunction(head_interactor.MultiargfunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#rangefunction}.
	 * @param ctx the parse tree
	 */
	void enterRangefunction(head_interactor.RangefunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#rangefunction}.
	 * @param ctx the parse tree
	 */
	void exitRangefunction(head_interactor.RangefunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#string}.
	 * @param ctx the parse tree
	 */
	void enterString(head_interactor.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#string}.
	 * @param ctx the parse tree
	 */
	void exitString(head_interactor.StringContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactor#string_arg}.
	 * @param ctx the parse tree
	 */
	void enterString_arg(head_interactor.String_argContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactor#string_arg}.
	 * @param ctx the parse tree
	 */
	void exitString_arg(head_interactor.String_argContext ctx);
}