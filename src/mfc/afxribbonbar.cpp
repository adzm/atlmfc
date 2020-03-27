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
#include "afxcontextmenumanager.h"
#include "afxribbonbar.h"
#include "afxribboncategory.h"
#include "afxribbonbutton.h"
#include "afxframewndex.h"
#include "afxmdiframewndex.h"
#include "afxvisualmanager.h"
#include "afxtooltipmanager.h"
#include "afxtooltipctrl.h"
#include "afxtoolbarmenubutton.h"
#include "afxregpath.h"
#include "afxsettingsstore.h"
#include "afxribbonpanel.h"
#include "afxribbonpanelmenu.h"
#include "afxribbonmainpanel.h"
#include "afxribboncustomizedialog.h"
#include "afxribbonedit.h"
#include "afxkeyboardmanager.h"
#include "afxribbonkeytip.h"
#include "afxribboninfoloader.h"
#include "afxribboncollector.h"
#include "afxribbonconstructor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UINT AFX_WM_POSTRECALCLAYOUT = ::RegisterWindowMessage(_T("AFX_WM_POSTRECALCLAYOUT"));
UINT AFX_WM_ON_CHANGE_RIBBON_CATEGORY = ::RegisterWindowMessage(_T("AFX_WM_ON_CHANGE_RIBBON_CATEGORY"));
UINT AFX_WM_ON_RIBBON_CUSTOMIZE = ::RegisterWindowMessage(_T("AFX_WM_ON_RIBBON_CUSTOMIZE"));
UINT AFX_WM_ON_HIGHLIGHT_RIBBON_LIST_ITEM = ::RegisterWindowMessage(_T("AFX_WM_ON_HIGHLIGHT_RIBBON_LIST_ITEM"));
UINT AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU = ::RegisterWindowMessage(_T("AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU"));

static const int nMinRibbonWidth = 300;

static const int nTooltipMinWidthDefault = 210;
static const int nTooltipWithImageMinWidthDefault = 318;
static const int nTooltipMaxWidth = 640;

static const int nXTabMargin = 14;
static const int nYTabMargin = 5;

static const int nXMargin = 2;
static const int nYMargin = 2;

static const int nIdToolTipClient = 1;
static const int nIdToolTipCaption = 2;

static const UINT idCut = (UINT) -10002;
static const UINT idCopy = (UINT) -10003;
static const UINT idPaste = (UINT) -10004;
static const UINT idSelectAll = (UINT) -10005;

#define AFX_REG_SECTION_FMT _T("%TsMFCRibbonBar-%d")
#define AFX_REG_SECTION_FMT_EX _T("%TsMFCRibbonBar-%d%x")

#define AFX_REG_ENTRY_QA_TOOLBAR_LOCATION _T("QuickAccessToolbarOnTop")
#define AFX_REG_ENTRY_QA_TOOLBAR_COMMANDS _T("QuickAccessToolbarCommands")
#define AFX_REG_ENTRY_RIBBON_IS_MINIMIZED _T("IsMinimized")

#ifdef _UNICODE
#define AFX_TCF_TEXT CF_UNICODETEXT
#else
#define AFX_TCF_TEXT CF_TEXT
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonBar idle update through CMFCRibbonCmdUI class

CMFCRibbonCmdUI::CMFCRibbonCmdUI()
{
	m_pUpdated = NULL;
}

void CMFCRibbonCmdUI::Enable(BOOL bOn)
{
	m_bEnableChanged = TRUE;

	ASSERT_VALID(m_pOther);
	ASSERT_VALID(m_pUpdated);

	const BOOL bIsDisabled = !bOn;

	if (m_pUpdated->IsDisabled() != bIsDisabled)
	{
		m_pUpdated->m_bIsDisabled = bIsDisabled;
		m_pUpdated->OnEnable(!bIsDisabled);
		m_pOther->RedrawWindow(m_pUpdated->GetRect());
	}
}

void CMFCRibbonCmdUI::SetCheck(int nCheck)
{
	ASSERT_VALID(m_pOther);
	ASSERT_VALID(m_pUpdated);

	if (m_pUpdated->IsChecked() != (BOOL)nCheck)
	{
		m_pUpdated->m_bIsChecked = (BOOL)nCheck;
		m_pUpdated->OnCheck((BOOL)nCheck);
		m_pOther->RedrawWindow(m_pUpdated->GetRect());
	}
}

void CMFCRibbonCmdUI::SetRadio(BOOL bOn)
{
	ASSERT_VALID(m_pUpdated);

	m_pUpdated->m_bIsRadio = bOn;
	SetCheck(bOn ? 1 : 0);
}

void CMFCRibbonCmdUI::SetText(LPCTSTR lpszText)
{
	ENSURE(lpszText != NULL);

	ASSERT_VALID(m_pOther);
	ASSERT_VALID(m_pUpdated);

	if (lstrcmp(m_pUpdated->GetText(), lpszText) != 0)
	{
		m_pUpdated->SetText(lpszText);
		m_pOther->RedrawWindow(m_pUpdated->GetRect());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonCaptionButton

IMPLEMENT_DYNCREATE(CMFCRibbonCaptionButton, CMFCRibbonButton)

CMFCRibbonCaptionButton::CMFCRibbonCaptionButton(UINT uiCmd, HWND hwndMDIChild)
{
	m_nID = uiCmd;
	m_hwndMDIChild = hwndMDIChild;
}

void CMFCRibbonCaptionButton::OnDraw(CDC* pDC)
{
	ASSERT_VALID(pDC);

	CMFCVisualManager::GetInstance()->OnDrawRibbonCaptionButton
		(pDC, this);
}

void CMFCRibbonCaptionButton::OnLButtonUp(CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT(m_nID != 0);

	if (IsPressed() && IsHighlighted())
	{
		if (m_hwndMDIChild != NULL)
		{
			::PostMessage(m_hwndMDIChild, WM_SYSCOMMAND, m_nID, 0);
		}
		else
		{
			ASSERT_VALID(m_pRibbonBar);
			m_pRibbonBar->GetParent()->PostMessage(WM_SYSCOMMAND, m_nID);
		}

		m_bIsHighlighted = FALSE;
	}
}

CSize CMFCRibbonCaptionButton::GetRegularSize(CDC* /*pDC*/)
{
	ASSERT_VALID(this);
	return CSize(::GetSystemMetrics(SM_CXMENUSIZE), ::GetSystemMetrics(SM_CYMENUSIZE));
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonContextCaption

IMPLEMENT_DYNCREATE(CMFCRibbonContextCaption, CMFCRibbonButton)

CMFCRibbonContextCaption::CMFCRibbonContextCaption(LPCTSTR lpszName, UINT uiID, AFX_RibbonCategoryColor clrContext)
{
	m_strText = lpszName;
	m_uiID = uiID;
	m_Color = clrContext;
	m_nRightTabX = -1;
}

CMFCRibbonContextCaption::CMFCRibbonContextCaption()
{
	m_uiID = 0;
	m_Color = AFX_CategoryColor_None;
	m_nRightTabX = -1;
}

void CMFCRibbonContextCaption::OnDraw(CDC* pDC)
{
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	COLORREF clrText = CMFCVisualManager::GetInstance()->OnDrawRibbonCategoryCaption(pDC, this);
	COLORREF clrTextOld = pDC->SetTextColor(clrText);

	CRect rectText = m_rect;

	const UINT uiDTFlags = DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX;

	if (GetParentRibbonBar()->IsTransparentCaption())
	{
		const BOOL bIsZoomed = GetParentRibbonBar()->GetParent()->IsZoomed();
		CMFCVisualManager::GetInstance()->DrawTextOnGlass(pDC, m_strText, rectText, uiDTFlags, bIsZoomed ? 0 : 10, bIsZoomed ? RGB(255, 255, 255) :(COLORREF)-1);
	}
	else
	{
		pDC->DrawText(m_strText, rectText, uiDTFlags);
	}

	pDC->SetTextColor(clrTextOld);
}

void CMFCRibbonContextCaption::OnLButtonUp(CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	if (m_pRibbonBar->GetActiveCategory() != NULL && m_pRibbonBar->GetActiveCategory()->GetContextID() == m_uiID &&
		(m_pRibbonBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
	{
		return;
	}

	for (int i = 0; i < m_pRibbonBar->GetCategoryCount(); i++)
	{
		CMFCRibbonCategory* pCategory = m_pRibbonBar->GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() == m_uiID)
		{
			m_pRibbonBar->SetActiveCategory(pCategory, m_pRibbonBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS);
			return;
		}
	}
}

int CMFCRibbonContextCaption::GetContextCategoryCount()
{
	ASSERT_VALID(this);

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return 0;
	}

	int nCount = 0;
	for (int i = 0; i < m_pRibbonBar->GetCategoryCount(); i++)
	{
		CMFCRibbonCategory* pCategory = m_pRibbonBar->GetCategory(i);
		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);

			if (pCategory->GetContextID() == m_uiID && pCategory->IsVisible())
			{
				nCount++;
			}
		}
	}

	return nCount;
}

BOOL CMFCRibbonContextCaption::OnSetAccData(long lVal)
{
	ASSERT_VALID(this);

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return FALSE;
	}

	CArray<CMFCRibbonCategory*,CMFCRibbonCategory*> arCategories;
	GetContextCategories(arCategories);

	int nIndex = lVal - 1;
	if (nIndex >= 0 && nIndex < (int)arCategories.GetSize())
	{
		CMFCRibbonCategory* pCategory = arCategories[nIndex];
		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);

			CMFCRibbonTab* pTab = pCategory->GetTab();
			if (pTab != NULL)
			{
				ASSERT_VALID(pTab);
				return pTab->SetACCData(m_pRibbonBar, m_AccData);
			}
		}
	}

	return FALSE;
}

void CMFCRibbonContextCaption::GetContextCategories(CArray<CMFCRibbonCategory*,CMFCRibbonCategory*>& arCategories)
{
	ASSERT_VALID(this);

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return;
	}

	for (int i = 0; i < m_pRibbonBar->GetCategoryCount(); i++)
	{
		CMFCRibbonCategory* pCategory = m_pRibbonBar->GetCategory(i);
		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);

			if (pCategory->GetContextID() == m_uiID && pCategory->IsVisible())
			{
				arCategories.Add(pCategory);
			}
		}
	}
}

int CMFCRibbonContextCaption::GetContextCaptionIndex(CMFCRibbonContextCaption* pContextCaption)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pContextCaption);

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return -1;
	}

	CArray<CMFCRibbonContextCaption*, CMFCRibbonContextCaption*> arCaptions;
	m_pRibbonBar->GetVisibleContextCaptions(arCaptions);

	for (int i = 0; i < (int)arCaptions.GetSize(); i++)
	{
		if (arCaptions[i] == pContextCaption)
		{
			return i;
		}
	}

	return -1;
}

BOOL CMFCRibbonContextCaption::SetACCData(CWnd* pParent, CAccessibilityData& data)
{
	CMFCRibbonButton::SetACCData(pParent, data);

	data.m_nAccRole = ROLE_SYSTEM_PUSHBUTTON;
	data.m_bAccState = STATE_SYSTEM_NORMAL;

	return TRUE;
}

HRESULT CMFCRibbonContextCaption::get_accParent(IDispatch **ppdispParent)
{
	if (!ppdispParent)
	{
		return E_INVALIDARG;
	}

	*ppdispParent = NULL;

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	LPDISPATCH lpDispatch = m_pRibbonBar->GetAccessibleDispatch();
	if (lpDispatch != NULL)
	{
		*ppdispParent =  lpDispatch;
		return S_OK;
	}

	return S_OK;
}

HRESULT CMFCRibbonContextCaption::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	int count = GetContextCategoryCount();

	*pcountChildren = count;
	return S_OK;
}

HRESULT CMFCRibbonContextCaption::accDoDefaultAction(VARIANT varChild)
{
	if (varChild.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	CArray<CMFCRibbonCategory*,CMFCRibbonCategory*> arCategories;
	GetContextCategories(arCategories);

	if (varChild.lVal == CHILDID_SELF && (int)arCategories.GetSize() > 0)
	{
		CMFCRibbonCategory* pCategory = arCategories[0];
		if (pCategory != NULL && pCategory->GetTab() != NULL)
		{
			pCategory->GetTab()->OnAccDefaultAction();
			return S_OK;
		}
	}

	if (varChild.lVal != CHILDID_SELF)
	{
		int nIndex = (int)varChild.lVal - 1;
		if (nIndex < 0 || nIndex >= (int)arCategories.GetSize())
		{
			return E_INVALIDARG;
		}

		CMFCRibbonCategory* pCategory = arCategories[nIndex];
		if (pCategory != NULL && pCategory->GetTab() != NULL)
		{
			pCategory->GetTab()->OnAccDefaultAction();
			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CMFCRibbonContextCaption::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	CArray<CMFCRibbonCategory*,CMFCRibbonCategory*> arCategories;
	GetContextCategories(arCategories);

	switch (navDir)
	{
	case NAVDIR_FIRSTCHILD:
		if (varStart.lVal == CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = 1;
			return S_OK;
		}
		break;

	case NAVDIR_LASTCHILD:
		if (varStart.lVal == CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = (long)arCategories.GetSize();
			return S_OK;
		}
		break;

	case NAVDIR_NEXT:
	case NAVDIR_RIGHT:
		if (varStart.lVal != CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = varStart.lVal + 1;
			if (pvarEndUpAt->lVal > (long)arCategories.GetSize())
			{
				pvarEndUpAt->vt = VT_EMPTY;
				return S_FALSE;
			}
			return S_OK;
		}
		else
		{
			CArray<CMFCRibbonContextCaption*, CMFCRibbonContextCaption*> arCaptions;
			m_pRibbonBar->GetVisibleContextCaptions(arCaptions);

			int nIndex = GetContextCaptionIndex(this) + 1;
			if (nIndex < (int)arCaptions.GetSize())
			{
				CMFCRibbonContextCaption* pCaption = arCaptions[nIndex];
				if (pCaption != NULL)
				{
					ASSERT_VALID(pCaption);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pCaption->GetIDispatch(TRUE);

					return S_OK;
				}
			}

			CMFCRibbonTabsGroup* pTabs = m_pRibbonBar->GetTabs();
			if (pTabs != NULL)
			{
				ASSERT_VALID(pTabs);

				pvarEndUpAt->vt = VT_DISPATCH;
				pvarEndUpAt->pdispVal = pTabs->GetIDispatch(TRUE);

				return S_OK;
			}
		}
		break;

	case NAVDIR_PREVIOUS:
	case NAVDIR_LEFT:
		if (varStart.lVal != CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = varStart.lVal - 1;

			if (pvarEndUpAt->lVal <= 0)
			{
				pvarEndUpAt->vt = VT_EMPTY;
				return S_FALSE;
			}

			return S_OK;
		}
		else
		{
			CArray<CMFCRibbonContextCaption*, CMFCRibbonContextCaption*> arCaptions;
			m_pRibbonBar->GetVisibleContextCaptions(arCaptions);

			int nIndex = GetContextCaptionIndex (this) - 1;
			if (nIndex > 0)
			{
				CMFCRibbonContextCaption* pCaption = arCaptions[nIndex];
				if (pCaption != NULL)
				{
					ASSERT_VALID(pCaption);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pCaption->GetIDispatch(TRUE);

					return S_OK;
				}
			}

			if (m_pRibbonBar->GetQuickAccessToolbar() != NULL && m_pRibbonBar->GetQuickAccessToolbar()->IsVisible())
			{
				pvarEndUpAt->vt = VT_DISPATCH;
				pvarEndUpAt->pdispVal = m_pRibbonBar->GetQuickAccessToolbar()->GetIDispatch(TRUE);

				return S_OK;
			}
			else
			{
				CMFCRibbonApplicationButton* pMainButton = m_pRibbonBar->GetApplicationButton();
				if (pMainButton != NULL)
				{
					ASSERT_VALID(pMainButton);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pMainButton->GetIDispatch(TRUE);

					return S_OK;
				}
			}
		}
		break;
	}

	return S_FALSE;
}

IMPLEMENT_DYNCREATE(CMFCRibbonApplicationButton, CMFCRibbonButton);

//////////////////////////////////////////////////////////////////////
// CMFCRibbonApplicationButton

void CMFCRibbonApplicationButton::SetImage(UINT uiBmpResID)
{
	ASSERT_VALID(this);

	if (m_Image.IsValid())
	{
		m_Image.Clear();
	}

	m_Image.Load(uiBmpResID, NULL, TRUE);
	m_Image.SetSingleImage();

	if (m_Image.IsValid() && m_Image.GetBitsPerPixel() < 32)
	{
		m_Image.ConvertTo32Bits(GetGlobalData()->clrBtnFace);
	}
}

void CMFCRibbonApplicationButton::SetImage(HBITMAP hBmp)
{
	ASSERT_VALID(this);

	if (m_Image.IsValid())
	{
		m_Image.Clear();
	}

	if (hBmp == NULL)
	{
		return;
	}

	m_Image.AddImage(hBmp, TRUE);
	m_Image.SetSingleImage();

	if (m_Image.IsValid() && m_Image.GetBitsPerPixel() < 32)
	{
		m_Image.ConvertTo32Bits(GetGlobalData()->clrBtnFace);
	}
}

void CMFCRibbonApplicationButton::SetWindows7Image(UINT uiBmpResID)
{
	ASSERT_VALID(this);

	if (m_ImageWindows7.IsValid())
	{
		m_ImageWindows7.Clear();
	}

	m_ImageWindows7.Load(uiBmpResID, NULL, TRUE);
	m_ImageWindows7.SetSingleImage();

	if (m_ImageWindows7.IsValid() && m_ImageWindows7.GetBitsPerPixel() < 32)
	{
		m_ImageWindows7.ConvertTo32Bits(GetGlobalData()->clrBtnFace);
	}
}

void CMFCRibbonApplicationButton::SetWindows7Image(HBITMAP hBmp)
{
	ASSERT_VALID(this);

	if (m_ImageWindows7.IsValid())
	{
		m_ImageWindows7.Clear();
	}

	if (hBmp == NULL)
	{
		return;
	}

	m_ImageWindows7.AddImage(hBmp, TRUE);
	m_ImageWindows7.SetSingleImage();

	if (m_ImageWindows7.IsValid() && m_ImageWindows7.GetBitsPerPixel() < 32)
	{
		m_ImageWindows7.ConvertTo32Bits(GetGlobalData()->clrBtnFace);
	}
}

void CMFCRibbonApplicationButton::OnLButtonDblClk(CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	m_pRibbonBar->GetParent()->PostMessage(WM_SYSCOMMAND, SC_CLOSE);
}

void CMFCRibbonApplicationButton::OnLButtonDown(CPoint point)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	if (m_pRibbonBar->GetMainCategory() == NULL)
	{
		CMFCRibbonButton::OnLButtonDown(point);
		return;
	}

	CMFCRibbonBaseElement::OnLButtonDown(point);

	ASSERT_VALID(m_pRibbonBar->GetMainCategory());

	if (!ShowMainMenu())
	{
		CMFCRibbonButton::OnLButtonDown(point);
	}
}

void CMFCRibbonApplicationButton::DrawImage(CDC* pDC, RibbonImageType /*type*/, CRect rectImage)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	CMFCToolBarImages* pImage = &m_Image;
	CMFCToolBarImages::ImageAlignHorz horz = CMFCToolBarImages::ImageAlignHorzLeft;
	CMFCToolBarImages::ImageAlignVert vert = CMFCToolBarImages::ImageAlignVertTop;

	if (m_pRibbonBar->IsWindows7Look())
	{
		double scale = GetGlobalData()->GetRibbonImageScale();

		if (m_ImageWindows7.IsValid())
		{
			pImage = &m_ImageWindows7;
		}

		horz = CMFCToolBarImages::ImageAlignHorzCenter;
		vert = CMFCToolBarImages::ImageAlignVertCenter;

		CSize sizeImage(pImage->GetImageSize());

		CSize sizeIdeal(16, 16);
		if (scale > 1.)
		{
			sizeIdeal.cx = (int)(.5 + scale * sizeIdeal.cx);
			sizeIdeal.cy = (int)(.5 + scale * sizeIdeal.cy);
		}

		if (sizeImage.cx > sizeIdeal.cx)
		{
			sizeImage.cx = sizeIdeal.cx;
			horz = CMFCToolBarImages::ImageAlignHorzStretch;
		}
		if (sizeImage.cy > sizeIdeal.cy)
		{
			sizeImage.cy = sizeIdeal.cy;
			vert = CMFCToolBarImages::ImageAlignVertStretch;
		}

		rectImage.left += (rectImage.Width() - sizeImage.cx) / 2;
		rectImage.right = rectImage.left + sizeImage.cx;
		rectImage.top += (rectImage.Height() - sizeImage.cy) / 2;
		rectImage.bottom = rectImage.top + sizeImage.cy;

		CSize sizeArrow (CMenuImages::Size());
		if (scale > 1.)
		{
			sizeArrow.cx = (int)(.5 + scale * sizeArrow.cx);
			sizeArrow.cy = (int)(.5 + scale * sizeArrow.cy);
		}

		CRect rectArrow(CPoint(rectImage.right - sizeArrow.cx / 2 + nXMargin,
			rectImage.top + (sizeImage.cy - sizeArrow.cy) / 2), sizeArrow);

		CRect rectWhite = rectArrow;
		rectWhite.OffsetRect(0, 1);

		CMenuImages::IMAGES_IDS id =
			scale > 1. ?
			CMenuImages::IdArrowDownLarge : CMenuImages::IdArrowDown;

		CMenuImages::Draw(pDC, id, rectWhite, CMenuImages::ImageWhite);
		CMenuImages::Draw(pDC, id, rectArrow, m_bIsDisabled ? CMenuImages::ImageGray : CMenuImages::ImageBlack);


		rectImage.OffsetRect(-sizeArrow.cx / 2, 0);
	}
	else if (GetGlobalData()->GetRibbonImageScale() != 1.)
	{
		const CSize sizeImage = m_Image.GetImageSize();

		if (sizeImage.cx >= 32 && sizeImage.cy >= 32)
		{
			// The image is already scaled
			horz = CMFCToolBarImages::ImageAlignHorzCenter;
			vert = CMFCToolBarImages::ImageAlignVertCenter;
		}
		else
		{
			horz = CMFCToolBarImages::ImageAlignHorzStretch;
			vert = CMFCToolBarImages::ImageAlignVertStretch;
		}
	}

	pImage->SetTransparentColor(GetGlobalData()->clrBtnFace);
	pImage->DrawEx(pDC, rectImage, 0, horz, vert);
}

BOOL CMFCRibbonApplicationButton::ShowMainMenu()
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	if (m_pRibbonBar->GetMainCategory()->GetPanelCount() == 0)
	{
		return FALSE;
	}

	CMFCRibbonBaseElement::OnShowPopupMenu();

	const BOOL bIsRTL = (m_pRibbonBar->GetExStyle() & WS_EX_LAYOUTRTL);

	CRect rectBtn = m_rect;
	m_pRibbonBar->ClientToScreen(&rectBtn);

	CMFCRibbonMainPanel* pPanel = DYNAMIC_DOWNCAST(CMFCRibbonMainPanel, m_pRibbonBar->GetMainCategory()->GetPanel(0));
	ASSERT_VALID(pPanel);

	if (!m_pRibbonBar->IsWindows7Look())
	{
		pPanel->m_nTopMargin = rectBtn.Height() / 2 - 2;
	}
	else
	{
		pPanel->m_nTopMargin = 2;
	}
	pPanel->m_pMainButton = this;

	CClientDC dc(m_pRibbonBar);

	CFont* pOldFont = dc.SelectObject(m_pRibbonBar->GetFont());
	ENSURE(pOldFont != NULL);

	pPanel->RecalcWidths(&dc, 32767);

	dc.SelectObject(pOldFont);

	CMFCRibbonPanelMenu* pMenu = new CMFCRibbonPanelMenu(pPanel);
	pMenu->SetParentRibbonElement(this);

	int y = rectBtn.bottom;
	if (!m_pRibbonBar->IsWindows7Look())
	{
		y = rectBtn.CenterPoint().y;
	}
	pMenu->Create(m_pRibbonBar, bIsRTL ? rectBtn.right : rectBtn.left, y, (HMENU) NULL);

	SetDroppedDown(pMenu);

	return TRUE;
}

