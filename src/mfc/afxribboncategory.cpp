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
#include "afxribbonpanel.h"
#include "afxribboncategory.h"
#include "afxribbonbar.h"
#include "afxvisualmanager.h"
#include "afxribbonpanelmenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const int nPanelMarginLeft = 2;
static const int nPanelMarginRight = 2;
static const int nPanelMarginTop = 3;
static const int nPanelMarginBottom = 4;

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonTab

IMPLEMENT_DYNAMIC(CMFCRibbonTab, CMFCRibbonBaseElement)

CMFCRibbonTab::CMFCRibbonTab()
{
	m_bIsTruncated = FALSE;
	m_Color = AFX_CategoryColor_None;
	m_nFullWidth = 0;
}

CString CMFCRibbonTab::GetToolTipText() const
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	if (!m_bIsTruncated)
	{
		return _T("");
	}

	CString strToolTipText = m_pParent->m_strName;
	strToolTipText.Remove(_T('&'));

	return strToolTipText;
}

void CMFCRibbonTab::CopyFrom(const CMFCRibbonBaseElement& s)
{
	CMFCRibbonBaseElement::CopyFrom(s);

	CMFCRibbonTab& src = (CMFCRibbonTab&) s;
	m_Color = src.m_Color;
	m_nFullWidth = src.m_nFullWidth;
}

void CMFCRibbonTab::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	ASSERT_VALID(m_pParent);
	ASSERT_VALID(m_pParent->GetParentRibbonBar());

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	COLORREF clrText = CMFCVisualManager::GetInstance()->OnDrawRibbonCategoryTab(pDC, this, m_pParent->IsActive() || GetDroppedDown() != NULL);
	COLORREF clrTextOld = pDC->SetTextColor(clrText);

	CRect rectTab = m_rect;
	CRect rectTabText = m_rect;

	pDC->DrawText(m_pParent->m_strName, rectTabText, DT_CALCRECT | DT_SINGLELINE | DT_VCENTER);

	const int cxTabText = rectTabText.Width();
	const int cxTabTextMargin = max(4, (rectTab.Width() - cxTabText) / 2);

	rectTab.DeflateRect(cxTabTextMargin, 0);
	rectTab.top += nPanelMarginTop;

	pDC->DrawText(m_pParent->m_strName, rectTab, DT_SINGLELINE | DT_VCENTER);
	pDC->SetTextColor(clrTextOld);
}

CRect CMFCRibbonTab::GetKeyTipRect(CDC* pDC, BOOL /*bIsMenu*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	ASSERT_VALID(m_pParent);
	ASSERT_VALID(m_pParent->m_pParentRibbonBar);

	CSize sizeKeyTip = GetKeyTipSize(pDC);

	if (sizeKeyTip == CSize(0, 0) || m_rect.IsRectEmpty())
	{
		return CRect(0, 0, 0, 0);
	}

	CRect rectKeyTip(0, 0, 0, 0);

	CRect rectTab = m_rect;
	CRect rectTabText = m_rect;

	pDC->DrawText(m_pParent->m_strName, rectTabText, DT_CALCRECT | DT_SINGLELINE | DT_VCENTER);

	const int cxTabText = rectTabText.Width();
	const int cxTabTextMargin = max(4, (rectTab.Width() - cxTabText) / 2);

	rectTab.DeflateRect(cxTabTextMargin, 0);
	rectTab.top += nPanelMarginTop;

	rectKeyTip.left = rectTab.CenterPoint().x - sizeKeyTip.cx / 2;
	rectKeyTip.right = rectKeyTip.left + sizeKeyTip.cx;

	rectKeyTip.top = rectTabText.bottom - 2;
	rectKeyTip.bottom = rectKeyTip.top + sizeKeyTip.cy;

	return rectKeyTip;
}

BOOL CMFCRibbonTab::OnKey(BOOL /*bIsMenuKey*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
	ASSERT_VALID(pBar);

	if (IsDisabled())
	{
		return FALSE;
	}

	if (m_pParent->GetParentMenuBar() != NULL)
	{
		// Already dropped-down
		return TRUE;
	}

	pBar->SetActiveCategory(m_pParent);

	if ((pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
	{
		pBar->SetKeyboardNavigationLevel(m_pParent);
	}

	return FALSE;
}

BOOL CMFCRibbonTab::SetACCData(CWnd* pParent, CAccessibilityData& data)
{
	ASSERT_VALID(this);

	if (m_pParent == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(m_pParent);

	CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
	if (pBar->GetSafeHwnd() == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pBar);

	const BOOL bIsRibbonMinimized = (pBar->GetHideFlags () & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0;

	if (!CMFCRibbonBaseElement::SetACCData(pParent, data))
	{
		return FALSE;
	}

	data.m_bAccState = STATE_SYSTEM_FOCUSABLE | STATE_SYSTEM_SELECTABLE;

	if (bIsRibbonMinimized)
	{
		data.m_bAccState |= STATE_SYSTEM_HASPOPUP;

		if (IsDroppedDown())
		{
			data.m_bAccState |= (STATE_SYSTEM_SELECTED | STATE_SYSTEM_PRESSED);
			data.m_strAccDefAction = _T("Close");
		}
		else
		{
			data.m_strAccDefAction = _T("Open");
		}
	}
	else 
	{
		if (m_pParent->IsActive())
		{
			data.m_bAccState |= STATE_SYSTEM_SELECTED;
		}

		data.m_strAccDefAction = _T("Switch");
	}

	data.m_strAccName = m_pParent->GetName();
	data.m_nAccRole = ROLE_SYSTEM_PAGETAB;
	data.m_strAccKeys = _T("Alt, ") + m_strKeys;

	return TRUE;
}

void CMFCRibbonTab::Redraw()
{
	ASSERT_VALID(this);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	ASSERT_VALID(m_pParent);

	CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
	ASSERT_VALID(pBar);

	CRect rect = m_rect;

	rect.InflateRect(10, 10);
	pBar->RedrawWindow(rect);
}

CSize CMFCRibbonTab::GetRegularSize(CDC* /*pDC*/)
{
	return CSize(0, 0);
}

void CMFCRibbonTab::OnLButtonDown(CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	m_pParent->GetParentRibbonBar()->SetActiveCategory(m_pParent);
}

void CMFCRibbonTab::OnAccDefaultAction()
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	if (m_pParent == NULL || m_pParent->GetParentRibbonBar()->GetSafeHwnd() == NULL)
	{
		return;
	}

	CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
	ASSERT_VALID(pBar);

	const BOOL bIsRibbonMinimized = (pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0;

	if (pBar->IsSingleLevelAccessibilityMode() || !bIsRibbonMinimized)
	{
		pBar->SetActiveCategory(m_pParent);
	}
	else
	{
		pBar->OnLButtonDown(0, m_rect.TopLeft());
		pBar->OnLButtonUp(0, m_rect.TopLeft());
	}
}

