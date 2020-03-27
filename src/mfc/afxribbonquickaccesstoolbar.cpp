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
#include "afxribbonquickaccesstoolbar.h"
#include "afxribbonbar.h"
#include "afxribboncategory.h"
#include "afxvisualmanager.h"
#include "afxribbonpanelmenu.h"
#include "afxmenuimages.h"
#include "afxribbonres.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

////////////////////////////////////////////////////////
// CMFCRibbonQuickAccessCustomizeButton class

CMFCRibbonQuickAccessToolBarDefaultState::CMFCRibbonQuickAccessToolBarDefaultState()
{
}

void CMFCRibbonQuickAccessToolBarDefaultState::AddCommand(UINT uiCmd, BOOL bIsVisible/* = TRUE*/)
{
	m_arCommands.Add(uiCmd);
	m_arVisibleState.Add(bIsVisible);
}

void CMFCRibbonQuickAccessToolBarDefaultState::RemoveAll()
{
	m_arCommands.RemoveAll();
	m_arVisibleState.RemoveAll();
}

void CMFCRibbonQuickAccessToolBarDefaultState::CopyFrom(const CMFCRibbonQuickAccessToolBarDefaultState& src)
{
	RemoveAll();

	for (int i = 0; i < src.m_arCommands.GetSize(); i++)
	{
		AddCommand(src.m_arCommands [i], src.m_arVisibleState [i]);
	}
}

////////////////////////////////////////////////////////
// CMFCRibbonQuickAccessCustomizeButton class

class CMFCRibbonQuickAccessCustomizeButton : public CMFCRibbonButton
{
	friend class CMFCRibbonQuickAccessToolBar;

	DECLARE_DYNCREATE(CMFCRibbonQuickAccessCustomizeButton)

	CMFCRibbonQuickAccessCustomizeButton()
	{
		ENSURE(m_strMoreButtons.LoadString(IDS_AFXBARRES_MORE_BUTTONS));
	}

	virtual CSize GetImageSize(RibbonImageType /*type*/) const
	{
		ASSERT_VALID(this);

		CSize sizeImage = CMenuImages::Size();

		if (GetGlobalData()->GetRibbonImageScale() != 1.)
		{
			sizeImage.cx = (int)(.5 + GetGlobalData()->GetRibbonImageScale() * sizeImage.cx);
			sizeImage.cy = (int)(.5 + GetGlobalData()->GetRibbonImageScale() * sizeImage.cy);
		}

		return sizeImage;
	}

	virtual CSize GetCompactSize(CDC* pDC)
	{
		ASSERT_VALID(this);

		CSize size = CMFCRibbonButton::GetCompactSize(pDC);
		CSize sizeImage = GetImageSize((RibbonImageType)-1);

		size.cx = sizeImage.cx + 4;
		size.cy = sizeImage.cy * 2;

		return size;
	}

	virtual BOOL HasMenu() const
	{
		return TRUE;
	}

	virtual void OnShowPopupMenu()
	{
		OnLButtonDown(m_rect.TopLeft());
	}

	virtual void OnDraw(CDC* pDC)
	{
		ASSERT_VALID(this);
		ASSERT_VALID(pDC);

		if (m_rect.IsRectEmpty())
		{
			return;
		}

		CMFCVisualManager::GetInstance()->OnFillRibbonButton(pDC, this);

		CMenuImages::IMAGES_IDS nImageIndex = CMenuImages::IdCustomizeArrowDown;

		if (m_arHidden.GetSize() > 0)
		{
			nImageIndex = GetGlobalData()->m_bIsRTL ? CMenuImages::IdArrowPageLeft : CMenuImages::IdCustomizeMoreButtonsHorz;
		}

		SetKeys(m_arHidden.GetSize() == 0 ? NULL : _T("00"));

		CRect rectWhite = m_rect;
		rectWhite.OffsetRect(0, 1);

		CSize sizeImage = CMenuImages::Size ();

		CMenuImages::Draw(pDC, nImageIndex, rectWhite, CMenuImages::ImageLtGray, sizeImage);
		CMenuImages::Draw(pDC, nImageIndex, m_rect, CMenuImages::ImageBlack2, sizeImage);

		CMFCVisualManager::GetInstance()->OnDrawRibbonButtonBorder(pDC, this);
	}

