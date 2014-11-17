#ifndef BSOBJECT_H__
#define BSOBJECT_H__

#define PAINTDC(a) PaintDCRect(CRect(a))

enum enumBSCheckBoxState
{
    CBS_UNCHECK = 0,
    CBS_CHECKED,
    CBS_END
};

enum enumBSBtnState
{
    BS_NORMAL = 0,
    BS_HOVER,
    BS_CLICK,
    BS_FOCUS,
    BS_DISABLE,
    BS_END
};

enum enumBSBKHPos
{
    BPH_LEFT = 0,
    BPH_MID,
    BPH_RIGHT,
    BPH_END
};

enum enumBSBKHPosEx
{
    BPHX_LEFT = 0,
    BPHX_LEFTMID,
    BPHX_MID,
    BPHX_RIGHTMID,
    BPHX_RIGHT,
    BPHX_END
};

enum enumBSBKVPos
{
    BPV_TOP = 0,
    BPV_MID,
    BPV_BOTTOM,
    BPV_END
};

enum enumBSScrollBar
{
    SB_BEGINARROW = 0,
    SB_BODY,
    SB_ENDARROW,
    SB_END
};

enum enumBSSliderBar
{
    SBS_COVER = 0,
    SBS_UNCOVER,
    SBS_END
};

enum enumMenuPanel
{
    MP_MAINMENU = 0,
    MP_SUBMENU,
    MP_END
};

enum enumMenuButton
{
    MB_PUSH = 0,
    MB_SLIDER,
    MB_SINGLECHECK,
    MB_END
};

enum enumWebState
{
    WS_LOADING = 0,
    WS_ONLINE,
    WS_OFFLINE,
    WS_ANIMATION,
    WS_EDIT,
    WS_END
};

// CBSObject
const UINT UIMsgPanelItemClicked = ::RegisterWindowMessage(_T("PanelItemClicked"));
enum enumMenuItemClick
{
	MIC_MID,
    MIC_LEFT,
    MIC_RIGHT,
    MIC_END
};

enum enumWebItemClick
{
    WIC_FACE,
    WIC_CLOSE,
    WIC_END
};
enum enumWebItemClickButton
{
    WICB_UP,
    WICB_DOWN,
	WICB_MOVE,
    WICB_END
};
enum enumListItemClick
{
    LIC_ITEM,
    LIC_END
};



