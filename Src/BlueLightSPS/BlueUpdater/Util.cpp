#include "stdafx.h"
#include "Util.h"
#include <atlconv.h>
#include "Encoding.h"
namespace Util_Tools
{

	Util::Util()
	{
	}


	Util::~Util()
	{
	}
	static std::string base64_chars =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	void Util::base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len, CString& strBase64) {
		int i = 0;
		int j = 0;
		unsigned char char_array_3[3];
		unsigned char char_array_4[4];
		strBase64 = L"";
		while (in_len--) {
			char_array_3[i++] = *(bytes_to_encode++);
			if (i == 3) {
				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for (i = 0; (i < 4); i++)
					strBase64 += (wchar_t)base64_chars[char_array_4[i]];
				i = 0;
			}
		}

		if (i)
		{
			for (j = i; j < 3; j++)
				char_array_3[j] = '\0';

			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (j = 0; (j < i + 1); j++)
				strBase64 += (wchar_t)base64_chars[char_array_4[j]];

			while ((i++ < 3))
				strBase64 += (wchar_t)'=';

		}
	}





	void Util::Split(CString& src, TCHAR split, std::vector<CString>& retData)
	{
		int start = 0;
		int index = src.Find(split);
		retData.clear();
		while (index >= 0)
		{
			retData.push_back(src.Mid(start, index - start));
			start = index + 1;
			index = src.Find(split, start);
		}
		if (!src.IsEmpty())
		{
			retData.push_back(src.Mid(start));
		}
	}

	void Util::Split(CString& src, TCHAR split, std::vector<int>& retData)
	{
		int start = 0;
		int index = src.Find(split);
		while (index >= 0)
		{
			retData.push_back(_tstoi(src.Mid(start, index - start)));
			start = index + 1;
			index = src.Find(split, start);
		}
		if (!src.IsEmpty())
		{
			retData.push_back(_tstoi(src.Mid(start)));
		}
	}

	void Util::Join(const std::vector<CString>& data, CString& dest)
	{
		for (int i = 0, len = data.size(); i < len; ++i)
		{
			dest += data[i];
			if (i + 1 < len)
			{
				dest += _T(",");
			}
		}
	}

	void Util::Join(const std::vector<int>& data, CString& dest)
	{
		CString strFmt;
		for (int i = 0, len = data.size(); i < len; ++i)
		{
			strFmt.Format(_T("%d"), data[i]);
			dest += strFmt;
			if (i + 1 < len)
			{
				dest += _T(",");
			}
		}
	}


	bool Util::MakeDir(LPCTSTR lpPath)
	{
		bool bRet = true;

		CString csPathname = lpPath;
		int iEnd = csPathname.ReverseFind('\\');
		int iPt = csPathname.Find('\\');
		if ((iPt >= 0) && (csPathname[iPt - 1] == ':'))
		{
			iPt = csPathname.Find('\\', iPt + 1);
		}

		CString path;
		while ((iPt != -1) && (iPt <= iEnd))
		{
			path = csPathname.Left(iPt);

			WIN32_FIND_DATA  wfd;
			BOOL rValue = FALSE;
			HANDLE hFind = FindFirstFile(path, &wfd);
			if ((INVALID_HANDLE_VALUE != hFind) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				rValue = TRUE;
			}
			else
			{
				if (ERROR_PATH_NOT_FOUND == CreateDirectory(path, NULL))
				{
					FindClose(hFind);
					bRet = false;
					break;
				}
			}
			FindClose(hFind);
			iPt = csPathname.Find('\\', iPt + 1);
		}
		return bRet;
	}

	bool Util::DeleteFiles(LPCTSTR strFolderPath)
	{
		CString strPath = strFolderPath;
		if (strPath.Right(1) != _T("\\"))
		{
			strPath += _T("\\");
		}
		CString strFilePath(strPath);
		strPath += _T("*.*");

		HANDLE hFind;
		WIN32_FIND_DATA fd;
		bool bResult = false;
		hFind = ::FindFirstFile(strPath, &fd);
		if (INVALID_HANDLE_VALUE != hFind)
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				CString fileName(fd.cFileName);
				fileName = strFilePath + fileName;
				SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
				if (!DeleteFile(fileName))
				{
					// error log
				}
			}
			else
			{
				CString fileName(fd.cFileName);
				if (0 != fileName.Compare(_T(".")) &&
					0 != fileName.Compare(_T("..")))
				{
					fileName = strFilePath + fileName;
					SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
					DeleteFiles(fileName);
				}
			}
			while (::FindNextFile(hFind, &fd))
			{

				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
					CString fileName(fd.cFileName);
					fileName = strFilePath + fileName;
					SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
					if (!DeleteFile(fileName))
					{
						// error log
					}
				}
				else
				{
					CString fileName(fd.cFileName);
					if (0 != fileName.Compare(_T(".")) &&
						0 != fileName.Compare(_T("..")))
					{
						fileName = strFilePath + fileName;
						SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
						DeleteFiles(fileName);
					}
				}
			}
			::FindClose(hFind);

			bResult = true;
		}
		SetFileAttributes(strFolderPath, FILE_ATTRIBUTE_NORMAL);
		RemoveDirectory(strFolderPath);

		return bResult;
	}

	bool Util::FindSubFolders(LPCTSTR strFolderPath, std::vector<CString> &vecFolderNames)
	{
		CString strPath = strFolderPath;
		if (strPath.Right(1) != _T("\\"))
		{
			strPath += _T("\\");
		}
		CString strFilePath(strPath);
		strPath += _T("*.*");

		HANDLE hFind;
		WIN32_FIND_DATA fd;
		bool bResult = false;
		hFind = ::FindFirstFile(strPath, &fd);
		if (INVALID_HANDLE_VALUE != hFind)
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
// 				CString fileName(fd.cFileName);
// 				fileName = strFilePath + fileName;
//  				SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
// 
// 				vecFolderNames.push_back(fileName);
				//is a file but not folder
			}
			else
			{
				CString fullpath;
				CString fileName(fd.cFileName);
				if (0 != fileName.Compare(_T(".")) &&
					0 != fileName.Compare(_T("..")))
				{
					fullpath = strFilePath + fileName;
					SetFileAttributes(fullpath, FILE_ATTRIBUTE_NORMAL);

					vecFolderNames.push_back(fileName);
				}
			}
			while (::FindNextFile(hFind, &fd))
			{
				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
// 					CString fileName(fd.cFileName);
// 					fileName = strFilePath + fileName;
// 					SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
// 					
// 					vecFolderNames.push_back(fileName);
				}
				else
				{
					CString fullpath;
					CString fileName(fd.cFileName);
					if (0 != fileName.Compare(_T(".")) &&
						0 != fileName.Compare(_T("..")))
					{
						fullpath = strFilePath + fileName;
						SetFileAttributes(fullpath, FILE_ATTRIBUTE_NORMAL);
						vecFolderNames.push_back(fileName);
					}
				}
			}
			::FindClose(hFind);

			bResult = true;
		}
		SetFileAttributes(strFolderPath, FILE_ATTRIBUTE_NORMAL);

		return bResult;
	}

	bool Util::GetExpandPath(LPCTSTR pszEnvironmentPath, CString &csExpandPath)
	{
		bool bRet(false);
		TCHAR *pszPath = NULL;

		do
		{
			if (NULL == pszEnvironmentPath)
			{
				break;
			}

			DWORD dw = ::ExpandEnvironmentStrings(pszEnvironmentPath, NULL, 0);
			if (0 == dw)
			{
				break;
			}

			pszPath = new TCHAR[dw + 1];
			if (NULL == pszPath)
			{
				break;
			}
			::SecureZeroMemory(pszPath, sizeof(TCHAR) * (dw + 1));
			dw = ::ExpandEnvironmentStrings(pszEnvironmentPath, pszPath, dw + 1);
			if (0 == dw)
			{
				break;
			}

			csExpandPath = pszPath;
			bRet = true;
		} while (false);

		if (NULL != pszPath)
		{
			delete[]pszPath;
			pszPath = NULL;
		}

		return bRet;
	}

	LPCTSTR Util::ToString(bool bVal)
	{
		return bVal ? L"true" : L"false";
	}

	bool Util::MakeDateQueryCommand(bool bHasFrom, bool bHasTo, CString& strFrom, CString& strTo, CString& strVal)
	{
		if (bHasFrom && bHasTo)
		{
			strVal.Format(_T("@between %s and %s"), strFrom, strTo);
		}
		else if (bHasFrom)
		{
			strVal.Format(_T("@>= %s"), strFrom);
		}
		else if (bHasTo)
		{
			strVal.Format(_T("@<= %s"), strTo);
		}
		else
		{
			return false;
		}
		return true;
	}


	static inline bool is_base64(unsigned char c) {
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

	CString Util::base64_decode(CString& strBase64Src)
	{
		CString strDest;
		base64_decode(strBase64Src, strDest);
		return strDest;
	}

	void Util::base64_decode(CString& strBase64Src, CString& strBase64Dest)
	{
		int in_len = strBase64Src.GetLength();
		int i = 0;
		int j = 0;
		int in_ = 0;
		unsigned char char_array_4[4], char_array_3[3];
		std::string ret;

		while (in_len-- && (strBase64Src[in_] != '=') && is_base64(strBase64Src[in_])) {
			char_array_4[i++] = strBase64Src[in_]; in_++;
			if (i == 4) {
				for (i = 0; i < 4; i++)
					char_array_4[i] = base64_chars.find(char_array_4[i]);

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (i = 0; (i < 3); i++)
					ret += char_array_3[i];
				i = 0;
			}
		}

		if (i) {
			for (j = i; j < 4; j++)
				char_array_4[j] = 0;

			for (j = 0; j < 4; j++)
				char_array_4[j] = base64_chars.find(char_array_4[j]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (j = 0; (j < i - 1); j++)
				ret += char_array_3[j];
		}

		strBase64Dest = (LPCTSTR)ret.c_str();
		strBase64Dest.ReleaseBuffer(ret.length() / 2);
	}

}