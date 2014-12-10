#pragma once
#include "JsonType.h"
#include "JsonString.h"
#include <stack>
#include "JsonSymbol.h"
namespace Json{

	class JsonParser
	{
	public:
		std::shared_ptr<JsonObject> Parse(json_char* json);
		std::shared_ptr<JsonObject> Parse(json_char* json, int len);
	private:
		JsonObject* ParseObject(void);
		JsonArray* ParseArray(void);
		JsonType* ParseField(void);
	
	private:
		std::auto_ptr<JsonSymbol> m_jsonSymbol;
	};

}

