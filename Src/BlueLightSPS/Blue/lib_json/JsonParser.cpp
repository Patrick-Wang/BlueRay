
#include "JsonObjects.h"
#include "JsonParser.h"
#include "JsonFactory.h"
#include <iostream>
namespace Json{

	std::shared_ptr<JsonObject> JsonParser::Parse( json_char* json )
	{
		return Parse(json, json_strlen(json));
	}

	std::shared_ptr<JsonObject> JsonParser::Parse(json_char* json, int len)
	{
		m_jsonSymbol.reset(new JsonSymbol(json, len, 0));
		JsonSymbol::Symbol symbol = m_jsonSymbol->nextSymbol();
		if (JsonSymbol::object_open != symbol)
		{
			throw std::exception("object does not begin with \"{\" ");
		}
		return std::shared_ptr<JsonObject>(ParserObject());
	}

	JsonArray* JsonParser::ParserArray(void)
	{
		JsonSymbol::Symbol symbol;
		JsonArray* jArray = JsonFactory::createArray();
		while ((symbol = m_jsonSymbol->nextSymbol()) != JsonSymbol::array_close){
			switch (symbol){
			case JsonSymbol::object_open:
				jArray->add(ParserObject());
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
				jArray->add(ParserArray());
				break;
			default:
				throw std::exception((std::string("invalid symbol in array : ") + (char)(symbol)).c_str());
			}
		}
		return jArray;
	}

	JsonType* JsonParser::ParserField(void)
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
			return ParserArray();
		case JsonSymbol::object_open:
			return ParserObject();
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

	JsonObject* JsonParser::ParserObject(void)
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
					obj->add(fieldName.str(), ParserField());
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