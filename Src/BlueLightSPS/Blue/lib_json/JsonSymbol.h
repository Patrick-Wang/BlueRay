#pragma once
#include "JsonString.h"

namespace Json{

	class JsonSymbol
	{
	public:
		enum Symbol{
			array_open = J('['),
			array_close = J(']'),
			object_open = J('{'),
			object_close = J('}'),
			string = J('\"'),
			semicolon = J(','),
			seperator = J(':'),
			null = J('n'),
			real = J('t'),
			fake = J('f'),
			digit = 3
		};
		typedef struct Digesttag{
			bool isFloat;
			union{
				int ival;
				float fval;
			};
		}Digit;

		Symbol nextSymbol();
		JsonString& nextString(JsonString& jstr);
		void nextDigest(Digit& digest);
		int getCursor(){
			return m_cursor;
		}
		JsonSymbol(json_char* jstr, int len, int cursor);
		~JsonSymbol();
	private:
		json_char next();
		void back();
		bool unUsable(json_char symb);
		void nextReal();
		void nextFake();
		void nextNull();
		bool isDigit(json_char jsymbol);
		bool isQuot(int index);
	private:
		JsonString m_jstr;
		int m_cursor;
	};

}