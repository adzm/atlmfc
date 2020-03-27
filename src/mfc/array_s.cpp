
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
//
// Implementation of parameterized Array
//
/////////////////////////////////////////////////////////////////////////////
// NOTE: we allocate an array of 'm_nMaxSize' elements, but only
//  the current size 'm_nSize' contains properly constructed
//  objects.

#include "stdafx.h"
#include <wchar.h>



#include "elements.h"  // used for special creation

#define new DEBUG_NEW

/////////////////////////////////////////////////////////////////////////////

static void _ConstructElements(CString* pNewData, INT_PTR nCount)
{
	ASSERT(nCount >= 0);

	while (nCount--)
	{
		ConstructElement(pNewData);
		pNewData++;
	}
}

static void _DestructElements(CString* pOldData, INT_PTR nCount)
{
	ASSERT(nCount >= 0);

	while (nCount--)
	{
		DestructElement(pOldData);
		pOldData++;
	}
}

static void _CopyElements(CString* pDest, CString* pSrc, INT_PTR nCount)
{
	ASSERT(nCount >= 0);

	while (nCount--)
	{
		*pDest = *pSrc;
		++pDest;
		++pSrc;
	}
}

/////////////////////////////////////////////////////////////////////////////

CStringArray::CStringArray()
{
	m_pData = NULL;
	m_nSize = m_nMaxSize = m_nGrowBy = 0;
}

CStringArray::~CStringArray()
{
	AFX_BEGIN_DESTRUCTOR

		ASSERT_VALID(this);

		_DestructElements(m_pData, m_nSize);
		delete[] (BYTE*)m_pData;

	AFX_END_DESTRUCTOR
}

void CStringArray::SetSize(INT_PTR nNewSize, INT_PTR nGrowBy)
{
	ASSERT_VALID(this);
	ASSERT(nNewSize >= 0);

	if(nNewSize < 0 )
		AfxThrowInvalidArgException();

	if (nGrowBy >= 0)
		m_nGrowBy = nGrowBy;  // set new size

	if (nNewSize == 0)
	{
		// shrink to nothing

		_DestructElements(m_pData, m_nSize);
		delete[] (BYTE*)m_pData;
		m_pData = NULL;
		m_nSize = m_nMaxSize = 0;
	}
	else if (m_pData == NULL)
	{
		// create one with exact size
#ifdef SIZE_T_MAX
		ASSERT(nNewSize <= SIZE_T_MAX/sizeof(CString));    // no overflow
#endif
		m_pData = (CString*) new BYTE[nNewSize * sizeof(CString)];

		_ConstructElements(m_pData, nNewSize);

		m_nSize = m_nMaxSize = nNewSize;
	}
	else if (nNewSize <= m_nMaxSize)
	{
		// it fits
		if (nNewSize > m_nSize)
		{
			// initialize the new elements

			_ConstructElements(&m_pData[m_nSize], nNewSize-m_nSize);

		}

		else if (m_nSize > nNewSize)  // destroy the old elements
			_DestructElements(&m_pData[nNewSize], m_nSize-nNewSize);

		m_nSize = nNewSize;
	}
	else
	{
		// otherwise, grow array
		INT_PTR nGrowArrayBy = m_nGrowBy;
		if (nGrowArrayBy == 0)
		{
			// heuristically determine growth when nGrowArrayBy == 0
			//  (this avoids heap fragmentation in many situations)
			nGrowArrayBy = min(1024, max(4, m_nSize / 8));
		}
		INT_PTR nNewMax;
		if (nNewSize < m_nMaxSize + nGrowArrayBy)
			nNewMax = m_nMaxSize + nGrowArrayBy;  // granularity
		else
			nNewMax = nNewSize;  // no slush

		ASSERT(nNewMax >= m_nMaxSize);  // no wrap around
		
		if(nNewMax  < m_nMaxSize)
			AfxThrowInvalidArgException();

#ifdef SIZE_T_MAX
		ASSERT(nNewMax <= SIZE_T_MAX/sizeof(CString)); // no overflow
#endif
		CString* pNewData = (CString*) new BYTE[(size_t)nNewMax * sizeof(CString)];

		// copy new data from old 
		Checked::memcpy_s(pNewData, (size_t)nNewMax * sizeof(CString), 
			m_pData, (size_t)m_nSize * sizeof(CString));

		// construct remaining elements
		ASSERT(nNewSize > m_nSize);

		_ConstructElements(&pNewData[m_nSize], nNewSize-m_nSize);

		// get rid of old stuff (note: no destructors called)
		delete[] (BYTE*)m_pData;
		m_pData = pNewData;
		m_nSize = nNewSize;
		m_nMaxSize = nNewMax;
	}
}

