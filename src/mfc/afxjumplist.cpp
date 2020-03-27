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

#ifndef __AFXADV_H__
#include <afxadv.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <propkey.h>
#include <atlconv.h>
#include <propvarutil.h>

#include "afxglobals.h"

#if (WINVER >= 0x0601)
CJumpList::CJumpList(BOOL bAutoCommit) 
{
	m_bInitialized = FALSE;
	m_nMaxSlots = 0;
	m_bAutoCommit = bAutoCommit;
}

CJumpList::~CJumpList()
{
	if (!afxGlobalData.bIsWindows7)
	{
		return;
	}

	if (m_bInitialized && !m_bAutoCommit)
	{
		TRACE0("Jump list is being destroyed without a call on CJumpList::CommitList.\n");
	}

	if (m_bAutoCommit)
	{
		// calls ClearAll as well
		// can be called when m_bInitialized is FALSE
		CommitList();
	}
	else
	{
		ClearAll();
	}
}

void CJumpList::ClearAll()
{
	if (!afxGlobalData.bIsWindows7)
	{
		return;
	}

	ClearAllDestinations();
	ReleaseObjectArray(m_tasksPtr.Detach());
	ReleaseObjectArray(m_removedItemsPtr.Detach());

	m_bInitialized = FALSE;
}

BOOL CJumpList::InitializeList()
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	HRESULT hr = S_OK;
	if (m_destListPtr == NULL)
	{
		hr = m_destListPtr.CoCreateInstance(CLSID_DestinationList, NULL, CLSCTX_INPROC_SERVER);
		if (FAILED(hr))
		{
			TRACE1("Error initializing Jump List, code: %x", hr);
			return FALSE;
		}
	}

	if (m_tasksPtr == NULL)
	{
		hr = m_tasksPtr.CoCreateInstance(CLSID_EnumerableObjectCollection, NULL, CLSCTX_INPROC_SERVER);
		if (FAILED(hr))
		{
			TRACE1("Error initializing task collection, code: %x", hr);
			return FALSE;
		}
	}

	if (!m_bInitialized)
	{
		CString strAppID = m_strAppID; 
		if (strAppID.IsEmpty ())
		{
			// try WinApp
			CWinApp* pApp = AfxGetApp();
			ASSERT(pApp != NULL);
			strAppID = pApp->m_pszAppID;
		}

		if(!strAppID.IsEmpty())
		{
#ifdef UNICODE
			m_destListPtr->SetAppID(strAppID);
#else
			USES_CONVERSION;
			LPCWSTR lpAppID = A2W(strAppID);
			m_destListPtr->SetAppID(lpAppID);
#endif
		}

		hr = m_destListPtr->BeginList(&m_nMaxSlots, IID_IObjectArray, (LPVOID*)&m_removedItemsPtr);
		if (FAILED(hr))
		{
			TRACE1("ICustomDestinationList::BeginList failed, initialization canceled, HRESULT: %x", hr);
			return FALSE;
		}
		m_bInitialized = TRUE;
	}

	return TRUE;
}

UINT CJumpList::GetMaxSlots() const
{
	if (!afxGlobalData.bIsWindows7)
	{
		return 0;
	}

	ASSERT(m_bInitialized);
	return m_nMaxSlots;
}

BOOL CJumpList::AddKnownCategory(KNOWNDESTCATEGORY category)
{
	if (!InitializeList()) // always returns FALSE if OS < Win7 
	{
		return FALSE;
	}

	HRESULT hr = m_destListPtr->AppendKnownCategory(category);
	if (FAILED(hr))
	{
		TRACE1("CJumpList::AddKnownCategory failed, HRESULT: %x\n", hr);
		return FALSE;
	}

	return TRUE;
}

BOOL CJumpList::AddTask(LPCTSTR strTargetExecutablePath, LPCTSTR strCommandLineArgs, 
						LPCTSTR strTitle, LPCTSTR strIconPath, int iIconIndex)
{
	if (!InitializeList()) // always returns FALSE if OS < Win7 
	{
		return FALSE;
	}

	AfxIsValidString(strTargetExecutablePath);
	AfxIsValidString(strTitle);

	if (strTargetExecutablePath == NULL || strTitle == NULL)
	{
		return FALSE;
	}

	CComPtr<IShellLink> shellLinkPtr;
	if (FAILED(shellLinkPtr.CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER)))
	{
		return FALSE;
	}

	shellLinkPtr->SetPath(strTargetExecutablePath);
	shellLinkPtr->SetArguments(strCommandLineArgs);
	shellLinkPtr->SetIconLocation(strIconPath, iIconIndex);

	CComQIPtr<IPropertyStore> propPtr = shellLinkPtr;

	if (propPtr != NULL)
	{
		PROPVARIANT var;
#ifdef UNICODE
		if (FAILED(InitPropVariantFromString(strTitle, &var)))
		{
			return FALSE;
		}
#else
		USES_CONVERSION;
		LPCWSTR lpTitle = A2W(strTitle);
		if (FAILED(InitPropVariantFromString(lpTitle, &var)))
		{
			return FALSE;
		}
#endif

		if (FAILED(propPtr->SetValue(PKEY_Title, var)))
		{
			PropVariantClear(&var);
			return FALSE;
		}

		HRESULT hr = propPtr->Commit();
		PropVariantClear(&var);
		if (FAILED(hr))
		{
			return FALSE;
		}
	}

	return (SUCCEEDED(m_tasksPtr->AddObject(shellLinkPtr.Detach())));
}