void CMFCRibbonTab::OnLButtonDblClk(CPoint /*point*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	if (m_pParent->IsActive())
	{
		if (m_pParent->m_ActiveTime != (clock_t)-1 && clock() - m_pParent->m_ActiveTime <(int) GetDoubleClickTime())
		{
			return;
		}

		CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
		ASSERT_VALID(pBar);

		if ((pBar->GetHideFlags() & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0)
		{
			// Ribbon is minimized, restore it now:
			if (IsDroppedDown())
			{
				ClosePopupMenu();
			}

			m_pParent->ShowElements();
		}
		else
		{
			// Minimize ribbon:
			m_pParent->ShowElements(FALSE);
		}

		pBar->GetParentFrame()->RecalcLayout();
		pBar->RedrawWindow();
	}
}

BOOL CMFCRibbonTab::IsSelected() const
{
	ASSERT_VALID(this);
	return m_bIsFocused;
}

HRESULT CMFCRibbonTab::accHitTest(long /*xLeft*/, long /*yTop*/, VARIANT* pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	pvarChild->vt = VT_I4;
	pvarChild->lVal = CHILDID_SELF;

	return S_OK;
}

HRESULT CMFCRibbonTab::get_accParent(IDispatch **ppdispParent)
{
	HRESULT hr = E_INVALIDARG;

	if (m_pParent == NULL || m_pParent->GetParentRibbonBar()->GetSafeHwnd() == NULL)
	{
		return hr;
	}

	if (ppdispParent && m_pParent->m_pParentRibbonBar->GetTabs() != NULL)
	{
		*ppdispParent = m_pParent->m_pParentRibbonBar->GetTabs()->GetIDispatch(TRUE);
		hr  = (*ppdispParent) ? S_OK : S_FALSE;
	}          

	return hr;
}

HRESULT CMFCRibbonTab::accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild)
{
	if (!pxLeft || !pyTop || !pcxWidth || !pcyHeight)
	{
		return E_INVALIDARG;
	}

	if (m_pParent == NULL || m_pParent->m_pParentRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{		
		CRect rectAccLocation = m_rect;
		m_pParent->m_pParentRibbonBar->ClientToScreen(&rectAccLocation);

		*pxLeft = rectAccLocation.left;
		*pyTop = rectAccLocation.top;
		*pcxWidth = rectAccLocation.Width();
		*pcyHeight = rectAccLocation.Height();
	}

	return S_OK;
}

HRESULT CMFCRibbonTab::get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CString str = _T("Switch");
		*pszDefaultAction = str.AllocSysString();

		return S_OK;
	}

	return S_FALSE;
}

HRESULT CMFCRibbonTab::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (m_pParent == NULL)
	{
		return S_FALSE;
	}

	ASSERT_VALID(m_pParent);
	
	CMFCRibbonBar* pBar = m_pParent->GetParentRibbonBar();
	if (pBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}
	
	ASSERT_VALID(pBar);

	CMFCRibbonTabsGroup* pTabs = pBar->GetTabs();
	if (pTabs == NULL)
	{
		return S_FALSE;
	}

	ASSERT_VALID(pTabs);

	switch (navDir)
	{
	case NAVDIR_NEXT:   
	case NAVDIR_RIGHT:
		if (varStart.lVal == CHILDID_SELF)
		{
			//next tab
			int nIndex =  pTabs->GetButtonIndex(this) + 1;
			if (nIndex < pTabs->GetCount ())
			{
				CMFCRibbonBaseElement* pButton = pTabs->GetButton(nIndex);
				if (pButton != NULL)
				{
					ASSERT_VALID(pButton);
					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pButton->GetIDispatch(TRUE);
					return S_OK;
				}
			}
		}
		break;

	case NAVDIR_PREVIOUS: 
	case NAVDIR_LEFT:
		if (varStart.lVal == CHILDID_SELF)
		{
			//prev tab
			int nIndex =  pTabs->GetButtonIndex (this) - 1;
			if (nIndex >= 0)
			{
				CMFCRibbonBaseElement* pButton = pTabs->GetButton(nIndex);
				if (pButton != NULL)
				{
					ASSERT_VALID(pButton);
					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pButton->GetIDispatch(TRUE);
					return S_OK;
				}
			}
		}
		break;
	}

	return S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonCategoryScroll

CRibbonCategoryScroll::CRibbonCategoryScroll()
{
	m_bIsLeft = FALSE;
}

void CRibbonCategoryScroll::CopyFrom(const CMFCRibbonBaseElement& s)
{
	CMFCRibbonButton::CopyFrom(s);

	CRibbonCategoryScroll& src = (CRibbonCategoryScroll&) s;
	m_bIsLeft = src.m_bIsLeft;
}

void CRibbonCategoryScroll::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	CMFCVisualManager::GetInstance()->OnDrawRibbonCategoryScroll(
		pDC, this);
}

BOOL CRibbonCategoryScroll::OnAutoRepeat()
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	if (m_rect.IsRectEmpty())
	{
		return FALSE;
	}

	return m_pParent->OnScrollHorz(m_bIsLeft);
}

void CRibbonCategoryScroll::OnMouseMove(CPoint point) 
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParent);

	if (m_rect.IsRectEmpty())
	{
		m_bIsHighlighted = FALSE;
		return;
	}

	BOOL bWasHighlighted = m_bIsHighlighted;
	m_bIsHighlighted = m_rect.PtInRect(point);

	if (bWasHighlighted != m_bIsHighlighted)
	{
		if (m_pParent->GetParentMenuBar() != NULL)
		{
			m_pParent->GetParentMenuBar()->PopTooltip();
		}
		else if (m_pParent->GetParentRibbonBar() != NULL)
		{
			m_pParent->GetParentRibbonBar()->PopTooltip();
		}

		Redraw();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRibbonCategory

IMPLEMENT_DYNCREATE(CMFCRibbonCategory, CMFCBaseAccessibleObject)

CMFCRibbonCategory::CMFCRibbonCategory()
{
	CommonInit();
}

CMFCRibbonCategory::CMFCRibbonCategory(CMFCRibbonBar* pParentRibbonBar, LPCTSTR lpszName, UINT uiSmallImagesResID, UINT uiLargeImagesResID, CSize sizeSmallImage, CSize sizeLargeImage)
{
	ASSERT_VALID(pParentRibbonBar);
	ENSURE(lpszName != NULL);

	CommonInit(pParentRibbonBar, lpszName, uiSmallImagesResID, uiLargeImagesResID, sizeSmallImage, sizeLargeImage);
}

void CMFCRibbonCategory::CommonInit(CMFCRibbonBar* pParentRibbonBar, LPCTSTR lpszName, UINT uiSmallImagesResID, UINT uiLargeImagesResID, CSize sizeSmallImage, CSize sizeLargeImage)
{
	m_pParentMenuBar = NULL;
	m_bMouseIsPressed = FALSE;
	m_bIsActive = FALSE;
	m_bIsVisible = TRUE;
	m_dwData = 0;
	m_uiContextID = 0;
	m_nLastCategoryWidth = -1;
	m_nLastCategoryOffsetY = 0;
	m_nMinWidth = -1;

	m_rect.SetRectEmpty();

	m_pParentRibbonBar = pParentRibbonBar;
	SetName(lpszName);

	// Load images:
	if (sizeSmallImage != CSize(0, 0))
	{
		m_SmallImages.SetImageSize(sizeSmallImage);
	}

	if (sizeLargeImage != CSize(0, 0))
	{
		m_LargeImages.SetImageSize(sizeLargeImage);
	}

	m_uiSmallImagesResID = uiSmallImagesResID;
	m_uiLargeImagesResID = uiLargeImagesResID;

	if (m_uiSmallImagesResID > 0)
	{
		if (!m_SmallImages.Load(m_uiSmallImagesResID))
		{
			m_uiSmallImagesResID = 0;
			ASSERT(FALSE);
		}
	}

	if (m_uiLargeImagesResID > 0)
	{
		if (!m_LargeImages.Load(m_uiLargeImagesResID))
		{
			m_uiLargeImagesResID = 0;
			ASSERT(FALSE);
		}
	}

	const double dblScale = GetGlobalData()->GetRibbonImageScale();
	if (dblScale != 1.0)
	{
		if (sizeSmallImage == CSize(16, 16))
		{
			m_SmallImages.SmoothResize(dblScale);
		}

		if (sizeLargeImage == CSize(32, 32))
		{
			m_LargeImages.SmoothResize(dblScale);
		}
	}

	m_Tab.m_pParent = this;

	int nIndex = m_strName.Find(_T('\n'));
	if (nIndex >= 0)
	{
		m_Tab.SetKeys(m_strName.Mid(nIndex + 1));
		m_strName = m_strName.Left(nIndex);
	}

	m_ScrollLeft.m_pParent = this;
	m_ScrollRight.m_pParent = this;
	m_ScrollLeft.m_bIsLeft = TRUE;
	m_ScrollRight.m_bIsLeft = FALSE;

	m_nScrollOffset = 0;
	m_ActiveTime = (clock_t)-1;
}

CMFCRibbonCategory::~CMFCRibbonCategory()
{
	int i = 0;

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		delete m_arPanels [i];
	}

	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		delete m_arElements [i];
	}
}

