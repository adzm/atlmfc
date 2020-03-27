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
#include "afxbaseribbonelement.h"

#include "afxribboncategory.h"
#include "afxribbonbar.h"
#include "afxpopupmenu.h"
#include "afxribbonpanelmenu.h"
#include "afxkeyboardmanager.h"
#include "afxvisualmanager.h"
#include "afxribboncommandslistbox.h"
#include "afxribbonquickaccesstoolbar.h"
#include "afxribbonkeytip.h"
#include "afxribbonres.h"
#include "afxmenuimages.h"
#include "afxmdiframewndex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static inline BOOL __stdcall IsSystemCommand(UINT uiCmd)
{
	return (uiCmd >= 0xF000 && uiCmd < 0xF1F0);
}

//////////////////////////////////////////////////////////////////////
// CMFCBaseAccessibleObject

IMPLEMENT_DYNAMIC(CMFCBaseAccessibleObject, CCmdTarget)

BEGIN_INTERFACE_MAP(CMFCBaseAccessibleObject, CCmdTarget)
	INTERFACE_PART(CMFCBaseAccessibleObject, IID_IAccessible, Accessible)
END_INTERFACE_MAP()

CMFCBaseAccessibleObject::CMFCBaseAccessibleObject()
{
	EnableAutomation();
}

CMFCBaseAccessibleObject::~CMFCBaseAccessibleObject()
{
	ExternalDisconnect ();
}

//**************************************************************************************
// IUnknown interface

STDMETHODIMP_(ULONG) CMFCBaseAccessibleObject::XAccessible::AddRef()
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CMFCBaseAccessibleObject::XAccessible::Release()
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->ExternalRelease();
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::QueryInterface(REFIID iid, LPVOID far* ppvObj)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::GetTypeInfoCount(UINT FAR* pctinfo)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)

	LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
	ASSERT(lpDispatch != NULL);

	return lpDispatch->GetTypeInfoCount(pctinfo);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::GetTypeInfo(UINT itinfo, LCID lcid, ITypeInfo FAR* FAR* pptinfo)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)

	LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
	ASSERT(lpDispatch != NULL);

	return lpDispatch->GetTypeInfo(itinfo, lcid, pptinfo);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::GetIDsOfNames(REFIID riid, OLECHAR FAR* FAR* rgszNames, UINT cNames, LCID lcid, DISPID FAR* rgdispid) 
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)

	LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
	ASSERT(lpDispatch != NULL);

	return lpDispatch->GetIDsOfNames(riid, rgszNames, cNames, lcid, rgdispid);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS FAR* pdispparams, VARIANT FAR* pvarResult, EXCEPINFO FAR* pexcepinfo, UINT FAR* puArgErr)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	
	LPDISPATCH lpDispatch = pThis->GetIDispatch(FALSE);
	ASSERT(lpDispatch != NULL);

	return lpDispatch->Invoke(dispidMember, riid, lcid, wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr);
}

//*********************************************************************************************
// Accessible:

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accParent(THIS_ IDispatch * FAR* ppdispParent)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accParent(ppdispParent);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accChildCount(THIS_ long FAR* pChildCount)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accChildCount(pChildCount);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accChild(THIS_ VARIANT varChildIndex, IDispatch * FAR* ppdispChild)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accChild(varChildIndex, ppdispChild);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accName(THIS_ VARIANT varChild, BSTR* pszName)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accName(varChild, pszName);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accValue(THIS_ VARIANT varChild, BSTR* pszValue)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accValue(varChild, pszValue);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accDescription(THIS_ VARIANT varChild, BSTR FAR* pszDescription)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accDescription(varChild, pszDescription);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accRole(THIS_ VARIANT varChild, VARIANT *pvarRole)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accRole(varChild, pvarRole);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accState(THIS_ VARIANT varChild, VARIANT *pvarState)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accState(varChild, pvarState);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accHelp(THIS_ VARIANT varChild, BSTR* pszHelp)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accHelp(varChild, pszHelp);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accHelpTopic(THIS_ BSTR* pszHelpFile, VARIANT varChild, long* pidTopic)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accHelpTopic(pszHelpFile, varChild, pidTopic);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accKeyboardShortcut(THIS_ VARIANT varChild, BSTR* pszKeyboardShortcut)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accKeyboardShortcut(varChild, pszKeyboardShortcut);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accFocus(THIS_ VARIANT FAR * pvarFocusChild)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accFocus(pvarFocusChild);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accSelection(THIS_ VARIANT FAR * pvarSelectedChildren)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accSelection(pvarSelectedChildren);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::get_accDefaultAction(THIS_ VARIANT varChild, BSTR* pszDefaultAction)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->get_accDefaultAction(varChild, pszDefaultAction);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::accSelect(THIS_ long flagsSelect, VARIANT varChild)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->accSelect(flagsSelect, varChild);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::accLocation(THIS_ long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->accLocation(pxLeft, pyTop, pcxWidth, pcyHeight, varChild);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::accNavigate(THIS_ long navDir, VARIANT varStart, VARIANT * pvarEndUpAt)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->accNavigate(navDir, varStart, pvarEndUpAt);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::accHitTest(THIS_ long xLeft, long yTop, VARIANT * pvarChildAtPoint)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->accHitTest(xLeft, yTop, pvarChildAtPoint);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::accDoDefaultAction(THIS_ VARIANT varChild)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->accDoDefaultAction(varChild);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::put_accName(THIS_ VARIANT varChild, BSTR szName)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->put_accName(varChild, szName);
}

STDMETHODIMP CMFCBaseAccessibleObject::XAccessible::put_accValue(THIS_ VARIANT varChild, BSTR pszValue)
{
	METHOD_PROLOGUE(CMFCBaseAccessibleObject, Accessible)
	return pThis->put_accValue(varChild, pszValue);
}

HRESULT CMFCBaseAccessibleObject::get_accParent(IDispatch** ppdispParent)
{
	if (!ppdispParent)
	{
		return E_INVALIDARG;
	}

	*ppdispParent = NULL;
	return S_OK;
}

HRESULT CMFCBaseAccessibleObject::get_accChildCount(long *pcountChildren)
{
	if (!pcountChildren)
	{
		return E_INVALIDARG;
	}

	*pcountChildren = 0;
	return S_OK;
}

HRESULT CMFCBaseAccessibleObject::get_accChild(VARIANT varChild, IDispatch **ppdispChild)
{
	if (!ppdispChild)
	{
		return E_INVALIDARG;
	}

	*ppdispChild = NULL;

	return varChild.vt != VT_I4 ? E_INVALIDARG : S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::get_accName(VARIANT varChild, BSTR* pszName)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();
		if (pWnd->GetSafeHwnd() != NULL)
		{
			ASSERT_VALID (pWnd);

			SetACCData(pWnd, m_AccData);
			*pszName = m_AccData.m_strAccName.AllocSysString();

			return S_OK;
		}
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);

		if (m_AccData.m_strAccName.IsEmpty())
		{
			return S_FALSE;
		}

		*pszName = m_AccData.m_strAccName.AllocSysString();
	}

	return S_OK;
}

