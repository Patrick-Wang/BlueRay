#include "StdAfx.h"
#include "BSButton.h"


CBSButton::CBSButton(void)
    :CBSObject()
	, m_bHasInsideColor(false)
	, m_bHasBorderColor(false)
	, m_width(1)
{
}

CBSButton::~CBSButton(void)
{
}

BEGIN_MESSAGE_MAP(CBSButton, CBSObject)
    ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void CBSButton::RePaintDC(RECT rect, BOOL bRShow)
{
	CBSObject::OnEraseBkgnd(NULL);
	OnPaint();
}
BOOL CBSButton::OnEraseBkgnd(CDC* pDC)
{
	CString sCaption;
	GetWindowText(sCaption); 
	if (sCaption.IsEmpty())
	{
		return CBSObject::OnEraseBkgnd(pDC); 
	}
	else 
	{
		return FALSE;
	}
}
void CBSButton::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CBSObject::OnPaint() for painting messages
    
	//CDC* dc = CDC::FromHandle(GetDC()->GetSafeHdc()); // device context for painting
	RECT rt;
	GetWindowRect(&rt);
	ScreenToClient(&rt);
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	HDC hDC = memDc.GetSafeHdc();
	CBitmap btScreen;
	btScreen.CreateCompatibleBitmap(&dc, rt.right - rt.left, rt.bottom - rt.top);
	memDc.SelectObject(&btScreen);
	//if (m_bHasPaintDC)
	//{
	//	hDC = m_hPaintDC;
	//}

	if (m_bHasBorderColor){
		CBSObject::OnEraseBkgnd(&memDc);
	}

	if (m_bHasInsideColor)
	{
		CBSObject::FillRect(hDC, rt, m_crInsideColor[GetState()]);
	}

	if (m_bHasBorderColor){
		CBSObject::DrawRect(hDC, CRect(rt.left + 1, rt.top + 1, rt.right - 1, rt.bottom - 1), m_crBorderColor[GetState()], m_width);
	}

    //Draw text
    CString sCaption;
    GetWindowText(sCaption); 
    if (!sCaption.IsEmpty())
    {
		if (!m_bHasInsideColor && !m_bHasBorderColor)
		{
			CBSObject::OnEraseBkgnd(&memDc);
		}
		

        COLORREF crText;
        RECT rtText;
        if (m_crTextColor2[GetState()] == 0)
        {
            crText = m_crTextColor2[BS_NORMAL];
        }
        else
        {
            crText = m_crTextColor2[GetState()];
        }

        if (crText != 0)
        {            
            if (!m_bIsUseTextRect)
            {
                rtText.left = rt.left;
                rtText.right = rt.right;
                rtText.top = rt.top + 1;
                rtText.bottom = rt.bottom + 1;
            }
            else
            {
                rtText.left = m_rtTextRect.left;
                rtText.right = m_rtTextRect.right;
                rtText.top = m_rtTextRect.top + 1;
                rtText.bottom = m_rtTextRect.bottom + 1;
            }

            DrawText(hDC, &PAINTDC(rtText), sCaption, (HFONT)GetFont()->GetSafeHandle(), crText, m_uiTextAlign);
        }

        if (m_crTextColor[GetState()] == 0)
        {
            crText = m_crTextColor[BS_NORMAL];
        }
        else
        {
            crText = m_crTextColor[GetState()];
        }
        
        if (!m_bIsUseTextRect)
        {
            rtText.left = rt.left;
            rtText.right = rt.right;
            rtText.top = rt.top;
            rtText.bottom = rt.bottom;
        }
        else
        {
            rtText.left = m_rtTextRect.left;
            rtText.right = m_rtTextRect.right;
            rtText.top = m_rtTextRect.top;
            rtText.bottom = m_rtTextRect.bottom;
        }
        
        DrawText(hDC, &PAINTDC(rtText), sCaption, (HFONT)GetFont()->GetSafeHandle(), crText, m_uiTextAlign);
        
    }
	dc.BitBlt(rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, &memDc, rt.left, rt.top, SRCCOPY);
	btScreen.DeleteObject();
	memDc.DeleteDC();
}

BOOL CBSButton::Create(CWnd* pParentWnd, UINT nID)
{
    // TODO: Add your specialized code here and/or call the base class
    CRect rt(0, 0, 0, 0);
    CBSObject::Create(_T("Button"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, rt, pParentWnd, nID);
    ((CButton*)this)->SetButtonStyle(BS_OWNERDRAW);

    return TRUE;
}

void CBSButton::OnMouseLeave()
{
	CBSObject::OnMouseLeave();
	d_OnMoveLeave();
}

void CBSButton::OnMouseMove( UINT nFlags, CPoint point )
{
	BOOL bHover = m_isHover;
	CBSObject::OnMouseMove(nFlags, point);
	if ((bHover != m_isHover) && m_isHover)
	{
		//OnMoveHover
		d_OnMoveHover();
	}
}

void CBSButton::SetTextColor(enumBSBtnState BtnState, COLORREF crTextColor)
{
	if (BS_HOVER == BtnState){
		m_isHoverEnabled = TRUE;
	}
	else if (BS_CLICK == BtnState)
	{
		m_isClickEnabled = TRUE;
	}
	
	__super::SetTextColor(BtnState, crTextColor);
}

void CBSButton::SetColorInside(enumBSBtnState BtnState, COLORREF crBGColor)
{
	if (BS_HOVER == BtnState){
		m_isHoverEnabled = TRUE;
	}
	else if (BS_CLICK == BtnState)
	{
		m_isClickEnabled = TRUE;
	}
	m_bHasInsideColor = true;
	m_crInsideColor[BtnState] = crBGColor;
}

void CBSButton::SetColorBorder(enumBSBtnState BtnState, COLORREF crBGColor, int width /*= 1*/)
{
	m_width = width;
	if (BS_HOVER == BtnState){
		m_isHoverEnabled = TRUE;
	}
	else if (BS_CLICK == BtnState)
	{
		m_isClickEnabled = TRUE;
	}
	m_bHasBorderColor = true;
	m_crBorderColor[BtnState] = crBGColor;
}
