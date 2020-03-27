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
#include <stddef.h>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

/////////////////////////////////////////////////////////////////////////////
// AFX_MODULE_STATE push/pop implementation

#ifdef _AFXDLL
AFX_MODULE_STATE* AFXAPI AfxSetModuleState(AFX_MODULE_STATE* pNewState) throw()
{
	_AFX_THREAD_STATE* pState = NULL;

	TRY
	{
		pState = _afxThreadState.GetData();
	}
	CATCH(CInvalidArgException, pInvalidArgException)
	{
		DELETE_EXCEPTION(pInvalidArgException);
		pState = NULL;
	}
	END_CATCH

	ASSERT(pState);
	if(pState)
	{
		AFX_MODULE_STATE* pPrevState = pState->m_pModuleState;
		pState->m_pModuleState = pNewState;
		return pPrevState;
	}
	else
	{
		return NULL;
	}
}

// AFX_MAINTAIN_STATE functions

AFX_MAINTAIN_STATE::AFX_MAINTAIN_STATE(AFX_MODULE_STATE* pNewState)
{
	m_pPrevModuleState = AfxSetModuleState(pNewState);
}

AFX_MAINTAIN_STATE::~AFX_MAINTAIN_STATE()
{
	AFX_BEGIN_DESTRUCTOR

	_AFX_THREAD_STATE* pState = _afxThreadState;
	ASSERT(pState);
	if(pState)
	{
		pState->m_pModuleState = m_pPrevModuleState;
	}

	AFX_END_DESTRUCTOR
}
#endif //_AFXDLL

// AFX_MAINTAIN_STATE2 functions

AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE* pNewState) throw()
{
	pNewState; // to make the compiler happy...
#ifdef _AFXDLL
	m_pThreadState = _afxThreadState.GetData();
	ASSERT(m_pThreadState);

	if(m_pThreadState)
	{
		m_pPrevModuleState = m_pThreadState->m_pModuleState;
		m_pThreadState->m_pModuleState = pNewState;
	}
	else
	{
		// This is a very bad state; we have no good way to report the error at this moment
		// since exceptions from here are not expected
		m_pPrevModuleState=NULL;
		m_pThreadState=NULL;
	}
#endif
}

AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2()
{
#ifdef _AFXDLL
	// Not a good place to report errors here, so just be safe
	if(m_pThreadState)
	{
		m_pThreadState->m_pModuleState = m_pPrevModuleState;
	}
#endif
}

/////////////////////////////////////////////////////////////////////////////
// _AFX_THREAD_STATE implementation

_AFX_THREAD_STATE::_AFX_THREAD_STATE()
{
#ifdef _DEBUG
	m_nDisablePumpCount = 0;
#endif
	m_msgCur.message = WM_NULL;
	m_nMsgLast = WM_NULL;
	//::GetCursorPos(&(m_ptCursorLast));
	m_ptCursorLast = CPoint(0,0);
}

_AFX_THREAD_STATE::~_AFX_THREAD_STATE()
{
	// unhook windows hooks
	if (m_hHookOldMsgFilter != NULL)
		::UnhookWindowsHookEx(m_hHookOldMsgFilter);
	if (m_hHookOldCbtFilter != NULL)
		::UnhookWindowsHookEx(m_hHookOldCbtFilter);

	// free safety pool buffer
	if (m_pSafetyPoolBuffer != NULL)
		free(m_pSafetyPoolBuffer);

	// parking window must have already been cleaned up by now!
	ASSERT(m_pWndPark == NULL);
}

_AFX_THREAD_STATE* AFXAPI AfxGetThreadState()
{
	_AFX_THREAD_STATE *pState =_afxThreadState.GetData();
	ENSURE(pState != NULL); 
	return pState;
}

THREAD_LOCAL(_AFX_THREAD_STATE, _afxThreadState)

/////////////////////////////////////////////////////////////////////////////
// AFX_MODULE_STATE implementation

