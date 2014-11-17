#include "StdAfx.h"
#include "BSScrollbar.h"

#define SCROLLBAR_MINIMAL_LEN   (2)

// CBSScrollbar

IMPLEMENT_DYNAMIC(CBSScrollbar, CBSObject)

CBSScrollbar::CBSScrollbar()
: m_iMaxLen(0)
, m_iVisibleLen(0)
, m_iCurPos(0)
, m_iBodyWidth(0)
, m_iBodyHeight(0)
, m_Orientation(SB_VER)
{
	::SecureZeroMemory(m_pScrollBarImgs, sizeof(m_pScrollBarImgs));
}

CBSScrollbar::~CBSScrollbar()
{
	for (int i = 0; i < SRB_END; i++)
	{
		delete m_pScrollBarImgs[i];
	}
}

BEGIN_MESSAGE_MAP(CBSScrollbar, CBSObject)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_WM_DRAWITEM()
END_MESSAGE_MAP()

// CBSScrollbar message handlers


int CBSScrollbar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CBSObject::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here
	
    return 0;
}

void CBSScrollbar::RePaintDC(RECT rect, BOOL bRShow)
{
	CBSObject::OnEraseBkgnd(NULL);
	OnPaint();
}

void CBSScrollbar::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CBSObject::OnPaint() for painting messages
	HDC hDC = dc.GetSafeHdc();
	if (m_bHasPaintDC)
	{
		hDC = m_hPaintDC;
	}

	do 
	{
		if (NULL == hDC || (m_iMaxLen <= 0) || (m_iMaxLen - m_iVisibleLen <= 0))
		{
			break;
		}

		CRect rect; 
		GetWindowRect(&rect);
		ScreenToClient(&rect);
		if (rect.Width() <= 0 || rect.Height() <= 0)
		{
			break;
		}

		if (SB_VER == m_Orientation)
		{
			if (m_iBodyWidth <= 0 || m_iBodyWidth > rect.Width())
			{
				m_iBodyWidth = rect.Width();
			}

			int bodyLeft = rect.left + (rect.Width() - m_iBodyWidth) / 2;
			int bodyHeight = rect.Height() * m_iVisibleLen / m_iMaxLen;
			if (bodyHeight < SCROLLBAR_MINIMAL_LEN)
			{
				bodyHeight = SCROLLBAR_MINIMAL_LEN;
			}
			int bodyTop = rect.top + (rect.Height() - bodyHeight) * m_iCurPos / (m_iMaxLen - m_iVisibleLen);
			CRect bodyRect(bodyLeft, bodyTop, bodyLeft + m_iBodyWidth, bodyTop + bodyHeight);

			//CBSObject::DrawPNG(hDC, PaintDCRect(rect), m_pScrollBarImgs[SRB_BACK]);
			CBSObject::DrawPNG(hDC, PaintDCRect(bodyRect), m_pScrollBarImgs[SRB_BODY]);
		}
		else
		{
			if (m_iBodyHeight <= 0 || m_iBodyHeight > rect.Height())
			{
				m_iBodyHeight = rect.Height();
			}

			int bodyTop = rect.top + (rect.Height() - m_iBodyHeight) / 2;
			int bodyWidth = rect.Width() * m_iVisibleLen / m_iMaxLen;
			if (bodyWidth < SCROLLBAR_MINIMAL_LEN)
			{
				bodyWidth = SCROLLBAR_MINIMAL_LEN;
			}
			int bodyLeft = rect.left + (rect.Width() - bodyWidth) * m_iCurPos / (m_iMaxLen - m_iVisibleLen);
			CRect bodyRect(bodyLeft, bodyTop, bodyLeft + bodyWidth, bodyTop + m_iBodyHeight);

			//CBSObject::DrawPNG(hDC, PaintDCRect(rect), m_pScrollBarImgs[SRB_BACK]);
			CBSObject::DrawPNG(hDC, PaintDCRect(bodyRect), m_pScrollBarImgs[SRB_BODY]);
		}
	} while (FALSE);
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetSBPictureIDs
                
  Summary:      Set scrollbar picture IDs

  Author:       zhang.xu 2011.06.04

  Args:         UINT uiBeginArrowID
                UINT uiBodyID
                UINT uiEndArrowID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSScrollbar::SetSBPictureIDs(UINT uiBackID, UINT uiBodyID)
{
    //delete m_pScrollBarImgs[SRB_BACK];
	//m_pScrollBarImgs[SRB_BACK] = CBSObject::LoadImage(uiBackID, AfxGetInstanceHandle());
	delete m_pScrollBarImgs[SRB_BODY];
	m_pScrollBarImgs[SRB_BODY] = CBSObject::LoadImage(uiBodyID, AfxGetInstanceHandle());
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBarLengths
                
  Summary:      Set scrollbar length

  Author:       zhang.xu 2011.06.04

  Args:         int MaxLen

                int VisableLen

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSScrollbar::SetBarLengths(int iMaxLen, int iVisableLen)
{
    m_iMaxLen = iMaxLen;
    m_iVisibleLen = iVisableLen;
	RedrawWindow();
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBarPos
                
  Summary:      Set scrollbar position

  Author:       zhang.xu 2011.06.04

  Args:         int MaxSize

                int CurID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSScrollbar::SetBarPos(int iCurID)
{
    m_iCurPos = iCurID;
	RedrawWindow();
}

BOOL CBSScrollbar::Create(CWnd* pParentWnd, UINT nID)
{
	CRect rt(0, 0, 0, 0);
	CBSObject::Create(NULL, NULL, WS_VISIBLE | WS_CHILD, rt, pParentWnd , nID);

	return TRUE;
}

void CBSScrollbar::SetBodyWidth(UINT nWidth)
{
	m_iBodyWidth = nWidth;
}