BOOL CMFCRibbonApplicationButton::OnKey(BOOL bIsMenuKey)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	if (m_pRibbonBar->m_nKeyboardNavLevel == 0)
	{
		m_pRibbonBar->RemoveAllKeys();
		m_pRibbonBar->m_nCurrKeyChar = 0;
	}

	if (m_pRibbonBar->GetMainCategory() == NULL)
	{
		return CMFCRibbonButton::OnKey(bIsMenuKey);
	}

	ShowMainMenu();

	if (m_pPopupMenu != NULL)
	{
		ASSERT_VALID(m_pPopupMenu);
		m_pPopupMenu->SendMessage(WM_KEYDOWN, VK_HOME);
	}

	return FALSE;
}

BOOL CMFCRibbonApplicationButton::SetACCData(CWnd* pParent, CAccessibilityData& data)
{
	CMFCRibbonButton::SetACCData(pParent, data);

	data.m_strAccName = m_strText.IsEmpty() ? _T("Application menu") : m_strText;
	data.m_nAccRole = ROLE_SYSTEM_BUTTONDROPDOWNGRID;
	data.m_bAccState = STATE_SYSTEM_FOCUSABLE | STATE_SYSTEM_HASPOPUP;;

	return TRUE;
}

HRESULT CMFCRibbonApplicationButton::get_accParent(IDispatch **ppdispParent)
{
	if (!ppdispParent)
	{
		return E_INVALIDARG;
	}

	*ppdispParent = NULL;

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	LPDISPATCH lpDispatch = m_pRibbonBar->GetAccessibleDispatch();
	if (lpDispatch != NULL)
	{
		*ppdispParent =  lpDispatch;
	}

	return S_OK;
}

HRESULT CMFCRibbonApplicationButton::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	switch(navDir)
	{
	case NAVDIR_NEXT:
	case NAVDIR_RIGHT:
		if (varStart.lVal == CHILDID_SELF)
		{
			if (m_pRibbonBar->m_QAToolbar.IsVisible())
			{
				pvarEndUpAt->vt = VT_DISPATCH;
				pvarEndUpAt->pdispVal = m_pRibbonBar->m_QAToolbar.GetIDispatch(TRUE);

				return S_OK;
			}
		}
	}

	return S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonBar

IMPLEMENT_DYNAMIC(CMFCRibbonBar, CPane)

CMFCRibbonBar::CMFCRibbonBar(BOOL bReplaceFrameCaption) : m_bReplaceFrameCaption(bReplaceFrameCaption)
{
	m_dwHideFlags = 0;
	m_nCategoryHeight = 0;
	m_nCategoryMinWidth = 0;
	m_bRecalcCategoryHeight = TRUE;
	m_bRecalcCategoryWidth = TRUE;
	m_nTabsHeight = 0;
	m_hFont = NULL;
	m_pActiveCategory = NULL;
	m_pActiveCategorySaved = NULL;
	m_nHighlightedTab = -1;
	m_pMainButton = NULL;
	m_bAutoDestroyMainButton = FALSE;
	m_pMainCategory = NULL;
	m_pPrintPreviewCategory = NULL;
	m_bIsPrintPreview = TRUE;
	m_sizeMainButton = CSize(0, 0);
	m_pHighlighted = NULL;
	m_pPressed = NULL;
	m_bTracked = FALSE;
	m_nTabTruncateRatio = 0;
	m_pToolTip = NULL;
	m_bForceRedraw = FALSE;
	m_nSystemButtonsNum = 0;
	m_bMaximizeMode = FALSE;
	m_bAutoCommandTimer = FALSE;
	m_bPrintPreviewMode = FALSE;
	m_bIsTransparentCaption = FALSE;
	m_bIsMaximized = FALSE;
	m_bToolTip = TRUE;
	m_bToolTipDescr = TRUE;
	m_nTooltipWidthRegular = nTooltipMinWidthDefault;
	m_nTooltipWidthLargeImage = nTooltipWithImageMinWidthDefault;
	m_bKeyTips = TRUE;
	m_bIsCustomizeMenu = FALSE;
	m_nKeyboardNavLevel = -1;
	m_pKeyboardNavLevelParent = NULL;
	m_pKeyboardNavLevelCurrent = NULL;
	m_nCurrKeyChar = 0;
	m_bDontSetKeyTips = FALSE;

	m_rectCaption.SetRectEmpty();
	m_rectCaptionText.SetRectEmpty();
	m_rectSysButtons.SetRectEmpty();

	m_nCaptionHeight = 0;

	m_bWindows7Look = FALSE;

	m_bQuickAccessToolbarOnTop = TRUE;
	m_bSingleLevelAccessibilityMode = FALSE;

	EnableActiveAccessibility();
}

CMFCRibbonBar::~CMFCRibbonBar()
{
	int i = 0;

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		ASSERT_VALID(m_arCategories [i]);
		delete m_arCategories [i];
	}

	for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);
		delete m_arContextCaptions [i];
	}

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);
		delete m_pMainCategory;
	}

	if (m_bAutoDestroyMainButton && m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);
		delete m_pMainButton;
	}
}

BEGIN_MESSAGE_MAP(CMFCRibbonBar, CPane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CANCELMODE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
	ON_WM_SIZING()
	ON_WM_MOUSEWHEEL()
	ON_WM_SETTINGCHANGE()
	ON_WM_TIMER()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_ERASEBKGND()
	ON_WM_SYSCOMMAND()
	ON_WM_SETCURSOR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_SHOWWINDOW()
	ON_WM_SETFONT()
	ON_WM_GETFONT()
	ON_WM_MOUSELEAVE()
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXT, 0, 0xFFFF, &CMFCRibbonBar::OnNeedTipText)
	ON_REGISTERED_MESSAGE(AFX_WM_UPDATETOOLTIPS, &CMFCRibbonBar::OnUpdateToolTips)
	ON_REGISTERED_MESSAGE(AFX_WM_POSTRECALCLAYOUT, &CMFCRibbonBar::OnPostRecalcLayout)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonBar message handlers

BOOL CMFCRibbonBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	return CreateEx(pParentWnd, 0, dwStyle, nID);
}

BOOL CMFCRibbonBar::CreateEx(CWnd* pParentWnd, DWORD /*dwCtrlStyle*/, DWORD dwStyle, UINT nID)
{
	ASSERT_VALID(pParentWnd);   // must have a parent

	m_dwStyle |= CBRS_HIDE_INPLACE;

	// save the style
	SetPaneAlignment(dwStyle & CBRS_ALL);

	// create the HWND
	CRect rect;
	rect.SetRectEmpty();

	m_dwControlBarStyle = 0; // can't float, resize, close, slide

	if (m_bReplaceFrameCaption && GetGlobalData()->IsDwmCompositionEnabled())
	{
		dwStyle |= WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZE;
	}

	if (!CWnd::Create(GetGlobalData()->RegisterWindowClass(_T("Afx:RibbonBar")), NULL, dwStyle | WS_CLIPSIBLINGS, rect, pParentWnd, nID))
	{
		return FALSE;
	}

	if (pParentWnd->IsKindOf(RUNTIME_CLASS(CFrameWndEx)))
	{
		((CFrameWndEx*) pParentWnd)->AddPane(this);
	}
	else if (pParentWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		((CMDIFrameWndEx*) pParentWnd)->AddPane(this);
	}
	else
	{
		ASSERT(FALSE);
		return FALSE;
	}

	pParentWnd->SetMenu(NULL);

	if (m_bReplaceFrameCaption)
	{
		if (GetGlobalData()->IsDwmCompositionEnabled())
		{
			pParentWnd->SetWindowPos(NULL, -1, -1, -1, -1, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_FRAMECHANGED);
		}
		else
		{
			pParentWnd->ModifyStyle(WS_CAPTION, 0);
		}
	}

	return TRUE;
}

BOOL CMFCRibbonBar::LoadFromResource(UINT uiXMLResID, LPCTSTR lpszResType, HINSTANCE hInstance)
{
	ASSERT_VALID(this);
	return LoadFromResource(MAKEINTRESOURCE(uiXMLResID), lpszResType, hInstance);
}

BOOL CMFCRibbonBar::LoadFromResource(LPCTSTR lpszXMLResID, LPCTSTR lpszResType, HINSTANCE hInstance)
{
	ASSERT_VALID (this);

	CMFCRibbonInfo info;
	CMFCRibbonInfoLoader loader(info);

	if (!loader.Load(lpszXMLResID, lpszResType, hInstance))
	{
		TRACE0("Cannot load ribbon from resource\n");
		return FALSE;
	}

	CMFCRibbonConstructor constr(info);
	constr.ConstructRibbonBar(*this);

	return TRUE;
}

BOOL CMFCRibbonBar::LoadFromBuffer(LPCTSTR lpszXMLBuffer)
{
	ASSERT_VALID(this);
	ASSERT(lpszXMLBuffer != NULL);

	CMFCRibbonInfo info;
	CMFCRibbonInfoLoader loader(info);

	if (!loader.LoadFromBuffer(lpszXMLBuffer))
	{
		TRACE0("Cannot load ribbon from buffer\n");
		return FALSE;
	}

	CMFCRibbonConstructor constr(info);
	constr.ConstructRibbonBar(*this);

	return TRUE;
}

void CMFCRibbonBar::SetWindows7Look(BOOL bWindows7Look, BOOL bRecalc/* = TRUE*/)
{
	if (bWindows7Look != m_bWindows7Look)
	{
		m_bWindows7Look = bWindows7Look;

		if (GetSafeHwnd() != NULL && bRecalc)
		{
			ForceRecalcLayout();
		}
	}
}

CSize CMFCRibbonBar::CalcFixedLayout(BOOL, BOOL /*bHorz*/)
{
	ASSERT_VALID(this);

	CClientDC dc(this);

	CFont* pOldFont = dc.SelectObject(GetFont());
	ENSURE(pOldFont != NULL);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	m_nCaptionHeight = 0;

	if (m_bReplaceFrameCaption)
	{
		m_nCaptionHeight = GetSystemMetrics(SM_CYCAPTION) + 1;

		if (GetGlobalData()->IsDwmCompositionEnabled())
		{
			m_nCaptionHeight += GetSystemMetrics(SM_CYSIZEFRAME);
		}
	}

	int cy = 0;

	CSize sizeMainButton = m_sizeMainButton;
	double scale = GetGlobalData()->GetRibbonImageScale();
	if (scale > 1.)
	{
		sizeMainButton.cx = (int)(.5 + scale * sizeMainButton.cx);
		sizeMainButton.cy = (int)(.5 + scale * sizeMainButton.cy);
	}

	if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL)
	{
		cy = m_nCaptionHeight;
	}
	else
	{
		if (m_bRecalcCategoryHeight)
		{
			m_nCategoryHeight = 0;
		}

			m_nTabsHeight = tm.tmHeight + 2 * nYTabMargin;

		if (m_bRecalcCategoryHeight)
		{
			for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
			{
				CMFCRibbonCategory* pCategory = m_arCategories [i];
				ASSERT_VALID(pCategory);

				m_nCategoryHeight = max(m_nCategoryHeight, pCategory->GetMaxHeight(&dc));
			}
			m_bRecalcCategoryHeight = FALSE;
		}

		const CSize sizeAQToolbar = m_QAToolbar.GetRegularSize(&dc);

		if (IsQuickAccessToolbarOnTop())
		{
			m_nCaptionHeight = max(m_nCaptionHeight, sizeAQToolbar.cy + (IsWindows7Look() ? 0 : (2 * nYMargin)));
		}

		const int nQuickAceesToolbarHeight = IsQuickAccessToolbarOnTop() ? 0 : sizeAQToolbar.cy;
		const int nCategoryHeight = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) ? 0 : m_nCategoryHeight;

		cy = nQuickAceesToolbarHeight + nCategoryHeight + max( m_nCaptionHeight + m_nTabsHeight, m_sizeMainButton.cy + nYMargin);
	}

	if (GetGlobalData()->IsDwmCompositionEnabled())
	{
		if (GetParent()->IsZoomed() && m_bReplaceFrameCaption)
		{
			cy += ::GetSystemMetrics(SM_CYSIZEFRAME) - 2;
		}
	}

	dc.SelectObject(pOldFont);
	return CSize(32767, cy);
}

BOOL CMFCRibbonBar::PreCreateWindow(CREATESTRUCT& cs)
{
	m_dwStyle &= ~(CBRS_BORDER_ANY|CBRS_BORDER_3D);
	return CPane::PreCreateWindow(cs);
}

int CMFCRibbonBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPane::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_CaptionButtons [0].SetID(SC_MINIMIZE);
	m_CaptionButtons [1].SetID(SC_MAXIMIZE);
	m_CaptionButtons [2].SetID(SC_CLOSE);

	for (int i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
	{
		m_CaptionButtons [i].m_pRibbonBar = this;
	}

	CString strCaption;
	GetParent()->GetWindowText(strCaption);

	SetWindowText(strCaption);

	CTooltipManager::CreateToolTip(m_pToolTip, this, AFX_TOOLTIP_TYPE_RIBBON);

	if (m_pToolTip->GetSafeHwnd() != NULL)
	{
		CRect rectDummy(0, 0, 0, 0);

		m_pToolTip->SetMaxTipWidth (nTooltipMaxWidth);

		m_pToolTip->AddTool(this, LPSTR_TEXTCALLBACK, &rectDummy, nIdToolTipClient);
		m_pToolTip->AddTool(this, LPSTR_TEXTCALLBACK, &rectDummy, nIdToolTipCaption);
	}

	m_QAToolbar.m_pRibbonBar = this;
	m_Tabs.m_pRibbonBar = this;

	return 0;
}

void CMFCRibbonBar::OnDestroy()
{
	CTooltipManager::DeleteToolTip(m_pToolTip);
	RemoveAllKeys();

	CPane::OnDestroy();
}

void CMFCRibbonBar::OnSize(UINT nType, int cx, int cy)
{
	CPane::OnSize(nType, cx, cy);

	const BOOL bHideAll = cx < nMinRibbonWidth;
	const BOOL bIsHidden = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) != 0;

	BOOL bWasMaximized = m_bIsMaximized;

	m_bIsMaximized = GetParent()->IsZoomed();

	if (bHideAll != bIsHidden)
	{
		if (bHideAll)
		{
			m_dwHideFlags |= AFX_RIBBONBAR_HIDE_ALL;
		}
		else
		{
			m_dwHideFlags &= ~AFX_RIBBONBAR_HIDE_ALL;
		}

		if (m_pMainButton != NULL && bHideAll)
		{
			ASSERT_VALID(m_pMainButton);
			m_pMainButton->SetRect(CRect(0, 0, 0, 0));
		}

		PostMessage(AFX_WM_POSTRECALCLAYOUT);
	}
	else if (bWasMaximized != m_bIsMaximized)
	{
		m_bForceRedraw = TRUE;
		RecalcLayout();
	}
	else
	{
		RecalcLayout();
	}

	UpdateToolTipsRect();
}

LRESULT CMFCRibbonBar::OnPostRecalcLayout(WPARAM,LPARAM)
{
	GetParentFrame()->RecalcLayout();
	return 0;
}

void CMFCRibbonBar::SetApplicationButton(CMFCRibbonApplicationButton* pButton, CSize sizeButton)
{
	ASSERT_VALID(this);

	m_pMainButton = pButton;

	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		m_pMainButton->m_pRibbonBar = this;
		m_sizeMainButton = sizeButton;
	}
	else
	{
		m_sizeMainButton = CSize(0, 0);
	}
}

CMFCRibbonMainPanel* CMFCRibbonBar::AddMainCategory(LPCTSTR lpszName, UINT uiSmallImagesResID, UINT uiLargeImagesResID, CSize sizeSmallImage, CSize sizeLargeImage, CRuntimeClass* pRTI)
{
	ASSERT_VALID(this);
	ENSURE(lpszName != NULL);

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);
		delete m_pMainCategory;
	}

	if (pRTI != NULL)
	{
		m_pMainCategory = DYNAMIC_DOWNCAST(CMFCRibbonCategory, pRTI->CreateObject ());

		if (m_pMainCategory == NULL)
		{
			ASSERT(FALSE);
			return NULL;
		}

		m_pMainCategory->CommonInit(this, lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage);
	}
	else
	{
		m_pMainCategory = new CMFCRibbonCategory(this, lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage);
	}

	return(CMFCRibbonMainPanel*) m_pMainCategory->AddPanel(lpszName, 0, RUNTIME_CLASS(CMFCRibbonMainPanel));
}

CMFCRibbonCategory* CMFCRibbonBar::AddCategory(LPCTSTR lpszName, UINT uiSmallImagesResID, UINT uiLargeImagesResID,
	CSize sizeSmallImage, CSize sizeLargeImage, int nInsertAt, CRuntimeClass* pRTI)
{
	ASSERT_VALID(this);
	ENSURE(lpszName != NULL);

	CMFCRibbonCategory* pCategory = NULL;

	if (pRTI != NULL)
	{
		pCategory = DYNAMIC_DOWNCAST(CMFCRibbonCategory, pRTI->CreateObject());

		if (pCategory == NULL)
		{
			ASSERT(FALSE);
			return NULL;
		}

		pCategory->CommonInit(this, lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage);
	}
	else
	{
		pCategory = new CMFCRibbonCategory(this, lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage);
	}

	if (nInsertAt < 0)
	{
		m_arCategories.Add(pCategory);
	}
	else
	{
		m_arCategories.InsertAt(nInsertAt, pCategory);
	}

	if (m_pActiveCategory == NULL)
	{
		m_pActiveCategory = pCategory;
		m_pActiveCategory->m_bIsActive = TRUE;
	}

	m_bRecalcCategoryHeight = TRUE;
	m_bRecalcCategoryWidth = TRUE;

	if (!m_bSingleLevelAccessibilityMode)
	{
		m_Tabs.UpdateTabs(m_arCategories);
	}

	return pCategory;
}

CMFCRibbonCategory* CMFCRibbonBar::AddContextCategory(LPCTSTR lpszName, LPCTSTR lpszContextName, UINT uiContextID, AFX_RibbonCategoryColor clrContext,
	UINT uiSmallImagesResID, UINT uiLargeImagesResID, CSize sizeSmallImage, CSize sizeLargeImage, CRuntimeClass* pRTI)
{
	ASSERT_VALID(this);
	ENSURE(lpszContextName != NULL);
	ENSURE(uiContextID != 0);

	CMFCRibbonCategory* pCategory = AddCategory(lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage, -1, pRTI);

	if (pCategory == NULL)
	{
		return NULL;
	}

	ASSERT_VALID(pCategory);

	pCategory->m_bIsVisible = FALSE;

	CMFCRibbonContextCaption* pCaption = NULL;

	for (int i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);

		if (m_arContextCaptions [i]->m_uiID == uiContextID)
		{
			pCaption = m_arContextCaptions[i];
			pCaption->m_strText = lpszContextName;
			pCaption->m_Color = clrContext;
			break;
		}
	}

	if (pCaption == NULL)
	{
		pCaption = new CMFCRibbonContextCaption(lpszContextName, uiContextID, clrContext);
		pCaption->m_pRibbonBar = this;

		m_arContextCaptions.Add(pCaption);
	}

	pCategory->SetTabColor(clrContext);
	pCategory->m_uiContextID = uiContextID;

	return pCategory;
}

CMFCRibbonCategory* CMFCRibbonBar::AddQATOnlyCategory(LPCTSTR lpszName, UINT uiSmallImagesResID, CSize sizeSmallImage)
{
	ASSERT_VALID(this);

	CMFCRibbonCategory* pCategory = AddCategory(lpszName, uiSmallImagesResID, 0, sizeSmallImage);

	if (pCategory == NULL)
	{
		return NULL;
	}

	ASSERT_VALID(pCategory);

	pCategory->m_bIsVisible = FALSE;

	return pCategory;
}

BOOL CMFCRibbonBar::SetActiveCategory(CMFCRibbonCategory* pActiveCategory, BOOL bForceRestore)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pActiveCategory);

	if (!pActiveCategory->IsVisible())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (pActiveCategory == m_pMainCategory)
	{
		// Main category cannot be active
		ASSERT(FALSE);
		return FALSE;
	}

	if (m_pActiveCategory != NULL && pActiveCategory != m_pActiveCategory)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->SetActive(FALSE);
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory == pActiveCategory)
		{
			if (m_dwHideFlags == AFX_RIBBONBAR_HIDE_ELEMENTS && !bForceRestore)
			{
				m_pActiveCategory = pCategory;
				m_pActiveCategory->m_bIsActive = TRUE;

				CRect rectCategory;
				GetClientRect(rectCategory);

				rectCategory.top = pCategory->GetTabRect().bottom;
				rectCategory.bottom = rectCategory.top + m_nCategoryHeight;

				ClientToScreen(&rectCategory);

				if (m_nKeyboardNavLevel < 0)
				{
					pCategory->NormalizeFloatingRect (this, rectCategory);
				}

				pCategory->ShowFloating (rectCategory);

				RedrawWindow(pCategory->GetTabRect());

				// Notify parent frame:
				CFrameWnd* pParentFrame = GetParentFrame();
				ASSERT_VALID(pParentFrame);

				pParentFrame->SendMessage(AFX_WM_ON_CHANGE_RIBBON_CATEGORY, 0, (LPARAM)this);
				return TRUE;
			}

			if (pCategory->IsActive())
			{
				if (m_dwHideFlags == AFX_RIBBONBAR_HIDE_ELEMENTS && bForceRestore)
				{
					pCategory->ShowElements();
					RedrawWindow();
				}

				return TRUE;
			}

			m_pActiveCategory = pCategory;
			m_pActiveCategory->SetActive();

			if (GetSafeHwnd() != NULL)
			{
				if (m_dwHideFlags == AFX_RIBBONBAR_HIDE_ELEMENTS && bForceRestore)
				{
					pCategory->ShowElements();
				}

				m_bForceRedraw = TRUE;
				RecalcLayout();
			}

			// Notify parent frame:
			CFrameWnd* pParentFrame = GetParentFrame();
			ASSERT_VALID(pParentFrame);

			pParentFrame->SendMessage(AFX_WM_ON_CHANGE_RIBBON_CATEGORY, 0, (LPARAM)this);
			return TRUE;
		}
	}

	ASSERT(FALSE);
	return FALSE;
}

int CMFCRibbonBar::FindCategoryIndexByData(DWORD dwData) const
{
	ASSERT_VALID(this);

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->GetData() == dwData)
		{
			return i;
		}
	}

	return -1;
}

