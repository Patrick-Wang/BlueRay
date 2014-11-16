#include "stdafx.h"
#include "BPComboBox.h"
#include "bsobject.h"

CBPComboBox::CBPComboBox()
{
}


CBPComboBox::~CBPComboBox()
{
}

void CBPComboBox::Create(CWnd* pParent, UINT id)
{
	CComboBox::Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(0, 0, 0, 0), pParent, id);
	CFont* pFont = CBSObject::GetFontPtr(_T("Segoe UI"), 12, FALSE, FALSE, FALSE);
	ShowWindow(SW_SHOW);
	SetFont(pFont);
}
BEGIN_MESSAGE_MAP(CBPComboBox, CComboBox)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


void CBPComboBox::OnDestroy()
{
	CComboBox::OnDestroy();
	CFont* pFont = GetFont();
	//->DeleteObject();
	delete pFont;
}
