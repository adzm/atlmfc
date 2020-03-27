// This MFC Library source code supports the Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "msxml2.h"

#include "afxribboninfo.h"
#include "afxtagmanager.h"
#include "atlxml.h"

#pragma comment(lib, "msxml2.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static LPCTSTR s_szTrue            = _T("TRUE");
static LPCTSTR s_szFalse           = _T("FALSE");

static LPCTSTR s_szTag_Body        = _T("AFX_RIBBON");
static LPCTSTR s_szTag_Header      = _T("HEADER");
static LPCTSTR s_szTag_Version     = _T("VERSION");
static LPCTSTR s_szTag_Sizes       = _T("SIZES");
static LPCTSTR s_szTag_RibbonBar   = _T("RIBBON_BAR");

static LPCTSTR s_szTag_Sizes_Small = _T("IMAGE_SMALL");
static LPCTSTR s_szTag_Sizes_Large = _T("IMAGE_LARGE");

CMFCRibbonInfo::XRibbonInfoParserRoot::XRibbonInfoParserRoot()
{
}

CMFCRibbonInfo::XRibbonInfoParserRoot::~XRibbonInfoParserRoot()
{
}

CMFCRibbonInfo::XRibbonInfoParserCollection::XRibbonInfoParserCollection()
{
}

CMFCRibbonInfo::XRibbonInfoParserCollection::~XRibbonInfoParserCollection()
{
}

CMFCRibbonInfo::XRibbonInfoParser::XRibbonInfoParser()
{
}

