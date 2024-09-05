// Generated from /home/oster/Electrolisys/arithmetictree/grammar/ParseRules.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ParseRulesParser}.
 */
public interface ParseRulesListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#value_type}.
	 * @param ctx the parse tree
	 */
	void enterValue_type(ParseRulesParser.Value_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#value_type}.
	 * @param ctx the parse tree
	 */
	void exitValue_type(ParseRulesParser.Value_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#comparator}.
	 * @param ctx the parse tree
	 */
	void enterComparator(ParseRulesParser.ComparatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#comparator}.
	 * @param ctx the parse tree
	 */
	void exitComparator(ParseRulesParser.ComparatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#input}.
	 * @param ctx the parse tree
	 */
	void enterInput(ParseRulesParser.InputContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#input}.
	 * @param ctx the parse tree
	 */
	void exitInput(ParseRulesParser.InputContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#line_input}.
	 * @param ctx the parse tree
	 */
	void enterLine_input(ParseRulesParser.Line_inputContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#line_input}.
	 * @param ctx the parse tree
	 */
	void exitLine_input(ParseRulesParser.Line_inputContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#node_access}.
	 * @param ctx the parse tree
	 */
	void enterNode_access(ParseRulesParser.Node_accessContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#node_access}.
	 * @param ctx the parse tree
	 */
	void exitNode_access(ParseRulesParser.Node_accessContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(ParseRulesParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(ParseRulesParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void enterVardefinition(ParseRulesParser.VardefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#vardefinition}.
	 * @param ctx the parse tree
	 */
	void exitVardefinition(ParseRulesParser.VardefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#comparision}.
	 * @param ctx the parse tree
	 */
	void enterComparision(ParseRulesParser.ComparisionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#comparision}.
	 * @param ctx the parse tree
	 */
	void exitComparision(ParseRulesParser.ComparisionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterLhs_comp(ParseRulesParser.Lhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#lhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitLhs_comp(ParseRulesParser.Lhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void enterRhs_comp(ParseRulesParser.Rhs_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#rhs_comp}.
	 * @param ctx the parse tree
	 */
	void exitRhs_comp(ParseRulesParser.Rhs_compContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void enterExpr_comp(ParseRulesParser.Expr_compContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#expr_comp}.
	 * @param ctx the parse tree
	 */
	void exitExpr_comp(ParseRulesParser.Expr_compContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(ParseRulesParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(ParseRulesParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(ParseRulesParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(ParseRulesParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ParseRulesParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ParseRulesParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(ParseRulesParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(ParseRulesParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariableInExpr(ParseRulesParser.VariableInExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VariableInExpr}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariableInExpr(ParseRulesParser.VariableInExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(ParseRulesParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link ParseRulesParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(ParseRulesParser.BinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(ParseRulesParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(ParseRulesParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link ParseRulesParser#input_array}.
	 * @param ctx the parse tree
	 */
	void enterItemArray(ParseRulesParser.ItemArrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ItemArray}
	 * labeled alternative in {@link ParseRulesParser#input_array}.
	 * @param ctx the parse tree
	 */
	void exitItemArray(ParseRulesParser.ItemArrayContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(ParseRulesParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(ParseRulesParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(ParseRulesParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(ParseRulesParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(ParseRulesParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(ParseRulesParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void enterMultiargfunction(ParseRulesParser.MultiargfunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#multiargfunction}.
	 * @param ctx the parse tree
	 */
	void exitMultiargfunction(ParseRulesParser.MultiargfunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void enterRangefunction(ParseRulesParser.RangefunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#rangefunction}.
	 * @param ctx the parse tree
	 */
	void exitRangefunction(ParseRulesParser.RangefunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParseRulesParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(ParseRulesParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParseRulesParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(ParseRulesParser.StringContext ctx);
}