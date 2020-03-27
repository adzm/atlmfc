// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "StdAfx.h"

#include "Common.h"
#include "AtlTraceModuleManager.h"
#include "sal.h"

namespace ATL
{
static bool WINAPI ShouldTraceOutput(
	_In_ DWORD_PTR dwModule,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel,
	_Deref_out_opt_ const CAtlTraceCategory **ppCategory,
	_Deref_out_opt_ CAtlTraceModule::fnCrtDbgReport_t *pfnCrtDbgReport);

void WINAPI NotifyTool()
{
	HANDLE hEvent;
	hEvent = OpenEventA(EVENT_MODIFY_STATE, FALSE, g_pszUpdateEventName);

	if(hEvent)
	{
		SetEvent(hEvent);
		CloseHandle(hEvent);
	}
}

// API
DWORD_PTR __stdcall AtlTraceRegister(
	_In_ HINSTANCE hInst,
	_In_opt_ int (__cdecl *fnCrtDbgReport)(
		_In_ int,
		_In_z_ const char *,
		_In_ int,
		_In_z_ const char *,
		_In_z_ const char *,...))
{
	int iModule = g_Allocator.AddModule(hInst);
	CAtlTraceModule* pModule = g_Allocator.GetModule(iModule);
	ATLASSERT(pModule != NULL);
	if(pModule != NULL)
	{
		pModule->CrtDbgReport(fnCrtDbgReport);
		NotifyTool();
	}

	return( DWORD_PTR( iModule )+1 );
}

BOOL __stdcall AtlTraceUnregister(_In_ DWORD_PTR dwModule)
{
	int iModule = int( dwModule-1 );
	g_Allocator.RemoveModule( iModule );

	NotifyTool();

	return TRUE;
}

DWORD_PTR __stdcall AtlTraceRegisterCategoryA(
	_In_ DWORD_PTR dwModule,
	_In_z_count_c_(ATL_TRACE_MAX_NAME_SIZE) const CHAR szCategoryName[ATL_TRACE_MAX_NAME_SIZE])
{
	if( szCategoryName == NULL )
	{
		return 0;
	}
	return AtlTraceRegisterCategoryU(dwModule, CA2W(szCategoryName));
}

DWORD_PTR __stdcall AtlTraceRegisterCategoryU(
	_In_ DWORD_PTR dwModule,
	_In_z_count_c_(ATL_TRACE_MAX_NAME_SIZE) const WCHAR szCategoryName[ATL_TRACE_MAX_NAME_SIZE])
{
	if( szCategoryName == NULL )
		return 0;

	int iModule = int( dwModule-1 );

	int iCategory = g_Allocator.AddCategory(iModule, szCategoryName);
	NotifyTool();

	return( DWORD_PTR( iCategory )+1 );
}

BOOL __stdcall AtlTraceModifyProcess(
	_In_ DWORD_PTR dwProcess,
	_In_ UINT nLevel,
	_In_ BOOL bEnabled,
	_In_ BOOL bFuncAndCategoryNames,
	_In_ BOOL bFileNameAndLineNo)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	CAtlTraceProcess* pProcess = pAllocator->GetProcess();
	ATLASSERT(pProcess != NULL);
	if(pProcess != NULL)
	{
		pProcess->m_nLevel = nLevel;
		pProcess->m_bEnabled = 0 != bEnabled;
		pProcess->m_bFuncAndCategoryNames = 0 != bFuncAndCategoryNames;
		pProcess->m_bFileNameAndLineNo = 0 != bFileNameAndLineNo;
	}

	return( TRUE );
}

