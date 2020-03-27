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
#include "sal.h"



#define new DEBUG_NEW

/////////////////////////////////////////////////////////////////////////////
// CDragListBox

CDragListBox::~CDragListBox()
{
	DestroyWindow();
}

void CDragListBox::PreSubclassWindow()
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT((GetStyle() & (LBS_MULTIPLESEL|LBS_SORT)) == 0);
	MakeDragList(m_hWnd);
}

#pragma push_macro("DrawInsert")
#undef DrawInsert

BOOL CDragListBox::BeginDrag(CPoint pt)
{
	m_nLast = -1;
	DrawInsert(ItemFromPt(pt));
	return TRUE;
}

void CDragListBox::CancelDrag(CPoint)
{
	DrawInsert(-1);
}

UINT CDragListBox::Dragging(CPoint pt)
{
	int nIndex = ItemFromPt(pt, FALSE); // don't allow scrolling just yet
	DrawInsert(nIndex);
	ItemFromPt(pt);
	return (nIndex == LB_ERR) ? DL_STOPCURSOR : DL_MOVECURSOR;
}

void CDragListBox::Dropped(int nSrcIndex, CPoint pt)
{
	ASSERT(!(GetStyle() & (LBS_OWNERDRAWFIXED|LBS_OWNERDRAWVARIABLE)) ||
		(GetStyle() & LBS_HASSTRINGS));

	DrawInsert(-1);
	int nDestIndex = ItemFromPt(pt);

	if (nSrcIndex == -1 || nDestIndex == -1)
		return;
	if (nDestIndex == nSrcIndex || nDestIndex == nSrcIndex+1)
		return; //didn't move
	CString str;
	UINT_PTR dwData;
	GetText(nSrcIndex, str);
	dwData = GetItemData(nSrcIndex);
	DeleteString(nSrcIndex);
	if (nSrcIndex < nDestIndex)
		nDestIndex--;
	nDestIndex = InsertString(nDestIndex, str);
	SetItemData(nDestIndex, dwData);
	SetCurSel(nDestIndex);
}

void CDragListBox::DrawInsert(int nIndex)
{
	if (m_nLast != nIndex)
	{
		DrawSingle(m_nLast);
		DrawSingle(nIndex);
		m_nLast = nIndex;
	}
}

#pragma pop_macro("DrawInsert")

void CDragListBox::DrawSingle(int nIndex)
{
	if (nIndex == -1)
		return;
	CBrush* pBrush = CDC::GetHalftoneBrush();
	CRect rect;
	GetClientRect(&rect);
	CRgn rgn;
	rgn.CreateRectRgnIndirect(&rect);

	CDC* pDC = GetDC();
	// prevent drawing outside of listbox
	// this can happen at the top of the listbox since the listbox's DC is the
	// parent's DC
	pDC->SelectClipRgn(&rgn);

	GetItemRect(nIndex, &rect);
	rect.bottom = rect.top+2;
	rect.top -= 2;
	CBrush* pBrushOld = pDC->SelectObject(pBrush);
	//draw main line
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATINVERT);

	pDC->SelectObject(pBrushOld);
	ReleaseDC(pDC);
}

BOOL CDragListBox::OnChildNotify(UINT nMessage, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if (nMessage != m_nMsgDragList)
		return CListBox::OnChildNotify(nMessage, wParam, lParam, pResult);

	ASSERT(pResult != NULL);
	LPDRAGLISTINFO pInfo = (LPDRAGLISTINFO)lParam;
	ASSERT(pInfo != NULL);
	switch (pInfo->uNotification)
	{
	case DL_BEGINDRAG:
		*pResult = BeginDrag(pInfo->ptCursor);
		break;
	case DL_CANCELDRAG:
		CancelDrag(pInfo->ptCursor);
		break;
	case DL_DRAGGING:
		*pResult = Dragging(pInfo->ptCursor);
		break;
	case DL_DROPPED:
		Dropped(GetCurSel(), pInfo->ptCursor);
		break;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CToolBarCtrl

BEGIN_MESSAGE_MAP(CToolBarCtrl, CWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CToolBarCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_BAR_REG));

	CWnd* pWnd = this;
	return pWnd->Create(TOOLBARCLASSNAME, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CToolBarCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CToolBarCtrl::~CToolBarCtrl()
{
	DestroyWindow();
}

int CToolBarCtrl::AddBitmap(int nNumButtons, CBitmap* pBitmap)
{
	ASSERT(::IsWindow(m_hWnd));
	TBADDBITMAP tbab;
	tbab.hInst = NULL;
	tbab.nID = (UINT_PTR)pBitmap->GetSafeHandle();
	return (int) ::SendMessage(m_hWnd, TB_ADDBITMAP, (WPARAM)nNumButtons,
		(LPARAM)&tbab);
}

int CToolBarCtrl::AddBitmap(int nNumButtons, UINT nBitmapID)
{
	ASSERT(::IsWindow(m_hWnd));
	TBADDBITMAP tbab;
	tbab.hInst = AfxFindResourceHandle((LPCTSTR)(DWORD_PTR)nBitmapID, RT_BITMAP);
	ASSERT(tbab.hInst != NULL);
	tbab.nID = nBitmapID;
	return (int) ::SendMessage(m_hWnd, TB_ADDBITMAP, (WPARAM)nNumButtons,
		(LPARAM)&tbab);
}

void CToolBarCtrl::SaveState(HKEY hKeyRoot, LPCTSTR lpszSubKey,
	LPCTSTR lpszValueName)
{
	ASSERT(::IsWindow(m_hWnd));
	TBSAVEPARAMS tbs;
	tbs.hkr = hKeyRoot;
	tbs.pszSubKey = lpszSubKey;
	tbs.pszValueName = lpszValueName;
	::SendMessage(m_hWnd, TB_SAVERESTORE, (WPARAM)TRUE, (LPARAM)&tbs);
}

void CToolBarCtrl::RestoreState(HKEY hKeyRoot, LPCTSTR lpszSubKey,
	LPCTSTR lpszValueName)
{
	ASSERT(::IsWindow(m_hWnd));
	TBSAVEPARAMS tbs;
	tbs.hkr = hKeyRoot;
	tbs.pszSubKey = lpszSubKey;
	tbs.pszValueName = lpszValueName;
	::SendMessage(m_hWnd, TB_SAVERESTORE, (WPARAM)FALSE, (LPARAM)&tbs);
}

int CToolBarCtrl::AddString(UINT nStringID)
{
	ASSERT(::IsWindow(m_hWnd));
	HINSTANCE hInst = AfxFindResourceHandle(MAKEINTRESOURCE((nStringID>>4)+1),
		RT_STRING);
	ASSERT(hInst != NULL);

	CString strTemp;
	BOOL bLoaded = strTemp.LoadString(hInst, nStringID);
	ASSERT(bLoaded);
	
	return (int)::SendMessage(m_hWnd, TB_ADDSTRING, 0, (LPARAM)strTemp.GetBuffer());
}

int CToolBarCtrl::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CWnd::OnCreate(lpcs) == -1)
		return -1;
	SetButtonStructSize(sizeof(TBBUTTON));
	return 0;
}