BOOL CJumpList::AddTaskSeparator()
{
	if (!InitializeList()) // always returns FALSE if OS < Win7 
	{
		return FALSE;
	}

	CComPtr<IShellLink> shellLinkPtr;
	if (FAILED(shellLinkPtr.CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER)))
	{
		return FALSE;
	}

	CComQIPtr<IPropertyStore> propPtr = shellLinkPtr;
	PROPVARIANT var;
	var.vt = VT_BOOL;
	var.boolVal = VARIANT_TRUE;

	if (FAILED(propPtr->SetValue(PKEY_AppUserModel_IsDestListSeparator, var)))
	{
		PropVariantClear(&var);
		return FALSE;
	}

	HRESULT hr = propPtr->Commit();
	PropVariantClear(&var);
	if (FAILED(hr))
	{
		return FALSE;
	}

	return (SUCCEEDED(m_tasksPtr->AddObject(shellLinkPtr.Detach())));
}

BOOL CJumpList::AddTask(IShellLink* pShellLink)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	ASSERT(pShellLink != NULL);

	if (pShellLink == NULL)
	{
		return FALSE;
	}

	if (!InitializeList())
	{
		return FALSE;
	}

	if (FAILED(m_tasksPtr->AddObject(pShellLink)))
	{
		return FALSE;
	}

	pShellLink->AddRef();
	return TRUE;
}

BOOL CJumpList::AddTasks(IObjectArray* pObjectCollection)
{
	if (!InitializeList()) // always returns FALSE if OS < Win7 
	{
		return FALSE;
	}

	ASSERT(pObjectCollection != NULL);

	if (pObjectCollection == NULL)
	{
		return FALSE;
	}

	return SUCCEEDED(m_tasksPtr->AddFromArray(pObjectCollection));
}

BOOL CJumpList::AddDestination(LPCTSTR lpcszCategoryName, LPCTSTR lpcszDestinationPath)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	ASSERT(lpcszCategoryName != NULL);
	ASSERT(lpcszDestinationPath != NULL);

	if (lpcszCategoryName == NULL || lpcszDestinationPath == NULL)
	{
		return FALSE;
	}

	IObjectCollection* pColl = GetObjectCollection(lpcszCategoryName);

	if (pColl == NULL)
	{
		TRACE0("AddDestination - GetObjectCollection returned NULL collection.\n");
		return FALSE;
	}

	IShellItem* psi = NULL;
#ifdef UNICODE
	HRESULT hr = afxGlobalData.ShellCreateItemFromParsingName(lpcszDestinationPath, NULL, IID_IShellItem, (LPVOID*)&psi);
#else
	USES_CONVERSION;
	LPWSTR lpDestPath = A2W(lpcszDestinationPath);
	HRESULT hr = afxGlobalData.ShellCreateItemFromParsingName(lpDestPath, NULL, IID_IShellItem, (LPVOID*)&psi);
#endif

	if (FAILED(hr))
	{
		TRACE1("Can't obtain IShellItem from specified destination, HRESULT: %x.\n", hr);
		return FALSE;
	}

	hr = pColl->AddObject(psi);

	if (FAILED(hr))
	{
		TRACE1("Add object to collection failed, HRESULT: %x.\n", hr);
		psi->Release();
		return FALSE;
	}

	return TRUE;
}

BOOL CJumpList::AddDestination(LPCTSTR lpcszCategoryName, IShellItem* pShellItem)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	ASSERT(pShellItem != NULL);

	if (pShellItem == NULL)
	{
		return FALSE;
	}

	IObjectCollection* pColl = GetObjectCollection(lpcszCategoryName);

	if (pColl == NULL)
	{
		return FALSE;
	}

	HRESULT hr = pColl->AddObject(pShellItem);

	if (FAILED(hr))
	{
		TRACE1("Add object to collection failed, HRESULT: %x.\n", hr);
		return FALSE;
	}

	return TRUE;
}

