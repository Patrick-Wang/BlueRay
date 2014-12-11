#include "StdAfx.h"
#include "BSObject.h"


// CBSObject

IMPLEMENT_DYNAMIC(CBSObject, CWnd)

CBSObject::CBSObject()
    :m_CurBtnState(BS_NORMAL)
    ,m_bIsDown(FALSE)
    ,m_isHover(FALSE)
    ,m_uiTextAlign(DT_VCENTER | DT_SINGLELINE | DT_CENTER | DT_WORD_ELLIPSIS)
    ,m_bIsUseBGPicRect(FALSE)
    ,m_bIsUseTextRect(FALSE)
    ,m_isClickEnabled(FALSE)
    ,m_isFocusEnabled(FALSE)
    ,m_isHoverEnabled(FALSE)
    ,m_isHBackground(FALSE)
    ,m_isVBackground(FALSE)
    ,m_bIsEraseBG(FALSE)
	,m_hPaintDC(NULL)
	,m_bHasPaintDC(FALSE)
	,m_hBitmap(NULL)
	,m_iWidth(0)
	,m_iHeight(0)
    ,m_crBackgroundColor(RGB(0, 0, 0))
    ,m_bIsUseBGColor(FALSE)
    ,m_bIsSelectEnabled(FALSE)
    ,m_bIsSelect(FALSE)
    ,m_bIsEnable(TRUE)
    ,m_strCaption(_T(""))
    ,m_bLastState(TRUE)
{
    SecureZeroMemory(m_uiBGPictureIDs, BS_END * sizeof(UINT));
    SecureZeroMemory(m_crTextColor, BS_END * sizeof(UINT));
    SecureZeroMemory(m_crTextColor2, BS_END * sizeof(UINT));
    SecureZeroMemory(m_piPanelBG, BS_END * sizeof(Gdiplus::Image*));
    
    m_rtTextRect.left = 0;
    m_rtTextRect.right = 0;
    m_rtTextRect.top = 0;
    m_rtTextRect.bottom = 0;

    m_rtBGPicRect.left = 0;
    m_rtBGPicRect.right = 0;
    m_rtBGPicRect.top = 0;
    m_rtBGPicRect.bottom = 0;
}

CBSObject::~CBSObject()
{
    for (int iIndex = 0; iIndex < BS_END; iIndex++)
    {
        if (m_piPanelBG[iIndex] != NULL)
        {
            delete m_piPanelBG[iIndex];
            m_piPanelBG[iIndex] = NULL;
        }
    }
    m_cfFont.DeleteObject();
}

BEGIN_MESSAGE_MAP(CBSObject, CWnd)
    ON_WM_ERASEBKGND()
    ON_WM_LBUTTONUP()
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
    ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

// CBSObject message handlers

void CBSObject::SetText(UINT uiTextResID)
{
    CString strTemp;
    if (strTemp.LoadString(AfxGetResourceHandle(), uiTextResID))
    {
        SetWindowText(strTemp);
    }
    else
    {
        strTemp = _T("");
    }
}

void CBSObject::SetWindowText(UINT uiTextResID)
{
    SetText(uiTextResID);
}


CRect CBSObject::PaintDCRect(CRect& rect)
{
	CRect reRet(rect);
	if (m_bHasPaintDC)
	{
		//reset the text rect
		int iW = rect.right - rect.left;
		int iH = rect.bottom - rect.top;
		reRet.left += m_StartPaintPoint.x;
		reRet.top += m_StartPaintPoint.y;
		reRet.bottom = reRet.top + iH;
		reRet.right = reRet.left + iW;
	}

	return reRet;
}

void CBSObject::SetWindowText(LPCTSTR strCaption)
{
    if (strCaption != NULL)
    {
        m_strCaption = strCaption;
        if (IsWindow(this->GetSafeHwnd()))
        {
            PaintParent();
            Invalidate();
        }
    }
    else
    {
        m_strCaption.Empty();
    }
}

