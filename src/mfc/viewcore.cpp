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



/////////////////////////////////////////////////////////////////////////////
// CView

BEGIN_MESSAGE_MAP(CView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEACTIVATE()
	ON_WM_CREATE()
	ON_WM_DESTROY()

	// Standard commands for split pane
	ON_COMMAND_EX(ID_WINDOW_SPLIT, &CView::OnSplitCmd)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_SPLIT, &CView::OnUpdateSplitCmd)

	// Standard commands for next pane
	ON_UPDATE_COMMAND_UI(ID_NEXT_PANE, &CView::OnUpdateNextPaneMenu)
	ON_COMMAND_EX(ID_NEXT_PANE, &CView::OnNextPaneCmd)
	ON_UPDATE_COMMAND_UI(ID_PREV_PANE, &CView::OnUpdateNextPaneMenu)
	ON_COMMAND_EX(ID_PREV_PANE, &CView::OnNextPaneCmd)

	// special command for Initial Update
	ON_MESSAGE_VOID(WM_INITIALUPDATE, CView::OnInitialUpdate)

	ON_WM_PRINTCLIENT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView construction/destruction

CView::CView()
{
	m_pDocument = NULL;
	m_bInitialRedraw = FALSE;
}

CView::~CView()
{
	AFX_BEGIN_DESTRUCTOR

		// If we're the current routing view, pop the routing view stack
		_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
		while (pThreadState->m_pRoutingView == this)
			pThreadState->m_pPushRoutingView->Pop();

		if (m_pDocument != NULL)
			m_pDocument->RemoveView(this);

	AFX_END_DESTRUCTOR
}

/////////////////////////////////////////////////////////////////////////////
// CView second phase construction - bind to document

BOOL CView::PreCreateWindow(CREATESTRUCT & cs)
{
	ASSERT(cs.style & WS_CHILD);

	if (cs.lpszClass == NULL)
	{
		VERIFY(AfxDeferRegisterClass(AFX_WNDFRAMEORVIEW_REG));
		cs.lpszClass = _afxWndFrameOrView;  // COLOR_WINDOW background
	}

	if (cs.style & WS_BORDER)
	{
		cs.dwExStyle |= WS_EX_CLIENTEDGE;
		cs.style &= ~WS_BORDER;
	}

	return TRUE;
}

int CView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CWnd::OnCreate(lpcs) == -1)
		return -1;

	// if ok, wire in the current document
	ASSERT(m_pDocument == NULL);
	CCreateContext* pContext = (CCreateContext*)lpcs->lpCreateParams;

	// A view should be created in a given context!
	if (pContext != NULL && pContext->m_pCurrentDoc != NULL)
	{
		pContext->m_pCurrentDoc->AddView(this);
		ASSERT(m_pDocument != NULL);
	}
	else
	{
		TRACE(traceAppMsg, 0, "Warning: Creating a pane with no CDocument.\n");
	}

	return 0;   // ok
}

void CView::OnDestroy()
{
	CFrameWnd* pFrame = GetParentFrame();
	if (pFrame != NULL && pFrame->GetActiveView() == this)
		pFrame->SetActiveView(NULL);    // deactivate during death
	CWnd::OnDestroy();
}

// self destruction
void CView::PostNcDestroy()
{
	// default for views is to allocate them on the heap
	//  the default post-cleanup is to 'delete this'.
	//  never explicitly call 'delete' on a view
	delete this;
}

void CView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType)
{
	ENSURE_ARG(lpClientRect != NULL);
	if (nAdjustType != 0)
	{
		// allow for special client-edge style
		::AdjustWindowRectEx(lpClientRect, 0, FALSE, GetExStyle());

		// default behavior for in-place editing handles scrollbars
		DWORD dwStyle = GetStyle();
		if (dwStyle & WS_VSCROLL)
		{
			int nAdjust = afxData.cxVScroll;
			if (dwStyle & WS_BORDER)
				nAdjust -= AFX_CX_BORDER;
			lpClientRect->right += nAdjust;
		}
		if (dwStyle & WS_HSCROLL)
		{
			int nAdjust = afxData.cyHScroll;
			if (dwStyle & WS_BORDER)
				nAdjust -= AFX_CY_BORDER;
			lpClientRect->bottom += nAdjust;
		}
		return;
	}

	// call default to place borders outside of client rect
	CWnd::CalcWindowRect(lpClientRect, nAdjustType);
}