INT_PTR CStringArray::Append(const CStringArray& src)
{
	ASSERT_VALID(this);
	ASSERT(this != &src);   // cannot append to itself

	if(this == &src)
		AfxThrowInvalidArgException();

	INT_PTR nOldSize = m_nSize;
	SetSize(m_nSize + src.m_nSize);

	_CopyElements(m_pData + nOldSize, src.m_pData, src.m_nSize);

	return nOldSize;
}

void CStringArray::Copy(const CStringArray& src)
{
	ASSERT_VALID(this);
	ASSERT(this != &src);   // cannot append to itself

	if(this != &src)
	{
		SetSize(src.m_nSize);
		_CopyElements(m_pData, src.m_pData, src.m_nSize);
	}
}

void CStringArray::FreeExtra()
{
	ASSERT_VALID(this);

	if (m_nSize != m_nMaxSize)
	{
		// shrink to desired size
#ifdef SIZE_T_MAX
		ASSERT(m_nSize <= SIZE_T_MAX/sizeof(CString)); // no overflow
#endif
		CString* pNewData = NULL;
		if (m_nSize != 0)
		{
			pNewData = (CString*) new BYTE[m_nSize * sizeof(CString)];

			// copy new data from old 
			Checked::memcpy_s(pNewData, m_nSize * sizeof(CString), 
				m_pData, m_nSize * sizeof(CString));
		}

		// get rid of old stuff (note: no destructors called)
		delete[] (BYTE*)m_pData;
		m_pData = pNewData;
		m_nMaxSize = m_nSize;
	}
}

/////////////////////////////////////////////////////////////////////////////

void CStringArray::SetAtGrow(INT_PTR nIndex, LPCTSTR newElement)
{
	ASSERT_VALID(this);
	ASSERT(nIndex >= 0);

	if(nIndex < 0)
		AfxThrowInvalidArgException();

	if (nIndex >= m_nSize)
		SetSize(nIndex+1);
	m_pData[nIndex] = newElement;
}


void CStringArray::SetAtGrow(INT_PTR nIndex, const CString& newElement)
{
	ASSERT_VALID(this);
	ASSERT(nIndex >= 0);

	if(nIndex < 0)
		AfxThrowInvalidArgException();

	if (nIndex >= m_nSize)
	{
		// Make sure newElement is not a reference to an element in the array.
		// Or else, it will be invalidated by the reallocation.
		ENSURE(	(nIndex < m_nMaxSize) ||
				(&newElement < m_pData) ||
				(&newElement >= (m_pData + m_nMaxSize) ) );
		SetSize(nIndex+1);
	}
	m_pData[nIndex] = newElement;
}



void CStringArray::InsertEmpty(INT_PTR nIndex, INT_PTR nCount)
{
	ASSERT_VALID(this);
	ASSERT(nIndex >= 0);    // will expand to meet need
	ASSERT(nCount > 0);     // zero or negative size not allowed

	if(nIndex < 0 || nCount <= 0)
		AfxThrowInvalidArgException();

	if (nIndex >= m_nSize)
	{
		// adding after the end of the array
		SetSize(nIndex + nCount);  // grow so nIndex is valid
	}
	else
	{
		// inserting in the middle of the array
		INT_PTR nOldSize = m_nSize;
		INT_PTR nOverlapSize = min(nCount, nOldSize - nIndex);

		SetSize(m_nSize + nCount);  // grow it to new size

		// destroy slots we are about to overwrite
		_DestructElements(&m_pData[m_nSize - nOverlapSize], nOverlapSize);

		// shift old data up to fill gap 
		Checked::memmove_s(&m_pData[nIndex+nCount], (m_nSize-(nIndex+nCount)) * sizeof(CString), 
			&m_pData[nIndex], (nOldSize-nIndex) * sizeof(CString));

		// re-init the now-vacant slots we moved data from
		_ConstructElements(&m_pData[nIndex], nOverlapSize);
	}

	// insert new value in the gap
	ASSERT(nIndex + nCount <= m_nSize);
}