BOOL __stdcall AtlTraceModifyModule(
	_In_ DWORD_PTR dwProcess,
	_In_ DWORD_PTR dwModule,
	_In_ UINT nLevel,
	_In_ ATLTRACESTATUS eStatus)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	int iModule = int( dwModule-1 );

	CAtlTraceModule* pModule = pAllocator->GetModule(iModule);
	ATLASSERT(pModule != NULL);
	if(pModule != NULL)
	{
		switch(eStatus)
		{
		case ATLTRACESTATUS_INHERIT:
			pModule->m_eStatus = CAtlTraceSettings::Inherit;
			break;
		case ATLTRACESTATUS_ENABLED:
			pModule->m_eStatus = CAtlTraceSettings::Enabled;
			break;
		case ATLTRACESTATUS_DISABLED:
			pModule->m_eStatus = CAtlTraceSettings::Disabled;
			break;
		default:
			ATLASSERT( false );
			break;
		}
		pModule->m_nLevel = nLevel;
	}

	return( TRUE );
}

BOOL __stdcall AtlTraceModifyCategory(
	_In_ DWORD_PTR dwProcess,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel,
	_In_ ATLTRACESTATUS eStatus)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	int iCategory = int( dwCategory-1 );
	CAtlTraceCategory *pCategory = pAllocator->GetCategory(iCategory);
	if(pCategory != NULL)
	{
		switch(eStatus)
		{
		case ATLTRACESTATUS_INHERIT:
			pCategory->m_eStatus = CAtlTraceSettings::Inherit;
			break;
		case ATLTRACESTATUS_ENABLED:
			pCategory->m_eStatus = CAtlTraceSettings::Enabled;
			break;
		case ATLTRACESTATUS_DISABLED:
			pCategory->m_eStatus = CAtlTraceSettings::Disabled;
			break;
		default:
			ATLASSERT(false);
			break;
		}
		pCategory->m_nLevel = nLevel;
	}
	return TRUE;
}

BOOL __stdcall AtlTraceGetProcess(
	_In_ DWORD_PTR dwProcess,
	_Out_opt_ UINT *pnLevel,
	_Out_opt_ BOOL *pbEnabled,
	_Out_opt_ BOOL *pbFuncAndCategoryNames,
	_Out_opt_ BOOL *pbFileNameAndLineNo)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	CAtlTraceProcess* pProcess = pAllocator->GetProcess();
	ATLENSURE(pProcess != NULL);

	if(pnLevel)
		*pnLevel = pProcess->m_nLevel;
	if(pbEnabled)
		*pbEnabled = pProcess->m_bEnabled;
	if(pbFuncAndCategoryNames)
		*pbFuncAndCategoryNames = pProcess->m_bFuncAndCategoryNames;
	if(pbFileNameAndLineNo)
		*pbFileNameAndLineNo = pProcess->m_bFileNameAndLineNo;

	return( TRUE );
}

BOOL __stdcall AtlTraceGetModule(
	_In_ DWORD_PTR dwProcess,
	_In_ DWORD_PTR dwModule,
	_Out_opt_ UINT *pnLevel,
	_Out_opt_ ATLTRACESTATUS *peStatus)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	int iModule = int( dwModule-1 );
	CAtlTraceModule *pModule = pAllocator->GetModule(iModule);
	ATLENSURE(pModule != NULL);

	if(pnLevel != NULL)
	{
		*pnLevel = pModule->m_nLevel;
	}

	if(peStatus != NULL)
	{
		switch(pModule->m_eStatus)
		{
		case CAtlTraceSettings::Inherit:
			*peStatus = ATLTRACESTATUS_INHERIT;
			break;
		case CAtlTraceSettings::Enabled:
			*peStatus = ATLTRACESTATUS_ENABLED;
			break;
		case CAtlTraceSettings::Disabled:
			*peStatus = ATLTRACESTATUS_DISABLED;
			break;
		default:
			ATLASSERT(false);
			break;
		}
	}

	return TRUE;
}

