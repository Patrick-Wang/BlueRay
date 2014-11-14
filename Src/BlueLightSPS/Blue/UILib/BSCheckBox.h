/*+===================================================================
  File:         BSCheckBox.h

  Summary:      Custom checkbox control

  Author:       zhang.xu 2011.06.01

  Classes:      CBSCheckBox

  Functions:    None

  Origin:       BlackSkin
----------------------------------------------------------------------
===================================================================+*/

#ifndef BSCHECKBOX_H__
#define BSCHECKBOX_H__

#include "bsobject.h"

class CBSCheckBox :
    public CBSObject
{
public:
    CBSCheckBox(void);
    ~CBSCheckBox(void);

protected:
	DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
	//yuhq
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

public:
    BOOL Create(CWnd* pParentWnd, UINT nID);
    void SetCheckedPic(UINT uiCheckBoxPicID);
    void SetCheck(enumBSCheckBoxState iCheckState);
    enumBSCheckBoxState GetCheck(void);
private:
    enumBSCheckBoxState m_CheckBoxState;
    Gdiplus::Image* m_piCheckImage;
};

#endif //BSCHECKBOX_H__
