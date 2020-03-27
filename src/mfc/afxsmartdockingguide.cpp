// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "afxcontrolbarutil.h"
#include "afxsmartdockingguide.h"
#include "afxribbonres.h"
#include "afxglobals.h"
#include "afxdockingmanager.h"
#include "afxvisualmanager.h"
#include "afxdrawmanager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int CSmartDockingStandaloneGuide::m_nLeftOffsetX = 16;
const int CSmartDockingStandaloneGuide::m_nRightOffsetX = 16;
const int CSmartDockingStandaloneGuide::m_nTopOffsetY = 16;
const int CSmartDockingStandaloneGuide::m_nBottomOffsetY = 16;

IMPLEMENT_DYNCREATE(CSmartDockingStandaloneGuide, CObject)
IMPLEMENT_DYNCREATE(CSmartDockingGroupGuidesManager, CObject)

#define COLOR_HIGHLIGHT_FRAME RGB(65, 112, 202)
#define ALPHA_TRANSPARENT 192

static AFX_SMARTDOCK_THEME __stdcall GetVMTheme()
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();
	if (params.m_uiMarkerBmpResID [0] != 0)
	{
		return AFX_SDT_DEFAULT;
	}

	AFX_SMARTDOCK_THEME theme = CDockingManager::GetSmartDockingTheme();
	if (theme == AFX_SDT_DEFAULT)
	{
		theme = CMFCVisualManager::GetInstance()->GetSmartDockingTheme();
	}

	return theme;
}

static void __stdcall ShadeRect(CDC* pDC, CRect rect, BOOL bIsVert)
{
	ASSERT_VALID(pDC);

	COLORREF colors [2] =
	{
		RGB(198, 198, 198),
		RGB(206, 206, 206),
	};

	rect.DeflateRect(1, 1);

	for (int i = 0; i < 2; i++)
	{
		CPen pen(PS_SOLID, 1, colors [i]);
		CPen* pOldPen = pDC->SelectObject(&pen);

		if (bIsVert)
		{
			pDC->MoveTo(rect.left + i, rect.top);
			pDC->LineTo(rect.left + i, rect.bottom);
		}
		else
		{
			pDC->MoveTo(rect.left, rect.top + i);
			pDC->LineTo(rect.right, rect.top + i);
		}

		pDC->SelectObject(pOldPen);
	}
}

// CSmartDockingStandaloneGuide

CSmartDockingStandaloneGuide::CSmartDockingStandaloneGuide() : m_nSideNo(sdNONE), m_cx(-1), m_cy(-1), m_bHiLited(FALSE), m_bLayered(FALSE), m_bIsDefaultImage(TRUE)
{
}

CSmartDockingStandaloneGuide::~CSmartDockingStandaloneGuide()
{
	Destroy();
}

void CSmartDockingStandaloneGuide::Create(SDMarkerPlace nSideNo, CWnd* pwndOwner)
{
	ASSERT(nSideNo >= sdLEFT && nSideNo <= sdBOTTOM);

	m_nSideNo = nSideNo;

	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();
	const BOOL bAlphaMarkers = params.m_bIsAlphaMarkers || GetVMTheme() == AFX_SDT_VS2008;

	InitImages(params);

	m_Rgn.Attach(CMFCToolBarImages::CreateRegionFromImage(m_Image.GetImageWell(), params.m_clrTransparent));

	CRect rect;
	m_Rgn.GetRgnBox(rect);

	m_cx = rect.Width();
	m_cy = rect.Height();

	HBITMAP hBmp = m_Image.GetImageWellLight();
	if (hBmp == NULL)
	{
		hBmp = m_Image.GetImageWell();
	}

	BOOL bIsVert = m_nSideNo == sdTOP || m_nSideNo == sdBOTTOM;

	m_wndBmp.Create(&rect, hBmp, NULL, pwndOwner, m_bIsDefaultImage, bIsVert);
	m_wndBmp.ModifyStyleEx(0, WS_EX_LAYERED);

	if (!bAlphaMarkers)
	{
		GetGlobalData()->SetLayeredAttrib(m_wndBmp.GetSafeHwnd(), params.m_clrTransparent, 0, LWA_COLORKEY);
	}

	m_bLayered = TRUE;

	m_wndBmp.ModifyStyleEx(0, WS_EX_TOPMOST);
}

void CSmartDockingStandaloneGuide::Destroy()
{
	if (::IsWindow(m_wndBmp.m_hWnd))
	{
		m_wndBmp.DestroyWindow();
	}
}

