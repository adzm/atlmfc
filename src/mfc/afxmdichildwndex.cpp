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
#include "afxcontrolbarutil.h"
#include "afxmdiframewndex.h"
#include "afxmdichildwndex.h"
#include "afxpaneframewnd.h"
#include "afxpreviewviewex.h"
#include "afxmdiclientareawnd.h"
#include "afxglobalutils.h"
#include "afxdockablepane.h"
#include "afxdatarecovery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BOOL CMDIChildWndEx::m_bEnableFloatingBars = FALSE;
DWORD CMDIChildWndEx::m_dwExcludeStyle = WS_CAPTION | WS_BORDER | WS_THICKFRAME;
DWORD CMDIChildWndEx::m_dwDefaultTaskbarTabPropertyFlags = STPF_USEAPPTHUMBNAILWHENACTIVE | STPF_USEAPPPEEKWHENACTIVE;

UINT AFX_WM_AFTER_TASKBAR_ACTIVATE = ::RegisterWindowMessage (_T("AFX_WM_AFTER_TASKBAR_ACTIVATE"));

typedef HRESULT (STDAPICALLTYPE *PFNSETWINDOWATTRIBUTE)(HWND, DWORD, LPCVOID, DWORD);
typedef HRESULT (STDAPICALLTYPE *PFNSETICONICTHUMBNAIL)(HWND, HBITMAP, DWORD);
typedef HRESULT (STDAPICALLTYPE *PFNSETICONICLIVEPRBMP)(HWND, HBITMAP, POINT *, DWORD);
typedef HRESULT (STDAPICALLTYPE *PFNINVALIDATEICONICBITMAPS)(HWND);

/////////////////////////////////////////////////////////////////////////////
// CMDIChildWndEx

IMPLEMENT_DYNCREATE(CMDIChildWndEx, CMDIChildWnd)

#pragma warning(disable : 4355)

CMDIChildWndEx::CMDIChildWndEx() : m_Impl(this)
{
	m_pMDIFrame = NULL;
	m_bToBeDestroyed = FALSE;
	m_bWasMaximized = FALSE;
	m_bIsMinimized = FALSE;
	m_rectOriginal.SetRectEmpty();
	m_bActivating = FALSE;
	m_bInOnCreate = FALSE;

	// ---- MDITabGroup+
	m_pRelatedTabGroup = NULL;
	// ---- MDITabGroup-

	m_pTabbedControlBar = NULL;
	m_bTabRegistered = FALSE;
	m_bEnableTaskbarThumbnailClip = TRUE;
}

#pragma warning(default : 4355)

CMDIChildWndEx::~CMDIChildWndEx()
{
}

BEGIN_MESSAGE_MAP(CMDIChildWndEx, CMDIChildWnd)
	ON_WM_CREATE()
	ON_WM_MDIACTIVATE()
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_DESTROY()
	ON_WM_GETMINMAXINFO()
	ON_WM_NCPAINT()
	ON_WM_NCACTIVATE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCHITTEST()
	ON_WM_NCCALCSIZE()
	ON_WM_LBUTTONUP()
	ON_WM_NCRBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_ERASEBKGND()
	ON_WM_STYLECHANGED()
	ON_WM_SYSCOMMAND()
	ON_WM_SETTEXT()
	ON_WM_SETICON()
	ON_MESSAGE(WM_IDLEUPDATECMDUI, &CMDIChildWndEx::OnIdleUpdateCmdUI)
	ON_REGISTERED_MESSAGE(AFX_WM_CHANGEVISUALMANAGER, &CMDIChildWndEx::OnChangeVisualManager)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIChildWndEx message handlers

BOOL CMDIChildWndEx::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message >= WM_KEYFIRST && pMsg->message <= WM_KEYLAST && m_pMDIFrame != NULL && m_pMDIFrame->GetActivePopup() != NULL)
	{
		// Don't process accelerators if popup window is active
		return FALSE;
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE && m_pRelatedTabGroup != NULL && GetCapture() == m_pRelatedTabGroup)
	{
		m_pRelatedTabGroup->PostMessage(WM_CANCELMODE);
		return CMDIChildWnd::PreTranslateMessage(pMsg);
	}

	return CMDIChildWnd::PreTranslateMessage(pMsg);
}

int CMDIChildWndEx::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	m_pMDIFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetMDIFrame());
	ASSERT_VALID(m_pMDIFrame);

	m_Impl.m_bHasBorder = (lpCreateStruct->style & WS_BORDER) != NULL;
	m_bInOnCreate = TRUE;

	if ((GetStyle() & WS_SYSMENU) == 0)
	{
		GetParent()->SetRedraw(FALSE);

		m_rectOriginal = CRect(CPoint(lpCreateStruct->x, lpCreateStruct->y), CSize(lpCreateStruct->cx, lpCreateStruct->cy));

		if (m_pMDIFrame != NULL && !m_pMDIFrame->IsMDITabbedGroup())
		{
			CRect rect;
			m_pMDIFrame->m_wndClientArea.GetClientRect(rect);

			CRect rectClient;
			GetClientRect(rectClient);
			ClientToScreen(rectClient);

			CRect rectScreen;
			GetWindowRect(rectScreen);

			rect.left -= rectClient.left - rectScreen.left;
			rect.top -= rectClient.top - rectScreen.top;
			rect.right += rectScreen.right - rectClient.right;
			rect.bottom += rectScreen.bottom - rectClient.bottom;

			SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
		}

		GetParent()->SetRedraw(TRUE);
	}

	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
	{
		m_bInOnCreate = FALSE;
		return -1;
	}

	if (m_pMDIFrame->IsPrintPreview())
	{
		m_pMDIFrame->SendMessage(WM_CLOSE);
	}

	CFrameImpl::AddFrame(this);
	RegisterTaskbarTab();

	PostMessage(AFX_WM_CHANGEVISUALMANAGER);

	m_bInOnCreate = FALSE;
	return 0;
}
void CMDIChildWndEx::RegisterTaskbarTab(CMDIChildWndEx* pWndBefore)
{
	ASSERT_VALID(this);

	if (!IsTaskbarTabsSupportEnabled())
	{
		return;
	}

	if (m_tabProxyWnd.GetSafeHwnd() != NULL)
	{
		// attempt to create a proxy despite it has been already created
		return;
	}

	m_tabProxyWnd.SetRelatedMDIChildFrame(this);
	CRect rect(CPoint(-32000, -32000), CSize(10, 10));

	CString strClassName = GetGlobalData()->RegisterWindowClass(_T("AFX_SUPERBAR_TAB"));
	CString strWindowText;
	GetWindowText(strWindowText);

	if (!m_tabProxyWnd.CreateEx(WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, strClassName, strWindowText, 
		WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, rect, NULL, 0, NULL))
	{
		TRACE1("Creation of tab proxy window failed, error code: %d", GetLastError());
		return;
	}

	ITaskbarList3* pTaskbarList3 = GetGlobalData()->GetITaskbarList3();
	if (pTaskbarList3)
	{
		CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
		ASSERT_VALID(pTopLevel);

		HRESULT hr = pTaskbarList3->RegisterTab(m_tabProxyWnd.GetSafeHwnd(), pTopLevel->GetSafeHwnd());
		if (FAILED(hr))
		{
			TRACE1("Registration of tab failed, error code: %x", hr);
			UnregisterTaskbarTab();
			return;
		}

		if (pWndBefore == NULL && m_pMDIFrame != NULL)
		{
			// attempt to find right place automatically
			pWndBefore = m_pMDIFrame->m_wndClientArea.FindNextRegisteredWithTaskbarMDIChild(this);
		}

		CMDITabProxyWnd* pProxyWnd = pWndBefore != NULL ? pWndBefore->GetTabProxyWnd() : NULL;

		hr = pTaskbarList3->SetTabOrder(m_tabProxyWnd.GetSafeHwnd(), pProxyWnd->GetSafeHwnd());
		if (FAILED(hr))
		{
			TRACE1("Setting of tab order failed, error code: %x", hr);
			UnregisterTaskbarTab();
			return;
		}

		if (m_pMDIFrame != NULL && m_pMDIFrame->MDIGetActive() == this)
		{
			SetTaskbarTabActive();
		}

		// Set the appropriate DWM properties on the MDI child window
		BOOL bHasIconicBitmap = TRUE;

		_AfxDwmSetWindowAttribute(m_tabProxyWnd.GetSafeHwnd(), DWMWA_HAS_ICONIC_BITMAP, &bHasIconicBitmap, sizeof(BOOL));
		_AfxDwmSetWindowAttribute(m_tabProxyWnd.GetSafeHwnd(), DWMWA_FORCE_ICONIC_REPRESENTATION, &bHasIconicBitmap, sizeof(BOOL));

		SetTaskbarTabProperties(m_dwDefaultTaskbarTabPropertyFlags);
		SetTaskbarTabText(strWindowText);
	}

	m_bTabRegistered = TRUE;

	// clips view area on taskbar thumbnail after registration
	if (IsRegisteredWithTaskbarTabs())
	{
		InvalidateIconicBitmaps();
	}
}

