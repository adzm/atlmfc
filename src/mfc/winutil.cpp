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
#include <malloc.h>



/////////////////////////////////////////////////////////////////////////////
// Other helpers

BOOL AFXAPI AfxCustomLogFont(UINT nIDS, LOGFONT* pLogFont)
{
	ENSURE_ARG(pLogFont != NULL);
	ASSERT(nIDS != 0);

	TCHAR szFontInfo[256];
	if (!AfxLoadString(nIDS, szFontInfo,_countof(szFontInfo)))
		return FALSE;

	LPTSTR lpszSize = _tcschr(szFontInfo, '\n');
	if (lpszSize != NULL)
	{
		// get point size and convert to pixels
		pLogFont->lfHeight = _ttoi(lpszSize+1);
		pLogFont->lfHeight =
			MulDiv(pLogFont->lfHeight, afxData.cyPixelsPerInch, 72);
		*lpszSize = '\0';
	}
	Checked::tcsncpy_s(pLogFont->lfFaceName, _countof(pLogFont->lfFaceName), szFontInfo, _TRUNCATE);
	return TRUE;
}

BOOL AFXAPI _AfxIsComboBoxControl(HWND hWnd, UINT nStyle)
{
	if (hWnd == NULL)
		return FALSE;
	// do cheap style compare first
	if ((UINT)(::GetWindowLong(hWnd, GWL_STYLE) & 0x0F) != nStyle)
		return FALSE;

	// do expensive classname compare next
	TCHAR szCompare[_countof("combobox")+1];
	::GetClassName(hWnd, szCompare, _countof(szCompare));
	return ::AfxInvariantStrICmp(szCompare, _T("combobox")) == 0;
}

BOOL AFXAPI _AfxCompareClassName(HWND hWnd, LPCTSTR lpszClassName)
{
	ASSERT(::IsWindow(hWnd));
	TCHAR szTemp[32];
	::GetClassName(hWnd, szTemp, _countof(szTemp));
	return ::AfxInvariantStrICmp(szTemp, lpszClassName) == 0;
}

HWND AFXAPI _AfxChildWindowFromPoint(HWND hWnd, POINT pt)
{
	ASSERT(hWnd != NULL);

	// check child windows
	::ClientToScreen(hWnd, &pt);
	HWND hWndChild = ::GetWindow(hWnd, GW_CHILD);
	for (; hWndChild != NULL; hWndChild = ::GetWindow(hWndChild, GW_HWNDNEXT))
	{
		if (_AfxGetDlgCtrlID(hWndChild) != (WORD)-1 &&
			(::GetWindowLong(hWndChild, GWL_STYLE) & WS_VISIBLE))
		{
			// see if point hits the child window
			CRect rect;
			::GetWindowRect(hWndChild, rect);
			if (rect.PtInRect(pt))
				return hWndChild;
		}
	}

	return NULL;    // not found
}

HWND AFXAPI _AfxTopChildWindowFromPoint(HWND hWnd, POINT pt)
{
	ASSERT(hWnd != NULL);

	// ask Windows for the child window at the point
	HWND hWndRet = ::RealChildWindowFromPoint(hWnd, pt);
	if (hWndRet != NULL)
	{
		return ((hWndRet == hWnd) ? NULL : hWndRet);
	}

	// fallback: check child windows, return the topmost child that contains the point
	::ClientToScreen(hWnd, &pt);
	HWND hWndChild = ::GetWindow(hWnd, GW_CHILD);
	for (; hWndChild != NULL; hWndChild = ::GetWindow(hWndChild, GW_HWNDNEXT))
	{
		if (_AfxGetDlgCtrlID(hWndChild) != (WORD)-1 && (::GetWindowLong(hWndChild, GWL_STYLE) & WS_VISIBLE))
		{
			// see if point hits the child window
			CRect rect;
			::GetWindowRect(hWndChild, rect);
			if (rect.PtInRect(pt))
			{
				hWndRet = hWndChild;
			}
		}
	}

	return hWndRet;    // not found
}

void AFXAPI AfxSetWindowText(HWND hWndCtrl, LPCTSTR lpszNew)
{
	ENSURE(hWndCtrl);
	ENSURE(lpszNew);

	size_t nNewLen = _tcslen(lpszNew);
	TCHAR szOld[256]=_T("");
	// fast check to see if text really changes (reduces flash in controls)
	if (nNewLen > _countof(szOld) ||
		::GetWindowText(hWndCtrl, szOld, _countof(szOld)) != static_cast<int>(nNewLen) ||
		lstrcmp(szOld, lpszNew) != 0)
	{
		// change it
		::SetWindowText(hWndCtrl, lpszNew);
	}
}

void AFXAPI AfxDeleteObject(HGDIOBJ* pObject)
{
	ENSURE_ARG(pObject != NULL);	
	if (*pObject != NULL)
	{
		DeleteObject(*pObject);
		*pObject = NULL;
	}
}

