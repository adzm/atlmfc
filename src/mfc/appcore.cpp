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
#include "sal.h"

#include "afxdatarecovery.h"

#ifdef _AFXDLL
#include "afxglobals.h"
#endif

AFX_STATIC_DATA const TCHAR _afxFileSection[] = _T("Recent File List");
AFX_STATIC_DATA const TCHAR _afxFileEntry[] = _T("File%d");
AFX_STATIC_DATA const TCHAR _afxPreviewSection[] = _T("Settings");
AFX_STATIC_DATA const TCHAR _afxPreviewEntry[] = _T("PreviewPages");

/////////////////////////////////////////////////////////////////////////////
// globals (internal library use)

// CDocManager statics are in this file for granularity reasons
BOOL CDocManager::bStaticInit = TRUE;
CDocManager* CDocManager::pStaticDocManager = NULL;
CPtrList* CDocManager::pStaticList = NULL;

BEGIN_MESSAGE_MAP(CWinApp, CCmdTarget)
	// Global File commands
	ON_COMMAND(ID_APP_EXIT, &CWinApp::OnAppExit)
	// MRU - most recently used file menu
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_FILE1, &CWinApp::OnUpdateRecentFileMenu)
	ON_COMMAND_EX_RANGE(ID_FILE_MRU_FILE1, ID_FILE_MRU_FILE16, &CWinApp::OnOpenRecentFile)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// _AFX_WIN_STATE implementation


static HINSTANCE _AfxLoadLangDLL(LPCWSTR pszFormat, LPCWSTR pszPath, LPCWSTR pwzLocaleName)
{
	WCHAR szLangDLL[_MAX_PATH+14];
	WCHAR szLangCode[4];
	HINSTANCE hInstance = NULL;
	int nResult = _AfxGetLocaleInfoEx(pwzLocaleName, LOCALE_SABBREVLANGNAME, szLangCode, 4);
	if (nResult == 0)
	{
		return NULL;
	}
	ASSERT(nResult == 4);

	int ret;
	ATL_CRT_ERRORCHECK_SPRINTF(ret = _snwprintf_s(szLangDLL, _countof(szLangDLL), _countof(szLangDLL) - 1, pszFormat, pszPath, szLangCode));
	if (ret == -1 || ret >= _countof(szLangDLL))
	{
		ASSERT(FALSE);
		return NULL;
	}

	hInstance = ::LoadLibraryExW(szLangDLL, NULL, LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE | LOAD_LIBRARY_AS_IMAGE_RESOURCE);

	if (hInstance == NULL)
	{
		// if library load failed using flags only valid on Vista+, fall back to using flags valid on XP
		hInstance = ::LoadLibraryExW(szLangDLL, NULL, LOAD_LIBRARY_AS_DATAFILE);
	}

	return hInstance;
}

static HINSTANCE _AfxLoadLocDLL(LPCWSTR pszFormat, LPCWSTR pszPath)
{
	WCHAR szLangDLL[_MAX_PATH+14];
	HINSTANCE hInstance = NULL;

	int ret;
	ATL_CRT_ERRORCHECK_SPRINTF(ret = _snwprintf_s(szLangDLL, _countof(szLangDLL), _countof(szLangDLL) - 1, pszFormat, pszPath, L"LOC"));
	if (ret == -1 || ret >= _countof(szLangDLL))
	{
		ASSERT(FALSE);
		return NULL;
	}

	hInstance = ::LoadLibraryExW(szLangDLL, NULL, LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE | LOAD_LIBRARY_AS_IMAGE_RESOURCE);

	if (hInstance == NULL)
	{
		// if library load failed using flags only valid on Vista+, fall back to using flags valid on XP
		hInstance = ::LoadLibraryExW(szLangDLL, NULL, LOAD_LIBRARY_AS_DATAFILE);
	}

	return hInstance;
}

HINSTANCE AFXAPI _AfxLoadLangDLLFromList(LPCWSTR pszFormat, LPCWSTR pszPath, LPWSTR pszLanguageList)
{
	HINSTANCE hLangDLL = NULL;
	WCHAR *pwz = pszLanguageList;
	while (*pwz != 0)
	{
		// Load the resource DLL using the language names.
		hLangDLL = _AfxLoadLangDLL(pszFormat, pszPath, pwz);
		if(hLangDLL != NULL)
		{
			return hLangDLL;
		}
		pwz += wcslen(pwz) + 1;  // move to next ID in list
	}

	return NULL;
}

static BOOL CALLBACK _AfxEnumResLangProc(HMODULE /*hModule*/, LPCTSTR /*pszType*/, 
	LPCTSTR /*pszName*/, WORD langid, LONG_PTR lParam)
{
	if(lParam == NULL)
		return FALSE;
		
	LANGID* plangid = reinterpret_cast< LANGID* >( lParam );
	*plangid = langid;

	return TRUE;
}

// HINSTANCE of the module
extern "C" IMAGE_DOS_HEADER __ImageBase;
BOOL g_fLoadingResourcesForMFCDLL = FALSE;

const int nMaxExpectedPreferredLangs = 20;

HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat, LPCTSTR pszPath)
{
	CStringW strFormat = pszFormat;
	CStringW strPath = pszPath;

	// load language specific DLL
	HINSTANCE hLangDLL = NULL;

	// Get the thread preferred UI languages using the language names
	BOOL bGotPreferredLangs = FALSE;
	ULONG nLanguages, cchLanguagesBuffer;
	WCHAR wszLanguages[(6 * nMaxExpectedPreferredLangs) + 1] = {0}; // each lang has five chars plus NULL, plus terminating NULL

	nLanguages = 0;
	cchLanguagesBuffer = _countof(wszLanguages);
	bGotPreferredLangs = _AfxGetThreadPreferredUILanguages(MUI_LANGUAGE_NAME | MUI_UI_FALLBACK, &nLanguages, wszLanguages, &cchLanguagesBuffer);
	if (bGotPreferredLangs)
	{
		// Load the resource DLL using the language names.
		hLangDLL = _AfxLoadLangDLLFromList(strFormat, strPath, wszLanguages);
		if (hLangDLL != NULL)
		{
			return hLangDLL;
		}
	}

	if (!g_fLoadingResourcesForMFCDLL)
	{
		// Attempt to load a "LOC" resource DLL.
		hLangDLL = _AfxLoadLocDLL(strFormat, strPath);
		if(hLangDLL != NULL)
		{
			return hLangDLL;
		}
	}

	return NULL;
}

HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat)
{
	TCHAR pszNewFormat[MAX_PATH + 2 + 1] = _T("%s"); // have space for %s and string terminator
	ENSURE(AtlStrLen(pszFormat) <= MAX_PATH);
	_tcscat_s (pszNewFormat, _countof(pszNewFormat), pszFormat);
	return AfxLoadLangResourceDLL(pszNewFormat, _T(""));
}

CWinApp::CWinApp(LPCTSTR lpszAppName)
{
	if (lpszAppName != NULL)
		m_pszAppName = _tcsdup(lpszAppName);
	else
		m_pszAppName = NULL;

	// initialize CWinThread state
	AFX_MODULE_STATE* pModuleState = _AFX_CMDTARGET_GETSTATE();
	ENSURE(pModuleState);
	AFX_MODULE_THREAD_STATE* pThreadState = pModuleState->m_thread;
	ENSURE(pThreadState);
	ASSERT(AfxGetThread() == NULL);
	pThreadState->m_pCurrentWinThread = this;
	ASSERT(AfxGetThread() == this);
	m_hThread = ::GetCurrentThread();
	m_nThreadID = ::GetCurrentThreadId();

	// initialize CWinApp state
	ASSERT(afxCurrentWinApp == NULL); // only one CWinApp object please
	pModuleState->m_pCurrentWinApp = this;
	ASSERT(AfxGetApp() == this);

	// in non-running state until WinMain
	m_hInstance = NULL;
	m_hLangResourceDLL = NULL;
	m_pszHelpFilePath = NULL;
	m_pszProfileName = NULL;
	m_pszRegistryKey = NULL;
	m_pszExeName = NULL;
	m_pszAppID = NULL;
	m_pRecentFileList = NULL;
	m_pDocManager = NULL;
	m_atomApp = m_atomSystemTopic = NULL;
	m_lpCmdLine = NULL;
	m_pCmdInfo = NULL;
	m_pDataRecoveryHandler = NULL;

	// initialize wait cursor state
	m_nWaitCursorCount = 0;
	m_hcurWaitCursorRestore = NULL;

	// initialize current printer state
	m_hDevMode = NULL;
	m_hDevNames = NULL;
	m_nNumPreviewPages = 0;     // not specified (defaults to 1)

	// initialize DAO state
	m_lpfnDaoTerm = NULL;   // will be set if AfxDaoInit called

	// other initialization
	m_bHelpMode = FALSE;
	m_eHelpType = afxWinHelp;
	m_nSafetyPoolSize = 512;        // default size

	m_dwRestartManagerSupportFlags = 0;    // don't support Restart Manager by default
	m_nAutosaveInterval = 5 * 60 * 1000;   // default autosave interval is 5 minutes (only has effect if autosave flag is set)

	m_bTaskbarInteractionEnabled = TRUE;

	// Detect the kind of OS:
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx(&osvi);

	m_bIsWindows7 = (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 1) || (osvi.dwMajorVersion > 6);

	// Taskbar initialization:
	m_bComInitialized = FALSE;

	m_pTaskbarList = NULL;
	m_pTaskbarList3 = NULL;
	m_bTaskBarInterfacesAvailable = TRUE;
}

BOOL CWinApp::LoadSysPolicies() 
{
	return _LoadSysPolicies();
}