BOOL CMDIChildWndEx::IsRegisteredWithTaskbarTabs()
{
	return m_tabProxyWnd.GetSafeHwnd() != NULL;
}

BOOL CMDIChildWndEx::IsTaskbarTabsSupportEnabled()
{
	CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
	if (pTopLevel == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pTopLevel);

	CWinApp* pApp = AfxGetApp();
	if(pApp == NULL)
	{
		return FALSE;
	}

	ASSERT_VALID(pApp);

	if (!pApp->IsTaskbarInteractionEnabled() || !CanShowOnTaskBarTabs() || !GetGlobalData()->bIsWindows7 || (GetStyle () & WS_SYSMENU) != 0)
	{
		return FALSE;
	}

	return TRUE;
}
BOOL CMDIChildWndEx::InvalidateIconicBitmaps()
{
	ASSERT_VALID(this);

	if (!IsTaskbarTabsSupportEnabled() || !IsRegisteredWithTaskbarTabs()) 
	{
		return FALSE;
	}

	CRect rectThumbnailClip(0, 0, 0, 0);
	if (m_bEnableTaskbarThumbnailClip)
	{
		rectThumbnailClip = GetTaskbarThumbnailClipRect();
	}

	SetTaskbarThumbnailClipRect(rectThumbnailClip);

	_AfxDwmInvalidateIconicBitmaps(m_tabProxyWnd.GetSafeHwnd());

	return TRUE;
}
void CMDIChildWndEx::UpdateTaskbarTabIcon(HICON hIcon)
{
	if (m_tabProxyWnd.GetSafeHwnd() != NULL)
	{
		m_tabProxyWnd.SetIcon(hIcon, FALSE);
	}
}
void CMDIChildWndEx::SetTaskbarTabOrder(CMDIChildWndEx* pWndBefore)
{
	ASSERT_VALID(this);

	if (!IsTaskbarTabsSupportEnabled() || !IsRegisteredWithTaskbarTabs()) 
	{
		return;
	}

	if (m_tabProxyWnd.GetSafeHwnd() != NULL)
	{
		ITaskbarList3* pTaskbarList = GetGlobalData()->GetITaskbarList3();
		ASSERT(pTaskbarList != NULL);

		HWND hWndBefore = pWndBefore != NULL ? pWndBefore->GetTabProxyWnd()->GetSafeHwnd() : NULL;
		if (pTaskbarList != NULL)
		{
			pTaskbarList->SetTabOrder(m_tabProxyWnd.GetSafeHwnd(), hWndBefore);
		}
	}
}

void CMDIChildWndEx::SetTaskbarTabProperties(DWORD dwFlags)
{
	ASSERT_VALID(this);

	if (!IsTaskbarTabsSupportEnabled() || !IsRegisteredWithTaskbarTabs()) 
	{
		return;
	}

	if (m_tabProxyWnd.GetSafeHwnd() != NULL)
	{
		ITaskbarList3* pTaskbarList = GetGlobalData()->GetITaskbarList3();
		ASSERT(pTaskbarList != NULL);

		CComQIPtr<ITaskbarList4> spTaskbarList4 = pTaskbarList;

		if (spTaskbarList4 != NULL)
		{
			HRESULT hr = spTaskbarList4->SetTabProperties(m_tabProxyWnd.GetSafeHwnd(), (STPFLAG)dwFlags);

			if (FAILED(hr))
			{
				TRACE1("CMDIChildWndEx::SetTaskbarTabProperties failed with code %x\n", hr);
			}
		}
	}
}

BOOL CMDIChildWndEx::DockPaneLeftOf(CPane* pBar, CPane* pLeftOf)
{
	m_dockManager.DockPaneLeftOf(pBar, pLeftOf);
	return TRUE;
}
void CMDIChildWndEx::SetTaskbarTabActive()
{
	ASSERT_VALID(this);

	if (!IsTaskbarTabsSupportEnabled())
		return;

	ITaskbarList3 *pTaskbarList3 = GetGlobalData()->GetITaskbarList3();
	if (pTaskbarList3)
	{
		CMDIFrameWndEx* pParentFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
		ASSERT_VALID(pParentFrame);
		pTaskbarList3->SetTabActive(m_tabProxyWnd.GetSafeHwnd(), pParentFrame->GetSafeHwnd(), 0);
	}
}
void CMDIChildWndEx::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd)
{
	static BOOL bActivating = FALSE;

	m_dockManager.OnActivateFrame(bActivate);

	m_bActivating = bActivate;

	if (!bActivating)
	{
		bActivating = TRUE;

		CMDIChildWnd::OnMDIActivate(bActivate, pActivateWnd, pDeactivateWnd);

		if (bActivate && m_pMDIFrame != NULL)
		{
			ASSERT_VALID(m_pMDIFrame);
			m_pMDIFrame->m_wndClientArea.SetActiveTab(pActivateWnd->GetSafeHwnd());
		}

		// If in MDI Tabbed or MDI Tabbed Group, mode, and if the application wants
		// the behavior, set the MDI child as the active tab in the task bar tab list.
		if (IsTaskbarTabsSupportEnabled() && IsRegisteredWithTaskbarTabs())
		{
			CWinApp* pApp = AfxGetApp();
			if (pApp != NULL)
			{
				CDataRecoveryHandler *pHandler = pApp->GetDataRecoveryHandler();
				if ((pHandler == NULL) || (!pHandler->GetShutdownByRestartManager()))
				{
					InvalidateIconicBitmaps();
					CMDIChildWndEx* pChild = DYNAMIC_DOWNCAST(CMDIChildWndEx, pDeactivateWnd);
					if (pChild != NULL)
					{
						pChild->InvalidateIconicBitmaps();
					}

					SetTaskbarTabActive();
				}
			}
		}

		bActivating = FALSE;

		if (bActivate && m_pMDIFrame != NULL)
		{
			CDockingManager* parentDockManager = m_pMDIFrame->GetDockingManager();
			ASSERT_VALID(parentDockManager);

			if (parentDockManager != NULL && parentDockManager->IsOLEContainerMode() || m_dockManager.IsOLEContainerMode())
			{
				//parentDockManager->AdjustDockingLayout();
				afxGlobalUtils.ForceAdjustLayout(parentDockManager, TRUE);
			}
		}
	}

	if (bActivate && !IsTaskbarTabsSupportEnabled() || !IsRegisteredWithTaskbarTabs())
	{
		SetTaskbarThumbnailClipRect(CRect(0, 0, 0, 0));
	}
}

