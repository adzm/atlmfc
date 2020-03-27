// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#include "stdafx.h"
#include "Common.h"
#include "Allocate.h"

//disable compiler reserved initialization area warning
#pragma warning(disable : 4074)
#pragma init_seg(compiler)

// if you change data size or data placement in CAtlTraceProcess or CAtlTraceModule 
// you should also change file mappings name because atltrace uses shared memory to store
// data and it will be not compatible with previous version
const char *g_pszUpdateEventName	= "AtlTraceModuleManager_ProcessAddedStatic_100";
const char *g_pszAllocFileMapName	= "AtlDebugAllocator_FileMappingNameStatic_100";

const char *g_pszKernelObjFmt = "%s_%0x";

CAtlAllocator g_Allocator;

static bool WINAPI Init()
{
	char szFileMappingName[MAX_PATH];

	int ret;
	ATL_CRT_ERRORCHECK_SPRINTF(ret = _snprintf_s(szFileMappingName, _countof(szFileMappingName), _countof(szFileMappingName) - 1, g_pszKernelObjFmt,
		g_pszAllocFileMapName, GetCurrentProcessId()));
	
	if(ret == -1 || ret >= MAX_PATH)
	{
		throw CAtlException( E_FAIL );
	}

	// surely four megs is enough?
	g_Allocator.Init(szFileMappingName, 4*1024*1024);

	return true;
}

static const bool g_bInitialized = Init();

#ifdef _DEBUG

namespace ATL
{

CTrace CTrace::s_trace;

};

#endif