void CStringArray::InsertAt(INT_PTR nIndex, LPCTSTR newElement, INT_PTR nCount)
{

	// make room for new elements
	InsertEmpty(nIndex, nCount);



	// copy elements into the empty space
	CString temp = newElement;
	while (nCount--)
		m_pData[nIndex++] = temp;

}


void CStringArray::InsertAt(INT_PTR nIndex, const CString& newElement, INT_PTR nCount)
{
	// make room for new elements
	InsertEmpty(nIndex, nCount);

	// copy elements into the empty space
	while (nCount--)
		m_pData[nIndex++] = newElement;
}


void CStringArray::RemoveAt(INT_PTR nIndex, INT_PTR nCount)
{
	ASSERT_VALID(this);
	ASSERT(nIndex >= 0);
	ASSERT(nCount >= 0);
	INT_PTR nUpperBound = nIndex + nCount;
	ASSERT(nUpperBound <= m_nSize && nUpperBound >= nIndex && nUpperBound >= nCount);

	if(nIndex < 0 || nCount < 0 || (nUpperBound > m_nSize) || (nUpperBound < nIndex) || (nUpperBound < nCount))
		AfxThrowInvalidArgException();
		
	// just remove a range
	INT_PTR nMoveCount = m_nSize - (nUpperBound);

	_DestructElements(&m_pData[nIndex], nCount);

	if (nMoveCount)
	{
		Checked::memmove_s(&m_pData[nIndex], nMoveCount * sizeof(CString), 
			&m_pData[nUpperBound], nMoveCount * sizeof(CString));
	}

	m_nSize -= nCount;
}

void CStringArray::InsertAt(INT_PTR nStartIndex, const CStringArray* pNewArray)
{
	ASSERT_VALID(this);
	ASSERT(pNewArray != NULL);
	ASSERT_KINDOF(CStringArray, pNewArray);
	ASSERT_VALID(pNewArray);
	ASSERT(nStartIndex >= 0);

	if(pNewArray == NULL || nStartIndex < 0)
		AfxThrowInvalidArgException();

	if (pNewArray->GetSize() > 0)
	{
		InsertAt(nStartIndex, pNewArray->GetAt(0), pNewArray->GetSize());
		for (INT_PTR i = 0; i < pNewArray->GetSize(); i++)
			SetAt(nStartIndex + i, pNewArray->GetAt(i));
	}
}


/////////////////////////////////////////////////////////////////////////////
// Serialization

void CStringArray::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar.WriteCount(m_nSize);
		for (INT_PTR i = 0; i < m_nSize; i++)
			ar << m_pData[i];
	}
	else
	{
		DWORD_PTR nOldSize = ar.ReadCount();
		SetSize(nOldSize);
		for (INT_PTR i = 0; i < m_nSize; i++)
			ar >> m_pData[i];
	}
}



/////////////////////////////////////////////////////////////////////////////
// Diagnostics

#ifdef _DEBUG
void CStringArray::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);

	dc << "with " << m_nSize << " elements";
	if (dc.GetDepth() > 0)
	{
		for (INT_PTR i = 0; i < m_nSize; i++)
			dc << "\n\t[" << i << "] = " << m_pData[i];
	}

	dc << "\n";
}

void CStringArray::AssertValid() const
{
	CObject::AssertValid();

	if (m_pData == NULL)
	{
		ASSERT(m_nSize == 0);
		ASSERT(m_nMaxSize == 0);
	}
	else
	{
		ASSERT(m_nSize >= 0);
		ASSERT(m_nMaxSize >= 0);
		ASSERT(m_nSize <= m_nMaxSize);
		ASSERT(AfxIsValidAddress(m_pData, m_nMaxSize * sizeof(CString)));
	}
}
#endif //_DEBUG



IMPLEMENT_SERIAL(CStringArray, CObject, 0)

/////////////////////////////////////////////////////////////////////////////