	virtual void OnLButtonDown(CPoint /*point*/)
	{
		ASSERT_VALID(this);
		ASSERT_VALID(m_pRibbonBar);

		if (m_bIsDroppedDown)
		{
			m_bIsHighlighted = TRUE;
			Redraw();
			return;
		}

		const BOOL bIsRTL = (m_pRibbonBar->GetExStyle() & WS_EX_LAYOUTRTL);
		CWnd* pWndParent = m_pRibbonBar;

		if (m_pParentMenu != NULL)
		{
			pWndParent = m_pParentMenu;
		}

		ASSERT_VALID(pWndParent);
		HWND hwndParent = pWndParent->GetSafeHwnd();

		CRect rectBtn = m_rect;
		pWndParent->ClientToScreen(&rectBtn);

		const int x = bIsRTL ? rectBtn.right : rectBtn.left;

		if (m_arHidden.GetSize() == 0)
		{
			m_bIsDroppedDown = TRUE;
			m_bIsHighlighted = TRUE;

			Redraw();

			if (!m_pRibbonBar->OnShowRibbonQATMenu(pWndParent, x, rectBtn.bottom, this) && ::IsWindow(hwndParent))
			{
				m_bIsDroppedDown = FALSE;
			}
		}
		else
		{
			CMFCRibbonPanelMenu* pMenu = new CMFCRibbonPanelMenu(m_pRibbonBar, m_arHidden, TRUE);
			((CMFCRibbonPanelMenuBar*)pMenu->GetMenuBar())->m_bIsQATPopup = TRUE;

			pMenu->SetParentRibbonElement(this);
			pMenu->Create(m_pRibbonBar, x, rectBtn.bottom, (HMENU) NULL);

			SetDroppedDown(pMenu);

			if (m_pRibbonBar->GetKeyboardNavigationLevel() >= 0)
			{
				m_pRibbonBar->RedrawWindow();
			}
		}
	}

	virtual void CopyFrom(const CMFCRibbonBaseElement& s)
	{
		ASSERT_VALID(this);

		CMFCRibbonButton::CopyFrom(s);

		CMFCRibbonQuickAccessCustomizeButton& src = (CMFCRibbonQuickAccessCustomizeButton&) s;
		m_pRibbonBar = src.m_pRibbonBar;

		m_strMoreButtons = src.m_strMoreButtons;
	}

	virtual CString GetToolTipText() const
	{
		ASSERT_VALID(this);

		if (IsDroppedDown())
		{
			return _T("");
		}

		if (m_arHidden.GetSize() == 0)
		{
			return CMFCRibbonButton::GetToolTipText();
		}

		return m_strMoreButtons;
	}

	virtual CRect GetKeyTipRect(CDC* pDC, BOOL /*bIsMenu*/)
	{
		ASSERT_VALID(this);

		CSize sizeKeyTip = GetKeyTipSize(pDC);
		CRect rectKeyTip(0, 0, 0, 0);

		if (sizeKeyTip == CSize(0, 0) || m_rect.IsRectEmpty() || m_pParentMenu != NULL)
		{
			return rectKeyTip;
		}

		rectKeyTip.left = m_rect.left;
		rectKeyTip.top = m_rect.CenterPoint().y;

		rectKeyTip.right = rectKeyTip.left + sizeKeyTip.cx;
		rectKeyTip.bottom = rectKeyTip.top + sizeKeyTip.cy;

		return rectKeyTip;
	}

	virtual BOOL OnKey(BOOL /*bIsMenuKey*/)
	{
		ASSERT_VALID(this);

		OnLButtonDown(CPoint(-1, -1));
		return FALSE;
	}

protected:
	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> m_arHidden;
	CString m_strMoreButtons;
};

IMPLEMENT_DYNCREATE(CMFCRibbonQuickAccessCustomizeButton, CMFCRibbonButton)

////////////////////////////////////////////////////////
// CMFCRibbonQuickAccessToolBar class

IMPLEMENT_DYNCREATE(CMFCRibbonQuickAccessToolBar, CMFCRibbonButtonsGroup)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFCRibbonQuickAccessToolBar::CMFCRibbonQuickAccessToolBar()
{
	m_pRibbonBar = NULL;
	m_rectCommands.SetRectEmpty();
}

CMFCRibbonQuickAccessToolBar::~CMFCRibbonQuickAccessToolBar()
{
}