int CMFCRibbonBar::GetCategoryCount() const
{
	ASSERT_VALID(this);
	return(int) m_arCategories.GetSize();
}

int CMFCRibbonBar::GetVisibleCategoryCount() const
{
	ASSERT_VALID(this);

	int nCount = 0;

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories[i];
		ASSERT_VALID(pCategory);

		if (pCategory->IsVisible())
		{
			nCount++;
		}
	}

	return nCount;
}

CMFCRibbonCategory* CMFCRibbonBar::GetCategory(int nIndex) const
{
	ASSERT_VALID(this);

	if (nIndex < 0 || nIndex >= (int)m_arCategories.GetSize())
	{
		ASSERT(FALSE);
		return NULL;
	}

	return m_arCategories [nIndex];
}

int CMFCRibbonBar::GetCategoryIndex(CMFCRibbonCategory* pCategory) const
{
	ASSERT_VALID(this);
	ASSERT_VALID(pCategory);

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		if (m_arCategories [i] == pCategory)
		{
			return i;
		}
	}

	return -1;
}

void CMFCRibbonBar::ShowCategory(int nIndex, BOOL bShow/* = TRUE*/)
{
	ASSERT_VALID(this);

	if (nIndex < 0 || nIndex >= (int)m_arCategories.GetSize())
	{
		ASSERT(FALSE);
		return;
	}

	CMFCRibbonCategory* pCategory = m_arCategories [nIndex];
	ASSERT_VALID(pCategory);

	pCategory->m_bIsVisible = bShow;
}

void CMFCRibbonBar::ShowContextCategories(UINT uiContextID, BOOL bShow/* = TRUE*/)
{
	ASSERT_VALID(this);

	if (uiContextID == 0)
	{
		ASSERT(FALSE);
		return;
	}

	BOOL bChangeActiveCategory = FALSE;
	int i = 0;

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() == uiContextID)
		{
			pCategory->m_bIsVisible = bShow;

			if (!bShow && pCategory == m_pActiveCategory)
			{
				bChangeActiveCategory = TRUE;
			}
		}
	}

	if (bChangeActiveCategory)
	{
		for (i = 0; i < (int)m_arCategories.GetSize(); i++)
		{
			CMFCRibbonCategory* pCategory = m_arCategories [i];
			ASSERT_VALID(pCategory);

			if (pCategory->IsVisible())
			{
				SetActiveCategory(pCategory);
				return;
			}
		}

		m_pActiveCategory = NULL;
	}
}

BOOL CMFCRibbonBar::ActivateContextCategory(UINT uiContextID)
{
	ASSERT_VALID(this);

	if (uiContextID == 0)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() == uiContextID && pCategory->m_bIsVisible)
		{
			SetActiveCategory(pCategory);
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CMFCRibbonBar::HideAllContextCategories()
{
	ASSERT_VALID(this);
	BOOL bRes = FALSE;

	BOOL bChangeActiveCategory = FALSE;
	int i = 0;

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() != 0)
		{
			if (pCategory->m_bIsVisible)
			{
				bRes = TRUE;
			}

			pCategory->m_bIsVisible = FALSE;
			pCategory->m_bIsActive = FALSE;

			if (pCategory == m_pActiveCategory)
			{
				bChangeActiveCategory = TRUE;

				for (int j = 0; j < pCategory->GetPanelCount(); j++)
				{
					CMFCRibbonPanel* pPanel = pCategory->GetPanel(j);
					ASSERT_VALID(pPanel);

					pPanel->OnShow(FALSE);
				}
			}
		}
	}

	if (bChangeActiveCategory)
	{
		for (i = 0; i < (int)m_arCategories.GetSize(); i++)
		{
			CMFCRibbonCategory* pCategory = m_arCategories [i];
			ASSERT_VALID(pCategory);

			if (pCategory->IsVisible())
			{
				if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS)
				{
					m_pActiveCategory = pCategory;
					m_pActiveCategory->m_bIsActive = TRUE;
				}
				else
				{
					SetActiveCategory(pCategory);
				}

				return bRes;
			}
		}

		m_pActiveCategory = NULL;
	}

	return bRes;
}

BOOL CMFCRibbonBar::GetContextName(UINT uiContextID, CString& strName) const
{
	ASSERT_VALID(this);

	if (uiContextID == 0)
	{
		return FALSE;
	}

	CMFCRibbonContextCaption* pCaption = FindContextCaption(uiContextID);
	if (pCaption == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pCaption);
	strName = pCaption->m_strText;

	return TRUE;
}

BOOL CMFCRibbonBar::RemoveCategory(int nIndex)
{
	ASSERT_VALID(this);

	if (nIndex < 0 || nIndex >= (int)m_arCategories.GetSize())
	{
		return FALSE;
	}

	OnCancelMode();

	CMFCRibbonCategory* pCategory = m_arCategories [nIndex];
	ASSERT_VALID(pCategory);

	const BOOL bChangeActiveCategory = (pCategory == m_pActiveCategory);

	delete pCategory;

	m_arCategories.RemoveAt(nIndex);

	if (bChangeActiveCategory)
	{
		if (m_arCategories.GetSize() == 0)
		{
			m_pActiveCategory = NULL;
		}
		else
		{
			nIndex = min(nIndex, (int)m_arCategories.GetSize() - 1);

			m_pActiveCategory = m_arCategories [nIndex];
			ASSERT_VALID(m_pActiveCategory);

			if (!m_pActiveCategory->IsVisible())
			{
				m_pActiveCategory = NULL;

				for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
				{
					CMFCRibbonCategory* pCurrCategory = m_arCategories [i];
					ASSERT_VALID(pCurrCategory);

					if (pCurrCategory->IsVisible())
					{
						m_pActiveCategory = pCurrCategory;
						m_pActiveCategory->m_bIsActive = TRUE;
						break;
					}
				}
			}
			else
			{
				m_pActiveCategory->m_bIsActive = TRUE;
			}
		}
	}

	if (!m_bSingleLevelAccessibilityMode)
	{
		m_Tabs.UpdateTabs(m_arCategories);
	}

	return TRUE;
}

void CMFCRibbonBar::RemoveAllCategories()
{
	OnCancelMode();

	int i = 0;

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		ASSERT_VALID(m_arCategories [i]);
		delete m_arCategories [i];
	}

	for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);
		delete m_arContextCaptions [i];
	}

	m_arCategories.RemoveAll();
	m_arContextCaptions.RemoveAll();

	m_pActiveCategory = NULL;
}

void CMFCRibbonBar::OnSetFont(CFont* pFont, BOOL /*bRedraw*/)
{
	m_hFont = (HFONT)pFont->GetSafeHandle();
	ForceRecalcLayout();
}

HFONT CMFCRibbonBar::OnGetFont()
{
	return m_hFont != NULL ? m_hFont : (HFONT)GetGlobalData()->fontRegular.GetSafeHandle();
}

void CMFCRibbonBar::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	int i = 0;

	CMemDC memDC(dc, this);
	CDC* pDC = &memDC.GetDC();

	CRect rectClip;
	dc.GetClipBox(rectClip);

	CRgn rgnClip;

	if (!rectClip.IsRectEmpty())
	{
		rgnClip.CreateRectRgnIndirect(rectClip);
		pDC->SelectClipRgn(&rgnClip);
	}

	pDC->SetBkMode(TRANSPARENT);

	CRect rectClient;
	GetClientRect(rectClient);

	OnFillBackground(pDC, rectClient);

	CFont* pOldFont = pDC->SelectObject(GetFont());
	ENSURE(pOldFont != NULL);

	// Draw caption bar:
	if (!m_rectCaption.IsRectEmpty())
	{
		CRect rectFill = m_rectCaption;
		rectFill.top = 0;

		if (m_bIsTransparentCaption)
		{
			pDC->FillSolidRect(rectFill, RGB(0, 0, 0));

			CMFCToolBarImages::m_bIsDrawOnGlass = TRUE;
		}

		CMFCVisualManager::GetInstance()->OnDrawRibbonCaption
			(pDC, this, m_rectCaption, m_rectCaptionText);

		for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
		{
			if (!m_CaptionButtons [i].GetRect ().IsRectEmpty ())
			{
				m_CaptionButtons [i].OnDraw(pDC);
			}
		}

		for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
		{
			ASSERT_VALID(m_arContextCaptions [i]);
			m_arContextCaptions [i]->OnDraw(pDC);
		}

		CMFCToolBarImages::m_bIsDrawOnGlass = FALSE;
	}

	if (m_bIsTransparentCaption && m_bQuickAccessToolbarOnTop)
	{
		CMFCToolBarImages::m_bIsDrawOnGlass = TRUE;
	}

	// Draw quick access toolbar:
	COLORREF cltTextOld = (COLORREF)-1;
	COLORREF cltQATText = CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarTextColor();

	if (cltQATText != (COLORREF)-1)
	{
		cltTextOld = pDC->SetTextColor(cltQATText);
	}

	m_QAToolbar.OnDraw(pDC);

	if (cltTextOld != (COLORREF)-1)
	{
		pDC->SetTextColor(cltTextOld);
	}

	CMFCToolBarImages::m_bIsDrawOnGlass = FALSE;

	// Draw active category:
	if (m_pActiveCategory != NULL && m_dwHideFlags == 0)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->OnDraw(pDC);
	}

	// Draw tabs:
	CRect rectTabs = rectClient;
	rectTabs.top = m_rectCaption.IsRectEmpty() ? rectClient.top : m_rectCaption.bottom;
	rectTabs.bottom = rectTabs.top + m_nTabsHeight;

	COLORREF clrTextTabs = CMFCVisualManager::GetInstance()->OnDrawRibbonTabsFrame(pDC, this, rectTabs);

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->IsVisible())
		{
			pCategory->m_Tab.OnDraw(pDC);
		}
	}

	// Draw elements on right of tabs:
	COLORREF clrTextOld = (COLORREF)-1;
	if (clrTextTabs != (COLORREF)-1)
	{
		clrTextOld = pDC->SetTextColor(clrTextTabs);
	}

	m_TabElements.OnDraw(pDC);

	if (clrTextOld != (COLORREF)-1)
	{
		pDC->SetTextColor(clrTextOld);
	}

	// Draw main button:
	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		if (!m_pMainButton->GetRect().IsRectEmpty())
		{
			CMFCVisualManager::GetInstance()->OnDrawRibbonApplicationButton(pDC, m_pMainButton);

			m_pMainButton->OnDraw(pDC);
		}
	}

	pDC->SelectObject(pOldFont);
	pDC->SelectClipRgn(NULL);
}

void CMFCRibbonBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPane::OnLButtonDown(nFlags, point);

	DeactivateKeyboardFocus();

	CMFCRibbonBaseElement* pDroppedDown = GetDroppedDown();
	if (pDroppedDown != NULL)
	{
		ASSERT_VALID(pDroppedDown);
		pDroppedDown->ClosePopupMenu();
	}

	if ((m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) == AFX_RIBBONBAR_HIDE_ALL || IsWindows7Look())
	{
		CRect rectIcon = m_rectCaption;
		rectIcon.right = IsQuickAccessToolbarOnTop() && !m_QAToolbar.m_rect.IsRectEmpty() ? m_QAToolbar.m_rect.left - 1 : rectIcon.left + rectIcon.Height();

		if (rectIcon.PtInRect(point))
		{
			CPoint ptMenu(m_rectCaption.left, m_rectCaption.bottom);
			ClientToScreen(&ptMenu);

			ShowSysMenu(ptMenu);
			return;
		}
	}

	OnMouseMove(nFlags, point);

	CMFCRibbonBaseElement* pHit = HitTest(point);

	if (pHit != NULL)
	{
		ASSERT_VALID(pHit);

		pHit->OnLButtonDown(point);
		pHit->m_bIsPressed = TRUE;

		CRect rectHit = pHit->GetRect();
		rectHit.InflateRect(1, 1);

		RedrawWindow(rectHit);

		m_pPressed = pHit;
	}
	else
	{
		if (m_rectCaption.PtInRect(point))
		{
			if (CMFCPopupMenu::GetActiveMenu() != NULL)
			{
				CMFCPopupMenu::GetActiveMenu()->SendMessage(WM_CLOSE);
			}

			if (!m_rectSysButtons.PtInRect(point))
			{
				GetParent()->SendMessage(WM_NCLBUTTONDOWN, (WPARAM) HTCAPTION, MAKELPARAM(point.x, point.y));
			}
			return;
		}

		if (m_pActiveCategory != NULL &&(m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
		{
			ASSERT_VALID(m_pActiveCategory);
			m_pPressed = m_pActiveCategory->OnLButtonDown(point);
		}
	}

	if (m_pPressed != NULL)
	{
		ASSERT_VALID(m_pPressed);

		int nDelay = 250;

		if (m_pPressed->IsAutoRepeatMode(nDelay))
		{
			SetTimer(AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND, nDelay, NULL);
			m_bAutoCommandTimer = TRUE;
		}
	}
}

void CMFCRibbonBar::OnLButtonUp(UINT nFlags, CPoint point)
{
	CPane::OnLButtonUp(nFlags, point);

	if (m_bAutoCommandTimer)
	{
		KillTimer(AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND);
		m_bAutoCommandTimer = FALSE;
	}

	CMFCRibbonBaseElement* pHit = HitTest(point);

	HWND hwndThis = GetSafeHwnd();

	if (pHit != NULL)
	{
		ASSERT_VALID(pHit);

		pHit->OnLButtonUp(point);

		if (!::IsWindow(hwndThis))
		{
			return;
		}

		pHit->m_bIsPressed = FALSE;

		RedrawWindow(pHit->GetRect());
	}

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->OnLButtonUp(point);

		if (!::IsWindow(hwndThis))
		{
			return;
		}
	}

	const BOOL bIsPressedButon = m_pPressed != NULL;

	if (m_pPressed != NULL)
	{
		ASSERT_VALID(m_pPressed);

		CRect rect = m_pPressed->GetRect();

		m_pPressed->m_bIsPressed = FALSE;
		m_pPressed = NULL;

		RedrawWindow(rect);
	}

	if (bIsPressedButon)
	{
		::GetCursorPos(&point);
		ScreenToClient(&point);

		OnMouseMove(nFlags, point);
	}
}

void CMFCRibbonBar::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CPane::OnLButtonDblClk(nFlags, point);

	CMFCRibbonBaseElement* pHit = HitTest(point);
	if (pHit != NULL)
	{
		ASSERT_VALID(pHit);

		if (!pHit->IsKindOf(RUNTIME_CLASS(CMFCRibbonContextCaption)))
		{
			pHit->OnLButtonDblClk(point);
			return;
		}
	}

	if (m_rectCaption.PtInRect(point) && !m_rectSysButtons.PtInRect(point))
	{
		BOOL bSysMenu = FALSE;

		if ((m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) == AFX_RIBBONBAR_HIDE_ALL || IsWindows7Look())
		{
			CRect rectIcon = m_rectCaption;
			rectIcon.right = rectIcon.left + rectIcon.Height();

			bSysMenu = rectIcon.PtInRect(point);
		}

		GetParent()->SendMessage(WM_NCLBUTTONDBLCLK, (WPARAM) (bSysMenu ? HTSYSMENU : HTCAPTION), MAKELPARAM(point.x, point.y));
		return;
	}
}

void CMFCRibbonBar::OnMouseMove(UINT nFlags, CPoint point)
{
	CPane::OnMouseMove(nFlags, point);

	CMFCRibbonBaseElement* pHit = HitTest(point);

	if (point == CPoint(-1, -1))
	{
		m_bTracked = FALSE;
	}
	else if (!m_bTracked)
	{
		m_bTracked = TRUE;

		TRACKMOUSEEVENT trackmouseevent;
		trackmouseevent.cbSize = sizeof(trackmouseevent);
		trackmouseevent.dwFlags = TME_LEAVE;
		trackmouseevent.hwndTrack = GetSafeHwnd();
		TrackMouseEvent(&trackmouseevent);

		if (m_pPressed != NULL &&((nFlags & MK_LBUTTON) == 0))
		{
			ASSERT_VALID(m_pPressed);
			m_pPressed->m_bIsPressed = FALSE;
		}
	}

	if (pHit != m_pHighlighted)
	{
		PopTooltip();

		if (m_pHighlighted != NULL)
		{
			ASSERT_VALID(m_pHighlighted);
			m_pHighlighted->m_bIsHighlighted = FALSE;
			m_pHighlighted->OnHighlight(FALSE);

			InvalidateRect(m_pHighlighted->GetRect());

			m_pHighlighted = NULL;
		}

		if (pHit != NULL)
		{
			ASSERT_VALID(pHit);

			if ((nFlags & MK_LBUTTON) == 0 || pHit->IsPressed())
			{
				m_pHighlighted = pHit;
				m_pHighlighted->OnHighlight(TRUE);
				m_pHighlighted->m_bIsHighlighted = TRUE;
				InvalidateRect(m_pHighlighted->GetRect());
				m_pHighlighted->OnMouseMove(point);
			}
		}

		UpdateWindow();
	}
	else if (m_pHighlighted != NULL)
	{
		ASSERT_VALID(m_pHighlighted);

		if (!m_pHighlighted->m_bIsHighlighted)
		{
			m_pHighlighted->m_bIsHighlighted = TRUE;
			RedrawWindow(m_pHighlighted->GetRect());
		}

		m_pHighlighted->OnMouseMove(point);
	}

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->OnMouseMove(point);
	}
}

BOOL CMFCRibbonBar::OnMouseWheel(UINT /*nFlags*/, short zDelta, CPoint /*pt*/)
{
	if (CMFCPopupMenu::GetActiveMenu() != NULL || m_pActiveCategory == NULL ||
		(m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS))
	{
		return FALSE;
	}

	if (m_nKeyboardNavLevel >= 0)
	{
		return FALSE;
	}

	if (GetFocus ()->GetSafeHwnd () != NULL && IsChild (GetFocus ()))
	{
		return FALSE;
	}

	CPoint point;
	::GetCursorPos(&point);

	ScreenToClient(&point);

	CRect rectClient;
	GetClientRect(rectClient);

	if (!rectClient.PtInRect(point))
	{
		return FALSE;
	}

	ASSERT_VALID(m_pActiveCategory);

	int nActiveCategoryIndex = -1;

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory == m_pActiveCategory)
		{
			nActiveCategoryIndex = i;
			break;
		}
	}

	if (nActiveCategoryIndex == -1)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	const int nSteps = -zDelta / WHEEL_DELTA;

	nActiveCategoryIndex = nActiveCategoryIndex + nSteps;

	if (nActiveCategoryIndex < 0)
	{
		nActiveCategoryIndex = 0;
	}

	if (nActiveCategoryIndex >= (int)m_arCategories.GetSize())
	{
		nActiveCategoryIndex = (int)m_arCategories.GetSize() - 1;
	}

	CMFCRibbonCategory* pNewActiveCategory = m_arCategories [nActiveCategoryIndex];
	ASSERT_VALID(pNewActiveCategory);

	if (!pNewActiveCategory->IsVisible())
	{
		if (nSteps < 0)
		{
			nActiveCategoryIndex--;

			while (nActiveCategoryIndex >= 0)
			{
				pNewActiveCategory = m_arCategories [nActiveCategoryIndex];
				ASSERT_VALID(pNewActiveCategory);

				if (pNewActiveCategory->IsVisible())
				{
					return SetActiveCategory(pNewActiveCategory);
				}

				nActiveCategoryIndex--;
			}
		}
		else
		{
			nActiveCategoryIndex++;

			while (nActiveCategoryIndex < (int)m_arCategories.GetSize())
			{
				pNewActiveCategory = m_arCategories [nActiveCategoryIndex];
				ASSERT_VALID(pNewActiveCategory);

				if (pNewActiveCategory->IsVisible())
				{
					return SetActiveCategory(pNewActiveCategory);
				}

				nActiveCategoryIndex++;
			}
		}

		return TRUE;
	}

	PopTooltip();
	return SetActiveCategory(pNewActiveCategory);
}

void CMFCRibbonBar::OnMouseLeave()
{
	CPoint point;

	::GetCursorPos(&point);
	ScreenToClient(&point);

	CRect rectClient;
	GetClientRect(rectClient);

	if (!rectClient.PtInRect(point))
	{
		OnMouseMove(0, CPoint(-1, -1));
	}

	m_bTracked = FALSE;
}

void CMFCRibbonBar::OnCancelMode()
{
	CPane::OnCancelMode();

	DeactivateKeyboardFocus(FALSE);

	if (m_bAutoCommandTimer)
	{
		KillTimer(AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND);
		m_bAutoCommandTimer = FALSE;
	}

	m_bTracked = FALSE;

	PopTooltip();

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->OnCancelMode();
	}

	if (m_pHighlighted != NULL)
	{
		ASSERT_VALID(m_pHighlighted);

		CRect rect = m_pHighlighted->GetRect();

		m_pHighlighted->m_bIsHighlighted = FALSE;
		m_pHighlighted->OnHighlight(FALSE);
		m_pHighlighted->m_bIsPressed = FALSE;

		if (m_pPressed == m_pHighlighted)
		{
			m_pPressed = NULL;
		}

		m_pHighlighted = NULL;
		RedrawWindow(rect);
	}

	if (m_pPressed != NULL)
	{
		ASSERT_VALID(m_pPressed);

		CRect rect = m_pPressed->GetRect();

		m_pPressed->m_bIsHighlighted = FALSE;
		m_pPressed->m_bIsPressed = FALSE;

		m_pPressed = NULL;
		RedrawWindow(rect);
	}
}

