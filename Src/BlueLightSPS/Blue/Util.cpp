#include "stdafx.h"
#include "Util.h"
#include "BRComboBox.h"
#include <atlconv.h>
namespace Util_Tools
{

	Util::Util()
	{
	}


	Util::~Util()
	{
	}
	static const char* base64_chars =
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



	void Util::SetWindowSize(HWND hWnd, int iWheight, int iHeight)
	{
		CRect WindowRect;
		CRect ClientRect;
		GetWindowRect(hWnd, &WindowRect);
		GetClientRect(hWnd, &ClientRect);
		//int deltaW = WindowRect.Width() - ClientRect.Width();
		//int deltaH = WindowRect.Height() - ClientRect.Height();
		//SetClientSize(hWnd, iWheight - deltaW, iHeight - deltaH);
		::SetWindowPos(hWnd, NULL, 0, 0, iWheight, iHeight, SWP_SHOWWINDOW);
	}

	void Util::SetClientSize(HWND hWnd, int iWheight, int iHeight)
	{
		CRect WindowRect;
		CRect ClientRect;
		GetWindowRect(hWnd, &WindowRect);
		GetClientRect(hWnd, &ClientRect);
		int deltaW = WindowRect.Width() - ClientRect.Width();
		int deltaH = WindowRect.Height() - ClientRect.Height();
		MoveWindow(hWnd, WindowRect.left, WindowRect.top, iWheight + deltaW, iHeight + deltaH, true);
	}

	CComboBox* Util::CreateComboBox(CWnd* pParent, UINT Id, CString csFont, int iFSize, BOOL isReadOnly)
	{
		CFont* pFont = NULL;
		pFont = CBSObject::GetFontPtr(csFont, iFSize, FALSE, FALSE, FALSE);

		CComboBox* pComb = new CComboBox();

		if (isReadOnly)
		{
			pComb->Create(WS_CHILD | /*WS_TABSTOP | */WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL, CRect(0, 0, 0, 0), pParent, Id);
		}
		else
		{
			pComb->Create(WS_CHILD | /*WS_TABSTOP |*/ WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(0, 0, 0, 0), pParent, Id);
		}

		pComb->SetFont(pFont);

		return pComb;
	}

