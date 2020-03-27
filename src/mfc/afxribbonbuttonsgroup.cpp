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
#include "afxglobals.h"
#include "afxribbonbuttonsgroup.h"
#include "afxvisualmanager.h"
#include "afxribbonbar.h"
#include "afxribbonstatusbar.h"
#include "afxribboncategory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCRibbonButtonsGroup, CMFCRibbonBaseElement)

// Construction/Destruction
CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup()
{
}

CMFCRibbonButtonsGroup::CMFCRibbonButtonsGroup(CMFCRibbonBaseElement* pButton)
{
	AddButton(pButton);
}

CMFCRibbonButtonsGroup::~CMFCRibbonButtonsGroup()
{
	RemoveAll();
}

void CMFCRibbonButtonsGroup::AddButton(CMFCRibbonBaseElement* pButton)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pButton);

	pButton->SetParentCategory(m_pParent);
	pButton->m_pParentGroup = this;

	m_arButtons.Add(pButton);
}

void CMFCRibbonButtonsGroup::AddButtons(const CList<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& lstButtons)
{
	ASSERT_VALID(this);

	for (POSITION pos = lstButtons.GetHeadPosition(); pos != NULL;)
	{
		AddButton(lstButtons.GetNext(pos));
	}
}

void CMFCRibbonButtonsGroup::RemoveAll()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		delete m_arButtons [i];
	}

	m_arButtons.RemoveAll();
}

void CMFCRibbonButtonsGroup::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	// Fill group background:
	COLORREF clrText = CMFCVisualManager::GetInstance()->OnDrawRibbonButtonsGroup(pDC, this, m_rect);
	COLORREF clrTextOld = (COLORREF)-1;
	if (clrText != (COLORREF)-1)
	{
		clrTextOld = pDC->SetTextColor(clrText);
	}

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->m_rect.IsRectEmpty())
		{
			continue;
		}

		CString strText = pButton->m_strText;

		if (pButton->GetImageSize(CMFCRibbonBaseElement::RibbonImageSmall) != CSize(0, 0))
		{
			pButton->m_strText.Empty();
		}

		pButton->OnDraw(pDC);

		pButton->m_strText = strText;
	}

	if (clrTextOld != (COLORREF)-1)
	{
		pDC->SetTextColor(clrTextOld);
	}
}

CSize CMFCRibbonButtonsGroup::GetRegularSize(CDC* pDC)
{
	ASSERT_VALID(this);

	const BOOL bIsOnStatusBar = DYNAMIC_DOWNCAST(CMFCRibbonStatusBar, GetParentRibbonBar()) != NULL;

	CSize size(0, 0);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->SetInitialMode(TRUE);
		pButton->OnCalcTextSize(pDC);

		CSize sizeButton = pButton->GetSize(pDC);

		size.cx += sizeButton.cx;
		size.cy = max(size.cy, sizeButton.cy);
	}

	if (bIsOnStatusBar)
	{
		size.cx += 2;
	}

	return size;
}

void CMFCRibbonButtonsGroup::OnUpdateCmdUI(CMFCRibbonCmdUI* pCmdUI, CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->OnUpdateCmdUI(pCmdUI, pTarget, bDisableIfNoHndler);
	}
}

