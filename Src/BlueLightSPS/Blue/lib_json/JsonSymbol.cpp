
#include "JsonSymbol.h"

namespace Json{

	JsonSymbol::JsonSymbol(json_char* jstr, int len, int cursor)
		: m_jstr(jstr, len)
		, m_cursor(cursor)
	{

	}

	JsonSymbol::~JsonSymbol()
	{
	}

	bool JsonSymbol::unUsable(json_char symb){
		return symb == J(' ') || symb == J('\r') || symb == J('\n') || symb == J('\t');
	}


	void JsonSymbol::nextReal(){
		if (JsonString(m_jstr.str() + m_cursor - 1, 4, true).equals(J("true")))
		{
			m_cursor += 3;
		}
		else{
			throw std::exception("expected \"true\" as value");
		}
	}
	void JsonSymbol::nextFake(){
		if (JsonString(m_jstr.str() + m_cursor - 1, 5, true).equals(J("false")))
		{
			m_cursor += 4;
		}
		else{
			throw std::exception("expected \"false\" as value");
		}
	}

	JsonSymbol::Symbol JsonSymbol::nextSymbol(){
		JsonSymbol::Symbol symb = (JsonSymbol::Symbol)next();
		switch (symb)
		{
		case real:
			nextReal();
			break;
		case fake:
			nextFake();
			break;
		case null:
			nextNull();
			break;
		default:
			if (isDigit(symb))
			{
				return digit;
			}
			break;
		}
		return symb;
	}

	void JsonSymbol::nextNull()
	{
		if (JsonString(m_jstr.str() + m_cursor - 1, 4, true).equals(J("null")))
		{
			m_cursor += 3;
		}
		else{
			throw std::exception("expected \"null\" as value");
		}
	}

	JsonString& JsonSymbol::nextString( JsonString& jstr )
	{
		int start = m_cursor;
		int end = m_jstr.find(J('\"'), m_cursor);
		if (end > 0 && start  > 0)
		{
			m_cursor = end + 1;
			return jstr.setString(m_jstr.str() + start,  end - start);
		}
		throw std::exception("invalid json string format");
	}

	bool JsonSymbol::isDigit( json_char jsymbol )
	{
		return jsymbol <= J('9') && jsymbol >= J('0') ||  J('-') == jsymbol;
	}

	void JsonSymbol::nextDigest( Digit& digest )
	{
		int start = m_cursor - 1;
		json_char jch = 0;
		digest.isFloat = false;
		while (jch = next()){
			if (J('.') == jch){
				if (!digest.isFloat){
					digest.isFloat = true;
				}
				else{
					throw std::exception("float has too many dot");
				}
			}
			else if (!isDigit(jch)){
				back();
				break;
			}
		}

		if (digest.isFloat){
			digest.fval = (float)json_atof(JsonString(m_jstr.str() + start, m_cursor - start, true).str());
		}
		else{
			digest.ival = json_atol(JsonString(m_jstr.str() + start, m_cursor - start, true).str());
		}
	}


	json_char JsonSymbol::next()
	{
		json_char jch = m_jstr[m_cursor++];
		while (unUsable(jch))	{
			jch = m_jstr[m_cursor++];
		}
		return jch;
	}

	void JsonSymbol::back()
	{
		--m_cursor;
	}

}