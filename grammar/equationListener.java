// Generated from equation.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link equationParser}.
 */
public interface equationListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link equationParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(equationParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link equationParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(equationParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(equationParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(equationParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(equationParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(equationParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(equationParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Literal}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(equationParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SumProduct}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSumProduct(equationParser.SumProductContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SumProduct}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSumProduct(equationParser.SumProductContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(equationParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link equationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(equationParser.BinaryOpContext ctx);
}