void CMFCRibbonQuickAccessToolBar::SetCommands(CMFCRibbonBar* pRibbonBar, const CList<UINT,UINT>& lstCommands, LPCTSTR lpszToolTip)
{
	CMFCRibbonQuickAccessCustomizeButton* pButton = new CMFCRibbonQuickAccessCustomizeButton;
	pButton->SetToolTipText(lpszToolTip);

	SetCommands(pRibbonBar, lstCommands, pButton);
}

void CMFCRibbonQuickAccessToolBar::SetCommands(CMFCRibbonBar* pRibbonBar, const CList<UINT,UINT>& lstCommands, CMFCRibbonQuickAccessCustomizeButton* pCustButton)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pRibbonBar);

	BOOL bSetByUser = TRUE;

	if (pCustButton == NULL)
	{
		bSetByUser = FALSE;

		// Leave existing:
		if (m_arButtons.GetSize() == 0)
		{
			return;
		}

		int nSize = (int) m_arButtons.GetSize();

		pCustButton = DYNAMIC_DOWNCAST(CMFCRibbonQuickAccessCustomizeButton, m_arButtons [nSize - 1]);
		m_arButtons.SetSize(nSize - 1);
	}

	RemoveAll();

	ASSERT_VALID(pCustButton);

	m_pRibbonBar = pRibbonBar;

	BOOL bAddToState = bSetByUser && m_DefaultState.m_arCommands.GetSize() == 0;

	for (POSITION pos = lstCommands.GetHeadPosition(); pos != NULL;)
	{
		UINT uiCmd = lstCommands.GetNext(pos);

		if (uiCmd == 0)
		{
			CMFCRibbonSeparator* pSeparator = new CMFCRibbonSeparator(TRUE);

			pSeparator->m_pRibbonBar = m_pRibbonBar;
			pSeparator->m_bQuickAccessMode = TRUE;

			m_arButtons.Add(pSeparator);
			continue;
		}

		CMFCRibbonBaseElement* pElem = pRibbonBar->FindByID(uiCmd, FALSE);
		if (pElem == NULL)
		{
			TRACE(_T("CMFCRibbonQuickAccessToolBar::SetCommands: Ribbon element with ID = %d not found\n"), uiCmd);
			continue;
		}

		CMFCRibbonBaseElement* pButton = (CMFCRibbonBaseElement*) pElem->GetRuntimeClass()->CreateObject();
		ASSERT_VALID(pButton);

		pButton->CopyFrom(*pElem);
		pButton->m_pRibbonBar = m_pRibbonBar;
		pButton->SetOriginal(pElem);
		pButton->m_bQuickAccessMode = TRUE;

		m_arButtons.Add(pButton);

		if (bAddToState)
		{
			m_DefaultState.AddCommand(uiCmd);
		}
	}

	pCustButton->m_pRibbonBar = m_pRibbonBar;
	m_arButtons.Add(pCustButton);

	RebuildKeys();
}

void CMFCRibbonQuickAccessToolBar::GetCommands(CList<UINT,UINT>& lstCommands)
{
	ASSERT_VALID(this);

	lstCommands.RemoveAll();

	for (int i = 0; i < m_arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->GetID() != 0 || pButton->IsKindOf(RUNTIME_CLASS(CMFCRibbonSeparator)))
		{
			lstCommands.AddTail(pButton->GetID());
		}
	}
}

int CMFCRibbonQuickAccessToolBar::GetActualWidth() const
{
	ASSERT_VALID(this);

	if (m_arButtons.GetSize() == 0)
	{
		return 0;
	}

	CMFCRibbonBaseElement* pLastButton = m_arButtons [m_arButtons.GetSize() - 1];
	ASSERT_VALID(pLastButton);

	return pLastButton->m_rect.right - m_rect.left;
}

void CMFCRibbonQuickAccessToolBar::OnAfterChangeRect(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	CMFCRibbonButtonsGroup::OnAfterChangeRect(pDC);
	RebuildHiddenItems();

	m_rectCommands = m_rect;

	if (m_arButtons.GetSize() > 0)
	{
		CMFCRibbonQuickAccessCustomizeButton* pCustButton = DYNAMIC_DOWNCAST(CMFCRibbonQuickAccessCustomizeButton, m_arButtons [m_arButtons.GetSize() - 1]);
		ASSERT_VALID(pCustButton);

		CRect rectChevron = pCustButton->GetRect();

		m_rectCommands.right = rectChevron.left;

		if (m_arButtons.GetSize() > 1)
		{
			if (m_pRibbonBar->IsQuickAccessToolbarOnTop())
			{
				if (!m_pRibbonBar->IsWindows7Look ())
				{
					rectChevron.OffsetRect(CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarChevronOffset(), 0);
				}

				if (CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarRightMargin() > 0)
				{
					rectChevron.top -= 2;
					rectChevron.bottom--;
				}
			}
			else
			{
				rectChevron.OffsetRect(6, 0);
				rectChevron.bottom++;
			}
		}

		pCustButton->SetRect(rectChevron);
		pCustButton->OnAfterChangeRect(pDC);
	}
}