HRESULT CToolBarCtrl::GetDropTarget(IDropTarget** ppDropTarget) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(ppDropTarget);
	return (HRESULT) ::SendMessage(m_hWnd, TB_GETOBJECT, (WPARAM)&IID_IDropTarget, (LPARAM)ppDropTarget);
}

int CToolBarCtrl::GetString(int nString, CString& str) const
{
	ASSERT(::IsWindow(m_hWnd));
	int nLength = (int)(short)LOWORD(::SendMessage(m_hWnd, TB_GETSTRING, MAKEWPARAM(0, nString), NULL));
	if(nLength != -1)
	{
		nLength = (int)::SendMessage(m_hWnd, TB_GETSTRING, MAKEWPARAM(nLength + 1, nString), (LPARAM)str.GetBufferSetLength(nLength+1));
		str.ReleaseBuffer();
	}
	return nLength;
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBarCtrl

BOOL CStatusBarCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_BAR_REG));

	CWnd* pWnd = this;
	return pWnd->Create(STATUSCLASSNAME, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CStatusBarCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle,
	const RECT& rect,	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;

}

CStatusBarCtrl::~CStatusBarCtrl()
{
	DestroyWindow();
}

int CStatusBarCtrl::GetText(LPTSTR lpszText, int nPane, int* pType) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nPane < 256);
	LRESULT dw = ::SendMessage(m_hWnd, SB_GETTEXT, (WPARAM)nPane,
		(LPARAM)lpszText);
	if (pType != NULL)
		*pType = HIWORD(dw);
	return LOWORD(dw);
}

CString CStatusBarCtrl::GetText(int nPane, int* pType) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nPane < 256);
	int nLength = LOWORD(::SendMessage(m_hWnd, SB_GETTEXTLENGTH,
		(WPARAM)nPane, 0L));
	CString str;
	LRESULT dw = ::SendMessage(m_hWnd, SB_GETTEXT, (WPARAM)nPane,
		(LPARAM)str.GetBufferSetLength(nLength+1));
	str.ReleaseBuffer();
	if (pType != NULL)
		*pType = HIWORD(dw);
	return str;
}

int CStatusBarCtrl::GetTextLength(int nPane, int* pType) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nPane < 256);
	LRESULT dw = ::SendMessage(m_hWnd, SB_GETTEXTLENGTH, (WPARAM)nPane, 0L);
	if (pType != NULL)
		*pType = HIWORD(dw);
	return LOWORD(dw);
}

CString CStatusBarCtrl::GetTipText(int nPane) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nPane < 256);
	TCHAR buf[256];
	::SendMessage(m_hWnd, SB_GETTIPTEXT, MAKEWPARAM(nPane, 256), (LPARAM)buf);
	return CString(buf);
}

BOOL CStatusBarCtrl::GetBorders(int& nHorz, int& nVert, int& nSpacing) const
{
	ASSERT(::IsWindow(m_hWnd));
	int borders[3];
	BOOL bResult = (BOOL)::SendMessage(m_hWnd, SB_GETBORDERS, 0, (LPARAM)borders);
	if (bResult)
	{
		nHorz = borders[0];
		nVert = borders[1];
		nSpacing = borders[2];
	}
	return bResult;
}

void CStatusBarCtrl::DrawItem(LPDRAWITEMSTRUCT)
{
	ASSERT(FALSE);  // must override for self draw status bars
}

