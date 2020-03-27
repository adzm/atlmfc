// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef ATLDEBUG_SHAREDMEORY_ALLOCATOR_HEADER
#define ATLDEBUG_SHAREDMEORY_ALLOCATOR_HEADER

class CAtlTraceProcess;
class CAtlTraceModule;
class CAtlTraceCategory;

class CTraceSnapshot
{
public:
	struct CModuleInfo
	{
		DWORD_PTR m_dwModule;
		int m_nCategories;
		int m_iFirstCategory;
	};

public:
	CSimpleArray< CModuleInfo > m_aModules;
	CSimpleArray< DWORD_PTR > m_adwCategories;
};

class CAtlAllocator
{
public:
	CAtlAllocator() :
		m_dwPageSize(0),
		m_hMap(NULL),
		m_bValid(false),
		m_pProcess(NULL),
		m_bSnapshot(false)
	{
	}

	~CAtlAllocator()
	{
		Close();
	}

	bool Init(
		_In_z_ const CHAR *pszFileMappingName,
		_In_ DWORD dwMaxSize);
	bool Open(_In_z_ const CHAR *pszFileMappingName);
	void Close(_In_ bool bForceUnmap = false);
	bool IsValid() const
	{
		return m_bValid;
	}

	CAtlTraceProcess *GetProcess() const
	{
		return m_pProcess;
	}
	CAtlTraceModule *GetModule(_In_ int iModule) const;
//	CAtlTraceCategory *GetCategory(int iModule, unsigned nCategory) const;
	CAtlTraceCategory* GetCategory(_In_ int iCategory) const;

	/*
	bool Lock(DWORD dwTimeOut);
	void Unlock();
	*/

	bool LoadSettings(_In_z_ const CHAR *pszFileName);
	bool LoadSettings(_In_z_ const WCHAR *pszFileName);
	bool SaveSettings(_In_z_ const CHAR *pszFileName);
	bool SaveSettings(_In_z_ const WCHAR *pszFileName);

	int GetModuleCount() const;
	int GetCategoryCount(_In_ int iModule) const;
	int GetCategoryCount(_In_ const CAtlTraceModule& Module) const;

	bool FindModule(
		_In_z_ const WCHAR *pszModuleName,
		_Out_ unsigned *pnModule) const;

	int AddModule(_In_ HINSTANCE hInst);
	int AddCategory(
		_In_ int iModule,
		_In_z_ const WCHAR *szCategoryName);

	bool RemoveModule(_In_ int iModule);

	void CleanUp();

	void TakeSnapshot();
	void ReleaseSnapshot();

	CTraceSnapshot m_snapshot;
	bool m_bSnapshot;

private:
	CAtlTraceProcess *m_pProcess;
	DWORD m_dwPageSize;
	HANDLE m_hMap;
	bool m_bValid;
	BYTE *m_pBufferStart;
};

#endif // ATLDEBUG_SHAREDMEORY_ALLOCATOR_HEADER
