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

#include "afxlayout.h"
#include "afxext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// AFX_DYNAMIC_LAYOUT_ITEM

struct AFX_DYNAMIC_LAYOUT_ITEM
{
	struct Point
	{
		Point()
			: x(0.0)
			, y(0.0)
		{
		}

		double x;
		double y;
	};

	AFX_DYNAMIC_LAYOUT_ITEM(HWND hWnd, const CMFCDynamicLayout::MoveSettings& moveSettings, const CMFCDynamicLayout::SizeSettings& sizeSettings)
		: m_hWnd(hWnd)
		, m_moveSettings(moveSettings)
		, m_sizeSettings(sizeSettings)
	{
	}

	HWND m_hWnd;
	Point m_ptInit;
	Point m_szInit;
	CMFCDynamicLayout::MoveSettings m_moveSettings;
	CMFCDynamicLayout::SizeSettings m_sizeSettings;
};

/////////////////////////////////////////////////////////////////////////////
// CMFCDynamicLayout

IMPLEMENT_DYNAMIC(CMFCDynamicLayout, CObject)

CMFCDynamicLayout::CMFCDynamicLayout()
	: m_pHostWnd(NULL)
	, m_MinSize(0, 0)
{
}

CMFCDynamicLayout::~CMFCDynamicLayout()
{
	while (!m_listWnd.IsEmpty())
	{
		delete m_listWnd.RemoveHead();
	}
}

BOOL CMFCDynamicLayout::Create(CWnd* pHostWnd)
{
	if (pHostWnd->GetSafeHwnd() == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}
	
	m_pHostWnd = pHostWnd;
	return TRUE;
}

void CMFCDynamicLayout::Adjust()
{
	const int nCount = (int)m_listWnd.GetCount();
	if (nCount == 0)
	{
		return;
	}

	HDWP hDWP = ::BeginDeferWindowPos(nCount);

	for (POSITION pos = m_listWnd.GetHeadPosition(); pos != NULL;)
	{
		AFX_DYNAMIC_LAYOUT_ITEM* pItem = m_listWnd.GetNext(pos);
		HWND hwnd = pItem->m_hWnd;

		if (::IsWindow(hwnd))
		{
			CRect rectItem;
			UINT uiFlags = AdjustItemRect(*pItem, rectItem);

			if ((uiFlags & (SWP_NOMOVE | SWP_NOSIZE)) != (SWP_NOMOVE | SWP_NOSIZE))
			{
				::DeferWindowPos(hDWP, hwnd, HWND_TOP, rectItem.left, rectItem.top, 
					rectItem.Width(), rectItem.Height(), 
					uiFlags | SWP_NOZORDER | SWP_NOREPOSITION | SWP_NOACTIVATE | SWP_NOCOPYBITS);
			}
		}
	}

	::EndDeferWindowPos(hDWP);
}

CMFCDynamicLayout::MoveSettings CMFCDynamicLayout::MoveNone()
{
	return MoveSettings();
}

CMFCDynamicLayout::MoveSettings CMFCDynamicLayout::MoveHorizontal(int nRatio)
{
	MoveSettings settings;
	settings.m_nXRatio = nRatio;

	return settings;
}

CMFCDynamicLayout::MoveSettings CMFCDynamicLayout::MoveVertical(int nRatio)
{
	MoveSettings settings;
	settings.m_nYRatio = nRatio;

	return settings;
}

CMFCDynamicLayout::MoveSettings CMFCDynamicLayout::MoveHorizontalAndVertical(int nXRatio, int nYRatio)
{
	MoveSettings settings;

	settings.m_nXRatio = nXRatio;
	settings.m_nYRatio = nYRatio;

	return settings;
}

CMFCDynamicLayout::SizeSettings CMFCDynamicLayout::SizeNone()
{
	return SizeSettings();
}

CMFCDynamicLayout::SizeSettings CMFCDynamicLayout::SizeHorizontal(int nRatio)
{
	SizeSettings settings;
	settings.m_nXRatio = nRatio;

	return settings;
}

CMFCDynamicLayout::SizeSettings CMFCDynamicLayout::SizeVertical(int nRatio)
{
	SizeSettings settings;
	settings.m_nYRatio = nRatio;

	return settings;
}

CMFCDynamicLayout::SizeSettings CMFCDynamicLayout::SizeHorizontalAndVertical(int nXRatio, int nYRatio)
{
	SizeSettings settings;

	settings.m_nXRatio = nXRatio;
	settings.m_nYRatio = nYRatio;

	return settings;
}