void CMDIChildWndEx::ActivateFrame(int nCmdShow)
{
	CWnd* pWndParent = GetParent();
	ASSERT_VALID(pWndParent);

	if (CMDIFrameWndEx::m_bDisableSetRedraw || pWndParent->GetSafeHwnd() == NULL)
	{
		if ((GetStyle() & WS_SYSMENU) == 0)
		{
			nCmdShow = SW_SHOWMAXIMIZED;
		}

		if (m_pMDIFrame != 0 && m_pMDIFrame->IsMDITabbedGroup())
		{
			nCmdShow = SW_SHOWNORMAL;
		}

		CMDIChildWnd::ActivateFrame(nCmdShow);
		return;
	}

	pWndParent->SetRedraw(FALSE);

	CMDIChildWnd::ActivateFrame(nCmdShow);

	pWndParent->SetRedraw(TRUE);
	pWndParent->RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN);
}

int CMDIChildWndEx::OnSetText(LPCTSTR lpszText)
{
	LRESULT lRes = Default();

	if (m_pMDIFrame != NULL)
	{
		ASSERT_VALID(m_pMDIFrame);
		m_pMDIFrame->m_wndClientArea.UpdateTabs(TRUE);
	}

	m_Impl.OnSetText(lpszText);
	SetTaskbarTabText(lpszText);

	return (int)lRes;
}

void CMDIChildWndEx::SetTaskbarTabText(LPCTSTR lpcszDefaultText)
{
	if (IsTaskbarTabsSupportEnabled() && IsRegisteredWithTaskbarTabs() && lpcszDefaultText != NULL)
	{
		CMDIFrameWndEx* pWnd = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
		if (pWnd == NULL)
		{
			return;
		}

		DWORD dwStyle = pWnd->GetStyle();

		if ((dwStyle & FWS_ADDTOTITLE) == FWS_ADDTOTITLE)
		{
			CString strFrameTitle = pWnd->GetTitle();
			CString strWndName;
			CString strChildTitle(lpcszDefaultText);

			if ((dwStyle & FWS_PREFIXTITLE) == FWS_PREFIXTITLE)
			{
				strWndName = strChildTitle + _T(" - ") + strFrameTitle;
			}
			else
			{
				strWndName = strFrameTitle + _T(" - ") + strChildTitle;
			}
			m_tabProxyWnd.SetWindowText((LPCTSTR)strWndName);
		}
		else
		{
			m_tabProxyWnd.SetWindowText(lpcszDefaultText);
		}
	}
}

HICON CMDIChildWndEx::OnSetIcon(BOOL /*bIsLarge*/, HICON /*hIcon*/)
{
	HICON hIcon = (HICON)Default();

	if (m_pMDIFrame != NULL)
	{
		ASSERT_VALID(m_pMDIFrame);
		m_pMDIFrame->m_wndClientArea.UpdateTabs();
	}

	return hIcon;
}

CString CMDIChildWndEx::GetFrameText() const
{
	ASSERT_VALID(this);

	CString strText;
	GetWindowText(strText);

	return strText;
}

HICON CMDIChildWndEx::GetFrameIcon() const
{
	ASSERT_VALID(this);

	HICON hIcon = GetIcon(FALSE);
	if (hIcon == NULL)
	{
		hIcon = (HICON)(LONG_PTR) GetClassLongPtr(GetSafeHwnd(), GCLP_HICONSM);
	}

	return hIcon;
}

void CMDIChildWndEx::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	BOOL bRedraw = m_Impl.IsOwnerDrawCaption() && IsWindowVisible() &&(GetStyle() & WS_MAXIMIZE) == 0;

	CString strTitle1;

	if (bRedraw)
	{
		GetWindowText(strTitle1);
	}

	CMDIChildWnd::OnUpdateFrameTitle(bAddToTitle);

	if (bRedraw)
	{
		CString strTitle2;
		GetWindowText(strTitle2);

		if (strTitle1 != strTitle2)
		{
			SendMessage(WM_NCPAINT, 0, 0);
		}
	}

	if (m_pMDIFrame != NULL)
	{
		ASSERT_VALID(m_pMDIFrame);
		m_pMDIFrame->m_wndClientArea.UpdateTabs();
	}
}

void CMDIChildWndEx::OnSize(UINT nType, int cx, int cy)
{
	if (m_bToBeDestroyed)
	{
		// prevents main menu flickering when the last document is being closed
		return;
	}

	InvalidateIconicBitmaps();

	m_bIsMinimized = (nType == SIZE_MINIMIZED);

	if (CMFCVisualManager::GetInstance()->IsOwnerDrawCaption())
	{
		if (m_pMDIFrame != NULL && !m_pMDIFrame->IsMDITabbedGroup())
		{
			CRect rectWindow;
			GetWindowRect(rectWindow);

			WINDOWPOS wndpos;
			wndpos.flags = SWP_FRAMECHANGED;
			wndpos.x     = rectWindow.left;
			wndpos.y     = rectWindow.top;
			wndpos.cx    = rectWindow.Width();
			wndpos.cy    = rectWindow.Height();

			m_Impl.OnWindowPosChanging(&wndpos);
		}
		else if (m_Impl.m_bIsWindowRgn)
		{
			m_Impl.m_bIsWindowRgn = FALSE;
			SetWindowRgn(NULL, TRUE);
		}
	}

	if (!m_bIsMinimized && nType != SIZE_MAXIMIZED && !m_bWasMaximized)
	{
		m_dockManager.m_bSizeFrame = TRUE;
		CMDIChildWnd::OnSize(nType, cx, cy);
		AdjustDockingLayout();
		m_dockManager.m_bSizeFrame = FALSE;

		m_Impl.UpdateCaption();
		return;
	}

	CMDIChildWnd::OnSize(nType, cx, cy);

	if ((nType == SIZE_MAXIMIZED ||(nType == SIZE_RESTORED && m_bWasMaximized)))
	{
		RecalcLayout();

		if (m_pNotifyHook != NULL && nType == SIZE_RESTORED)
		{
			CMDIFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetParentFrame());
			if (pTopLevelFrame == NULL || !pTopLevelFrame->AreMDITabs())
			{
				ModifyStyle(0, WS_OVERLAPPEDWINDOW);
			}
		}
	}

	m_bWasMaximized = (nType == SIZE_MAXIMIZED);
	m_Impl.UpdateCaption();
}

BOOL CMDIChildWndEx::PreCreateWindow(CREATESTRUCT& cs)
{
	m_dockManager.Create(this);
	return CMDIChildWnd::PreCreateWindow(cs);
}