HRESULT CMFCBaseAccessibleObject::get_accValue(VARIANT varChild, BSTR *pszValue)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();

		if (pWnd->GetSafeHwnd() != NULL)
		{
			ASSERT_VALID (pWnd);

			SetACCData(pWnd, m_AccData);
			*pszValue = m_AccData.m_strAccValue.AllocSysString();

			return S_OK;
		}
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);

		if (m_AccData.m_strAccValue.IsEmpty())
		{
			return S_FALSE;
		}

		*pszValue = m_AccData.m_strAccValue.AllocSysString();
		return S_OK;
	}

	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::get_accDescription(VARIANT varChild, BSTR *pszDescription)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();

		if (pWnd->GetSafeHwnd () != NULL)
		{
			ASSERT_VALID (pWnd);

			SetACCData(pWnd, m_AccData);
			*pszDescription = m_AccData.m_strDescription.AllocSysString();

			return S_OK;
		}
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);
		if (m_AccData.m_strDescription.IsEmpty())
		{
			return S_FALSE;
		}
		*pszDescription = m_AccData.m_strDescription.AllocSysString();
		return S_OK;
	}

	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::get_accRole(VARIANT varChild, VARIANT *pvarRole)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();
		if (pWnd->GetSafeHwnd () != NULL)
		{
			ASSERT_VALID (pWnd);
			SetACCData(pWnd, m_AccData);
			pvarRole->vt = VT_I4;
			pvarRole->lVal = m_AccData.m_nAccRole;
			return S_OK;
		}
	}

	if (!pvarRole || (varChild.vt != VT_I4 && varChild.lVal != CHILDID_SELF))
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		pvarRole->vt = VT_I4;
		OnSetAccData(varChild.lVal);
		pvarRole->lVal = m_AccData.m_nAccRole;
		return S_OK;
	}

	return S_OK;
}

HRESULT CMFCBaseAccessibleObject::get_accState(VARIANT varChild, VARIANT *pvarState)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();
		if (pWnd->GetSafeHwnd () != NULL)
		{
			ASSERT_VALID (pWnd);
			SetACCData(pWnd, m_AccData);
			pvarState->vt = VT_I4;
			pvarState->lVal = m_AccData.m_bAccState;
			return S_OK;
		}
	}

	if (!pvarState || (varChild.vt != VT_I4 && varChild.lVal != CHILDID_SELF))
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);
		pvarState->vt = VT_I4;
		pvarState->lVal = m_AccData.m_bAccState;
		return S_OK; 
	}

	return E_INVALIDARG;
}

HRESULT CMFCBaseAccessibleObject::get_accHelp(VARIANT varChild, BSTR *pszHelp)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		 return S_FALSE;
	}

	if (varChild.vt != VT_I4 || NULL == pszHelp)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);
		*pszHelp = m_AccData.m_strAccHelp.AllocSysString();

		return S_OK; 
	}

	return E_INVALIDARG;
}

HRESULT CMFCBaseAccessibleObject::get_accHelpTopic(BSTR* /*pszHelpFile*/, VARIANT /*varChild*/, long* /*pidTopic*/)
{
	return E_NOTIMPL;
}

HRESULT CMFCBaseAccessibleObject::get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut)
{
	if (varChild.vt != VT_I4 && varChild.lVal != CHILDID_SELF)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();
		if (pWnd->GetSafeHwnd() != NULL)
		{
			ASSERT_VALID (pWnd);

			SetACCData(pWnd, m_AccData);
			*pszKeyboardShortcut = m_AccData.m_strAccKeys.AllocSysString();

			return S_OK;
		}
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);
		*pszKeyboardShortcut = m_AccData.m_strAccKeys.AllocSysString();

		return S_OK;
	}

	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::get_accFocus(VARIANT *pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	return E_NOTIMPL;
}

HRESULT CMFCBaseAccessibleObject::get_accSelection(VARIANT *pvarChildren)
{
	if (!pvarChildren)
	{
		return E_INVALIDARG;
	}

	return E_NOTIMPL;
}

HRESULT CMFCBaseAccessibleObject::get_accDefaultAction(VARIANT varChild, BSTR* pszDefaultAction)
{
	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{
		CWnd* pWnd = GetParentWnd();
		if (pWnd->GetSafeHwnd () != NULL)
		{
			ASSERT_VALID (pWnd);

			SetACCData(pWnd, m_AccData);
			*pszDefaultAction = m_AccData.m_strAccDefAction.AllocSysString();

			return S_OK;
		}
	}

	if (varChild.vt != VT_I4 && varChild.lVal != CHILDID_SELF)
	{
		return E_INVALIDARG;
	}

	OnSetAccData(varChild.lVal);

	if (m_AccData.m_strAccDefAction.IsEmpty())
	{
		return S_FALSE;
	}

	*pszDefaultAction = m_AccData.m_strAccDefAction.AllocSysString();
	return S_OK;
}

HRESULT CMFCBaseAccessibleObject::accSelect(long /*flagsSelect*/, VARIANT /*varChild*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::accLocation(long* /*pxLeft*/, long* /*pyTop*/, long* /*pcxWidth*/, long* /*pcyHeight*/, VARIANT /*varChild*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::accNavigate(long /*navDir*/, VARIANT /*varStart*/, VARIANT* /*pvarEndUpAt*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::accHitTest(long /*xLeft*/, long /*yTop*/, VARIANT* /*pvarChild*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::accDoDefaultAction(VARIANT /*varChild*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::put_accName(VARIANT /*varChild*/, BSTR /*szName*/)
{
	return S_FALSE;
}

HRESULT CMFCBaseAccessibleObject::put_accValue(VARIANT /*varChild*/, BSTR /*szValue*/)
{
	return S_FALSE;
}

BOOL CMFCBaseAccessibleObject::OnSetAccData(long /*lVal*/)
{
	return FALSE;
}