void CMFCRibbonCategory::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	CMFCVisualManager::GetInstance()->OnDrawRibbonCategory(pDC, this, m_rect);

	BOOL bClip = FALSE;

	CRgn rgnClip;

	if (!m_ScrollLeft.GetRect().IsRectEmpty() ||
		!m_ScrollRight.GetRect().IsRectEmpty())
	{
		CRect rectClient = m_rect;
		rectClient.DeflateRect(nPanelMarginLeft, nPanelMarginTop, 
			nPanelMarginRight, nPanelMarginBottom);

		rgnClip.CreateRectRgnIndirect(rectClient);
		pDC->SelectClipRgn(&rgnClip);

		bClip = TRUE;
	}

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->DoPaint(pDC);
	}

	if (bClip)
	{
		pDC->SelectClipRgn(NULL);
	}

	m_ScrollLeft.OnDraw(pDC);
	m_ScrollRight.OnDraw(pDC);
}

CMFCRibbonPanel* CMFCRibbonCategory::AddPanel(LPCTSTR lpszPanelName, HICON hIcon, CRuntimeClass* pRTI)
{
	ASSERT_VALID(this);
	ENSURE(lpszPanelName != NULL);

	CMFCRibbonPanel* pPanel = NULL;

	if (pRTI != NULL)
	{
		pPanel = DYNAMIC_DOWNCAST(CMFCRibbonPanel, pRTI->CreateObject());

		if (pPanel == NULL)
		{
			ASSERT(FALSE);
			return NULL;
		}

		pPanel->CommonInit(lpszPanelName, hIcon);
	}
	else
	{
		pPanel = new CMFCRibbonPanel(lpszPanelName, hIcon);
	}

	m_arPanels.Add(pPanel);

	pPanel->m_pParent = this;
	pPanel->m_btnLaunch.m_pParent = this;
	pPanel->m_btnDefault.m_pParent = this;

	m_nLastCategoryWidth = -1;
	m_nMinWidth = -1;
	return pPanel;
}

BOOL CMFCRibbonCategory::RemovePanel (int nIndex, BOOL bDelete)
{
	ASSERT_VALID (this);

	if (nIndex < 0 || nIndex >= m_arPanels.GetSize ())
	{
		ASSERT (FALSE);
		return FALSE;
	}

	CMFCRibbonPanel* pPanel = m_arPanels [nIndex];
	ASSERT_VALID (pPanel);

	m_arPanels.RemoveAt (nIndex);

	if (bDelete)
	{
		delete pPanel;
	}

	return TRUE;
}

int CMFCRibbonCategory::GetPanelCount() const
{
	ASSERT_VALID(this);
	return(int) m_arPanels.GetSize();
}

CMFCRibbonPanel* CMFCRibbonCategory::GetPanel(int nIndex)
{
	ASSERT_VALID(this);
	return m_arPanels [nIndex];
}

int CMFCRibbonCategory::GetPanelIndex(const CMFCRibbonPanel* pPanel) const
{
	ASSERT_VALID(this);
	ASSERT_VALID(pPanel);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		if (m_arPanels [i] == pPanel)
		{
			return i;
		}
	}

	return -1;
}

int CMFCRibbonCategory::GetMaxHeight(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	int nMaxHeight = 0;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		nMaxHeight = max(nMaxHeight, pPanel->GetHeight(pDC));
	}

	return nMaxHeight + pDC->GetTextExtent(m_strName).cy + nPanelMarginTop + nPanelMarginBottom;
}

