// This MFC Library source code supports the Microsoft Office Fluent User Interface
// (the "Fluent UI") and is provided only as referential material to supplement the
// Microsoft Foundation Classes Reference and related electronic documentation
// included with the MFC C++ library software.
// License terms to copy, use or distribute the Fluent UI are available separately.
// To learn more about our Fluent UI licensing program, please visit
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "afxdatarecovery.h"

#include <ShlObj.h>
#include <KnownFolders.h>

#if defined(_UNICODE)
#include "afxtaskdialog.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CALLBACK AfxAutosaveTimerProc(HWND, UINT, UINT_PTR, DWORD)
{
	CWinApp *pApp = AfxGetApp();
	if (pApp != NULL)
	{
		CDataRecoveryHandler *pHandler = pApp->GetDataRecoveryHandler();
		if (pHandler != NULL)
		{
			pHandler->SetSaveDocumentInfoOnIdle(TRUE);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDataRecoveryHandler

CDataRecoveryHandler::CDataRecoveryHandler(_In_ DWORD dwRestartManagerSupportFlags, _In_ int nAutosaveInterval)
{
	// Ensure that the combination of flags makes sense
	ASSERT(dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_SUPPORT_RESTART | AFX_RESTART_MANAGER_SUPPORT_RECOVERY));
	if (dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES)
	{
		ASSERT(dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART | AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL));
	}

	m_dwRestartManagerSupportFlags = dwRestartManagerSupportFlags;
	m_nAutosaveInterval = nAutosaveInterval;
	m_bSaveDocumentInfoOnIdle = FALSE;
	m_bShutdownByRestartManager = FALSE;
	m_bRestoringPreviousOpenDocs = FALSE;
	m_nTimerID = 0;
}

CDataRecoveryHandler::~CDataRecoveryHandler()
{
	// Process failed autosave deletes
	while (!m_lstAutosavesToDelete.IsEmpty())
	{
		CString strAutosaveToDelete = m_lstAutosavesToDelete.RemoveHead();
		DeleteFile(strAutosaveToDelete);
	}

	KillTimer(NULL, m_nTimerID);
}

BOOL CDataRecoveryHandler::Initialize()
{
	BOOL bRet = TRUE;

	if (m_dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART | AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL))
	{
		HRESULT hr = S_FALSE;
		PWSTR pszAutosavePath = NULL;

		// Get the path where files will be autosaved on timer tick or restart
		hr = _AfxSHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &pszAutosavePath);

		if ((hr == S_OK) && (pszAutosavePath != NULL))
		{
			SetAutosavePath(pszAutosavePath);
			CoTaskMemFree(pszAutosavePath);
		}
		else
		{
			bRet = FALSE;
		}
	}

	if (bRet && (m_dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL))
	{
		// Start the timer that will be used to trigger the periodic autosaves
		m_nTimerID = SetTimer(NULL, m_nTimerID, GetAutosaveInterval(), AfxAutosaveTimerProc);
	}

	return bRet;
}

void CDataRecoveryHandler::SetAutosaveInterval(_In_ int nAutosaveInterval)
{
	// reset the auto-save timer interval...
	m_nAutosaveInterval = nAutosaveInterval;
	// ...and then reset the timer with the new auto-save interval.
	m_nTimerID = SetTimer(NULL, m_nTimerID, GetAutosaveInterval(), AfxAutosaveTimerProc);
}

BOOL CDataRecoveryHandler::SaveOpenDocumentList()
{
	BOOL bRet = TRUE;  // return FALSE if document list non-empty and not saved

	POSITION posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
	if (posAutosave != NULL)
	{
		bRet = FALSE;

		// Save the open document list and associated autosave info to the registry
		CRegKey keyRestart;
		if (keyRestart.Create(AfxGetApp()->GetAppRegistryKey(), GetRestartIdentifier()) == ERROR_SUCCESS)
		{
			while (posAutosave != NULL)
			{
				CString strDocument, strAutosave;
				m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);

				keyRestart.SetStringValue(strDocument, strAutosave, REG_SZ);
			}

			return TRUE;
		}
	}

	return bRet;
}