BOOL CMFCBaseAccessibleObject::SetACCData(CWnd* /*pParent*/, CAccessibilityData& /*data*/)
{ 
	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// CMFCRibbonSeparator

IMPLEMENT_DYNCREATE(CMFCRibbonSeparator, CMFCRibbonBaseElement)

CMFCRibbonSeparator::CMFCRibbonSeparator(BOOL bIsHoriz)
{
	m_bIsHoriz = bIsHoriz;
}

CSize CMFCRibbonSeparator::GetRegularSize(CDC* /*pDC*/)
{
	ASSERT_VALID(this);
	return CSize(4, 4);
}

void CMFCRibbonSeparator::CopyFrom(const CMFCRibbonBaseElement& s)
{
	ASSERT_VALID(this);
	CMFCRibbonBaseElement::CopyFrom(s);

	const CMFCRibbonSeparator& src =(const CMFCRibbonSeparator&) s;
	m_bIsHoriz = src.m_bIsHoriz;
}

void CMFCRibbonSeparator::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	CRect rect = m_rect;

	if (m_bQuickAccessMode)
	{
		rect.left = rect.CenterPoint().x - 1;
		rect.right = rect.left + 2;

		rect.DeflateRect(0, 3);

		CMFCVisualManager::GetInstance()->OnDrawRibbonQuickAccessToolBarSeparator(pDC, this, rect);
		return;
	}

	if (m_bIsHoriz)
	{
		rect.top = rect.CenterPoint().y;
		rect.bottom = rect.top + 1;
	}
	else
	{
		rect.left = rect.CenterPoint().x;
		rect.right = rect.left + 1;

		rect.DeflateRect(0, 5);
	}

	CBasePane* pParentBar = NULL;

	if (m_pParentMenu != NULL)
	{
		pParentBar = m_pParentMenu;
	}
	else
	{
		pParentBar = GetTopLevelRibbonBar();
	}

	if (pParentBar != NULL)
	{
		BOOL bDisableSideBarInXPMode = FALSE;

		if (m_bIsDefaultMenuLook && m_pParentMenu != NULL)
		{
			bDisableSideBarInXPMode = m_pParentMenu->m_bDisableSideBarInXPMode;
			rect.left += 2 * CMFCVisualManager::GetInstance()->GetMenuImageMargin() + 2;
			m_pParentMenu->m_bDisableSideBarInXPMode = FALSE;
		}

		CMFCVisualManager::GetInstance()->OnDrawSeparator(pDC, pParentBar, rect, !m_bIsHoriz);

		if (m_pParentMenu != NULL)
		{
			m_pParentMenu->m_bDisableSideBarInXPMode = bDisableSideBarInXPMode;
		}
	}
}

int CMFCRibbonSeparator::AddToListBox(CMFCRibbonCommandsListBox* pWndListBox, BOOL /*bDeep*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pWndListBox);
	ENSURE(pWndListBox->GetSafeHwnd() != NULL);

	CString strText;
	ENSURE(strText.LoadString(IDS_AFXBARRES_QAT_SEPARATOR));

	int nIndex = pWndListBox->AddString(_T(" ") + strText);	// Should be always first!
	pWndListBox->SetItemData(nIndex, (DWORD_PTR) this);

	return nIndex;
}

void CMFCRibbonSeparator::OnDrawOnList(CDC* pDC, CString strText, int nTextOffset, CRect rect, BOOL /*bIsSelected*/, BOOL /*bHighlighted*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	BOOL bIsDisabled = m_bIsDisabled;
	m_bIsDisabled = FALSE;

	const int nXMargin = 3;

	rect.DeflateRect(nXMargin, 0);
	rect.left += nTextOffset;

	pDC->DrawText(strText, rect, DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);

	m_bIsDisabled = bIsDisabled;
}

//////////////////////////////////////////////////////////////////////
// CMFCRibbonBaseElement

IMPLEMENT_DYNAMIC(CMFCRibbonBaseElement, CMFCBaseAccessibleObject)

CMFCRibbonBaseElement::CMFCRibbonBaseElement()
{
	m_Location = RibbonElementNotInGroup;
	m_nID = 0;
	m_dwData = 0;
	m_rect.SetRectEmpty();
	m_pParent = NULL;
	m_pParentGroup = NULL;
	m_pParentMenu = NULL;
	m_bCompactMode = FALSE;
	m_bIntermediateMode = FALSE;
	m_bFloatyMode = FALSE;
	m_bQuickAccessMode = FALSE;
	m_bIsHighlighted = FALSE;
	m_bIsFocused = FALSE;
	m_bIsPressed = FALSE;
	m_bIsDisabled = FALSE;
	m_bIsChecked = FALSE;
	m_bIsRadio = FALSE;
	m_bIsDroppedDown = FALSE;
	m_pOriginal = NULL;
	m_pRibbonBar = NULL;
	m_nRow = -1;
	m_bDontNotify = FALSE;
	m_bTextAlwaysOnRight = FALSE;
	m_pPopupMenu = NULL;
	m_nImageOffset = 0;
	m_bShowGroupBorder = FALSE;
	m_bIsVisible = TRUE;
	m_bIsDefaultMenuLook = FALSE;
	m_bIsAlwaysLarge = FALSE;
	m_bDrawDefaultIcon = TRUE;
	m_bIsOnPaletteTop = FALSE;
	m_bOnBeforeShowItemMenuIsSent = FALSE;
	m_bEnableUpdateTooltipInfo   = TRUE;
	m_bEnableTooltipInfoShortcut = TRUE;
	m_bIsTabElement = FALSE;
}

CMFCRibbonBaseElement::~CMFCRibbonBaseElement()
{
	if (m_pPopupMenu != NULL)
	{
		ASSERT_VALID(m_pPopupMenu);
		ENSURE(m_pPopupMenu->m_pParentRibbonElement == this);

		m_pPopupMenu->m_pParentRibbonElement = NULL;
		ClosePopupMenu();
	}
}

void CMFCRibbonBaseElement::SetID(UINT nID)
{
	ASSERT_VALID(this);
	m_nID = nID;
}

void CMFCRibbonBaseElement::SetText(LPCTSTR lpszText)
{
	ASSERT_VALID(this);
	m_strText = lpszText == NULL ? _T("") : lpszText;

	int nIndex = m_strText.Find(_T('\n'));
	if (nIndex >= 0)
	{
		m_strKeys = m_strText.Mid(nIndex + 1);
		m_strText = m_strText.Left(nIndex);
	}

	m_strText.TrimLeft();
	m_strText.TrimRight();
}

void CMFCRibbonBaseElement::SetKeys(LPCTSTR lpszKeys, LPCTSTR lpszMenuKeys)
{
	ASSERT_VALID(this);

	m_strKeys = lpszKeys == NULL ? _T("") : lpszKeys;
	m_strMenuKeys = lpszMenuKeys == NULL ? _T("") : lpszMenuKeys;
}

void CMFCRibbonBaseElement::SetTextAlwaysOnRight(BOOL bSet)
{
	ASSERT_VALID(this);
	m_bTextAlwaysOnRight = bSet;
}

void CMFCRibbonBaseElement::OnLButtonDown(CPoint /*point*/)
{
	CMFCRibbonPanel* pPanel = GetParentPanel();
	if (pPanel != NULL)
	{
		ASSERT_VALID(pPanel);

		CMFCRibbonBaseElement* pDroppedDown = pPanel->GetDroppedDown();
		if (pDroppedDown != NULL)
		{
			ASSERT_VALID(pDroppedDown);
			pDroppedDown->ClosePopupMenu();
		}
	}

	if (m_pParentMenu != NULL)
	{
		return;
	}

	if (m_pRibbonBar != NULL)
	{
		ASSERT_VALID(m_pRibbonBar);

		CMFCRibbonBaseElement* pDroppedDown = m_pRibbonBar->GetDroppedDown();
		if (pDroppedDown != NULL)
		{
			ASSERT_VALID(pDroppedDown);
			pDroppedDown->ClosePopupMenu();
		}
	}

	if (m_pParent != NULL)
	{
		ASSERT_VALID(m_pParent);

		CMFCRibbonBaseElement* pDroppedDown = m_pParent->GetDroppedDown();
		if (pDroppedDown != NULL)
		{
			ASSERT_VALID(pDroppedDown);
			pDroppedDown->ClosePopupMenu();
		}
	}
}

