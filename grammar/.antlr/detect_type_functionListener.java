// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link detect_type_functionParser}.
 */
public interface detect_type_functionListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#value_type}.
	 * @param ctx the parse tree
	 */
	void enterValue_type(detect_type_functionParser.Value_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#value_type}.
	 * @param ctx the parse tree
	 */
	void exitValue_type(detect_type_functionParser.Value_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#comparator}.
	 * @param ctx the parse tree
	 */
	void enterComparator(detect_type_functionParser.ComparatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#comparator}.
	 * @param ctx the parse tree
	 */
	void exitComparator(detect_type_functionParser.ComparatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#input}.
	 * @param ctx the parse tree
	 */
	void enterInput(detect_type_functionParser.InputContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#input}.
	 * @param ctx the parse tree
	 */
	void exitInput(detect_type_functionParser.InputContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#line_input}.
	 * @param ctx the parse tree
	 */
	void enterLine_input(detect_type_functionParser.Line_inputContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#line_input}.
	 * @param ctx the parse tree
	 */
	void exitLine_input(detect_type_functionParser.Line_inputContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#node_access}.
	 * @param ctx the parse tree
	 */
	void enterNode_access(detect_type_functionParser.Node_accessContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#node_access}.
	 * @param ctx the parse tree
	 */
	void exitNode_access(detect_type_functionParser.Node_accessContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(detect_type_functionParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(detect_type_functionParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void enterVardefinition(detect_type_functionParser.VardefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void exitVardefinition(detect_type_functionParser.VardefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#comparision}.
	 * @param ctx the parse tree
	 */
	void enterComparision(detect_type_functionParser.ComparisionContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#comparision}.
	 * @param ctx the parse tree
	 */
	void exitComparision(detect_type_functionParser.ComparisionContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterLhs_comp(detect_type_functionParser.Lhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitLhs_comp(detect_type_functionParser.Lhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterRhs_comp(detect_type_functionParser.Rhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitRhs_comp(detect_type_functionParser.Rhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void enterExpr_comp(detect_type_functionParser.Expr_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void exitExpr_comp(detect_type_functionParser.Expr_compContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(detect_type_functionParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(detect_type_functionParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(detect_type_functionParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(detect_type_functionParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(detect_type_functionParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(detect_type_functionParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(detect_type_functionParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(detect_type_functionParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariableInExpr(detect_type_functionParser.VariableInExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariableInExpr(detect_type_functionParser.VariableInExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(detect_type_functionParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link detect_type_functionParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(detect_type_functionParser.BinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(detect_type_functionParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(detect_type_functionParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link detect_type_functionParser#input_array}.
	 * @param ctx the parse tree
	 */
	void enterItemArray(detect_type_functionParser.ItemArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link detect_type_functionParser#input_array}.
	 * @param ctx the parse tree
	 */
	void exitItemArray(detect_type_functionParser.ItemArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(detect_type_functionParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(detect_type_functionParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(detect_type_functionParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(detect_type_functionParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(detect_type_functionParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(detect_type_functionParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void enterMultiargfunction(detect_type_functionParser.MultiargfunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void exitMultiargfunction(detect_type_functionParser.MultiargfunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void enterRangefunction(detect_type_functionParser.RangefunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void exitRangefunction(detect_type_functionParser.RangefunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link detect_type_functionParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(detect_type_functionParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link detect_type_functionParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(detect_type_functionParser.StringContext ctx);
}