CSize CMFCRibbonQuickAccessToolBar::GetRegularSize(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(m_pRibbonBar);

	CSize size = CMFCRibbonButtonsGroup::GetRegularSize(pDC);

	if (m_pRibbonBar->IsQuickAccessToolbarOnTop() && m_arButtons.GetSize() > 1)
	{
		size.cx += max(6, CMFCVisualManager::GetInstance()->GetRibbonQuickAccessToolBarChevronOffset());
	}

	size.cy += m_pRibbonBar->IsQuickAccessToolbarOnTop() ? 1 : 3;

	return size;
}

void CMFCRibbonQuickAccessToolBar::RebuildHiddenItems()
{
	ASSERT_VALID(this);

	if (m_arButtons.GetSize() == 0)
	{
		return;
	}

	CMFCRibbonQuickAccessCustomizeButton* pCustButton = DYNAMIC_DOWNCAST(CMFCRibbonQuickAccessCustomizeButton, m_arButtons [m_arButtons.GetSize() - 1]);
	ASSERT_VALID(pCustButton);

	pCustButton->m_arHidden.RemoveAll();

	for (int i = 0; i < m_arButtons.GetSize() - 1; i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->m_rect.IsRectEmpty())
		{
			pCustButton->m_arHidden.Add(pButton);
		}
	}

	if (pCustButton->m_arHidden.GetSize() > 0 && m_pParentMenu == NULL)
	{
		pCustButton->m_arHidden.Add(pCustButton);
	}
}

void CMFCRibbonQuickAccessToolBar::ReplaceCommands(const CList<UINT,UINT>& lstCommands)
{
	ASSERT_VALID(this);
	SetCommands(m_pRibbonBar, lstCommands, (CMFCRibbonQuickAccessCustomizeButton*) NULL);
}

void CMFCRibbonQuickAccessToolBar::ResetCommands()
{
	ASSERT_VALID(this);

	CList<UINT,UINT> lstCommands;
	GetDefaultCommands(lstCommands);

	SetCommands(m_pRibbonBar, lstCommands, (CMFCRibbonQuickAccessCustomizeButton*) NULL);
}

void CMFCRibbonQuickAccessToolBar::Add(CMFCRibbonBaseElement* pElem)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElem);

	CMFCRibbonBaseElement* pButton = (CMFCRibbonBaseElement*) pElem->GetRuntimeClass()->CreateObject();
	ASSERT_VALID(pButton);

	pButton->CopyFrom(*pElem);
	pButton->m_pRibbonBar = m_pRibbonBar;

	if (pElem->m_pOriginal != NULL)
	{
		pButton->SetOriginal(pElem->m_pOriginal);
	}
	else
	{
		pButton->SetOriginal(pElem);
	}

	pButton->m_bQuickAccessMode = TRUE;

	m_arButtons.InsertAt(m_arButtons.GetSize() - 1, pButton);
	RebuildKeys();
}

void CMFCRibbonQuickAccessToolBar::Remove(CMFCRibbonBaseElement* pElem)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pElem);

	for (int i = 0; i < m_arButtons.GetSize() - 1; i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		if (pButton->GetID() == pElem->GetID())
		{
			m_arButtons.RemoveAt(i);
			delete pButton;

			RebuildHiddenItems();
			RebuildKeys();
			return;
		}
	}
}

void CMFCRibbonQuickAccessToolBar::GetDefaultCommands(CList<UINT,UINT>& lstCommands)
{
	ASSERT_VALID(this);

	lstCommands.RemoveAll();

	for (int i = 0; i < m_DefaultState.m_arCommands.GetSize(); i++)
	{
		if (m_DefaultState.m_arVisibleState [i])
		{
			lstCommands.AddTail(m_DefaultState.m_arCommands [i]);
		}
	}
}