void CMFCRibbonBar::RecalcLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	DeactivateKeyboardFocus();

	m_bIsTransparentCaption = FALSE;

	if (m_pPrintPreviewCategory == NULL && m_bIsPrintPreview)
	{
		AddPrintPreviewCategory();
		ASSERT_VALID(m_pPrintPreviewCategory);
	}

	m_nTabTruncateRatio = 0;

	CPane::RecalcLayout();

	const BOOL bHideAll = m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL;
	const int nCategoryHeight = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) ? 0 : m_nCategoryHeight;
	const int cyFrameBorder = GetSystemMetrics(SM_CYSIZEFRAME);

	int i = 0;

	CRect rect;
	GetClientRect(rect);

	CClientDC dc(this);

	CFont* pOldFont = dc.SelectObject(GetFont());
	ENSURE(pOldFont != NULL);

	CString strCaption;
	GetWindowText(strCaption);

	const int nCaptionTextWidth = dc.GetTextExtent(strCaption).cx;

	for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);
		m_arContextCaptions [i]->SetRect(CRect(0, 0, 0, 0));
	}

	// Reposition caption and caption buttons:
	int xSysButtonsLeft = 0;
	m_rectSysButtons.SetRectEmpty();

	if (!m_bReplaceFrameCaption)
	{
		m_rectCaption.SetRectEmpty();
		m_rectCaptionText.SetRectEmpty();

		for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
		{
			m_CaptionButtons [i].SetRect(CRect(0, 0, 0, 0));
		}
	}
	else
	{
		m_rectCaption = rect;
		m_rectCaption.bottom = m_rectCaption.top + m_nCaptionHeight;

		int x = m_rectCaption.right;
		int nCaptionOffsetY = 0;

		if (GetGlobalData()->IsDwmCompositionEnabled())
		{
			if (GetParent()->IsZoomed())
			{
				rect.top += cyFrameBorder / 2 + nYMargin;
				m_rectCaption.OffsetRect(0, cyFrameBorder / 2 + nYMargin);
			}

			// Hide our buttons:
			for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
			{
				m_CaptionButtons [i].SetRect(CRect(0, 0, 0, 0));
			}

			// Get system buttons size:
			NONCLIENTMETRICS ncm;
			ncm.cbSize = sizeof(ncm);
			GetGlobalData()->GetNonClientMetrics (ncm);

			int nSysButtonsWidth = 3 * ncm.iCaptionWidth;

			x -= nSysButtonsWidth;

			m_rectSysButtons = m_rectCaption;
			m_rectSysButtons.left = x;
			xSysButtonsLeft = x;
		}
		else
		{
			NONCLIENTMETRICS ncm;
			ncm.cbSize = sizeof(ncm);
			GetGlobalData()->GetNonClientMetrics(ncm);

			int nSysBtnEdge = min(ncm.iCaptionHeight, m_rectCaption.Height() - nYMargin);

			const CSize sizeCaptionButton(nSysBtnEdge, nSysBtnEdge);
			const int yOffsetCaptionButton = max(0,
				(m_rectCaption.Height() - sizeCaptionButton.cy) / 2);

			for (i = AFX_RIBBON_CAPTION_BUTTONS - 1; i >= 0; i--)
			{
				if ((m_CaptionButtons [i].GetID() == SC_RESTORE || m_CaptionButtons [i].GetID() == SC_MAXIMIZE) && (GetParent()->GetStyle() & WS_MAXIMIZEBOX) == 0)
				{
					m_CaptionButtons [i].SetRect(CRect(0, 0, 0, 0));
					continue;
				}

				if (m_CaptionButtons [i].GetID() == SC_MINIMIZE && (GetParent()->GetStyle() & WS_MINIMIZEBOX) == 0)
				{
					m_CaptionButtons [i].SetRect(CRect(0, 0, 0, 0));
					continue;
				}

				CRect rectCaptionButton(CPoint(x - sizeCaptionButton.cx, m_rectCaption.top + yOffsetCaptionButton), sizeCaptionButton);

				m_CaptionButtons [i].SetRect(rectCaptionButton);

				x -= sizeCaptionButton.cx;

				if (m_CaptionButtons [i].GetID() == SC_RESTORE || m_CaptionButtons [i].GetID() == SC_MAXIMIZE)
				{
					m_CaptionButtons [i].SetID(GetParent()->IsZoomed() ? SC_RESTORE : SC_MAXIMIZE);
				}
			}
		}

		m_rectCaptionText = m_rectCaption;

		if (GetGlobalData()->IsDwmCompositionEnabled())
		{
			m_rectCaptionText.top += GetSystemMetrics(SM_CYSIZEFRAME) / 2;
		}

		m_rectCaptionText.right = x - nXMargin;
		m_rectCaptionText.OffsetRect(0, nCaptionOffsetY);

		xSysButtonsLeft = m_rectCaptionText.right;
	}

	// Reposition main button:
	CSize sizeMainButton = m_sizeMainButton;
	if (IsWindows7Look())
	{
		sizeMainButton.cx += 2 * nYTabMargin;
	}

	double scale = GetGlobalData()->GetRibbonImageScale();
	if (scale > 1.)
	{
		sizeMainButton.cx = (int)(.5 + scale * sizeMainButton.cx);
		sizeMainButton.cy = (int)(.5 + scale * sizeMainButton.cy);
	}

	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		if (bHideAll)
		{
			m_pMainButton->SetRect(CRect(0, 0, 0, 0));
		}
		else
		{
			int yOffset = nYMargin;

			if (GetGlobalData()->IsDwmCompositionEnabled())
			{
				yOffset += GetSystemMetrics(SM_CYSIZEFRAME) / 2;
			}

			m_pMainButton->SetRect(CRect(CPoint(rect.left, rect.top + yOffset), sizeMainButton));

			if (!IsWindows7Look())
			{
				m_rectCaptionText.left = m_pMainButton->GetRect().right + nXMargin;
			}
			else
			{
				CRect rectMainBtn = rect;
				rectMainBtn.top = m_rectCaption.IsRectEmpty() ? rect.top : m_rectCaption.bottom;
				rectMainBtn.bottom = rectMainBtn.top + m_nTabsHeight;
				rectMainBtn.right = rectMainBtn.left + sizeMainButton.cx;

				m_pMainButton->SetRect(rectMainBtn);

				if (IsQuickAccessToolbarOnTop())
				{
					m_rectCaptionText.left = m_rectCaption.left + ::GetSystemMetrics(SM_CXSMICON) + 4 * nXMargin;
				}
			}
		}
	}

	CRect rectCategory = rect;

	// Reposition quick access toolbar:
	int nQAToolbarHeight = 0;

	if (bHideAll)
	{
		m_QAToolbar.m_rect.SetRectEmpty();
		m_TabElements.m_rect.SetRectEmpty();
	}
	else
	{
		CSize sizeAQToolbar = m_QAToolbar.GetRegularSize(&dc);

		if (IsQuickAccessToolbarOnTop())
		{
			m_QAToolbar.m_rect = m_rectCaptionText;

			const int yOffset = max(0, (m_rectCaptionText.Height() - sizeAQToolbar.cy) / 2);

			m_QAToolbar.m_rect.top += yOffset;
			m_QAToolbar.m_rect.bottom = m_QAToolbar.m_rect.top + sizeAQToolbar.cy;

			if (GetGlobalData()->IsDwmCompositionEnabled())
			{
				m_QAToolbar.m_rect.top += nYMargin;
			}

			m_QAToolbar.m_rect.right = min(m_QAToolbar.m_rect.left + sizeAQToolbar.cx, m_rectCaptionText.right - 50);

			m_QAToolbar.OnAfterChangeRect(&dc);

			int nQAActualWidth = m_QAToolbar.GetActualWidth();
			int nQARight = m_QAToolbar.m_rect.left + nQAActualWidth + nXMargin;

			if (nQARight < m_QAToolbar.m_rect.right)
			{
				m_QAToolbar.m_rect.right = nQARight;
			}

			m_rectCaptionText.left = m_QAToolbar.m_rect.right;
			if (!IsWindows7Look())
			{
				m_rectCaptionText.left += CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarRightMargin();
			}
			else
			{
				m_rectCaptionText.left += 3 * nXMargin;
			}
		}
		else
		{
			m_QAToolbar.m_rect = rect;
			m_QAToolbar.m_rect.top = m_QAToolbar.m_rect.bottom - sizeAQToolbar.cy;
			nQAToolbarHeight = sizeAQToolbar.cy;

			rectCategory.bottom = m_QAToolbar.m_rect.top;
		}
	}

	m_QAToolbar.OnAfterChangeRect(&dc);

	if (!bHideAll)
	{
		const int yTabTop = m_rectCaption.IsRectEmpty() ? rect.top : m_rectCaption.bottom;
		const int yTabBottom = rect.bottom - nCategoryHeight - nQAToolbarHeight;

		// Reposition tab elements:
		CSize sizeTabElemens = m_TabElements.GetCompactSize(&dc);

		const int yOffset = max(0, (yTabBottom - yTabTop - sizeTabElemens.cy) / 2);
		const int nTabElementsHeight = min(m_nTabsHeight, sizeTabElemens.cy);

		m_TabElements.m_rect = CRect(CPoint(rect.right - sizeTabElemens.cx, yTabTop + yOffset), CSize(sizeTabElemens.cx, nTabElementsHeight));

		// Reposition tabs:

		const int nTabs = GetVisibleCategoryCount();

		if (nTabs > 0)
		{
			const int nTabLeftOffset = sizeMainButton.cx + 1;
			const int cxTabsArea = rect.Width() - nTabLeftOffset - sizeTabElemens.cx - nXMargin;
			const int nMaxTabWidth = cxTabsArea / nTabs;

			int x = rect.left + nTabLeftOffset;
			BOOL bIsFirstContextTab = TRUE;
			BOOL bCaptionOnRight = FALSE;

			m_Tabs.m_rect.SetRect(x,  yTabTop, cxTabsArea, yTabBottom);

			int cxTabs = 0;

			for (i = 0; i < (int)m_arCategories.GetSize(); i++)
			{
				CMFCRibbonCategory* pCategory = m_arCategories [i];
				ASSERT_VALID(pCategory);

				if (pCategory->IsVisible())
				{
					CRect rectTabText(0, 0, nMaxTabWidth, m_nTabsHeight);

					dc.DrawText(pCategory->m_strName, rectTabText, DT_CALCRECT | DT_SINGLELINE | DT_VCENTER);

					int nTextWidth = rectTabText.Width();
					int nCurrTabMargin = nXTabMargin + nTextWidth / 40;

					pCategory->m_Tab.m_nFullWidth = nTextWidth + 2 * nCurrTabMargin;

					const UINT uiContextID = pCategory->GetContextID();

					if (uiContextID != 0 && m_bReplaceFrameCaption)
					{
						// If the current tab is last in current context, and there is no space
						// for category caption width, add extra space:
						BOOL bIsSingle = TRUE;

						for (int j = 0; j < (int)m_arCategories.GetSize(); j++)
						{
							CMFCRibbonCategory* pCategoryNext = m_arCategories [j];
							ASSERT_VALID(pCategoryNext);

							if (i != j && pCategoryNext->GetContextID() == uiContextID)
							{
								bIsSingle = FALSE;
								break;
							}
						}

						if (bIsSingle)
						{
							CMFCRibbonContextCaption* pCaption = FindContextCaption(uiContextID);
							if (pCaption != NULL)
							{
								ASSERT_VALID(pCaption);

								const int nMinCaptionWidth = dc.GetTextExtent(pCaption->GetText()).cx + 2 * nXTabMargin;

								if (nMinCaptionWidth > pCategory->m_Tab.m_nFullWidth)
								{
									pCategory->m_Tab.m_nFullWidth = nMinCaptionWidth;
								}
							}
						}
					}

					cxTabs += pCategory->m_Tab.m_nFullWidth;
				}
				else
				{
					pCategory->m_Tab.m_nFullWidth = 0;
				}
			}

			BOOL bNoSpace = cxTabs > cxTabsArea;

			for (i = 0; i < (int)m_arCategories.GetSize(); i++)
			{
				CMFCRibbonCategory* pCategory = m_arCategories [i];
				ASSERT_VALID(pCategory);

				if (!pCategory->IsVisible())
				{
					pCategory->m_Tab.SetRect(CRect(0, 0, 0, 0));
					continue;
				}

				int nTabWidth = pCategory->m_Tab.m_nFullWidth;

				if (nTabWidth > nMaxTabWidth && bNoSpace)
				{
					pCategory->m_Tab.m_bIsTruncated = TRUE;

					if (nTabWidth > 0)
					{
						m_nTabTruncateRatio = max(m_nTabTruncateRatio, (int)(100 - 100. * nMaxTabWidth / nTabWidth));
					}

					nTabWidth = nMaxTabWidth;
				}
				else
				{
					pCategory->m_Tab.m_bIsTruncated = FALSE;
				}

				pCategory->m_Tab.SetRect(CRect(x, yTabTop, x + nTabWidth, yTabBottom));

				const UINT uiContextID = pCategory->GetContextID();

				if (uiContextID != 0 && m_bReplaceFrameCaption)
				{
					CMFCRibbonContextCaption* pCaption = FindContextCaption(uiContextID);
					if (pCaption != NULL)
					{
						ASSERT_VALID(pCaption);

						int nCaptionWidth = max(nTabWidth, dc.GetTextExtent(pCaption->m_strText).cx);

						CRect rectOld = pCaption->GetRect();
						CRect rectCaption = m_rectCaption;

						rectCaption.left = rectOld.left == 0 ? x : rectOld.left;
						rectCaption.right = min(xSysButtonsLeft, x + nCaptionWidth);

						if (bIsFirstContextTab)
						{
							if (IsQuickAccessToolbarOnTop() && rectCaption.left - nXTabMargin < m_QAToolbar.m_rect.right)
							{
								m_QAToolbar.m_rect.right = rectCaption.left - nXTabMargin;

								if (m_QAToolbar.m_rect.right <= m_QAToolbar.m_rect.left)
								{
									m_QAToolbar.m_rect.SetRectEmpty();
								}

								m_QAToolbar.OnAfterChangeRect(&dc);

								m_rectCaptionText.left = rectCaption.right + nXTabMargin;
								bCaptionOnRight = TRUE;
							}
							else
							{
								const int yCaptionRight = min(m_rectCaptionText.right, x);
								const int nCaptionWidthLeft = yCaptionRight - m_rectCaptionText.left;
								const int nCaptionWidthRight = m_rectCaption.right - rectCaption.right - nXTabMargin;

								if (nCaptionTextWidth > nCaptionWidthLeft && nCaptionWidthLeft < nCaptionWidthRight)
								{
									m_rectCaptionText.left = rectCaption.right + nXTabMargin;
									bCaptionOnRight = TRUE;
								}
								else
								{
									m_rectCaptionText.right = yCaptionRight;
								}
							}

							bIsFirstContextTab = FALSE;
						}
						else if (bCaptionOnRight)
						{
							m_rectCaptionText.left = rectCaption.right + nXTabMargin;
						}

						pCaption->SetRect(rectCaption);

						pCaption->m_nRightTabX = pCategory->m_Tab.m_bIsTruncated ? -1 : pCategory->m_Tab.GetRect().right;
					}
				}

				x += nTabWidth;
			}
		}

		rectCategory.top = yTabBottom;
	}

	m_TabElements.OnAfterChangeRect(&dc);

	CRect rectCategoryRedraw = rectCategory;

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);

		m_pActiveCategory->m_rect = bHideAll ? CRect(0, 0, 0, 0) : rectCategory;

		if (nCategoryHeight > 0)
		{
			int nLastPanelIndex = m_pActiveCategory->GetPanelCount() - 1;

			CRect rectLastPaneOld;
			rectLastPaneOld.SetRectEmpty();

			if (nLastPanelIndex >= 0)
			{
				rectLastPaneOld = m_pActiveCategory->GetPanel(nLastPanelIndex)->GetRect();
			}

			m_pActiveCategory->RecalcLayout(&dc);

			if (nLastPanelIndex >= 0 && m_pActiveCategory->GetPanel(nLastPanelIndex)->GetRect() == rectLastPaneOld)
			{
				rectCategoryRedraw.left = rectLastPaneOld.right;
			}
		}
	}

	dc.SelectObject(pOldFont);

	if (GetGlobalData()->IsDwmCompositionEnabled() && m_bReplaceFrameCaption)
	{
		GetParent()->ModifyStyleEx(0, WS_EX_WINDOWEDGE);

		MARGINS margins;
		margins.cxLeftWidth = 0;
		margins.cxRightWidth = 0;
		margins.cyTopHeight = m_rectCaption.bottom;
		margins.cyBottomHeight = 0;

		if (_AfxDwmExtendFrameIntoClientArea(GetParent()->GetSafeHwnd(), &margins) == S_OK)
		{
			m_bIsTransparentCaption = TRUE;
		}
	}

	if (m_bForceRedraw)
	{
		RedrawWindow();
		m_bForceRedraw = FALSE;
	}
	else
	{
		InvalidateRect(m_rectCaption);

		CRect rectTabs = rect;
		rectTabs.top = m_rectCaption.IsRectEmpty() ? rect.top : m_rectCaption.bottom;
		rectTabs.bottom = rectTabs.top + m_nTabsHeight + 2 * nYTabMargin;

		InvalidateRect(rectTabs);
		InvalidateRect(m_QAToolbar.m_rect);
		InvalidateRect(rectCategoryRedraw);

		UpdateWindow();
	}

	CMenu* pSysMenu = GetParent()->GetSystemMenu(FALSE);

	if (m_bReplaceFrameCaption && pSysMenu->GetSafeHmenu() != NULL && !m_bIsTransparentCaption)
	{
		for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
		{
			CString strName;
			pSysMenu->GetMenuString(m_CaptionButtons [i].GetID(), strName, MF_BYCOMMAND);

			strName = strName.SpanExcluding(_T("\t"));
			strName.Remove(_T('&'));

			m_CaptionButtons [i].SetToolTipText(strName);
		}
	}

	UpdateToolTipsRect();

	if (!m_bSingleLevelAccessibilityMode)
	{
		m_Tabs.UpdateTabs(m_arCategories);
	}
}

void CMFCRibbonBar::OnFillBackground(CDC* pDC, CRect rectClient)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_bIsTransparentCaption)
	{
		rectClient.top = m_rectCaption.bottom;
	}

	CMFCVisualManager::GetInstance()->OnFillBarBackground(pDC, this, rectClient, rectClient);
}

CMFCRibbonBaseElement* CMFCRibbonBar::HitTest(CPoint point, BOOL bCheckActiveCategory, BOOL bCheckPanelCaption)
{
	ASSERT_VALID(this);

	int i = 0;

	// Check for the main button:
	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		CRect rectMainButton = m_pMainButton->GetRect();

		if (!IsWindows7Look())
		{
			rectMainButton.left = rectMainButton.top = 0;
		}

		if (rectMainButton.PtInRect(point))
		{
			return m_pMainButton;
		}
	}

	// Check for quick access toolbar:
	CMFCRibbonBaseElement* pQAElem = m_QAToolbar.HitTest(point);
	if (pQAElem != NULL)
	{
		ASSERT_VALID(pQAElem);
		return pQAElem;
	}

	// Check for tab elements:
	CMFCRibbonBaseElement* pTabElem = m_TabElements.HitTest(point);
	if (pTabElem != NULL)
	{
		ASSERT_VALID(pTabElem);
		return pTabElem->HitTest(point);
	}

	// Check for caption buttons:
	for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
	{
		if (m_CaptionButtons [i].GetRect().PtInRect(point))
		{
			return &m_CaptionButtons [i];
		}
	}

	// Check for context captions:
	for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);

		if (m_arContextCaptions [i]->GetRect().PtInRect(point))
		{
			return m_arContextCaptions [i];
		}
	}

	// Check for tabs:
	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (pCategory->m_Tab.GetRect().PtInRect(point))
		{
			return &pCategory->m_Tab;
		}
	}

	if (bCheckActiveCategory && m_pActiveCategory != NULL && (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
	{
		ASSERT_VALID(m_pActiveCategory);
		return m_pActiveCategory->HitTest(point, bCheckPanelCaption);
	}

	return NULL;
}

void CMFCRibbonBar::SetQuickAccessToolbarOnTop(BOOL bOnTop)
{
	ASSERT_VALID(this);
	m_bQuickAccessToolbarOnTop = bOnTop;
}

void CMFCRibbonBar::SetQuickAccessDefaultState(const CMFCRibbonQuickAccessToolBarDefaultState& state)
{
	ASSERT_VALID(this);

	m_QAToolbar.m_DefaultState.CopyFrom(state);

	CList<UINT,UINT> lstDefCommands;
	m_QAToolbar.GetDefaultCommands(lstDefCommands);

	SetQuickAccessCommands(lstDefCommands, FALSE);
}

void CMFCRibbonBar::SetQuickAccessCommands(const CList<UINT,UINT>& lstCommands, BOOL bRecalcLayout/* = TRUE*/)
{
	ASSERT_VALID(this);

	OnCancelMode();

	CString strTooltip;
	ENSURE(strTooltip.LoadString(IDS_AFXBARRES_CUSTOMIZE_QAT_TOOLTIP));

	m_QAToolbar.SetCommands(this, lstCommands, strTooltip);

	if (bRecalcLayout)
	{
		m_bForceRedraw = TRUE;
		RecalcLayout();
	}
}

void CMFCRibbonBar::GetQuickAccessCommands(CList<UINT,UINT>& lstCommands)
{
	ASSERT_VALID(this);
	m_QAToolbar.GetCommands(lstCommands);
}

void CMFCRibbonBar::OnClickButton(CMFCRibbonButton* pButton, CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pButton);

	const UINT nID = pButton->GetID();

	pButton->m_bIsHighlighted = pButton->m_bIsPressed = FALSE;
	RedrawWindow(pButton->GetRect());

	if (nID != 0 && nID != (UINT)-1)
	{
		GetOwner()->SendMessage(WM_COMMAND, nID);
	}
}

void CMFCRibbonBar::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	ASSERT_VALID(this);

	CMFCRibbonCmdUI state;
	state.m_pOther = this;

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->OnUpdateCmdUI(&state, pTarget, bDisableIfNoHndler);
	}

	m_QAToolbar.OnUpdateCmdUI(&state, pTarget, bDisableIfNoHndler);
	m_TabElements.OnUpdateCmdUI(&state, pTarget, bDisableIfNoHndler);

	// update the dialog controls added to the ribbon
	UpdateDialogControls(pTarget, bDisableIfNoHndler);
}

BOOL CMFCRibbonBar::OnCommand(WPARAM wParam, LPARAM lParam)
{
	BOOL bAccelerator = FALSE;
	int nNotifyCode = HIWORD(wParam);

	// Find the control send the message:
	HWND hWndCtrl = (HWND)lParam;
	if (hWndCtrl == NULL)
	{
		if (wParam == IDCANCEL) // ESC was pressed
		{
			return TRUE;
		}

		if (wParam != IDOK ||
			(hWndCtrl = ::GetFocus()) == NULL)
		{
			return FALSE;
		}

		bAccelerator = TRUE;
		nNotifyCode = 0;
	}

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);

		return m_pActiveCategory->NotifyControlCommand(bAccelerator, nNotifyCode, wParam, lParam);
	}

	return FALSE;
}

CMFCRibbonBaseElement* CMFCRibbonBar::FindByID(UINT uiCmdID, BOOL bVisibleOnly, BOOL bExcludeQAT) const
{
	ASSERT_VALID(this);

	if (!bExcludeQAT)
	{
		CMFCRibbonBaseElement* pQATElem = ((CMFCRibbonBar*) this)->m_QAToolbar.FindByID(uiCmdID);
		if (pQATElem != NULL)
		{
			ASSERT_VALID(pQATElem);
			return pQATElem;
		}
	}

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);

		CMFCRibbonBaseElement* pElem = m_pMainCategory->FindByID(uiCmdID, bVisibleOnly);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (bVisibleOnly && !pCategory->IsVisible())
		{
			continue;
		}

		CMFCRibbonBaseElement* pElem = pCategory->FindByID(uiCmdID, bVisibleOnly);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return((CMFCRibbonBar*) this)->m_TabElements.FindByID(uiCmdID);
}

CMFCRibbonBaseElement* CMFCRibbonBar::FindByData(DWORD_PTR dwData, BOOL bVisibleOnly) const
{
	ASSERT_VALID(this);

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);

		CMFCRibbonBaseElement* pElem = m_pMainCategory->FindByData(dwData, bVisibleOnly);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (bVisibleOnly && !pCategory->IsVisible())
		{
			continue;
		}

		CMFCRibbonBaseElement* pElem = pCategory->FindByData(dwData, bVisibleOnly);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return((CMFCRibbonBar*) this)->m_TabElements.FindByData(dwData);
}

void CMFCRibbonBar::GetElementsByID(UINT uiCmdID, CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arButtons)
{
	ASSERT_VALID(this);

	arButtons.RemoveAll();

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);
		m_pMainCategory->GetElementsByID(uiCmdID, arButtons);
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		pCategory->GetElementsByID(uiCmdID, arButtons);
	}

	m_QAToolbar.GetElementsByID(uiCmdID, arButtons);
	m_TabElements.GetElementsByID(uiCmdID, arButtons);
}