void CBSObject::CreateBSFont(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic, CFont* pFont)
{
    LOGFONT lf;
	lf.lfHeight = -fontSize/*-MulDiv(fontSize, GetDeviceCaps(pDC->GetSafeHdc(), LOGPIXELSY), 72)*/;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = bBold == TRUE ? 700 : FW_THIN;
	lf.lfItalic = bItalic;
	lf.lfUnderline =(BYTE)bUnderLine;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = PROOF_QUALITY;
	lf.lfPitchAndFamily = VARIABLE_PITCH;
	_tcsncpy_s(lf.lfFaceName, lfFaceName, LF_FACESIZE);
	pFont->CreateFontIndirect(&lf);
}

void CBSObject::SetBSFont(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    m_cfFont.DeleteObject();

	CBSObject::CreateBSFont(lfFaceName, fontSize, bUnderLine, bBold, bItalic, &m_cfFont);
    
    SetFont(&m_cfFont);

}

CFont* CBSObject::GetFontPtr(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    CFont* pFontTemp = NULL;

    pFontTemp = new CFont();

    CBSObject::CreateBSFont(lfFaceName, fontSize, bUnderLine, bBold, bItalic, pFontTemp);

    return pFontTemp;
}

void CBSObject::SetBSFont(UINT uiFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    CString strFaceName;
    if (strFaceName.LoadString(uiFaceName))
    {
	    CBSObject::SetBSFont(strFaceName, fontSize, bUnderLine, bBold, bItalic);
    }
}

CFont* CBSObject::GetFontPtr(UINT uiFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    CFont* pFontTemp = NULL;

    CString strFaceName;
    if (strFaceName.LoadString(uiFaceName))
    {
	    pFontTemp = GetFontPtr(strFaceName, fontSize, bUnderLine, bBold, bItalic);
    }

    return pFontTemp;
}

void CBSObject::GetWindowText(CString& strCaption)
{
    strCaption = m_strCaption;
}

BOOL CBSObject::DrawBitmap(HDC hDC, const RECT &rectDst, UINT uiRes, HINSTANCE hInst)
{
    Gdiplus::Graphics	graphics(hDC);

    Gdiplus::Bitmap bmp(hInst,(WCHAR *)MAKEINTRESOURCE(uiRes));

	graphics.DrawImage(&bmp,rectDst.left, rectDst.top);
	
	return TRUE;
}

BOOL CBSObject::DrawPNG(HDC hDC, const RECT &rectDst, UINT Res, HINSTANCE hInst)
{
    return DrawPNG(hDC, rectDst, NULL, Res, hInst); 
}

BOOL CBSObject::DrawPNG(HDC hDC, const RECT &rectDst, const RECT* prectImagePortion, UINT Res, HINSTANCE hInst)
{
	BOOL bRet = FALSE;

    Gdiplus::Graphics graphics(hDC);

	HRSRC  hResource = ::FindResource(hInst,  MAKEINTRESOURCE(Res),  TEXT("PNG"));  
	if  (hResource > 0)
    {
	    DWORD  imageSize = ::SizeofResource(hInst, hResource);  
	    if  (imageSize > 0)
        {
            HGLOBAL hHandle = ::LoadResource(hInst,hResource);
            if (NULL != hHandle)
            {
                void* pResourceData = ::LockResource(hHandle);

                if  (pResourceData != NULL)  
                {
                    HGLOBAL hBuffer;
                    hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, imageSize);  
                    if  (hBuffer)  
                    {  
                        void* pBuffer = ::GlobalLock(hBuffer);  
                        if  (pBuffer)  
                        {  
                            memcpy_s(pBuffer, imageSize, pResourceData, imageSize); //For stm0117
                            IStream*  pStream = NULL;  
                            if  (::CreateStreamOnHGlobal(hBuffer,  FALSE,  &pStream) == S_OK)  
                            {  
                                Gdiplus::Image cImage(pStream);
                                Gdiplus::RectF cRectF(static_cast<Gdiplus::REAL>(rectDst.left), 
                                    static_cast<Gdiplus::REAL>(rectDst.top), 
                                    static_cast<Gdiplus::REAL>(rectDst.right - rectDst.left), 
                                    static_cast<Gdiplus::REAL>(rectDst.bottom - rectDst.top));
                                Gdiplus::ImageAttributes clImgAtt;
								clImgAtt.SetWrapMode(Gdiplus::WrapModeTileFlipXY);
								if (NULL == prectImagePortion)
								{
									graphics.DrawImage(&cImage, 
                                        cRectF, 
                                        static_cast<Gdiplus::REAL>(0), 
                                        static_cast<Gdiplus::REAL>(0),
                                        static_cast<Gdiplus::REAL>(cImage.GetWidth()), 
                                        static_cast<Gdiplus::REAL>(cImage.GetHeight()),
										Gdiplus::UnitPixel, 
                                        &clImgAtt); //
								}
								else
                                {
									graphics.DrawImage(&cImage, 
                                        cRectF, 
                                        static_cast<Gdiplus::REAL>(prectImagePortion->left), 
										static_cast<Gdiplus::REAL>(prectImagePortion->top), 
										static_cast<Gdiplus::REAL>(prectImagePortion->right - prectImagePortion->left), 
										static_cast<Gdiplus::REAL>(prectImagePortion->bottom - prectImagePortion->top), 
										Gdiplus::Unit::UnitPixel, 
										NULL, 
										NULL, 
										NULL);
								}

                                pStream->Release();  
                                bRet = TRUE;
                            }  
                            ::GlobalUnlock(hBuffer);  
                        }  
                        ::GlobalFree(hBuffer);  
                        hBuffer  =  NULL;  
                    }
                }
            }
        }
    }

	return bRet;
}

