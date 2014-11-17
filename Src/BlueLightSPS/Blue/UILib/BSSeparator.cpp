#include "StdAfx.h"
#include "BSSeparator.h"


CBSSeparator::CBSSeparator(void)
    :CBSObject()
	, m_uiSeparatorBKID(0)
{
}


CBSSeparator::~CBSSeparator(void)
{
}

BEGIN_MESSAGE_MAP(CBSSeparator, CBSObject)
    ON_WM_CREATE()
    ON_WM_PAINT()
END_MESSAGE_MAP()

int CBSSeparator::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CBSObject::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here

    return 0;
}

void CBSSeparator::RePaintDC(RECT rect, BOOL bRShow)
{
	CDC* pDC = GetDC();
    CBSObject::OnEraseBkgnd(pDC);
    ReleaseDC(pDC);
    pDC = NULL;
	OnPaint();
}

void CBSSeparator::SetSeparatorBKPic(UINT uiSeparatorBKID)
{
	m_uiSeparatorBKID = uiSeparatorBKID;
}

void CBSSeparator::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CBSObject::OnPaint() for painting messages
    
	RECT rt;
	GetWindowRect(&rt);
	ScreenToClient(&rt);

	HDC hDC = dc.GetSafeHdc();
	if (m_bHasPaintDC)
	{
		hDC = m_hPaintDC;
	}

	if (NULL != hDC)
	{
		DrawPNG(hDC, PAINTDC(rt), m_uiSeparatorBKID, AfxGetInstanceHandle());	
	}
}

BOOL CBSSeparator::Create(CWnd* pParentWnd, UINT nID)
{
    CRect rt(0, 0, 0, 0);
    return CBSObject::Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rt, pParentWnd, nID);
}
