#include "stdafx.h"
#include "BRComboBox.h"
#include "UILib/bsobject.h"

CBRComboBox::CBRComboBox()
{
}


CBRComboBox::~CBRComboBox()
{
}

void CBRComboBox::Create(CWnd* pParent, UINT id)
{
	CComboBox::Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(0, 0, 0, 0), pParent, id);
	CFont* pFont = CBSObject::GetFontPtr(_T("Microsoft YaHei"), 12, FALSE, FALSE, FALSE);
	ShowWindow(SW_SHOW);
	SetFont(pFont);
}
BEGIN_MESSAGE_MAP(CBRComboBox, CComboBox)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


void CBRComboBox::OnDestroy()
{
	CComboBox::OnDestroy();
	CFont* pFont = GetFont();
	//->DeleteObject();
	delete pFont;
}


BOOL CBRComboBox::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CComboBox::OnEraseBkgnd(pDC);
}