void CSmartDockingStandaloneGuide::Show(BOOL bShow)
{
	if (::IsWindow(m_wndBmp.m_hWnd))
	{
		m_wndBmp.ShowWindow(bShow ? SW_SHOW : SW_HIDE);
	}
}

void CSmartDockingStandaloneGuide::AdjustPos(CRect rcHost)
{
	int x = 0;
	int y = 0;

	switch (m_nSideNo)
	{
	case sdLEFT:
		x = rcHost.left + m_nLeftOffsetX;
		y = ((rcHost.bottom + rcHost.top) >> 1) -(m_cy>>1);
		break;

	case sdRIGHT:
		x = rcHost.right - m_nRightOffsetX - m_cx;
		y = ((rcHost.bottom + rcHost.top) >> 1) -(m_cy>>1);
		break;

	case sdTOP:
		x = ((rcHost.left + rcHost.right) >> 1) -(m_cx >> 1);
		y = rcHost.top + m_nTopOffsetY;
		break;

	case sdBOTTOM:
		x = ((rcHost.left + rcHost.right) >> 1) -(m_cx >> 1);
		y = rcHost.bottom - m_nBottomOffsetY - m_cy;
		break;

	default:
		ASSERT(FALSE);
		return;
	}

	if (m_wndBmp.GetSafeHwnd() != NULL)
	{
		m_wndBmp.SetWindowPos(&CWnd::wndTopMost, x, y, -1, -1, SWP_NOSIZE | SWP_NOACTIVATE);
	}
}

void CSmartDockingStandaloneGuide::Highlight(BOOL bHiLite)
{
	if (m_bHiLited == bHiLite)
	{
		m_wndBmp.UpdateLayered();
		return;
	}

	m_bHiLited = bHiLite;
	m_wndBmp.Highlight(m_bHiLited);

	if (!m_bIsDefaultImage || GetVMTheme() == AFX_SDT_VS2008)
	{
		HBITMAP hBmpLight = m_Image.GetImageWellLight();
		if (hBmpLight == NULL)
		{
			hBmpLight = m_Image.GetImageWell();
		}

		m_wndBmp.Assign(bHiLite ? (m_ImageHot.IsValid() ? m_ImageHot.GetImageWell() : m_Image.GetImageWell()) : hBmpLight, TRUE);
	}
}

BOOL CSmartDockingStandaloneGuide::IsPtIn(CPoint point) const
{
	if (m_wndBmp.GetSafeHwnd() == NULL || !m_wndBmp.IsWindowVisible())
	{
		return FALSE;
	}
	m_wndBmp.ScreenToClient(&point);

	if (m_bLayered)
	{
		return m_Rgn.PtInRegion(point);
	}
	else
	{
		CRgn rgn;
		rgn.CreateRectRgn(0, 0, 0, 0);

		m_wndBmp.GetWindowRgn(rgn);

		return rgn.PtInRegion(point);
	}
}

