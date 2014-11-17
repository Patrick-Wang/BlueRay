#ifndef BSSCROLLBAR_H__
#define BSSCROLLBAR_H__

enum tagBSScrollBarEnum
{
	SRB_BACK = 0,
	SRB_BODY,
	SRB_END
};

typedef enum tagOrientationEnum
{
	SB_VER = 0,
	SB_HOR
}OrientationEnum;

// CBSScrollbar
#include "BSObject.h"

class CBSScrollbar : public CBSObject
{
	DECLARE_DYNAMIC(CBSScrollbar)

public:
	CBSScrollbar();
	virtual ~CBSScrollbar();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
public:
	void RePaintDC(RECT rect, BOOL bRShow = TRUE);
    void SetSBPictureIDs(UINT uiBackID, UINT uiBodyID);
    void SetBarPos(int iPos);
    void SetBarLengths(int iMaxLen, int iVisableLen);
	virtual BOOL Create(CWnd* pParentWnd, UINT nID);
	void SetBodyWidth(UINT nWidth);
	void SetBodyHeight(UINT nHeight);
	void SetOrientation(OrientationEnum orientation)
	{
		m_Orientation = orientation;
	}

private:
	Gdiplus::Image *m_pScrollBarImgs[SRB_END];
    int m_iMaxLen;
    int m_iVisibleLen;
    int m_iCurPos;
	int m_iBodyWidth;
	int m_iBodyHeight;
	OrientationEnum m_Orientation;
};

#endif //BSSCROLLBAR_H__
