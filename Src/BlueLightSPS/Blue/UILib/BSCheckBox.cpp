#include "StdAfx.h"
#include "BSCheckBox.h"


CBSCheckBox::CBSCheckBox(void)
    :CBSObject()
    ,m_CheckBoxState(CBS_UNCHECK)
    ,m_piCheckImage(NULL)
{
}

CBSCheckBox::~CBSCheckBox(void)
{
    if (m_piCheckImage != NULL)
    {
        delete m_piCheckImage;
        m_piCheckImage = NULL;
    }
}

BEGIN_MESSAGE_MAP(CBSCheckBox, CBSObject)
	///////yuhq
	ON_WM_LBUTTONUP()
    ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL CBSCheckBox::Create(CWnd* pParentWnd, UINT nID)
{
    // TODO: Add your specialized code here and/or call the base class
    CRect rt(0, 0, 0, 0);
    return CBSObject::Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rt, pParentWnd, nID);
}

void CBSCheckBox::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CBSObject::OnPaint() for painting messages

    RECT rt;
    GetWindowRect(&rt);
    ScreenToClient(&rt);

    if (m_CheckBoxState == CBS_CHECKED && m_piCheckImage != NULL)
    {
        DrawPNG(dc.GetSafeHdc(), rt, m_piCheckImage);
    }
}


/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetCheckedPic
                
  Summary:      Set checked pictures

  Author:       zhang.xu 2011.06.03

  Args:         enumBSCheckBoxState CheckBoxState
                    
                UINT uiCheckBoxPicID

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSCheckBox::SetCheckedPic(UINT uiCheckBoxPicID)
{
    m_piCheckImage = LoadImage(uiCheckBoxPicID, AfxGetInstanceHandle());
}



/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetCheck
                
  Summary:      Set checkbox state

  Author:       zhang.xu 2011.06.03

  Args:         enumBSCheckBoxState iCheckState

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSCheckBox::SetCheck(enumBSCheckBoxState iCheckState)
{
    m_CheckBoxState = iCheckState;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetCheck
                
  Summary:      Get checkbox state

  Author:       zhang.xu 2011.06.03

  Args:         None

  Returns:      enumBSCheckBoxState

-----------------------------------------------------------------F-F*/
enumBSCheckBoxState CBSCheckBox::GetCheck(void)
{
    return m_CheckBoxState;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     OnLButtonUp
                
  Summary:      Respond the left button up message

  Author:       yu.hq 2011.06.12

  Args:         UINT nFlags, CPoint point

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSCheckBox::OnLButtonUp( UINT nFlags, CPoint point )
{
	if (m_CheckBoxState)
	{ 
		m_CheckBoxState = CBS_UNCHECK;
	} 
	else
	{
		m_CheckBoxState = CBS_CHECKED;
	}
    Invalidate();

    CBSObject::OnLButtonUp(nFlags, point);
}