BOOL CStatusBarCtrl::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam,
	LRESULT* pResult)
{
	if (message != WM_DRAWITEM)
		return CWnd::OnChildNotify(message, wParam, lParam, pResult);

	ASSERT(pResult == NULL);       // no return value expected
	UNUSED(pResult); // unused in release builds

	DrawItem((LPDRAWITEMSTRUCT)lParam);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CListCtrl

BEGIN_MESSAGE_MAP(CListCtrl, CWnd)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

BOOL CListCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_LISTVIEW_REG));

	CWnd* pWnd = this;
	return pWnd->Create(WC_LISTVIEW, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CListCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CListCtrl::~CListCtrl()
{
	DestroyWindow();
}

BOOL CListCtrl::GetItemRect(int nItem, LPRECT lpRect, UINT nCode) const
{
	ASSERT(::IsWindow(m_hWnd));
	lpRect->left = nCode;
	return (BOOL) ::SendMessage(m_hWnd, LVM_GETITEMRECT, (WPARAM)nItem,
		(LPARAM)lpRect);
}

BOOL CListCtrl::SetItemCountEx(int iCount, DWORD dwFlags /* = LVSICF_NOINVALIDATEALL */)
{
	ASSERT(::IsWindow(m_hWnd));

	// can't have dwFlags on a control that isn't virutal
	ASSERT(dwFlags == 0 || (GetStyle() & LVS_OWNERDATA));

	return (BOOL) ::SendMessage(m_hWnd, LVM_SETITEMCOUNT, (WPARAM) iCount,
		(LPARAM) dwFlags);
}

CSize CListCtrl::SetIconSpacing(int cx, int cy)
{
	ASSERT(::IsWindow(m_hWnd));
	DWORD dwRet = (DWORD) ::SendMessage(m_hWnd, LVM_SETICONSPACING,
		0, (LPARAM) MAKELONG(cx, cy));

	return CSize(dwRet);
}

CSize CListCtrl::SetIconSpacing(CSize size)
{
	ASSERT(::IsWindow(m_hWnd));
	DWORD dwRet = (DWORD) ::SendMessage(m_hWnd, LVM_SETICONSPACING,
		0, (LPARAM) MAKELONG(size.cx, size.cy));

	return CSize(dwRet);
}

BOOL CListCtrl::GetSubItemRect(int iItem, int iSubItem, int nArea, CRect& ref) const
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nArea == LVIR_BOUNDS || nArea == LVIR_ICON || nArea == LVIR_LABEL || nArea == LVIR_SELECTBOUNDS);

	RECT rect;
	rect.top = iSubItem;
	rect.left = nArea;
	BOOL bRet = (BOOL) ::SendMessage(m_hWnd, LVM_GETSUBITEMRECT,
		iItem, (LPARAM) &rect);

	if (bRet)
		ref = rect;
	return bRet;
}

int CListCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat,
	int nWidth, int nSubItem)
{
	LVCOLUMN column;
	column.mask = LVCF_TEXT|LVCF_FMT;
	column.pszText = (LPTSTR)lpszColumnHeading;
	column.fmt = nFormat;
	if (nWidth != -1)
	{
		column.mask |= LVCF_WIDTH;
		column.cx = nWidth;
	}
	if (nSubItem != -1)
	{
		column.mask |= LVCF_SUBITEM;
		column.iSubItem = nSubItem;
	}
	return CListCtrl::InsertColumn(nCol, &column);
}

int CListCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask,
	int nImage, LPARAM lParam)
{
	ASSERT(::IsWindow(m_hWnd));
	LVITEM item;
	item.mask = nMask;
	item.iItem = nItem;
	item.iSubItem = 0;
	item.pszText = (LPTSTR)lpszItem;
	item.state = nState;
	item.stateMask = nStateMask;
	item.iImage = nImage;
	item.lParam = lParam;
	return CListCtrl::InsertItem(&item);
}

int CListCtrl::HitTest(CPoint pt, UINT* pFlags) const
{
	ASSERT(::IsWindow(m_hWnd));
	LVHITTESTINFO hti;
	hti.pt = pt;
	int nRes = (int) ::SendMessage(m_hWnd, LVM_HITTEST, 0, (LPARAM)&hti);
	if (pFlags != NULL)
		*pFlags = hti.flags;
	return nRes;
}

BOOL CListCtrl::SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem,
	int nImage, UINT nState, UINT nStateMask, LPARAM lParam)
{
	ASSERT((nMask & LVIF_INDENT) == 0);
	return SetItem(nItem, nSubItem, nMask, lpszItem, nImage, nState, nStateMask, lParam, 0);
}

BOOL CListCtrl::SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem,
	int nImage, UINT nState, UINT nStateMask, LPARAM lParam, int nIndent)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT((GetStyle() & LVS_OWNERDATA)==0);

	LVITEM lvi;
	lvi.mask = nMask;
	lvi.iItem = nItem;
	lvi.iSubItem = nSubItem;
	lvi.stateMask = nStateMask;
	lvi.state = nState;
	lvi.pszText = (LPTSTR) lpszItem;
	lvi.iImage = nImage;
	lvi.lParam = lParam;
	lvi.iIndent = nIndent;

	return (BOOL) ::SendMessage(m_hWnd, LVM_SETITEM, 0, (LPARAM)&lvi);
}

BOOL CListCtrl::SetItemState(int nItem, UINT nState, UINT nStateMask)
{
	ASSERT(::IsWindow(m_hWnd));
	LVITEM lvi;
	lvi.stateMask = nStateMask;
	lvi.state = nState;
	return (BOOL) ::SendMessage(m_hWnd, LVM_SETITEMSTATE, nItem, (LPARAM)&lvi);
}

BOOL CListCtrl::SetItemText(int nItem, int nSubItem, LPCTSTR lpszText)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT((GetStyle() & LVS_OWNERDATA)==0);
	LVITEM lvi;
	lvi.iSubItem = nSubItem;
	lvi.pszText = (LPTSTR) lpszText;
	return (BOOL) ::SendMessage(m_hWnd, LVM_SETITEMTEXT, nItem, (LPARAM)&lvi);
}

