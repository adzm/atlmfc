// This MFC Library source code supports the Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "afxcontrolbarutil.h"
#include "afxglobalutils.h"
#include "afxvisualmanagerwindows7.h"
#include "afxtoolbar.h"
#include "afxdrawmanager.h"
#include "afxpopupmenubar.h"
#include "afxmenubar.h"
#include "afxglobals.h"
#include "afxtoolbarmenubutton.h"
#include "afxcustomizebutton.h"
#include "afxmenuimages.h"
#include "afxcaptionbar.h"
#include "afxbasetabctrl.h"
#include "afxcolorbar.h"
#include "afxtabctrl.h"
#include "afxtaskspane.h"
#include "afxstatusbar.h"
#include "afxautohidebutton.h"
#include "afxheaderctrl.h"
#include "afxrebar.h"
#include "afxdesktopalertwnd.h"
#include "afxdropdowntoolbar.h"
#include "afxtagmanager.h"
#include "afxframewndex.h"
#include "afxmdiframewndex.h"
#include "afxdockablepane.h"
#include "afxoutlookbartabctrl.h"
#include "afxtoolbarcomboboxbutton.h"

#include "afxribbonbar.h"
#include "afxribbonpanel.h"
#include "afxribboncategory.h"
#include "afxribbonbutton.h"
#include "afxribbonquickaccesstoolbar.h"
#include "afxribboncombobox.h"
#include "afxribbonmainpanel.h"
#include "afxribbonpanelmenu.h"
#include "afxribbonlabel.h"
#include "afxribbonpalettegallery.h"
#include "afxribbonstatusbar.h"
#include "afxribbonstatusbarpane.h"
#include "afxribbonprogressbar.h"
#include "afxribbonlinkctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define AFX_RT_STYLE_XML _T("STYLE_XML")

CString	CMFCVisualManagerWindows7::m_strStylePrefix;
HINSTANCE CMFCVisualManagerWindows7::m_hinstRes = NULL;
BOOL CMFCVisualManagerWindows7::m_bAutoFreeRes = FALSE;

IMPLEMENT_DYNCREATE(CMFCVisualManagerWindows7, CMFCVisualManagerWindows)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCVisualManagerWindows7::CMFCVisualManagerWindows7()
: m_bLoaded(FALSE)
{
}

CMFCVisualManagerWindows7::~CMFCVisualManagerWindows7()
{
}


CString __stdcall CMFCVisualManagerWindows7::MakeResourceID(LPCTSTR lpszID)
{
	CString strResID(lpszID);
	ASSERT(!strResID.IsEmpty());

	if (!m_strStylePrefix.IsEmpty())
	{
		strResID = m_strStylePrefix + strResID;
	}

	return strResID;
}

CString __stdcall CMFCVisualManagerWindows7::GetStyleResourceID()
{
	return _T("WINDOWS7_IDX_STYLE");
}

void __stdcall CMFCVisualManagerWindows7::SetResourceHandle(HINSTANCE hinstRes)
{
	m_bAutoFreeRes = FALSE;

	if (m_hinstRes != hinstRes)
	{
		m_hinstRes = hinstRes;

		if (CMFCVisualManager::GetInstance()->IsKindOf(RUNTIME_CLASS(CMFCVisualManagerWindows7)))
		{
			CMFCVisualManager::GetInstance()->OnUpdateSystemColors();
		}
	}
}

BOOL __stdcall CMFCVisualManagerWindows7::SetStyle(LPCTSTR lpszPath)
{
	if (m_hinstRes >(HINSTANCE) 32)
	{
		return TRUE;
	}

	UNREFERENCED_PARAMETER(lpszPath);
	CString strStyle(GetStyleResourceID());
	HINSTANCE hinstRes = AfxFindResourceHandle(strStyle, AFX_RT_STYLE_XML);

	if (::FindResource(hinstRes, strStyle, AFX_RT_STYLE_XML) == NULL)
	{
		TRACE(_T("Cannot load Style: %s\r\n"), strStyle);
		ASSERT(FALSE);
		return FALSE;
	}

	CleanStyle();
	SetResourceHandle(hinstRes);

	return TRUE;
}

void __stdcall CMFCVisualManagerWindows7::CleanStyle()
{
	if (m_bAutoFreeRes && m_hinstRes > (HINSTANCE)32)
	{
		::FreeLibrary(m_hinstRes);
	}

	m_hinstRes = NULL;
	m_strStylePrefix.Empty();
}

BOOL CMFCVisualManagerWindows7::IsOwnerDrawMenuCheck()
{
	return CanDrawImage() ? FALSE : CMFCVisualManagerWindows::IsOwnerDrawMenuCheck();
}

BOOL CMFCVisualManagerWindows7::IsHighlightWholeMenuItem()
{
	return CanDrawImage() ? TRUE : CMFCVisualManagerWindows::IsHighlightWholeMenuItem();
}

void CMFCVisualManagerWindows7::DrawSeparator(CDC* pDC, const CRect& rect, CPen& pen1, CPen& pen2, BOOL bHorz)
{
	CRect rect1(rect);
	CRect rect2;

	if (bHorz)
	{
		rect1.top += rect.Height() / 2 - 1;
		rect1.bottom = rect1.top;
		rect2 = rect1;
		rect2.OffsetRect(0, 1);
	}
	else
	{
		rect1.left += rect.Width() / 2 - 1;
		rect1.right = rect1.left;
		rect2 = rect1;
		rect2.OffsetRect(1, 0);
	}

	if (CMFCToolBarImages::m_bIsDrawOnGlass)
	{
		CDrawingManager dm(*pDC);

		LOGPEN logpen;

		pen1.GetLogPen(&logpen);
		dm.DrawLine(rect1.left, rect1.top, rect1.right, rect1.bottom, logpen.lopnColor);

		pen2.GetLogPen(&logpen);
		dm.DrawLine(rect2.left, rect2.top, rect2.right, rect2.bottom, logpen.lopnColor);
	}
	else
	{
		CPen* pOldPen = pDC->SelectObject(&pen1);
		pDC->MoveTo(rect1.TopLeft());
		pDC->LineTo(rect1.BottomRight());

		pDC->SelectObject(&pen2);
		pDC->MoveTo(rect2.TopLeft());
		pDC->LineTo(rect2.BottomRight());

		pDC->SelectObject(pOldPen);
	}
}

void CMFCVisualManagerWindows7::DrawNcBtn(CDC* pDC, const CRect& rect, UINT nButton, AFX_BUTTON_STATE state, BOOL bSmall, BOOL bActive, BOOL bMDI/* = FALSE*/)
{
	ASSERT_VALID(pDC);

	if (m_hThemeWindow == NULL)
	{
		UINT nState = 0;

		switch (nButton)
		{
		case SC_CLOSE:
			nState = DFCS_CAPTIONCLOSE;
			break;

		case SC_MINIMIZE:
			nState = DFCS_CAPTIONMIN;
			break;

		case SC_MAXIMIZE:
			nState = DFCS_CAPTIONMAX;
			break;

		case SC_RESTORE:
			nState = DFCS_CAPTIONRESTORE;
			break;

		case SC_CONTEXTHELP:
			nState = DFCS_CAPTIONHELP;
			break;

		default:
			return;
		}

		if (!bActive)
		{
			nState |= DFCS_INACTIVE;
		}

		if (state != ButtonsIsRegular)
		{
			nState |= state == ButtonsIsHighlighted ? DFCS_HOT : DFCS_PUSHED;
		}

		CRect rt(rect);
		pDC->DrawFrameControl(rt, DFC_CAPTION, nState);
		return;
	}

	int nPart = 0;
	int nState = 0;
	if (nButton == SC_CLOSE)
	{
		if (bMDI)
		{
			nPart = WP_MDICLOSEBUTTON;
		}
		else
		{
			nPart = bSmall ? WP_SMALLCLOSEBUTTON : WP_CLOSEBUTTON;
		}

		nState = bActive ? CBS_NORMAL : CBS_DISABLED;
		if (state != ButtonsIsRegular)
		{
			nState = state == ButtonsIsHighlighted ? CBS_HOT : CBS_PUSHED;
		}
	}
	else if (nButton == SC_MINIMIZE)
	{
		if (bMDI)
		{
			nPart = WP_MDIMINBUTTON;
		}
		else if (!bSmall)
		{
			nPart = WP_MINBUTTON;
		}

		nState = bActive ? MINBS_NORMAL : MINBS_DISABLED;
		if (state != ButtonsIsRegular)
		{
			nState = state == ButtonsIsHighlighted ? MINBS_HOT : MINBS_PUSHED;
		}
	}
	else if (nButton == SC_MAXIMIZE)
	{
		if (!bMDI && !bSmall)
		{
			nPart = WP_MAXBUTTON;
		}

		nState = bActive ? MAXBS_NORMAL : MAXBS_DISABLED;
		if (state != ButtonsIsRegular)
		{
			nState = state == ButtonsIsHighlighted ? MAXBS_HOT : MAXBS_PUSHED;
		}
	}
	else if (nButton == SC_RESTORE)
	{
		if (bMDI)
		{
			nPart = WP_MDIRESTOREBUTTON;
		}
		else
		{
			nPart = WP_RESTOREBUTTON;
		}

		nState = bActive ? RBS_NORMAL : RBS_DISABLED;
		if (state != ButtonsIsRegular)
		{
			nState = state == ButtonsIsHighlighted ? RBS_HOT : RBS_PUSHED;
		}
	}
	else if (nButton == SC_CONTEXTHELP)
	{
		if (bMDI)
		{
			nPart = WP_MDIHELPBUTTON;
		}
		else if (!bSmall)
		{
			nPart = WP_HELPBUTTON;
		}

		nState = bActive ? HBS_NORMAL : HBS_DISABLED;
		if (state != ButtonsIsRegular)
		{
			nState = state == ButtonsIsHighlighted ? HBS_HOT : HBS_PUSHED;
		}
	}

	if (nPart == 0)
	{
		return;
	}

	DrawThemeBackground(m_hThemeWindow, pDC->GetSafeHdc(), nPart, nState, &rect, 0);
}

void CMFCVisualManagerWindows7::DrawNcText(CDC* pDC, CRect& rect, const CString& strTitle, BOOL bActive, BOOL bIsRTL, BOOL bTextCenter, BOOL bGlass/* = FALSE*/, int nGlassGlowSize/* = 0*/, COLORREF clrGlassText/* = (COLORREF)-1*/)
{
	if (strTitle.IsEmpty() || rect.right <= rect.left)
	{
		return;
	}

	ASSERT_VALID(pDC);

	int nOldMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF clrOldText = pDC->GetTextColor();

	DWORD dwTextStyle = DT_END_ELLIPSIS | DT_SINGLELINE | DT_VCENTER | (bIsRTL ? DT_RTLREADING : 0);

	COLORREF clrText = bActive 
		? GetGlobalData()->clrCaptionText
		: GetGlobalData()->clrInactiveCaptionText;

	int widthFull = rect.Width();
	int width = pDC->GetTextExtent(strTitle).cx;

	if (bTextCenter && width < widthFull)
	{
		rect.left += (widthFull - width) / 2;
	}

	rect.right = min(rect.left + width, rect.right);

	if (rect.right > rect.left)
	{
		if (bGlass)
		{
			DrawTextOnGlass(pDC, strTitle, rect, dwTextStyle, nGlassGlowSize, clrGlassText);
		}
		else
		{
			pDC->SetTextColor(clrText);
			pDC->DrawText(strTitle, rect, dwTextStyle);
		}
	}

	pDC->SetBkMode(nOldMode);
	pDC->SetTextColor(clrOldText);
}

