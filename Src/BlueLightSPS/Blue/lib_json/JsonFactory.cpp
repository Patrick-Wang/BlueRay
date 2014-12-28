
#include "JsonFactory.h"
#include "JsonObjects.h"

namespace Json{

	class JsonValueString : public JsonValue<json_string>{
	public:
		JsonValueString(json_string& str) : JsonValue<json_string>(str){}
		JsonValueString(json_char* str) : JsonValue<json_string>(json_string(str)){}
		virtual JsonTypeTag tag(){
			return jstring;
		}

		virtual void asJson(json_stringstream& os){
			os << J("\"") << value() << J("\"");
		}
	};

	class JsonValueInt : public JsonValue<int>{
	public:
		JsonValueInt(int val) : JsonValue<int>(val){}

		virtual JsonTypeTag tag(){
			return jint;
		}

		virtual void asJson(json_stringstream& os){
			os << value();
		}
	};

	class JsonValueBool : public JsonValue<bool>{
	public:
		JsonValueBool(bool val) : JsonValue<bool>(val){}

		virtual JsonTypeTag tag(){
			return jbool;
		}

		virtual void asJson(json_stringstream& os){
			if (value()){
				os << J("true");
			}
			else{
				os << J("false");
			}

		}
	};

	class JsonValueFloat : public JsonValue<float>{
	public:
		JsonValueFloat(float val) : JsonValue<float>(val){}

		virtual JsonTypeTag tag(){
			return jfloat;
		}

		virtual void asJson(json_stringstream& os){
			os  << value();
		}
	};

	class JsonValueArray : public JsonValue<std::shared_ptr<JsonArray>>{
	public:
		JsonValueArray(JsonArray* val) 
			: JsonValue<std::shared_ptr<JsonArray>>(std::shared_ptr<JsonArray>(val)){}

		virtual JsonTypeTag tag(){
			return value()->tag();
		}

		virtual void asJson(json_stringstream& os){
			value()->asJson(os);
		}
	};

	class JsonValueObject : public JsonValue<std::shared_ptr<JsonObject>>{
	public:
		JsonValueObject(JsonObject* val) 
			: JsonValue<std::shared_ptr<JsonObject>>(std::shared_ptr<JsonObject>(val)){}

		virtual JsonTypeTag tag(){
			return value()->tag();
		}

		virtual void asJson(json_stringstream& os){
			value()->asJson(os);
		}
	};

	class JsonValueNull : public JsonType{
	public:
		virtual JsonTypeTag tag(){
			return jnull;
		}

		virtual void asJson(json_stringstream& os){
			os << "null";
		}
	};

	JsonType* JsonFactory::createInt(int val){
		return new JsonValueInt(val);
	}

	JsonType* JsonFactory::createFloat(float val){
		return new JsonValueFloat(val);
	}
	
	JsonType* JsonFactory::createBool(bool val){
		return new JsonValueBool(val);
	}
	JsonType* JsonFactory::createString(json_char* val){
		return new JsonValueString(val);
	}	
	JsonType* JsonFactory::createNull(){
		return new JsonValueNull();
	}	

	JsonObject*  JsonFactory::createObject(){
		return new JsonObject();
	}	

	JsonArray* JsonFactory::createArray(){
		return new JsonArray();
	}
}