// This function is not exception safe - will leak a registry key if exceptions are thrown from some places
// To reduce risk of leaks, I've declared the whole function throw(). This despite the fact that its callers have
// no dependency on non-throwing.
BOOL CWinApp::_LoadSysPolicies() throw()
{
	HKEY hkPolicy = NULL;
	DWORD dwValue = 0;
	DWORD dwDataLen = sizeof(dwValue);
	DWORD dwType = 0;

	// clear current policy settings.
	m_dwPolicies = _AFX_SYSPOLICY_NOTINITIALIZED;

	static _AfxSysPolicyData rgExplorerData[] = 
	{
		{_T("NoRun"), _AFX_SYSPOLICY_NORUN},
		{_T("NoDrives"), _AFX_SYSPOLICY_NODRIVES},
		{_T("RestrictRun"), _AFX_SYSPOLICY_RESTRICTRUN},
		{_T("NoNetConnectDisconnect"), _AFX_SYSPOLICY_NONETCONNECTDISCONNECTD},
		{_T("NoRecentDocsHistory"), _AFX_SYSPOLICY_NORECENTDOCHISTORY},
		{_T("NoClose"), _AFX_SYSPOLICY_NOCLOSE},
		{NULL, NULL}
	};

	static _AfxSysPolicyData rgNetworkData[] = 
	{
		{_T("NoEntireNetwork"), _AFX_SYSPOLICY_NOENTIRENETWORK},
		{NULL, NULL}
	};

	static _AfxSysPolicyData rgComDlgData[] = 
	{
		{_T("NoPlacesBar"), _AFX_SYSPOLICY_NOPLACESBAR},
		{_T("NoBackButton"), _AFX_SYSPOLICY_NOBACKBUTTON},
		{_T("NoFileMru"), _AFX_SYSPOLICY_NOFILEMRU},
		{NULL, NULL}
	};

	static _AfxSysPolicies rgPolicies[] = 
	{
		{_T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"),
			rgExplorerData},
		{_T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network"),
			rgNetworkData},
		{_T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Comdlg32"),
			rgComDlgData},
		{NULL, NULL}
	};

	_AfxSysPolicies *pPolicies = rgPolicies;
	_AfxSysPolicyData *pData = NULL;

	while (pPolicies->szPolicyKey != NULL)
	{

		if (ERROR_SUCCESS == ::RegOpenKeyEx(
					HKEY_CURRENT_USER,
					pPolicies->szPolicyKey,
					NULL,
					KEY_QUERY_VALUE,
					&hkPolicy
					))
		{
			pData = pPolicies->pData;
			while (pData->szPolicyName)
			{
				if (ERROR_SUCCESS == ::RegQueryValueEx(
									 hkPolicy,
									 pData->szPolicyName,
									 NULL,
									 &dwType,
									 (BYTE*)&dwValue,
									 &dwDataLen))
				{
					if (dwType == REG_DWORD)
					{
						if (dwValue != 0)
							m_dwPolicies |= pData->dwID;
						else
							m_dwPolicies &= ~pData->dwID;
					}
				}
				dwValue = 0;
				dwDataLen = sizeof(dwValue);
				dwType = 0;
				pData++;
			}
			::RegCloseKey(hkPolicy);
			hkPolicy = NULL;
		}
		pPolicies++;
	};
	return TRUE;
}

BOOL CWinApp::GetSysPolicyValue(DWORD dwPolicyID, BOOL *pbValue)
{
	if (!pbValue)
		return FALSE; // bad pointer
	*pbValue = (m_dwPolicies & dwPolicyID) != 0;
	return TRUE;
}

BOOL CWinApp::InitApplication()
{
	if (CDocManager::pStaticDocManager != NULL)
	{
		if (m_pDocManager == NULL)
			m_pDocManager = CDocManager::pStaticDocManager;
		CDocManager::pStaticDocManager = NULL;
	}

	if (m_pDocManager != NULL)
		m_pDocManager->AddDocTemplate(NULL);
	else
		CDocManager::bStaticInit = FALSE;

	LoadSysPolicies();

	return TRUE;
}

BOOL CWinApp::InitInstance()
{
	InitLibId();
	m_hLangResourceDLL = LoadAppLangResourceDLL();
	if(m_hLangResourceDLL != NULL)
	{
		AfxSetResourceHandle(m_hLangResourceDLL);
		_AtlBaseModule.SetResourceInstance(m_hLangResourceDLL);
	}

	// Register the application with the Restart Manager, if supported.
	if (SupportsRestartManager())
	{
		RegisterWithRestartManager(SupportsApplicationRecovery(), _T(""));
	}

	// If the application is linked statically to MFC, then cleanup of the globals
	// does not need to be reference counted.  Otherwise, we need to make sure that
	// the last CWinApp to exit does the cleanup of all the globals.

#ifdef _AFXDLL
	AfxGlobalsAddRef();
#endif

	return TRUE;
}

HINSTANCE CWinApp::LoadAppLangResourceDLL()
{
	TCHAR szPath[MAX_PATH];
	LPTSTR pszExtension;

	int ret = ::GetModuleFileName(m_hInstance, szPath, MAX_PATH);
	if(ret == 0 || ret == MAX_PATH)
	{
		ASSERT(FALSE);
		return NULL;
	}
	pszExtension = ::PathFindExtension(szPath);
	*pszExtension = '\0';

	TCHAR szFormat[] = _T("%s%s.dll");

	return AfxLoadLangResourceDLL(szFormat, szPath);
}

void CWinApp::LoadStdProfileSettings(UINT nMaxMRU)
{
	ASSERT_VALID(this);
	ASSERT(m_pRecentFileList == NULL);

	BOOL bNoRecentDocs = FALSE;
	GetSysPolicyValue(_AFX_SYSPOLICY_NORECENTDOCHISTORY, &bNoRecentDocs);
	if (nMaxMRU != 0 && !bNoRecentDocs )
	{
		// create file MRU since nMaxMRU not zero
		m_pRecentFileList = new CRecentFileList(0, _afxFileSection, _afxFileEntry,
			nMaxMRU);
		m_pRecentFileList->ReadList();
	}
	// 0 by default means not set
	m_nNumPreviewPages = GetProfileInt(_afxPreviewSection, _afxPreviewEntry, 0);
}

void CWinApp::ParseCommandLine(CCommandLineInfo& rCmdInfo)
{
	for (int i = 1; i < __argc; i++)
	{
		LPCTSTR pszParam = __targv[i];
		BOOL bFlag = FALSE;
		BOOL bLast = ((i + 1) == __argc);
		if (pszParam[0] == '-' || pszParam[0] == '/')
		{
			// remove flag specifier
			bFlag = TRUE;
			++pszParam;
		}
		rCmdInfo.ParseParam(pszParam, bFlag, bLast);
	}
}