BOOL CBSObject::DrawPNG(HDC hDC, const RECT &rectDst, Gdiplus::Image* pImage, const RECT* prectImagePortion /*= NULL*/)
{
	BOOL bRet = FALSE;

    if (pImage > 0)
    {
        Gdiplus::Graphics graphics(hDC);

        Gdiplus::RectF cRectF(static_cast<Gdiplus::REAL>(rectDst.left), 
            static_cast<Gdiplus::REAL>(rectDst.top), 
            static_cast<Gdiplus::REAL>(rectDst.right - rectDst.left), 
            static_cast<Gdiplus::REAL>(rectDst.bottom - rectDst.top));
								
	    Gdiplus::ImageAttributes clImgAtt;
	    clImgAtt.SetWrapMode(Gdiplus::WrapModeTileFlipXY);

        if (NULL == prectImagePortion)
		{
			graphics.DrawImage(pImage, 
                cRectF, 
                static_cast<Gdiplus::REAL>(0), 
                static_cast<Gdiplus::REAL>(0),
                static_cast<Gdiplus::REAL>(pImage->GetWidth()), 
                static_cast<Gdiplus::REAL>(pImage->GetHeight()),
				Gdiplus::UnitPixel, 
                &clImgAtt); //
		}
		else
        {
			graphics.DrawImage(pImage, 
                cRectF, 
                static_cast<Gdiplus::REAL>(prectImagePortion->left), 
				static_cast<Gdiplus::REAL>(prectImagePortion->top), 
				static_cast<Gdiplus::REAL>(prectImagePortion->right - prectImagePortion->left), 
				static_cast<Gdiplus::REAL>(prectImagePortion->bottom - prectImagePortion->top), 
				Gdiplus::Unit::UnitPixel, 
				NULL, //&clImgAtt
				NULL, 
				NULL);
		}

        bRet = TRUE;
    }

	return bRet;
}

Gdiplus::Image* CBSObject::LoadImage(UINT Res, HINSTANCE hInst)
{
	BOOL bRet = FALSE;
    Gdiplus::Image* pImage = NULL;

	HRSRC  hResource = ::FindResource(hInst,  MAKEINTRESOURCE(Res),  TEXT("PNG"));  
	if  (hResource > 0)
    {
	    DWORD  imageSize = ::SizeofResource(hInst, hResource);  
	    if  (imageSize > 0)
        {
            HGLOBAL hHandle = ::LoadResource(hInst,hResource);
            if (NULL != hHandle)
            {
                void* pResourceData = ::LockResource(hHandle);

                if  (pResourceData != NULL)  
                {
                    HGLOBAL hBuffer;
                    hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, imageSize);  
                    if  (hBuffer)  
                    {  
                        void* pBuffer = ::GlobalLock(hBuffer);  
                        if  (pBuffer)  
                        {  
                            memcpy_s(pBuffer, imageSize, pResourceData, imageSize); 
                            IStream*  pStream = NULL;  
                            if  (::CreateStreamOnHGlobal(hBuffer,  FALSE,  &pStream) == S_OK)  
                            {  
                                pImage = new Gdiplus::Image(pStream);
                                
                                pStream->Release();  
                                bRet = TRUE;
                            }  
                            ::GlobalUnlock(hBuffer);  
                        }  
                        ::GlobalFree(hBuffer);  
                        hBuffer  =  NULL;  
                    }
                }
            }
        }
    }

	return pImage;
}

