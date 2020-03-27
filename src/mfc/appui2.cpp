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



/////////////////////////////////////////////////////////////////////////////
// DDE and ShellExecute support

BOOL CWinApp::ProcessShellCommand(CCommandLineInfo& rCmdInfo)
{
	BOOL bResult = TRUE;
	switch (rCmdInfo.m_nShellCommand)
	{
	case CCommandLineInfo::RestartByRestartManager:
		// Re-register with the restart manager using the restart identifier from the command line
		RegisterWithRestartManager(SupportsApplicationRecovery(), rCmdInfo.m_strRestartIdentifier);

		// Call RestartIntance, which should reopen any previously opened document(s) and
		// optionally load the autosaved versions after querying the user about loading.
		if (RestartInstance())
			break;
		// If RestartInstance returns FALSE, then fall through to FileNew case, so
		// a new document is created--otherwise the main frame will not be created.

	case CCommandLineInfo::FileNew:
		if (!AfxGetApp()->OnCmdMsg(ID_FILE_NEW, 0, NULL, NULL))
			OnFileNew();
		if (m_pMainWnd == NULL)
			bResult = FALSE;
		break;

	// If we've been asked to open a file, call OpenDocumentFile()
	case CCommandLineInfo::FileOpen:
		if (!OpenDocumentFile(rCmdInfo.m_strFileName))
			bResult = FALSE;
		break;

	// If the user wanted to print, hide our main window and
	// fire a message to ourselves to start the printing
	case CCommandLineInfo::FilePrintTo:
	case CCommandLineInfo::FilePrint:
		m_nCmdShow = SW_HIDE;
		ASSERT(m_pCmdInfo == NULL);
		if(OpenDocumentFile(rCmdInfo.m_strFileName))
		{
			m_pCmdInfo = &rCmdInfo;
			ENSURE_VALID(m_pMainWnd);
			m_pMainWnd->SendMessage(WM_COMMAND, ID_FILE_PRINT_DIRECT);
			m_pCmdInfo = NULL;
		}
		bResult = FALSE;
		break;

	// If we're doing DDE print or print to, start up without a new document and hide ourselves
	case CCommandLineInfo::FileDDENoShow:
		m_pCmdInfo = (CCommandLineInfo*)(UINT_PTR)m_nCmdShow;
		m_nCmdShow = SW_HIDE;
		break;

	// If we're doing DDE open, start up without a new document, but don't hide ourselves -- this causes the
	// icon in the Windows 7 taskbar to start in the wrong position and slide into the right position.
	case CCommandLineInfo::FileDDE:
		break;

	// If we've been asked to register, exit without showing UI.
	// Registration was already done in InitInstance().
	case CCommandLineInfo::AppRegister:
		{
			Register();			
			bResult = FALSE;    // that's all we do

			// If nobody is using it already, we can use it.
			// We'll flag that we're unregistering and not save our state
			// on the way out. This new object gets deleted by the
			// app object destructor.

			if (m_pCmdInfo == NULL)
			{
				m_pCmdInfo = new CCommandLineInfo;
				m_pCmdInfo->m_nShellCommand = CCommandLineInfo::AppUnregister;
			}
			break;
		}

	// If we've been asked to unregister, unregister and then terminate
	case CCommandLineInfo::AppUnregister:
		{
			BOOL bUnregistered = Unregister();

			if (!rCmdInfo.m_bRunEmbedded)
			{
				if (bUnregistered)
					AfxMessageBox(AFX_IDP_UNREG_DONE);
				else
					AfxMessageBox(AFX_IDP_UNREG_FAILURE);
			}
			bResult = FALSE;    // that's all we do

			// If nobody is using it already, we can use it.
			// We'll flag that we're unregistering and not save our state
			// on the way out. This new object gets deleted by the
			// app object destructor.

			if (m_pCmdInfo == NULL)
			{
				m_pCmdInfo = new CCommandLineInfo;
				m_pCmdInfo->m_nShellCommand = CCommandLineInfo::AppUnregister;
			}
		}
		break;
	}
	return bResult;
}

void CWinApp::InitLibId()
{
}

BOOL CWinApp::Register()
{
	return TRUE;
}

BOOL CWinApp::Unregister()
{
	HKEY    hKey = 0;
	TCHAR   szBuf[_MAX_PATH+1];
	LONG    cSize = 0;
	BOOL    bRet = TRUE;

	POSITION pos = GetFirstDocTemplatePosition();
	while (pos != NULL)
	{
		CDocTemplate* pTempl = GetNextDocTemplate(pos);
		if (pTempl != NULL)
			pTempl->OnCmdMsg(0, CN_OLE_UNREGISTER, NULL, NULL);
	}

	// Remove profile information -- the registry entries exist if
	// SetRegistryKey() was used.

	if (m_pszRegistryKey)
	{
		ENSURE(m_pszProfileName != NULL);

		CString strKey = _T("Software\\");
		strKey += m_pszRegistryKey;
		CString strSubKey = strKey + _T("\\") + m_pszProfileName;

		DelRegTree(HKEY_CURRENT_USER, strSubKey);

		// If registry key is empty then remove it

		DWORD   dwResult;
		if ((dwResult = ::RegOpenKeyEx(HKEY_CURRENT_USER, strKey, 0, KEY_ENUMERATE_SUB_KEYS, &hKey)) ==
			ERROR_SUCCESS)
		{
			if (::RegEnumKey(hKey, 0, szBuf, _MAX_PATH) == ERROR_NO_MORE_ITEMS)
				DelRegTree(HKEY_CURRENT_USER, strKey);
			::RegCloseKey(hKey);
		}
		if (RegQueryValue(HKEY_CURRENT_USER, strSubKey, szBuf, &cSize) == ERROR_SUCCESS)
			bRet = TRUE;
	}
	return bRet;
}