BOOL CWinApp::RestartInstance()
{
	BOOL bRet = FALSE;

	CDataRecoveryHandler *pHandler = GetDataRecoveryHandler();
	if (pHandler)
	{
		// First read the set of previously opened documents (and associated autosaves) from the registry.
		// ReadOpenDocumentList will return TRUE only if at least one document name was read.
		if (pHandler->ReadOpenDocumentList())
		{
			// Then reopen the previously opened documents (handler will check whether this is enabled).
			bRet = pHandler->ReopenPreviousDocuments();

			// Finally restore the the associated autosaves (handler will check whether this is enabled and query user).
			pHandler->RestoreAutosavedDocuments();
		}
	}

	// Return TRUE if any documents were opened, else return FALSE to indicate
	// that a new document should be opened as in the normal startup scenario.
	return bRet;
}

/////////////////////////////////////////////////////////////////////////////
// CCommandLineInfo implementation

#define RESTART_COMMAND_LINE_ARG "RestartByRestartManager"  // command-line argument used when restarting the application
#define RESTART_IDENTIFIER_LEN   36                         // length of restart identifier (GUID) used when restarting

CCommandLineInfo::CCommandLineInfo()
{
	m_bShowSplash = TRUE;
	m_bRunEmbedded = FALSE;
	m_bRunAutomated = FALSE;
	m_bRegisterPerUser = FALSE;
	m_nShellCommand = FileNew;
}

CCommandLineInfo::~CCommandLineInfo()
{
}

void CCommandLineInfo::ParseParam(const TCHAR* pszParam,BOOL bFlag,BOOL bLast)
{
	if (bFlag)
	{
		const CStringA strParam(pszParam);
		ParseParamFlag(strParam.GetString());
	}
	else
		ParseParamNotFlag(pszParam);

	ParseLast(bLast);
}

#ifdef UNICODE
void CCommandLineInfo::ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
{
	if (bFlag)
		ParseParamFlag(pszParam);
	else
		ParseParamNotFlag(pszParam);

	ParseLast(bLast);
}
#endif // UNICODE

void CCommandLineInfo::ParseParamFlag(const char* pszParam)
{
	// OLE command switches are case insensitive, while
	// shell command switches are case sensitive

	if (lstrcmpA(pszParam, "pt") == 0)
		m_nShellCommand = FilePrintTo;
	else if (lstrcmpA(pszParam, "p") == 0)
		m_nShellCommand = FilePrint;
	else if (::AfxInvariantStrICmp(pszParam, "Register") == 0 ||
		::AfxInvariantStrICmp(pszParam, "Regserver") == 0)
		m_nShellCommand = AppRegister;
	else if (::AfxInvariantStrICmp(pszParam, "RegisterPerUser") == 0 ||
		::AfxInvariantStrICmp(pszParam, "RegserverPerUser") == 0)
	{
		m_nShellCommand = AppRegister;
		m_bRegisterPerUser = TRUE;
	}
	else if (::AfxInvariantStrICmp(pszParam, "Unregister") == 0 ||
		::AfxInvariantStrICmp(pszParam, "Unregserver") == 0)
		m_nShellCommand = AppUnregister;
	else if (::AfxInvariantStrICmp(pszParam, "UnregisterPerUser") == 0 ||
		::AfxInvariantStrICmp(pszParam, "UnregserverPerUser") == 0)
	{
		m_nShellCommand = AppUnregister;
		m_bRegisterPerUser = TRUE;
	}
	else if (_strnicmp(pszParam, RESTART_COMMAND_LINE_ARG, _countof(RESTART_COMMAND_LINE_ARG) - 1) == 0)
	{
		CString strParam = pszParam;
		if (strParam.GetLength() == _countof(RESTART_COMMAND_LINE_ARG) + RESTART_IDENTIFIER_LEN)
		{
			m_nShellCommand = RestartByRestartManager;
			m_strRestartIdentifier = strParam.Right(RESTART_IDENTIFIER_LEN);
		}
	}
	else if (lstrcmpA(pszParam, "ddenoshow") == 0)
	{
		AfxOleSetUserCtrl(FALSE);
		m_nShellCommand = FileDDENoShow;
	}
	else if (lstrcmpA(pszParam, "dde") == 0)
	{
		AfxOleSetUserCtrl(FALSE);
		m_nShellCommand = FileDDE;
	}
	else if (::AfxInvariantStrICmp(pszParam, "Embedding") == 0)
	{
		AfxOleSetUserCtrl(FALSE);
		m_bRunEmbedded = TRUE;
		m_bShowSplash = FALSE;
	}
	else if (::AfxInvariantStrICmp(pszParam, "Automation") == 0)
	{
		AfxOleSetUserCtrl(FALSE);
		m_bRunAutomated = TRUE;
		m_bShowSplash = FALSE;
	}
}

void CCommandLineInfo::ParseParamNotFlag(const TCHAR* pszParam)
{
	if (m_strFileName.IsEmpty())
		m_strFileName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strPrinterName.IsEmpty())
		m_strPrinterName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strDriverName.IsEmpty())
		m_strDriverName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strPortName.IsEmpty())
		m_strPortName = pszParam;
}