BOOL __stdcall AtlTraceGetCategory(
	_In_ DWORD_PTR dwProcess,
	_In_ DWORD_PTR dwCategory,
	_Out_opt_ UINT *pnLevel,
	_Out_opt_ ATLTRACESTATUS *peStatus)
{
	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
#ifdef _DEBUG
	if( pAllocator == NULL )
	{
		pAllocator = &g_Allocator;
	}
#endif  // _DEBUG

	int iCategory = int( dwCategory-1 );
	CAtlTraceCategory* pCategory = pAllocator->GetCategory( iCategory );
	ATLENSURE(pCategory != NULL);

	if(pnLevel != NULL)
	{
		*pnLevel = pCategory->m_nLevel;
	}

	if(peStatus != NULL)
	{
		switch(pCategory->m_eStatus)
		{
		case CAtlTraceSettings::Inherit:
			*peStatus = ATLTRACESTATUS_INHERIT;
			break;
		case CAtlTraceSettings::Enabled:
			*peStatus = ATLTRACESTATUS_ENABLED;
			break;
		case CAtlTraceSettings::Disabled:
			*peStatus = ATLTRACESTATUS_DISABLED;
			break;
		}
	}

	return( TRUE );
}

void __stdcall AtlTraceGetUpdateEventNameA(_Inout_z_ CHAR *pszEventName)
{
	if( g_pszUpdateEventName == NULL || pszEventName == NULL )
	{
		return;
	}
#pragma warning(push)
#pragma warning(disable:4996)
	// This API is deprecated because the size of the buffer cannot be
	// known. Therefore, we have to use unsafe version of strcpy. The
	// warning is disabled to prevent build problems.
	strcpy(pszEventName, g_pszUpdateEventName);
#pragma warning(pop)
}

void __stdcall AtlTraceGetUpdateEventNameA_s(
	_Out_z_cap_(cchEventName) CHAR *pszEventName,
	_In_ size_t cchEventName)
{
	if( g_pszUpdateEventName == NULL || pszEventName == NULL )
	{
		return;
	}
	Checked::strcpy_s(pszEventName, cchEventName, g_pszUpdateEventName);
}

void __stdcall AtlTraceGetUpdateEventNameU(_Inout_z_ WCHAR *pszEventName)
{
	if( g_pszUpdateEventName == NULL || pszEventName == NULL )
	{
		return;
	}
#pragma warning(push)
#pragma warning(disable:4996)
	// This API is deprecated because the size of the buffer cannot be
	// known. Therefore, we have to use unsafe version of wcscpy. The
	// warning is disabled to prevent build problems.
	wcscpy(pszEventName, CA2W(g_pszUpdateEventName));
#pragma warning(pop)
}

void __stdcall AtlTraceGetUpdateEventNameU_s(
	_Out_z_cap_(cchEventName) WCHAR *pszEventName,
	_In_ size_t cchEventName)
{
	if( g_pszUpdateEventName == NULL || pszEventName == NULL )
	{
		return;
	}
	Checked::wcscpy_s(pszEventName, cchEventName, CA2W(g_pszUpdateEventName));
}

void __cdecl AtlTraceVA(
	_In_ DWORD_PTR dwModule,
	_In_opt_z_ const char *pszFileName,
	_In_ int nLine,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel,
	_In_z_ _Printf_format_string_ const CHAR *pszFormat, 
	_In_ va_list ptr)
{
	const CAtlTraceCategory *pCategory;
	CAtlTraceModule::fnCrtDbgReport_t pfnCrtDbgReport = NULL;
	static const int nCount = 1024;
	CHAR szBuf[nCount] = {'\0'};
	int nLen = 0;

	if(ShouldTraceOutput(dwModule, dwCategory, nLevel, &pCategory, &pfnCrtDbgReport))
	{
		if (nLen >= 0 && nLen < nCount)
                {
                        if(g_Allocator.GetProcess()->m_bFileNameAndLineNo)
		        {
			        int nTemp;
			        ATL_CRT_ERRORCHECK_SPRINTF(nTemp = _snprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, "%s(%d) : ", pszFileName, nLine));
			        if( nTemp < 0 )
				        nLen = nCount;
			        else
				        nLen += nTemp;
		        }
                }
		if (nLen >= 0 && nLen < nCount)
                {
		        if(pCategory && g_Allocator.GetProcess()->m_bFuncAndCategoryNames)
		        {
			        int nTemp;
			        ATL_CRT_ERRORCHECK_SPRINTF(nTemp = _snprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, "%S: ", pCategory->Name()));
			        if( nTemp < 0 )
				        nLen = nCount;
			        else
				        nLen += nTemp;
		        }
                }
		if (nLen >= 0 && nLen < nCount)
		{
			ATL_CRT_ERRORCHECK_SPRINTF(_vsnprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, pszFormat, ptr));
		}

		if(pfnCrtDbgReport != NULL)
			pfnCrtDbgReport(_CRT_WARN, NULL, 0, NULL, "%s", szBuf);
		else
			OutputDebugStringA(szBuf);
	}
}

