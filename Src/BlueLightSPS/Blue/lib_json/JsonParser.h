#pragma once
#include "JsonType.h"
#include "JsonString.h"
#include <stack>
#include "JsonSymbol.h"
namespace Json{

	class JsonParser
	{
	public:
		JsonType* Parse(json_char* json);
		JsonType* Parse(json_char* json, int len);
	private:
		JsonObject* ParseObject(void);
		JsonArray* ParseArray(void);
		JsonType* ParseField(void);
	
	private:
		std::auto_ptr<JsonSymbol> m_jsonSymbol;
	};

}