CMFCRibbonInfo::XRibbonInfoParser::~XRibbonInfoParser()
{
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::ReadColor(const CString& strName, COLORREF& val)
{
	CString strVal;
	if (ReadString(strName, strVal) && !strVal.IsEmpty())
	{
		return CTagManager::ParseColor(strVal, val);
	}

	return FALSE;
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::ReadBool(const CString& strName, BOOL& val)
{
	CString strVal;
	if (ReadString(strName, strVal) && !strVal.IsEmpty())
	{
		strVal.Trim();
		val = strVal == s_szTrue;
		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::ReadSize(const CString& strName, CSize& val)
{
	CString strVal;
	if (ReadString(strName, strVal) && !strVal.IsEmpty())
	{
		return CTagManager::ParseSize(strVal, val);
	}

	return FALSE;
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::ReadInt(const CString& strName, int& val)
{
	CString strVal;
	if (ReadString(strName, strVal) && !strVal.IsEmpty())
	{
		strVal.Trim();
		val = _ttol(strVal);
		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::ReadUInt(const CString& strName, UINT& val)
{
	int nVal = 0;
	if (ReadInt(strName, nVal))
	{
		val = (UINT)nVal;
		return TRUE;
	}

	return FALSE;
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::WriteColor(const CString& strName, COLORREF val, COLORREF /*valDefault*/)
{
#if 0
	if (val == valDefault)
	{
		return TRUE;
	}
#endif

	CString strVal;
	strVal.Format(_T("%d, %d, %d"), GetRValue (val), GetGValue (val), GetBValue (val));

	return WriteString(strName, strVal);
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::WriteBool(const CString& strName, BOOL val, BOOL /*valDefault*/)
{
#if 0
	if (val == valDefault)
	{
		return TRUE;
	}
#endif

	CString strVal;
	if (val)
	{
		strVal = s_szTrue;
	}
	else
	{
		strVal = s_szFalse;
	}

	return WriteString(strName, strVal);
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::WriteSize(const CString& strName, const CSize& val, const CSize& /*valDefault*/)
{
#if 0
	if (val == valDefault)
	{
		return TRUE;
	}
#endif

	CString strVal;
	strVal.Format(_T("%d, %d"), val.cx, val.cy);

	return WriteString(strName, strVal);
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::WriteInt(const CString& strName, int val, int /*valDefault*/)
{
#if 0
	if (val == valDefault)
	{
		return TRUE;
	}
#endif

	CString strVal;
	strVal.Format(_T("%d"), val);

	return WriteString(strName, strVal);
}

BOOL CMFCRibbonInfo::XRibbonInfoParser::WriteUInt(const CString& strName, UINT val, UINT /*valDefault*/)
{
#if 0
	if (val == valDefault)
	{
		return TRUE;
	}
#endif

	CString strVal;
	strVal.Format(_T("%u"), val);

	return WriteString(strName, strVal);
}

class CXMLParser;

class CXMLParserCollection : public CMFCRibbonInfo::XRibbonInfoParserCollection
{
	friend class CXMLParser;

protected:
	CXMLParserCollection(IXMLDOMNodeList* pList);

public:
	virtual ~CXMLParserCollection()
	{
		for (INT_PTR i = 0; i < m_array.GetSize(); i++)
		{
			CMFCRibbonInfo::XRibbonInfoParser* pParser = m_array[i];
			if (pParser != NULL)
			{
				delete pParser;
			}
		}

		m_array.RemoveAll();
	}

	virtual UINT GetCount() const
	{
		return (UINT)m_array.GetSize();
	}

	virtual CMFCRibbonInfo::XRibbonInfoParser* GetItem(UINT nIndex)
	{
		if (nIndex < GetCount())
		{
			return m_array[nIndex];
		}

		return NULL;
	}

private:
	CArray<CMFCRibbonInfo::XRibbonInfoParser*, CMFCRibbonInfo::XRibbonInfoParser*> m_array;
};

class CXMLParser : public CMFCRibbonInfo::XRibbonInfoParser
{
	friend class CXMLParserRoot;
	friend class CXMLParserCollection;

protected:
	CXMLParser(IXMLDOMNode* node) : m_node(node) {}

public:
	CXMLParser() {}
	virtual ~CXMLParser() {}

	virtual BOOL Add(const CString& strName, CMFCRibbonInfo::XRibbonInfoParser** val)
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		if (val == NULL)
		{
			return FALSE;
		}

		CXMLDocument document;
		HRESULT hr = m_node.GetOwnerDocument(document);
		IF_HR_INVALID_RETURN_BOOL(hr);

		CXMLNode<IXMLDOMElement> element;
		hr = document.CreateElement(strName, element);
		IF_HR_INVALID_RETURN_BOOL(hr);

		hr = m_node.AppendChild(element);
		IF_HR_INVALID_RETURN_BOOL(hr);

		*val = new CXMLParser(element);

		return HR_SUCCEEDED_OK(hr);
	}

	virtual BOOL Read(const CString& strName, CMFCRibbonInfo::XRibbonInfoParser** val)
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		if (val == NULL)
		{
			return FALSE;
		}

		*val = NULL;

		CXMLNode<IXMLDOMNode> element;
		HRESULT hr = m_node.SelectNode(strName, element);
		IF_HR_INVALID_RETURN_BOOL(hr);

		*val = new CXMLParser(element);

		return HR_SUCCEEDED_OK(hr);
	}

	virtual BOOL ReadCollection(const CString& strName, CMFCRibbonInfo::XRibbonInfoParserCollection** val)
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		if (val == NULL)
		{
			return FALSE;
		}

		*val = NULL;

		CComQIPtr<IXMLDOMNodeList> nodes;
		HRESULT hr = m_node.SelectNodes(strName, &nodes);
		IF_HR_INVALID_RETURN_BOOL(hr);

		*val = new CXMLParserCollection(nodes);

		return HR_SUCCEEDED_OK(hr);
	}

	virtual BOOL ReadString(const CString& strName, CString& val)
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		CXMLNode<IXMLDOMNode> node;
		HRESULT hr = m_node.SelectNode(strName, node);
		IF_HR_INVALID_RETURN_BOOL(hr);

		hr = node.GetText(val);

		return HR_SUCCEEDED_OK(hr);
	}

	virtual BOOL ReadValue(CString& val)
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		HRESULT hr = m_node.GetText(val);

		return HR_SUCCEEDED_OK(hr);
	}

	virtual BOOL WriteString(const CString& strName, const CString& val, const CString& valDefault = CString())
	{
		if (!m_node.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		if (val == valDefault)
		{
			return TRUE;
		}

		CXMLDocument document;
		HRESULT hr = m_node.GetOwnerDocument(document);
		IF_HR_INVALID_RETURN_BOOL(hr);

		CXMLNode<IXMLDOMElement> element;
		hr = document.CreateElementWithText(strName, val, element);
		IF_HR_INVALID_RETURN_BOOL(hr);

		hr = m_node.AppendChild(element);

		return HR_SUCCEEDED_OK(hr);
	}

private:
	CXMLNode<IXMLDOMNode> m_node;
};

CXMLParserCollection::CXMLParserCollection(IXMLDOMNodeList* pList)
{
	if (pList != NULL)
	{
		CComQIPtr<IXMLDOMNodeList> list(pList);

		long nCount = 0;
		if (list->get_length(&nCount) == S_OK)
		{
			for (long i = 0; i < nCount; i++)
			{
				CXMLNode<IXMLDOMNode> node;
				list->get_item(i, node);

				CMFCRibbonInfo::XRibbonInfoParser* pParser = new CXMLParser(node);
				if (pParser != NULL)
				{
					m_array.Add(pParser);
				}
			}
		}
	}
}

class CXMLParserRoot : public CMFCRibbonInfo::XRibbonInfoParserRoot
{
public:
	CXMLParserRoot() {}
	virtual ~CXMLParserRoot() {}

	virtual BOOL GetRoot(const CString& strName, CMFCRibbonInfo::XRibbonInfoParser** pParser)
	{
		if (pParser == NULL)
		{
			return FALSE;
		}

		HRESULT hr = E_FAIL;

		if (!m_document.IsValid())
		{
			hr = m_document.Create(_T("1.0"), _T("UTF-8"), TRUE, strName);
			IF_HR_INVALID_RETURN_BOOL(hr);
		}

		CXMLNode<IXMLDOMElement> element;
		hr = m_document.GetDocumentElement(element);
		IF_HR_INVALID_RETURN_BOOL(hr);

		*pParser = new CXMLParser(element);

		return HR_SUCCEEDED_OK(hr);
	}

	const CString& GetErrorReason() const { return m_document.GetErrorReason(); }
	long GetErrorLine() const { return m_document.GetErrorLine(); }
	long GetErrorLinePos() const { return m_document.GetErrorLinePos(); }

	virtual BOOL Load(IStream* pStream)
	{
		if (m_document.Load(pStream) != S_OK)
		{
			return FALSE;
		}

		return TRUE;
	}

	virtual BOOL Load(LPBYTE lpBuffer, UINT size)
	{
		if (m_document.Load(lpBuffer, size) != S_OK)
		{
			return FALSE;
		}

		return TRUE;
	}

	virtual BOOL Save(IStream* pStream)
	{
		if (!m_document.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		return m_document.Save(pStream) == S_OK;
	}

	virtual BOOL Save(LPBYTE* lpBuffer, UINT& size)
	{
		if (!m_document.IsValid())
		{
			ASSERT(FALSE);
			return FALSE;
		}

		return m_document.Save(lpBuffer, size) == S_OK;
	}

private:
	CXMLDocument m_document;
};

BOOL CMFCRibbonInfo::Read(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	m_Error.Empty();

	BOOL bRes = FALSE;

	CMFCRibbonInfo::XRibbonInfoParser* pParserHeader = NULL;
	rParser.Read(s_szTag_Header, &pParserHeader);
	if (pParserHeader != NULL)
	{
		UINT nValue = (UINT)m_dwVersion;
		bRes = pParserHeader->ReadUInt(s_szTag_Version, nValue);
		m_dwVersion = (DWORD)nValue;

		if (bRes)
		{
			CMFCRibbonInfo::XRibbonInfoParser* pParserSizes = NULL;
			pParserHeader->Read(s_szTag_Sizes, &pParserSizes);
			if (pParserSizes != NULL)
			{
				pParserSizes->ReadSize(s_szTag_Sizes_Small, m_sizeImage[e_ImagesSmall]);
				pParserSizes->ReadSize(s_szTag_Sizes_Large, m_sizeImage[e_ImagesLarge]);

				delete pParserSizes;
			}
		}

		delete pParserHeader;
	}

	if (!bRes)
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorInvalidHeader);
		return FALSE;
	}

	bRes = FALSE;

	CMFCRibbonInfo::XRibbonInfoParser* pParserRibbonBar = NULL;
	rParser.Read(s_szTag_RibbonBar, &pParserRibbonBar);
	if (pParserRibbonBar != NULL)
	{
		bRes = m_RibbonBar.Read(*pParserRibbonBar);
		delete pParserRibbonBar;
	}

	if (!bRes)
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorInvalidRibbon);
		return FALSE;
	}

	CSize sizeSmall(m_sizeImage[e_ImagesSmall]);
	CSize sizeLarge(m_sizeImage[e_ImagesLarge]);

	m_RibbonBar.m_Images.m_Image.SetImageSize(sizeSmall);

	if (m_RibbonBar.m_MainCategory != NULL)
	{
		m_RibbonBar.m_MainCategory->m_SmallImages.m_Image.SetImageSize(sizeSmall);
		m_RibbonBar.m_MainCategory->m_LargeImages.m_Image.SetImageSize(sizeLarge);
	}

	int i = 0;
	int j = 0;
	int k = 0;

	XArrayCategory arCategories;
	arCategories.Append(m_RibbonBar.m_arCategories);

	for (i = 0; i < m_RibbonBar.m_arContexts.GetSize(); i++)
	{
		arCategories.Append(m_RibbonBar.m_arContexts[i]->m_arCategories);
	}

	for (i = 0; i < arCategories.GetSize(); i++)
	{
		XCategory* pCategory = arCategories[i];

		pCategory->m_SmallImages.m_Image.SetImageSize(sizeSmall);
		pCategory->m_LargeImages.m_Image.SetImageSize(sizeLarge);

		for (j = 0; j < pCategory->m_arPanels.GetSize(); j++)
		{
			XPanel* pPanel = pCategory->m_arPanels[j];

			for (k = 0; k < pPanel->m_arElements.GetSize(); k++)
			{
				XElement* pElement = pPanel->m_arElements[k];

				if (pElement->GetElementType() == e_TypeGroup)
				{
					XElementGroup* pGroup = (XElementGroup*)pElement;

					pGroup->m_Images.m_Image.SetImageSize(sizeSmall);
				}
			}
		}
	}

	return TRUE;
}

BOOL CMFCRibbonInfo::Write(CMFCRibbonInfo::XRibbonInfoParser& rParser)
{
	m_Error.Empty();

	BOOL bRes = FALSE;

	CMFCRibbonInfo::XRibbonInfoParser* pParserHeader = NULL;
	rParser.Add(s_szTag_Header, &pParserHeader);
	if (pParserHeader != NULL)
	{
		bRes = pParserHeader->WriteUInt(s_szTag_Version, m_dwVersion, 0);

		if (bRes && (m_sizeImage[e_ImagesSmall] != CSize(16, 16) || m_sizeImage[e_ImagesLarge] != CSize(32, 32)))
		{
			CMFCRibbonInfo::XRibbonInfoParser* pParserSizes = NULL;
			pParserHeader->Add(s_szTag_Sizes, &pParserSizes);
			if (pParserSizes != NULL)
			{
				pParserSizes->WriteSize(s_szTag_Sizes_Small, m_sizeImage[e_ImagesSmall], CSize(16, 16));
				pParserSizes->WriteSize(s_szTag_Sizes_Large, m_sizeImage[e_ImagesLarge], CSize(32, 32));

				delete pParserSizes;
			}
		}

		delete pParserHeader;
	}

	if (!bRes)
	{
		return FALSE;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserRibbonBar = NULL;
	rParser.Add(s_szTag_RibbonBar, &pParserRibbonBar);
	if (pParserRibbonBar != NULL)
	{
		bRes = m_RibbonBar.Write(*pParserRibbonBar);
		delete pParserRibbonBar;
	}

	return bRes;
}

BOOL CMFCRibbonInfo::Read(IStream* pStream)
{
	m_Error.Empty();

	if (pStream == NULL)
	{
		return FALSE;
	}

	CXMLParserRoot document;
	if (!document.Load(pStream))
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorFile, document.GetErrorReason(), document.GetErrorLine(), document.GetErrorLinePos());
		return FALSE;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserRoot = NULL;
	document.GetRoot(s_szTag_Body, &pParserRoot);
	if (pParserRoot == NULL)
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorInvalidRoot);
		return FALSE;
	}

	BOOL bRes = Read(*pParserRoot);
	delete pParserRoot;

	return bRes;
}

BOOL CMFCRibbonInfo::Read(LPBYTE lpBuffer, UINT nSize)
{
	m_Error.Empty();

	if (lpBuffer == NULL || nSize == 0)
	{
		return FALSE;
	}

	CXMLParserRoot document;
	if (!document.Load(lpBuffer, nSize))
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorFile, document.GetErrorReason(), document.GetErrorLine(), document.GetErrorLinePos());
		return FALSE;
	}

	CMFCRibbonInfo::XRibbonInfoParser* pParserRoot = NULL;
	document.GetRoot(s_szTag_Body, &pParserRoot);
	if (pParserRoot == NULL)
	{
		m_Error.SetError(CMFCRibbonInfo::XInfoError::e_ErrorInvalidRoot);
		return FALSE;
	}

	BOOL bRes = Read(*pParserRoot);
	delete pParserRoot;

	return bRes;
}