void CMFCVisualManagerWindows7::CleanUp()
{
	m_AppCaptionFont.DeleteObject();
	m_penSeparatorDark.DeleteObject();
	m_penSeparatorLight.DeleteObject();

	m_brRibbonBarBkgnd.DeleteObject();

	m_ctrlMenuItemBack.CleanUp();
    m_MenuItemMarkerC.Clear();
    m_MenuItemMarkerR.Clear();
	m_ctrlMenuHighlighted[0].CleanUp();
	m_ctrlMenuHighlighted[1].CleanUp();

	m_ctrlRibbonComboBoxBtn.CleanUp();

	m_ctrlRibbonCaptionQA.CleanUp();
	m_ctrlRibbonCategoryBack.CleanUp();
	m_ctrlRibbonCategoryTab.CleanUp();
	m_ctrlRibbonCategoryTabSep.CleanUp();
	m_ctrlRibbonCategoryBtnPage[0].CleanUp();
	m_ctrlRibbonCategoryBtnPage[1].CleanUp();
	m_ctrlRibbonPanelBack.CleanUp();
	m_ctrlRibbonPanelBackSep.CleanUp();
	m_ctrlRibbonMainPanel.CleanUp();
	m_ctrlRibbonBtnMainPanel.CleanUp();
	m_ctrlRibbonBtnGroup_S.CleanUp();
	m_ctrlRibbonBtnGroup_F.CleanUp();
	m_ctrlRibbonBtnGroup_M.CleanUp();
	m_ctrlRibbonBtnGroup_L.CleanUp();
	m_ctrlRibbonBtnGroupMenu_F[0].CleanUp();
	m_ctrlRibbonBtnGroupMenu_F[1].CleanUp();
	m_ctrlRibbonBtnGroupMenu_M[0].CleanUp();
	m_ctrlRibbonBtnGroupMenu_M[1].CleanUp();
	m_ctrlRibbonBtnGroupMenu_L[0].CleanUp();
	m_ctrlRibbonBtnGroupMenu_L[1].CleanUp();
	m_ctrlRibbonBtn[0].CleanUp();
	m_ctrlRibbonBtn[1].CleanUp();
	m_ctrlRibbonBtnMenuH[0].CleanUp();
	m_ctrlRibbonBtnMenuH[1].CleanUp();
	m_ctrlRibbonBtnMenuV[0].CleanUp();
	m_ctrlRibbonBtnMenuV[1].CleanUp();
	m_ctrlRibbonBtnLaunch.CleanUp();
	m_RibbonBtnLaunchIcon.Clear();
	m_ctrlRibbonBtnMain.CleanUp();
	m_ctrlRibbonSliderBtnPlus.CleanUp();
	m_ctrlRibbonSliderBtnMinus.CleanUp();
	m_RibbonBtnDefaultImage.Clear ();
	m_ctrlRibbonBtnDefault.CleanUp();
	m_ctrlRibbonBtnDefaultIcon.CleanUp();
	m_ctrlRibbonBtnDefaultQAT.CleanUp();
	m_ctrlRibbonBtnStatusPane.CleanUp();
	m_ctrlRibbonBtnPalette[0].CleanUp();
	m_ctrlRibbonBtnPalette[1].CleanUp();
	m_ctrlRibbonBtnPalette[2].CleanUp();

	m_ctrlRibbonBorder_QAT.CleanUp();
	m_ctrlRibbonBorder_Panel.CleanUp();

	m_ctrlRibbonContextSeparator.CleanUp();
	for (int i = 0; i < AFX_RIBBON_CATEGORY_COLOR_COUNT; i++)
	{
		m_ctrlRibbonContextCategory[i].CleanUp();
	}

	m_cacheRibbonCategoryBack.Clear();
	m_cacheRibbonPanelBack.Clear();
	m_cacheRibbonBtnGroup_S.Clear();
	m_cacheRibbonBtnGroup_F.Clear();
	m_cacheRibbonBtnGroup_M.Clear();
	m_cacheRibbonBtnGroup_L.Clear();
	m_cacheRibbonBtnGroupMenu_F[0].Clear();
	m_cacheRibbonBtnGroupMenu_M[0].Clear();
	m_cacheRibbonBtnGroupMenu_L[0].Clear();
	m_cacheRibbonBtnGroupMenu_F[1].Clear();
	m_cacheRibbonBtnGroupMenu_M[1].Clear();
	m_cacheRibbonBtnGroupMenu_L[1].Clear();
	m_cacheRibbonBtnDefault.Clear();

	m_ActivateFlag.RemoveAll();

	m_bLoaded = FALSE;
}

