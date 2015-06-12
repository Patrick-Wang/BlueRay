#pragma once
#include "JsonType.h"
namespace Json{

	class JsonString{
	public:
		JsonString(bool zeroTerminate);

		JsonString(json_char* start, int length, bool zeroTerminate);

		JsonString(json_char* start, int length);

		JsonString(json_char* start);

		JsonString(json_string& start);

		~JsonString();

		JsonString& setString(json_char* begin, int len);

		bool equals(json_char* val);

		int indexOf(json_char ch, int index = 0);

		int lastIndexOf(json_char ch, int index = -1);

		int length(){
			return m_length;
		}

		json_char* str(){
			return m_begin;
		}

		json_char& operator[] (int index){
			return m_begin[index];
		}

	private:
		int m_length;
		json_char* m_begin;
		json_char m_rawEnd;
		bool m_zeroTerminate;
	};
}