BOOL CDataRecoveryHandler::ReadOpenDocumentList()
{
	BOOL bRet = FALSE;  // return TRUE only if at least one document was found

	// Read the open document list and associated autosave info from the registry
	CRegKey keyApp(AfxGetApp()->GetAppRegistryKey()), keyRestart;
	if (keyRestart.Open(keyApp, GetRestartIdentifier()) == ERROR_SUCCESS)
	{
		DWORD dwValueIndex = 0;
		TCHAR szValueName[MAX_PATH] = _T("");
		DWORD cchValueName = _countof(szValueName);
		while (::RegEnumValue(keyRestart, dwValueIndex, szValueName, &cchValueName, NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
		{
			dwValueIndex++;
			cchValueName = _countof(szValueName);


			TCHAR szValue[MAX_PATH] = _T("");
			DWORD cchValue = _countof(szValue);
			if (keyRestart.QueryStringValue(szValueName, szValue, &cchValue) == ERROR_SUCCESS)
			{
				m_mapDocNameToAutosaveName[szValueName] = szValue;
				bRet = TRUE;
			}
		}

		// Once the information is read, delete the key from the registry
		keyRestart.Close();
		keyApp.DeleteSubKey(GetRestartIdentifier());
	}

	return bRet;
}

BOOL CDataRecoveryHandler::AutosaveDocumentInfo(_In_ CDocument *pDocument, _In_ BOOL bResetModifiedFlag)
{
	if (m_dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART | AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL))
	{
		if (pDocument != NULL)
		{
			ASSERT_VALID(pDocument);
			ASSERT_KINDOF(CDocument, pDocument);

			CString strDocumentPathName;
			m_mapDocumentPtrToDocName.Lookup(pDocument, strDocumentPathName);

			if (strDocumentPathName.IsEmpty())
			{
				strDocumentPathName = GetDocumentListName(pDocument);
				m_mapDocumentPtrToDocName[pDocument] = strDocumentPathName;
			}

			if (!strDocumentPathName.IsEmpty())
			{
				CString strAutosavePathNameCurrent, strAutosavePathNameNew;
				if (pDocument->IsModified())
				{
					// Make sure that the document has an entry in the open document list
					if (!m_mapDocNameToAutosaveName.Lookup(strDocumentPathName, strAutosavePathNameCurrent))
					{
						m_mapDocNameToAutosaveName[strDocumentPathName] = _T("");
					}

					if (m_dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART | AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL))
					{
						// Generate the new autosave filename
						strAutosavePathNameNew = GenerateAutosaveFileName(strDocumentPathName);

						// Save the document to the autosave location (but don't update document path)
						if (pDocument->DoSave(strAutosavePathNameNew, FALSE))
						{
							// If successful, update the document's entry in the open document list...
							m_mapDocNameToAutosaveName[strDocumentPathName] = strAutosavePathNameNew;

							//...and delete the previous autosave file (if there was one)
							if (strAutosavePathNameCurrent.CompareNoCase(strAutosavePathNameNew) != 0)
							{
								DeleteAutosavedFile(strAutosavePathNameCurrent);
							}

							if (bResetModifiedFlag)
							{
								// Make sure that the document is still in modified state,
								// so any attempt to close it will prompt for save.
								pDocument->SetModifiedFlag(TRUE);
							}
							else
							{
								// Make sure that the document is in un-modified state,
								// so pending SaveAllModified will not prompt for save.
								pDocument->SetModifiedFlag(FALSE);
							}
						}
					}
				}
				else
				{
					BOOL bRet = m_mapDocNameToAutosaveName.Lookup(strDocumentPathName, strAutosavePathNameCurrent);

					// Make sure that the document is in the open document list with no autosave associated
					m_mapDocNameToAutosaveName[strDocumentPathName] = _T("");

					if (bRet)
					{
						// Delete the previous autosave file (if there was one)
						DeleteAutosavedFile(strAutosavePathNameCurrent);
					}
				}
			}

			return TRUE;
		}
	}

	return FALSE;
}