BOOL CMFCRibbonBar::SetElementKeys(UINT uiCmdID, LPCTSTR lpszKeys, LPCTSTR lpszMenuKeys)
{
	ASSERT_VALID(this);

	int i = 0;

	BOOL bFound = FALSE;

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);

		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		m_pMainCategory->GetElementsByID(uiCmdID, arButtons);

		for (int j = 0; j < (int)arButtons.GetSize(); j++)
		{
			ASSERT_VALID(arButtons [j]);
			arButtons [j]->SetKeys(lpszKeys, lpszMenuKeys);

			bFound = TRUE;
		}
	}

	for (i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		pCategory->GetElementsByID(uiCmdID, arButtons);

		for (int j = 0; j < (int)arButtons.GetSize(); j++)
		{
			ASSERT_VALID(arButtons [j]);
			arButtons [j]->SetKeys(lpszKeys, lpszMenuKeys);

			bFound = TRUE;
		}
	}

	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
	m_TabElements.GetElementsByID(uiCmdID, arButtons);

	for (i = 0; i < (int)arButtons.GetSize(); i++)
	{
		ASSERT_VALID(arButtons [i]);
		arButtons [i]->SetKeys(lpszKeys, lpszMenuKeys);

		bFound = TRUE;
	}

	return bFound;
}

void CMFCRibbonBar::AddToTabs(CMFCRibbonBaseElement* pElement)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElement);

	pElement->SetParentRibbonBar(this);
	pElement->m_bIsTabElement = TRUE;
	m_TabElements.AddButton(pElement);

	if (m_nSystemButtonsNum > 0)
	{
		// Move the new element prior to system buttons:
		int nSize = (int)m_TabElements.m_arButtons.GetSize();

		m_TabElements.m_arButtons.RemoveAt(nSize - 1);
		m_TabElements.m_arButtons.InsertAt(nSize - m_nSystemButtonsNum - 1, pElement);
	}
}

void CMFCRibbonBar::RemoveAllFromTabs()
{
	ASSERT_VALID(this);

	if (m_nSystemButtonsNum > 0)
	{
		while ((int)m_TabElements.m_arButtons.GetSize() > m_nSystemButtonsNum)
		{
			delete m_TabElements.m_arButtons [0];
			m_TabElements.m_arButtons.RemoveAt(0);
		}
	}
	else
	{
		m_TabElements.RemoveAll();
	}
}

static CString strTipText;

BOOL CMFCRibbonBar::OnNeedTipText(UINT /*id*/, NMHDR* pNMH, LRESULT* /*pResult*/)
{
	if (!m_bToolTip)
	{
		return TRUE;
	}

	if (m_pToolTip->GetSafeHwnd() == NULL || pNMH->hwndFrom != m_pToolTip->GetSafeHwnd())
	{
		return FALSE;
	}

	if (CMFCPopupMenu::GetActiveMenu() != NULL)
	{
		return FALSE;
	}

	LPNMTTDISPINFO pTTDispInfo = (LPNMTTDISPINFO) pNMH;
	ENSURE(pTTDispInfo != NULL);
	ASSERT((pTTDispInfo->uFlags & TTF_IDISHWND) == 0);

	CPoint point;

	::GetCursorPos(&point);
	ScreenToClient(&point);

	CMFCRibbonBaseElement* pHit = HitTest(point, TRUE);
	if (pHit == NULL)
	{
		return TRUE;
	}

	ASSERT_VALID(pHit);

	strTipText = pHit->GetToolTipText();
	if (strTipText.IsEmpty())
	{
		return TRUE;
	}

	CMFCToolTipCtrl* pToolTip = DYNAMIC_DOWNCAST(CMFCToolTipCtrl, m_pToolTip);

	if (pToolTip != NULL)
	{
		ASSERT_VALID(pToolTip);

		if (m_bToolTipDescr)
		{
			pToolTip->SetDescription(pHit->GetDescription());
		}

		pToolTip->SetHotRibbonButton(DYNAMIC_DOWNCAST(CMFCRibbonButton, pHit));

		if (pHit->IsShowTooltipOnBottom())
		{
			CRect rectWindow;
			GetWindowRect(rectWindow);

			CRect rectElem = pHit->GetRect();
			ClientToScreen(&rectElem);

			pToolTip->SetLocation(CPoint(rectElem.left, rectWindow.bottom));
		}

		pToolTip->SetFixedWidth(m_nTooltipWidthRegular, m_nTooltipWidthLargeImage);
	}

	if (m_nKeyboardNavLevel >= 0)
	{
		m_pToolTip->SetWindowPos(&wndTopMost, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}

	pTTDispInfo->lpszText = const_cast<LPTSTR>((LPCTSTR) strTipText);
	return TRUE;
}

BOOL CMFCRibbonBar::PreTranslateMessage(MSG* pMsg)
{
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_MOUSEMOVE:
		if (m_pToolTip->GetSafeHwnd() != NULL)
		{
			m_pToolTip->RelayEvent(pMsg);
		}

		break;
	}

	if (pMsg->message == WM_LBUTTONDOWN)
	{
		CMFCRibbonRichEditCtrl* pEdit = DYNAMIC_DOWNCAST(CMFCRibbonRichEditCtrl, GetFocus());
		if (pEdit != NULL)
		{
			ASSERT_VALID(pEdit);

			CPoint point;

			::GetCursorPos(&point);
			ScreenToClient(&point);

			pEdit->GetOwnerRibbonEdit ().PreLMouseDown(point);
		}
	}

	if (pMsg->message == WM_KEYDOWN)
	{
		int nChar = (int)pMsg->wParam;

		if (::GetFocus() == GetSafeHwnd())
		{
			CMFCRibbonBaseElement* pFocused = GetFocused();
			if (pFocused != NULL)
			{
				ASSERT_VALID(pFocused);
				if (pFocused->OnProcessKey(nChar))
				{
					return TRUE;
				}
			}
		}

		switch (nChar)
		{
		case VK_ESCAPE:
			if (m_nKeyboardNavLevel > 0)
			{
				SetKeyboardNavigationLevel(m_pKeyboardNavLevelParent);
			}
			else if (CMFCPopupMenu::GetActiveMenu() == NULL)
			{
				DeactivateKeyboardFocus();

				CFrameWnd* pParentFrame = GetParentFrame();
				if (pParentFrame != NULL)
				{
					ASSERT_VALID(pParentFrame);
					pParentFrame->SetFocus();
				}
			}

			break;

		case VK_SPACE:
			if (m_nKeyboardNavLevel >= 0 && CMFCPopupMenu::GetActiveMenu() == NULL && ::GetFocus() == GetSafeHwnd())
			{
				DeactivateKeyboardFocus();

				CFrameWnd* pParentFrame = GetParentFrame();
				if (pParentFrame != NULL)
				{
					ASSERT_VALID(pParentFrame);
					pParentFrame->SetFocus();
				}
			}

		case VK_LEFT:
		case VK_RIGHT:
		case VK_UP:
		case VK_DOWN:
		case VK_RETURN:
		case VK_TAB:
			if (::GetFocus() != GetSafeHwnd())
			{
				if (nChar != VK_TAB)
				{
					break;
				}
				else
				{
					if (!IsChild(GetFocus()))
					{
						break;
					}
				}
			}

			if (NavigateRibbon(nChar))
			{
				return TRUE;
			}

		default:
			if (ProcessKey(nChar))
			{
				return TRUE;
			}
		}
	}

	return CPane::PreTranslateMessage(pMsg);
}

LRESULT CMFCRibbonBar::OnUpdateToolTips(WPARAM wp, LPARAM)
{
	UINT nTypes = (UINT) wp;

	if (nTypes & AFX_TOOLTIP_TYPE_RIBBON)
	{
		CTooltipManager::CreateToolTip(m_pToolTip, this, AFX_TOOLTIP_TYPE_RIBBON);

		CRect rectDummy(0, 0, 0, 0);

		m_pToolTip->SetMaxTipWidth(nTooltipMaxWidth);

		m_pToolTip->AddTool(this, LPSTR_TEXTCALLBACK, &rectDummy, nIdToolTipClient);
		m_pToolTip->AddTool(this, LPSTR_TEXTCALLBACK, &rectDummy, nIdToolTipCaption);

		UpdateToolTipsRect();
	}

	return 0;
}

void CMFCRibbonBar::PopTooltip()
{
	ASSERT_VALID(this);

	if (m_pToolTip->GetSafeHwnd() != NULL)
	{
		m_pToolTip->Pop();
	}
}

BOOL CMFCRibbonBar::DrawMenuImage(CDC* pDC, const CMFCToolBarMenuButton* pMenuItem, const CRect& rectImage)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	ASSERT_VALID(pMenuItem);

	UINT uiCmdID = pMenuItem->m_nID;
	if (uiCmdID == 0)
	{
		return FALSE;
	}

	if (uiCmdID == idCut)
	{
		uiCmdID = ID_EDIT_CUT;
	}

	if (uiCmdID == idCopy)
	{
		uiCmdID = ID_EDIT_COPY;
	}

	if (uiCmdID == idPaste)
	{
		uiCmdID = ID_EDIT_PASTE;
	}

	if (uiCmdID == idSelectAll)
	{
		uiCmdID = ID_EDIT_SELECT_ALL;
	}

	CMFCRibbonBaseElement* pElem = FindByID(uiCmdID, FALSE, TRUE);
	if (pElem == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pElem);

	BOOL bIsRibbonImageScale = GetGlobalData()->IsRibbonImageScaleEnabled();
	GetGlobalData()->EnableRibbonImageScale(FALSE);

	const CSize sizeElemImage = pElem->GetImageSize(CMFCRibbonButton::RibbonImageSmall);

	if (sizeElemImage == CSize(0, 0) || sizeElemImage.cx > rectImage.Width() || sizeElemImage.cy > rectImage.Height())
	{
		GetGlobalData()->EnableRibbonImageScale(bIsRibbonImageScale);
		return FALSE;
	}

	int dx = (rectImage.Width() - sizeElemImage.cx) / 2;
	int dy = (rectImage.Height() - sizeElemImage.cy) / 2;

	CRect rectDraw = rectImage;
	rectDraw.DeflateRect(dx, dy);

	BOOL bWasDisabled = pElem->IsDisabled();
	BOOL bWasChecked = pElem->IsChecked();

	pElem->m_bIsDisabled = pMenuItem->m_nStyle & TBBS_DISABLED;
	pElem->m_bIsChecked = pMenuItem->m_nStyle & TBBS_CHECKED;

	BOOL bRes = pElem->OnDrawMenuImage(pDC, rectDraw);

	pElem->m_bIsDisabled = bWasDisabled;
	pElem->m_bIsChecked = bWasChecked;

	GetGlobalData()->EnableRibbonImageScale(bIsRibbonImageScale);
	return bRes;
}

