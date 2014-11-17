#ifndef BSBUTTON_H__
#define BSBUTTON_H__

#include "bsobject.h"
#include "Delegate.h"

class CBSButton :
    public CBSObject
{
public:
	CBSButton(void);
	~CBSButton(void);
    BOOL Create(CWnd* pParentWnd, UINT nID);
	void RePaintDC(RECT rect, BOOL bRShow = TRUE);
	CDelegate<void(void)> d_OnMoveLeave;
	CDelegate<void(void)> d_OnMoveHover;
	virtual void SetTextColor(enumBSBtnState BtnState, COLORREF crTextColor);
	void SetColorInside(enumBSBtnState BtnState, COLORREF crBGColor);
	void SetColorBorder(enumBSBtnState BtnState, COLORREF crBGColor, int width = 2);

public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool m_bHasInsideColor;
	bool m_bHasBorderColor;
	int m_width;
	COLORREF m_crInsideColor[BS_END];
	COLORREF m_crBorderColor[BS_END];
};

#endif //BSBUTTON_H__