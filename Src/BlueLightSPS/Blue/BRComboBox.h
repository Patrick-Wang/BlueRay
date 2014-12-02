#pragma once
#include "afxwin.h"
class CBRComboBox :
	public CComboBox
{
public:
	CBRComboBox();
	~CBRComboBox();
	void Create(CWnd* pParent, UINT id);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

