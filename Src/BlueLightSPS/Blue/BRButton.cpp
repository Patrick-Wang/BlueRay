#include "stdafx.h"
#include "BRButton.h"
#include "colors.h"

CBRButton::CBRButton(BOOL bLink /*= FALSE*/)
	: m_bLink(bLink)
{

}


CBRButton::~CBRButton()
{
}
BEGIN_MESSAGE_MAP(CBRButton, CBSButton)
	ON_WM_CREATE()
END_MESSAGE_MAP()


int CBRButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBSButton::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (m_bLink){
		SetTextColor(enumBSBtnState::BS_NORMAL, COL_BLUE);
		SetTextColor(enumBSBtnState::BS_HOVER, COL_DARK_BLUE);
		SetTextColor(enumBSBtnState::BS_CLICK, COL_BLUE);
	}
	else{
		SetColorInside(enumBSBtnState::BS_NORMAL, COL_WHITE);
		SetColorInside(enumBSBtnState::BS_HOVER, COL_GRAY);
		SetColorInside(enumBSBtnState::BS_CLICK, COL_WHITE);
		SetColorBorder(enumBSBtnState::BS_NORMAL, COL_BLACK, 2);
		SetColorBorder(enumBSBtnState::BS_HOVER, COL_BLACK, 2);
		SetColorBorder(enumBSBtnState::BS_CLICK, COL_BLACK, 2);
	}

	CBSButton::SetBSFont(_T("Segoe UI"), 12, FALSE, FALSE);

	return 0;
}

void CBRButton::SetBSFont(int fontSize, BOOL bUnderLine /*= FALSE*/, BOOL bBold /*= FALSE*/, BOOL bItalic /*= FALSE*/)
{
	CBSButton::SetBSFont(_T("Segoe UI"), fontSize, bUnderLine, bBold, bItalic);
}

void CBRButton::EnableBorder(bool bEnable)
{
	m_bHasBorderColor = bEnable;
}