Gdiplus::Image* CBSObject::LoadImage(LPCTSTR strImagePath, HINSTANCE hInst)
{   
    Gdiplus::Image* pImage = NULL;

    if (strImagePath != NULL)
    {        
        CFileStatus status;

	    if (CFile::GetStatus(strImagePath, status))
        {
            pImage = new Gdiplus::Image(strImagePath);
        }   
    }

	return pImage;
}


BOOL CBSObject::FillRect(HDC hDC, const RECT& rectDst, COLORREF crBGColor)
{
    BOOL bRet = FALSE;

    HBRUSH hbrush = ::CreateSolidBrush(crBGColor);
    if (hbrush)
    {
        ::FillRect(hDC, &rectDst, hbrush);
        ::DeleteObject(hbrush);
        bRet = TRUE;
    }

    return bRet;
}

BOOL CBSObject::DrawText(HDC hDC, const LPRECT lpRect, const CString& strText, 
							  HFONT hFont, COLORREF clrText, UINT uiFormat)
{
	BOOL bResult = FALSE;

#ifdef OSK 
	HFONT hFontOld = (HFONT)::SelectObject(hDC, hFont);
	COLORREF clrTextOld = ::SetTextColor(hDC, clrText);
	int nBkModeOld = ::SetBkMode(hDC, TRANSPARENT);

    if (::DrawText(hDC, strText, strText.GetLength(), lpRect, uiFormat))
	{
		bResult = TRUE;
	}

	if (hFontOld)
	{
		::SelectObject(hDC, hFontOld);
	}
	::SetTextColor(hDC, clrTextOld);
	::SetBkMode(hDC, nBkModeOld);
#else   
    Gdiplus::Graphics graphics(hDC);
    
    Gdiplus::SolidBrush brush(Gdiplus::Color(255, GetRValue(clrText), GetGValue(clrText), GetBValue(clrText)));
    Gdiplus::Font font(hDC, hFont);
    Gdiplus::RectF  rect(lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top);

	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	graphics.SetTextRenderingHint(Gdiplus::TextRenderingHintClearTypeGridFit);
         
    Gdiplus::StringFormat strformat;
    if (uiFormat & DT_TOP)
    {
        strformat.SetLineAlignment(Gdiplus::StringAlignmentNear);
    }

    if (uiFormat & DT_VCENTER)
    {
        strformat.SetLineAlignment(Gdiplus::StringAlignmentCenter);
    }

    if (uiFormat & DT_BOTTOM)
    {
        strformat.SetLineAlignment(Gdiplus::StringAlignmentFar);
    }

    if (uiFormat & DT_LEFT)
    {
        strformat.SetAlignment(Gdiplus::StringAlignmentNear);
    }

    if (uiFormat & DT_CENTER)
    {
        strformat.SetAlignment(Gdiplus::StringAlignmentCenter);
    }

    if (uiFormat & DT_RIGHT)
    {
        strformat.SetAlignment(Gdiplus::StringAlignmentFar);
    }

    if ((uiFormat & DT_WORDBREAK) == 0)
    {
        strformat.SetFormatFlags(Gdiplus::StringFormatFlagsNoWrap);
    }

    if (uiFormat & DT_SINGLELINE)
    {

    }

    if (uiFormat & DT_WORD_ELLIPSIS)
    {
        strformat.SetTrimming(Gdiplus::StringTrimmingEllipsisCharacter);
    }

    if (uiFormat & DT_NOCLIP)
    {
        strformat.SetFormatFlags(Gdiplus::StringFormatFlagsNoClip);
    }

    graphics.DrawString(strText, -1, &font, rect, &strformat, &brush);


#endif
	return bResult;
}