BOOL CMFCRibbonInfo::Write(IStream* pStream)
{
	m_Error.Empty();

	if (pStream == NULL)
	{
		return FALSE;
	}

	CXMLParserRoot document;
	CMFCRibbonInfo::XRibbonInfoParser* pParserRoot = NULL;
	document.GetRoot(s_szTag_Body, &pParserRoot);
	if (pParserRoot == NULL)
	{
		return FALSE;
	}

	BOOL bRes = Write(*pParserRoot);
	delete pParserRoot;

	if (!bRes)
	{
		return FALSE;
	}

	return document.Save(pStream);
}

BOOL CMFCRibbonInfo::Write(LPBYTE* lpBuffer, UINT& nSize)
{
	m_Error.Empty();

	if (lpBuffer == NULL)
	{
		return FALSE;
	}

	*lpBuffer = NULL;
	nSize = 0;

	CXMLParserRoot document;
	CMFCRibbonInfo::XRibbonInfoParser* pParserRoot = NULL;
	document.GetRoot(s_szTag_Body, &pParserRoot);
	if (pParserRoot == NULL)
	{
		return FALSE;
	}

	BOOL bRes = Write(*pParserRoot);
	delete pParserRoot;

	if (!bRes)
	{
		return FALSE;
	}

	return document.Save(lpBuffer, nSize);
}