void CMFCRibbonBar::ShowSysMenu(const CPoint& point)
{
	ASSERT_VALID(this);

	CWnd* pParentWnd = GetParent();

	if (pParentWnd->GetSafeHwnd() != NULL)
	{
		CMenu* pMenu = pParentWnd->GetSystemMenu(FALSE);
		if (pMenu->GetSafeHmenu() == NULL)
		{
			return;
		}

		pMenu->SetDefaultItem(SC_CLOSE);

		if (GetParent()->IsZoomed())
		{
			pMenu->EnableMenuItem(SC_SIZE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			pMenu->EnableMenuItem(SC_MOVE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
			pMenu->EnableMenuItem(SC_MAXIMIZE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

			pMenu->EnableMenuItem(SC_RESTORE, MF_BYCOMMAND | MF_ENABLED);
		}
		else
		{
			pMenu->EnableMenuItem(SC_RESTORE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

			pMenu->EnableMenuItem(SC_SIZE, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(SC_MOVE, MF_BYCOMMAND | MF_ENABLED);
			pMenu->EnableMenuItem(SC_MAXIMIZE, MF_BYCOMMAND | MF_ENABLED);
		}

		if ((GetParent()->GetStyle() & WS_MAXIMIZEBOX) == 0)
		{
			pMenu->DeleteMenu(SC_RESTORE, MF_BYCOMMAND);
			pMenu->DeleteMenu(SC_MAXIMIZE, MF_BYCOMMAND);
		}

		if ((GetParent()->GetStyle() & WS_MINIMIZEBOX) == 0)
		{
			pMenu->DeleteMenu(SC_MINIMIZE, MF_BYCOMMAND);
		}

		if (afxContextMenuManager != NULL)
		{
			afxContextMenuManager->ShowPopupMenu(pMenu->GetSafeHmenu(), point.x, point.y, GetParent(), TRUE, TRUE, FALSE);
		}
		else
		{
			::TrackPopupMenu(pMenu->GetSafeHmenu(), TPM_CENTERALIGN | TPM_LEFTBUTTON, point.x, point.y, 0, GetOwner()->GetSafeHwnd(), NULL);
		}
	}
}

void CMFCRibbonBar::OnPaneContextMenu(CWnd* /*pParentFrame*/, CPoint point)
{
	if (point == CPoint(-1, -1))
	{
		CMFCRibbonBaseElement* pFocused = GetFocused();
		if (pFocused != NULL)
		{
			ASSERT_VALID(pFocused);

			CRect rectFocus = pFocused->GetRect();
			ClientToScreen(&rectFocus);

			OnShowRibbonContextMenu(this, rectFocus.left, rectFocus.top, pFocused);

			CFrameWnd* pParentFrame = GetParentFrame();
			ASSERT_VALID(pParentFrame);

			pParentFrame->SetFocus();
			return;
		}
	}

	DeactivateKeyboardFocus();

	CPoint ptClient = point;
	ScreenToClient(&ptClient);

	CMFCRibbonBaseElement* pHit = HitTest(ptClient, TRUE, TRUE);

	if (pHit != NULL && pHit->IsKindOf(RUNTIME_CLASS(CMFCRibbonContextCaption)))
	{
		pHit->OnLButtonUp(point);
		return;
	}

	if (m_rectCaption.PtInRect(ptClient) && pHit == NULL)
	{
		ShowSysMenu(point);
		return;
	}

	OnShowRibbonContextMenu(this, point.x, point.y, pHit);
}

BOOL CMFCRibbonBar::OnShowRibbonContextMenu(CWnd* pWnd, int x, int y, CMFCRibbonBaseElement* pHit)
{
	DeactivateKeyboardFocus();

	ASSERT_VALID(this);
	ASSERT_VALID(pWnd);

	if (m_bAutoCommandTimer)
	{
		KillTimer(AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND);
		m_bAutoCommandTimer = FALSE;
	}

	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 && (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0) // Both left and right mouse buttons are pressed
	{
		return FALSE;
	}

	if (afxContextMenuManager == NULL)
	{
		return FALSE;
	}

	if (pHit != NULL)
	{
		ASSERT_VALID(pHit);

		if (!pHit->IsHighlighted())
		{
			pHit->m_bIsHighlighted = TRUE;
			pHit->Redraw();
		}
	}

	CMFCPopupMenu* pPopupMenu = DYNAMIC_DOWNCAST(CMFCPopupMenu, pWnd->GetParent());

	CFrameWnd* pParentFrame = GetParentFrame();
	ASSERT_VALID(pParentFrame);

	const UINT idCustomize = (UINT) -102;
	const UINT idQATOnBottom = (UINT) -103;
	const UINT idQATOnTop = (UINT) -104;
	const UINT idAddToQAT = (UINT) -105;
	const UINT idRemoveFromQAT = (UINT) -106;
	const UINT idMinimize = (UINT) -107;
	const UINT idRestore = (UINT) -108;

	CMenu menu;
	menu.CreatePopupMenu();

	{
		CString strItem;

		if (m_bIsCustomizeMenu)
		{
			ENSURE(strItem.LoadString(IDS_AFXBARRES_CUSTOMIZE_QAT_TOOLTIP));
			menu.AppendMenu(MF_STRING, (UINT) AFX_MENU_GROUP_ID, strItem);

			for (int i = 0; i < (int)m_QAToolbar.m_DefaultState.m_arCommands.GetSize(); i++)
			{
				const UINT uiCmd = m_QAToolbar.m_DefaultState.m_arCommands [i];

				CMFCRibbonBaseElement* pElement = FindByID(uiCmd, FALSE);
				if (pElement != NULL)
				{
					ASSERT_VALID(pElement);

					strItem = pElement->GetText();

					if (strItem.IsEmpty())
					{
						pElement->UpdateTooltipInfo();
						strItem = pElement->GetToolTipText();
					}

					int uiMenuCmd = -((int) uiCmd);

					menu.AppendMenu(MF_STRING, uiMenuCmd, strItem);

					if (m_QAToolbar.FindByID(uiCmd) != NULL)
					{
						menu.CheckMenuItem(uiMenuCmd, MF_CHECKED);
					}
				}
			}
		}
		else if (pHit != NULL)
		{
			ASSERT_VALID(pHit);

			UINT nID = pHit->GetQuickAccessToolBarID();

			if (pHit->m_bQuickAccessMode)
			{
				ENSURE(strItem.LoadString(IDS_AFXBARRES_REMOVE_FROM_QAT));
				menu.AppendMenu(MF_STRING, idRemoveFromQAT, strItem);
			}
			else if (pHit->CanBeAddedToQuickAccessToolBar())
			{
				ENSURE(strItem.LoadString(IDS_AFXBARRES_ADD_TO_QAT));
				menu.AppendMenu(MF_STRING, idAddToQAT, strItem);

				if (m_QAToolbar.FindByID(nID) != NULL)
				{
					// Already on QAT, disable this item
					menu.EnableMenuItem(idAddToQAT, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
				}
			}
		}

		if (menu.GetMenuItemCount() > 0)
		{
			menu.AppendMenu(MF_SEPARATOR);
		}

		ENSURE(strItem.LoadString(m_bIsCustomizeMenu ? IDS_AFXBARRES_MORE_COMMANDS : IDS_AFXBARRES_CUSTOMIZE_QAT));

		menu.AppendMenu(MF_STRING, idCustomize, strItem);

		if (IsQuickAccessToolbarOnTop())
		{
			ENSURE(strItem.LoadString(m_bIsCustomizeMenu ? IDS_AFXBARRES_PLACE_BELOW_RIBBON : IDS_AFXBARRES_PLACE_QAT_BELOW_RIBBON));
			menu.AppendMenu(MF_STRING, idQATOnBottom, strItem);
		}
		else
		{
			ENSURE(strItem.LoadString(m_bIsCustomizeMenu ? IDS_AFXBARRES_PLACE_ABOVE_RIBBON : IDS_AFXBARRES_PLACE_QAT_ABOVE_RIBBON));
			menu.AppendMenu(MF_STRING, idQATOnTop, strItem);
		}

		menu.AppendMenu(MF_SEPARATOR);

		if (m_dwHideFlags == AFX_RIBBONBAR_HIDE_ELEMENTS)
		{
			ENSURE(strItem.LoadString(IDS_AFXBARRES_MINIMIZE_RIBBON));
			menu.AppendMenu(MF_STRING, idRestore, strItem);
			menu.CheckMenuItem(idRestore, MF_CHECKED);
		}
		else
		{
			ENSURE(strItem.LoadString(IDS_AFXBARRES_MINIMIZE_RIBBON));
			menu.AppendMenu(MF_STRING, idMinimize, strItem);
		}
	}

	HWND hwndThis = pWnd->GetSafeHwnd();

	if (pPopupMenu != NULL)
	{
		afxContextMenuManager->SetDontCloseActiveMenu();
	}

	int nMenuResult = afxContextMenuManager->TrackPopupMenu(menu, x, y, pWnd);

	if (pPopupMenu != NULL)
	{
		afxContextMenuManager->SetDontCloseActiveMenu(FALSE);
	}

	if (!::IsWindow(hwndThis))
	{
		return FALSE;
	}

	if (pHit != NULL)
	{
		ASSERT_VALID(pHit);

		pHit->m_bIsHighlighted = FALSE;

		CMFCRibbonBaseElement* pDroppedDown = pHit->GetDroppedDown();

		if (pDroppedDown != NULL)
		{
			ASSERT_VALID(pDroppedDown);

			pDroppedDown->ClosePopupMenu();
			pHit->m_bIsDroppedDown = FALSE;
		}

		pHit->Redraw();
	}

	BOOL bRecalcLayout = FALSE;

	switch (nMenuResult)
	{
	case idCustomize:
		{
			if (pHit == m_pHighlighted)
			{
				m_pHighlighted = NULL;
			}

			if (pHit == m_pPressed)
			{
				m_pPressed = NULL;
			}

			if (pPopupMenu != NULL)
			{
				pPopupMenu->SendMessage(WM_CLOSE);
			}

			if (pParentFrame->SendMessage(AFX_WM_ON_RIBBON_CUSTOMIZE, 0, (LPARAM)this) == 0)
			{
				CMFCRibbonCustomizeDialog* pDlg = new CMFCRibbonCustomizeDialog (pParentFrame, this);
				ENSURE(pDlg != NULL);

				pDlg->DoModal();
				delete pDlg;
			}

			return TRUE;
		}
		break;

	case idAddToQAT:
		if (pHit != NULL)
		{
			ASSERT_VALID(pHit);

			if (pHit->m_bIsDefaultMenuLook)
			{
				CMFCRibbonBaseElement* pElem = FindByID(pHit->GetID(), FALSE);
				if (pElem != NULL)
				{
					ASSERT_VALID(pElem);
					pHit = pElem;
				}
			}

			bRecalcLayout = pHit->OnAddToQAToolbar(m_QAToolbar);

		}
		break;

	case idRemoveFromQAT:
		ASSERT_VALID(pHit);

		if (pHit == m_pHighlighted)
		{
			m_pHighlighted = NULL;
		}

		if (pHit == m_pPressed)
		{
			m_pPressed = NULL;
		}

		m_QAToolbar.Remove(pHit);
		bRecalcLayout = TRUE;
		break;

	case idQATOnBottom:
		SetQuickAccessToolbarOnTop(FALSE);
		bRecalcLayout = TRUE;
		break;

	case idQATOnTop:
		SetQuickAccessToolbarOnTop(TRUE);
		bRecalcLayout = TRUE;
		break;

	case idMinimize:
		if (m_pActiveCategory != NULL)
		{
			ASSERT_VALID(m_pActiveCategory);
			m_pActiveCategory->ShowElements(FALSE);
			RedrawWindow();
		}
		break;

	case idRestore:
		if (m_pActiveCategory != NULL)
		{
			ASSERT_VALID(m_pActiveCategory);
			m_pActiveCategory->ShowElements();
			RedrawWindow();
		}
		break;

	default:
		if (m_bIsCustomizeMenu)
		{
			UINT uiCmd = -nMenuResult;

			if (uiCmd != 0)
			{
				CMFCRibbonBaseElement* pElement = FindByID(uiCmd, FALSE);
				if (pElement != NULL)
				{
					ASSERT_VALID(pElement);

					if (m_QAToolbar.FindByID(uiCmd) != NULL)
					{
						m_QAToolbar.Remove(pElement);
					}
					else
					{
						m_QAToolbar.Add(pElement);
					}

					bRecalcLayout = TRUE;
					break;
				}
			}
		}

		if (pPopupMenu != NULL)
		{
			CMFCPopupMenu::m_pActivePopupMenu = pPopupMenu;
		}

		return FALSE;
	}

	if (pPopupMenu != NULL)
	{
		pPopupMenu->SendMessage(WM_CLOSE);
	}

	if (bRecalcLayout)
	{
		m_bForceRedraw = TRUE;
		RecalcLayout();

		if (pParentFrame->GetSafeHwnd() != NULL)
		{
			pParentFrame->RecalcLayout();
			pParentFrame->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
		}
	}

	return TRUE;
}

BOOL CMFCRibbonBar::OnShowRibbonQATMenu(CWnd* pWnd, int x, int y, CMFCRibbonBaseElement* pHit)
{
	ASSERT_VALID(this);

	BOOL bIsCustomizeMenu = m_bIsCustomizeMenu;
	m_bIsCustomizeMenu = TRUE;

	BOOL bRes = OnShowRibbonContextMenu(pWnd, x, y, pHit);

	m_bIsCustomizeMenu = bIsCustomizeMenu;

	return bRes;
}

void CMFCRibbonBar::OnSizing(UINT fwSide, LPRECT pRect)
{
	if (CMFCPopupMenu::GetActiveMenu() != NULL)
	{
		CMFCPopupMenu::GetActiveMenu()->SendMessage(WM_CLOSE);
	}

	CPane::OnSizing(fwSide, pRect);
}

BOOL CMFCRibbonBar::SaveState(LPCTSTR lpszProfileName, int nIndex, UINT uiID)
{
	CString strProfileName = ::AFXGetRegPath(AFX_RIBBON_PROFILE, lpszProfileName);

	BOOL bResult = FALSE;

	if (nIndex == -1)
	{
		nIndex = GetDlgCtrlID();
	}

	CString strSection;
	if (uiID == (UINT) -1)
	{
		strSection.Format(AFX_REG_SECTION_FMT, (LPCTSTR)strProfileName, nIndex);
	}
	else
	{
		strSection.Format(AFX_REG_SECTION_FMT_EX, (LPCTSTR)strProfileName, nIndex, uiID);
	}

	CSettingsStoreSP regSP;
	CSettingsStore& reg = regSP.Create(FALSE, FALSE);

	if (reg.CreateKey(strSection))
	{
		reg.Write(AFX_REG_ENTRY_QA_TOOLBAR_LOCATION, m_bQuickAccessToolbarOnTop);

		CList<UINT,UINT> lstCommands;
		GetQuickAccessCommands(lstCommands);

		reg.Write(AFX_REG_ENTRY_QA_TOOLBAR_COMMANDS, lstCommands);

		reg.Write(AFX_REG_ENTRY_RIBBON_IS_MINIMIZED, (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0);
	}

	bResult = CPane::SaveState(lpszProfileName, nIndex, uiID);

	return bResult;
}

BOOL CMFCRibbonBar::LoadState(LPCTSTR lpszProfileName, int nIndex, UINT uiID)
{
	CString strProfileName = ::AFXGetRegPath(AFX_RIBBON_PROFILE, lpszProfileName);

	if (nIndex == -1)
	{
		nIndex = GetDlgCtrlID();
	}

	CString strSection;
	if (uiID == (UINT) -1)
	{
		strSection.Format(AFX_REG_SECTION_FMT, (LPCTSTR)strProfileName, nIndex);
	}
	else
	{
		strSection.Format(AFX_REG_SECTION_FMT_EX, (LPCTSTR)strProfileName, nIndex, uiID);
	}

	CSettingsStoreSP regSP;
	CSettingsStore& reg = regSP.Create(FALSE, TRUE);

	if (!reg.Open(strSection))
	{
		return FALSE;
	}

	reg.Read(AFX_REG_ENTRY_QA_TOOLBAR_LOCATION, m_bQuickAccessToolbarOnTop);

	if (!m_bQuickAccessToolbarOnTop && m_bReplaceFrameCaption)
	{
		m_nCaptionHeight = GetSystemMetrics (SM_CYCAPTION) + 1;

		if (GetGlobalData()->IsDwmCompositionEnabled())
		{
			m_nCaptionHeight += GetSystemMetrics (SM_CYSIZEFRAME);
		}
	}


	CList<UINT,UINT> lstCommands;
	reg.Read(AFX_REG_ENTRY_QA_TOOLBAR_COMMANDS, lstCommands);

	m_QAToolbar.SetCommands(this, lstCommands, (CMFCRibbonQuickAccessCustomizeButton*) NULL);

	BOOL bIsMinimized = FALSE;
	reg.Read(AFX_REG_ENTRY_RIBBON_IS_MINIMIZED, bIsMinimized);

	if (bIsMinimized)
	{
		m_dwHideFlags |= AFX_RIBBONBAR_HIDE_ELEMENTS;

		if (m_pActiveCategory != NULL)
		{
			ASSERT_VALID(m_pActiveCategory);
			m_pActiveCategory->ShowElements(FALSE);
		}
	}

	RecalcLayout();

	return CPane::LoadState(lpszProfileName, nIndex, uiID);
}

void CMFCRibbonBar::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CPane::OnSettingChange(uFlags, lpszSection);

	if (uFlags == SPI_SETNONCLIENTMETRICS || uFlags == SPI_SETWORKAREA || uFlags == SPI_SETICONTITLELOGFONT)
	{
		ForceRecalcLayout();
	}
}

void CMFCRibbonBar::ForceRecalcLayout()
{
	m_bRecalcCategoryHeight = TRUE;
	m_bRecalcCategoryWidth = TRUE;

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);
		m_pMainCategory->CleanUpSizes();
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		pCategory->CleanUpSizes();
	}

	GetGlobalData()->UpdateFonts();

	CFrameWnd* pParentFrame = GetParentFrame();
	ASSERT_VALID(pParentFrame);

	m_bForceRedraw = TRUE;
	RecalcLayout();

	if (pParentFrame->GetSafeHwnd() != NULL)
	{
		pParentFrame->RecalcLayout();
		pParentFrame->RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}
}

void CMFCRibbonBar::SetMaximizeMode(BOOL bMax, CWnd* pWnd)
{
	ASSERT_VALID(this);

	if (m_bMaximizeMode == bMax)
	{
		return;
	}

	for (int i = 0; i < m_nSystemButtonsNum; i++)
	{
		int nSize = (int)m_TabElements.m_arButtons.GetSize();

		delete m_TabElements.m_arButtons [nSize - 1];
		m_TabElements.m_arButtons.SetSize(nSize - 1);
	}

	m_nSystemButtonsNum = 0;

	if (bMax)
	{
		ASSERT_VALID(pWnd);

		CFrameWnd* pFrameWnd = DYNAMIC_DOWNCAST(CFrameWnd, pWnd);
		BOOL bIsOleContainer = pFrameWnd != NULL && pFrameWnd->m_pNotifyHook != NULL;

		HMENU hSysMenu = NULL;

		CMenu* pMenu = pWnd->GetSystemMenu(FALSE);
		if (pMenu != NULL && ::IsMenu(pMenu->m_hMenu))
		{
			hSysMenu = pMenu->GetSafeHmenu();
			if (!::IsMenu(hSysMenu) || (pWnd->GetStyle() & WS_SYSMENU) == 0 && !bIsOleContainer)
			{
				hSysMenu = NULL;
			}
		}

		LONG style = ::GetWindowLong(*pWnd, GWL_STYLE);

		if (hSysMenu != NULL)
		{
			// Add a minimize box if required.
			if (style & WS_MINIMIZEBOX)
			{
				m_TabElements.AddButton(new CMFCRibbonCaptionButton(SC_MINIMIZE, pWnd->GetSafeHwnd()));
				m_nSystemButtonsNum++;
			}

			// Add a restore box if required.
			if (style & WS_MAXIMIZEBOX)
			{
				m_TabElements.AddButton(new CMFCRibbonCaptionButton(SC_RESTORE, pWnd->GetSafeHwnd()));
				m_nSystemButtonsNum++;
			}

			// Add a close box:
			CMFCRibbonCaptionButton* pBtnClose = new CMFCRibbonCaptionButton(SC_CLOSE, pWnd->GetSafeHwnd());

			if (hSysMenu != NULL)
			{
				MENUITEMINFO menuInfo;
				ZeroMemory(&menuInfo,sizeof(MENUITEMINFO));
				menuInfo.cbSize = sizeof(MENUITEMINFO);
				menuInfo.fMask = MIIM_STATE;

				if (!::GetMenuItemInfo(hSysMenu, SC_CLOSE, FALSE, &menuInfo) || (menuInfo.fState & MFS_GRAYED) || (menuInfo.fState & MFS_DISABLED))
				{
					pBtnClose->m_bIsDisabled = TRUE;
				}
			}

			m_TabElements.AddButton(pBtnClose);
			m_nSystemButtonsNum++;
		}
	}

	m_bMaximizeMode = bMax;
	m_pHighlighted = NULL;
	m_pPressed = NULL;

	RecalcLayout();
	RedrawWindow();
}

void CMFCRibbonBar::SetActiveMDIChild(CWnd* pWnd)
{
	ASSERT_VALID(this);

	for (int i = 0; i < (int)m_TabElements.m_arButtons.GetSize(); i++)
	{
		CMFCRibbonCaptionButton* pCaptionButton = DYNAMIC_DOWNCAST(CMFCRibbonCaptionButton, m_TabElements.m_arButtons [i]);

		if (pCaptionButton != NULL)
		{
			ASSERT_VALID(pCaptionButton);
			pCaptionButton->m_hwndMDIChild = pWnd->GetSafeHwnd();
		}
	}
}

void CMFCRibbonBar::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND)
	{
		if (m_pPressed != NULL)
		{
			ASSERT_VALID(m_pPressed);

			CPoint point;

			::GetCursorPos(&point);
			ScreenToClient(&point);

			if (m_pPressed->GetRect().PtInRect(point))
			{
				if (!m_pPressed->OnAutoRepeat())
				{
					KillTimer(AFX_TIMER_ID_RIBBONBAR_AUTO_COMMAND);
				}
			}
		}
	}

	if (nIDEvent == AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS)
	{
		SetKeyboardNavigationLevel(NULL, FALSE);
		KillTimer(AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS);
	}

	CPane::OnTimer(nIDEvent);
}

void CMFCRibbonBar::SetPrintPreviewMode(BOOL bSet)
{
	ASSERT_VALID(this);

	if (!m_bIsPrintPreview)
	{
		return;
	}

	m_bPrintPreviewMode = bSet;

	if (bSet)
	{
		ASSERT_VALID(m_pPrintPreviewCategory);

		OnSetPrintPreviewKeys(m_pPrintPreviewCategory->GetPanel(0), m_pPrintPreviewCategory->GetPanel(1), m_pPrintPreviewCategory->GetPanel(2));

		m_arVisibleCategoriesSaved.RemoveAll();

		for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
		{
			CMFCRibbonCategory* pCategory = m_arCategories [i];
			ASSERT_VALID(pCategory);

			if (pCategory->IsVisible())
			{
				m_arVisibleCategoriesSaved.Add(i);
				pCategory->m_bIsVisible = FALSE;
			}
		}

		m_pPrintPreviewCategory->m_bIsVisible = TRUE;

		if (m_pActiveCategory != NULL)
		{
			m_pActiveCategory->SetActive(FALSE);
		}

		m_pActiveCategorySaved = m_pActiveCategory;
		m_pActiveCategory = m_pPrintPreviewCategory;

		m_pActiveCategory->SetActive();
	}
	else
	{
		for (int i = 0; i < (int)m_arVisibleCategoriesSaved.GetSize(); i++)
		{
			ShowCategory(m_arVisibleCategoriesSaved [i]);
		}

		m_arVisibleCategoriesSaved.RemoveAll();

		m_pPrintPreviewCategory->m_bIsVisible = FALSE;

		m_pActiveCategory = m_pActiveCategorySaved;

		if (m_pActiveCategory != NULL)
		{
			m_pActiveCategory->SetActive();
		}
	}

	RecalcLayout();
	RedrawWindow();
}

void CMFCRibbonBar::EnablePrintPreview(BOOL bEnable)
{
	ASSERT_VALID(this);
	m_bIsPrintPreview = bEnable;

	if (!bEnable && m_pPrintPreviewCategory != NULL)
	{
		ASSERT_VALID(m_pPrintPreviewCategory);

		RemoveCategory(GetCategoryIndex(m_pPrintPreviewCategory));
		m_pPrintPreviewCategory = NULL;
	}
}

static CString __stdcall LoadCommandLabel(UINT uiCommdnID)
{
	TCHAR szFullText [256];
	CString strText;

	if (AfxLoadString(uiCommdnID, szFullText))
	{
		AfxExtractSubString(strText, szFullText, 1, '\n');
	}

	strText.Remove(_T('&'));
	return strText;
}

CMFCRibbonCategory* CMFCRibbonBar::AddPrintPreviewCategory()
{
	ASSERT_VALID(this);

	if (!m_bIsPrintPreview)
	{
		return NULL;
	}

	ENSURE(m_pPrintPreviewCategory == NULL);

	const int nTwoPagesImageSmall = 1;
	const int nNextPageImageSmall = 2;
	const int nPrevPageImageSmall = 3;
	const int nPrintImageSmall = 4;
	const int nCloseImageSmall = 5;
	const int nZoomInImageSmall = 6;
	const int nZoomOutImageSmall = 7;

	const int nPrintImageLarge = 0;
	const int nZoomInImageLarge = 1;
	const int nZoomOutImageLarge = 2;
	const int nCloseImagLarge = 3;
	const int nOnePageImageLarge = 4;

	CString strLabel;
	ENSURE(strLabel.LoadString(IDS_AFXBARRES_PRINT_PREVIEW));

	m_pPrintPreviewCategory = new CMFCRibbonCategory(this, strLabel, IDB_AFXBARRES_RIBBON_PRINT_SMALL, IDB_AFXBARRES_RIBBON_PRINT_LARGE);

	m_pPrintPreviewCategory->m_bIsVisible = FALSE;

	ENSURE(strLabel.LoadString(IDS_AFXBARRES_PRINT));

	CMFCRibbonPanel* pPrintPanel = m_pPrintPreviewCategory->AddPanel(strLabel, m_pPrintPreviewCategory->GetSmallImages().ExtractIcon(nPrintImageSmall));
	ASSERT_VALID(pPrintPanel);

	pPrintPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_PRINT, LoadCommandLabel(AFX_ID_PREVIEW_PRINT), nPrintImageSmall, nPrintImageLarge));

	ENSURE(strLabel.LoadString(IDS_AFXBARRES_ZOOM));

	CMFCRibbonPanel* pZoomPanel = m_pPrintPreviewCategory->AddPanel(strLabel, m_pPrintPreviewCategory->GetSmallImages().ExtractIcon(nZoomInImageSmall));
	ASSERT_VALID(pZoomPanel);

	pZoomPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_ZOOMIN, LoadCommandLabel(AFX_ID_PREVIEW_ZOOMIN), nZoomInImageSmall, nZoomInImageLarge));
	pZoomPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_ZOOMOUT, LoadCommandLabel(AFX_ID_PREVIEW_ZOOMOUT), nZoomOutImageSmall, nZoomOutImageLarge));

	CString str1;
	ENSURE(str1.LoadString(AFX_IDS_ONEPAGE));

	CString str2;
	ENSURE(str2.LoadString(AFX_IDS_TWOPAGE));

	CString strPages = str1.GetLength() > str2.GetLength() ? str1 : str2;

	pZoomPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_NUMPAGE, strPages, nTwoPagesImageSmall, nOnePageImageLarge));

	ENSURE(strLabel.LoadString(IDS_AFXBARRES_PREVIEW));

	CMFCRibbonPanel* pPreviewPanel = m_pPrintPreviewCategory->AddPanel(strLabel, m_pPrintPreviewCategory->GetSmallImages().ExtractIcon(nCloseImageSmall));
	ASSERT_VALID(pPreviewPanel);

	pPreviewPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_NEXT, LoadCommandLabel(AFX_ID_PREVIEW_NEXT), nNextPageImageSmall, -1));
	pPreviewPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_PREV, LoadCommandLabel(AFX_ID_PREVIEW_PREV), nPrevPageImageSmall, -1));
	pPreviewPanel->Add(new CMFCRibbonSeparator);
	pPreviewPanel->Add(new CMFCRibbonButton(AFX_ID_PREVIEW_CLOSE, LoadCommandLabel(AFX_ID_PREVIEW_CLOSE), nCloseImageSmall, nCloseImagLarge));

	m_arCategories.Add(m_pPrintPreviewCategory);
	return m_pPrintPreviewCategory;
}

void CMFCRibbonBar::OnSetPrintPreviewKeys(CMFCRibbonPanel* pPrintPanel, CMFCRibbonPanel* pZoomPanel, CMFCRibbonPanel* pPreviewPanel)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pPrintPanel);
	ASSERT_VALID(pZoomPanel);
	ASSERT_VALID(pPreviewPanel);

	pPrintPanel->SetKeys(_T("zp"));
	pZoomPanel->SetKeys(_T("zz"));
	pPreviewPanel->SetKeys(_T("zv"));

	SetElementKeys(AFX_ID_PREVIEW_NEXT, _T("x"));
	SetElementKeys(AFX_ID_PREVIEW_PREV, _T("v"));
	SetElementKeys(AFX_ID_PREVIEW_CLOSE, _T("c"));
	SetElementKeys(AFX_ID_PREVIEW_ZOOMIN, _T("qi"));
	SetElementKeys(AFX_ID_PREVIEW_ZOOMOUT, _T("qo"));
	SetElementKeys(AFX_ID_PREVIEW_PRINT, _T("p"));
	SetElementKeys(AFX_ID_PREVIEW_NUMPAGE, _T("1"));
}

CMFCRibbonContextCaption* CMFCRibbonBar::FindContextCaption(UINT uiID) const
{
	ASSERT_VALID(this);
	ASSERT(uiID != 0);

	for (int i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		ASSERT_VALID(m_arContextCaptions [i]);

		if (m_arContextCaptions [i]->m_uiID == uiID)
		{
			return m_arContextCaptions [i];
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBar::GetDroppedDown()
{
	ASSERT_VALID(this);

	// Check for the main button:
	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		if (m_pMainButton->GetDroppedDown() != NULL)
		{
			return m_pMainButton;
		}
	}

	// Check for quick access toolbar:
	CMFCRibbonBaseElement* pQAElem = m_QAToolbar.GetDroppedDown();
	if (pQAElem != NULL)
	{
		ASSERT_VALID(pQAElem);
		return pQAElem;
	}

	// Check for tab elements:
	CMFCRibbonBaseElement* pTabElem = m_TabElements.GetDroppedDown();
	if (pTabElem != NULL)
	{
		ASSERT_VALID(pTabElem);
		return pTabElem;
	}

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);

		if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS)
		{
			if (m_pActiveCategory->m_Tab.GetDroppedDown() != NULL)
			{
				ASSERT_VALID(m_pActiveCategory->m_Tab.GetDroppedDown());
				return m_pActiveCategory->m_Tab.GetDroppedDown();
			}
		}

		return m_pActiveCategory->GetDroppedDown();
	}

	return NULL;
}

void CMFCRibbonBar::OnSysColorChange()
{
	CPane::OnSysColorChange();

	GetGlobalData()->UpdateSysColors();

	CMFCVisualManager::GetInstance()->OnUpdateSystemColors();
	RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
}

BOOL CMFCRibbonBar::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

LRESULT CMFCRibbonBar::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (!m_bIsTransparentCaption)
	{
		return CPane::WindowProc(message, wParam, lParam);
	}

	if (message == WM_NCHITTEST)
	{
		LRESULT lResult = 0;
		_AfxDwmDefWindowProc(GetParent()->GetSafeHwnd(), message, wParam, lParam, &lResult);

		if (lResult == HTCLOSE || lResult == HTMINBUTTON || lResult == HTMAXBUTTON)
		{
			return HTTRANSPARENT;
		}

		if (!GetParent()->IsZoomed())
		{
			CPoint point(LOWORD(lParam), HIWORD(lParam));

			CRect rectResizeTop = m_rectCaption;
			rectResizeTop.right = m_rectSysButtons.left - 1;
			rectResizeTop.bottom = rectResizeTop.top + GetSystemMetrics(SM_CYSIZEFRAME) / 2;

			ClientToScreen(&rectResizeTop);

			if (rectResizeTop.PtInRect(point))
			{
				return HTTOP;
			}
		}
	}

	return CPane::WindowProc(message, wParam, lParam);
}

void CMFCRibbonBar::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (m_bIsTransparentCaption)
	{
		if (nID == SC_MAXIMIZE && GetParent()->IsZoomed())
		{
			nID = SC_RESTORE;
		}

		GetParent()->SendMessage(WM_SYSCOMMAND, (WPARAM) nID, lParam);
	}
	else
	{
		CPane::OnSysCommand(nID, lParam);
	}
}

BOOL CMFCRibbonBar::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (m_bIsTransparentCaption && !GetParent()->IsZoomed())
	{
		CRect rectResizeTop = m_rectCaption;
		rectResizeTop.right = m_rectSysButtons.left - 1;
		rectResizeTop.bottom = rectResizeTop.top + GetSystemMetrics(SM_CYSIZEFRAME) / 2;

		ClientToScreen(&rectResizeTop);

		CPoint point;
		GetCursorPos(&point);

		if (rectResizeTop.PtInRect(point))
		{
			SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZENS));
			return TRUE;
		}
	}

	return CPane::OnSetCursor(pWnd, nHitTest, message);
}

void CMFCRibbonBar::DWMCompositionChanged()
{
	if (!m_bReplaceFrameCaption)
	{
		return;
	}

	DWORD dwStyle = WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZE;

	if (GetGlobalData()->IsDwmCompositionEnabled())
	{
		ModifyStyle(0, dwStyle, SWP_FRAMECHANGED);
		GetParent()->ModifyStyle(0, WS_CAPTION);
		GetParent()->SetWindowRgn(NULL, TRUE);
	}
	else
	{
		ModifyStyle(dwStyle, 0, SWP_FRAMECHANGED);
		GetParent()->ModifyStyle(WS_CAPTION, 0);
	}

	GetParent()->SetWindowPos(NULL, -1, -1, -1, -1, SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_FRAMECHANGED);

	m_bForceRedraw = TRUE;
	RecalcLayout();
}

void CMFCRibbonBar::UpdateToolTipsRect()
{
	if (m_pToolTip->GetSafeHwnd() != NULL)
	{
		CRect rectToolTipClient;
		GetClientRect(rectToolTipClient);

		CRect rectToolTipCaption(0, 0, 0, 0);

		if (m_bIsTransparentCaption)
		{
			rectToolTipClient.top = m_rectCaption.bottom + 1;
			rectToolTipCaption = m_rectCaption;
			rectToolTipCaption.right = m_rectSysButtons.left - 1;
		}

		m_pToolTip->SetToolRect(this, nIdToolTipClient, rectToolTipClient);
		m_pToolTip->SetToolRect(this, nIdToolTipCaption, rectToolTipCaption);
	}
}

