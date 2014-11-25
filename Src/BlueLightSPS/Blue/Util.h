#pragma once
#include "UILib/BSStatic.h"
#include "UILib/BSButton.h"

class Util
{
public:
	Util();
	~Util();
	static void SetWindowSize(HWND hWnd, int iWheight, int iHeight);
	static void SetClientSize(HWND hWnd, int iWheight, int iHeight);
	static CComboBox* CreateComboBox(CWnd* pParent, UINT Id, CString csFont, int iFSize);
	static CBSStatic* CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
	static CEdit* CreateEdit(CWnd* pParent, UINT Id, CString csDefaultText, CString csFont, int iFSize);
	static CDateTimeCtrl* CreateDateTimePicker(CWnd* pParent, UINT Id, CString csFont, int iFSize);
	static CBSButton* CreateButton(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);

};

