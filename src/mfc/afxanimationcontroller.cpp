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
#include "afxanimationcontroller.h"

IMPLEMENT_DYNAMIC(CBaseTransition,CObject);
IMPLEMENT_DYNAMIC(CBaseKeyFrame,CObject);
IMPLEMENT_DYNAMIC(CKeyFrame,CBaseKeyFrame);
IMPLEMENT_DYNAMIC(CAnimationBaseObject,CObject);
IMPLEMENT_DYNAMIC(CAnimationValue,CAnimationBaseObject);
IMPLEMENT_DYNAMIC(CAnimationPoint,CAnimationBaseObject);
IMPLEMENT_DYNAMIC(CAnimationSize,CAnimationBaseObject);
IMPLEMENT_DYNAMIC(CAnimationColor,CAnimationBaseObject);
IMPLEMENT_DYNAMIC(CAnimationRect,CAnimationBaseObject);
IMPLEMENT_DYNCREATE(CAnimationController, CObject)

CBaseKeyFrame CAnimationController::g_KeyframeStoryboardStart;

////////////////////////////////////////////////////////////
// CBaseTransition implementation

IUIAnimationTransition* CBaseTransition::GetTransition(IUIAnimationTransitionLibrary* pLibrary, IUIAnimationTransitionFactory* pFactory)
{
	if (m_transition == NULL && pLibrary != NULL && pFactory != NULL)
	{
		Create(pLibrary, pFactory);
	}

	return m_transition;
}

