/*+===================================================================
  File:         BSSliderbar.cpp

  Summary:      Custom sliderbar control

  Author:       zhang.xu 2011.06.01

  Classes:      CBSSliderbar

  Functions:    None

  Origin:       BlackSkin
----------------------------------------------------------------------
===================================================================+*/

#include "StdAfx.h"
#include "BSSliderbar.h"



CBSSliderbar::CBSSliderbar(void)
{
	SecureZeroMemory(m_uiSliderPicIDs, BS_END);
	SecureZeroMemory(m_uiBarPicIDs, SBS_END);
	m_rcSlider.X = 0.0f;
	m_rcSlider.Y = 0.0f;
	m_rcBar.X = 0.0f;
	m_rcBar.Y = 0.0f;
	m_isClickEnabled = TRUE;
	m_isHoverEnabled = TRUE;

}


CBSSliderbar::~CBSSliderbar(void)
{
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBarPicIDs
                
  Summary:      Set bar's picture IDs

  Author:       zhang.xu 2011.06.04

  Args:         UINT uiCoverPicID
                
                UINT uiUncoverPicID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSSliderbar::SetBarPicIDs(UINT uiCoverPicID, UINT uiUncoverPicID)
{
	m_uiBarPicIDs[SBS_COVER] = uiCoverPicID;
	m_uiBarPicIDs[SBS_UNCOVER] = uiUncoverPicID;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetSliderPicIDs
                
  Summary:      Set slider picture IDs

  Author:       zhang.xu 2011.06.04

  Args:         enumBSBtnState SliderState
                
                UINT uiPicID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSSliderbar::SetSliderPicIDs(enumBSBtnState SliderState, UINT uiPicID)
{
    m_uiSliderPicIDs[SliderState] = uiPicID;
}

BEGIN_MESSAGE_MAP(CBSSliderbar, CBSObject)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//ON_WM_DESTROY()
END_MESSAGE_MAP()

void CBSSliderbar::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    // TODO: Add your message handler code here and/or call default

    //CBSObject::OnDrawItem(nIDCtl, lpDrawItemStruct);
    
    //Draw cover bar and uncover bar

    //Draw slider
}

BOOL CBSSliderbar::Create(CWnd* pParentWnd, UINT nID)
{
	CRect rt(0, 0, 0, 0);
	CBSObject::Create(_T("BUTTON"), NULL, WS_CLIPCHILDREN    | WS_VISIBLE, rt, pParentWnd, nID);


	return TRUE;
}


void CBSSliderbar::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CBSObject::OnPaint() for painting messages
	CRect rcSliderWnd;
	GetWindowRect(&rcSliderWnd);

	RECT rt = {m_rcBar.X, m_rcBar.Y, m_rcBar.X + m_rcBar.Width, m_rcBar.Y + m_rcBar.Height};
	DrawPNG(dc.GetSafeHdc(), rt, m_uiBarPicIDs[SBS_UNCOVER], AfxGetInstanceHandle());

	rt.right = (m_rcSlider.GetLeft() + m_rcSlider.Width / 2.0f);
	DrawPNG(dc.GetSafeHdc(), rt, m_uiBarPicIDs[SBS_COVER], AfxGetInstanceHandle());

	rt.left = m_rcSlider.X;
	rt.bottom = m_rcSlider.Y + m_rcSlider.Height;
	rt.top = m_rcSlider.Y;
	rt.right = m_rcSlider.X + m_rcSlider.Width;

	DrawPNG(dc.GetSafeHdc(), rt, m_uiSliderPicIDs[GetState()], AfxGetInstanceHandle());
}

void CBSSliderbar::SetSliderSize( UINT uiWidth, UINT uiHeight )
{
	m_rcSlider.Width = uiWidth;
	m_rcSlider.Height = uiHeight;

	CRect rcSliderWnd;
	GetWindowRect(&rcSliderWnd);
	m_rcSlider.Y = (rcSliderWnd.Height() - uiHeight) / 2.0f;
}

void CBSSliderbar::SetBarSize( UINT uiWidth, UINT uiHeight )
{
	CRect rcSliderWnd;
	GetWindowRect(&rcSliderWnd);
	m_rcBar.Y = (rcSliderWnd.Height() - uiHeight) / 2.0f;
	m_rcBar.X =  (rcSliderWnd.Width() - uiWidth) / 2.0f;

	m_rcBar.Width = uiWidth;
	m_rcBar.Height = uiHeight;

	m_rcScrol.X = m_rcBar.X;
	m_rcScrol.Y = m_rcBar.Y;
	m_rcScrol.Width = m_rcBar.Width;
	m_rcScrol.Height = m_rcBar.Height;
}


void CBSSliderbar::OnMouseMove( UINT nFlags, CPoint point )
{

	CWnd::OnMouseMove(nFlags, point);

	if (MK_LBUTTON == nFlags)
	{
		UINT uiPosNew = PointToPos(point);

		UINT uiPosOld = GetPos();

		if (uiPosOld != uiPosNew)
		{
			SetPos(uiPosNew);
			OnPosChange(uiPosOld, uiPosNew);
		}
		m_isHover = FALSE;
	}
	else
	{
		CRect rcSlider(m_rcSlider.X, m_rcSlider.Y, m_rcSlider.X + m_rcSlider.Width, m_rcSlider.Y + m_rcSlider.Height);
	
		if (rcSlider.PtInRect(point))
		{
			if (GetState() != BS_HOVER)
			{
				m_isHover = TRUE;
				Invalidate();
			}
		}
		else
		{
			if (GetState() == BS_HOVER)
			{
				m_isHover = FALSE;
				Invalidate();
			}
			
		}
	}
}

