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
#include "io.h" // for _access

#include "afxdatarecovery.h"

/////////////////////////////////////////////////////////////////////////////
// CDocument

BEGIN_MESSAGE_MAP(CDocument, CCmdTarget)
	//{{AFX_MSG_MAP(CDocument)
	ON_COMMAND(ID_FILE_CLOSE, &CDocument::OnFileClose)
	ON_COMMAND(ID_FILE_SAVE, &CDocument::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CDocument::OnFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#if WINVER >= 0x0600
BEGIN_INTERFACE_MAP(CDocument, CCmdTarget)
	INTERFACE_PART(CDocument, IID_IInitializeWithStream, InitializeWithStream)
	INTERFACE_PART(CDocument, IID_IPreviewHandler, PreviewHandler)
	INTERFACE_PART(CDocument, IID_IPreviewHandlerVisuals, PreviewHandlerVisuals)
	INTERFACE_PART(CDocument, IID_IObjectWithSite, ObjectWithSite)
	INTERFACE_PART(CDocument, IID_IOleWindow, OleWindow)
END_INTERFACE_MAP()
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocument construction/destruction

CDocument::CDocument()
{
	m_pDocTemplate = NULL;
	m_bModified = FALSE;
	m_bAutoDelete = TRUE;       // default to auto delete document
	m_bEmbedded = FALSE;        // default to file-based document
	ASSERT(m_viewList.IsEmpty());

	m_pStream = NULL;
	m_hWndHost = NULL;
	m_pPreviewFrame = NULL;
	m_rectHost.SetRectEmpty();
	m_grfMode = 0;
	m_bGetThumbnailMode = FALSE;
	m_bPreviewHandlerMode = FALSE;
	m_bSearchMode = FALSE;
	m_posReadChunk = NULL;
	m_pDocumentAdapter = NULL;
	m_pPreviewHandlerSite = NULL;
	m_bFinalRelease = FALSE;
	m_bOLELocked = FALSE;

	m_clrRichPreviewBackColor = RGB(255, 255, 255);
	m_clrRichPreviewTextColor = RGB(0, 0, 0);
}

CDocument::~CDocument()
{
	// do not call DeleteContents here !
#ifdef _DEBUG
	if (IsModified())
		TRACE(traceAppMsg, 0, "Warning: destroying an unsaved document.\n");
#endif

	// there should be no views left!
	DisconnectViews();
	ASSERT(m_viewList.IsEmpty());

	if (m_pDocTemplate != NULL)
		m_pDocTemplate->RemoveDocument(this);
	ASSERT(m_pDocTemplate == NULL);     // must be detached

	// if IPreviewHandler::Unload was not called for some reason release stream and site
	if (m_pStream != NULL)
	{
		// if stream is not NULL it has not been released yet
		m_pStream->Release();
		m_pStream = NULL;
	}

	if (m_pDocumentAdapter != NULL)
	{
		m_pDocumentAdapter->m_pParentDoc = NULL;
	}

	if (m_pPreviewHandlerSite != NULL)
	{
		m_pPreviewHandlerSite->Release();
		m_pPreviewHandlerSite = NULL;
	}

	ClearChunkList();
}

void CDocument::OnFinalRelease()
{
	ASSERT_VALID(this);

	if (m_bPreviewHandlerMode)
	{
		if (m_bOLELocked)
		{
			AfxOleUnlockApp();
			m_bOLELocked = FALSE;
		}

		m_bAutoDelete = TRUE;
	}
	m_bFinalRelease = TRUE; // rich preview documents can be destroyed only from FinalRelease
	OnCloseDocument();  // may 'delete this'
}

void CDocument::DisconnectViews()
{
	while (!m_viewList.IsEmpty())
	{
		CView* pView = (CView*)m_viewList.RemoveHead();
		ASSERT_VALID(pView);
		ASSERT_KINDOF(CView, pView);
		pView->m_pDocument = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDocument attributes, general services

void CDocument::SetTitle(LPCTSTR lpszTitle)
{
	m_strTitle = lpszTitle;
	UpdateFrameCounts();        // will cause name change in views
}

void CDocument::DeleteContents()
{
}

/////////////////////////////////////////////////////////////////////////////
// Closing documents or views

void CDocument::OnChangedViewList()
{
	// if no more views on the document, delete ourself
	// not called if directly closing the document or terminating the app
	if (m_viewList.IsEmpty() && m_bAutoDelete)
	{
		OnCloseDocument();
		return;
	}

	// update the frame counts as needed
	UpdateFrameCounts();
}

void CDocument::UpdateFrameCounts()
	 // assumes 1 doc per frame
{
	// walk all frames of views (mark and sweep approach)
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		ASSERT(::IsWindow(pView->m_hWnd));
		if (pView->IsWindowVisible())   // Do not count invisible windows.
		{
			CFrameWnd* pFrame = pView->GetParentFrame();
			if (pFrame != NULL)
				pFrame->m_nWindow = -1;     // unknown
		}
	}

	// now do it again counting the unique ones
	int nFrames = 0;
	pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		ASSERT(::IsWindow(pView->m_hWnd));
		if (pView->IsWindowVisible())   // Do not count invisible windows.
		{
			CFrameWnd* pFrame = pView->GetParentFrame();
			if (pFrame != NULL && pFrame->m_nWindow == -1)
			{
				ASSERT_VALID(pFrame);
				// not yet counted (give it a 1 based number)
				pFrame->m_nWindow = ++nFrames;
			}
		}
	}

	// lastly walk the frames and update titles (assume same order)
	// go through frames updating the appropriate one
	int iFrame = 1;
	pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		ASSERT(::IsWindow(pView->m_hWnd));
		if (pView->IsWindowVisible())   // Do not count invisible windows.
		{
			CFrameWnd* pFrame = pView->GetParentFrame();
			if (pFrame != NULL && pFrame->m_nWindow == iFrame)
			{
				ASSERT_VALID(pFrame);
				if (nFrames == 1)
					pFrame->m_nWindow = 0;      // the only one of its kind
				pFrame->OnUpdateFrameTitle(TRUE);
				iFrame++;
			}
		}
	}
	ASSERT(iFrame == nFrames + 1);
}

BOOL CDocument::CanCloseFrame(CFrameWnd* pFrameArg)
	// permission to close all views using this frame
	//  (at least one of our views must be in this frame)
{
	ASSERT_VALID(pFrameArg);
	UNUSED(pFrameArg);   // unused in release builds

	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		CFrameWnd* pFrame = pView->GetParentFrame();
		// assume frameless views are ok to close
		if (pFrame != NULL)
		{
			// assumes 1 document per frame
			ASSERT_VALID(pFrame);
			if (pFrame->m_nWindow > 0)
				return TRUE;        // more than one frame refering to us
		}
	}

	// otherwise only one frame that we know about
	return SaveModified();
}