void AFXAPI AfxCancelModes(HWND hWndRcvr)
{
	// if we receive a message destined for a window, cancel any combobox
	//  popups that could be in toolbars or dialog bars
	HWND hWndCancel = ::GetFocus();
	if (hWndCancel == NULL)
		return;     // nothing to cancel

	if (hWndCancel == hWndRcvr)
		return;     // let input go to window with focus

	// focus is in part of a combo-box
	if (!_AfxIsComboBoxControl(hWndCancel, (UINT)CBS_DROPDOWNLIST))
	{
		// check as a dropdown
		hWndCancel = ::GetParent(hWndCancel);   // parent of edit is combo
		if (hWndCancel == hWndRcvr)
			return;     // let input go to part of combo

		if (!_AfxIsComboBoxControl(hWndCancel, (UINT)CBS_DROPDOWN))
			return;     // not a combo-box that is active
	}

	// combo-box is active, but if receiver is a popup, do nothing
	if (hWndRcvr != NULL &&
	  (::GetWindowLong(hWndRcvr, GWL_STYLE) & WS_CHILD) != 0 &&
	  ::GetParent(hWndRcvr) == ::GetDesktopWindow())
		return;

	// finally, we should cancel the mode!
	::SendMessage(hWndCancel, CB_SHOWDROPDOWN, FALSE, 0L);
}

void AFXAPI AfxGlobalFree(HGLOBAL hGlobal)
{
	if (hGlobal == NULL)
		return;

	// avoid bogus warning error messages from various debugging tools
	ASSERT(GlobalFlags(hGlobal) != GMEM_INVALID_HANDLE);
	UINT nCount = GlobalFlags(hGlobal) & GMEM_LOCKCOUNT;
	while (nCount--)
		GlobalUnlock(hGlobal);

	// finally, really free the handle
	GlobalFree(hGlobal);
}

/////////////////////////////////////////////////////////////////////////////
// Special new handler for safety pool on temp maps

#define MIN_MALLOC_OVERHEAD 4   // LocalAlloc or other overhead

int AFX_CDECL AfxCriticalNewHandler(size_t nSize)
	// nSize is already rounded
{
	// called during critical memory allocation
	//  free up part of the app's safety cache
	TRACE(atlTraceGeneral, 0, "Warning: Critical memory allocation failed!\n");
	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	if (pThreadState != NULL && pThreadState->m_pSafetyPoolBuffer != NULL)
	{
		size_t nOldBufferSize = _msize(pThreadState->m_pSafetyPoolBuffer);
		if (nOldBufferSize <= nSize + MIN_MALLOC_OVERHEAD)
		{
			// give it all up
			TRACE(atlTraceGeneral, 0, "Warning: Freeing application's memory safety pool!\n");
			free(pThreadState->m_pSafetyPoolBuffer);
			pThreadState->m_pSafetyPoolBuffer = NULL;
		}
		else
		{
			BOOL bEnable = AfxEnableMemoryTracking(FALSE);
			_expand(pThreadState->m_pSafetyPoolBuffer,
				nOldBufferSize - (nSize + MIN_MALLOC_OVERHEAD));
			AfxEnableMemoryTracking(bEnable);
			TRACE(atlTraceGeneral, 0, "Warning: Shrinking safety pool from %d to %d to satisfy request of %d bytes.\n",
				 nOldBufferSize, _msize(pThreadState->m_pSafetyPoolBuffer), nSize);
		}
		return 1;       // retry it
	}

	TRACE(atlTraceGeneral, 0, "ERROR: Critical memory allocation from safety pool failed!\n");
	AfxThrowMemoryException();      // oops
}

#pragma warning(push)  // disable 4191
#pragma warning(disable : 4191)	// 'type cast' : unsafe conversion from 'FARPROC' to 'DLLGETVERSIONPROC'

// Common Control Versions:
//   WinNT 4.0          maj=4 min=00
//   IE 3.x             maj=4 min=70
//   IE 4.0             maj=4 min=71
//   IE 5.0             maj=5 min=80
//   Win2000            maj=5 min=81
HRESULT GetCommCtrlVersion(
	_Out_ LPDWORD pdwMajor,
	_Out_ LPDWORD pdwMinor)
{
	*pdwMajor = 0;
	*pdwMinor = 0;

	HINSTANCE hInstDLL = ::LoadLibraryW(L"comctl32.dll");
	if(hInstDLL == NULL)
	{
		return AtlHresultFromLastError();
	}

	// We must get this function explicitly because some DLLs don't implement it.
	DLLGETVERSIONPROC pfnDllGetVersion = (DLLGETVERSIONPROC)::GetProcAddress(hInstDLL, "DllGetVersion");
	HRESULT hRet;

	if(pfnDllGetVersion != NULL)
	{
		DLLVERSIONINFO dvi;
		memset(&dvi, 0, sizeof(dvi));
		dvi.cbSize = sizeof(dvi);

		hRet = (*pfnDllGetVersion)(&dvi);
		if (SUCCEEDED(hRet))
		{
			*pdwMajor = dvi.dwMajorVersion;
			*pdwMinor = dvi.dwMinorVersion;
		}
	}
	else
	{
		hRet = E_NOTIMPL;
	}
	
	::FreeLibrary(hInstDLL);
	return hRet;
}

#pragma warning(pop)  // disable 4191

/////////////////////////////////////////////////////////////////////////////
