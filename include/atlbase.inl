// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLBASE_INL__
#define __ATLBASE_INL__

#pragma once

#ifndef __ATLBASE_H__
	#error atlbase.inl requires atlbase.h to be included first
#endif
#pragma warning(push)
#pragma warning(disable:4571) //catch(...) blocks compiled with /EHs do NOT catch or re-throw Structured Exceptions
namespace ATL
{

/////////////////////////////////////////////////////////////////////////////
// Connection Point Helpers

ATLINLINE ATLAPI AtlAdvise(
	_Inout_ IUnknown* pUnkCP,
	_Inout_opt_ IUnknown* pUnk,
	_In_ const IID& iid,
	_Out_ LPDWORD pdw)
{
	if(pUnkCP == NULL)
		return E_INVALIDARG;

	CComPtr<IConnectionPointContainer> pCPC;
	CComPtr<IConnectionPoint> pCP;
	HRESULT hRes = pUnkCP->QueryInterface(__uuidof(IConnectionPointContainer), (void**)&pCPC);
	if (SUCCEEDED(hRes))
		hRes = pCPC->FindConnectionPoint(iid, &pCP);
	if (SUCCEEDED(hRes))
		hRes = pCP->Advise(pUnk, pdw);
	return hRes;
}

ATLINLINE ATLAPI AtlUnadvise(
	_Inout_ IUnknown* pUnkCP,
	_In_ const IID& iid,
	_In_ DWORD dw)
{
	if(pUnkCP == NULL)
		return E_INVALIDARG;

	CComPtr<IConnectionPointContainer> pCPC;
	CComPtr<IConnectionPoint> pCP;
	HRESULT hRes = pUnkCP->QueryInterface(__uuidof(IConnectionPointContainer), (void**)&pCPC);
	if (SUCCEEDED(hRes))
		hRes = pCPC->FindConnectionPoint(iid, &pCP);
	if (SUCCEEDED(hRes))
		hRes = pCP->Unadvise(dw);
	return hRes;
}

/////////////////////////////////////////////////////////////////////////////
// Inproc Marshaling helpers

//This API should be called from the same thread that called
//AtlMarshalPtrInProc
ATLINLINE ATLAPI AtlFreeMarshalStream(_Inout_ IStream* pStream)
{
	HRESULT hRes=S_OK;
	if (pStream != NULL)
	{
		LARGE_INTEGER l;
		l.QuadPart = 0;
		pStream->Seek(l, STREAM_SEEK_SET, NULL);
		hRes=CoReleaseMarshalData(pStream);
		pStream->Release();
	}
	return hRes;
}

ATLPREFAST_SUPPRESS(6387)
ATLINLINE ATLAPI AtlMarshalPtrInProc(
	_Inout_ IUnknown* pUnk,
	_In_ const IID& iid,
	_Outptr_ IStream** ppStream)
{
	ATLASSERT(ppStream != NULL);
	if (ppStream == NULL)
		return E_POINTER;

	HRESULT hRes = CreateStreamOnHGlobal(NULL, TRUE, ppStream);
	if (SUCCEEDED(hRes))
	{
		hRes = CoMarshalInterface(*ppStream, iid,
			pUnk, MSHCTX_INPROC, NULL, MSHLFLAGS_TABLESTRONG);
		if (FAILED(hRes))
		{
			(*ppStream)->Release();
			*ppStream = NULL;
		}
	}
	return hRes;
}
ATLPREFAST_UNSUPPRESS()

ATLINLINE ATLAPI AtlUnmarshalPtr(
	_Inout_ IStream* pStream,
	_In_ const IID& iid,
	_Outptr_ IUnknown** ppUnk)
{
	ATLASSERT(ppUnk != NULL);
	if (ppUnk == NULL)
		return E_POINTER;

	*ppUnk = NULL;
	HRESULT hRes = E_INVALIDARG;
	if (pStream != NULL)
	{
		LARGE_INTEGER l;
		l.QuadPart = 0;
		pStream->Seek(l, STREAM_SEEK_SET, NULL);
		hRes = CoUnmarshalInterface(pStream, iid, (void**)ppUnk);
	}
	return hRes;
}

/////////////////////////////////////////////////////////////////////////////
// Module
ATLPREFAST_SUPPRESS(6387 28196)
ATLINLINE ATLAPI AtlComModuleGetClassObject(
	_Inout_ _ATL_COM_MODULE* pComModule,
	_In_ REFCLSID rclsid,
	_In_ REFIID riid,
	_COM_Outptr_ LPVOID* ppv)
{
	if (ppv == NULL)
	{
		return E_POINTER;
	}

	*ppv = NULL;

	ATLASSERT(pComModule != NULL);
	if (pComModule == NULL)
	{
		return E_INVALIDARG;
	}

	if (pComModule->cbSize == 0)  // Module hasn't been initialized
	{
		return E_UNEXPECTED;
	}

	HRESULT hr = S_OK;

	for (_ATL_OBJMAP_ENTRY_EX** ppEntry = pComModule->m_ppAutoObjMapFirst; ppEntry < pComModule->m_ppAutoObjMapLast; ppEntry++)
	{
		if (*ppEntry != NULL)
		{
			const _ATL_OBJMAP_ENTRY_EX* pEntry = *ppEntry;

			if ((pEntry->pfnGetClassObject != NULL) && InlineIsEqualGUID(rclsid, *pEntry->pclsid))
			{
				_ATL_OBJMAP_CACHE* pCache = pEntry->pCache;
				
				if (pCache->pCF == NULL)
				{
					CComCritSecLock<CComCriticalSection> lock(pComModule->m_csObjMap, false);
					hr = lock.Lock();
					if (FAILED(hr))
					{
						ATLTRACE(atlTraceCOM, 0, _T("ERROR : Unable to lock critical section in AtlComModuleGetClassObject\n"));
						ATLASSERT(FALSE);
						break;
					}

					if (pCache->pCF == NULL)
					{
						IUnknown *factory;
						hr = pEntry->pfnGetClassObject(pEntry->pfnCreateInstance, __uuidof(IUnknown), reinterpret_cast<void**>(&factory));
						if (SUCCEEDED(hr))
						{
							pCache->pCF = reinterpret_cast<IUnknown*>(::EncodePointer(factory));
						}
					}
				}

				if (pCache->pCF != NULL)
				{
					// Decode factory pointer
					IUnknown* factory = reinterpret_cast<IUnknown*>(::DecodePointer(pCache->pCF));
					_Analysis_assume_(factory != nullptr);
					hr = factory->QueryInterface(riid, ppv);
				}
				break;
			}
		}
	}

	if (*ppv == NULL && hr == S_OK)
	{
		hr = CLASS_E_CLASSNOTAVAILABLE;
	}

	return hr;
}
ATLPREFAST_UNSUPPRESS()

ATLINLINE ATLAPI AtlComModuleRegisterClassObjects(
	_Inout_ _ATL_COM_MODULE* pComModule,
	_In_ DWORD dwClsContext,
	_In_ DWORD dwFlags)
{
	ATLASSERT(pComModule != NULL);
	if (pComModule == NULL)
		return E_INVALIDARG;

	HRESULT hr = S_FALSE;
	for (_ATL_OBJMAP_ENTRY_EX** ppEntry = pComModule->m_ppAutoObjMapFirst; ppEntry < pComModule->m_ppAutoObjMapLast && SUCCEEDED(hr); ppEntry++)
	{
		if (*ppEntry != NULL)
			hr = (*ppEntry)->RegisterClassObject(dwClsContext, dwFlags);
	}
	return hr;
}

ATLINLINE ATLAPI AtlComModuleRevokeClassObjects(
	_Inout_ _ATL_COM_MODULE* pComModule)
{
	ATLASSERT(pComModule != NULL);
	if (pComModule == NULL)
		return E_INVALIDARG;

	HRESULT hr = S_OK;
	for (_ATL_OBJMAP_ENTRY_EX** ppEntry = pComModule->m_ppAutoObjMapFirst; ppEntry < pComModule->m_ppAutoObjMapLast && hr == S_OK; ppEntry++)
	{
		if (*ppEntry != NULL)
			hr = (*ppEntry)->RevokeClassObject();
	}
	return hr;
}

#ifdef _ATL_USE_WINAPI_FAMILY_DESKTOP_APP

ATLINLINE ATLAPI_(BOOL) AtlWaitWithMessageLoop(_In_ HANDLE hEvent)
{
	DWORD dwRet;
	MSG msg;

	while(1)
	{
		dwRet = MsgWaitForMultipleObjectsEx(1, &hEvent, INFINITE, QS_ALLINPUT, MWMO_INPUTAVAILABLE);

		if (dwRet == WAIT_OBJECT_0)
			return TRUE;    // The event was signaled

		if (dwRet != WAIT_OBJECT_0 + 1)
			break;          // Something else happened

		// There is one or more window message available. Dispatch them
		while(PeekMessage(&msg,0,0,0,PM_NOREMOVE))
		{
			// check for unicode window so we call the appropriate functions
			BOOL bUnicode = ::IsWindowUnicode(msg.hwnd);
			BOOL bRet;

			if (bUnicode)
				bRet = ::GetMessageW(&msg, NULL, 0, 0);
			else
				bRet = ::GetMessageA(&msg, NULL, 0, 0);

			if (bRet > 0)
			{
				::TranslateMessage(&msg);

				if (bUnicode)
					::DispatchMessageW(&msg);
				else
					::DispatchMessageA(&msg);
			}

			if (WaitForSingleObject(hEvent, 0) == WAIT_OBJECT_0)
				return TRUE; // Event is now signaled.
		}
	}
	return FALSE;
}

#endif // _ATL_USE_WINAPI_FAMILY_DESKTOP_APP

/////////////////////////////////////////////////////////////////////////////
// QI support
ATLINLINE ATLAPI AtlInternalQueryInterface(
	_Inout_ void* pThis,
	_In_ const _ATL_INTMAP_ENTRY* pEntries,
	_In_ REFIID iid,
	_COM_Outptr_ void** ppvObject)
{
	ATLASSERT(pThis != NULL);
	ATLASSERT(pEntries!= NULL);
 
	if(pThis == NULL || pEntries == NULL)
		return E_INVALIDARG;

	// First entry in the com map should be a simple map entry
	ATLASSERT(pEntries->pFunc == _ATL_SIMPLEMAPENTRY);
 
	if (ppvObject == NULL)
		return E_POINTER;

	if (InlineIsEqualUnknown(iid)) // use first interface
	{
		IUnknown* pUnk = (IUnknown*)((INT_PTR)pThis+pEntries->dw);
		pUnk->AddRef();
		*ppvObject = pUnk;
		return S_OK;
	}
 
	HRESULT hRes;
 
	for (;; pEntries++)
	{
		if (pEntries->pFunc == NULL)
		{
			hRes = E_NOINTERFACE;
			break;
		}

		BOOL bBlind = (pEntries->piid == NULL);
		if (bBlind || InlineIsEqualGUID(*(pEntries->piid), iid))
		{
			if (pEntries->pFunc == _ATL_SIMPLEMAPENTRY) //offset
			{
				ATLASSERT(!bBlind);
				IUnknown* pUnk = (IUnknown*)((INT_PTR)pThis+pEntries->dw);
				pUnk->AddRef();
				*ppvObject = pUnk;
				return S_OK;
			}
 
			// Actual function call
 
			hRes = pEntries->pFunc(pThis,
				iid, ppvObject, pEntries->dw);
			if (hRes == S_OK)
				return S_OK;
			if (!bBlind && FAILED(hRes))
				break;
		}
	}
 
	*ppvObject = NULL;
 
	return hRes;
}

ATLINLINE ATLAPI_(DWORD) AtlGetVersion(_In_opt_ void* /* pReserved */)
{
	return _ATL_VER;
}

/////////////////////////////////////////////////////////////////////////////
// Windowing

ATLINLINE ATLAPI_(void) AtlWinModuleAddCreateWndData(
	_Inout_ _ATL_WIN_MODULE* pWinModule,
	_Inout_ _AtlCreateWndData* pData,
	_In_ void* pObject)
{
	if (pWinModule == NULL)
		_AtlRaiseException((DWORD)EXCEPTION_ACCESS_VIOLATION);

	ATLASSERT(pData != NULL && pObject != NULL);
	if(pData == NULL || pObject == NULL)
		_AtlRaiseException((DWORD)EXCEPTION_ACCESS_VIOLATION);

	pData->m_pThis = pObject;
	pData->m_dwThreadID = ::GetCurrentThreadId();
	CComCritSecLock<CComCriticalSection> lock(pWinModule->m_csWindowCreate, false);
	if (FAILED(lock.Lock()))
	{
		ATLTRACE(atlTraceWindowing, 0, _T("ERROR : Unable to lock critical section in AtlWinModuleAddCreateWndData\n"));
		ATLASSERT(0);
		return;
	}
	pData->m_pNext = pWinModule->m_pCreateWndList;
	pWinModule->m_pCreateWndList = pData;
}

ATLINLINE ATLAPI_(void*) AtlWinModuleExtractCreateWndData(
	_Inout_opt_ _ATL_WIN_MODULE* pWinModule)
{
	if (pWinModule == NULL)
		return NULL;

	void* pv = NULL;
	CComCritSecLock<CComCriticalSection> lock(pWinModule->m_csWindowCreate, false);
	if (FAILED(lock.Lock()))
	{
		ATLTRACE(atlTraceWindowing, 0, _T("ERROR : Unable to lock critical section in AtlWinModuleExtractCreateWndData\n"));
		ATLASSERT(0);
		return pv;
	}
	_AtlCreateWndData* pEntry = pWinModule->m_pCreateWndList;
	if(pEntry != NULL)
	{
		DWORD dwThreadID = ::GetCurrentThreadId();
		_AtlCreateWndData* pPrev = NULL;
		while(pEntry != NULL)
		{
			if(pEntry->m_dwThreadID == dwThreadID)
			{
				if(pPrev == NULL)
					pWinModule->m_pCreateWndList = pEntry->m_pNext;
				else
					pPrev->m_pNext = pEntry->m_pNext;
				pv = pEntry->m_pThis;
				break;
			}
			pPrev = pEntry;
			pEntry = pEntry->m_pNext;
		}
	}
	return pv;
}

ATLINLINE ATLAPI AtlWinModuleInit(
	_Inout_ _ATL_WIN_MODULE* pWinModule)
{
	if (pWinModule == NULL)
		return E_INVALIDARG;

	// check only in the DLL
	if (pWinModule->cbSize != sizeof(_ATL_WIN_MODULE))
		return E_INVALIDARG;

	pWinModule->m_pCreateWndList = NULL;

	HRESULT hr = pWinModule->m_csWindowCreate.Init();
	if (FAILED(hr))
	{
		ATLTRACE(atlTraceWindowing, 0, _T("ERROR : Unable to initialize critical section in AtlWinModuleInit\n"));
		ATLASSERT(0);
	}
	return hr;
}

/////////////////////////////////////////////////////////////////////////////
// Module

ATLINLINE ATLAPI AtlModuleAddTermFunc(
	_Inout_ _ATL_MODULE* pModule,
	_In_ _ATL_TERMFUNC* pFunc,
	_In_ DWORD_PTR dw)
{
	if (pModule == NULL)
		return E_INVALIDARG;

	HRESULT hr = S_OK;
	_ATL_TERMFUNC_ELEM* pNew = _ATL_NEW _ATL_TERMFUNC_ELEM;
	if (pNew == NULL)
		hr = E_OUTOFMEMORY;
	else
	{
		pNew->pFunc = pFunc;
		pNew->dw = dw;
		CComCritSecLock<CComCriticalSection> lock(pModule->m_csStaticDataInitAndTypeInfo, false);
		hr = lock.Lock();
		if (SUCCEEDED(hr))
		{
			pNew->pNext = pModule->m_pTermFuncs;
			pModule->m_pTermFuncs = pNew;
		}
		else
		{
			delete pNew;
			ATLTRACE(atlTraceGeneral, 0, _T("ERROR : Unable to lock critical section in AtlModuleAddTermFunc\n"));
			ATLASSERT(0);
		}
	}
	return hr;
}

ATLINLINE ATLAPI_(void) AtlCallTermFunc(_Inout_ _ATL_MODULE* pModule)
{
	if (pModule == NULL)
		_AtlRaiseException((DWORD)EXCEPTION_ACCESS_VIOLATION);

	_ATL_TERMFUNC_ELEM* pElem = pModule->m_pTermFuncs;
	_ATL_TERMFUNC_ELEM* pNext = NULL;
	while (pElem != NULL)
	{
		pElem->pFunc(pElem->dw);
		pNext = pElem->pNext;
		delete pElem;
		pElem = pNext;
	}
	pModule->m_pTermFuncs = NULL;
}

} // namespace ATL
#pragma warning(pop)
#endif // __ATLBASE_INL__
