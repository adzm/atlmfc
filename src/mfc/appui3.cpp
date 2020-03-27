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
#include "afxrendertarget.h"

/////////////////////////////////////////////////////////////////////////////
// CWinApp Settings Helpers


void CWinApp::SetRegistryKey(LPCTSTR lpszRegistryKey)
{
	ASSERT(m_pszRegistryKey == NULL);
	ASSERT(lpszRegistryKey != NULL);
	ASSERT(m_pszAppName != NULL);

	BOOL bEnable = AfxEnableMemoryTracking(FALSE);
	free((void*)m_pszRegistryKey);
	m_pszRegistryKey = _tcsdup(lpszRegistryKey);
	free((void*)m_pszProfileName);
	m_pszProfileName = _tcsdup(m_pszAppName);
	AfxEnableMemoryTracking(bEnable);
}

void CWinApp::SetRegistryKey(UINT nIDRegistryKey)
{
	ASSERT(m_pszRegistryKey == NULL);

	TCHAR szRegistryKey[256];
	VERIFY(AfxLoadString(nIDRegistryKey, szRegistryKey));
	SetRegistryKey(szRegistryKey);
}

typedef HRESULT (STDAPICALLTYPE *PFNSETCURRENTPROCESSEXPLICITAPPUSERMODELID)(PCWSTR);
void CWinApp::SetAppID(LPCTSTR lpcszAppID)
{
	HMODULE hShell = GetModuleHandleW(L"Shell32");
	if (hShell == NULL)
	{
		return;
	}

	PFNSETCURRENTPROCESSEXPLICITAPPUSERMODELID pfnSetAppUserModelID = 
		(PFNSETCURRENTPROCESSEXPLICITAPPUSERMODELID)GetProcAddress(hShell, "SetCurrentProcessExplicitAppUserModelID");
	if (pfnSetAppUserModelID == NULL)
	{
		return;
	}

	m_pszAppID = lpcszAppID;

#if(WINVER >= 0x0601)
#ifdef UNICODE
	pfnSetAppUserModelID(lpcszAppID);
#else
	USES_CONVERSION;
	LPCWSTR lpID = A2W(lpcszAppID);
	pfnSetAppUserModelID(lpID);
#endif
#endif
}

// returns key for HKEY_CURRENT_USER\"Software"\RegistryKey\ProfileName
// creating it if it doesn't exist
// responsibility of the caller to call RegCloseKey() on the returned HKEY
HKEY CWinApp::GetAppRegistryKey(CAtlTransactionManager* pTM)
{
	ASSERT(m_pszRegistryKey != NULL);
	ASSERT(m_pszProfileName != NULL);

	HKEY hAppKey = NULL;
	HKEY hSoftKey = NULL;
	HKEY hCompanyKey = NULL;
	
	LSTATUS lStatus = pTM != NULL ? 
		pTM->RegOpenKeyEx(HKEY_CURRENT_USER, _T("software"), 0, KEY_WRITE|KEY_READ, &hSoftKey) :
		::RegOpenKeyEx(HKEY_CURRENT_USER, _T("software"), 0, KEY_WRITE|KEY_READ, &hSoftKey);

	if (lStatus == ERROR_SUCCESS)
	{
		DWORD dw;

		lStatus = pTM != NULL ? 
			pTM->RegCreateKeyEx(hSoftKey, m_pszRegistryKey, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hCompanyKey, &dw) :
			::RegCreateKeyEx(hSoftKey, m_pszRegistryKey, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hCompanyKey, &dw);

		if (lStatus == ERROR_SUCCESS)
		{
			lStatus = pTM != NULL ? 
				pTM->RegCreateKeyEx(hCompanyKey, m_pszProfileName, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hAppKey, &dw) :
				::RegCreateKeyEx(hCompanyKey, m_pszProfileName, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hAppKey, &dw);
		}
	}
	if (hSoftKey != NULL)
		RegCloseKey(hSoftKey);
	if (hCompanyKey != NULL)
		RegCloseKey(hCompanyKey);

	return hAppKey;
}