void CMFCVisualManagerWindows7::OnUpdateSystemColors()
{
	HINSTANCE hinstResOld = NULL;

	if (m_hinstRes == NULL)
	{
		SetStyle();
		return;
	}

	if (m_hinstRes != NULL)
	{
		hinstResOld = AfxGetResourceHandle();
		AfxSetResourceHandle(m_hinstRes);
	}

	CleanUp();

	CMFCVisualManagerWindows::OnUpdateSystemColors();

	m_nMenuBorderSize = 1;

	CTagManager tm;

	if (!tm.LoadFromResource(GetStyleResourceID(), AFX_RT_STYLE_XML))
	{
#if !defined _AFXDLL
		TRACE(_T("\r\nImportant: to enable the Windows7 look in static link,\r\n"));
		TRACE(_T("include afxribbon.rc from the RC file in your project.\r\n\r\n"));
		ASSERT(FALSE);
#endif
		if (hinstResOld != NULL)
		{
			AfxSetResourceHandle(hinstResOld);
		}

		return;
	}

	{
		CString strStyle;
		tm.ExcludeTag(_T("STYLE"), strStyle);
		tm.SetBuffer(strStyle);
	}

	CString strItem;

	if (!tm.IsEmpty())
	{
		int nVersion = 0;

		if (tm.ExcludeTag(_T("VERSION"), strItem))
		{
			CTagManager tmItem(strItem);

			tmItem.ReadInt(_T("NUMBER"), nVersion);

			int nType = 20;
			if (nVersion == 2007)
			{
				tmItem.ReadInt(_T("TYPE"), nType);

				m_bLoaded = TRUE;
			}

			if (m_bLoaded)
			{
				if (tmItem.ExcludeTag(_T("ID_PREFIX"), strItem))
				{
					strItem.TrimLeft();
					strItem.TrimRight();
					m_strStylePrefix = strItem;
				}
			}
		}
	}

	if (!m_bLoaded)
	{
		if (hinstResOld != NULL)
		{
			::AfxSetResourceHandle(hinstResOld);
		}

		return;
	}

	// menu
	if (tm.ExcludeTag(_T("MENU"), strItem))
	{
		CTagManager tmItem(strItem);

		tmItem.ReadInt(_T("BorderSize"), m_nMenuBorderSize);

		tmItem.ReadControlRenderer(_T("ItemBack"), m_ctrlMenuItemBack, MakeResourceID(_T("IDB_MENU_ITEM_BACK")));
		tmItem.ReadToolBarImages (_T("ItemCheck"), m_MenuItemMarkerC, MakeResourceID(_T("IDB_MENU_ITEM_MARKER_C")));
		tmItem.ReadToolBarImages (_T("ItemRadio"), m_MenuItemMarkerR, MakeResourceID(_T("IDB_MENU_ITEM_MARKER_R")));
		tmItem.ReadControlRenderer(_T("Highlighted"), m_ctrlMenuHighlighted[0], MakeResourceID(_T("IDB_MENU_BTN")));
		tmItem.ReadControlRenderer(_T("HighlightedDisabled"), m_ctrlMenuHighlighted[1], MakeResourceID(_T("IDB_MENU_BTN_DISABLED")));
	}

	m_brMenuRarelyUsed.DeleteObject();
	m_brMenuRarelyUsed.CreateSolidBrush(m_clrMenuRarelyUsed);

	m_clrRibbonEdit            = GetGlobalData()->clrWindow;
	m_clrRibbonEditHighlighted = GetGlobalData()->clrWindow;
	m_clrRibbonEditPressed     = m_clrRibbonEditHighlighted;
	m_clrRibbonEditDisabled    = GetGlobalData()->clrBtnFace;

	m_clrRibbonEditBorder            = GetGlobalData()->clrWindow;
	m_clrRibbonEditBorderDisabled    = GetGlobalData()->clrBtnShadow;
	m_clrRibbonEditBorderHighlighted = m_clrMenuItemBorder;
	m_clrRibbonEditBorderPressed     = m_clrRibbonEditBorderHighlighted;
	m_clrRibbonEditSelection         = GetGlobalData()->clrHilite;

	m_clrRibbonBarBkgnd         = GetGlobalData()->clrBarFace;
	m_clrRibbonBarGradientLight = GetGlobalData()->clrBarLight;
	m_clrRibbonBarGradientDark  = m_clrRibbonBarGradientLight;

	// bars
	if (tm.ExcludeTag(_T("BARS"), strItem))
	{
		CTagManager tmItem(strItem);

		CString strBar;
		if (tmItem.ExcludeTag(_T("RIBBONBAR"), strBar))
		{
			CTagManager tmBar(strBar);

			tmBar.ReadColor(_T("Bkgnd"), m_clrRibbonBarBkgnd);
			tmBar.ReadColor(_T("GradientLight"), m_clrRibbonBarGradientLight);
			m_clrRibbonBarGradientDark = m_clrRibbonBarGradientLight;
			tmBar.ReadColor(_T("GradientDark"), m_clrRibbonBarGradientDark);
		}
	}

	m_brRibbonBarBkgnd.DeleteObject ();
	m_brRibbonBarBkgnd.CreateSolidBrush  (m_clrRibbonBarBkgnd);

	m_clrRibbonCategoryText            = GetGlobalData()->clrBarText;
	m_clrRibbonCategoryTextHighlighted = GetGlobalData()->clrBarText;
	m_clrRibbonCategoryTextDisabled    = GetGlobalData()->clrBarText;

	if (tm.ExcludeTag(_T("RIBBON"), strItem))
	{
		CTagManager tmItem(strItem);

		CString str;

		if (tmItem.ExcludeTag(_T("CATEGORY"), str))
		{
			CTagManager tmCategory(str);
			tmCategory.ReadControlRenderer(_T("BACK"), m_ctrlRibbonCategoryBack, MakeResourceID(_T("IDB_RIBBON_CATEGORY_BACK")));

			CString strTab;
			if (tmCategory.ExcludeTag(_T("TAB"), strTab))
			{
				CTagManager tmTab(strTab);

				tmTab.ReadControlRenderer(_T("BUTTON"), m_ctrlRibbonCategoryTab, MakeResourceID(_T("IDB_RIBBON_CATEGORY_TAB")));
				tmTab.ReadColor (_T("TextNormal"), m_clrRibbonCategoryText);
				tmTab.ReadColor (_T("TextHighlighted"), m_clrRibbonCategoryTextHighlighted);
				tmTab.ReadColor (_T("TextDisabled"), m_clrRibbonCategoryTextDisabled);
			}

			tmCategory.ReadControlRenderer (_T("TAB_SEPARATOR"), m_ctrlRibbonCategoryTabSep, MakeResourceID(_T("IDB_RIBBON_CATEGORY_TAB_SEP")));

			tmCategory.ReadControlRenderer (_T("BUTTON_PAGE_L"), m_ctrlRibbonCategoryBtnPage[0], MakeResourceID(_T("IDB_RIBBON_BTN_PAGE_L")));
			tmCategory.ReadControlRenderer (_T("BUTTON_PAGE_R"), m_ctrlRibbonCategoryBtnPage[1], MakeResourceID(_T("IDB_RIBBON_BTN_PAGE_R")));
		}

		if (tmItem.ExcludeTag(_T("PANEL"), str))
		{
			CTagManager tmPanel(str);

			{
				CString strBack;
				if (tmPanel.ExcludeTag(_T("BACK"), strBack))
				{
					CTagManager tmBack(strBack);

					tmBack.ReadControlRenderer (_T("FULL"), m_ctrlRibbonPanelBack, MakeResourceID(_T("IDB_RIBBON_PANEL_BACK")));
					tmBack.ReadControlRenderer(_T("SEPARATOR"), m_ctrlRibbonPanelBackSep, MakeResourceID(_T("IDB_RIBBON_PANEL_BACK_SEP")));
				}
			}

			{
				CString strCaption;
				if (tmPanel.ExcludeTag(_T("CAPTION"), strCaption))
				{
					CTagManager tmCaption(strCaption);

					tmCaption.ReadControlRenderer(_T("LAUNCH_BTN"), m_ctrlRibbonBtnLaunch, MakeResourceID(_T("IDB_RIBBON_BTN_LAUNCH")));
					tmCaption.ReadToolBarImages(_T("LAUNCH_ICON"), m_RibbonBtnLaunchIcon, MakeResourceID(_T("IDB_RIBBON_BTN_LAUNCH_ICON")));
					tmCaption.ReadColor(_T("TextNormal"), m_clrRibbonPanelCaptionText);
					tmCaption.ReadColor(_T("TextHighlighted"), m_clrRibbonPanelCaptionTextHighlighted);
				}
			}

			{
				CString strButtons;
				if (tmPanel.ExcludeTag(_T("BUTTONS"), strButtons))
				{
					CTagManager tmButtons(strButtons);

					tmButtons.ReadControlRenderer(_T("BUTTON_GROUP_F"), m_ctrlRibbonBtnGroup_F, MakeResourceID(_T("IDB_RIBBON_BTN_GROUP_F")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUP_M"), m_ctrlRibbonBtnGroup_M, MakeResourceID(_T("IDB_RIBBON_BTN_GROUP_M")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUP_L"), m_ctrlRibbonBtnGroup_L, MakeResourceID(_T("IDB_RIBBON_BTN_GROUP_L")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUP_S"), m_ctrlRibbonBtnGroup_S, MakeResourceID(_T("IDB_RIBBON_BTN_GROUP_S")));

					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_F_C"), m_ctrlRibbonBtnGroupMenu_F[0], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_F_C")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_F_M"), m_ctrlRibbonBtnGroupMenu_F[1], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_F_M")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_M_C"), m_ctrlRibbonBtnGroupMenu_M[0], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_M_C")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_M_M"), m_ctrlRibbonBtnGroupMenu_M[1], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_M_M")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_L_C"), m_ctrlRibbonBtnGroupMenu_L[0], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_L_C")));
					tmButtons.ReadControlRenderer(_T("BUTTON_GROUPMENU_L_M"), m_ctrlRibbonBtnGroupMenu_L[1], MakeResourceID(_T("IDB_RIBBON_BTN_GROUPMENU_L_M")));

					tmButtons.ReadControlRenderer(_T("BUTTON_NORMAL_S"), m_ctrlRibbonBtn[0], MakeResourceID(_T("IDB_RIBBON_BTN_NORMAL_S")));
					tmButtons.ReadControlRenderer(_T("BUTTON_NORMAL_B"), m_ctrlRibbonBtn[1], MakeResourceID(_T("IDB_RIBBON_BTN_NORMAL_B")));

					tmButtons.ReadControlRenderer(_T("BUTTON_DEFAULT"), m_ctrlRibbonBtnDefault, MakeResourceID(_T("IDB_RIBBON_BTN_DEFAULT")));
					tmButtons.ReadControlRenderer(_T("BUTTON_DEFAULT_ICON"), m_ctrlRibbonBtnDefaultIcon, MakeResourceID(_T("IDB_RIBBON_BTN_DEFAULT_ICON")));
					tmButtons.ReadToolBarImages(_T("BUTTON_DEFAULT_IMAGE"), m_RibbonBtnDefaultImage, MakeResourceID(_T("IDB_RIBBON_BTN_DEFAULT_IMAGE")));
					tmButtons.ReadControlRenderer(_T("BUTTON_DEFAULT_QAT"), m_ctrlRibbonBtnDefaultQAT, MakeResourceID(_T("IDB_RIBBON_BTN_DEFAULT_QAT")));

					tmButtons.ReadControlRenderer(_T("BUTTON_MENU_H_C"), m_ctrlRibbonBtnMenuH[0], MakeResourceID(_T("IDB_RIBBON_BTN_MENU_H_C")));
					tmButtons.ReadControlRenderer(_T("BUTTON_MENU_H_M"), m_ctrlRibbonBtnMenuH[1], MakeResourceID(_T("IDB_RIBBON_BTN_MENU_H_M")));
					tmButtons.ReadControlRenderer(_T("BUTTON_MENU_V_C"), m_ctrlRibbonBtnMenuV[0], MakeResourceID(_T("IDB_RIBBON_BTN_MENU_V_C")));
					tmButtons.ReadControlRenderer(_T("BUTTON_MENU_V_M"), m_ctrlRibbonBtnMenuV[1], MakeResourceID(_T("IDB_RIBBON_BTN_MENU_V_M")));

					tmButtons.ReadControlRenderer(_T("BUTTON_PNL_T"), m_ctrlRibbonBtnPalette[0], MakeResourceID(_T("IDB_RIBBON_BTN_PALETTE_T")));
					tmButtons.ReadControlRenderer(_T("BUTTON_PNL_M"), m_ctrlRibbonBtnPalette[1], MakeResourceID(_T("IDB_RIBBON_BTN_PALETTE_M")));
					tmButtons.ReadControlRenderer(_T("BUTTON_PNL_B"), m_ctrlRibbonBtnPalette[2], MakeResourceID(_T("IDB_RIBBON_BTN_PALETTE_B")));
				}
			}

			{
				CString strEdit;
				if (tmPanel.ExcludeTag(_T("EDIT"), strEdit))
				{
					CTagManager tmEdit(strEdit);

					tmEdit.ReadColor(_T("Normal"), m_clrRibbonEdit);
					tmEdit.ReadColor(_T("Highlighted"), m_clrRibbonEditHighlighted);
					tmEdit.ReadColor(_T("Disabled"), m_clrRibbonEditDisabled);
					tmEdit.ReadColor(_T("Pressed"), m_clrRibbonEditPressed);

					tmEdit.ReadColor(_T("BorderNormal"), m_clrRibbonEditBorder);
					tmEdit.ReadColor(_T("BorderHighlighted"), m_clrRibbonEditBorderHighlighted);
					tmEdit.ReadColor(_T("BorderDisabled"), m_clrRibbonEditBorderDisabled);
					tmEdit.ReadColor(_T("BorderPressed"), m_clrRibbonEditBorderPressed);
					tmEdit.ReadColor(_T("Selection"), m_clrRibbonEditSelection);

					CString strButton;
					if (tmEdit.ExcludeTag(_T("BUTTON"), strButton))
					{
						CTagManager tmButton (strButton);
						tmButton.ReadControlRenderer(_T("IMAGE"), m_ctrlRibbonComboBoxBtn, MakeResourceID(_T("IDB_COMBOBOX_BTN")));
					}
				}
			}
		}

		if (tmItem.ExcludeTag(_T("CONTEXT"), str))
		{
			CTagManager tmContext(str);

			CString strCategory;
			if (tmContext.ExcludeTag(_T("CATEGORY"), strCategory))
			{
				CTagManager tmCategory(strCategory);

				CMFCControlRendererInfo prBack;
				CMFCControlRendererInfo prCaption;
				CMFCControlRendererInfo prTab;
				COLORREF clrText = m_clrRibbonCategoryText;
				COLORREF clrTextHighlighted = m_clrRibbonCategoryTextHighlighted;
				COLORREF clrCaptionText = clrText;

				tmCategory.ReadControlRendererInfo(_T("BACK"), prBack);

				CString strTab;
				if (tmCategory.ExcludeTag(_T("TAB"), strTab))
				{
					CTagManager tmTab(strTab);

					tmTab.ReadControlRendererInfo(_T("BUTTON"), prTab);
					tmTab.ReadColor(_T("TextNormal"), clrText);
					tmTab.ReadColor(_T("TextHighlighted"), clrTextHighlighted);
				}

				CString strCaption;
				if (tmCategory.ExcludeTag(_T("CAPTION"), strCaption))
				{
					CTagManager tmCaption(strCaption);

					tmCaption.ReadControlRendererInfo(_T("BACK"), prCaption);
					tmCaption.ReadColor(_T("TextNormal"), clrCaptionText);
				}

				CString strID[AFX_RIBBON_CATEGORY_COLOR_COUNT] =
				{
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_R_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_O_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_Y_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_G_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_B_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_I_")),
					MakeResourceID(_T("IDB_RIBBON_CONTEXT_V_"))
				};

				for (int i = 0; i < AFX_RIBBON_CATEGORY_COLOR_COUNT; i++)
				{
					CMFCRibbonContextCategory& cat = m_ctrlRibbonContextCategory[i];

					prTab.m_strBmpResID     = strID[i] + _T("CATEGORY_TAB");
					prCaption.m_strBmpResID = strID[i] + _T("CATEGORY_CAPTION");
					prBack.m_strBmpResID    = strID[i] + _T("CATEGORY_BACK");

					cat.m_ctrlCaption.Create(prCaption);
					cat.m_ctrlTab.Create(prTab);
					cat.m_ctrlBack.Create(prBack);
					cat.m_clrText            = clrText;
					cat.m_clrTextHighlighted = clrTextHighlighted;
					cat.m_clrCaptionText     = clrCaptionText;
				}
			}

			tmContext.ReadControlRenderer(_T("SEPARATOR"), m_ctrlRibbonContextSeparator, MakeResourceID(_T("IDB_RIBBON_CONTEXT_SEPARATOR")));
		}
		
		tmItem.ReadControlRenderer(_T("MAIN_BUTTON"), m_ctrlRibbonBtnMain, MakeResourceID(_T("IDB_RIBBON_BTN_MAIN")));

		if (tmItem.ExcludeTag(_T("MAIN"), str))
		{
			CTagManager tmMain(str);

			tmMain.ReadControlRenderer(_T("BACK"), m_ctrlRibbonMainPanel, MakeResourceID(_T("IDB_RIBBON_PANEL_MAIN")));
			tmMain.ReadControlRenderer(_T("BUTTON"), m_ctrlRibbonBtnMainPanel, MakeResourceID(_T("IDB_RIBBON_BTN_PANEL_MAIN")));
		}

		if (tmItem.ExcludeTag(_T("CAPTION"), str))
		{
			CTagManager tmCaption(str);
			tmCaption.ReadControlRenderer(_T("QA"), m_ctrlRibbonCaptionQA, MakeResourceID(_T("IDB_RIBBON_CAPTION_QA")));
		}

		if (tmItem.ExcludeTag(_T("STATUS"), str))
		{
			CTagManager tmStatus(str);
			tmStatus.ReadControlRenderer(_T("PANE_BUTTON"), m_ctrlRibbonBtnStatusPane, MakeResourceID(_T("IDB_RIBBON_BTN_STATUS_PANE")));

			CString strSlider;
			if (tmStatus.ExcludeTag(_T("SLIDER"), strSlider))
			{
				CTagManager tmSlider(strSlider);

				tmSlider.ReadControlRenderer(_T("PLUS"), m_ctrlRibbonSliderBtnPlus, MakeResourceID(_T("IDB_RIBBON_SLIDER_BTN_PLUS")));
				tmSlider.ReadControlRenderer(_T("MINUS"), m_ctrlRibbonSliderBtnMinus, MakeResourceID(_T("IDB_RIBBON_SLIDER_BTN_MINUS")));
			}
		}

		if (tmItem.ExcludeTag(_T("BORDERS"), str))
		{
			CTagManager tmBorders(str);

			tmBorders.ReadControlRenderer(_T("QAT"), m_ctrlRibbonBorder_QAT, MakeResourceID(_T("IDB_RIBBON_BORDER_QAT")));
			tmBorders.ReadControlRenderer (_T("PANEL"), m_ctrlRibbonBorder_Panel, MakeResourceID(_T("IDB_RIBBON_BORDER_PANEL")));
		}
	}

	if (hinstResOld != NULL)
	{
		AfxSetResourceHandle(hinstResOld);
	}


	NONCLIENTMETRICS ncm;
	ncm.cbSize = sizeof(ncm);
	GetGlobalData()->GetNonClientMetrics(ncm);
	m_AppCaptionFont.CreateFontIndirect(&ncm.lfCaptionFont);

	m_penSeparatorDark.CreatePen(PS_SOLID, 0, RGB (198, 212, 227));
	m_penSeparatorLight.CreatePen(PS_SOLID, 0, RGB (237, 243, 248));
}

void CMFCVisualManagerWindows7::OnDrawMenuCheck(CDC* pDC, CMFCToolBarMenuButton* pButton, CRect rect, BOOL bHighlight, BOOL bIsRadio)
{
	ASSERT_VALID(pButton);

    CMFCToolBarImages& img = bIsRadio ? m_MenuItemMarkerR : m_MenuItemMarkerC;

	if (!CanDrawImage() || img.GetCount() == 0)
	{
		CMFCVisualManagerWindows::OnDrawMenuCheck(pDC, pButton, rect, bHighlight, bIsRadio);
		return;
	}

    CSize size(img.GetImageSize());
    CRect rectImage(0, 0, size.cx, size.cy);

    if ((pButton->m_nStyle & TBBS_DISABLED) == TBBS_DISABLED)
    {
        rectImage.OffsetRect(0, size.cy);
    }

	if (GetGlobalData()->m_bIsRTL)
	{
		img.Mirror();
	}

    img.DrawEx(pDC, rect, 0, CMFCToolBarImages::ImageAlignHorzCenter, CMFCToolBarImages::ImageAlignVertCenter, rectImage);

	if (GetGlobalData()->m_bIsRTL)
	{
		img.Mirror();
	}
}