BOOL CBSObject::DrawPNG(HDC hDC, const RECT &rectDst, LPCTSTR strImagePath, HINSTANCE hInst)
{
    BOOL bRet = FALSE;

    if (strImagePath == NULL)
    {
        return bRet;
    }

    Gdiplus::Graphics graphics(hDC);

    CFileStatus status;

	if (CFile::GetStatus(strImagePath, status))
    {
        Gdiplus::Image cImage(strImagePath);
        Gdiplus::RectF cRectF(static_cast<Gdiplus::REAL>(rectDst.left), 
            static_cast<Gdiplus::REAL>(rectDst.top), 
            static_cast<Gdiplus::REAL>(rectDst.right - rectDst.left), 
            static_cast<Gdiplus::REAL>(rectDst.bottom - rectDst.top));
        
        graphics.DrawImage(&cImage, cRectF);
        bRet = TRUE;

    }     

    return bRet;
}

void CBSObject::PreSubclassWindow()
{

    CWnd::PreSubclassWindow();
}


BOOL CBSObject::OnEraseBkgnd(CDC* pDC)
{
    BOOL bRet = TRUE;

    RECT rt;
    GetWindowRect(&rt);
    ScreenToClient(&rt);

    HDC hDC = NULL;
    
	if (m_bHasPaintDC)
	{
		hDC = m_hPaintDC;
	} 
    else
    {
        hDC = pDC->GetSafeHdc();
    }

    if (m_bIsUseBGColor)
    {
        FillRect(hDC, PAINTDC(rt), m_crBackgroundColor);
    }

    int iState = GetState();

    if (m_bIsEnable && (FALSE == m_bLastState))
    {
        OnMouseLeave();
        m_bLastState = TRUE;
    }

    if (m_piPanelBG[iState] == NULL)
    {        
        if (!m_bIsUseBGPicRect)
        {   
            if (m_uiBGPictureIDs[iState] != 0)
            {
                m_piPanelBG[iState] = LoadImage(m_uiBGPictureIDs[iState], AfxGetInstanceHandle());
            }
			else if (!m_csGBPicture[iState].IsEmpty())
			{
				m_piPanelBG[iState] = LoadImage(m_csGBPicture[iState], AfxGetInstanceHandle());
			}
            else
            {
                m_piPanelBG[iState] = LoadImage(m_uiBGPictureIDs[BS_NORMAL], AfxGetInstanceHandle());
            }
        }
        else
        {
            if (m_uiBGPictureIDs[iState] != 0)
            {
                m_piPanelBG[iState] = LoadImage(m_uiBGPictureIDs[iState], AfxGetInstanceHandle());
            }
			else if (!m_csGBPicture[iState].IsEmpty())
			{
				m_piPanelBG[iState] = LoadImage(m_csGBPicture[iState], AfxGetInstanceHandle());
            }
            else
            {
                m_piPanelBG[iState] = LoadImage(m_uiBGPictureIDs[BS_NORMAL], AfxGetInstanceHandle());
            }
        }    
    }

    if (m_piPanelBG[iState] != NULL)
    {
        if (!m_bIsUseBGPicRect)
        {
            DrawPNG(hDC, PAINTDC(rt), m_piPanelBG[iState]);
        }
        else
        {
            DrawPNG(hDC, PAINTDC(m_rtBGPicRect), m_piPanelBG[iState]);
        }
    }
    
    return bRet;
}

void CBSObject::SetTextAlign(UINT uiAlign)
{
    m_uiTextAlign = uiAlign;
    if (IsWindow(this->GetSafeHwnd()))
    {
        PaintParent();
        Invalidate();
    }
}

void CBSObject::SetBGPicRect(int x, int y, int cx, int cy)
{
    m_rtBGPicRect.left = x;
    m_rtBGPicRect.top = y;
    m_rtBGPicRect.right = x + cx;
    m_rtBGPicRect.bottom = y + cy;
    m_bIsUseBGPicRect = TRUE;
}