	CBSStatic* Util::CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize)
	{
		CBSStatic* pStatic = new CBSStatic();
		pStatic->Create(pParent, Id);

		pStatic->SetWindowText(csWindowText);

		pStatic->SetBSFont(csFont, iFSize);

		return pStatic;
	}

	CEdit* Util::CreateEdit(CWnd* pParent, UINT Id, CString csDefaultText, CString csFont, int iFSize, bool bMulLine)
	{
		CFont* pFont = NULL;
		CEdit* pEdit = new CEdit();

		pFont = CBSObject::GetFontPtr(csFont, iFSize, FALSE, FALSE, FALSE);

		if (!bMulLine)
		{
			pEdit->CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
				WS_CHILD | /*WS_TABSTOP |*/ WS_VISIBLE/* | WS_BORDER | WS_HSCROLL |
													  WS_VSCROLL | ES_MULTILINE */ | ES_WANTRETURN,
													  CRect(0, 0, 0, 0), pParent, Id);
		}
		else
		{
			pEdit->CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL,
				WS_CHILD | /*WS_TABSTOP |*/ WS_VISIBLE/* | WS_BORDER | WS_HSCROLL | ES_WANTRETURN*/ |
													  WS_VSCROLL  | ES_MULTILINE ,
													  CRect(0, 0, 0, 0), pParent, Id);
		}


		pEdit->SetFont(pFont);

		return pEdit;
	}


	CDateTimeCtrl* Util::CreateDateTimePicker(CWnd* pParent, UINT Id, CString csFont, int iFSize)
	{
		CFont* pFont = NULL;
		CDateTimeCtrl* pDateTimeCtrl = new CDateTimeCtrl();

		pFont = CBSObject::GetFontPtr(csFont, iFSize, FALSE, FALSE, FALSE);

		pDateTimeCtrl->Create(WS_VISIBLE | WS_CHILD | /*WS_TABSTOP |*/ DTS_RIGHTALIGN | DTS_SHOWNONE, CRect(0, 0, 0, 0), pParent, Id);

		pDateTimeCtrl->SetFont(pFont);

		pDateTimeCtrl->SetTime(COleDateTime::GetCurrentTime());

		pDateTimeCtrl->SetFormat(_T("yyyy-MM-dd"));

		return pDateTimeCtrl;
	}

	CDateTimeCtrl* Util::CreateDateTimePickerWithoutCheckbox(CWnd* pParent, UINT Id, CString csFont, int iFSize)
	{
		CFont* pFont = NULL;
		CDateTimeCtrl* pDateTimeCtrl = new CDateTimeCtrl();

		pFont = CBSObject::GetFontPtr(csFont, iFSize, FALSE, FALSE, FALSE);

		pDateTimeCtrl->Create(WS_VISIBLE | WS_CHILD | /*WS_TABSTOP |*/ DTS_RIGHTALIGN, CRect(0, 0, 0, 0), pParent, Id);

		pDateTimeCtrl->SetFont(pFont);

		pDateTimeCtrl->SetTime(COleDateTime::GetCurrentTime());

		pDateTimeCtrl->SetFormat(_T("yyyy-MM-dd"));

		return pDateTimeCtrl;
	}

	CBRButton* Util::CreateButton(CWnd* pParent, UINT Id, CString csButtonText, CString csFont, int iFSize)
	{
		CBRButton* pButton = new CBRButton();
		pButton->Create(pParent, Id);

		pButton->SetWindowText(csButtonText);

		pButton->SetBSFont(iFSize);

		return pButton;
	}

	CButton* Util::CreateCheckBox(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize)
	{
		CFont* pFont = NULL;
		CButton* pButton = new CButton();
		pButton->Create(csWindowText, /*WS_TABSTOP |*/ WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, CRect(0, 0, 0, 0), pParent, Id);;

		pButton->SetWindowText(csWindowText);

		pFont = CBSObject::GetFontPtr(csFont, iFSize, FALSE, FALSE, FALSE);
		pButton->SetFont(pFont);

		return pButton;
	}


	void Util::Split(CString& src, TCHAR split, std::vector<CString>& retData)
	{
		int start = 0;
		int index = src.Find(split);
		retData.clear();
		while (index > 0)
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
		while (index > 0)
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


	void Util::StringToDate(CString &strData, COleDateTime& objDataTime)
	{
		int iYear = 0;
		int iMonth = 0;
		int iDay = 0;
		int iHour = 0;
		int iMin = 0;
		int iSec = 0;

		swscanf_s(strData.GetBuffer(strData.GetLength()), _T("%d-%d-%dT%d:%d:%d"),
			&iYear, &iMonth, &iDay, &iHour, &iMin, &iSec);
		strData.ReleaseBuffer(strData.GetLength());
		objDataTime.SetDateTime(iYear, iMonth, iDay, 0, 0, 0);
		return;
	}

	void Util::StringToDataTime(CString &strData, COleDateTime& objDataTime)
	{
		int iYear = 0;
		int iMonth = 0;
		int iDay = 0;
		int iHour = 0;
		int iMin = 0;
		int iSec = 0;

		swscanf_s(strData.GetBuffer(strData.GetLength()), _T("%d-%d-%d %d:%d:%d"),
			&iYear, &iMonth, &iDay, &iHour, &iMin, &iSec);
		strData.ReleaseBuffer(strData.GetLength());
		objDataTime.SetDateTime(iYear, iMonth, iDay, iHour, iMin, iSec);
		return;
	}

	//= 0  equal
	//< 0 strRightUpdateTime new
	//>0 strLeftUpdateTime new
	DOUBLE Util::CompareTime(CString& strLeftUpdateTime, CString& strRightUpdateTime)
	{
		COleDateTime objRightTime;
		StringToDataTime(strRightUpdateTime, objRightTime);
		COleDateTime objLeftTime;
		StringToDataTime(strLeftUpdateTime, objLeftTime);
		COleDateTimeSpan objSpan = objLeftTime - objRightTime;
		DOUBLE lSeconds = static_cast<DOUBLE>(objSpan.GetTotalSeconds());
		return lSeconds;
	}

	DOUBLE Util::CompareTime(SYSTEMTIME &tmLeftTime, SYSTEMTIME &tmRightTime)
	{
		COleDateTime objRightTime(tmRightTime);
		COleDateTime objLeftTime(tmLeftTime);
		COleDateTimeSpan objSpan = objLeftTime - objRightTime;
		DOUBLE dSeconds = static_cast<DOUBLE>(objSpan.GetTotalSeconds());
		return dSeconds;
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

	bool Util::FindSubFolders(LPCTSTR strFolderPath, vector<CString> &vecFolderNames)
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

	int Util::CaculateMaxWidthOfItems(CWnd *pWnd, const vector<CString> &strItems, CFont *pfont)
	{
		// Reset the dropped width
		int nNumEntries = strItems.size();
		int nWidth = 0;
		CString str;

		CClientDC dc(pWnd);
		int nSave = dc.SaveDC();
		dc.SelectObject(pfont);

		int nScrollWidth = ::GetSystemMetrics(SM_CXVSCROLL);
		for (int i = 0; i < nNumEntries; i++)
		{
			int nLength = dc.GetTextExtent(strItems[i]).cx + nScrollWidth;
			nWidth = max(nWidth, nLength);
		}

		// Add margin space to the calculations
		nWidth += dc.GetTextExtent(_T("0")).cx;

		dc.RestoreDC(nSave);

		return nWidth;
	}


	bool Util::GetLatestLogonUser(CString& strUserName)
	{
		bool bRet = false;
		bool bInitialized = false;
		CXMLParser objXMLParser;
		do
		{
			int iRet = objXMLParser.Initialize();

			if (ERR_OK != iRet)
			{
				break;
			}

			bInitialized = true;
			CString strPath;

			if (!Util_Tools::Util::GetExpandPath(IDS_SETTING_LOCATION_WITHOUTSLASH, strPath))
			{
				break;
			}

			strPath += IDS_SETTING_FILENAME;
			if (!PathFileExists(strPath))
			{
				break;
			}
			else
			{
				iRet = objXMLParser.LoadXML(strPath);
				if (ERR_OK != iRet)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pSettingRootNode = objXMLParser.QueryRootNode();
				if (NULL == pSettingRootNode)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pUsers = objXMLParser.QueryNode(pSettingRootNode, IDS_SETTING_ITEM_USERS);
				if (NULL == pUsers)
				{
					break;
				}

				CString strLastUser;
				iRet = objXMLParser.GetNodeAttribute(pUsers, IDS_SETTING_ITEM_LASTLOGINUSER, strUserName);

				if (ERR_OK != iRet)
				{
					break;
				}
			}

			bRet = true;
		} while (false);


		if (bInitialized)
		{
			objXMLParser.Uninitialize();
		}

		return bRet;
	}

	bool Util::SetLatestLogonUser(CString& strUserName)
	{
		bool bRet = false;
		bool bInitialized = false;
		CXMLParser objXMLParser;
		do
		{
			int iRet = objXMLParser.Initialize();

			if (ERR_OK != iRet)
			{
				break;
			}

			CString strPath;
			bInitialized = true;

			if (!Util_Tools::Util::GetExpandPath(IDS_SETTING_LOCATION_WITHOUTSLASH, strPath))
			{
				break;
			}

			strPath += IDS_SETTING_FILENAME;
			if (!PathFileExists(strPath))
			{
				if (!Util_Tools::Util::MakeDir(strPath))
				{
					break;
				}

				//create file

				MSXML2::IXMLDOMNodePtr pSettingRootNode = objXMLParser.CreateRoot(IDS_SETTING_ITEM_ROOT);
				if (NULL == pSettingRootNode)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pUsersNode = objXMLParser.CreateChildNode(pSettingRootNode, IDS_SETTING_ITEM_USERS, _T(""));
				if (NULL == pUsersNode)
				{
					break;
				}

				iRet = objXMLParser.SetNodeAttribute(pUsersNode, IDS_SETTING_ITEM_LASTLOGINUSER, strUserName);

				if (ERR_OK == iRet)
				{
					objXMLParser.SaveXML(strPath);
				}
			}
			else
			{
				iRet = objXMLParser.LoadXML(strPath);
				if (ERR_OK != iRet)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pSettingRootNode = objXMLParser.QueryRootNode();
				if (NULL == pSettingRootNode)
				{
					break;
				}

				MSXML2::IXMLDOMNodePtr pUsers = objXMLParser.QueryNode(pSettingRootNode, IDS_SETTING_ITEM_USERS);
				if (NULL == pUsers)
				{
					break;
				}

				CString strLastUser;
				iRet = objXMLParser.SetNodeAttribute(pUsers, IDS_SETTING_ITEM_LASTLOGINUSER, strUserName);

				if (ERR_OK == iRet)
				{
					objXMLParser.SaveXML(strPath);
				}

			}

			bRet = true;
		} while (false);

		if (bInitialized)
		{
			objXMLParser.Uninitialize();
		}

		return bRet;
	}
}