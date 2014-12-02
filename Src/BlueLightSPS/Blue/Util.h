#pragma once
#include "UILib/BSStatic.h"
#include "BRButton.h"
#include <vector>
class Util
{
public:
	Util();
	~Util();
	static void SetWindowSize(HWND hWnd, int iWheight, int iHeight);
	static void SetClientSize(HWND hWnd, int iWheight, int iHeight);
	static CComboBox* CreateComboBox(CWnd* pParent, UINT Id, CString csFont, int iFSize, BOOL isReadOnly = FALSE);
	static CBSStatic* CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
	static CEdit* CreateEdit(CWnd* pParent, UINT Id, CString csDefaultText, CString csFont, int iFSize);
	static CDateTimeCtrl* CreateDateTimePicker(CWnd* pParent, UINT Id, CString csFont, int iFSize);
	static CBRButton* CreateButton(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
	static CButton* CreateCheckBox(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
	static void Split(CString& src, TCHAR split, std::vector<CString>& retData);
	static void Split(CString& src, TCHAR split, std::vector<int>& retData);
	static void Join(const std::vector<CString>& retData, CString& dest);
	static void Join(const std::vector<int>& retData, CString& dest);
	
	static void StringToDate(CString &strData, COleDateTime& objDataTime);
	static void StringToDataTime(CString &strData, COleDateTime& objDataTime);
	static DOUBLE CompareTime(CString& strLeftUpdateTime, CString& strRightUpdateTime);
	static DOUBLE CompareTime(SYSTEMTIME &tmLeftTime, SYSTEMTIME &tmRightTime);
	static bool MakeDir(LPCTSTR lpPath);
	static bool DeleteFiles(LPCTSTR strFolderPath);
	static bool GetExpandPath(LPCTSTR pszEnvironmentPath, CString &csExpandPath);

};