void CMFCVisualManagerWindows7::OnDrawMenuBorder(CDC* pDC, CMFCPopupMenu* pMenu, CRect rect)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawMenuBorder(pDC, pMenu, rect);
		return;
	}

	if (pMenu != NULL)
	{
		CMFCRibbonPanelMenuBar* pRibbonMenuBar = DYNAMIC_DOWNCAST(CMFCRibbonPanelMenuBar, pMenu->GetMenuBar());

		if (pRibbonMenuBar != NULL)
		{
			ASSERT_VALID(pRibbonMenuBar);

			if (pRibbonMenuBar->IsMainPanel())
			{
				if (m_ctrlRibbonMainPanel.IsValid())
				{
					m_ctrlRibbonMainPanel.DrawFrame(pDC, rect);
				}

				return;
			}

			if (!pRibbonMenuBar->IsMenuMode())
			{
				if (pRibbonMenuBar->IsQATPopup() && m_ctrlRibbonBorder_QAT.IsValid())
				{
					m_ctrlRibbonBorder_QAT.DrawFrame(pDC, rect);
					return;
				}
				else if (pRibbonMenuBar->IsCategoryPopup())
				{
					return;
				}
				else if (pRibbonMenuBar->IsRibbonMiniToolBar())
				{
				}
				else
				{
					if (pRibbonMenuBar->GetPanel() != NULL)
					{
						m_ctrlRibbonBorder_Panel.DrawFrame(pDC, rect);
						return;
					}
				}
			}
		}
	}

	CMFCVisualManagerWindows::OnDrawMenuBorder (pDC, pMenu, rect);
}

void CMFCVisualManagerWindows7::OnHighlightMenuItem(CDC *pDC, CMFCToolBarMenuButton* pButton, CRect rect, COLORREF& clrText)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnHighlightMenuItem(pDC, pButton, rect, clrText);
		return;
	}

	clrText = GetGlobalData()->clrMenuText;
	m_ctrlMenuHighlighted[(pButton->m_nStyle & TBBS_DISABLED) == TBBS_DISABLED ? 1 : 0].Draw(pDC, rect);
}

void CMFCVisualManagerWindows7::OnDrawRibbonCaption(CDC* pDC, CMFCRibbonBar* pBar, CRect rectCaption, CRect rectText)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pBar);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonCaption(pDC, pBar, rectCaption, rectText);
		return;
	}

	CWnd* pWnd = pBar->GetParent ();
	ASSERT_VALID (pWnd);

	const DWORD dwStyleEx = pWnd->GetExStyle();

	const BOOL bIsRTL  = (dwStyleEx & WS_EX_LAYOUTRTL) == WS_EX_LAYOUTRTL;
	const BOOL bActive = IsWindowActive(pWnd);
	const BOOL bGlass  = pBar->IsTransparentCaption();

	{
		CSize szSysBorder(GetSystemBorders(TRUE));

		if (!bGlass)
		{
			CRect rectCaption1(rectCaption);
			rectCaption1.InflateRect(szSysBorder.cx, szSysBorder.cy, szSysBorder.cx, 0);

			if (m_hThemeWindow != NULL)
			{
				DrawThemeBackground(m_hThemeWindow, pDC->GetSafeHdc(), WP_CAPTION, bActive ? CS_ACTIVE : CS_INACTIVE, &rectCaption1, 0);
			}
			else
			{
				CDrawingManager dm(*pDC);
				dm.FillGradient(rectCaption1, bActive ? GetGlobalData()->clrActiveCaption : GetGlobalData()->clrInactiveCaption, bActive ? GetGlobalData()->clrActiveCaptionGradient : GetGlobalData()->clrInactiveCaptionGradient, FALSE);
			}
		}

		CRect rectQAT = pBar->GetQuickAccessToolbarLocation();

		if (rectQAT.left > rectQAT.right)
		{
			rectText.left = rectQAT.left + 1;
		}

		BOOL bHide  = (pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ALL) != 0;
		BOOL bExtra = !bHide && pBar->IsQuickAccessToolbarOnTop() && rectQAT.left < rectQAT.right && !pBar->IsQATEmpty();

		BOOL bDrawIcon = (bHide && !bExtra) || pBar->IsWindows7Look();

		if (bExtra)
		{
			CRect rectQAFrame(rectQAT);
			rectQAFrame.right = rectText.left - 6;
			rectQAFrame.InflateRect(1, 1, 1, 1);

			const CMFCControlRendererInfo& params = m_ctrlRibbonCaptionQA.GetParams();

			if (rectQAFrame.Height() < params.m_rectImage.Height())
			{
				rectQAFrame.top = rectQAFrame.bottom - params.m_rectImage.Height();
			}

			m_ctrlRibbonCaptionQA.Draw(pDC, rectQAFrame, bActive ? 0 : 1);
		}

		if (bDrawIcon)
		{
			HICON hIcon = afxGlobalUtils.GetWndIcon(pWnd);

			if (hIcon != NULL)
			{
				CSize szIcon(::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));

				long x = rectCaption.left + 2;
				long y = rectCaption.top  + max(0, (rectCaption.Height() - szIcon.cy) / 2);

				pDC->DrawState(CPoint(x, y), szIcon, hIcon, DSS_NORMAL, (CBrush*)NULL);

				if (rectText.left < (x + szIcon.cx + 4))
				{
					rectText.left = x + szIcon.cx + 4;
				}
			}
		}
	}

	CString strText;
	pWnd->GetWindowText(strText);

	CFont* pOldFont = (CFont*)pDC->SelectObject(&m_AppCaptionFont);
	ASSERT(pOldFont != NULL);

	DrawNcText(pDC, rectText, strText, bActive, bIsRTL, FALSE, bGlass, pWnd->IsZoomed() ? 0 : 10, pWnd->IsZoomed() ? RGB(255, 255, 255) :(COLORREF)-1);

	pDC->SelectObject(pOldFont);
}

void CMFCVisualManagerWindows7::OnDrawRibbonCaptionButton(CDC* pDC, CMFCRibbonCaptionButton* pButton)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	const BOOL bHighlighted = pButton->IsHighlighted() || pButton->IsFocused();
	const BOOL bPressed = pButton->IsPressed();

	AFX_BUTTON_STATE state = ButtonsIsRegular;
	if (bPressed)
	{
		if (bHighlighted)
		{
			state = ButtonsIsPressed;
		}
	}
	else if (bHighlighted)
	{
		state = ButtonsIsHighlighted;
	}

	const BOOL bMDI = pButton->IsMDIChildButton();
	BOOL bActive = TRUE;

	if (!bMDI)
	{
		CMFCRibbonBar* pBar = pButton->GetParentRibbonBar();
		if (pBar->GetSafeHwnd() != NULL)
		{
			CWnd* pWnd = pBar->GetParent();
			ASSERT_VALID(pWnd);

			bActive = IsWindowActive(pWnd);
		}
	}

	CRect rect(pButton->GetRect());
	rect.DeflateRect(m_hThemeWindow == NULL ? 1 : 2, m_hThemeWindow == NULL ? 1 : 2);

	DrawNcBtn(pDC, rect, pButton->GetID(), state, FALSE, bActive, bMDI);
}

COLORREF CMFCVisualManagerWindows7::OnDrawRibbonPanel(CDC* pDC, CMFCRibbonPanel* pPanel, CRect rectPanel, CRect rectCaption)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::OnDrawRibbonPanel(pDC, pPanel, rectPanel, rectCaption);
	}

	ASSERT_VALID (pDC);
	ASSERT_VALID (pPanel);

	if (pPanel->IsKindOf(RUNTIME_CLASS(CMFCRibbonMainPanel)))
	{
		const int nBorderSize = GetPopupMenuBorderSize();
		rectPanel.InflateRect(nBorderSize, nBorderSize);
		
		m_ctrlRibbonMainPanel.Draw(pDC, rectPanel);
	}
	else
	{
		if (!pPanel->IsMenuMode() && !pPanel->IsCollapsed())
		{
			BOOL bHighlighted = pPanel->IsHighlighted();

			CMFCControlRenderer* pRenderer = &m_ctrlRibbonPanelBack;
			CMFCVisualManagerBitmapCache* pCache = &m_cacheRibbonPanelBack;

			CMFCRibbonCategory* pCategory = pPanel->GetParentCategory();
			ASSERT_VALID(pCategory);

			const CMFCControlRendererInfo& params = pRenderer->GetParams();

			CRect rectBack(rectPanel);
			CMFCRibbonPanelMenuBar* pMenuBar = pPanel->GetParentMenuBar();
			if (m_ctrlRibbonPanelBackSep.IsValid() && (pMenuBar == NULL || pMenuBar->GetPanel() == NULL))
			{
				CRect rectSep (rectPanel);

				rectSep.left = rectSep.right - m_ctrlRibbonPanelBackSep.GetParams().m_rectImage.Width();
				m_ctrlRibbonPanelBackSep.Draw(pDC, rectSep);
				rectPanel.right = rectSep.left;
			}

			int nCacheIndex = -1;
			CSize size (params.m_rectImage.Width(), rectPanel.Height());
			nCacheIndex = pCache->FindIndex(size);
			if (nCacheIndex == -1)
			{
				nCacheIndex = pCache->CacheY(size.cy, *pRenderer);
			}

			if (nCacheIndex != -1)
			{
				pCache->Get(nCacheIndex)->DrawY(pDC, rectBack, CSize(params.m_rectInter.left, params.m_rectImage.right - params.m_rectInter.right), bHighlighted ? 1 : 0);
			}
			else
			{
				pRenderer->Draw(pDC, rectBack, bHighlighted ? 1 : 0);
			}
		}
	}

	return m_clrRibbonPanelCaptionText;
}

void CMFCVisualManagerWindows7::OnDrawRibbonPanelCaption(CDC* pDC, CMFCRibbonPanel* pPanel, CRect rectCaption)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonPanelCaption(pDC, pPanel, rectCaption);
		return;
	}

	if (pPanel->IsKindOf(RUNTIME_CLASS(CMFCRibbonMainPanel)))
	{
		return;
	}

	CString str = pPanel->GetName();

	if (!str.IsEmpty())
	{
		if (pPanel->GetLaunchButton().GetID() > 0)
		{
			rectCaption.right = pPanel->GetLaunchButton().GetRect().left;

			rectCaption.DeflateRect(1, 1);
			rectCaption.OffsetRect(-1, -1);
		}
		else
		{
			rectCaption.DeflateRect(1, 1);

			if ((rectCaption.Width() % 2) == 0)
			{
				rectCaption.right--;
			}

			rectCaption.OffsetRect(0, -1);
		}

		COLORREF clrTextOld = pDC->SetTextColor(pPanel->IsHighlighted() ? m_clrRibbonPanelCaptionTextHighlighted : m_clrRibbonPanelCaptionText);

		pDC->DrawText( str, rectCaption, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
		pDC->SetTextColor(clrTextOld);
	}
}

void CMFCVisualManagerWindows7::OnDrawRibbonCategory(CDC* pDC, CMFCRibbonCategory* pCategory, CRect rectCategory)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pCategory);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonCategory(pDC, pCategory, rectCategory);
		return;
	}

	CMFCControlRenderer* pRenderer = &m_ctrlRibbonCategoryBack;
	CMFCVisualManagerBitmapCache* pCache = &m_cacheRibbonCategoryBack;

	CMFCRibbonBaseElement* pParentButton = pCategory->GetParentButton();

	if (pCategory->GetTabColor() != AFX_CategoryColor_None && (pParentButton == NULL || !pParentButton->IsQATMode()))
	{
		CMFCRibbonContextCategory& context = m_ctrlRibbonContextCategory[pCategory->GetTabColor() - 1];

		pRenderer = &context.m_ctrlBack;
		pCache    = &context.m_cacheBack;
	}

	const CMFCControlRendererInfo& params = pRenderer->GetParams();

	CMFCRibbonPanelMenuBar* pMenuBar = pCategory->GetParentMenuBar();
	if (pMenuBar != NULL)
	{
		if (pMenuBar->GetCategory() != NULL)
		{
			if (rectCategory.left < 0 || rectCategory.top < 0)
			{
				CDrawingManager dm(*pDC);
				dm.FillGradient(rectCategory, m_clrRibbonBarGradientDark, m_clrRibbonBarGradientLight, TRUE);

				return;
			}
		}
	}

	int nCacheIndex = -1;
	if (pCache != NULL)
	{
		CSize size(params.m_rectImage.Width(), rectCategory.Height());
		nCacheIndex = pCache->FindIndex(size);
		if (nCacheIndex == -1)
		{
			nCacheIndex = pCache->CacheY(size.cy, *pRenderer);
		}
	}

	if (nCacheIndex != -1)
	{
		pCache->Get(nCacheIndex)->DrawY(pDC, rectCategory, CSize(params.m_rectInter.left, params.m_rectImage.right - params.m_rectInter.right));
	}
	else
	{
		pRenderer->Draw(pDC, rectCategory);
	}
}