// returns key for:
//      HKEY_CURRENT_USER\"Software"\RegistryKey\AppName\lpszSection
// creating it if it doesn't exist.
// responsibility of the caller to call RegCloseKey() on the returned HKEY
HKEY CWinApp::GetSectionKey(LPCTSTR lpszSection, CAtlTransactionManager* pTM)
{
	ASSERT(lpszSection != NULL);

	HKEY hSectionKey = NULL;
	HKEY hAppKey = GetAppRegistryKey(pTM);
	if (hAppKey == NULL)
		return NULL;

	DWORD dw;

	if (pTM != NULL)
	{
		pTM->RegCreateKeyEx(hAppKey, lpszSection, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hSectionKey, &dw);
	}
	else
	{
		::RegCreateKeyEx(hAppKey, lpszSection, 0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL, &hSectionKey, &dw);
	}

	RegCloseKey(hAppKey);
	return hSectionKey;
}

UINT CWinApp::GetProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry,
	int nDefault)
{
	ASSERT(lpszSection != NULL);
	ASSERT(lpszEntry != NULL);
	if (m_pszRegistryKey != NULL) // use registry
	{
		HKEY hSecKey = GetSectionKey(lpszSection);
		if (hSecKey == NULL)
			return nDefault;
		DWORD dwValue;
		DWORD dwType;
		DWORD dwCount = sizeof(DWORD);
		LONG lResult = RegQueryValueEx(hSecKey, (LPTSTR)lpszEntry, NULL, &dwType,
			(LPBYTE)&dwValue, &dwCount);
		RegCloseKey(hSecKey);
		if (lResult == ERROR_SUCCESS)
		{
			ASSERT(dwType == REG_DWORD);
			ASSERT(dwCount == sizeof(dwValue));
			return (UINT)dwValue;
		}
		return nDefault;
	}
	else
	{
		ASSERT(m_pszProfileName != NULL);
		return ::GetPrivateProfileInt(lpszSection, lpszEntry, nDefault,
			m_pszProfileName);
	}
}

CString CWinApp::GetProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
	LPCTSTR lpszDefault)
{
	ASSERT(lpszSection != NULL);
	ASSERT(lpszEntry != NULL);
	if (m_pszRegistryKey != NULL)
	{
		HKEY hSecKey = GetSectionKey(lpszSection);
		if (hSecKey == NULL)
			return lpszDefault;
		CString strValue;
		DWORD dwType=REG_NONE;
		DWORD dwCount=0;
		LONG lResult = RegQueryValueEx(hSecKey, (LPTSTR)lpszEntry, NULL, &dwType,
			NULL, &dwCount);
		if (lResult == ERROR_SUCCESS)
		{
			ASSERT(dwType == REG_SZ);
			lResult = RegQueryValueEx(hSecKey, (LPTSTR)lpszEntry, NULL, &dwType,
				(LPBYTE)strValue.GetBuffer(dwCount/sizeof(TCHAR)), &dwCount);
			strValue.ReleaseBuffer();
		}
		RegCloseKey(hSecKey);
		if (lResult == ERROR_SUCCESS)
		{
			ASSERT(dwType == REG_SZ);
			return strValue;
		}
		return lpszDefault;
	}
	else
	{
		ASSERT(m_pszProfileName != NULL);

		if (lpszDefault == NULL)
			lpszDefault = _T("");	// don't pass in NULL
		TCHAR szT[4096];
		DWORD dw = ::GetPrivateProfileString(lpszSection, lpszEntry,
			lpszDefault, szT, _countof(szT), m_pszProfileName);
		ASSERT(dw < 4095);
		return szT;
	}
}