BOOL CJumpList::AddDestination(LPCTSTR lpcszCategoryName, IShellLink* pShellLink)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	ASSERT(pShellLink != NULL);

	if (pShellLink == NULL)
	{
		return FALSE;
	}

	IObjectCollection* pColl = GetObjectCollection(lpcszCategoryName);

	if (pColl == NULL)
	{
		return FALSE;
	}

	HRESULT hr = pColl->AddObject(pShellLink);

	if (FAILED(hr))
	{
		TRACE1("Add object to collection failed, HRESULT: %x.\n", hr);
		return FALSE;
	}

	return TRUE;
}

IObjectCollection* CJumpList::GetObjectCollection(LPCTSTR lpcszCategoryName)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return NULL;
	}

	ASSERT(lpcszCategoryName);

	if (lpcszCategoryName == NULL)
	{
		return NULL;
	}

	IObjectCollection* pColl = NULL;
	m_mapDestinations.Lookup(lpcszCategoryName, pColl);
	if(pColl == NULL)
	{
		HRESULT hr = CoCreateInstance(CLSID_EnumerableObjectCollection, NULL, CLSCTX_INPROC_SERVER, 
			IID_IObjectCollection, (LPVOID*) &pColl);
		if (FAILED(hr))
		{
			TRACE1("Creation of object collection failed with HRESULT: %x.\n", hr);
			return NULL;
		}

		m_mapDestinations.SetAt(lpcszCategoryName, pColl);
	}

	return pColl;
}

BOOL CJumpList::CommitList()
{
	if (!InitializeList()) // always returns FALSE if OS < Win7 
	{
		return FALSE;
	}

	for (POSITION pos = m_mapDestinations.GetStartPosition(); pos != NULL;)
	{
		CString strCategory;
		IObjectCollection* pColl = NULL;
		m_mapDestinations.GetNextAssoc(pos, strCategory, pColl);

		// remove items that could be in "removed" list from the collection being added  
		IObjectCollection* pFinalCollection = CheckRemovedItems(pColl);

		ASSERT(pFinalCollection != NULL);
		if (pFinalCollection == NULL)
		{
			TRACE1("A final collection for Category \"%s\" is NULL. This category is not committed. \n", strCategory);
			continue;
		}

		UINT nDocCount = 0;
		pFinalCollection->GetCount(&nDocCount);

		if (nDocCount == 0)
		{
			TRACE1("WARNING: A final collection for Category \"%s\" is empty. \n", strCategory);
		}

#ifdef UNICODE
		HRESULT hr = m_destListPtr->AppendCategory(strCategory, pFinalCollection);
#else
		USES_CONVERSION;
		LPWSTR lpCategory = A2W(strCategory);
		HRESULT hr = m_destListPtr->AppendCategory(lpCategory, pFinalCollection);
#endif
		if(FAILED(hr))
		{
			TRACE2("Append category %s failed , HRESULT: %x.\n", strCategory, hr);
		}

		ReleaseObjectArray(pFinalCollection);
	}

	ASSERT(m_tasksPtr != NULL);
	UINT nTaskCount = 0;
	m_tasksPtr->GetCount(&nTaskCount);

	if (nTaskCount > 0)
	{
		HRESULT hr = m_destListPtr->AddUserTasks(m_tasksPtr);
		if (FAILED(hr))
		{
			TRACE1("Add tasks failed, code: %x\n", hr);
		}
		IObjectCollection* pTaskColl = m_tasksPtr.Detach();
		ReleaseObjectArray(pTaskColl);
	}

	m_mapDestinations.RemoveAll();

	BOOL bResult = TRUE;
	HRESULT hr = m_destListPtr->CommitList();

	if (FAILED(hr))
	{
		TRACE1("CommitList failed, HRESULT: %x\n", hr);
		bResult = FALSE;
	}

	ClearAll(); //set m_bInitialized to FALSE

	// prevent calling CommitList for second time from destructor
	m_bAutoCommit = FALSE;

	return bResult;
}

