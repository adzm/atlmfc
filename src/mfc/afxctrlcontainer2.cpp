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

// This module is compiled two different ways:
// 1) It is compiled without _AFX_NO_MFC_CONTROLS_IN_DIALOGS #defined as part of the normal
//    MFC static libraries [N|U]AFXCW[D].LIB.  This way enables MFC controls in dialogs.
// 2) It is compiled with _AFX_NO_MFC_CONTROLS_IN_DIALOGS #defined as part of the smaller MFC
//    static libraries AFXNMCD[D].LIB, and it is one of the two modules included those libraries.
//    This way disables MFC controls in dialogs.  Use of these libraries is controlled by the
//    definition of _AFX_NO_MFC_CONTROLS_IN_DIALOGS in the application stdafx.h file.

#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
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

extern void AfxDoRegisterMFCControlClass(LPCTSTR lpszClassName, LPCTSTR lpszBaseClassName);
#endif

// The following symbol is used to force inclusion of this module from AFXNMCD[D].LIB when
// _AFX_NO_MFC_CONTROLS_IN_DIALOGS is defined in the application stdafx.h file.  This ensures
// that the control container support is not linked into the application.
#if !defined(_AFXDLL) && defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
#ifdef _X86_
extern "C" { int _afxNoMFCControlContainerInDialogs = 0; }
#else
extern "C" { int __afxNoMFCControlContainerInDialogs = 0; }
#endif
#endif

////////////////////////////////////////////////////////////////////////////

BOOL CMFCControlContainer::SubclassDlgControls()
{
#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	if (m_pWnd->GetSafeHwnd() != NULL)
	{
		// Subclass Feature Pack controls:
		CWnd* pWndChild = m_pWnd->GetWindow(GW_CHILD);
		while (pWndChild != NULL)
		{
			ASSERT_VALID(pWndChild);

			TCHAR lpszClassName [MAX_CLASS_NAME + 1];

			::GetClassName(pWndChild->GetSafeHwnd(), lpszClassName, MAX_CLASS_NAME);
			CWnd* pWndSubclassedCtrl = CreateDlgControl(lpszClassName);

			if (pWndSubclassedCtrl != NULL)
			{
				m_arSubclassedCtrls.Add((CObject*)pWndSubclassedCtrl);
				pWndSubclassedCtrl->SubclassWindow(pWndChild->GetSafeHwnd());
			}

			pWndChild = pWndChild->GetNextWindow();
		}

		return TRUE;
	}
#endif

	return FALSE;
}

void CMFCControlContainer::PreUnsubclassControl(CWnd* pControl)
{
#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	CMFCShellListCtrl* pListCtrl = DYNAMIC_DOWNCAST(CMFCShellListCtrl, pControl);
	if (pListCtrl != NULL && pListCtrl->GetHeaderCtrl().GetSafeHwnd() != NULL)
	{
		pListCtrl->GetHeaderCtrl().UnsubclassWindow();
	}
#else
	UNREFERENCED_PARAMETER(pControl);
#endif
}

////////////////////////////////////////////////////////////////////////////

void AfxRegisterMFCCtrlClasses()
{
#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	AfxDoRegisterMFCControlClass(_T("MFCButton"), WC_BUTTON);
	AfxDoRegisterMFCControlClass(_T("MFCColorButton"), WC_BUTTON);
	AfxDoRegisterMFCControlClass(_T("MFCEditBrowse"), WC_EDIT);
	AfxDoRegisterMFCControlClass(_T("MFCFontComboBox"), WC_COMBOBOX);
	AfxDoRegisterMFCControlClass(_T("MFCLink"), WC_BUTTON);
	AfxDoRegisterMFCControlClass(_T("MFCMaskedEdit"), WC_EDIT);
	AfxDoRegisterMFCControlClass(_T("MFCMenuButton"), WC_BUTTON);
	AfxDoRegisterMFCControlClass(_T("MFCPropertyGrid"), WC_STATIC);
	AfxDoRegisterMFCControlClass(_T("MFCShellList"), WC_LISTVIEW);
	AfxDoRegisterMFCControlClass(_T("MFCShellTree"), WC_TREEVIEW);
	AfxDoRegisterMFCControlClass(_T("MFCVSListBox"), WC_STATIC);
#endif
}

////////////////////////////////////////////////////////////////////////////

int __stdcall CMFCControlContainer::UTF8ToString(LPCSTR lpSrc, CString& strDst, int nLength)
{
	LPTSTR lpDst = NULL;
	int count = ::MultiByteToWideChar(CP_UTF8, 0, lpSrc, nLength, NULL, 0);
	if (count <= 0)
	{
		return 0;
	}

	LPWSTR lpWide = new WCHAR[count + 1];
	memset(lpWide, 0, (count + 1) * sizeof(WCHAR));

	::MultiByteToWideChar(CP_UTF8, 0, lpSrc, nLength, lpWide, count);

#ifdef _UNICODE
	lpDst = lpWide;
#else
	count = ::WideCharToMultiByte(::GetACP(), 0, lpWide, -1, NULL, 0, NULL, 0);

	if (count > 0)
	{
		lpDst = new char[count + 1];
		memset(lpDst, 0, count + 1);

		::WideCharToMultiByte(::GetACP(), 0, lpWide, -1, lpDst, count, NULL, 0);
	}

	delete [] lpWide;
#endif

	strDst = lpDst;
	delete[] lpDst;
	return count;
}