void CMFCRibbonButtonsGroup::OnAfterChangeRect(CDC* pDC)
{
	ASSERT_VALID(this);

	BOOL bIsFirst = TRUE;

	const BOOL bIsOnStatusBar = DYNAMIC_DOWNCAST(CMFCRibbonStatusBar, GetParentRibbonBar()) != NULL;
	const BOOL bIsQATOnBottom = IsQuickAccessToolBar() && !m_pRibbonBar->IsQuickAccessToolbarOnTop();

	const int nMarginX = IsQuickAccessToolBar() ? 2 : 0;
	const int nMarginTop = bIsQATOnBottom ? 2 : bIsOnStatusBar ? 1 : 0;
	const int nMarginBottom = IsQuickAccessToolBar() || bIsOnStatusBar ? 1 : 0;

	const int nButtonHeight = m_rect.Height() - nMarginTop - nMarginBottom;

	CRect rectGroup = m_rect;

	int x = rectGroup.left + nMarginX;

	int nCustomizeButtonIndex = -1;

	if (IsQuickAccessToolBar() && m_arButtons.GetSize() > 0)
	{
		// Last button is customize - it always visible.
		// Leave space for it:
		nCustomizeButtonIndex = (int) m_arButtons.GetSize() - 1;

		CMFCRibbonBaseElement* pButton = m_arButtons [nCustomizeButtonIndex];
		ASSERT_VALID(pButton);

		CSize sizeButton = pButton->GetSize(pDC);
		rectGroup.right -= sizeButton.cx;
	}

	BOOL bHasHiddenItems = FALSE;

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->m_bShowGroupBorder = TRUE;

		if (pButton->m_pRibbonBar != NULL && !pButton->m_pRibbonBar->IsShowGroupBorder(this))
		{
			pButton->m_bShowGroupBorder = FALSE;
		}

		if (m_rect.IsRectEmpty())
		{
			pButton->m_rect = CRect(0, 0, 0, 0);
			pButton->OnAfterChangeRect(pDC);
			continue;
		}

		BOOL bIsLast = i == m_arButtons.GetSize() - 1;

		pButton->SetParentCategory(m_pParent);

		CSize sizeButton = pButton->GetSize(pDC);
		sizeButton.cy = i != nCustomizeButtonIndex ? nButtonHeight : nButtonHeight - 1;

		const int y = i != nCustomizeButtonIndex ? rectGroup.top + nMarginTop : rectGroup.top;

		pButton->m_rect = CRect(CPoint(x, y), sizeButton);

		const BOOL bIsHiddenSeparator = bHasHiddenItems && pButton->IsSeparator();

		if ((pButton->m_rect.right > rectGroup.right || bIsHiddenSeparator) && i != nCustomizeButtonIndex)
		{
			pButton->m_rect = CRect(0, 0, 0, 0);
			bHasHiddenItems = TRUE;
		}
		else
		{
			x += sizeButton.cx;
		}

		pButton->OnAfterChangeRect(pDC);

		if (bIsFirst && bIsLast)
		{
			pButton->m_Location = RibbonElementSingleInGroup;
		}
		else if (bIsFirst)
		{
			pButton->m_Location = RibbonElementFirstInGroup;
		}
		else if (bIsLast)
		{
			pButton->m_Location = RibbonElementLastInGroup;
		}
		else
		{
			pButton->m_Location = RibbonElementMiddleInGroup;
		}

		bIsFirst = FALSE;
	}
}

void CMFCRibbonButtonsGroup::OnShow(BOOL bShow)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->OnShow(bShow);
	}
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::HitTest(CPoint point)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->m_rect.PtInRect(point))
		{
			return pButton;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::Find(const CMFCRibbonBaseElement* pElement)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->Find(pElement);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::FindByID(UINT uiCmdID)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->FindByID(uiCmdID);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::FindByData(DWORD_PTR dwData)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->FindByData(dwData);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::FindByOriginal(CMFCRibbonBaseElement* pOriginal)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pOriginal);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->FindByOriginal(pOriginal);
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetPressed()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->GetPressed();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetDroppedDown()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->GetDroppedDown();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetHighlighted()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->GetHighlighted();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}

	return NULL;
}

BOOL CMFCRibbonButtonsGroup::ReplaceByID(UINT uiCmdID, CMFCRibbonBaseElement* pElem)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElem);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->GetID() == uiCmdID)
		{
			pElem->CopyFrom(*pButton);
			m_arButtons [i] = pElem;

			delete pButton;
			return TRUE;
		}

		if (pButton->ReplaceByID(uiCmdID, pElem))
		{
			return TRUE;
		}
	}

	return FALSE;
}

void CMFCRibbonButtonsGroup::SetImages(CMFCToolBarImages* pImages, CMFCToolBarImages* pHotImages, CMFCToolBarImages* pDisabledImages)
{
	ASSERT_VALID(this);

	if (pImages != NULL)
	{
		pImages->CopyTo(m_Images);
	}

	if (pHotImages != NULL)
	{
		pHotImages->CopyTo(m_HotImages);
	}

	if (pDisabledImages != NULL)
	{
		pDisabledImages->CopyTo(m_DisabledImages);
	}

	const CSize sizeImage = m_Images.GetImageSize();

	const double dblScale = GetGlobalData()->GetRibbonImageScale();
	if (dblScale != 1.0 && sizeImage == CSize(16, 16))
	{
		m_Images.SetTransparentColor(GetGlobalData()->clrBtnFace);
		m_Images.SmoothResize(dblScale);

		m_HotImages.SetTransparentColor(GetGlobalData()->clrBtnFace);
		m_HotImages.SmoothResize(dblScale);

		m_DisabledImages.SetTransparentColor(GetGlobalData()->clrBtnFace);
		m_DisabledImages.SmoothResize(dblScale);
	}
}

