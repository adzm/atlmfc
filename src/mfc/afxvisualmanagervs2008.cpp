// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright(C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "afxvisualmanagervs2008.h"
#include "afxtoolbarmenubutton.h"
#include "afxdrawmanager.h"
#include "afxtabctrl.h"
#include "afxautohidebutton.h"
#include "afxcolorbar.h"
#include "afxglobals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WINXPBLUE_GRADIENT_LIGHT	RGB(239, 243, 250)
#define WINXPBLUE_GRADIENT_DARK		RGB(193, 210, 238)
#define WINXPBLUE_MENUITEM_BORDER	RGB(152, 181, 226)
#define WINXPBLUE_MENU_GUTTER		RGB(241, 241, 241)
#define WINXPBLUE_MENU_GUTTER_DARK	RGB(225, 225, 225)

IMPLEMENT_DYNCREATE(CMFCVisualManagerVS2008, CMFCVisualManagerVS2005)

// Construction/Destruction
CMFCVisualManagerVS2008::CMFCVisualManagerVS2008()
{
	m_bConnectMenuToParent = FALSE;
	m_bShdowDroppedDownMenuButton = FALSE;
	m_bOSColors = FALSE;

	OnUpdateSystemColors();
}

CMFCVisualManagerVS2008::~CMFCVisualManagerVS2008()
{
}

void CMFCVisualManagerVS2008::OnFillBarBackground(CDC* pDC, CBasePane* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea)
{
	ASSERT_VALID(pBar);
	ASSERT_VALID(pDC);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 ||
		GetGlobalData()->IsHighContrastMode() ||
		!pBar->IsKindOf(RUNTIME_CLASS(CMFCPopupMenuBar)) ||
		pBar->IsKindOf(RUNTIME_CLASS(CMFCColorBar)) ||
		GetStandardWindowsTheme() != WinXpTheme_Blue)
	{
		CMFCVisualManagerVS2005::OnFillBarBackground(pDC, pBar, rectClient, rectClip, bNCArea);
		return;
	}

	if (rectClip.IsRectEmpty())
	{
		rectClip = rectClient;
	}

	pDC->FillRect(rectClip, &m_brMenuLight);

	CMFCPopupMenuBar* pMenuBar = DYNAMIC_DOWNCAST(CMFCPopupMenuBar, pBar);
	ASSERT_VALID(pMenuBar);

	if (!pMenuBar->m_bDisableSideBarInXPMode)
	{
		CRect rectImages = rectClient;

		rectImages.right = rectImages.left + pMenuBar->GetGutterWidth();
		rectImages.DeflateRect(0, 1);

		CBrush br(WINXPBLUE_MENU_GUTTER);
		pDC->FillRect(rectImages, &br);

		CPen* pOldPen = pDC->SelectObject(&m_penSeparator);
		ASSERT(pOldPen != NULL);

		pDC->MoveTo(rectImages.right, rectImages.top);
		pDC->LineTo(rectImages.right, rectImages.bottom);

		pDC->SelectObject(pOldPen);
	}
}

void CMFCVisualManagerVS2008::OnHighlightRarelyUsedMenuItems(CDC* pDC, CRect rectRarelyUsed)
{
	ASSERT_VALID(pDC);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() ||
		GetStandardWindowsTheme() != WinXpTheme_Blue)
	{
		CMFCVisualManagerVS2005::OnHighlightRarelyUsedMenuItems(pDC, rectRarelyUsed);
		return;
	}

	rectRarelyUsed.left--;
	rectRarelyUsed.right = rectRarelyUsed.left + CMFCToolBar::GetMenuImageSize().cx + 2 * GetMenuImageMargin() + 2;

	CBrush br(WINXPBLUE_MENU_GUTTER_DARK);
	pDC->FillRect(rectRarelyUsed, &br);
}