void __cdecl AtlTraceVU(
	_In_ DWORD_PTR dwModule,
	_In_opt_z_ const char *pszFileName,
	_In_ int nLine,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel,
	_In_z_ _Printf_format_string_ const WCHAR *pszFormat, 
	_In_ va_list ptr)
{
	const CAtlTraceCategory *pCategory;
	CAtlTraceModule::fnCrtDbgReport_t pfnCrtDbgReport = NULL;
	const int nCount = 1024;
	WCHAR szBuf[nCount] = {L'\0'};
	int nLen = 0;

	if(ShouldTraceOutput(dwModule, dwCategory, nLevel, &pCategory, &pfnCrtDbgReport))
	{
		if (nLen >= 0 && nLen < nCount)
                {
                        if(g_Allocator.GetProcess()->m_bFileNameAndLineNo && nLen < nCount && nLen >= 0)
		        {
			        int nTemp;
			        ATL_CRT_ERRORCHECK_SPRINTF(nTemp = _snwprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, L"%S(%d) : ", pszFileName, nLine));
			        if( nTemp < 0 )
				        nLen = nCount;
			        else
				        nLen += nTemp;
		        }
                }
		if (nLen >= 0 && nLen < nCount)
                {
                        if(pCategory && g_Allocator.GetProcess()->m_bFuncAndCategoryNames)
		        {
			        int nTemp;
			        ATL_CRT_ERRORCHECK_SPRINTF(nTemp = _snwprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, L"%s: ", pCategory->Name()));
			        if( nTemp < 0 )
				        nLen = nCount;
			        else
				        nLen += nTemp;
		        }

                }
		if (nLen >= 0 && nLen < nCount)
		{
			ATL_CRT_ERRORCHECK_SPRINTF(_vsnwprintf_s(szBuf + nLen, nCount - nLen, nCount - nLen - 1, pszFormat, ptr));
		}

		if(pfnCrtDbgReport)
			pfnCrtDbgReport(_CRT_WARN, NULL, 0, NULL, "%S", szBuf);
		else
			OutputDebugStringW(szBuf);
	}
}

DWORD_PTR __stdcall AtlTraceOpenProcess(_In_ DWORD idProcess)
{
	CAtlAllocator* pAllocator = new CAtlAllocator;

	char szBuf[64];
	ATL_CRT_ERRORCHECK_SPRINTF(_snprintf_s(szBuf, _countof(szBuf), _countof(szBuf) - 1, g_pszKernelObjFmt, g_pszAllocFileMapName, idProcess));
	if( !pAllocator->Open(szBuf) )
	{
		delete pAllocator;
		return( 0 );
	}

	return( reinterpret_cast< DWORD_PTR >( pAllocator ) );
}

void __stdcall AtlTraceCloseProcess(_In_ DWORD_PTR dwProcess)
{
	ATLENSURE(dwProcess!=0);

	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
	pAllocator->Close( true );
	delete pAllocator;
}