BOOL CDataRecoveryHandler::AutosaveAllDocumentInfo()
{
	BOOL bRet = TRUE;

	if (m_dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART | AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL))
	{
		CWinApp *pApp = AfxGetApp();
		if (pApp != NULL)
		{
			CDocManager *pDocManager = pApp->m_pDocManager;
			if (pDocManager != NULL)
			{
				// Loop through all the document templates
				POSITION posTemplate = pDocManager->GetFirstDocTemplatePosition();
				while (posTemplate != NULL)
				{
					CDocTemplate* pTemplate = pDocManager->GetNextDocTemplate(posTemplate);
					ASSERT_KINDOF(CDocTemplate, pTemplate);

					// Loop through all the documents in the template
					POSITION posDocument = pTemplate->GetFirstDocPosition();
					while (posDocument != NULL)
					{
						CDocument* pDocument = pTemplate->GetNextDoc(posDocument);
						ASSERT_VALID(pDocument);
						ASSERT_KINDOF(CDocument, pDocument);

						// Autosave the document information for the document
						bRet &= AutosaveDocumentInfo(pDocument, FALSE);
					}
				}
			}
		}
	}

	// If any autosave failed, return failure
	return bRet;
}

BOOL CDataRecoveryHandler::CreateDocumentInfo(_In_ CDocument *pDocument)
{
	BOOL bRet = TRUE;

	if ((m_dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES) && !m_bRestoringPreviousOpenDocs)
	{
		// A document has been opened.  Add it to the open document list,
		// but first check to see if the document is already in the lists
		// (which will be the case if SDI) and remove those references.
		CString strDocumentListName;

		if (m_mapDocumentPtrToDocName.Lookup(pDocument, strDocumentListName))
		{
			m_mapDocumentPtrToDocName.RemoveKey(pDocument);
			m_mapDocumentPtrToDocTitle.RemoveKey(pDocument);
			m_mapDocNameToDocumentPtr.RemoveKey(strDocumentListName);
			CString strAutosavePathName;
			m_mapDocNameToAutosaveName.Lookup(strDocumentListName, strAutosavePathName);
			DeleteAutosavedFile(strAutosavePathName);
			m_mapDocNameToAutosaveName.RemoveKey(strDocumentListName);
		}

		strDocumentListName = GetDocumentListName(pDocument);
		m_mapDocumentPtrToDocName[pDocument] = strDocumentListName;
		m_mapDocNameToAutosaveName[strDocumentListName] = _T("");
	}

	return bRet;
}

BOOL CDataRecoveryHandler::UpdateDocumentInfo(_In_ CDocument *pDocument)
{
	BOOL bRet = TRUE;

	if (m_dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES)
	{
		// A document has been saved, perhaps with a new filename.  Delete the old
		// filename from the open document list and delete any existing auto-save
		// file from disk.  Add the new filename to the open document list.
		RemoveDocumentInfo(pDocument);
		CString strNewDocumentName = GetDocumentListName(pDocument);
		m_mapDocumentPtrToDocName[pDocument] = strNewDocumentName;
		m_mapDocNameToAutosaveName[strNewDocumentName] = _T("");
	}

	return bRet;
}

BOOL CDataRecoveryHandler::RemoveDocumentInfo(_In_ CDocument *pDocument)
{
	BOOL bRet = TRUE;

	if (m_dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES)
	{
		// A document has been closed.  Delete the filename from the open
		// document list and delete any existing auto-save file from disk.
		CString strDocumentName;
		if (m_mapDocumentPtrToDocName.Lookup(pDocument, strDocumentName))
		{
			CString strAutosavePathName;

			m_mapDocNameToAutosaveName.Lookup(strDocumentName, strAutosavePathName);
			DeleteAutosavedFile(strAutosavePathName);
			m_mapDocNameToAutosaveName.RemoveKey(strDocumentName);
			m_mapDocNameToDocumentPtr.RemoveKey(strDocumentName);
		}

		m_mapDocumentPtrToDocName.RemoveKey(pDocument);
		m_mapDocumentPtrToDocTitle.RemoveKey(pDocument);
	}

	return bRet;
}

BOOL CDataRecoveryHandler::DeleteAutosavedFile(_In_ const CString &strAutosavedFile)
{
	if (!strAutosavedFile.IsEmpty())
	{
		if (DeleteFile(strAutosavedFile) == 0)
		{
			// Remember failed deletes in a list to be processed at destruction
			m_lstAutosavesToDelete.AddTail(strAutosavedFile);
		}
	}

	return TRUE;
}