CString CListCtrl::GetItemText(int nItem, int nSubItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	LVITEM lvi;
	memset(&lvi, 0, sizeof(LVITEM));
	lvi.iSubItem = nSubItem;
	CString str;
	int nLen = 128;
	int nRes;
	do
	{
		nLen *= 2;
		lvi.cchTextMax = nLen;
		lvi.pszText = str.GetBufferSetLength(nLen);
		nRes  = (int)::SendMessage(m_hWnd, LVM_GETITEMTEXT, (WPARAM)nItem,
			(LPARAM)&lvi);
	} while (nRes >= nLen-1);
	str.ReleaseBuffer();
	return str;
}

int CListCtrl::GetItemText(_In_ int nItem, _In_ int nSubItem, _Out_writes_to_(nLen, return + 1) LPTSTR lpszText, _In_ int nLen) const
{
	ASSERT(::IsWindow(m_hWnd));
	LVITEM lvi;
	memset(&lvi, 0, sizeof(LVITEM));
	lvi.iSubItem = nSubItem;
	lvi.cchTextMax = nLen;
	lvi.pszText = lpszText;
	return (int)::SendMessage(m_hWnd, LVM_GETITEMTEXT, (WPARAM)nItem,
		(LPARAM)&lvi);
}

DWORD_PTR CListCtrl::GetItemData(int nItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	LVITEM lvi;
	memset(&lvi, 0, sizeof(LVITEM));
	lvi.iItem = nItem;
	lvi.mask = LVIF_PARAM;
	VERIFY(::SendMessage(m_hWnd, LVM_GETITEM, 0, (LPARAM)&lvi));
	return lvi.lParam;
}

void CListCtrl::DrawItem(LPDRAWITEMSTRUCT)
{
	ASSERT(FALSE);
}

BOOL CListCtrl::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam,
	LRESULT* pResult)
{
	if (message != WM_DRAWITEM)
		return CWnd::OnChildNotify(message, wParam, lParam, pResult);

	ASSERT(pResult == NULL);       // no return value expected
	UNUSED(pResult); // unused in release builds

	DrawItem((LPDRAWITEMSTRUCT)lParam);
	return TRUE;
}

void CListCtrl::RemoveImageList(int nImageList)
{
	HIMAGELIST h = (HIMAGELIST)SendMessage(LVM_GETIMAGELIST,
		(WPARAM)nImageList);
	if (CImageList::FromHandlePermanent(h) != NULL)
		SendMessage(LVM_SETIMAGELIST, (WPARAM)nImageList, NULL);
}

void CListCtrl::OnNcDestroy()
{
	RemoveImageList(LVSIL_NORMAL);
	RemoveImageList(LVSIL_SMALL);
	RemoveImageList(LVSIL_STATE);

	CWnd::OnNcDestroy();
}

CImageList* CListCtrl::CreateDragImage(int nItem, LPPOINT lpPoint)
{
	ASSERT(::IsWindow(m_hWnd));

	HIMAGELIST hImageList = (HIMAGELIST)::SendMessage(m_hWnd,
		LVM_CREATEDRAGIMAGE, nItem, (LPARAM)lpPoint);
	if (hImageList == NULL)
		return NULL;

	CImageList* pImageList = new CImageList;
	VERIFY(pImageList->Attach(hImageList));
	return pImageList;
}

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrl

BEGIN_MESSAGE_MAP(CTreeCtrl, CWnd)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CTreeCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_TREEVIEW_REG));

	CWnd* pWnd = this;
	return pWnd->Create(WC_TREEVIEW, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CTreeCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CTreeCtrl::~CTreeCtrl()
{
	DestroyWindow();
}

BOOL CTreeCtrl::GetItemRect(HTREEITEM hItem, LPRECT lpRect, BOOL bTextOnly) const
{
	ASSERT(::IsWindow(m_hWnd));
	*(HTREEITEM*)lpRect = hItem;
	return (BOOL)::SendMessage(m_hWnd, TVM_GETITEMRECT, (WPARAM)bTextOnly,
		(LPARAM)lpRect);
}

CString CTreeCtrl::GetItemText(HTREEITEM hItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.hItem = hItem;
	item.mask = TVIF_TEXT;
	CString str;
	int nLen = 128;
	int nRes;
	do
	{
		nLen *= 2;
		item.pszText = str.GetBufferSetLength(nLen);
		item.cchTextMax = nLen;
		::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		nRes = AtlStrLen(item.pszText);
	} while (nRes >= nLen-1);
	str.ReleaseBuffer();
	return str;
}

BOOL CTreeCtrl::GetItemImage(HTREEITEM hItem, int& nImage, int& nSelectedImage) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.hItem = hItem;
	item.mask = TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	BOOL bRes = (BOOL)::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
	if (bRes)
	{
		nImage = item.iImage;
		nSelectedImage = item.iSelectedImage;
	}
	return bRes;
}

UINT CTreeCtrl::GetItemState(HTREEITEM hItem, UINT nStateMask) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.hItem = hItem;
	item.mask = TVIF_STATE;
	item.stateMask = nStateMask;
	item.state = 0;
	VERIFY(::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item));
	return item.state;
}

DWORD_PTR CTreeCtrl::GetItemData(HTREEITEM hItem) const
{
	ENSURE(::IsWindow(m_hWnd));
	ENSURE_ARG(hItem != NULL);
	TVITEM item;
	item.hItem = hItem;
	item.mask = TVIF_PARAM;
	VERIFY(::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item));
	return item.lParam;
}

BOOL CTreeCtrl::ItemHasChildren(HTREEITEM hItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.hItem = hItem;
	item.mask = TVIF_CHILDREN;
	::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
	return item.cChildren;
}

