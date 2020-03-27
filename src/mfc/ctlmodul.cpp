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
#include "afxcontrolbarutil.h"

#define new DEBUG_NEW

/////////////////////////////////////////////////////////////////////////////
// COleControlModule::InitInstance

IMPLEMENT_DYNAMIC(COleControlModule, CWinApp)

BOOL COleControlModule::InitInstance()
{
#ifdef _AFXDLL
	// wire up resources from OLE DLL
	AfxOleInitModule();
#endif

	// Since we don't call CWinApp::InitInstance here, but do call CWinApp::ExitInstance
	// from COleControlModule::ExitInstance, we need to call AfxGlobalsAddRef in order to
	// keep the reference count on the afxGlobalData object consistent (when using MFC DLL).
#ifdef _AFXDLL
	AfxGlobalsAddRef();
#endif

	COleObjectFactory::RegisterAll();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COleControlModule::ExitInstance

int COleControlModule::ExitInstance()
{
	COleObjectFactory::RevokeAll();
	return CWinApp::ExitInstance();
}