void CDocument::PreCloseFrame(CFrameWnd* /*pFrameArg*/)
{
	// default does nothing
}

/////////////////////////////////////////////////////////////////////////////
// File/Path commands

void CDocument::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU)
{
	// store the path fully qualified
	TCHAR szFullPath[_MAX_PATH];
	ENSURE(lpszPathName);
	if ( lstrlen(lpszPathName) >= _MAX_PATH )
	{
		ASSERT(FALSE);
		// MFC requires paths with length < _MAX_PATH
		// No other way to handle the error from a void function
		AfxThrowFileException(CFileException::badPath);
	}

	if( AfxFullPath(szFullPath, lpszPathName) == FALSE )
	{
		ASSERT(FALSE);
		// MFC requires paths with length < _MAX_PATH
		// No other way to handle the error from a void function
		AfxThrowFileException(CFileException::badPath);
	}

	m_strPathName = szFullPath;
	ASSERT(!m_strPathName.IsEmpty());       // must be set to something
	m_bEmbedded = FALSE;
	ASSERT_VALID(this);

	// set the document title based on path name
	TCHAR szTitle[_MAX_FNAME];
	if (AfxGetFileTitle(szFullPath, szTitle, _MAX_FNAME) == 0)
		SetTitle(szTitle);

	// add it to the file MRU list
	if (bAddToMRU)
		AfxGetApp()->AddToRecentFileList(m_strPathName);

	ASSERT_VALID(this);
}

void CDocument::ClearPathName()
{
	// If we need to keep the document content but also force a
	// prompt on the next save, we need to clear the path name.
	m_strPathName.Empty();
}

/////////////////////////////////////////////////////////////////////////////
// Standard file menu commands

void CDocument::OnFileClose()
{
	if (!SaveModified())
		return;

	// shut it down
	OnCloseDocument();
		// this should destroy the document
}

void CDocument::OnFileSave()
{
	DoFileSave();
}

void CDocument::OnFileSaveAs()
{
	if(!DoSave(NULL))
		TRACE(traceAppMsg, 0, "Warning: File save-as failed.\n");
}

BOOL CDocument::DoFileSave()
{
	DWORD dwAttrib = GetFileAttributes(m_strPathName);
	if (dwAttrib & FILE_ATTRIBUTE_READONLY)
	{
		// we do not have read-write access or the file does not (now) exist
		if (!DoSave(NULL))
		{
			TRACE(traceAppMsg, 0, "Warning: File save with new name failed.\n");
			return FALSE;
		}
	}
	else
	{
		if (!DoSave(m_strPathName))
		{
			TRACE(traceAppMsg, 0, "Warning: File save failed.\n");
			return FALSE;
		}
	}
	return TRUE;
}

BOOL CDocument::DoSave(LPCTSTR lpszPathName, BOOL bReplace)
	// Save the document data to a file
	// lpszPathName = path name where to save document file
	// if lpszPathName is NULL then the user will be prompted (SaveAs)
	// note: lpszPathName can be different than 'm_strPathName'
	// if 'bReplace' is TRUE will change file name if successful (SaveAs)
	// if 'bReplace' is FALSE will not change path name (SaveCopyAs)
{
	CString newName = lpszPathName;

	if (newName.IsEmpty())
	{
		CDocTemplate* pTemplate = GetDocTemplate();
		ASSERT(pTemplate != NULL);

		newName = m_strPathName;
		if (bReplace && newName.IsEmpty())
		{
			newName = m_strTitle;
			// check for dubious filename
			int iBad = newName.FindOneOf(_T(":/\\"));
			if (iBad != -1)
				newName.ReleaseBuffer(iBad);

			if (AfxGetApp() && AfxGetApp()->GetDataRecoveryHandler())
			{
				// remove "[recovered]" from the title if it exists
				CString strNormalTitle = AfxGetApp()->GetDataRecoveryHandler()->GetNormalDocumentTitle(this);
				if (!strNormalTitle.IsEmpty())
					newName = strNormalTitle;
			}

			// append the default suffix if there is one
			CString strExt;
			if (pTemplate->GetDocString(strExt, CDocTemplate::filterExt) && !strExt.IsEmpty())
			{
				ASSERT(strExt[0] == '.');
				int iStart = 0;
				newName += strExt.Tokenize(_T(";"), iStart);
			}
		}

		if (!AfxGetApp()->DoPromptFileName(newName,
		  bReplace ? AFX_IDS_SAVEFILE : AFX_IDS_SAVEFILECOPY,
		  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST, FALSE, pTemplate))
			return FALSE;       // don't even attempt to save
	}

	CWaitCursor wait;

	if (!OnSaveDocument(newName))
	{
		if (lpszPathName == NULL)
		{
			// be sure to delete the file
			TRY
			{
				CFile::Remove(newName);
			}
			CATCH_ALL(e)
			{
				TRACE(traceAppMsg, 0, "Warning: failed to delete file after failed SaveAs.\n");
				DELETE_EXCEPTION(e);
			}
			END_CATCH_ALL
		}
		return FALSE;
	}

	// reset the title and change the document name
	if (bReplace)
	{
		SetPathName(newName);
		OnDocumentEvent(onAfterSaveDocument);
	}

	return TRUE;        // success
}

BOOL CDocument::SaveModified()
{
	if (!IsModified())
		return TRUE;        // ok to continue

	CDataRecoveryHandler *pHandler = NULL;
	if (AfxGetApp())
	{
		// if close is triggered by the restart manager, the file
		// will be auto-saved and a prompt for save is not permitted.
		pHandler = AfxGetApp()->GetDataRecoveryHandler();
		if (pHandler != NULL)
		{
			if (pHandler->GetShutdownByRestartManager())
				return TRUE;
		}
	}

	// get name/title of document
	CString name;
	if (m_strPathName.IsEmpty())
	{
		// get name based on caption
		name = m_strTitle;

		if (pHandler != NULL)
		{
			// remove "[recovered]" from the title if it exists
			CString strNormalTitle = pHandler->GetNormalDocumentTitle(this);
			if (!strNormalTitle.IsEmpty())
				name = strNormalTitle;
		}

		if (name.IsEmpty())
			ENSURE(name.LoadString(AFX_IDS_UNTITLED));
	}
	else
	{
		// get name based on file title of path name
		name = m_strPathName;
		AfxGetFileTitle(m_strPathName, name.GetBuffer(_MAX_PATH), _MAX_PATH);
		name.ReleaseBuffer();
	}

	CString prompt;
	AfxFormatString1(prompt, AFX_IDP_ASK_TO_SAVE, name);
	switch (AfxMessageBox(prompt, MB_YESNOCANCEL, AFX_IDP_ASK_TO_SAVE))
	{
	case IDCANCEL:
		return FALSE;       // don't continue

	case IDYES:
		// If so, either Save or Update, as appropriate
		if (!DoFileSave())
			return FALSE;       // don't continue
		break;

	case IDNO:
		// If not saving changes, revert the document
		break;

	default:
		ASSERT(FALSE);
		break;
	}
	return TRUE;    // keep going
}

