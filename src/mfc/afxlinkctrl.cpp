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
#include "afxlinkctrl.h"
#include "afxglobals.h"
#include "afxribbonres.h"
#include "afxtagmanager.h"
#include "afxctrlcontainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CMFCLinkCtrl, CMFCButton)

/////////////////////////////////////////////////////////////////////////////
// CMFCLinkCtrl

CMFCLinkCtrl::CMFCLinkCtrl()
{
	m_nFlatStyle = BUTTONSTYLE_NOBORDERS;
	m_sizePushOffset = CSize(0, 0);
	m_bTransparent = TRUE;

	m_bMultilineText = FALSE;
	m_bAlwaysUnderlineText = TRUE;
	m_bDefaultClickProcess = FALSE;
	m_bVisited = FALSE;

	SetMouseCursorHand();
}

CMFCLinkCtrl::~CMFCLinkCtrl()
{
}

BEGIN_MESSAGE_MAP(CMFCLinkCtrl, CMFCButton)
	ON_CONTROL_REFLECT_EX(BN_CLICKED, &CMFCLinkCtrl::OnClicked)
	ON_MESSAGE(WM_MFC_INITCTRL, &CMFCLinkCtrl::OnInitControl)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCLinkCtrl message handlers

void CMFCLinkCtrl::OnDraw(CDC* pDC, const CRect& rect, UINT /*uiState*/)
{
	ASSERT_VALID(pDC);

	// Set font:
	CFont* pOldFont = NULL;

	if (m_bAlwaysUnderlineText || m_bHover)
	{
		pOldFont = pDC->SelectObject(&(GetGlobalData()->fontDefaultGUIUnderline));
	}
	else
	{
		pOldFont = CMFCButton::SelectFont(pDC);
	}

	ENSURE(pOldFont != NULL);

	// Set text parameters:
	pDC->SetTextColor(m_bHover ? GetGlobalData()->clrHotLinkHoveredText : (m_bVisited ? GetGlobalData()->clrHotLinkVisitedText : GetGlobalData()->clrHotLinkNormalText));
	pDC->SetBkMode(TRANSPARENT);

	// Obtain label:
	CString strLabel;
	GetWindowText(strLabel);

	CRect rectText = rect;
	pDC->DrawText(strLabel, rectText, m_bMultilineText ? DT_WORDBREAK : DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
}

BOOL CMFCLinkCtrl::OnClicked()
{
	ASSERT_VALID(this);

	if (!IsWindowEnabled())
	{
		return TRUE;
	}

	if (m_bDefaultClickProcess)
	{
		m_bHover = FALSE;
		Invalidate();
		UpdateWindow();

		return FALSE;
	}

	CWaitCursor wait;

	CString strURL = m_strURL;
	if (strURL.IsEmpty())
	{
		GetWindowText(strURL);
	}

	if (::ShellExecute(NULL, NULL, m_strPrefix + strURL, NULL, NULL, SW_SHOWNORMAL) <(HINSTANCE) 32)
	{
		TRACE(_T("Can't open URL: %Ts\n"), strURL.GetString());
	}

	m_bVisited = TRUE;
	m_bHover = FALSE;
	Invalidate();
	UpdateWindow();

	return TRUE;
}

void CMFCLinkCtrl::SetURL(LPCTSTR lpszURL)
{
	if (lpszURL == NULL)
	{
		m_strURL.Empty();
	}
	else
	{
		m_strURL = lpszURL;
	}
}

void CMFCLinkCtrl::SetURLPrefix(LPCTSTR lpszPrefix)
{
	ENSURE(lpszPrefix != NULL);
	m_strPrefix = lpszPrefix;
}

CSize CMFCLinkCtrl::SizeToContent(BOOL bVCenter, BOOL bHCenter)
{
	if (m_sizeImage != CSize(0, 0))
	{
		return CMFCButton::SizeToContent();
	}

	ASSERT_VALID(this);
	ENSURE(GetSafeHwnd() != NULL);

	CClientDC dc(this);

	// Set font:
	CFont* pOldFont = dc.SelectObject(&(GetGlobalData()->fontDefaultGUIUnderline));
	ENSURE(pOldFont != NULL);

	// Obtain label:
	CString strLabel;
	GetWindowText(strLabel);

	CRect rectClient;
	GetClientRect(rectClient);

	CRect rectText = rectClient;
	dc.DrawText(strLabel, rectText, DT_SINGLELINE | DT_CALCRECT);
	rectText.InflateRect(3, 3);

	if (bVCenter || bHCenter)
	{
		ASSERT(GetParent()->GetSafeHwnd() != NULL);
		MapWindowPoints(GetParent(), rectClient);

		int dx = bHCenter ?(rectClient.Width() - rectText.Width()) / 2 : 0;
		int dy = bVCenter ?(rectClient.Height() - rectText.Height()) / 2 : 0;

		SetWindowPos(NULL, rectClient.left + dx, rectClient.top + dy, rectText.Width(), rectText.Height(), SWP_NOZORDER | SWP_NOACTIVATE);
	}
	else
	{
		SetWindowPos(NULL, -1, -1, rectText.Width(), rectText.Height(), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}

	dc.SelectObject(pOldFont);
	return rectText.Size();
}

void CMFCLinkCtrl::OnDrawFocusRect(CDC* pDC, const CRect& rectClient)
{
	ASSERT_VALID(pDC);

	CRect rectFocus = rectClient;
	pDC->DrawFocusRect(rectFocus);
}

BOOL CMFCLinkCtrl::PreTranslateMessage(MSG* pMsg)
{
	switch(pMsg->message)
	{
	case WM_KEYDOWN:
		if (pMsg->wParam == VK_SPACE || pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
		break;

	case WM_KEYUP:
		if (pMsg->wParam == VK_SPACE)
		{
			return TRUE;
		}
		else if (pMsg->wParam == VK_RETURN)
		{
			OnClicked();
			return TRUE;
		}
		break;
	}

	return CMFCButton::PreTranslateMessage(pMsg);
}

LRESULT CMFCLinkCtrl::OnInitControl(WPARAM wParam, LPARAM lParam)
{
	DWORD dwSize = (DWORD)wParam;
	BYTE* pbInitData = (BYTE*)lParam;

	CString strDst;
	CMFCControlContainer::UTF8ToString((LPSTR)pbInitData, strDst, dwSize);

	CTagManager tagManager(strDst);

	CString strUrl;
	if (tagManager.ExcludeTag(PS_MFCLink_Url, strUrl))
	{
		SetURL(strUrl);
	}

	CString strUrlPrefix;
	if (tagManager.ExcludeTag(PS_MFCLink_UrlPrefix, strUrlPrefix))
	{
		SetURLPrefix(strUrlPrefix);
	}

	CString strFullTextTooltip;
	if (tagManager.ExcludeTag(PS_MFCLink_FullTextTooltip, strFullTextTooltip))
	{
		if (!strFullTextTooltip.IsEmpty())
		{
			strFullTextTooltip.MakeUpper();
			EnableFullTextTooltip(strFullTextTooltip == PS_True);
		}
	}

	CString strTooltip;
	if (tagManager.ExcludeTag(PS_MFCLink_Tooltip, strTooltip))
	{
		SetTooltip(strTooltip);
	}

	return 0;
}
