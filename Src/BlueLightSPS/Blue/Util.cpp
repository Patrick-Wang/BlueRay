#include "stdafx.h"
#include "Util.h"
#include "BRComboBox.h"

Util::Util()
{
}


Util::~Util()
{
}

void Util::SetWindowSize(HWND hWnd, int iWheight, int iHeight)
{
	CRect WindowRect;
	CRect ClientRect;
	GetWindowRect(hWnd, &WindowRect);
	GetClientRect(hWnd, &ClientRect);
	int deltaW = WindowRect.Width() - ClientRect.Width();
	int deltaH = WindowRect.Height() - ClientRect.Height();
	MoveWindow(hWnd, WindowRect.left, WindowRect.top, iWheight + deltaW, iHeight + deltaH, true);
}

CComboBox* Util::CreateComboBox(CWnd* pParent, UINT Id, CFont* pFont)
{
	CComboBox* pComb = new CComboBox();
	pComb->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(0, 0, 0, 0), pParent, Id);
	pComb->SetFont(pFont);
	return pComb;
}

CBSStatic* Util::CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize)
{
	CBSStatic* pStatic = new CBSStatic();
	pStatic->Create(pParent, Id);

	pStatic->SetWindowText(csWindowText);
	
	pStatic->SetBSFont(csFont, iFSize);

	return pStatic;
}