void CMDIChildWndEx::AddDockSite()
{
	ASSERT_VALID(this);
}

BOOL CMDIChildWndEx::AddPane(CBasePane* pControlBar, BOOL bTail)
{
	ASSERT_VALID(this);
	return m_dockManager.AddPane(pControlBar, bTail);
}

BOOL CMDIChildWndEx::InsertPane(CBasePane* pControlBar, CBasePane* pTarget, BOOL bAfter)
{
	ASSERT_VALID(this);
	return m_dockManager.InsertPane(pControlBar, pTarget, bAfter);
}

void CMDIChildWndEx::RemovePaneFromDockManager(CBasePane* pControlBar, BOOL bDestroy, BOOL bAdjustLayout, BOOL bAutoHide, CBasePane* pBarReplacement)
{
	ASSERT_VALID(this);
	m_dockManager.RemovePaneFromDockManager(pControlBar, bDestroy, bAdjustLayout, bAutoHide, pBarReplacement);
}

void CMDIChildWndEx::DockPane(CBasePane* pBar, UINT nDockBarID, LPCRECT /*lpRect*/)
{
	ASSERT_VALID(this);

	if (pBar->CanFloat() && !CMDIChildWndEx::m_bEnableFloatingBars)
	{
		// bar can't be floating
		pBar->m_dwControlBarStyle &= ~AFX_CBRS_FLOAT;
	}

	if (pBar->CanBeResized() || pBar->CanFloat())
	{
		pBar->EnableDocking(CBRS_ALIGN_ANY);
		m_dockManager.DockPane(pBar, nDockBarID);
	}
	else
	{
		AddPane(pBar, TRUE);
	}
}

void CMDIChildWndEx::OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState)
{
	ASSERT_VALID(this);

	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, AfxGetMainWnd());
	if (pMainFrame != NULL)
	{
		pMainFrame->SetPrintPreviewFrame(bPreview ? this : NULL);
	}

	m_dockManager.SetPrintPreviewMode(bPreview, pState);
	DWORD dwSavedState = pState->dwStates;
	CMDIChildWnd::OnSetPreviewMode(bPreview, pState);
	pState->dwStates = dwSavedState;

	AdjustDockingLayout();
	RecalcLayout();
}

CBasePane* CMDIChildWndEx::GetPane(UINT nID)
{
	ASSERT_VALID(this);

	CBasePane* pBar = m_dockManager.FindPaneByID(nID, TRUE);
	return pBar;
}

void CMDIChildWndEx::ShowPane(CBasePane* pBar, BOOL bShow, BOOL bDelay, BOOL bActivate)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pBar);

	pBar->ShowPane(bShow, bDelay, bActivate);
}

CBasePane* CMDIChildWndEx::PaneFromPoint(CPoint point, int nSensitivity, bool bExactBar, CRuntimeClass* pRTCBarType) const
{
	ASSERT_VALID(this);
	return m_dockManager.PaneFromPoint(point, nSensitivity, bExactBar, pRTCBarType);
}

CBasePane* CMDIChildWndEx::PaneFromPoint(CPoint point, int nSensitivity, DWORD& dwAlignment, CRuntimeClass* pRTCBarType) const
{
	ASSERT_VALID(this);
	return m_dockManager.PaneFromPoint(point, nSensitivity, dwAlignment, pRTCBarType);
}

BOOL CMDIChildWndEx::IsPointNearDockSite(CPoint point, DWORD& dwBarAlignment, BOOL& bOuterEdge) const
{
	ASSERT_VALID(this);
	return m_dockManager.IsPointNearDockSite(point, dwBarAlignment, bOuterEdge);
}

void CMDIChildWndEx::AdjustDockingLayout(HDWP hdwp)
{
	ASSERT_VALID(this);

	if (m_dockManager.IsInAdjustLayout())
	{
		return;
	}

	m_dockManager.AdjustDockingLayout(hdwp);
	AdjustClientArea();
}

void CMDIChildWndEx::AdjustClientArea()
{
	CWnd* pChildWnd = (m_pTabbedControlBar != NULL && m_pTabbedControlBar->IsMDITabbed() &&
		m_pTabbedControlBar->GetParent() == this) ? m_pTabbedControlBar : GetDlgItem(AFX_IDW_PANE_FIRST);
	if (pChildWnd != NULL)
	{
		if (!pChildWnd->IsKindOf(RUNTIME_CLASS(CSplitterWnd)) && !pChildWnd->IsKindOf(RUNTIME_CLASS(CFormView)))
		{
			pChildWnd->ModifyStyle(0, WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
		}
		else
		{
			pChildWnd->ModifyStyle(0, WS_CLIPSIBLINGS);
		}

		if (!m_bInOnCreate && !CDockingManager::m_bFullScreenMode)
		{
			CRect rectClientAreaBounds = m_dockManager.GetClientAreaBounds();

			rectClientAreaBounds.left += m_rectBorder.left;
			rectClientAreaBounds.top  += m_rectBorder.top;
			rectClientAreaBounds.right -= m_rectBorder.right;
			rectClientAreaBounds.bottom -= m_rectBorder.bottom;

			pChildWnd->SetWindowPos(&wndBottom, rectClientAreaBounds.left, rectClientAreaBounds.top,
				rectClientAreaBounds.Width(), rectClientAreaBounds.Height(), SWP_NOACTIVATE);
		}
	}
}

BOOL CMDIChildWndEx::OnMoveMiniFrame(CWnd* pFrame)
{
	ASSERT_VALID(this);
	return m_dockManager.OnMoveMiniFrame(pFrame);
}

BOOL CMDIChildWndEx::EnableDocking(DWORD dwDockStyle)
{
	return m_dockManager.EnableDocking(dwDockStyle);
}

BOOL CMDIChildWndEx::EnableAutoHidePanes(DWORD dwDockStyle)
{
	return m_dockManager.EnableAutoHidePanes(dwDockStyle);
}

void CMDIChildWndEx::RecalcLayout(BOOL bNotify)
{
	if (m_bInRecalcLayout)
		return;

	m_bInRecalcLayout = TRUE;

	if (!m_bIsMinimized)
	{
		CView* pView = GetActiveView();

		if (m_dockManager.IsPrintPreviewValid() || m_dockManager.IsOLEContainerMode())
		{
			if (pView != NULL && pView->IsKindOf(RUNTIME_CLASS(CPreviewViewEx)))
			{

				m_dockManager.RecalcLayout(bNotify);
				CRect rectClient = m_dockManager.GetClientAreaBounds();
				pView->SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_NOZORDER  | SWP_NOACTIVATE);
			}
			else
			{
				COleClientItem* pActiveItem = NULL;
				pView = GetActiveView();

				if (pView != NULL && GetParentFrame()->GetActiveFrame() == this && m_bActivating)
				{
					ASSERT_VALID(pView);

					COleDocument* pDoc = DYNAMIC_DOWNCAST(COleDocument, pView->GetDocument());
					if (pDoc != NULL)
					{
						ASSERT_VALID(pDoc);
						pActiveItem = pDoc->GetInPlaceActiveItem(pView);

						if (bNotify && pActiveItem != NULL && pActiveItem->m_pInPlaceFrame != NULL)
						{
							pActiveItem->m_pInPlaceFrame->OnRecalcLayout();
						}
					}
					CRect rectClient;

					CFrameWnd* pFrame = pView->GetParentFrame();
					if (pFrame->GetSafeHwnd() != NULL)
					{
						pFrame->GetClientRect(rectClient);

						CWnd* pChildWnd = m_dockManager.IsPrintPreviewValid() ? GetDlgItem (AFX_IDW_PANE_SAVE) : GetDlgItem (AFX_IDW_PANE_FIRST);

						if (pChildWnd->GetSafeHwnd() != NULL && pChildWnd->IsKindOf(RUNTIME_CLASS(CSplitterWnd)))
						{
							pChildWnd->SetWindowPos(NULL, 0, 0, rectClient.Width(), rectClient.Height(), SWP_NOZORDER  | SWP_NOACTIVATE);
						}
						else
						{
							pView->SetWindowPos(NULL, 0, 0, rectClient.Width(), rectClient.Height(), SWP_NOZORDER  | SWP_NOACTIVATE);
						}
					}
				}
				else
				{
					AdjustClientArea();
				}
			}
		}
		else
		{
			m_dockManager.RecalcLayout(bNotify);
			AdjustClientArea();
		}
	}

	m_bInRecalcLayout = FALSE;
}