void CMFCRibbonCategory::RecalcLayout(CDC* pDC)
{
	if (m_rect.IsRectEmpty())
	{
		return;
	}

	if (m_pParentMenuBar != NULL)
	{
		CleanUpSizes();
	}

	RecalcPanelWidths(pDC);

	if (m_arPanels.GetSize() == 0)
	{
		return;
	}

	int i = 0;
	BOOL bRedrawScroll = FALSE;

	const DWORD dwRibbonHideFlags = GetParentRibbonBar()->m_dwHideFlags;
	const BOOL bHideAll = (dwRibbonHideFlags & AFX_RIBBONBAR_HIDE_ALL) ||(dwRibbonHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS);

	if (m_nMinWidth < 0)
	{
		m_nMinWidth = GetMinWidth(pDC);
	}

	if (bHideAll && m_pParentMenuBar == NULL)
	{
		for (i = 0; i < m_arPanels.GetSize(); i++)
		{
			CMFCRibbonPanel* pPanel = m_arPanels [i];
			ASSERT_VALID(pPanel);

			pPanel->Reposition(pDC, CRect(0, 0, 0, 0));
			pPanel->OnShow(FALSE);
		}

		m_nLastCategoryWidth = -1;
		m_nMinWidth = -1;
	}
	else if (m_nLastCategoryWidth != m_rect.Width() || m_nLastCategoryOffsetY != m_rect.top)
	{
		m_nLastCategoryWidth = m_rect.Width();
		m_nLastCategoryOffsetY = m_rect.top;

		CRect rectClient = m_rect;
		rectClient.DeflateRect(nPanelMarginLeft * 2, nPanelMarginTop, nPanelMarginRight * 2, nPanelMarginBottom);

		ResetPanelsLayout();

		if (rectClient.Width() <= m_nMinWidth)
		{
			//-------------------------
			// Just collapse all panes:
			//-------------------------
			for (i = 0; i < m_arPanels.GetSize(); i++)
			{
				CMFCRibbonPanel* pPanel = m_arPanels [i];
				ASSERT_VALID(pPanel);

				pPanel->m_bForceCollpapse = TRUE;
				pPanel->m_nCurrWidthIndex = (int) pPanel->m_arWidths.GetSize() - 1;
			}
		}
		else
		{
			BOOL bAutoResize = TRUE;

			if (m_arCollapseOrder.GetSize() > 0)
			{
				bAutoResize = FALSE;

				BOOL bOK = TRUE;

				for (int iNextPane = 0; iNextPane <= m_arCollapseOrder.GetSize(); iNextPane++)
				{
					bOK = SetPanelsLayout(rectClient.Width());
					if (bOK || iNextPane == m_arCollapseOrder.GetSize())
					{
						break;
					}

					// Find next pane for collapsing - from the user-defined list:
					int nPaneIndex = m_arCollapseOrder [iNextPane];
					if (nPaneIndex < 0 || nPaneIndex >= m_arPanels.GetSize())
					{
						ASSERT(FALSE);
						bOK = FALSE;
						break;
					}

					CMFCRibbonPanel* pPanel = m_arPanels [nPaneIndex];
					ASSERT_VALID(pPanel);

					if (iNextPane < m_arCollapseOrder.GetSize() - 1 && m_arCollapseOrder [iNextPane + 1] == -1)
					{
						pPanel->m_bForceCollpapse = TRUE;
						pPanel->m_nCurrWidthIndex = (int) pPanel->m_arWidths.GetSize() - 1;

						iNextPane++;
					}
					else
					{
						if (pPanel->m_nCurrWidthIndex < pPanel->m_arWidths.GetSize() - 1)
						{
							pPanel->m_nCurrWidthIndex++;
						}
					}
				}

				if (!bOK)
				{
					bAutoResize = TRUE;
					ResetPanelsLayout();
				}
			}

			if (bAutoResize)
			{
				while (TRUE)
				{
					if (SetPanelsLayout(rectClient.Width()))
					{
						break;
					}

					// Find next pane for collapsing - next matched:
					int nMaxWeightIndex = -1;
					int nMaxWeight = 1;

					for (i = 0; i < m_arPanels.GetSize(); i++)
					{
						CMFCRibbonPanel* pPanel = m_arPanels [i];
						ASSERT_VALID(pPanel);

						int nWeight = (int) pPanel->m_arWidths.GetSize() - pPanel->m_nCurrWidthIndex - 1;
						if (nWeight >= nMaxWeight)
						{
							nMaxWeightIndex = i;
							nMaxWeight = nWeight;
						}
					}

					if (nMaxWeightIndex < 0)
					{
						break;
					}

					CMFCRibbonPanel* pPanel = m_arPanels [nMaxWeightIndex];
					ASSERT_VALID(pPanel);

					pPanel->m_nCurrWidthIndex++;
				}
			}
		}

		ReposPanels(pDC);
		bRedrawScroll = TRUE;
	}

	UpdateScrollButtons();

	if (bRedrawScroll && GetParentRibbonBar()->GetSafeHwnd() != NULL)
	{
		if (!m_ScrollLeft.GetRect().IsRectEmpty() ||
			!m_ScrollRight.GetRect().IsRectEmpty())
		{
			GetParentRibbonBar()->RedrawWindow(m_rect);
		}
	}
}

void CMFCRibbonCategory::UpdateScrollButtons()
{
	m_ScrollLeft.m_pParentMenu = m_pParentMenuBar;
	m_ScrollRight.m_pParentMenu = m_pParentMenuBar;

	CRect rectScrollRightOld = m_ScrollRight.GetRect();

	const int cxScrollWidth = (int)(GetGlobalData()->GetRibbonImageScale() * 13);

	CRect rectScrollLeft(0, 0, 0, 0);
	CRect rectScrollRight(0, 0, 0, 0);

	if (m_nScrollOffset > 0)
	{
		rectScrollLeft = m_rect;
		rectScrollLeft.right = rectScrollLeft.left + cxScrollWidth;
	}

	if (m_rect.Width() + m_nScrollOffset < m_nMinWidth)
	{
		rectScrollRight = m_rect;
		rectScrollRight.left = rectScrollRight.right - cxScrollWidth;
	}

	m_ScrollLeft.SetRect(rectScrollLeft);
	m_ScrollRight.SetRect(rectScrollRight);

	if (rectScrollRight.IsRectEmpty () && !rectScrollRightOld.IsRectEmpty ())
	{
		GetParentRibbonBar ()->RedrawWindow (rectScrollRightOld);
	}
}

void CMFCRibbonCategory::ReposPanels(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	CRect rectClient = m_rect;
	rectClient.DeflateRect(nPanelMarginLeft * 2, nPanelMarginTop, 
							nPanelMarginRight * 2, nPanelMarginBottom);

	const BOOL bForceCollpapse = (rectClient.Width() <= m_nMinWidth);

	int x = rectClient.left - m_nScrollOffset;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (bForceCollpapse)
		{
			pPanel->m_bForceCollpapse = TRUE;
			pPanel->m_nCurrWidthIndex = (int) pPanel->m_arWidths.GetSize() - 1;
		}

		const int nCurrPanelWidth = 
			pPanel->m_arWidths [pPanel->m_nCurrWidthIndex] + 
			2 * pPanel->m_nXMargin;

		CRect rectPanel = CRect(x, rectClient.top, 
								x + nCurrPanelWidth, rectClient.bottom);

		pPanel->Reposition(pDC, rectPanel);

		x = pPanel->m_rect.right + nPanelMarginRight;

		if (rectPanel.right <= rectClient.left + 2 * nPanelMarginLeft ||
			rectPanel.left >= rectClient.right - 2 * nPanelMarginRight)
		{
			rectPanel.SetRectEmpty();



			pPanel->Reposition(pDC, rectPanel);
		}

		if (bForceCollpapse)
		{
			pPanel->m_bForceCollpapse = TRUE;
		}

		pPanel->OnAfterChangeRect(pDC);
	}
}

void CMFCRibbonCategory::RecalcPanelWidths(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	int nHeight = -1;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (pPanel->m_arWidths.GetSize() == 0)
		{
			if (nHeight == -1)
			{
				nHeight = GetMaxHeight(pDC);
			}

			pPanel->RecalcWidths(pDC, nHeight);
			m_nLastCategoryWidth = -1;
		}
	}

	m_nMinWidth = -1;
}

void CMFCRibbonCategory::CleanUpSizes()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->CleanUpSizes();
		pPanel->m_arWidths.RemoveAll();
	}

	m_nLastCategoryWidth = -1;
	m_nMinWidth = -1;
}

int CMFCRibbonCategory::GetMinWidth(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	int nMinWidth = nPanelMarginLeft;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		nMinWidth += pPanel->GetMinWidth(pDC) + nPanelMarginRight;
	}

	return nMinWidth;
}

void CMFCRibbonCategory::OnMouseMove(CPoint point)
{
	ASSERT_VALID(this);

	m_ScrollLeft.OnMouseMove(point);
	m_ScrollRight.OnMouseMove(point);

	if (m_ScrollLeft.IsHighlighted() || m_ScrollRight.IsHighlighted())
	{
		return;
	}

	HighlightPanel(GetPanelFromPoint(point), point);
}