HMENU CDocument::GetDefaultMenu()
{
	return NULL;    // just use original default
}

HACCEL CDocument::GetDefaultAccelerator()
{
	return NULL;    // just use original default
}

void CDocument::ReportSaveLoadException(LPCTSTR lpszPathName,
	CException* e, BOOL bSaving, UINT nIDPDefault)
{
	UINT nIDP = nIDPDefault;
	UINT nHelpContext = nIDPDefault;
	CString prompt;

	if (e != NULL)
	{
		ASSERT_VALID(e);
		if (e->IsKindOf(RUNTIME_CLASS(CUserException)))
			return; // already reported

		if (e->IsKindOf(RUNTIME_CLASS(CArchiveException)))
		{
			switch (((CArchiveException*)e)->m_cause)
			{
			case CArchiveException::badSchema:
			case CArchiveException::badClass:
			case CArchiveException::badIndex:
			case CArchiveException::endOfFile:
				nIDP = AFX_IDP_FAILED_INVALID_FORMAT;
				break;
			default:
				break;
			}
		}
		else if (e->IsKindOf(RUNTIME_CLASS(CFileException)))
		{
			TRACE(traceAppMsg, 0, "Reporting file I/O exception on Save/Load with lOsError = $%lX.\n",
				((CFileException*)e)->m_lOsError);

			CFileException* pFileException = (CFileException*)e;
			if (pFileException->m_strFileName.IsEmpty())
				pFileException->m_strFileName = lpszPathName;

			LPTSTR lpszMessage = prompt.GetBuffer(_MAX_PATH);
			ASSERT(lpszMessage != NULL);
			if (!e->GetErrorMessage(lpszMessage, _MAX_PATH-1, &nHelpContext))
			{
				switch (((CFileException*)e)->m_cause)
				{
					case CFileException::fileNotFound:
					case CFileException::badPath:
						nIDP = AFX_IDP_FAILED_INVALID_PATH;
						break;
					case CFileException::diskFull:
						nIDP = AFX_IDP_FAILED_DISK_FULL;
						break;
					case CFileException::accessDenied:
						nIDP = bSaving ? AFX_IDP_FAILED_ACCESS_WRITE :
								AFX_IDP_FAILED_ACCESS_READ;
						break;

					case CFileException::badSeek:
					case CFileException::genericException:
					case CFileException::tooManyOpenFiles:
					case CFileException::invalidFile:
					case CFileException::hardIO:
					case CFileException::directoryFull:
						break;

					default:
						break;
				}
			}
			prompt.ReleaseBuffer();
		}
	}

	if (prompt.IsEmpty())
	{
		TCHAR szTitle[_MAX_PATH];
		AfxGetFileTitle(lpszPathName, szTitle, _countof(szTitle));
		AfxFormatString1(prompt, nIDP, szTitle);
	}

	AfxMessageBox(prompt, MB_ICONEXCLAMATION, nHelpContext);
}

/////////////////////////////////////////////////////////////////////////////
// File operations (default uses CDocument::Serialize)

BOOL CMirrorFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags,
	CFileException* pError)
{
	ASSERT(lpszFileName != NULL);
	m_strMirrorName.Empty();

	CFileStatus status;
	if (nOpenFlags & CFile::modeCreate) //opened for writing
	{
		if (CFile::GetStatus(lpszFileName, status))
		{
			CString strRoot;
			AfxGetRoot(lpszFileName, strRoot);

			DWORD dwSecPerClus, dwBytesPerSec, dwFreeClus, dwTotalClus;
			int nBytes = 0;
			if (GetDiskFreeSpace(strRoot, &dwSecPerClus, &dwBytesPerSec, &dwFreeClus,
				&dwTotalClus))
			{
				nBytes = dwFreeClus*dwSecPerClus*dwBytesPerSec;
			}
			if (nBytes > 2*status.m_size) // at least 2x free space avail
			{
				// get the directory for the file
				TCHAR szPath[_MAX_PATH];
				LPTSTR lpszName;
				GetFullPathName(lpszFileName, _MAX_PATH, szPath, &lpszName);
				*lpszName = NULL;

				//let's create a temporary file name
				GetTempFileName(szPath, _T("MFC"), 0,
					m_strMirrorName.GetBuffer(_MAX_PATH+1));
				m_strMirrorName.ReleaseBuffer();
			}
		}
	}

	if (!m_strMirrorName.IsEmpty() &&
		CFile::Open(m_strMirrorName, nOpenFlags, pError))
	{
		m_strFileName = lpszFileName;
		FILETIME ftCreate, ftAccess, ftModify;
		if (::GetFileTime((HANDLE)m_hFile, &ftCreate, &ftAccess, &ftModify))
		{
			AfxTimeToFileTime(status.m_ctime, &ftCreate);
			SetFileTime((HANDLE)m_hFile, &ftCreate, &ftAccess, &ftModify);
		}

		DWORD dwLength = 0;
		PSECURITY_DESCRIPTOR pSecurityDescriptor = NULL;
		if (GetFileSecurity(lpszFileName, DACL_SECURITY_INFORMATION,
			NULL, dwLength, &dwLength))
		{
			pSecurityDescriptor = (PSECURITY_DESCRIPTOR) new BYTE[dwLength];
			if (::GetFileSecurity(lpszFileName, DACL_SECURITY_INFORMATION,
				pSecurityDescriptor, dwLength, &dwLength))
			{
				SetFileSecurity(m_strMirrorName, DACL_SECURITY_INFORMATION, pSecurityDescriptor);
			}
			delete[] (BYTE*)pSecurityDescriptor;
		}
		return TRUE;
	}
	m_strMirrorName.Empty();
	return CFile::Open(lpszFileName, nOpenFlags, pError);
}

void CMirrorFile::Abort()
{
	CFile::Abort();
	if (!m_strMirrorName.IsEmpty())
		CFile::Remove(m_strMirrorName);
}

void CMirrorFile::Close()
{
	CString strName = m_strFileName; //file close empties string
	CFile::Close();
	if (!m_strMirrorName.IsEmpty())
	{
		if(!ReplaceFile(strName, m_strMirrorName, NULL, 0, NULL, NULL))
		{
			CFile::Remove(strName);
			CFile::Rename(m_strMirrorName, strName);
		}
	}
}

CFile* CDocument::GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
	CFileException* pError)
{
	CMirrorFile* pFile = new CMirrorFile;
	ASSERT(pFile != NULL);
	if (!pFile->Open(lpszFileName, nOpenFlags, pError))
	{
		delete pFile;
		pFile = NULL;
	}
	return pFile;
}