class CBSObject : public CWnd
{
	DECLARE_DYNAMIC(CBSObject)

public:
	CBSObject();
	virtual ~CBSObject();
 
protected:
	DECLARE_MESSAGE_MAP()
public:
    void SetWindowText(LPCTSTR strCaption);
    void GetWindowText(CString& strCaption);
    void PaintParent();
    void SetWindowText(UINT uiTextResID);
    void SetText(UINT uiTextResID);
    BOOL DrawBitmap(HDC hDC, const RECT &rectDst, UINT uiRes, HINSTANCE hInst);
    static BOOL DrawPNG(HDC hDC, const RECT &rectDst, UINT Res, HINSTANCE hInst);
    static BOOL DrawPNG(HDC hDC, const RECT &rectDst, LPCTSTR strImagePath, HINSTANCE hInst);
    static BOOL DrawPNG(HDC hDC, const RECT &rectDst, const RECT* prectImagePortion, UINT Res, HINSTANCE hInst);
    static BOOL DrawPNG(HDC hDC, const RECT &rectDst, Gdiplus::Image* pImage, const RECT* prectImagePortion = NULL);
    static BOOL FillRect(HDC hDC, const RECT& rectDst, COLORREF crBGColor);
	static BOOL DrawRect(HDC hDC, const RECT& rectDst, COLORREF crBGColor, int bold = 1);
	static BOOL DrawLine(HDC hDC, const POINT& ptStart, const POINT& ptEnd, COLORREF crBGColor, int bold = 1);
    static BOOL DrawText(HDC hDC, const LPRECT lpRect, const CString& strText, HFONT hFont, COLORREF clrText, UINT uiFormat);
    static Gdiplus::Image* CBSObject::LoadImage(UINT Res, HINSTANCE hInst);
    static Gdiplus::Image* CBSObject::LoadImage(LPCTSTR strImagePath, HINSTANCE hInst);
    void SetBGPicRect(int x, int y, int cx, int cy);
    void SetTextRect(int x, int y, int cx, int cy);
    void SetTextAlign(UINT uiAlign);
    void SetTextColor(COLORREF crTextColor);
    void SetBGPictureIDs(enumBSBtnState BtnState, UINT uiBKPictureID);
	void SetBGPicturePath(enumBSBtnState BtnState, CString csBKPicturePath);//wsh add
    void SetBGPictureID(UINT uiBGPictureID);
    virtual void SetTextColor(enumBSBtnState BtnState, COLORREF crTextColor);
    enumBSBtnState GetState();
    void SetBKPictureHIDs(UINT uiLeftPicID, UINT uiMidPicID, UINT uiRightPicID);
	void SetBKPictureVIDs(UINT uiTopPicID, UINT uiMidPicID, UINT uiBottomPicID);
    void EnableEraseBackground(BOOL bIsErase = TRUE);
    virtual void PreSubclassWindow();
    void SetBSFont(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
    static CFont* GetFontPtr(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
    void SetBSFont(UINT uiFaceName, int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
    static CFont* GetFontPtr(UINT uiFaceName, int fontSize, BOOL bUnderLine = FALSE, BOOL bBold = FALSE, BOOL bItalic = FALSE);
   
    CFont* GetFont();
    void SetBackgroundColor(COLORREF crBGColor);

    void PaintGrandpa();
	virtual void SetPaintDC(HDC hPaintDC, int ix, int iy, int iCx, int iCy);
	virtual void RePaintDC(RECT rect, BOOL bRShow = FALSE);
	virtual void EnablePaintDC(BOOL bEnable);
	CRect PaintDCRect(CRect& rect);
    void EnableWindow(BOOL bIsEnable);
    void EnableSelect(BOOL bIsEnable);
    void UnselectWindow();
    BOOL IsWindowEnable();
    BOOL IsMouseHover();
    void SetTextColor2(COLORREF crTextColor);
    void SetTextColor2(enumBSBtnState BtnState, COLORREF crTextColor);
protected:
    Gdiplus::Image*  m_piPanelBG[BS_END];
    CFont m_cfFont;
    BOOL m_bIsUseBGPicRect;
    RECT m_rtBGPicRect;
    BOOL m_bIsUseTextRect;
    RECT m_rtTextRect;
    UINT m_uiTextAlign;
    BOOL m_isClickEnabled;
    BOOL m_isFocusEnabled;
    BOOL m_isHoverEnabled;
    BOOL m_isHover;
    UINT m_uiBGPictureIDs[BS_END];
	CString m_csGBPicture[BS_END];//wsh add
    COLORREF m_crTextColor[BS_END];
    COLORREF m_crTextColor2[BS_END];
    enumBSBtnState m_CurBtnState;
    BOOL m_isHBackground;
    BOOL m_isVBackground;
    UINT m_uiBKPicHIDs[BPH_END];
    UINT m_uiBKPicVIDs[BPV_END];
    CString m_strCaption;
    BOOL m_bIsDown;
    BOOL m_bIsEraseBG;
    COLORREF m_crBackgroundColor;
    BOOL m_bIsUseBGColor;
    BOOL m_bIsSelectEnabled;
    BOOL m_bIsSelect;
	HDC m_hPaintDC;
	CPoint m_StartPaintPoint;
	int m_iWidth;
	int m_iHeight;
	BOOL m_bHasPaintDC;
	HBITMAP m_hBitmap;
    BOOL m_bIsEnable;
public:
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    //afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
    static void CreateBSFont(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic, CFont* pFont);
    BOOL m_bLastState;
};

#endif //BSOBJECT_H__