BOOL CDataRecoveryHandler::DeleteAllAutosavedFiles()
{
	POSITION posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
	while (posAutosave != NULL)
	{
		CString strDocument, strAutosave;
		m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);

		if (!strAutosave.IsEmpty())
		{
			// Make sure that the document has an entry in the open document list
			m_mapDocNameToAutosaveName[strDocument] = _T("");

			// Delete the autosave file
			DeleteAutosavedFile(strAutosave);
		}
	}

	return TRUE;
}

BOOL CDataRecoveryHandler::ReopenPreviousDocuments()
{
	BOOL bRet = FALSE;
	m_mapDocNameToDocumentPtr.RemoveAll();
	m_bRestoringPreviousOpenDocs = TRUE;

	if (m_dwRestartManagerSupportFlags & AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES)
	{
		POSITION posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
		while (posAutosave != NULL)
		{
			CDocument *pDocument = NULL;
			CString strDocument, strAutosave;
			m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);

			int iPathDelimiter = strDocument.FindOneOf(_T(":/\\"));
			if (iPathDelimiter != -1)
			{
				// Open an existing previously saved document from disk.
				pDocument = AfxGetApp()->OpenDocumentFile(strDocument, TRUE);
			}
			else
			{
				// Create a new document and give it the previously opened document's name,
				// using the template based on the extension in the document's name.
				CWinApp *pApp = AfxGetApp();
				CDocTemplate* pBestTemplate = NULL;

				if ((pApp != NULL) && (pApp->m_pDocManager != NULL))
				{
					pBestTemplate = pApp->m_pDocManager->GetBestTemplate(strDocument);
				}

				if (pBestTemplate != NULL)
				{
					pDocument = pBestTemplate->OpenDocumentFile(NULL, FALSE, TRUE);
				}

				if (pDocument != NULL)
				{
					CString strDocumentTitle = strDocument;
					int nStartExtension = strDocument.ReverseFind(_T('.'));
					if (nStartExtension > 0)
					{
						strDocumentTitle = strDocument.Left(nStartExtension);
					}
					pDocument->SetTitle(strDocumentTitle);
				}
			}

			m_mapDocNameToDocumentPtr[strDocument] = pDocument;
			bRet |= (pDocument != NULL);
		}
	}

	m_bRestoringPreviousOpenDocs = FALSE;
	// If any document was created, return TRUE.
	return bRet;
}

void CDataRecoveryHandler::QueryRestoreAutosavedDocuments()
{
	// This method is separate so an alternate UI can be provided for asking the user about
	// restoring autosaved files.  After presenting the UI, fill m_mapDocNameToRestoreBool with
	// pairs of filenames and true/false values to indicate whether a file should be restored.
	int nRet = IDNO;
#if defined(_UNICODE)
	if (CTaskDialog::IsSupported())
	{
		BOOL bRet;
		CString strTitle;
		bRet = strTitle.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_1);
		ASSERT(bRet);
		CString strMainInstruction;
		bRet = strMainInstruction.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_2);
		ASSERT(bRet);
		strTitle += _T("\r\n");
		strTitle += strMainInstruction;
		CString strContent;
		bRet = strContent.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_3);
		ASSERT(bRet);
		CString strFooter;
		bRet = strFooter.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_4);
		ASSERT(bRet);

		INT_PTR nReturn = CTaskDialog::ShowDialog(strContent, strTitle, AfxGetApp()->m_pszAppName,
			AFX_IDS_AUTOSAVE_RECOVERY_ASK_5, AFX_IDS_AUTOSAVE_RECOVERY_ASK_6, 0, TDF_USE_COMMAND_LINKS, strFooter);
		nRet = (nReturn == AFX_IDS_AUTOSAVE_RECOVERY_ASK_5 ? IDYES : IDNO);
	}
	else