void CDocument::ReleaseFile(CFile* pFile, BOOL bAbort)
{
	ASSERT_KINDOF(CFile, pFile);
	if (bAbort)
		pFile->Abort(); // will not throw an exception
	else
		pFile->Close();
	delete pFile;
}

BOOL CDocument::OnNewDocument()
{
#ifdef _DEBUG
	if(IsModified())
		TRACE(traceAppMsg, 0, "Warning: OnNewDocument replaces an unsaved document.\n");
#endif

	DeleteContents();
	m_strPathName.Empty();      // no path name yet
	SetModifiedFlag(FALSE);     // make clean
	OnDocumentEvent(onAfterNewDocument);

	return TRUE;
}

BOOL CDocument::OnOpenDocument(LPCTSTR lpszPathName)
{
#ifdef _DEBUG
	if (IsModified())
		TRACE(traceAppMsg, 0, "Warning: OnOpenDocument replaces an unsaved document.\n");
#endif

	ENSURE(lpszPathName);

	CFileException* pfe = new CFileException;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, pfe);
	if (pFile == NULL)
	{
		TRY
		{
			ReportSaveLoadException(lpszPathName, pfe,
				FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		}
		END_TRY
		DELETE_EXCEPTION(pfe);
		return FALSE;
	}

	DELETE_EXCEPTION(pfe);

	DeleteContents();
	SetModifiedFlag();  // dirty during de-serialize

	CArchive loadArchive(pFile, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_pDocument = this;
	loadArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		if (pFile->GetLength() != 0)
			Serialize(loadArchive);     // load me
		loadArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);
		DeleteContents();   // remove failed contents

		TRY
		{
			ReportSaveLoadException(lpszPathName, e,
				FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		}
		END_TRY
		DELETE_EXCEPTION(e);
		return FALSE;
	}
	END_CATCH_ALL

	SetModifiedFlag(FALSE);     // start off with unmodified

	return TRUE;
}