void CMFCVisualManagerVS2008::OnDrawButtonBorder(CDC* pDC, CMFCToolBarButton* pButton, CRect rect, CMFCVisualManager::AFX_BUTTON_STATE state)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	CMFCToolBarMenuButton* pMenuButton = DYNAMIC_DOWNCAST(CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuBarButton = pMenuButton != NULL && pMenuButton->GetParentWnd() != NULL && pMenuButton->GetParentWnd()->IsKindOf(RUNTIME_CLASS(CMFCMenuBar));
	if (bIsMenuBarButton)
	{
		rect.bottom -= 2;
	}

	if (!bIsMenuBarButton || !pMenuButton->IsDroppedDown())
	{
		CMFCVisualManagerVS2005::OnDrawButtonBorder(pDC, pButton, rect, state);
		return;
	}

	pDC->Draw3dRect(rect, m_clrMenuItemBorder, m_clrMenuItemBorder);
}

void CMFCVisualManagerVS2008::OnFillButtonInterior(CDC* pDC, CMFCToolBarButton* pButton, CRect rect, CMFCVisualManager::AFX_BUTTON_STATE state)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	CMFCToolBarMenuButton* pMenuButton = 
		DYNAMIC_DOWNCAST(CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuBarButton = pMenuButton != NULL &&
		pMenuButton->GetParentWnd() != NULL &&
		pMenuButton->GetParentWnd()->IsKindOf(RUNTIME_CLASS(CMFCMenuBar));

	if (bIsMenuBarButton)
	{
		rect.bottom -= 2;
	}

	if (!bIsMenuBarButton || !pMenuButton->IsDroppedDown())
	{
		CMFCVisualManagerVS2005::OnFillButtonInterior(pDC, pButton, rect, state);
		return;
	}

	if (!m_bOSColors)
	{
		OnFillHighlightedArea(pDC, rect, &m_brBarBkgnd, pButton);
		return;
	}

	COLORREF clr1 = CDrawingManager::PixelAlpha(m_clrHighlight, 85);
	COLORREF clr2 = RGB(255, 255, 255);

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, clr1, clr2, TRUE);
}

void CMFCVisualManagerVS2008::OnHighlightMenuItem(CDC *pDC, CMFCToolBarMenuButton* pButton, CRect rect, COLORREF& clrText)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode())
	{
		CMFCVisualManagerVS2005::OnHighlightMenuItem(pDC, pButton, rect, clrText);
		return;
	}

	const int nRoundSize = 3;
	const BOOL bIsWinXPBlue = (GetStandardWindowsTheme() == WinXpTheme_Blue);

	COLORREF clr1 = bIsWinXPBlue ? WINXPBLUE_GRADIENT_DARK : m_clrHighlightGradientDark;
	COLORREF clr2 = bIsWinXPBlue ? WINXPBLUE_GRADIENT_LIGHT : m_clrHighlightGradientLight;
	COLORREF clrBorder = bIsWinXPBlue ? WINXPBLUE_MENUITEM_BORDER : m_clrHighlightGradientDark;

	if (m_bOSColors)
	{
		clr1 = m_clrHighlight;
		clr2 = RGB(255, 255, 255);
		clrBorder = m_clrHighlightDn;
	}

	rect.DeflateRect(2, 0);

	CRgn rgn;
	rgn.CreateRoundRectRgn(rect.left, rect.top, rect.right, rect.bottom, nRoundSize, nRoundSize);

	pDC->SelectClipRgn(&rgn);

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, clr1, clr2, TRUE);

	pDC->SelectClipRgn(NULL);

	CPen pen(PS_SOLID, 1, clrBorder);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush* pOldBrush = (CBrush*) pDC->SelectStockObject(NULL_BRUSH);

	pDC->RoundRect(rect.left, rect.top, rect.right, rect.bottom, nRoundSize + 2, nRoundSize + 2);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	clrText = GetHighlightedMenuItemTextColor(pButton);
}