#endif
	{
		BOOL bRet;
		CString strAutosaveRecoverQuery, strTemp;
		bRet = strAutosaveRecoverQuery.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_1);
		ASSERT(bRet);
		strAutosaveRecoverQuery += _T("\r\n");
		bRet = strTemp.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_2);
		ASSERT(bRet);
		strAutosaveRecoverQuery += strTemp;
		strAutosaveRecoverQuery += _T("\r\n\r\n");
		bRet = strTemp.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_3);
		ASSERT(bRet);
		strAutosaveRecoverQuery += strTemp;
		strAutosaveRecoverQuery += _T("\r\n\r\n");
		bRet = strTemp.LoadString(AFX_IDS_AUTOSAVE_RECOVERY_ASK_4);
		ASSERT(bRet);
		strAutosaveRecoverQuery += strTemp;

		nRet = AfxMessageBox(strAutosaveRecoverQuery, MB_YESNO);
	}

	POSITION posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
	while (posAutosave != NULL)
	{
		CString strDocument, strAutosave;
		m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);

		if (!strAutosave.IsEmpty())
		{
			m_mapDocNameToRestoreBool[strDocument] = (nRet == IDYES ? true :false);
		}
	}
}

BOOL CDataRecoveryHandler::RestoreAutosavedDocuments()
{
	m_mapDocNameToRestoreBool.RemoveAll();
	m_bRestoringPreviousOpenDocs = TRUE;

	if ((m_dwRestartManagerSupportFlags & (AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES | AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES)) == (AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES | AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES))
	{
		CFileStatus fs;
		POSITION posAutosave;
		BOOL bHaveDocumentsToRestore = FALSE;

		// First determine whether there are any autosaved files to restore
		posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
		while (posAutosave != NULL)
		{
			CString strDocument, strAutosave;
			m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);
			if ((!strAutosave.IsEmpty()) && (CFile::GetStatus(strAutosave, fs)))
			{
				bHaveDocumentsToRestore = TRUE;
				break;
			}
		}

		if (bHaveDocumentsToRestore)
		{
			// Call QueryRestoreAutosavedDocuments to fill up the m_mapDocNameToRestoreBool map
			// with true/false about whether to restore the autosave for each document that has one.
			QueryRestoreAutosavedDocuments();

			posAutosave = m_mapDocNameToAutosaveName.GetStartPosition();
			while (posAutosave != NULL)
			{
				CString strDocument, strAutosave;
				m_mapDocNameToAutosaveName.GetNextAssoc(posAutosave, strDocument, strAutosave);

				if ((!strAutosave.IsEmpty()) && (CFile::GetStatus(strAutosave, fs)))
				{
					bool bRestore;
					m_mapDocNameToRestoreBool.Lookup(strDocument, bRestore);
					if (bRestore)
					{
						// Turn redraw of the main frame off so the opening/closing is not visible
						AfxGetApp()->GetMainWnd()->SetRedraw(FALSE);

						// Open the autosave file
						CDocument *pDocument = AfxGetApp()->OpenDocumentFile(strAutosave, FALSE);
						if (pDocument != NULL)
						{
							CString strTitle;
							int iPathDelimiter = strDocument.FindOneOf(_T(":/\\"));
							if (iPathDelimiter != -1)
							{
								// Set the path name to the original document path
								pDocument->SetPathName(strDocument, FALSE);
								strTitle = pDocument->GetTitle();
							}
							else
							{
								// Set the path name to empty so save will prompt
								pDocument->ClearPathName();

								strTitle = strDocument;
								int nStartExtension = strDocument.ReverseFind(_T('.'));
								if (nStartExtension > 0)
								{
									strTitle = strDocument.Left(nStartExtension);
								}
								pDocument->SetTitle(strTitle);
							}

							CString strDocumentListName = GetDocumentListName(pDocument);
							m_mapDocumentPtrToDocName[pDocument] = strDocumentListName;

							// Close the original file now that the autosave file is opened, but
							// only if the original document is different than current (not SDI).
							CDocument *pOriginalDocument = NULL;
							m_mapDocNameToDocumentPtr.Lookup(strDocument, pOriginalDocument);
							if ((pOriginalDocument != NULL) && (pOriginalDocument != pDocument))
							{
								pOriginalDocument->OnCloseDocument();
							}

							// Set the document to be modified so it will prompt for save
							pDocument->SetModifiedFlag(TRUE);

							// Turn redraw of the main frame back on
							AfxGetApp()->GetMainWnd()->SetRedraw(TRUE);
							AfxGetApp()->GetMainWnd()->Invalidate(TRUE);
							AfxGetApp()->GetMainWnd()->UpdateWindow();

							// Append the "[recovered]" string to the title.  Do this after turning redraw back on so
							// there is an indication of state change in the application, and so repainting is forced.
							m_mapDocumentPtrToDocTitle[pDocument] = strTitle;
							CString strRecoveredTitle = GetRecoveredDocumentTitle(strTitle);
							pDocument->SetTitle(strRecoveredTitle);
						}
						else
						{
							// Turn redraw of the main frame back on
							AfxGetApp()->GetMainWnd()->SetRedraw(TRUE);
							AfxGetApp()->GetMainWnd()->Invalidate(TRUE);
							AfxGetApp()->GetMainWnd()->UpdateWindow();
						}
					}
					else
					{
						// Remove the autosave association
						m_mapDocNameToAutosaveName[strDocument] = _T("");

						// Delete the autosave file
						DeleteAutosavedFile(strAutosave);
					}
				}
			}
		}
	}

	m_mapDocNameToRestoreBool.RemoveAll();
	m_mapDocNameToDocumentPtr.RemoveAll();
	m_bRestoringPreviousOpenDocs = FALSE;
	return TRUE;
}