void CBSSliderbar::OnLButtonDown( UINT nFlags, CPoint point )
{

	CWnd::OnLButtonDown(nFlags, point);

	CRect rcSlider(m_rcBar.X, m_rcBar.Y, m_rcBar.X + m_rcBar.Width, m_rcBar.Y + m_rcBar.Height);
	if (rcSlider.PtInRect(point))
	{
		m_bIsDown = TRUE;
	}
	else
	{
		m_bIsDown = FALSE;
	}

	UINT uiPos = PointToPos(point);
	UINT uiPosOld = GetPos();
	if (uiPosOld != uiPos)
	{
		SetPos(uiPos);
		OnPosChange(uiPosOld, uiPos);
		Invalidate();
	}
}

void CBSSliderbar::OnLButtonUp( UINT nFlags, CPoint point )
{
	__super::OnLButtonUp(nFlags, point);
}

void CBSSliderbar::SetRange( UINT uiRange )
{
	m_uiRange = uiRange;
}

UINT CBSSliderbar::GetPos( void )
{
	CPoint pt;
	pt.x = m_rcSlider.X + m_rcSlider.Width / 2.0f;
	pt.y = 0;
	return PointToPos(pt);
}

void CBSSliderbar::SetPos( UINT uiPos )
{
	if (m_uiRange >= uiPos)
	{
		PosToLocation(uiPos);
		//Invalidate();
		CRect rcSlider;
		GetWindowRect(&rcSlider);
		GetParent()->ScreenToClient(&rcSlider);
		GetParent()->InvalidateRect(rcSlider);
	}
}

void CBSSliderbar::PosToLocation( UINT uiPos )
{
	FLOAT fX = GetStepLength() * uiPos;
	m_rcSlider.X = m_rcScrol.X + fX - (m_rcSlider.Width) / 2.0f;
}

FLOAT CBSSliderbar::GetStepLength( void )
{
	return m_rcScrol.Width / m_uiRange;
}

UINT CBSSliderbar::PointToPos( CPoint& pt )
{
	FLOAT fPos = (pt.x - m_rcScrol.X) / GetStepLength();
	UINT uiPos = 0;
	if ((fPos - (int)fPos) > 0.5f)
	{
		uiPos = (int)fPos + 1;
	}
	else
	{
		uiPos = (int)fPos;
	}
	return uiPos;
}

void CBSSliderbar::OnPosChange( UINT uiOldPos, UINT uiNewPos )
{
	GetParent()->SendMessage(WM_SLIDER_DRAG, (WPARAM)this, (LPARAM)uiOldPos);
// 	CRect rcSlider;
// 	GetWindowRect(&rcSlider);
// 	GetParent()->ScreenToClient(&rcSlider);
// 	GetParent()->InvalidateRect(rcSlider);
}

void CBSSliderbar::SetScrolRange( UINT uiWidth )
{
	m_rcScrol.X = m_rcBar.X;
	m_rcScrol.Y = m_rcBar.Y;
	m_rcScrol.Width = m_rcBar.Width;
	m_rcScrol.Height = m_rcBar.Height;

	m_rcScrol.Width = uiWidth;
	m_rcScrol.X = m_rcBar.X + (m_rcBar.Width - uiWidth) / 2.0f;
}

void CBSSliderbar::SetSliderOffset(int iX, int iY)
{
	m_rcSlider.X += iX;
	m_rcSlider.Y += iY;
}

// void CBSSliderbar::NewBKGround(CDC* pBGdc)
// {
// 	if (NULL == m_pDC && NULL == m_pBmp)
// 	{
// 		CRect rcSliderWnd;
// 		GetWindowRect(&rcSliderWnd);
// 		CDC* pThisDC = GetDC();
// 		m_pDC = new CDC;
// 		m_pDC->CreateCompatibleDC(pThisDC);
// 		m_pBmp = new CBitmap;
// 		m_pBmp->CreateCompatibleBitmap(pThisDC, rcSliderWnd.Width(), rcSliderWnd.Height());
// 		m_pDC->SelectObject(m_pBmp);
// 		//m_pDC->SetBkColor(RGB(255, 255, 255));
// 
// 		m_pDC->BitBlt(0, 0, rcSliderWnd.Width(), rcSliderWnd.Height(), pThisDC, 0, 0, SRCCOPY);
// 		ReleaseDC(pThisDC);
// 	}
// 	else if(pBGdc)
// 	{
// 		CRect rcSlider;
// 		GetWindowRect(&rcSlider);
// 		GetParent()->ScreenToClient(&rcSlider);
// 		m_pDC->BitBlt(0, 0, rcSlider.Width(), rcSlider.Height(), pBGdc, rcSlider.left, rcSlider.top, SRCCOPY);
// 	}
// }
// 
// void CBSSliderbar::OnDestroy()
// {
// 	if (m_pDC)
// 	{
// 		m_pBmp->DeleteObject();
// 		delete m_pDC;
// 		delete m_pBmp;
// 		m_pBmp = NULL;
// 		m_pDC = NULL;
// 	}
// }
