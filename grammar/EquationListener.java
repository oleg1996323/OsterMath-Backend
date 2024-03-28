// Generated from Equation.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link EquationParser}.
 */
public interface EquationListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link EquationParser#main}.
	 * @param ctx the parse tree
	 */
	void enterMain(EquationParser.MainContext ctx);
	/**
	 * Exit a parse tree produced by {@link EquationParser#main}.
	 * @param ctx the parse tree
	 */
	void exitMain(EquationParser.MainContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOp(EquationParser.UnaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryOp}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOp(EquationParser.UnaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParens(EquationParser.ParensContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parens}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParens(EquationParser.ParensContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ValueDef}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterValueDef(EquationParser.ValueDefContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ValueDef}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitValueDef(EquationParser.ValueDefContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterBinaryOp(EquationParser.BinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BinaryOp}
	 * labeled alternative in {@link EquationParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitBinaryOp(EquationParser.BinaryOpContext ctx);
}