void CMDIChildWndEx::OnSizing(UINT fwSide, LPRECT pRect)
{
	CMDIChildWnd::OnSizing(fwSide, pRect);

	CRect rect;
	GetWindowRect(rect);

	if (rect.Size() != CRect(pRect).Size())
	{
		AdjustDockingLayout();
	}

}
void CMDIChildWndEx::UnregisterTaskbarTab(BOOL bCheckRegisteredMDIChildCount)
{
	// If in MDI Tabbed or MDI Tabbed Group, mode, and if the application
	// wants the behavior, remove the MDI child from the task bar tab list.
	if (m_tabProxyWnd.GetSafeHwnd() != NULL)
	{
		ITaskbarList3 *pTaskbarList3 = GetGlobalData()->GetITaskbarList3();
		if (pTaskbarList3)
		{
			pTaskbarList3->UnregisterTab(m_tabProxyWnd.GetSafeHwnd());
		}
		if (m_tabProxyWnd.GetSafeHwnd() != NULL)
		{
			m_tabProxyWnd.DestroyWindow();
		}

		if (bCheckRegisteredMDIChildCount)
		{
			// if no registered children - reset clip rect to full app window
			CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
			if (pTopLevel != NULL && pTopLevel->GetRegisteredWithTaskBarMDIChildCount() == 0)
			{
				ITaskbarList3* pTaskbarList3 = GetGlobalData()->GetITaskbarList3();
				if (pTaskbarList3 != NULL)
				{
					pTaskbarList3->SetThumbnailClip(pTopLevel->GetSafeHwnd(), NULL);
				}

			}
		}
	}
}
void CMDIChildWndEx::OnDestroy()
{
	UnregisterTaskbarTab();

	if (m_pMDIFrame != NULL && m_pMDIFrame->IsPrintPreview())
	{
		m_pMDIFrame->SendMessage(WM_CLOSE);
	}

	if (m_pTabbedControlBar != NULL && CWnd::FromHandlePermanent(m_pTabbedControlBar->GetSafeHwnd()) != NULL)
	{
		CWnd* pParent = m_pTabbedControlBar->GetParent();

		if (pParent == this && m_pMDIFrame != NULL && !m_pMDIFrame->m_bClosing)
		{
			// tabbed MDI is being closed. We need to reassign parent of embedded control bar
			m_pTabbedControlBar->ShowWindow(SW_HIDE);
			m_pTabbedControlBar->SetParent(m_pTabbedControlBar->GetDockSiteFrameWnd());
			m_pMDIFrame->GetDockingManager()->AddHiddenMDITabbedBar(m_pTabbedControlBar);
		}
		m_pTabbedControlBar = NULL;
	}

	CFrameImpl::RemoveFrame(this);

	POSITION pos = NULL;

	for (pos = m_dockManager.m_lstMiniFrames.GetHeadPosition(); pos != NULL;)
	{
		CPaneFrameWnd* pNextFrame = DYNAMIC_DOWNCAST(CPaneFrameWnd, m_dockManager.m_lstMiniFrames.GetNext(pos));
		if (pNextFrame != NULL)
		{
			pNextFrame->DestroyWindow();
		}
	}

	CList<HWND, HWND> lstChildren;
	CWnd* pNextWnd = GetTopWindow();
	while (pNextWnd != NULL)
	{
		lstChildren.AddTail(pNextWnd->m_hWnd);
		pNextWnd = pNextWnd->GetNextWindow();
	}

	for (pos = lstChildren.GetHeadPosition(); pos != NULL;)
	{
		HWND hwndNext = lstChildren.GetNext(pos);
		if (IsWindow(hwndNext) && ::GetParent(hwndNext) == m_hWnd)
		{
			::DestroyWindow(hwndNext);
		}
	}

	// CMDIClientAreaWnd::OnMDIDestroy will take care about removing from the tabs.
	m_pRelatedTabGroup = NULL;

	CMDIChildWnd::OnDestroy();
}

void CMDIChildWndEx::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI)
{
	if (m_pMDIFrame != NULL && m_pMDIFrame->IsFullScreen() && !m_pMDIFrame->AreMDITabs())
	{
		m_pMDIFrame->m_Impl.GetFullScreenMinMaxInfo(lpMMI);
	}
	else
	{
		CMDIChildWnd::OnGetMinMaxInfo(lpMMI);
	}
}

void CMDIChildWndEx::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	CMDIChildWnd::OnStyleChanged(nStyleType, lpStyleStruct);

	if (IsTaskbarTabsSupportEnabled())
	{
		RegisterTaskbarTab();
	}
	else
	{
		UnregisterTaskbarTab();
	}

	BOOL bWasSysMenu = (lpStyleStruct->styleOld & WS_SYSMENU);
	BOOL bIsSysMenu = (lpStyleStruct->styleNew & WS_SYSMENU);

	if (bWasSysMenu == bIsSysMenu)
	{
		return;
	}

	BOOL bIsInMDITabbedGroup = m_pMDIFrame != NULL && m_pMDIFrame->IsMDITabbedGroup();

	if (bWasSysMenu)
	{
		if ((lpStyleStruct->styleOld & WS_MAXIMIZE) == 0 && (lpStyleStruct->styleOld & WS_MINIMIZE) == 0)
		{
			CRect rectWindow;
			GetWindowRect(rectWindow);

			GetParent()->ScreenToClient(&rectWindow);
			m_rectOriginal = rectWindow;
		}

		if (m_pMDIFrame != NULL &&(m_pMDIFrame->m_wndClientArea.GetExStyle() & WS_EX_CLIENTEDGE) != 0)
		{
			m_pMDIFrame->m_wndClientArea.ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_FRAMECHANGED);
		}

		if (!bIsInMDITabbedGroup)
		{
			if (!IsZoomed() && bIsSysMenu)
			{
				if (CMFCVisualManager::GetInstance()->IsOwnerDrawCaption())
				{
					m_Impl.m_bIsWindowRgn = CMFCVisualManager::GetInstance()->OnSetWindowRegion(this, m_rectOriginal.Size());
				}
				else
				{
					m_Impl.m_bIsWindowRgn = FALSE;
					SetWindowRgn(NULL, TRUE);
				}
			}

			CRect rect;
			m_pMDIFrame->m_wndClientArea.GetClientRect(rect);


			CRect rectClient;
			GetClientRect(rectClient);
			ClientToScreen(rectClient);

			CRect rectScreen;
			GetWindowRect(rectScreen);

			rect.left -= rectClient.left - rectScreen.left;
			rect.top -= rectClient.top - rectScreen.top;
			rect.right += rectScreen.right - rectClient.right;
			rect.bottom += rectScreen.bottom - rectClient.bottom;

			if (!rect.IsRectNull())
			{
				SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
			}
		}
	}
	else if (!bIsInMDITabbedGroup)
	{
		if (m_pMDIFrame != NULL &&(m_pMDIFrame->m_wndClientArea.GetExStyle() & WS_EX_CLIENTEDGE) == 0)
		{
			m_pMDIFrame->m_wndClientArea.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
		}

		if (!IsZoomed() && bIsSysMenu)
		{
			if (CMFCVisualManager::GetInstance()->IsOwnerDrawCaption())
			{
				CRect rectWindow(m_rectOriginal);

				if (rectWindow.IsRectNull())
				{
					GetWindowRect(rectWindow);
					GetParent()->ScreenToClient(&rectWindow);
				}

				if (!rectWindow.IsRectNull())
				{
					m_Impl.m_bIsWindowRgn = CMFCVisualManager::GetInstance()->OnSetWindowRegion(this, rectWindow.Size());
				}
			}
			else
			{
				m_Impl.m_bIsWindowRgn = FALSE;
				SetWindowRgn(NULL, TRUE);
			}
		}

		if (!m_rectOriginal.IsRectNull())
		{
			SetWindowPos(NULL, m_rectOriginal.left, m_rectOriginal.top, m_rectOriginal.Width(), m_rectOriginal.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
		}
	}
}

