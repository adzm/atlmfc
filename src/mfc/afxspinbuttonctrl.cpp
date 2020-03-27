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
#include "afxvisualmanager.h"
#include "afxglobals.h"
#include "afxspinbuttonctrl.h"
#include "afxtoolbarimages.h"
#include "afxdrawmanager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCSpinButtonCtrl

CMFCSpinButtonCtrl::CMFCSpinButtonCtrl()
{
	m_bTracked = FALSE;

	m_bIsButtonPressedUp = FALSE;
	m_bIsButtonPressedDown = FALSE;

	m_bIsButtonHighlightedUp = FALSE;
	m_bIsButtonHighlightedDown = FALSE;
}

CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl()
{
}

BEGIN_MESSAGE_MAP(CMFCSpinButtonCtrl, CSpinButtonCtrl)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CANCELMODE()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCSpinButtonCtrl message handlers

void CMFCSpinButtonCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CMemDC memDC(dc, this);

	OnDraw(&memDC.GetDC());
}

void CMFCSpinButtonCtrl::OnDraw(CDC* pDC)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	CRect rectClient;
	GetClientRect(rectClient);

	if (CMFCToolBarImages::m_bIsDrawOnGlass)
	{
		CDrawingManager dm(*pDC);
		dm.DrawRect(rectClient, GetGlobalData()->clrWindow, (COLORREF)-1);
	}
	else
	{
		pDC->FillRect(rectClient, &(GetGlobalData()->brWindow));
	}

	int nState = 0;

	if (m_bIsButtonPressedUp)
	{
		nState |= AFX_SPIN_PRESSEDUP;
	}

	if (m_bIsButtonPressedDown)
	{
		nState |= AFX_SPIN_PRESSEDDOWN;
	}

	if (m_bIsButtonHighlightedUp)
	{
		nState |= AFX_SPIN_HIGHLIGHTEDUP;
	}

	if (m_bIsButtonHighlightedDown)
	{
		nState |= AFX_SPIN_HIGHLIGHTEDDOWN;
	}

	if (!IsWindowEnabled())
	{
		nState |= AFX_SPIN_DISABLED;
	}

	CMFCVisualManager::GetInstance()->OnDrawSpinButtons(pDC, rectClient, nState, FALSE, this);
}

void CMFCSpinButtonCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect rect;
	GetClientRect(rect);

	CRect rectUp = rect;
	rectUp.bottom = rect.CenterPoint().y;

	CRect rectDown = rect;
	rectDown.top = rectUp.bottom;

	m_bIsButtonPressedUp = rectUp.PtInRect(point);
	m_bIsButtonPressedDown = rectDown.PtInRect(point);

	CSpinButtonCtrl::OnLButtonDown(nFlags, point);
}

void CMFCSpinButtonCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bIsButtonPressedUp = FALSE;
	m_bIsButtonPressedDown = FALSE;

	m_bIsButtonHighlightedUp = FALSE;
	m_bIsButtonHighlightedDown = FALSE;

	CSpinButtonCtrl::OnLButtonUp(nFlags, point);
}

void CMFCSpinButtonCtrl::OnCancelMode()
{
	CSpinButtonCtrl::OnCancelMode();

	m_bIsButtonPressedUp = FALSE;
	m_bIsButtonPressedDown = FALSE;

	m_bIsButtonHighlightedUp = FALSE;
	m_bIsButtonHighlightedDown = FALSE;
}

void CMFCSpinButtonCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	BOOL bIsButtonHighlightedUp = m_bIsButtonHighlightedUp;
	BOOL bIsButtonHighlightedDown = m_bIsButtonHighlightedDown;

	CRect rect;
	GetClientRect(rect);

	CRect rectUp = rect;
	rectUp.bottom = rect.CenterPoint().y;

	CRect rectDown = rect;
	rectDown.top = rectUp.bottom;

	m_bIsButtonHighlightedUp = rectUp.PtInRect(point);
	m_bIsButtonHighlightedDown = rectDown.PtInRect(point);

	if (nFlags & MK_LBUTTON)
	{
		m_bIsButtonPressedUp = m_bIsButtonHighlightedUp;
		m_bIsButtonPressedDown = m_bIsButtonHighlightedDown;
	}

	CSpinButtonCtrl::OnMouseMove(nFlags, point);

	if (bIsButtonHighlightedUp != m_bIsButtonHighlightedUp || bIsButtonHighlightedDown != m_bIsButtonHighlightedDown)
	{
		RedrawWindow();
	}

	if (!m_bTracked)
	{
		m_bTracked = TRUE;

		TRACKMOUSEEVENT trackmouseevent;
		trackmouseevent.cbSize = sizeof(trackmouseevent);
		trackmouseevent.dwFlags = TME_LEAVE;
		trackmouseevent.hwndTrack = GetSafeHwnd();
		TrackMouseEvent(&trackmouseevent);
	}
}

void CMFCSpinButtonCtrl::OnMouseLeave()
{
	m_bTracked = FALSE;

	if (m_bIsButtonPressedUp || m_bIsButtonPressedDown || m_bIsButtonHighlightedUp || m_bIsButtonHighlightedDown)
	{
		m_bIsButtonHighlightedUp = FALSE;
		m_bIsButtonHighlightedDown = FALSE;

		RedrawWindow();
	}
}

BOOL CMFCSpinButtonCtrl::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}


