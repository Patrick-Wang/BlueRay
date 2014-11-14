#include "StdAfx.h"
#include "SwitchButton.h"
//#include "../CommonFile/CommonDefine.h"

CSwitchButton::CSwitchButton(void)
	: m_enSwitch(LEFT)
	, m_enSwState(SWST_NORMAL)
	, m_fInnerScale_X(0.85f)
	, m_fInnerScale_Y(0.8f)
	, m_ptOffset(0, 0)
{

}


CSwitchButton::~CSwitchButton(void)
{
}


BEGIN_MESSAGE_MAP(CSwitchButton, CBSButton)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	//ON_WM_LBUTTONDOWN()
	//ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()




void CSwitchButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CBSObject::OnPaint() for painting messages




	RECT rt;
	GetWindowRect(&rt);
	ScreenToClient(&rt);


	//Draw background picture
	if (!m_bIsUseBGPicRect)
	{       
		DrawPNG(dc.GetSafeHdc(), rt, m_uiBGPictureIDs[GetState()], AfxGetInstanceHandle());
	}
	else
	{
		DrawPNG(dc.GetSafeHdc(), m_rtBGPicRect, m_uiBGPictureIDs[GetState()], AfxGetInstanceHandle());
	}

	CRect rcBtn(rt);
	CRect rcDraw(rcBtn);



	if (m_enSwitch == LEFT)
	{
		rcBtn.left += rcBtn.Width() / 2;
		DrawText(dc.GetSafeHdc(), &rcBtn, m_astrText[RIGHT], (HFONT)GetFont()->GetSafeHandle(), m_adwColor[m_enSwitch], DT_VCENTER | DT_SINGLELINE | DT_CENTER);


		rcDraw.right = rcDraw.left + rcDraw.Width() / 2;
		rcDraw.InflateRect(-rcDraw.Width() * (1 - m_fInnerScale_X) / 2, -rcDraw.Height() * (1 - m_fInnerScale_Y) / 2);
		rcDraw.OffsetRect(m_ptOffset);
		DrawPNG(dc.GetSafeHdc(), rcDraw, m_auiPicID[LEFT][m_enSwState], AfxGetInstanceHandle());
	}
	else
	{
		rcDraw.right = rcDraw.left + rcDraw.Width() / 2;
		DrawText(dc.GetSafeHdc(), &rcDraw, m_astrText[LEFT], (HFONT)GetFont()->GetSafeHandle(), m_adwColor[m_enSwitch], DT_VCENTER | DT_SINGLELINE | DT_CENTER);

		
		rcBtn.left += rcBtn.Width() / 2;
		rcBtn.InflateRect(-rcBtn.Width() * (1 - m_fInnerScale_X) / 2, -rcBtn.Height() * (1 - m_fInnerScale_Y) / 2);

		rcBtn.OffsetRect(-1 * m_ptOffset.x, m_ptOffset.y);
		DrawPNG(dc.GetSafeHdc(), rcBtn, m_auiPicID[RIGHT][m_enSwState], AfxGetInstanceHandle());		
	}

}

void CSwitchButton::SetSwitchPic(SwitchEnum enSwitchBtn, StateEnum enSwitchState, UINT uiID)
{
	m_auiPicID[enSwitchBtn][enSwitchState] = uiID;
}

void CSwitchButton::SetSwitchText( SwitchEnum enSwitchPic, CString cstrText )
{
	m_astrText[enSwitchPic] = cstrText;
}

void CSwitchButton::SetSwithcColor( SwitchEnum enSwitchPic, COLORREF dwColor )
{
	m_adwColor[enSwitchPic] = dwColor;
}



void CSwitchButton::SetSwitchState( SwitchEnum enSwitch )
{
	m_enSwitch = enSwitch;
	Invalidate();
}

void CSwitchButton::OnMouseMove( UINT nFlags, CPoint point )
{
	__super::OnMouseMove(nFlags, point);
}

void CSwitchButton::GetSwitchRect( CRect& rcSwtich )
{
	GetWindowRect(&rcSwtich);
	ScreenToClient(&rcSwtich);
	if (LEFT == m_enSwitch)
	{
		rcSwtich.right = rcSwtich.left + rcSwtich.Width() / 2;
	}
	else
	{
		rcSwtich.left = rcSwtich.left + rcSwtich.Width() / 2;
	}
}

//void CSwitchButton::OnLButtonDown( UINT nFlags, CPoint point )
//{
//	__super::OnLButtonDown(nFlags, point);
//
//	if (!IsWindowEnable())
//	{
//		return;
//	}
//
//	CRect rcSwtich;
//	GetSwitchRect(rcSwtich);
//	if (rcSwtich.PtInRect(point))
//	{
//		m_enSwState = SWST_PUSH;
//		Invalidate();
//		
//	}
//	else
//	{
//		m_enSwState = SWST_NORMAL;
//		if (LEFT == GetSwitchState())
//		{
//			SetSwitchState(RIGHT);
//		}
//		else
//		{
//			SetSwitchState(LEFT);
//		}
//		GetParent()->SendMessage(WM_SWITCH_POS_CHANGE, WPARAM(this), LPARAM(GetSwitchState()));
//	}
//
//}

//void CSwitchButton::OnLButtonUp( UINT nFlags, CPoint point )
//{
//	__super::OnLButtonUp(nFlags, point);
//	if (!IsWindowEnable())
//	{
//		return;
//	}
//	m_enSwState = SWST_NORMAL;
//
//	Invalidate();
//	
//}

//wsh add
void CSwitchButton::OnLButtonDblClk( UINT nFlags, CPoint point )
{
	//no operation
}

void CSwitchButton::SetInnerScale(float fScale_X, float fScale_Y)
{
	m_fInnerScale_X = fScale_X;
	m_fInnerScale_Y = fScale_Y;
}

void CSwitchButton::SetInnerOffSet( POINT& pt )
{
	m_ptOffset.x = pt.x;
	m_ptOffset.y = pt.y;
}