void CMFCVisualManagerWindows7::OnDrawRibbonCategoryScroll(CDC* pDC, CRibbonCategoryScroll* pScroll)
{
	if (!CanDrawImage ())
	{
		CMFCVisualManagerWindows::OnDrawRibbonCategoryScroll (pDC, pScroll);
		return;
	}

	ASSERT_VALID (pDC);
	ASSERT_VALID (pScroll);

	CRect rect = pScroll->GetRect ();

	CMFCControlRenderer* pRenderer = 
		&m_ctrlRibbonCategoryBtnPage[pScroll->IsLeftScroll () ? 0 : 1];
	int index = 0;

	if (pScroll->IsPressed ())
	{
		index = 1;
		if (pScroll->IsHighlighted())
		{
			index = 2;
		}
	}
	else if (pScroll->IsHighlighted())
	{
		index = 1;
	}

	pRenderer->Draw (pDC, rect, index);
	
	BOOL bIsLeft = pScroll->IsLeftScroll ();
	if (GetGlobalData()->m_bIsRTL)
	{
		bIsLeft = !bIsLeft;
	}

	CMenuImages::Draw (pDC, bIsLeft ? CMenuImages::IdArrowLeftLarge : CMenuImages::IdArrowRightLarge, rect);
}

COLORREF CMFCVisualManagerWindows7::OnDrawRibbonCategoryTab(CDC* pDC, CMFCRibbonTab* pTab, BOOL bIsActive)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pTab);

	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::OnDrawRibbonCategoryTab (pDC, pTab, bIsActive);
	}

	CMFCRibbonCategory* pCategory = pTab->GetParentCategory();
	ASSERT_VALID(pCategory);
	CMFCRibbonBar* pBar = pCategory->GetParentRibbonBar();
	ASSERT_VALID(pBar);

	bIsActive = bIsActive && ((pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0 || pTab->GetDroppedDown() != NULL);

	const BOOL bPressed       = pTab->IsPressed();
	const BOOL bIsFocused	  = pTab->IsFocused() &&(pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS);
	const BOOL bIsHighlighted = (pTab->IsHighlighted() || bIsFocused) && !pTab->IsDroppedDown();

	CRect rectTab(pTab->GetRect());
	rectTab.bottom++;

	int ratio = 0;
	if (m_ctrlRibbonCategoryTabSep.IsValid())
	{
		ratio = pBar->GetTabTruncateRatio();
	}

	if (ratio > 0)
	{
		rectTab.left++;
	}

	CMFCControlRenderer* pRenderer = &m_ctrlRibbonCategoryTab;
	COLORREF clrText = m_clrRibbonCategoryText;
	COLORREF clrTextHighlighted = m_clrRibbonCategoryTextHighlighted;

	if (pCategory->GetTabColor() != AFX_CategoryColor_None)
	{
		CMFCRibbonContextCategory& context = m_ctrlRibbonContextCategory[pCategory->GetTabColor() - 1];

		pRenderer = &context.m_ctrlTab;
		clrText   = context.m_clrText;
		clrTextHighlighted = context.m_clrTextHighlighted;
	}

	if (bIsActive || bPressed || bIsHighlighted)
	{
		int nImage = 1;

		if (bIsHighlighted && !bPressed)
		{
			nImage = bIsActive ? 2 : 0;
		}

		pRenderer->Draw(pDC, rectTab, nImage);
	}

	if (ratio > 0)
	{
		CRect rectSep(rectTab);
		rectSep.left = rectSep.right;
		rectSep.right += m_ctrlRibbonCategoryTabSep.GetParams().m_rectImage.Width();
		rectSep.bottom--;

		m_ctrlRibbonCategoryTabSep.Draw(pDC, rectSep, 0, (BYTE)min(ratio * 255 / 100, 255));
	}

	return bIsActive ? clrTextHighlighted : clrText;
}

COLORREF CMFCVisualManagerWindows7::OnDrawRibbonTabsFrame(CDC* pDC, CMFCRibbonBar* pWndRibbonBar, CRect rectTab)
{
	UNREFERENCED_PARAMETER(pDC);
	UNREFERENCED_PARAMETER(pWndRibbonBar);
	UNREFERENCED_PARAMETER(rectTab);

	return(COLORREF)-1;
}

void CMFCVisualManagerWindows7::OnFillMenuImageRect(CDC* pDC, CMFCToolBarButton* pButton, CRect rect, CMFCVisualManager::AFX_BUTTON_STATE state)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnFillMenuImageRect(pDC, pButton, rect, state);
		return;
	}

	OnFillButtonInterior(pDC, pButton, rect, state);
}

void CMFCVisualManagerWindows7::OnFillButtonInterior(CDC* pDC, CMFCToolBarButton* pButton, CRect rect, CMFCVisualManager::AFX_BUTTON_STATE state)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnFillButtonInterior(pDC, pButton, rect, state);
		return;
	}

	CMFCCustomizeButton* pCustButton = DYNAMIC_DOWNCAST(CMFCCustomizeButton, pButton);

	if (pCustButton == NULL)
	{
		if (CMFCToolBar::IsCustomizeMode() && 
			!CMFCToolBar::IsAltCustomizeMode() && !pButton->IsLocked())
		{
			return;
		}

		CMFCControlRenderer* pRenderer = NULL;
		int index = 0;

		BOOL bDisabled = (pButton->m_nStyle & TBBS_DISABLED) == TBBS_DISABLED;
		//BOOL bPressed  = (pButton->m_nStyle & TBBS_PRESSED ) == TBBS_PRESSED;
		BOOL bChecked  = (pButton->m_nStyle & TBBS_CHECKED ) == TBBS_CHECKED;

		CBasePane* pBar = DYNAMIC_DOWNCAST(CBasePane, pButton->GetParentWnd());

		CMFCToolBarMenuButton* pMenuButton = 
			DYNAMIC_DOWNCAST(CMFCToolBarMenuButton, pButton);
		if (pMenuButton != NULL && pBar != NULL)
		{
			if (pBar->IsKindOf(RUNTIME_CLASS(CMFCMenuBar)) == NULL && pBar->IsKindOf(RUNTIME_CLASS(CMFCPopupMenuBar)))
			{
				if (bChecked)
				{
					pRenderer = &m_ctrlMenuItemBack;

					if (bDisabled)
					{
						index = 1;
					}

					rect.InflateRect(0, 0, 0, 1);
				}
				else if (state == ButtonsIsPressed || state == ButtonsIsHighlighted)
				{
					pRenderer = &m_ctrlMenuHighlighted[bDisabled ? 1 : 0];
				}
				else
				{
					return;
				}
			}
		}

		if (pRenderer != NULL)
		{
			pRenderer->Draw(pDC, rect, index);
			return;
		}
	}

	CMFCVisualManagerWindows::OnFillButtonInterior(pDC, pButton, rect, state);
}

void CMFCVisualManagerWindows7::OnDrawButtonBorder(CDC* pDC, CMFCToolBarButton* pButton, CRect rect, CMFCVisualManager::AFX_BUTTON_STATE state)
{
	CMFCToolBarMenuButton* pMenuButton = DYNAMIC_DOWNCAST(CMFCToolBarMenuButton, pButton);
	if (CanDrawImage() && pMenuButton != NULL && pMenuButton->GetParentWnd () != NULL && pMenuButton->GetParentWnd()->IsKindOf(RUNTIME_CLASS(CMFCPopupMenuBar)))
	{
		return;
	}

	CMFCVisualManagerWindows::OnDrawButtonBorder(pDC, pButton, rect, state);
}

void CMFCVisualManagerWindows7::OnFillBarBackground(CDC* pDC, CBasePane* pBar, CRect rectClient, CRect rectClip, BOOL bNCArea)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pBar);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnFillBarBackground (pDC, pBar, rectClient, rectClip, bNCArea);
		return;
	}

	if (pBar->IsKindOf(RUNTIME_CLASS(CMFCRibbonStatusBar)))
	{
		if (m_hThemeWindow != NULL)
		{
			DrawThemeBackground(m_hThemeStatusBar, pDC->GetSafeHdc(), 0, 0, &rectClient, 0);
			return;
		}
	}
	else if (pBar->IsKindOf(RUNTIME_CLASS(CMFCRibbonBar)))
	{
		CDrawingManager dm(*pDC);
		dm.FillGradient(rectClient, m_clrRibbonBarGradientDark, m_clrRibbonBarGradientLight, TRUE);

		return;
	}

	CMFCVisualManagerWindows::OnFillBarBackground(pDC, pBar, rectClient, rectClip, bNCArea);
}

void CMFCVisualManagerWindows7::OnDrawStatusBarSizeBox(CDC* pDC, CMFCStatusBar* pStatBar, CRect rectSizeBox)
{
	if (!CanDrawImage() || m_hThemeStatusBar == NULL)
	{
		CMFCVisualManagerWindows::OnDrawStatusBarSizeBox(pDC, pStatBar, rectSizeBox);
		return;
	}

	DrawThemeBackground(m_hThemeStatusBar, pDC->GetSafeHdc(), SP_GRIPPER, 0, &rectSizeBox, 0);
}

void CMFCVisualManagerWindows7::OnDrawRibbonGalleryButton(CDC* pDC, CMFCRibbonGalleryIcon* pButton)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonGalleryButton(pDC, pButton);
		return;
	}

	int index = 0;
	if (pButton->IsDisabled())
	{
		index = 3;
	}
	else
	{
		if (pButton->IsPressed())
		{
			if (pButton->IsHighlighted())
			{
				index = 2;
			}
		}
		else if (pButton->IsHighlighted() || pButton->IsFocused())
		{
			index = 1;
		}
	}

	int nBtn = 1;
	if (pButton->IsLast())
	{
		nBtn = 2;
	}
	else if (pButton->IsFirst())
	{
		nBtn = 0;
	}

	m_ctrlRibbonBtnPalette[nBtn].Draw(pDC, pButton->GetRect(), index);
}

COLORREF CMFCVisualManagerWindows7::OnDrawRibbonCategoryCaption(CDC* pDC, CMFCRibbonContextCaption* pContextCaption)
{
	if (!CanDrawImage() || pContextCaption->GetColor() == AFX_CategoryColor_None)
	{
		return CMFCVisualManagerWindows::OnDrawRibbonCategoryCaption(pDC, pContextCaption);
	}

	CMFCRibbonContextCategory& context = m_ctrlRibbonContextCategory[pContextCaption->GetColor() - 1];

	CRect rect(pContextCaption->GetRect());
	context.m_ctrlCaption.Draw(pDC, rect);

	int xTabRight = pContextCaption->GetRightTabX();

	if (xTabRight > 0)
	{
		CRect rectTab(pContextCaption->GetParentRibbonBar()->GetActiveCategory()->GetTabRect());
		rect.top = rectTab.top;
		rect.bottom = rectTab.bottom;
		rect.right = xTabRight;

		m_ctrlRibbonContextSeparator.DrawFrame(pDC, rect);
	}

	return context.m_clrCaptionText;
}

COLORREF CMFCVisualManagerWindows7::OnDrawRibbonStatusBarPane(CDC* pDC, CMFCRibbonStatusBar* pBar, CMFCRibbonStatusBarPane* pPane)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pBar);
	ASSERT_VALID(pPane);

	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::OnDrawRibbonStatusBarPane(pDC, pBar, pPane);
	}

	CRect rectPane = pPane->GetRect();

	const BOOL bHighlighted = pPane->IsHighlighted() || pPane->IsFocused();
	const BOOL bChecked     = pPane->IsChecked();

	if (bHighlighted || bChecked)
	{
		CRect rectButton = rectPane;
		rectButton.DeflateRect(1, 1);

		int index = 0;
		if (pPane->IsPressed())
		{
			if (bHighlighted)
			{
				index = 1;
			}
		}
		else if (bChecked)
		{
			if (bHighlighted)
			{
				index = 0;
			}
			else
			{
				index = 1;
			}
		}

		m_ctrlRibbonBtnStatusPane.Draw(pDC, rectButton, index);
	}

	return(COLORREF)-1;
}

