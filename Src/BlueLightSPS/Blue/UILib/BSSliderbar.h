#ifndef BSSLIDERBAR_H__
#define BSSLIDERBAR_H__
#include "bsobject.h"
#include <GdiPlus.h>
#include "Delegate.h"
//#include "BSButton.h"

#define WM_SLIDER_DRAG	WM_APP + 12323

class CBSSliderbar : public CBSObject
{
public:
	CBSSliderbar(void);
	~CBSSliderbar(void);
	//void NewBKGround(CDC* pBGdc = NULL);
	void SetBarPicIDs(UINT uiCoverPicID, UINT uiUncoverPicID);
	void SetSliderPicIDs(enumBSBtnState SliderState, UINT uiPicID);
	void SetBarSize(UINT uiWidth, UINT uiHeight);
	void SetScrolRange(UINT uiWidth);
	void SetSliderOffset(int iX, int iY);
	void SetSliderSize(UINT uiWidth, UINT uiHeight);
	virtual BOOL Create(CWnd* pParentWnd, UINT nID);
	void SetPos(UINT uiPos);
	UINT GetPos(void);
	void SetRange(UINT uiRange);

	//void OnDestroy();
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnPaint();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnPosChange(UINT uiOldPos, UINT uiNewPos);
	void PosToLocation( UINT uiPos );
	UINT PointToPos(CPoint& pt);
	FLOAT GetStepLength(void);
private:
	UINT m_uiSliderPicIDs[BS_END];
	UINT m_uiBarPicIDs[SBS_END];
	UINT m_uiRange;
	Gdiplus::RectF	m_rcSlider;
	Gdiplus::RectF	m_rcBar;
	Gdiplus::RectF	m_rcScrol;
// 	CDC* m_pDC;
// 	CBitmap* m_pBmp;
};

#endif //BSSLIDERBAR_H__