#ifndef BSSTATIC_H__
#define BSSTATIC_H__

#include "bsobject.h"
class CBSStatic :
    public CBSObject
{
public:
    CBSStatic(void);
    ~CBSStatic(void);
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnPaint();
    BOOL Create(CWnd* pParentWnd, UINT nID);
};

#endif //BSSTATIC_H__