void CMFCRibbonBaseElement::OnUpdateCmdUI(CMFCRibbonCmdUI* pCmdUI, CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	ASSERT_VALID(this);
	ENSURE(pCmdUI != NULL);

	if (m_nID == 0 || IsSystemCommand(m_nID) ||
		m_nID >= AFX_IDM_FIRST_MDICHILD)
	{
		return;
	}

	pCmdUI->m_pUpdated = this;

	pCmdUI->m_nID = m_nID;
	pCmdUI->DoUpdate(pTarget, bDisableIfNoHndler);

	pCmdUI->m_pUpdated = NULL;
}

BOOL CMFCRibbonBaseElement::NotifyControlCommand(BOOL bAccelerator, int nNotifyCode, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(bAccelerator);
	UNREFERENCED_PARAMETER(nNotifyCode);
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);

	return FALSE;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::HitTest(CPoint /*point*/)
{
	ASSERT_VALID(this);
	return this;
}

CMFCRibbonBar* CMFCRibbonBaseElement::GetTopLevelRibbonBar() const
{
	ASSERT_VALID(this);

	if (m_pRibbonBar != NULL)
	{
		ASSERT_VALID(m_pRibbonBar);
		return m_pRibbonBar;
	}

	if (m_pParent != NULL)
	{
		ASSERT_VALID(m_pParent);

		if (m_pParent->GetParentRibbonBar() != NULL)
		{
			ASSERT_VALID(m_pParent->GetParentRibbonBar());
			return m_pParent->GetParentRibbonBar();
		}
	}

	if (m_pParentMenu != NULL)
	{
		ASSERT_VALID(m_pParentMenu);
		return m_pParentMenu->GetTopLevelRibbonBar();
	}

	return NULL;
}