void __stdcall AtlTraceSnapshotProcess(_In_ DWORD_PTR dwProcess)
{
	ATLENSURE(dwProcess!=0);

	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
	pAllocator->TakeSnapshot();
}

BOOL __stdcall AtlTraceGetProcessInfo(
	_In_ DWORD_PTR dwProcess,
	_Out_ ATLTRACEPROCESSINFO* pProcessInfo)
{
	ATLENSURE(dwProcess!=0);
	ATLASSERT(pProcessInfo != NULL);

	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
	ATLASSERT(pAllocator->m_bSnapshot);
	CAtlTraceProcess *pProcess = pAllocator->GetProcess();
	ATLASSERT(pProcess != NULL);

	if(pProcess)
	{
		wcsncpy_s(pProcessInfo->szName, _countof(pProcessInfo->szName), pProcess->Name(), _TRUNCATE);
		wcscpy_s(pProcessInfo->szPath, _countof(pProcessInfo->szPath), pProcess->Path());
		pProcessInfo->dwId = pProcess->Id();
		pProcessInfo->settings.nLevel = pProcess->m_nLevel;
		pProcessInfo->settings.bEnabled = pProcess->m_bEnabled;
		pProcessInfo->settings.bFuncAndCategoryNames = pProcess->m_bFuncAndCategoryNames;
		pProcessInfo->settings.bFileNameAndLineNo = pProcess->m_bFileNameAndLineNo;
		pProcessInfo->nModules = pAllocator->m_snapshot.m_aModules.GetSize();
	}
	return( TRUE );
}

void __stdcall AtlTraceGetModuleInfo(
	_In_ DWORD_PTR dwProcess,
	_In_ int iModule,
	_Out_ ATLTRACEMODULEINFO* pModuleInfo)
{
	ATLENSURE(dwProcess!=0);
	ATLASSERT(pModuleInfo != NULL);
	if( pModuleInfo == NULL )
		return;

	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
	ATLASSERT(pAllocator->m_bSnapshot);

	DWORD_PTR dwModule = pAllocator->m_snapshot.m_aModules[iModule].m_dwModule;
	CAtlTraceModule* pModule = pAllocator->GetModule(int(dwModule-1));
	if( pModule == NULL )
		return;

	wcsncpy_s(pModuleInfo->szName, _countof(pModuleInfo->szName), pModule->Name(), _TRUNCATE);
	wcsncpy_s(pModuleInfo->szPath, _countof(pModuleInfo->szPath), pModule->Path(), _TRUNCATE);
	pModuleInfo->nCategories = pModule->m_nCategories;
	pModuleInfo->settings.nLevel = pModule->m_nLevel;
	pModuleInfo->dwModule = dwModule;
	switch(pModule->m_eStatus)
	{
	default:
	case CAtlTraceSettings::Inherit:
		pModuleInfo->settings.eStatus = ATLTRACESTATUS_INHERIT;
		break;
	case CAtlTraceSettings::Enabled:
		pModuleInfo->settings.eStatus = ATLTRACESTATUS_ENABLED;
		break;
	case CAtlTraceSettings::Disabled:
		pModuleInfo->settings.eStatus = ATLTRACESTATUS_DISABLED;
		break;
	}
}