CString CDataRecoveryHandler::GetDocumentListName(_In_ CDocument *pDocument) const
{
	CString strDocumentPathName = pDocument->GetPathName();
	if (strDocumentPathName.IsEmpty())
	{
		strDocumentPathName = pDocument->GetTitle();

		// append the default suffix if there is one
		CString strExt;
		CDocTemplate* pTemplate = pDocument->GetDocTemplate();
		ASSERT(pTemplate != NULL);
		if (pTemplate && pTemplate->GetDocString(strExt, CDocTemplate::filterExt) && !strExt.IsEmpty())
		{
			ASSERT(strExt[0] == '.');
			int iStart = 0;
			strDocumentPathName += strExt.Tokenize(_T(";"), iStart);
		}
	}

	return strDocumentPathName;
}

CString CDataRecoveryHandler::GenerateAutosaveFileName(_In_ const CString &strDocumentName) const
{
	int nPathLength = strDocumentName.GetLength();
	int nLastBackslash = strDocumentName.ReverseFind(_T('\\'));
	CString strDocumentFileName = strDocumentName.Right(nPathLength - nLastBackslash - 1);

	GUID guidAutosave = GUID_NULL;
	CoCreateGuid(&guidAutosave);

	CString strAutosave;
	strAutosave.Format(_T("%08lX%04X%04x%02X%02X%02X%02X%02X%02X%02X%02X"),
		guidAutosave.Data1, guidAutosave.Data2, guidAutosave.Data3,
		guidAutosave.Data4[0], guidAutosave.Data4[1], guidAutosave.Data4[2], guidAutosave.Data4[3],
		guidAutosave.Data4[4], guidAutosave.Data4[5], guidAutosave.Data4[6], guidAutosave.Data4[7]);

	CString strAutosavePathName;
	strAutosavePathName = GetAutosavePath();
	strAutosavePathName += _T("\\");
	strAutosavePathName += strAutosave;
	strAutosavePathName += _T(".");
	strAutosavePathName += strDocumentFileName;

	return strAutosavePathName;
}

CString CDataRecoveryHandler::GetRecoveredDocumentTitle(_In_ const CString &strDocumentTitle) const
{
	CString strFormat, strRecoveredTitle;
	BOOL bRet = strFormat.LoadString(AFX_IDS_AUTOSAVE_RECOVERED);
	ASSERT(bRet);
	strRecoveredTitle.Format(strFormat, strDocumentTitle.GetString());
	return strRecoveredTitle;
}

CString CDataRecoveryHandler::GetNormalDocumentTitle(CDocument *pDocument) const
{
	CString strNormalTitle;
	m_mapDocumentPtrToDocTitle.Lookup(pDocument, strNormalTitle);
	return strNormalTitle;
}