void CMFCVisualManagerVS2008::OnEraseTabsArea(CDC* pDC, CRect rect, const CMFCBaseTabCtrl* pTabWnd)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pTabWnd);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() ||
		!pTabWnd->IsVS2005Style() ||
		pTabWnd->IsDialogControl())
	{
		CMFCVisualManagerVS2005::OnEraseTabsArea(pDC, rect, pTabWnd);
		return;
	}

	CFrameWnd* pMainFrame = AFXGetTopLevelFrame(pTabWnd);
	if (pMainFrame->GetSafeHwnd() != NULL)
	{
		CRect rectMain;
		pMainFrame->GetClientRect(rectMain);
		pMainFrame->MapWindowPoints((CMFCTabCtrl*)pTabWnd, &rectMain);

		rect.top = rectMain.top;
		rect.left = rectMain.left;
		rect.right = rect.left + GetGlobalData()->m_rectVirtual.Width() + 10;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, m_clrBarGradientDark, m_clrBarGradientLight, FALSE, 0);
}

void CMFCVisualManagerVS2008::OnEraseTabsButton(CDC* pDC, CRect rect, CMFCButton* pButton, CMFCBaseTabCtrl* pWndTab)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);
	ASSERT_VALID(pWndTab);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() ||
		!pWndTab->IsVS2005Style() ||
		pWndTab->IsDialogControl() ||
		pButton->IsPressed() || pButton->IsHighlighted())
	{
		CMFCVisualManagerVS2005::OnEraseTabsButton(pDC, rect, pButton, pWndTab);
		return;
	}

	CRgn rgn;
	rgn.CreateRectRgnIndirect(rect);

	pDC->SelectClipRgn(&rgn);

	CFrameWnd* pMainFrame = AFXGetTopLevelFrame(pButton);
	if (pMainFrame->GetSafeHwnd() != NULL)
	{
		CRect rectMain;
		pMainFrame->GetClientRect(rectMain);
		pMainFrame->MapWindowPoints(pButton, &rectMain);

		rect.top = rectMain.top;
		rect.left = rectMain.left;
		rect.right = rect.left + GetGlobalData()->m_rectVirtual.Width() + 10;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, m_clrBarGradientDark, m_clrBarGradientLight, FALSE, 0);

	pDC->SelectClipRgn(NULL);
}

BOOL CMFCVisualManagerVS2008::OnEraseTabsFrame(CDC* pDC, CRect rect, const CMFCBaseTabCtrl* pTabWnd)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pTabWnd);

	if (!pTabWnd->IsVS2005Style() || GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode())
	{
		return CMFCVisualManagerVS2005::OnEraseTabsFrame(pDC, rect, pTabWnd);
	}

	COLORREF clrActiveTab = pTabWnd->GetTabBkColor(pTabWnd->GetActiveTab());
	if (clrActiveTab == (COLORREF)-1)
	{
		clrActiveTab = m_clrHighlight;
	}

	CBrush brFill(clrActiveTab);
	pDC->FillRect(rect, &brFill);

	return TRUE;
}