BOOL CMFCDynamicLayout::AddItem(UINT nID, MoveSettings moveSettings, SizeSettings sizeSettings)
{
	if (m_pHostWnd->GetSafeHwnd() == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return AddItem(m_pHostWnd->GetDlgItem(nID)->GetSafeHwnd(), moveSettings, sizeSettings);
}

BOOL CMFCDynamicLayout::AddItem(HWND hWnd, MoveSettings moveSettings, SizeSettings sizeSettings)
{
	if (hWnd == NULL || !::IsWindow(hWnd) || !::IsChild(m_pHostWnd->GetSafeHwnd(), hWnd))
	{
		ASSERT(FALSE);
		return FALSE;
	}

	AFX_DYNAMIC_LAYOUT_ITEM* pItem = FindItem(hWnd);
	if (pItem != NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	CFormView* pFormView = DYNAMIC_DOWNCAST(CFormView, m_pHostWnd);
	if (pFormView != NULL)
	{
		ASSERT_VALID(pFormView);

		if (pFormView->IsInitDlgCompleted())
		{
			TRACE0("CMFCDynamicLayout::AddAnchor failed! Please call this method inside WM_INITDIALOG message handler in your CFormView-derived class.\n");
			ASSERT(FALSE);
		}
	}

	pItem = new AFX_DYNAMIC_LAYOUT_ITEM(hWnd, moveSettings, sizeSettings);

	CorrectItem(*pItem);

	if (PrepareItem(*pItem))
	{
		m_listWnd.AddTail(pItem);
	}

	return TRUE;
}

AFX_DYNAMIC_LAYOUT_ITEM* CMFCDynamicLayout::FindItem(HWND hWnd)
{
	for (POSITION pos = m_listWnd.GetHeadPosition(); pos != NULL;)
	{
		AFX_DYNAMIC_LAYOUT_ITEM* pItem = m_listWnd.GetNext(pos);
		if (pItem->m_hWnd == hWnd)
		{
			return pItem;
		}
	}

	return NULL;
}

void CMFCDynamicLayout::CorrectItem(AFX_DYNAMIC_LAYOUT_ITEM& item) const
{
	CString strName;
	::GetClassName(item.m_hWnd, strName.GetBufferSetLength(1024), 1024);
	strName.ReleaseBuffer();

	if (strName.CompareNoCase(WC_COMBOBOX) == 0 || strName.CompareNoCase(WC_COMBOBOXEX) == 0)
	{
		DWORD dwStyle = ::GetWindowLong(item.m_hWnd, GWL_STYLE);

		if (item.m_sizeSettings.IsVertical() && (dwStyle & CBS_SIMPLE) == 0)
		{
			item.m_sizeSettings.m_nYRatio = 0;
		}
	}
}

CRect CMFCDynamicLayout::GetItemRect(AFX_DYNAMIC_LAYOUT_ITEM& item) const
{
	CRect rectChild(0, 0, 0, 0);

	if (m_pHostWnd == NULL)
	{
		ASSERT(FALSE);
		return NULL;
	}

	::GetWindowRect (item.m_hWnd, rectChild);
	m_pHostWnd->ScreenToClient(rectChild);

	return rectChild;
}

BOOL CMFCDynamicLayout::PrepareItem(AFX_DYNAMIC_LAYOUT_ITEM& item) const
{
	CRect rectHost;
	GetHostWndRect(rectHost);

	if (rectHost.IsRectNull())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	CRect rectChild = GetItemRect(item);

	const double deltaX = 0.01 * rectHost.Width();
	const double deltaY = 0.01 * rectHost.Height();

	item.m_ptInit.x = (double)rectChild.left;
	item.m_ptInit.y = (double)rectChild.top;

	if (item.m_moveSettings.IsHorizontal())
	{
		item.m_ptInit.x -= deltaX * item.m_moveSettings.m_nXRatio;
	}

	if (item.m_moveSettings.IsVertical())
	{
		item.m_ptInit.y -= deltaY * item.m_moveSettings.m_nYRatio;
	}

	item.m_szInit.x  = (double)rectChild.Width ();
	item.m_szInit.y  = (double)rectChild.Height ();

	if (item.m_sizeSettings.IsHorizontal())
	{
		item.m_szInit.x -= deltaX * item.m_sizeSettings.m_nXRatio;
	}

	if (item.m_sizeSettings.IsVertical())
	{
		item.m_szInit.y -= deltaY * item.m_sizeSettings.m_nYRatio;
	}

	return TRUE;
}

UINT CMFCDynamicLayout::AdjustItemRect(AFX_DYNAMIC_LAYOUT_ITEM& item, CRect& rectItem) const
{
	rectItem.SetRectEmpty();

	CRect rectHost;
	GetHostWndRect(rectHost);

	if (rectHost.IsRectNull())
	{
		return SWP_NOMOVE | SWP_NOSIZE;
	}

	UINT uiFlags = 0;
	const double deltaX = 0.01 * rectHost.Width();
	const double deltaY = 0.01 * rectHost.Height();

	AFX_DYNAMIC_LAYOUT_ITEM::Point point(item.m_ptInit);
	AFX_DYNAMIC_LAYOUT_ITEM::Point size(item.m_szInit);

	if (item.m_moveSettings.IsHorizontal())
	{
		point.x += deltaX * item.m_moveSettings.m_nXRatio;
	}

	if (item.m_moveSettings.IsVertical())
	{
		point.y += deltaY * item.m_moveSettings.m_nYRatio;
	}

	if (item.m_sizeSettings.IsHorizontal())
	{
		size.x += deltaX * item.m_sizeSettings.m_nXRatio;
	}

	if (item.m_sizeSettings.IsVertical())
	{
		size.y += deltaY * item.m_sizeSettings.m_nYRatio;
	}

	rectItem.left = (long)point.x + rectHost.left;
	rectItem.top = (long)point.y + rectHost.top;
	rectItem.right = rectItem.left + (long)size.x;
	rectItem.bottom = rectItem.top + (long)size.y;

	if (rectItem.left == (item.m_ptInit.x + rectHost.left) && rectItem.top == (item.m_ptInit.y + rectHost.top))
	{
		uiFlags |= SWP_NOMOVE;
	}

	if (rectItem.Width() == item.m_szInit.x && rectItem.Height() == item.m_szInit.y)
	{
		uiFlags |= SWP_NOSIZE;
	}

	return uiFlags;
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDynamicLayoutData

void CMFCDynamicLayoutData::CleanUp()
{
	m_listCtrls.RemoveAll();
}

inline int AfxClamp(WORD wValue, int nMin = 0, int nMax = 100)
{
	int value = (SHORT)wValue;

#if _DEBUG
	if (value < nMin || value > nMax)
	{
		TRACE(_T("Data is out of bounds.\n"));
	}
#endif

	return value < nMin ? nMin : (value > nMax ? nMax : value);
}

BOOL CMFCDynamicLayoutData::ReadResource(LPVOID lpResource, UINT nSize)
{
	if (lpResource == NULL || nSize == 0)
	{
		return FALSE;
	}

	ASSERT(AfxIsValidAddress (lpResource, nSize, FALSE));

	CleanUp();

	const BYTE* const pBuf = (BYTE*)lpResource;
	const WORD* const pwEnd = (WORD*)(pBuf + nSize);
	const WORD* pw = (WORD*)pBuf;

	// header
	WORD wVersion = *pw++;

	if (wVersion == 0)
	{
		// data
		while (pw + 4 <= pwEnd)
		{
			Item itemData;

			itemData.m_moveSettings.m_nXRatio = AfxClamp(*pw++);
			itemData.m_moveSettings.m_nYRatio = AfxClamp(*pw++);
			itemData.m_sizeSettings.m_nXRatio = AfxClamp(*pw++);
			itemData.m_sizeSettings.m_nYRatio = AfxClamp(*pw++);

			m_listCtrls.AddTail(itemData);
		}

		return m_listCtrls.GetCount() > 0;
	}

	return FALSE;
}

BOOL CMFCDynamicLayoutData::ApplyLayoutDataTo(CWnd* pHostWnd, BOOL bUpdate)
{
	if (pHostWnd->GetSafeHwnd() == NULL || m_listCtrls.IsEmpty())
	{
		return FALSE;
	}

	ASSERT_VALID(pHostWnd);

	pHostWnd->EnableDynamicLayout(FALSE);
	pHostWnd->EnableDynamicLayout();

	CMFCDynamicLayout* pLayout = (CMFCDynamicLayout*) pHostWnd->GetDynamicLayout();

	if (pLayout == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pLayout);

	if (!pLayout->Create(pHostWnd))
	{
		return FALSE;
	}

	int nCount = 0;
	CWnd* pChild = pHostWnd->GetWindow (GW_CHILD);
	POSITION pos = m_listCtrls.GetHeadPosition();
	while (pChild != NULL && pos != NULL)
	{
		const Item& item = m_listCtrls.GetNext(pos);

		if (!item.m_moveSettings.IsNone() || !item.m_sizeSettings.IsNone())
		{
			pLayout->AddItem(pChild->GetSafeHwnd(), item.m_moveSettings, item.m_sizeSettings);
			nCount++;
		}

		pChild = pChild->GetNextWindow();
	}

	if (bUpdate)
	{
		pLayout->Adjust();
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDynamicLayout - loading RT_DIALOG_LAYOUT resource

BOOL CMFCDynamicLayout::LoadResource(CWnd* pHostWnd, LPVOID lpResource, DWORD dwSize)
{
	if (pHostWnd->GetSafeHwnd() == NULL || !::IsWindow(pHostWnd->GetSafeHwnd()) || lpResource == NULL)
	{
		return FALSE;
	}

	CMFCDynamicLayoutData layoutData;
	BOOL bResult = layoutData.ReadResource(lpResource, (UINT)dwSize);
	layoutData.ApplyLayoutDataTo(pHostWnd, FALSE);

	return bResult;
}