BOOL CTreeCtrl::SetItem(HTREEITEM hItem, UINT nMask, LPCTSTR lpszItem, int nImage,
	int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam)
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.hItem = hItem;
	item.mask = nMask;
	item.pszText = (LPTSTR) lpszItem;
	item.iImage = nImage;
	item.iSelectedImage = nSelectedImage;
	item.state = nState;
	item.stateMask = nStateMask;
	item.lParam = lParam;
	return (BOOL)::SendMessage(m_hWnd, TVM_SETITEM, 0, (LPARAM)&item);
}

BOOL CTreeCtrl::SetItemEx(HTREEITEM hItem, UINT nMask, LPCTSTR lpszItem, int nImage,
	int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam, 
	UINT uStateEx, HWND hWnd, int iExpandedImage)
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEMEX item;
	item.hItem = hItem;
	item.mask = nMask;
	item.pszText = (LPTSTR) lpszItem;
	item.iImage = nImage;
	item.iSelectedImage = nSelectedImage;
	item.state = nState;
	item.stateMask = nStateMask;
	item.lParam = lParam;
	item.uStateEx = uStateEx;
	item.hwnd = hWnd;
	item.iExpandedImage = iExpandedImage;
	return (BOOL)::SendMessage(m_hWnd, TVM_SETITEM, 0, (LPARAM)&item);
}

HTREEITEM CTreeCtrl::InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
	int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
	HTREEITEM hParent, HTREEITEM hInsertAfter)
{
	ASSERT(::IsWindow(m_hWnd));
	TVINSERTSTRUCT tvis;
	tvis.hParent = hParent;
	tvis.hInsertAfter = hInsertAfter;
	tvis.item.mask = nMask;
	tvis.item.pszText = (LPTSTR) lpszItem;
	tvis.item.iImage = nImage;
	tvis.item.iSelectedImage = nSelectedImage;
	tvis.item.state = nState;
	tvis.item.stateMask = nStateMask;
	tvis.item.lParam = lParam;
	return (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)&tvis);
}

HTREEITEM CTreeCtrl::HitTest(CPoint pt, UINT* pFlags) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVHITTESTINFO hti;
	hti.pt = pt;
	HTREEITEM h = (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0,
		(LPARAM)&hti);
	if (pFlags != NULL)
		*pFlags = hti.flags;
	return h;
}

void CTreeCtrl::RemoveImageList(int nImageList)
{
	HIMAGELIST h = (HIMAGELIST)SendMessage(TVM_GETIMAGELIST,
		(WPARAM)nImageList);
	if (CImageList::FromHandlePermanent(h) != NULL)
		SendMessage(TVM_SETIMAGELIST, (WPARAM)nImageList, NULL);
}

void CTreeCtrl::OnDestroy()
{
	RemoveImageList(LVSIL_NORMAL);
	RemoveImageList(LVSIL_STATE);

	CWnd::OnDestroy();
}

CImageList* CTreeCtrl::CreateDragImage(HTREEITEM hItem)
{
	ASSERT(::IsWindow(m_hWnd));

	HIMAGELIST hImageList = (HIMAGELIST)::SendMessage(m_hWnd,
		TVM_CREATEDRAGIMAGE, 0, (LPARAM)hItem);
	if (hImageList == NULL)
		return NULL;

	CImageList* pImageList = new CImageList;
	VERIFY(pImageList->Attach(hImageList));
	return pImageList;
}

BOOL CTreeCtrl::GetCheck(HTREEITEM hItem) const
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.mask = TVIF_HANDLE | TVIF_STATE;
	item.hItem = hItem;
	item.stateMask = TVIS_STATEIMAGEMASK;
	VERIFY(::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item));
	// Return zero if it's not checked, or nonzero otherwise.
	return ((BOOL)(item.state >> 12) -1);
}

BOOL CTreeCtrl::SetCheck(HTREEITEM hItem, BOOL fCheck)
{
	ASSERT(::IsWindow(m_hWnd));
	TVITEM item;
	item.mask = TVIF_HANDLE | TVIF_STATE;
	item.hItem = hItem;
	item.stateMask = TVIS_STATEIMAGEMASK;

	 // Since state images are one-based, passing a 1 to the 
	 // INDEXTOSTATEIMAGEMASK macro turns the check off, and
	// passing 2 turns it on.
	item.state = INDEXTOSTATEIMAGEMASK((fCheck ? 2 : 1));

	return (BOOL)::SendMessage(m_hWnd, TVM_SETITEM, 0, (LPARAM)&item);
}

#if defined(UNICODE)

BOOL CTreeCtrl::GetItemPartRect(HTREEITEM hItem, TVITEMPART nPart, LPRECT lpRect)
{ 
	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT(lpRect);
	TVGETITEMPARTRECTINFO info; 
	info.hti = hItem; 
	info.prc = lpRect; 
	info.partID = nPart; 
	return (BOOL)::SendMessage((m_hWnd), TVM_GETITEMPARTRECT, 0, (LPARAM)&info); 
}

UINT CTreeCtrl::GetItemStateEx(HTREEITEM hItem) const
{
	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT(hItem);

	TVITEMEX item;
	item.hItem = hItem;
	item.mask = TVIF_STATEEX;
	VERIFY(::SendMessage(m_hWnd, TVM_GETITEM,0,(LPARAM)&item));
	return item.uStateEx;
}

int CTreeCtrl::GetItemExpandedImageIndex(HTREEITEM hItem) const
{
	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT(hItem);

	TVITEMEX item;
	item.hItem = hItem;

	item.mask = TVIF_EXPANDEDIMAGE;
	item.uStateEx = TVIF_EXPANDEDIMAGE;
	VERIFY(::SendMessage(m_hWnd, TVM_GETITEM,0,(LPARAM)&item));
	return item.iExpandedImage;
}
#endif
/////////////////////////////////////////////////////////////////////////////
// CSpinButtonCtrl