void CSmartDockingStandaloneGuide::InitImages(CSmartDockingInfo& params)
{
	static UINT uiDefaultMarkerIDs2005 [] =
	{
		IDB_AFXBARRES_SD_LEFT,
		IDB_AFXBARRES_SD_RIGHT,
		IDB_AFXBARRES_SD_TOP,
		IDB_AFXBARRES_SD_BOTTOM,
		IDB_AFXBARRES_SD_MIDDLE
	};

	static UINT uiDefaultMarkerIDs2008 [] =
	{
		IDB_AFXBARRES_SD2008_LEFT,
		IDB_AFXBARRES_SD2008_RIGHT,
		IDB_AFXBARRES_SD2008_TOP,
		IDB_AFXBARRES_SD2008_BOTTOM,
		IDB_AFXBARRES_SD2008_MIDDLE
	};

	static UINT uiDefaultMarkerHotIDs2008 [] =
	{
		IDB_AFXBARRES_SD2008_LEFT_HOT,
		IDB_AFXBARRES_SD2008_RIGHT_HOT,
		IDB_AFXBARRES_SD2008_TOP_HOT,
		IDB_AFXBARRES_SD2008_BOTTOM_HOT,
		IDB_AFXBARRES_SD2008_MIDDLE_HOT
	};

	m_Image.Clear();
	m_Image.SetLightPercentage(-1);
	m_ImageHot.Clear();

	int nIndex = -1;

	switch (m_nSideNo)
	{
	case sdLEFT:
	case sdCLEFT:
		nIndex = 0;
		break;

	case sdRIGHT:
	case sdCRIGHT:
		nIndex = 1;
		break;

	case sdTOP:
	case sdCTOP:
		nIndex = 2;
		break;

	case sdBOTTOM:
	case sdCBOTTOM:
		nIndex = 3;
		break;

	case sdCMIDDLE:
		nIndex = 4;
		break;

	default:
		ASSERT(FALSE);
		return;
	}

	UINT uiResID = params.m_uiMarkerBmpResID [nIndex];
	UINT uiResHotID = params.m_uiMarkerLightBmpResID [nIndex];
	m_bIsDefaultImage = uiResID == 0;

	if (m_bIsDefaultImage)
	{
		// Use default marker:
		AFX_SMARTDOCK_THEME theme = GetVMTheme();

		switch (theme)
		{
		case AFX_SDT_VS2005:
			uiResID = uiDefaultMarkerIDs2005 [nIndex];
			break;

		case AFX_SDT_VS2008:
			uiResID = uiDefaultMarkerIDs2008 [nIndex];
			uiResHotID = uiDefaultMarkerHotIDs2008 [nIndex];
			break;
		}
	}

	m_Image.SetMapTo3DColors(FALSE);
	m_Image.SetAlwaysLight(uiResHotID == 0);
	m_Image.Load(uiResID);
	m_Image.SetSingleImage();

	m_Image.SetTransparentColor(params.m_clrTransparent);

	if (uiResHotID != 0)
	{
		m_ImageHot.SetMapTo3DColors(FALSE);
		m_ImageHot.Load(uiResHotID);
		m_ImageHot.SetSingleImage();

		m_ImageHot.SetTransparentColor(params.m_clrTransparent);
	}

	COLORREF clrToneSrc = m_bIsDefaultImage ?(COLORREF)-1 : params.m_clrToneSrc;
	COLORREF clrToneDst = m_bIsDefaultImage && params.m_clrToneDest == -1 ? CMFCVisualManager::GetInstance()->GetSmartDockingHighlightToneColor() : params.m_clrToneDest;

	if (clrToneSrc != (COLORREF)-1 && clrToneDst != (COLORREF)-1)
	{
		m_Image.AdaptColors(clrToneSrc, clrToneDst);
	}

	HWND hwndBmp = m_wndBmp.GetSafeHwnd();
	if (hwndBmp != NULL)
	{
		HBITMAP hBmpLight = m_Image.GetImageWellLight();
		if (hBmpLight == NULL)
		{
			hBmpLight = m_Image.GetImageWell();
		}

		m_wndBmp.Assign(hBmpLight, FALSE);

		if (!params.m_bIsAlphaMarkers && GetVMTheme() != AFX_SDT_VS2008)
		{
			::SetLayeredWindowAttributes(hwndBmp, params.m_clrTransparent, 0, LWA_COLORKEY);
		}
	}
}

// CSmartDockingGroupGuidesWnd

CSmartDockingGroupGuidesWnd::CSmartDockingGroupGuidesWnd() : m_pCentralGroup(NULL)
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();

	COLORREF clrBaseGroupBackground;
	COLORREF clrBaseGroupBorder;

	CMFCVisualManager::GetInstance()->GetSmartDockingBaseGuideColors(clrBaseGroupBackground, clrBaseGroupBorder);

	m_brBaseBackground.CreateSolidBrush(params.m_clrBaseBackground == -1 ? clrBaseGroupBackground : params.m_clrBaseBackground);
	m_brBaseBorder.CreateSolidBrush(params.m_clrBaseBorder == -1 ? clrBaseGroupBorder : params.m_clrBaseBorder);
}

BEGIN_MESSAGE_MAP(CSmartDockingGroupGuidesWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CSmartDockingGroupGuidesWnd::Update()
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();
	if (!params.m_bIsAlphaMarkers && GetVMTheme() != AFX_SDT_VS2008)
	{
		RedrawWindow();
		return;
	}

	CRect rect;
	GetClientRect(rect);

	CPoint point(0, 0);
	CSize size(rect.Size());

	LPBYTE pBits = NULL;
	HBITMAP hBitmap = CDrawingManager::CreateBitmap_32(size, (void**)&pBits);
	if (hBitmap == NULL)
	{
		return;
	}

	CBitmap bitmap;
	bitmap.Attach(hBitmap);

	CClientDC clientDC(this);
	CDC dc;
	dc.CreateCompatibleDC(&clientDC);

	CBitmap* pBitmapOld = (CBitmap*)dc.SelectObject(&bitmap);

	ASSERT_VALID(m_pCentralGroup);

	m_pCentralGroup->DrawCentralGroupGuides(dc, m_brBaseBackground, m_brBaseBorder, rect);

	BLENDFUNCTION bf;
	bf.BlendOp             = AC_SRC_OVER;
	bf.BlendFlags          = 0;
	bf.SourceConstantAlpha = 255;
	bf.AlphaFormat         = LWA_COLORKEY;

	UpdateLayeredWindow(NULL, 0, &size, &dc, &point, 0, &bf, 0x02);

	dc.SelectObject(pBitmapOld);
}

