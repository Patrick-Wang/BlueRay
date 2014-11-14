/*+===================================================================
  File:         BSObject.cpp

  Summary:      Base class for all BlackSkin objects

  Author:       zhang.xu 2011.06.02

  Classes:      CBSObject

  Functions:    None

  Origin:       BlackSkin
----------------------------------------------------------------------
===================================================================+*/

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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    SetText

  Summary:     Set the text of control.

  Author:      zhang.xu 2011-06-02

  Args:        [in] UNIT uiTextResID
                Resource ID of text.

  Returns:     void
-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    SetWindowText

  Summary:     Set the text of control.

  Author:      zhang.xu 2011-06-19

  Args:        [in] UNIT uiTextResID
                Resource ID of text.

  Returns:     void
-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetWindowText
                
  Summary:      Set window text

  Author:       zhang.xu 2011.06.15

  Args:         LPCTSTR strCaption

  Returns:      None

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBSFont
                
  Summary:      Set font

  Author:       zhang.xu 2011.06.15

  Args:         LPCTSTR lfFaceName
                
                int fontSize
                
                BOOL bUnderLine
                
                BOOL bBold
                
                BOOL bItalic

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::SetBSFont(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    m_cfFont.DeleteObject();

	CBSObject::CreateBSFont(lfFaceName, fontSize, bUnderLine, bBold, bItalic, &m_cfFont);
    
    SetFont(&m_cfFont);

}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetFontPtr
                
  Summary:      Get font pointer

  Author:       zhang.xu 2011.06.15

  Args:         HDC hdc
                
                LPCTSTR lfFaceName
                
                int fontSize
                
                BOOL bUnderLine
                
                BOOL bBold
                
                BOOL bItalic

  Returns:      CFont*