#ifdef UNICODE
void CCommandLineInfo::ParseParamNotFlag(const char* pszParam)
{
	if (m_strFileName.IsEmpty())
		m_strFileName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strPrinterName.IsEmpty())
		m_strPrinterName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strDriverName.IsEmpty())
		m_strDriverName = pszParam;
	else if (m_nShellCommand == FilePrintTo && m_strPortName.IsEmpty())
		m_strPortName = pszParam;
}
#endif

void CCommandLineInfo::ParseLast(BOOL bLast)
{
	if (bLast)
	{
		if (m_nShellCommand == FileNew && !m_strFileName.IsEmpty())
			m_nShellCommand = FileOpen;
		m_bShowSplash = !m_bRunEmbedded && !m_bRunAutomated;
	}
}

/////////////////////////////////////////////////////////////////////////////
// App termination

CWinApp::~CWinApp()
{
	AFX_BEGIN_DESTRUCTOR

	ReleaseTaskBarRefs();

	if (m_bComInitialized)
	{
		CoUninitialize();
		m_bComInitialized = FALSE;
	}

	// free doc manager
	if (m_pDocManager != NULL)
		delete m_pDocManager;

	// free recent file list
	if (m_pRecentFileList != NULL)
		delete m_pRecentFileList;

	// free data recovery handler
	if (m_pDataRecoveryHandler != NULL)
		delete m_pDataRecoveryHandler;

	// free static list of document templates
	if (!afxContextIsDLL)
	{
		if (CDocManager::pStaticList != NULL)
		{
			delete CDocManager::pStaticList;
			CDocManager::pStaticList = NULL;
		}
		if (CDocManager::pStaticDocManager != NULL)
		{
			delete CDocManager::pStaticDocManager;
			CDocManager::pStaticDocManager = NULL;
		}
	}

	// free printer info
	if (m_hDevMode != NULL)
		AfxGlobalFree(m_hDevMode);
	if (m_hDevNames != NULL)
		AfxGlobalFree(m_hDevNames);

	// free atoms if used
	if (m_atomApp != NULL)
		::GlobalDeleteAtom(m_atomApp);
	if (m_atomSystemTopic != NULL)
		::GlobalDeleteAtom(m_atomSystemTopic);

	// free cached commandline
	if (m_pCmdInfo != NULL)
		delete m_pCmdInfo;

	// cleanup module state
	AFX_MODULE_STATE* pModuleState = _AFX_CMDTARGET_GETSTATE();
	if (pModuleState->m_lpszCurrentAppName == m_pszAppName)
		pModuleState->m_lpszCurrentAppName = NULL;
	if (pModuleState->m_pCurrentWinApp == this)
		pModuleState->m_pCurrentWinApp = NULL;

	// free various strings allocated with _tcsdup
	free((void*)m_pszAppName);
	free((void*)m_pszRegistryKey);
	free((void*)m_pszExeName);
	free((void*)m_pszHelpFilePath);
	free((void*)m_pszProfileName);

	// avoid calling CloseHandle() on our own thread handle
	// during the CWinThread destructor
	m_hThread = NULL;
	AFX_END_DESTRUCTOR
}

void CWinApp::SaveStdProfileSettings()
{
	ASSERT_VALID(this);

	if (m_pRecentFileList != NULL)
		m_pRecentFileList->WriteList();

	if (m_nNumPreviewPages != 0)
		WriteProfileInt(_afxPreviewSection, _afxPreviewEntry, m_nNumPreviewPages);
}

int CWinApp::ExitInstance()
{
	// if we remember that we're unregistering,
	// don't save our profile settings

	if (m_pCmdInfo == NULL ||
		(m_pCmdInfo->m_nShellCommand != CCommandLineInfo::AppUnregister &&
		 m_pCmdInfo->m_nShellCommand != CCommandLineInfo::AppRegister))
	{
		if (!afxContextIsDLL)
			SaveStdProfileSettings();
	}

	// If the application is linked statically to MFC, then cleanup of the globals
	// does not need to be reference counted.  Otherwise, we need to make sure that
	// the last CWinApp to exit does the cleanup of all the globals.

#ifdef _AFXDLL
	AfxGlobalsRelease();
#endif

	// Release any references to D2D
	AfxReleaseD2DRefs();

	// Cleanup DAO if necessary
	if (m_lpfnDaoTerm != NULL)
	{
		// If a DLL, YOU must call AfxDaoTerm prior to ExitInstance
		ASSERT(!afxContextIsDLL);
		(*m_lpfnDaoTerm)();
	}

	if (m_hLangResourceDLL != NULL)
	{
		::FreeLibrary(m_hLangResourceDLL);
		m_hLangResourceDLL = NULL;
	}

	int nReturnValue=0;
	if(AfxGetCurrentMessage())
	{
		nReturnValue=static_cast<int>(AfxGetCurrentMessage()->wParam);
	}
	
	return nReturnValue; // returns the value from PostQuitMessage
}

/////////////////////////////////////////////////////////////////////////////


// Main running routine until application exits
int CWinApp::Run()
{
	if (m_pMainWnd == NULL && AfxOleGetUserCtrl())
	{
		// Not launched /Embedding or /Automation, but has no main window!
		TRACE(traceAppMsg, 0, "Warning: m_pMainWnd is NULL in CWinApp::Run - quitting application.\n");
		AfxPostQuitMessage(0);
	}
	return CWinThread::Run();
}