void CSmartDockingGroupGuidesWnd::OnPaint()
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();

	CPaintDC dc(this); // device context for painting

	CMemDC memDC(dc, this);
	CDC* pDC = &memDC.GetDC();

	CRect rectClient;
	GetClientRect(rectClient);

	CBrush brBack;
	brBack.CreateSolidBrush(params.m_clrTransparent);

	pDC->FillRect(rectClient, &brBack);

	ASSERT_VALID(m_pCentralGroup);

	m_pCentralGroup->DrawCentralGroupGuides(*pDC, m_brBaseBackground, m_brBaseBorder, rectClient);
}

void CSmartDockingGroupGuidesWnd::OnClose()
{
	// so that it does not get destroyed
}

BOOL CSmartDockingGroupGuidesWnd::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

// CSmartDockingGroupGuide

CSmartDockingGroupGuide::CSmartDockingGroupGuide() : m_pCentralGroup(NULL), m_bVisible(TRUE), m_clrFrame((COLORREF)-1)
{
}

CSmartDockingGroupGuide::~CSmartDockingGroupGuide()
{
}

void CSmartDockingGroupGuide::Create(SDMarkerPlace, CWnd*)
{
	// should never be called
	ASSERT(FALSE);
}

void CSmartDockingGroupGuide::Destroy()
{
	// should never be called
	ASSERT(FALSE);
}

void CSmartDockingGroupGuide::Show(BOOL)
{
	// should never be called
	ASSERT(FALSE);
}

void CSmartDockingGroupGuide::AdjustPos(CRect)
{
	// should never be called
	ASSERT(FALSE);
}

void CSmartDockingGroupGuide::Highlight(BOOL bHiLite)
{
	if (m_bHiLited == bHiLite)
	{
		return;
	}

	ASSERT_VALID(m_pCentralGroup);

	m_bHiLited = bHiLite;
	m_pCentralGroup->m_Wnd.Update();
}

void CSmartDockingGroupGuide::SetVisible(BOOL bVisible/* = TRUE*/, BOOL bRedraw/* = TRUE*/)
{
	m_bVisible = bVisible;

	if (bRedraw && m_pCentralGroup != NULL)
	{
		ASSERT_VALID(m_pCentralGroup);
		m_pCentralGroup->m_Wnd.Update();
	}
}

BOOL CSmartDockingGroupGuide::IsPtIn(CPoint point) const
{
	if (!m_bVisible)
	{
		return FALSE;
	}

	m_pCentralGroup->m_Wnd.ScreenToClient(&point);
	return m_Rgn.PtInRegion(point.x, point.y);
}

void CSmartDockingGroupGuide::Create(SDMarkerPlace nSideNo, CSmartDockingGroupGuidesManager* pCentralGroup)
{
	ASSERT(nSideNo >= sdCLEFT && nSideNo <= sdCMIDDLE);

	m_nSideNo = nSideNo;
	m_pCentralGroup = pCentralGroup;

	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();

	InitImages(params);

	if (m_bIsDefaultImage)
	{
		AFX_SMARTDOCK_THEME theme = GetVMTheme();

		switch (theme)
		{
		case AFX_SDT_VS2005:
			params.m_nCentralGroupOffset = 9;
			params.m_sizeTotal = CSize(88, 88);
			break;

		case AFX_SDT_VS2008:
			params.m_nCentralGroupOffset = 5;
			params.m_sizeTotal = CSize(110, 110);
			break;
		}
	}

	COLORREF clrBaseGroupBackground;
	CMFCVisualManager::GetInstance()->GetSmartDockingBaseGuideColors(clrBaseGroupBackground, m_clrFrame);

	m_penFrame.CreatePen(PS_SOLID, 1, m_clrFrame);
	m_penHighlight.CreatePen(PS_SOLID, 1, COLOR_HIGHLIGHT_FRAME);

	const CSize sizeGroup = params.m_sizeTotal;
	const CSize sizeImage = m_Image.GetImageSize();

	switch (m_nSideNo)
	{
	case sdCLEFT:
		m_nOffsetX = 0;
		m_nOffsetY = (sizeGroup.cy  - sizeImage.cy) / 2;
		break;

	case sdCRIGHT:
		m_nOffsetX = sizeGroup.cx  - sizeImage.cx;
		m_nOffsetY = (sizeGroup.cy  - sizeImage.cy) / 2;
		break;

	case sdCTOP:
		m_nOffsetX = (sizeGroup.cx  - sizeImage.cx) / 2;
		m_nOffsetY = 0;
		break;

	case sdCBOTTOM:
		m_nOffsetX = (sizeGroup.cx  - sizeImage.cx) / 2;
		m_nOffsetY = sizeGroup.cy  - sizeImage.cy;
		break;

	case sdCMIDDLE:
		m_nOffsetX = (sizeGroup.cx  - sizeImage.cx) / 2;
		m_nOffsetY = (sizeGroup.cy  - sizeImage.cy) / 2;
		break;
	}

	m_Rgn.Attach(CMFCToolBarImages::CreateRegionFromImage(m_Image.GetImageWell(), params.m_clrTransparent));
	m_Rgn.OffsetRgn(m_nOffsetX, m_nOffsetY);
}

