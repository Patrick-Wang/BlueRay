#include "StdAfx.h"
#include "BSStatic.h"


CBSStatic::CBSStatic(void)
{
    
}


CBSStatic::~CBSStatic(void)
{
}




BEGIN_MESSAGE_MAP(CBSStatic, CBSObject)
    ON_WM_PAINT()
END_MESSAGE_MAP()


void CBSStatic::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CBSObject::OnPaint() for painting messages
    RECT rt;
    GetWindowRect(&rt);
    ScreenToClient(&rt);

    //Draw text
    CString sCaption;
    GetWindowText(sCaption); 
    if (!sCaption.IsEmpty())
    {
        DrawText(dc.GetSafeHdc(), &rt, sCaption, (HFONT)GetFont()->GetSafeHandle(), m_crTextColor[BS_NORMAL], m_uiTextAlign);
    }
}


BOOL CBSStatic::Create(CWnd* pParentWnd, UINT nID)
{
    // TODO: Add your specialized code here and/or call the base class
    CRect rt(0, 0, 0, 0);
	return CBSObject::Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, rt, pParentWnd, nID);
}
