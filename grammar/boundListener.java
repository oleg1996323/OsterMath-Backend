// Generated from bound.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link boundParser}.
 */
public interface boundListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link boundParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(boundParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(boundParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link boundParser#eq}.
	 * @param ctx the parse tree
	 */
	void enterEq(boundParser.EqContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#eq}.
	 * @param ctx the parse tree
	 */
	void exitEq(boundParser.EqContext ctx);
	/**
	 * Enter a parse tree produced by {@link boundParser#hdr}.
	 * @param ctx the parse tree
	 */
	void enterHdr(boundParser.HdrContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#hdr}.
	 * @param ctx the parse tree
	 */
	void exitHdr(boundParser.HdrContext ctx);
	/**
	 * Enter a parse tree produced by the {@code values}
	 * labeled alternative in {@link boundParser#exprexprexprexprexprexprexprexprexprfunctionsfunctionsfunctionsfunctionsfunctionsfunctionsfunctions}.
	 * @param ctx the parse tree
	 */
	void enterValues(boundParser.ValuesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code values}
	 * labeled alternative in {@link boundParser#exprexprexprexprexprexprexprexprexprfunctionsfunctionsfunctionsfunctionsfunctionsfunctionsfunctions}.
	 * @param ctx the parse tree
	 */
	void exitValues(boundParser.ValuesContext ctx);
	/**
	 * Enter a parse tree produced by {@link boundParser#bound_coefs}.
	 * @param ctx the parse tree
	 */
	void enterBound_coefs(boundParser.Bound_coefsContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#bound_coefs}.
	 * @param ctx the parse tree
	 */
	void exitBound_coefs(boundParser.Bound_coefsContext ctx);
	/**
	 * Enter a parse tree produced by {@link boundParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(boundParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(boundParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(boundParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(boundParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariable(boundParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariable(boundParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Number}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNumber(boundParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Number}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNumber(boundParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(boundParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(boundParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArrayDef}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterArrayDef(boundParser.ArrayDefContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArrayDef}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitArrayDef(boundParser.ArrayDefContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Constant}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterConstant(boundParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Constant}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitConstant(boundParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(boundParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionCall}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(boundParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by the {@code PowerOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterPowerOp(boundParser.PowerOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code PowerOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitPowerOp(boundParser.PowerOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(boundParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link boundParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(boundParser.BinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link boundParser#array}.
	 * @param ctx the parse tree
	 */
	void enterArray(boundParser.ArrayContext ctx);
	/**
	 * Exit a parse tree produced by {@link boundParser#array}.
	 * @param ctx the parse tree
	 */
	void exitArray(boundParser.ArrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code pares}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterPares(boundParser.ParesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code pares}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitPares(boundParser.ParesContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Natlog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterNatlog(boundParser.NatlogContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Natlog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitNatlog(boundParser.NatlogContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Declog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterDeclog(boundParser.DeclogContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Declog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitDeclog(boundParser.DeclogContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Baselog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterBaselog(boundParser.BaselogContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Baselog}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitBaselog(boundParser.BaselogContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Exponent}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterExponent(boundParser.ExponentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Exponent}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitExponent(boundParser.ExponentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Squareroot}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterSquareroot(boundParser.SquarerootContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Squareroot}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitSquareroot(boundParser.SquarerootContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Sumproduct}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void enterSumproduct(boundParser.SumproductContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Sumproduct}
	 * labeled alternative in {@link boundParser#functions}.
	 * @param ctx the parse tree
	 */
	void exitSumproduct(boundParser.SumproductContext ctx);
}