void CSmartDockingGroupGuide::DestroyImages()
{
	m_Rgn.DeleteObject();
}

void CSmartDockingGroupGuide::Draw(CDC& dc, BOOL bAlpha)
{
	const BOOL bFadeImage = !m_bHiLited && !m_bIsDefaultImage && !m_ImageHot.IsValid();

	CAfxDrawState ds;
	CMFCToolBarImages& image = m_bHiLited && m_ImageHot.IsValid() ? m_ImageHot : m_Image;

	if (bAlpha && !m_bHiLited)
	{
		image.DrawEx(&dc, CRect(CPoint(m_nOffsetX, m_nOffsetY), image.GetImageSize()), 0, 
			CMFCToolBarImages::ImageAlignHorzLeft,
			CMFCToolBarImages::ImageAlignVertTop,
			CRect(0, 0, 0, 0), ALPHA_TRANSPARENT);
		return;
	}

	image.PrepareDrawImage(ds, CSize(0, 0), bFadeImage);

	image.Draw(&dc, m_nOffsetX, m_nOffsetY, 0, FALSE, FALSE, FALSE, FALSE, bFadeImage);
	image.EndDrawImage(ds);

	if (!m_bIsDefaultImage)
	{
		return;
	}

	if (GetVMTheme() == AFX_SDT_VS2008)
	{
		return;
	}

	// For the default image we need to draw the border:
	CRect rect;
	m_Rgn.GetRgnBox(rect);

	CPen* pOldPen = dc.SelectObject(m_bHiLited ? &m_penHighlight : &m_penFrame);

	switch (m_nSideNo)
	{
	case sdCLEFT:
		rect.right -= 7;
		dc.MoveTo(rect.right, rect.top);
		dc.LineTo(rect.left, rect.top);
		dc.LineTo(rect.left, rect.bottom);
		dc.LineTo(rect.right, rect.bottom);
		ShadeRect(&dc, rect, FALSE);
		break;

	case sdCRIGHT:
		rect.left += 7;
		dc.MoveTo(rect.left, rect.top);
		dc.LineTo(rect.right - 1, rect.top);
		dc.LineTo(rect.right - 1, rect.bottom);
		dc.LineTo(rect.left, rect.bottom);
		ShadeRect(&dc, rect, FALSE);
		break;

	case sdCTOP:
		rect.bottom -= 7;
		dc.MoveTo(rect.left, rect.bottom);
		dc.LineTo(rect.left, rect.top);
		dc.LineTo(rect.right, rect.top);
		dc.LineTo(rect.right, rect.bottom);
		ShadeRect(&dc, rect, TRUE);
		break;

	case sdCBOTTOM:
		rect.top += 7;
		dc.MoveTo(rect.left, rect.top);
		dc.LineTo(rect.left, rect.bottom - 1);
		dc.LineTo(rect.right, rect.bottom - 1);
		dc.LineTo(rect.right, rect.top);
		ShadeRect(&dc, rect, TRUE);
		break;

	case sdCMIDDLE:
		break;
	}

	dc.SelectObject(pOldPen);
}

// CSmartDockingGroupGuidesManager

CSmartDockingGroupGuidesManager::CSmartDockingGroupGuidesManager() : m_bCreated(FALSE), m_bMiddleIsOn(FALSE), m_bLayered(FALSE)
{
}