void CMFCRibbonButtonsGroup::OnDrawImage(CDC* pDC, CRect rectImage,  CMFCRibbonBaseElement* pButton, int nImageIndex)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	ASSERT_VALID(pButton);

	CMFCToolBarImages& image = (pButton->IsDisabled() && m_DisabledImages.GetCount() != 0) ? m_DisabledImages :
		(pButton->IsHighlighted() && m_HotImages.GetCount() != 0) ? m_HotImages : m_Images;

	if (image.GetCount() <= 0)
	{
		return;
	}

	CAfxDrawState ds;

	CPoint ptImage = rectImage.TopLeft();
	ptImage.x++;

	image.SetTransparentColor(GetGlobalData()->clrBtnFace);
	image.PrepareDrawImage(ds);

	image.SetTransparentColor(GetGlobalData()->clrBtnFace);
	image.Draw(pDC, ptImage.x, ptImage.y, nImageIndex, FALSE, pButton->IsDisabled() && m_DisabledImages.GetCount() == 0);

	image.EndDrawImage(ds);
}

void CMFCRibbonButtonsGroup::CopyFrom(const CMFCRibbonBaseElement& s)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::CopyFrom(s);
	CMFCRibbonButtonsGroup& src = (CMFCRibbonButtonsGroup&) s;

	RemoveAll();

	for (int i = 0; i < src.m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pSrcElem = src.m_arButtons [i];
		ASSERT_VALID(pSrcElem);

		CMFCRibbonBaseElement* pElem = (CMFCRibbonBaseElement*) pSrcElem->GetRuntimeClass()->CreateObject();
		ASSERT_VALID(pElem);

		pElem->CopyFrom(*pSrcElem);

		m_arButtons.Add(pElem);
	}

	src.m_Images.CopyTo(m_Images);
	src.m_HotImages.CopyTo(m_HotImages);
	src.m_DisabledImages.CopyTo(m_DisabledImages);
}

void CMFCRibbonButtonsGroup::SetParentMenu(CMFCRibbonPanelMenuBar* pMenuBar)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::SetParentMenu(pMenuBar);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->SetParentMenu(pMenuBar);
	}
}

void CMFCRibbonButtonsGroup::SetOriginal(CMFCRibbonBaseElement* pOriginal)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::SetOriginal(pOriginal);
	CMFCRibbonButtonsGroup* pOriginalGroup = DYNAMIC_DOWNCAST(CMFCRibbonButtonsGroup, pOriginal);

	if (pOriginalGroup == NULL)
	{
		return;
	}

	ASSERT_VALID(pOriginalGroup);

	if (pOriginalGroup->m_arButtons.GetSize() != m_arButtons.GetSize())
	{
		ASSERT(FALSE);
		return;
	}

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->SetOriginal(pOriginalGroup->m_arButtons [i]);
	}
}

void CMFCRibbonButtonsGroup::GetItemIDsList(CList<UINT,UINT>& lstItems) const
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->GetItemIDsList(lstItems);
	}
}

void CMFCRibbonButtonsGroup::GetElementsByID(UINT uiCmdID, CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->GetElementsByID(uiCmdID, arElements);
	}
}

int CMFCRibbonButtonsGroup::AddToListBox(CMFCRibbonCommandsListBox* pWndListBox, BOOL bDeep)
{
	ASSERT_VALID(this);

	int nIndex = -1;

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		nIndex = pButton->AddToListBox(pWndListBox, bDeep);
	}

	return nIndex;
}

void CMFCRibbonButtonsGroup::CleanUpSizes()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->CleanUpSizes();
	}
}

