#pragma once
#include "afxwin.h"
class CBPComboBox :
	public CComboBox
{
public:
	CBPComboBox();
	~CBPComboBox();
	void Create(CWnd* pParent, UINT id);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
};

