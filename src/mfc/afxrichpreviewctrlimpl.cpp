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

IMPLEMENT_DYNAMIC(CMFCPreviewCtrlImpl, CWnd)

CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl()
{
	m_clrBackColor = RGB (255, 255, 255);
	m_clrTextColor = RGB (0, 0, 0);
}

CMFCPreviewCtrlImpl::~CMFCPreviewCtrlImpl()
{
}


BEGIN_MESSAGE_MAP(CMFCPreviewCtrlImpl, CWnd)
	ON_WM_NCDESTROY()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CMFCPreviewCtrlImpl::Create (HWND hWndParent, const RECT* prc)
{
	return Create (hWndParent, prc, NULL);
}
BOOL CMFCPreviewCtrlImpl::Create (HWND hWndParent, const RECT* prc, CCreateContext* pContext)
{
	if (prc == NULL)	
	{
		TRACE0("CMFCPreviewCtrlImpl::Create failed: prc is NULL");
		return FALSE;
	}

	CreateEx (0, NULL, _T (""), WS_CHILD | WS_VISIBLE, prc->left, prc->top, 
		prc->right - prc->left, 
		prc->bottom - prc->top, hWndParent, (HMENU) 1);

	if (pContext != NULL && pContext->m_pNewViewClass != NULL)
	{
		DWORD dwStyle = AFX_WS_DEFAULT_VIEW & ~WS_BORDER;
		CView* pView = (CView*) pContext->m_pNewViewClass->CreateObject ();

		CRect rectHost (prc); 
		// Create with the right size (wrong position)
		CRect rect(CPoint(0,0), rectHost.Size ());

		if (!pView->Create(NULL, NULL, dwStyle | WS_VISIBLE,
			rect, this, AFX_PREVIEW_VIEW_ID, pContext))
		{
			TRACE(traceAppMsg, 0, "Warning: couldn't create view.\n");
			// pWnd will be cleaned up by PostNcDestroy
			return FALSE;
		}
		pView->OnInitialUpdate ();
	}

	return TRUE;
}

// CMFCPreviewCtrlImpl message handlers



void CMFCPreviewCtrlImpl::OnNcDestroy()
{
	CWnd::OnNcDestroy();
}

void CMFCPreviewCtrlImpl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	DoPaint (&dc);
}

BOOL CMFCPreviewCtrlImpl::OnEraseBkgnd(CDC* pDC)
{
	UNREFERENCED_PARAMETER(pDC);
	return TRUE;
}
void CMFCPreviewCtrlImpl::DoPaint (CPaintDC* pDC)
{
	UNREFERENCED_PARAMETER(pDC);
}
void CMFCPreviewCtrlImpl::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	CWnd* pWnd = GetDlgItem (AFX_PREVIEW_VIEW_ID);

	if (pWnd != NULL && ::IsWindow (pWnd->GetSafeHwnd ()))
	{
		ASSERT_VALID (pWnd);

		CRect rect;
		GetClientRect (rect);

		pWnd->SetWindowPos (NULL, 0, 0, rect.Width (), rect.Height (), 
			SWP_NOZORDER | SWP_NOACTIVATE);
	}
}
void CMFCPreviewCtrlImpl::SetPreviewVisuals (COLORREF clrBack, COLORREF clrText, const LOGFONTW *plf)
{
	m_clrBackColor = clrBack;
	m_clrTextColor = clrText;
	if (plf != NULL)
	{
#ifdef UNICODE
		m_font.CreateFontIndirect (plf);
#else
		LOGFONTA lf;
		memcpy (&lf, plf, sizeof (LOGFONTA));

		size_t  i;
		size_t	bufSize = 32;
		wcstombs_s (&i, lf.lfFaceName, bufSize, plf->lfFaceName, bufSize);
		m_font.CreateFontIndirect (&lf);
#endif
	}
}

void CMFCPreviewCtrlImpl::Destroy ()
{
	if (::IsWindow (m_hWnd))
	{
		DestroyWindow ();
	}
}

void CMFCPreviewCtrlImpl::SetHost (HWND hWndParent)
{
	if (::IsWindow (m_hWnd))
	{
		::SetParent (m_hWnd, hWndParent);
	}
}

void CMFCPreviewCtrlImpl::Redraw ()
{
	if (::IsWindow (m_hWnd))
	{
		Invalidate ();
		UpdateWindow ();
	}
}

void CMFCPreviewCtrlImpl::SetRect (const RECT* prc, BOOL bRedraw)
{
	if (::IsWindow (m_hWnd) && prc != NULL)
	{
		SetWindowPos (NULL, prc->left, prc->top, prc->right - prc->left, 
			prc->bottom - prc->top, SWP_NOACTIVATE | SWP_NOREDRAW | SWP_NOZORDER);

		if (bRedraw)
		{
			Redraw ();
		}
	}
}

void CMFCPreviewCtrlImpl::Focus ()
{
	if (::IsWindow (m_hWnd))
	{
		SetFocus ();
	}
}