void CMFCRibbonButtonsGroup::SetParentRibbonBar(CMFCRibbonBar* pRibbonBar)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::SetParentRibbonBar(pRibbonBar);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->SetParentRibbonBar(pRibbonBar);
	}
}

void CMFCRibbonButtonsGroup::SetParentCategory(CMFCRibbonCategory* pCategory)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::SetParentCategory(pCategory);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->SetParentCategory(pCategory);
	}
}

void CMFCRibbonButtonsGroup::AddToKeyList(CArray<CMFCRibbonKeyTip*,CMFCRibbonKeyTip*>& arElems)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->AddToKeyList(arElems);
	}
}

void CMFCRibbonButtonsGroup::OnRTLChanged(BOOL bIsRTL)
{
	ASSERT_VALID(this);

	CMFCRibbonBaseElement::OnRTLChanged(bIsRTL);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->OnRTLChanged(bIsRTL);
	}
}

const CSize CMFCRibbonButtonsGroup::GetImageSize() const
{
	ASSERT_VALID(this);

	if (m_Images.GetCount() <= 0)
	{
		return CSize(0, 0);
	}

	return m_Images.GetImageSize();
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetFocused()
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pElem = pButton->GetFocused();
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);
			return pElem;
		}
	}
	
	return NULL;
}

void CMFCRibbonButtonsGroup::GetVisibleElements(CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
{
	ASSERT_VALID(this);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		pButton->GetVisibleElements(arElements);
	}
}


CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetFirstTabStop()
{
	ASSERT_VALID(this);

	for (int i = 0; i < (int)m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pTabStop = pButton->GetFirstTabStop();
		if (pTabStop != NULL)
		{
			return pTabStop;
		}
	}

	return NULL;
}

CMFCRibbonBaseElement* CMFCRibbonButtonsGroup::GetLastTabStop()
{
	ASSERT_VALID(this);

	for (int i = (int)m_arButtons.GetSize() - 1; i >= 0; i--)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CMFCRibbonBaseElement* pTabStop = pButton->GetLastTabStop();
		if (pTabStop != NULL)
		{
			return pTabStop;
		}
	}

	return NULL;
}

int CMFCRibbonButtonsGroup::GetButtonIndex(const CMFCRibbonBaseElement* pButton) const
{
	if (pButton == NULL)
	{
		return -1;
	}

	ASSERT_VALID(this);
	ASSERT_VALID(pButton);

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		if (m_arButtons [i] == pButton)
		{
			return i;
		}
	}

	return -1;
}

IMPLEMENT_DYNCREATE(CMFCRibbonTabsGroup, CMFCRibbonButtonsGroup)

CMFCRibbonTabsGroup::CMFCRibbonTabsGroup()
{
}

CMFCRibbonTabsGroup::CMFCRibbonTabsGroup(CMFCRibbonBaseElement* pButton)
{
	AddButton(pButton);
}

CMFCRibbonTabsGroup::~CMFCRibbonTabsGroup()
{
	m_arButtons.RemoveAll();
}

BOOL CMFCRibbonTabsGroup::SetACCData(CWnd* /*pParent*/, CAccessibilityData& /*data*/)
{
	ASSERT_VALID(this);

	m_AccData.Clear();
	m_AccData.m_strAccName = _T("Ribbon Tabs"); 
	m_AccData.m_nAccRole = ROLE_SYSTEM_GROUPING;
	m_AccData.m_bAccState = STATE_SYSTEM_NORMAL;
	m_AccData.m_rectAccLocation = m_rect;

	if (m_pRibbonBar->GetSafeHwnd() != NULL)
	{
		m_pRibbonBar->ClientToScreen(&m_AccData.m_rectAccLocation);
	}

	return TRUE;
}

BOOL CMFCRibbonTabsGroup::OnSetAccData (long lVal)
{
	ASSERT_VALID(this);

	m_AccData.Clear();

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID (m_pRibbonBar);

	int nIndex = (int)lVal - 1;

	if (nIndex < 0 || nIndex >= m_arButtons.GetSize())
	{
		return FALSE;
	}

	ASSERT_VALID(m_arButtons[nIndex]);
	return m_arButtons[nIndex]->SetACCData (m_pRibbonBar, m_AccData);
}