void CMDIChildWndEx::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID == SC_KEYMENU) && m_pMDIFrame && m_pMDIFrame->AreMDITabs())
	{
		// If in tabbed MDI mode, ignore request for the menu for
		// the MDI child windows--otherwise we loop infinitely.
		return;
	}

	CMDIChildWnd::OnSysCommand(nID, lParam);
}

LRESULT CMDIChildWndEx::OnIdleUpdateCmdUI(WPARAM, LPARAM)
{
	m_dockManager.SendMessageToMiniFrames(WM_IDLEUPDATECMDUI);
	return 0L;
}

LPCTSTR CMDIChildWndEx::GetDocumentName(CObject** /*pObj*/)
{
	CDocument* pDoc = GetActiveDocument();
	if (pDoc != NULL)
	{
		return pDoc->GetPathName();
	}
	return NULL;
}

void CMDIChildWndEx::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos)
{
	if ((lpwndpos->flags & SWP_FRAMECHANGED) == SWP_FRAMECHANGED)
	{
		if (m_pMDIFrame != NULL && !m_pMDIFrame->IsMDITabbedGroup())
		{
			m_Impl.OnWindowPosChanging(lpwndpos);
		}
		else if (m_Impl.m_bIsWindowRgn)
		{
			m_Impl.m_bIsWindowRgn = FALSE;
			SetWindowRgn(NULL, TRUE);
		}
	}

	CMDIChildWnd::OnWindowPosChanged(lpwndpos);
}

void CMDIChildWndEx::OnNcPaint()
{
	BOOL bIsInMDITabbedGroup = m_pMDIFrame != NULL && m_pMDIFrame->IsMDITabbedGroup();

	if (bIsInMDITabbedGroup || IsZoomed() || !CMFCVisualManager::GetInstance()->IsOwnerDrawCaption())
	{
		Default();
		return;
	}

	if (!m_Impl.OnNcPaint())
	{
		Default();
	}
}

BOOL CMDIChildWndEx::OnNcActivate(BOOL bActive)
{
	BOOL bIsOwnerDraw = m_Impl.OnNcActivate(bActive);

	if (bIsOwnerDraw)
	{
		SetRedraw(FALSE);
	}

	BOOL bRes = CMDIChildWnd::OnNcActivate(bActive);

	if (bIsOwnerDraw)
	{
		SetRedraw(TRUE);
		RedrawWindow(NULL, NULL, RDW_FRAME | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE | RDW_ALLCHILDREN);
	}

	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL)
	{
		CDataRecoveryHandler *pHandler = pApp->GetDataRecoveryHandler();
		if ((pHandler == NULL) || (!pHandler->GetShutdownByRestartManager()))
		{
			InvalidateIconicBitmaps();
		}
	}

	return bRes;
}

void CMDIChildWndEx::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	m_Impl.OnNcMouseMove(nHitTest, point);
	CMDIChildWnd::OnNcMouseMove(nHitTest, point);
}

LRESULT CMDIChildWndEx::OnNcHitTest(CPoint point)
{
	UINT nHit = m_Impl.OnNcHitTest(point);
	if (nHit != HTNOWHERE)
	{
		return nHit;
	}

	return CMDIChildWnd::OnNcHitTest(point);
}

LRESULT CMDIChildWndEx::OnChangeVisualManager(WPARAM, LPARAM)
{
	if (m_pMDIFrame != NULL && !m_pMDIFrame->IsMDITabbedGroup())
	{
		m_Impl.OnChangeVisualManager();
	}

	return 0;
}

void CMDIChildWndEx::OnSendIconicThumbnail(WPARAM, LPARAM)
{
	CDC dcThumbnail;
	PrintClient(&dcThumbnail, PRF_CLIENT);

	HBITMAP hBitmap = (HBITMAP)(dcThumbnail.GetCurrentBitmap()->m_hObject);
	_AfxDwmSetIconicThumbnail(GetSafeHwnd(), hBitmap, DWM_SIT_DISPLAYFRAME);
}

void CMDIChildWndEx::OnSendIconicLivePreviewBitmap(WPARAM, LPARAM)
{
	CDC dcThumbnail;
	PrintClient(&dcThumbnail, PRF_CLIENT);

	CRect rectClient;
	GetClientRect(rectClient);
	CPoint ptClient;
	ptClient.x = rectClient.left;
	ptClient.y = rectClient.top;

	HBITMAP hBitmap = (HBITMAP)(dcThumbnail.GetCurrentBitmap()->m_hObject);
	_AfxDwmSetIconicLivePreviewBitmap(GetSafeHwnd(), hBitmap, &ptClient, DWM_SIT_DISPLAYFRAME);
}

BOOL CMDIChildWndEx::OnTaskbarTabThumbnailStretch(HBITMAP hBmpDst, const CRect& rectDst, HBITMAP hBmpSrc, const CRect& rectSrc)
{
	UNREFERENCED_PARAMETER(rectSrc);

	if (hBmpSrc == NULL || hBmpDst == NULL)
	{
		return FALSE;
	}

	CImage image;
	image.Attach(hBmpSrc);

	CClientDC dcClient(this);

	CDC dc;
	dc.CreateCompatibleDC(&dcClient);

	HBITMAP hOldBmp = (HBITMAP)dc.SelectObject(hBmpDst);

	BOOL bResult = image.Draw(dc.GetSafeHdc(), rectDst, Gdiplus::InterpolationModeHighQualityBicubic);

	dc.SelectObject(hOldBmp);

	return bResult;
}

