#include "stdafx.h"
#include "JsonString.h"

namespace Json{

	JsonString::JsonString( bool zeroTerminate ) 
		: m_zeroTerminate(zeroTerminate)
		, m_begin(NULL)
		, m_length(0)
		, m_rawEnd(J('\0')){

	}

	JsonString::JsonString( json_char* start, int length, bool zeroTerminate ) 
		: m_begin(start)
		, m_length(length)
		, m_zeroTerminate(zeroTerminate){
			if (zeroTerminate){
				m_rawEnd = m_begin[m_length];
				m_begin[m_length] = 0;
			}
	}

	JsonString::JsonString( json_char* start, int length ) 
		: m_begin(start)
		, m_length(length)
		, m_zeroTerminate(false)
		, m_rawEnd(J('\0'))
	{}

	JsonString::JsonString( json_char* start )
		: m_begin(start)
		, m_length(json_strlen(start))
		, m_zeroTerminate(false)
		, m_rawEnd(J('\0'))
	{

	}

	JsonString::JsonString( json_string& str )
		: m_begin((json_char*)str.c_str())
		, m_length(str.length())
		, m_zeroTerminate(false)
		, m_rawEnd(J('\0'))
	{

	}

	JsonString::~JsonString(){
		if (m_zeroTerminate && m_begin != NULL){
			m_begin[m_length] = m_rawEnd;
		}
	}

	JsonString& JsonString::setString( json_char* begin, int len ){
		m_begin = begin;
		m_length = len;
		if (m_zeroTerminate){
			m_rawEnd = m_begin[m_length];
			m_begin[m_length] = 0;
		}
		return *this;
	}

	bool JsonString::equals( json_char* val ){
		if (NULL != val && 0 == _tcscmp(val, m_begin))
		{
			return true;
		}
		return false;
	}

	int JsonString::indexOf( json_char ch, int start /*= 0*/ )
	{
		while (start < m_length)
		{
			if (ch == m_begin[start++]){
				return start - 1;
			}
		}
		return -1;
	}

	int JsonString::lastIndexOf(json_char ch, int index /*= -1*/)
	{
		if (index < 0)
		{
			index = m_length - 1;
		}
		while (index >= 0)
		{
			if (ch == m_begin[index--]){
				return index + 1;
			}
		}
		return -1;
	}

}