void CBSObject::SetTextRect(int x, int y, int cx, int cy)
{
    m_rtTextRect.left = x;
    m_rtTextRect.top = y;
    m_rtTextRect.right = x + cx;
    m_rtTextRect.bottom = y + cy;
    m_bIsUseTextRect = TRUE;
}


void CBSObject::SetTextColor(COLORREF crTextColor)
{
    m_crTextColor[BS_NORMAL] = crTextColor;
}


void CBSObject::SetTextColor2(COLORREF crTextColor)
{
    m_crTextColor2[BS_NORMAL] = crTextColor;
}


void CBSObject::SetBGPictureIDs(enumBSBtnState btnState, UINT uiBKPictureID)
{
    switch (btnState)
    {
    case BS_NORMAL:
        break;
    case BS_CLICK:
        m_isClickEnabled = uiBKPictureID > 0;
        break;
    case BS_HOVER:
        m_isHoverEnabled = uiBKPictureID > 0;
        break;
    case BS_FOCUS:
        m_isHoverEnabled = uiBKPictureID > 0;
        break;
    case BS_DISABLE:
        break;
    default:
        break;
    }

    if (btnState != BS_END)
    {
        if (m_piPanelBG[btnState] != NULL)
        {
            delete m_piPanelBG[BS_NORMAL];
            m_piPanelBG[btnState] = NULL;
        }
        m_uiBGPictureIDs[btnState] = uiBKPictureID;
    }
 
    if (IsWindow(this->GetSafeHwnd()) && GetState() != btnState)
    {
        PaintParent();
        Invalidate();
    }
}

void CBSObject::SetTextColor(enumBSBtnState BtnState, COLORREF crTextColor)
{
    m_crTextColor[BtnState] = crTextColor;
}


void CBSObject::SetTextColor2(enumBSBtnState BtnState, COLORREF crTextColor)
{
    m_crTextColor2[BtnState] = crTextColor;
}

void CBSObject::OnMouseLeave()
{
    if (!m_bIsEnable)
    {
        return;
    }

    BOOL bIsRepaint = FALSE;
    if (m_isHover && !m_bIsSelect)
    {
        m_isHover = FALSE;
        if (m_isHoverEnabled)
        {
            bIsRepaint = TRUE;
        }
    }

    if (m_bIsDown)
    {
        m_bIsDown = FALSE;
        if (m_isClickEnabled)
        {
            bIsRepaint = TRUE;
        }
    }

    if (bIsRepaint)
    {
        PaintParent();        
        Invalidate();
    }
    
}

void CBSObject::SetPaintDC(HDC hPaintDC, int ix, int iy, int iCx, int iCy)
{
	m_hPaintDC = hPaintDC;
	m_StartPaintPoint = CPoint(ix, iy);
	m_iWidth = iCx;
	m_iHeight = iCy;
}

void CBSObject::RePaintDC(RECT rect, BOOL bRShow)
{
}

void CBSObject::EnablePaintDC(BOOL bEnable)
{
	m_bHasPaintDC = bEnable;
}

enumBSBtnState CBSObject::GetState()
{
    enumBSBtnState btnState = BS_NORMAL;
    if (!m_bIsEnable)
	{
		btnState = BS_DISABLE;
	}
    else if (m_isClickEnabled && m_bIsDown)
	{
		btnState = BS_CLICK;
	}
	else
	{
		if (m_isHoverEnabled && m_isHover)
        {
			btnState = BS_HOVER;
		}
	}

    return btnState;
}

void CBSObject::SetBKPictureHIDs(UINT uiLeftPicID, UINT uiMidPicID, UINT uiRightPicID)
{
	m_uiBKPicHIDs[BPH_LEFT] = uiLeftPicID;
	m_uiBKPicHIDs[BPH_MID] = uiMidPicID;
	m_uiBKPicHIDs[BPH_RIGHT] = uiRightPicID;
	m_isHBackground = TRUE;
}

void CBSObject::SetBKPictureVIDs(UINT uiTopPicID, UINT uiMidPicID, UINT uiBottomPicID)
{
    m_uiBKPicVIDs[BPV_TOP] = uiTopPicID;
    m_uiBKPicVIDs[BPV_MID] = uiMidPicID;
    m_uiBKPicVIDs[BPV_BOTTOM] = uiBottomPicID;
    m_isVBackground = TRUE;
}