BOOL CBaseTransition::AddToStoryboard(IUIAnimationStoryboard* pStoryboard)
{
	if (pStoryboard == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (m_bAdded)
	{
		return TRUE;
	}

	ASSERT(m_pRelatedVariable != NULL);
	if (m_pRelatedVariable == NULL)
	{
		TRACE("An attempt to add a transition without related animation variable. Call CAnimationValue::AddTransition first.\n");
		return FALSE;
	}

	if (m_pRelatedVariable != NULL)
	{
		IUIAnimationVariable* pVariable = m_pRelatedVariable->GetVariable();
		if (pVariable == NULL)
		{
			TRACE("An attempt to add a transition for animation variable that has not been created.\n");
			return FALSE;
		}

		if (FAILED(pStoryboard->AddTransition(pVariable, m_transition)))
		{
			TRACE("Failed to add the transition to Storyboard.\n");
			return FALSE;
		}

		m_bAdded = TRUE;
	}

	return TRUE;
}

BOOL CBaseTransition::AddToStoryboardAtKeyframes(IUIAnimationStoryboard* pStoryboard)
{
	if (pStoryboard == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (m_bAdded)
	{
		return TRUE;
	}

	ASSERT(m_pRelatedVariable != NULL);
	if (m_pRelatedVariable == NULL)
	{
		TRACE("An attempt to add a transition without related animation variable. Call CAnimationValue::AddTransition first.\n");
		return FALSE;
	}

	if (m_pStartKeyframe == NULL && m_pEndKeyframe == NULL)
	{
		return FALSE;
	}

	if (m_pStartKeyframe != NULL && !m_pStartKeyframe->IsAdded())
	{
		if (!m_pStartKeyframe->AddToStoryboard(pStoryboard, TRUE))
		{
			return FALSE;
		}
	}

	if (m_pEndKeyframe != NULL && !m_pEndKeyframe->IsAdded())
	{
		if (!m_pEndKeyframe->AddToStoryboard(pStoryboard, TRUE))
		{
			return FALSE;
		}
	}

	if (m_pRelatedVariable != NULL && m_pRelatedVariable->GetVariable() != NULL)
	{
		if (m_pStartKeyframe != NULL && m_pEndKeyframe != NULL)
		{
			HRESULT hr = pStoryboard->AddTransitionBetweenKeyframes(m_pRelatedVariable->GetVariable(), m_transition, 
				m_pStartKeyframe->GetAnimationKeyframe(), m_pEndKeyframe->GetAnimationKeyframe());
			if (FAILED(hr))
			{
				TRACE1("Failed to add the transition to Storyboard between keyframes. Error code: %x\n", hr);
				return FALSE;
			}

			m_bAdded = TRUE;
		}
		else if (m_pStartKeyframe != NULL)
		{
			HRESULT hr = pStoryboard->AddTransitionAtKeyframe(m_pRelatedVariable->GetVariable(), m_transition, m_pStartKeyframe->GetAnimationKeyframe());
			if (FAILED(hr))
			{
				TRACE1("Failed to add the transition to Storyboard at keyframe. Error code: %x\n", hr);
				return FALSE;
			}

			m_bAdded = TRUE;
		}
	}
	
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// CBaseKeyFrame implementation

BOOL CBaseKeyFrame::AddToStoryboard(IUIAnimationStoryboard* /*pStoryboard*/, BOOL /*bDeepAdd*/)
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// CKeyFrame implementation

CKeyFrame::CKeyFrame(CBaseTransition* pTransition) : m_pTransition (pTransition) 
{
	ASSERT(pTransition != NULL);
	m_bAdded = FALSE;
	m_bIsKeyframeAtOffset = FALSE;
	m_offset = 0.0;
	m_pExistingKeyFrame = NULL;
}

CKeyFrame::CKeyFrame(CBaseKeyFrame* pKeyframe, UI_ANIMATION_SECONDS offset) : m_pExistingKeyFrame(pKeyframe), m_offset(offset)
{
	ASSERT(pKeyframe != NULL);
	m_bAdded = FALSE;
	m_bIsKeyframeAtOffset = TRUE;
	m_pTransition = NULL;
}

BOOL CKeyFrame::AddToStoryboard(IUIAnimationStoryboard* pStoryboard, BOOL bDeepAdd)
{
	return m_bIsKeyframeAtOffset ? AddToStoryboardAtOffset(pStoryboard, bDeepAdd) : AddToStoryboardAfterTransition(pStoryboard, bDeepAdd);
}

BOOL CKeyFrame::AddToStoryboardAfterTransition(IUIAnimationStoryboard* pStoryboard, BOOL bDeepAdd)
{
	ASSERT(pStoryboard != NULL);

	if (pStoryboard == NULL || m_pTransition == NULL)
	{
		return FALSE;
	}

	BOOL bResult = TRUE;
	if (!m_pTransition->IsAdded())
	{
		if (bDeepAdd)
		{
			bResult = m_pTransition->AddToStoryboardAtKeyframes(pStoryboard);
		}
		else
		{
			return FALSE;
		}
	}

	if (bResult)
	{
		IUIAnimationTransition* pTransition = m_pTransition->GetTransition();
		ENSURE(pTransition != NULL); // must be created at this point

		if (SUCCEEDED(pStoryboard->AddKeyframeAfterTransition(pTransition, &m_keyframe)))
		{
			m_bAdded = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CKeyFrame::AddToStoryboardAtOffset(IUIAnimationStoryboard* pStoryboard, BOOL bDeepAdd)
{
	if (m_pExistingKeyFrame == NULL || pStoryboard == NULL)
	{
		return FALSE;
	}

	BOOL bResult = TRUE;

	if (!m_pExistingKeyFrame->IsAdded())
	{
		if (bDeepAdd)
		{
			bResult = m_pExistingKeyFrame->AddToStoryboard(pStoryboard, TRUE);
		}
		else
		{
			return FALSE;
		}
	}

	if (SUCCEEDED(pStoryboard->AddKeyframeAtOffset(m_pExistingKeyFrame->GetAnimationKeyframe(), m_offset, &m_keyframe)))
	{
		m_bAdded = TRUE;
		return TRUE;
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////////
// CAnimationVariable implementation

CAnimationVariable::CAnimationVariable(DOUBLE dblDefaultValue)
{
	m_dblDefaultValue = dblDefaultValue;
	m_bAutodestroyTransitions = FALSE;
	m_pParentObject = NULL;
}

CAnimationVariable::~CAnimationVariable()
{
	ClearTransitions(m_bAutodestroyTransitions);
}

BOOL CAnimationVariable::Create(IUIAnimationManager* pManager)
{
	if (pManager == NULL)
	{
		return FALSE;
	}

	if (m_variable != NULL)
	{
		m_variable.Detach()->Release();
	}

	if (pManager != NULL)
	{
		if (FAILED(pManager->CreateAnimationVariable(m_dblDefaultValue, &m_variable)))
		{
			TRACE("Failed to create animation variable\n.");
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CAnimationVariable::CreateTransitions(IUIAnimationTransitionLibrary* pLibrary, IUIAnimationTransitionFactory* pFactory)
{
	for (POSITION pos = m_lstTransitions.GetHeadPosition(); pos != NULL;)
	{
		CBaseTransition* pTransition = DYNAMIC_DOWNCAST(CBaseTransition, m_lstTransitions.GetNext(pos));
		ASSERT_VALID(pTransition);

		if (pTransition == NULL || !pTransition->Create(pLibrary, pFactory))
		{
			return FALSE;
		}
	}

	return TRUE;
}

void CAnimationVariable::SetDefaultValue(DOUBLE dblDefaultValue)
{
	m_dblDefaultValue = dblDefaultValue;
	if (m_variable != NULL)
	{
		m_variable.Detach()->Release();
	}
}

HRESULT CAnimationVariable::GetValue(DOUBLE& dblValue)
{
	if (m_variable == NULL)
	{
		dblValue = m_dblDefaultValue;
		return S_OK;
	}
	return m_variable->GetValue(&dblValue);
}

HRESULT CAnimationVariable::GetValue(INT32& nValue)
{
	if (m_variable == NULL)
	{
		nValue = (INT32) m_dblDefaultValue;
		return S_OK;
	}
	return m_variable->GetIntegerValue(&nValue);
}

void CAnimationVariable::AddTransition(CBaseTransition* pTransition)
{
	if (pTransition != NULL)
	{
		ASSERT_VALID(pTransition);
		if (pTransition->GetRelatedVariable() != NULL)
		{
			TRACE0("This transition has already been added to a variable.\n");
			return;
		}
		pTransition->SetRelatedVariable(this);

		m_lstTransitions.AddTail(pTransition);
	}
}

void CAnimationVariable::ClearTransitions(BOOL bAutodestroy)
{
	if (m_bAutodestroyTransitions || bAutodestroy)
	{
		while (!m_lstTransitions.IsEmpty())
		{
			delete m_lstTransitions.RemoveTail();
		}
	}
	else
	{
		m_lstTransitions.RemoveAll();
	}
}

void CAnimationVariable::ApplyTransitions(CAnimationController* pController, IUIAnimationStoryboard* pStoryboard, BOOL bDependOnKeyframes)
{
	if (pController == NULL)
	{
		TRACE("Can't apply transition, because pController is NULL\n");
		return;
	}
	if (m_variable == NULL && !Create(pController->GetUIAnimationManager()))
	{
		return;
	}

	for (POSITION pos = m_lstTransitions.GetHeadPosition(); pos != NULL;)
	{
		CBaseTransition* pTransition = DYNAMIC_DOWNCAST(CBaseTransition, m_lstTransitions.GetNext(pos));
		ASSERT_VALID(pTransition);

		if (pTransition == NULL)
		{
			continue;
		}

		if (pTransition->GetStartKeyframe() == NULL && pTransition->GetEndKeyframe() == NULL && !bDependOnKeyframes)
		{
			pTransition->AddToStoryboard(pStoryboard);
		}
		else if (!pTransition->IsAdded() && bDependOnKeyframes)
		{
			pTransition->AddToStoryboardAtKeyframes(pStoryboard);
		}
	}
}

void CAnimationVariable::EnableValueChangedEvent (CAnimationController* pController, BOOL bEnable)
{
	if (pController == NULL || m_variable == NULL && !Create(pController->GetUIAnimationManager()))
	{
		return;
	}

	if (m_variable == NULL)
	{
		return;
	}

	if (!bEnable)
	{
		m_variable->SetVariableChangeHandler(NULL);
		return;
	}

	CComPtr<IUIAnimationVariableChangeHandler> pValueChangeHandler;
	if (FAILED(CAnimationVariableChangeHandler::CreateInstance(pController, &pValueChangeHandler)))
	{
		TRACE("Failed to create Animation Varible Changed Event Handler.\n");
		return;
	}

	m_variable->SetVariableChangeHandler(pValueChangeHandler);
}

void CAnimationVariable::EnableIntegerValueChangedEvent (CAnimationController* pController, BOOL bEnable)
{
	if (pController == NULL || m_variable == NULL && !Create(pController->GetUIAnimationManager()))
	{
		return;
	}

	if (m_variable == NULL)
	{
		return;
	}

	if (!bEnable)
	{
		m_variable->SetVariableIntegerChangeHandler(NULL);
		return;
	}

	CComPtr<IUIAnimationVariableIntegerChangeHandler> pValueChangeHandler;
	if (FAILED(CAnimationVariableIntegerChangeHandler::CreateInstance(pController, &pValueChangeHandler)))
	{
		TRACE("Failed to create Animation Varible Changed Event Handler.\n");
		return;
	}

	m_variable->SetVariableIntegerChangeHandler(pValueChangeHandler);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationBaseObject implementation

CAnimationBaseObject::CAnimationBaseObject()
{
	m_nGroupID = 0;
	m_nObjectID = 0;
	m_dwUserData = 0;
	m_pParentController = NULL;
	m_bAutodestroyTransitions = TRUE;
}

CAnimationBaseObject::CAnimationBaseObject(UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData)
{
	m_dwUserData = dwUserData;
	m_pParentController = NULL;
	m_bAutodestroyTransitions = TRUE;
	SetID(nObjectID, nGroupID);
}

CAnimationBaseObject::~CAnimationBaseObject() 
{
	if (m_pParentController != NULL)
	{
		m_pParentController->RemoveAnimationObject(this, TRUE);
	}
}
void CAnimationBaseObject::SetID(UINT32 nObjectID, UINT32 nGroupID)
{
	m_nObjectID = nObjectID;

	if (m_pParentController == NULL)
	{
		// object has not been added to controller, just set group ID and return
		m_nGroupID = nGroupID;
		return;
	}

	if (m_nGroupID != nGroupID)
	{
		CAnimationController* pController = m_pParentController;
		m_pParentController->RemoveAnimationObject(this, TRUE); // sets m_pParentController to NULL
		m_nGroupID = nGroupID;
		pController->AddAnimationObject(this);
	}
}

BOOL CAnimationBaseObject::CreateTransitions()
{
	if (m_pParentController == NULL)
	{
		TRACE0("This animation object has not been added to Animation Controller.\n");
		return FALSE;
	}

	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar == NULL || !pNextVar->CreateTransitions(m_pParentController->GetUITransitionLibrary(), m_pParentController->GetUITransitionFactory()))
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CAnimationBaseObject::ApplyTransitions(IUIAnimationStoryboard* pStoryboard, BOOL bDependOnKeyframes)
{
	if (m_pParentController	== NULL)
	{
		TRACE("ApplyTransitions failed because the Animation Object has not been added to Animation Controller");
		ASSERT(FALSE);
		return FALSE;
	}

	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar != NULL)
		{
			pNextVar->SetParentAnimationObject(this);
			pNextVar->ApplyTransitions(m_pParentController, pStoryboard, bDependOnKeyframes);
		}
	}

	return TRUE;
}

void CAnimationBaseObject::ClearTransitions(BOOL bAutodestroy)
{
	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar != NULL)
		{
			pNextVar->ClearTransitions(bAutodestroy || m_bAutodestroyTransitions);
		}
	}
}

void CAnimationBaseObject::EnableValueChangedEvent(CAnimationController* pController, BOOL bEnable)
{
	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar != NULL)
		{
			pNextVar->EnableValueChangedEvent(pController, bEnable);
		}
	}
}

void CAnimationBaseObject::EnableIntegerValueChangedEvent(CAnimationController* pController, BOOL bEnable)
{
	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar != NULL)
		{
			pNextVar->EnableIntegerValueChangedEvent(pController, bEnable);
		}
	}
}

BOOL CAnimationBaseObject::ContainsVariable(IUIAnimationVariable* pVariable)
{
	if (pVariable == NULL)
	{
		return FALSE;
	}

	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);
		
		if (pNextVar == NULL)
		{
			continue;
		}

		IUIAnimationVariable* pAnimationVar = pNextVar->GetVariable();
		if (pAnimationVar != NULL &&  pAnimationVar == pVariable)
		{
			return TRUE;
		}
	}

	return FALSE;
}

void CAnimationBaseObject::SetParentAnimationObjects()
{
	CList<CAnimationVariable*, CAnimationVariable*> lst;
	GetAnimationVariableList(lst);

	for (POSITION pos = lst.GetHeadPosition(); pos != NULL;)
	{
		CAnimationVariable* pNextVar = lst.GetNext(pos);

		if (pNextVar != NULL)
		{
			pNextVar->SetParentAnimationObject(this);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// CAnimationValue implementation

CAnimationValue::CAnimationValue() : m_value(0.)
{
}

CAnimationValue::CAnimationValue(DOUBLE dblDefaultValue, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : 
	CAnimationBaseObject(nGroupID, nObjectID, dwUserData), m_value(dblDefaultValue)
{
}

BOOL CAnimationValue::GetValue(DOUBLE& dblValue)
{
	if (FAILED(m_value.GetValue(dblValue)))
	{
		TRACE("Failed to get DOUBLE value.\n");
		return FALSE;
	}
	return TRUE;
}

BOOL CAnimationValue::GetValue(INT32& nValue)
{
	if (FAILED(m_value.GetValue(nValue)))
	{
		TRACE("Failed to get INT32 value.\n");
		return FALSE;
	}
	return TRUE;
}

void CAnimationValue::AddTransition(CBaseTransition* pTransition)
{
	ASSERT(pTransition != NULL);

	if (pTransition != NULL)
	{
		m_value.AddTransition(pTransition);
	}
}

void CAnimationValue::GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst)
{
	lst.AddTail(&m_value);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationPoint implementation

CAnimationPoint::CAnimationPoint()
{
}

CAnimationPoint::CAnimationPoint(const CPoint& ptDefault, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : 
	CAnimationBaseObject(nGroupID, nObjectID, dwUserData), m_xValue(ptDefault.x), m_yValue(ptDefault.y)
{
}

void CAnimationPoint::SetDefaultValue(const POINT& ptDefault)
{
	m_xValue.SetDefaultValue(ptDefault.x);
	m_yValue.SetDefaultValue(ptDefault.y);
}

CPoint CAnimationPoint::GetDefaultValue()
{
	return CPoint((int)m_xValue.GetDefaultValue(), (int)m_yValue.GetDefaultValue());
}

BOOL CAnimationPoint::GetValue(CPoint& ptValue) 
{
	DOUBLE dblValue = 0.0;
	HRESULT hr = m_xValue.GetValue(dblValue);
	if (FAILED(hr))
	{
		TRACE1("CAnimationPoint::GetValue for X coordinate failed. Error code: %x\n", hr);
		ptValue = GetDefaultValue();
		return FALSE;
	}

	ptValue.x = (LONG)dblValue;

	hr = m_yValue.GetValue(dblValue);
	if (FAILED(hr))
	{
		TRACE1("CAnimationPoint::GetValue for Y coordinate failed. Error code: %x\n", hr);
		ptValue = GetDefaultValue();
		return FALSE;
	}

	ptValue.y = (LONG)dblValue;

	return TRUE; 
}

void CAnimationPoint::AddTransition(CBaseTransition* pXTransition, CBaseTransition* pYTransition)
{
	if (pXTransition != NULL)
	{
		m_xValue.AddTransition(pXTransition);
	}

	if (pYTransition != NULL)
	{
		m_yValue.AddTransition(pYTransition);
	}
}

void CAnimationPoint::GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst)
{
	lst.AddTail(&m_xValue);
	lst.AddTail(&m_yValue);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationSize implementation

CAnimationSize::CAnimationSize()
{
}

CAnimationSize::CAnimationSize(const CSize& szDefault, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : 
	CAnimationBaseObject(nGroupID, nObjectID, dwUserData)
{
	SetDefaultValue(szDefault);
}

void CAnimationSize::SetDefaultValue(const CSize& szDefault)
{
	m_cxValue.SetDefaultValue(szDefault.cx);
	m_cyValue.SetDefaultValue(szDefault.cy);
}

CSize CAnimationSize::GetDefaultValue()
{
	return CSize((int)m_cxValue.GetDefaultValue(), (int)m_cyValue.GetDefaultValue());
}

BOOL CAnimationSize::GetValue(CSize& szValue)
{
	DOUBLE dblValue = 0.0;
	HRESULT hr = m_cxValue.GetValue(dblValue);
	if (FAILED(hr))
	{
		TRACE1("CAnimationPoint::GetValue for width failed. Error code: %x\n", hr);
		szValue = GetDefaultValue();
		return FALSE;
	}

	szValue.cx = (LONG)dblValue;

	hr = m_cyValue.GetValue(dblValue);
	if (FAILED(hr))
	{
		TRACE1("CAnimationPoint::GetValue for height failed. Error code: %x\n", hr);
		szValue = GetDefaultValue();
		return FALSE;
	}

	szValue.cy = (LONG)dblValue;

	return TRUE; 
}

void CAnimationSize::AddTransition(CBaseTransition* pCXTransition, CBaseTransition* pCYTransition)
{
	if (pCXTransition != NULL)
	{
		m_cxValue.AddTransition(pCXTransition);
	}

	if (pCYTransition != NULL)
	{
		m_cyValue.AddTransition(pCYTransition);
	}
}


void CAnimationSize::GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst)
{
	lst.AddTail(&m_cxValue);
	lst.AddTail(&m_cyValue);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationColor implementation

CAnimationColor::CAnimationColor()
{
}

CAnimationColor::CAnimationColor(COLORREF color, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : CAnimationBaseObject(nGroupID, nObjectID, dwUserData)
{
	SetDefaultValue(color);
}

void CAnimationColor::SetDefaultValue(COLORREF color)
{
	m_rValue.SetDefaultValue(GetRValue(color));
	m_gValue.SetDefaultValue(GetGValue(color));
	m_bValue.SetDefaultValue(GetBValue(color));
}

COLORREF CAnimationColor::GetDefaultValue()
{
	return RGB((BYTE)m_rValue.GetDefaultValue(), (BYTE)m_gValue.GetDefaultValue(), (BYTE)m_bValue.GetDefaultValue());
}

BOOL CAnimationColor::GetValue(COLORREF& color)
{
	INT32 nRValue = 0;
	INT32 nGValue = 0;
	INT32 nBValue = 0;

	color = GetDefaultValue();

	HRESULT hr = m_rValue.GetValue(nRValue);

	if (FAILED(hr))
	{
		TRACE1("CAnimationColor::GetValue failed for Red component. Error code: %x.\n", hr);
		return FALSE;
	}

	hr = m_gValue.GetValue(nGValue);

	if (FAILED(hr))
	{
		TRACE1("CAnimationColor::GetValue failed for Green component. Error code: %x.\n", hr);
		return FALSE;
	}

	hr = m_bValue.GetValue(nBValue);

	if (FAILED(hr))
	{
		TRACE1("CAnimationColor::GetValue failed for Blue component. Error code: %x.\n", hr);
		return FALSE;
	}

	color = RGB(nRValue, nGValue, nBValue);

	return TRUE;
}

void CAnimationColor::AddTransition(CBaseTransition* pRTransition, CBaseTransition* pGTransition, CBaseTransition* pBTransition)
{
	if (pRTransition != NULL)
	{
		m_rValue.AddTransition(pRTransition);
	}
	
	if (pGTransition != NULL)
	{
		m_gValue.AddTransition(pGTransition);
	}
	
	if (pBTransition != NULL)
	{
		m_bValue.AddTransition(pBTransition);
	}
}

void CAnimationColor::GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst)
{
	lst.AddTail(&m_rValue);
	lst.AddTail(&m_gValue);
	lst.AddTail(&m_bValue);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationRect implementation

CAnimationRect::CAnimationRect()
{
	m_bFixedSize = FALSE;
}

CAnimationRect::CAnimationRect(const CRect& rect, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : CAnimationBaseObject(nGroupID, nObjectID, dwUserData)
{
	SetDefaultValue(rect);
	m_szInitial = rect.Size();
	m_bFixedSize = FALSE;
}

CAnimationRect::CAnimationRect(const CPoint& pt, const CSize& sz, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : CAnimationBaseObject(nGroupID, nObjectID, dwUserData)
{
	CRect rect(pt, sz);
	SetDefaultValue(rect);
	m_szInitial = sz;
	m_bFixedSize = FALSE;
}

CAnimationRect::CAnimationRect(int nLeft, int nTop, int nRight, int nBottom, UINT32 nGroupID, UINT32 nObjectID, DWORD_PTR dwUserData) : CAnimationBaseObject(nGroupID, nObjectID, dwUserData)
{
	CRect rect(nLeft, nTop, nRight, nBottom);
	SetDefaultValue(rect);
	m_szInitial = rect.Size();
	m_bFixedSize = FALSE;
}

void CAnimationRect::SetDefaultValue(const CRect& rect)
{
	m_leftValue.SetDefaultValue(rect.left);
	m_topValue.SetDefaultValue(rect.top);
	m_rightValue.SetDefaultValue(rect.right);
	m_bottomValue.SetDefaultValue(rect.bottom);
	m_szInitial = rect.Size();
}

CRect CAnimationRect::GetDefaultValue()
{
	CRect rect((int)m_leftValue.GetDefaultValue(), (int)m_topValue.GetDefaultValue(), (int)m_rightValue.GetDefaultValue(), 
		(int)m_bottomValue.GetDefaultValue());
	return rect;
}

BOOL CAnimationRect::GetValue(CRect& rect)
{
	INT32 nLeft = 0;
	INT32 nRight = 0;
	INT32 nTop = 0;
	INT32 nBottom = 0;

	rect = GetDefaultValue();

	HRESULT hr = m_leftValue.GetValue(nLeft);
	if (FAILED(hr))
	{
		TRACE1("CAnimationRect::GetValue failed for LEFT value. Error code: %x\n", hr);
		return FALSE;
	}

	hr = m_topValue.GetValue(nTop);
	if (FAILED(hr))
	{
		TRACE1("CAnimationRect::GetValue failed for TOP value. Error code: %x\n", hr);
		return FALSE;
	}

	if (m_bFixedSize)
	{
		rect.SetRect(nLeft, nTop, nLeft + m_szInitial.cx, nTop + m_szInitial.cy);
		return TRUE;
	}

	hr = m_rightValue.GetValue(nRight);
	if (FAILED(hr))
	{
		TRACE1("CAnimationRect::GetValue failed for RIGHT value. Error code: %x\n", hr);
		return FALSE;
	}

	hr = m_bottomValue.GetValue(nBottom);
	if (FAILED(hr))
	{
		TRACE1("CAnimationRect::GetValue failed for BOTTOM value. Error code: %x\n", hr);
		return FALSE;
	}

	rect.SetRect(nLeft, nTop, nRight, nBottom);
	return TRUE;
}

void CAnimationRect::AddTransition(CBaseTransition* pLeftTransition, CBaseTransition* pTopTransition, 
				   CBaseTransition* pRightTransition, CBaseTransition* pBottomTransition)
{
	if (pLeftTransition != NULL)
	{
		m_leftValue.AddTransition(pLeftTransition);
	}
	
	if (pTopTransition != NULL)
	{
		m_topValue.AddTransition(pTopTransition);
	}
	
	if (pRightTransition != NULL)
	{
		m_rightValue.AddTransition(pRightTransition);
	}
	
	if (pBottomTransition != NULL)
	{
		m_bottomValue.AddTransition(pBottomTransition);
	}
}

void CAnimationRect::GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst)
{
	lst.AddTail(&m_leftValue);
	lst.AddTail(&m_rightValue);
	lst.AddTail(&m_topValue);
	lst.AddTail(&m_bottomValue);
}

//////////////////////////////////////////////////////////////////////////
// CAnimationGroup implementation

CAnimationGroup::CAnimationGroup(CAnimationController* pParentController, UINT32 nGroupID) : m_nGroupID(nGroupID), m_bAutodestroyKeyframes(TRUE), m_bAutoclearTransitions(TRUE),
	m_bAutodestroyAnimationObjects(FALSE), m_pParentController(pParentController)
{
}

CAnimationGroup::~CAnimationGroup()
{
	RemoveKeyframes();
	RemoveTransitions();
	if (m_bAutodestroyAnimationObjects)
	{
		while (!m_lstAnimationObjects.IsEmpty())
		{
			delete m_lstAnimationObjects.RemoveTail();
		}
	}
	else
	{
		for (POSITION posObj = m_lstAnimationObjects.GetHeadPosition(); posObj != NULL;)
		{
			CAnimationBaseObject* pObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(posObj));
			pObject->DetachFromController();
		}

		m_lstAnimationObjects.RemoveAll();
	}
}

void CAnimationGroup::AddKeyframes(IUIAnimationStoryboard* pStoryboard, BOOL bAddDeep)
{
	for (POSITION pos = m_lstKeyFrames.GetHeadPosition(); pos != NULL;)
	{
		CBaseKeyFrame* pBase = DYNAMIC_DOWNCAST(CBaseKeyFrame, m_lstKeyFrames.GetNext(pos));
		ASSERT(pBase != NULL);

		if (pBase == NULL)
		{
			continue;
		}

		if (pBase->IsKeyframeAtOffset())
		{
			pBase->AddToStoryboard(pStoryboard, bAddDeep);
		}
		else if (!pBase->IsKeyframeAtOffset() && bAddDeep)
		{
			pBase->AddToStoryboard(pStoryboard, TRUE);
		}
	}
}

void CAnimationGroup::RemoveKeyframes()
{
	CBaseKeyFrame* pStoryboardStart = CAnimationController::GetKeyframeStoryboardStart();

	if (m_bAutodestroyKeyframes)
	{
		while (!m_lstKeyFrames.IsEmpty())
		{
			CKeyFrame* pKF = (CKeyFrame*) m_lstKeyFrames.RemoveTail();
			if (pKF != pStoryboardStart)
			{
				delete pKF;
			}
		}
	}
	else
	{
		m_lstKeyFrames.RemoveAll();
	}
}

void CAnimationGroup::AddTransitions(IUIAnimationStoryboard* pStoryboard, BOOL bDependOnKeyframes)
{
	for (POSITION pos = m_lstAnimationObjects.GetHeadPosition(); pos != NULL;)
	{
		CAnimationBaseObject* pAnimationObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(pos));
		ASSERT_VALID(pAnimationObject);

		if (pAnimationObject != NULL)
		{
			pAnimationObject->ApplyTransitions(pStoryboard, bDependOnKeyframes);
		}
	}
}

BOOL CAnimationGroup::CreateTransitions()
{
	for (POSITION pos = m_lstAnimationObjects.GetHeadPosition(); pos != NULL;)
	{
		CAnimationBaseObject* pAnimationObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(pos));
		ASSERT_VALID(pAnimationObject);

		if (pAnimationObject == NULL)
		{
			continue;
		}

		if (!pAnimationObject->CreateTransitions())
		{
			return FALSE;
		}
	}

	return TRUE;
}

void CAnimationGroup::ApplyTransitions()
{
	ASSERT(m_pStoryboard != NULL);

	if (m_pStoryboard == NULL || !CreateTransitions())
	{
		return;
	}

	// add static keyframes (keyframes dependent on offsets)
	AddKeyframes(m_pStoryboard, FALSE);

	// add transitions that do not depend on keyframes
	AddTransitions(m_pStoryboard, FALSE);	

	// add keyframes depending on transitions and other keyframes
	AddKeyframes(m_pStoryboard, TRUE);

	// add transitions that depend on keyframes
	AddTransitions(m_pStoryboard, TRUE);	
}

void CAnimationGroup::RemoveTransitions()
{
	if (m_bAutoclearTransitions)
	{
		for (POSITION pos = m_lstAnimationObjects.GetHeadPosition(); pos != NULL;)
		{
			CAnimationBaseObject* pAnimationObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(pos));
			ASSERT_VALID(pAnimationObject);

			if (pAnimationObject != NULL)
			{
				pAnimationObject->ClearTransitions(FALSE);
			}
		}
	}
}

void CAnimationGroup::SetAutodestroyTransitions(BOOL bAutoDestroy)
{
	for (POSITION pos = m_lstAnimationObjects.GetHeadPosition(); pos != NULL;)
	{
		CAnimationBaseObject* pAnimationObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(pos));
		ASSERT_VALID(pAnimationObject);

		if (pAnimationObject != NULL)
		{
			pAnimationObject->SetAutodestroyTransitions(bAutoDestroy);
		}
	}
}

CAnimationBaseObject* CAnimationGroup::FindAnimationObject(IUIAnimationVariable* pVariable)
{
	for (POSITION pos = m_lstAnimationObjects.GetHeadPosition(); pos != NULL;)
	{
		CAnimationBaseObject* pAnimationObject = DYNAMIC_DOWNCAST(CAnimationBaseObject, m_lstAnimationObjects.GetNext(pos));
		ASSERT_VALID(pAnimationObject);

		if (pAnimationObject != NULL && pAnimationObject->ContainsVariable(pVariable))
		{
			return pAnimationObject;
		}
	}

	return NULL;
}

BOOL CAnimationGroup::Animate(IUIAnimationManager* pManager, IUIAnimationTimer* pTimer, BOOL bScheduleNow)
{
	// clean up the old storyboard
	if (m_pStoryboard != NULL)
	{
		m_pStoryboard.Detach()->Release();
		m_pStoryboard = NULL;
	}

	if (pManager == NULL || pTimer == NULL)
	{
		return FALSE;
	}

	HRESULT hr = pManager->CreateStoryboard(&m_pStoryboard);
	if (FAILED(hr))
	{
		TRACE1("IUIAnimationManager::CreateStoryboard failed. Error code: %x.\n", hr);
		return FALSE;
	}

	hr = m_pStoryboard->SetTag(NULL, m_nGroupID);
	if (FAILED(hr))
	{
		TRACE1("IUIAnimationStoryboard::SetTag failed. Error code: %x.\n", hr);
		return FALSE;
	}

	ApplyTransitions();

	if (bScheduleNow)
	{
		UI_ANIMATION_SECONDS timeNow;
		hr = pTimer->GetTime(&timeNow);
		if (FAILED(hr))
		{
			TRACE1("IUIAnimationTimer::GetTime failed. Error code: %x.\n", hr);
			return FALSE;
		}
		return Schedule(pTimer, timeNow);
	}

	return TRUE;
}

BOOL CAnimationGroup::Schedule(IUIAnimationTimer* pTimer, UI_ANIMATION_SECONDS time)
{
	if (pTimer == NULL)
	{
		return FALSE;
	}

	if (m_pParentController == NULL)
	{
		TRACE("Schedule failed, because m_pParentController is NULL.\n");
		return FALSE;
	}

	if (m_pStoryboard == NULL)
	{
		TRACE("Schedule failed, because m_pStoryboard is NULL: call AnimateGroup first.\n");
		return FALSE;
	}

	UI_ANIMATION_SECONDS timeNow;
	if (time == 0.0)
	{
		pTimer->GetTime(&timeNow);
	}
	else
	{
		timeNow = time;
	}

	m_pParentController->OnBeforeAnimationStart(this);

	HRESULT hr = m_pStoryboard->Schedule(timeNow);
	if (FAILED(hr))
	{
		TRACE1("Failed to schedule Animation Group. Error code: %x\n", hr);
		return FALSE;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// CAnimationController implementation

CAnimationController::CAnimationController(void)
{
	m_pRelatedWnd = NULL;
	m_bIsValid = TRUE;
}

CAnimationController::~CAnimationController(void)
{
	RemoveAllAnimationGroups();
}

IUIAnimationManager* CAnimationController::GetUIAnimationManager()
{
	if (!m_bIsValid)
	{
		return NULL;
	}

	if (m_pAnimationManager != NULL)
	{
		return m_pAnimationManager;
	}

	HRESULT hr = CoCreateInstance(CLSID_UIAnimationManager, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAnimationManager));
	if (FAILED(hr))
	{
		TRACE1("Failed to create IUIAnimationManager. Error code: %x\n", hr);
		m_pAnimationManager = NULL;
		if (hr == REGDB_E_CLASSNOTREG || hr == E_NOINTERFACE)
		{
			m_bIsValid = FALSE;
		}
		
		return NULL;
	}

	return m_pAnimationManager;
}

IUIAnimationTransitionLibrary* CAnimationController::GetUITransitionLibrary()
{
	if (!m_bIsValid)
	{
		return NULL;
	}

	if (m_pTransitionLibrary != NULL)
	{
		return m_pTransitionLibrary;
	}

	HRESULT hr = CoCreateInstance(CLSID_UIAnimationTransitionLibrary, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pTransitionLibrary));
	if (FAILED(hr))
	{
		TRACE1("Failed to create IUIAnimationTransitionLibrary. Error code: %x\n", hr);
		m_pTransitionLibrary = NULL;

		if (hr == REGDB_E_CLASSNOTREG || hr == E_NOINTERFACE)
		{
			m_bIsValid = FALSE;
		}

		return NULL;
	}

	return m_pTransitionLibrary;
}

IUIAnimationTimer* CAnimationController::GetUIAnimationTimer()
{
	if (!m_bIsValid)
	{
		return NULL;
	}

	if (m_pAnimationTimer != NULL)
	{
		return m_pAnimationTimer;
	}

	HRESULT hr = CoCreateInstance(CLSID_UIAnimationTimer, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAnimationTimer));
	
	if (FAILED(hr))
	{
		TRACE1("Failed to create IUIAnimationTimer. Error code: %x\n", hr);
		m_pAnimationTimer = NULL;
		if (hr == REGDB_E_CLASSNOTREG || hr == E_NOINTERFACE)
		{
			m_bIsValid = FALSE;
		}
		return NULL;
	}

	return m_pAnimationTimer;
}

IUIAnimationTransitionFactory* CAnimationController::GetUITransitionFactory()
{
	if (!m_bIsValid)
	{
		return NULL;
	}

	if (m_pTransitionFactory != NULL)
	{
		return m_pTransitionFactory;
	}

	HRESULT hr = CoCreateInstance(CLSID_UIAnimationTransitionFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pTransitionFactory));
	
	if (FAILED(hr))
	{
		TRACE1("Failed to create IUIAnimationTransitionFactory. Error code: %x\n", hr);
		m_pTransitionFactory = NULL;
		if (hr == REGDB_E_CLASSNOTREG || hr == E_NOINTERFACE)
		{
			m_bIsValid = FALSE;
		}
		return NULL;
	}

	return m_pTransitionFactory;
}

CAnimationGroup* CAnimationController::AddAnimationObject(CAnimationBaseObject* pObject)
{
	ENSURE(pObject != NULL);
	ASSERT_VALID(pObject);

	UINT32 nGroupID = pObject->GetGroupID();

	if (pObject->m_pParentController != NULL)
	{
		if (pObject->m_pParentController == this)
		{
			// already added to this controller
			return FindAnimationGroup(nGroupID);
		}

		ASSERT(FALSE);
		TRACE("AddAnimationObject failed because pObject is already added to another controller.\n");
		return NULL;
	}

	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);

	if (pGroup == NULL)
	{
		pGroup = new CAnimationGroup(this, nGroupID);
		m_lstAnimationGroups.AddTail(pGroup);
	}

	pGroup->m_lstAnimationObjects.AddTail(pObject);
	pObject->m_pParentController = this;

	return pGroup;
}

void CAnimationController::RemoveAnimationObject(CAnimationBaseObject* pObject, BOOL bNoDelete)
{
	ENSURE(pObject != NULL);
	ASSERT_VALID(pObject);

	CAnimationGroup* pGroup = FindAnimationGroup(pObject->GetGroupID());
	if (pGroup != NULL)
	{
		POSITION pos = pGroup->m_lstAnimationObjects.Find(pObject);
		if (pos != NULL)
		{
			pGroup->m_lstAnimationObjects.RemoveAt(pos);
			if (pGroup->m_bAutodestroyAnimationObjects && !bNoDelete)
			{
				delete pObject;
			}
			else
			{
				pObject->m_pParentController = NULL;
			}
		}
	}
}

void CAnimationController::RemoveAnimationGroup(UINT32 nGroupID)
{
	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	if (pGroup != NULL)
	{
		POSITION pos = m_lstAnimationGroups.Find(pGroup);
		if (pos != NULL)
		{
			m_lstAnimationGroups.RemoveAt(pos);
			delete pGroup;
		}
	}
}

void CAnimationController::RemoveAllAnimationGroups()
{
	for (POSITION pos = m_lstAnimationGroups.GetHeadPosition(); pos != NULL;)
	{
		CAnimationGroup* pGroup = m_lstAnimationGroups.GetNext(pos);

		if (pGroup != NULL)
		{
			delete pGroup;
		}
	}

	m_lstAnimationGroups.RemoveAll();
}

BOOL CAnimationController::AddKeyframeToGroup(UINT32 nGroupID, CBaseKeyFrame* pKeyframe)
{
	ASSERT_VALID(pKeyframe);

	if (pKeyframe == NULL)
	{
		return FALSE;
	}

	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	if (pGroup == NULL)
	{
		pGroup = new CAnimationGroup(this, nGroupID);
		m_lstAnimationGroups.AddTail(pGroup);
	}

	if (pGroup->m_lstKeyFrames.Find(pKeyframe) != NULL)
	{
		return TRUE;
	}

	pGroup->m_lstKeyFrames.AddTail(pKeyframe);
	return TRUE;
}

CKeyFrame* CAnimationController::CreateKeyframe(UINT32 nGroupID, CBaseTransition* pTransition)
{
	ASSERT(pTransition != NULL);

	if (pTransition == NULL)
	{
		return NULL;
	}

	CKeyFrame* pKeyFrame = new CKeyFrame(pTransition);
	if (!AddKeyframeToGroup(nGroupID, pKeyFrame))
	{
		delete pKeyFrame;
		return NULL;
	}

	return pKeyFrame;
}

CKeyFrame* CAnimationController::CreateKeyframe(UINT32 nGroupID, CBaseKeyFrame* pKeyframe, UI_ANIMATION_SECONDS offset)
{
	ASSERT(pKeyframe != NULL);

	if (pKeyframe == NULL)
	{
		return NULL;
	}

	CKeyFrame* pKeyFrameNew = new CKeyFrame(pKeyframe, offset);
	if (!AddKeyframeToGroup(nGroupID, pKeyFrameNew))
	{
		delete pKeyFrameNew;
		return NULL;
	}

	return pKeyFrameNew;
}

void CAnimationController::RemoveTransitions(UINT32 nGroupID)
{
	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	if (pGroup != NULL)
	{
		pGroup->RemoveTransitions();
	}
}

CAnimationGroup* CAnimationController::FindAnimationGroup(UINT32 nGroupID)
{
	CAnimationGroup* pGroup = NULL;

	for (POSITION pos = m_lstAnimationGroups.GetHeadPosition(); pos != NULL;)
	{
		pGroup = m_lstAnimationGroups.GetNext(pos);
		ENSURE(pGroup != NULL);

		if (pGroup->GetGroupID() == nGroupID)
		{
			return pGroup;
		}
	}

	return NULL;
}

CAnimationGroup* CAnimationController::FindAnimationGroup(IUIAnimationStoryboard* pStoryboard)
{
	CAnimationGroup* pGroup = NULL;

	if (pStoryboard == NULL)
	{
		return NULL;
	}

	for (POSITION pos = m_lstAnimationGroups.GetHeadPosition(); pos != NULL;)
	{
		pGroup = m_lstAnimationGroups.GetNext(pos);
		ENSURE(pGroup != NULL);

		UINT32 nGroupID = pGroup->GetGroupID();
		UINT32 nID = (UINT32)-1;
		IUnknown* pUnk = NULL;

		HRESULT hr = UIAnimation_GetStoryboardTag(pStoryboard, 0, &pUnk, &nID);
		if (SUCCEEDED(hr) && nGroupID == nID)
		{
			return pGroup;
		}

		if (pGroup->m_pStoryboard == pStoryboard)
		{
			return pGroup;
		}
	}

	return NULL;
}

BOOL CAnimationController::FindAnimationObject(IUIAnimationVariable* pVariable, CAnimationBaseObject** ppObject, CAnimationGroup** ppGroup)
{
	if (pVariable == NULL || ppObject == NULL || ppGroup == NULL)
	{
		return FALSE;
	}


	for (POSITION pos = m_lstAnimationGroups.GetHeadPosition(); pos != NULL;)
	{
		*ppGroup = m_lstAnimationGroups.GetNext(pos);
		*ppObject = (*ppGroup)->FindAnimationObject(pVariable);
		if (*ppObject != NULL)
		{
			return TRUE;
		}
	}

	*ppObject = NULL;
	*ppGroup = NULL;
	return FALSE;
}

void CAnimationController::UpdateAnimationManager()
{
	IUIAnimationManager* pManager = GetUIAnimationManager();
	IUIAnimationTimer* pTimer = GetUIAnimationTimer();

	if (pManager == NULL || pTimer == NULL)
	{
		return;
	}

	UI_ANIMATION_SECONDS secondsNow;
	pTimer->GetTime(&secondsNow);
	pManager->Update(secondsNow);
}

BOOL CAnimationController::IsAnimationInProgress()
{
	IUIAnimationManager* pManager = GetUIAnimationManager();

	if (pManager == NULL)
	{
		return FALSE;
	}

	UI_ANIMATION_MANAGER_STATUS status;
	if (FAILED(pManager->GetStatus(&status)))
	{
		return FALSE;
	}

	return (status == UI_ANIMATION_MANAGER_BUSY);
}

BOOL CAnimationController::AnimateGroup(UINT32 nGroupID, BOOL bScheduleNow)
{
	if (!m_bIsValid)
	{
		return FALSE;
	}

	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	IUIAnimationManager* pManager = GetUIAnimationManager();
	IUIAnimationTimer* pTimer = GetUIAnimationTimer();

	if (pGroup == NULL)
	{
		TRACE("AnimateGroup failed, because a group with specified ID is not found.\n");
		return FALSE;
	}

	if (pManager == NULL || pTimer == NULL)
	{
		TRACE("AnimateGroup failed, because animation manager and/or animation timer have not been initialized.\n");
		return FALSE;
	}

	BOOL bResult = pGroup->Animate(pManager, pTimer, bScheduleNow);

	if (bResult && bScheduleNow)
	{
		OnAfterSchedule(pGroup);
	}

	return bResult;
}

BOOL CAnimationController::ScheduleGroup(UINT32 nGroupID, UI_ANIMATION_SECONDS time)
{
	if (!m_bIsValid)
	{
		return FALSE;
	}

	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);

	if (pGroup == NULL)
	{
		TRACE("ScheduleGroup failed, because a group with specified ID is not found.\n");
		return FALSE;
	}

	IUIAnimationTimer* pTimer = GetUIAnimationTimer();

	if (pTimer == NULL)
	{
		TRACE("ScheduleGroup failed, because Animation Timer has not been initialized.\n");
		return FALSE;
	}

	BOOL bResult = pGroup->Schedule(pTimer, time);
	if (bResult)
	{
		OnAfterSchedule(pGroup);
	}

	return bResult;
}

void CAnimationController::OnBeforeAnimationStart(CAnimationGroup* /*pGroup*/)
{
}

void CAnimationController::OnAfterSchedule(CAnimationGroup* pGroup)
{
	CleanUpGroup(pGroup);
}

void CAnimationController::CleanUpGroup(UINT32 nGroupID)
{
	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	if (pGroup != NULL)
	{
		CleanUpGroup(pGroup);
	}
}
void CAnimationController::CleanUpGroup(CAnimationGroup* pGroup)
{
	ASSERT(pGroup != NULL);

	if (pGroup != NULL)
	{
		pGroup->RemoveKeyframes();
		pGroup->RemoveTransitions();
	}
}

void CAnimationController::OnAnimationManagerStatusChanged(UI_ANIMATION_MANAGER_STATUS newStatus, UI_ANIMATION_MANAGER_STATUS /*previousStatus*/)
{
	if (newStatus == UI_ANIMATION_MANAGER_BUSY && m_pRelatedWnd->GetSafeHwnd() != NULL && ::IsWindow(m_pRelatedWnd->GetSafeHwnd()))
	{
		m_pRelatedWnd->RedrawWindow(NULL, NULL, RDW_INVALIDATE);
	}
}

void CAnimationController::OnAnimationValueChanged(CAnimationGroup* /*pGroup*/, CAnimationBaseObject* /*pObject*/, IUIAnimationVariable* /*variable*/, DOUBLE /*newValue*/, DOUBLE /*prevValue*/)
{
}

void CAnimationController::OnAnimationIntegerValueChanged(CAnimationGroup* /*pGroup*/, CAnimationBaseObject* /*pObject*/, IUIAnimationVariable* /*variable*/, INT32 /*newValue*/, INT32 /*prevValue*/)
{
}

void CAnimationController::OnStoryboardStatusChanged(CAnimationGroup* /*pGroup*/, UI_ANIMATION_STORYBOARD_STATUS /*newStatus*/, UI_ANIMATION_STORYBOARD_STATUS /*previousStatus*/)
{
}

void CAnimationController::OnStoryboardUpdated(CAnimationGroup* /*pGroup*/)
{
}

BOOL CAnimationController::OnHasPriorityCancel(CAnimationGroup* /*pGroupScheduled*/, CAnimationGroup* /*pGroupNew*/, UI_ANIMATION_PRIORITY_EFFECT /*priorityEffect*/)
{
	return FALSE;
}

BOOL CAnimationController::OnHasPriorityConclude(CAnimationGroup* /*pGroupScheduled*/, CAnimationGroup* /*pGroupNew*/, UI_ANIMATION_PRIORITY_EFFECT /*priorityEffect*/)
{
	return FALSE;
}

BOOL CAnimationController::OnHasPriorityTrim(CAnimationGroup* /*pGroupScheduled*/, CAnimationGroup* /*pGroupNew*/, UI_ANIMATION_PRIORITY_EFFECT /*priorityEffect*/)
{
	return FALSE;
}

BOOL CAnimationController::OnHasPriorityCompress(CAnimationGroup* /*pGroupScheduled*/, CAnimationGroup* /*pGroupNew*/, UI_ANIMATION_PRIORITY_EFFECT /*priorityEffect*/)
{
	return FALSE;
}

void CAnimationController::OnAnimationTimerPreUpdate()
{
}

void CAnimationController::OnAnimationTimerPostUpdate()
{
	if (m_pRelatedWnd->GetSafeHwnd() != NULL && ::IsWindow(m_pRelatedWnd->GetSafeHwnd()))
	{
		m_pRelatedWnd->Invalidate();
	}
}

void CAnimationController::OnAnimationTimerRenderingTooSlow(UINT32 /*fps*/)
{
}

BOOL CAnimationController::EnableAnimationManagerEvent(BOOL bEndble)
{
	IUIAnimationManager* pAnimationManager = GetUIAnimationManager();

	if (pAnimationManager == NULL)
	{
		return FALSE;
	}

	if (!bEndble)
	{
		pAnimationManager->SetManagerEventHandler(NULL);
		return TRUE;
	}

	CComPtr<IUIAnimationManagerEventHandler> pManagerEventHandler;
	if (FAILED(CAnimationManagerEventHandler::CreateInstance(this, &pManagerEventHandler)))
	{
		TRACE("Failed to create Animation Manager Event Handler.\n");
		return FALSE;
	}

	if (FAILED(pAnimationManager->SetManagerEventHandler(pManagerEventHandler)))
	{
		TRACE("Failed to set Animation Manager Event Handler.\n");
		return FALSE;
	}
	
	return TRUE;
}

BOOL CAnimationController::EnableAnimationTimerEventHandler(BOOL bEnable, UI_ANIMATION_IDLE_BEHAVIOR idleBehavior)
{
	IUIAnimationTimer* pTimer = GetUIAnimationTimer();
	CComQIPtr<IUIAnimationTimerUpdateHandler> pUpdateHandler = GetUIAnimationManager();

	if (pTimer == NULL || pUpdateHandler == NULL)
	{
		return FALSE;
	}

	if (!bEnable)
	{
		pTimer->SetTimerEventHandler(NULL);
		pTimer->SetTimerUpdateHandler(NULL, idleBehavior);
		return TRUE;
	}

	CComPtr<IUIAnimationTimerEventHandler> pTimerHandler;
	if (FAILED(CAnimationTimerEventHandler::CreateInstance(this, &pTimerHandler)))
	{
		TRACE("Failed to create Animation Timer Event Handler.\n");
		return FALSE;
	}

	if (FAILED(pTimer->SetTimerEventHandler(pTimerHandler)))
	{
		TRACE("Failed to set Animation Timer Event Handler.\n");
		return FALSE;
	}

	if (pUpdateHandler != NULL)
	{
		pTimer->SetTimerUpdateHandler(pUpdateHandler, idleBehavior);
	}

	return TRUE;
}

BOOL CAnimationController::EnableStoryboardEventHandler(UINT32 nGroupID, BOOL bEnable)
{
	CAnimationGroup* pGroup = FindAnimationGroup(nGroupID);
	if (pGroup == NULL)
	{
		return FALSE;
	}

	if (pGroup->m_pStoryboard == NULL)
	{
		TRACE("Storyboard has not been created for the specified Animation Group\n");
		return FALSE;
	}

	if (!bEnable)
	{
		pGroup->m_pStoryboard->SetStoryboardEventHandler(NULL);
		return TRUE;
	}

	CComPtr<IUIAnimationStoryboardEventHandler> pStoryboardEventHandler;
	if (FAILED(CAnimationStoryboardEventHandler::CreateInstance(this, &pStoryboardEventHandler)))
	{
		TRACE("Failed to create Storyboard Event Handler.\n");
		return FALSE;
	}

	if (FAILED(pGroup->m_pStoryboard->SetStoryboardEventHandler(pStoryboardEventHandler)))
	{
		TRACE("Failed to set Storyboard Manager Event Handler.\n");
		return FALSE;
	}

	return TRUE;
}

BOOL CAnimationController::EnablePriorityComparisonHandler(DWORD_PTR dwHandlerType)
{
	IUIAnimationManager* pAnimationManager = GetUIAnimationManager();

	if (pAnimationManager == NULL)
	{
		return FALSE;
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_ALL) == UI_ANIMATION_PHT_NONE)
	{
		pAnimationManager->SetCancelPriorityComparison(NULL);
		pAnimationManager->SetCompressPriorityComparison(NULL);
		pAnimationManager->SetConcludePriorityComparison(NULL);
		pAnimationManager->SetTrimPriorityComparison(NULL);
		return TRUE;
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_CANCEL_REMOVE) == UI_ANIMATION_PHT_CANCEL_REMOVE)
	{
		pAnimationManager->SetCancelPriorityComparison(NULL);
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_CONCLUDE_REMOVE) == UI_ANIMATION_PHT_CONCLUDE_REMOVE)
	{
		pAnimationManager->SetConcludePriorityComparison(NULL);
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_COMPRESS_REMOVE) == UI_ANIMATION_PHT_COMPRESS_REMOVE)
	{
		pAnimationManager->SetCompressPriorityComparison(NULL);
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_TRIM_REMOVE) == UI_ANIMATION_PHT_TRIM_REMOVE)
	{
		pAnimationManager->SetTrimPriorityComparison(NULL);
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_CANCEL) == UI_ANIMATION_PHT_CANCEL)
	{
		CComPtr<IUIAnimationPriorityComparison> pHandler;
		CUIAnimationPriorityComparisonHandler<PriorityComparisonMethodCancel>::CreateInstance(this, &pHandler);
		if (FAILED(pAnimationManager->SetCancelPriorityComparison(pHandler)))
		{
			return FALSE;
		}
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_COMPRESS) == UI_ANIMATION_PHT_COMPRESS)
	{
		CComPtr<IUIAnimationPriorityComparison> pHandler;
		CUIAnimationPriorityComparisonHandler<PriorityComparisonMethodCompress>::CreateInstance(this, &pHandler);
		if (FAILED(pAnimationManager->SetCompressPriorityComparison(pHandler)))
		{
			return FALSE;
		}
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_CONCLUDE) == UI_ANIMATION_PHT_CONCLUDE)
	{
		CComPtr<IUIAnimationPriorityComparison> pHandler;
		CUIAnimationPriorityComparisonHandler<PriorityComparisonMethodConclude>::CreateInstance(this, &pHandler);
		if (FAILED(pAnimationManager->SetConcludePriorityComparison(pHandler)))
		{
			return FALSE;
		}
	}

	if ((dwHandlerType & UI_ANIMATION_PHT_TRIM) == UI_ANIMATION_PHT_TRIM)
	{
		CComPtr<IUIAnimationPriorityComparison> pHandler;
		CUIAnimationPriorityComparisonHandler<PriorityComparisonMethodTrim>::CreateInstance(this, &pHandler);
		if (FAILED(pAnimationManager->SetTrimPriorityComparison(pHandler)))
		{
			return FALSE;
		}
	}

	return TRUE;
}

CBaseKeyFrame* CAnimationController::GetKeyframeStoryboardStart()
{
	return &CAnimationController::g_KeyframeStoryboardStart;
}