CMFCRibbonBaseElement* CMFCRibbonCategory::HitTest(CPoint point, BOOL bCheckPanelCaption) const
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement* pBtnScroll = HitTestScrollButtons(point);
	if (pBtnScroll != NULL)
	{
		return pBtnScroll;
	}

	CMFCRibbonPanel* pPanel = GetPanelFromPoint(point);
	if (pPanel != NULL)
	{
		ASSERT_VALID(pPanel);
		return pPanel->HitTest(point, bCheckPanelCaption);
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonCategory::HitTestScrollButtons(CPoint point) const
{
	ASSERT_VALID(this);

	if (m_ScrollLeft.GetRect().PtInRect(point))
	{
		return(CMFCRibbonBaseElement*)&m_ScrollLeft;
	}

	if (m_ScrollRight.GetRect().PtInRect(point))
	{
		return(CMFCRibbonBaseElement*)&m_ScrollRight;
	}

	return NULL;
}

int CMFCRibbonCategory::HitTestEx(CPoint point) const
{
	ASSERT_VALID(this);

	CMFCRibbonPanel* pPanel = GetPanelFromPoint(point);
	if (pPanel != NULL)
	{
		ASSERT_VALID(pPanel);
		return pPanel->HitTestEx(point);
	}

	return -1;
}

CMFCRibbonPanel* CMFCRibbonCategory::GetPanelFromPoint(CPoint point) const
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (pPanel->m_rect.PtInRect(point))
		{
			return pPanel;
		}
	}

	return NULL;
}

CMFCRibbonPanel* CMFCRibbonCategory::HighlightPanel(CMFCRibbonPanel* pHLPanel, CPoint point)
{
	ASSERT_VALID(this);

	CMFCRibbonPanel* pPrevHLPanel = NULL;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (pPanel->IsHighlighted())
		{
			if (pHLPanel != pPanel)
			{
				pPanel->Highlight(FALSE, point);
			}

			pPrevHLPanel = pPanel;
		}

		if (pHLPanel == pPanel)
		{
			pPanel->Highlight(TRUE, point);
		}
	}

	if (m_pParentMenuBar != NULL)
	{
		ASSERT_VALID(m_pParentMenuBar);
		m_pParentMenuBar->UpdateWindow();
	}
	else
	{
		ASSERT_VALID(m_pParentRibbonBar);
		m_pParentRibbonBar->UpdateWindow();
	}

	return pPrevHLPanel;
}

void CMFCRibbonCategory::OnCancelMode()
{
	m_bMouseIsPressed = FALSE;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->CancelMode();
	}
}

CMFCRibbonBaseElement* CMFCRibbonCategory::OnLButtonDown(CPoint point)
{
	CMFCRibbonBaseElement* pBtnScroll = HitTestScrollButtons(point);
	if (pBtnScroll != NULL)
	{
		ASSERT_VALID(pBtnScroll);
		pBtnScroll->OnAutoRepeat();

		if (HitTestScrollButtons(point) == pBtnScroll)
		{
			return pBtnScroll;
		}
		else
		{
			return NULL;
		}
	}

	CMFCRibbonPanel* pPanel = GetPanelFromPoint(point);
	if (pPanel == NULL)
	{
		return NULL;
	}

	m_bMouseIsPressed = TRUE;

	ASSERT_VALID(pPanel);
	return pPanel->MouseButtonDown(point);
}

void CMFCRibbonCategory::OnLButtonUp(CPoint point)
{
	m_ScrollLeft.m_bIsHighlighted = FALSE;
	m_ScrollRight.m_bIsHighlighted = FALSE;

	CMFCRibbonPanel* pPanel = GetPanelFromPoint(point);
	if (pPanel == NULL)
	{
		return;
	}

	m_bMouseIsPressed = FALSE;

	ASSERT_VALID(pPanel);
	pPanel->MouseButtonUp(point);
}

void CMFCRibbonCategory::OnUpdateCmdUI(CMFCRibbonCmdUI* pCmdUI, CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->OnUpdateCmdUI(pCmdUI, pTarget, bDisableIfNoHndler);
	}
}

BOOL CMFCRibbonCategory::NotifyControlCommand(BOOL bAccelerator, int nNotifyCode, WPARAM wParam, LPARAM lParam)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (pPanel->NotifyControlCommand(bAccelerator, nNotifyCode, wParam, lParam))
		{
			return TRUE;
		}
	}

	return FALSE;
}

void CMFCRibbonCategory::SetActive(BOOL bIsActive)
{
	ASSERT_VALID(this);

	if (m_bIsActive == bIsActive)
	{
		return;
	}

	if ((m_pParentRibbonBar->m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) != 0)
	{
		m_bIsActive = bIsActive;
		return;
	}

	if (!m_pParentRibbonBar->m_bIsPrintPreview || !GetGlobalData()->IsDwmCompositionEnabled())
	{
		ShowElements();
	}

	m_bIsActive = bIsActive;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->OnShow(bIsActive);
	}

	m_ActiveTime = bIsActive ? clock() :(clock_t)-1;
}

void CMFCRibbonCategory::ShowElements(BOOL bShow)
{
	ASSERT_VALID(this);

	GetParentRibbonBar()->m_dwHideFlags = bShow ? 0 : AFX_RIBBONBAR_HIDE_ELEMENTS;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->OnShow(bShow);
	}

	GetParentRibbonBar()->GetParentFrame()->RecalcLayout();
}

CMFCRibbonBaseElement* CMFCRibbonCategory::FindByID(UINT uiCmdID, BOOL bVisibleOnly) const
{
	ASSERT_VALID(this);

	int i = 0;

	if (!bVisibleOnly)
	{
		for (i = 0; i < m_arElements.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pElem = m_arElements [i];
			ASSERT_VALID(pElem);

			if (pElem->GetID() == uiCmdID)
			{
				return pElem;
			}
		}
	}

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pElem = pPanel->FindByID(uiCmdID);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonCategory::FindByData(DWORD_PTR dwData, BOOL bVisibleOnly) const
{
	ASSERT_VALID(this);

	int i = 0;

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pElem = pPanel->FindByData(dwData);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	if (!bVisibleOnly)
	{
		for (i = 0; i < m_arElements.GetSize(); i++)
		{
			CMFCRibbonBaseElement* pElem = m_arElements [i];
			ASSERT_VALID(pElem);

			if (pElem->GetData() == dwData)
			{
				return pElem;
			}
		}
	}

	return NULL;
}

void CMFCRibbonCategory::GetElementsByID(UINT uiCmdID, CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arButtons)
{
	ASSERT_VALID(this);

	int i = 0;

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->GetElementsByID(uiCmdID, arButtons);
	}

	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = m_arElements [i];
		ASSERT_VALID(pElem);

		if (pElem->GetID() == uiCmdID)
		{
			arButtons.Add(pElem);
		}
	}
}

void CMFCRibbonCategory::GetItemIDsList(CList<UINT,UINT>& lstItems, BOOL bHiddenOnly) const
{
	ASSERT_VALID(this);

	int i = 0;

	if (!bHiddenOnly)
	{
		for (i = 0; i < m_arPanels.GetSize(); i++)
		{
			CMFCRibbonPanel* pPanel = m_arPanels [i];
			ASSERT_VALID(pPanel);

			pPanel->GetItemIDsList(lstItems);
		}
	}

	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = m_arElements [i];
		ASSERT_VALID(pElem);

		pElem->GetItemIDsList(lstItems);
	}
}

CMFCRibbonPanel* CMFCRibbonCategory::FindPanelWithElem(const CMFCRibbonBaseElement* pElement)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElement);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		if (pPanel->HasElement(pElement))
		{
			return pPanel;
		}
	}

	return NULL;
}

void CMFCRibbonCategory::AddHidden(CMFCRibbonBaseElement* pElement)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElement);

	pElement->SetParentCategory(this);
	m_arElements.Add(pElement);
}

