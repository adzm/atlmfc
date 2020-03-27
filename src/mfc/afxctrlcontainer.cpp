// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// CWnd support for MFC Control containment (Feature Pack controls)
//

#include "stdafx.h"
#include "afxctrlcontainer.h"
#include "afxtagmanager.h"
#include "afxbutton.h"
#include "afxcolorbutton.h"
#include "afxeditbrowsectrl.h"
#include "afxfontcombobox.h"
#include "afxlinkctrl.h"
#include "afxmaskededit.h"
#include "afxmenubutton.h"
#include "afxpropertygridctrl.h"
#include "afxshelllistctrl.h"
#include "afxshelltreectrl.h"
#include "afxvslistbox.h"

////////////////////////////////////////////////////////////////////////////

void AfxDoRegisterMFCControlClass(LPCTSTR lpszClassName, LPCTSTR lpszBaseClassName)
{
	ASSERT(lpszClassName != NULL);
	ASSERT(lpszBaseClassName != NULL);

	WNDCLASS wnd = {0};

	HINSTANCE hInst = AfxGetInstanceHandle();
	if (!GetClassInfo(hInst, lpszBaseClassName, &wnd))
	{
		wnd.style = CS_DBLCLKS;
		wnd.hInstance = hInst;
		wnd.lpfnWndProc = ::DefWindowProc;
	}

	wnd.lpszClassName = lpszClassName;
	AfxRegisterClass(&wnd);
}

////////////////////////////////////////////////////////////////////////////
// CMFCControlContainer

CMFCControlContainer::CMFCControlContainer(CWnd* pWnd) : m_pWnd(pWnd)
{
}

CMFCControlContainer::~CMFCControlContainer()
{
	FreeSubclassedControls();
	ClearControlData();
}

void CMFCControlContainer::FreeSubclassedControls()
{
	// Free subclassed controls: 
	for (int i = 0; i < m_arSubclassedCtrls.GetCount(); i++)
	{
		if (m_arSubclassedCtrls [i] != NULL)
		{
			delete m_arSubclassedCtrls [i];
		}
	}
	m_arSubclassedCtrls.RemoveAll();
}

CWnd* CMFCControlContainer::CreateDlgControl(LPCTSTR lpszClassName)
{
	ASSERT(m_pWnd->GetSafeHwnd() != NULL);

	if (lpszClassName != NULL)
	{
		CString strClass = lpszClassName;
		CWnd* pWndSubclassedCtrl = NULL;

		if (strClass == _T("MFCButton"))
		{
			pWndSubclassedCtrl = new CMFCButton;
		}
		else if (strClass == _T("MFCColorButton"))
		{
			pWndSubclassedCtrl = new CMFCColorButton;
		}
		else if (strClass == _T("MFCEditBrowse"))
		{
			pWndSubclassedCtrl = new CMFCEditBrowseCtrl;
		}
		else if (strClass == _T("MFCFontComboBox"))
		{
			pWndSubclassedCtrl = new CMFCFontComboBox;
		}
		else if (strClass == _T("MFCLink"))
		{
			pWndSubclassedCtrl = new CMFCLinkCtrl;
		}
		else if (strClass == _T("MFCMaskedEdit"))
		{
			pWndSubclassedCtrl = new CMFCMaskedEdit;
		}
		else if (strClass == _T("MFCMenuButton"))
		{
			pWndSubclassedCtrl = new CMFCMenuButton;
		}
		else if (strClass == _T("MFCPropertyGrid"))
		{
			pWndSubclassedCtrl = new CMFCPropertyGridCtrl;
		}
		else if (strClass == _T("MFCShellList"))
		{
			pWndSubclassedCtrl = new CMFCShellListCtrl;
		}
		else if (strClass == _T("MFCShellTree"))
		{
			pWndSubclassedCtrl = new CMFCShellTreeCtrl;
		}
		else if (strClass == _T("MFCVSListBox"))
		{
			pWndSubclassedCtrl = new CVSListBox;
		}

		return pWndSubclassedCtrl;
	}

	return NULL;
}

BOOL CMFCControlContainer::IsSubclassedFeaturePackControl(HWND hWndCtrl)
{
	if (hWndCtrl == NULL)
	{
		return FALSE;
	}

	for (int i = 0; i < m_arSubclassedCtrls.GetCount(); i++)
	{
		CWnd* pWnd = (CWnd*)m_arSubclassedCtrls[i];
		if (pWnd->GetSafeHwnd() == hWndCtrl)
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CMFCControlContainer::ReSubclassControl(HWND hWndCtrl, WORD nIDC, CWnd& control)
{
	if (hWndCtrl == NULL)
	{
		return FALSE;
	}

	int nIndex = -1;
	for (int i = 0; i < m_arSubclassedCtrls.GetCount(); i++)
	{
		CWnd* pWnd = (CWnd*)m_arSubclassedCtrls [i];
		if (pWnd->GetSafeHwnd() == hWndCtrl)
		{
			nIndex = i;
			break;
		}
	}

	if (nIndex != -1)
	{
		CWnd* pWnd = DYNAMIC_DOWNCAST(CWnd, m_arSubclassedCtrls [nIndex]);
		
		if (pWnd->GetSafeHwnd() != NULL)
		{
			ASSERT_VALID(pWnd);

			// get init state
			DWORD dwSize = 0;
			BYTE* pbInitData = NULL;
			GetControlData(nIDC, dwSize, pbInitData);

			// Free old subclassed control:
			m_arSubclassedCtrls [nIndex] = NULL;

			// unsubclass
			PreUnsubclassControl(pWnd);
			VERIFY(pWnd->UnsubclassWindow() == hWndCtrl);
			// destroy
			delete pWnd;

			// subclass
			if (!control.SubclassWindow(hWndCtrl))
			{
				ASSERT(FALSE);      // possibly trying to subclass twice?
				AfxThrowNotSupportedException();
			}

			// set init state
			if (dwSize > 0)
			{
				control.SendMessage(WM_MFC_INITCTRL, (WPARAM)dwSize, (LPARAM)pbInitData);
			}

			return TRUE;
		}
	}

	return FALSE;
}

void CMFCControlContainer::SetControlData(WORD nIDC, DWORD dwSize, BYTE* pbData)
{
	CByteArray* pArray = new CByteArray;
	pArray->SetSize(dwSize);

	BYTE* pbBuffer = pArray->GetData();
	if (memcpy_s(pbBuffer, dwSize, pbData, dwSize) != 0)
	{
		delete pArray;
		ASSERT(FALSE);
		return;
	}

	m_mapControlData.SetAt(nIDC, pArray);
}

BOOL CMFCControlContainer::GetControlData(WORD nIDC, DWORD& dwSize, BYTE*& pbData)
{
	CObject* pData = NULL;
	if (m_mapControlData.Lookup(nIDC, pData) && pData != NULL)
	{
		CByteArray* pArray = (CByteArray*)pData;
		dwSize = (DWORD)pArray->GetSize();
		pbData = pArray->GetData();
		return TRUE;
	}

	return FALSE;
}

void CMFCControlContainer::ClearControlData()
{
	WORD nIDC;
	CObject* pData = NULL;
	POSITION pos = m_mapControlData.GetStartPosition();
	while (pos != NULL)
	{
		m_mapControlData.GetNextAssoc(pos, nIDC, pData); 
		CByteArray* pArray = (CByteArray*)pData; 
		delete pArray;
	}

	m_mapControlData.RemoveAll();
}