#ifdef _AFXDLL
AFX_MODULE_STATE::AFX_MODULE_STATE(BOOL bDLL, WNDPROC pfnAfxWndProc,
	DWORD dwVersion, BOOL bSystem)
#else
AFX_MODULE_STATE::AFX_MODULE_STATE(BOOL bDLL)
#endif
{
	m_factoryList.Construct(offsetof(COleObjectFactory, m_pNextFactory));
	m_classList.Construct(offsetof(CRuntimeClass, m_pNextClass));

	m_fRegisteredClasses = 0;
	m_bDLL = (BYTE)bDLL;
#ifdef _AFXDLL
	m_pfnAfxWndProc = pfnAfxWndProc;
	m_dwVersion = dwVersion;
	m_bSystem = (BYTE)bSystem;
#endif
	BOOL bEnable = TRUE;
	TRY
	{
		//Preallocate the registered classes string, but CRT memory leak report is
		//called before the string frees memory, so need to disable tracking.
		bEnable = AfxEnableMemoryTracking(FALSE);
		m_strUnregisterList.Preallocate(4096);
		AfxEnableMemoryTracking(bEnable);	
	}		
	CATCH(CMemoryException, e)
	{
		AfxEnableMemoryTracking(bEnable);	
		DELETE_EXCEPTION(e);
	}
	END_CATCH
	// app starts out in "user control"
	m_bUserCtrl = TRUE;

	m_lockList.Construct(offsetof(COleControlLock, m_pNextLock));

#ifdef _AFXDLL
	m_libraryList.Construct(offsetof(CDynLinkLibrary, m_pNextDLL));
#endif

	m_bInitNetworkAddressControl = FALSE;
	m_bInitNetworkAddressControlCalled = FALSE;
}

AFX_MODULE_STATE::~AFX_MODULE_STATE()
{
#ifndef _AFX_NO_DAO_SUPPORT
	delete m_pDaoState;
#endif

	// clean up type lib cache map, if any
	if (m_pTypeLibCacheMap != NULL)
	{
		m_pTypeLibCacheMap->RemoveAll(&m_typeLibCache);
		delete m_pTypeLibCacheMap;
	}
}

void CTypeLibCacheMap::RemoveAll(void* pExcept)
{
	POSITION pos = GetStartPosition();
	void* pTypeLibID, *pExceptKey = NULL;
	CTypeLibCache* pCache, *pExceptCache = NULL;
	
	while (pos != NULL)
	{
		GetNextAssoc(pos, pTypeLibID, (void*&)pCache);
		if (pCache != pExcept)
		{
			delete pCache;
		}
		else
		{
			pExceptKey = pTypeLibID;
			pExceptCache = pCache;
        }
	}
	
	CMapPtrToPtr::RemoveAll();
	
	if(pExcept != NULL && pExceptKey != NULL)
	{
		CMapPtrToPtr::SetAt(pExceptKey, pExceptCache);
    }
}

AFX_MODULE_THREAD_STATE::AFX_MODULE_THREAD_STATE()
{
	m_nLastHit = static_cast<INT_PTR>(-1);
	m_nLastStatus = static_cast<INT_PTR>(-1);
	m_pLastInfo = NULL;

	m_frameList.Construct(offsetof(CFrameWnd, m_pNextFrameWnd));

	// Note: it is only necessary to initialize non-zero data
	m_pfnNewHandler = &AfxNewHandler;
}

AFX_MODULE_THREAD_STATE::~AFX_MODULE_THREAD_STATE()
{
	// cleanup thread local tooltip window
	if (m_pToolTip != NULL)
		m_pToolTip->DestroyToolTipCtrl();

	delete m_pLastInfo;

	// cleanup temp/permanent maps (just the maps themselves)
	delete m_pmapHWND;
	delete m_pmapHMENU;
	delete m_pmapHDC;
	delete m_pmapHGDIOBJ;
	delete m_pmapHIMAGELIST;

	// cleanup socket notification list
	if (m_plistSocketNotifications != NULL)
		while (!m_plistSocketNotifications->IsEmpty())
			delete m_plistSocketNotifications->RemoveHead();
#ifndef _AFXDLL
	// cleanup dynamically allocated socket maps
	delete m_pmapSocketHandle;
	delete m_pmapDeadSockets;
	delete m_plistSocketNotifications;
#endif
}