// Under Win32, a reg key may not be deleted unless it is empty.
// Thus, to delete a tree,  one must recursively enumerate and
// delete all of the sub-keys.

LONG CWinApp::DelRegTree(HKEY hParentKey, const CString& strKeyName, CAtlTransactionManager* pTM)
{
	return AfxDelRegTreeHelper(hParentKey, strKeyName, pTM);
}

LONG AFXAPI AfxDelRegTreeHelper(HKEY hParentKey, const CString& strKeyName, CAtlTransactionManager* pTM)
{
	TCHAR   szSubKeyName[MAX_PATH + 1];
	HKEY    hCurrentKey;
	DWORD   dwResult;

	CString strRedirectedKeyName = strKeyName;
	if( ( HKEY_CLASSES_ROOT == hParentKey ) && ( TRUE == AfxGetPerUserRegistration() ) )
	{
		strRedirectedKeyName = _T("Software\\Classes\\") + strRedirectedKeyName;
		hParentKey = HKEY_CURRENT_USER;
	}

	dwResult = pTM != NULL ? 
		pTM->RegOpenKeyEx(hParentKey, strRedirectedKeyName, 0, KEY_WRITE | KEY_READ, &hCurrentKey) : 
		::RegOpenKeyEx(hParentKey, strRedirectedKeyName, 0, KEY_WRITE | KEY_READ, &hCurrentKey);
	if (dwResult == ERROR_SUCCESS)
	{
		// Remove all subkeys of the key to delete
		while ((dwResult = RegEnumKey(hCurrentKey, 0, szSubKeyName, MAX_PATH)) == ERROR_SUCCESS)
		{
			try
			{
				// temp CString constructed from szSubKeyName can throw in Low Memory condition.
				if ((dwResult = AfxDelRegTreeHelper(hCurrentKey, szSubKeyName, pTM)) != ERROR_SUCCESS)
					break;
			}
			catch(CMemoryException* e)
			{
				dwResult = ERROR_NOT_ENOUGH_MEMORY;
				e->Delete();
				break;
			}
		}

		// If all went well, we should now be able to delete the requested key
		if ((dwResult == ERROR_NO_MORE_ITEMS) || (dwResult == ERROR_BADKEY))
		{
			dwResult = pTM != NULL ? 
				pTM->RegDeleteKey(hParentKey, strRedirectedKeyName) :
				::RegDeleteKey(hParentKey, strRedirectedKeyName);
		}
		RegCloseKey(hCurrentKey);
	}

	return dwResult;
}

void CWinApp::EnableShellOpen()
{
	ASSERT(m_atomApp == NULL && m_atomSystemTopic == NULL); // do once
	if (m_atomApp != NULL || m_atomSystemTopic != NULL)
	{
		return;
	}

	CString strShortName;
	AfxGetModuleFileName(AfxGetInstanceHandle(), strShortName);

	// strip out path
	CString strFileName = ::PathFindFileName(strShortName);
	// strip out extension
	LPTSTR pszFileName = strFileName.GetBuffer();
	::PathRemoveExtension(pszFileName);
	strFileName.ReleaseBuffer();

	m_atomApp = ::GlobalAddAtom(strFileName);
	m_atomSystemTopic = ::GlobalAddAtom(_T("system"));
}

void CWinApp::RegisterShellFileTypes(BOOL bCompat)
{
	ENSURE(m_pDocManager != NULL);
	m_pDocManager->RegisterShellFileTypes(bCompat);
}

void CWinApp::UnregisterShellFileTypes()
{
	ENSURE(m_pDocManager != NULL);
	m_pDocManager->UnregisterShellFileTypes();
}


int CWinApp::GetOpenDocumentCount()
{
	ENSURE(m_pDocManager != NULL);
	return m_pDocManager->GetOpenDocumentCount();
}

/////////////////////////////////////////////////////////////////////////////
// Doc template support


void CWinApp::AddDocTemplate(CDocTemplate* pTemplate)
{
	if (m_pDocManager == NULL)
		m_pDocManager = new CDocManager;
	m_pDocManager->AddDocTemplate(pTemplate);
}

POSITION CWinApp::GetFirstDocTemplatePosition() const
{
	if (m_pDocManager == NULL)
		return NULL;
	return m_pDocManager->GetFirstDocTemplatePosition();
}

CDocTemplate* CWinApp::GetNextDocTemplate(POSITION& rPosition) const
{
	ENSURE(m_pDocManager != NULL);
	return m_pDocManager->GetNextDocTemplate(rPosition);
}

/////////////////////////////////////////////////////////////////////////////
