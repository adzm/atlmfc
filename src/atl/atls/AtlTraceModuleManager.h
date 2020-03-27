// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef ATLDEBUG_TRACE_MANAGER
#define ATLDEBUG_TRACE_MANAGER

#include "Allocate.h"

//
// if you make changes to those classes look at file mappings in Externs.cpp
//

// Names
class CAtlTraceModuleInfo
{
public:
	explicit CAtlTraceModuleInfo();

	void Reset(_In_ HINSTANCE hInst);
	HINSTANCE GetInstance() const
	{
		return m_hInst;
	}
	const WCHAR *Path() const
	{
		return m_szPath;
	}
	const WCHAR *Name() const
	{
		return m_szName;
	}

	int m_iFirstCategory;
	LONG m_nCategories;

private:
	WCHAR m_szPath[MAX_PATH];
	WCHAR m_szName[_MAX_FNAME];
	HINSTANCE m_hInst;
};

class CAtlTraceSettings
{
public:
	CAtlTraceSettings() :
		m_nLevel(0),
		m_eStatus(Inherit),
		m_nRefCount(0),
		m_nCookie(0)
	{
	}

	UINT m_nLevel;
	enum Status
	{
		Inherit = 0,
		Enabled,
		Disabled
	};

	Status m_eStatus;

	// Only valid if (m_nRefCount > 0) && (m_nCookie != 0)
	LONG m_nRefCount;
	LONG m_nCookie;

public:
	// Tries to mark the object as allocated.  If the object is not available for allocation, returns false.
	// Call this, then initialize the data, then call MarkValid.  A successful TryAllocate gets a reference
	// to the object
	bool TryAllocate()
	{
		if( m_nCookie != 0 )
		{
			return( false );
		}
		LONG nNewRefCount = ::InterlockedIncrement( &m_nRefCount );
		if( nNewRefCount == 1 )
		{
			// We are the first ones here
			return( true );
		}

		return( false );
	}

	// Marks the object as valid.
	void MarkValid(_In_ LONG nCookie)
	{
		ATLASSERT( nCookie != 0 );
		m_nCookie = nCookie;
	}

	// Tries to get a reference to the object.  If the object is invalid, returns false.  Must call Release to
	// release the reference after a successful TryAddRef
	bool TryAddRef()
	{
		LONG nNewRefCount = ::InterlockedIncrement( &m_nRefCount );
		if( (nNewRefCount > 1) && (m_nCookie != 0) )
		{
			// The object is valid, and we now own a reference to it
			return( true );
		}
		else
		{
			Release();

			return( false );
		}
	}

	// Releases a reference to the object.  If the objects refcount hits zero, the object is invalidated
	void Release()
	{
		LONG nNewRefCount = ::InterlockedDecrement( &m_nRefCount );
		if( nNewRefCount == 0 )
		{
			// We just released the last reference, so mark as invalid
			m_nCookie = 0;
		}
	}
};

// Categories
class CAtlTraceCategory :
	public CAtlTraceSettings
{
public:
	CAtlTraceCategory();

	const WCHAR *Name() const
	{
		return m_szName;
	}

	void Reset(
		_In_z_ const WCHAR *pszName,
		_In_ LONG nModuleCookie);

	LONG m_nModuleCookie;
	int m_iNextCategory;

private:
	WCHAR m_szName[ATL_TRACE_MAX_NAME_SIZE];
};

// Modules (DLLs)
class CAtlTraceModule :
	public CAtlTraceModuleInfo,
	public CAtlTraceSettings
{
public:
	typedef int (__cdecl *fnCrtDbgReport_t)(
		_In_ int,
		_In_z_ const CHAR *,
		_In_ int,
		_In_z_ const CHAR *,
		_In_z_ _Printf_format_string_ const CHAR *,...);

	explicit CAtlTraceModule();

	void CrtDbgReport(_In_opt_ fnCrtDbgReport_t pfnCrtDbgReport);
	fnCrtDbgReport_t CrtDbgReport() const
	{
		return m_pfnCrtDbgReport;
	}

private:
	fnCrtDbgReport_t m_pfnCrtDbgReport;
};

// Process Info
class CAtlTraceProcess :
	public CAtlTraceModuleInfo
{
public:
	// This structure varies in size on x64 and x86, so the trace tool can only control processes
	// that match its own platform. This member is set in the constructor and checked in the trace
	// tool when the process is first being opened. If the size does not match the expected size,
	// then the process is skipped, because it was built for the other platform.
	// WARNING: Make sure not to add members to the structure that will mis-align it such that the
	// x86 and x64 versions of the structure do not have m_cbSize in the same location.  Currently
	// the member is in the same location because it is __int64 and padding is added in x86 builds.
	__int64 m_cbSize;

	explicit CAtlTraceProcess(_In_ DWORD_PTR dwMaxSize);
	void Save(_In_ FILE *file, _In_ UINT nTabs) const;
	bool Load(_In_ FILE *file);

	UINT IncRef()
	{
		return ++m_nRef;
	}
	UINT DecRef()
	{
		return --m_nRef;
	}
	DWORD Id() const
	{
		return m_dwId;
	}
	DWORD_PTR MaxSize() const
	{
		return m_dwMaxSize;
	}
	void *Base() const
	{
		return m_pvBase;
	}
	int ModuleCount() const
	{
		return m_nModuleCount;
	}
	int CategoryCount() const
	{
		return m_nCategoryCount;
	}
	void IncModuleCount(_In_ UINT nModules)
	{
		m_nModuleCount += nModules;
	}
	void IncCategoryCount(_In_ UINT nCategories)
	{
		m_nCategoryCount += nCategories;
	}

	LONG GetNextCookie();

	DWORD_PTR m_dwFrontAlloc, m_dwBackAlloc, m_dwCurrFront, m_dwCurrBack;

	UINT m_nLevel;
	bool m_bLoaded, m_bEnabled, m_bFuncAndCategoryNames, m_bFileNameAndLineNo;

private:
	DWORD m_dwId;
	DWORD_PTR m_dwMaxSize;
	UINT m_nRef;
	void *m_pvBase;

	UINT m_nModuleCount, m_nCategoryCount;
	LONG m_nNextCookie;
};

#endif // ATLDEBUG_TRACE_MANAGER
