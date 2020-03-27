// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#include <UIAnimation.h>

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

#ifndef __UIAnimationHelper_h__
#define __UIAnimationHelper_h__

// Base class template for all UIAnimation callback base class templates
template <class IUIAnimationCallback, class CUIAnimationCallbackDerived>
class CUIAnimationCallbackBase :
    public IUIAnimationCallback
{
public:
    
    // Creates an instance of CUIAnimationCallbackDerived and returns a pointer to its IUIAnimationCallback interface,
    // plus an optional pointer to the object itself.  Note that the latter is not AddRef'ed.
    static __checkReturn COM_DECLSPEC_NOTHROW HRESULT
    CreateInstance
    (
            __deref_out IUIAnimationCallback **ppUIAnimationCallback,
        __deref_opt_out CUIAnimationCallbackDerived **ppUIAnimationCallbackDerived = NULL
    )
    {
        if (ppUIAnimationCallbackDerived != NULL)
        {
            *ppUIAnimationCallbackDerived = NULL;
        }
        
        if (ppUIAnimationCallback == NULL)
        {
            return E_POINTER;
        }
        
        CUIAnimationCallbackObject<IUIAnimationCallback, CUIAnimationCallbackDerived> *pUIAnimationCallbackDerived =
            new CUIAnimationCallbackObject<IUIAnimationCallback, CUIAnimationCallbackDerived>;
        
        if (pUIAnimationCallbackDerived == NULL)
        {
            *ppUIAnimationCallback = NULL;
            return E_OUTOFMEMORY;
        }
        
        *ppUIAnimationCallback = static_cast<IUIAnimationCallback *>(pUIAnimationCallbackDerived);
        (*ppUIAnimationCallback)->AddRef();
        
        // Do not AddRef class pointer; caller must ensure it has a shorter lifetime than the interface pointer        
        if (ppUIAnimationCallbackDerived != NULL)
        {
            *ppUIAnimationCallbackDerived = pUIAnimationCallbackDerived;
        }
        
        return S_OK;
    }
    
protected:
    
    COM_DECLSPEC_NOTHROW HRESULT
    QueryInterfaceCallback
    (
                   __in REFIID riid,
                   __in REFIID riidCallback,
        __deref_opt_out_opt void **ppvObject
    )
    {
        if (ppvObject == NULL)
        {
            return E_POINTER;
        }
        
        static const IID IID_UNKNOWN = { 0x00000000, 0x0000, 0x0000, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 };
        if (::InlineIsEqualGUID(riid, IID_UNKNOWN))
        {
            *ppvObject = static_cast<IUIAnimationCallback *>(this);
            AddRef();
            return S_OK;
        }
        
        if (::InlineIsEqualGUID(riid, riidCallback))
        {
            *ppvObject = static_cast<IUIAnimationCallback *>(this);
            AddRef();
            return S_OK;
        }
        
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
    
private:
    
    template <class IUIAnimationCallback, class CUIAnimationCallbackDerived>
    class CUIAnimationCallbackObject :
        public CUIAnimationCallbackDerived
    {
    public:
        
        CUIAnimationCallbackObject
        (
        )
         : m_dwRef(0)
        {
        }
        
        // IUnknown
        
        IFACEMETHOD(QueryInterface)
        (
                   __in REFIID riid,
            __deref_out void **ppvObject
        )
        {
            IUIAnimationCallback **ppAnimationInterface = reinterpret_cast<IUIAnimationCallback **>(ppvObject);
            return QueryInterfaceCallback(riid, IID_PPV_ARGS(ppAnimationInterface));
        }
        
        IFACEMETHOD_(ULONG, AddRef)
        (
        )
        {
            return ++m_dwRef;
        }
        
        IFACEMETHOD_(ULONG, Release)
        (
        )
        {
            if (--m_dwRef == 0)
            {
                delete this;
                return 0;
            }
            
            return m_dwRef;
        }
        
    private:
        
        DWORD m_dwRef;
    };
};


/***************************************************************************************\

  Callback Base Class Templates
  
  To define a UIAnimation "callback object", simply derive a class from the appropriate
  template instantiation, e.g.:
  
    class CMyStoryboardEventHandler :
        public CUIAnimationStoryboardEventHandlerBase<CMyStoryboardEventHandler>
    {
        ...
        Implementations of IUIAnimationStoryboardEventHandler methods
        ...
    };
  
  Then, to create an instance of the class, call its static CreateInstance method: 
  
    IUIAnimationStoryboardEventHandler *pStoryboardEventHandler;
    hr = CMyStoryboardEventHandler::CreateInstance(
        &pStoryboardEventHandler
        );
    if (SUCCEEDED(hr))
    {
        hr = m_pStoryboard->SetStoryboardEventHandler(
            pStoryboardEventHandler
            );
        ...
    }
  
  An optional temporary class pointer can be used to initialize the object:
  
    IUIAnimationStoryboardEventHandler *pStoryboardEventHandler;
    CMyStoryboardEventHandler *pMyStoryboardEventHandler;
    hr = CMyStoryboardEventHandler::CreateInstance(
        &pStoryboardEventHandler,
        &pMyStoryboardEventHandler
        );
    if (SUCCCEEDED(hr))
    {
        pMyStoryboardEventHandler->Initialize(this);
        hr = m_pStoryboard->SetStoryboardEventHandler(
            pStoryboardEventHandler
            );
        ...
    }

\***************************************************************************************/

// Base class template for implementation of IUIAnimationManagerEventHandler
template <class CManagerEventHandlerDerived>
class CUIAnimationManagerEventHandlerBase :
    public CUIAnimationCallbackBase<IUIAnimationManagerEventHandler, CManagerEventHandlerDerived>
{
public:
    
    // IUIAnimationManagerEventHandler
    
    // Handles OnManagerStatusChanged events, which occur when the animation manager's status changes
    IFACEMETHOD(OnManagerStatusChanged)
    (
        __in UI_ANIMATION_MANAGER_STATUS newStatus,                     // The new status
        __in UI_ANIMATION_MANAGER_STATUS previousStatus                 // The previous status
    ) PURE;
};

// Base class template for implementation of IUIAnimationVariableChangeHandler
template <class CVariableChangeHandlerDerived>
class CUIAnimationVariableChangeHandlerBase :
    public CUIAnimationCallbackBase<IUIAnimationVariableChangeHandler, CVariableChangeHandlerDerived>
{
public:
    
    // IUIAnimationVariableChangeHandler
    
    // Handles OnValueChanged events, which occur when an animation variable's value changes; receives value updates as DOUBLE
    IFACEMETHOD(OnValueChanged)
    (
        __in IUIAnimationStoryboard *storyboard,                        // The storyboard that is animating the variable
        __in IUIAnimationVariable *variable,                            // The animation variable that was updated
        __in DOUBLE newValue,                                           // The new value
        __in DOUBLE previousValue                                       // The previous value
    ) PURE;
};

// Base class template for implementation of IUIAnimationVariableIntegerChangeHandler
template <class CVariableIntegerChangeHandlerDerived>
class CUIAnimationVariableIntegerChangeHandlerBase :
    public CUIAnimationCallbackBase<IUIAnimationVariableIntegerChangeHandler, CVariableIntegerChangeHandlerDerived>
{
public:
    
    // IUIAnimationVariableIntegerChangeHandler
    
    // Handles OnIntegerValueChanged events, which occur when an animation variable's rounded value changes; receives value updates as INT32
    IFACEMETHOD(OnIntegerValueChanged)
    (
        __in IUIAnimationStoryboard *storyboard,                        // The storyboard that is animating the variable
        __in IUIAnimationVariable *variable,                            // The animation variable that was updated
        __in INT32 newValue,                                            // The new rounded value
        __in INT32 previousValue                                        // The previous rounded value
    ) PURE;
};

// Base class template for implementation of IUIAnimationStoryboardEventHandler
template <class CStoryboardEventHandlerDerived>
class CUIAnimationStoryboardEventHandlerBase :
    public CUIAnimationCallbackBase<IUIAnimationStoryboardEventHandler, CStoryboardEventHandlerDerived>
{
public:
    
    // IUIAnimationStoryboardEventHandler
    
    // Handles OnStoryboardStatusChanged events, which occur when a storyboard's status changes
    IFACEMETHOD(OnStoryboardStatusChanged)
    (
        __in IUIAnimationStoryboard *storyboard,                        // The storyboard that changed status
        __in UI_ANIMATION_STORYBOARD_STATUS newStatus,                  // The new status
        __in UI_ANIMATION_STORYBOARD_STATUS previousStatus              // The previous status 
    ) PURE;
    
    // Handles OnStoryboardUpdated events, which occur when a storyboard is updated
    IFACEMETHOD(OnStoryboardUpdated)
    (
        __in IUIAnimationStoryboard *storyboard                         // The storyboard that was updated
    ) PURE;
};

// Base class template for implementation of IUIAnimationPriorityComparison
template <class CPriorityComparisonDerived>
class CUIAnimationPriorityComparisonBase :
    public CUIAnimationCallbackBase<IUIAnimationPriorityComparison, CPriorityComparisonDerived>
{
public:
    
    // IUIAnimationPriorityComparison
    
    // Determines the relative priority between a scheduled storyboard and a new storyboard
    IFACEMETHOD(HasPriority)
    (
        __in IUIAnimationStoryboard *pStoryboardScheduled,              // Currently scheduled storyboard
        __in IUIAnimationStoryboard *pStoryboardNew,                    // New storyboard that conflicts with scheduled storyboard
        __in UI_ANIMATION_PRIORITY_EFFECT priorityEffect                // Potential effect on attempt to schedule storyboard if HasPriority returns S_FALSE
    ) PURE;
};

// Base class template for implementation of IUIAnimationInterpolator
template <class CInterpolatorDerived>
class CUIAnimationInterpolatorBase :
    public CUIAnimationCallbackBase<IUIAnimationInterpolator, CInterpolatorDerived>
{
public:
    
    // IUIAnimationInterpolator
    
    // Sets the interpolator's initial value and velocity
    IFACEMETHOD(SetInitialValueAndVelocity)
    (
        __in DOUBLE initialValue,                                       // The initial value
        __in DOUBLE initialVelocity                                     // The initial velocity
    ) PURE;
    
    // Sets the interpolator's duration
    IFACEMETHOD(SetDuration)
    (
        __in UI_ANIMATION_SECONDS duration                              // The interpolator duration
    ) PURE;
    
    // Gets the interpolator's duration
    IFACEMETHOD(GetDuration)
    (
        __out UI_ANIMATION_SECONDS *duration                            // The interpolator duration
    ) PURE;
    
    // Gets the final value to which the interpolator leads
    IFACEMETHOD(GetFinalValue)
    (
        __out DOUBLE *value                                             // The final value
    ) PURE;
    
    // Interpolates the value at a given offset
    IFACEMETHOD(InterpolateValue)
    (
         __in UI_ANIMATION_SECONDS offset,                              // The offset
        __out DOUBLE *value                                             // The interpolated value
    ) PURE;
    
    // Interpolates the velocity at a given offset
    IFACEMETHOD(InterpolateVelocity)
    (
         __in UI_ANIMATION_SECONDS offset,                              // The offset
        __out DOUBLE *velocity                                          // The interpolated velocity
    ) PURE;
    
    // Gets the interpolator's dependencies
    IFACEMETHOD(GetDependencies)
    (
        __out UI_ANIMATION_DEPENDENCIES *initialValueDependencies,      // The aspects of the interpolator that depend on its initial value
        __out UI_ANIMATION_DEPENDENCIES *initialVelocityDependencies,   // The aspects of the interpolator that depend on its initial velocity
        __out UI_ANIMATION_DEPENDENCIES *durationDependencies           // The aspects of the interpolator that depend on its duration
    ) PURE;
};

// Base class template for implementation of IUIAnimationTimerEventHandler
template <class CTimerEventHandlerDerived>
class CUIAnimationTimerEventHandlerBase :
    public CUIAnimationCallbackBase<IUIAnimationTimerEventHandler, CTimerEventHandlerDerived>
{
public:
    
    // IUIAnimationTimerEventHandler
    
    // Handles OnPreUpdate events, which occur before an animation udpate begins
    IFACEMETHOD(OnPreUpdate)
    (
    ) PURE;
    
    // Handles OnPostUpdate events, which occur after an animation update is finished
    IFACEMETHOD(OnPostUpdate)
    (
    ) PURE;
    
    // Handles OnRenderingTooSlow events, which occur when the rendering frame rate for an animation falls below the minimum acceptable frame rate
    IFACEMETHOD(OnRenderingTooSlow)
    (
        __in UINT32 framesPerSecond                                     // The current frame rate, in frames-per-second
    ) PURE;
};


/***************************************************************************************\

  Helper Functions

\***************************************************************************************/

// Gets the tag of a variable, or (NULL, idDefault) if no tag was set
inline __checkReturn HRESULT
UIAnimation_GetVariableTag
(
               __in IUIAnimationVariable *pVariable,
               __in UINT32 idDefault,
    __deref_opt_out IUnknown **ppObject,
          __out_opt UINT32 *pId
)
{
    HRESULT hr = pVariable->GetTag(ppObject, pId);
    
    if (hr == UI_E_VALUE_NOT_SET)
    {
        if (ppObject != NULL)
        {
            *ppObject = NULL;
        }
        
        if (pId != NULL)
        {
            *pId = idDefault;
        }
        
        hr = S_OK;
    }
    
    return hr;
}

// Gets the tag of a storyboard, or (NULL, idDefault) if no tag was set
inline __checkReturn HRESULT
UIAnimation_GetStoryboardTag
(
               __in IUIAnimationStoryboard *pStoryboard,
               __in UINT32 idDefault,
    __deref_opt_out IUnknown **ppObject,
          __out_opt UINT32 *pId
)
{
    HRESULT hr = pStoryboard->GetTag(ppObject, pId);
    
    if (hr == UI_E_VALUE_NOT_SET)
    {
        if (ppObject != NULL)
        {
            *ppObject = NULL;
        }
        
        if (pId != NULL)
        {
            *pId = idDefault;
        }
        
        hr = S_OK;
    }
    
    return hr;
}

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#endif // __UIAnimationHelper_h__