void AFXAPI AfxPostQuitMessage(int nExitCode)
{
	// cleanup OLE libraries
	CWinThread* pThread = AfxGetThread();
	if (pThread != NULL && pThread->m_lpfnOleTermOrFreeLib != NULL)
		(*pThread->m_lpfnOleTermOrFreeLib)(TRUE, TRUE);

	::PostQuitMessage(nExitCode);
}

/////////////////////////////////////////////////////////////////////////////
// WinHelp Helper


void CWinApp::WinHelp(DWORD_PTR dwData, UINT nCmd)
{
	CWnd* pMainWnd = AfxGetMainWnd();
	ENSURE_VALID(pMainWnd);

	// return global app help mode state to FALSE (backward compatibility)
	m_bHelpMode = FALSE;
	pMainWnd->PostMessage(WM_KICKIDLE); // trigger idle update

	pMainWnd->WinHelp(dwData, nCmd);
}

/////////////////////////////////////////////////////////////////////////////
// HtmlHelp Helper

void CWinApp::HtmlHelp(DWORD_PTR dwData, UINT nCmd)
{
	CWnd* pMainWnd = AfxGetMainWnd();
	ENSURE_VALID(pMainWnd);

	// return global app help mode state to FALSE (backward compatibility)
	m_bHelpMode = FALSE;
	pMainWnd->PostMessage(WM_KICKIDLE); // trigger idle update

	pMainWnd->HtmlHelp(dwData, nCmd);
}

void CWinApp::WinHelpInternal(DWORD_PTR dwData, UINT nCmd)
{
	CWnd* pMainWnd = AfxGetMainWnd();
	ENSURE_VALID(pMainWnd);

	// return global app help mode state to FALSE (backward compatibility)
	m_bHelpMode = FALSE;
	pMainWnd->PostMessage(WM_KICKIDLE); // trigger idle update
	pMainWnd->WinHelpInternal(dwData, nCmd);
}

/////////////////////////////////////////////////////////////////////////////
// Restart Manager support

// Restart Manager is only supported on Vista+, so we dynamically load the exports we need
typedef HRESULT (WINAPI *PFNREGISTERAPPLICATIONRESTART)(PCWSTR, DWORD);
typedef HRESULT (WINAPI *PFNREGISTERAPPLICATIONRECOVERYCALLBACK)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD);
typedef HRESULT (WINAPI *PFNAPPLICATIONRECOVERYINPROGRESS)(PBOOL);
typedef VOID    (WINAPI *PFNAPPLICATIONRECOVERYFINISHED)(BOOL);

DWORD WINAPI AfxApplicationRecoveryWrapper(LPVOID lpvParam)
{
	DWORD dwRet = 0;
	CWinApp *pApp = AfxGetApp();
	if (pApp != NULL)
	{
		ASSERT_VALID(pApp);
		dwRet = pApp->ApplicationRecoveryCallback(lpvParam);
	}

	return dwRet;
}

HRESULT CWinApp::RegisterWithRestartManager(BOOL bRegisterRecoveryCallback, const CString &strRestartIdentifierParam)
{
	// This method may be called twice.  It will be called from CWinApp::InitInstance with an empty restart identifier string,
	// and a new restart identifier string will be generated.  It may then be called from CWinApp::ProcessShellCommand with the
	// restart identifier string that was passed in on the command line, if the application was restarted by the Restart Manager.

	// The restart identifier is the key name where the list of documents is stored in the registry.
	// It is unique per application instance.

	HRESULT hr = S_OK;
	CString strCommandLineArgs, strCommandLineArgsAppend, strRestartIdentifier = strRestartIdentifierParam;

	// Generate the unique ID for the restart information for this instance
	if (strRestartIdentifier.IsEmpty())
	{
		GUID guidRestartIdentifier = GUID_NULL;
		CoCreateGuid(&guidRestartIdentifier);

		CString strGuid;
		strRestartIdentifier.Format(_T("%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X"),
			guidRestartIdentifier.Data1, guidRestartIdentifier.Data2, guidRestartIdentifier.Data3,
			guidRestartIdentifier.Data4[0], guidRestartIdentifier.Data4[1], guidRestartIdentifier.Data4[2], guidRestartIdentifier.Data4[3],
			guidRestartIdentifier.Data4[4], guidRestartIdentifier.Data4[5], guidRestartIdentifier.Data4[6], guidRestartIdentifier.Data4[7]);
	}

	// Set up the command line to be used if the Restart Manager restarts this instance
	strCommandLineArgs = m_lpCmdLine;

	strCommandLineArgsAppend += _T(RESTART_COMMAND_LINE_ARG);
	strCommandLineArgsAppend += _T(":");
	strCommandLineArgsAppend += strRestartIdentifier;

	// If this instance of the application was restarted, then the command line already
	// contains the restart command line arguments, so they do not need to be appended.
	if (strCommandLineArgs.Find(strCommandLineArgsAppend, 0) == -1)
	{
		strCommandLineArgs += _T(" /");
		strCommandLineArgs += strCommandLineArgsAppend;
	}

	// Create the data recovery handler
	CDataRecoveryHandler *pHandler = GetDataRecoveryHandler();
	if (pHandler != NULL)
	{
		pHandler->SetRestartIdentifier(strRestartIdentifier);
	}

	if (bRegisterRecoveryCallback)
	{
		hr = RegisterWithRestartManager(CComBSTR(strCommandLineArgs), GetApplicationRestartFlags(), AfxApplicationRecoveryWrapper, GetApplicationRecoveryParameter(), GetApplicationRecoveryPingInterval(), 0);
	}
	else
	{
		hr = RegisterWithRestartManager(CComBSTR(strCommandLineArgs), GetApplicationRestartFlags(), NULL, NULL, 0, 0);
	}

	return hr;
}