BOOL CWinApp::GetProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
	BYTE** ppData, UINT* pBytes)
{
	ASSERT(lpszSection != NULL);
	ASSERT(lpszEntry != NULL);
	ASSERT(ppData != NULL);
	ASSERT(pBytes != NULL);
	*ppData = NULL;
	*pBytes = 0;
	if (m_pszRegistryKey != NULL)
	{
		HKEY hSecKey = GetSectionKey(lpszSection);
		if (hSecKey == NULL)
		{
			return FALSE;
		}

		// ensure destruction
		::ATL::CRegKey rkSecKey(hSecKey);

		DWORD dwType=0;
		DWORD dwCount=0; 
		LONG lResult = RegQueryValueEx(hSecKey, (LPTSTR)lpszEntry, NULL, &dwType, NULL, &dwCount);
		*pBytes = dwCount;
		if (lResult == ERROR_SUCCESS)
		{
			ASSERT(dwType == REG_BINARY);
			*ppData = new BYTE[*pBytes];
			lResult = RegQueryValueEx(hSecKey, (LPTSTR)lpszEntry, NULL, &dwType,
				*ppData, &dwCount);
		}
		if (lResult == ERROR_SUCCESS)
		{
			ASSERT(dwType == REG_BINARY);
			return TRUE;
		}
		else
		{
			delete [] *ppData;
			*ppData = NULL;
		}
		return FALSE;
	}
	else
	{
		ASSERT(m_pszProfileName != NULL);

		CString str = GetProfileString(lpszSection, lpszEntry, NULL);
		if (str.IsEmpty())
			return FALSE;
		ASSERT(str.GetLength()%2 == 0);
		INT_PTR nLen = str.GetLength();
		*pBytes = UINT(nLen)/2;
		*ppData = new BYTE[*pBytes];
		for (int i=0;i<nLen;i+=2)
		{
			(*ppData)[i/2] = (BYTE)
				(((str[i+1] - 'A') << 4) + (str[i] - 'A'));
		}
		return TRUE;
	}
}


BOOL CWinApp::WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry,
	int nValue)
{
	ASSERT(lpszSection != NULL);
	ASSERT(lpszEntry != NULL);
	if (m_pszRegistryKey != NULL)
	{
		HKEY hSecKey = GetSectionKey(lpszSection);
		if (hSecKey == NULL)
			return FALSE;
		LONG lResult = RegSetValueEx(hSecKey, lpszEntry, NULL, REG_DWORD,
			(LPBYTE)&nValue, sizeof(nValue));
		RegCloseKey(hSecKey);
		return lResult == ERROR_SUCCESS;
	}
	else
	{
		ASSERT(m_pszProfileName != NULL);

		TCHAR szT[16];
		_stprintf_s(szT, _countof(szT), _T("%d"), nValue);
		return ::WritePrivateProfileString(lpszSection, lpszEntry, szT,
			m_pszProfileName);
	}
}

BOOL CWinApp::WriteProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
			LPCTSTR lpszValue)
{
	ASSERT(lpszSection != NULL);
	if (m_pszRegistryKey != NULL)
	{
		LONG lResult;
		if (lpszEntry == NULL) //delete whole section
		{
			HKEY hAppKey = GetAppRegistryKey();
			if (hAppKey == NULL)
				return FALSE;
			lResult = ::RegDeleteKey(hAppKey, lpszSection);
			RegCloseKey(hAppKey);
		}
		else if (lpszValue == NULL)
		{
			HKEY hSecKey = GetSectionKey(lpszSection);
			if (hSecKey == NULL)
				return FALSE;
			// necessary to cast away const below
			lResult = ::RegDeleteValue(hSecKey, (LPTSTR)lpszEntry);
			RegCloseKey(hSecKey);
		}
		else
		{
			HKEY hSecKey = GetSectionKey(lpszSection);
			if (hSecKey == NULL)
				return FALSE;
			lResult = RegSetValueEx(hSecKey, lpszEntry, NULL, REG_SZ,
				(LPBYTE)lpszValue, (static_cast<DWORD>(_tcslen(lpszValue))+1)*sizeof(TCHAR));
			RegCloseKey(hSecKey);
		}
		return lResult == ERROR_SUCCESS;
	}
	else
	{
		ASSERT(m_pszProfileName != NULL);
		ASSERT(AtlStrLen(m_pszProfileName) < 4095); // can't read in bigger
		return ::WritePrivateProfileString(lpszSection, lpszEntry, lpszValue,
			m_pszProfileName);
	}
}

