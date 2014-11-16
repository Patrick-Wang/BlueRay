#pragma once
#include "UILib\BSButton.h"
class CBPButton :	public CBSButton
{
public:
	CBPButton(BOOL bLink = FALSE);
	~CBPButton();
	void EnableBorder(bool bEnable);
	void SetBSFont(int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	BOOL m_bLink;

};