void CMDIChildWndEx::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp)
{
	BOOL bIsInMDITabbedGroup = m_pMDIFrame != NULL && m_pMDIFrame->IsMDITabbedGroup();

	if (!bIsInMDITabbedGroup && !IsZoomed() && CMFCVisualManager::GetInstance()->IsOwnerDrawCaption() && (GetStyle() & WS_BORDER) == 0)
	{
		lpncsp->rgrc[0].top += ::GetSystemMetrics(SM_CYCAPTION);
	}

	CMDIChildWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

void CMDIChildWndEx::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_Impl.OnLButtonUp(point);
	CMDIChildWnd::OnLButtonUp(nFlags, point);
}

void CMDIChildWndEx::OnMouseMove(UINT nFlags, CPoint point)
{
	m_Impl.OnMouseMove(point);
	CMDIChildWnd::OnMouseMove(nFlags, point);
}

void CMDIChildWndEx::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_Impl.OnLButtonDown(point);
	CMDIChildWnd::OnLButtonDown(nFlags, point);
}

void CMDIChildWndEx::AddTabbedPane(CDockablePane* pControlBar)
{
	ASSERT_VALID(pControlBar);
	m_pTabbedControlBar = pControlBar;

	m_pTabbedControlBar->OnBeforeChangeParent(this);
	m_pTabbedControlBar->EnableGripper(FALSE);
	m_pTabbedControlBar->SetParent(this);
	m_pTabbedControlBar->ShowWindow(SW_SHOW);
	m_pTabbedControlBar->SetMDITabbed(TRUE);

	m_pMDIFrame->GetDockingManager()->RemoveHiddenMDITabbedBar(m_pTabbedControlBar);

	AdjustClientArea();
}

BOOL CMDIChildWndEx::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

void CMDIChildWndEx::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	if (m_pTabbedControlBar != NULL && nHitTest == HTCAPTION && !IsZoomed())	
	{
		ASSERT_VALID(m_pTabbedControlBar);
		m_pTabbedControlBar->OnShowControlBarMenu(point);
		return;
	}

	CMDIChildWnd::OnNcRButtonUp(nHitTest, point);
}

CWnd* CMDIChildWndEx::GetTaskbarPreviewWnd()
{
	ASSERT_VALID(this);
	CWnd* pWnd = GetDescendantWindow(AFX_IDW_PANE_FIRST);

	if (pWnd->GetSafeHwnd() != NULL)
	{
		ASSERT_VALID(pWnd);

		CWnd* pParent = pWnd->GetParent();

		if (pParent != this && pParent->GetSafeHwnd() != NULL && pParent->IsKindOf(RUNTIME_CLASS(CSplitterWnd)))
		{
			pWnd = pParent;
		}
	}
	else
	{
		pWnd = GetWindow(GW_CHILD);
	}

	return pWnd;
}

void CMDIChildWndEx::OnTaskbarTabThumbnailActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	UNREFERENCED_PARAMETER(pWndOther);
	UNREFERENCED_PARAMETER(bMinimized);

	if (nState == WA_ACTIVE)
	{
		ActivateTopLevelFrame();
	}
}

int CMDIChildWndEx::OnTaskbarTabThumbnailMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	UNREFERENCED_PARAMETER(pDesktopWnd);
	UNREFERENCED_PARAMETER(nHitTest);

	CMDIFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
	ASSERT_VALID(pTopLevelFrame);

	if (message == WM_LBUTTONUP)
	{
		ActivateTopLevelFrame();
	}
	return 1;
}

void CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton()
{
	CMDIFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
	ASSERT_VALID(pTopLevelFrame);

	if (pTopLevelFrame == NULL || !pTopLevelFrame->IsWindowEnabled())
	{
		return;
	}

	CDocument* pDoc = GetActiveDocument();
	if (pDoc != NULL && pDoc->IsModified())
	{
		ActivateTopLevelFrame();
	}

	PostMessage(WM_CLOSE);
}

void CMDIChildWndEx::EnableTaskbarThumbnailClipRect(BOOL bEnable)
{
	m_bEnableTaskbarThumbnailClip = bEnable;

	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rect(0, 0, 0, 0); 
	if (bEnable) 
	{
		rect = GetTaskbarThumbnailClipRect();
	}

	SetTaskbarThumbnailClipRect(rect);	
}

CRect CMDIChildWndEx::GetTaskbarThumbnailClipRect() const
{
	ASSERT_VALID(this);

	CRect rect(0, 0, 0, 0);
	GetWindowRect(rect);
	
	return rect;
}

BOOL CMDIChildWndEx::SetTaskbarThumbnailClipRect(CRect rect)
{
	if (!GetGlobalData()->bIsWindows7)
	{
		return FALSE;
	}
	
	CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
	if (pTopLevel == NULL || pTopLevel->MDIGetActive() != this)
	{
		return FALSE;
	}

	if (!rect.IsRectNull())
	{
		pTopLevel->ScreenToClient(rect);
	}
	
	ITaskbarList3* pTaskbarList3 = GetGlobalData()->GetITaskbarList3();
	if (pTaskbarList3 == NULL)
	{
		TRACE0("Warning: ITaskbarList3 is NULL.");
		return FALSE;
	}

	HRESULT hr = pTaskbarList3->SetThumbnailClip(pTopLevel->GetSafeHwnd(), rect.IsRectNull() || rect.IsRectEmpty() ? NULL : &rect);

	if (!SUCCEEDED(hr))
	{
		TRACE1("SetTaskbarThumbnailClipRect failed with code %x.", hr);
		return FALSE;
	}

	return TRUE;
}

void CMDIChildWndEx::ActivateTopLevelFrame()
{
	CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());
	if (pTopLevel == NULL)
	{
		return;
	}

	ActivateFrame();
	pTopLevel->SetForegroundWindow();

	BOOL bIsMinimized = pTopLevel->IsIconic();

	pTopLevel->ShowWindow(bIsMinimized ? SW_RESTORE : SW_SHOW);
	pTopLevel->PostMessage(AFX_WM_AFTER_TASKBAR_ACTIVATE, (WPARAM)bIsMinimized, (LPARAM)GetSafeHwnd());

	if (pTopLevel->IsIconic())
	{
		pTopLevel->ShowWindow(SW_RESTORE);
	}
	else
	{
		pTopLevel->ShowWindow(SW_SHOW);
	}
}

BOOL CMDIChildWndEx::IsTabbedMDIChild()
{
	return m_pMDIFrame != NULL && m_pMDIFrame->AreMDITabs();
}

BOOL CMDIChildWndEx::CanShowOnMDITabs() 
{ 
	if ((GetStyle() & WS_VISIBLE) != 0)
	{
		// Window is visible: show it on the MDI tabs
		return TRUE;
	}

	// Window is hidden.
	COleServerDoc* pDoc = DYNAMIC_DOWNCAST(COleServerDoc, GetActiveDocument());
	if (pDoc != NULL)
	{
		ASSERT_VALID(pDoc);
		if (pDoc->IsEmbedded())
		{
			// Embedded server documents should be always added to the MDI tabs:
			return TRUE;
		}
	}

	return FALSE;
}

//////////////////////////////////////////////////
/// CMDITabProxyWnd

IMPLEMENT_DYNCREATE(CMDITabProxyWnd, CWnd)

BEGIN_MESSAGE_MAP(CMDITabProxyWnd, CWnd)
	ON_WM_DWMSENDICONICTHUMBNAIL()
	ON_WM_DWMSENDICONICLIVEPREVIEWBITMAP()
	ON_WM_ACTIVATE()
	ON_WM_MOUSEACTIVATE()
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