BOOL CMFCRibbonCategory::OnDrawImage(CDC* pDC, CRect rect, CMFCRibbonBaseElement* pElement, BOOL bIsLargeImage, BOOL nImageIndex, BOOL bCenter)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElement);

	CMFCToolBarImages& image = bIsLargeImage ? m_LargeImages : m_SmallImages;

	if (nImageIndex >= image.GetCount())
	{
		return FALSE;
	}

	CAfxDrawState ds;

	CPoint ptImage = rect.TopLeft();
	const CSize sizeImage = GetImageSize(bIsLargeImage);

	if (bCenter)
	{
		ptImage.Offset(max(0, (rect.Width() - sizeImage.cx) / 2), max(0, (rect.Height() - sizeImage.cy) / 2));
	}

	image.SetTransparentColor(GetGlobalData()->clrBtnFace);
	image.PrepareDrawImage(ds, sizeImage);

	image.Draw(pDC, ptImage.x, ptImage.y, nImageIndex, FALSE, pElement->IsDisabled());

	image.EndDrawImage(ds);
	return TRUE;
}

CSize CMFCRibbonCategory::GetImageSize(BOOL bIsLargeImage) const
{
	ASSERT_VALID(this);

	const CMFCToolBarImages& image = bIsLargeImage ? m_LargeImages : m_SmallImages;
	return image.GetImageSize();
}

void CMFCRibbonCategory::GetElements(CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
{
	ASSERT_VALID(this);

	arElements.RemoveAll();

	int i = 0;

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->GetElements(arElements);
	}

	// Add hidden elements:
	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = m_arElements [i];
		ASSERT_VALID(pElem);

		arElements.Add(pElem);
	}
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetDroppedDown()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pElem = pPanel->GetDroppedDown();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

void CMFCRibbonCategory::ShowFloating(CRect rectFloating)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pParentRibbonBar);

	if ((m_pParentRibbonBar->m_dwHideFlags & AFX_RIBBONBAR_HIDE_ELEMENTS) == 0)
	{
		ASSERT(FALSE);
		return;
	}

	const BOOL bIsRTL = (m_pParentRibbonBar->GetExStyle() & WS_EX_LAYOUTRTL);

	CMFCRibbonPanelMenu* pMenu = new CMFCRibbonPanelMenu(this, rectFloating.Size());

	m_Tab.SetDroppedDown(pMenu);

	pMenu->Create(m_pParentRibbonBar, bIsRTL ? rectFloating.right : rectFloating.left, rectFloating.top, (HMENU) NULL);
}

void CMFCRibbonCategory::CopyFrom(CMFCRibbonCategory& src)
{
	ASSERT_VALID(this);

	int i = 0;

	m_strName = src.m_strName;
	m_bIsActive = src.m_bIsActive;
	m_bIsVisible = src.m_bIsVisible;

	for (i = 0; i < src.m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanelSrc = src.m_arPanels [i];
		ASSERT_VALID(pPanelSrc);

		CMFCRibbonPanel* pPanel = (CMFCRibbonPanel*) pPanelSrc->GetRuntimeClass()->CreateObject();
		ASSERT_VALID(pPanel);

		pPanel->CopyFrom(*pPanelSrc);

		pPanel->m_btnDefault.CopyFrom(pPanelSrc->m_btnDefault);
		pPanel->m_btnDefault.SetOriginal(&pPanelSrc->m_btnDefault);

		m_arPanels.Add(pPanel);
	}

	m_pParentRibbonBar = src.m_pParentRibbonBar;
	m_rect = src.m_rect;
	m_Tab.CopyFrom(src.m_Tab);

	m_dwData = src.m_dwData;
	m_uiContextID = src.m_uiContextID;
	m_pParentMenuBar = src.m_pParentMenuBar;

	src.m_SmallImages.CopyTo(m_SmallImages);
	src.m_LargeImages.CopyTo(m_LargeImages);

	m_arCollapseOrder.RemoveAll();
	m_arCollapseOrder.Copy(src.m_arCollapseOrder);

	m_ScrollLeft.CopyFrom(src.m_ScrollLeft);
	m_ScrollLeft.m_pParent = this;
	m_ScrollRight.CopyFrom(src.m_ScrollRight);
	m_ScrollRight.m_pParent = this;

	m_uiSmallImagesResID = src.m_uiSmallImagesResID;
	m_uiLargeImagesResID = src.m_uiLargeImagesResID;
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetParentButton() const
{
	ASSERT_VALID(this);

	if (m_pParentMenuBar == NULL)
	{
		return NULL;
	}

	return((CMFCPopupMenu*)m_pParentMenuBar->GetParent())->GetParentRibbonElement();
}

void CMFCRibbonCategory::SetKeys(LPCTSTR lpszKeys)
{
	ASSERT_VALID(this);
	ENSURE(lpszKeys != NULL);

	m_Tab.SetKeys(lpszKeys);
}

void CMFCRibbonCategory::SetName(LPCTSTR lpszName)
{
	ASSERT_VALID(this);

	m_strName = lpszName == NULL ? _T("") : lpszName;

	// Remove '&' characters and build key string:
	CString strKeys;

	for (int i = 0; i < m_strName.GetLength(); i++)
	{
		if (m_strName [i] == _T('&'))
		{
			m_strName.Delete(i);

			if (i < m_strName.GetLength())
			{
				strKeys += m_strName [i];
			}
		}
	}

	m_Tab.SetKeys(strKeys);
}

void CMFCRibbonCategory::OnRTLChanged(BOOL bIsRTL)
{
	ASSERT_VALID(this);

	int i = 0;

	for (i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->OnRTLChanged(bIsRTL);
	}

	for (i = 0; i < m_arElements.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = m_arElements [i];
		ASSERT_VALID(pElem);

		pElem->OnRTLChanged(bIsRTL);
	}

	m_nLastCategoryWidth = -1;
}

int CMFCRibbonCategory::GetTextTopLine() const
{
	ASSERT_VALID(this);

	const CSize sizeImageLarge = GetImageSize(TRUE);
	if (sizeImageLarge == CSize(0, 0))
	{
		return -1;
	}

	return sizeImageLarge.cy + 5;
}

void CMFCRibbonCategory::SetCollapseOrder(const CArray<int, int>& arCollapseOrder)
{
	ASSERT_VALID(this);

	m_arCollapseOrder.RemoveAll();
	m_arCollapseOrder.Copy(arCollapseOrder);
}

BOOL CMFCRibbonCategory::SetPanelsLayout(int nWidth)
{
	int nTotalWidth = 0;

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->m_bForceCollpapse = FALSE;

		if (pPanel->m_nCurrWidthIndex == pPanel->m_arWidths.GetSize() - 1 && pPanel->m_arWidths.GetSize() > 1)
		{
			pPanel->m_bForceCollpapse = TRUE;
		}

		const int nCurrPanelWidth = pPanel->m_arWidths [pPanel->m_nCurrWidthIndex] + 2 * pPanel->m_nXMargin;

		nTotalWidth += nCurrPanelWidth + nPanelMarginRight;

		if (nTotalWidth > nWidth)
		{
			return FALSE;
		}
	}

	return TRUE;
}

void CMFCRibbonCategory::ResetPanelsLayout()
{
	// all panels in max. width:
	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->m_nCurrWidthIndex = 0;
		pPanel->m_bTruncateCaption = FALSE;
	}

	m_nScrollOffset = 0;
}

