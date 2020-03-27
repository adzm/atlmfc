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
#include <afxocc.h>

#include "afxpanedialog.h"
#include "afxglobalutils.h"
#include "afxdockingmanager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaneDialog

IMPLEMENT_SERIAL(CPaneDialog, CDockablePane, VERSIONABLE_SCHEMA | 1)

CPaneDialog::CPaneDialog()
{
	m_pOccDialogInfo = NULL;
}

CPaneDialog::~CPaneDialog()
{
}

/////////////////////////////////////////////////////////////////////////////
// CPaneDialog message handlers

BOOL CPaneDialog::Create(LPCTSTR lpszWindowName, CWnd* pParentWnd, BOOL bHasGripper, UINT nIDTemplate, UINT nStyle, UINT nID)
{
	return Create(lpszWindowName, pParentWnd, bHasGripper, MAKEINTRESOURCE(nIDTemplate), nStyle, nID);
}

BOOL CPaneDialog::Create(LPCTSTR lpszWindowName, CWnd* pParentWnd, BOOL bHasGripper, LPCTSTR lpszTemplateName, UINT nStyle, UINT nID, DWORD dwTabbedStyle, DWORD dwControlBarStyle)
{
	m_lpszBarTemplateName = (LPTSTR) lpszTemplateName;

	if (!CDockablePane::Create(lpszWindowName, pParentWnd, CSize(0, 0), bHasGripper, nID, nStyle, dwTabbedStyle, dwControlBarStyle))
	{
		return FALSE;
	}

	if ((GetStyle() & WS_CHILD) == 0)
	{
		TRACE0("CPaneDialog::Create failed: make sure that your dialog has \"Child\" style in resources.\n");
		ASSERT(FALSE);
		return FALSE;
	}

	m_lpszBarTemplateName = NULL;
	SetOwner(AFXGetTopLevelFrame(this));

	if (m_sizeDialog != CSize(0, 0))
	{
		SetWindowPos(NULL, -1, -1, m_sizeDialog.cx, m_sizeDialog.cy, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
	}

	return TRUE;
}

void CPaneDialog::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
	CDockablePane::OnUpdateCmdUI(pTarget, bDisableIfNoHndler);
}

BEGIN_MESSAGE_MAP(CPaneDialog, CDockablePane)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_WINDOWPOSCHANGING()
	ON_MESSAGE(WM_INITDIALOG, &CPaneDialog::HandleInitDialog)
	ON_WM_PRINTCLIENT()
END_MESSAGE_MAP()

LRESULT CPaneDialog::HandleInitDialog(WPARAM wParam, LPARAM lParam)
{
	CBasePane::HandleInitDialog(wParam, lParam);

	Default();  // allow default to initialize first(common dialogs/etc)

	// create OLE controls
	COccManager* pOccManager = afxOccManager;
	if ((pOccManager != NULL) &&(m_pOccDialogInfo != NULL))
	{
		if (!pOccManager->CreateDlgControls(this, m_lpszBarTemplateName, m_pOccDialogInfo))
		{
			TRACE(_T("Warning: CreateDlgControls failed during dialog bar init.\n"));
			return FALSE;
		}
	}

	LoadDynamicLayoutResource(m_lpszBarTemplateName);

	return TRUE;
}

BOOL CPaneDialog::SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo)
{
	m_pOccDialogInfo = pOccDialogInfo;
	return TRUE;
}

BOOL CPaneDialog::OnEraseBkgnd(CDC* pDC)
{
	CRect rectClient;
	GetClientRect(rectClient);

	pDC->FillRect(rectClient, &(GetGlobalData()->brBtnFace));
	return TRUE;
}

void CPaneDialog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CPoint ptScr = point;
	ClientToScreen(&ptScr);

	int nHitTest = HitTest(ptScr, TRUE);

	if (nHitTest == HTCAPTION)
	{
		CDockablePane::OnLButtonDblClk(nFlags, point);
	}
	else
	{
		CWnd::OnLButtonDblClk(nFlags, point);
	}
}

void CPaneDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPoint ptScr = point;
	ClientToScreen(&ptScr);

	int nHitTest = HitTest(ptScr, TRUE);

	if (nHitTest == HTCAPTION || nHitTest == AFX_HTCLOSE || nHitTest == HTMAXBUTTON || nHitTest == HTMINBUTTON)
	{
		CDockablePane::OnLButtonDown(nFlags, point);
	}
	else
	{
		CWnd::OnLButtonDown(nFlags, point);
	}
}

void CPaneDialog::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos)
{
	CDockablePane::OnWindowPosChanging(lpwndpos);

	if (!CanBeResized())
	{
		CSize sizeMin;
		GetMinSize(sizeMin);

		if (IsHorizontal() && lpwndpos->cy < sizeMin.cy)
		{
			lpwndpos->cy = sizeMin.cy;
			lpwndpos->hwndInsertAfter = HWND_BOTTOM;
		}
		else if (!IsHorizontal() && lpwndpos->cx < sizeMin.cx)
		{
			lpwndpos->cx = sizeMin.cx;
			lpwndpos->hwndInsertAfter = HWND_BOTTOM;
		}
	}
}

LRESULT CPaneDialog::OnPrintClient(CDC* pDC, UINT nFlags)
{
	if (nFlags & PRF_ERASEBKGND)
	{
		SendMessage(WM_ERASEBKGND, (WPARAM)pDC->GetSafeHdc());
	}

	return 0L;
}
