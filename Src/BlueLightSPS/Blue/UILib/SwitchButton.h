/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:      CSwitchButton

Summary:    

Author:     sunfd  2011/6/11

Methods:   

C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/


#pragma once
#include "bsbutton.h"
#include "BSStatic.h"

#define WM_SWITCH_POS_CHANGE WM_APP + 521


typedef enum tagSwitchPicEnum
{
	LEFT,
	RIGHT,
	SWITCH_END
}SwitchEnum;

typedef enum tagStateEnum
{
	SWST_NORMAL,
	SWST_PUSH,
	SWBTN_END = 2
}StateEnum;

class CSwitchButton : public CBSButton
{
public:
	CSwitchButton(void);
	~CSwitchButton(void);

	void SetSwitchPic(SwitchEnum enSwitchBtn, StateEnum enSwitchState, UINT uiID);
	void SetSwitchText(SwitchEnum enSwitchPic, CString cstrText);
	void SetSwithcColor(SwitchEnum enSwitchPic, COLORREF dwColor);

	void SetSwitchState(SwitchEnum enSwitch);
	SwitchEnum GetSwitchState(void) {return m_enSwitch;}
	void SetInnerScale(float fScale_X, float fScale_Y);
	void SetInnerOffSet(POINT& pt);
	DECLARE_MESSAGE_MAP()

	void GetSwitchRect(CRect& rcSwtich);
	void OnMouseMove(UINT nFlags, CPoint point);
	//void OnLButtonDown(UINT nFlags, CPoint point);
	//void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDblClk(UINT nFlags, CPoint point);//wsh add
	
	afx_msg void OnPaint();
protected:
	UINT m_auiPicID[SWITCH_END][SWBTN_END];
	CString m_astrText[SWITCH_END];
	COLORREF m_adwColor[SWITCH_END];
	SwitchEnum m_enSwitch;
	StateEnum  m_enSwState;
	float m_fInnerScale_X;
	float m_fInnerScale_Y;
	CPoint m_ptOffset;
};