BOOL CMFCRibbonCategory::OnScrollHorz(BOOL bScrollLeft, int nScrollOffset/* = 0*/)
{
	ASSERT_VALID(this);

	const int nPrevScrollOffset = m_nScrollOffset;

	if (nScrollOffset == 0)
	{
		nScrollOffset = 50;
	}

	if (bScrollLeft)
	{
		m_nScrollOffset -= nScrollOffset;
	}
	else
	{
		m_nScrollOffset += nScrollOffset;
	}

	m_nScrollOffset = min(m_nMinWidth - m_rect.Width(), max(0, m_nScrollOffset));

	CMFCRibbonBar* pRibbonBar = GetParentRibbonBar();
	ASSERT_VALID(pRibbonBar);

	CClientDC dc(pRibbonBar);

	CFont* pOldFont = dc.SelectObject(pRibbonBar->GetFont());
	ASSERT(pOldFont != NULL);

	ReposPanels(&dc);

	dc.SelectObject(pOldFont);

	UpdateScrollButtons();

	if (m_pParentMenuBar != NULL)
	{
		ASSERT_VALID(m_pParentMenuBar);
		m_pParentMenuBar->RedrawWindow();
	}
	else
	{
		pRibbonBar->RedrawWindow(m_rect);
	}

	return nPrevScrollOffset != m_nScrollOffset;
}

void CMFCRibbonCategory::EnsureVisible(CMFCRibbonButton* pButton)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pButton);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	CRect rectClient = m_rect;
	rectClient.DeflateRect(nPanelMarginLeft * 2, nPanelMarginTop, 
		nPanelMarginRight * 2, nPanelMarginBottom);

	CRect rectButton = pButton->GetRect();
	if (rectButton.IsRectEmpty())
	{
		CMFCRibbonPanel* pParentPanel = pButton->GetParentPanel();
		if (pParentPanel == NULL)
		{
			return;
		}

		ASSERT_VALID(pParentPanel);
		ASSERT(pParentPanel->GetRect().IsRectEmpty());

		int nPanelIndex = -1;
		int nFirstVisiblePanel = -1;
		int nLastVisiblePanel = -1;
		int i = 0;

		for (i = 0; i < m_arPanels.GetSize(); i++)
		{
			CMFCRibbonPanel* pPanel = m_arPanels [i];
			ASSERT_VALID(pPanel);

			if (pPanel == pParentPanel)
			{
				nPanelIndex = i;
			}

			if (!pPanel->GetRect().IsRectEmpty())
			{
				if (nFirstVisiblePanel < 0)
				{
					nFirstVisiblePanel = i;
				}

				nLastVisiblePanel = i;
			}
		}

		if (nPanelIndex == -1 || nFirstVisiblePanel == -1 || nLastVisiblePanel == -1)
		{
			return;
		}

		if (nPanelIndex < nFirstVisiblePanel)
		{
			while (OnScrollHorz(TRUE))
			{
				if (!pParentPanel->GetRect().IsRectEmpty() &&
					pParentPanel->GetRect().left >= rectClient.left)
				{
					break;
				}
			}
		}
		else if (nPanelIndex > nLastVisiblePanel)
		{
			while (OnScrollHorz(FALSE))
			{
				if (!pParentPanel->GetRect().IsRectEmpty() &&
					pParentPanel->GetRect().right <= rectClient.right)
				{
					break;
				}
			}
		}

		return;
	}

	if (rectButton.left < m_rect.left - nPanelMarginRight)
	{
		OnScrollHorz(TRUE, rectClient.left - rectButton.left);
	}
	else if (rectButton.right > m_rect.right + nPanelMarginRight)
	{
		OnScrollHorz(FALSE, rectButton.right - rectClient.right);
	}
}

void CMFCRibbonCategory::NormalizeFloatingRect(CMFCRibbonBar* pRibbonBar, CRect& rectCategory)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pRibbonBar);

	CRect rectRibbon;
	pRibbonBar->GetWindowRect(rectRibbon);

	CRect rectScreen;

	MONITORINFO mi;
	mi.cbSize = sizeof(MONITORINFO);
	if (GetMonitorInfo(MonitorFromPoint(rectRibbon.TopLeft(), MONITOR_DEFAULTTONEAREST), &mi))
	{
		rectScreen = mi.rcWork;
	}
	else
	{
		::SystemParametersInfo(SPI_GETWORKAREA, 0, &rectScreen, 0);
	}

	rectCategory.right = min(rectCategory.right, rectScreen.right);
	rectCategory.left = max(rectCategory.left, rectScreen.left);
}