CSmartDockingGroupGuidesManager::~CSmartDockingGroupGuidesManager()
{
	Destroy();
}

void CSmartDockingGroupGuidesManager::Create(CWnd* pwndOwner)
{
	if (m_bCreated)
	{
		return;
	}

	CRgn rgnAll;
	rgnAll.CreateRectRgn(0, 0, 0, 0);

	CSmartDockingStandaloneGuide::SDMarkerPlace i;
	for (i = CSmartDockingStandaloneGuide::sdCLEFT; i <= CSmartDockingStandaloneGuide::sdCMIDDLE; ++reinterpret_cast<int&>(i))
	{
		m_arMarkers[i - CSmartDockingStandaloneGuide::sdCLEFT].Create(i, this);
		rgnAll.CombineRgn(&rgnAll, &m_arMarkers[i - CSmartDockingStandaloneGuide::sdCLEFT].m_Rgn, RGN_OR);
	}

	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();

	UINT uiBaseResID = params.m_uiBaseBmpResID;

	if (uiBaseResID == 0)
	{
		AFX_SMARTDOCK_THEME theme = GetVMTheme();

		switch (theme)
		{
		case AFX_SDT_VS2008:
			uiBaseResID = IDB_AFXBARRES_SD2008_BASE;
			break;
		}
	}

	if (uiBaseResID != 0)
	{
		m_Image.SetMapTo3DColors(FALSE);
		m_Image.SetAlwaysLight();
		m_Image.Load(uiBaseResID);
		m_Image.SetSingleImage();
		m_Image.SetTransparentColor(params.m_clrTransparent);
	}

	CRect rectBase;
	rgnAll.GetRgnBox(rectBase);
	rectBase.DeflateRect(params.m_nCentralGroupOffset, params.m_nCentralGroupOffset);

#define AFX_BASE_PTS 4
	POINT ptBase [AFX_BASE_PTS];

	ptBase [0].x = rectBase.left;
	ptBase [0].y = rectBase.CenterPoint().y;
	ptBase [1].x = rectBase.CenterPoint().x;
	ptBase [1].y = rectBase.bottom;
	ptBase [2].x = rectBase.right;
	ptBase [2].y = rectBase.CenterPoint().y;
	ptBase [3].x = rectBase.CenterPoint().x;
	ptBase [3].y = rectBase.top;

	m_rgnBase.CreatePolygonRgn(ptBase, AFX_BASE_PTS, ALTERNATE);

	rgnAll.CombineRgn(&rgnAll, &m_rgnBase, RGN_OR);

	CRect rcGroup;
	rgnAll.GetRgnBox(rcGroup);

	BOOL bResult = FALSE;

	bResult = m_Wnd.CreateEx(WS_EX_TOPMOST, GetSmartDockingWndClassName<CS_OWNDC | CS_SAVEBITS>(), _T(""), WS_POPUP, rcGroup, pwndOwner, NULL);

	if (bResult)
	{
		m_Wnd.m_pCentralGroup = this;

		m_Wnd.ModifyStyleEx(0, WS_EX_LAYERED);

		if (!params.m_bIsAlphaMarkers && GetVMTheme() != AFX_SDT_VS2008)
		{
			GetGlobalData()->SetLayeredAttrib(m_Wnd.GetSafeHwnd(), params.m_clrTransparent, 0, LWA_COLORKEY);
		}
		else
		{
			m_Wnd.Update();
		}

		m_bLayered = TRUE;

		m_bCreated = TRUE;
	}
}

void CSmartDockingGroupGuidesManager::Destroy()
{
	if (!m_bCreated)
	{
		return;
	}

	CSmartDockingStandaloneGuide::SDMarkerPlace i;
	for (i = CSmartDockingStandaloneGuide::sdCLEFT; i <= CSmartDockingStandaloneGuide::sdCMIDDLE; ++reinterpret_cast<int&>(i))
	{
		m_arMarkers[i - CSmartDockingStandaloneGuide::sdCLEFT].DestroyImages();
	}

	m_Wnd.DestroyWindow();

	m_rgnBase.DeleteObject();

	m_bCreated = FALSE;
}