void CMFCRibbonQuickAccessToolBar::RebuildKeys()
{
	for (int i = 0; i < m_arButtons.GetSize() - 1; i++)
	{
		CMFCRibbonBaseElement* pButton = m_arButtons [i];
		ASSERT_VALID(pButton);

		CString strKeys;

		if (i < 9)
		{
			strKeys.Format(_T("%d"), i + 1);
		}
		else if (i >= 9 && i < 18)
		{
			strKeys.Format(_T("0%d"), 18 - i);
		}
		else
		{
			const int k = i - 18;

			if (k < 26)
			{
				strKeys.Format(_T("%Tc%Tc"), _T('0') + k / 26, _T('a') +(k % 26));
			}
		}

		pButton->SetKeys(strKeys);
	}
}

BOOL CMFCRibbonQuickAccessToolBar::SetACCData(CWnd* pParent, CAccessibilityData& data)
{
	CMFCRibbonButtonsGroup::SetACCData (pParent, data);

	data.m_strAccName = m_strText.IsEmpty() ? _T("Quick Access Toolbar") : m_strText;
	data.m_strAccValue = data.m_strAccName;

	data.m_nAccRole = ROLE_SYSTEM_TOOLBAR;
	data.m_bAccState = STATE_SYSTEM_NORMAL;
	
	return TRUE;
}

BOOL CMFCRibbonQuickAccessToolBar::OnSetAccData(long lVal)
{
	ASSERT_VALID(this);

	m_AccData.Clear();

	if (m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return FALSE;
	}

	int nIndex = (int)lVal - 1;

	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
	GetVisibleElements(arButtons);

	if (nIndex < 0 || nIndex >= arButtons.GetSize())
	{
		return FALSE;
	}

	ASSERT_VALID(arButtons[nIndex]);
	return arButtons[nIndex]->SetACCData (m_pRibbonBar, m_AccData);
}

HRESULT CMFCRibbonQuickAccessToolBar::accHitTest(long xLeft, long yTop, VARIANT *pvarChild)
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

	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
	GetVisibleElements(arButtons);

	for (int i = 0; i < arButtons.GetSize(); i++)
	{
		CMFCRibbonBaseElement* pElem = arButtons [i];
		ASSERT_VALID (pElem);

		CRect rectElem = pElem->GetRect();
		if (rectElem.PtInRect(pt))
		{
			pvarChild->lVal = i + 1;
			pElem->SetACCData(m_pRibbonBar, m_AccData);
			break;
		}
	}

	return S_OK;
}

HRESULT CMFCRibbonQuickAccessToolBar::accDoDefaultAction(VARIANT varChild)
{
	if (varChild.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	if (varChild.lVal != CHILDID_SELF)
	{
		CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
		GetVisibleElements(arButtons);

		int nIndex = (int)varChild.lVal - 1;
		if (nIndex < 0 || nIndex >= arButtons.GetSize())
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

HRESULT CMFCRibbonQuickAccessToolBar::get_accParent(IDispatch **ppdispParent)
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

HRESULT CMFCRibbonQuickAccessToolBar::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*> arButtons;
	GetVisibleElements(arButtons);

	*pcountChildren = (long)arButtons.GetSize();
	return S_OK;
}

HRESULT CMFCRibbonQuickAccessToolBar::accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild)
{
	if (!pxLeft || !pyTop || !pcxWidth || !pcyHeight)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF && m_pRibbonBar->GetSafeHwnd() != NULL)
	{		
		CRect rectAccLocation = m_rect;
		m_pRibbonBar->ClientToScreen(&rectAccLocation);

		*pxLeft = rectAccLocation.left;
		*pyTop = rectAccLocation.top;
		*pcxWidth = rectAccLocation.Width();
		*pcyHeight = rectAccLocation.Height();

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

HRESULT CMFCRibbonQuickAccessToolBar::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
{
	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

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
		
			if (pvarEndUpAt->lVal > arButtons.GetSize())
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

			if (arCaptions.GetSize() > 0)
			{ 
				CMFCRibbonContextCaption* pCaption = arCaptions[0];
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
			CMFCRibbonApplicationButton* pMainButton = m_pRibbonBar->GetApplicationButton();
			if (pMainButton != NULL)
			{
				ASSERT_VALID(pMainButton);

				pvarEndUpAt->vt = VT_DISPATCH;
				pvarEndUpAt->pdispVal = pMainButton->GetIDispatch(TRUE);

				return S_OK;
			}
		}
		break;
	}

	return S_FALSE;
}



