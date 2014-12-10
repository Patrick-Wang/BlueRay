#pragma once

#include <string>
#include <memory>
#include <sstream>
#include <list>
#include <tchar.h>
#ifdef _UNICODE
#define J(x)	L##x
#elif
#define J(x)	x
#endif // _UNICODE


namespace Json{

	class JsonObject;
	class JsonArray;
	class JsonField;
	class JsonType;
#ifdef _UNICODE
	typedef std::wstring		json_string;
	typedef wchar_t				json_char;
	typedef std::wostringstream	json_stringstream;
#elif
	typedef std::string			json_string;
	typedef char				json_char;
	typedef std::ostringstream	json_stringstream;
#endif // _UNICODE

	
	inline int json_strlen(json_char* jcs){
		return _tcslen(jcs);
	}

	inline double json_atof(json_char* jcs){
		return _tstof(jcs);
	}

	inline int json_atol(json_char* jcs){
		return _tstol(jcs);
	}

	enum JsonTypeTag{
		jint, jfloat, jbool, jstring, jarray, jobject, jnull
	};

	class JsonType{
	public:
		virtual JsonTypeTag tag() = 0;
		virtual void asJson(json_stringstream& os) = 0;
		virtual ~JsonType(){}
	};

	template<typename ty>
	class JsonValue : public JsonType{
	public:
		JsonValue(ty& var) : m_var(var){}

		ty& value(){
			return m_var;
		}

	private:
		ty m_var;
	};

	typedef std::shared_ptr<JsonValue<json_string>> JsonStringValuePtr;
};