BOOL CSpinButtonCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_UPDOWN_REG));

	CWnd* pWnd = this;
	return pWnd->Create(UPDOWN_CLASS, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CSpinButtonCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle,
	const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CSpinButtonCtrl::~CSpinButtonCtrl()
{
	DestroyWindow();
}

void CSpinButtonCtrl::GetRange(int &lower, int& upper) const
{
	ASSERT(::IsWindow(m_hWnd));
	LRESULT dw = ::SendMessage(m_hWnd, UDM_GETRANGE, 0, 0l);
	lower = (int)(short)HIWORD(dw);
	upper = (int)(short)LOWORD(dw);
}

/////////////////////////////////////////////////////////////////////////////
// CSliderCtrl

BOOL CSliderCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_BAR_REG));

	CWnd* pWnd = this;
	return pWnd->Create(TRACKBAR_CLASS, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CSliderCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CSliderCtrl::~CSliderCtrl()
{
	DestroyWindow();
}

void CSliderCtrl::GetRange(int& nMin, int& nMax) const
{
	ASSERT(::IsWindow(m_hWnd));
	nMin = GetRangeMin();
	nMax = GetRangeMax();
}

void CSliderCtrl::SetRange(int nMin, int nMax, BOOL bRedraw)
{
	SetRangeMin(nMin, bRedraw); // instead of TBM_SETRANGE, use TBM_SETRANGEMIN and
	SetRangeMax(nMax, bRedraw); // TBM_SETRANGEMAX which use LONGs instead of WORDs.
}

void CSliderCtrl::GetSelection(int& nMin, int& nMax) const
{
	ASSERT(::IsWindow(m_hWnd));
	nMin = int(::SendMessage(m_hWnd, TBM_GETSELSTART, 0, 0L));
	nMax = int(::SendMessage(m_hWnd, TBM_GETSELEND, 0, 0L));
}

void CSliderCtrl::SetSelection(int nMin, int nMax)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, TBM_SETSELSTART, 0, (LPARAM)nMin); // instead of TBM_SETSEL, use TBM_SETSELSTART and
	::SendMessage(m_hWnd, TBM_SETSELEND, 0, (LPARAM)nMax);   // TBM_SETSELEND which use LONGs instead of WORDs.
}

/////////////////////////////////////////////////////////////////////////////
// CProgressCtrl

BOOL CProgressCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_PROGRESS_REG));

	CWnd* pWnd = this;
	return pWnd->Create(PROGRESS_CLASS, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CProgressCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle,
	const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CProgressCtrl::~CProgressCtrl()
{
	DestroyWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrl

BOOL CHeaderCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_LISTVIEW_REG));

	CWnd* pWnd = this;
	return pWnd->Create(WC_HEADER, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CHeaderCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CHeaderCtrl::~CHeaderCtrl()
{
	DestroyWindow();
}

void CHeaderCtrl::DrawItem(LPDRAWITEMSTRUCT)
{
	ASSERT(FALSE);  // must override for self draw header controls
}

BOOL CHeaderCtrl::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam,
	LRESULT* pResult)
{
	if (message != WM_DRAWITEM)
		return CWnd::OnChildNotify(message, wParam, lParam, pResult);

	ASSERT(pResult == NULL);       // no return value expected
	UNUSED(pResult); // unused in release builds

	DrawItem((LPDRAWITEMSTRUCT)lParam);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CHotKeyCtrl

BOOL CHotKeyCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_HOTKEY_REG));

	CWnd* pWnd = this;
	return pWnd->Create(HOTKEY_CLASS, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CHotKeyCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CHotKeyCtrl::~CHotKeyCtrl()
{
	DestroyWindow();
}

void CHotKeyCtrl::GetHotKey(WORD &wVirtualKeyCode, WORD &wModifiers) const
{
	ASSERT(::IsWindow(m_hWnd));
	LRESULT dw = ::SendMessage(m_hWnd, HKM_GETHOTKEY, 0, 0L);
	wVirtualKeyCode = LOBYTE(LOWORD(dw));
	wModifiers = HIBYTE(LOWORD(dw));
}

CString CHotKeyCtrl::GetKeyName(UINT vk, BOOL fExtended)
{
	LONG lScan = MapVirtualKey(vk, 0) << 16;

	// if it's an extended key, add the extended flag
	if (fExtended)
		lScan |= 0x01000000L;

	CString str;
	int nBufferLen = 64;
	int nLen;
	do
	{
		nBufferLen *= 2;
		LPTSTR psz = str.GetBufferSetLength(nBufferLen);
		nLen = ::GetKeyNameText(lScan, psz, nBufferLen + 1);
		str.ReleaseBuffer(nLen);
	}
	while (nLen == nBufferLen);
	return str;
}

static const TCHAR szPlus[] = _T(" + ");

CString CHotKeyCtrl::GetHotKeyName() const
{
	ASSERT(::IsWindow(m_hWnd));

	CString strKeyName;
	WORD wCode;
	WORD wModifiers;

	GetHotKey(wCode, wModifiers);
	if (wCode != 0 || wModifiers != 0)
	{
		if (wModifiers & HOTKEYF_CONTROL)
		{
			strKeyName += GetKeyName(VK_CONTROL, FALSE);
			strKeyName += szPlus;
		}

		if (wModifiers & HOTKEYF_SHIFT)
		{
			strKeyName += GetKeyName(VK_SHIFT, FALSE);
			strKeyName += szPlus;
		}

		if (wModifiers & HOTKEYF_ALT)
		{
			strKeyName += GetKeyName(VK_MENU, FALSE);
			strKeyName += szPlus;
		}

		strKeyName += GetKeyName(wCode, wModifiers & HOTKEYF_EXT);
	}

	return strKeyName;
}

/////////////////////////////////////////////////////////////////////////////
// CTabCtrl

BEGIN_MESSAGE_MAP(CTabCtrl, CWnd)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CTabCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
	UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_TAB_REG));

	CWnd* pWnd = this;
	return pWnd->Create(WC_TABCONTROL, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CTabCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd,	UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}

