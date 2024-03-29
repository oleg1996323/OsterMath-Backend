// Generated from bound.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class boundParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, SUMPRODUCT=6, LN=7, LG=8, LOG_X=9, 
		EXP=10, SQRT=11, ADD=12, SUB=13, MUL=14, DIV=15, POW=16, STRING=17, VARIABLE=18, 
		VARIABLE_RANGE=19, WS=20, EOL=21, NUMBER=22, CONSTANTS=23, PI=24;
	public static final int
		RULE_file = 0, RULE_eq = 1, RULE_hdr = 2, RULE_values = 3, RULE_bound_coefs = 4, 
		RULE_main = 5, RULE_expr = 6, RULE_array = 7, RULE_functions = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "eq", "hdr", "values", "bound_coefs", "main", "expr", "array", 
			"functions"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'['", "','", "']'", "'sumproduct'", "'Ln'", "'Lg'", 
			"'Log'", "'Exp'", "'Sqrt'", "'+'", "'-'", "'*'", "'/'", "'^'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, "SUMPRODUCT", "LN", "LG", "LOG_X", 
			"EXP", "SQRT", "ADD", "SUB", "MUL", "DIV", "POW", "STRING", "VARIABLE", 
			"VARIABLE_RANGE", "WS", "EOL", "NUMBER", "CONSTANTS", "PI"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "bound.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public boundParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FileContext extends ParserRuleContext {
		public EqContext eq() {
			return getRuleContext(EqContext.class,0);
		}
		public TerminalNode EOL() { return getToken(boundParser.EOL, 0); }
		public Bound_coefsContext bound_coefs() {
			return getRuleContext(Bound_coefsContext.class,0);
		}
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitFile(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			eq();
			setState(19);
			match(EOL);
			setState(20);
			bound_coefs();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EqContext extends ParserRuleContext {
		public List<TerminalNode> VARIABLE() { return getTokens(boundParser.VARIABLE); }
		public TerminalNode VARIABLE(int i) {
			return getToken(boundParser.VARIABLE, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> EOL() { return getTokens(boundParser.EOL); }
		public TerminalNode EOL(int i) {
			return getToken(boundParser.EOL, i);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public EqContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_eq; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterEq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitEq(this);
		}
	}

	public final EqContext eq() throws RecognitionException {
		EqContext _localctx = new EqContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_eq);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(29); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(22);
				match(VARIABLE);
				setState(24);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(23);
					match(WS);
					}
				}

				setState(26);
				expr(0);
				setState(27);
				match(EOL);
				}
				}
				setState(31); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==VARIABLE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class HdrContext extends ParserRuleContext {
		public List<TerminalNode> VARIABLE() { return getTokens(boundParser.VARIABLE); }
		public TerminalNode VARIABLE(int i) {
			return getToken(boundParser.VARIABLE, i);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public HdrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_hdr; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterHdr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitHdr(this);
		}
	}

	public final HdrContext hdr() throws RecognitionException {
		HdrContext _localctx = new HdrContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_hdr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(33);
				match(VARIABLE);
				setState(35);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(34);
					match(WS);
					}
				}

				}
				}
				setState(39); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==VARIABLE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValuesContext extends ParserRuleContext {
		public List<TerminalNode> VARIABLE() { return getTokens(boundParser.VARIABLE); }
		public TerminalNode VARIABLE(int i) {
			return getToken(boundParser.VARIABLE, i);
		}
		public List<TerminalNode> EOL() { return getTokens(boundParser.EOL); }
		public TerminalNode EOL(int i) {
			return getToken(boundParser.EOL, i);
		}
		public List<TerminalNode> EOF() { return getTokens(boundParser.EOF); }
		public TerminalNode EOF(int i) {
			return getToken(boundParser.EOF, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public ValuesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_values; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterValues(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitValues(this);
		}
	}

	public final ValuesContext values() throws RecognitionException {
		ValuesContext _localctx = new ValuesContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_values);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(57); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(41);
				match(VARIABLE);
				setState(42);
				match(EOL);
				setState(53); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(47); 
						_errHandler.sync(this);
						_la = _input.LA(1);
						do {
							{
							{
							setState(43);
							expr(0);
							setState(45);
							_errHandler.sync(this);
							_la = _input.LA(1);
							if (_la==WS) {
								{
								setState(44);
								match(WS);
								}
							}

							}
							}
							setState(49); 
							_errHandler.sync(this);
							_la = _input.LA(1);
						} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 12861386L) != 0) );
						setState(51);
						_la = _input.LA(1);
						if ( !(_la==EOF || _la==EOL) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(55); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				}
				setState(59); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==VARIABLE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Bound_coefsContext extends ParserRuleContext {
		public HdrContext hdr() {
			return getRuleContext(HdrContext.class,0);
		}
		public TerminalNode EOL() { return getToken(boundParser.EOL, 0); }
		public ValuesContext values() {
			return getRuleContext(ValuesContext.class,0);
		}
		public Bound_coefsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bound_coefs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterBound_coefs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitBound_coefs(this);
		}
	}

	public final Bound_coefsContext bound_coefs() throws RecognitionException {
		Bound_coefsContext _localctx = new Bound_coefsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_bound_coefs);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			hdr();
			setState(62);
			match(EOL);
			setState(63);
			values();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MainContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode EOF() { return getToken(boundParser.EOF, 0); }
		public MainContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_main; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterMain(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitMain(this);
		}
	}

	public final MainContext main() throws RecognitionException {
		MainContext _localctx = new MainContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_main);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(65);
			expr(0);
			setState(66);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnaryOpContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode ADD() { return getToken(boundParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(boundParser.SUB, 0); }
		public UnaryOpContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterUnaryOp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitUnaryOp(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ExprContext {
		public TerminalNode VARIABLE() { return getToken(boundParser.VARIABLE, 0); }
		public VariableContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitVariable(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NumberContext extends ExprContext {
		public TerminalNode NUMBER() { return getToken(boundParser.NUMBER, 0); }
		public NumberContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitNumber(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParensContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParensContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterParens(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitParens(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayDefContext extends ExprContext {
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ArrayDefContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterArrayDef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitArrayDef(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstantContext extends ExprContext {
		public TerminalNode CONSTANTS() { return getToken(boundParser.CONSTANTS, 0); }
		public ConstantContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitConstant(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionCallContext extends ExprContext {
		public FunctionsContext functions() {
			return getRuleContext(FunctionsContext.class,0);
		}
		public FunctionCallContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterFunctionCall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitFunctionCall(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PowerOpContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode POW() { return getToken(boundParser.POW, 0); }
		public PowerOpContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterPowerOp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitPowerOp(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BinaryOpContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(boundParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(boundParser.DIV, 0); }
		public TerminalNode ADD() { return getToken(boundParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(boundParser.SUB, 0); }
		public BinaryOpContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterBinaryOp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitBinaryOp(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				{
				_localctx = new ParensContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(69);
				match(T__0);
				setState(70);
				expr(0);
				setState(71);
				match(T__1);
				}
				break;
			case 2:
				{
				_localctx = new UnaryOpContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(73);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(74);
				expr(9);
				}
				break;
			case 3:
				{
				_localctx = new FunctionCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(75);
				functions();
				}
				break;
			case 4:
				{
				_localctx = new ArrayDefContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(76);
				array();
				}
				break;
			case 5:
				{
				_localctx = new VariableContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(77);
				match(VARIABLE);
				}
				break;
			case 6:
				{
				_localctx = new NumberContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(78);
				match(NUMBER);
				}
				break;
			case 7:
				{
				_localctx = new ConstantContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(79);
				match(CONSTANTS);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(93);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(91);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(82);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(83);
						_la = _input.LA(1);
						if ( !(_la==MUL || _la==DIV) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(84);
						expr(9);
						}
						break;
					case 2:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(85);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(86);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(87);
						expr(8);
						}
						break;
					case 3:
						{
						_localctx = new PowerOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(88);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(89);
						match(POW);
						setState(90);
						expr(7);
						}
						break;
					}
					} 
				}
				setState(95);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayContext extends ParserRuleContext {
		public List<TerminalNode> VARIABLE() { return getTokens(boundParser.VARIABLE); }
		public TerminalNode VARIABLE(int i) {
			return getToken(boundParser.VARIABLE, i);
		}
		public List<TerminalNode> NUMBER() { return getTokens(boundParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(boundParser.NUMBER, i);
		}
		public List<TerminalNode> CONSTANTS() { return getTokens(boundParser.CONSTANTS); }
		public TerminalNode CONSTANTS(int i) {
			return getToken(boundParser.CONSTANTS, i);
		}
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterArray(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitArray(this);
		}
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_array);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			match(T__2);
			setState(97);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 12845056L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(102); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(102);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__3:
					{
					setState(98);
					match(T__3);
					setState(99);
					match(VARIABLE);
					}
					break;
				case NUMBER:
					{
					setState(100);
					match(NUMBER);
					}
					break;
				case CONSTANTS:
					{
					setState(101);
					match(CONSTANTS);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(104); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 12582928L) != 0) );
			setState(106);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FunctionsContext extends ParserRuleContext {
		public FunctionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functions; }
	 
		public FunctionsContext() { }
		public void copyFrom(FunctionsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SumproductContext extends FunctionsContext {
		public TerminalNode SUMPRODUCT() { return getToken(boundParser.SUMPRODUCT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public SumproductContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterSumproduct(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitSumproduct(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NatlogContext extends FunctionsContext {
		public TerminalNode LN() { return getToken(boundParser.LN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public NatlogContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterNatlog(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitNatlog(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExponentContext extends FunctionsContext {
		public TerminalNode EXP() { return getToken(boundParser.EXP, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public ExponentContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterExponent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitExponent(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclogContext extends FunctionsContext {
		public TerminalNode LG() { return getToken(boundParser.LG, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public DeclogContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterDeclog(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitDeclog(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BaselogContext extends FunctionsContext {
		public TerminalNode LOG_X() { return getToken(boundParser.LOG_X, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public BaselogContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterBaselog(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitBaselog(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParesContext extends FunctionsContext {
		public FunctionsContext functions() {
			return getRuleContext(FunctionsContext.class,0);
		}
		public ParesContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterPares(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitPares(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SquarerootContext extends FunctionsContext {
		public TerminalNode SQRT() { return getToken(boundParser.SQRT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(boundParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(boundParser.WS, i);
		}
		public SquarerootContext(FunctionsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).enterSquareroot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof boundListener ) ((boundListener)listener).exitSquareroot(this);
		}
	}

	public final FunctionsContext functions() throws RecognitionException {
		FunctionsContext _localctx = new FunctionsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_functions);
		int _la;
		try {
			setState(189);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				_localctx = new ParesContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(108);
				match(T__0);
				setState(109);
				functions();
				setState(110);
				match(T__1);
				}
				break;
			case LN:
				_localctx = new NatlogContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				match(LN);
				setState(113);
				match(T__0);
				setState(115);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(114);
					match(WS);
					}
				}

				setState(117);
				expr(0);
				setState(119);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(118);
					match(WS);
					}
				}

				setState(121);
				match(T__1);
				}
				break;
			case LG:
				_localctx = new DeclogContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(123);
				match(LG);
				setState(124);
				match(T__0);
				setState(126);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(125);
					match(WS);
					}
				}

				setState(128);
				expr(0);
				setState(130);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(129);
					match(WS);
					}
				}

				setState(132);
				match(T__1);
				}
				break;
			case LOG_X:
				_localctx = new BaselogContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(134);
				match(LOG_X);
				setState(135);
				match(T__0);
				setState(137);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(136);
					match(WS);
					}
				}

				setState(139);
				expr(0);
				setState(141);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(140);
					match(WS);
					}
				}

				setState(143);
				match(T__3);
				setState(145);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(144);
					match(WS);
					}
				}

				setState(147);
				expr(0);
				setState(149);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(148);
					match(WS);
					}
				}

				setState(151);
				match(T__1);
				}
				break;
			case EXP:
				_localctx = new ExponentContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(153);
				match(EXP);
				setState(154);
				match(T__0);
				setState(156);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(155);
					match(WS);
					}
				}

				setState(158);
				expr(0);
				setState(160);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(159);
					match(WS);
					}
				}

				setState(162);
				match(T__1);
				}
				break;
			case SQRT:
				_localctx = new SquarerootContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(164);
				match(SQRT);
				setState(165);
				match(T__0);
				setState(167);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(166);
					match(WS);
					}
				}

				setState(169);
				expr(0);
				setState(171);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(170);
					match(WS);
					}
				}

				setState(173);
				match(T__1);
				}
				break;
			case SUMPRODUCT:
				_localctx = new SumproductContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(175);
				match(SUMPRODUCT);
				setState(176);
				match(T__0);
				setState(177);
				expr(0);
				setState(178);
				match(T__3);
				setState(179);
				expr(0);
				setState(184);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(180);
					match(T__3);
					setState(181);
					expr(0);
					}
					}
					setState(186);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(187);
				match(T__1);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 8);
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0018\u00c0\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0001\u0001\u0001\u0003\u0001\u0019\b\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0004\u0001\u001e\b\u0001\u000b\u0001\f\u0001\u001f\u0001\u0002"+
		"\u0001\u0002\u0003\u0002$\b\u0002\u0004\u0002&\b\u0002\u000b\u0002\f\u0002"+
		"\'\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003.\b\u0003"+
		"\u0004\u00030\b\u0003\u000b\u0003\f\u00031\u0001\u0003\u0001\u0003\u0004"+
		"\u00036\b\u0003\u000b\u0003\f\u00037\u0004\u0003:\b\u0003\u000b\u0003"+
		"\f\u0003;\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0003\u0006Q\b\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0005\u0006\\\b\u0006\n\u0006\f\u0006_\t\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0004\u0007"+
		"g\b\u0007\u000b\u0007\f\u0007h\u0001\u0007\u0001\u0007\u0001\b\u0001\b"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\bt\b\b\u0001\b\u0001\b"+
		"\u0003\bx\b\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u007f\b"+
		"\b\u0001\b\u0001\b\u0003\b\u0083\b\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0003\b\u008a\b\b\u0001\b\u0001\b\u0003\b\u008e\b\b\u0001\b\u0001\b"+
		"\u0003\b\u0092\b\b\u0001\b\u0001\b\u0003\b\u0096\b\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0003\b\u009d\b\b\u0001\b\u0001\b\u0003\b\u00a1\b\b"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u00a8\b\b\u0001\b\u0001"+
		"\b\u0003\b\u00ac\b\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0005\b\u00b7\b\b\n\b\f\b\u00ba\t\b\u0001\b\u0001\b"+
		"\u0003\b\u00be\b\b\u0001\b\u0000\u0001\f\t\u0000\u0002\u0004\u0006\b\n"+
		"\f\u000e\u0010\u0000\u0004\u0001\u0001\u0015\u0015\u0001\u0000\f\r\u0001"+
		"\u0000\u000e\u000f\u0002\u0000\u0012\u0012\u0016\u0017\u00dd\u0000\u0012"+
		"\u0001\u0000\u0000\u0000\u0002\u001d\u0001\u0000\u0000\u0000\u0004%\u0001"+
		"\u0000\u0000\u0000\u00069\u0001\u0000\u0000\u0000\b=\u0001\u0000\u0000"+
		"\u0000\nA\u0001\u0000\u0000\u0000\fP\u0001\u0000\u0000\u0000\u000e`\u0001"+
		"\u0000\u0000\u0000\u0010\u00bd\u0001\u0000\u0000\u0000\u0012\u0013\u0003"+
		"\u0002\u0001\u0000\u0013\u0014\u0005\u0015\u0000\u0000\u0014\u0015\u0003"+
		"\b\u0004\u0000\u0015\u0001\u0001\u0000\u0000\u0000\u0016\u0018\u0005\u0012"+
		"\u0000\u0000\u0017\u0019\u0005\u0014\u0000\u0000\u0018\u0017\u0001\u0000"+
		"\u0000\u0000\u0018\u0019\u0001\u0000\u0000\u0000\u0019\u001a\u0001\u0000"+
		"\u0000\u0000\u001a\u001b\u0003\f\u0006\u0000\u001b\u001c\u0005\u0015\u0000"+
		"\u0000\u001c\u001e\u0001\u0000\u0000\u0000\u001d\u0016\u0001\u0000\u0000"+
		"\u0000\u001e\u001f\u0001\u0000\u0000\u0000\u001f\u001d\u0001\u0000\u0000"+
		"\u0000\u001f \u0001\u0000\u0000\u0000 \u0003\u0001\u0000\u0000\u0000!"+
		"#\u0005\u0012\u0000\u0000\"$\u0005\u0014\u0000\u0000#\"\u0001\u0000\u0000"+
		"\u0000#$\u0001\u0000\u0000\u0000$&\u0001\u0000\u0000\u0000%!\u0001\u0000"+
		"\u0000\u0000&\'\u0001\u0000\u0000\u0000\'%\u0001\u0000\u0000\u0000\'("+
		"\u0001\u0000\u0000\u0000(\u0005\u0001\u0000\u0000\u0000)*\u0005\u0012"+
		"\u0000\u0000*5\u0005\u0015\u0000\u0000+-\u0003\f\u0006\u0000,.\u0005\u0014"+
		"\u0000\u0000-,\u0001\u0000\u0000\u0000-.\u0001\u0000\u0000\u0000.0\u0001"+
		"\u0000\u0000\u0000/+\u0001\u0000\u0000\u000001\u0001\u0000\u0000\u0000"+
		"1/\u0001\u0000\u0000\u000012\u0001\u0000\u0000\u000023\u0001\u0000\u0000"+
		"\u000034\u0007\u0000\u0000\u000046\u0001\u0000\u0000\u00005/\u0001\u0000"+
		"\u0000\u000067\u0001\u0000\u0000\u000075\u0001\u0000\u0000\u000078\u0001"+
		"\u0000\u0000\u00008:\u0001\u0000\u0000\u00009)\u0001\u0000\u0000\u0000"+
		":;\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000\u0000;<\u0001\u0000\u0000"+
		"\u0000<\u0007\u0001\u0000\u0000\u0000=>\u0003\u0004\u0002\u0000>?\u0005"+
		"\u0015\u0000\u0000?@\u0003\u0006\u0003\u0000@\t\u0001\u0000\u0000\u0000"+
		"AB\u0003\f\u0006\u0000BC\u0005\u0000\u0000\u0001C\u000b\u0001\u0000\u0000"+
		"\u0000DE\u0006\u0006\uffff\uffff\u0000EF\u0005\u0001\u0000\u0000FG\u0003"+
		"\f\u0006\u0000GH\u0005\u0002\u0000\u0000HQ\u0001\u0000\u0000\u0000IJ\u0007"+
		"\u0001\u0000\u0000JQ\u0003\f\u0006\tKQ\u0003\u0010\b\u0000LQ\u0003\u000e"+
		"\u0007\u0000MQ\u0005\u0012\u0000\u0000NQ\u0005\u0016\u0000\u0000OQ\u0005"+
		"\u0017\u0000\u0000PD\u0001\u0000\u0000\u0000PI\u0001\u0000\u0000\u0000"+
		"PK\u0001\u0000\u0000\u0000PL\u0001\u0000\u0000\u0000PM\u0001\u0000\u0000"+
		"\u0000PN\u0001\u0000\u0000\u0000PO\u0001\u0000\u0000\u0000Q]\u0001\u0000"+
		"\u0000\u0000RS\n\b\u0000\u0000ST\u0007\u0002\u0000\u0000T\\\u0003\f\u0006"+
		"\tUV\n\u0007\u0000\u0000VW\u0007\u0001\u0000\u0000W\\\u0003\f\u0006\b"+
		"XY\n\u0006\u0000\u0000YZ\u0005\u0010\u0000\u0000Z\\\u0003\f\u0006\u0007"+
		"[R\u0001\u0000\u0000\u0000[U\u0001\u0000\u0000\u0000[X\u0001\u0000\u0000"+
		"\u0000\\_\u0001\u0000\u0000\u0000][\u0001\u0000\u0000\u0000]^\u0001\u0000"+
		"\u0000\u0000^\r\u0001\u0000\u0000\u0000_]\u0001\u0000\u0000\u0000`a\u0005"+
		"\u0003\u0000\u0000af\u0007\u0003\u0000\u0000bc\u0005\u0004\u0000\u0000"+
		"cg\u0005\u0012\u0000\u0000dg\u0005\u0016\u0000\u0000eg\u0005\u0017\u0000"+
		"\u0000fb\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000fe\u0001\u0000"+
		"\u0000\u0000gh\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000\u0000hi\u0001"+
		"\u0000\u0000\u0000ij\u0001\u0000\u0000\u0000jk\u0005\u0005\u0000\u0000"+
		"k\u000f\u0001\u0000\u0000\u0000lm\u0005\u0001\u0000\u0000mn\u0003\u0010"+
		"\b\u0000no\u0005\u0002\u0000\u0000o\u00be\u0001\u0000\u0000\u0000pq\u0005"+
		"\u0007\u0000\u0000qs\u0005\u0001\u0000\u0000rt\u0005\u0014\u0000\u0000"+
		"sr\u0001\u0000\u0000\u0000st\u0001\u0000\u0000\u0000tu\u0001\u0000\u0000"+
		"\u0000uw\u0003\f\u0006\u0000vx\u0005\u0014\u0000\u0000wv\u0001\u0000\u0000"+
		"\u0000wx\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000yz\u0005\u0002"+
		"\u0000\u0000z\u00be\u0001\u0000\u0000\u0000{|\u0005\b\u0000\u0000|~\u0005"+
		"\u0001\u0000\u0000}\u007f\u0005\u0014\u0000\u0000~}\u0001\u0000\u0000"+
		"\u0000~\u007f\u0001\u0000\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000"+
		"\u0080\u0082\u0003\f\u0006\u0000\u0081\u0083\u0005\u0014\u0000\u0000\u0082"+
		"\u0081\u0001\u0000\u0000\u0000\u0082\u0083\u0001\u0000\u0000\u0000\u0083"+
		"\u0084\u0001\u0000\u0000\u0000\u0084\u0085\u0005\u0002\u0000\u0000\u0085"+
		"\u00be\u0001\u0000\u0000\u0000\u0086\u0087\u0005\t\u0000\u0000\u0087\u0089"+
		"\u0005\u0001\u0000\u0000\u0088\u008a\u0005\u0014\u0000\u0000\u0089\u0088"+
		"\u0001\u0000\u0000\u0000\u0089\u008a\u0001\u0000\u0000\u0000\u008a\u008b"+
		"\u0001\u0000\u0000\u0000\u008b\u008d\u0003\f\u0006\u0000\u008c\u008e\u0005"+
		"\u0014\u0000\u0000\u008d\u008c\u0001\u0000\u0000\u0000\u008d\u008e\u0001"+
		"\u0000\u0000\u0000\u008e\u008f\u0001\u0000\u0000\u0000\u008f\u0091\u0005"+
		"\u0004\u0000\u0000\u0090\u0092\u0005\u0014\u0000\u0000\u0091\u0090\u0001"+
		"\u0000\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u0093\u0001"+
		"\u0000\u0000\u0000\u0093\u0095\u0003\f\u0006\u0000\u0094\u0096\u0005\u0014"+
		"\u0000\u0000\u0095\u0094\u0001\u0000\u0000\u0000\u0095\u0096\u0001\u0000"+
		"\u0000\u0000\u0096\u0097\u0001\u0000\u0000\u0000\u0097\u0098\u0005\u0002"+
		"\u0000\u0000\u0098\u00be\u0001\u0000\u0000\u0000\u0099\u009a\u0005\n\u0000"+
		"\u0000\u009a\u009c\u0005\u0001\u0000\u0000\u009b\u009d\u0005\u0014\u0000"+
		"\u0000\u009c\u009b\u0001\u0000\u0000\u0000\u009c\u009d\u0001\u0000\u0000"+
		"\u0000\u009d\u009e\u0001\u0000\u0000\u0000\u009e\u00a0\u0003\f\u0006\u0000"+
		"\u009f\u00a1\u0005\u0014\u0000\u0000\u00a0\u009f\u0001\u0000\u0000\u0000"+
		"\u00a0\u00a1\u0001\u0000\u0000\u0000\u00a1\u00a2\u0001\u0000\u0000\u0000"+
		"\u00a2\u00a3\u0005\u0002\u0000\u0000\u00a3\u00be\u0001\u0000\u0000\u0000"+
		"\u00a4\u00a5\u0005\u000b\u0000\u0000\u00a5\u00a7\u0005\u0001\u0000\u0000"+
		"\u00a6\u00a8\u0005\u0014\u0000\u0000\u00a7\u00a6\u0001\u0000\u0000\u0000"+
		"\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8\u00a9\u0001\u0000\u0000\u0000"+
		"\u00a9\u00ab\u0003\f\u0006\u0000\u00aa\u00ac\u0005\u0014\u0000\u0000\u00ab"+
		"\u00aa\u0001\u0000\u0000\u0000\u00ab\u00ac\u0001\u0000\u0000\u0000\u00ac"+
		"\u00ad\u0001\u0000\u0000\u0000\u00ad\u00ae\u0005\u0002\u0000\u0000\u00ae"+
		"\u00be\u0001\u0000\u0000\u0000\u00af\u00b0\u0005\u0006\u0000\u0000\u00b0"+
		"\u00b1\u0005\u0001\u0000\u0000\u00b1\u00b2\u0003\f\u0006\u0000\u00b2\u00b3"+
		"\u0005\u0004\u0000\u0000\u00b3\u00b8\u0003\f\u0006\u0000\u00b4\u00b5\u0005"+
		"\u0004\u0000\u0000\u00b5\u00b7\u0003\f\u0006\u0000\u00b6\u00b4\u0001\u0000"+
		"\u0000\u0000\u00b7\u00ba\u0001\u0000\u0000\u0000\u00b8\u00b6\u0001\u0000"+
		"\u0000\u0000\u00b8\u00b9\u0001\u0000\u0000\u0000\u00b9\u00bb\u0001\u0000"+
		"\u0000\u0000\u00ba\u00b8\u0001\u0000\u0000\u0000\u00bb\u00bc\u0005\u0002"+
		"\u0000\u0000\u00bc\u00be\u0001\u0000\u0000\u0000\u00bdl\u0001\u0000\u0000"+
		"\u0000\u00bdp\u0001\u0000\u0000\u0000\u00bd{\u0001\u0000\u0000\u0000\u00bd"+
		"\u0086\u0001\u0000\u0000\u0000\u00bd\u0099\u0001\u0000\u0000\u0000\u00bd"+
		"\u00a4\u0001\u0000\u0000\u0000\u00bd\u00af\u0001\u0000\u0000\u0000\u00be"+
		"\u0011\u0001\u0000\u0000\u0000\u001b\u0018\u001f#\'-17;P[]fhsw~\u0082"+
		"\u0089\u008d\u0091\u0095\u009c\u00a0\u00a7\u00ab\u00b8\u00bd";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}