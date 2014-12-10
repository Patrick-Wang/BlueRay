#pragma once
#include "JsonType.h"
#include <vector>
namespace Json{
	class JsonFactory{
	public:
		static JsonType* create(int val);
		static JsonType* create(long long value);
		static JsonType* create(float val);
		static JsonType* create(double val);
		static JsonType* create(bool val);
		static JsonType* create(json_char* val);
		static JsonObject* createObject();
		static JsonType* create();
		static JsonArray* createArray();
	};
}