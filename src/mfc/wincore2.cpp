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
#include "occimpl.h"

// This module is compiled two different ways:
// 1) It is compiled without _AFX_NO_MFC_CONTROLS_IN_DIALOGS #defined as part of the normal
//    MFC static libraries [N|U]AFXCW[D].LIB.  This way enables MFC controls in dialogs.
// 2) It is compiled with _AFX_NO_MFC_CONTROLS_IN_DIALOGS #defined as part of the smaller MFC
//    static libraries AFXNMCD[D].LIB, and it is one of the two modules included those libraries.
//    This way disables MFC controls in dialogs.  Use of these libraries is controlled by the
//    definition of _AFX_NO_MFC_CONTROLS_IN_DIALOGS in the application stdafx.h file.

#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
#include "afxctrlcontainer.h"
#include "afxglobals.h"
#endif

#define new DEBUG_NEW

// The following symbol is used to force inclusion of this module from AFXNMCD[D].LIB when
// _AFX_NO_MFC_CONTROLS_IN_DIALOGS is defined in the application stdafx.h file.  This ensures
// that the CWnd::ExecuteDlgInit without MFC control support is linked into the application.
#if !defined(_AFXDLL) && defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
#ifdef _X86_
extern "C" { int _afxNoMFCControlSupportInDialogs = 0; }
#else
extern "C" { int __afxNoMFCControlSupportInDialogs = 0; }
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog initialization support, possibly including support for MFC controls

BOOL CWnd::ExecuteDlgInit(LPVOID lpResource)
{
	BOOL bSuccess = TRUE;
	if (lpResource != NULL)
	{
		UNALIGNED WORD* lpnRes = (WORD*)lpResource;
		while (bSuccess && *lpnRes != 0)	
		{
			WORD nIDC = *lpnRes++;
			WORD nMsg = *lpnRes++;
			DWORD dwLen = *((UNALIGNED DWORD*&)lpnRes)++;

			// In Win32 the WM_ messages have changed.  They have
			// to be translated from the 16-bit values to 32-bit
			// values here.

			#define WIN16_LB_ADDSTRING  0x0401
			#define WIN16_CB_ADDSTRING  0x0403
			if (nMsg == WIN16_LB_ADDSTRING)
				nMsg = LB_ADDSTRING;
			else if (nMsg == WIN16_CB_ADDSTRING)
				nMsg = CB_ADDSTRING;

			// check for invalid/unknown message types
			ASSERT(nMsg == LB_ADDSTRING || nMsg == CB_ADDSTRING ||
				nMsg == WM_MFC_INITCTRL ||
				nMsg == WM_OCC_LOADFROMSTREAM ||
				nMsg == WM_OCC_LOADFROMSTREAM_EX ||
				nMsg == WM_OCC_LOADFROMSTORAGE ||
				nMsg == WM_OCC_LOADFROMSTORAGE_EX ||
				nMsg == WM_OCC_INITNEW);

#ifdef _DEBUG
			// For AddStrings, the count must exactly delimit the
			// string, including the NULL termination.  This check
			// will not catch all mal-formed ADDSTRINGs, but will
			// catch some.
			if (nMsg == LB_ADDSTRING || nMsg == CB_ADDSTRING)
				ASSERT(*((LPBYTE)lpnRes + (UINT)dwLen - 1) == 0);
#endif

			if (nMsg == LB_ADDSTRING || nMsg == CB_ADDSTRING)
			{
				// List/Combobox returns -1 for error
				if (::SendDlgItemMessageA(m_hWnd, nIDC, nMsg, 0, (LPARAM) lpnRes) == -1)
					bSuccess = FALSE;
			}
#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
			else if (nMsg == WM_MFC_INITCTRL)
			{
				if (::SendDlgItemMessageA(m_hWnd, nIDC, nMsg, (WPARAM)dwLen, (LPARAM) lpnRes) == -1)
					bSuccess = FALSE;

				// Subclass Feature Pack controls: 
				if (m_pMFCCtrlContainer == NULL)
				{
					m_pMFCCtrlContainer = new CMFCControlContainer(this);
					m_pMFCCtrlContainer->SubclassDlgControls();
				}

				if (m_pMFCCtrlContainer != NULL)
				{
					m_pMFCCtrlContainer->SetControlData(nIDC, dwLen, (BYTE*) lpnRes);
				}
			}
#endif
			// skip past data
			lpnRes = (WORD*)((LPBYTE)lpnRes + (UINT)dwLen);
		}
	}

	// send update message to all controls after all other siblings loaded
	if (bSuccess)
		SendMessageToDescendants(WM_INITIALUPDATE, 0, 0, FALSE, FALSE);

	return bSuccess;
}

/////////////////////////////////////////////////////////////////////////////
// Special DDX_ proc for subclassing controls

void AFXAPI DDX_Control(CDataExchange* pDX, int nIDC, CWnd& rControl)
{
	if ((rControl.m_hWnd == NULL) && (rControl.GetControlUnknown() == NULL))    // not subclassed yet
	{
		ASSERT(!pDX->m_bSaveAndValidate);

		pDX->PrepareCtrl(nIDC);
		HWND hWndCtrl;
		pDX->m_pDlgWnd->GetDlgItem(nIDC, &hWndCtrl);

#if defined(_AFXDLL) || !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
		CMFCControlContainer* pMFCCtrlContainer = pDX->m_pDlgWnd->GetMFCControlContainer();
		if (pMFCCtrlContainer != NULL && pMFCCtrlContainer->IsSubclassedFeaturePackControl(hWndCtrl))
		{
			pMFCCtrlContainer->ReSubclassControl(hWndCtrl, (WORD)nIDC, rControl);
			return;
		}
#endif

		if ((hWndCtrl != NULL) && !rControl.SubclassWindow(hWndCtrl))
		{
			ASSERT(FALSE);      // possibly trying to subclass twice?
			AfxThrowNotSupportedException();
		}
#ifndef _AFX_NO_OCC_SUPPORT
		else
		{
			if (hWndCtrl == NULL)
			{
				if (pDX->m_pDlgWnd->GetOleControlSite(nIDC) != NULL)
				{
					rControl.AttachControlSite(pDX->m_pDlgWnd, nIDC);
				}
			}
			else
			{
				// If the control has reparented itself (e.g., invisible control),
				// make sure that the CWnd gets properly wired to its control site.
				if (pDX->m_pDlgWnd->m_hWnd != ::GetParent(rControl.m_hWnd))
					rControl.AttachControlSite(pDX->m_pDlgWnd);
			}
		}
#endif //!_AFX_NO_OCC_SUPPORT

	}
}