void CMFCRibbonBaseElement::SetDroppedDown(CMFCPopupMenu* pPopupMenu)
{
	ASSERT_VALID(this);

	m_pPopupMenu = pPopupMenu;

	if (pPopupMenu != NULL)
	{
		ASSERT_VALID(pPopupMenu);
		pPopupMenu->SetParentRibbonElement(this);
	}
	else
	{
		NotifyHighlightListItem(-1);
	}

	BOOL bWasDroppedDown = m_bIsDroppedDown;
	m_bIsDroppedDown = pPopupMenu != NULL;

	if (!m_bIsDroppedDown)
	{
		m_bIsHighlighted = m_bIsPressed = FALSE;
	}

	if (bWasDroppedDown != m_bIsDroppedDown)
	{
		Redraw();
	}

	if (m_pParentMenu->GetSafeHwnd() != NULL && pPopupMenu == NULL)
	{
		ASSERT_VALID(m_pParentMenu);
		ASSERT_VALID(m_pParentMenu->GetParent());

		CMFCPopupMenu::m_pActivePopupMenu = (CMFCPopupMenu*) m_pParentMenu->GetParent();
	}

	m_bOnBeforeShowItemMenuIsSent = FALSE;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::Find(const CMFCRibbonBaseElement* pElement)
{
	ASSERT_VALID(this);
	return (pElement == this) ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::FindByID(UINT uiCmdID)
{
	ASSERT_VALID(this);
	return (m_nID == uiCmdID) ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::FindByData(DWORD_PTR dwData)
{
	ASSERT_VALID(this);
	return (m_dwData == dwData) ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::FindByOriginal(CMFCRibbonBaseElement* pOriginal)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pOriginal);
	return (m_pOriginal == pOriginal) ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::GetPressed()
{
	ASSERT_VALID(this);
	return IsPressed() ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::GetDroppedDown()
{
	ASSERT_VALID(this);
	return IsDroppedDown() ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::GetHighlighted()
{
	ASSERT_VALID(this);
	return IsHighlighted() ? this : NULL;
}

CMFCRibbonBaseElement* CMFCRibbonBaseElement::GetFocused()
{
	ASSERT_VALID(this);

	return IsFocused() ? this : NULL;
}

BOOL CMFCRibbonBaseElement::ReplaceByID(UINT uiCmdID, CMFCRibbonBaseElement* pElem)
{
	ASSERT_VALID(this);
	UNREFERENCED_PARAMETER(uiCmdID);
	UNREFERENCED_PARAMETER(pElem);

	return FALSE;
}

void CMFCRibbonBaseElement::SetParentCategory(CMFCRibbonCategory* pParent)
{
	ASSERT_VALID(this);
	m_pParent = pParent;
}

void CMFCRibbonBaseElement::CopyFrom(const CMFCRibbonBaseElement& src)
{
	ASSERT_VALID(this);

	m_nID = src.m_nID;
	m_dwData = src.m_dwData;
	m_bTextAlwaysOnRight = src.m_bTextAlwaysOnRight;
	m_strText = src.m_strText;
	m_strKeys = src.m_strKeys;
	m_strMenuKeys = src.m_strMenuKeys;
	m_pParent = src.m_pParent;
	m_pParentGroup = src.m_pParentGroup;
	m_strToolTip = src.m_strToolTip;
	m_strDescription = src.m_strDescription;
	m_bQuickAccessMode = src.m_bQuickAccessMode;
	m_bIsVisible = src.m_bIsVisible;
	m_bIsDefaultMenuLook = src.m_bIsDefaultMenuLook;
	m_bIsRadio = src.m_bIsRadio;
	m_bIsAlwaysLarge = src.m_bIsAlwaysLarge;
	m_bIsOnPaletteTop = src.m_bIsOnPaletteTop;
	m_bEnableUpdateTooltipInfo = src.m_bEnableUpdateTooltipInfo;
	m_bEnableTooltipInfoShortcut = src.m_bEnableTooltipInfoShortcut;
}

void CMFCRibbonBaseElement::SetParentMenu(CMFCRibbonPanelMenuBar* pMenuBar)
{
	ASSERT_VALID(this);

	m_pParentMenu = pMenuBar;
}

void CMFCRibbonBaseElement::SetOriginal(CMFCRibbonBaseElement* pOriginal)
{
	ASSERT_VALID(this);

	if (pOriginal != NULL)
	{
		ASSERT_VALID(pOriginal);

		while (pOriginal->m_pOriginal != NULL)
		{
			pOriginal = pOriginal->m_pOriginal;
		}
	}

	m_pOriginal = pOriginal;
}

CWnd* CMFCRibbonBaseElement::GetParentWnd() const
{
	ASSERT_VALID(this);

	if (m_pRibbonBar != NULL)
	{
		ASSERT_VALID(m_pRibbonBar);
		return m_pRibbonBar;
	}
	else if (m_pParentMenu != NULL)
	{
		ASSERT_VALID(m_pParentMenu);
		return m_pParentMenu;
	}
	else if (m_pParent != NULL)
	{
		ASSERT_VALID(m_pParent);
		ASSERT_VALID(m_pParent->GetParentRibbonBar());

		return m_pParent->GetParentRibbonBar();
	}

	return NULL;
}

CMFCRibbonPanel* CMFCRibbonBaseElement::GetParentPanel() const
{
	ASSERT_VALID(this);

	if (m_pParentMenu != NULL)
	{
		ASSERT_VALID(m_pParentMenu);

		if (m_pParentMenu->m_pCategory != NULL)
		{
			ASSERT_VALID(m_pParentMenu->m_pCategory);
			return m_pParentMenu->m_pCategory->FindPanelWithElem(this);
		}

		return m_pParentMenu->m_pPanel;
	}
	else if (m_pParent != NULL)
	{
		ASSERT_VALID(m_pParent);
		return m_pParent->FindPanelWithElem(this);
	}

	return NULL;
}

BOOL CMFCRibbonBaseElement::IsMenuMode() const
{
	ASSERT_VALID(this);

	if (m_pParentMenu != NULL)
	{
		ASSERT_VALID(m_pParentMenu);

		if (m_pParentMenu->m_pPanel == NULL)
		{
			return FALSE;
		}

		ASSERT_VALID(m_pParentMenu->m_pPanel);

		return m_pParentMenu->m_pPanel->IsMenuMode();
	}

	return FALSE;
}

void CMFCRibbonBaseElement::Redraw()
{
	ASSERT_VALID(this);

	if (m_rect.IsRectEmpty())
	{
		return;
	}

	if (m_pParentMenu->GetSafeHwnd() != NULL)
	{
		m_pParentMenu->RedrawWindow(m_rect);
		return;
	}

	CWnd* pWndParent = GetParentWnd();

	if (pWndParent->GetSafeHwnd() != NULL)
	{
		pWndParent->RedrawWindow(m_rect);
	}
}

CString CMFCRibbonBaseElement::GetToolTipText() const
{
	ASSERT_VALID(this);

	if (IsDroppedDown())
	{
		return _T("");
	}

	CString strTipText = m_strToolTip;

	if (m_bQuickAccessMode && strTipText.IsEmpty())
	{
		strTipText = m_strText;
		strTipText.Replace(_T("&&"), AFX_DUMMY_AMPERSAND_SEQUENCE);
		strTipText.Remove(_T('&'));
		strTipText.Replace(AFX_DUMMY_AMPERSAND_SEQUENCE, _T("&"));
	}

	//--------------------
	// Add shortcut label:
	//--------------------
	CWnd* pWndParent = NULL;

	if (m_pRibbonBar != NULL)
	{
		pWndParent = m_pRibbonBar;
	}
	else if (m_pParentMenu != NULL)
	{
		pWndParent = m_pParentMenu;
	}
	else if (m_pParent != NULL)
	{
		ASSERT_VALID(m_pParent);
		pWndParent = m_pParent->GetParentRibbonBar();
	}

	if (m_bEnableTooltipInfoShortcut)
	{
		CString strLabel;
		CFrameWnd* pParentFrame = AFXGetParentFrame(pWndParent) == NULL ? NULL : AFXGetTopLevelFrame(AFXGetParentFrame(pWndParent));

		if (pParentFrame != NULL && (CKeyboardManager::FindDefaultAccelerator(m_nID, strLabel, pParentFrame, TRUE) ||
			CKeyboardManager::FindDefaultAccelerator(m_nID, strLabel, pParentFrame->GetActiveFrame(), FALSE)))
		{
			strTipText += _T(" (");
			strTipText += strLabel;
			strTipText += _T(')');
		}
	}

	return strTipText;
}

CString CMFCRibbonBaseElement::GetDescription() const
{
	ASSERT_VALID(this);
	return m_strDescription;
}

void CMFCRibbonBaseElement::SetToolTipText(LPCTSTR lpszText)
{
	ASSERT_VALID(this);
	m_strToolTip = lpszText == NULL ? _T("") : lpszText;
}

void CMFCRibbonBaseElement::SetDescription(LPCTSTR lpszText)
{
	ASSERT_VALID(this);
	m_strDescription = lpszText == NULL ? _T("") : lpszText;
}

void CMFCRibbonBaseElement::EnableUpdateTooltipInfo(BOOL bEnable)
{
	if (m_bEnableUpdateTooltipInfo != bEnable)
	{
		m_bEnableUpdateTooltipInfo = bEnable;

		if (m_bEnableUpdateTooltipInfo)
		{
			UpdateTooltipInfo();
		}
	}
}

void CMFCRibbonBaseElement::EnableTooltipInfoShortcut(BOOL bEnable)
{
	m_bEnableTooltipInfoShortcut = bEnable;
}

void CMFCRibbonBaseElement::UpdateTooltipInfo()
{
	ASSERT_VALID(this);

	if (!m_bEnableUpdateTooltipInfo || m_nID == 0 || m_nID == (UINT)-1)
	{
		return;
	}

	CString strText;
	if (!strText.LoadString(m_nID))
	{
		return;
	}

	m_strToolTip.Empty();
	m_strDescription.Empty();

	if (strText.IsEmpty())
	{
		return;
	}

	AfxExtractSubString(m_strDescription, strText, 0);
	AfxExtractSubString(m_strToolTip, strText, 1, '\n');

	m_strToolTip.Replace(_T("&&"), AFX_DUMMY_AMPERSAND_SEQUENCE);
	m_strToolTip.Remove(_T('&'));
	m_strToolTip.Replace(AFX_DUMMY_AMPERSAND_SEQUENCE, _T("&"));
}

void CMFCRibbonBaseElement::OnAfterChangeRect(CDC* /*pDC*/)
{
	ASSERT_VALID(this);

	if (m_strToolTip.IsEmpty())
	{
		UpdateTooltipInfo();
	}
}

BOOL CMFCRibbonBaseElement::NotifyCommand(BOOL bWithDelay)
{
	ASSERT_VALID(this);

	if (m_pOriginal != NULL)
	{
		if (m_bQuickAccessMode && (m_bIsHighlighted || m_bIsPressed || m_bIsFocused))
		{
			m_bIsHighlighted = m_bIsPressed = m_bIsFocused = FALSE;
			Redraw();
		}

		ASSERT_VALID(m_pOriginal);
		return m_pOriginal->NotifyCommand(bWithDelay);
	}

	UINT uiID = GetNotifyID();

	if (uiID == 0 || uiID == (UINT)-1)
	{
		return FALSE;
	}

	CMFCRibbonBar* pRibbonBar = GetTopLevelRibbonBar();
	if (pRibbonBar == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pRibbonBar);

	CWnd* pWndParent = pRibbonBar->GetParent();
	if (pWndParent == NULL)
	{
		return FALSE;
	}

	m_bIsHighlighted = m_bIsPressed = m_bIsFocused = FALSE;

	Redraw();

	ASSERT_VALID(pWndParent);

	if (uiID == AFX_IDM_FIRST_MDICHILD)
	{
		HWND hwndMDIChild = (HWND) m_dwData;

		if (::IsWindow(hwndMDIChild))
		{
			CMFCRibbonBar* pTopLevelRibbon = GetTopLevelRibbonBar();
			if (pTopLevelRibbon != NULL)
			{
				CMDIFrameWndEx* pMDIFrameWnd = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pTopLevelRibbon->GetTopLevelFrame());

				if (pMDIFrameWnd != NULL)
				{
					WINDOWPLACEMENT	wndpl;
					wndpl.length = sizeof(WINDOWPLACEMENT);
					::GetWindowPlacement(hwndMDIChild,&wndpl);

					if (wndpl.showCmd == SW_SHOWMINIMIZED)
					{
						::ShowWindow(hwndMDIChild, SW_RESTORE);
					}

					if (bWithDelay)
					{
						::PostMessage(pMDIFrameWnd->m_hWndMDIClient, WM_MDIACTIVATE, (WPARAM) hwndMDIChild, 0);
					}
					else
					{
						::SendMessage(pMDIFrameWnd->m_hWndMDIClient, WM_MDIACTIVATE, (WPARAM) hwndMDIChild, 0);
					}

					return TRUE;
				}
			}
		}
	}

	if (bWithDelay)
	{
		pWndParent->PostMessage(WM_COMMAND, uiID);
	}
	else
	{
		pWndParent->SendMessage(WM_COMMAND, uiID);
	}

	return TRUE;
}

void CMFCRibbonBaseElement::PostMenuCommand(UINT /*uiCmdId*/)
{
	ASSERT_VALID(this);

	m_bIsDroppedDown = FALSE;
	Redraw();

	if (m_pParentMenu != NULL)
	{
		ASSERT_VALID(m_pParentMenu);
		m_pParentMenu->GetParent()->SendMessage(WM_CLOSE);
	}
}

void CMFCRibbonBaseElement::GetElementsByID(UINT uiCmdID, CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
{
	ASSERT_VALID(this);

	if (uiCmdID == m_nID)
	{
		arElements.Add(this);
	}
}

void CMFCRibbonBaseElement::GetItemIDsList(CList<UINT,UINT>& lstItems) const
{
	ASSERT_VALID(this);

	if (m_nID != 0 && m_nID != (UINT)-1 && lstItems.Find(m_nID) == NULL)
	{
		lstItems.AddTail(m_nID);
	}
}

int CMFCRibbonBaseElement::AddToListBox(CMFCRibbonCommandsListBox* pWndListBox, BOOL /*bDeep*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pWndListBox);
	ENSURE(pWndListBox->GetSafeHwnd() != NULL);

	if (m_nID == 0 || m_nID == (UINT)-1)
	{
		return -1;
	}

	if (m_nID >= ID_FILE_MRU_FILE1 && m_nID <= ID_FILE_MRU_FILE16)
	{
		return -1;
	}

	for (int i = 0; i < pWndListBox->GetCount (); i++)
	{
		CMFCRibbonBaseElement* pItem = (CMFCRibbonBaseElement*) pWndListBox->GetItemData (i);
		if (pItem == NULL)
		{
			continue;
		}

		ASSERT_VALID(pItem);

		if (pItem->m_nID == m_nID && (!pItem->HasMenu() || pWndListBox->CommandsOnly()))
		{
			// Already exist, don't add it
			return -1;
		}
	}


	UpdateTooltipInfo();

	CString strText = m_strToolTip;
	if (strText.IsEmpty())
	{
		strText = GetText();
	}

	strText.Replace(_T("&&"), AFX_DUMMY_AMPERSAND_SEQUENCE);
	strText.Remove(_T('&'));
	strText.Replace(AFX_DUMMY_AMPERSAND_SEQUENCE, _T("&"));

	int nIndex = pWndListBox->AddString(strText);
	pWndListBox->SetItemData(nIndex, (DWORD_PTR) this);

	return nIndex;
}

void CMFCRibbonBaseElement::OnDrawOnList(CDC* pDC, CString strText, int nTextOffset, CRect rect, BOOL /*bIsSelected*/, BOOL /*bHighlighted*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	BOOL bIsDisabled = m_bIsDisabled;
	m_bIsDisabled = FALSE;

	if (m_bDrawDefaultIcon)
	{
		CRect rectImage = rect;
		rectImage.right = rect.left + nTextOffset;

		CMFCVisualManager::GetInstance()->OnDrawDefaultRibbonImage(pDC, rectImage);
	}

	CRect rectText = rect;

	rectText.left += nTextOffset;

	const int nXMargin = 3;
	rectText.DeflateRect(nXMargin, 0);

	pDC->DrawText(strText, rectText, DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);
	m_bIsDisabled = bIsDisabled;
}

void CMFCRibbonBaseElement::ClosePopupMenu()
{
	ASSERT_VALID(this);

	if (m_pPopupMenu != NULL && ::IsWindow(m_pPopupMenu->m_hWnd))
	{
		if (m_pPopupMenu->InCommand())
		{
			return;
		}

		m_pPopupMenu->m_bAutoDestroyParent = FALSE;
		m_pPopupMenu->CloseMenu();
	}

	m_pPopupMenu = NULL;
	m_bOnBeforeShowItemMenuIsSent = FALSE;
}

BOOL CMFCRibbonBaseElement::CanBeAddedToQuickAccessToolBar() const
{
	ASSERT_VALID(this);

	return m_nID != 0 && m_nID != (UINT)-1 && !IsStandardCommand(m_nID);
}

BOOL CMFCRibbonBaseElement::OnAddToQAToolbar(CMFCRibbonQuickAccessToolBar& qat)
{
	qat.Add(this);
	return TRUE;
}

BOOL CMFCRibbonBaseElement::StretchToWholeRow(CDC* /*pDC*/, int nHeight)
{
	ASSERT_VALID(this);

	if (!CanBeStretched() || m_bCompactMode || m_bIntermediateMode)
	{
		return FALSE;
	}

	m_rect.bottom = m_rect.top + nHeight;
	return TRUE;
}

BOOL CMFCRibbonBaseElement::SetACCData(CWnd* pParent, CAccessibilityData& data)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pParent);

	data.Clear();

	data.m_strAccName = m_strText.IsEmpty() ? m_strToolTip : m_strText;
	data.m_strAccName.Remove(_T('&'));
	data.m_strAccName.Trim();

	data.m_nAccRole = IsMenuMode() ? ROLE_SYSTEM_MENUITEM : ROLE_SYSTEM_PUSHBUTTON;

	data.m_strDescription = m_strDescription;
	data.m_nAccHit = 1;
	data.m_strAccDefAction = IsMenuMode () ? _T("Execute") : _T("Press");

	data.m_bAccState = STATE_SYSTEM_FOCUSABLE;
	if (IsChecked())
	{
		data.m_bAccState |= STATE_SYSTEM_CHECKED;
	}

	if (IsDisabled())
	{
		data.m_bAccState |= STATE_SYSTEM_UNAVAILABLE;
	}

	if (IsPressed() || IsMenuMode() && IsHighlighted())
	{
		data.m_bAccState |= STATE_SYSTEM_FOCUSED;
	}

	data.m_rectAccLocation = m_rect;
	pParent->ClientToScreen(&data.m_rectAccLocation);

	if (IsSeparator())
	{
		data.m_strAccName =  m_strText.IsEmpty() ?  _T("Separator") : m_strText;
		data.m_nAccRole = ROLE_SYSTEM_SEPARATOR;
		data.m_bAccState = STATE_SYSTEM_NORMAL;
		data.m_strAccDefAction.Empty();

		return TRUE;
	}

	CString strKeys = m_strKeys;

	if (!m_bQuickAccessMode && m_pParentMenu != NULL && strKeys.GetLength() < 2)
	{
		// Try to find key from label:
		int nIndexAmp = m_strText.Find(_T('&'));

		if (nIndexAmp >= 0 && nIndexAmp < m_strText.GetLength() - 1 && m_strText[nIndexAmp + 1] != _T('&'))
		{
			strKeys = m_strText.Mid(nIndexAmp + 1, 1);
		}
	}

	if (!strKeys.IsEmpty())
	{
		data.m_strAccKeys = _T("Alt, ");

		if (m_pParent != NULL)
		{
			ASSERT_VALID(m_pParent);
			data.m_strAccKeys += m_pParent->m_Tab.m_strKeys + _T(", ");
		}

		data.m_strAccKeys += strKeys;
	}

	return TRUE;
}

void CMFCRibbonBaseElement::OnAccDefaultAction()
{
	NotifyCommand(TRUE);	
}

void CMFCRibbonBaseElement::OnDrawKeyTip(CDC* pDC, const CRect& rect, BOOL bIsMenu)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (m_strKeys.IsEmpty())
	{
		return;
	}

	CMFCVisualManager::GetInstance()->OnDrawRibbonKeyTip(pDC, this, rect, bIsMenu ? m_strMenuKeys : m_strKeys);
}

CSize CMFCRibbonBaseElement::GetKeyTipSize(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	if (!m_bQuickAccessMode && m_pParentMenu != NULL && m_strKeys.GetLength() < 2)
	{
		// Try to find key from label:
		int nIndexAmp = m_strText.Find(_T('&'));

		if (nIndexAmp >= 0 && nIndexAmp < m_strText.GetLength() - 1 && m_strText [nIndexAmp + 1] != _T('&'))
		{
			m_strKeys = m_strText.Mid(nIndexAmp + 1, 1);
		}
	}

	if (m_strKeys.IsEmpty())
	{
		return CSize(0, 0);
	}

	const CString strMin = _T("O");

	CSize sizeMin = pDC->GetTextExtent(strMin);
	CSize sizeText = pDC->GetTextExtent(m_strKeys);

	sizeText.cx = max(sizeText.cx, sizeMin.cx);
	sizeText.cy = max(sizeText.cy, sizeMin.cy);

	return CSize(sizeText.cx + 10, sizeText.cy + 2);
}

BOOL CMFCRibbonBaseElement::OnKey(BOOL bIsMenuKey)
{
	ASSERT_VALID(this);

	if (m_bIsDisabled)
	{
		return FALSE;
	}

	if (m_rect.IsRectEmpty())
	{
		CMFCRibbonPanel* pParentPanel = GetParentPanel();
		if (pParentPanel != NULL)
		{
			ASSERT_VALID(pParentPanel);

			if (pParentPanel->IsCollapsed())
			{
				if (!HasMenu())
				{
					if (!NotifyCommand(TRUE))
					{
						return FALSE;
					}

					if (m_pParentMenu != NULL)
					{
						CMFCRibbonBar* pTopLevelRibbon = GetTopLevelRibbonBar();

						// Close menu:
						ASSERT_VALID(m_pParentMenu);

						CFrameWnd* pParentFrame = AFXGetParentFrame(m_pParentMenu);
						ASSERT_VALID(pParentFrame);

						pParentFrame->DestroyWindow();

						if (pTopLevelRibbon != NULL && pTopLevelRibbon->GetTopLevelFrame() != NULL)
						{
							pTopLevelRibbon->GetTopLevelFrame()->SetFocus();
						}
					}

					return TRUE;
				}
				else
				{
					CMFCRibbonBar* pTopLevelRibbon = GetTopLevelRibbonBar();
					if (pTopLevelRibbon != NULL)
					{
						pTopLevelRibbon->HideKeyTips();
					}

					CMFCRibbonPanelMenu* pPopup = pParentPanel->ShowPopup();
					if (pPopup != NULL)
					{
						ASSERT_VALID(pPopup);

						CMFCRibbonBaseElement* pPopupElem = pPopup->FindByOrigin(this);
						if (pPopupElem != NULL)
						{
							ASSERT_VALID(pPopupElem);
							return pPopupElem->OnKey(bIsMenuKey);
						}
					}
				}
			}
		}

		return FALSE;
	}

	return NotifyCommand(TRUE);
}

void CMFCRibbonBaseElement::AddToKeyList(CArray<CMFCRibbonKeyTip*,CMFCRibbonKeyTip*>& arElems)
{
	ASSERT_VALID(this);

	arElems.Add(new CMFCRibbonKeyTip(this));

	if (!m_strMenuKeys.IsEmpty() && HasMenu())
	{
		arElems.Add(new CMFCRibbonKeyTip(this, TRUE));
	}
}

int CMFCRibbonBaseElement::GetDropDownImageWidth() const
{
	ASSERT_VALID(this);

	return CMenuImages::Size().cx;
}

void CMFCRibbonBaseElement::NotifyHighlightListItem(int nIndex)
{
	ASSERT_VALID(this);

	CMFCRibbonBar* pRibbonBar = GetTopLevelRibbonBar();
	if (pRibbonBar == NULL)
	{
		return;
	}

	ASSERT_VALID(pRibbonBar);

	CWnd* pWndParent = pRibbonBar->GetParent();
	if (pWndParent == NULL)
	{
		return;
	}

	pWndParent->SendMessage(AFX_WM_ON_HIGHLIGHT_RIBBON_LIST_ITEM, (WPARAM)nIndex, (LPARAM)this);
}

void CMFCRibbonBaseElement::OnShowPopupMenu()
{
	ASSERT_VALID(this);

	CMFCRibbonBar* pRibbonBar = GetTopLevelRibbonBar();
	if (pRibbonBar == NULL)
	{
		return;
	}

	ASSERT_VALID(pRibbonBar);

	CWnd* pWndParent = pRibbonBar->GetParent();
	if (pWndParent == NULL)
	{
		return;
	}

	if (!m_bOnBeforeShowItemMenuIsSent)
	{
		m_bOnBeforeShowItemMenuIsSent = TRUE;
		pWndParent->SendMessage(AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU, (WPARAM)0, (LPARAM)this);
	}
}

void CMFCRibbonBaseElement::GetVisibleElements(CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements)
{
	ASSERT_VALID(this);

	if (!m_rect.IsRectEmpty())
	{
		arElements.Add(this);
	}
}

HRESULT CMFCRibbonBaseElement::get_accParent(IDispatch **ppdispParent)
{
	if (!ppdispParent)
	{
		return E_INVALIDARG;
	}

	*ppdispParent = NULL;

	if (!IsTabElement() || m_pRibbonBar->GetSafeHwnd() == NULL)
	{
		return S_FALSE;
	}

	LPDISPATCH lpDispatch = m_pRibbonBar->GetAccessibleDispatch();
	if (lpDispatch != NULL)
	{
		*ppdispParent = lpDispatch;
	}

	return S_OK;
}

HRESULT CMFCRibbonBaseElement::accLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild)
{
	if (!pxLeft || !pyTop || !pcxWidth || !pcyHeight)
	{
		return E_INVALIDARG;
	}

	if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF)
	{		
		CRect rectLocation = m_rect;
		
		CWnd* pParentWnd = m_pRibbonBar;
		if (pParentWnd->GetSafeHwnd() == NULL)
		{
			pParentWnd = GetParentWnd();
			if (pParentWnd->GetSafeHwnd() == NULL)
			{
				return S_FALSE;
			}
		}

		pParentWnd->ClientToScreen(&rectLocation);

		*pxLeft = rectLocation.left;
		*pyTop = rectLocation.top;
		*pcxWidth = rectLocation.Width();
		*pcyHeight = rectLocation.Height();

		return S_OK;
	}

	if (varChild.vt == VT_I4 && varChild.lVal > 0)
	{
		OnSetAccData(varChild.lVal);

		*pxLeft = m_AccData.m_rectAccLocation.left;
		*pyTop = m_AccData.m_rectAccLocation.top;
		*pcxWidth = m_AccData.m_rectAccLocation.Width();
		*pcyHeight = m_AccData.m_rectAccLocation.Height();

		return S_OK;
	}

	return S_FALSE;
}