void CBSObject::SetBGPictureID(UINT uiBGPictureID)
{
    if (m_piPanelBG[BS_NORMAL] != NULL)
    {
        delete m_piPanelBG[BS_NORMAL];
        m_piPanelBG[BS_NORMAL] = NULL;
    }
    m_uiBGPictureIDs[BS_NORMAL] = uiBGPictureID;
    if (IsWindow(this->GetSafeHwnd()))
    {
        PaintParent();
        Invalidate();
    }
}

void CBSObject::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (!m_bIsEnable)
    {
        return;
    }
    if (m_isClickEnabled)
    {
        CRect rt;
        GetWindowRect(&rt);
        ScreenToClient(&rt);

        if (rt.PtInRect(point))
        {
            if (m_bIsSelectEnabled && !m_bIsSelect)
            {
                m_bIsSelect = TRUE;
                m_isHover = TRUE;
            }
            else if (m_bIsSelectEnabled && m_bIsSelect)
            {
                m_bIsSelect = FALSE;
            }
        }
        
        m_bIsDown = FALSE;
        PaintParent();
        Invalidate();
        
    }
    else
    {

    }

    CWnd::OnLButtonUp(nFlags, point);
}


void CBSObject::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (!m_bIsEnable)
    {
        return;
    }
    if (m_isClickEnabled)
    {
        m_bIsDown = TRUE;
        PaintParent();
        Invalidate();
    }


    CWnd::OnLButtonDown(nFlags, point);
}


void CBSObject::OnMouseMove(UINT nFlags, CPoint point)
{
    if (!m_bIsEnable)
    {
       
        return;
    }
    if (!m_bIsSelect )
	{
       
		if (!m_isHover)
		{			

          
			m_isHover = TRUE;

            if (m_isHoverEnabled)
            {
                
                PaintParent();
			    Invalidate();
            }
		}
	}

    if (!m_bIsSelect && m_isHover && GetCapture() != this)
    {

        TRACKMOUSEEVENT TrackMouseEvent;
		TrackMouseEvent.cbSize = sizeof (TRACKMOUSEEVENT);
		TrackMouseEvent.dwFlags = TME_LEAVE;
		TrackMouseEvent.hwndTrack = GetSafeHwnd();
		TrackMouseEvent.dwHoverTime = 0;
		_TrackMouseEvent(&TrackMouseEvent);

    }
    else if (!m_bIsSelect && m_isHover)
    {
        CRect rt;
        GetWindowRect(&rt);
        ScreenToClient(&rt);

        if (!rt.PtInRect(point))
        {
            TRACKMOUSEEVENT TrackMouseEvent;
		    TrackMouseEvent.cbSize = sizeof (TRACKMOUSEEVENT);
		    TrackMouseEvent.dwFlags = TME_LEAVE;
		    TrackMouseEvent.hwndTrack = GetSafeHwnd();
		    TrackMouseEvent.dwHoverTime = 0;
		    _TrackMouseEvent(&TrackMouseEvent);
        }
        
    }

    CWnd::OnMouseMove(nFlags, point);
}

void CBSObject::PaintParent()
{
    CRect   rect;
    GetWindowRect(&rect); 
    GetParent()->ScreenToClient(&rect); 
    GetParent()->InvalidateRect(&rect);
}

void CBSObject::PaintGrandpa()
{
    CRect   rect;
    GetWindowRect(&rect);
    GetParent()->GetParent()->ScreenToClient(&rect); 
    GetParent()->GetParent()->InvalidateRect(&rect);
}


void CBSObject::EnableEraseBackground(BOOL bIsErase /*= TRUE*/)
{
   m_bIsEraseBG = bIsErase;
}

CFont* CBSObject::GetFont()
{
   return &m_cfFont;
}

void CBSObject::SetBackgroundColor(COLORREF crBGColor)
{
    m_crBackgroundColor = crBGColor;
    m_bIsUseBGColor = TRUE;
    if (IsWindow(this->GetSafeHwnd()))
    {
        PaintParent();
        Invalidate();
    }
}