HRESULT CWinApp::RegisterWithRestartManager(LPCWSTR pwzCommandLineArgs, DWORD dwRestartFlags, APPLICATION_RECOVERY_CALLBACK pRecoveryCallback, LPVOID lpvParam, DWORD dwPingInterval, DWORD dwCallbackFlags)
{
	HRESULT hr = S_OK;

	// Register for restart by the Restart Manager (component update scenario)
	// Note that according to MSDN, UnregisterApplicationRestart does not need to be called on normal
	// application shutdown, but only if the application for some reason can no longer be restarted.
	hr = _AfxRegisterApplicationRestart(pwzCommandLineArgs, dwRestartFlags);
	if (hr != S_OK)
	{
		return hr;
	}

	if (pRecoveryCallback != NULL)
	{
		// Register for application recovery (application hang or crash scenario)
		// Note that according to MSDN, UnregisterApplicationRecoveryCallback does not need to be called on normal
		// application shutdown, but only if the application for some reason can no longer do recovery.
		hr = _AfxRegisterApplicationRecoveryCallback(pRecoveryCallback, lpvParam, dwPingInterval, dwCallbackFlags);
		if (hr != S_OK)
		{
			return hr;
		}
	}

	return S_OK;
}

DWORD CWinApp::ApplicationRecoveryCallback(LPVOID /* lpvParam */)
{
	// To change this behavior, either override CWinApp::ApplicationRecoveryCallback or
	// call CWinApp::RegisterWithRestartManager using your own recovery callback function.

	// ApplicationRecoveryInProgress must be called before the ping interval has elapsed. The ping interval
	// is set via the dwPingInterval parameter in the call to RegisterApplicationRecoveryCallback above.
	BOOL bRecoveryCanceled = FALSE;
	HRESULT hr = _AfxApplicationRecoveryInProgress(&bRecoveryCanceled);
	if (FAILED(hr) || bRecoveryCanceled)
	{
		// Recovery has been canceled, so terminate the application.
		return 0;
	}

	BOOL bRecoverySuccessful = TRUE;
	CDataRecoveryHandler *pHandler = GetDataRecoveryHandler();
	if (pHandler)
	{
		// Save the list of open documents to the registry.  Since an exception has already
		// occurred, we do as little as possible here, so we don't do any document autosaves.
		bRecoverySuccessful = pHandler->SaveOpenDocumentList();
	}

	// Once recovery is complete, call ApplicationRecoveryFinished so the Restart Manager can restart the app.
	_AfxApplicationRecoveryFinished(bRecoverySuccessful);

	return 0;
}

CDataRecoveryHandler *CWinApp::GetDataRecoveryHandler()
{
	static BOOL bTriedOnce = FALSE;

	// Since the application restart and application recovery are supported only on Windows
	// Vista and above, we don't need a recovery handler on Windows versions less than Vista.
	if (SupportsRestartManager() || SupportsApplicationRecovery())
	{
		if (!bTriedOnce && m_pDataRecoveryHandler == NULL)
		{
			m_pDataRecoveryHandler = new CDataRecoveryHandler(m_dwRestartManagerSupportFlags, m_nAutosaveInterval);
			if (!m_pDataRecoveryHandler->Initialize())
			{
				delete m_pDataRecoveryHandler;
				m_pDataRecoveryHandler = NULL;
			}
		}
	}

	bTriedOnce = TRUE;
	return m_pDataRecoveryHandler;
}

/////////////////////////////////////////////////////////////////////////////
// Special exception handling

LRESULT CWinApp::ProcessWndProcException(CException* e, const MSG* pMsg)
{
	ENSURE_ARG(e != NULL);
	ENSURE_ARG(pMsg != NULL);
	// handle certain messages in CWinThread
	switch (pMsg->message)
	{
	case WM_CREATE:
	case WM_PAINT:
		return CWinThread::ProcessWndProcException(e, pMsg);
	}

	// handle all the rest
	UINT nIDP = AFX_IDP_INTERNAL_FAILURE;   // generic message string
	LRESULT lResult = 0;        // sensible default
	if (pMsg->message == WM_COMMAND)
	{
		if ((HWND)pMsg->lParam == NULL)
			nIDP = AFX_IDP_COMMAND_FAILURE; // command (not from a control)
		lResult = (LRESULT)TRUE;        // pretend the command was handled
	}
	if (e->IsKindOf(RUNTIME_CLASS(CMemoryException)))
	{
		e->ReportError(MB_ICONEXCLAMATION|MB_SYSTEMMODAL, nIDP);
	}
	else if (!e->IsKindOf(RUNTIME_CLASS(CUserException)))
	{
		// user has not been alerted yet of this catastrophic problem
		e->ReportError(MB_ICONSTOP, nIDP);
	}
	return lResult; // sensible default return from most WndProc functions
}

/////////////////////////////////////////////////////////////////////////////
// CWinApp idle processing