void CMFCRibbonBar::OnEditContextMenu(CMFCRibbonRichEditCtrl* pEdit, CPoint point)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pEdit);

	if (afxContextMenuManager == NULL)
	{
		return;
	}

	CString strItem;
	TCHAR szFullText [256];

	CMenu menu;
	menu.CreatePopupMenu();

	AfxLoadString(ID_EDIT_CUT, szFullText);
	AfxExtractSubString(strItem, szFullText, 1, '\n');
	menu.AppendMenu(MF_STRING, idCut, strItem);

	AfxLoadString(ID_EDIT_COPY, szFullText);
	AfxExtractSubString(strItem, szFullText, 1, '\n');
	menu.AppendMenu(MF_STRING, idCopy, strItem);

	AfxLoadString(ID_EDIT_PASTE, szFullText);
	AfxExtractSubString(strItem, szFullText, 1, '\n');
	menu.AppendMenu(MF_STRING, idPaste, strItem);

	menu.AppendMenu(MF_SEPARATOR);

	AfxLoadString(ID_EDIT_SELECT_ALL, szFullText);
	AfxExtractSubString(strItem, szFullText, 1, '\n');
	menu.AppendMenu(MF_STRING, idSelectAll, strItem);

	if (!::IsClipboardFormatAvailable(AFX_TCF_TEXT))
	{
		menu.EnableMenuItem(idPaste, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	long nStart, nEnd;
	pEdit->GetSel(nStart, nEnd);

	if (nEnd <= nStart)
	{
		menu.EnableMenuItem(idCopy, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		menu.EnableMenuItem(idCut, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	if (pEdit->GetWindowTextLength() == 0)
	{
		menu.EnableMenuItem(idSelectAll, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	int nMenuResult = afxContextMenuManager->TrackPopupMenu(menu, point.x, point.y, pEdit);

	switch (nMenuResult)
	{
	case idCut:
		pEdit->Cut();
		break;

	case idCopy:
		pEdit->Copy();
		break;

	case idPaste:
		pEdit->Paste();
		break;

	case idSelectAll:
		pEdit->SetSel(0, -1);
		break;
	}
}

void CMFCRibbonBar::EnableToolTips(BOOL bEnable, BOOL bEnableDescr)
{
	ASSERT_VALID(this);

	m_bToolTip = bEnable;
	m_bToolTipDescr = bEnableDescr;
}

void CMFCRibbonBar::SetTooltipFixedWidth(int nWidthRegular, int nWidthLargeImage)	// 0 - set variable size
{
	ASSERT_VALID(this);

	m_nTooltipWidthRegular = nWidthRegular;
	m_nTooltipWidthLargeImage = nWidthLargeImage;
}

void CMFCRibbonBar::EnableKeyTips(BOOL bEnable)
{
	ASSERT_VALID(this);

	m_bKeyTips = bEnable;
}

void CMFCRibbonBar::GetItemIDsList(CList<UINT,UINT>& lstItems, BOOL bHiddenOnly/* = FALSE*/) const
{
	ASSERT_VALID(this);

	lstItems.RemoveAll();

	if (m_pMainCategory != NULL)
	{
		ASSERT_VALID(m_pMainCategory);

		m_pMainCategory->GetItemIDsList(lstItems, FALSE);
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		pCategory->GetItemIDsList(lstItems, bHiddenOnly);
	}

	if (!bHiddenOnly)
	{
		m_QAToolbar.GetItemIDsList(lstItems);
		m_TabElements.GetItemIDsList(lstItems);
	}
}

void CMFCRibbonBar::ToggleMimimizeState()
{
	ASSERT_VALID(this);

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);

		const BOOL bIsHidden = m_dwHideFlags == AFX_RIBBONBAR_HIDE_ELEMENTS;

		m_pActiveCategory->ShowElements(bIsHidden);
		RedrawWindow();
	}
}

void CMFCRibbonBar::OnSetFocus(CWnd* pOldWnd)
{
	CPane::OnSetFocus(pOldWnd);

	if (m_nKeyboardNavLevel < 0 && !m_bDontSetKeyTips)
	{
		SetKeyboardNavigationLevel(NULL, FALSE);
	}

	m_bDontSetKeyTips = FALSE;
}

void CMFCRibbonBar::OnKillFocus(CWnd* pNewWnd)
{
	CPane::OnKillFocus(pNewWnd);

	if (m_nKeyboardNavLevel >= 0)
	{
		m_nKeyboardNavLevel = -1;
		m_pKeyboardNavLevelParent = NULL;
		m_pKeyboardNavLevelCurrent = NULL;
		m_nCurrKeyChar = 0;

		RemoveAllKeys();
		RedrawWindow();
	}

	if (!IsChild(pNewWnd))
	{
		CMFCRibbonBaseElement* pFocused = GetFocused();
		if (pFocused != NULL && !pFocused->IsDroppedDown())
		{
			pFocused->m_bIsFocused = FALSE;
			pFocused->OnSetFocus(FALSE);
			pFocused->Redraw();
		}
	}
}

BOOL CMFCRibbonBar::TranslateChar(UINT nChar)
{
	if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL)
	{
		return FALSE;
	}

	if (!CKeyboardManager::IsKeyPrintable(nChar))
	{
		return FALSE;
	}

	if (m_nKeyboardNavLevel < 0)
	{
		SetKeyboardNavigationLevel(NULL, FALSE);
	}

	if (!ProcessKey(nChar))
	{
		DeactivateKeyboardFocus(FALSE);
		return FALSE;
	}

	return TRUE;
}

void CMFCRibbonBar::DeactivateKeyboardFocus(BOOL bSetFocus)
{
	RemoveAllKeys();
	m_nCurrKeyChar = 0;

	CMFCRibbonBaseElement* pFocused = GetFocused();
	if (pFocused != NULL)
	{
		pFocused->m_bIsFocused = FALSE;
		pFocused->OnSetFocus(FALSE);
		pFocused->Redraw();
	}

	if (m_nKeyboardNavLevel < 0)
	{
		return;
	}

	m_nKeyboardNavLevel = -1;
	m_pKeyboardNavLevelParent = NULL;
	m_pKeyboardNavLevelCurrent = NULL;

	CFrameWnd* pParentFrame = GetParentFrame();
	ASSERT_VALID(pParentFrame);

	if (bSetFocus)
	{
		pParentFrame->SetFocus();
	}

	RedrawWindow();
}

void CMFCRibbonBar::SetKeyboardNavigationLevel(CObject* pLevel, BOOL bSetFocus)
{
	if (!m_bKeyTips)
	{
		return;
	}

	if (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL)
	{
		return;
	}

	if (bSetFocus)
	{
		SetFocus();
	}

	int i = 0;

	RemoveAllKeys();
	m_nCurrKeyChar = 0;

	m_pKeyboardNavLevelParent = NULL;
	m_pKeyboardNavLevelCurrent = pLevel;

	CFrameWnd* pParentFrame = GetParentFrame();
	ASSERT_VALID(pParentFrame);

	CWnd* pFocus = GetFocus();

	BOOL bActive = (pFocus->GetSafeHwnd() != NULL &&
		(pParentFrame->IsChild(pFocus) || pFocus->GetSafeHwnd() == pParentFrame->GetSafeHwnd()));

	if (!bActive)
	{
		return;
	}

	if (pLevel == NULL)
	{
		m_nKeyboardNavLevel = 0;

		if (m_pMainButton != NULL)
		{
			m_arKeyElements.Add(new CMFCRibbonKeyTip(m_pMainButton));
		}

		for (i = 0; i < (int)m_arCategories.GetSize(); i++)
		{
			CMFCRibbonCategory* pCategory = m_arCategories [i];
			ASSERT_VALID(pCategory);

			if (pCategory->IsVisible())
			{
				m_arKeyElements.Add(new CMFCRibbonKeyTip(&pCategory->m_Tab));
			}
		}

		m_QAToolbar.AddToKeyList(m_arKeyElements);
		m_TabElements.AddToKeyList(m_arKeyElements);

		if (m_pActiveCategory != NULL && (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) == 0)
		{
			m_pActiveCategory->m_Tab.m_bIsFocused = TRUE;
		}
		else if (m_pMainButton != NULL)
		{
			m_pMainButton->m_bIsFocused = TRUE;
		}
	}
	else
	{
		CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> arElems;

		CMFCRibbonCategory* pCategory = DYNAMIC_DOWNCAST(CMFCRibbonCategory, pLevel);
		CMFCRibbonPanel* pPanel = DYNAMIC_DOWNCAST(CMFCRibbonPanel, pLevel);

		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);

			if (m_dwHideFlags == 0 || pCategory->GetParentMenuBar() != NULL)
			{
				pCategory->GetElements(arElems);
			}
		}
		else if (pPanel != NULL)
		{
			ASSERT_VALID(pPanel);

			pPanel->GetElements(arElems);

			if (!pPanel->IsMainPanel())
			{
				CMFCRibbonCategory* pParentCategory = NULL;

				if (pPanel->GetParentButton() == NULL || !pPanel->GetParentButton()->IsQATMode())
				{
					pParentCategory = pPanel->GetParentCategory();
				}

				if (pPanel->GetParentMenuBar() != NULL)
				{
					CMFCPopupMenu* pPopupMenu = DYNAMIC_DOWNCAST(CMFCPopupMenu, pPanel->GetParentMenuBar()->GetParent());
					ASSERT_VALID(pPopupMenu);

					CMFCRibbonPanelMenu* pParentMenu = DYNAMIC_DOWNCAST(CMFCRibbonPanelMenu, pPopupMenu->GetParentPopupMenu());

					if (pParentMenu != NULL)
					{
						m_pKeyboardNavLevelParent = pParentMenu->GetPanel();

						if (m_pKeyboardNavLevelParent == NULL)
						{
							pParentCategory = pParentMenu->GetCategory();
						}
					}
					else
					{
						CMFCRibbonBaseElement* pParentElement = pPopupMenu->GetParentRibbonElement();
						if (pParentElement != NULL)
						{
							pParentCategory = pParentElement->GetParentCategory();
						}
					}
				}

				if (pParentCategory != NULL && !pParentCategory->GetRect().IsRectEmpty())
				{
					m_pKeyboardNavLevelParent = pParentCategory;
				}
			}
		}

		for (i = 0; i < (int)arElems.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pElem = arElems [i];
			ASSERT_VALID(pElem);

			pElem->AddToKeyList(m_arKeyElements);
		}

		m_nKeyboardNavLevel = 1;
	}

	ShowKeyTips();
	RedrawWindow();
}

LPDISPATCH CMFCRibbonBar::GetAccessibleDispatch()
{
	if (m_pStdObject != NULL)
	{
		m_pStdObject->AddRef();
		return m_pStdObject;
	}

	return NULL;
}

CMFCBaseAccessibleObject* CMFCRibbonBar::AccessibleObjectByIndex(long lVal)
{
	if (lVal <= 0)
	{
		return NULL;
	}

	int nMainButtonIndex = 0;
	if (m_pMainButton != NULL && m_pMainButton->IsVisible ())
	{
		nMainButtonIndex = 1;
	}

	int nQatIndex = 0;

	if (m_QAToolbar.IsVisible())
	{
		nQatIndex = nMainButtonIndex + 1;
	}

	int nTabsIndex = nQatIndex > 0 ? nQatIndex + 1 : nMainButtonIndex + 1;
	int nContextTabsIndex = nTabsIndex + 1;
	int nContextCountMax = nContextTabsIndex + GetVisibleContextCaptionCount();
	int nRealActiveCategoryIndex = nContextCountMax;

	if (lVal == nMainButtonIndex)
	{
		return m_pMainButton;
	}

	if (lVal == nQatIndex)
	{
		return &m_QAToolbar;
	}

	if (lVal == nTabsIndex)
	{
		return &m_Tabs;
	}

	if ((nContextTabsIndex <= lVal) && (lVal < nContextCountMax))
	{
		int nIndex = lVal - nContextTabsIndex;

		CArray<int, int> arCaptions;
		GetVisibleContextCaptions(&arCaptions);

		if (nIndex < 0 || nIndex >= (int)arCaptions.GetSize())
		{
			return NULL;
		}

		UINT nContextID = arCaptions[nIndex];

		CMFCRibbonContextCaption* pCaption = FindContextCaption(nContextID);
		if (pCaption != NULL)
		{
			return pCaption;
		}
	}

	BOOL bHideCategory = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS);
	if (bHideCategory)
	{
		nRealActiveCategoryIndex--;
	}

	// Active Category:
	if (m_pActiveCategory != NULL && m_pActiveCategory->IsVisible() && !bHideCategory && lVal == nRealActiveCategoryIndex)
	{
		return m_pActiveCategory;
	}

	// TabElement
	if (lVal > nRealActiveCategoryIndex && (lVal <= (nRealActiveCategoryIndex + m_TabElements.GetCount())))
	{
		int nIndex = lVal - nRealActiveCategoryIndex -1;

		CMFCRibbonBaseElement* pTabElement = m_TabElements.GetButton(nIndex);
		return pTabElement == NULL ? NULL : pTabElement;
	}

	int nMinimizeButtonIndex = nRealActiveCategoryIndex + m_TabElements.GetCount() + 1;
	int nMaximizeButtonIndex = nMinimizeButtonIndex + 1;
	int nCloseButtonIndex = nMaximizeButtonIndex + 1;

	if (IsCaptionButtons())
	{
		if (lVal == nMinimizeButtonIndex)
		{
			return &m_CaptionButtons[0];
		}

		if (lVal == nMaximizeButtonIndex)
		{
			return &m_CaptionButtons[1];
		}

		if (lVal == nCloseButtonIndex)
		{
			return &m_CaptionButtons[2];
		}
	}
	return NULL;
}

CMFCBaseAccessibleObject* CMFCRibbonBar::AccessibleObjectFromPoint(CPoint point)
{
	CRect rectQAT = m_QAToolbar.GetRect();
	if (rectQAT.PtInRect(point))
	{
		return &m_QAToolbar;
	}

	// Maybe MainButton
	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		if (m_pMainButton->GetRect().PtInRect(point))
		{
			return m_pMainButton;
		}
	}

	// Tabs
	CRect rectTabs = m_Tabs.GetRect();
	if (rectTabs.PtInRect(point))
	{
		return &m_Tabs;
	}

	 // Context Caption
	int i = 0;

	for (i = 0; i < (int)m_arContextCaptions.GetSize(); i++)
	{
		CMFCRibbonContextCaption* pCaption = m_arContextCaptions[i];
		if (pCaption != NULL)
		{
			ASSERT_VALID (pCaption);

			if (pCaption->GetRect().PtInRect(point))
			{
				return pCaption;
			}
		}
	}

	BOOL bHideCategory = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS);

	// Active Category
	if (m_pActiveCategory != NULL && m_pActiveCategory->IsVisible() && !bHideCategory)
	{
		if (m_pActiveCategory->GetRect().PtInRect(point))
		{
			return m_pActiveCategory;
		}
	}

	// Maybe TabElement on Tabs right
	for (i = 0; i < m_TabElements.GetCount(); i++)
	{
		CMFCRibbonBaseElement* pTabElement = m_TabElements.GetButton(i);
		if (pTabElement != NULL)
		{
			ASSERT_VALID(pTabElement);

			if (pTabElement->GetRect().PtInRect(point))
			{
				return pTabElement;
			}
		}
	}

	if (IsCaptionButtons())
	{
		// Caption button
		for (i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
		{
			if (m_CaptionButtons[i].GetRect().PtInRect(point))
			{
				return &m_CaptionButtons[i];
			}
		}
	}

	return NULL;
}

int CMFCRibbonBar::GetAccObjectCount()
{
	if ((m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) || !IsVisible())
	{
		return 0;
	}

	int count = 1;
	if (m_pMainButton != NULL && m_pMainButton->IsVisible())
	{
		count++;
	}

	if (m_QAToolbar.IsVisible())
	{
		count++;
	}

	BOOL bHideCategory = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS);

	if (m_pActiveCategory != NULL && m_pActiveCategory->IsVisible() && !bHideCategory)
	{
		count++;
	}

	count += m_TabElements.GetCount();
	count += GetVisibleContextCaptionCount();

	return count;
}

BOOL CMFCRibbonBar::OnSetAccData(long lVal)
{
	ASSERT_VALID(this);

	m_AccData.Clear ();

	if (m_bSingleLevelAccessibilityMode)
	{
		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		GetVisibleElements(arButtons);

		int nIndex = (int)lVal - 1;

		if (nIndex < 0 || nIndex >= (int)arButtons.GetSize())
		{
			return FALSE;
		}

		ASSERT_VALID(arButtons[nIndex]);
		return arButtons[nIndex]->SetACCData(this, m_AccData);
	}
	else
	{
		CMFCBaseAccessibleObject* pAccObject = AccessibleObjectByIndex(lVal);
		if (pAccObject != NULL)
		{
			ASSERT_VALID(pAccObject);

			pAccObject->SetACCData(this, m_AccData);
			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CMFCRibbonBar::accHitTest(long xLeft, long yTop, VARIANT *pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	pvarChild->vt = VT_I4;
	pvarChild->lVal = CHILDID_SELF;

	CPoint pt (xLeft, yTop);
	ScreenToClient (&pt);

	if (m_bSingleLevelAccessibilityMode)
	{
		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		GetVisibleElements(arButtons);

		for (int i = 0; i < (int)arButtons.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pElem = arButtons[i];
			ASSERT_VALID(pElem);

			CRect rectElem = pElem->GetRect();
			if (rectElem.PtInRect(pt))
			{
				pvarChild->lVal = i + 1;
				pElem->SetACCData(this, m_AccData);
				break;
			}
		}
	}
	else
	{
		CMFCBaseAccessibleObject* pAccObject = AccessibleObjectFromPoint(pt);
		if (pAccObject != NULL)
		{
			ASSERT_VALID(pAccObject);

			pAccObject->SetACCData(this, m_AccData);
			pvarChild->vt = VT_DISPATCH;
			pvarChild->pdispVal = pAccObject->GetIDispatch(TRUE);
		}
	}

	return S_OK;
}

HRESULT CMFCRibbonBar::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	if (m_bSingleLevelAccessibilityMode)
	{
		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		GetVisibleElements(arButtons);

		*pcountChildren = (int)arButtons.GetSize();
	}
	else
	{
		*pcountChildren = GetAccObjectCount();
	}


	return S_OK;
}

HRESULT CMFCRibbonBar::get_accChild(VARIANT varChild, IDispatch **ppdispChild)
{
	if (!ppdispChild)
	{
		return E_INVALIDARG;
	}

	*ppdispChild = NULL;

	if (varChild.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (!m_bSingleLevelAccessibilityMode)
	{
		CMFCBaseAccessibleObject* pAccObject = AccessibleObjectByIndex(varChild.lVal);
		if (pAccObject != NULL)
		{
			ASSERT_VALID(pAccObject);
			*ppdispChild = pAccObject->GetIDispatch(TRUE);
		}
	}

	return (*ppdispChild != NULL) ? S_OK : S_FALSE;
}

HRESULT CMFCRibbonBar::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (m_bSingleLevelAccessibilityMode)
	{
		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		GetVisibleElements(arButtons);

		switch (navDir)
		{
		case NAVDIR_FIRSTCHILD:
			if (varStart.lVal == CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = 1;
				return S_OK;
			}
			break;

		case NAVDIR_LASTCHILD:
			if (varStart.lVal == CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = (int)arButtons.GetSize();
				return S_OK;
			}
			break;

		case NAVDIR_NEXT:
		case NAVDIR_RIGHT:
			if (varStart.lVal != CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = varStart.lVal + 1;
				if (pvarEndUpAt->lVal > (int)arButtons.GetSize())
				{
					pvarEndUpAt->vt = VT_EMPTY;
					return S_FALSE;
				}
				return S_OK;
			}
			break;

		case NAVDIR_PREVIOUS:
		case NAVDIR_LEFT:
			if (varStart.lVal != CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = varStart.lVal - 1;
				if (pvarEndUpAt->lVal <= 0)
				{
					pvarEndUpAt->vt = VT_EMPTY;
					return S_FALSE;
				}
				return S_OK;
			}
			break;
		}

		return S_FALSE;
	}
	else
	{
		switch (navDir)
		{
		case NAVDIR_FIRSTCHILD:
			if (varStart.lVal == CHILDID_SELF)

			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = 1;
				return S_OK;
			}
			break;

		case NAVDIR_LASTCHILD:
			if (varStart.lVal == CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = GetAccObjectCount();
				return S_OK;
			}
			break;

		case NAVDIR_NEXT:
		case NAVDIR_RIGHT:
			if (varStart.lVal != CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = varStart.lVal + 1;

				if (pvarEndUpAt->lVal > GetAccObjectCount())
				{
					pvarEndUpAt->vt = VT_EMPTY;
					return S_FALSE;
				}

				return S_OK;
			}
			break;

		case NAVDIR_PREVIOUS:
		case NAVDIR_LEFT:
			if (varStart.lVal != CHILDID_SELF)
			{
				pvarEndUpAt->vt = VT_I4;
				pvarEndUpAt->lVal = varStart.lVal - 1;

				if (pvarEndUpAt->lVal <= 0)
				{
					pvarEndUpAt->vt = VT_EMPTY;
					return S_FALSE;
				}

				return S_OK;
			}
			break;
		}

		return S_FALSE;
	}
}

HRESULT CMFCRibbonBar::accDoDefaultAction(VARIANT varChild)
{
	if (varChild.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (m_bSingleLevelAccessibilityMode)
	{
		if (varChild.lVal != CHILDID_SELF)
		{
			CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
			GetVisibleElements(arButtons);

			int nIndex = (int)varChild.lVal - 1;
			if (nIndex < 0 || nIndex >= (int)arButtons.GetSize())
			{
				return E_INVALIDARG;
			}

			CMFCRibbonBaseElement* pElem = arButtons[nIndex];
			if (pElem != NULL)
			{
				ASSERT_VALID (pElem);

				pElem->OnAccDefaultAction();
				return S_OK;
			}

		}
		return S_FALSE;
	}

	return S_FALSE;
}

HRESULT CMFCRibbonBar::accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild)
{
	if (m_bSingleLevelAccessibilityMode)
	{
		return __super::accLocation(pxLeft, pyTop, pcxWidth, pcyHeight, varChild);
	}

	if (!pxLeft || !pyTop || !pcxWidth || !pcyHeight)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CRect rc;
		GetWindowRect (rc);

		*pxLeft = rc.left;
		*pyTop = rc.top;
		*pcxWidth = rc.Width();
		*pcyHeight = rc.Height();

		return S_OK;
	}

	if (varChild.vt == VT_I4)
	{
		OnSetAccData(varChild.lVal);

		*pxLeft = m_AccData.m_rectAccLocation.left;
		*pyTop = m_AccData.m_rectAccLocation.top;
		*pcxWidth = m_AccData.m_rectAccLocation.Width();
		*pcyHeight = m_AccData.m_rectAccLocation.Height();
	}

	return S_OK;
}

void CMFCRibbonBar::OnBeforeProcessKey(int& nChar)
{
	nChar = CKeyboardManager::TranslateCharToUpper(nChar);
}

BOOL CMFCRibbonBar::ProcessKey(int nChar)
{
	OnBeforeProcessKey(nChar);

	CMFCRibbonBaseElement* pKeyElem = NULL;

	BOOL bIsMenuKey = FALSE;

	for (int i = 0; i < (int)m_arKeyElements.GetSize() && pKeyElem == NULL; i++)
	{
		CMFCRibbonKeyTip* pKey = m_arKeyElements [i];
		ASSERT_VALID(pKey);

		CMFCRibbonBaseElement* pElem = pKey->GetElement();
		ASSERT_VALID(pElem);

		CString strKeys = pKey->IsMenuKey() ? pElem->GetMenuKeys() : pElem->GetKeys();
		strKeys.MakeUpper();

		if (strKeys.IsEmpty())
		{
			continue;
		}

		if (m_nCurrKeyChar != 0)
		{
			if (strKeys.GetLength() > 1 && strKeys [0] == m_nCurrKeyChar && strKeys [1] == nChar)
			{
				pKeyElem = pElem;
				bIsMenuKey = pKey->IsMenuKey();
				break;
			}
		}
		else if (strKeys [0] == nChar)
		{
			if (strKeys.GetLength() > 1)
			{
				m_nCurrKeyChar = strKeys [0];
				ShowKeyTips();
				return TRUE;
			}
			else
			{
				pKeyElem = pElem;
				bIsMenuKey = pKey->IsMenuKey();
				break;
			}
		}
	}

	if (pKeyElem == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pKeyElem);

	if (::GetFocus() != GetSafeHwnd())
	{
		SetFocus();
	}

	CMFCDisableMenuAnimation disableMenuAnimation;
	HWND hwndThis = GetSafeHwnd();

	if (pKeyElem->OnKey(bIsMenuKey) && ::IsWindow(hwndThis))
	{
		DeactivateKeyboardFocus();
	}

	return TRUE;
}