void CBSObject::EnableWindow(BOOL bIsEnable)
{
    if (m_bIsEnable != bIsEnable)
    {
         //add by Tsubasa 2011/7/14
         m_bLastState = m_bIsEnable; 

         m_bIsEnable = bIsEnable;
        ::EnableWindow(this->GetSafeHwnd(), bIsEnable);
         PaintParent();
         Invalidate();
    }
}

void CBSObject::EnableSelect(BOOL bIsEnable)
{
    m_bIsSelectEnabled = bIsEnable;
}

void CBSObject::UnselectWindow()
{
    if (m_bIsSelectEnabled)
    {
        m_bIsSelect = FALSE;
        m_isHover = FALSE;
        if (IsWindow(this->GetSafeHwnd()))
        {
            PaintParent();
            Invalidate();
        }
    }
}

BOOL CBSObject::IsWindowEnable()
{
    return m_bIsEnable;
}

BOOL CBSObject::IsMouseHover()
{
    return m_isHover;
}

BOOL CBSObject::PreTranslateMessage(MSG* pMsg)    
{   
    BOOL bRet = FALSE;

	if (WM_KEYDOWN == pMsg->message)     
	{
		if (VK_RETURN == pMsg->wParam || VK_ESCAPE == pMsg->wParam)     
		{
			bRet = TRUE;
		}
	}

    if (!bRet)
    {
        bRet = CWnd::PreTranslateMessage(pMsg);
    }
    
	return bRet;
}

void CBSObject::SetBGPicturePath( enumBSBtnState BtnState, CString csBKPicturePath )
{   
	switch (BtnState)
	{
	case BS_NORMAL:
		break;
	case BS_CLICK:
		m_isClickEnabled = csBKPicturePath.IsEmpty();//uiBKPictureID > 0;
		break;
	case BS_HOVER:
		m_isHoverEnabled = csBKPicturePath.IsEmpty();//uiBKPictureID > 0;
		break;
	case BS_FOCUS:
		m_isHoverEnabled = csBKPicturePath.IsEmpty();//uiBKPictureID > 0;
		break;
	case BS_DISABLE:
		break;
	default:
		break;
	}

	if (BtnState != BS_END)
	{
		if (m_piPanelBG[BtnState] != NULL)
		{
			delete m_piPanelBG[BS_NORMAL];
			m_piPanelBG[BtnState] = NULL;
		}
		m_csGBPicture[BtnState] = csBKPicturePath;
	}

	if (IsWindow(this->GetSafeHwnd()) && GetState() != BtnState)
	{
		PaintParent();
		Invalidate();
	}


}

BOOL CBSObject::DrawRect(HDC hDC, const RECT& rectDst, COLORREF crBGColor, int bold)
{
	BOOL bRet = FALSE;

	HPEN hPen = ::CreatePen(PS_SOLID, bold, crBGColor);
	
	if (hPen)
	{
		HGDIOBJ hold = ::SelectObject(hDC, hPen);
		::MoveToEx(hDC, rectDst.left, rectDst.top, NULL);
		::LineTo(hDC, rectDst.right, rectDst.top);
		::LineTo(hDC, rectDst.right, rectDst.bottom);
		::LineTo(hDC, rectDst.left, rectDst.bottom);
		::LineTo(hDC, rectDst.left, rectDst.top - 1);
		::SelectObject(hDC, hold);
		::DeleteObject(hPen);
		bRet = TRUE;
	}

	return bRet;
}


BOOL CBSObject::DrawLine(HDC hDC, const POINT& ptStart, const POINT& ptEnd, COLORREF crBGColor, int bold /*= 1*/)
{
	BOOL bRet = FALSE;

	HPEN hPen = ::CreatePen(PS_SOLID, bold, crBGColor);

	if (hPen)
	{
		HGDIOBJ hold = ::SelectObject(hDC, hPen);
		::MoveToEx(hDC, ptStart.x, ptStart.y, NULL);
		::LineTo(hDC, ptEnd.x, ptEnd.y);
		::SelectObject(hDC, hold);
		::DeleteObject(hPen);
		bRet = TRUE;
	}

	return bRet;
}