BOOL CMFCRibbonCategory::IsWindows7Look() const
{
	CMFCRibbonBar* pBar = GetParentRibbonBar();
	if (pBar == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return pBar->IsWindows7Look();
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetFirstVisibleElement() const
{
	ASSERT_VALID(this);

	if (m_arPanels.GetSize() == 0)
	{
		return NULL;
	}

	//------------------------------------------------------
	// If the category is scrolled right, scroll left first:
	//------------------------------------------------------
	if (m_nScrollOffset > 0)
	{
		((CMFCRibbonCategory*) this)->OnScrollHorz(TRUE, m_nScrollOffset);
	}

	CMFCRibbonPanel* pPanel = m_arPanels [0];
	ASSERT_VALID(pPanel);

	if (pPanel->IsCollapsed())
	{
		return &pPanel->GetDefaultButton();
	}

	return pPanel->GetElement(0);
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetLastVisibleElement() const
{
	ASSERT_VALID(this);

	if (m_arPanels.GetSize() == 0)
	{
		return NULL;
	}

	//--------------------
	// Scroll right first:
	//--------------------
	while (!m_ScrollRight.GetRect().IsRectEmpty())
	{
		((CMFCRibbonCategory*) this)->OnScrollHorz(FALSE);
	}

	CMFCRibbonPanel* pPanel = m_arPanels [m_arPanels.GetSize() - 1];
	ASSERT_VALID(pPanel);

	if (pPanel->IsCollapsed())
	{
		return &pPanel->GetDefaultButton();
	}

	if (pPanel->GetCount() == 0)
	{
		return NULL;
	}

	return pPanel->GetElement(pPanel->GetCount() - 1);
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetFocused()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pElem = pPanel->GetFocused();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonCategory::GetHighlighted()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pElem = pPanel->GetHighlighted();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

void CMFCRibbonCategory::GetVisibleElements(CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arButtons)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels [i];
		ASSERT_VALID(pPanel);

		pPanel->GetVisibleElements(arButtons);
	}
}

BOOL CMFCRibbonCategory::OnKey(UINT nChar)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement* pFocused = NULL;
	CMFCRibbonBaseElement* pFocusedNew = NULL;

	switch (nChar)
	{
	case VK_LEFT:
	case VK_RIGHT:
	case VK_DOWN:
	case VK_UP:
	case VK_TAB:
		{
			CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arElems;
			GetVisibleElements(arElems);

			if (arElems.GetSize() == 0)
			{
				return FALSE;
			}

			if ((pFocused = GetFocused()) == NULL)
			{
				for (int i = 0; i < arElems.GetSize(); i++)
				{
					CMFCRibbonBaseElement* pElem = arElems [i];
					ASSERT_VALID(pElem);

					if (pElem->IsTabStop() && !pElem->GetRect().IsRectEmpty())
					{
						pFocusedNew = pElem;
						break;
					}
				}
			}
			else
			{
				ASSERT_VALID(pFocused);

				int nScroll = 0;

				BOOL bIsScrollLeftAvailable = !m_ScrollLeft.GetRect().IsRectEmpty();
				BOOL bIsScrollRightAvailable = !m_ScrollRight.GetRect().IsRectEmpty();

				pFocusedNew = CMFCRibbonBar::FindNextFocusedElement(
					nChar, arElems, m_rect, pFocused,
					bIsScrollLeftAvailable, bIsScrollRightAvailable, nScroll);

				if (nScroll != 0)
				{
					switch (nScroll)
					{
					case -2:
						pFocusedNew = GetFirstVisibleElement();
						break;

					case 2:
						pFocusedNew = GetLastVisibleElement();
						break;

					case -1:
					case 1:
						OnScrollHorz(nScroll < 0);
					}
				}
			}
		}
		break;

	case VK_RETURN:
	case VK_SPACE:
		if ((pFocused = GetFocused()) != NULL)
		{
			ASSERT_VALID(pFocused);
			pFocused->OnKey(FALSE);

			return TRUE;
		}
		return FALSE;;

	default:
		return FALSE;
	}

	if (pFocusedNew == pFocused)
	{
		return TRUE;
	}

	if (pFocusedNew == NULL)
	{
		return FALSE;
	}

	if (m_pParentRibbonBar != NULL)
	{
		ASSERT_VALID(m_pParentRibbonBar);
		m_pParentRibbonBar->DeactivateKeyboardFocus(FALSE);
	}

	if (pFocused != NULL)
	{
		pFocused->m_bIsHighlighted = pFocused->m_bIsFocused = FALSE;
		pFocused->OnSetFocus(FALSE);
		pFocused->Redraw();
	}

	ASSERT_VALID(pFocusedNew);

	pFocusedNew->m_bIsFocused = TRUE;
	pFocusedNew->OnSetFocus(TRUE);
	pFocusedNew->Redraw();

	return TRUE;
}

BOOL CMFCRibbonCategory::OnSetAccData (long lVal)
{
	ASSERT_VALID(this);

	m_AccData.Clear();

	int nIndex = (int)lVal - 1;

	if (nIndex < 0 || nIndex >= m_arPanels.GetSize())
	{
		return FALSE;
	}

	ASSERT_VALID(m_arPanels[nIndex]);
	return m_arPanels[nIndex]->SetACCData(m_pParentRibbonBar, m_AccData);
}

HRESULT CMFCRibbonCategory::get_accParent(IDispatch **ppdispParent)
{
	if (!ppdispParent)
	{
		return E_INVALIDARG;
	}

	*ppdispParent = NULL;

	CMFCRibbonBar* pRibbonBar = GetParentRibbonBar();
	if (pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	ASSERT_VALID (pRibbonBar);

	LPDISPATCH lpDispatch = pRibbonBar->GetAccessibleDispatch();
	if (lpDispatch != NULL)
	{
		*ppdispParent =  lpDispatch;
		return S_OK;
	}

	return S_OK;
}

HRESULT CMFCRibbonCategory::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	*pcountChildren = (long)m_arPanels.GetSize(); 
	return S_OK;
}

HRESULT CMFCRibbonCategory::get_accChild(VARIANT varChild, IDispatch **ppdispChild)
{
	if (!ppdispChild)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4)
	{
		int nIndex = varChild.lVal -1;
		CMFCRibbonPanel* pPanel = m_arPanels[nIndex];
		if (pPanel == NULL)
		{
			return S_FALSE;
		}
		
		ASSERT_VALID(pPanel);

		*ppdispChild = pPanel->GetIDispatch(TRUE);
		if (*ppdispChild)
		{
			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CMFCRibbonCategory::accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild)
{
	if (!pxLeft || !pyTop || !pcxWidth || !pcyHeight)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF && m_pParentRibbonBar->GetSafeHwnd() != NULL)
	{	
		CRect panelRect = m_rect;
		m_pParentRibbonBar->ClientToScreen(&panelRect);

		*pxLeft = panelRect.left;
		*pyTop = panelRect.top;
		*pcxWidth = panelRect.Width();
		*pcyHeight = panelRect.Height();

		return S_OK;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);

		*pxLeft = m_AccData.m_rectAccLocation.left;
		*pyTop = m_AccData.m_rectAccLocation.top;
		*pcxWidth = m_AccData.m_rectAccLocation.Width();
		*pcyHeight = m_AccData.m_rectAccLocation.Height();
	}

	return S_OK;
}

HRESULT CMFCRibbonCategory::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

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
			pvarEndUpAt->lVal = (int)m_arPanels.GetSize();
			return S_OK;
		}
		break;

	case NAVDIR_NEXT:   
	case NAVDIR_RIGHT:
		if (varStart.lVal != CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = varStart.lVal + 1;

			if (pvarEndUpAt->lVal > (int)m_arPanels.GetSize())
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
		else if (m_pParentRibbonBar->GetSafeHwnd() != NULL)
		{
			int nCount = m_pParentRibbonBar->m_TabElements.GetCount();
			if (nCount > 0)
			{
				CMFCRibbonBaseElement* pTabElement = m_pParentRibbonBar->m_TabElements.GetButton(nCount-1);
				if (pTabElement != NULL)
				{
					ASSERT_VALID(pTabElement);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pTabElement->GetIDispatch(TRUE);

					return S_OK;
				}
			}
			else if (m_pParentRibbonBar->GetTabs() != NULL)
			{
				CMFCRibbonTabsGroup* pTabs = m_pParentRibbonBar->GetTabs();
				if (pTabs != NULL)
				{
					ASSERT_VALID(pTabs);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pTabs->GetIDispatch(TRUE);

					return S_OK;
				}
			}
		}
		break;
	}

	return S_FALSE;
}

HRESULT CMFCRibbonCategory::accHitTest(long xLeft, long yTop, VARIANT *pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	if (m_pParentRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	pvarChild->vt = VT_I4;
	pvarChild->lVal = CHILDID_SELF;

	CPoint pt(xLeft, yTop);
	m_pParentRibbonBar->ScreenToClient(&pt);

	for (int i = 0; i < m_arPanels.GetSize(); i++)
	{
		CMFCRibbonPanel* pPanel = m_arPanels[i];
		if (pPanel == NULL)
		{
			continue;
		}

		ASSERT_VALID(pPanel);

		if (pPanel->GetRect().PtInRect(pt))
		{
			IDispatch* pDispatch = pPanel->GetIDispatch(TRUE);
			if (pDispatch)
			{
				pPanel->SetACCData(m_pParentRibbonBar, m_AccData);

				pvarChild->vt = VT_DISPATCH;
				pvarChild->pdispVal = pDispatch;

				return S_OK;
			}
		}
	}

	return S_FALSE;
}

BOOL CMFCRibbonCategory::SetACCData(CWnd* /*pParent*/, CAccessibilityData& data)
{
	ASSERT_VALID(this);

	data.m_strAccName = m_strName;
	data.m_nAccRole = ROLE_SYSTEM_TOOLBAR;
	data.m_strAccValue = _T("Group");
	data.m_rectAccLocation = GetRect();

	if (m_pParentRibbonBar->GetSafeHwnd() != NULL)
	{
		m_pParentRibbonBar->ClientToScreen(&data.m_rectAccLocation);
	}

	data.m_bAccState = 0;
	return TRUE;
}
