/*+===================================================================
  File:         BSSeparator.h

  Summary:      Custom button control

  Author:       w_x 2011.06.19

  Classes:      CBSSeparator

  Functions:    None

  Origin:       BlackSkin
----------------------------------------------------------------------
===================================================================+*/

#ifndef BSSEPARATOR_H__
#define BSSEPARATOR_H__

#include "bsobject.h"

class CBSSeparator :
    public CBSObject
{
public:
	CBSSeparator(void);
	~CBSSeparator(void);
	BOOL Create(CWnd* pParentWnd, UINT nID);
	void RePaintDC(RECT rect, BOOL bRShow = TRUE);
	void SetSeparatorBKPic(UINT uiSeparatorBKID);

public:
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();

public:
	UINT m_uiSeparatorBKID;
};

#endif //BSSEPARATOR_H__