CTabCtrl::~CTabCtrl()
{
	DestroyWindow();
}

void CTabCtrl::DrawItem(LPDRAWITEMSTRUCT)
{
	ASSERT(FALSE);  // must override for self draw tab controls
}

BOOL CTabCtrl::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam,
	LRESULT* pResult)
{
	if (message != WM_DRAWITEM)
		return CWnd::OnChildNotify(message, wParam, lParam, pResult);

	ASSERT(pResult == NULL);       // no return value expected
	UNUSED(pResult); // unused in release builds

	DrawItem((LPDRAWITEMSTRUCT)lParam);
	return TRUE;
}

void CTabCtrl::OnDestroy()
{
	HIMAGELIST h = (HIMAGELIST)SendMessage(TCM_GETIMAGELIST);
	if (CImageList::FromHandlePermanent(h) != NULL)
		SendMessage(TCM_SETIMAGELIST, NULL, NULL);

	CWnd::OnDestroy();
}

DWORD CTabCtrl::GetItemState(int nItem, DWORD dwMask) const
{
	ASSERT(::IsWindow(m_hWnd));

	TCITEM item;
	item.mask = TCIF_STATE;
	item.dwStateMask = dwMask;
	VERIFY(::SendMessage(m_hWnd, TCM_GETITEM, (WPARAM)nItem, (LPARAM)&item));

	return item.dwState;
}

BOOL CTabCtrl::SetItemState(int nItem, DWORD dwMask, DWORD dwState)
{
	ASSERT(::IsWindow(m_hWnd));

	TCITEM item;
	item.mask = TCIF_STATE;
	item.dwState = dwState;
	item.dwStateMask = dwMask;

	return (BOOL) ::SendMessage(m_hWnd, TCM_SETITEM,
		(WPARAM) nItem, (LPARAM) &item);
}

LONG CTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem,
	int nImage, LPARAM lParam)
{
	ASSERT(::IsWindow(m_hWnd));

	TCITEM item;
	item.mask = nMask;
	item.iImage = nImage;
	item.lParam = lParam;
	item.pszText = (LPTSTR) lpszItem;

	return (LONG) ::SendMessage(m_hWnd, TCM_INSERTITEM, nItem, (LPARAM) &item);
}

LONG CTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem,
	int nImage, LPARAM lParam, DWORD dwState, DWORD dwStateMask)
{
	ASSERT(::IsWindow(m_hWnd));

	TCITEM item;
	item.mask = nMask;
	item.iImage = nImage;
	item.lParam = lParam;
	item.pszText = (LPTSTR) lpszItem;
	item.dwState = dwState;
	item.dwStateMask = dwStateMask;

	return (LONG) ::SendMessage(m_hWnd, TCM_INSERTITEM, nItem, (LPARAM) &item);
}


/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrl

BOOL CAnimateCtrl::Create(DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTL_ANIMATE_REG));

	CWnd* pWnd = this;
	return pWnd->Create(ANIMATE_CLASS, NULL, dwStyle, rect, pParentWnd, nID);
}

BOOL CAnimateCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect,
	CWnd* pParentWnd, UINT nID)
{
	BOOL bRet = Create(dwStyle, rect, pParentWnd, nID);
	if (bRet && dwExStyle != 0)
	{
		bRet = ModifyStyleEx(0, dwExStyle);
	}
	return bRet;
}


