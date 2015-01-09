/* ******************* */
/* */
/* Copyright 2014 Sony Corporation */
/* */
/* ******************* */
#pragma once
#include <WTypes.h>
#include <memory>
class CEncoding
{
public:
	CEncoding(void);
	virtual ~CEncoding(void);

	static CEncoding* Utf16LE();
	static CEncoding* Utf8();
	static CEncoding* Ansi();

	//bytesEncoded is end with '\0' or L'\0'
	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16le) = 0;
	virtual void GetString(unsigned char* srcBytesEncoded, CString& destUtf16le) = 0;

private:
	static CEncoding* m_utf16le;
	static CEncoding* m_utf8;
	static CEncoding* m_ansi;
};