void CMFCRibbonBar::RemoveAllKeys()
{
	// protect against recursive calls by copying the key array, emptying the
	// original key array and then deleting the elements from the copied array.
	int nSize = (int)m_arKeyElements.GetSize();
	if (nSize == 0)
	{
		return;
	}

	CArray<CMFCRibbonKeyTip*,CMFCRibbonKeyTip*> arKeyElements;

	for (int i = 0; i < nSize; i++)
	{
		arKeyElements.Add(m_arKeyElements[i]);
	}

	m_arKeyElements.RemoveAll();

	for (int i = 0; i < nSize; i++)
	{
		CMFCRibbonKeyTip* pKeyTip = arKeyElements [i];
		ASSERT_VALID(pKeyTip);

		if (pKeyTip->GetSafeHwnd() != NULL)
		{
			pKeyTip->DestroyWindow();
		}

		delete pKeyTip;
	}
}

void CMFCRibbonBar::ShowKeyTips(BOOL bRepos)
{
	for (int i = 0; i < (int)m_arKeyElements.GetSize(); i++)
	{
		CMFCRibbonKeyTip* pKeyTip = m_arKeyElements [i];
		ASSERT_VALID(pKeyTip);

		CMFCRibbonBaseElement* pElem = pKeyTip->GetElement();
		ASSERT_VALID(pElem);

		if (m_nCurrKeyChar != 0)
		{
			CString strKeys = pKeyTip->IsMenuKey() ? pElem->GetMenuKeys() : pElem->GetKeys();
			strKeys.MakeUpper();

			if (strKeys.GetLength() < 2 || strKeys [0] != m_nCurrKeyChar)
			{
				pKeyTip->Hide();
				continue;
			}
		}

		pKeyTip->Show(bRepos);
	}

	if (m_pToolTip->GetSafeHwnd() != NULL && m_pToolTip->IsWindowVisible())
	{
		m_pToolTip->SetWindowPos(&wndTopMost, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
}

void CMFCRibbonBar::HideKeyTips()
{
	for (int i = 0; i < (int)m_arKeyElements.GetSize(); i++)
	{
		CMFCRibbonKeyTip* pKeyTip = m_arKeyElements [i];
		ASSERT_VALID(pKeyTip);

		pKeyTip->Hide();
	}
}

void CMFCRibbonBar::OnRTLChanged(BOOL bIsRTL)
{
	CPane::OnRTLChanged(bIsRTL);

	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);
		m_pMainButton->OnRTLChanged(bIsRTL);
	}

	m_QAToolbar.OnRTLChanged(bIsRTL);
	m_TabElements.OnRTLChanged(bIsRTL);

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		pCategory->OnRTLChanged(bIsRTL);
	}

	m_bForceRedraw = TRUE;
	RecalcLayout();
}

BOOL CMFCRibbonBar::OnSysKeyDown(CFrameWnd* pFrameWnd, WPARAM wParam, LPARAM lParam)
{
	if (wParam == VK_SPACE)
	{
		// Pop up the system menu for the frame ourselves (so we get the themed menu)
		CRect rectWindow;
		int cxOffset = 4, cyOffset = 23;

		GetWindowRect(rectWindow);
		ShowSysMenu(CPoint(rectWindow.left + cxOffset, rectWindow.top + cyOffset));

		RemoveAllKeys();
		KillTimer(AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS);

		return FALSE;
	}

	if (!m_bKeyTips)
	{
		return wParam == VK_F10 || wParam == VK_MENU;
	}

	BOOL  isCtrlPressed = (0x8000 & GetKeyState(VK_CONTROL)) != 0;
	BOOL  isShiftPressed = (0x8000 & GetKeyState(VK_SHIFT)) != 0;

	if (wParam != VK_MENU && wParam != VK_F10)
	{
		KillTimer(AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS);
		return FALSE;
	}

	if (CMFCPopupMenu::m_pActivePopupMenu == NULL && (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ALL) == 0 && (wParam == VK_MENU ||(wParam == VK_F10 && !isCtrlPressed && !isShiftPressed)))
	{
		if (GetFocus() == this &&(lParam &(1 << 30)) == 0 && wParam == VK_F10)
		{
			pFrameWnd->SetFocus();
		}
		else
		{
			if (wParam == VK_F10)
			{
				SetFocus();
			}
			else if (m_nKeyboardNavLevel < 0)
			{
				int nDelay = 200;
				SetTimer(AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS, nDelay, NULL);
			}
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonBar::OnSysKeyUp(CFrameWnd* pFrameWnd, WPARAM wParam, LPARAM /*lParam*/)
{
	if (!m_bKeyTips)
	{
		return wParam == VK_F10 || wParam == VK_MENU;
	}

	KillTimer(AFX_TIMER_ID_RIBBONBAR_SHOW_KEYTIPS);

	if (wParam == VK_MENU)
	{
		if (GetFocus() != this)
		{
			SetFocus();
		}
		else if (CMFCPopupMenu::m_pActivePopupMenu == NULL)
		{
			pFrameWnd->SetFocus();
		}

		RedrawWindow();
		return TRUE;
	}

	return FALSE;
}

void CMFCRibbonBar::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CPane::OnShowWindow(bShow, nStatus);

	if (!bShow && m_bIsTransparentCaption)
	{
		MARGINS margins;
		margins.cxLeftWidth = 0;
		margins.cxRightWidth = 0;
		margins.cyTopHeight = 0;
		margins.cyBottomHeight = 0;

		_AfxDwmExtendFrameIntoClientArea(GetParent()->GetSafeHwnd(), &margins);
	}
}

BOOL CMFCRibbonBar::NavigateRibbon(int nChar)
{
	ASSERT_VALID(this);

	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arElems;

	const BOOL bIsRibbonMinimized = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0;

	if (GetDroppedDown() != NULL || nChar == VK_ESCAPE)
	{
		return FALSE;
	}

	// Get focused element
	CMFCRibbonBaseElement* pFocused = GetFocused();
	if (pFocused == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pFocused);

	HideKeyTips();

	RemoveAllKeys();
	m_nCurrKeyChar = 0;

	m_nKeyboardNavLevel = -1;
	m_pKeyboardNavLevelParent = NULL;
	m_pKeyboardNavLevelCurrent = NULL;

	if (pFocused == m_pMainButton)
	{
		switch (nChar)
		{
		case VK_DOWN:
		case VK_RETURN:
		case VK_SPACE:
			pFocused->OnKey(FALSE);
			return TRUE;

		case VK_UP:
			return TRUE;

		case VK_RIGHT:
			if (m_pActiveCategory != NULL)
			{
				ASSERT_VALID(m_pActiveCategory);

				pFocused->m_bIsFocused = pFocused->m_bIsHighlighted = FALSE;
				pFocused->OnSetFocus(FALSE);
				pFocused->Redraw();

				m_pActiveCategory->m_Tab.m_bIsFocused = TRUE;
				m_pActiveCategory->m_Tab.OnSetFocus(TRUE);
				m_pActiveCategory->m_Tab.Redraw();
				return TRUE;
			}
		}
	}

	if (nChar == VK_RETURN || nChar == VK_SPACE)
	{
		pFocused->OnKey(FALSE);
		return TRUE;
	}

	if (nChar == VK_DOWN && pFocused->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)) && m_pActiveCategory != NULL && !bIsRibbonMinimized)
	{
		ASSERT_VALID(m_pActiveCategory);

		CMFCRibbonBaseElement* pFocusedNew = m_pActiveCategory->GetFirstVisibleElement();
		if (pFocusedNew != NULL)
		{
			ASSERT_VALID(pFocusedNew);

			pFocused->m_bIsFocused = pFocused->m_bIsHighlighted = FALSE;
			pFocused->OnSetFocus(FALSE);
			pFocused->Redraw();

			pFocusedNew->m_bIsFocused = TRUE;
			pFocusedNew->OnSetFocus(TRUE);
			pFocusedNew->Redraw();
			return TRUE;
		}
	}

	switch (nChar)
	{
	case VK_DOWN:
	case VK_UP:
	case VK_LEFT:
	case VK_RIGHT:
	case VK_TAB:
		{
			GetVisibleElements(arElems);

			CRect rectClient;
			GetClientRect(rectClient);

			int nScroll = 0;
			BOOL bIsScrollLeftAvailable = FALSE;
			BOOL bIsScrollRightAvailable = FALSE;

			if (m_pActiveCategory != NULL)
			{
				ASSERT_VALID(m_pActiveCategory);

				bIsScrollLeftAvailable = !m_pActiveCategory->m_ScrollLeft.GetRect().IsRectEmpty();
				bIsScrollRightAvailable = !m_pActiveCategory->m_ScrollRight.GetRect().IsRectEmpty();
			}

			CMFCRibbonBaseElement* pFocusedNew = FindNextFocusedElement(
				nChar, arElems, rectClient, pFocused,  bIsScrollLeftAvailable, bIsScrollRightAvailable, nScroll);

			if (nScroll != 0 && m_pActiveCategory != NULL)
			{
				switch (nScroll)
				{
				case -2:
					pFocusedNew = m_pActiveCategory->GetFirstVisibleElement();
					break;

				case 2:
					pFocusedNew = m_pActiveCategory->GetLastVisibleElement();
					break;

				case -1:
				case 1:
					m_pActiveCategory->OnScrollHorz(nScroll < 0);
				}
			}

			if (pFocusedNew == pFocused)
			{
				return TRUE;
			}

			if (pFocusedNew == NULL)
			{
				return TRUE;
			}

			if (nChar == VK_UP)
			{
				//-----------------------------------------------------
				// Up ouside the current panel should activate the tab!
				//-----------------------------------------------------
				if (pFocusedNew->GetParentPanel() != pFocused->GetParentPanel() && !pFocusedNew->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)) && m_pActiveCategory != NULL)
				{
					pFocusedNew = &m_pActiveCategory->m_Tab;
				}
			}

			pFocused->m_bIsHighlighted = pFocused->m_bIsFocused = FALSE;
			pFocused->OnSetFocus(FALSE);
			pFocused->Redraw();

			ASSERT_VALID(pFocusedNew);

			if (pFocusedNew->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)) && !bIsRibbonMinimized)
			{
				if (pFocused->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)) && (nChar == VK_LEFT || nChar == VK_RIGHT))
				{
					SetActiveCategory(pFocusedNew->GetParentCategory());
					pFocusedNew->m_bIsFocused = TRUE;
				}
				else if (m_pActiveCategory != NULL)
				{
					ASSERT_VALID(m_pActiveCategory);

					pFocusedNew = &m_pActiveCategory->m_Tab;
					pFocusedNew->m_bIsFocused = TRUE;
					pFocusedNew->OnSetFocus(TRUE);
				}
			}
			else
			{
				pFocusedNew->m_bIsFocused = TRUE;
				pFocusedNew->OnSetFocus(TRUE);
			}

			pFocusedNew->Redraw();
			return TRUE;
		}
	}

	return FALSE;
}

CMFCRibbonBaseElement* __stdcall CMFCRibbonBar::FindNearest(CPoint pt, const CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arButtons)
{
	for (int i = 0; i < (int)arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = arButtons [i];
		ASSERT_VALID(pElem);

		if (pElem->m_rect.PtInRect(pt))
		{
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* __stdcall CMFCRibbonBar::FindNextFocusedElement(
	int nChar, const CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElems,
	CRect rectElems, CMFCRibbonBaseElement* pFocused,
	BOOL bIsScrollLeftAvailable, BOOL bIsScrollRightAvailable, int& nScroll)
{
	ASSERT_VALID(pFocused);

	nScroll = 0;
	int nIndexFocused = -1;

	for (int i = 0; i < (int)arElems.GetSize(); i++)
	{
		if (arElems [i] == pFocused)
		{
			nIndexFocused = i;
			break;
		}
	}

	if (nIndexFocused < 0)
	{
		return FALSE;
	}

	const BOOL bIsTabFocused = pFocused->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab));

	CMFCRibbonBaseElement* pFocusedNew = NULL;

	if (nChar == VK_TAB)
	{
		const BOOL bShift = ::GetAsyncKeyState(VK_SHIFT) & 0x8000;

		int nNewIndex = -1;

		if (bShift)
		{
			for (int i = nIndexFocused - 1; nNewIndex < 0; i--)
			{
				if (i < 0)
				{
					if (bIsScrollLeftAvailable)
					{
						nScroll = -1;
						return NULL;
					}
					else if (bIsScrollRightAvailable)
					{
						nScroll = 2;
						return NULL;
					}

					i = (int)arElems.GetSize() - 1;
				}

				if (i == nIndexFocused)
				{
					return FALSE;
				}

				ASSERT_VALID(arElems [i]);

				if (bIsTabFocused && arElems [i]->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)))
				{
					continue;
				}

				if (arElems [i]->IsTabStop() && !arElems [i]->GetRect().IsRectEmpty())
				{
					nNewIndex = i;
				}
			}
		}
		else
		{
			for (int i = nIndexFocused + 1; nNewIndex < 0; i++)
			{
				if (i >= (int)arElems.GetSize())
				{
					if (bIsScrollRightAvailable)
					{
						nScroll = 1;
						return NULL;
					}
					else if (bIsScrollLeftAvailable)
					{
						nScroll = -2;
						return NULL;
					}

					i = 0;
				}

				if (i == nIndexFocused)
				{
					return FALSE;
				}

				ASSERT_VALID(arElems [i]);

				if (bIsTabFocused && arElems [i]->IsKindOf(RUNTIME_CLASS(CMFCRibbonTab)))
				{
					continue;
				}

				if (arElems [i]->IsTabStop() && !arElems [i]->GetRect().IsRectEmpty())
				{
					nNewIndex = i;
				}
			}
		}

		pFocusedNew = arElems [nNewIndex];
	}
	else
	{
		if (pFocused->HasFocus())
		{
			return NULL;
		}

		CRect rectCurr = pFocused->GetRect();

		const int nStep = 5;

		switch (nChar)
		{
		case VK_LEFT:
		case VK_RIGHT:
			{
				int xStart = nChar == VK_RIGHT ?
					rectCurr.right + 1 :
					rectCurr.left - nStep - 1;
				int xStep = nChar == VK_RIGHT ? nStep : -nStep;

				for (int x = xStart; pFocusedNew == NULL; x += xStep)
				{
					if (nChar == VK_RIGHT)
					{
						if (x > rectElems.right)
						{
							if (bIsScrollRightAvailable)
							{
								nScroll = 1;
								return NULL;
							}
							else if (bIsScrollLeftAvailable)
							{
								nScroll = -2;
								return NULL;
							}

							x = rectElems.left;
						}
					}
					else
					{
						if (x < rectElems.left)
						{
							if (bIsScrollLeftAvailable)
							{
								nScroll = -1;
								return NULL;
							}
							else if (bIsScrollRightAvailable)
							{
								nScroll = 2;
								return NULL;
							}

							x = rectElems.right;
						}
					}

					if (x >= rectCurr.left && x <= rectCurr.right)
					{
						break;
					}

					CRect rectArea(x, rectCurr.top, x + nStep, rectCurr.bottom);
					if (pFocused->IsLargeMode() || pFocused->IsWholeRowHeight())
					{
						rectArea.DeflateRect(0, rectArea.Height() / 3);
					}

					CRect rectInter;

					for (int i = 0; i < (int)arElems.GetSize(); i++)
					{
						CMFCRibbonBaseElement* pElem = arElems [i];
						ASSERT_VALID(pElem);

						if (pElem->IsTabStop() && rectInter.IntersectRect(pElem->m_rect, rectArea))
						{
							pFocusedNew = pElem;
							break;
						}
					}
				}
			}
			break;

		case VK_UP:
		case VK_DOWN:
			{
				int x = rectCurr.CenterPoint().x;

				int yStart = nChar == VK_DOWN ?
					rectCurr.bottom + 1 :
					rectCurr.top - 1;

				int yStep = nChar == VK_DOWN ? nStep : -nStep;

				for (int i = 0; pFocusedNew == NULL; i++)
				{
					int y = yStart;

					int x1 = x - i * nStep;
					int x2 = x + i * nStep;

					if (x1 < rectElems.left && x2 > rectElems.right)
					{
						break;
					}

					while (pFocusedNew == NULL)
					{
						if ((pFocusedNew = FindNearest(CPoint(x1, y), arElems)) == NULL)
						{
							pFocusedNew = FindNearest(CPoint(x2, y), arElems);
						}

						if (pFocusedNew != NULL)
						{
							ASSERT_VALID(pFocusedNew);

							if (!pFocusedNew->IsTabStop())
							{
								pFocusedNew = NULL;
							}
						}

						y += yStep;

						if (nChar == VK_DOWN)
						{
							if (y > rectElems.bottom)
							{
								break;
							}
						}
						else
						{
							if (y < rectElems.top)
							{
								break;
							}
						}
					}
				}
			}
		}
	}

	return pFocusedNew;
}

CMFCRibbonBaseElement* CMFCRibbonBar::GetFocused()
{
	const BOOL bIsRibbonMinimized = (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0;

	//---------------------------
	// Check for the main button:
	//---------------------------
	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);

		if (m_pMainButton->IsFocused())
		{
			return m_pMainButton;
		}
	}

	//--------------------------------
	// Check for quick access toolbar:
	//--------------------------------
	CMFCRibbonBaseElement* pQAElem = m_QAToolbar.GetFocused();
	if (pQAElem != NULL)
	{
		ASSERT_VALID(pQAElem);
		return pQAElem;
	}

	//------------------------
	// Check for tab elements:
	//------------------------
	CMFCRibbonBaseElement* pTabElem = m_TabElements.GetFocused();
	if (pTabElem != NULL)
	{
		ASSERT_VALID(pTabElem);
		return pTabElem;
	}

	if (m_pActiveCategory != NULL)
	{
		ASSERT_VALID(m_pActiveCategory);

		if (m_pActiveCategory->m_Tab.IsFocused())
		{
			return &m_pActiveCategory->m_Tab;
		}

		if (!bIsRibbonMinimized)
		{
			return m_pActiveCategory->GetFocused();
		}
	}

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		if (m_arCategories [i]->m_Tab.IsFocused())
		{
			return &m_arCategories [i]->m_Tab;
		}
	}

	return NULL;
}

void CMFCRibbonBar::GetVisibleElements(CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arButtons)
{
	ASSERT_VALID(this);

	arButtons.RemoveAll();

	if (m_pMainButton != NULL)
	{
		ASSERT_VALID(m_pMainButton);
		m_pMainButton->GetVisibleElements(arButtons);
	}

	m_QAToolbar.GetVisibleElements(arButtons);

	for (int i = 0; i < (int)m_arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory = m_arCategories [i];
		ASSERT_VALID(pCategory);

		if (!pCategory->m_Tab.m_rect.IsRectEmpty())
		{
			pCategory->m_Tab.GetVisibleElements(arButtons);
		}
	}

	m_TabElements.GetVisibleElements(arButtons);

	if (m_pActiveCategory != NULL && (m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
	{
		ASSERT_VALID(m_pActiveCategory);
		m_pActiveCategory->GetVisibleElements(arButtons);
	}
}

BOOL CMFCRibbonBar::SaveToXMLFile(LPCTSTR lpszFilePath) const
{
	ASSERT_VALID(this);
	ASSERT(lpszFilePath != NULL);

	LPBYTE lpBuffer = NULL;
	UINT nSize = SaveToXMLBuffer(&lpBuffer);

	if (nSize == 0 || lpBuffer == NULL)
	{
		return FALSE;
	}

	BOOL bRes = TRUE;

	try
	{
		CFile file(lpszFilePath, CFile::modeCreate | CFile::modeWrite);
		file.Write(lpBuffer, nSize);
	}
	catch(CFileException* pEx)
	{
		bRes = FALSE;
		TRACE(_T("CMFCRibbonBar::SaveToXMLFile (%Ts): Reporting file I/O exception with lOsError = %lX.\n"), lpszFilePath, pEx->m_lOsError);
		pEx->Delete();
	}

	delete [] lpBuffer;
	return bRes;
}

UINT CMFCRibbonBar::SaveToXMLBuffer(LPBYTE* ppBuffer) const
{
	ASSERT_VALID(this);
	ASSERT(ppBuffer != NULL);

	CMFCRibbonInfo info;
	CMFCRibbonCollector collector(info, CMFCRibbonCollector::e_CollectImagesID);
	collector.CollectRibbonBar(*this);

	UINT nSize = 0;
	*ppBuffer = NULL;

	if (!info.Write(ppBuffer, nSize) || ppBuffer == NULL)
	{
		return 0;
	}

	return nSize;
}

int CMFCRibbonBar::GetVisibleContextCaptionCount ()
{
	int nCount = 0;
	UINT uiContextID = 0;

	for (int i = 0; i < GetCategoryCount (); i++)
	{
		CMFCRibbonCategory* pCategory = GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() != 0 && pCategory->GetContextID() != uiContextID && pCategory->IsVisible())
		{
			uiContextID = pCategory->GetContextID();
			nCount++;
		}
	}

	return nCount;
}

void CMFCRibbonBar::GetVisibleContextCaptions (CArray<int, int>* arCaptions)
{
	UINT uiContextID = 0;

	for (int i = 0; i < GetCategoryCount (); i++)
	{
		CMFCRibbonCategory* pCategory = GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() != 0 && pCategory->GetContextID() != uiContextID && pCategory->IsVisible())
		{
			uiContextID = pCategory->GetContextID();
			arCaptions->Add(uiContextID);
		}
	}
}

void CMFCRibbonBar::GetVisibleContextCaptions (CArray<CMFCRibbonContextCaption*, CMFCRibbonContextCaption*>& arCaptions)
{
	UINT uiContextID = 0;

	for (int i = 0; i < GetCategoryCount (); i++)
	{
		CMFCRibbonCategory* pCategory = GetCategory(i);
		ASSERT_VALID(pCategory);

		if (pCategory->GetContextID() != 0 && pCategory->GetContextID() != uiContextID && pCategory->IsVisible())
		{
			uiContextID = pCategory->GetContextID();

			CMFCRibbonContextCaption* pCaption = FindContextCaption(uiContextID);
			if (pCaption != NULL)
			{
				ASSERT_VALID (pCaption);
				arCaptions.Add(pCaption);
			}
		}
	}
}

BOOL CMFCRibbonBar::IsCaptionButtons ()
{
	for (int i = 0; i < AFX_RIBBON_CAPTION_BUTTONS; i++)
	{
		if (m_CaptionButtons[i].GetRect().IsRectEmpty())
		{
			return FALSE;
		}
	}

	return TRUE;
}