HRESULT CMFCRibbonTabsGroup::accHitTest(long xLeft, long yTop, VARIANT *pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	pvarChild->vt = VT_I4;
	pvarChild->lVal = CHILDID_SELF;

	CPoint pt(xLeft, yTop);
	m_pRibbonBar->ScreenToClient(&pt);

	for (int i = 0; i < m_arButtons.GetSize (); i++)
	{
		CMFCRibbonBaseElement* pElem = m_arButtons[i];
		if (pElem != NULL)
		{
			ASSERT_VALID(pElem);

			if (pElem->GetRect().PtInRect(pt))
			{
				pvarChild->lVal = i + 1;
				pElem->SetACCData(m_pRibbonBar, m_AccData);
				break;
			}
		}
	}

	return S_OK;
}

HRESULT CMFCRibbonTabsGroup::get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		return S_FALSE;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);
		*pszDefaultAction = m_AccData.m_strAccDefAction.AllocSysString();
		return S_OK; 
	}

	return S_FALSE;
}

HRESULT CMFCRibbonTabsGroup::accDoDefaultAction(VARIANT varChild)
{
	if (varChild.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (varChild.lVal != CHILDID_SELF)
	{
		int nIndex = (int)varChild.lVal - 1;
		if (nIndex < 0 || nIndex >= m_arButtons.GetSize())
		{
			return E_INVALIDARG;
		}

		CMFCRibbonBaseElement* pElem = m_arButtons[nIndex];
		if (pElem != NULL)
		{
			ASSERT_VALID (pElem);

			pElem->OnAccDefaultAction();
			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CMFCRibbonTabsGroup::get_accParent(IDispatch **ppdispParent)
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

	LPDISPATCH lpDispatch = (LPDISPATCH)m_pRibbonBar->GetAccessibleDispatch();
	if (lpDispatch != NULL)
	{
		*ppdispParent =  lpDispatch;
	}

	return S_OK;
}

HRESULT CMFCRibbonTabsGroup::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	*pcountChildren = (long)m_arButtons.GetSize(); 
	return S_OK;
}

HRESULT CMFCRibbonTabsGroup::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
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
			pvarEndUpAt->lVal = (long)m_arButtons.GetSize();
			return S_OK;
		}
		break;

	case NAVDIR_NEXT:   
	case NAVDIR_RIGHT:
		if (varStart.lVal != CHILDID_SELF)
		{
			pvarEndUpAt->vt = VT_I4;
			pvarEndUpAt->lVal = varStart.lVal + 1;
			
			if (pvarEndUpAt->lVal > m_arButtons.GetSize())
			{
				pvarEndUpAt->vt = VT_EMPTY;
				return S_FALSE;
			}

			return S_OK;
		}
		else
		{
			if (m_pRibbonBar->m_TabElements.GetCount() > 0)
			{
				CMFCRibbonBaseElement* pTabElement = m_pRibbonBar->m_TabElements.GetButton(0);
				if (pTabElement != NULL)
				{
					ASSERT_VALID(pTabElement);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pTabElement->GetIDispatch(TRUE);

					return S_OK;
				}
			}
			else
			{
				CMFCRibbonCategory* pCatrgory = m_pRibbonBar->GetActiveCategory();
				if (pCatrgory != NULL)
				{
					ASSERT_VALID(pCatrgory);
					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pCatrgory->GetIDispatch(TRUE);
					return S_OK;
				}
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
			if (m_pRibbonBar->m_QAToolbar.IsVisible())
			{
				pvarEndUpAt->vt = VT_DISPATCH;
				pvarEndUpAt->pdispVal = m_pRibbonBar->m_QAToolbar.GetIDispatch(TRUE);

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

void CMFCRibbonTabsGroup::UpdateTabs(CArray<CMFCRibbonCategory*,CMFCRibbonCategory*>& arCategories)
{
	m_arButtons.RemoveAll();

	for (int i = 0; i < arCategories.GetSize(); i++)
	{
		CMFCRibbonCategory* pCategory  = (CMFCRibbonCategory*)arCategories[i];
		if (pCategory != NULL)
		{
			ASSERT_VALID(pCategory);

			if (pCategory->IsVisible() && !pCategory->m_Tab.GetRect().IsRectEmpty())
			{
				m_arButtons.Add(&pCategory->m_Tab);
			}
		}
	}
}