BOOL CDocument::OnSaveDocument(LPCTSTR lpszPathName)
{
	ENSURE(lpszPathName);

	CFileException *pfe = new CFileException;
	CFile* pFile = NULL;
	pFile = GetFile(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, pfe);

	if (pFile == NULL)
	{
		TRY
		{
			ReportSaveLoadException(lpszPathName, pfe,
				TRUE, AFX_IDP_INVALID_FILENAME);
		}
		END_TRY
		DELETE_EXCEPTION(pfe);
		return FALSE;
	}

	DELETE_EXCEPTION(pfe);

	CArchive saveArchive(pFile, CArchive::store | CArchive::bNoFlushOnDelete);
	saveArchive.m_pDocument = this;
	saveArchive.m_bForceFlat = FALSE;
	TRY
	{
		CWaitCursor wait;
		Serialize(saveArchive);     // save me
		saveArchive.Close();
		ReleaseFile(pFile, FALSE);
	}
	CATCH_ALL(e)
	{
		ReleaseFile(pFile, TRUE);

		TRY
		{
			ReportSaveLoadException(lpszPathName, e,
				TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
		}
		END_TRY
		DELETE_EXCEPTION(e);
		return FALSE;
	}
	END_CATCH_ALL

	SetModifiedFlag(FALSE);     // back to unmodified

	return TRUE;        // success
}

void CDocument::OnCloseDocument()
	// must close all views now (no prompting) - usually destroys this
{
	// search/organize/preview handler can be destroyed only from FinalRelease 
	if (IsSearchAndOrganizeHandler() && !m_bFinalRelease)
	{
		return;
	}

	// destroy all frames viewing this document
	// the last destroy may destroy us
	BOOL bAutoDelete = m_bAutoDelete;
	m_bAutoDelete = FALSE;  // don't destroy document while closing views
	while (!m_viewList.IsEmpty())
	{
		// get frame attached to the view
		CView* pView = (CView*)m_viewList.GetHead();
		ASSERT_VALID(pView);
		CFrameWnd* pFrame = pView->EnsureParentFrame();

		// and close it
		PreCloseFrame(pFrame);
		pFrame->DestroyWindow();
			// will destroy the view as well
	}
	m_bAutoDelete = bAutoDelete;
	OnDocumentEvent(onAfterCloseDocument);

	// clean up contents of document before destroying the document itself
	DeleteContents();

	// delete the document if necessary
	if (m_bAutoDelete)
		delete this;
}

void CDocument::OnDocumentEvent(DocumentEvent deEvent)
{
	// check if recovery handling is enabled...
	CWinApp *pApp = AfxGetApp();
	if (pApp != NULL)
	{
		CDataRecoveryHandler *pHandler = pApp->GetDataRecoveryHandler();
		if (pHandler != NULL)
		{
			// ...and if so, notify of the specified event.
			switch (deEvent)
			{
				case onAfterNewDocument:
				{
					// add the document to the open document list.
					pHandler->CreateDocumentInfo(this);
					break;
				}

				case onAfterOpenDocument:
				{
					// add the document to the open document list.
					pHandler->CreateDocumentInfo(this);
					break;
				}

				case onAfterSaveDocument:
				{
					// update the document info (filename may have changed).
					pHandler->UpdateDocumentInfo(this);
					break;
				}

				case onAfterCloseDocument:
				{
					// remove any document auto-save info, as long as the
					// restart manager is not actually causing the close.
					if (!pHandler->GetShutdownByRestartManager())
					{
						pHandler->RemoveDocumentInfo(this);
					}
					break;
				}
			}
		}
	}
}

void CDocument::OnIdle()
{
	// check if recovery handling is enabled...
	CWinApp *pApp = AfxGetApp();
	if (pApp != NULL)
	{
		CDataRecoveryHandler *pHandler = pApp->GetDataRecoveryHandler();
		if ((pHandler != NULL) && (pHandler->GetSaveDocumentInfoOnIdle()))
		{
			// ...and if so, save the document info.  Note that the info is saved
			// even if the document is not modified (for reopen on restart), but
			// the content is auto-saved only if the document is modified.
			pHandler->AutosaveDocumentInfo(this);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// View operations

void CDocument::AddView(CView* pView)
{
	ASSERT_VALID(pView);
	ASSERT(pView->m_pDocument == NULL); // must not be already attached
	ASSERT(m_viewList.Find(pView, NULL) == NULL);   // must not be in list

	m_viewList.AddTail(pView);
	ASSERT(pView->m_pDocument == NULL); // must be un-attached
	pView->m_pDocument = this;

	OnChangedViewList();    // must be the last thing done to the document
}

void CDocument::RemoveView(CView* pView)
{
	ASSERT_VALID(pView);
	ASSERT(pView->m_pDocument == this); // must be attached to us

	m_viewList.RemoveAt(m_viewList.Find(pView));
	pView->m_pDocument = NULL;

	OnChangedViewList();    // must be the last thing done to the document
}

POSITION CDocument::GetFirstViewPosition() const
{
	return m_viewList.GetHeadPosition();
}

CView* CDocument::GetNextView(POSITION& rPosition) const
{
	ASSERT(rPosition != BEFORE_START_POSITION);
		// use CDocument::GetFirstViewPosition instead !
	if (rPosition == NULL)
		return NULL;    // nothing left
	CView* pView = (CView*)m_viewList.GetNext(rPosition);
	ASSERT_KINDOF(CView, pView);
	return pView;
}

void CDocument::UpdateAllViews(CView* pSender, LPARAM lHint, CObject* pHint)
	// walk through all views
{
	ASSERT(pSender == NULL || !m_viewList.IsEmpty());
		// must have views if sent by one of them

	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		if (pView != pSender)
			pView->OnUpdate(pSender, lHint, pHint);
	}
}

void CDocument::SendInitialUpdate()
	// walk through all views and call OnInitialUpdate
{
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
		pView->OnInitialUpdate();
	}
}

/////////////////////////////////////////////////////////////////////////////
// command routing

BOOL CDocument::OnCmdMsg(UINT nID, int nCode, void* pExtra,
	AFX_CMDHANDLERINFO* pHandlerInfo)
{
	if (CCmdTarget::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise check template
	if (m_pDocTemplate != NULL &&
	  m_pDocTemplate->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////
// CDocument search/organize/preview/live-icon support
HRESULT CDocument::LoadDocumentFromStream(IStream* pStream, DWORD grfMode)
{
	ASSERT_VALID(this);
	return OnLoadDocumentFromStream(pStream, grfMode);
}

void CDocument::OnUnloadHandler()
{
}

HRESULT CDocument::OnLoadDocumentFromStream(IStream* pStream, DWORD grfMode)
{
	UNREFERENCED_PARAMETER(grfMode);

	ASSERT(pStream != NULL);
	if (pStream == NULL)
	{
		return E_INVALIDARG;
	}
	
	COleStreamFile file;
	file.Attach(pStream);

	CArchive loadArchive(&file, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_pDocument = this;
	loadArchive.m_bForceFlat = FALSE;

	HRESULT hr = S_OK;
	TRY
	{
		Serialize (loadArchive);
		loadArchive.Close();
	}
	CATCH_ALL(e)
	{
		DELETE_EXCEPTION(e);
		TRACE0("Error: CDocument::OnLoadDocumentFromStream - serialization from stream failed.");
		hr = E_FAIL;
	}
	END_CATCH_ALL

	return hr;
}

HRESULT CDocument::OnPreviewHandlerQueryFocus(HWND* phwnd)
{
	if (phwnd == NULL)
	{
		TRACE0("Error: IPreviewHandler::QueryFocus called with NULL pointer.");
		return E_INVALIDARG;
	}

	*phwnd = ::GetFocus();
	HRESULT hr = S_OK;

	if (*phwnd == NULL)
	{
		hr = HRESULT_FROM_WIN32(GetLastError());
	}

	return hr;
}
HRESULT CDocument::OnPreviewHandlerTranslateAccelerator(MSG* pmsg)
{
	HRESULT hr = S_FALSE;
	UNREFERENCED_PARAMETER(pmsg);

	if (m_pPreviewHandlerSite != NULL)
	{
		//
		// If previewer has multiple tab stops, it's needed to do appropriate first/last child checking.
		// This sample previewer has no tabstops, so we want to just forward this message out 
		//
		hr = m_pPreviewHandlerSite->TranslateAccelerator(pmsg);
	}

	return hr;
}

BOOL CDocument::OnCreatePreviewFrame()
{
	CWinApp* pApp = AfxGetApp();
	ASSERT_VALID(pApp);
	POSITION pos = pApp->GetFirstDocTemplatePosition();

	while (pos != NULL)
	{
		CDocTemplate* pDocTemplate = (CDocTemplate*) pApp->GetNextDocTemplate(pos);
		ASSERT_VALID(pDocTemplate);
		if (pDocTemplate->m_pDocClass == GetRuntimeClass())
		{
			m_pPreviewFrame = pDocTemplate->CreatePreviewFrame(CWnd::FromHandle(m_hWndHost), this);
			ASSERT_VALID(m_pPreviewFrame);
			break;
		}
	}

	if (m_pPreviewFrame == NULL)
	{
		TRACE0("Error: Document was unable to create preview frame.");
		return FALSE;
	}

	CWnd* pWnd = m_pPreviewFrame->GetDescendantWindow(AFX_IDW_PANE_FIRST);

	// ensure it's first in the view list
	if (pWnd != NULL)
	{
		POSITION pos = m_viewList.Find(pWnd);
		if (pos != NULL)
		{
			m_viewList.RemoveAt(pos);
			m_viewList.AddHead(pWnd);
		}
	}

	m_pPreviewFrame->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, 0);

	for (POSITION pos = GetFirstViewPosition(); pos != NULL;)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);

		pView->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, 0);

		if (m_pPreviewFrame->GetActiveView() == NULL && m_pPreviewFrame->IsChild(pView))
		{
			m_pPreviewFrame->SetActivePreviewView(pView);
		}
	}

	return TRUE;
}

BOOL CDocument::GetThumbnail(UINT cx, HBITMAP* phbmp, WTS_ALPHATYPE* pdwAlpha)
{
	ASSERT(phbmp != NULL);
	if (pdwAlpha != NULL)
	{
		*pdwAlpha = WTSAT_UNKNOWN;
	}

	HDC hdc = ::GetDC(NULL);
	CDC* pDC = CDC::FromHandle(hdc);
	CDC dc;
	CDC* pDrawDC = pDC;
	CBitmap* pOldBitmap = NULL;
	CBitmap bitmap;

	// Here you need  to calculate document area to be displayed on the Live Icon
	CRect rectDocBounds = CRect(0, 0, cx, cx);

	if (dc.CreateCompatibleDC(pDC))
	{
		if (bitmap.CreateCompatibleBitmap(pDC, rectDocBounds.Width(), rectDocBounds.Height()))
		{
			pDrawDC = &dc;
			pOldBitmap = dc.SelectObject(&bitmap);
		}
	}
	else
	{
		::ReleaseDC(NULL, hdc);
		return FALSE;
	}

	dc.SelectObject(&bitmap);

	OnDrawThumbnail(dc, &rectDocBounds);

	if (pDrawDC != pDC)
	{
		dc.SelectObject(pOldBitmap);
	}

	::ReleaseDC(NULL, hdc);
	*phbmp = (HBITMAP)bitmap.Detach();

	return TRUE;
}

BOOL CDocument::IsSearchAndOrganizeHandler() const
{
	return m_bPreviewHandlerMode || m_bSearchMode || m_bGetThumbnailMode;
}

void CDocument::OnRichPreviewUnload()
{
	m_bModified = FALSE;

	// tell the document to clear data.
	// sometimes Release is not called after unload
	// therefore the data must be unloaded here
	OnUnloadHandler();
	DeleteContents();

	if (m_pPreviewHandlerSite != NULL)
	{
		m_pPreviewHandlerSite->Release();
		m_pPreviewHandlerSite = NULL;
	}

	if (m_pPreviewFrame != NULL && IsWindow(m_pPreviewFrame->GetSafeHwnd()))
	{
		m_pPreviewFrame->SetActiveView(NULL);
		::DestroyWindow(m_pPreviewFrame->GetSafeHwnd());
		m_pPreviewFrame = NULL;
	}

	if (m_pStream != NULL)
	{
		// if stream is not NULL it has not been released yet
		m_pStream->Release();
		m_pStream = NULL;
	}

	m_hWndHost = NULL;
	m_rectHost.SetRectEmpty();
	m_grfMode = 0;
}

#if WINVER >= 0x0600
/////////////////////////////////////////////////////////////////////////////
// IInitializeWithStream interface implementation
STDMETHODIMP_(ULONG) CDocument::XInitializeWithStream::AddRef()
{
	METHOD_PROLOGUE_EX(CDocument, InitializeWithStream)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CDocument::XInitializeWithStream::Release()
{
	METHOD_PROLOGUE_EX(CDocument, InitializeWithStream)
	return pThis->ExternalRelease();
}

STDMETHODIMP CDocument::XInitializeWithStream::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX(CDocument, InitializeWithStream);
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CDocument::XInitializeWithStream::Initialize(IStream* pStream, DWORD grfMode)
{
	METHOD_PROLOGUE(CDocument, InitializeWithStream);
	if (pStream == NULL)
	{
		TRACE0("Error: IInitializeWithStream::Iniitalize called with pStream = NULL");
		return E_INVALIDARG;
	}

	pThis->m_bPreviewHandlerMode = TRUE;
	pThis->m_bAutoDelete = false;

	pStream->AddRef();
	pThis->m_pStream = pStream;
	pThis->m_grfMode = grfMode;

	if (!pThis->m_bOLELocked)
	{
		AfxOleLockApp();
		pThis->m_bOLELocked = TRUE;
	}

	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// IPreviewHandler interface implementation
STDMETHODIMP_(ULONG) CDocument::XPreviewHandler::AddRef()
{
	METHOD_PROLOGUE_EX(CDocument, PreviewHandler)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CDocument::XPreviewHandler::Release()
{
	METHOD_PROLOGUE_EX(CDocument, PreviewHandler)
	return pThis->ExternalRelease();
}

STDMETHODIMP CDocument::XPreviewHandler::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX(CDocument, PreviewHandler)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CDocument::XPreviewHandler::SetWindow(HWND hwnd, const RECT *prc)
{
	METHOD_PROLOGUE(CDocument, PreviewHandler);

	pThis->m_hWndHost = hwnd;
	if (prc != NULL)
	{
		pThis->m_rectHost = *prc;
	}
	
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandler::SetRect(const RECT *prc)
{
	METHOD_PROLOGUE(CDocument, PreviewHandler);
	if (prc == NULL)
	{
		TRACE0("Error: IPreviewHandler::SetRect failed, because prc = NULL");
		return E_INVALIDARG;
	}

	pThis->m_rectHost = *prc;

	if (pThis->m_pPreviewFrame != NULL)
	{
		ASSERT_VALID(pThis->m_pPreviewFrame);
		pThis->m_pPreviewFrame->SetWindowPos(NULL, 0, 0, pThis->m_rectHost.Width(), pThis->m_rectHost.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
		pThis->UpdateAllViews(NULL);
	}
	
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandler::DoPreview()
{
	METHOD_PROLOGUE(CDocument, PreviewHandler);

	if (pThis->m_pStream == NULL)
	{
		TRACE0("Error: IPreviewHandler::DoPreview is called, but m_pStream is NULL.");
		return E_FAIL;
	}

	pThis->m_bEmbedded = TRUE;
	pThis->OnNewDocument();

	if (!pThis->OnCreatePreviewFrame())
	{
		return E_FAIL;
	}

	ASSERT_VALID(pThis->m_pPreviewFrame);

	HRESULT hr = S_OK;
	TRY
	{
		hr = pThis->LoadDocumentFromStream(pThis->m_pStream, pThis->m_grfMode);
	}
	CATCH_ALL(e)
	{
		DELETE_EXCEPTION(e);
		TRACE0("Error: DoPreview failed because LoadDocumentFromStream has thrown an exception.");
		hr = E_FAIL;
	}
	END_CATCH_ALL

	// release the stream immediately
	pThis->m_pStream->Release();
	pThis->m_pStream = NULL;

	if (hr != S_OK)
	{
		return hr;
	}

	CRect rectHost = pThis->m_rectHost;
	pThis->m_pPreviewFrame->SetWindowPos(NULL, rectHost.left, rectHost.top, rectHost.Width(), rectHost.Height(), SWP_NOZORDER | SWP_NOACTIVATE);

	pThis->m_pPreviewFrame->ShowWindow(SW_SHOW);
	pThis->SendInitialUpdate();

	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandler::Unload()
{
	METHOD_PROLOGUE(CDocument, PreviewHandler);
	pThis->OnRichPreviewUnload();
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandler::SetFocus()
{
	METHOD_PROLOGUE(CDocument, PreviewHandler)

	if (pThis->m_pPreviewFrame != NULL && IsWindow(pThis->m_pPreviewFrame->GetSafeHwnd()))
	{
		ASSERT_VALID(pThis->m_pPreviewFrame);
		pThis->m_pPreviewFrame->SetFocus();
	}
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandler::QueryFocus(HWND *phwnd)
{
	METHOD_PROLOGUE(CDocument, PreviewHandler)
	return pThis->OnPreviewHandlerQueryFocus(phwnd);
}

STDMETHODIMP CDocument::XPreviewHandler::TranslateAccelerator(MSG *pmsg)
{
	METHOD_PROLOGUE(CDocument, PreviewHandler)
	return pThis->OnPreviewHandlerTranslateAccelerator(pmsg);
}

/////////////////////////////////////////////////////////////////////////////
// IPreviewHandlerVisuals interface implementation
STDMETHODIMP_(ULONG) CDocument::XPreviewHandlerVisuals::AddRef()
{
	METHOD_PROLOGUE_EX(CDocument, PreviewHandlerVisuals)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CDocument::XPreviewHandlerVisuals::Release()
{
	METHOD_PROLOGUE_EX(CDocument, PreviewHandlerVisuals)
	return pThis->ExternalRelease();
}

STDMETHODIMP CDocument::XPreviewHandlerVisuals::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE(CDocument, PreviewHandlerVisuals)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CDocument::XPreviewHandlerVisuals::SetBackgroundColor(COLORREF color)
{
	METHOD_PROLOGUE(CDocument, PreviewHandlerVisuals)
	pThis->m_clrRichPreviewBackColor = color;
	pThis->OnRichPreviewBackColorChanged();
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandlerVisuals::SetFont(const LOGFONTW *plf)
{
	METHOD_PROLOGUE(CDocument, PreviewHandlerVisuals)
	if (plf == NULL)
	{
		return E_POINTER;
	}
	
	pThis->OnBeforeRichPreviewFontChanged();
	pThis->m_lfRichPreviewFont.DeleteObject();

#ifdef _UNICODE
	pThis->m_lfRichPreviewFont.CreateFontIndirect(plf);
#else
	LOGFONTA lf;
	memcpy(&lf, plf, sizeof(LOGFONTA));

	size_t  i;
	size_t	bufSize = 32;
	wcstombs_s(&i, lf.lfFaceName, bufSize, plf->lfFaceName, bufSize);
	pThis->m_lfRichPreviewFont.CreateFontIndirect(&lf);
#endif
	
	pThis->OnRichPreviewFontChanged();
	return S_OK;
}

STDMETHODIMP CDocument::XPreviewHandlerVisuals::SetTextColor(COLORREF color)
{
	METHOD_PROLOGUE(CDocument, PreviewHandlerVisuals)
	pThis->m_clrRichPreviewTextColor = color;
	pThis->OnRichPreviewTextColorChanged();
	return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// IObjectWithSite interface implementation
STDMETHODIMP_(ULONG) CDocument::XObjectWithSite::AddRef()
{
	METHOD_PROLOGUE_EX(CDocument, ObjectWithSite)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CDocument::XObjectWithSite::Release()
{
	METHOD_PROLOGUE_EX(CDocument, ObjectWithSite)
	return pThis->ExternalRelease();
}

STDMETHODIMP CDocument::XObjectWithSite::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX(CDocument, ObjectWithSite)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CDocument::XObjectWithSite::SetSite(IUnknown *punkSite)
{
	METHOD_PROLOGUE(CDocument, ObjectWithSite);
	pThis->m_spUnkSite = punkSite;
	//
	// Clean up old frame
	//
	if (pThis->m_pPreviewHandlerSite != NULL)
	{
		pThis->m_pPreviewHandlerSite->Release();
		pThis->m_pPreviewHandlerSite = NULL;
	}

	//
	// Get the new frame
	//
	if (pThis->m_spUnkSite)
	{
		pThis->m_spUnkSite->QueryInterface(IID_PPV_ARGS(&pThis->m_pPreviewHandlerSite));
	}

	pThis->OnRichPreviewSiteChanged();

	return S_OK;
}

STDMETHODIMP CDocument::XObjectWithSite::GetSite(REFIID riid, void **ppvSite)
{
	METHOD_PROLOGUE(CDocument, ObjectWithSite)

	ASSERT(ppvSite != NULL);
	HRESULT hRes = E_POINTER;
	if (ppvSite != NULL)
	{
		if (pThis->m_spUnkSite)
			hRes = pThis->m_spUnkSite->QueryInterface(riid, ppvSite);
		else
		{
			*ppvSite = NULL;
			hRes = E_FAIL;
		}
	}
	return hRes;
}
/////////////////////////////////////////////////////////////////////////////
// IOleWindow interface implementation
STDMETHODIMP_(ULONG) CDocument::XOleWindow::AddRef()
{
	METHOD_PROLOGUE_EX(CDocument, OleWindow)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CDocument::XOleWindow::Release()
{
	METHOD_PROLOGUE_EX(CDocument, OleWindow)
	return pThis->ExternalRelease();
}

STDMETHODIMP CDocument::XOleWindow::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX(CDocument, OleWindow);
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CDocument::XOleWindow::GetWindow(HWND *phwnd)
{
	METHOD_PROLOGUE(CDocument, OleWindow);

	HRESULT hr = E_INVALIDARG;
	if (phwnd != NULL)
	{
		*phwnd = pThis->m_hWndHost; 
		hr = S_OK;
	}

	return hr;
}

STDMETHODIMP CDocument::XOleWindow::ContextSensitiveHelp(BOOL)
{
	METHOD_PROLOGUE(CDocument, OleWindow);
	return E_NOTIMPL;
}
#endif

void CDocument::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	UNREFERENCED_PARAMETER(dc);
	UNREFERENCED_PARAMETER(lprcBounds);
}

void CDocument::ClearChunkList()
{
	m_posReadChunk = NULL;

	POSITION pos = m_lstChunks.GetHeadPosition();
	while (pos != NULL)
	{
		IFilterChunkValue* v = (IFilterChunkValue*) m_lstChunks.GetNext(pos);
		if (v != NULL)
		{
			delete v;
		}
	}

	m_lstChunks.RemoveAll();
}

BOOL CDocument::SetChunkValue(IFilterChunkValue* pValue)
{
	if (pValue == NULL || !pValue->IsValid())
	{
		return false;
	}

	POSITION pos = FindChunk(pValue->GetChunkGUID(), pValue->GetChunkPID());

	if (pos == NULL)
	{
		m_lstChunks.AddTail(pValue);
	}

	return TRUE;
}

void CDocument::BeginReadChunks()
{
	m_posReadChunk = m_lstChunks.GetHeadPosition();
}

BOOL CDocument::ReadNextChunkValue(IFilterChunkValue** ppValue)
{
	if (m_posReadChunk == NULL || ppValue == NULL)
	{
		return FALSE;
	}

	*ppValue = (IFilterChunkValue*) m_lstChunks.GetNext(m_posReadChunk);
	return TRUE;
}

void CDocument::RemoveChunk(REFCLSID guid, DWORD pid)
{
	POSITION pos = FindChunk(guid, pid);
	if (pos != NULL)
	{
		delete m_lstChunks.GetAt(pos);
		m_lstChunks.RemoveAt(pos);
	}
}

POSITION CDocument::FindChunk(REFCLSID guid, DWORD pid)
{
	POSITION value = NULL;
	POSITION pos = m_lstChunks.GetHeadPosition();
	POSITION posPrev = NULL;
	while (pos != NULL)
	{
		posPrev = pos;
		IFilterChunkValue* v = (IFilterChunkValue*) m_lstChunks.GetNext(pos);
		if (IsEqualIID(v->GetChunkGUID(), guid) && v->GetChunkPID() == pid)
		{
			value = posPrev;
			break;
		}
	}

	return value;
}

/////////////////////////////////////////////////////////////////////////////
// CDocument diagnostics

#ifdef _DEBUG
void CDocument::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);

	dc << "m_strTitle = " << m_strTitle;
	dc << "\nm_strPathName = " << m_strPathName;
	dc << "\nm_bModified = " << m_bModified;
	dc << "\nm_pDocTemplate = " << (void*)m_pDocTemplate;

	if (dc.GetDepth() > 0)
	{
		POSITION pos = GetFirstViewPosition();
		while (pos != NULL)
		{
			CView* pView = GetNextView(pos);
			dc << "\nwith view " << (void*)pView;
		}
	}

	dc << "\n";
}

void CDocument::AssertValid() const
{
	CObject::AssertValid();

	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CView* pView = GetNextView(pos);
		ASSERT_VALID(pView);
	}
}
#endif //_DEBUG

IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)

/////////////////////////////////////////////////////////////////////////////
CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl()
{
	Clear();
}

CMFCFilterChunkValueImpl::~CMFCFilterChunkValueImpl()
{
	// NOTE, the member m_propVariant is not a real allocated variant using CoTaskMemAlloc, so do not call PropVariantClear() on it
	Clear();
}

void CMFCFilterChunkValueImpl::Clear()
{
	m_fIsValid = false;
	ZeroMemory(&m_chunk, sizeof(m_chunk));
	PropVariantInit(&m_propVariant);
	m_strValue.Empty();
}

HRESULT CMFCFilterChunkValueImpl::GetValue(PROPVARIANT **ppPropVariant)
{
	HRESULT hr = S_OK;
	if (ppPropVariant == NULL)
		return E_INVALIDARG;

	*ppPropVariant = NULL;

	CComHeapPtr<PROPVARIANT> spPropVariant;

	// allocate a propvariant on the COM heap
	if (spPropVariant.Allocate())
	{
		// fill it with COMHeap copied data from our local non-com heap propvariant 
		hr = PropVariantCopy(spPropVariant, &m_propVariant);
	}
	else
	{
		hr = E_OUTOFMEMORY;
	}

	if (SUCCEEDED(hr))
	{
		// detach and return this as the value
		*ppPropVariant = spPropVariant.Detach();
	}
	return hr;
}

HRESULT CMFCFilterChunkValueImpl::CopyChunk(STAT_CHUNK *pStatChunk)
{
	if (pStatChunk == NULL)
		return E_INVALIDARG;

	*pStatChunk = m_chunk;
	return S_OK;
}

HRESULT CMFCFilterChunkValueImpl::SetTextValue(REFPROPERTYKEY pkey, LPCTSTR pszValue, CHUNKSTATE chunkType /*= CHUNK_VALUE*/, LCID locale/* = 0*/,
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	if (pszValue == NULL)
		return E_INVALIDARG;

	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_strValue = pszValue;
#ifdef UNICODE
		m_propVariant.vt = VT_LPWSTR;
		m_propVariant.pwszVal = (LPWSTR)(LPCTSTR)m_strValue;
#else
		m_propVariant.vt = VT_LPSTR;
		m_propVariant.pszVal = (LPSTR)(LPCTSTR)m_strValue;
#endif
		m_fIsValid = true;
	}
	return hr;
};
HRESULT CMFCFilterChunkValueImpl::SetBoolValue(REFPROPERTYKEY pkey, BOOL bVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/, 
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	return SetBoolValue(pkey, bVal ? VARIANT_TRUE : VARIANT_FALSE, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
};
HRESULT CMFCFilterChunkValueImpl::SetBoolValue(REFPROPERTYKEY pkey, VARIANT_BOOL bVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/, 
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_BOOL;
		m_propVariant.boolVal = bVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetIntValue(REFPROPERTYKEY pkey, int nVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/,
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_I4;
		m_propVariant.lVal = nVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetLongValue(REFPROPERTYKEY pkey, long lVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/, 
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_I4;
		m_propVariant.lVal = lVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetDwordValue(REFPROPERTYKEY pkey, DWORD dwVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/, 
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_UI4;
		m_propVariant.ulVal = dwVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetInt64Value(REFPROPERTYKEY pkey, __int64 nVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/, 
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_I8;
		m_propVariant.hVal.QuadPart = nVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetSystemTimeValue(REFPROPERTYKEY pkey, const SYSTEMTIME &systemTime, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/,
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_FILETIME;
		SystemTimeToFileTime(&systemTime, &m_propVariant.filetime);
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetFileTimeValue(REFPROPERTYKEY pkey, FILETIME dtVal, CHUNKSTATE chunkType/* = CHUNK_VALUE*/, LCID locale/* = 0*/,
			DWORD cwcLenSource/* = 0*/, DWORD cwcStartSource/* = 0*/, CHUNK_BREAKTYPE chunkBreakType/* = CHUNK_NO_BREAK*/)
{
	HRESULT hr = SetChunk(pkey, chunkType, locale, cwcLenSource, cwcStartSource, chunkBreakType);
	if (SUCCEEDED(hr))
	{
		m_propVariant.vt = VT_FILETIME;
		m_propVariant.filetime = dtVal;
		m_fIsValid = true;
	}
	return hr;
};

HRESULT CMFCFilterChunkValueImpl::SetChunk(REFPROPERTYKEY pkey, CHUNKSTATE chunkType/*=CHUNK_VALUE*/, LCID locale /*=0*/, 
			DWORD cwcLenSource /*=0*/, DWORD cwcStartSource /*=0*/, CHUNK_BREAKTYPE chunkBreakType /*= CHUNK_NO_BREAK */)
{
	Clear();

	// initialize the chunk
	m_chunk.attribute.psProperty.ulKind = PRSPEC_PROPID;
	m_chunk.attribute.psProperty.propid = pkey.pid;
	m_chunk.attribute.guidPropSet = pkey.fmtid;
	m_chunk.flags = chunkType;
	m_chunk.locale = locale == 0 ? GetUserDefaultLCID() : locale;
	m_chunk.cwcLenSource = cwcLenSource;
	m_chunk.cwcStartSource = cwcStartSource;
	m_chunk.breakType = chunkBreakType;

	return S_OK;
}

void CMFCFilterChunkValueImpl::CopyFrom(IFilterChunkValue* pValue)
{
	Clear();

	pValue->CopyChunk(&m_chunk);

	// NOTE this object does not contain a real property variant that was allocated with CoTaskMemAlloc
	m_propVariant = pValue->GetValueNoAlloc();
	m_strValue = pValue->GetString();

	// fix up the string ownership to member
#ifdef UNICODE	
	if (m_propVariant.vt == VT_LPWSTR)
	{
		m_propVariant.pwszVal = (LPWSTR)(LPCTSTR)m_strValue;
	}
#else
	if (m_propVariant.vt == VT_LPSTR)
	{
		m_propVariant.pszVal = (LPSTR)(LPCTSTR)m_strValue;
	}
#endif
	else if (m_propVariant.vt & VT_VECTOR)
	{
	}

	m_fIsValid = pValue->IsValid();

	return;
}