void CMFCVisualManagerVS2008::OnDrawTab(CDC* pDC, CRect rectTab, int iTab, BOOL bIsActive, const CMFCBaseTabCtrl* pTabWnd)
{
	ASSERT_VALID(pTabWnd);
	ASSERT_VALID(pDC);

	const COLORREF clrTab = pTabWnd->GetTabBkColor(iTab);
	const BOOL bIsHighlight = (iTab == pTabWnd->GetHighlightedTab());

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() ||
		pTabWnd->IsDialogControl() ||
		pTabWnd->IsFlatTab() || 
		clrTab != (COLORREF)-1)
	{
		CMFCVisualManagerVS2005::OnDrawTab(pDC, rectTab, iTab, bIsActive, pTabWnd);
		return;
	}

	if ((bIsActive || bIsHighlight || m_bOSColors) && pTabWnd->IsVS2005Style())
	{
		((CMFCBaseTabCtrl*)pTabWnd)->SetTabBkColor(iTab, 
			bIsActive ? m_clrHighlight : 
			bIsHighlight ? m_clrHighlightDnGradientDark : GetThemeColor(m_hThemeButton, 2));

		CMFCVisualManagerVS2005::OnDrawTab(pDC, rectTab, iTab, bIsActive, pTabWnd);

		((CMFCBaseTabCtrl*)pTabWnd)->SetTabBkColor(iTab, clrTab);
		return;
	}

	if (m_hThemeTab == NULL ||
		pTabWnd->IsOneNoteStyle() || pTabWnd->IsVS2005Style() ||
		pTabWnd->IsLeftRightRounded())
	{
		CRect rectClip = rectTab;
		rectClip.bottom -= 2;

		CRgn rgn;
		rgn.CreateRectRgnIndirect(&rectClip);

		pDC->SelectClipRgn(&rgn);

		CMFCVisualManagerVS2005::OnDrawTab(pDC, rectTab, iTab, bIsActive, pTabWnd);
		
		pDC->SelectClipRgn(NULL);
		return;
	}

	int nState = TIS_NORMAL;
	if (bIsActive)
	{
		nState = TIS_SELECTED;
	}
	else if (iTab == pTabWnd->GetHighlightedTab())
	{
		nState = TIS_HOT;
	}

	rectTab.right += 2;

	if (!bIsActive)
	{
		rectTab.bottom--;
	}

	if (rectTab.Width() > 25)	// DrawThemeBackground will draw < 25 width tab bad
	{
		DrawThemeBackground(m_hThemeTab, pDC->GetSafeHdc(), TABP_TABITEM, nState, &rectTab, 0);

		if (pTabWnd->GetLocation() == CMFCBaseTabCtrl::LOCATION_BOTTOM)
		{
			CDrawingManager dm(*pDC);
			dm.MirrorRect(rectTab, FALSE);
		}
	}

	COLORREF clrTabText = GetGlobalData()->clrWindowText;

	if (!bIsActive)
	{
		clrTabText = GetGlobalData()->clrBtnDkShadow;
	}
	else
	{
		::GetThemeColor(m_hThemeTab, TABP_TABITEM, nState, TMT_TEXTCOLOR, &clrTabText);
	}

	COLORREF cltTextOld = pDC->SetTextColor(clrTabText);

	rectTab.right -= 2;

	OnDrawTabContent(pDC, rectTab, iTab, bIsActive, pTabWnd,(COLORREF)-1);

	pDC->SetTextColor(cltTextOld);
}

void CMFCVisualManagerVS2008::OnDrawAutoHideButtonBorder(CDC* pDC, CRect rect, CRect rectBorderSize, CMFCAutoHideButton* pButton)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() || m_hThemeTab == NULL)
	{
		CMFCVisualManagerVS2005::OnDrawAutoHideButtonBorder(pDC, rect, rectBorderSize, pButton);
		return;
	}

	const int nState = pButton->IsHighlighted() ? TIS_HOT : TIS_NORMAL;
	const DWORD dwAlign = (pButton->GetAlignment()) & CBRS_ALIGN_ANY;

	CDrawingManager dm(*pDC);

	switch(dwAlign)
	{
	case CBRS_ALIGN_LEFT:
	case CBRS_ALIGN_RIGHT:
		{
			CRect rectTab(0, 0, rect.Height(), rect.Width());

			CDC dcMem;
			dcMem.CreateCompatibleDC(pDC);

			CBitmap bmpMem;
			bmpMem.CreateCompatibleBitmap(pDC, rectTab.Width(), rectTab.Height());

			CBitmap* pBmpOld = (CBitmap*) dcMem.SelectObject(&bmpMem);

			DrawThemeBackground(m_hThemeTab, dcMem.GetSafeHdc(), TABP_TABITEM, nState, &rectTab, 0);

			dm.DrawRotated(rect, dcMem, dwAlign == CBRS_ALIGN_LEFT);
			dcMem.SelectObject(pBmpOld);
		}
		break;

	case CBRS_ALIGN_TOP:
	case CBRS_ALIGN_BOTTOM:
		DrawThemeBackground(m_hThemeTab, pDC->GetSafeHdc(), TABP_TABITEM, nState, &rect, 0);

		if (dwAlign == CBRS_ALIGN_TOP)
		{
			dm.MirrorRect(rect, FALSE);
			break;
		}
	}
}