BOOL CWinApp::WriteProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
	LPBYTE pData, UINT nBytes)
{
	ASSERT(lpszSection != NULL);
	if (m_pszRegistryKey != NULL)
	{
		LONG lResult;
		HKEY hSecKey = GetSectionKey(lpszSection);
		if (hSecKey == NULL)
			return FALSE;
		lResult = RegSetValueEx(hSecKey, lpszEntry, NULL, REG_BINARY,
			pData, nBytes);
		RegCloseKey(hSecKey);
		return lResult == ERROR_SUCCESS;
	}

	// convert to string and write out
	LPTSTR lpsz = new TCHAR[nBytes*2+1];
	UINT i;
	for (i = 0; i < nBytes; i++)
	{
		lpsz[i*2] = (TCHAR)((pData[i] & 0x0F) + 'A'); //low nibble
		lpsz[i*2+1] = (TCHAR)(((pData[i] >> 4) & 0x0F) + 'A'); //high nibble
	}
	lpsz[i*2] = 0;

	ASSERT(m_pszProfileName != NULL);

	BOOL bResult = WriteProfileString(lpszSection, lpszEntry, lpsz);
	delete[] lpsz;
	return bResult;
}

BOOL CWinApp::EnableTaskbarInteraction(BOOL bEnable) 
{
	if(AfxGetMainWnd() != NULL)
	{
		ASSERT(FALSE);
		TRACE0("Windows 7 taskbar interacrion must be called before creation of main window.\n");
		return FALSE;
	}

	m_bTaskbarInteractionEnabled = bEnable;
	return TRUE;
}

BOOL CWinApp::IsTaskbarInteractionEnabled() 
{ 
	return m_bIsWindows7 && m_bTaskbarInteractionEnabled; 
}

BOOL CWinApp::IsWindows7() 
{ 
	return m_bIsWindows7; 
}

BOOL CWinApp::EnableD2DSupport(D2D1_FACTORY_TYPE d2dFactoryType, DWRITE_FACTORY_TYPE writeFactoryType)
{
	_AFX_D2D_STATE* pD2DState = AfxGetD2DState();
	if (pD2DState == NULL)
	{
		return FALSE;
	}

	if (pD2DState->IsD2DInitialized())
	{
		ASSERT(FALSE);
		TRACE0("D2D is already initialized. Please call this method before creation of main window\n");
		return FALSE;
	}

	return pD2DState->InitD2D(d2dFactoryType, writeFactoryType);
}

ITaskbarList* CWinApp::GetITaskbarList()
{
	HRESULT hr = S_OK;

	if (!m_bIsWindows7 || !m_bTaskbarInteractionEnabled)
	{
		return NULL;
	}

	if (m_pTaskbarList != NULL)
	{
		return static_cast<ITaskbarList*>(m_pTaskbarList);
	}

	if (!m_bComInitialized)
	{
		hr = CoInitialize(NULL);
		if (SUCCEEDED(hr))
		{
			m_bComInitialized = TRUE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, __uuidof(ITaskbarList), reinterpret_cast<void**>(&m_pTaskbarList));
	}

	ASSERT(SUCCEEDED(hr));
	return static_cast<ITaskbarList*>(m_pTaskbarList);
}

ITaskbarList3* CWinApp::GetITaskbarList3()
{
	HRESULT hr = S_OK;

	if (!m_bIsWindows7 || !m_bTaskbarInteractionEnabled)
	{
		return NULL;
	}

	if (m_pTaskbarList3 != NULL)
	{
		return static_cast<ITaskbarList3*>(m_pTaskbarList3);
	}

	if (!m_bComInitialized)
	{
		hr = CoInitialize(NULL);
		if (SUCCEEDED(hr))
		{
			m_bComInitialized = TRUE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, __uuidof(ITaskbarList3), reinterpret_cast<void**>(&m_pTaskbarList3));
	}

	ASSERT(SUCCEEDED(hr));
	return static_cast<ITaskbarList3*>(m_pTaskbarList3);
}

void CWinApp::ReleaseTaskBarRefs()
{
	m_bTaskbarInteractionEnabled = FALSE;

	if (m_pTaskbarList != NULL)
	{
		RELEASE(m_pTaskbarList);
		m_pTaskbarList = NULL;
	}

	if (m_pTaskbarList3 != NULL)
	{
		RELEASE(m_pTaskbarList3);
		m_pTaskbarList3 = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