void CMFCVisualManagerWindows7::OnDrawRibbonSliderZoomButton(CDC* pDC, CMFCRibbonSlider* pSlider, CRect rect, BOOL bIsZoomOut, BOOL bIsHighlighted, BOOL bIsPressed, BOOL bIsDisabled)
{
	UNREFERENCED_PARAMETER(pSlider);
	UNREFERENCED_PARAMETER(bIsHighlighted);
	UNREFERENCED_PARAMETER(bIsPressed);

	ASSERT_VALID(pDC);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonSliderZoomButton(pDC, pSlider, rect, bIsZoomOut, bIsHighlighted, bIsPressed, bIsDisabled);
		return;
	}

	CMFCControlRenderer* pRenderer = bIsZoomOut ? &m_ctrlRibbonSliderBtnMinus : &m_ctrlRibbonSliderBtnPlus;

	int index = 0;
	if (bIsDisabled)
	{
		index = 3;
	}
	else
	{
		if (bIsPressed)
		{
			if (bIsHighlighted)
			{
				index = 2;
			}
		}
		else if (bIsHighlighted)
		{
			index = 1;
		}
	}

	pRenderer->FillInterior(pDC, rect, GetGlobalData()->GetRibbonImageScale() != 1. ? CMFCToolBarImages::ImageAlignHorzStretch : CMFCToolBarImages::ImageAlignHorzCenter, GetGlobalData()->GetRibbonImageScale() != 1. ? CMFCToolBarImages::ImageAlignVertStretch : CMFCToolBarImages::ImageAlignVertCenter, index);
}

void CMFCVisualManagerWindows7::OnDrawRibbonSliderChannel(CDC* pDC, CMFCRibbonSlider* pSlider, CRect rect)
{
	if (m_hThemeTrack == NULL)
	{
		CMFCVisualManagerWindows::OnDrawRibbonSliderChannel(pDC, pSlider, rect);
		return;
	}

	ASSERT_VALID(pDC);

	BOOL bVert = FALSE;

	if (bVert)
	{
		if (rect.Width() < 3)
		{
			rect.right++;
		}
	}
	else
	{
		if (rect.Height() < 3)
		{
			rect.bottom++;
		}
	}

	DrawThemeBackground(m_hThemeTrack, pDC->GetSafeHdc(), bVert ? TKP_TRACKVERT : TKP_TRACK, 1, &rect, 0);
}

void CMFCVisualManagerWindows7::OnDrawRibbonSliderThumb(CDC* pDC, CMFCRibbonSlider* pSlider, CRect rect, BOOL bIsHighlighted, BOOL bIsPressed, BOOL bIsDisabled)
{
	if (m_hThemeTrack == NULL)
	{
		CMFCVisualManagerWindows::OnDrawRibbonSliderThumb(pDC, pSlider, rect, bIsHighlighted, bIsPressed, bIsDisabled);
		return;
	}

	ASSERT_VALID(pDC);

	int nPart = 0;
	int nState = 0;

	BOOL bVert = FALSE;
	BOOL bLeftTop = FALSE;
	BOOL bRightBottom = TRUE;

	if (bLeftTop && bRightBottom)
	{
		nPart = bVert ? TKP_THUMBVERT : TKP_THUMB;
	}
	else if (bLeftTop)
	{
		nPart = bVert ? TKP_THUMBLEFT : TKP_THUMBTOP;
	}
	else
	{
		nPart = bVert ? TKP_THUMBRIGHT : TKP_THUMBBOTTOM;
	}

	if (bIsDisabled)
	{
		nState = TUS_DISABLED;
	}
	else if (bIsPressed)
	{
		nState = TUS_PRESSED;
	}
	else if (bIsHighlighted)
	{
		nState = TUS_HOT;
	}
	else
	{
		nState = TUS_NORMAL;
	}

	DrawThemeBackground(m_hThemeTrack, pDC->GetSafeHdc(), nPart, nState, &rect, 0);
}

void CMFCVisualManagerWindows7::OnDrawRibbonProgressBar(CDC* pDC, CMFCRibbonProgressBar* pProgress, CRect rectProgress, CRect rectChunk, BOOL bInfiniteMode)
{
	if (m_hThemeProgress == NULL)
	{
		CMFCVisualManagerWindows::OnDrawRibbonProgressBar(pDC, pProgress, rectProgress, rectChunk, bInfiniteMode);
		return;
	}

	DrawThemeBackground(m_hThemeProgress, pDC->GetSafeHdc(), PP_BAR, 0, &rectProgress, 0);

	if (!bInfiniteMode)
	{
		if (!rectChunk.IsRectEmpty() || pProgress->GetPos() != pProgress->GetRangeMin())
		{
			DrawThemeBackground(m_hThemeProgress, pDC->GetSafeHdc(), PP_CHUNK, 0, &rectChunk, 0);
		}
	}
	else if (pProgress->GetPos() != pProgress->GetRangeMin())
	{
		CRgn rgn;
		rgn.CreateRectRgnIndirect(rectProgress);
		pDC->SelectClipRgn(&rgn);

		double index = (pProgress->GetPos() - pProgress->GetRangeMin()) * 2.0 / double(pProgress->GetRangeMax() - pProgress->GetRangeMin());

		rectProgress.OffsetRect((int)(rectProgress.Width() *(index - 1.0)), 0);

		DrawThemeBackground(m_hThemeProgress, pDC->GetSafeHdc(), PP_MOVEOVERLAY, 0, &rectProgress, 0);

		pDC->SelectClipRgn(NULL);
	}
}

void CMFCVisualManagerWindows7::OnDrawDefaultRibbonImage(CDC* pDC, CRect rectImage, BOOL bIsDisabled/* = FALSE*/, BOOL bIsPressed/* = FALSE*/, BOOL bIsHighlighted/* = FALSE*/)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawDefaultRibbonImage(pDC, rectImage, bIsDisabled, bIsPressed, bIsHighlighted);
		return;
	}

	m_RibbonBtnDefaultImage.DrawEx(pDC, rectImage, bIsDisabled ? 1 : 0,	CMFCToolBarImages::ImageAlignHorzCenter, CMFCToolBarImages::ImageAlignVertCenter);
}

void CMFCVisualManagerWindows7::OnDrawRibbonApplicationButton(CDC* pDC, CMFCRibbonButton* pButton)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonApplicationButton(pDC, pButton);
		return;
	}

	BOOL bIsHighlighted = pButton->IsHighlighted() || pButton->IsFocused();
	BOOL bIsPressed = pButton->IsPressed() || pButton->IsDroppedDown();

	if (pButton->IsDroppedDown())
	{
		bIsPressed = TRUE;
		bIsHighlighted = TRUE;
	}

	CRect rect = pButton->GetRect();

	int index = 0;
	if (bIsPressed)
	{
		if (bIsHighlighted)
		{
			index = 2;
		}
	}
	else if (bIsHighlighted)
	{
		index = 1;
	}

	m_ctrlRibbonBtnMain.Draw(pDC, pButton->GetRect(), index);
}

void CMFCVisualManagerWindows7::OnDrawCheckBoxEx(CDC *pDC, CRect rect, int nState, BOOL bHighlighted, BOOL bPressed, BOOL bEnabled)
{
	if (m_hThemeButton == NULL)
	{
		CMFCVisualManager::OnDrawCheckBoxEx(pDC, rect, nState, bHighlighted, bPressed, bEnabled);
		return;
	}

	DrawCheckBox(pDC, rect, bHighlighted, nState, bEnabled, bPressed);
}

void CMFCVisualManagerWindows7::OnDrawRadioButton(CDC *pDC, CRect rect, BOOL bOn, BOOL bHighlighted, BOOL bPressed, BOOL bEnabled)
{
	DrawRadioButton(pDC, rect, bHighlighted, bOn, bEnabled, bPressed);
}

void CMFCVisualManagerWindows7::OnDrawRibbonButtonBorder(CDC* pDC, CMFCRibbonButton* pButton)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonButtonBorder(pDC, pButton);
		return;
	}

	if (pButton->IsKindOf(RUNTIME_CLASS(CMFCRibbonEdit)))
	{
		CRect rect(pButton->GetRect());

		COLORREF colorBorder = m_clrRibbonEditBorder;

		if (pButton->IsDisabled())
		{
			colorBorder = m_clrRibbonEditBorderDisabled;
		}
		else if (pButton->IsHighlighted() || pButton->IsDroppedDown() || pButton->IsFocused())
		{
			colorBorder = pButton->IsDroppedDown() ? m_clrRibbonEditBorderPressed : m_clrRibbonEditBorderHighlighted;
		}

		rect.left = pButton->GetCommandRect().left;

		if (CMFCToolBarImages::m_bIsDrawOnGlass)
		{
			CDrawingManager dm(*pDC);
			dm.DrawRect(rect, (COLORREF)-1, colorBorder);
		}
		else
		{
			pDC->Draw3dRect(rect, colorBorder, colorBorder);
		}
	}
}

void CMFCVisualManagerWindows7::OnDrawRibbonLaunchButton(CDC* pDC, CMFCRibbonLaunchButton* pButton, CMFCRibbonPanel* pPanel)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);
	ASSERT_VALID(pPanel);

	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonLaunchButton(pDC, pButton, pPanel);
		return;
	}

	CRect rect(pButton->GetRect());
	rect.right--;
	rect.bottom--;

	BOOL bHighlighted = pButton->IsHighlighted() || pButton->IsFocused();

	int index = 0;

	if (m_RibbonBtnLaunchIcon.GetCount() > 3)
	{
		if (pButton->IsDisabled())
		{
			index = 3;
		}
		else if (pButton->IsPressed())
		{
			if (bHighlighted)
			{
				index = 2;
			}
		}
		else if (bHighlighted)
		{
			index = 1;
		}
	}
	else
	{
		if (!pButton->IsDisabled())
		{
			if (pButton->IsPressed())
			{
				if (bHighlighted)
				{
					index = 2;
				}
			}
			else if (bHighlighted)
			{
				index = 1;
			}
		}
	}

	if (m_ctrlRibbonBtnLaunch.IsValid())
	{
		m_ctrlRibbonBtnLaunch.Draw(pDC, rect, index);
	}

	if (m_RibbonBtnLaunchIcon.IsValid())
	{
		const double dblImageScale = afxGlobalData.GetRibbonImageScale();

		if (dblImageScale == 1.)
		{
			m_RibbonBtnLaunchIcon.DrawEx(pDC, rect, index, CMFCToolBarImages::ImageAlignHorzCenter, CMFCToolBarImages::ImageAlignVertCenter);
		}
		else
		{
			CSize sizeImage = m_RibbonBtnLaunchIcon.GetImageSize();

			sizeImage.cx = (int)(.5 + dblImageScale * sizeImage.cx);
			sizeImage.cy = (int)(.5 + dblImageScale * sizeImage.cy);

			rect.left = rect.CenterPoint().x - sizeImage.cx / 2;
			rect.right = rect.left + sizeImage.cx;

			rect.top = rect.CenterPoint().y - sizeImage.cy / 2;
			rect.bottom = rect.top + sizeImage.cy;

			m_RibbonBtnLaunchIcon.DrawEx(pDC, rect, index, CMFCToolBarImages::ImageAlignHorzStretch, CMFCToolBarImages::ImageAlignVertStretch);
		}
	}
}