COLORREF CMFCVisualManagerVS2008::OnDrawPaneCaption(CDC* pDC, CDockablePane* pBar, BOOL bActive, CRect rectCaption, CRect rectButtons)
{
	ASSERT_VALID(pDC);

	if (!m_bOSColors)
	{
		return CMFCVisualManagerVS2005::OnDrawPaneCaption(pDC, pBar, bActive, rectCaption, rectButtons);
	}

	rectCaption.bottom++;

	CDrawingManager dm(*pDC);
	dm.FillGradient(rectCaption, 
		bActive ? GetGlobalData()->clrActiveCaptionGradient : GetGlobalData()->clrInactiveCaptionGradient, 
		bActive ? GetGlobalData()->clrActiveCaption : GetGlobalData()->clrInactiveCaption, 
		TRUE);

	return bActive ? GetGlobalData()->clrCaptionText : GetGlobalData()->clrInactiveCaptionText;
}

void CMFCVisualManagerVS2008::OnUpdateSystemColors()
{
	m_bOSColors = m_hThemeExplorerBar != NULL &&
		GetGlobalData()->m_nBitsPerPixel > 8 && !GetGlobalData()->IsHighContrastMode();

	CMFCVisualManagerVS2005::OnUpdateSystemColors();

	if (!m_bOSColors)
	{
		return;
	}

	::GetThemeColor(m_hThemeExplorerBar, 0, 0, TMT_EDGEHIGHLIGHTCOLOR, &m_clrToolBarGradientLight);
	::GetThemeColor(m_hThemeExplorerBar, 0, 0, TMT_GRADIENTCOLOR2, &m_clrToolBarGradientDark);

	m_clrBarGradientDark = CDrawingManager::SmartMixColors(m_clrToolBarGradientDark, m_clrToolBarGradientLight,
		1., 2, 1);

	m_clrBarGradientLight = m_clrToolBarGradientLight;

	m_clrToolBarGradientVertLight = m_clrToolBarGradientLight;

	m_clrToolBarGradientVertDark = CDrawingManager::PixelAlpha(
			m_clrToolBarGradientDark, 98);

	// Calculate highlight gradient colors:
	m_clrCustomizeButtonGradientLight = m_clrToolBarGradientDark;
	m_clrCustomizeButtonGradientDark = m_clrBarGradientDark;

	m_clrToolBarBottomLine = CDrawingManager::PixelAlpha(m_clrToolBarGradientDark, 85);
	m_colorToolBarCornerBottom = m_clrToolBarGradientDark;

	m_brTabBack.DeleteObject();
	m_brTabBack.CreateSolidBrush(m_clrToolBarGradientLight);

	m_brFace.DeleteObject();
	m_brFace.CreateSolidBrush(m_clrToolBarGradientLight);

	m_clrToolbarDisabled = CDrawingManager::SmartMixColors(
		m_clrToolBarGradientDark, m_clrToolBarGradientLight, .92);

	m_penBottomLine.DeleteObject();
	m_penBottomLine.CreatePen(PS_SOLID, 1, m_clrToolBarBottomLine);
}