/////////////////////////////////////////////////////////////////////////////
// AFX_MODULE_STATE for base application

LRESULT CALLBACK AfxWndProcBase(HWND, UINT, WPARAM, LPARAM);

class _AFX_BASE_MODULE_STATE : public AFX_MODULE_STATE
{
public:
#ifdef _AFXDLL
	_AFX_BASE_MODULE_STATE() : AFX_MODULE_STATE(TRUE, AfxWndProcBase, _MFC_VER)
#else
	_AFX_BASE_MODULE_STATE() : AFX_MODULE_STATE(TRUE)
#endif
		{ }
};

PROCESS_LOCAL(_AFX_BASE_MODULE_STATE, _afxBaseModuleState)

#ifdef _AFXDLL

#undef AfxWndProc
LRESULT CALLBACK
AfxWndProcBase(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	AFX_MANAGE_STATE(_afxBaseModuleState.GetData());
	return AfxWndProc(hWnd, nMsg, wParam, lParam);
}

#endif

/////////////////////////////////////////////////////////////////////////////
// helper functions for module state

AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState()
{
	return _afxBaseModuleState.GetData();
}

AFX_MODULE_STATE* AFXAPI AfxGetModuleState()
{
	_AFX_THREAD_STATE* pState = _afxThreadState;
	ENSURE(pState);
	AFX_MODULE_STATE* pResult;
	if (pState->m_pModuleState != NULL)
	{
		// thread state's module state serves as override
		pResult = pState->m_pModuleState;
	}
	else
	{
		// otherwise, use global app state
		pResult = _afxBaseModuleState.GetData();
	}
	ENSURE(pResult != NULL);
	return pResult;
}

HINSTANCE AFXAPI AfxGetInstanceHandleHelper()
{
	return AfxGetModuleState()->m_hCurrentInstanceHandle;
}

BOOL AFXAPI AfxIsModuleDll()
{
	return AfxGetModuleState()->m_bDLL;
}

BOOL AFXAPI AfxInitCurrentStateApp()
{
	CWinApp* pApp = AfxGetModuleState()->m_pCurrentWinApp;
	if (pApp != NULL && !pApp->InitInstance())
	{
		// Init Failed
		pApp->ExitInstance();
		AfxWinTerm();
		return FALSE;
	}
	return TRUE;
}

AFX_MODULE_THREAD_STATE* AFXAPI AfxGetModuleThreadState()
{
	AFX_MODULE_THREAD_STATE* pResult=AfxGetModuleState()->m_thread.GetData();
	ENSURE(pResult != NULL);
	return pResult;
}

/////////////////////////////////////////////////////////////////////////////
// CTypeLibCache::Unlock
// (Note: the rest of CTypeLibCache is implemented in oletyplb.cpp)

void CTypeLibCache::Unlock()
{
	ASSERT(m_cRef > 0);

	if (InterlockedDecrement(&m_cRef) == 0)
	{
		if (m_ptinfo != NULL)
		{
			m_ptinfo->Release();
			m_ptinfo = NULL;
		}
		if (m_ptlib != NULL)
		{
			m_ptlib->Release();
			m_ptlib = NULL;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// Registry Redirection Flag

AFX_STATIC_DATA BOOL _afxRedirectRegistration = FALSE;

void AFXAPI AfxSetPerUserRegistration(BOOL bEnable)
{
	_afxRedirectRegistration = bEnable;
}

BOOL AFXAPI AfxGetPerUserRegistration(void)
{
	return _afxRedirectRegistration;
}

/////////////////////////////////////////////////////////////////////////////
