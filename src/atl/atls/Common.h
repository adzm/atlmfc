// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

// if you change data size or data placement in CAtlTraceProcess or CAtlTraceModule 
// you should also change file mappings name because atltrace uses shared memory to store
// data and it will be not compatible with previous version

#define UpdateEventName    "AtlTraceModuleManager_ProcessAddedStatic_110"  // keep the ANSI and Unicode versions of
#define UpdateEventNameU  L"AtlTraceModuleManager_ProcessAddedStatic_110"  // this event name in synch if changed!
#define AllocFileMapNameU L"AtlDebugAllocator_FileMappingNameStatic_110"
#define KernelObjFmtU     L"%s_%0x"

extern class CAtlAllocator g_Allocator;
