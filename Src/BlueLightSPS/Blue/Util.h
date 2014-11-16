#pragma once
class Util
{
public:
	Util();
	~Util();
	static void SetWindowSize(HWND hWnd, int iWheight, int iHeight);
	static CComboBox* CreateComboBox(CWnd* pParent, UINT Id);
};

