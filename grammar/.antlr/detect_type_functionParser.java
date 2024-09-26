// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class detect_type_functionParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, VARIABLE=8, DATABASE=9, 
		LARGER=10, LARGER_EQUAL=11, EQUAL=12, LESS=13, LESS_EQUAL=14, SUMPRODUCT=15, 
		SUMPRODUCT_I=16, SUM=17, SUM_I=18, PRODUCT=19, PRODUCT_I=20, LN=21, LG=22, 
		LOG_X=23, EXP=24, SQRT=25, PI=26, COS=27, SIN=28, ASIN=29, ACOS=30, FACTORIAL=31, 
		STRING=32, WS=33, EOL=34, UINT=35, ADD=36, SUB=37, MUL=38, DIV=39, POW=40, 
		QUOTE=41, ASTERISK=42, EXPONENT=43, FLOAT=44, ID_NUMBER=45;
	public static final int
		RULE_value_type = 0, RULE_line_input = 1, RULE_node_access = 2, RULE_variable = 3, 
		RULE_expr = 4, RULE_array = 5, RULE_number = 6, RULE_constant = 7, RULE_function = 8, 
		RULE_multiargfunction = 9, RULE_rangefunction = 10, RULE_string = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"value_type", "line_input", "node_access", "variable", "expr", "array", 
			"number", "constant", "function", "multiargfunction", "rangefunction", 
			"string"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "';'", "'VAR('", "'['", "']'", "'\"'", null, null, 
			"'>'", null, "'='", null, "'<'", null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "'+'", "'-'", "'*'", "'/'", "'^'", "'''"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "VARIABLE", "DATABASE", 
			"LARGER", "LARGER_EQUAL", "EQUAL", "LESS", "LESS_EQUAL", "SUMPRODUCT", 
			"SUMPRODUCT_I", "SUM", "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", "LOG_X", 
			"EXP", "SQRT", "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", "STRING", 
			"WS", "EOL", "UINT", "ADD", "SUB", "MUL", "DIV", "POW", "QUOTE", "ASTERISK", 
			"EXPONENT", "FLOAT", "ID_NUMBER"
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
	public String getGrammarFileName() { return "detect_type_function.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public detect_type_functionParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Value_typeContext extends ParserRuleContext {
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public Value_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value_type; }
	}

	public final Value_typeContext value_type() throws RecognitionException {
		Value_typeContext _localctx = new Value_typeContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_value_type);
		try {
			setState(27);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(24);
				array();
				}
				break;
			case T__0:
			case T__3:
			case VARIABLE:
			case SUMPRODUCT:
			case SUM:
			case SUM_I:
			case PRODUCT:
			case PRODUCT_I:
			case LN:
			case LG:
			case LOG_X:
			case EXP:
			case SQRT:
			case PI:
			case COS:
			case SIN:
			case ASIN:
			case ACOS:
			case FACTORIAL:
			case WS:
			case UINT:
			case ADD:
			case SUB:
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(25);
				expr(0);
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 3);
				{
				setState(26);
				string();
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

	@SuppressWarnings("CheckReturnValue")
	public static class Line_inputContext extends ParserRuleContext {
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Line_inputContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line_input; }
	}

	public final Line_inputContext line_input() throws RecognitionException {
		Line_inputContext _localctx = new Line_inputContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_line_input);
		try {
			setState(31);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(29);
				array();
				}
				break;
			case T__0:
			case T__3:
			case VARIABLE:
			case SUMPRODUCT:
			case SUM:
			case SUM_I:
			case PRODUCT:
			case PRODUCT_I:
			case LN:
			case LG:
			case LOG_X:
			case EXP:
			case SQRT:
			case PI:
			case COS:
			case SIN:
			case ASIN:
			case ACOS:
			case FACTORIAL:
			case WS:
			case UINT:
			case ADD:
			case SUB:
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(30);
				expr(0);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Node_accessContext extends ParserRuleContext {
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public List<TerminalNode> UINT() { return getTokens(detect_type_functionParser.UINT); }
		public TerminalNode UINT(int i) {
			return getToken(detect_type_functionParser.UINT, i);
		}
		public Node_accessContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_node_access; }
	}

	public final Node_accessContext node_access() throws RecognitionException {
		Node_accessContext _localctx = new Node_accessContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_node_access);
		int _la;
		try {
			int _alt;
			setState(103);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(33);
					match(WS);
					}
					}
					setState(38);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				{
				setState(39);
				match(T__0);
				setState(43);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(40);
					match(WS);
					}
					}
					setState(45);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(46);
				match(T__1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(47);
				match(T__0);
				setState(51);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(48);
					match(WS);
					}
					}
					setState(53);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(54);
				match(UINT);
				setState(58);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(55);
					match(WS);
					}
					}
					setState(60);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(61);
				match(T__1);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(62);
				match(T__0);
				setState(66);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(63);
					match(WS);
					}
					}
					setState(68);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(69);
				match(UINT);
				setState(73);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(70);
						match(WS);
						}
						} 
					}
					setState(75);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
				}
				setState(86);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(76);
					match(T__2);
					setState(80);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(77);
						match(WS);
						}
						}
						setState(82);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(83);
					match(UINT);
					}
					}
					setState(88);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(92);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(89);
					match(WS);
					}
					}
					setState(94);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(95);
				match(T__1);
				}
				setState(100);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(97);
						match(WS);
						}
						} 
					}
					setState(102);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				}
				}
				break;
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
	public static class VariableContext extends ParserRuleContext {
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public TerminalNode VARIABLE() { return getToken(detect_type_functionParser.VARIABLE, 0); }
		public TerminalNode DATABASE() { return getToken(detect_type_functionParser.DATABASE, 0); }
		public Node_accessContext node_access() {
			return getRuleContext(Node_accessContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_variable);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WS) {
				{
				{
				setState(105);
				match(WS);
				}
				}
				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(149);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				{
				{
				setState(111);
				match(T__3);
				setState(139);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
				case 1:
					{
					setState(115);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(112);
						match(WS);
						}
						}
						setState(117);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(118);
					match(DATABASE);
					setState(119);
					match(VARIABLE);
					setState(123);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(120);
						match(WS);
						}
						}
						setState(125);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				case 2:
					{
					setState(129);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(126);
						match(WS);
						}
						}
						setState(131);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(132);
					match(VARIABLE);
					setState(136);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(133);
						match(WS);
						}
						}
						setState(138);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(141);
				match(T__1);
				setState(143);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(142);
					node_access();
					}
					break;
				}
				}
				}
				break;
			case VARIABLE:
				{
				{
				setState(145);
				match(VARIABLE);
				setState(147);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
				case 1:
					{
					setState(146);
					node_access();
					}
					break;
				}
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(154);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(151);
					match(WS);
					}
					} 
				}
				setState(156);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
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
		public TerminalNode ADD() { return getToken(detect_type_functionParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(detect_type_functionParser.SUB, 0); }
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public UnaryOpContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParensContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParensContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LiteralContext extends ExprContext {
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public LiteralContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionCallContext extends ExprContext {
		public FunctionContext function() {
			return getRuleContext(FunctionContext.class,0);
		}
		public MultiargfunctionContext multiargfunction() {
			return getRuleContext(MultiargfunctionContext.class,0);
		}
		public RangefunctionContext rangefunction() {
			return getRuleContext(RangefunctionContext.class,0);
		}
		public FunctionCallContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VariableInExprContext extends ExprContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public VariableInExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BinaryOpContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode POW() { return getToken(detect_type_functionParser.POW, 0); }
		public TerminalNode MUL() { return getToken(detect_type_functionParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(detect_type_functionParser.DIV, 0); }
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public TerminalNode ADD() { return getToken(detect_type_functionParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(detect_type_functionParser.SUB, 0); }
		public BinaryOpContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(180);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				{
				_localctx = new ParensContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(158);
				match(T__0);
				setState(159);
				expr(0);
				setState(160);
				match(T__1);
				}
				break;
			case 2:
				{
				_localctx = new VariableInExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(162);
				variable();
				}
				break;
			case 3:
				{
				_localctx = new FunctionCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(166);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
				case 1:
					{
					setState(163);
					function();
					}
					break;
				case 2:
					{
					setState(164);
					multiargfunction();
					}
					break;
				case 3:
					{
					setState(165);
					rangefunction();
					}
					break;
				}
				}
				break;
			case 4:
				{
				_localctx = new LiteralContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(170);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case FLOAT:
					{
					setState(168);
					number();
					}
					break;
				case EXP:
				case PI:
					{
					setState(169);
					constant();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 5:
				{
				_localctx = new UnaryOpContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(172);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(176);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(173);
						match(WS);
						}
						} 
					}
					setState(178);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
				}
				setState(179);
				expr(4);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(217);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(215);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
					case 1:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(182);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(183);
						match(POW);
						setState(184);
						expr(4);
						}
						break;
					case 2:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(185);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(189);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==WS) {
							{
							{
							setState(186);
							match(WS);
							}
							}
							setState(191);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(192);
						_la = _input.LA(1);
						if ( !(_la==MUL || _la==DIV) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(196);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(193);
								match(WS);
								}
								} 
							}
							setState(198);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
						}
						setState(199);
						expr(3);
						}
						break;
					case 3:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(200);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(204);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==WS) {
							{
							{
							setState(201);
							match(WS);
							}
							}
							setState(206);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(207);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(211);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(208);
								match(WS);
								}
								} 
							}
							setState(213);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
						}
						setState(214);
						expr(2);
						}
						break;
					}
					} 
				}
				setState(219);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
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
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<ArrayContext> array() {
			return getRuleContexts(ArrayContext.class);
		}
		public ArrayContext array(int i) {
			return getRuleContext(ArrayContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public ArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array; }
	}

	public final ArrayContext array() throws RecognitionException {
		ArrayContext _localctx = new ArrayContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_array);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			match(T__4);
			setState(224);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(221);
					match(WS);
					}
					} 
				}
				setState(226);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			}
			setState(229);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__3:
			case VARIABLE:
			case SUMPRODUCT:
			case SUM:
			case SUM_I:
			case PRODUCT:
			case PRODUCT_I:
			case LN:
			case LG:
			case LOG_X:
			case EXP:
			case SQRT:
			case PI:
			case COS:
			case SIN:
			case ASIN:
			case ACOS:
			case FACTORIAL:
			case WS:
			case UINT:
			case ADD:
			case SUB:
			case FLOAT:
				{
				setState(227);
				expr(0);
				}
				break;
			case T__4:
				{
				setState(228);
				array();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(234);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WS) {
				{
				{
				setState(231);
				match(WS);
				}
				}
				setState(236);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(250);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(237);
				match(T__2);
				setState(241);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(238);
						match(WS);
						}
						} 
					}
					setState(243);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				}
				setState(246);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__3:
				case VARIABLE:
				case SUMPRODUCT:
				case SUM:
				case SUM_I:
				case PRODUCT:
				case PRODUCT_I:
				case LN:
				case LG:
				case LOG_X:
				case EXP:
				case SQRT:
				case PI:
				case COS:
				case SIN:
				case ASIN:
				case ACOS:
				case FACTORIAL:
				case WS:
				case UINT:
				case ADD:
				case SUB:
				case FLOAT:
					{
					setState(244);
					expr(0);
					}
					break;
				case T__4:
					{
					setState(245);
					array();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				}
				setState(252);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(253);
			match(T__5);
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
	public static class NumberContext extends ParserRuleContext {
		public TerminalNode UINT() { return getToken(detect_type_functionParser.UINT, 0); }
		public TerminalNode FLOAT() { return getToken(detect_type_functionParser.FLOAT, 0); }
		public NumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number; }
	}

	public final NumberContext number() throws RecognitionException {
		NumberContext _localctx = new NumberContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(255);
			_la = _input.LA(1);
			if ( !(_la==UINT || _la==FLOAT) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
	public static class ConstantContext extends ParserRuleContext {
		public TerminalNode PI() { return getToken(detect_type_functionParser.PI, 0); }
		public TerminalNode EXP() { return getToken(detect_type_functionParser.EXP, 0); }
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_constant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(257);
			_la = _input.LA(1);
			if ( !(_la==EXP || _la==PI) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
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
	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode LN() { return getToken(detect_type_functionParser.LN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public TerminalNode LG() { return getToken(detect_type_functionParser.LG, 0); }
		public TerminalNode EXP() { return getToken(detect_type_functionParser.EXP, 0); }
		public TerminalNode SQRT() { return getToken(detect_type_functionParser.SQRT, 0); }
		public TerminalNode COS() { return getToken(detect_type_functionParser.COS, 0); }
		public TerminalNode SIN() { return getToken(detect_type_functionParser.SIN, 0); }
		public TerminalNode ACOS() { return getToken(detect_type_functionParser.ACOS, 0); }
		public TerminalNode ASIN() { return getToken(detect_type_functionParser.ASIN, 0); }
		public TerminalNode FACTORIAL() { return getToken(detect_type_functionParser.FACTORIAL, 0); }
		public TerminalNode LOG_X() { return getToken(detect_type_functionParser.LOG_X, 0); }
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_function);
		int _la;
		try {
			int _alt;
			setState(553);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,81,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(262);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(259);
					match(WS);
					}
					}
					setState(264);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(265);
				match(LN);
				setState(266);
				match(T__0);
				setState(270);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,40,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(267);
						match(WS);
						}
						} 
					}
					setState(272);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,40,_ctx);
				}
				setState(273);
				expr(0);
				setState(277);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(274);
					match(WS);
					}
					}
					setState(279);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(280);
				match(T__1);
				setState(284);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,42,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(281);
						match(WS);
						}
						} 
					}
					setState(286);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,42,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(290);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(287);
					match(WS);
					}
					}
					setState(292);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(293);
				match(LG);
				setState(294);
				match(T__0);
				setState(298);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(295);
						match(WS);
						}
						} 
					}
					setState(300);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
				}
				setState(301);
				expr(0);
				setState(305);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(302);
					match(WS);
					}
					}
					setState(307);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(308);
				match(T__1);
				setState(312);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,46,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(309);
						match(WS);
						}
						} 
					}
					setState(314);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,46,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(318);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(315);
					match(WS);
					}
					}
					setState(320);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(321);
				match(EXP);
				setState(322);
				match(T__0);
				setState(326);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,48,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(323);
						match(WS);
						}
						} 
					}
					setState(328);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,48,_ctx);
				}
				setState(329);
				expr(0);
				setState(333);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(330);
					match(WS);
					}
					}
					setState(335);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(336);
				match(T__1);
				setState(340);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,50,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(337);
						match(WS);
						}
						} 
					}
					setState(342);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,50,_ctx);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(346);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(343);
					match(WS);
					}
					}
					setState(348);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(349);
				match(SQRT);
				setState(350);
				match(T__0);
				setState(354);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(351);
						match(WS);
						}
						} 
					}
					setState(356);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
				}
				setState(357);
				expr(0);
				setState(361);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(358);
					match(WS);
					}
					}
					setState(363);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(364);
				match(T__1);
				setState(368);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,54,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(365);
						match(WS);
						}
						} 
					}
					setState(370);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,54,_ctx);
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(374);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(371);
					match(WS);
					}
					}
					setState(376);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(377);
				match(COS);
				setState(378);
				match(T__0);
				setState(382);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,56,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(379);
						match(WS);
						}
						} 
					}
					setState(384);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,56,_ctx);
				}
				setState(385);
				expr(0);
				setState(389);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(386);
					match(WS);
					}
					}
					setState(391);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(392);
				match(T__1);
				setState(396);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(393);
						match(WS);
						}
						} 
					}
					setState(398);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
				}
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(402);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(399);
					match(WS);
					}
					}
					setState(404);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(405);
				match(SIN);
				setState(406);
				match(T__0);
				setState(410);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,60,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(407);
						match(WS);
						}
						} 
					}
					setState(412);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,60,_ctx);
				}
				setState(413);
				expr(0);
				setState(417);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(414);
					match(WS);
					}
					}
					setState(419);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(420);
				match(T__1);
				setState(424);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,62,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(421);
						match(WS);
						}
						} 
					}
					setState(426);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,62,_ctx);
				}
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(430);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(427);
					match(WS);
					}
					}
					setState(432);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(433);
				match(ACOS);
				setState(434);
				match(T__0);
				setState(438);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,64,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(435);
						match(WS);
						}
						} 
					}
					setState(440);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,64,_ctx);
				}
				setState(441);
				expr(0);
				setState(445);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(442);
					match(WS);
					}
					}
					setState(447);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(448);
				match(T__1);
				setState(452);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,66,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(449);
						match(WS);
						}
						} 
					}
					setState(454);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,66,_ctx);
				}
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(458);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(455);
					match(WS);
					}
					}
					setState(460);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(461);
				match(ASIN);
				setState(462);
				match(T__0);
				setState(466);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(463);
						match(WS);
						}
						} 
					}
					setState(468);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
				}
				setState(469);
				expr(0);
				setState(473);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(470);
					match(WS);
					}
					}
					setState(475);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(476);
				match(T__1);
				setState(480);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,70,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(477);
						match(WS);
						}
						} 
					}
					setState(482);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,70,_ctx);
				}
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(486);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(483);
					match(WS);
					}
					}
					setState(488);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(489);
				match(FACTORIAL);
				setState(490);
				match(T__0);
				setState(494);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,72,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(491);
						match(WS);
						}
						} 
					}
					setState(496);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,72,_ctx);
				}
				setState(497);
				expr(0);
				setState(501);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(498);
					match(WS);
					}
					}
					setState(503);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(504);
				match(T__1);
				setState(508);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,74,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(505);
						match(WS);
						}
						} 
					}
					setState(510);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,74,_ctx);
				}
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(514);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(511);
					match(WS);
					}
					}
					setState(516);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(517);
				match(LOG_X);
				setState(518);
				match(T__0);
				setState(522);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(519);
						match(WS);
						}
						} 
					}
					setState(524);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
				}
				setState(525);
				expr(0);
				setState(529);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(526);
					match(WS);
					}
					}
					setState(531);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(532);
				match(T__2);
				setState(536);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,78,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(533);
						match(WS);
						}
						} 
					}
					setState(538);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,78,_ctx);
				}
				setState(539);
				expr(0);
				setState(543);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(540);
					match(WS);
					}
					}
					setState(545);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(546);
				match(T__1);
				setState(550);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,80,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(547);
						match(WS);
						}
						} 
					}
					setState(552);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,80,_ctx);
				}
				}
				break;
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
	public static class MultiargfunctionContext extends ParserRuleContext {
		public TerminalNode SUMPRODUCT() { return getToken(detect_type_functionParser.SUMPRODUCT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public TerminalNode SUM() { return getToken(detect_type_functionParser.SUM, 0); }
		public TerminalNode PRODUCT() { return getToken(detect_type_functionParser.PRODUCT, 0); }
		public MultiargfunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiargfunction; }
	}

	public final MultiargfunctionContext multiargfunction() throws RecognitionException {
		MultiargfunctionContext _localctx = new MultiargfunctionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_multiargfunction);
		int _la;
		try {
			setState(615);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,88,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(558);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(555);
					match(WS);
					}
					}
					setState(560);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(561);
				match(SUMPRODUCT);
				setState(562);
				match(T__0);
				setState(563);
				expr(0);
				setState(564);
				match(T__2);
				setState(565);
				expr(0);
				setState(570);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(566);
					match(T__2);
					setState(567);
					expr(0);
					}
					}
					setState(572);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(573);
				match(T__1);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(578);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(575);
					match(WS);
					}
					}
					setState(580);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(581);
				match(SUM);
				setState(582);
				match(T__0);
				setState(583);
				expr(0);
				setState(584);
				match(T__2);
				setState(585);
				expr(0);
				setState(590);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(586);
					match(T__2);
					setState(587);
					expr(0);
					}
					}
					setState(592);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(593);
				match(T__1);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(598);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(595);
					match(WS);
					}
					}
					setState(600);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(601);
				match(PRODUCT);
				setState(602);
				match(T__0);
				setState(603);
				expr(0);
				setState(604);
				match(T__2);
				setState(605);
				expr(0);
				setState(610);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(606);
					match(T__2);
					setState(607);
					expr(0);
					}
					}
					setState(612);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(613);
				match(T__1);
				}
				break;
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
	public static class RangefunctionContext extends ParserRuleContext {
		public TerminalNode SUM_I() { return getToken(detect_type_functionParser.SUM_I, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> WS() { return getTokens(detect_type_functionParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(detect_type_functionParser.WS, i);
		}
		public TerminalNode PRODUCT_I() { return getToken(detect_type_functionParser.PRODUCT_I, 0); }
		public RangefunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rangefunction; }
	}

	public final RangefunctionContext rangefunction() throws RecognitionException {
		RangefunctionContext _localctx = new RangefunctionContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_rangefunction);
		int _la;
		try {
			int _alt;
			setState(673);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,97,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(620);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(617);
					match(WS);
					}
					}
					setState(622);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(623);
				match(SUM_I);
				setState(624);
				match(T__0);
				setState(628);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,90,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(625);
						match(WS);
						}
						} 
					}
					setState(630);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,90,_ctx);
				}
				setState(631);
				expr(0);
				setState(635);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(632);
					match(WS);
					}
					}
					setState(637);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(638);
				match(T__1);
				setState(642);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,92,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(639);
						match(WS);
						}
						} 
					}
					setState(644);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,92,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(648);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(645);
					match(WS);
					}
					}
					setState(650);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(651);
				match(PRODUCT_I);
				setState(652);
				match(T__0);
				setState(656);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,94,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(653);
						match(WS);
						}
						} 
					}
					setState(658);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,94,_ctx);
				}
				setState(659);
				expr(0);
				setState(663);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(660);
					match(WS);
					}
					}
					setState(665);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(666);
				match(T__1);
				setState(670);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,96,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(667);
						match(WS);
						}
						} 
					}
					setState(672);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,96,_ctx);
				}
				}
				break;
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
	public static class StringContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(detect_type_functionParser.STRING, 0); }
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(675);
			match(T__6);
			setState(676);
			match(STRING);
			setState(677);
			match(T__6);
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
		case 4:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001-\u02a8\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0003\u0000\u001c\b\u0000\u0001\u0001\u0001"+
		"\u0001\u0003\u0001 \b\u0001\u0001\u0002\u0005\u0002#\b\u0002\n\u0002\f"+
		"\u0002&\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002*\b\u0002\n\u0002\f"+
		"\u0002-\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u00022\b\u0002"+
		"\n\u0002\f\u00025\t\u0002\u0001\u0002\u0001\u0002\u0005\u00029\b\u0002"+
		"\n\u0002\f\u0002<\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"A\b\u0002\n\u0002\f\u0002D\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"H\b\u0002\n\u0002\f\u0002K\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"O\b\u0002\n\u0002\f\u0002R\t\u0002\u0001\u0002\u0005\u0002U\b\u0002\n"+
		"\u0002\f\u0002X\t\u0002\u0001\u0002\u0005\u0002[\b\u0002\n\u0002\f\u0002"+
		"^\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002c\b\u0002\n\u0002"+
		"\f\u0002f\t\u0002\u0003\u0002h\b\u0002\u0001\u0003\u0005\u0003k\b\u0003"+
		"\n\u0003\f\u0003n\t\u0003\u0001\u0003\u0001\u0003\u0005\u0003r\b\u0003"+
		"\n\u0003\f\u0003u\t\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003"+
		"z\b\u0003\n\u0003\f\u0003}\t\u0003\u0001\u0003\u0005\u0003\u0080\b\u0003"+
		"\n\u0003\f\u0003\u0083\t\u0003\u0001\u0003\u0001\u0003\u0005\u0003\u0087"+
		"\b\u0003\n\u0003\f\u0003\u008a\t\u0003\u0003\u0003\u008c\b\u0003\u0001"+
		"\u0003\u0001\u0003\u0003\u0003\u0090\b\u0003\u0001\u0003\u0001\u0003\u0003"+
		"\u0003\u0094\b\u0003\u0003\u0003\u0096\b\u0003\u0001\u0003\u0005\u0003"+
		"\u0099\b\u0003\n\u0003\f\u0003\u009c\t\u0003\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0003\u0004\u00a7\b\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u00ab"+
		"\b\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u00af\b\u0004\n\u0004\f\u0004"+
		"\u00b2\t\u0004\u0001\u0004\u0003\u0004\u00b5\b\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u00bc\b\u0004\n"+
		"\u0004\f\u0004\u00bf\t\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u00c3"+
		"\b\u0004\n\u0004\f\u0004\u00c6\t\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0005\u0004\u00cb\b\u0004\n\u0004\f\u0004\u00ce\t\u0004\u0001\u0004\u0001"+
		"\u0004\u0005\u0004\u00d2\b\u0004\n\u0004\f\u0004\u00d5\t\u0004\u0001\u0004"+
		"\u0005\u0004\u00d8\b\u0004\n\u0004\f\u0004\u00db\t\u0004\u0001\u0005\u0001"+
		"\u0005\u0005\u0005\u00df\b\u0005\n\u0005\f\u0005\u00e2\t\u0005\u0001\u0005"+
		"\u0001\u0005\u0003\u0005\u00e6\b\u0005\u0001\u0005\u0005\u0005\u00e9\b"+
		"\u0005\n\u0005\f\u0005\u00ec\t\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"\u00f0\b\u0005\n\u0005\f\u0005\u00f3\t\u0005\u0001\u0005\u0001\u0005\u0003"+
		"\u0005\u00f7\b\u0005\u0005\u0005\u00f9\b\u0005\n\u0005\f\u0005\u00fc\t"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\b\u0005\b\u0105\b\b\n\b\f\b\u0108\t\b\u0001\b\u0001\b\u0001"+
		"\b\u0005\b\u010d\b\b\n\b\f\b\u0110\t\b\u0001\b\u0001\b\u0005\b\u0114\b"+
		"\b\n\b\f\b\u0117\t\b\u0001\b\u0001\b\u0005\b\u011b\b\b\n\b\f\b\u011e\t"+
		"\b\u0001\b\u0005\b\u0121\b\b\n\b\f\b\u0124\t\b\u0001\b\u0001\b\u0001\b"+
		"\u0005\b\u0129\b\b\n\b\f\b\u012c\t\b\u0001\b\u0001\b\u0005\b\u0130\b\b"+
		"\n\b\f\b\u0133\t\b\u0001\b\u0001\b\u0005\b\u0137\b\b\n\b\f\b\u013a\t\b"+
		"\u0001\b\u0005\b\u013d\b\b\n\b\f\b\u0140\t\b\u0001\b\u0001\b\u0001\b\u0005"+
		"\b\u0145\b\b\n\b\f\b\u0148\t\b\u0001\b\u0001\b\u0005\b\u014c\b\b\n\b\f"+
		"\b\u014f\t\b\u0001\b\u0001\b\u0005\b\u0153\b\b\n\b\f\b\u0156\t\b\u0001"+
		"\b\u0005\b\u0159\b\b\n\b\f\b\u015c\t\b\u0001\b\u0001\b\u0001\b\u0005\b"+
		"\u0161\b\b\n\b\f\b\u0164\t\b\u0001\b\u0001\b\u0005\b\u0168\b\b\n\b\f\b"+
		"\u016b\t\b\u0001\b\u0001\b\u0005\b\u016f\b\b\n\b\f\b\u0172\t\b\u0001\b"+
		"\u0005\b\u0175\b\b\n\b\f\b\u0178\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u017d"+
		"\b\b\n\b\f\b\u0180\t\b\u0001\b\u0001\b\u0005\b\u0184\b\b\n\b\f\b\u0187"+
		"\t\b\u0001\b\u0001\b\u0005\b\u018b\b\b\n\b\f\b\u018e\t\b\u0001\b\u0005"+
		"\b\u0191\b\b\n\b\f\b\u0194\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u0199\b"+
		"\b\n\b\f\b\u019c\t\b\u0001\b\u0001\b\u0005\b\u01a0\b\b\n\b\f\b\u01a3\t"+
		"\b\u0001\b\u0001\b\u0005\b\u01a7\b\b\n\b\f\b\u01aa\t\b\u0001\b\u0005\b"+
		"\u01ad\b\b\n\b\f\b\u01b0\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u01b5\b\b"+
		"\n\b\f\b\u01b8\t\b\u0001\b\u0001\b\u0005\b\u01bc\b\b\n\b\f\b\u01bf\t\b"+
		"\u0001\b\u0001\b\u0005\b\u01c3\b\b\n\b\f\b\u01c6\t\b\u0001\b\u0005\b\u01c9"+
		"\b\b\n\b\f\b\u01cc\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u01d1\b\b\n\b\f"+
		"\b\u01d4\t\b\u0001\b\u0001\b\u0005\b\u01d8\b\b\n\b\f\b\u01db\t\b\u0001"+
		"\b\u0001\b\u0005\b\u01df\b\b\n\b\f\b\u01e2\t\b\u0001\b\u0005\b\u01e5\b"+
		"\b\n\b\f\b\u01e8\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u01ed\b\b\n\b\f\b"+
		"\u01f0\t\b\u0001\b\u0001\b\u0005\b\u01f4\b\b\n\b\f\b\u01f7\t\b\u0001\b"+
		"\u0001\b\u0005\b\u01fb\b\b\n\b\f\b\u01fe\t\b\u0001\b\u0005\b\u0201\b\b"+
		"\n\b\f\b\u0204\t\b\u0001\b\u0001\b\u0001\b\u0005\b\u0209\b\b\n\b\f\b\u020c"+
		"\t\b\u0001\b\u0001\b\u0005\b\u0210\b\b\n\b\f\b\u0213\t\b\u0001\b\u0001"+
		"\b\u0005\b\u0217\b\b\n\b\f\b\u021a\t\b\u0001\b\u0001\b\u0005\b\u021e\b"+
		"\b\n\b\f\b\u0221\t\b\u0001\b\u0001\b\u0005\b\u0225\b\b\n\b\f\b\u0228\t"+
		"\b\u0003\b\u022a\b\b\u0001\t\u0005\t\u022d\b\t\n\t\f\t\u0230\t\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0005\t\u0239\b\t\n"+
		"\t\f\t\u023c\t\t\u0001\t\u0001\t\u0001\t\u0005\t\u0241\b\t\n\t\f\t\u0244"+
		"\t\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0005\t\u024d"+
		"\b\t\n\t\f\t\u0250\t\t\u0001\t\u0001\t\u0001\t\u0005\t\u0255\b\t\n\t\f"+
		"\t\u0258\t\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0005"+
		"\t\u0261\b\t\n\t\f\t\u0264\t\t\u0001\t\u0001\t\u0003\t\u0268\b\t\u0001"+
		"\n\u0005\n\u026b\b\n\n\n\f\n\u026e\t\n\u0001\n\u0001\n\u0001\n\u0005\n"+
		"\u0273\b\n\n\n\f\n\u0276\t\n\u0001\n\u0001\n\u0005\n\u027a\b\n\n\n\f\n"+
		"\u027d\t\n\u0001\n\u0001\n\u0005\n\u0281\b\n\n\n\f\n\u0284\t\n\u0001\n"+
		"\u0005\n\u0287\b\n\n\n\f\n\u028a\t\n\u0001\n\u0001\n\u0001\n\u0005\n\u028f"+
		"\b\n\n\n\f\n\u0292\t\n\u0001\n\u0001\n\u0005\n\u0296\b\n\n\n\f\n\u0299"+
		"\t\n\u0001\n\u0001\n\u0005\n\u029d\b\n\n\n\f\n\u02a0\t\n\u0003\n\u02a2"+
		"\b\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0000"+
		"\u0001\b\f\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016"+
		"\u0000\u0004\u0001\u0000$%\u0001\u0000&\'\u0002\u0000##,,\u0002\u0000"+
		"\u0018\u0018\u001a\u001a\u030d\u0000\u001b\u0001\u0000\u0000\u0000\u0002"+
		"\u001f\u0001\u0000\u0000\u0000\u0004g\u0001\u0000\u0000\u0000\u0006l\u0001"+
		"\u0000\u0000\u0000\b\u00b4\u0001\u0000\u0000\u0000\n\u00dc\u0001\u0000"+
		"\u0000\u0000\f\u00ff\u0001\u0000\u0000\u0000\u000e\u0101\u0001\u0000\u0000"+
		"\u0000\u0010\u0229\u0001\u0000\u0000\u0000\u0012\u0267\u0001\u0000\u0000"+
		"\u0000\u0014\u02a1\u0001\u0000\u0000\u0000\u0016\u02a3\u0001\u0000\u0000"+
		"\u0000\u0018\u001c\u0003\n\u0005\u0000\u0019\u001c\u0003\b\u0004\u0000"+
		"\u001a\u001c\u0003\u0016\u000b\u0000\u001b\u0018\u0001\u0000\u0000\u0000"+
		"\u001b\u0019\u0001\u0000\u0000\u0000\u001b\u001a\u0001\u0000\u0000\u0000"+
		"\u001c\u0001\u0001\u0000\u0000\u0000\u001d \u0003\n\u0005\u0000\u001e"+
		" \u0003\b\u0004\u0000\u001f\u001d\u0001\u0000\u0000\u0000\u001f\u001e"+
		"\u0001\u0000\u0000\u0000 \u0003\u0001\u0000\u0000\u0000!#\u0005!\u0000"+
		"\u0000\"!\u0001\u0000\u0000\u0000#&\u0001\u0000\u0000\u0000$\"\u0001\u0000"+
		"\u0000\u0000$%\u0001\u0000\u0000\u0000%\'\u0001\u0000\u0000\u0000&$\u0001"+
		"\u0000\u0000\u0000\'+\u0005\u0001\u0000\u0000(*\u0005!\u0000\u0000)(\u0001"+
		"\u0000\u0000\u0000*-\u0001\u0000\u0000\u0000+)\u0001\u0000\u0000\u0000"+
		"+,\u0001\u0000\u0000\u0000,.\u0001\u0000\u0000\u0000-+\u0001\u0000\u0000"+
		"\u0000.h\u0005\u0002\u0000\u0000/3\u0005\u0001\u0000\u000002\u0005!\u0000"+
		"\u000010\u0001\u0000\u0000\u000025\u0001\u0000\u0000\u000031\u0001\u0000"+
		"\u0000\u000034\u0001\u0000\u0000\u000046\u0001\u0000\u0000\u000053\u0001"+
		"\u0000\u0000\u00006:\u0005#\u0000\u000079\u0005!\u0000\u000087\u0001\u0000"+
		"\u0000\u00009<\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000:;\u0001"+
		"\u0000\u0000\u0000;=\u0001\u0000\u0000\u0000<:\u0001\u0000\u0000\u0000"+
		"=h\u0005\u0002\u0000\u0000>B\u0005\u0001\u0000\u0000?A\u0005!\u0000\u0000"+
		"@?\u0001\u0000\u0000\u0000AD\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000"+
		"\u0000BC\u0001\u0000\u0000\u0000CE\u0001\u0000\u0000\u0000DB\u0001\u0000"+
		"\u0000\u0000EI\u0005#\u0000\u0000FH\u0005!\u0000\u0000GF\u0001\u0000\u0000"+
		"\u0000HK\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000\u0000IJ\u0001\u0000"+
		"\u0000\u0000JV\u0001\u0000\u0000\u0000KI\u0001\u0000\u0000\u0000LP\u0005"+
		"\u0003\u0000\u0000MO\u0005!\u0000\u0000NM\u0001\u0000\u0000\u0000OR\u0001"+
		"\u0000\u0000\u0000PN\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000"+
		"QS\u0001\u0000\u0000\u0000RP\u0001\u0000\u0000\u0000SU\u0005#\u0000\u0000"+
		"TL\u0001\u0000\u0000\u0000UX\u0001\u0000\u0000\u0000VT\u0001\u0000\u0000"+
		"\u0000VW\u0001\u0000\u0000\u0000W\\\u0001\u0000\u0000\u0000XV\u0001\u0000"+
		"\u0000\u0000Y[\u0005!\u0000\u0000ZY\u0001\u0000\u0000\u0000[^\u0001\u0000"+
		"\u0000\u0000\\Z\u0001\u0000\u0000\u0000\\]\u0001\u0000\u0000\u0000]_\u0001"+
		"\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000_`\u0005\u0002\u0000\u0000"+
		"`d\u0001\u0000\u0000\u0000ac\u0005!\u0000\u0000ba\u0001\u0000\u0000\u0000"+
		"cf\u0001\u0000\u0000\u0000db\u0001\u0000\u0000\u0000de\u0001\u0000\u0000"+
		"\u0000eh\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000g$\u0001\u0000"+
		"\u0000\u0000g/\u0001\u0000\u0000\u0000g>\u0001\u0000\u0000\u0000h\u0005"+
		"\u0001\u0000\u0000\u0000ik\u0005!\u0000\u0000ji\u0001\u0000\u0000\u0000"+
		"kn\u0001\u0000\u0000\u0000lj\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000"+
		"\u0000m\u0095\u0001\u0000\u0000\u0000nl\u0001\u0000\u0000\u0000o\u008b"+
		"\u0005\u0004\u0000\u0000pr\u0005!\u0000\u0000qp\u0001\u0000\u0000\u0000"+
		"ru\u0001\u0000\u0000\u0000sq\u0001\u0000\u0000\u0000st\u0001\u0000\u0000"+
		"\u0000tv\u0001\u0000\u0000\u0000us\u0001\u0000\u0000\u0000vw\u0005\t\u0000"+
		"\u0000w{\u0005\b\u0000\u0000xz\u0005!\u0000\u0000yx\u0001\u0000\u0000"+
		"\u0000z}\u0001\u0000\u0000\u0000{y\u0001\u0000\u0000\u0000{|\u0001\u0000"+
		"\u0000\u0000|\u008c\u0001\u0000\u0000\u0000}{\u0001\u0000\u0000\u0000"+
		"~\u0080\u0005!\u0000\u0000\u007f~\u0001\u0000\u0000\u0000\u0080\u0083"+
		"\u0001\u0000\u0000\u0000\u0081\u007f\u0001\u0000\u0000\u0000\u0081\u0082"+
		"\u0001\u0000\u0000\u0000\u0082\u0084\u0001\u0000\u0000\u0000\u0083\u0081"+
		"\u0001\u0000\u0000\u0000\u0084\u0088\u0005\b\u0000\u0000\u0085\u0087\u0005"+
		"!\u0000\u0000\u0086\u0085\u0001\u0000\u0000\u0000\u0087\u008a\u0001\u0000"+
		"\u0000\u0000\u0088\u0086\u0001\u0000\u0000\u0000\u0088\u0089\u0001\u0000"+
		"\u0000\u0000\u0089\u008c\u0001\u0000\u0000\u0000\u008a\u0088\u0001\u0000"+
		"\u0000\u0000\u008bs\u0001\u0000\u0000\u0000\u008b\u0081\u0001\u0000\u0000"+
		"\u0000\u008c\u008d\u0001\u0000\u0000\u0000\u008d\u008f\u0005\u0002\u0000"+
		"\u0000\u008e\u0090\u0003\u0004\u0002\u0000\u008f\u008e\u0001\u0000\u0000"+
		"\u0000\u008f\u0090\u0001\u0000\u0000\u0000\u0090\u0096\u0001\u0000\u0000"+
		"\u0000\u0091\u0093\u0005\b\u0000\u0000\u0092\u0094\u0003\u0004\u0002\u0000"+
		"\u0093\u0092\u0001\u0000\u0000\u0000\u0093\u0094\u0001\u0000\u0000\u0000"+
		"\u0094\u0096\u0001\u0000\u0000\u0000\u0095o\u0001\u0000\u0000\u0000\u0095"+
		"\u0091\u0001\u0000\u0000\u0000\u0096\u009a\u0001\u0000\u0000\u0000\u0097"+
		"\u0099\u0005!\u0000\u0000\u0098\u0097\u0001\u0000\u0000\u0000\u0099\u009c"+
		"\u0001\u0000\u0000\u0000\u009a\u0098\u0001\u0000\u0000\u0000\u009a\u009b"+
		"\u0001\u0000\u0000\u0000\u009b\u0007\u0001\u0000\u0000\u0000\u009c\u009a"+
		"\u0001\u0000\u0000\u0000\u009d\u009e\u0006\u0004\uffff\uffff\u0000\u009e"+
		"\u009f\u0005\u0001\u0000\u0000\u009f\u00a0\u0003\b\u0004\u0000\u00a0\u00a1"+
		"\u0005\u0002\u0000\u0000\u00a1\u00b5\u0001\u0000\u0000\u0000\u00a2\u00b5"+
		"\u0003\u0006\u0003\u0000\u00a3\u00a7\u0003\u0010\b\u0000\u00a4\u00a7\u0003"+
		"\u0012\t\u0000\u00a5\u00a7\u0003\u0014\n\u0000\u00a6\u00a3\u0001\u0000"+
		"\u0000\u0000\u00a6\u00a4\u0001\u0000\u0000\u0000\u00a6\u00a5\u0001\u0000"+
		"\u0000\u0000\u00a7\u00b5\u0001\u0000\u0000\u0000\u00a8\u00ab\u0003\f\u0006"+
		"\u0000\u00a9\u00ab\u0003\u000e\u0007\u0000\u00aa\u00a8\u0001\u0000\u0000"+
		"\u0000\u00aa\u00a9\u0001\u0000\u0000\u0000\u00ab\u00b5\u0001\u0000\u0000"+
		"\u0000\u00ac\u00b0\u0007\u0000\u0000\u0000\u00ad\u00af\u0005!\u0000\u0000"+
		"\u00ae\u00ad\u0001\u0000\u0000\u0000\u00af\u00b2\u0001\u0000\u0000\u0000"+
		"\u00b0\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001\u0000\u0000\u0000"+
		"\u00b1\u00b3\u0001\u0000\u0000\u0000\u00b2\u00b0\u0001\u0000\u0000\u0000"+
		"\u00b3\u00b5\u0003\b\u0004\u0004\u00b4\u009d\u0001\u0000\u0000\u0000\u00b4"+
		"\u00a2\u0001\u0000\u0000\u0000\u00b4\u00a6\u0001\u0000\u0000\u0000\u00b4"+
		"\u00aa\u0001\u0000\u0000\u0000\u00b4\u00ac\u0001\u0000\u0000\u0000\u00b5"+
		"\u00d9\u0001\u0000\u0000\u0000\u00b6\u00b7\n\u0003\u0000\u0000\u00b7\u00b8"+
		"\u0005(\u0000\u0000\u00b8\u00d8\u0003\b\u0004\u0004\u00b9\u00bd\n\u0002"+
		"\u0000\u0000\u00ba\u00bc\u0005!\u0000\u0000\u00bb\u00ba\u0001\u0000\u0000"+
		"\u0000\u00bc\u00bf\u0001\u0000\u0000\u0000\u00bd\u00bb\u0001\u0000\u0000"+
		"\u0000\u00bd\u00be\u0001\u0000\u0000\u0000\u00be\u00c0\u0001\u0000\u0000"+
		"\u0000\u00bf\u00bd\u0001\u0000\u0000\u0000\u00c0\u00c4\u0007\u0001\u0000"+
		"\u0000\u00c1\u00c3\u0005!\u0000\u0000\u00c2\u00c1\u0001\u0000\u0000\u0000"+
		"\u00c3\u00c6\u0001\u0000\u0000\u0000\u00c4\u00c2\u0001\u0000\u0000\u0000"+
		"\u00c4\u00c5\u0001\u0000\u0000\u0000\u00c5\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c6\u00c4\u0001\u0000\u0000\u0000\u00c7\u00d8\u0003\b\u0004\u0003\u00c8"+
		"\u00cc\n\u0001\u0000\u0000\u00c9\u00cb\u0005!\u0000\u0000\u00ca\u00c9"+
		"\u0001\u0000\u0000\u0000\u00cb\u00ce\u0001\u0000\u0000\u0000\u00cc\u00ca"+
		"\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001\u0000\u0000\u0000\u00cd\u00cf"+
		"\u0001\u0000\u0000\u0000\u00ce\u00cc\u0001\u0000\u0000\u0000\u00cf\u00d3"+
		"\u0007\u0000\u0000\u0000\u00d0\u00d2\u0005!\u0000\u0000\u00d1\u00d0\u0001"+
		"\u0000\u0000\u0000\u00d2\u00d5\u0001\u0000\u0000\u0000\u00d3\u00d1\u0001"+
		"\u0000\u0000\u0000\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u00d6\u0001"+
		"\u0000\u0000\u0000\u00d5\u00d3\u0001\u0000\u0000\u0000\u00d6\u00d8\u0003"+
		"\b\u0004\u0002\u00d7\u00b6\u0001\u0000\u0000\u0000\u00d7\u00b9\u0001\u0000"+
		"\u0000\u0000\u00d7\u00c8\u0001\u0000\u0000\u0000\u00d8\u00db\u0001\u0000"+
		"\u0000\u0000\u00d9\u00d7\u0001\u0000\u0000\u0000\u00d9\u00da\u0001\u0000"+
		"\u0000\u0000\u00da\t\u0001\u0000\u0000\u0000\u00db\u00d9\u0001\u0000\u0000"+
		"\u0000\u00dc\u00e0\u0005\u0005\u0000\u0000\u00dd\u00df\u0005!\u0000\u0000"+
		"\u00de\u00dd\u0001\u0000\u0000\u0000\u00df\u00e2\u0001\u0000\u0000\u0000"+
		"\u00e0\u00de\u0001\u0000\u0000\u0000\u00e0\u00e1\u0001\u0000\u0000\u0000"+
		"\u00e1\u00e5\u0001\u0000\u0000\u0000\u00e2\u00e0\u0001\u0000\u0000\u0000"+
		"\u00e3\u00e6\u0003\b\u0004\u0000\u00e4\u00e6\u0003\n\u0005\u0000\u00e5"+
		"\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e4\u0001\u0000\u0000\u0000\u00e6"+
		"\u00ea\u0001\u0000\u0000\u0000\u00e7\u00e9\u0005!\u0000\u0000\u00e8\u00e7"+
		"\u0001\u0000\u0000\u0000\u00e9\u00ec\u0001\u0000\u0000\u0000\u00ea\u00e8"+
		"\u0001\u0000\u0000\u0000\u00ea\u00eb\u0001\u0000\u0000\u0000\u00eb\u00fa"+
		"\u0001\u0000\u0000\u0000\u00ec\u00ea\u0001\u0000\u0000\u0000\u00ed\u00f1"+
		"\u0005\u0003\u0000\u0000\u00ee\u00f0\u0005!\u0000\u0000\u00ef\u00ee\u0001"+
		"\u0000\u0000\u0000\u00f0\u00f3\u0001\u0000\u0000\u0000\u00f1\u00ef\u0001"+
		"\u0000\u0000\u0000\u00f1\u00f2\u0001\u0000\u0000\u0000\u00f2\u00f6\u0001"+
		"\u0000\u0000\u0000\u00f3\u00f1\u0001\u0000\u0000\u0000\u00f4\u00f7\u0003"+
		"\b\u0004\u0000\u00f5\u00f7\u0003\n\u0005\u0000\u00f6\u00f4\u0001\u0000"+
		"\u0000\u0000\u00f6\u00f5\u0001\u0000\u0000\u0000\u00f7\u00f9\u0001\u0000"+
		"\u0000\u0000\u00f8\u00ed\u0001\u0000\u0000\u0000\u00f9\u00fc\u0001\u0000"+
		"\u0000\u0000\u00fa\u00f8\u0001\u0000\u0000\u0000\u00fa\u00fb\u0001\u0000"+
		"\u0000\u0000\u00fb\u00fd\u0001\u0000\u0000\u0000\u00fc\u00fa\u0001\u0000"+
		"\u0000\u0000\u00fd\u00fe\u0005\u0006\u0000\u0000\u00fe\u000b\u0001\u0000"+
		"\u0000\u0000\u00ff\u0100\u0007\u0002\u0000\u0000\u0100\r\u0001\u0000\u0000"+
		"\u0000\u0101\u0102\u0007\u0003\u0000\u0000\u0102\u000f\u0001\u0000\u0000"+
		"\u0000\u0103\u0105\u0005!\u0000\u0000\u0104\u0103\u0001\u0000\u0000\u0000"+
		"\u0105\u0108\u0001\u0000\u0000\u0000\u0106\u0104\u0001\u0000\u0000\u0000"+
		"\u0106\u0107\u0001\u0000\u0000\u0000\u0107\u0109\u0001\u0000\u0000\u0000"+
		"\u0108\u0106\u0001\u0000\u0000\u0000\u0109\u010a\u0005\u0015\u0000\u0000"+
		"\u010a\u010e\u0005\u0001\u0000\u0000\u010b\u010d\u0005!\u0000\u0000\u010c"+
		"\u010b\u0001\u0000\u0000\u0000\u010d\u0110\u0001\u0000\u0000\u0000\u010e"+
		"\u010c\u0001\u0000\u0000\u0000\u010e\u010f\u0001\u0000\u0000\u0000\u010f"+
		"\u0111\u0001\u0000\u0000\u0000\u0110\u010e\u0001\u0000\u0000\u0000\u0111"+
		"\u0115\u0003\b\u0004\u0000\u0112\u0114\u0005!\u0000\u0000\u0113\u0112"+
		"\u0001\u0000\u0000\u0000\u0114\u0117\u0001\u0000\u0000\u0000\u0115\u0113"+
		"\u0001\u0000\u0000\u0000\u0115\u0116\u0001\u0000\u0000\u0000\u0116\u0118"+
		"\u0001\u0000\u0000\u0000\u0117\u0115\u0001\u0000\u0000\u0000\u0118\u011c"+
		"\u0005\u0002\u0000\u0000\u0119\u011b\u0005!\u0000\u0000\u011a\u0119\u0001"+
		"\u0000\u0000\u0000\u011b\u011e\u0001\u0000\u0000\u0000\u011c\u011a\u0001"+
		"\u0000\u0000\u0000\u011c\u011d\u0001\u0000\u0000\u0000\u011d\u022a\u0001"+
		"\u0000\u0000\u0000\u011e\u011c\u0001\u0000\u0000\u0000\u011f\u0121\u0005"+
		"!\u0000\u0000\u0120\u011f\u0001\u0000\u0000\u0000\u0121\u0124\u0001\u0000"+
		"\u0000\u0000\u0122\u0120\u0001\u0000\u0000\u0000\u0122\u0123\u0001\u0000"+
		"\u0000\u0000\u0123\u0125\u0001\u0000\u0000\u0000\u0124\u0122\u0001\u0000"+
		"\u0000\u0000\u0125\u0126\u0005\u0016\u0000\u0000\u0126\u012a\u0005\u0001"+
		"\u0000\u0000\u0127\u0129\u0005!\u0000\u0000\u0128\u0127\u0001\u0000\u0000"+
		"\u0000\u0129\u012c\u0001\u0000\u0000\u0000\u012a\u0128\u0001\u0000\u0000"+
		"\u0000\u012a\u012b\u0001\u0000\u0000\u0000\u012b\u012d\u0001\u0000\u0000"+
		"\u0000\u012c\u012a\u0001\u0000\u0000\u0000\u012d\u0131\u0003\b\u0004\u0000"+
		"\u012e\u0130\u0005!\u0000\u0000\u012f\u012e\u0001\u0000\u0000\u0000\u0130"+
		"\u0133\u0001\u0000\u0000\u0000\u0131\u012f\u0001\u0000\u0000\u0000\u0131"+
		"\u0132\u0001\u0000\u0000\u0000\u0132\u0134\u0001\u0000\u0000\u0000\u0133"+
		"\u0131\u0001\u0000\u0000\u0000\u0134\u0138\u0005\u0002\u0000\u0000\u0135"+
		"\u0137\u0005!\u0000\u0000\u0136\u0135\u0001\u0000\u0000\u0000\u0137\u013a"+
		"\u0001\u0000\u0000\u0000\u0138\u0136\u0001\u0000\u0000\u0000\u0138\u0139"+
		"\u0001\u0000\u0000\u0000\u0139\u022a\u0001\u0000\u0000\u0000\u013a\u0138"+
		"\u0001\u0000\u0000\u0000\u013b\u013d\u0005!\u0000\u0000\u013c\u013b\u0001"+
		"\u0000\u0000\u0000\u013d\u0140\u0001\u0000\u0000\u0000\u013e\u013c\u0001"+
		"\u0000\u0000\u0000\u013e\u013f\u0001\u0000\u0000\u0000\u013f\u0141\u0001"+
		"\u0000\u0000\u0000\u0140\u013e\u0001\u0000\u0000\u0000\u0141\u0142\u0005"+
		"\u0018\u0000\u0000\u0142\u0146\u0005\u0001\u0000\u0000\u0143\u0145\u0005"+
		"!\u0000\u0000\u0144\u0143\u0001\u0000\u0000\u0000\u0145\u0148\u0001\u0000"+
		"\u0000\u0000\u0146\u0144\u0001\u0000\u0000\u0000\u0146\u0147\u0001\u0000"+
		"\u0000\u0000\u0147\u0149\u0001\u0000\u0000\u0000\u0148\u0146\u0001\u0000"+
		"\u0000\u0000\u0149\u014d\u0003\b\u0004\u0000\u014a\u014c\u0005!\u0000"+
		"\u0000\u014b\u014a\u0001\u0000\u0000\u0000\u014c\u014f\u0001\u0000\u0000"+
		"\u0000\u014d\u014b\u0001\u0000\u0000\u0000\u014d\u014e\u0001\u0000\u0000"+
		"\u0000\u014e\u0150\u0001\u0000\u0000\u0000\u014f\u014d\u0001\u0000\u0000"+
		"\u0000\u0150\u0154\u0005\u0002\u0000\u0000\u0151\u0153\u0005!\u0000\u0000"+
		"\u0152\u0151\u0001\u0000\u0000\u0000\u0153\u0156\u0001\u0000\u0000\u0000"+
		"\u0154\u0152\u0001\u0000\u0000\u0000\u0154\u0155\u0001\u0000\u0000\u0000"+
		"\u0155\u022a\u0001\u0000\u0000\u0000\u0156\u0154\u0001\u0000\u0000\u0000"+
		"\u0157\u0159\u0005!\u0000\u0000\u0158\u0157\u0001\u0000\u0000\u0000\u0159"+
		"\u015c\u0001\u0000\u0000\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015a"+
		"\u015b\u0001\u0000\u0000\u0000\u015b\u015d\u0001\u0000\u0000\u0000\u015c"+
		"\u015a\u0001\u0000\u0000\u0000\u015d\u015e\u0005\u0019\u0000\u0000\u015e"+
		"\u0162\u0005\u0001\u0000\u0000\u015f\u0161\u0005!\u0000\u0000\u0160\u015f"+
		"\u0001\u0000\u0000\u0000\u0161\u0164\u0001\u0000\u0000\u0000\u0162\u0160"+
		"\u0001\u0000\u0000\u0000\u0162\u0163\u0001\u0000\u0000\u0000\u0163\u0165"+
		"\u0001\u0000\u0000\u0000\u0164\u0162\u0001\u0000\u0000\u0000\u0165\u0169"+
		"\u0003\b\u0004\u0000\u0166\u0168\u0005!\u0000\u0000\u0167\u0166\u0001"+
		"\u0000\u0000\u0000\u0168\u016b\u0001\u0000\u0000\u0000\u0169\u0167\u0001"+
		"\u0000\u0000\u0000\u0169\u016a\u0001\u0000\u0000\u0000\u016a\u016c\u0001"+
		"\u0000\u0000\u0000\u016b\u0169\u0001\u0000\u0000\u0000\u016c\u0170\u0005"+
		"\u0002\u0000\u0000\u016d\u016f\u0005!\u0000\u0000\u016e\u016d\u0001\u0000"+
		"\u0000\u0000\u016f\u0172\u0001\u0000\u0000\u0000\u0170\u016e\u0001\u0000"+
		"\u0000\u0000\u0170\u0171\u0001\u0000\u0000\u0000\u0171\u022a\u0001\u0000"+
		"\u0000\u0000\u0172\u0170\u0001\u0000\u0000\u0000\u0173\u0175\u0005!\u0000"+
		"\u0000\u0174\u0173\u0001\u0000\u0000\u0000\u0175\u0178\u0001\u0000\u0000"+
		"\u0000\u0176\u0174\u0001\u0000\u0000\u0000\u0176\u0177\u0001\u0000\u0000"+
		"\u0000\u0177\u0179\u0001\u0000\u0000\u0000\u0178\u0176\u0001\u0000\u0000"+
		"\u0000\u0179\u017a\u0005\u001b\u0000\u0000\u017a\u017e\u0005\u0001\u0000"+
		"\u0000\u017b\u017d\u0005!\u0000\u0000\u017c\u017b\u0001\u0000\u0000\u0000"+
		"\u017d\u0180\u0001\u0000\u0000\u0000\u017e\u017c\u0001\u0000\u0000\u0000"+
		"\u017e\u017f\u0001\u0000\u0000\u0000\u017f\u0181\u0001\u0000\u0000\u0000"+
		"\u0180\u017e\u0001\u0000\u0000\u0000\u0181\u0185\u0003\b\u0004\u0000\u0182"+
		"\u0184\u0005!\u0000\u0000\u0183\u0182\u0001\u0000\u0000\u0000\u0184\u0187"+
		"\u0001\u0000\u0000\u0000\u0185\u0183\u0001\u0000\u0000\u0000\u0185\u0186"+
		"\u0001\u0000\u0000\u0000\u0186\u0188\u0001\u0000\u0000\u0000\u0187\u0185"+
		"\u0001\u0000\u0000\u0000\u0188\u018c\u0005\u0002\u0000\u0000\u0189\u018b"+
		"\u0005!\u0000\u0000\u018a\u0189\u0001\u0000\u0000\u0000\u018b\u018e\u0001"+
		"\u0000\u0000\u0000\u018c\u018a\u0001\u0000\u0000\u0000\u018c\u018d\u0001"+
		"\u0000\u0000\u0000\u018d\u022a\u0001\u0000\u0000\u0000\u018e\u018c\u0001"+
		"\u0000\u0000\u0000\u018f\u0191\u0005!\u0000\u0000\u0190\u018f\u0001\u0000"+
		"\u0000\u0000\u0191\u0194\u0001\u0000\u0000\u0000\u0192\u0190\u0001\u0000"+
		"\u0000\u0000\u0192\u0193\u0001\u0000\u0000\u0000\u0193\u0195\u0001\u0000"+
		"\u0000\u0000\u0194\u0192\u0001\u0000\u0000\u0000\u0195\u0196\u0005\u001c"+
		"\u0000\u0000\u0196\u019a\u0005\u0001\u0000\u0000\u0197\u0199\u0005!\u0000"+
		"\u0000\u0198\u0197\u0001\u0000\u0000\u0000\u0199\u019c\u0001\u0000\u0000"+
		"\u0000\u019a\u0198\u0001\u0000\u0000\u0000\u019a\u019b\u0001\u0000\u0000"+
		"\u0000\u019b\u019d\u0001\u0000\u0000\u0000\u019c\u019a\u0001\u0000\u0000"+
		"\u0000\u019d\u01a1\u0003\b\u0004\u0000\u019e\u01a0\u0005!\u0000\u0000"+
		"\u019f\u019e\u0001\u0000\u0000\u0000\u01a0\u01a3\u0001\u0000\u0000\u0000"+
		"\u01a1\u019f\u0001\u0000\u0000\u0000\u01a1\u01a2\u0001\u0000\u0000\u0000"+
		"\u01a2\u01a4\u0001\u0000\u0000\u0000\u01a3\u01a1\u0001\u0000\u0000\u0000"+
		"\u01a4\u01a8\u0005\u0002\u0000\u0000\u01a5\u01a7\u0005!\u0000\u0000\u01a6"+
		"\u01a5\u0001\u0000\u0000\u0000\u01a7\u01aa\u0001\u0000\u0000\u0000\u01a8"+
		"\u01a6\u0001\u0000\u0000\u0000\u01a8\u01a9\u0001\u0000\u0000\u0000\u01a9"+
		"\u022a\u0001\u0000\u0000\u0000\u01aa\u01a8\u0001\u0000\u0000\u0000\u01ab"+
		"\u01ad\u0005!\u0000\u0000\u01ac\u01ab\u0001\u0000\u0000\u0000\u01ad\u01b0"+
		"\u0001\u0000\u0000\u0000\u01ae\u01ac\u0001\u0000\u0000\u0000\u01ae\u01af"+
		"\u0001\u0000\u0000\u0000\u01af\u01b1\u0001\u0000\u0000\u0000\u01b0\u01ae"+
		"\u0001\u0000\u0000\u0000\u01b1\u01b2\u0005\u001e\u0000\u0000\u01b2\u01b6"+
		"\u0005\u0001\u0000\u0000\u01b3\u01b5\u0005!\u0000\u0000\u01b4\u01b3\u0001"+
		"\u0000\u0000\u0000\u01b5\u01b8\u0001\u0000\u0000\u0000\u01b6\u01b4\u0001"+
		"\u0000\u0000\u0000\u01b6\u01b7\u0001\u0000\u0000\u0000\u01b7\u01b9\u0001"+
		"\u0000\u0000\u0000\u01b8\u01b6\u0001\u0000\u0000\u0000\u01b9\u01bd\u0003"+
		"\b\u0004\u0000\u01ba\u01bc\u0005!\u0000\u0000\u01bb\u01ba\u0001\u0000"+
		"\u0000\u0000\u01bc\u01bf\u0001\u0000\u0000\u0000\u01bd\u01bb\u0001\u0000"+
		"\u0000\u0000\u01bd\u01be\u0001\u0000\u0000\u0000\u01be\u01c0\u0001\u0000"+
		"\u0000\u0000\u01bf\u01bd\u0001\u0000\u0000\u0000\u01c0\u01c4\u0005\u0002"+
		"\u0000\u0000\u01c1\u01c3\u0005!\u0000\u0000\u01c2\u01c1\u0001\u0000\u0000"+
		"\u0000\u01c3\u01c6\u0001\u0000\u0000\u0000\u01c4\u01c2\u0001\u0000\u0000"+
		"\u0000\u01c4\u01c5\u0001\u0000\u0000\u0000\u01c5\u022a\u0001\u0000\u0000"+
		"\u0000\u01c6\u01c4\u0001\u0000\u0000\u0000\u01c7\u01c9\u0005!\u0000\u0000"+
		"\u01c8\u01c7\u0001\u0000\u0000\u0000\u01c9\u01cc\u0001\u0000\u0000\u0000"+
		"\u01ca\u01c8\u0001\u0000\u0000\u0000\u01ca\u01cb\u0001\u0000\u0000\u0000"+
		"\u01cb\u01cd\u0001\u0000\u0000\u0000\u01cc\u01ca\u0001\u0000\u0000\u0000"+
		"\u01cd\u01ce\u0005\u001d\u0000\u0000\u01ce\u01d2\u0005\u0001\u0000\u0000"+
		"\u01cf\u01d1\u0005!\u0000\u0000\u01d0\u01cf\u0001\u0000\u0000\u0000\u01d1"+
		"\u01d4\u0001\u0000\u0000\u0000\u01d2\u01d0\u0001\u0000\u0000\u0000\u01d2"+
		"\u01d3\u0001\u0000\u0000\u0000\u01d3\u01d5\u0001\u0000\u0000\u0000\u01d4"+
		"\u01d2\u0001\u0000\u0000\u0000\u01d5\u01d9\u0003\b\u0004\u0000\u01d6\u01d8"+
		"\u0005!\u0000\u0000\u01d7\u01d6\u0001\u0000\u0000\u0000\u01d8\u01db\u0001"+
		"\u0000\u0000\u0000\u01d9\u01d7\u0001\u0000\u0000\u0000\u01d9\u01da\u0001"+
		"\u0000\u0000\u0000\u01da\u01dc\u0001\u0000\u0000\u0000\u01db\u01d9\u0001"+
		"\u0000\u0000\u0000\u01dc\u01e0\u0005\u0002\u0000\u0000\u01dd\u01df\u0005"+
		"!\u0000\u0000\u01de\u01dd\u0001\u0000\u0000\u0000\u01df\u01e2\u0001\u0000"+
		"\u0000\u0000\u01e0\u01de\u0001\u0000\u0000\u0000\u01e0\u01e1\u0001\u0000"+
		"\u0000\u0000\u01e1\u022a\u0001\u0000\u0000\u0000\u01e2\u01e0\u0001\u0000"+
		"\u0000\u0000\u01e3\u01e5\u0005!\u0000\u0000\u01e4\u01e3\u0001\u0000\u0000"+
		"\u0000\u01e5\u01e8\u0001\u0000\u0000\u0000\u01e6\u01e4\u0001\u0000\u0000"+
		"\u0000\u01e6\u01e7\u0001\u0000\u0000\u0000\u01e7\u01e9\u0001\u0000\u0000"+
		"\u0000\u01e8\u01e6\u0001\u0000\u0000\u0000\u01e9\u01ea\u0005\u001f\u0000"+
		"\u0000\u01ea\u01ee\u0005\u0001\u0000\u0000\u01eb\u01ed\u0005!\u0000\u0000"+
		"\u01ec\u01eb\u0001\u0000\u0000\u0000\u01ed\u01f0\u0001\u0000\u0000\u0000"+
		"\u01ee\u01ec\u0001\u0000\u0000\u0000\u01ee\u01ef\u0001\u0000\u0000\u0000"+
		"\u01ef\u01f1\u0001\u0000\u0000\u0000\u01f0\u01ee\u0001\u0000\u0000\u0000"+
		"\u01f1\u01f5\u0003\b\u0004\u0000\u01f2\u01f4\u0005!\u0000\u0000\u01f3"+
		"\u01f2\u0001\u0000\u0000\u0000\u01f4\u01f7\u0001\u0000\u0000\u0000\u01f5"+
		"\u01f3\u0001\u0000\u0000\u0000\u01f5\u01f6\u0001\u0000\u0000\u0000\u01f6"+
		"\u01f8\u0001\u0000\u0000\u0000\u01f7\u01f5\u0001\u0000\u0000\u0000\u01f8"+
		"\u01fc\u0005\u0002\u0000\u0000\u01f9\u01fb\u0005!\u0000\u0000\u01fa\u01f9"+
		"\u0001\u0000\u0000\u0000\u01fb\u01fe\u0001\u0000\u0000\u0000\u01fc\u01fa"+
		"\u0001\u0000\u0000\u0000\u01fc\u01fd\u0001\u0000\u0000\u0000\u01fd\u022a"+
		"\u0001\u0000\u0000\u0000\u01fe\u01fc\u0001\u0000\u0000\u0000\u01ff\u0201"+
		"\u0005!\u0000\u0000\u0200\u01ff\u0001\u0000\u0000\u0000\u0201\u0204\u0001"+
		"\u0000\u0000\u0000\u0202\u0200\u0001\u0000\u0000\u0000\u0202\u0203\u0001"+
		"\u0000\u0000\u0000\u0203\u0205\u0001\u0000\u0000\u0000\u0204\u0202\u0001"+
		"\u0000\u0000\u0000\u0205\u0206\u0005\u0017\u0000\u0000\u0206\u020a\u0005"+
		"\u0001\u0000\u0000\u0207\u0209\u0005!\u0000\u0000\u0208\u0207\u0001\u0000"+
		"\u0000\u0000\u0209\u020c\u0001\u0000\u0000\u0000\u020a\u0208\u0001\u0000"+
		"\u0000\u0000\u020a\u020b\u0001\u0000\u0000\u0000\u020b\u020d\u0001\u0000"+
		"\u0000\u0000\u020c\u020a\u0001\u0000\u0000\u0000\u020d\u0211\u0003\b\u0004"+
		"\u0000\u020e\u0210\u0005!\u0000\u0000\u020f\u020e\u0001\u0000\u0000\u0000"+
		"\u0210\u0213\u0001\u0000\u0000\u0000\u0211\u020f\u0001\u0000\u0000\u0000"+
		"\u0211\u0212\u0001\u0000\u0000\u0000\u0212\u0214\u0001\u0000\u0000\u0000"+
		"\u0213\u0211\u0001\u0000\u0000\u0000\u0214\u0218\u0005\u0003\u0000\u0000"+
		"\u0215\u0217\u0005!\u0000\u0000\u0216\u0215\u0001\u0000\u0000\u0000\u0217"+
		"\u021a\u0001\u0000\u0000\u0000\u0218\u0216\u0001\u0000\u0000\u0000\u0218"+
		"\u0219\u0001\u0000\u0000\u0000\u0219\u021b\u0001\u0000\u0000\u0000\u021a"+
		"\u0218\u0001\u0000\u0000\u0000\u021b\u021f\u0003\b\u0004\u0000\u021c\u021e"+
		"\u0005!\u0000\u0000\u021d\u021c\u0001\u0000\u0000\u0000\u021e\u0221\u0001"+
		"\u0000\u0000\u0000\u021f\u021d\u0001\u0000\u0000\u0000\u021f\u0220\u0001"+
		"\u0000\u0000\u0000\u0220\u0222\u0001\u0000\u0000\u0000\u0221\u021f\u0001"+
		"\u0000\u0000\u0000\u0222\u0226\u0005\u0002\u0000\u0000\u0223\u0225\u0005"+
		"!\u0000\u0000\u0224\u0223\u0001\u0000\u0000\u0000\u0225\u0228\u0001\u0000"+
		"\u0000\u0000\u0226\u0224\u0001\u0000\u0000\u0000\u0226\u0227\u0001\u0000"+
		"\u0000\u0000\u0227\u022a\u0001\u0000\u0000\u0000\u0228\u0226\u0001\u0000"+
		"\u0000\u0000\u0229\u0106\u0001\u0000\u0000\u0000\u0229\u0122\u0001\u0000"+
		"\u0000\u0000\u0229\u013e\u0001\u0000\u0000\u0000\u0229\u015a\u0001\u0000"+
		"\u0000\u0000\u0229\u0176\u0001\u0000\u0000\u0000\u0229\u0192\u0001\u0000"+
		"\u0000\u0000\u0229\u01ae\u0001\u0000\u0000\u0000\u0229\u01ca\u0001\u0000"+
		"\u0000\u0000\u0229\u01e6\u0001\u0000\u0000\u0000\u0229\u0202\u0001\u0000"+
		"\u0000\u0000\u022a\u0011\u0001\u0000\u0000\u0000\u022b\u022d\u0005!\u0000"+
		"\u0000\u022c\u022b\u0001\u0000\u0000\u0000\u022d\u0230\u0001\u0000\u0000"+
		"\u0000\u022e\u022c\u0001\u0000\u0000\u0000\u022e\u022f\u0001\u0000\u0000"+
		"\u0000\u022f\u0231\u0001\u0000\u0000\u0000\u0230\u022e\u0001\u0000\u0000"+
		"\u0000\u0231\u0232\u0005\u000f\u0000\u0000\u0232\u0233\u0005\u0001\u0000"+
		"\u0000\u0233\u0234\u0003\b\u0004\u0000\u0234\u0235\u0005\u0003\u0000\u0000"+
		"\u0235\u023a\u0003\b\u0004\u0000\u0236\u0237\u0005\u0003\u0000\u0000\u0237"+
		"\u0239\u0003\b\u0004\u0000\u0238\u0236\u0001\u0000\u0000\u0000\u0239\u023c"+
		"\u0001\u0000\u0000\u0000\u023a\u0238\u0001\u0000\u0000\u0000\u023a\u023b"+
		"\u0001\u0000\u0000\u0000\u023b\u023d\u0001\u0000\u0000\u0000\u023c\u023a"+
		"\u0001\u0000\u0000\u0000\u023d\u023e\u0005\u0002\u0000\u0000\u023e\u0268"+
		"\u0001\u0000\u0000\u0000\u023f\u0241\u0005!\u0000\u0000\u0240\u023f\u0001"+
		"\u0000\u0000\u0000\u0241\u0244\u0001\u0000\u0000\u0000\u0242\u0240\u0001"+
		"\u0000\u0000\u0000\u0242\u0243\u0001\u0000\u0000\u0000\u0243\u0245\u0001"+
		"\u0000\u0000\u0000\u0244\u0242\u0001\u0000\u0000\u0000\u0245\u0246\u0005"+
		"\u0011\u0000\u0000\u0246\u0247\u0005\u0001\u0000\u0000\u0247\u0248\u0003"+
		"\b\u0004\u0000\u0248\u0249\u0005\u0003\u0000\u0000\u0249\u024e\u0003\b"+
		"\u0004\u0000\u024a\u024b\u0005\u0003\u0000\u0000\u024b\u024d\u0003\b\u0004"+
		"\u0000\u024c\u024a\u0001\u0000\u0000\u0000\u024d\u0250\u0001\u0000\u0000"+
		"\u0000\u024e\u024c\u0001\u0000\u0000\u0000\u024e\u024f\u0001\u0000\u0000"+
		"\u0000\u024f\u0251\u0001\u0000\u0000\u0000\u0250\u024e\u0001\u0000\u0000"+
		"\u0000\u0251\u0252\u0005\u0002\u0000\u0000\u0252\u0268\u0001\u0000\u0000"+
		"\u0000\u0253\u0255\u0005!\u0000\u0000\u0254\u0253\u0001\u0000\u0000\u0000"+
		"\u0255\u0258\u0001\u0000\u0000\u0000\u0256\u0254\u0001\u0000\u0000\u0000"+
		"\u0256\u0257\u0001\u0000\u0000\u0000\u0257\u0259\u0001\u0000\u0000\u0000"+
		"\u0258\u0256\u0001\u0000\u0000\u0000\u0259\u025a\u0005\u0013\u0000\u0000"+
		"\u025a\u025b\u0005\u0001\u0000\u0000\u025b\u025c\u0003\b\u0004\u0000\u025c"+
		"\u025d\u0005\u0003\u0000\u0000\u025d\u0262\u0003\b\u0004\u0000\u025e\u025f"+
		"\u0005\u0003\u0000\u0000\u025f\u0261\u0003\b\u0004\u0000\u0260\u025e\u0001"+
		"\u0000\u0000\u0000\u0261\u0264\u0001\u0000\u0000\u0000\u0262\u0260\u0001"+
		"\u0000\u0000\u0000\u0262\u0263\u0001\u0000\u0000\u0000\u0263\u0265\u0001"+
		"\u0000\u0000\u0000\u0264\u0262\u0001\u0000\u0000\u0000\u0265\u0266\u0005"+
		"\u0002\u0000\u0000\u0266\u0268\u0001\u0000\u0000\u0000\u0267\u022e\u0001"+
		"\u0000\u0000\u0000\u0267\u0242\u0001\u0000\u0000\u0000\u0267\u0256\u0001"+
		"\u0000\u0000\u0000\u0268\u0013\u0001\u0000\u0000\u0000\u0269\u026b\u0005"+
		"!\u0000\u0000\u026a\u0269\u0001\u0000\u0000\u0000\u026b\u026e\u0001\u0000"+
		"\u0000\u0000\u026c\u026a\u0001\u0000\u0000\u0000\u026c\u026d\u0001\u0000"+
		"\u0000\u0000\u026d\u026f\u0001\u0000\u0000\u0000\u026e\u026c\u0001\u0000"+
		"\u0000\u0000\u026f\u0270\u0005\u0012\u0000\u0000\u0270\u0274\u0005\u0001"+
		"\u0000\u0000\u0271\u0273\u0005!\u0000\u0000\u0272\u0271\u0001\u0000\u0000"+
		"\u0000\u0273\u0276\u0001\u0000\u0000\u0000\u0274\u0272\u0001\u0000\u0000"+
		"\u0000\u0274\u0275\u0001\u0000\u0000\u0000\u0275\u0277\u0001\u0000\u0000"+
		"\u0000\u0276\u0274\u0001\u0000\u0000\u0000\u0277\u027b\u0003\b\u0004\u0000"+
		"\u0278\u027a\u0005!\u0000\u0000\u0279\u0278\u0001\u0000\u0000\u0000\u027a"+
		"\u027d\u0001\u0000\u0000\u0000\u027b\u0279\u0001\u0000\u0000\u0000\u027b"+
		"\u027c\u0001\u0000\u0000\u0000\u027c\u027e\u0001\u0000\u0000\u0000\u027d"+
		"\u027b\u0001\u0000\u0000\u0000\u027e\u0282\u0005\u0002\u0000\u0000\u027f"+
		"\u0281\u0005!\u0000\u0000\u0280\u027f\u0001\u0000\u0000\u0000\u0281\u0284"+
		"\u0001\u0000\u0000\u0000\u0282\u0280\u0001\u0000\u0000\u0000\u0282\u0283"+
		"\u0001\u0000\u0000\u0000\u0283\u02a2\u0001\u0000\u0000\u0000\u0284\u0282"+
		"\u0001\u0000\u0000\u0000\u0285\u0287\u0005!\u0000\u0000\u0286\u0285\u0001"+
		"\u0000\u0000\u0000\u0287\u028a\u0001\u0000\u0000\u0000\u0288\u0286\u0001"+
		"\u0000\u0000\u0000\u0288\u0289\u0001\u0000\u0000\u0000\u0289\u028b\u0001"+
		"\u0000\u0000\u0000\u028a\u0288\u0001\u0000\u0000\u0000\u028b\u028c\u0005"+
		"\u0014\u0000\u0000\u028c\u0290\u0005\u0001\u0000\u0000\u028d\u028f\u0005"+
		"!\u0000\u0000\u028e\u028d\u0001\u0000\u0000\u0000\u028f\u0292\u0001\u0000"+
		"\u0000\u0000\u0290\u028e\u0001\u0000\u0000\u0000\u0290\u0291\u0001\u0000"+
		"\u0000\u0000\u0291\u0293\u0001\u0000\u0000\u0000\u0292\u0290\u0001\u0000"+
		"\u0000\u0000\u0293\u0297\u0003\b\u0004\u0000\u0294\u0296\u0005!\u0000"+
		"\u0000\u0295\u0294\u0001\u0000\u0000\u0000\u0296\u0299\u0001\u0000\u0000"+
		"\u0000\u0297\u0295\u0001\u0000\u0000\u0000\u0297\u0298\u0001\u0000\u0000"+
		"\u0000\u0298\u029a\u0001\u0000\u0000\u0000\u0299\u0297\u0001\u0000\u0000"+
		"\u0000\u029a\u029e\u0005\u0002\u0000\u0000\u029b\u029d\u0005!\u0000\u0000"+
		"\u029c\u029b\u0001\u0000\u0000\u0000\u029d\u02a0\u0001\u0000\u0000\u0000"+
		"\u029e\u029c\u0001\u0000\u0000\u0000\u029e\u029f\u0001\u0000\u0000\u0000"+
		"\u029f\u02a2\u0001\u0000\u0000\u0000\u02a0\u029e\u0001\u0000\u0000\u0000"+
		"\u02a1\u026c\u0001\u0000\u0000\u0000\u02a1\u0288\u0001\u0000\u0000\u0000"+
		"\u02a2\u0015\u0001\u0000\u0000\u0000\u02a3\u02a4\u0005\u0007\u0000\u0000"+
		"\u02a4\u02a5\u0005 \u0000\u0000\u02a5\u02a6\u0005\u0007\u0000\u0000\u02a6"+
		"\u0017\u0001\u0000\u0000\u0000b\u001b\u001f$+3:BIPV\\dgls{\u0081\u0088"+
		"\u008b\u008f\u0093\u0095\u009a\u00a6\u00aa\u00b0\u00b4\u00bd\u00c4\u00cc"+
		"\u00d3\u00d7\u00d9\u00e0\u00e5\u00ea\u00f1\u00f6\u00fa\u0106\u010e\u0115"+
		"\u011c\u0122\u012a\u0131\u0138\u013e\u0146\u014d\u0154\u015a\u0162\u0169"+
		"\u0170\u0176\u017e\u0185\u018c\u0192\u019a\u01a1\u01a8\u01ae\u01b6\u01bd"+
		"\u01c4\u01ca\u01d2\u01d9\u01e0\u01e6\u01ee\u01f5\u01fc\u0202\u020a\u0211"+
		"\u0218\u021f\u0226\u0229\u022e\u023a\u0242\u024e\u0256\u0262\u0267\u026c"+
		"\u0274\u027b\u0282\u0288\u0290\u0297\u029e\u02a1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}