void __stdcall AtlTraceGetCategoryInfo(
	_In_ DWORD_PTR dwProcess,
	_In_ DWORD_PTR dwModule,
	_In_ int iCategory,
	_Out_ ATLTRACECATEGORYINFO* pCategoryInfo)
{
	ATLENSURE(dwProcess!=0);
	ATLASSERT(pCategoryInfo != NULL);

	CAtlAllocator* pAllocator = reinterpret_cast< CAtlAllocator* >( dwProcess );
	ATLASSERT(pAllocator->m_bSnapshot);

	int iModule = int( dwModule-1 );
	CAtlTraceModule* pModule = pAllocator->GetModule( iModule );
	if( pModule == NULL )
		return;

	CAtlTraceCategory* pCategory = pAllocator->GetCategory( pModule->m_iFirstCategory );

	int nCategory = pModule->m_iFirstCategory;
	for( int iCategoryIndex = 0; iCategoryIndex < iCategory; iCategoryIndex++ )
	{
		if( pCategory == NULL )
			return;
		nCategory = pCategory->m_iNextCategory;
		pCategory = pAllocator->GetCategory( pCategory->m_iNextCategory );
	}

	if( pCategory == NULL )
		return;

	wcsncpy_s(pCategoryInfo->szName, _countof(pCategoryInfo->szName), pCategory->Name(), _TRUNCATE);
	pCategoryInfo->settings.nLevel = pCategory->m_nLevel;
	pCategoryInfo->dwCategory = DWORD_PTR( nCategory )+1;
	switch(pCategory->m_eStatus)
	{
	case CAtlTraceSettings::Inherit:
		pCategoryInfo->settings.eStatus = ATLTRACESTATUS_INHERIT;
		break;
	case CAtlTraceSettings::Enabled:
		pCategoryInfo->settings.eStatus = ATLTRACESTATUS_ENABLED;
		break;
	case CAtlTraceSettings::Disabled:
		pCategoryInfo->settings.eStatus = ATLTRACESTATUS_DISABLED;
		break;
	default:
		ATLASSERT( false );
		break;
	}
}

static bool WINAPI ShouldTraceOutput(
	_In_ DWORD_PTR dwModule,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel,
	_Deref_out_opt_ const CAtlTraceCategory **ppCategory,
	_Deref_out_opt_ CAtlTraceModule::fnCrtDbgReport_t *pfnCrtDbgReport)
{
	bool bFound = false;

	ATLASSERT(ppCategory && pfnCrtDbgReport);
	*ppCategory = NULL;
	*pfnCrtDbgReport = NULL;

	CAtlTraceProcess *pProcess = g_Allocator.GetProcess();
	ATLASSERT(pProcess);
	CAtlTraceModule *pModule = g_Allocator.GetModule( int( dwModule-1 ) );

	ATLASSERT(pModule != NULL);
	if(pModule != NULL)
	{
		*pfnCrtDbgReport = pModule->CrtDbgReport();

		CAtlTraceCategory *pCategory = g_Allocator.GetCategory( int( dwCategory-1 ) );
		if( pCategory != NULL )
		{
			bFound = true;
			bool bOut = false;

			if(pProcess->m_bEnabled &&
				pModule->m_eStatus == CAtlTraceSettings::Inherit &&
				pCategory->m_eStatus == CAtlTraceSettings::Inherit &&
				nLevel <= pProcess->m_nLevel)
			{
				bOut = true;
			}
			else if(pModule->m_eStatus == CAtlTraceSettings::Enabled &&
				pCategory->m_eStatus == CAtlTraceSettings::Inherit &&
				nLevel <= pModule->m_nLevel)
			{
				bOut = true;
			}
			else if(pCategory->m_eStatus == CAtlTraceSettings::Enabled &&
				nLevel <= pCategory->m_nLevel)
			{
				bOut = true;
			}

			if(bOut)
			{
				*ppCategory = pProcess->m_bFuncAndCategoryNames ? pCategory : NULL;
				return true;
			}
		}
	}

	return false;
}

bool _IsTracingEnabled(
	_In_ DWORD_PTR dwModule,
	_In_ DWORD_PTR dwCategory,
	_In_ UINT nLevel)
{
	const CAtlTraceCategory *pCategory = NULL;
	CAtlTraceModule::fnCrtDbgReport_t pfnCrtDbgReport = NULL;

	return(ShouldTraceOutput(dwModule, dwCategory, nLevel, &pCategory, &pfnCrtDbgReport));
}

};  // namespace ATL