void CSmartDockingGroupGuidesManager::Show(BOOL bShow)
{
	if (::IsWindow(m_Wnd.m_hWnd))
	{
		m_Wnd.ShowWindow(bShow ? SW_SHOW : SW_HIDE);
	}
}
void CSmartDockingGroupGuidesManager::GetWindowRect(CRect& rect)
{
	rect.SetRectEmpty();
	if (m_Wnd.GetSafeHwnd() != NULL)
	{
		m_Wnd.GetWindowRect(rect);
	}
}
BOOL CSmartDockingGroupGuidesManager::AdjustPos(CRect rcHost, int nMiddleIsOn)
{
	CRect rcWnd;
	if (m_Wnd.GetSafeHwnd() != NULL)
	{
		if (nMiddleIsOn != -1)
		{
			if (nMiddleIsOn == 0 && m_bMiddleIsOn)
			{
				m_bMiddleIsOn = FALSE;
				m_Wnd.Update();
			}
			else
				if (nMiddleIsOn == 1 && !m_bMiddleIsOn)
				{
					m_bMiddleIsOn = TRUE;
					m_Wnd.Update();
				}
		}

		m_Wnd.GetClientRect(rcWnd);

		int x = ((rcHost.right + rcHost.left) - rcWnd.Width()) >> 1;
		int y = ((rcHost.bottom + rcHost.top) - rcWnd.Height()) >> 1;

		CRect rcCurrentPos;
		m_Wnd.GetWindowRect(rcCurrentPos);

		if (rcCurrentPos.left != x || rcCurrentPos.top != y)
		{
			m_Wnd.SetWindowPos(&CWnd::wndTopMost, x, y, -1, -1, SWP_NOSIZE);

			return TRUE;
		}
	}

	return FALSE;
}

void CSmartDockingGroupGuidesManager::ShowGuide( CSmartDockingStandaloneGuide::SDMarkerPlace nMarkerNo, BOOL bShow/* = TRUE*/, BOOL bRedraw/* = TRUE*/)
{
	CSmartDockingGroupGuide* pMarker = GetGuide(nMarkerNo);
	if (pMarker == NULL)
	{
		return;
	}

	if (pMarker->IsVisible() != bShow)
	{
		pMarker->SetVisible(bShow, bRedraw);
	}
}

