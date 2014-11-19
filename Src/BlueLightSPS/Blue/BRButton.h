#pragma once
#include "UILib\BSButton.h"
#include "UILib\Delegate.h"
class CBRButton :	public CBSButton
{
public:
	CBRButton(BOOL bLink = FALSE);
	~CBRButton();
	void EnableBorder(bool bEnable);
	void SetBSFont(int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	BOOL m_bLink;

};