COLORREF CMFCVisualManagerWindows7::OnFillRibbonButton(CDC* pDC, CMFCRibbonButton* pButton)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::OnFillRibbonButton(pDC, pButton);
	}

	const BOOL bIsMenuMode = pButton->IsMenuMode();

	CRect rect(pButton->GetRect());

	CMFCControlRenderer* pRenderer = NULL;
	CMFCVisualManagerBitmapCache* pCache = NULL;
	int index = 0;

	BOOL bDisabled    = pButton->IsDisabled();
	BOOL bWasDisabled = bDisabled;
	BOOL bFocused     = pButton->IsFocused();
	BOOL bDroppedDown = pButton->IsDroppedDown();
	BOOL bPressed     = pButton->IsPressed() && !bIsMenuMode;
	BOOL bChecked     = pButton->IsChecked();
	BOOL bHighlighted = pButton->IsHighlighted() || bFocused;

	BOOL bDefaultPanelButton = pButton->IsDefaultPanelButton() && !pButton->IsQATMode();
	if (bFocused)
	{
		bDisabled = FALSE;
	}

	if (pButton->IsDroppedDown() && !bIsMenuMode)
	{
		bChecked     = TRUE;
		bPressed     = FALSE;
		bHighlighted = FALSE;
	}

	CMFCRibbonBaseElement::RibbonElementLocation location = pButton->GetLocationInGroup();

	if (pButton->IsKindOf(RUNTIME_CLASS(CMFCRibbonEdit)))
	{
		COLORREF color1 = m_clrRibbonEdit;
		if (bDisabled)
		{
			color1 = m_clrRibbonEditDisabled;
		}
		else if (bChecked || bHighlighted)
		{
			color1 = m_clrRibbonEditHighlighted;
		}

		COLORREF color2 = color1;

		rect.left = pButton->GetCommandRect().left;

		{
			CDrawingManager dm(*pDC);
			dm.FillGradient(rect, color1, color2, TRUE);
		}

		return (COLORREF)-1;
	}

	if (bChecked && bIsMenuMode && !pButton->IsGalleryIcon())
	{
		bChecked = FALSE;
	}

	if (location != CMFCRibbonBaseElement::RibbonElementNotInGroup && pButton->IsShowGroupBorder())
	{
		if (!pButton->GetMenuRect().IsRectEmpty())
		{
			CRect rectC = pButton->GetCommandRect();
			CRect rectM = pButton->GetMenuRect();

			CMFCControlRenderer* pRendererC = NULL;
			CMFCControlRenderer* pRendererM = NULL;

			CMFCVisualManagerBitmapCache* pCacheC = NULL;
			CMFCVisualManagerBitmapCache* pCacheM = NULL;

			if (location == CMFCRibbonBaseElement::RibbonElementSingleInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_F[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_L[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_F[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_L[1];
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementFirstInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_F[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_F[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_F[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_F[1];
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementLastInGroup)
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_L[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_L[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_L[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_L[1];
			}
			else
			{
				pRendererC = &m_ctrlRibbonBtnGroupMenu_M[0];
				pRendererM = &m_ctrlRibbonBtnGroupMenu_M[1];

				pCacheC = &m_cacheRibbonBtnGroupMenu_M[0];
				pCacheM = &m_cacheRibbonBtnGroupMenu_M[1];
			}

			int indexC = 0;
			int indexM = 0;

			BOOL bHighlightedC = pButton->IsCommandAreaHighlighted();
			BOOL bHighlightedM = pButton->IsMenuAreaHighlighted();

			if (bChecked)
			{
				indexC = 3;

				if (bHighlighted)
				{
					indexM = 5;
				}
			}

			if (bDisabled)
			{
				if (bChecked)
				{
					indexC = 5;
					indexM = 4;
				}
			}
			else
			{
				if (pButton->IsDroppedDown() && !bIsMenuMode)
				{
					indexC = pButton->IsChecked() ? 3 : 6;
					indexM = 3;
				}
				else
				{
					if (bFocused)
					{
						indexC = 6;
						indexM = 5;
					}

					if (bHighlightedC || bHighlightedM)
					{
						if (bChecked)
						{
							indexC = bHighlightedC ? 4 : 3;
						}
						else
						{
							indexC = bHighlightedC ? 1 : 6;
						}

						indexM = bHighlightedM ? 1 : 5;
					}

					if (bPressed)
					{
						if (bHighlightedC)
						{
							indexC = 2;
						}
					}
				}
			}

			if (indexC != -1 && indexM != -1)
			{
				int nCacheIndex = -1;
				if (pCacheC != NULL)
				{
					CSize size(rectC.Size());
					nCacheIndex = pCacheC->FindIndex(size);
					if (nCacheIndex == -1)
					{
						nCacheIndex = pCacheC->Cache(size, *pRendererC);
					}
				}

				if (nCacheIndex != -1)
				{
					pCacheC->Get(nCacheIndex)->Draw(pDC, rectC, indexC);
				}
				else
				{
					pRendererC->Draw(pDC, rectC, indexC);
				}

				nCacheIndex = -1;
				if (pCacheM != NULL)
				{
					CSize size(rectM.Size());
					nCacheIndex = pCacheM->FindIndex(size);
					if (nCacheIndex == -1)
					{
						nCacheIndex = pCacheM->Cache(size, *pRendererM);
					}
				}

				if (nCacheIndex != -1)
				{
					pCacheM->Get(nCacheIndex)->Draw(pDC, rectM, indexM);
				}
				else
				{
					pRendererM->Draw(pDC, rectM, indexM);
				}
			}

			return(COLORREF)-1;
		}
		else
		{
			if (location == CMFCRibbonBaseElement::RibbonElementSingleInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_S;
				pCache    = &m_cacheRibbonBtnGroup_S;
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementFirstInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_F;
				pCache    = &m_cacheRibbonBtnGroup_F;
			}
			else if (location == CMFCRibbonBaseElement::RibbonElementLastInGroup)
			{
				pRenderer = &m_ctrlRibbonBtnGroup_L;
				pCache    = &m_cacheRibbonBtnGroup_L;
			}
			else
			{
				pRenderer = &m_ctrlRibbonBtnGroup_M;
				pCache    = &m_cacheRibbonBtnGroup_M;
			}

			if (bChecked)
			{
				index = 3;
			}

			if (bDisabled && !bFocused)
			{
				index = 0;
			}
			else
			{
				if (bPressed)
				{
					if (bHighlighted)
					{
						index = 2;
					}
				}
				else if (bHighlighted)
				{
					index++;
				}
			}
		}
	}
	else if (bDefaultPanelButton)
	{
		if (bPressed)
		{
			if (bHighlighted)
			{
				index = 2;
			}
		}
		else if (bHighlighted)
		{
			index = 1;
		}
		else if (bChecked)
		{
			index = 2;
		}

		if (bFocused && !bDroppedDown && m_ctrlRibbonBtnDefault.GetImageCount () > 3)
		{
			index = 3;
		}

		if (index != -1)
		{
			pRenderer = &m_ctrlRibbonBtnDefault;
			CMFCVisualManagerBitmapCache* pCache = &m_cacheRibbonBtnDefault;

			const CMFCControlRendererInfo& params = pRenderer->GetParams();

			int nCacheIndex = -1;
			if (pCache != NULL)
			{
				CSize size(params.m_rectImage.Width(), rect.Height());
				nCacheIndex = pCache->FindIndex(size);
				if (nCacheIndex == -1)
				{
					nCacheIndex = pCache->CacheY(size.cy, *pRenderer);
				}
			}

			if (nCacheIndex != -1)
			{
				pCache->Get(nCacheIndex)->DrawY(pDC, rect, CSize(params.m_rectInter.left, params.m_rectImage.right - params.m_rectInter.right), index);

				return GetGlobalData()->clrBtnText;
			}
		}
	}
	else if ((!bDisabled &&(bPressed || bChecked || bHighlighted)) || (bDisabled && bFocused))
	{
		if (!pButton->GetMenuRect().IsRectEmpty()/* &&
												 (pButton->IsHighlighted() || bChecked)*/)
		{
			CRect rectC = pButton->GetCommandRect();
			CRect rectM = pButton->GetMenuRect();

			CMFCControlRenderer* pRendererC = pButton->IsMenuOnBottom() ? &m_ctrlRibbonBtnMenuV[0] : &m_ctrlRibbonBtnMenuH[0];
			CMFCControlRenderer* pRendererM = pButton->IsMenuOnBottom() ? &m_ctrlRibbonBtnMenuV[1] : &m_ctrlRibbonBtnMenuH[1];

			int indexC = -1;
			int indexM = -1;

			BOOL bDropped      = pButton->IsDroppedDown();
			BOOL bHighlightedC = pButton->IsCommandAreaHighlighted();
			BOOL bHighlightedM = pButton->IsMenuAreaHighlighted();

			if (bDisabled)
			{
				if (bHighlightedC || bHighlightedM)
				{
					indexC = 4;
					indexM = 4;

					if (bHighlightedM)
					{
						indexM = 0;

						if (bDropped && !bIsMenuMode)
						{
							indexC = 5;
							indexM = 2;
						}
						else if (bPressed)
						{
							indexM = 1;
						}
					}
				}
			}
			else
			{
				if (bDropped && !bIsMenuMode)
				{
					indexC = 5;
					indexM = 2;
				}
				else
				{
					if (bFocused)
					{
						indexC = 5;
						indexM = 4;
					}

					if (bChecked)
					{
						indexC = 2;
						indexM = 2;
					}

					if (bHighlightedC || bHighlightedM)
					{
						indexM = 4;

						if (bPressed)
						{
							if (bHighlightedC)
							{
								indexC = 1;
							}
							else if (bHighlightedM)
							{
								indexC = bChecked ? 3 : 5;
							}
						}
						else
						{
							indexC = bChecked ? 3 : 0;

							if (bHighlightedM)
							{
								indexC = bChecked ? 3 : 5;
								indexM = 0;
							}
						}
					}
				}
			}

			if (indexC != -1)
			{
				pRendererC->Draw(pDC, rectC, indexC);
			}

			if (indexM != -1)
			{
				pRendererM->Draw(pDC, rectM, indexM);
			}

			return(COLORREF)-1;
		}
		else
		{
			index = -1;

			pRenderer = &m_ctrlRibbonBtn[0];
			if (rect.Height() > pRenderer->GetParams().m_rectImage.Height() * 1.5 && m_ctrlRibbonBtn[1].IsValid())
			{
				pRenderer = &m_ctrlRibbonBtn[1];
			}

			if (bDisabled && bFocused)
			{
				if (pRenderer->GetImageCount() > 4)
				{
					index = 4;
				}
				else
				{
					index = 0;
				}
			}

			if (!bDisabled)
			{
				if (bChecked)
				{
					index = 2;
				}

				if (bPressed)
				{
					if (bHighlighted)
					{
						index = 1;
					}
				}
				else if (bHighlighted)
				{
					index++;
				}
			}
		}
	}

	COLORREF clrText = bWasDisabled ? GetGlobalData()->clrGrayedText : COLORREF(-1);

	if (pRenderer != NULL)
	{
		if (index != -1)
		{
			int nCacheIndex = -1;
			if (pCache != NULL)
			{
				CSize size(rect.Size());
				nCacheIndex = pCache->FindIndex(size);
				if (nCacheIndex == -1)
				{
					nCacheIndex = pCache->Cache(size, *pRenderer);
				}
			}

			if (nCacheIndex != -1)
			{
				pCache->Get(nCacheIndex)->Draw(pDC, rect, index);
			}
			else
			{
				pRenderer->Draw(pDC, rect, index);
			}

			if (!bWasDisabled)
			{
				clrText = GetGlobalData()->clrBtnText;
			}
		}
	}

	return clrText;
}

void CMFCVisualManagerWindows7::OnDrawRibbonMenuCheckFrame(CDC* pDC, CMFCRibbonButton* pButton, CRect rect)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonMenuCheckFrame(pDC, pButton, rect);
		return;
	}

	ASSERT_VALID(pDC);

	m_ctrlMenuItemBack.Draw(pDC, rect);
}

void CMFCVisualManagerWindows7::OnFillRibbonQuickAccessToolBarPopup(CDC* pDC, CMFCRibbonPanelMenuBar* pMenuBar, CRect rect)
{
	if (!CanDrawImage() || !m_ctrlRibbonBorder_QAT.IsValid())
	{
		CMFCVisualManagerWindows::OnFillRibbonQuickAccessToolBarPopup(pDC, pMenuBar, rect);
		return;
	}

	ASSERT_VALID (pDC);

	m_ctrlRibbonBorder_QAT.FillInterior(pDC, rect);
}

int CMFCVisualManagerWindows7::GetRibbonPopupBorderSize(const CMFCRibbonPanelMenu* pPopup) const
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::GetRibbonPopupBorderSize(pPopup);
	}

	if (pPopup != NULL)
	{
		ASSERT_VALID(pPopup);

		CMFCRibbonPanelMenuBar* pRibbonMenuBar = DYNAMIC_DOWNCAST(CMFCRibbonPanelMenuBar, (const_cast<CMFCRibbonPanelMenu*>(pPopup))->GetMenuBar());

		if (pRibbonMenuBar != NULL)
		{
			if (pRibbonMenuBar->IsMainPanel())
			{
				return m_ctrlRibbonMainPanel.GetParams().m_rectSides.left;
			}

			if (!pRibbonMenuBar->IsMenuMode())
			{
				if (pRibbonMenuBar->IsQATPopup())
				{
					if (m_ctrlRibbonBorder_QAT.IsValid())
					{
						return m_ctrlRibbonBorder_QAT.GetParams().m_rectSides.left;
					}
				}
				else if (pRibbonMenuBar->IsCategoryPopup())
				{
					return 0;
				}
				else if (pRibbonMenuBar->IsRibbonMiniToolBar())
				{
				}
				else
				{
					if (pRibbonMenuBar->GetPanel() != NULL)
					{
						if (m_ctrlRibbonBorder_Panel.IsValid())
						{
							return m_ctrlRibbonBorder_Panel.GetParams().m_rectSides.left;
						}
					}
				}
			}
		}
	}

	return(int)GetPopupMenuBorderSize();
}

void CMFCVisualManagerWindows7::OnDrawRibbonDefaultPaneButton(CDC* pDC, CMFCRibbonButton* pButton)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonDefaultPaneButton(pDC, pButton);
		return;
	}

	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	OnFillRibbonButton(pDC, pButton);

	BOOL bIsQATMode = pButton->IsQATMode();

	CRect rectFrame(pButton->GetRect());

	if (!bIsQATMode)
	{
		if (m_ctrlRibbonBtnDefaultIcon.IsValid())
		{
			const CSize sizeImage = pButton->GetImageSize(CMFCRibbonButton::RibbonImageSmall);
			const int nMarginX = 11;
			const int nMarginY = 10;
			
			rectFrame.top += nMarginY / 2;
			rectFrame.bottom = rectFrame.top + sizeImage.cy + 2 * nMarginY;
			rectFrame.top -= 2;
			rectFrame.left = rectFrame.CenterPoint ().x - sizeImage.cx / 2 - nMarginX;
			rectFrame.right = rectFrame.left + sizeImage.cx + 2 * nMarginX;

			m_ctrlRibbonBtnDefaultIcon.Draw(pDC, rectFrame);
		}
	}
	else
	{
		if (m_ctrlRibbonBtnDefaultQAT.IsValid())
		{
			int index = 0;
			if (pButton->IsDroppedDown())
			{
				index = 2;
			}
			else if (pButton->IsPressed())
			{
				if (pButton->IsHighlighted())
				{
					index = 2;
				}
			}
			else if (pButton->IsHighlighted() || pButton->IsFocused())
			{
				index = 1;
			}

			m_ctrlRibbonBtnDefaultQAT.Draw(pDC, rectFrame, index);
		}
	}

	OnDrawRibbonDefaultPaneButtonContext(pDC, pButton);
}

void CMFCVisualManagerWindows7::OnDrawRibbonRecentFilesFrame(CDC* pDC, CMFCRibbonMainPanel* pPanel, CRect rect)
{
	if (!CanDrawImage())
	{
		CMFCVisualManagerWindows::OnDrawRibbonRecentFilesFrame(pDC, pPanel, rect);
		return;
	}

	ASSERT_VALID(pDC);

	rect.right += 2;
	pDC->FillRect(rect, &m_brBarBkgnd);

	CRect rectSeparator = rect;
	rectSeparator.right = rectSeparator.left + 2;

	pDC->Draw3dRect(rectSeparator, GetGlobalData()->clrBtnShadow, GetGlobalData()->clrBtnHilite);
}

void CMFCVisualManagerWindows7::OnDrawComboDropButton(CDC* pDC, CRect rect, BOOL bDisabled, BOOL bIsDropped, BOOL bIsHighlighted, CMFCToolBarComboBoxButton* pButton)
{
	if (!CanDrawImage () || !pButton->IsRibbonButton())
	{
		CMFCVisualManagerWindows::OnDrawComboDropButton(pDC, rect, bDisabled, bIsDropped, bIsHighlighted, pButton);
		return;
	}

	rect.InflateRect(0, 1, 1, 1);

	int nIndex = 0;
	if (bDisabled)
	{
		nIndex = 3;
	}
	else
	{
		if (bIsDropped)
		{
			nIndex = 2;
		}
		else if (bIsHighlighted)
		{
			nIndex = 1;
		}
	}

	m_ctrlRibbonComboBoxBtn.Draw(pDC, rect, nIndex);

	rect.DeflateRect(0, 1, 1, 1);

	rect.bottom -= 2;

	CMenuImages::Draw(pDC, CMenuImages::IdArrowDown, rect, bDisabled ? CMenuImages::ImageGray : CMenuImages::ImageBlack);
}

COLORREF CMFCVisualManagerWindows7::OnDrawMenuLabel(CDC* pDC, CRect rect)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::OnDrawMenuLabel (pDC, rect);
	}

	ASSERT_VALID(pDC);

	pDC->FillRect(rect, &m_brRibbonBarBkgnd);

	CRect rectSeparator = rect;
	rectSeparator.top = rectSeparator.bottom - 2;

	DrawSeparator(pDC, rectSeparator, m_penSeparatorDark, m_penSeparatorLight, TRUE);

	return GetGlobalData()->clrBarText;
}

