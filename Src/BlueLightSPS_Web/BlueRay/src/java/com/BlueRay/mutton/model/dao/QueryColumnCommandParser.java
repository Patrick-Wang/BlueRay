package com.BlueRay.mutton.model.dao;

import java.sql.Date;
import java.util.regex.Pattern;

interface QueryColumnCommand {
	String execute(Class<?> cls, String colName, String cmd);
}

class QueryColumnCommandInvokerChain {
	private QueryColumnCommand command;
	private QueryColumnCommandInvokerChain nextInvoker;

	public QueryColumnCommandInvokerChain(QueryColumnCommand cmd) {
		this.command = cmd;
	}

	public QueryColumnCommandInvokerChain next(
			QueryColumnCommandInvokerChain next) {
		nextInvoker = next;
		return next;
	}

	public String Invoke(Class<?> cls, String colName, String cmd) {
		String ret = null;
		if (command != null) {
			ret = command.execute(cls, colName, cmd);
		}
		if (null == ret && null != nextInvoker) {
			ret = nextInvoker.Invoke(cls, colName, cmd);
		}
		return ret;
	}
}

abstract class AbstractQueryColumnCommand implements QueryColumnCommand {
	Pattern patten;

	public AbstractQueryColumnCommand(Pattern patten) {
		this.patten = patten;
	}

	public abstract String handle(Class<?> cls, String colName, String cmd);

	public String execute(Class<?> cls, String colName, String cmd) {
		if (patten.matcher(cmd).matches()) {
			return handle(cls, colName, cmd.replace("@", ""));
		}
		return null;
	}

}

class QueryColumnCommandNotNull extends AbstractQueryColumnCommand {
	public QueryColumnCommandNotNull() {
		super(Pattern.compile("^@\\s*!=\\s*null\\s*"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		return colName + " is not null ";
	}
}

class QueryColumnCommandIsNull extends AbstractQueryColumnCommand {

	public QueryColumnCommandIsNull() {
		super(Pattern.compile("^@\\s*==\\s*null\\s*"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		return colName + " is null ";
	}
}

class QueryColumnCommandEqual extends AbstractQueryColumnCommand {

	public QueryColumnCommandEqual() {
		super(Pattern.compile("^@\\s*==.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("==");
		String newCmd = cmd.substring(index + 2).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + "='" + newCmd + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + "='" + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + "=" + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;

	}
}

class QueryColumnCommandNotEqual extends AbstractQueryColumnCommand {

	public QueryColumnCommandNotEqual() {
		super(Pattern.compile("^@\\s*!=.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("!=");
		String newCmd = cmd.substring(index + 2).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + " != '" + newCmd + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + " !=' " + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + " != " + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;
	}
}

class QueryColumnCommandLike extends AbstractQueryColumnCommand {

	public QueryColumnCommandLike() {
		super(Pattern.compile("^@\\s*like.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("like");
		String newCmd = cmd.substring(index + 4).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + " like '%" + newCmd + "%' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + " like '%" + date + "%' ";
			} catch (Exception e) {

			}
		}
		return ret;
	}

}

class QueryColumnCommandGE extends AbstractQueryColumnCommand {
	public QueryColumnCommandGE() {
		super(Pattern.compile("^@\\s*>=.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf(">=");
		String newCmd = cmd.substring(index + 2).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + ">='" + newCmd + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + ">='" + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + ">=" + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;
	}
}

class QueryColumnCommandLE extends AbstractQueryColumnCommand {
	public QueryColumnCommandLE() {
		super(Pattern.compile("^@\\s*<=.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("<=");
		String newCmd = cmd.substring(index + 2).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + "<='" + newCmd + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + "<='" + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + "<=" + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;

	}
}

class QueryColumnCommandGreat extends AbstractQueryColumnCommand {
	public QueryColumnCommandGreat() {
		super(Pattern.compile("^@\\s*>.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf(">");
		String newCmd = cmd.substring(index + 1).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + ">'" + newCmd + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + ">'" + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + ">" + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;

	}
}

class QueryColumnCommandLess extends AbstractQueryColumnCommand {
	public QueryColumnCommandLess() {
		super(Pattern.compile("^@\\s*<.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("<");
		String newCmd = cmd.substring(index + 1).trim();
		String ret = "";
		if (cls.getName().equals(String.class.getName())) {
			ret = colName + "<'" + newCmd + "'";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date = newCmd.replace(" ", "");
				Date.valueOf(date);
				ret = colName + "<'" + date + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(newCmd);
				ret = colName + "<" + newCmd + " ";
			} catch (Exception e) {

			}
		}
		return ret;

	}
}

class QueryColumnCommandBetween extends AbstractQueryColumnCommand {
	public QueryColumnCommandBetween() {
		super(Pattern.compile("^@\\s*between\\s+.+\\s+and\\s+.+"));
	}

	@Override
	public String handle(Class<?> cls, String colName, String cmd) {
		int index = cmd.indexOf("between");
		String newCmd = cmd.substring(index + 7).trim();
		String ret = "";
		index = newCmd.indexOf("and");
		String first = newCmd.substring(0, index).trim();
		String second = newCmd.substring(index + 3).trim();

		if (cls.getName().equals(String.class.getName())) {
			ret = colName + " between'" + first + "' and '" + second + "' ";
		} else if (cls.getName().equals(Date.class.getName())) {
			try {
				String date1 = first.replace(" ", "");
				Date.valueOf(date1);
				String date2 = second.replace(" ", "");
				Date.valueOf(date2);
				ret = colName + " between'" + date1 + "' and '" + date2 + "' ";
			} catch (Exception e) {

			}
		} else if (cls.getName().equals(Integer.class.getName())) {
			try {
				Integer.valueOf(first);
				Integer.valueOf(second);
				ret = colName + " between " + first + " and " + second + " ";
			} catch (Exception e) {

			}
		}
		return ret;
	}
}

public class QueryColumnCommandParser {

	private final static QueryColumnCommandInvokerChain invokerChain = new QueryColumnCommandInvokerChain(
			new QueryColumnCommandNotNull());
	static {
		invokerChain
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandIsNull()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandEqual()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandBetween()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandEqual()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandGE()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandGreat()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandLE()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandLess()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandLike()))
				.next(new QueryColumnCommandInvokerChain(
						new QueryColumnCommandNotEqual()));
	}

	public static String parse(Class<?> cls, String colName, String cmd) {
		return invokerChain.Invoke(cls, colName, cmd);
	}
}
