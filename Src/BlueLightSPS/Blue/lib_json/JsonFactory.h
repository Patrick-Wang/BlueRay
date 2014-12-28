#pragma once
#include "JsonType.h"
#include <vector>
namespace Json{
	class JsonFactory{
	public:
		static JsonType* createInt(int val);
		static JsonType* createFloat(float val);
		static JsonType* createBool(bool val);
		static JsonType* createString(json_char* val);
		static JsonObject* createObject();
		static JsonType* createNull();
		static JsonArray* createArray();
	};
}