/////////////////////////////////////////////////////////////////////////////
// Command routing

BOOL CView::OnCmdMsg(UINT nID, int nCode, void* pExtra,
	AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// first pump through pane
	if (CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// then pump through document
	if (m_pDocument != NULL)
	{
		// special state for saving view before routing to document
		CPushRoutingView push(this);
		return m_pDocument->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CView drawing support

void CView::OnPaint()
{
	// standard paint routine
	CPaintDC dc(this);
	OnPrepareDC(&dc);
	OnDraw(&dc);
}

void CView::OnInitialUpdate()
{
	OnUpdate(NULL, 0, NULL);        // initial update
}

void CView::OnUpdate(CView* pSender, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	ASSERT(pSender != this);
	UNUSED(pSender);     // unused in release builds

	// invalidate the entire pane, erase background too
	Invalidate(TRUE);
}

void CView::OnPrint(CDC* pDC, CPrintInfo*)
{
	ASSERT_VALID(pDC);

	// Override and set printing variables based on page number
	OnDraw(pDC);                    // Call Draw
}

void CView::OnDraw(CDC*)
{
}

LRESULT CView::OnPrintClient(CDC* pDC, UINT nFlags)
{
	ASSERT_VALID(pDC);
	if (nFlags & PRF_ERASEBKGND)
	{
		SendMessage(WM_ERASEBKGND, (WPARAM)pDC->GetSafeHdc());
	}

	if (nFlags & PRF_CLIENT)
	{
		OnDraw(pDC);
	}

	return 0L;
}

/////////////////////////////////////////////////////////////////////////////
// CView selection support

BOOL CView::IsSelected(const CObject* pDocItem) const
{
	ASSERT_VALID(pDocItem);
	UNUSED(pDocItem);    // unused in release builds

	return FALSE;   // not implemented, so not selected
}

void CView::OnActivateView(BOOL bActivate, CView* pActivateView, CView*)
{
	UNUSED(pActivateView);   // unused in release builds

	if (bActivate)
	{
		ASSERT(pActivateView == this);

		// take the focus if this frame/view/pane is now active
		if (IsTopParentActive())
			SetFocus();
	}
}

void CView::OnActivateFrame(UINT /*nState*/, CFrameWnd* /*pFrameWnd*/)
{
}

int CView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	int nResult = CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
	if (nResult == MA_NOACTIVATE || nResult == MA_NOACTIVATEANDEAT)
		return nResult;   // frame does not want to activate

	CFrameWnd* pParentFrame = GetParentFrame();
	if (pParentFrame != NULL)
	{
		// eat it if this will cause activation
		ASSERT(pParentFrame == pDesktopWnd || pDesktopWnd->IsChild(pParentFrame));

		// either re-activate the current view, or set this view to be active
		CView* pView = pParentFrame->GetActiveView();
		HWND hWndFocus = ::GetFocus();
		if (pView == this &&
			m_hWnd != hWndFocus && !::IsChild(m_hWnd, hWndFocus))
		{
			// re-activate this view
			OnActivateView(TRUE, this, this);
		}
		else
		{
			// activate this view
			pParentFrame->SetActiveView(this);
		}
	}
	return nResult;
}

/////////////////////////////////////////////////////////////////////////////
// CView scrolling support

BOOL CView::OnScroll(UINT /*nScrollCode*/, UINT /*nPos*/, BOOL /*bDoScroll*/)
{
	return FALSE;
}

BOOL CView::OnScrollBy(CSize /*sizeScroll*/, BOOL /*bDoScroll*/)
{
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CView drag/drop support

DROPEFFECT CView::OnDragScroll(DWORD /*dwKeyState*/, CPoint /*point*/)
{
	return DROPEFFECT_SCROLL; // this means do the default
}

DROPEFFECT CView::OnDragEnter(COleDataObject* /*pDataObject*/,
	DWORD /*dwKeyState*/, CPoint /*point*/)
{
	return 0;   // DROPEFFECT_NONE
}

DROPEFFECT CView::OnDragOver(COleDataObject* /*pDataObject*/,
	DWORD /*dwKeyState*/, CPoint /*point*/)
{
	return 0;   // DROPEFFECT_NONE
}

BOOL CView::OnDrop(COleDataObject* /*pDataObject*/,
	DROPEFFECT /*dropEffect*/, CPoint /*point*/)
{
	return FALSE;
}

DROPEFFECT CView::OnDropEx(COleDataObject* /*pDataObject*/,
	DROPEFFECT /*dropEffect*/, DROPEFFECT /*dropEffectList*/, CPoint /*point*/)
{
	return (DROPEFFECT)-1;  // not implemented
}

void CView::OnDragLeave()
{
}

/////////////////////////////////////////////////////////////////////////////
// CView splitting commands

CSplitterWnd* PASCAL
CView::GetParentSplitter(const CWnd* pWnd, BOOL bAnyState)
{
	ENSURE_VALID(pWnd);
	CSplitterWnd* pSplitter = (CSplitterWnd*)pWnd->GetParent();
	if (!pSplitter->IsKindOf(RUNTIME_CLASS(CSplitterWnd)))
		return NULL;        // not a splitter
	if (!bAnyState)
	{
		// ignore splitters in minimized (iconic) windows
		while ((pWnd = pWnd->GetParent()) != NULL)
			if (pWnd->IsIconic())
				return NULL;
	}
	return pSplitter;
}

CScrollBar* CView::GetScrollBarCtrl(int nBar) const
{
	ASSERT(nBar == SB_HORZ || nBar == SB_VERT);
	if (GetStyle() & ((nBar == SB_HORZ) ? WS_HSCROLL : WS_VSCROLL))
	{
		// it has a regular windows style scrollbar (no control)
		return NULL;
	}

	CWnd* pParent = GetParentSplitter(this, TRUE);
	if (pParent == NULL)
		return NULL;            // no splitter

	UINT nID = _AfxGetDlgCtrlID(m_hWnd);
	if (nID < AFX_IDW_PANE_FIRST || nID > AFX_IDW_PANE_LAST)
		return NULL;            // not a standard pane ID

	// appropriate PANE id - look for sibling (splitter, or just frame)
	UINT nIDScroll;
	if (nBar == SB_HORZ)
		nIDScroll = AFX_IDW_HSCROLL_FIRST + (nID - AFX_IDW_PANE_FIRST) % 16;
	else
		nIDScroll = AFX_IDW_VSCROLL_FIRST + (nID - AFX_IDW_PANE_FIRST) / 16;

	// return shared scroll bars that are immediate children of splitter
	return (CScrollBar*)pParent->GetDlgItem(nIDScroll);
}


void CView::OnUpdateSplitCmd(CCmdUI* pCmdUI)
{
	ENSURE_ARG(pCmdUI != NULL);
	CSplitterWnd* pSplitter = GetParentSplitter(this, FALSE);
	pCmdUI->Enable(pSplitter != NULL && !pSplitter->IsTracking());
}

BOOL CView::OnSplitCmd(UINT)
{
	CSplitterWnd* pSplitter = GetParentSplitter(this, FALSE);
	if (pSplitter == NULL)
		return FALSE;

	ASSERT(!pSplitter->IsTracking());
	pSplitter->DoKeyboardSplit();
	return TRUE;    // attempted at least
}

void CView::OnUpdateNextPaneMenu(CCmdUI* pCmdUI)
{
	ASSERT(pCmdUI->m_nID == ID_NEXT_PANE ||
		pCmdUI->m_nID == ID_PREV_PANE);
	CSplitterWnd* pSplitter = GetParentSplitter(this, FALSE);
	pCmdUI->Enable(pSplitter != NULL &&
		pSplitter->CanActivateNext(pCmdUI->m_nID == ID_PREV_PANE));
}

BOOL CView::OnNextPaneCmd(UINT nID)
{
	CSplitterWnd* pSplitter = GetParentSplitter(this, FALSE);
	if (pSplitter == NULL)
		return FALSE;

	ASSERT(nID == ID_NEXT_PANE || nID == ID_PREV_PANE);
	pSplitter->ActivateNext(nID == ID_PREV_PANE);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Printing support virtual functions (others in viewpr.cpp)

void CView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	ASSERT_VALID(pDC);
	UNUSED(pDC); // unused in release builds

	// Default to one page printing if doc length not known
	if (pInfo != NULL)
		pInfo->m_bContinuePrinting =
			(pInfo->GetMaxPage() != 0xffff || (pInfo->m_nCurPage == 1));
}

BOOL CView::OnPreparePrinting(CPrintInfo*)
{
	// Do print DC initialization here
	// override and call DoPreparePrinting (in viewprnt.cpp)

	return TRUE;
}

void CView::OnBeginPrinting(CDC* pDC, CPrintInfo*)
{
	ASSERT_VALID(pDC);
	UNUSED(pDC);     // unused in release builds

	// Do printing initialization here
}

void CView::OnEndPrinting(CDC* pDC, CPrintInfo*)
{
	ASSERT_VALID(pDC);
	UNUSED(pDC);     // unused in release builds

	// Do printing cleanup here
}

// OnEndPrintPreview is here for swap tuning reasons
//  (see viewprev.cpp for complete preview mode implementation)
void CView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo,
			POINT, CPreviewView* pView)
{
	ASSERT_VALID(pDC);
	ASSERT_VALID(pView);

	if (pView->m_pPrintView != NULL)
		pView->m_pPrintView->OnEndPrinting(pDC, pInfo);

	CWnd* pMainWnd = GetParentFrame();
	if (DYNAMIC_DOWNCAST(CFrameWnd, pMainWnd) == NULL)
	{
		// if it's not a frame, we'll try the main window
		pMainWnd = AfxGetMainWnd();
	}

	CFrameWnd* pParent = STATIC_DOWNCAST(CFrameWnd, pMainWnd);
	ASSERT_VALID(pParent);

	// restore the old main window
	pParent->OnSetPreviewMode(FALSE, pView->m_pPreviewState);

	// Force active view back to old one
	pParent->SetActiveView(pView->m_pPreviewState->pViewActiveOld);
	if (pParent != GetParentFrame())
		OnActivateView(TRUE, this, this);   // re-activate view in real frame
	pView->DestroyWindow();     // destroy preview view
			// C++ object will be deleted in PostNcDestroy

	// restore main frame layout and idle message
	pParent->RecalcLayout();
	pParent->SendMessage(WM_SETMESSAGESTRING, (WPARAM)AFX_IDS_IDLEMESSAGE, 0L);
	pParent->UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CView diagnostics

#ifdef _DEBUG
void CView::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);

	if (m_pDocument != NULL)
		dc << "with document: " << m_pDocument;
	else
		dc << "with no document\n";
}

void CView::AssertValid() const
{
	CWnd::AssertValid();
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCtrlView

BEGIN_MESSAGE_MAP(CCtrlView, CView)
	ON_WM_PAINT()
	ON_WM_PRINTCLIENT()
END_MESSAGE_MAP()

CCtrlView::~CCtrlView()
{
}

CCtrlView::CCtrlView(LPCTSTR lpszClass, DWORD dwStyle)
{
	m_strClass = lpszClass;
	m_dwDefaultStyle = dwStyle;
}

BOOL CCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	ASSERT(cs.lpszClass == NULL);
	cs.lpszClass = m_strClass;

	// initialize common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTLS_REG));
	AfxDeferRegisterClass(AFX_WNDCOMMCTLSNEW_REG);

	// map default CView style to default style
	// WS_BORDER is insignificant
	if ((cs.style | WS_BORDER) == AFX_WS_DEFAULT_VIEW)
		cs.style = m_dwDefaultStyle & (cs.style | ~WS_BORDER);

	return CView::PreCreateWindow(cs);
}

void CCtrlView::OnDraw(CDC*)
{
	ASSERT(FALSE);
}

void CCtrlView::OnPaint()
{
	// this is done to avoid CView::OnPaint
	Default();
}

LRESULT CCtrlView::OnPrintClient(CDC* /*pDC*/, UINT /*nFlags*/)
{
	return Default();
}

/////////////////////////////////////////////////////////////////////////////
// CCtrlView diagnostics

#ifdef _DEBUG
void CCtrlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
	dc << "\nClass Name: " << m_strClass;
	dc << "\nDefault Style: ";
	dc.DumpAsHex(m_dwDefaultStyle);
}

void CCtrlView::AssertValid() const
{
	CWnd::AssertValid();
	ASSERT(!m_strClass.IsEmpty());
}
#endif //_DEBUG


// IMPLEMENT_DYNAMIC for CView is in wincore.cpp for .OBJ granularity reasons

IMPLEMENT_DYNAMIC(CSplitterWnd, CWnd)   // for swap tuning
IMPLEMENT_DYNAMIC(CCtrlView, CView)

/////////////////////////////////////////////////////////////////////////////
