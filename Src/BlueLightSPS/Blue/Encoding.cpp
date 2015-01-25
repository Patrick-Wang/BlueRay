#include "stdafx.h"
#include "Encoding.h"


class CUTF8Encoding : public CEncoding
{
public:
	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16le, int len)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == srcUtf16le)
		{
			return ret;
		}
		// wide char to multi char
		ret.second = WideCharToMultiByte(CP_UTF8, 0, srcUtf16le, len, NULL, 0, NULL, NULL);
		ret.first.reset(new byte[ret.second]);
		::WideCharToMultiByte(CP_UTF8, 0, srcUtf16le, len, (LPSTR)(ret.first.get()), ret.second, NULL, NULL);
		return ret;
	}

	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR src)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == src)
		{
			return ret;
		}
		// wide char to multi char
		ret.second = WideCharToMultiByte(CP_UTF8, 0, src, -1, NULL, 0, NULL, NULL);
		ret.first.reset(new byte[ret.second]);
		::WideCharToMultiByte(CP_UTF8, 0, src, -1, (LPSTR)(ret.first.get()), ret.second, NULL, NULL);
		return ret;
	}

	virtual void GetString(unsigned char* srcBytesEncoded, int len, CString& destUtf16le)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}

		int iTextLen = 0;
		iTextLen = MultiByteToWideChar(CP_UTF8, 0, (char*)srcBytesEncoded, len, NULL, 0);
		MultiByteToWideChar(CP_UTF8, 0, (char*)srcBytesEncoded, len, (LPWSTR)destUtf16le.GetBuffer(iTextLen), iTextLen);
		destUtf16le.ReleaseBuffer(iTextLen);
	}

	virtual void GetString(byte* srcBytesEncoded, CString& destUtf16leString)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}

		int iTextLen = 0;
		iTextLen = MultiByteToWideChar(CP_UTF8, 0, (char*)srcBytesEncoded, -1, NULL, 0);
		MultiByteToWideChar(CP_UTF8, 0, (char*)srcBytesEncoded, -1, (LPWSTR)destUtf16leString.GetBuffer(iTextLen), iTextLen);
		destUtf16leString.ReleaseBuffer(iTextLen);
	}
};


class CUTF16LEEncoding : public CEncoding
{
public:
	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16leString)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == srcUtf16leString)
		{
			return ret;
		}
		ret.first.reset((byte*)srcUtf16leString);
		ret.second = sizeof(wchar_t) * (wcslen(srcUtf16leString));
	}

	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16le, int len)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == srcUtf16le)
		{
			return ret;
		}
		ret.first.reset((byte*)srcUtf16le);
		ret.second = sizeof(wchar_t) * (len);
	}

	virtual void GetString(byte* srcBytesEncoded, CString& destUtf16leString)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}
		destUtf16leString = (wchar_t*)srcBytesEncoded;
	}

	virtual void GetString(unsigned char* srcBytesEncoded, int len, CString& destUtf16le)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}
		LPCTSTR dest = destUtf16le.GetBuffer(len / 2);
		memcpy_s((void*)dest, len, srcBytesEncoded, len);
		destUtf16le.ReleaseBuffer(len / 2);
	}
};


class CANSIEncoding : public CEncoding
{
public:
	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16le, int len)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == srcUtf16le)
		{
			return ret;
		}

		// wide char to multi char
		ret.second = WideCharToMultiByte(CP_ACP, 0, srcUtf16le, len, NULL, 0, NULL, NULL);
		byte* buf = new byte[ret.second];
		SecureZeroMemory(buf, ret.second);
		::WideCharToMultiByte(CP_ACP, 0, srcUtf16le, len, (LPSTR)buf, ret.second, NULL, NULL);
		ret.first.reset(buf);
		return ret;
	}

	virtual std::pair<std::shared_ptr<byte>, int> GetBytes(LPCWSTR srcUtf16leString)
	{
		std::pair<std::shared_ptr<byte>, int> ret;

		if (NULL == srcUtf16leString)
		{
			return ret;
		}

		// wide char to multi char
		ret.second = WideCharToMultiByte(CP_ACP, 0, srcUtf16leString, -1, NULL, 0, NULL, NULL);
		byte* buf = new byte[ret.second];
		SecureZeroMemory(buf, ret.second);
		::WideCharToMultiByte(CP_ACP, 0, srcUtf16leString, -1, (LPSTR)buf, ret.second, NULL, NULL);
		ret.first.reset(buf);
		return ret;
	}

	virtual void GetString(byte* srcBytesEncoded, CString& destUtf16leString)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}

		int iTextLen = 0;
		iTextLen = MultiByteToWideChar(CP_ACP, 0, (char*)srcBytesEncoded, -1, NULL, 0);
		MultiByteToWideChar(CP_ACP, 0, (char*)srcBytesEncoded, -1, (LPWSTR)destUtf16leString.GetBuffer(iTextLen + 1), iTextLen + 1);
		destUtf16leString.ReleaseBuffer(iTextLen);
	}

	virtual void GetString(unsigned char* srcBytesEncoded, int len, CString& destUtf16le)
	{
		if (NULL == srcBytesEncoded)
		{
			return;
		}

		int iTextLen = 0;
		iTextLen = MultiByteToWideChar(CP_ACP, 0, (char*)srcBytesEncoded, len, NULL, 0);
		MultiByteToWideChar(CP_ACP, 0, (char*)srcBytesEncoded, len, (LPWSTR)destUtf16le.GetBuffer(iTextLen + 1), iTextLen + 1);
		destUtf16le.ReleaseBuffer(iTextLen);
	}
};

static CUTF8Encoding s_utf8;
static CUTF16LEEncoding s_utf16LE;
static CANSIEncoding s_ansi;

CEncoding* CEncoding::m_utf16le = &s_utf16LE;
CEncoding* CEncoding::m_utf8 = &s_utf8;
CEncoding* CEncoding::m_ansi = &s_ansi;

CEncoding::CEncoding(void)
{
}


CEncoding::~CEncoding(void)
{
}

CEncoding* CEncoding::Utf16LE()
{
	return m_utf16le;
}

CEncoding* CEncoding::Utf8()
{
	return m_utf8;
}

CEncoding* CEncoding::Ansi()
{
	return m_ansi;
}