void CSmartDockingGroupGuidesManager::DrawCentralGroupGuides(CDC& dc, CBrush& brBaseBackground, CBrush& brBaseBorder, CRect rectClient)
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();
	const BOOL bAlphaMarkers = params.m_bIsAlphaMarkers || GetVMTheme() == AFX_SDT_VS2008;

	CDC cmpdc;
	cmpdc.CreateCompatibleDC(&dc);

	if (!bAlphaMarkers)
	{
		// fill with the transparent color
		CRect rect;
		dc.GetBoundsRect(rect, 0);

		CBrush brBack;
		brBack.CreateSolidBrush(params.m_clrTransparent);
		dc.FillRect(rect, &brBack);
	}

	if (m_Image.IsValid())
	{
		m_Image.DrawEx(&dc, rectClient, 0, 
			CMFCToolBarImages::ImageAlignHorzCenter, CMFCToolBarImages::ImageAlignVertCenter,
			CRect(0, 0, 0, 0), (BYTE)(bAlphaMarkers ? ALPHA_TRANSPARENT : 255));
	}
	else
	{
		dc.FillRgn(&m_rgnBase, &brBaseBackground);

		if (m_bMiddleIsOn && params.m_uiMarkerBmpResID [0] == 0) // Default images
		{
			CSmartDockingGroupGuide& centerMarker = m_arMarkers [CSmartDockingStandaloneGuide::sdCMIDDLE - CSmartDockingStandaloneGuide::sdCLEFT];

			if (centerMarker.IsVisible() && centerMarker.m_bHiLited)
			{
				CBrush br(COLOR_HIGHLIGHT_FRAME);
				dc.FrameRgn(&m_rgnBase, &br, 1, 1);
			}
			else
			{
				dc.FrameRgn(&m_rgnBase, &brBaseBorder, 1, 1);
			}
		}
		else
		{
			dc.FrameRgn(&m_rgnBase, &brBaseBorder, 1, 1);
		}
	}

	CSmartDockingStandaloneGuide::SDMarkerPlace i;
	CSmartDockingStandaloneGuide::SDMarkerPlace last = m_bMiddleIsOn ? CSmartDockingStandaloneGuide::sdCMIDDLE : CSmartDockingStandaloneGuide::sdCBOTTOM;

	for (i = CSmartDockingStandaloneGuide::sdCLEFT; i <= last; ++reinterpret_cast<int&>(i))
	{
		CSmartDockingGroupGuide& marker = m_arMarkers[i - CSmartDockingStandaloneGuide::sdCLEFT];

		if (marker.IsVisible())
		{
			marker.Draw(dc, bAlphaMarkers);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSmartDockingStandaloneGuideWnd

CSmartDockingStandaloneGuideWnd::CSmartDockingStandaloneGuideWnd()
{
	m_bIsHighlighted = FALSE;
	m_bIsDefaultImage = FALSE;
	m_clrFrame = (COLORREF)-1;
	m_bIsVert = FALSE;
}

CSmartDockingStandaloneGuideWnd::~CSmartDockingStandaloneGuideWnd()
{
}

BEGIN_MESSAGE_MAP(CSmartDockingStandaloneGuideWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// if the window gets created, the region is deeded to Windows
BOOL CSmartDockingStandaloneGuideWnd::Create(LPRECT pWndRect, HBITMAP hbmpFace, HRGN hrgnShape, CWnd* pwndOwner, BOOL bIsDefaultImage, BOOL bIsVert)
{
	// save data needed
	m_hbmpFace = hbmpFace;
	m_bIsDefaultImage = bIsDefaultImage;
	m_bIsVert = bIsVert;

	// create window with specified params
	BOOL res = CreateEx(0, GetSmartDockingWndClassName<CS_OWNDC | CS_SAVEBITS>(), _T(""), WS_POPUP, *pWndRect, pwndOwner, NULL);

	// if succeeded, set the region
	if (res)
	{
		SetWindowRgn(hrgnShape, FALSE);
	}

	COLORREF clrBaseGroupBackground;
	CMFCVisualManager::GetInstance()->GetSmartDockingBaseGuideColors(clrBaseGroupBackground, m_clrFrame);

	return res;
}

void CSmartDockingStandaloneGuideWnd::Highlight(BOOL bSet)
{
	m_bIsHighlighted = bSet;

	if (GetSafeHwnd() != NULL)
	{
		RedrawWindow();
		UpdateLayered();
	}
}

void CSmartDockingStandaloneGuideWnd::UpdateLayered()
{
	CSmartDockingInfo& params = CDockingManager::GetSmartDockingParams();
	const BOOL bAlphaMarkers = params.m_bIsAlphaMarkers || GetVMTheme() == AFX_SDT_VS2008;

	if (!bAlphaMarkers)
	{
		return;
	}

	CRect rect;
	GetClientRect(rect);

	CPoint point(0, 0);
	CSize size(rect.Size());

	LPBYTE pBits = NULL;
	HBITMAP hBitmap = CDrawingManager::CreateBitmap_32(size, (void**)&pBits);
	if (hBitmap == NULL)
	{
		return;
	}

	CBitmap bitmap;
	bitmap.Attach(hBitmap);

	CClientDC clientDC(this);
	CDC dc;
	dc.CreateCompatibleDC(&clientDC);

	CBitmap* pBitmapOld = (CBitmap*)dc.SelectObject(&bitmap);

	dc.DrawState(point, size, m_hbmpFace, DSS_NORMAL);

	BLENDFUNCTION bf;
	bf.BlendOp             = AC_SRC_OVER;
	bf.BlendFlags          = 0;
	bf.SourceConstantAlpha = (BYTE)(m_bIsHighlighted ? 255 : ALPHA_TRANSPARENT);
	bf.AlphaFormat         = LWA_COLORKEY;

	UpdateLayeredWindow(NULL, 0, &size, &dc,  &point, 0, &bf, 0x02);

	dc.SelectObject(pBitmapOld);
}

BOOL CSmartDockingStandaloneGuideWnd::Assign(HBITMAP hbmpFace, BOOL bRedraw)
{
	if (hbmpFace != NULL)
	{
		m_hbmpFace = hbmpFace;
	}

	Invalidate(bRedraw);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSmartDockingStandaloneGuideWnd message handlers

// simply splash the bitmap onto window's surface
void CSmartDockingStandaloneGuideWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectClient;
	GetClientRect(rectClient);

	dc.DrawState(CPoint(0, 0), rectClient.Size(), m_hbmpFace, DSS_NORMAL);

	if (!m_bIsDefaultImage || GetVMTheme() == AFX_SDT_VS2008)
	{
		return;
	}

	COLORREF clrFrame = m_bIsHighlighted ? COLOR_HIGHLIGHT_FRAME : m_clrFrame;
	dc.Draw3dRect(rectClient, clrFrame, clrFrame);

	ShadeRect(&dc, rectClient, m_bIsVert);
}

void CSmartDockingStandaloneGuideWnd::OnClose()
{
	// so that it does not get destroyed
}

BOOL CSmartDockingStandaloneGuideWnd::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}