HRESULT CMFCRibbonBaseElement::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt)
{
	if (!IsTabElement())
	{
		return S_FALSE;
	}

	pvarEndUpAt->vt = VT_EMPTY;

	if (varStart.vt != VT_I4)
	{
		return E_INVALIDARG;
	}

	CMFCRibbonButtonsGroup* pGroup = GetParentGroup();
	if (pGroup == NULL)
	{
		return S_FALSE;
	}

	ASSERT_VALID(pGroup);

	switch (navDir)
	{
	case NAVDIR_NEXT:   
	case NAVDIR_RIGHT:
		if (varStart.lVal == CHILDID_SELF)
		{
			int nIndex = pGroup->GetButtonIndex(this) + 1;
			if (nIndex < pGroup->GetCount())
			{	
				CMFCRibbonBaseElement* pElement = pGroup->GetButton(nIndex);
				if (pElement != NULL)
				{
					ASSERT_VALID(pElement);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pElement->GetIDispatch(TRUE);

					return S_OK;
				}
			}
			else
			{
				CMFCRibbonCategory* pCategory = m_pRibbonBar->GetActiveCategory();
				if (pCategory != NULL)
				{
					ASSERT_VALID(pCategory);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pCategory->GetIDispatch(TRUE);

					return S_OK;
				}
			}
		}
		break;

	case NAVDIR_PREVIOUS: 
	case NAVDIR_LEFT:
		if (varStart.lVal == CHILDID_SELF)
		{
			int nIndex = pGroup->GetButtonIndex(this) - 1;
			if (nIndex >= 0)
			{	
				CMFCRibbonBaseElement* pElement = pGroup->GetButton(nIndex);
				if (pElement != NULL)
				{
					ASSERT_VALID (pElement);

					pvarEndUpAt->vt = VT_DISPATCH;
					pvarEndUpAt->pdispVal = pElement->GetIDispatch(TRUE);

					return S_OK;
				}
			}
			else
			{
				CMFCRibbonTabsGroup* pTabs = m_pRibbonBar->GetTabs();
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

HRESULT CMFCRibbonBaseElement::accHitTest(long xLeft, long yTop, VARIANT *pvarChild)
{
	if (!pvarChild)
	{
		return E_INVALIDARG;
	}

	if (m_pRibbonBar->GetSafeHwnd() != NULL)
	{
		pvarChild->vt = VT_I4;
		pvarChild->lVal = CHILDID_SELF;

		CPoint pt(xLeft, yTop);
		m_pRibbonBar->ScreenToClient(&pt);
	}

	return S_OK;
}

HRESULT CMFCRibbonBaseElement::accDoDefaultAction(VARIANT /*varChild*/)
{
	OnAccDefaultAction();
	return S_OK;
}