CAnimateCtrl::~CAnimateCtrl()
{
	DestroyWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CRichEdit

CRichEditCtrl::~CRichEditCtrl()
{
	DestroyWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CImageList

CHandleMap* PASCAL afxMapHIMAGELIST(BOOL bCreate)
{
	AFX_MODULE_THREAD_STATE* pState = AfxGetModuleThreadState();
	if (pState->m_pmapHIMAGELIST == NULL && bCreate)
	{
		BOOL bEnable = AfxEnableMemoryTracking(FALSE);
		_PNH pnhOldHandler = AfxSetNewHandler(&AfxCriticalNewHandler);

		pState->m_pmapHIMAGELIST = new CHandleMap(RUNTIME_CLASS(CImageList),
			ConstructDestruct<CImageList>::Construct, ConstructDestruct<CImageList>::Destruct, 
			offsetof(CImageList, m_hImageList));

		AfxSetNewHandler(pnhOldHandler);
		AfxEnableMemoryTracking(bEnable);
	}
	return pState->m_pmapHIMAGELIST;
}

CImageList::CImageList()
{
	m_hImageList = NULL;
}

CImageList::~CImageList()
{
	AFX_BEGIN_DESTRUCTOR

		DeleteImageList();

	AFX_END_DESTRUCTOR
}

HIMAGELIST CImageList::Detach()
{
	HIMAGELIST hImageList = m_hImageList;
	if (hImageList != NULL)
	{
		CHandleMap* pMap = afxMapHIMAGELIST();
		if (pMap != NULL)
			pMap->RemoveHandle(m_hImageList);
	}

	m_hImageList = NULL;
	return hImageList;
}

BOOL CImageList::DeleteImageList()
{
	if (m_hImageList == NULL)
		return FALSE;
	return ImageList_Destroy(Detach());
}

CImageList* PASCAL CImageList::FromHandle(HIMAGELIST h)
{
	CHandleMap* pMap = afxMapHIMAGELIST(TRUE);
	ASSERT(pMap != NULL);
	CImageList* pImageList = (CImageList*)pMap->FromHandle(h);
	ASSERT(pImageList == NULL || pImageList->m_hImageList == h);
	return pImageList;
}

CImageList* PASCAL CImageList::FromHandlePermanent(HIMAGELIST h)
{
	CHandleMap* pMap = afxMapHIMAGELIST();
	CImageList* pImageList = NULL;
	if (pMap != NULL)
	{
		// only look in the permanent map - does no allocations
		pImageList = (CImageList*)pMap->LookupPermanent(h);
		ASSERT(pImageList == NULL || pImageList->m_hImageList == h);
	}
	return pImageList;
}

BOOL CImageList::Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow)
{
	return Attach(ImageList_Create(cx, cy, nFlags, nInitial, nGrow));
}

BOOL CImageList::Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
{
	ASSERT(HIWORD(nBitmapID) == 0);
	HINSTANCE hInst = AfxFindResourceHandle((LPCTSTR)(DWORD_PTR)nBitmapID, RT_BITMAP);
	ASSERT(hInst != NULL);
	return Attach(ImageList_LoadBitmap(hInst, 
		(LPCTSTR)(DWORD_PTR)nBitmapID, cx, nGrow, crMask));
}

BOOL CImageList::Create(LPCTSTR lpszBitmapID, int cx, int nGrow,
	COLORREF crMask)
{
	HINSTANCE hInst = AfxFindResourceHandle(lpszBitmapID, RT_BITMAP);
	ASSERT(hInst != NULL);
	return Attach(ImageList_LoadBitmap(hInst, lpszBitmapID, cx, nGrow, crMask));
}

BOOL CImageList::Create(CImageList& imagelist1, int nImage1,
	CImageList& imagelist2, int nImage2, int dx, int dy)
{
	return Attach(ImageList_Merge(imagelist1.m_hImageList, nImage1,
		imagelist2.m_hImageList, nImage2, dx, dy));
}

BOOL CImageList::Attach(HIMAGELIST hImageList)
{
	ASSERT(m_hImageList == NULL);      // only attach once, detach on destroy
	ASSERT(FromHandlePermanent(hImageList) == NULL);

	if (hImageList == NULL)
		return FALSE;

	CHandleMap* pMap = afxMapHIMAGELIST(TRUE);
	ASSERT(pMap != NULL);

	pMap->SetPermanent(m_hImageList = hImageList, this);
	return TRUE;
}

BOOL CImageList::Read(CArchive* pArchive)
{
	ASSERT(m_hImageList == NULL);
	ASSERT(pArchive != NULL);
	ASSERT(pArchive->IsLoading());
	CArchiveStream arcstream(pArchive);

	m_hImageList = ImageList_Read(&arcstream);
	return (m_hImageList != NULL);
}

BOOL CImageList::Write(CArchive* pArchive)
{
	ASSERT(m_hImageList != NULL);
	ASSERT(pArchive != NULL);
	ASSERT(pArchive->IsStoring());
	CArchiveStream arcstream(pArchive);
	return ImageList_Write(m_hImageList, &arcstream);
}

#ifdef _DEBUG
void CImageList::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);

	dc << "m_hImageList = " << (void*)m_hImageList;
	dc << "\n";
}

void CImageList::AssertValid() const
{
	CObject::AssertValid();
	if (m_hImageList == NULL)
		return;
	// should also be in the permanent or temporary handle map
	CObject* p=NULL;

	CHandleMap* pMap = afxMapHIMAGELIST();
	ASSERT(pMap != NULL);

	if(pMap)
	{
		ASSERT((p = pMap->LookupPermanent(m_hImageList)) != NULL ||
			(p = pMap->LookupTemporary(m_hImageList)) != NULL);
	}
	ASSERT((CImageList*)p == this);   // must be us
}
#endif


/////////////////////////////////////////////////////////////////////////////


#ifndef _AFX_ENABLE_INLINES

#define _AFXCMN_INLINE
#include "afxcmn.inl"

#endif //_AFX_ENABLE_INLINES

/////////////////////////////////////////////////////////////////////////////


IMPLEMENT_DYNAMIC(CDragListBox, CListBox)
IMPLEMENT_DYNAMIC(CSpinButtonCtrl, CWnd)
IMPLEMENT_DYNAMIC(CSliderCtrl, CWnd)
IMPLEMENT_DYNAMIC(CProgressCtrl, CWnd)
IMPLEMENT_DYNAMIC(CComboBoxEx, CComboBox)
IMPLEMENT_DYNAMIC(CHeaderCtrl, CWnd)
IMPLEMENT_DYNAMIC(CHotKeyCtrl, CWnd)
IMPLEMENT_DYNAMIC(CAnimateCtrl, CWnd)
IMPLEMENT_DYNAMIC(CTabCtrl, CWnd)
IMPLEMENT_DYNAMIC(CTreeCtrl, CWnd)
IMPLEMENT_DYNAMIC(CListCtrl, CWnd)
IMPLEMENT_DYNAMIC(CToolBarCtrl, CWnd)
IMPLEMENT_DYNAMIC(CStatusBarCtrl, CWnd)
IMPLEMENT_DYNCREATE(CImageList, CObject)
IMPLEMENT_DYNAMIC(CRichEditCtrl, CWnd)

/////////////////////////////////////////////////////////////////////////////
