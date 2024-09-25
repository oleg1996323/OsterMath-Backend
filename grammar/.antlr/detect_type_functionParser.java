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
		WS=10, EOL=11, UINT=12, ADD=13, SUB=14, MUL=15, DIV=16, POW=17, SUMPRODUCT=18, 
		SUMPRODUCT_I=19, SUM=20, SUM_I=21, PRODUCT=22, PRODUCT_I=23, LN=24, LG=25, 
		LOG_X=26, EXP=27, SQRT=28, PI=29, COS=30, SIN=31, ASIN=32, ACOS=33, FACTORIAL=34, 
		QUOTE=35, ASTERISK=36, EXPONENT=37, FLOAT=38, ID_NUMBER=39, STRING=40;
	public static final int
		RULE_value_type = 0, RULE_input = 1, RULE_line_input = 2, RULE_node_access = 3, 
		RULE_variable = 4, RULE_expr = 5, RULE_array = 6, RULE_input_array = 7, 
		RULE_number = 8, RULE_constant = 9, RULE_function = 10, RULE_multiargfunction = 11, 
		RULE_rangefunction = 12, RULE_string = 13;
	private static String[] makeRuleNames() {
		return new String[] {
			"value_type", "input", "line_input", "node_access", "variable", "expr", 
			"array", "input_array", "number", "constant", "function", "multiargfunction", 
			"rangefunction", "string"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "';'", "'VAR('", "'['", "']'", "'\"'", null, null, 
			null, null, null, "'+'", "'-'", "'*'", "'/'", "'^'", null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "'''"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "VARIABLE", "DATABASE", 
			"WS", "EOL", "UINT", "ADD", "SUB", "MUL", "DIV", "POW", "SUMPRODUCT", 
			"SUMPRODUCT_I", "SUM", "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", "LOG_X", 
			"EXP", "SQRT", "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", "QUOTE", 
			"ASTERISK", "EXPONENT", "FLOAT", "ID_NUMBER", "STRING"
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
			setState(31);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(28);
				array();
				}
				break;
			case T__0:
			case T__3:
			case VARIABLE:
			case WS:
			case UINT:
			case ADD:
			case SUB:
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
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(29);
				expr(0);
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 3);
				{
				setState(30);
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
	public static class InputContext extends ParserRuleContext {
		public List<Line_inputContext> line_input() {
			return getRuleContexts(Line_inputContext.class);
		}
		public Line_inputContext line_input(int i) {
			return getRuleContext(Line_inputContext.class,i);
		}
		public TerminalNode EOF() { return getToken(detect_type_functionParser.EOF, 0); }
		public InputContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_input; }
	}

	public final InputContext input() throws RecognitionException {
		InputContext _localctx = new InputContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_input);
		int _la;
		try {
			setState(39);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__3:
			case T__4:
			case VARIABLE:
			case WS:
			case UINT:
			case ADD:
			case SUB:
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
			case FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(34); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(33);
					line_input();
					}
					}
					setState(36); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 309236888882L) != 0) );
				}
				break;
			case EOF:
				enterOuterAlt(_localctx, 2);
				{
				setState(38);
				match(EOF);
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
		enterRule(_localctx, 4, RULE_line_input);
		try {
			setState(43);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				enterOuterAlt(_localctx, 1);
				{
				setState(41);
				array();
				}
				break;
			case T__0:
			case T__3:
			case VARIABLE:
			case WS:
			case UINT:
			case ADD:
			case SUB:
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
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(42);
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
		enterRule(_localctx, 6, RULE_node_access);
		int _la;
		try {
			int _alt;
			setState(115);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(48);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(45);
					match(WS);
					}
					}
					setState(50);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				{
				setState(51);
				match(T__0);
				setState(55);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(52);
					match(WS);
					}
					}
					setState(57);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(58);
				match(T__1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(59);
				match(T__0);
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(60);
					match(WS);
					}
					}
					setState(65);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(66);
				match(UINT);
				setState(70);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(67);
					match(WS);
					}
					}
					setState(72);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(73);
				match(T__1);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(74);
				match(T__0);
				setState(78);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(75);
					match(WS);
					}
					}
					setState(80);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(81);
				match(UINT);
				setState(85);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(82);
						match(WS);
						}
						} 
					}
					setState(87);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
				}
				setState(98);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(88);
					match(T__2);
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
					match(UINT);
					}
					}
					setState(100);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(104);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(101);
					match(WS);
					}
					}
					setState(106);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(107);
				match(T__1);
				}
				setState(112);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(109);
						match(WS);
						}
						} 
					}
					setState(114);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
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
		enterRule(_localctx, 8, RULE_variable);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(120);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WS) {
				{
				{
				setState(117);
				match(WS);
				}
				}
				setState(122);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(161);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				{
				{
				setState(123);
				match(T__3);
				setState(151);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
				case 1:
					{
					setState(127);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(124);
						match(WS);
						}
						}
						setState(129);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(130);
					match(DATABASE);
					setState(131);
					match(VARIABLE);
					setState(135);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(132);
						match(WS);
						}
						}
						setState(137);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				case 2:
					{
					setState(141);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(138);
						match(WS);
						}
						}
						setState(143);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(144);
					match(VARIABLE);
					setState(148);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==WS) {
						{
						{
						setState(145);
						match(WS);
						}
						}
						setState(150);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				}
				setState(153);
				match(T__1);
				setState(155);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
				case 1:
					{
					setState(154);
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
				setState(157);
				match(VARIABLE);
				setState(159);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
				case 1:
					{
					setState(158);
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
			setState(166);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(163);
					match(WS);
					}
					} 
				}
				setState(168);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
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
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				{
				_localctx = new ParensContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(170);
				match(T__0);
				setState(171);
				expr(0);
				setState(172);
				match(T__1);
				}
				break;
			case 2:
				{
				_localctx = new VariableInExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(174);
				variable();
				}
				break;
			case 3:
				{
				_localctx = new FunctionCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(178);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
				case 1:
					{
					setState(175);
					function();
					}
					break;
				case 2:
					{
					setState(176);
					multiargfunction();
					}
					break;
				case 3:
					{
					setState(177);
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
				setState(182);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case FLOAT:
					{
					setState(180);
					number();
					}
					break;
				case EXP:
				case PI:
					{
					setState(181);
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
				setState(184);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(188);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(185);
						match(WS);
						}
						} 
					}
					setState(190);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				}
				setState(191);
				expr(4);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(229);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(227);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
					case 1:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(194);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(195);
						match(POW);
						setState(196);
						expr(4);
						}
						break;
					case 2:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(197);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(201);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==WS) {
							{
							{
							setState(198);
							match(WS);
							}
							}
							setState(203);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(204);
						_la = _input.LA(1);
						if ( !(_la==MUL || _la==DIV) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(208);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(205);
								match(WS);
								}
								} 
							}
							setState(210);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
						}
						setState(211);
						expr(3);
						}
						break;
					case 3:
						{
						_localctx = new BinaryOpContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(212);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(216);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==WS) {
							{
							{
							setState(213);
							match(WS);
							}
							}
							setState(218);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(219);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(223);
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
						while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
							if ( _alt==1 ) {
								{
								{
								setState(220);
								match(WS);
								}
								} 
							}
							setState(225);
							_errHandler.sync(this);
							_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
						}
						setState(226);
						expr(2);
						}
						break;
					}
					} 
				}
				setState(231);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
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
		public List<Input_arrayContext> input_array() {
			return getRuleContexts(Input_arrayContext.class);
		}
		public Input_arrayContext input_array(int i) {
			return getRuleContext(Input_arrayContext.class,i);
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
		enterRule(_localctx, 12, RULE_array);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			match(T__4);
			setState(236);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(233);
					match(WS);
					}
					} 
				}
				setState(238);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
			}
			setState(239);
			input_array();
			setState(243);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==WS) {
				{
				{
				setState(240);
				match(WS);
				}
				}
				setState(245);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(256);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(246);
				match(T__2);
				setState(250);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(247);
						match(WS);
						}
						} 
					}
					setState(252);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
				}
				setState(253);
				input_array();
				}
				}
				setState(258);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(259);
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
	public static class Input_arrayContext extends ParserRuleContext {
		public Input_arrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_input_array; }
	 
		public Input_arrayContext() { }
		public void copyFrom(Input_arrayContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemArrayContext extends Input_arrayContext {
		public ArrayContext array() {
			return getRuleContext(ArrayContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ItemArrayContext(Input_arrayContext ctx) { copyFrom(ctx); }
	}

	public final Input_arrayContext input_array() throws RecognitionException {
		Input_arrayContext _localctx = new Input_arrayContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_input_array);
		try {
			setState(263);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				_localctx = new ItemArrayContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(261);
				array();
				}
				break;
			case T__0:
			case T__3:
			case VARIABLE:
			case WS:
			case UINT:
			case ADD:
			case SUB:
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
			case FLOAT:
				_localctx = new ItemArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(262);
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
		enterRule(_localctx, 16, RULE_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(265);
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
		enterRule(_localctx, 18, RULE_constant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(267);
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
		enterRule(_localctx, 20, RULE_function);
		int _la;
		try {
			int _alt;
			setState(563);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,82,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(272);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(269);
					match(WS);
					}
					}
					setState(274);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(275);
				match(LN);
				setState(276);
				match(T__0);
				setState(280);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,41,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(277);
						match(WS);
						}
						} 
					}
					setState(282);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,41,_ctx);
				}
				setState(283);
				expr(0);
				setState(287);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(284);
					match(WS);
					}
					}
					setState(289);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(290);
				match(T__1);
				setState(294);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(291);
						match(WS);
						}
						} 
					}
					setState(296);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,43,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(300);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(297);
					match(WS);
					}
					}
					setState(302);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(303);
				match(LG);
				setState(304);
				match(T__0);
				setState(308);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(305);
						match(WS);
						}
						} 
					}
					setState(310);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
				}
				setState(311);
				expr(0);
				setState(315);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(312);
					match(WS);
					}
					}
					setState(317);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(318);
				match(T__1);
				setState(322);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(319);
						match(WS);
						}
						} 
					}
					setState(324);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,47,_ctx);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(328);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(325);
					match(WS);
					}
					}
					setState(330);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(331);
				match(EXP);
				setState(332);
				match(T__0);
				setState(336);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,49,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(333);
						match(WS);
						}
						} 
					}
					setState(338);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,49,_ctx);
				}
				setState(339);
				expr(0);
				setState(343);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(340);
					match(WS);
					}
					}
					setState(345);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(346);
				match(T__1);
				setState(350);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,51,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(347);
						match(WS);
						}
						} 
					}
					setState(352);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,51,_ctx);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(356);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(353);
					match(WS);
					}
					}
					setState(358);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(359);
				match(SQRT);
				setState(360);
				match(T__0);
				setState(364);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(361);
						match(WS);
						}
						} 
					}
					setState(366);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
				}
				setState(367);
				expr(0);
				setState(371);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(368);
					match(WS);
					}
					}
					setState(373);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(374);
				match(T__1);
				setState(378);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,55,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(375);
						match(WS);
						}
						} 
					}
					setState(380);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,55,_ctx);
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(384);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(381);
					match(WS);
					}
					}
					setState(386);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(387);
				match(COS);
				setState(388);
				match(T__0);
				setState(392);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,57,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(389);
						match(WS);
						}
						} 
					}
					setState(394);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,57,_ctx);
				}
				setState(395);
				expr(0);
				setState(399);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(396);
					match(WS);
					}
					}
					setState(401);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(402);
				match(T__1);
				setState(406);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,59,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(403);
						match(WS);
						}
						} 
					}
					setState(408);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,59,_ctx);
				}
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(412);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(409);
					match(WS);
					}
					}
					setState(414);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(415);
				match(SIN);
				setState(416);
				match(T__0);
				setState(420);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,61,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(417);
						match(WS);
						}
						} 
					}
					setState(422);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,61,_ctx);
				}
				setState(423);
				expr(0);
				setState(427);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(424);
					match(WS);
					}
					}
					setState(429);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(430);
				match(T__1);
				setState(434);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,63,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(431);
						match(WS);
						}
						} 
					}
					setState(436);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,63,_ctx);
				}
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(440);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(437);
					match(WS);
					}
					}
					setState(442);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(443);
				match(ACOS);
				setState(444);
				match(T__0);
				setState(448);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,65,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(445);
						match(WS);
						}
						} 
					}
					setState(450);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,65,_ctx);
				}
				setState(451);
				expr(0);
				setState(455);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(452);
					match(WS);
					}
					}
					setState(457);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(458);
				match(T__1);
				setState(462);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,67,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(459);
						match(WS);
						}
						} 
					}
					setState(464);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,67,_ctx);
				}
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(468);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(465);
					match(WS);
					}
					}
					setState(470);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(471);
				match(ASIN);
				setState(472);
				match(T__0);
				setState(476);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,69,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(473);
						match(WS);
						}
						} 
					}
					setState(478);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,69,_ctx);
				}
				setState(479);
				expr(0);
				setState(483);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(480);
					match(WS);
					}
					}
					setState(485);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(486);
				match(T__1);
				setState(490);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,71,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(487);
						match(WS);
						}
						} 
					}
					setState(492);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,71,_ctx);
				}
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(496);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(493);
					match(WS);
					}
					}
					setState(498);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(499);
				match(FACTORIAL);
				setState(500);
				match(T__0);
				setState(504);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,73,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(501);
						match(WS);
						}
						} 
					}
					setState(506);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,73,_ctx);
				}
				setState(507);
				expr(0);
				setState(511);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(508);
					match(WS);
					}
					}
					setState(513);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(514);
				match(T__1);
				setState(518);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,75,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(515);
						match(WS);
						}
						} 
					}
					setState(520);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,75,_ctx);
				}
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(524);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(521);
					match(WS);
					}
					}
					setState(526);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(527);
				match(LOG_X);
				setState(528);
				match(T__0);
				setState(532);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,77,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(529);
						match(WS);
						}
						} 
					}
					setState(534);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,77,_ctx);
				}
				setState(535);
				expr(0);
				setState(539);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(536);
					match(WS);
					}
					}
					setState(541);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(542);
				match(T__2);
				setState(546);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,79,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(543);
						match(WS);
						}
						} 
					}
					setState(548);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,79,_ctx);
				}
				setState(549);
				expr(0);
				setState(553);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(550);
					match(WS);
					}
					}
					setState(555);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(556);
				match(T__1);
				setState(560);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,81,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(557);
						match(WS);
						}
						} 
					}
					setState(562);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,81,_ctx);
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
		enterRule(_localctx, 22, RULE_multiargfunction);
		int _la;
		try {
			setState(625);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,89,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(568);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(565);
					match(WS);
					}
					}
					setState(570);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(571);
				match(SUMPRODUCT);
				setState(572);
				match(T__0);
				setState(573);
				expr(0);
				setState(574);
				match(T__2);
				setState(575);
				expr(0);
				setState(580);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(576);
					match(T__2);
					setState(577);
					expr(0);
					}
					}
					setState(582);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(583);
				match(T__1);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(588);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(585);
					match(WS);
					}
					}
					setState(590);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(591);
				match(SUM);
				setState(592);
				match(T__0);
				setState(593);
				expr(0);
				setState(594);
				match(T__2);
				setState(595);
				expr(0);
				setState(600);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(596);
					match(T__2);
					setState(597);
					expr(0);
					}
					}
					setState(602);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(603);
				match(T__1);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(608);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(605);
					match(WS);
					}
					}
					setState(610);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(611);
				match(PRODUCT);
				setState(612);
				match(T__0);
				setState(613);
				expr(0);
				setState(614);
				match(T__2);
				setState(615);
				expr(0);
				setState(620);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(616);
					match(T__2);
					setState(617);
					expr(0);
					}
					}
					setState(622);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(623);
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
		enterRule(_localctx, 24, RULE_rangefunction);
		int _la;
		try {
			int _alt;
			setState(683);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,98,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(630);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(627);
					match(WS);
					}
					}
					setState(632);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(633);
				match(SUM_I);
				setState(634);
				match(T__0);
				setState(638);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,91,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(635);
						match(WS);
						}
						} 
					}
					setState(640);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,91,_ctx);
				}
				setState(641);
				expr(0);
				setState(645);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(642);
					match(WS);
					}
					}
					setState(647);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(648);
				match(T__1);
				setState(652);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,93,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(649);
						match(WS);
						}
						} 
					}
					setState(654);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,93,_ctx);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(658);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(655);
					match(WS);
					}
					}
					setState(660);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(661);
				match(PRODUCT_I);
				setState(662);
				match(T__0);
				setState(666);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,95,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(663);
						match(WS);
						}
						} 
					}
					setState(668);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,95,_ctx);
				}
				setState(669);
				expr(0);
				setState(673);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==WS) {
					{
					{
					setState(670);
					match(WS);
					}
					}
					setState(675);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(676);
				match(T__1);
				setState(680);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,97,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(677);
						match(WS);
						}
						} 
					}
					setState(682);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,97,_ctx);
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
		enterRule(_localctx, 26, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(685);
			match(T__6);
			setState(686);
			match(STRING);
			setState(687);
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
		case 5:
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
		"\u0004\u0001(\u02b2\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0001\u0000\u0001\u0000\u0001\u0000\u0003\u0000"+
		" \b\u0000\u0001\u0001\u0004\u0001#\b\u0001\u000b\u0001\f\u0001$\u0001"+
		"\u0001\u0003\u0001(\b\u0001\u0001\u0002\u0001\u0002\u0003\u0002,\b\u0002"+
		"\u0001\u0003\u0005\u0003/\b\u0003\n\u0003\f\u00032\t\u0003\u0001\u0003"+
		"\u0001\u0003\u0005\u00036\b\u0003\n\u0003\f\u00039\t\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0005\u0003>\b\u0003\n\u0003\f\u0003A\t\u0003"+
		"\u0001\u0003\u0001\u0003\u0005\u0003E\b\u0003\n\u0003\f\u0003H\t\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003M\b\u0003\n\u0003\f\u0003"+
		"P\t\u0003\u0001\u0003\u0001\u0003\u0005\u0003T\b\u0003\n\u0003\f\u0003"+
		"W\t\u0003\u0001\u0003\u0001\u0003\u0005\u0003[\b\u0003\n\u0003\f\u0003"+
		"^\t\u0003\u0001\u0003\u0005\u0003a\b\u0003\n\u0003\f\u0003d\t\u0003\u0001"+
		"\u0003\u0005\u0003g\b\u0003\n\u0003\f\u0003j\t\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0005\u0003o\b\u0003\n\u0003\f\u0003r\t\u0003\u0003"+
		"\u0003t\b\u0003\u0001\u0004\u0005\u0004w\b\u0004\n\u0004\f\u0004z\t\u0004"+
		"\u0001\u0004\u0001\u0004\u0005\u0004~\b\u0004\n\u0004\f\u0004\u0081\t"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u0086\b\u0004\n"+
		"\u0004\f\u0004\u0089\t\u0004\u0001\u0004\u0005\u0004\u008c\b\u0004\n\u0004"+
		"\f\u0004\u008f\t\u0004\u0001\u0004\u0001\u0004\u0005\u0004\u0093\b\u0004"+
		"\n\u0004\f\u0004\u0096\t\u0004\u0003\u0004\u0098\b\u0004\u0001\u0004\u0001"+
		"\u0004\u0003\u0004\u009c\b\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u00a0"+
		"\b\u0004\u0003\u0004\u00a2\b\u0004\u0001\u0004\u0005\u0004\u00a5\b\u0004"+
		"\n\u0004\f\u0004\u00a8\t\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003"+
		"\u0005\u00b3\b\u0005\u0001\u0005\u0001\u0005\u0003\u0005\u00b7\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005\u00bb\b\u0005\n\u0005\f\u0005\u00be"+
		"\t\u0005\u0001\u0005\u0003\u0005\u00c1\b\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005\u00c8\b\u0005\n\u0005"+
		"\f\u0005\u00cb\t\u0005\u0001\u0005\u0001\u0005\u0005\u0005\u00cf\b\u0005"+
		"\n\u0005\f\u0005\u00d2\t\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005"+
		"\u0005\u00d7\b\u0005\n\u0005\f\u0005\u00da\t\u0005\u0001\u0005\u0001\u0005"+
		"\u0005\u0005\u00de\b\u0005\n\u0005\f\u0005\u00e1\t\u0005\u0001\u0005\u0005"+
		"\u0005\u00e4\b\u0005\n\u0005\f\u0005\u00e7\t\u0005\u0001\u0006\u0001\u0006"+
		"\u0005\u0006\u00eb\b\u0006\n\u0006\f\u0006\u00ee\t\u0006\u0001\u0006\u0001"+
		"\u0006\u0005\u0006\u00f2\b\u0006\n\u0006\f\u0006\u00f5\t\u0006\u0001\u0006"+
		"\u0001\u0006\u0005\u0006\u00f9\b\u0006\n\u0006\f\u0006\u00fc\t\u0006\u0001"+
		"\u0006\u0005\u0006\u00ff\b\u0006\n\u0006\f\u0006\u0102\t\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0007\u0001\u0007\u0003\u0007\u0108\b\u0007\u0001\b"+
		"\u0001\b\u0001\t\u0001\t\u0001\n\u0005\n\u010f\b\n\n\n\f\n\u0112\t\n\u0001"+
		"\n\u0001\n\u0001\n\u0005\n\u0117\b\n\n\n\f\n\u011a\t\n\u0001\n\u0001\n"+
		"\u0005\n\u011e\b\n\n\n\f\n\u0121\t\n\u0001\n\u0001\n\u0005\n\u0125\b\n"+
		"\n\n\f\n\u0128\t\n\u0001\n\u0005\n\u012b\b\n\n\n\f\n\u012e\t\n\u0001\n"+
		"\u0001\n\u0001\n\u0005\n\u0133\b\n\n\n\f\n\u0136\t\n\u0001\n\u0001\n\u0005"+
		"\n\u013a\b\n\n\n\f\n\u013d\t\n\u0001\n\u0001\n\u0005\n\u0141\b\n\n\n\f"+
		"\n\u0144\t\n\u0001\n\u0005\n\u0147\b\n\n\n\f\n\u014a\t\n\u0001\n\u0001"+
		"\n\u0001\n\u0005\n\u014f\b\n\n\n\f\n\u0152\t\n\u0001\n\u0001\n\u0005\n"+
		"\u0156\b\n\n\n\f\n\u0159\t\n\u0001\n\u0001\n\u0005\n\u015d\b\n\n\n\f\n"+
		"\u0160\t\n\u0001\n\u0005\n\u0163\b\n\n\n\f\n\u0166\t\n\u0001\n\u0001\n"+
		"\u0001\n\u0005\n\u016b\b\n\n\n\f\n\u016e\t\n\u0001\n\u0001\n\u0005\n\u0172"+
		"\b\n\n\n\f\n\u0175\t\n\u0001\n\u0001\n\u0005\n\u0179\b\n\n\n\f\n\u017c"+
		"\t\n\u0001\n\u0005\n\u017f\b\n\n\n\f\n\u0182\t\n\u0001\n\u0001\n\u0001"+
		"\n\u0005\n\u0187\b\n\n\n\f\n\u018a\t\n\u0001\n\u0001\n\u0005\n\u018e\b"+
		"\n\n\n\f\n\u0191\t\n\u0001\n\u0001\n\u0005\n\u0195\b\n\n\n\f\n\u0198\t"+
		"\n\u0001\n\u0005\n\u019b\b\n\n\n\f\n\u019e\t\n\u0001\n\u0001\n\u0001\n"+
		"\u0005\n\u01a3\b\n\n\n\f\n\u01a6\t\n\u0001\n\u0001\n\u0005\n\u01aa\b\n"+
		"\n\n\f\n\u01ad\t\n\u0001\n\u0001\n\u0005\n\u01b1\b\n\n\n\f\n\u01b4\t\n"+
		"\u0001\n\u0005\n\u01b7\b\n\n\n\f\n\u01ba\t\n\u0001\n\u0001\n\u0001\n\u0005"+
		"\n\u01bf\b\n\n\n\f\n\u01c2\t\n\u0001\n\u0001\n\u0005\n\u01c6\b\n\n\n\f"+
		"\n\u01c9\t\n\u0001\n\u0001\n\u0005\n\u01cd\b\n\n\n\f\n\u01d0\t\n\u0001"+
		"\n\u0005\n\u01d3\b\n\n\n\f\n\u01d6\t\n\u0001\n\u0001\n\u0001\n\u0005\n"+
		"\u01db\b\n\n\n\f\n\u01de\t\n\u0001\n\u0001\n\u0005\n\u01e2\b\n\n\n\f\n"+
		"\u01e5\t\n\u0001\n\u0001\n\u0005\n\u01e9\b\n\n\n\f\n\u01ec\t\n\u0001\n"+
		"\u0005\n\u01ef\b\n\n\n\f\n\u01f2\t\n\u0001\n\u0001\n\u0001\n\u0005\n\u01f7"+
		"\b\n\n\n\f\n\u01fa\t\n\u0001\n\u0001\n\u0005\n\u01fe\b\n\n\n\f\n\u0201"+
		"\t\n\u0001\n\u0001\n\u0005\n\u0205\b\n\n\n\f\n\u0208\t\n\u0001\n\u0005"+
		"\n\u020b\b\n\n\n\f\n\u020e\t\n\u0001\n\u0001\n\u0001\n\u0005\n\u0213\b"+
		"\n\n\n\f\n\u0216\t\n\u0001\n\u0001\n\u0005\n\u021a\b\n\n\n\f\n\u021d\t"+
		"\n\u0001\n\u0001\n\u0005\n\u0221\b\n\n\n\f\n\u0224\t\n\u0001\n\u0001\n"+
		"\u0005\n\u0228\b\n\n\n\f\n\u022b\t\n\u0001\n\u0001\n\u0005\n\u022f\b\n"+
		"\n\n\f\n\u0232\t\n\u0003\n\u0234\b\n\u0001\u000b\u0005\u000b\u0237\b\u000b"+
		"\n\u000b\f\u000b\u023a\t\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u0243\b\u000b\n"+
		"\u000b\f\u000b\u0246\t\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005"+
		"\u000b\u024b\b\u000b\n\u000b\f\u000b\u024e\t\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b"+
		"\u0257\b\u000b\n\u000b\f\u000b\u025a\t\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0005\u000b\u025f\b\u000b\n\u000b\f\u000b\u0262\t\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0005\u000b\u026b\b\u000b\n\u000b\f\u000b\u026e\t\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u0272\b\u000b\u0001\f\u0005\f\u0275\b\f\n\f\f\f\u0278"+
		"\t\f\u0001\f\u0001\f\u0001\f\u0005\f\u027d\b\f\n\f\f\f\u0280\t\f\u0001"+
		"\f\u0001\f\u0005\f\u0284\b\f\n\f\f\f\u0287\t\f\u0001\f\u0001\f\u0005\f"+
		"\u028b\b\f\n\f\f\f\u028e\t\f\u0001\f\u0005\f\u0291\b\f\n\f\f\f\u0294\t"+
		"\f\u0001\f\u0001\f\u0001\f\u0005\f\u0299\b\f\n\f\f\f\u029c\t\f\u0001\f"+
		"\u0001\f\u0005\f\u02a0\b\f\n\f\f\f\u02a3\t\f\u0001\f\u0001\f\u0005\f\u02a7"+
		"\b\f\n\f\f\f\u02aa\t\f\u0003\f\u02ac\b\f\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0000\u0001\n\u000e\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010"+
		"\u0012\u0014\u0016\u0018\u001a\u0000\u0004\u0001\u0000\r\u000e\u0001\u0000"+
		"\u000f\u0010\u0002\u0000\f\f&&\u0002\u0000\u001b\u001b\u001d\u001d\u0316"+
		"\u0000\u001f\u0001\u0000\u0000\u0000\u0002\'\u0001\u0000\u0000\u0000\u0004"+
		"+\u0001\u0000\u0000\u0000\u0006s\u0001\u0000\u0000\u0000\bx\u0001\u0000"+
		"\u0000\u0000\n\u00c0\u0001\u0000\u0000\u0000\f\u00e8\u0001\u0000\u0000"+
		"\u0000\u000e\u0107\u0001\u0000\u0000\u0000\u0010\u0109\u0001\u0000\u0000"+
		"\u0000\u0012\u010b\u0001\u0000\u0000\u0000\u0014\u0233\u0001\u0000\u0000"+
		"\u0000\u0016\u0271\u0001\u0000\u0000\u0000\u0018\u02ab\u0001\u0000\u0000"+
		"\u0000\u001a\u02ad\u0001\u0000\u0000\u0000\u001c \u0003\f\u0006\u0000"+
		"\u001d \u0003\n\u0005\u0000\u001e \u0003\u001a\r\u0000\u001f\u001c\u0001"+
		"\u0000\u0000\u0000\u001f\u001d\u0001\u0000\u0000\u0000\u001f\u001e\u0001"+
		"\u0000\u0000\u0000 \u0001\u0001\u0000\u0000\u0000!#\u0003\u0004\u0002"+
		"\u0000\"!\u0001\u0000\u0000\u0000#$\u0001\u0000\u0000\u0000$\"\u0001\u0000"+
		"\u0000\u0000$%\u0001\u0000\u0000\u0000%(\u0001\u0000\u0000\u0000&(\u0005"+
		"\u0000\u0000\u0001\'\"\u0001\u0000\u0000\u0000\'&\u0001\u0000\u0000\u0000"+
		"(\u0003\u0001\u0000\u0000\u0000),\u0003\f\u0006\u0000*,\u0003\n\u0005"+
		"\u0000+)\u0001\u0000\u0000\u0000+*\u0001\u0000\u0000\u0000,\u0005\u0001"+
		"\u0000\u0000\u0000-/\u0005\n\u0000\u0000.-\u0001\u0000\u0000\u0000/2\u0001"+
		"\u0000\u0000\u00000.\u0001\u0000\u0000\u000001\u0001\u0000\u0000\u0000"+
		"13\u0001\u0000\u0000\u000020\u0001\u0000\u0000\u000037\u0005\u0001\u0000"+
		"\u000046\u0005\n\u0000\u000054\u0001\u0000\u0000\u000069\u0001\u0000\u0000"+
		"\u000075\u0001\u0000\u0000\u000078\u0001\u0000\u0000\u00008:\u0001\u0000"+
		"\u0000\u000097\u0001\u0000\u0000\u0000:t\u0005\u0002\u0000\u0000;?\u0005"+
		"\u0001\u0000\u0000<>\u0005\n\u0000\u0000=<\u0001\u0000\u0000\u0000>A\u0001"+
		"\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000"+
		"@B\u0001\u0000\u0000\u0000A?\u0001\u0000\u0000\u0000BF\u0005\f\u0000\u0000"+
		"CE\u0005\n\u0000\u0000DC\u0001\u0000\u0000\u0000EH\u0001\u0000\u0000\u0000"+
		"FD\u0001\u0000\u0000\u0000FG\u0001\u0000\u0000\u0000GI\u0001\u0000\u0000"+
		"\u0000HF\u0001\u0000\u0000\u0000It\u0005\u0002\u0000\u0000JN\u0005\u0001"+
		"\u0000\u0000KM\u0005\n\u0000\u0000LK\u0001\u0000\u0000\u0000MP\u0001\u0000"+
		"\u0000\u0000NL\u0001\u0000\u0000\u0000NO\u0001\u0000\u0000\u0000OQ\u0001"+
		"\u0000\u0000\u0000PN\u0001\u0000\u0000\u0000QU\u0005\f\u0000\u0000RT\u0005"+
		"\n\u0000\u0000SR\u0001\u0000\u0000\u0000TW\u0001\u0000\u0000\u0000US\u0001"+
		"\u0000\u0000\u0000UV\u0001\u0000\u0000\u0000Vb\u0001\u0000\u0000\u0000"+
		"WU\u0001\u0000\u0000\u0000X\\\u0005\u0003\u0000\u0000Y[\u0005\n\u0000"+
		"\u0000ZY\u0001\u0000\u0000\u0000[^\u0001\u0000\u0000\u0000\\Z\u0001\u0000"+
		"\u0000\u0000\\]\u0001\u0000\u0000\u0000]_\u0001\u0000\u0000\u0000^\\\u0001"+
		"\u0000\u0000\u0000_a\u0005\f\u0000\u0000`X\u0001\u0000\u0000\u0000ad\u0001"+
		"\u0000\u0000\u0000b`\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000\u0000"+
		"ch\u0001\u0000\u0000\u0000db\u0001\u0000\u0000\u0000eg\u0005\n\u0000\u0000"+
		"fe\u0001\u0000\u0000\u0000gj\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000"+
		"\u0000hi\u0001\u0000\u0000\u0000ik\u0001\u0000\u0000\u0000jh\u0001\u0000"+
		"\u0000\u0000kl\u0005\u0002\u0000\u0000lp\u0001\u0000\u0000\u0000mo\u0005"+
		"\n\u0000\u0000nm\u0001\u0000\u0000\u0000or\u0001\u0000\u0000\u0000pn\u0001"+
		"\u0000\u0000\u0000pq\u0001\u0000\u0000\u0000qt\u0001\u0000\u0000\u0000"+
		"rp\u0001\u0000\u0000\u0000s0\u0001\u0000\u0000\u0000s;\u0001\u0000\u0000"+
		"\u0000sJ\u0001\u0000\u0000\u0000t\u0007\u0001\u0000\u0000\u0000uw\u0005"+
		"\n\u0000\u0000vu\u0001\u0000\u0000\u0000wz\u0001\u0000\u0000\u0000xv\u0001"+
		"\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000y\u00a1\u0001\u0000\u0000"+
		"\u0000zx\u0001\u0000\u0000\u0000{\u0097\u0005\u0004\u0000\u0000|~\u0005"+
		"\n\u0000\u0000}|\u0001\u0000\u0000\u0000~\u0081\u0001\u0000\u0000\u0000"+
		"\u007f}\u0001\u0000\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080"+
		"\u0082\u0001\u0000\u0000\u0000\u0081\u007f\u0001\u0000\u0000\u0000\u0082"+
		"\u0083\u0005\t\u0000\u0000\u0083\u0087\u0005\b\u0000\u0000\u0084\u0086"+
		"\u0005\n\u0000\u0000\u0085\u0084\u0001\u0000\u0000\u0000\u0086\u0089\u0001"+
		"\u0000\u0000\u0000\u0087\u0085\u0001\u0000\u0000\u0000\u0087\u0088\u0001"+
		"\u0000\u0000\u0000\u0088\u0098\u0001\u0000\u0000\u0000\u0089\u0087\u0001"+
		"\u0000\u0000\u0000\u008a\u008c\u0005\n\u0000\u0000\u008b\u008a\u0001\u0000"+
		"\u0000\u0000\u008c\u008f\u0001\u0000\u0000\u0000\u008d\u008b\u0001\u0000"+
		"\u0000\u0000\u008d\u008e\u0001\u0000\u0000\u0000\u008e\u0090\u0001\u0000"+
		"\u0000\u0000\u008f\u008d\u0001\u0000\u0000\u0000\u0090\u0094\u0005\b\u0000"+
		"\u0000\u0091\u0093\u0005\n\u0000\u0000\u0092\u0091\u0001\u0000\u0000\u0000"+
		"\u0093\u0096\u0001\u0000\u0000\u0000\u0094\u0092\u0001\u0000\u0000\u0000"+
		"\u0094\u0095\u0001\u0000\u0000\u0000\u0095\u0098\u0001\u0000\u0000\u0000"+
		"\u0096\u0094\u0001\u0000\u0000\u0000\u0097\u007f\u0001\u0000\u0000\u0000"+
		"\u0097\u008d\u0001\u0000\u0000\u0000\u0098\u0099\u0001\u0000\u0000\u0000"+
		"\u0099\u009b\u0005\u0002\u0000\u0000\u009a\u009c\u0003\u0006\u0003\u0000"+
		"\u009b\u009a\u0001\u0000\u0000\u0000\u009b\u009c\u0001\u0000\u0000\u0000"+
		"\u009c\u00a2\u0001\u0000\u0000\u0000\u009d\u009f\u0005\b\u0000\u0000\u009e"+
		"\u00a0\u0003\u0006\u0003\u0000\u009f\u009e\u0001\u0000\u0000\u0000\u009f"+
		"\u00a0\u0001\u0000\u0000\u0000\u00a0\u00a2\u0001\u0000\u0000\u0000\u00a1"+
		"{\u0001\u0000\u0000\u0000\u00a1\u009d\u0001\u0000\u0000\u0000\u00a2\u00a6"+
		"\u0001\u0000\u0000\u0000\u00a3\u00a5\u0005\n\u0000\u0000\u00a4\u00a3\u0001"+
		"\u0000\u0000\u0000\u00a5\u00a8\u0001\u0000\u0000\u0000\u00a6\u00a4\u0001"+
		"\u0000\u0000\u0000\u00a6\u00a7\u0001\u0000\u0000\u0000\u00a7\t\u0001\u0000"+
		"\u0000\u0000\u00a8\u00a6\u0001\u0000\u0000\u0000\u00a9\u00aa\u0006\u0005"+
		"\uffff\uffff\u0000\u00aa\u00ab\u0005\u0001\u0000\u0000\u00ab\u00ac\u0003"+
		"\n\u0005\u0000\u00ac\u00ad\u0005\u0002\u0000\u0000\u00ad\u00c1\u0001\u0000"+
		"\u0000\u0000\u00ae\u00c1\u0003\b\u0004\u0000\u00af\u00b3\u0003\u0014\n"+
		"\u0000\u00b0\u00b3\u0003\u0016\u000b\u0000\u00b1\u00b3\u0003\u0018\f\u0000"+
		"\u00b2\u00af\u0001\u0000\u0000\u0000\u00b2\u00b0\u0001\u0000\u0000\u0000"+
		"\u00b2\u00b1\u0001\u0000\u0000\u0000\u00b3\u00c1\u0001\u0000\u0000\u0000"+
		"\u00b4\u00b7\u0003\u0010\b\u0000\u00b5\u00b7\u0003\u0012\t\u0000\u00b6"+
		"\u00b4\u0001\u0000\u0000\u0000\u00b6\u00b5\u0001\u0000\u0000\u0000\u00b7"+
		"\u00c1\u0001\u0000\u0000\u0000\u00b8\u00bc\u0007\u0000\u0000\u0000\u00b9"+
		"\u00bb\u0005\n\u0000\u0000\u00ba\u00b9\u0001\u0000\u0000\u0000\u00bb\u00be"+
		"\u0001\u0000\u0000\u0000\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bd"+
		"\u0001\u0000\u0000\u0000\u00bd\u00bf\u0001\u0000\u0000\u0000\u00be\u00bc"+
		"\u0001\u0000\u0000\u0000\u00bf\u00c1\u0003\n\u0005\u0004\u00c0\u00a9\u0001"+
		"\u0000\u0000\u0000\u00c0\u00ae\u0001\u0000\u0000\u0000\u00c0\u00b2\u0001"+
		"\u0000\u0000\u0000\u00c0\u00b6\u0001\u0000\u0000\u0000\u00c0\u00b8\u0001"+
		"\u0000\u0000\u0000\u00c1\u00e5\u0001\u0000\u0000\u0000\u00c2\u00c3\n\u0003"+
		"\u0000\u0000\u00c3\u00c4\u0005\u0011\u0000\u0000\u00c4\u00e4\u0003\n\u0005"+
		"\u0004\u00c5\u00c9\n\u0002\u0000\u0000\u00c6\u00c8\u0005\n\u0000\u0000"+
		"\u00c7\u00c6\u0001\u0000\u0000\u0000\u00c8\u00cb\u0001\u0000\u0000\u0000"+
		"\u00c9\u00c7\u0001\u0000\u0000\u0000\u00c9\u00ca\u0001\u0000\u0000\u0000"+
		"\u00ca\u00cc\u0001\u0000\u0000\u0000\u00cb\u00c9\u0001\u0000\u0000\u0000"+
		"\u00cc\u00d0\u0007\u0001\u0000\u0000\u00cd\u00cf\u0005\n\u0000\u0000\u00ce"+
		"\u00cd\u0001\u0000\u0000\u0000\u00cf\u00d2\u0001\u0000\u0000\u0000\u00d0"+
		"\u00ce\u0001\u0000\u0000\u0000\u00d0\u00d1\u0001\u0000\u0000\u0000\u00d1"+
		"\u00d3\u0001\u0000\u0000\u0000\u00d2\u00d0\u0001\u0000\u0000\u0000\u00d3"+
		"\u00e4\u0003\n\u0005\u0003\u00d4\u00d8\n\u0001\u0000\u0000\u00d5\u00d7"+
		"\u0005\n\u0000\u0000\u00d6\u00d5\u0001\u0000\u0000\u0000\u00d7\u00da\u0001"+
		"\u0000\u0000\u0000\u00d8\u00d6\u0001\u0000\u0000\u0000\u00d8\u00d9\u0001"+
		"\u0000\u0000\u0000\u00d9\u00db\u0001\u0000\u0000\u0000\u00da\u00d8\u0001"+
		"\u0000\u0000\u0000\u00db\u00df\u0007\u0000\u0000\u0000\u00dc\u00de\u0005"+
		"\n\u0000\u0000\u00dd\u00dc\u0001\u0000\u0000\u0000\u00de\u00e1\u0001\u0000"+
		"\u0000\u0000\u00df\u00dd\u0001\u0000\u0000\u0000\u00df\u00e0\u0001\u0000"+
		"\u0000\u0000\u00e0\u00e2\u0001\u0000\u0000\u0000\u00e1\u00df\u0001\u0000"+
		"\u0000\u0000\u00e2\u00e4\u0003\n\u0005\u0002\u00e3\u00c2\u0001\u0000\u0000"+
		"\u0000\u00e3\u00c5\u0001\u0000\u0000\u0000\u00e3\u00d4\u0001\u0000\u0000"+
		"\u0000\u00e4\u00e7\u0001\u0000\u0000\u0000\u00e5\u00e3\u0001\u0000\u0000"+
		"\u0000\u00e5\u00e6\u0001\u0000\u0000\u0000\u00e6\u000b\u0001\u0000\u0000"+
		"\u0000\u00e7\u00e5\u0001\u0000\u0000\u0000\u00e8\u00ec\u0005\u0005\u0000"+
		"\u0000\u00e9\u00eb\u0005\n\u0000\u0000\u00ea\u00e9\u0001\u0000\u0000\u0000"+
		"\u00eb\u00ee\u0001\u0000\u0000\u0000\u00ec\u00ea\u0001\u0000\u0000\u0000"+
		"\u00ec\u00ed\u0001\u0000\u0000\u0000\u00ed\u00ef\u0001\u0000\u0000\u0000"+
		"\u00ee\u00ec\u0001\u0000\u0000\u0000\u00ef\u00f3\u0003\u000e\u0007\u0000"+
		"\u00f0\u00f2\u0005\n\u0000\u0000\u00f1\u00f0\u0001\u0000\u0000\u0000\u00f2"+
		"\u00f5\u0001\u0000\u0000\u0000\u00f3\u00f1\u0001\u0000\u0000\u0000\u00f3"+
		"\u00f4\u0001\u0000\u0000\u0000\u00f4\u0100\u0001\u0000\u0000\u0000\u00f5"+
		"\u00f3\u0001\u0000\u0000\u0000\u00f6\u00fa\u0005\u0003\u0000\u0000\u00f7"+
		"\u00f9\u0005\n\u0000\u0000\u00f8\u00f7\u0001\u0000\u0000\u0000\u00f9\u00fc"+
		"\u0001\u0000\u0000\u0000\u00fa\u00f8\u0001\u0000\u0000\u0000\u00fa\u00fb"+
		"\u0001\u0000\u0000\u0000\u00fb\u00fd\u0001\u0000\u0000\u0000\u00fc\u00fa"+
		"\u0001\u0000\u0000\u0000\u00fd\u00ff\u0003\u000e\u0007\u0000\u00fe\u00f6"+
		"\u0001\u0000\u0000\u0000\u00ff\u0102\u0001\u0000\u0000\u0000\u0100\u00fe"+
		"\u0001\u0000\u0000\u0000\u0100\u0101\u0001\u0000\u0000\u0000\u0101\u0103"+
		"\u0001\u0000\u0000\u0000\u0102\u0100\u0001\u0000\u0000\u0000\u0103\u0104"+
		"\u0005\u0006\u0000\u0000\u0104\r\u0001\u0000\u0000\u0000\u0105\u0108\u0003"+
		"\f\u0006\u0000\u0106\u0108\u0003\n\u0005\u0000\u0107\u0105\u0001\u0000"+
		"\u0000\u0000\u0107\u0106\u0001\u0000\u0000\u0000\u0108\u000f\u0001\u0000"+
		"\u0000\u0000\u0109\u010a\u0007\u0002\u0000\u0000\u010a\u0011\u0001\u0000"+
		"\u0000\u0000\u010b\u010c\u0007\u0003\u0000\u0000\u010c\u0013\u0001\u0000"+
		"\u0000\u0000\u010d\u010f\u0005\n\u0000\u0000\u010e\u010d\u0001\u0000\u0000"+
		"\u0000\u010f\u0112\u0001\u0000\u0000\u0000\u0110\u010e\u0001\u0000\u0000"+
		"\u0000\u0110\u0111\u0001\u0000\u0000\u0000\u0111\u0113\u0001\u0000\u0000"+
		"\u0000\u0112\u0110\u0001\u0000\u0000\u0000\u0113\u0114\u0005\u0018\u0000"+
		"\u0000\u0114\u0118\u0005\u0001\u0000\u0000\u0115\u0117\u0005\n\u0000\u0000"+
		"\u0116\u0115\u0001\u0000\u0000\u0000\u0117\u011a\u0001\u0000\u0000\u0000"+
		"\u0118\u0116\u0001\u0000\u0000\u0000\u0118\u0119\u0001\u0000\u0000\u0000"+
		"\u0119\u011b\u0001\u0000\u0000\u0000\u011a\u0118\u0001\u0000\u0000\u0000"+
		"\u011b\u011f\u0003\n\u0005\u0000\u011c\u011e\u0005\n\u0000\u0000\u011d"+
		"\u011c\u0001\u0000\u0000\u0000\u011e\u0121\u0001\u0000\u0000\u0000\u011f"+
		"\u011d\u0001\u0000\u0000\u0000\u011f\u0120\u0001\u0000\u0000\u0000\u0120"+
		"\u0122\u0001\u0000\u0000\u0000\u0121\u011f\u0001\u0000\u0000\u0000\u0122"+
		"\u0126\u0005\u0002\u0000\u0000\u0123\u0125\u0005\n\u0000\u0000\u0124\u0123"+
		"\u0001\u0000\u0000\u0000\u0125\u0128\u0001\u0000\u0000\u0000\u0126\u0124"+
		"\u0001\u0000\u0000\u0000\u0126\u0127\u0001\u0000\u0000\u0000\u0127\u0234"+
		"\u0001\u0000\u0000\u0000\u0128\u0126\u0001\u0000\u0000\u0000\u0129\u012b"+
		"\u0005\n\u0000\u0000\u012a\u0129\u0001\u0000\u0000\u0000\u012b\u012e\u0001"+
		"\u0000\u0000\u0000\u012c\u012a\u0001\u0000\u0000\u0000\u012c\u012d\u0001"+
		"\u0000\u0000\u0000\u012d\u012f\u0001\u0000\u0000\u0000\u012e\u012c\u0001"+
		"\u0000\u0000\u0000\u012f\u0130\u0005\u0019\u0000\u0000\u0130\u0134\u0005"+
		"\u0001\u0000\u0000\u0131\u0133\u0005\n\u0000\u0000\u0132\u0131\u0001\u0000"+
		"\u0000\u0000\u0133\u0136\u0001\u0000\u0000\u0000\u0134\u0132\u0001\u0000"+
		"\u0000\u0000\u0134\u0135\u0001\u0000\u0000\u0000\u0135\u0137\u0001\u0000"+
		"\u0000\u0000\u0136\u0134\u0001\u0000\u0000\u0000\u0137\u013b\u0003\n\u0005"+
		"\u0000\u0138\u013a\u0005\n\u0000\u0000\u0139\u0138\u0001\u0000\u0000\u0000"+
		"\u013a\u013d\u0001\u0000\u0000\u0000\u013b\u0139\u0001\u0000\u0000\u0000"+
		"\u013b\u013c\u0001\u0000\u0000\u0000\u013c\u013e\u0001\u0000\u0000\u0000"+
		"\u013d\u013b\u0001\u0000\u0000\u0000\u013e\u0142\u0005\u0002\u0000\u0000"+
		"\u013f\u0141\u0005\n\u0000\u0000\u0140\u013f\u0001\u0000\u0000\u0000\u0141"+
		"\u0144\u0001\u0000\u0000\u0000\u0142\u0140\u0001\u0000\u0000\u0000\u0142"+
		"\u0143\u0001\u0000\u0000\u0000\u0143\u0234\u0001\u0000\u0000\u0000\u0144"+
		"\u0142\u0001\u0000\u0000\u0000\u0145\u0147\u0005\n\u0000\u0000\u0146\u0145"+
		"\u0001\u0000\u0000\u0000\u0147\u014a\u0001\u0000\u0000\u0000\u0148\u0146"+
		"\u0001\u0000\u0000\u0000\u0148\u0149\u0001\u0000\u0000\u0000\u0149\u014b"+
		"\u0001\u0000\u0000\u0000\u014a\u0148\u0001\u0000\u0000\u0000\u014b\u014c"+
		"\u0005\u001b\u0000\u0000\u014c\u0150\u0005\u0001\u0000\u0000\u014d\u014f"+
		"\u0005\n\u0000\u0000\u014e\u014d\u0001\u0000\u0000\u0000\u014f\u0152\u0001"+
		"\u0000\u0000\u0000\u0150\u014e\u0001\u0000\u0000\u0000\u0150\u0151\u0001"+
		"\u0000\u0000\u0000\u0151\u0153\u0001\u0000\u0000\u0000\u0152\u0150\u0001"+
		"\u0000\u0000\u0000\u0153\u0157\u0003\n\u0005\u0000\u0154\u0156\u0005\n"+
		"\u0000\u0000\u0155\u0154\u0001\u0000\u0000\u0000\u0156\u0159\u0001\u0000"+
		"\u0000\u0000\u0157\u0155\u0001\u0000\u0000\u0000\u0157\u0158\u0001\u0000"+
		"\u0000\u0000\u0158\u015a\u0001\u0000\u0000\u0000\u0159\u0157\u0001\u0000"+
		"\u0000\u0000\u015a\u015e\u0005\u0002\u0000\u0000\u015b\u015d\u0005\n\u0000"+
		"\u0000\u015c\u015b\u0001\u0000\u0000\u0000\u015d\u0160\u0001\u0000\u0000"+
		"\u0000\u015e\u015c\u0001\u0000\u0000\u0000\u015e\u015f\u0001\u0000\u0000"+
		"\u0000\u015f\u0234\u0001\u0000\u0000\u0000\u0160\u015e\u0001\u0000\u0000"+
		"\u0000\u0161\u0163\u0005\n\u0000\u0000\u0162\u0161\u0001\u0000\u0000\u0000"+
		"\u0163\u0166\u0001\u0000\u0000\u0000\u0164\u0162\u0001\u0000\u0000\u0000"+
		"\u0164\u0165\u0001\u0000\u0000\u0000\u0165\u0167\u0001\u0000\u0000\u0000"+
		"\u0166\u0164\u0001\u0000\u0000\u0000\u0167\u0168\u0005\u001c\u0000\u0000"+
		"\u0168\u016c\u0005\u0001\u0000\u0000\u0169\u016b\u0005\n\u0000\u0000\u016a"+
		"\u0169\u0001\u0000\u0000\u0000\u016b\u016e\u0001\u0000\u0000\u0000\u016c"+
		"\u016a\u0001\u0000\u0000\u0000\u016c\u016d\u0001\u0000\u0000\u0000\u016d"+
		"\u016f\u0001\u0000\u0000\u0000\u016e\u016c\u0001\u0000\u0000\u0000\u016f"+
		"\u0173\u0003\n\u0005\u0000\u0170\u0172\u0005\n\u0000\u0000\u0171\u0170"+
		"\u0001\u0000\u0000\u0000\u0172\u0175\u0001\u0000\u0000\u0000\u0173\u0171"+
		"\u0001\u0000\u0000\u0000\u0173\u0174\u0001\u0000\u0000\u0000\u0174\u0176"+
		"\u0001\u0000\u0000\u0000\u0175\u0173\u0001\u0000\u0000\u0000\u0176\u017a"+
		"\u0005\u0002\u0000\u0000\u0177\u0179\u0005\n\u0000\u0000\u0178\u0177\u0001"+
		"\u0000\u0000\u0000\u0179\u017c\u0001\u0000\u0000\u0000\u017a\u0178\u0001"+
		"\u0000\u0000\u0000\u017a\u017b\u0001\u0000\u0000\u0000\u017b\u0234\u0001"+
		"\u0000\u0000\u0000\u017c\u017a\u0001\u0000\u0000\u0000\u017d\u017f\u0005"+
		"\n\u0000\u0000\u017e\u017d\u0001\u0000\u0000\u0000\u017f\u0182\u0001\u0000"+
		"\u0000\u0000\u0180\u017e\u0001\u0000\u0000\u0000\u0180\u0181\u0001\u0000"+
		"\u0000\u0000\u0181\u0183\u0001\u0000\u0000\u0000\u0182\u0180\u0001\u0000"+
		"\u0000\u0000\u0183\u0184\u0005\u001e\u0000\u0000\u0184\u0188\u0005\u0001"+
		"\u0000\u0000\u0185\u0187\u0005\n\u0000\u0000\u0186\u0185\u0001\u0000\u0000"+
		"\u0000\u0187\u018a\u0001\u0000\u0000\u0000\u0188\u0186\u0001\u0000\u0000"+
		"\u0000\u0188\u0189\u0001\u0000\u0000\u0000\u0189\u018b\u0001\u0000\u0000"+
		"\u0000\u018a\u0188\u0001\u0000\u0000\u0000\u018b\u018f\u0003\n\u0005\u0000"+
		"\u018c\u018e\u0005\n\u0000\u0000\u018d\u018c\u0001\u0000\u0000\u0000\u018e"+
		"\u0191\u0001\u0000\u0000\u0000\u018f\u018d\u0001\u0000\u0000\u0000\u018f"+
		"\u0190\u0001\u0000\u0000\u0000\u0190\u0192\u0001\u0000\u0000\u0000\u0191"+
		"\u018f\u0001\u0000\u0000\u0000\u0192\u0196\u0005\u0002\u0000\u0000\u0193"+
		"\u0195\u0005\n\u0000\u0000\u0194\u0193\u0001\u0000\u0000\u0000\u0195\u0198"+
		"\u0001\u0000\u0000\u0000\u0196\u0194\u0001\u0000\u0000\u0000\u0196\u0197"+
		"\u0001\u0000\u0000\u0000\u0197\u0234\u0001\u0000\u0000\u0000\u0198\u0196"+
		"\u0001\u0000\u0000\u0000\u0199\u019b\u0005\n\u0000\u0000\u019a\u0199\u0001"+
		"\u0000\u0000\u0000\u019b\u019e\u0001\u0000\u0000\u0000\u019c\u019a\u0001"+
		"\u0000\u0000\u0000\u019c\u019d\u0001\u0000\u0000\u0000\u019d\u019f\u0001"+
		"\u0000\u0000\u0000\u019e\u019c\u0001\u0000\u0000\u0000\u019f\u01a0\u0005"+
		"\u001f\u0000\u0000\u01a0\u01a4\u0005\u0001\u0000\u0000\u01a1\u01a3\u0005"+
		"\n\u0000\u0000\u01a2\u01a1\u0001\u0000\u0000\u0000\u01a3\u01a6\u0001\u0000"+
		"\u0000\u0000\u01a4\u01a2\u0001\u0000\u0000\u0000\u01a4\u01a5\u0001\u0000"+
		"\u0000\u0000\u01a5\u01a7\u0001\u0000\u0000\u0000\u01a6\u01a4\u0001\u0000"+
		"\u0000\u0000\u01a7\u01ab\u0003\n\u0005\u0000\u01a8\u01aa\u0005\n\u0000"+
		"\u0000\u01a9\u01a8\u0001\u0000\u0000\u0000\u01aa\u01ad\u0001\u0000\u0000"+
		"\u0000\u01ab\u01a9\u0001\u0000\u0000\u0000\u01ab\u01ac\u0001\u0000\u0000"+
		"\u0000\u01ac\u01ae\u0001\u0000\u0000\u0000\u01ad\u01ab\u0001\u0000\u0000"+
		"\u0000\u01ae\u01b2\u0005\u0002\u0000\u0000\u01af\u01b1\u0005\n\u0000\u0000"+
		"\u01b0\u01af\u0001\u0000\u0000\u0000\u01b1\u01b4\u0001\u0000\u0000\u0000"+
		"\u01b2\u01b0\u0001\u0000\u0000\u0000\u01b2\u01b3\u0001\u0000\u0000\u0000"+
		"\u01b3\u0234\u0001\u0000\u0000\u0000\u01b4\u01b2\u0001\u0000\u0000\u0000"+
		"\u01b5\u01b7\u0005\n\u0000\u0000\u01b6\u01b5\u0001\u0000\u0000\u0000\u01b7"+
		"\u01ba\u0001\u0000\u0000\u0000\u01b8\u01b6\u0001\u0000\u0000\u0000\u01b8"+
		"\u01b9\u0001\u0000\u0000\u0000\u01b9\u01bb\u0001\u0000\u0000\u0000\u01ba"+
		"\u01b8\u0001\u0000\u0000\u0000\u01bb\u01bc\u0005!\u0000\u0000\u01bc\u01c0"+
		"\u0005\u0001\u0000\u0000\u01bd\u01bf\u0005\n\u0000\u0000\u01be\u01bd\u0001"+
		"\u0000\u0000\u0000\u01bf\u01c2\u0001\u0000\u0000\u0000\u01c0\u01be\u0001"+
		"\u0000\u0000\u0000\u01c0\u01c1\u0001\u0000\u0000\u0000\u01c1\u01c3\u0001"+
		"\u0000\u0000\u0000\u01c2\u01c0\u0001\u0000\u0000\u0000\u01c3\u01c7\u0003"+
		"\n\u0005\u0000\u01c4\u01c6\u0005\n\u0000\u0000\u01c5\u01c4\u0001\u0000"+
		"\u0000\u0000\u01c6\u01c9\u0001\u0000\u0000\u0000\u01c7\u01c5\u0001\u0000"+
		"\u0000\u0000\u01c7\u01c8\u0001\u0000\u0000\u0000\u01c8\u01ca\u0001\u0000"+
		"\u0000\u0000\u01c9\u01c7\u0001\u0000\u0000\u0000\u01ca\u01ce\u0005\u0002"+
		"\u0000\u0000\u01cb\u01cd\u0005\n\u0000\u0000\u01cc\u01cb\u0001\u0000\u0000"+
		"\u0000\u01cd\u01d0\u0001\u0000\u0000\u0000\u01ce\u01cc\u0001\u0000\u0000"+
		"\u0000\u01ce\u01cf\u0001\u0000\u0000\u0000\u01cf\u0234\u0001\u0000\u0000"+
		"\u0000\u01d0\u01ce\u0001\u0000\u0000\u0000\u01d1\u01d3\u0005\n\u0000\u0000"+
		"\u01d2\u01d1\u0001\u0000\u0000\u0000\u01d3\u01d6\u0001\u0000\u0000\u0000"+
		"\u01d4\u01d2\u0001\u0000\u0000\u0000\u01d4\u01d5\u0001\u0000\u0000\u0000"+
		"\u01d5\u01d7\u0001\u0000\u0000\u0000\u01d6\u01d4\u0001\u0000\u0000\u0000"+
		"\u01d7\u01d8\u0005 \u0000\u0000\u01d8\u01dc\u0005\u0001\u0000\u0000\u01d9"+
		"\u01db\u0005\n\u0000\u0000\u01da\u01d9\u0001\u0000\u0000\u0000\u01db\u01de"+
		"\u0001\u0000\u0000\u0000\u01dc\u01da\u0001\u0000\u0000\u0000\u01dc\u01dd"+
		"\u0001\u0000\u0000\u0000\u01dd\u01df\u0001\u0000\u0000\u0000\u01de\u01dc"+
		"\u0001\u0000\u0000\u0000\u01df\u01e3\u0003\n\u0005\u0000\u01e0\u01e2\u0005"+
		"\n\u0000\u0000\u01e1\u01e0\u0001\u0000\u0000\u0000\u01e2\u01e5\u0001\u0000"+
		"\u0000\u0000\u01e3\u01e1\u0001\u0000\u0000\u0000\u01e3\u01e4\u0001\u0000"+
		"\u0000\u0000\u01e4\u01e6\u0001\u0000\u0000\u0000\u01e5\u01e3\u0001\u0000"+
		"\u0000\u0000\u01e6\u01ea\u0005\u0002\u0000\u0000\u01e7\u01e9\u0005\n\u0000"+
		"\u0000\u01e8\u01e7\u0001\u0000\u0000\u0000\u01e9\u01ec\u0001\u0000\u0000"+
		"\u0000\u01ea\u01e8\u0001\u0000\u0000\u0000\u01ea\u01eb\u0001\u0000\u0000"+
		"\u0000\u01eb\u0234\u0001\u0000\u0000\u0000\u01ec\u01ea\u0001\u0000\u0000"+
		"\u0000\u01ed\u01ef\u0005\n\u0000\u0000\u01ee\u01ed\u0001\u0000\u0000\u0000"+
		"\u01ef\u01f2\u0001\u0000\u0000\u0000\u01f0\u01ee\u0001\u0000\u0000\u0000"+
		"\u01f0\u01f1\u0001\u0000\u0000\u0000\u01f1\u01f3\u0001\u0000\u0000\u0000"+
		"\u01f2\u01f0\u0001\u0000\u0000\u0000\u01f3\u01f4\u0005\"\u0000\u0000\u01f4"+
		"\u01f8\u0005\u0001\u0000\u0000\u01f5\u01f7\u0005\n\u0000\u0000\u01f6\u01f5"+
		"\u0001\u0000\u0000\u0000\u01f7\u01fa\u0001\u0000\u0000\u0000\u01f8\u01f6"+
		"\u0001\u0000\u0000\u0000\u01f8\u01f9\u0001\u0000\u0000\u0000\u01f9\u01fb"+
		"\u0001\u0000\u0000\u0000\u01fa\u01f8\u0001\u0000\u0000\u0000\u01fb\u01ff"+
		"\u0003\n\u0005\u0000\u01fc\u01fe\u0005\n\u0000\u0000\u01fd\u01fc\u0001"+
		"\u0000\u0000\u0000\u01fe\u0201\u0001\u0000\u0000\u0000\u01ff\u01fd\u0001"+
		"\u0000\u0000\u0000\u01ff\u0200\u0001\u0000\u0000\u0000\u0200\u0202\u0001"+
		"\u0000\u0000\u0000\u0201\u01ff\u0001\u0000\u0000\u0000\u0202\u0206\u0005"+
		"\u0002\u0000\u0000\u0203\u0205\u0005\n\u0000\u0000\u0204\u0203\u0001\u0000"+
		"\u0000\u0000\u0205\u0208\u0001\u0000\u0000\u0000\u0206\u0204\u0001\u0000"+
		"\u0000\u0000\u0206\u0207\u0001\u0000\u0000\u0000\u0207\u0234\u0001\u0000"+
		"\u0000\u0000\u0208\u0206\u0001\u0000\u0000\u0000\u0209\u020b\u0005\n\u0000"+
		"\u0000\u020a\u0209\u0001\u0000\u0000\u0000\u020b\u020e\u0001\u0000\u0000"+
		"\u0000\u020c\u020a\u0001\u0000\u0000\u0000\u020c\u020d\u0001\u0000\u0000"+
		"\u0000\u020d\u020f\u0001\u0000\u0000\u0000\u020e\u020c\u0001\u0000\u0000"+
		"\u0000\u020f\u0210\u0005\u001a\u0000\u0000\u0210\u0214\u0005\u0001\u0000"+
		"\u0000\u0211\u0213\u0005\n\u0000\u0000\u0212\u0211\u0001\u0000\u0000\u0000"+
		"\u0213\u0216\u0001\u0000\u0000\u0000\u0214\u0212\u0001\u0000\u0000\u0000"+
		"\u0214\u0215\u0001\u0000\u0000\u0000\u0215\u0217\u0001\u0000\u0000\u0000"+
		"\u0216\u0214\u0001\u0000\u0000\u0000\u0217\u021b\u0003\n\u0005\u0000\u0218"+
		"\u021a\u0005\n\u0000\u0000\u0219\u0218\u0001\u0000\u0000\u0000\u021a\u021d"+
		"\u0001\u0000\u0000\u0000\u021b\u0219\u0001\u0000\u0000\u0000\u021b\u021c"+
		"\u0001\u0000\u0000\u0000\u021c\u021e\u0001\u0000\u0000\u0000\u021d\u021b"+
		"\u0001\u0000\u0000\u0000\u021e\u0222\u0005\u0003\u0000\u0000\u021f\u0221"+
		"\u0005\n\u0000\u0000\u0220\u021f\u0001\u0000\u0000\u0000\u0221\u0224\u0001"+
		"\u0000\u0000\u0000\u0222\u0220\u0001\u0000\u0000\u0000\u0222\u0223\u0001"+
		"\u0000\u0000\u0000\u0223\u0225\u0001\u0000\u0000\u0000\u0224\u0222\u0001"+
		"\u0000\u0000\u0000\u0225\u0229\u0003\n\u0005\u0000\u0226\u0228\u0005\n"+
		"\u0000\u0000\u0227\u0226\u0001\u0000\u0000\u0000\u0228\u022b\u0001\u0000"+
		"\u0000\u0000\u0229\u0227\u0001\u0000\u0000\u0000\u0229\u022a\u0001\u0000"+
		"\u0000\u0000\u022a\u022c\u0001\u0000\u0000\u0000\u022b\u0229\u0001\u0000"+
		"\u0000\u0000\u022c\u0230\u0005\u0002\u0000\u0000\u022d\u022f\u0005\n\u0000"+
		"\u0000\u022e\u022d\u0001\u0000\u0000\u0000\u022f\u0232\u0001\u0000\u0000"+
		"\u0000\u0230\u022e\u0001\u0000\u0000\u0000\u0230\u0231\u0001\u0000\u0000"+
		"\u0000\u0231\u0234\u0001\u0000\u0000\u0000\u0232\u0230\u0001\u0000\u0000"+
		"\u0000\u0233\u0110\u0001\u0000\u0000\u0000\u0233\u012c\u0001\u0000\u0000"+
		"\u0000\u0233\u0148\u0001\u0000\u0000\u0000\u0233\u0164\u0001\u0000\u0000"+
		"\u0000\u0233\u0180\u0001\u0000\u0000\u0000\u0233\u019c\u0001\u0000\u0000"+
		"\u0000\u0233\u01b8\u0001\u0000\u0000\u0000\u0233\u01d4\u0001\u0000\u0000"+
		"\u0000\u0233\u01f0\u0001\u0000\u0000\u0000\u0233\u020c\u0001\u0000\u0000"+
		"\u0000\u0234\u0015\u0001\u0000\u0000\u0000\u0235\u0237\u0005\n\u0000\u0000"+
		"\u0236\u0235\u0001\u0000\u0000\u0000\u0237\u023a\u0001\u0000\u0000\u0000"+
		"\u0238\u0236\u0001\u0000\u0000\u0000\u0238\u0239\u0001\u0000\u0000\u0000"+
		"\u0239\u023b\u0001\u0000\u0000\u0000\u023a\u0238\u0001\u0000\u0000\u0000"+
		"\u023b\u023c\u0005\u0012\u0000\u0000\u023c\u023d\u0005\u0001\u0000\u0000"+
		"\u023d\u023e\u0003\n\u0005\u0000\u023e\u023f\u0005\u0003\u0000\u0000\u023f"+
		"\u0244\u0003\n\u0005\u0000\u0240\u0241\u0005\u0003\u0000\u0000\u0241\u0243"+
		"\u0003\n\u0005\u0000\u0242\u0240\u0001\u0000\u0000\u0000\u0243\u0246\u0001"+
		"\u0000\u0000\u0000\u0244\u0242\u0001\u0000\u0000\u0000\u0244\u0245\u0001"+
		"\u0000\u0000\u0000\u0245\u0247\u0001\u0000\u0000\u0000\u0246\u0244\u0001"+
		"\u0000\u0000\u0000\u0247\u0248\u0005\u0002\u0000\u0000\u0248\u0272\u0001"+
		"\u0000\u0000\u0000\u0249\u024b\u0005\n\u0000\u0000\u024a\u0249\u0001\u0000"+
		"\u0000\u0000\u024b\u024e\u0001\u0000\u0000\u0000\u024c\u024a\u0001\u0000"+
		"\u0000\u0000\u024c\u024d\u0001\u0000\u0000\u0000\u024d\u024f\u0001\u0000"+
		"\u0000\u0000\u024e\u024c\u0001\u0000\u0000\u0000\u024f\u0250\u0005\u0014"+
		"\u0000\u0000\u0250\u0251\u0005\u0001\u0000\u0000\u0251\u0252\u0003\n\u0005"+
		"\u0000\u0252\u0253\u0005\u0003\u0000\u0000\u0253\u0258\u0003\n\u0005\u0000"+
		"\u0254\u0255\u0005\u0003\u0000\u0000\u0255\u0257\u0003\n\u0005\u0000\u0256"+
		"\u0254\u0001\u0000\u0000\u0000\u0257\u025a\u0001\u0000\u0000\u0000\u0258"+
		"\u0256\u0001\u0000\u0000\u0000\u0258\u0259\u0001\u0000\u0000\u0000\u0259"+
		"\u025b\u0001\u0000\u0000\u0000\u025a\u0258\u0001\u0000\u0000\u0000\u025b"+
		"\u025c\u0005\u0002\u0000\u0000\u025c\u0272\u0001\u0000\u0000\u0000\u025d"+
		"\u025f\u0005\n\u0000\u0000\u025e\u025d\u0001\u0000\u0000\u0000\u025f\u0262"+
		"\u0001\u0000\u0000\u0000\u0260\u025e\u0001\u0000\u0000\u0000\u0260\u0261"+
		"\u0001\u0000\u0000\u0000\u0261\u0263\u0001\u0000\u0000\u0000\u0262\u0260"+
		"\u0001\u0000\u0000\u0000\u0263\u0264\u0005\u0016\u0000\u0000\u0264\u0265"+
		"\u0005\u0001\u0000\u0000\u0265\u0266\u0003\n\u0005\u0000\u0266\u0267\u0005"+
		"\u0003\u0000\u0000\u0267\u026c\u0003\n\u0005\u0000\u0268\u0269\u0005\u0003"+
		"\u0000\u0000\u0269\u026b\u0003\n\u0005\u0000\u026a\u0268\u0001\u0000\u0000"+
		"\u0000\u026b\u026e\u0001\u0000\u0000\u0000\u026c\u026a\u0001\u0000\u0000"+
		"\u0000\u026c\u026d\u0001\u0000\u0000\u0000\u026d\u026f\u0001\u0000\u0000"+
		"\u0000\u026e\u026c\u0001\u0000\u0000\u0000\u026f\u0270\u0005\u0002\u0000"+
		"\u0000\u0270\u0272\u0001\u0000\u0000\u0000\u0271\u0238\u0001\u0000\u0000"+
		"\u0000\u0271\u024c\u0001\u0000\u0000\u0000\u0271\u0260\u0001\u0000\u0000"+
		"\u0000\u0272\u0017\u0001\u0000\u0000\u0000\u0273\u0275\u0005\n\u0000\u0000"+
		"\u0274\u0273\u0001\u0000\u0000\u0000\u0275\u0278\u0001\u0000\u0000\u0000"+
		"\u0276\u0274\u0001\u0000\u0000\u0000\u0276\u0277\u0001\u0000\u0000\u0000"+
		"\u0277\u0279\u0001\u0000\u0000\u0000\u0278\u0276\u0001\u0000\u0000\u0000"+
		"\u0279\u027a\u0005\u0015\u0000\u0000\u027a\u027e\u0005\u0001\u0000\u0000"+
		"\u027b\u027d\u0005\n\u0000\u0000\u027c\u027b\u0001\u0000\u0000\u0000\u027d"+
		"\u0280\u0001\u0000\u0000\u0000\u027e\u027c\u0001\u0000\u0000\u0000\u027e"+
		"\u027f\u0001\u0000\u0000\u0000\u027f\u0281\u0001\u0000\u0000\u0000\u0280"+
		"\u027e\u0001\u0000\u0000\u0000\u0281\u0285\u0003\n\u0005\u0000\u0282\u0284"+
		"\u0005\n\u0000\u0000\u0283\u0282\u0001\u0000\u0000\u0000\u0284\u0287\u0001"+
		"\u0000\u0000\u0000\u0285\u0283\u0001\u0000\u0000\u0000\u0285\u0286\u0001"+
		"\u0000\u0000\u0000\u0286\u0288\u0001\u0000\u0000\u0000\u0287\u0285\u0001"+
		"\u0000\u0000\u0000\u0288\u028c\u0005\u0002\u0000\u0000\u0289\u028b\u0005"+
		"\n\u0000\u0000\u028a\u0289\u0001\u0000\u0000\u0000\u028b\u028e\u0001\u0000"+
		"\u0000\u0000\u028c\u028a\u0001\u0000\u0000\u0000\u028c\u028d\u0001\u0000"+
		"\u0000\u0000\u028d\u02ac\u0001\u0000\u0000\u0000\u028e\u028c\u0001\u0000"+
		"\u0000\u0000\u028f\u0291\u0005\n\u0000\u0000\u0290\u028f\u0001\u0000\u0000"+
		"\u0000\u0291\u0294\u0001\u0000\u0000\u0000\u0292\u0290\u0001\u0000\u0000"+
		"\u0000\u0292\u0293\u0001\u0000\u0000\u0000\u0293\u0295\u0001\u0000\u0000"+
		"\u0000\u0294\u0292\u0001\u0000\u0000\u0000\u0295\u0296\u0005\u0017\u0000"+
		"\u0000\u0296\u029a\u0005\u0001\u0000\u0000\u0297\u0299\u0005\n\u0000\u0000"+
		"\u0298\u0297\u0001\u0000\u0000\u0000\u0299\u029c\u0001\u0000\u0000\u0000"+
		"\u029a\u0298\u0001\u0000\u0000\u0000\u029a\u029b\u0001\u0000\u0000\u0000"+
		"\u029b\u029d\u0001\u0000\u0000\u0000\u029c\u029a\u0001\u0000\u0000\u0000"+
		"\u029d\u02a1\u0003\n\u0005\u0000\u029e\u02a0\u0005\n\u0000\u0000\u029f"+
		"\u029e\u0001\u0000\u0000\u0000\u02a0\u02a3\u0001\u0000\u0000\u0000\u02a1"+
		"\u029f\u0001\u0000\u0000\u0000\u02a1\u02a2\u0001\u0000\u0000\u0000\u02a2"+
		"\u02a4\u0001\u0000\u0000\u0000\u02a3\u02a1\u0001\u0000\u0000\u0000\u02a4"+
		"\u02a8\u0005\u0002\u0000\u0000\u02a5\u02a7\u0005\n\u0000\u0000\u02a6\u02a5"+
		"\u0001\u0000\u0000\u0000\u02a7\u02aa\u0001\u0000\u0000\u0000\u02a8\u02a6"+
		"\u0001\u0000\u0000\u0000\u02a8\u02a9\u0001\u0000\u0000\u0000\u02a9\u02ac"+
		"\u0001\u0000\u0000\u0000\u02aa\u02a8\u0001\u0000\u0000\u0000\u02ab\u0276"+
		"\u0001\u0000\u0000\u0000\u02ab\u0292\u0001\u0000\u0000\u0000\u02ac\u0019"+
		"\u0001\u0000\u0000\u0000\u02ad\u02ae\u0005\u0007\u0000\u0000\u02ae\u02af"+
		"\u0005(\u0000\u0000\u02af\u02b0\u0005\u0007\u0000\u0000\u02b0\u001b\u0001"+
		"\u0000\u0000\u0000c\u001f$\'+07?FNU\\bhpsx\u007f\u0087\u008d\u0094\u0097"+
		"\u009b\u009f\u00a1\u00a6\u00b2\u00b6\u00bc\u00c0\u00c9\u00d0\u00d8\u00df"+
		"\u00e3\u00e5\u00ec\u00f3\u00fa\u0100\u0107\u0110\u0118\u011f\u0126\u012c"+
		"\u0134\u013b\u0142\u0148\u0150\u0157\u015e\u0164\u016c\u0173\u017a\u0180"+
		"\u0188\u018f\u0196\u019c\u01a4\u01ab\u01b2\u01b8\u01c0\u01c7\u01ce\u01d4"+
		"\u01dc\u01e3\u01ea\u01f0\u01f8\u01ff\u0206\u020c\u0214\u021b\u0222\u0229"+
		"\u0230\u0233\u0238\u0244\u024c\u0258\u0260\u026c\u0271\u0276\u027e\u0285"+
		"\u028c\u0292\u029a\u02a1\u02a8\u02ab";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}