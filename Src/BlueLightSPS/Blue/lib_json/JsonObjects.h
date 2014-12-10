#pragma once
#include "JsonType.h"
#include <map>
namespace Json
{
	//class JsonField : public JsonType{
	//private:
	//	friend class JsonFactory;
	//	JsonField(){}
	//public:
	//	JsonField(json_char* fieldName, JsonType* fieldValue)
	//		: m_fieldName(fieldName), m_fieldValue(fieldValue){
	//			if (fieldValue->tag() == jfield)
	//			{
	//				throw std::exception("invalid");
	//			}
	//	}

	//	json_string& name(){
	//		return m_fieldName;
	//	}

	//	JsonTypePtr& value(){
	//		return m_fieldValue;
	//	}

	//	virtual JsonTypeTag tag(){
	//		return jfield;
	//	}

	//	virtual void asJson(json_stringstream& os){
	//		
	//	}

	//private:
	//	json_string m_fieldName;
	//	JsonTypePtr m_fieldValue;
	//};

	class JsonObject : public JsonType{

		typedef std::map<json_string, std::shared_ptr<JsonType>> JsonFields;
	private:
		friend class JsonFactory;
		JsonObject(){}
	public:

		JsonFields& fields(){
			return m_fields;
		}
	

		int asInt(json_char* name){
			preCheck(name, JsonTypeTag::jint);
			return static_cast<JsonValue<int>*>(m_fields[name].get())->value();
		}

		
		float asFloat(json_char* name){
			preCheck(name, JsonTypeTag::jfloat);
			return static_cast<JsonValue<float>*>(m_fields[name].get())->value();
		}

		json_string& asString(json_char* name){
			preCheck(name, JsonTypeTag::jstring);
			return static_cast<JsonValue<json_string>*>(m_fields[name].get())->value();
		}

		bool asBool(json_char* name){
			preCheck(name, JsonTypeTag::jbool);
			return static_cast<JsonValue<bool>*>(m_fields[name].get())->value();
		}

		JsonArray& asArray(json_char* name){
			preCheck(name, JsonTypeTag::jarray);
			return *((JsonArray*)(m_fields[name].get()));
		}

		JsonObject& asObject(json_char* name){
			preCheck(name, JsonTypeTag::jobject);
			return *static_cast<JsonObject*>(m_fields[name].get());
		}


		JsonType* field(json_char* name){
			return static_cast<JsonType*>(m_fields[name].get());
		}

		JsonObject& add(json_char* name, JsonType* val){
			if (m_fields[name].get() != val)
			{
				m_fields[name].reset(val);
			}
			return *this;
		}

		void asJson(json_stringstream& os){
			os << J("{");
			if (!m_fields.empty())
			{
				JsonFields::iterator it = m_fields.begin();
				os << "\"" << it->first << "\":";
				it->second->asJson(os);
				for (++it; it != m_fields.end(); ++it)
				{
					os << J(",");
					os << "\"" << it->first << "\":";
					it->second->asJson(os);
				}

			}
			os << J("}");
		}

		virtual JsonTypeTag tag(){
			return jobject;
		}
	private:
		void preCheck(json_char* key, JsonTypeTag tag){
			if (m_fields.find(key) == m_fields.end())
			{
				throw std::exception("No field");
			}

			if (m_fields[key]->tag() != tag)
			{
				throw std::exception("type not match");
			}
		}
	private:
		JsonFields m_fields;
	};

	class JsonArray : public JsonType{
		typedef std::list<std::shared_ptr<JsonType>> JsonItems;

	private:
		friend class JsonFactory;
		JsonArray(){}
	public:
		JsonItems& items(){
			return m_objects;
		}

		JsonArray& add(JsonType* jsonType){
			m_objects.push_back(std::shared_ptr<JsonType>(jsonType));
			return *this;
		}

		virtual JsonTypeTag tag(){
			return jarray;
		}

		void asJson(json_stringstream& os){
			os << J("[");
			if (!m_objects.empty())
			{
				JsonItems::iterator it = m_objects.begin();
				(*it)->asJson(os);
				for (++it; it != m_objects.end(); ++it)
				{
					os << J(",");
					(*it)->asJson(os);
				}
			}
			os << J("]");
		}

	private:
		JsonItems m_objects;
	};
}