COLORREF CMFCVisualManagerVS2008::OnFillCommandsListBackground(CDC* pDC, CRect rect, BOOL bIsSelected)
{
	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode())
	{
		return CMFCVisualManagerVS2005::OnFillCommandsListBackground(pDC, rect, bIsSelected);
	}

	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	rect.left = 0;

	const BOOL bIsWinXPBlue = (GetStandardWindowsTheme() == WinXpTheme_Blue) || m_bOSColors;

	if (bIsSelected)
	{
		COLORREF clr1 = bIsWinXPBlue ? WINXPBLUE_GRADIENT_DARK : m_clrHighlightGradientDark;
		COLORREF clr2 = bIsWinXPBlue ? WINXPBLUE_GRADIENT_LIGHT : m_clrHighlightGradientLight;
		COLORREF clrBorder = bIsWinXPBlue ? WINXPBLUE_MENUITEM_BORDER : m_clrHighlightGradientDark;

		if (m_bOSColors)
		{
			clr1 = m_clrHighlight;
			clr2 = RGB(255, 255, 255);
			clrBorder = m_clrHighlightDn;
		}

		CDrawingManager dm(*pDC);
		dm.FillGradient(rect, clr1, clr2, TRUE);

		pDC->Draw3dRect(rect, clrBorder, clrBorder);

		CMFCToolBarMenuButton dummy;
		return GetHighlightedMenuItemTextColor(&dummy);
	}
	else
	{
		pDC->FillRect(rect, &m_brMenuLight);

		int iImageWidth = CMFCToolBar::GetMenuImageSize().cx + GetMenuImageMargin();

		CRect rectImages = rect;
		rectImages.right = rectImages.left + iImageWidth + AFX_MENU_IMAGE_MARGIN;

		if (bIsWinXPBlue)
		{
			CBrush br(WINXPBLUE_MENU_GUTTER);
			pDC->FillRect(rectImages, &br);

			CPen* pOldPen = pDC->SelectObject(&m_penSeparator);
			ASSERT(pOldPen != NULL);

			pDC->MoveTo(rectImages.right, rectImages.top);
			pDC->LineTo(rectImages.right, rectImages.bottom);

			pDC->SelectObject(pOldPen);
		}
		else
		{
			CDrawingManager dm(*pDC);
			dm.FillGradient(rectImages, m_clrToolBarGradientLight, m_clrToolBarGradientDark, FALSE);
		}

		return GetGlobalData()->clrBarText;
	}
}

void CMFCVisualManagerVS2008::GetTabFrameColors(const CMFCBaseTabCtrl* pTabWnd, COLORREF& clrDark, COLORREF& clrBlack, COLORREF& clrHighlight,
		COLORREF& clrFace, COLORREF& clrDarkShadow, COLORREF& clrLight, CBrush*& pbrFace, CBrush*& pbrBlack)
{
	ASSERT_VALID(pTabWnd);
	
	CMFCVisualManagerVS2005::GetTabFrameColors(pTabWnd,
			   clrDark, clrBlack,
			   clrHighlight, clrFace,
			   clrDarkShadow, clrLight,
			   pbrFace, pbrBlack);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() || pTabWnd->IsFlatTab())
	{
		return;
	}

	clrBlack = GetGlobalData()->clrBarShadow;
}

void CMFCVisualManagerVS2008::OnDrawTabResizeBar(CDC* pDC, CMFCBaseTabCtrl* pWndTab, BOOL bIsVert, CRect rect, CBrush* pbrFace, CPen* pPen)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pbrFace);
	ASSERT_VALID(pPen);
	ASSERT_VALID(pWndTab);

	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode() || pWndTab->IsFlatTab())
	{
		CMFCVisualManagerVS2005::OnDrawTabResizeBar(pDC, pWndTab, bIsVert, rect, pbrFace, pPen);
		return;
	}

	CRgn rgn;
	rgn.CreateRectRgnIndirect(rect);

	pDC->SelectClipRgn(&rgn);

	CFrameWnd* pMainFrame = AFXGetTopLevelFrame(pWndTab);
	if (pMainFrame->GetSafeHwnd() != NULL)
	{
		CRect rectMain;
		pMainFrame->GetClientRect(rectMain);
		pMainFrame->MapWindowPoints(pWndTab, &rectMain);

		rect.top = rectMain.top;
		rect.left = rectMain.left;
		rect.right = rect.left + GetGlobalData()->m_rectVirtual.Width() + 10;
	}

	CDrawingManager dm(*pDC);
	dm.FillGradient(rect, m_clrBarGradientDark, m_clrBarGradientLight, FALSE, 0);

	pDC->SelectClipRgn(NULL);
}

AFX_SMARTDOCK_THEME CMFCVisualManagerVS2008::GetSmartDockingTheme()
{
	if (GetGlobalData()->m_nBitsPerPixel <= 8 || GetGlobalData()->IsHighContrastMode())
	{
		return CMFCVisualManagerVS2005::GetSmartDockingTheme();
	}

	return AFX_SDT_VS2008;
}
