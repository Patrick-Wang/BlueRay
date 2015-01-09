#pragma once
#include "JsonType.h"
#include <map>
#include <vector>
namespace Json
{
	class JsonObject : public JsonType{

		typedef std::map<json_string, std::shared_ptr<JsonType>> JsonFields;
	private:
		friend class JsonFactory;
		JsonObject(){}
	public:

		JsonFields& fields(){
			return m_fields;
		}
	
		bool isValid(json_char* name){
			return m_fields.find(name) != m_fields.end();
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
			if (!isValid(key))
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
		

	private:
		friend class JsonFactory;
		JsonArray(){}
	public:
		typedef std::vector<std::shared_ptr<Json::JsonType>> JsonItems;
		JsonItems& items(){
			return m_objects;
		}

		std::shared_ptr<Json::JsonType> erase(int index){
			std::shared_ptr<Json::JsonType> ret = *(m_objects.begin() + index);
			m_objects.erase(m_objects.begin() + index);
			return ret;
		}

		int size(){
			return m_objects.size();
		}

		JsonArray& add(JsonType* jsonType){
			m_objects.push_back(std::shared_ptr<JsonType>(jsonType));
			return *this;
		}

		JsonArray& add(std::shared_ptr<JsonType> jsonType){
			m_objects.push_back(jsonType);
			return *this;
		}

		int asInt(int index){
			preCheck(index, JsonTypeTag::jint);
			return static_cast<JsonValue<int>*>(m_objects[index].get())->value();
		}


		float asFloat(int index){
			preCheck(index, JsonTypeTag::jfloat);
			return static_cast<JsonValue<float>*>(m_objects[index].get())->value();
		}

		json_string& asString(int index){
			preCheck(index, JsonTypeTag::jstring);
			return static_cast<JsonValue<json_string>*>(m_objects[index].get())->value();
		}

		bool asBool(int index){
			preCheck(index, JsonTypeTag::jbool);
			return static_cast<JsonValue<bool>*>(m_objects[index].get())->value();
		}

		JsonArray& asArray(int index){
			preCheck(index, JsonTypeTag::jarray);
			return *((JsonArray*)(m_objects[index].get()));
		}

		JsonObject& asObject(int index){
			preCheck(index, JsonTypeTag::jobject);
			return *static_cast<JsonObject*>(m_objects[index].get());
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
		void preCheck(int index, JsonTypeTag tag){
			if (((int)m_objects.size()) <= index)
			{
				throw std::exception("array out off bound");
			}

			if (m_objects[index]->tag() != tag)
			{
				throw std::exception("type not match");
			}
		}
	private:
		JsonItems m_objects;
	};
}