CMDITabProxyWnd::CMDITabProxyWnd() : m_pRelatedMDIChildFrame(NULL)
{
}

CMDITabProxyWnd::~CMDITabProxyWnd()
{
}

void CMDITabProxyWnd::SetRelatedMDIChildFrame(CMDIChildWndEx* pRelatedMDIFrame)
{
	ASSERT_KINDOF(CMDIChildWndEx, pRelatedMDIFrame);
	m_pRelatedMDIChildFrame = pRelatedMDIFrame;
}

BOOL CMDITabProxyWnd::IsMDIChildActive()
{
	ASSERT_VALID(m_pRelatedMDIChildFrame);

	CMDIFrameWndEx* pTopLevel = DYNAMIC_DOWNCAST(CMDIFrameWndEx, m_pRelatedMDIChildFrame->GetTopLevelFrame());
	ASSERT_VALID(pTopLevel);

	if (pTopLevel->IsIconic())
	{
		return FALSE;
	}

	return pTopLevel->MDIGetActive() == m_pRelatedMDIChildFrame;
}

static double CorrectZoomSize(const CSize& sizeSrc, CSize& sizeDst)
{
	double Zoom = min((double)sizeDst.cx / (double)sizeSrc.cx, (double)sizeDst.cy / (double)sizeSrc.cy);

	sizeDst.cx = (long)(sizeSrc.cx * Zoom);
	sizeDst.cy = (long)(sizeSrc.cy * Zoom);

	return Zoom;
}

HBITMAP CMDITabProxyWnd::GetClientBitmap (int nWidth, int nHeight, BOOL bIsThumbnail)
{
	if (m_pRelatedMDIChildFrame == NULL || nWidth <= 0 || nHeight <= 0)
	{
		return NULL;
	}

	CRect rectWnd;
	CWnd* pPreviewWnd = m_pRelatedMDIChildFrame->GetTaskbarPreviewWnd();

	ASSERT_VALID(pPreviewWnd);
	pPreviewWnd->GetWindowRect(rectWnd);

	rectWnd.OffsetRect(-rectWnd.left, -rectWnd.top);

	if (rectWnd.Width() <= 0 || rectWnd.Height() <= 0)
	{
		return NULL;
	}

	CImage bmpSrc;
	bmpSrc.CreateEx(rectWnd.Width(), rectWnd.Height(), 32, BI_RGB, NULL, CImage::createAlphaChannel);

	CClientDC dcPreview(pPreviewWnd);

	CDC dcThumbnail;
	dcThumbnail.CreateCompatibleDC(&dcPreview);
	HBITMAP pOldSrc = (HBITMAP)dcThumbnail.SelectObject(HBITMAP(bmpSrc));
	BOOL bAlphaChannelSet = FALSE;

	pPreviewWnd->OnDrawIconicThumbnailOrLivePreview(dcThumbnail, rectWnd, CSize (nWidth, nHeight), bIsThumbnail, bAlphaChannelSet);
	dcThumbnail.SelectObject(pOldSrc);

	if (!bAlphaChannelSet)
	{
		LPBYTE pBits = (LPBYTE)bmpSrc.GetBits();
		if (bmpSrc.GetPitch() < 0)
		{
			pBits = pBits + ((bmpSrc.GetHeight() - 1) * bmpSrc.GetPitch());
		}
		for (int i = 0; i < rectWnd.Width() * rectWnd.Height(); i++)
		{
			pBits[3] = 255;
			pBits += 4;
		}
	}

	CSize szDst(nWidth, nHeight);
	CorrectZoomSize(rectWnd.Size(), szDst);
	CRect rectDst (CPoint(0, 0), szDst);

	CImage bmpDst;
	bmpDst.CreateEx(szDst.cx, -szDst.cy, 32, BI_RGB, NULL, CImage::createAlphaChannel);

	{
		BOOL bHandled = FALSE;
		if (bIsThumbnail)
		{
			bHandled = m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailStretch(HBITMAP(bmpDst), rectDst, HBITMAP(bmpSrc), rectWnd);
		}
		
		if (!bHandled)
		{
			CDC dc;
			dc.CreateCompatibleDC(&dcPreview);
			HBITMAP pOldDstBitmap = (HBITMAP)dc.SelectObject(HBITMAP(bmpDst));

			bmpSrc.AlphaBlend(dc.GetSafeHdc(), rectDst, rectWnd);
			dc.SelectObject(pOldDstBitmap);
		}
	}

	return bmpDst.Detach();
}

BOOL CMDITabProxyWnd::OnSendIconicThumbnail(int cx, int cy)
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return (BOOL)Default();
	}

	HBITMAP hBitmap = m_pRelatedMDIChildFrame->OnGetIconicThumbnail(cx, cy); 
	if (hBitmap == NULL)
	{
		hBitmap = GetClientBitmap(cx, cy, TRUE);
	}
			
	_AfxDwmSetIconicThumbnail(GetSafeHwnd(), hBitmap, 0);

	DeleteObject(hBitmap);

	return (BOOL)Default();
}

BOOL CMDITabProxyWnd::OnSendIconicLivePreviewBitmap()
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return TRUE;
	}

	ASSERT_VALID(m_pRelatedMDIChildFrame);

	BOOL bActive = IsMDIChildActive();
	CPoint ptClient(0,0);
	HBITMAP hBitmap = m_pRelatedMDIChildFrame->OnGetIconicLivePreviewBitmap(bActive, ptClient);

	if (hBitmap == NULL)
	{
		CMDIFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, m_pRelatedMDIChildFrame->GetTopLevelFrame());
		ASSERT_VALID(pTopLevelFrame);

		CRect rectWnd;
		
		CWnd* pPrintWnd = m_pRelatedMDIChildFrame->GetTaskbarPreviewWnd();
		pPrintWnd->GetWindowRect(rectWnd);
		pTopLevelFrame->ScreenToClient(rectWnd);

		ptClient.x = rectWnd.left;
		ptClient.y = rectWnd.top;

		hBitmap = GetClientBitmap(rectWnd.Width(), rectWnd.Height(), FALSE);
	}

	_AfxDwmSetIconicLivePreviewBitmap(GetSafeHwnd(), hBitmap, &ptClient, 0);
	DeleteObject(hBitmap);
	return FALSE;
}

void CMDITabProxyWnd::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return;
	}

	ASSERT_VALID(m_pRelatedMDIChildFrame);

	CMDIFrameWndEx* pTopLevelFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, m_pRelatedMDIChildFrame->GetTopLevelFrame());
	ASSERT_VALID(pTopLevelFrame);

	if (nID != SC_CLOSE)
	{
		if (nID != SC_MINIMIZE)
		{
			m_pRelatedMDIChildFrame->ActivateTopLevelFrame();
		}

		pTopLevelFrame->SendMessage(WM_SYSCOMMAND, nID, lParam);	
		return;
	}

	Default();
}

void CMDITabProxyWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return;
	}

	m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailActivate(nState, pWndOther, bMinimized);
}

int CMDITabProxyWnd::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return 0;
	}

	return m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailMouseActivate(pDesktopWnd, nHitTest, message);
}

void CMDITabProxyWnd::OnClose()
{
	if (m_pRelatedMDIChildFrame == NULL)
	{
		return;
	}

	m_pRelatedMDIChildFrame->OnPressTaskbarThmbnailCloseButton();
}
