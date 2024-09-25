// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link head_interactorParser}.
 */
public interface head_interactorListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#value_type}.
	 * @param ctx the parse tree
	 */
	void enterValue_type(head_interactorParser.Value_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#value_type}.
	 * @param ctx the parse tree
	 */
	void exitValue_type(head_interactorParser.Value_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#comparator}.
	 * @param ctx the parse tree
	 */
	void enterComparator(head_interactorParser.ComparatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#comparator}.
	 * @param ctx the parse tree
	 */
	void exitComparator(head_interactorParser.ComparatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#input}.
	 * @param ctx the parse tree
	 */
	void enterInput(head_interactorParser.InputContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#input}.
	 * @param ctx the parse tree
	 */
	void exitInput(head_interactorParser.InputContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#line_input}.
	 * @param ctx the parse tree
	 */
	void enterLine_input(head_interactorParser.Line_inputContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#line_input}.
	 * @param ctx the parse tree
	 */
	void exitLine_input(head_interactorParser.Line_inputContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#node_access}.
	 * @param ctx the parse tree
	 */
	void enterNode_access(head_interactorParser.Node_accessContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#node_access}.
	 * @param ctx the parse tree
	 */
	void exitNode_access(head_interactorParser.Node_accessContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(head_interactorParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(head_interactorParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void enterVardefinition(head_interactorParser.VardefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void exitVardefinition(head_interactorParser.VardefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#comparision}.
	 * @param ctx the parse tree
	 */
	void enterComparision(head_interactorParser.ComparisionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#comparision}.
	 * @param ctx the parse tree
	 */
	void exitComparision(head_interactorParser.ComparisionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterLhs_comp(head_interactorParser.Lhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitLhs_comp(head_interactorParser.Lhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterRhs_comp(head_interactorParser.Rhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitRhs_comp(head_interactorParser.Rhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void enterExpr_comp(head_interactorParser.Expr_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void exitExpr_comp(head_interactorParser.Expr_compContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(head_interactorParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(head_interactorParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(head_interactorParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(head_interactorParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(head_interactorParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(head_interactorParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(head_interactorParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(head_interactorParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariableInExpr(head_interactorParser.VariableInExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariableInExpr(head_interactorParser.VariableInExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(head_interactorParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link head_interactorParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(head_interactorParser.BinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(head_interactorParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(head_interactorParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link head_interactorParser#input_array}.
	 * @param ctx the parse tree
	 */
	void enterItemArray(head_interactorParser.ItemArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link head_interactorParser#input_array}.
	 * @param ctx the parse tree
	 */
	void exitItemArray(head_interactorParser.ItemArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(head_interactorParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(head_interactorParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(head_interactorParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(head_interactorParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(head_interactorParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(head_interactorParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void enterMultiargfunction(head_interactorParser.MultiargfunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void exitMultiargfunction(head_interactorParser.MultiargfunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void enterRangefunction(head_interactorParser.RangefunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void exitRangefunction(head_interactorParser.RangefunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link head_interactorParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(head_interactorParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link head_interactorParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(head_interactorParser.StringContext ctx);
}