IObjectCollection* CJumpList::CheckRemovedItems(IObjectCollection* pColl)
{
	if (!afxGlobalData.bIsWindows7)
	{
		return NULL;
	}

	ASSERT(pColl != NULL);
	ASSERT(m_bInitialized);
	ASSERT(m_destListPtr != NULL);

	if (m_removedItemsPtr == NULL)
	{
		return pColl;
	}

	UINT nRemovedObjCount = 0; 
	UINT nCheckObjCount = 0;

	if (FAILED(m_removedItemsPtr->GetCount(&nRemovedObjCount)) || nRemovedObjCount == 0)
	{
		return pColl;
	}

	if (FAILED(pColl->GetCount(&nCheckObjCount)) || nCheckObjCount == 0)
	{
		return pColl;
	}

	IObjectCollection* pFinalCollection = NULL;

	HRESULT hr = CoCreateInstance(CLSID_EnumerableObjectCollection, NULL, CLSCTX_INPROC_SERVER, 
		IID_IObjectCollection, (LPVOID*) &pFinalCollection);

	if (FAILED(hr))
	{
		return pColl;
	}

	for (UINT i = 0; i < nCheckObjCount; i++)
	{
		IShellItem* pShellItemChk = NULL;
		if (FAILED (pColl->GetAt(i, IID_IShellItem, (LPVOID*) &pShellItemChk)) || pShellItemChk == NULL)
		{
			continue;
		}

		for (UINT j = 0; j < nRemovedObjCount; j++)
		{
			IShellItem* pShellItemRemoved = NULL;
			if (FAILED (m_removedItemsPtr->GetAt(i, IID_IShellItem, (LPVOID*) &pShellItemRemoved)) || pShellItemRemoved == NULL)
			{
				continue;
			}

			int nOrder = 0;
			if (SUCCEEDED(pShellItemChk->Compare(pShellItemRemoved, 0, &nOrder)) && nOrder != 0)
			{
				pFinalCollection->AddObject(pShellItemChk);
			}
			else
			{
				pShellItemChk->Release();
			}
		}
	}

	pColl->Release();
	return pFinalCollection;

}

void CJumpList::ClearAllDestinations()
{
	if (!afxGlobalData.bIsWindows7)
	{
		return;
	}

	for (POSITION pos = m_mapDestinations.GetStartPosition(); pos != NULL;)
	{
		CString strCategory;
		IObjectCollection* pColl = NULL;
		m_mapDestinations.GetNextAssoc(pos, strCategory, pColl);

		ReleaseObjectArray(pColl);
	}

	m_mapDestinations.RemoveAll();
}

void CJumpList::ReleaseObjectArray(IObjectArray* pColl, BOOL bReleaseItemsOnly)
{
	if (pColl == NULL)
	{
		return;
	}

	UINT nObjCount = 0;
	HRESULT hr = pColl->GetCount(&nObjCount);
	if (FAILED(hr))
	{
		return;
	}

	for (UINT i = 0; i < nObjCount; i++)
	{
		IUnknown* pUnk = NULL;
		if (SUCCEEDED (pColl->GetAt(i, IID_IUnknown, (LPVOID*) &pUnk)) && pUnk != NULL)
		{
			pUnk->Release();
		}
	}

	if (!bReleaseItemsOnly)
	{
		pColl->Release();
	}
}

CAppDestinations::CAppDestinations()
{
	CWinApp* pApp = AfxGetApp();

	if (pApp != NULL)
	{
		SetAppID(pApp->m_pszAppID);	
	}
}

CAppDestinations::CAppDestinations(LPCTSTR lpszAppID)
{
	SetAppID(lpszAppID);
}

void CAppDestinations::SetAppID(LPCTSTR lpszAppID)
{
#ifdef UNICODE
	m_strAppID = lpszAppID;
#else
	USES_CONVERSION;
	m_strAppID = A2W(lpszAppID);
#endif
}

BOOL CAppDestinations::RemoveDestination(IUnknown* pUnk)
{
	if (!Init() || pUnk == NULL) // always returns FALSE for OS < Win7
	{
		return FALSE;
	}

	ENSURE(m_appDests != NULL);
	HRESULT hr = m_appDests->RemoveDestination(pUnk);

	if (FAILED(hr))
	{
		TRACE1("RemoveDestination failed with code %x.", hr);
		return FALSE;
	}

	return TRUE;
}

BOOL CAppDestinations::RemoveAllDestinations()
{
	if (!Init()) // always returns FALSE for OS < Win7
	{
		return FALSE;
	}

	ENSURE(m_appDests != NULL);
	HRESULT hr = m_appDests->RemoveAllDestinations();

	if (FAILED(hr))
	{
		TRACE1("RemoveAllDestinations failed with code %x.", hr);
		return FALSE;
	}

	return TRUE;
}

BOOL CAppDestinations::Init()
{
	if (!afxGlobalData.bIsWindows7)
	{
		return FALSE;
	}

	if (m_appDests != NULL) // already initialized
	{
		return TRUE;
	}

	HRESULT hr = m_appDests.CoCreateInstance(CLSID_ApplicationDestinations, NULL, CLSCTX_INPROC_SERVER);

	if (FAILED(hr))
	{
		TRACE1("Creation of Application Destinations object failed with HRESULT %x. \n", hr);
		return FALSE;
	}

	if (m_strAppID.IsEmpty ())
	{
		// try WinApp again
		CWinApp* pApp = AfxGetApp();
		ASSERT(pApp != NULL);

		SetAppID(pApp->m_pszAppID);
	}

	hr = m_appDests->SetAppID(m_strAppID);
	if (FAILED(hr))
	{
		TRACE1("IApplicationDestinations::SetAppID failed with HRESULT %x. \n", hr);
		return FALSE;
	}

	return TRUE;
}
#endif