COLORREF CMFCVisualManagerWindows7::GetRibbonEditBackgroundColor(CMFCRibbonRichEditCtrl* pEdit, BOOL bIsHighlighted, BOOL bIsPaneHighlighted, BOOL bIsDisabled)
{
	if (!CanDrawImage())
	{
		return CMFCVisualManagerWindows::GetRibbonEditBackgroundColor(pEdit, bIsHighlighted, bIsPaneHighlighted, bIsDisabled);
	}

	COLORREF color = m_clrRibbonEdit;

	if (bIsDisabled)
	{
		color = m_clrRibbonEditDisabled;
	}
	else
	{
		if (bIsHighlighted)
		{
			color = m_clrRibbonEditHighlighted;
		}
	}

	return color;
}

BOOL CMFCVisualManagerWindows7::IsWindowActive(CWnd* pWnd) const
{
	BOOL bActive = FALSE;

	HWND hWnd = pWnd->GetSafeHwnd();

	if (hWnd != NULL)
	{
		if (!m_ActivateFlag.Lookup(pWnd->GetSafeHwnd(), bActive))
		{
			//ASSERT(FALSE);
			bActive = TRUE;
		}
	}

	return bActive;
}

BOOL CMFCVisualManagerWindows7::OnNcActivate(CWnd* pWnd, BOOL bActive)
{
	ASSERT_VALID(pWnd);

	if (pWnd->GetSafeHwnd() == NULL)
	{
		return FALSE;
	}

	if (GetGlobalData()->IsDwmCompositionEnabled())
	{
		return FALSE;
	}

	// stay active if WF_STAYACTIVE bit is on
	if (pWnd->m_nFlags & WF_STAYACTIVE)
	{
		bActive = TRUE;
	}

	// but do not stay active if the window is disabled
	if (!pWnd->IsWindowEnabled())
	{
		bActive = FALSE;
	}

	BOOL bIsMDIFrame = FALSE;
	BOOL bWasActive = FALSE;

	// If the active state of an owner-draw MDI frame window changes, we need to
	// invalidate the MDI client area so the MDI child window captions are redrawn.
	if (IsOwnerDrawCaption())
	{
		bIsMDIFrame = pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd));
		bWasActive = IsWindowActive(pWnd);
	}

	m_ActivateFlag[pWnd->GetSafeHwnd()] = bActive;
	pWnd->SendMessage(WM_NCPAINT, 0, 0);

	if (IsOwnerDrawCaption())
	{
		if (bIsMDIFrame &&(bWasActive != bActive))
		{
			::RedrawWindow(((CMDIFrameWnd *)pWnd)->m_hWndMDIClient, NULL, NULL, RDW_INVALIDATE | RDW_ALLCHILDREN);
		}
	}

	return TRUE;
}

BOOL CMFCVisualManagerWindows7::OnNcPaint(CWnd* pWnd, const CObList& lstSysButtons, CRect rectRedraw)
{
	UNREFERENCED_PARAMETER(lstSysButtons);


	if (GetGlobalData()->IsDwmCompositionEnabled())
	{
		return FALSE;
	}

	if (pWnd->GetSafeHwnd() == NULL || m_hThemeWindow == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pWnd);

	CMFCRibbonBar* pBar = GetRibbonBar(pWnd);
	BOOL bRibbonCaption  = pBar != NULL && pBar->IsWindowVisible() && pBar->IsReplaceFrameCaption();
	if (!bRibbonCaption)
	{
		return FALSE;
	}
	else
	{
		const DWORD dwStyle = pWnd->GetStyle();
		BOOL bMaximized = (dwStyle & WS_MAXIMIZE) == WS_MAXIMIZE;
		if (bMaximized)
		{
			return TRUE;
		}
	}

	CWindowDC dc(pWnd);

	if (dc.GetSafeHdc() != NULL)
	{
		CRgn rgn;
		if (!rectRedraw.IsRectEmpty())
		{
			rgn.CreateRectRgnIndirect(rectRedraw);
			dc.SelectClipRgn(&rgn);
		}

		CRect rtWindow;
		pWnd->GetWindowRect(rtWindow);
		pWnd->ScreenToClient(rtWindow);

		CRect rtClient;
		pWnd->GetClientRect(rtClient);

		rtClient.OffsetRect(-rtWindow.TopLeft());
		dc.ExcludeClipRect(rtClient);

		rtWindow.OffsetRect(-rtWindow.TopLeft());

		BOOL bActive = IsWindowActive(pWnd);

		// Modify bActive(if currently TRUE) for owner-drawn MDI child windows: draw child
		// frame active only if window is active MDI child and the MDI frame window is active.
		if (bActive && IsOwnerDrawCaption() && pWnd->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
		{
			CMDIFrameWnd *pParent = ((CMDIChildWnd *)pWnd)->GetMDIFrame();
			if (pParent)
			{
				CMDIChildWnd *pActiveChild = pParent->MDIGetActive(NULL);
				if (pActiveChild)
				{
					bActive = ((pActiveChild->GetSafeHwnd() == pWnd->GetSafeHwnd()) && IsWindowActive(pParent));
				}
			}
		}

		CRect rectCaption(rtWindow);
		CSize szSysBorders(GetSystemBorders(bRibbonCaption));

		rectCaption.bottom = rectCaption.top + szSysBorders.cy + pBar->GetCaptionHeight();

		DrawThemeBackground(m_hThemeWindow, dc.GetSafeHdc(), WP_CAPTION, bActive ? CS_ACTIVE : CS_INACTIVE, &rectCaption, 0);

		rtWindow.top = rectCaption.bottom;
		dc.ExcludeClipRect(rectCaption);

		FRAMESTATES framestate = bActive ? FS_ACTIVE : FS_INACTIVE;

		CRect rectPart(rtWindow);
		rectPart.top = rectPart.bottom - szSysBorders.cy;
		DrawThemeBackground(m_hThemeWindow, dc.GetSafeHdc(), WP_FRAMEBOTTOM, framestate, &rectPart, 0);

		rectPart.bottom = rectPart.top;
		rectPart.top = rtWindow.top;
		rectPart.right = rectPart.left + szSysBorders.cx;
		DrawThemeBackground(m_hThemeWindow, dc.GetSafeHdc(), WP_FRAMELEFT, framestate, &rectPart, 0);

		rectPart.right = rtWindow.right;
		rectPart.left = rectPart.right - szSysBorders.cx;
		DrawThemeBackground(m_hThemeWindow, dc.GetSafeHdc(), WP_FRAMERIGHT, framestate, &rectPart, 0);

		dc.SelectClipRgn(NULL);

		return TRUE;
	}

	return FALSE;
}

CSize CMFCVisualManagerWindows7::GetSystemBorders(BOOL bRibbonPresent) const
{
	CSize size(::GetSystemMetrics(SM_CYSIZEFRAME), ::GetSystemMetrics(SM_CXSIZEFRAME));

	if (bRibbonPresent)
	{
		size.cx--;
		size.cy--;
	}

	return size;
}

CMFCRibbonBar* CMFCVisualManagerWindows7::GetRibbonBar(CWnd* pWnd) const
{
	CMFCRibbonBar* pBar = NULL;

	if (pWnd == NULL)
	{
		pWnd = AfxGetMainWnd();
	}

	if (pWnd->GetSafeHwnd() == NULL)
	{
		return NULL;
	}

	if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWndEx)))
	{
		pBar = ((CFrameWndEx*) pWnd)->GetRibbonBar();
	}
	else if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		pBar = ((CMDIFrameWndEx*) pWnd)->GetRibbonBar();
	}

	return pBar;
}

BOOL CMFCVisualManagerWindows7::IsRibbonPresent(CWnd* pWnd) const
{
	CMFCRibbonBar* pBar = GetRibbonBar(pWnd);

	return pBar != NULL && pBar->IsWindowVisible();
}
