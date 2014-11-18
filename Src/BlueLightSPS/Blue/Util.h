#pragma once
#include "UILib/BSStatic.h"

class Util
{
public:
	Util();
	~Util();
	static void SetWindowSize(HWND hWnd, int iWheight, int iHeight);
	static CComboBox* CreateComboBox(CWnd* pParent, UINT Id);
	static CBSStatic* CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
};