-----------------------------------------------------------------F-F*/
CFont* CBSObject::GetFontPtr(LPCTSTR lfFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    CFont* pFontTemp = NULL;

    pFontTemp = new CFont();

    CBSObject::CreateBSFont(lfFaceName, fontSize, bUnderLine, bBold, bItalic, pFontTemp);

    return pFontTemp;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBSFont
                
  Summary:      Set font

  Author:       zhang.xu 2011.06.26

  Args:         UINT uiFaceName
                
                int fontSize
                
                BOOL bUnderLine
                
                BOOL bBold
                
                BOOL bItalic

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::SetBSFont(UINT uiFaceName, int fontSize, BOOL bUnderLine, BOOL bBold, BOOL bItalic)
{
    CString strFaceName;
    if (strFaceName.LoadString(uiFaceName))
    {
	    CBSObject::SetBSFont(strFaceName, fontSize, bUnderLine, bBold, bItalic);
    }
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetFontPtr
                
  Summary:      Get font pointer

  Author:       zhang.xu 2011.06.26

  Args:         UINT uiFaceName
                
                int fontSize
                
                BOOL bUnderLine
                
                BOOL bBold
                
                BOOL bItalic

  Returns:      CFont*

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetWindowText
                
  Summary:      Get window text

  Author:       zhang.xu 2011.06.15

  Args:         [out]CString& strCaption

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::GetWindowText(CString& strCaption)
{
    strCaption = m_strCaption;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    DrawBitmap

  Summary:     Draw BMP format pictures.

  Author:      zhang.xu 2006-02-18

  Args:        [in] HDC hDC
                   Handle of DC.
               [in] const RECT &rectDst
                   Rectangle of drawing area.
               [in] UINT Res
                   Resource ID of the picture.
               [in] HINSTANCE hInst
                   Instance of resource.

  Returns:     BOOL
                   TRUE or FALSE.  
-----------------------------------------------------------------F-F*/
BOOL CBSObject::DrawBitmap(HDC hDC, const RECT &rectDst, UINT uiRes, HINSTANCE hInst)
{
    Gdiplus::Graphics	graphics(hDC);

    Gdiplus::Bitmap bmp(hInst,(WCHAR *)MAKEINTRESOURCE(uiRes));

	graphics.DrawImage(&bmp,rectDst.left, rectDst.top);
	
	return TRUE;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    DrawPNG

  Summary:     Draw PNG format pictures.

  Author:      zhang.xu 2006-02-18

  Args:        [in] HDC hDC
                   Handle of DC.
               [in] const RECT &rectDst
                   Rectangle of drawing area.
               [in] UINT Res
                   Resource ID of the picture.
               [in] HINSTANCE hInst
                   Instance of resource.

  Returns:     BOOL
                   TRUE or FALSE.  
-----------------------------------------------------------------F-F*/
BOOL CBSObject::DrawPNG(HDC hDC, const RECT &rectDst, UINT Res, HINSTANCE hInst)
{
    return DrawPNG(hDC, rectDst, NULL, Res, hInst); 
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    DrawPNG

  Summary:     Draw PNG format pictures.

  Author:      zhang.xu 2006-02-18

  Args:        [in] HDC hDC
                   Handle of DC.
               [in] const RECT &rectDst
                   Rectangle of drawing area.
               [in] const RECT* prectImagePortion
                   Rectangle of image portion.
               [in] UINT Res
                   Resource ID of the picture.
               [in] HINSTANCE hInst
                   Instance of resource.

  Returns:     BOOL
                   TRUE or FALSE.  
-----------------------------------------------------------------F-F*/
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
		    //void* pResourceData = ::LockResource(::LoadResource(hInst,hResource));  
            //For Fortify by zhaoyunf
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
                            //CopyMemory(pBuffer, pResourceData, imageSize);  
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
									//graphics.DrawImage(&cImage, cRectF);
									//========================liwk
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
										NULL, //&clImgAtt
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     DrawPNG
                
  Summary:      Draw an image to DC

  Author:       zhang.xu 2011.06.16

  Args:         HDC hDC
                
                const RECT &rectDst
                
                Gdiplus::Image* pImage

  Returns:      BOOL

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     LoadImage
                
  Summary:      Create an image object from resource ID

  Author:       zhang.xu 2011.06.16

  Args:         UINT Res
  
                HINSTANCE hInst

  Returns:      Gdiplus::Image*

-----------------------------------------------------------------F-F*/
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
		    //void* pResourceData = ::LockResource(::LoadResource(hInst,hResource));  
            //For Fortify by zhaoyunf
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
                            //CopyMemory(pBuffer, pResourceData, imageSize);  
                            memcpy_s(pBuffer, imageSize, pResourceData, imageSize); //For stm0117
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     LoadImage
                
  Summary:      Create an image object from resource ID

  Author:       zhang.xu 2011.06.16

  Args:         LPCTSTR strImagePath
  
                HINSTANCE hInst

  Returns:      Gdiplus::Image*

-----------------------------------------------------------------F-F*/
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


/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    FillRect

  Summary:     Fill rectangle of drawing area.

  Author:      zhang.xu 2009-05-18

  Args:        [in] HDC hDC
                   Handle of DC.
               [in] const RECT& rectDst
                   Rectangle of drawing area.
               [in] COLORREF crBGColor
                   Color of background.

  Returns:     BOOL
                   TRUE or FALSE.  
-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:    DrawText

  Summary:     Draw text in drawing area.

  Author:      zhang.xu 2009-05-22

  Args:        [in] HDC hDC
                   Handle of DC.
               [in] const RECT& rectDst
                   Rectangle of drawing area.
               [in] COLORREF crBGColor
                   Color of background.

  Returns:     BOOL
                   TRUE or FALSE.  
-----------------------------------------------------------------F-F*/
BOOL CBSObject::DrawText(HDC hDC, const LPRECT lpRect, const CString& strText, 
							  HFONT hFont, COLORREF clrText, UINT uiFormat)
{
	BOOL bResult = FALSE;

#ifdef OSK //Using GDI way, limitation is "Do NOT work on layer window."
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
#else //Using GDI+ way    
    Gdiplus::Graphics graphics(hDC);
    
    Gdiplus::SolidBrush brush(Gdiplus::Color(255, GetRValue(clrText), GetGValue(clrText), GetBValue(clrText)));
    Gdiplus::Font font(hDC, hFont);
    Gdiplus::RectF  rect(lpRect->left, lpRect->top, lpRect->right - lpRect->left, lpRect->bottom - lpRect->top);

    //Set antiAlias
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	graphics.SetTextRenderingHint(Gdiplus::TextRenderingHintClearTypeGridFit);
         
    //Set Format
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
        //As default
        //strformat.SetFormatFlags(Gdiplus::StringFormatFlagsNoWrap);
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     DrawPNG
                
  Summary:      Draw PNG from a file

  Author:       zhang.xu 2011-06-03

  Args:         HDC hDC

                const RECT &rectDst

                LPCTSTR strImagePath

                HINSTANCE hInst

  Returns:      BOOL

-----------------------------------------------------------------F-F*/
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
    // TODO: Add your specialized code here and/or call the base class

    CWnd::PreSubclassWindow();
}


BOOL CBSObject::OnEraseBkgnd(CDC* pDC)
{
    // TODO: Add your message handler code here and/or call default
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

    //add by Tsubasa 2011/7/14
    if (m_bIsEnable && (FALSE == m_bLastState))
    {
        OnMouseLeave();
        m_bLastState = TRUE;
    }

    if (m_piPanelBG[iState] == NULL)
    {        
        //Draw background picture
        if (!m_bIsUseBGPicRect)
        {   
            if (m_uiBGPictureIDs[iState] != 0)
            {
                m_piPanelBG[iState] = LoadImage(m_uiBGPictureIDs[iState], AfxGetInstanceHandle());
            }
			else if (!m_csGBPicture[iState].IsEmpty())//wsh add
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
			else if (!m_csGBPicture[iState].IsEmpty())//wsh add
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextAlign
                
  Summary:      Set alignment fo text

  Author:       zhang.xu 2011.06.03

  Args:         UINT uiAlign
  
  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetTextAlign(UINT uiAlign)
{
    m_uiTextAlign = uiAlign;
    if (IsWindow(this->GetSafeHwnd()))
    {
        PaintParent();
        Invalidate();
    }
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBGPicRect
                
  Summary:      Set background picture's size

  Author:       zhang.xu 2011-06-03

  Args:         int x
                int y
                int cx
                int cy

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetBGPicRect(int x, int y, int cx, int cy)
{
    m_rtBGPicRect.left = x;
    m_rtBGPicRect.top = y;
    m_rtBGPicRect.right = x + cx;
    m_rtBGPicRect.bottom = y + cy;
    m_bIsUseBGPicRect = TRUE;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextRect
                
  Summary:     

  Author:       zhang.xu 2011-06-03

  Args:         int x
                int y 
                int cx 
                int cy

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetTextRect(int x, int y, int cx, int cy)
{
    m_rtTextRect.left = x;
    m_rtTextRect.top = y;
    m_rtTextRect.right = x + cx;
    m_rtTextRect.bottom = y + cy;
    m_bIsUseTextRect = TRUE;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextColor
                
  Summary:      Set control's text color

  Author:       zhang.xu 2011-06-03

  Args:         COLORREF crTextColor

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetTextColor(COLORREF crTextColor)
{
    m_crTextColor[BS_NORMAL] = crTextColor;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextColor2
                
  Summary:      Set control's text color for metal pattern

  Author:       zhang.xu 2011-06-21

  Args:         COLORREF crTextColor

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetTextColor2(COLORREF crTextColor)
{
    m_crTextColor2[BS_NORMAL] = crTextColor;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBKPictureID
                
  Summary:      Set background picture ID

  Author:       zhang.xu 2011.06.03

  Args:         enumBSBtnState BtnState
                    
                UINT uiBKPictureID

  Returns:      void

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextColor
                
  Summary:      Set text color with button state

  Author:       zhang.xu 2011-06-03

  Args:         enumBSBtnState BtnState
                
                COLORREF crTextColor

  Returns:      void

-----------------------------------------------------------------F-F*/
void CBSObject::SetTextColor(enumBSBtnState BtnState, COLORREF crTextColor)
{
    m_crTextColor[BtnState] = crTextColor;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetTextColor2
                
  Summary:      Set text color with button state for metal pattern

  Author:       zhang.xu 2011-06-03

  Args:         enumBSBtnState BtnState
                
                COLORREF crTextColor

  Returns:      void

-----------------------------------------------------------------F-F*/
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
    // TODO: Add your message handler code here and/or call default
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
    //CWnd::OnMouseLeave();
    
}

void CBSObject::SetPaintDC(HDC hPaintDC, int ix, int iy, int iCx, int iCy)
{
	m_hPaintDC = hPaintDC;
	m_StartPaintPoint = CPoint(ix, iy);
	m_iWidth = iCx;
	m_iHeight = iCy;
	//m_bHasPaintDC = TRUE;
}

void CBSObject::RePaintDC(RECT rect, BOOL bRShow)
{
	//OnPaint();
}

void CBSObject::EnablePaintDC(BOOL bEnable)
{
	m_bHasPaintDC = bEnable;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetButtonState
                
  Summary:      Get button state

  Author:       zhang.xu 2011-06-03

  Args:         UINT uiItemState

  Returns:      enumBSBtnState

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBKPictureHIDs
                
  Summary:      Set background picture IDs

  Author:       zhang.xu 2011.06.03

  Args:         UINT uiLeftPicID
                
                UINT uiMidPicID
                
                UINT uiRightPicID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::SetBKPictureHIDs(UINT uiLeftPicID, UINT uiMidPicID, UINT uiRightPicID)
{
	m_uiBKPicHIDs[BPH_LEFT] = uiLeftPicID;
	m_uiBKPicHIDs[BPH_MID] = uiMidPicID;
	m_uiBKPicHIDs[BPH_RIGHT] = uiRightPicID;
	m_isHBackground = TRUE;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBKPicVIDs
                
  Summary:      Set background picture IDs

  Author:       zhang.xu 2011.06.03

  Args:         UINT uiTopPicID
                
                UINT uiMidPicID
                
                UINT uiBottomPicID

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::SetBKPictureVIDs(UINT uiTopPicID, UINT uiMidPicID, UINT uiBottomPicID)
{
    m_uiBKPicVIDs[BPV_TOP] = uiTopPicID;
    m_uiBKPicVIDs[BPV_MID] = uiMidPicID;
    m_uiBKPicVIDs[BPV_BOTTOM] = uiBottomPicID;
    m_isVBackground = TRUE;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBGPictureID
                
  Summary:      Set background picture ID

  Author:       zhang.xu 2011.06.12

  Args:         UINT uiBGPictureID

  Returns:      None

-----------------------------------------------------------------F-F*/
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
    // TODO: Add your message handler code here and/or call default
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
    // TODO: Add your message handler code here and/or call default
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
    // TODO: Add your message handler code here and/or call default
    if (!m_bIsSelect /* && GetCapture() != this*/)
	{
       
		if (!m_isHover)
		{			
			/*TRACKMOUSEEVENT TrackMouseEvent;
			TrackMouseEvent.cbSize = sizeof (TRACKMOUSEEVENT);
			TrackMouseEvent.dwFlags = TME_LEAVE;
			TrackMouseEvent.hwndTrack = GetSafeHwnd();
			TrackMouseEvent.dwHoverTime = 0;
			_TrackMouseEvent(&TrackMouseEvent);*/
          
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     PaintParent
                
  Summary:      Erase child window's area

  Author:       zhang.xu 2011.06.12

  Args:         None

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::PaintParent()
{
    CRect   rect;
    GetWindowRect(&rect); 
    GetParent()->ScreenToClient(&rect); 
    GetParent()->InvalidateRect(&rect);
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     PaintGrandpa
                
  Summary:      Ask grandpa to redraw background

  Author:       zhang.xu 2011-06-15

  Args:         None

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::PaintGrandpa()
{
    CRect   rect;
    GetWindowRect(&rect);
    GetParent()->GetParent()->ScreenToClient(&rect); 
    GetParent()->GetParent()->InvalidateRect(&rect);
}


/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     EnableEraseBackground
                
  Summary:      Set enable/disable to erase background

  Author:       zhang.xu 2011.06.12

  Args:         BOOL bIsErase

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::EnableEraseBackground(BOOL bIsErase /*= TRUE*/)
{
   m_bIsEraseBG = bIsErase;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     GetFont
                
  Summary:      Get font pointer

  Author:       zhang.xu 2011.06.12

  Args:         None

  Returns:      CFont*

-----------------------------------------------------------------F-F*/
CFont* CBSObject::GetFont()
{
   return &m_cfFont;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     SetBackgroundColor
                
  Summary:      Set background color

  Author:       zhang.xu 2011.06.12

  Args:         COLORREF crBGColor

  Returns:      None

-----------------------------------------------------------------F-F*/
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


/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     EnableWindow
                
  Summary:      Enable window

  Author:       zhang.xu 2011.06.12

  Args:         BOOL bIsEnable

  Returns:      None

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     EnableSelect
                
  Summary:      Enable select state

  Author:       zhang.xu 2011.06.12

  Args:         BOOL bIsEnable

  Returns:      None

-----------------------------------------------------------------F-F*/
void CBSObject::EnableSelect(BOOL bIsEnable)
{
    m_bIsSelectEnabled = bIsEnable;
}

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     UnselectWindow
                
  Summary:      Set unselect window state

  Author:       zhang.xu 2011.06.12

  Args:         None

  Returns:      None

-----------------------------------------------------------------F-F*/
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

/*F+F+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Function:     IsWindowEnable
                
  Summary:      Retrieve if the window is enable.

  Author:       zhang.xu 2011.06.19

  Args:         None

  Returns:      None

-----------------------------------------------------------------F-F*/
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
	// TODO: Add your specialized code here and/or call the base class   
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

//wsh add
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