BOOL CWinApp::OnIdle(LONG lCount)
{
	if (lCount <= 0)
	{
		CWinThread::OnIdle(lCount);

		// call doc-template idle hook
		POSITION pos = NULL;
		if (m_pDocManager != NULL)
			pos = m_pDocManager->GetFirstDocTemplatePosition();

		while (pos != NULL)
		{
			CDocTemplate* pTemplate = m_pDocManager->GetNextDocTemplate(pos);
			ASSERT_KINDOF(CDocTemplate, pTemplate);
			// if auto-save is enabled, the auto-save will be performed in the
			// document's OnIdle method, called from the template's OnIdle method
			pTemplate->OnIdle();
		}

		CDataRecoveryHandler *pHandler = GetDataRecoveryHandler();
		if (pHandler)
		{
			// clear the auto-save on idle flag--it will be set
			// again the next time the auto-save timer ticks.
			pHandler->SetSaveDocumentInfoOnIdle(FALSE);
		}
	}
	else if (lCount == 1)
	{
		VERIFY(!CWinThread::OnIdle(lCount));
	}
	return lCount < 1;  // more to do if lCount < 1
}

/////////////////////////////////////////////////////////////////////////////
// CWinApp idle processing

void CWinApp::DevModeChange(_In_z_ LPTSTR lpDeviceName)
{
	if (m_hDevNames == NULL)
		return;

	LPDEVNAMES lpDevNames = (LPDEVNAMES)::GlobalLock(m_hDevNames);
	ASSERT(lpDevNames != NULL);
	if (lstrcmp((LPCTSTR)lpDevNames + lpDevNames->wDeviceOffset,
		lpDeviceName) == 0)
	{
		HANDLE hPrinter;
		if (!OpenPrinter(lpDeviceName, &hPrinter, NULL))
			return;

		// DEVMODE changed for the current printer
		if (m_hDevMode != NULL)
			AfxGlobalFree(m_hDevMode);

		// A zero for last param returns the size of buffer needed.
		int nSize = DocumentProperties(NULL, hPrinter, lpDeviceName,
			NULL, NULL, 0);
		ASSERT(nSize >= 0);
		m_hDevMode = GlobalAlloc(GHND, nSize);
		LPDEVMODE lpDevMode = (LPDEVMODE)GlobalLock(m_hDevMode);

		// Fill in the rest of the structure.
		if (DocumentProperties(NULL, hPrinter, lpDeviceName, lpDevMode,
			NULL, DM_OUT_BUFFER) != IDOK)
		{
			AfxGlobalFree(m_hDevMode);
			m_hDevMode = NULL;
		}
		ClosePrinter(hPrinter);
	}
}

///////////////////////////////////////////////////////////////////////////
// CWinApp diagnostics

#ifdef _DEBUG
void CWinApp::AssertValid() const
{
	CWinThread::AssertValid();

	ASSERT(afxCurrentWinApp == this);
	ASSERT(afxCurrentInstanceHandle == m_hInstance);

	if (AfxGetThread() != (CWinThread*)this)
		return;     // only do subset if called from different thread

	if (m_pDocManager != NULL)
		ASSERT_VALID(m_pDocManager);
}

void CWinApp::Dump(CDumpContext& dc) const
{
	CWinThread::Dump(dc);

	dc << "m_hInstance = " << (void*)m_hInstance;
	dc << "\nm_lpCmdLine = " << m_lpCmdLine;
	dc << "\nm_nCmdShow = " << m_nCmdShow;
	dc << "\nm_pszAppName = " << m_pszAppName;
	dc << "\nm_bHelpMode = " << m_bHelpMode;
	dc << "\nm_pszExeName = " << m_pszExeName;
	dc << "\nm_pszHelpFilePath = " << m_pszHelpFilePath;
	dc << "\nm_pszProfileName = " << m_pszProfileName;
	dc << "\nm_hDevMode = " << (void*)m_hDevMode;
	dc << "\nm_hDevNames = " << (void*)m_hDevNames;
	dc << "\nm_dwPromptContext = " << m_dwPromptContext;
	dc << "\nm_eHelpType = " << m_eHelpType;

	if (m_pRecentFileList != NULL)
	{
		dc << "\nm_strRecentFiles[] = ";
		int nSize = m_pRecentFileList->GetSize();
		for (int i = 0; i < nSize; i++)
		{
			if ((*m_pRecentFileList)[i].GetLength() != 0)
				dc << "\n\tFile: " << (*m_pRecentFileList)[i];
		}
	}

	if (m_pDocManager != NULL)
		m_pDocManager->Dump(dc);

	dc << "\nm_nWaitCursorCount = " << m_nWaitCursorCount;
	dc << "\nm_hcurWaitCursorRestore = " << (void*)m_hcurWaitCursorRestore;
	dc << "\nm_nNumPreviewPages = " << m_nNumPreviewPages;

	_AFX_THREAD_STATE* pState = AfxGetThreadState();
	dc << "\nm_msgCur = {";
	dc << "\n\thwnd = " << (void*)pState->m_msgCur.hwnd;
	dc << "\n\tmessage = " << (UINT)pState->m_msgCur.message;
	dc << "\n\twParam = " << (UINT)pState->m_msgCur.wParam;
	dc << "\n\tlParam = " << (void*)pState->m_msgCur.lParam;
	dc << "\n\ttime = " << pState->m_msgCur.time;
	dc << "\n\tpt = " << CPoint(pState->m_msgCur.pt);
	dc << "\n}";

	dc << "\n";
}
#endif


IMPLEMENT_DYNAMIC(CWinApp, CWinThread)

#pragma warning(disable: 4074)
#pragma init_seg(lib)

PROCESS_LOCAL(_AFX_WIN_STATE, _afxWinState)

/////////////////////////////////////////////////////////////////////////////
///////
///////
