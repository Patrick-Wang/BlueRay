
#include "JsonObjects.h"
#include "JsonParser.h"
#include "JsonFactory.h"

#include <iostream>
namespace Json{

	JsonType* JsonParser::Parse( json_char* json )
	{
		return Parse(json, json_strlen(json));
	}

	JsonType* JsonParser::Parse(json_char* json, int len)
	{
		m_jsonSymbol.reset(new JsonSymbol(json, len, 0));
		JsonSymbol::Symbol symbol = m_jsonSymbol->nextSymbol();
		switch (symbol)
		{
		case Json::JsonSymbol::array_open:
			return ParseArray();
		case Json::JsonSymbol::object_open:
			return ParseObject();
		case Json::JsonSymbol::object_close:
		case Json::JsonSymbol::array_close:
		case Json::JsonSymbol::string:
		case Json::JsonSymbol::semicolon:
		case Json::JsonSymbol::seperator:
		case Json::JsonSymbol::null:
		case Json::JsonSymbol::real:
		case Json::JsonSymbol::fake:
		case Json::JsonSymbol::digit:
		default:
			throw std::exception("invalid json");
			break;
		}


	}

	JsonArray* JsonParser::ParseArray(void)
	{
		JsonSymbol::Symbol symbol;
		JsonArray* jArray = JsonFactory::createArray();
		while ((symbol = m_jsonSymbol->nextSymbol()) != JsonSymbol::array_close){
			switch (symbol){
			case JsonSymbol::object_open:
				jArray->add(ParseObject());
				break;
			case JsonSymbol::semicolon:
				break;
			case JsonSymbol::string:
				{
					JsonString str(true);
					jArray->add(JsonFactory::create(m_jsonSymbol->nextString(str).str()));
				}
				break;
			case JsonSymbol::array_open:
				jArray->add(ParseArray());
				break;
			default:
				throw std::exception((std::string("invalid symbol in array : ") + (char)(symbol)).c_str());
			}
		}
		return jArray;
	}

	JsonType* JsonParser::ParseField(void)
	{
		JsonSymbol::Symbol symbol;
		switch (symbol = m_jsonSymbol->nextSymbol())
		{
		case JsonSymbol::string:
			{
				JsonString jsString(true);
				m_jsonSymbol->nextString(jsString).str();
				return JsonFactory::create(jsString.str());
			}
		case JsonSymbol::array_open:
			return ParseArray();
		case JsonSymbol::object_open:
			return ParseObject();
			break;
		case JsonSymbol::null:
			return JsonFactory::create();
		case JsonSymbol::real:
			return JsonFactory::create(true);
		case JsonSymbol::fake:
			return JsonFactory::create(false);
			break;
		case JsonSymbol::digit:
			{
				JsonSymbol::Digit dig;
				m_jsonSymbol->nextDigest(dig);
				if (dig.isFloat)
				{
					return JsonFactory::create(dig.fval);
				}
				else {
					return JsonFactory::create(dig.ival);
				}
			}
		default:
			
			throw std::exception("invalid field symbol in field " + (json_char)symbol);
		}
	}

	JsonObject* JsonParser::ParseObject(void)
	{
		JsonObject* obj = JsonFactory::createObject();
		JsonSymbol::Symbol symbol = JsonSymbol::array_open;
		while ((symbol = m_jsonSymbol->nextSymbol()) != JsonSymbol::object_close)
		{
			switch (symbol){
			case JsonSymbol::string:
				{
					JsonString fieldName(true);
					m_jsonSymbol->nextString(fieldName);
					JsonSymbol::Symbol symbol = m_jsonSymbol->nextSymbol();
					if (symbol != JsonSymbol::seperator)
					{
						throw std::exception("invalid field separator");
					}
					obj->add(fieldName.str(), ParseField());
				}

				break;
			case JsonSymbol::semicolon:
				break;
			default:
				throw std::exception("invalid symbol in object");
			}
		}
		return obj;
	}


}