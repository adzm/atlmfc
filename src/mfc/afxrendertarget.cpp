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
#include "afxrendertarget.h"

template<class Interface>
AFX_INLINE void SafeRelease(Interface **ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();
		(*ppInterfaceToRelease) = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// _AFX_D2D_STATE

_AFX_D2D_STATE::_AFX_D2D_STATE()
{
	m_pDirect2dFactory = NULL;
	m_pWriteFactory = NULL;
	m_pWicFactory = NULL;
	m_hinstD2DDLL = NULL;
	m_hinstDWriteDLL = NULL;
	m_bComInitialized = FALSE;
}

_AFX_D2D_STATE::~_AFX_D2D_STATE()
{
	// D2D references should already have been released via
	// CWinApp::ExitInstance, but call again to make sure.
	ReleaseD2DRefs();
}

BOOL _AFX_D2D_STATE::InitD2D(D2D1_FACTORY_TYPE d2dFactoryType, DWRITE_FACTORY_TYPE writeFactoryType)
{
	if (m_bD2DInitialized)
	{
		return TRUE;
	}

	HRESULT hr = S_OK;

	if (!m_bComInitialized)
	{
		hr = CoInitialize(NULL);
		if (FAILED(hr))
		{
			return FALSE;
		}

		m_bComInitialized = TRUE;
	}

	if ((m_hinstD2DDLL = ::AtlLoadSystemLibraryUsingFullPath(L"D2D1.dll")) == NULL)
	{
		return FALSE;
	}

	typedef HRESULT (WINAPI * D2D1CREATEFACTORY)(D2D1_FACTORY_TYPE factoryType, REFIID riid, CONST D2D1_FACTORY_OPTIONS *pFactoryOptions, void **ppIFactory);

	D2D1CREATEFACTORY pfD2D1CreateFactory = (D2D1CREATEFACTORY)::GetProcAddress(m_hinstD2DDLL, "D2D1CreateFactory");
	if (pfD2D1CreateFactory != NULL)
	{
		hr = (*pfD2D1CreateFactory)(d2dFactoryType, __uuidof(ID2D1Factory),
			NULL, reinterpret_cast<void **>(&m_pDirect2dFactory));
		if (FAILED(hr))
		{
			m_pDirect2dFactory = NULL;
			return FALSE;
		}
	}

	m_pfD2D1MakeRotateMatrix = (D2D1MAKEROTATEMATRIX)::GetProcAddress(m_hinstD2DDLL, "D2D1MakeRotateMatrix");

	m_hinstDWriteDLL = AtlLoadSystemLibraryUsingFullPath(L"DWrite.dll");
	if (m_hinstDWriteDLL != NULL)
	{
		auto pfD2D1CreateFactory = AtlGetProcAddressFn(m_hinstDWriteDLL, DWriteCreateFactory);
		if (pfD2D1CreateFactory)
		{
			hr = (*pfD2D1CreateFactory)(writeFactoryType, __uuidof(IDWriteFactory), (IUnknown**)&m_pWriteFactory);
		}
	}

	hr = CoCreateInstance(CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&m_pWicFactory);

	m_bD2DInitialized = TRUE;
	return TRUE;
}

void _AFX_D2D_STATE::ReleaseD2DRefs()
{
	if (m_bD2DInitialized)
	{
		if (m_pDirect2dFactory != NULL)
		{
			m_pDirect2dFactory->Release();
			m_pDirect2dFactory = NULL;
		}

		if (m_pWriteFactory != NULL)
		{
			m_pWriteFactory->Release();
			m_pWriteFactory = NULL;
		}

		if (m_pWicFactory != NULL)
		{
			m_pWicFactory->Release();
			m_pWicFactory = NULL;
		}

		if (m_hinstD2DDLL != NULL)
		{
			::FreeLibrary(m_hinstD2DDLL);
			m_hinstD2DDLL = NULL;
		}

		if (m_hinstDWriteDLL != NULL)
		{
			::FreeLibrary(m_hinstDWriteDLL);
			m_hinstDWriteDLL = NULL;
		}

		m_bD2DInitialized = FALSE;
	}

	if (m_bComInitialized)
	{
		CoUninitialize();
		m_bComInitialized = FALSE;
	}
}

_AFX_D2D_STATE* AFX_CDECL AfxGetD2DState()
{
	return _afxD2DState.GetData();
}

void AFX_CDECL AfxReleaseD2DRefs()
{
	if (_afxD2DState.GetDataNA() != NULL)
	{
		_afxD2DState.GetDataNA()->ReleaseD2DRefs();
	}
}

////////////////////////////////////////////////////////////////////////////////
// CD2DPointF

CD2DPointF::CD2DPointF(const CPoint& pt)
{
	x = (FLOAT)pt.x;
	y = (FLOAT)pt.y;
}

CD2DPointF::CD2DPointF(const D2D1_POINT_2F& pt)
{
	x = pt.x;
	y = pt.y;
}

CD2DPointF::CD2DPointF(const D2D1_POINT_2F* pt)
{
	x = pt == NULL ? 0 : pt->x;
	y = pt == NULL ? 0 : pt->y;
}

CD2DPointF::CD2DPointF(FLOAT fX, FLOAT fY)
{
	x = fX;
	y = fY;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DPointU

CD2DPointU::CD2DPointU(const CPoint& pt)
{
	x = (UINT32)pt.x;
	y = (UINT32)pt.y;
}

CD2DPointU::CD2DPointU(const D2D1_POINT_2U& pt)
{
	x = pt.x;
	y = pt.y;
}

CD2DPointU::CD2DPointU(const D2D1_POINT_2U* pt)
{
	x = pt == NULL ? 0 : pt->x;
	y = pt == NULL ? 0 : pt->y;
}

CD2DPointU::CD2DPointU(UINT32 uX, UINT32 uY)
{
	x = uX;
	y = uY;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DSizeF

CD2DSizeF::CD2DSizeF(const CSize& size)
{
	width = (FLOAT)size.cx;
	height = (FLOAT)size.cy;
}

CD2DSizeF::CD2DSizeF(const D2D1_SIZE_F& size)
{
	width = size.width;
	height = size.height;
}

CD2DSizeF::CD2DSizeF(const D2D1_SIZE_F* size)
{
	width = size == NULL ? 0 : size->width;
	height = size == NULL ? 0 : size->height;
}

CD2DSizeF::CD2DSizeF(FLOAT cx, FLOAT cy)
{
	width = cx;
	height = cy;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DSizeU

CD2DSizeU::CD2DSizeU(const CSize& size)
{
	width = (UINT32)size.cx;
	height = (UINT32)size.cy;
}

CD2DSizeU::CD2DSizeU(const D2D1_SIZE_U& size)
{
	width = size.width;
	height = size.height;
}

CD2DSizeU::CD2DSizeU(const D2D1_SIZE_U* size)
{
	width = size == NULL ? 0 : size->width;
	height = size == NULL ? 0 : size->height;
}

CD2DSizeU::CD2DSizeU(UINT32 cx, UINT32 cy)
{
	width = cx;
	height = cy;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DRectF

CD2DRectF::CD2DRectF(const CRect& rect)
{
	left = (FLOAT)rect.left;
	right = (FLOAT)rect.right;
	top = (FLOAT)rect.top;
	bottom = (FLOAT)rect.bottom;
}

CD2DRectF::CD2DRectF(const D2D1_RECT_F& rect)
{
	left = rect.left;
	right = rect.right;
	top = rect.top;
	bottom = rect.bottom;
}

CD2DRectF::CD2DRectF(const D2D1_RECT_F* rect)
{
	left = rect == NULL ? 0 : rect->left;
	right = rect == NULL ? 0 : rect->right;
	top = rect == NULL ? 0 : rect->top;
	bottom = rect == NULL ? 0 : rect->bottom;
}

CD2DRectF::CD2DRectF(FLOAT fLeft, FLOAT fTop, FLOAT fRight, FLOAT fBottom)
{
	left = fLeft;
	right = fRight;
	top = fTop;
	bottom = fBottom;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DRectU

CD2DRectU::CD2DRectU(const CRect& rect)
{
	left = (UINT32)rect.left;
	right = (UINT32)rect.right;
	top = (UINT32)rect.top;
	bottom = (UINT32)rect.bottom;
}

CD2DRectU::CD2DRectU(const D2D1_RECT_U& rect)
{
	left = rect.left;
	right = rect.right;
	top = rect.top;
	bottom = rect.bottom;
}

CD2DRectU::CD2DRectU(const D2D1_RECT_U* rect)
{
	left = rect == NULL ? 0 : rect->left;
	right = rect == NULL ? 0 : rect->right;
	top = rect == NULL ? 0 : rect->top;
	bottom = rect == NULL ? 0 : rect->bottom;
}

CD2DRectU::CD2DRectU(UINT32 uLeft, UINT32 uTop, UINT32 uRight, UINT32 uBottom)
{
	left = uLeft;
	right = uRight;
	top = uTop;
	bottom = uBottom;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DRoundedRect

CD2DRoundedRect::CD2DRoundedRect(const CD2DRectF& rectIn, const CD2DSizeF& sizeRadius)
{
	rect = rectIn;
	radiusX = sizeRadius.width;
	radiusY = sizeRadius.height;
}

CD2DRoundedRect::CD2DRoundedRect(const D2D1_ROUNDED_RECT& rectIn)
{
	rect = rectIn.rect;
	radiusX = rectIn.radiusX;
	radiusY = rectIn.radiusY;
}

CD2DRoundedRect::CD2DRoundedRect(const D2D1_ROUNDED_RECT* rectIn)
{
	if (rectIn != NULL)
	{
		rect = rectIn->rect;
		radiusX = rectIn->radiusX;
		radiusY = rectIn->radiusY;
	}
}

////////////////////////////////////////////////////////////////////////////////
// CD2DEllipse

CD2DEllipse::CD2DEllipse(const CD2DRectF& rect)
{
	radiusX = .5f * (rect.right - rect.left);
	radiusY = .5f * (rect.bottom - rect.top);
	point.x = rect.left + radiusX;
	point.y = rect.top + radiusY;
}

CD2DEllipse::CD2DEllipse(const D2D1_ELLIPSE& ellipse)
{
	point = ellipse.point;
	radiusX = ellipse.radiusX;
	radiusY = ellipse.radiusY;
}

CD2DEllipse::CD2DEllipse(const D2D1_ELLIPSE* ellipse)
{
	if (ellipse == NULL)
	{
		point.x = point.y = 0;
		radiusX = 0.0f;
		radiusY = 0.0f;
	}
	else
	{
		point = ellipse->point;
		radiusX = ellipse->radiusX;
		radiusY = ellipse->radiusY;
	}
}

CD2DEllipse::CD2DEllipse(const CD2DPointF& ptCenter, const CD2DSizeF& sizeRadius)
{
	point.x = ptCenter.x;
	point.y = ptCenter.y;
	radiusX = sizeRadius.width;
	radiusY = sizeRadius.height;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DResource

IMPLEMENT_DYNAMIC(CD2DResource, CObject)

CD2DResource::CD2DResource(CRenderTarget* pParentTarget, BOOL bAutoDestroy)
{
	m_pParentTarget = pParentTarget;
	m_bIsAutoDestroy = bAutoDestroy;

	if (m_pParentTarget != NULL && m_pParentTarget->m_lstResources.Find(this) == NULL)
	{
		m_pParentTarget->m_lstResources.AddTail(this);
	}
}

CD2DResource::~CD2DResource()
{
	if (m_pParentTarget != NULL)
	{
		ASSERT_VALID(m_pParentTarget);

		POSITION pos = m_pParentTarget->m_lstResources.Find(this);
		if (pos != NULL)
		{
			m_pParentTarget->m_lstResources.RemoveAt(pos);
		}
	}
}

HRESULT CD2DResource::ReCreate(CRenderTarget* pRenderTarget)
{
	Destroy();
	return Create(pRenderTarget);
}

////////////////////////////////////////////////////////////////////////////////
// CD2DLayer

IMPLEMENT_DYNAMIC(CD2DLayer, CD2DResource)

CD2DLayer::CD2DLayer(CRenderTarget*	pParentTarget, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	m_pLayer = NULL;
}

CD2DLayer::~CD2DLayer()
{
	Destroy();
}

HRESULT CD2DLayer::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pLayer != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	ID2D1Layer* pLayer = NULL;
	HRESULT hr = pRenderTarget->GetRenderTarget()->CreateLayer(&pLayer);

	if (SUCCEEDED(hr))
	{
		m_pLayer = pLayer;
	}

	return hr;
}

void CD2DLayer::Destroy()
{
	SafeRelease(&m_pLayer);
}

CD2DSizeF CD2DLayer::GetSize() const
{
	if (m_pLayer == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeF(0, 0);
	}

	return m_pLayer->GetSize();
}

void CD2DLayer::Attach(ID2D1Layer* pResource)
{
	ASSERT(m_pLayer == NULL);
	m_pLayer = pResource;
}

ID2D1Layer* CD2DLayer::Detach()
{
	ID2D1Layer* pResource = m_pLayer;
	m_pLayer = NULL;
	return pResource;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DBrushProperties

CD2DBrushProperties::CD2DBrushProperties()
{
	CommonInit();
}

CD2DBrushProperties::CD2DBrushProperties(FLOAT _opacity)
{
	CommonInit();
	opacity = _opacity;
}

CD2DBrushProperties::CD2DBrushProperties(D2D1_MATRIX_3X2_F _transform, FLOAT _opacity)
{
	CommonInit();

	opacity = _opacity;
	transform = _transform;
}

void CD2DBrushProperties::CommonInit()
{
	transform = D2D1::Matrix3x2F::Identity();
	opacity = 1.;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DBrush

IMPLEMENT_DYNAMIC(CD2DBrush, CD2DResource)

CD2DBrush::CD2DBrush(CRenderTarget*	pParentTarget, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	m_pBrush = NULL;

	if (pBrushProperties == NULL)
	{
		m_pBrushProperties = NULL;
	}
	else
	{
		m_pBrushProperties = new CD2DBrushProperties;
		*m_pBrushProperties = *pBrushProperties;
	}
}

CD2DBrush::~CD2DBrush()
{
	Destroy();
}

void CD2DBrush::Destroy()
{
	SafeRelease(&m_pBrush);

	if (m_pBrushProperties != NULL)
	{
		delete m_pBrushProperties;
		m_pBrushProperties =  NULL;
	}
}

void CD2DBrush::Attach(ID2D1Brush* pResource)
{
	ASSERT(m_pBrush == NULL);
	m_pBrush = pResource;
}

ID2D1Brush* CD2DBrush::Detach()
{
	ID2D1Brush* pResource = m_pBrush;
	m_pBrush = NULL;
	return pResource;
}

void CD2DBrush::SetOpacity(FLOAT opacity)
{
	if (m_pBrush == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pBrush->SetOpacity(opacity);
}

FLOAT CD2DBrush::GetOpacity() const
{
	if (m_pBrush == NULL)
	{
		ASSERT(FALSE);
		return 0.0f;
	}

	return m_pBrush->GetOpacity();
}

void CD2DBrush::SetTransform(const D2D1_MATRIX_3X2_F* transform)
{
	if (m_pBrush == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pBrush->SetTransform(transform);
}

void CD2DBrush::GetTransform(D2D1_MATRIX_3X2_F* transform) const
{
	if (m_pBrush == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pBrush->GetTransform(transform);
}

////////////////////////////////////////////////////////////////////////////////
// CD2DSolidColorBrush

IMPLEMENT_DYNAMIC(CD2DSolidColorBrush, CD2DBrush)

CD2DSolidColorBrush::CD2DSolidColorBrush(CRenderTarget* pParentTarget, D2D1_COLOR_F color, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	m_pSolidColorBrush = NULL;
	m_colorSolid = color;
}

CD2DSolidColorBrush::CD2DSolidColorBrush(CRenderTarget* pParentTarget, COLORREF color, int nAlpha, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	m_pSolidColorBrush = NULL;
	m_colorSolid = CRenderTarget::COLORREF_TO_D2DCOLOR(color, nAlpha);
}

CD2DSolidColorBrush::~CD2DSolidColorBrush()
{
	Destroy();
}

HRESULT CD2DSolidColorBrush::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pBrush != NULL || m_pSolidColorBrush != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	ID2D1SolidColorBrush* pSolidColorBrush = NULL;
	HRESULT hr = pRenderTarget->GetRenderTarget()->CreateSolidColorBrush(&m_colorSolid, m_pBrushProperties, &pSolidColorBrush);

	if (SUCCEEDED(hr))
	{
		m_pBrush = m_pSolidColorBrush = pSolidColorBrush;
	}

	return hr;
}

void CD2DSolidColorBrush::Destroy()
{
	CD2DBrush::Destroy();
	m_pSolidColorBrush = NULL;
}

void CD2DSolidColorBrush::Attach(ID2D1SolidColorBrush* pResource)
{
	ASSERT(m_pBrush == NULL);
	m_pBrush = m_pSolidColorBrush = pResource;
}

ID2D1SolidColorBrush* CD2DSolidColorBrush::Detach()
{
	ID2D1SolidColorBrush* pResource = m_pSolidColorBrush;
	m_pBrush = m_pSolidColorBrush = NULL;
	return pResource;
}

void CD2DSolidColorBrush::SetColor(D2D1_COLOR_F color)
{
	m_colorSolid = color;

	if (m_pSolidColorBrush != NULL)
	{
		m_pSolidColorBrush->SetColor(color);
	}
}

D2D1_COLOR_F CD2DSolidColorBrush::GetColor() const
{
	return (m_pSolidColorBrush != NULL) ?  m_pSolidColorBrush->GetColor() : m_colorSolid;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DBitmapBrush

IMPLEMENT_DYNAMIC(CD2DBitmapBrush, CD2DBrush)

CD2DBitmapBrush::CD2DBitmapBrush(CRenderTarget* pParentTarget, D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	CommonInit(pBitmapBrushProperties);
	m_pBitmap = new CD2DBitmap(pParentTarget);
}

CD2DBitmapBrush::CD2DBitmapBrush(CRenderTarget* pParentTarget, UINT uiResID, LPCTSTR lpszType, CD2DSizeU sizeDest, D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	CommonInit(pBitmapBrushProperties);
	m_pBitmap = new CD2DBitmap(pParentTarget, uiResID, lpszType, sizeDest);
}

CD2DBitmapBrush::CD2DBitmapBrush(CRenderTarget* pParentTarget, LPCTSTR lpszImagePath, CD2DSizeU sizeDest, D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	CommonInit(pBitmapBrushProperties);
	m_pBitmap = new CD2DBitmap(pParentTarget, lpszImagePath, sizeDest);
}

void CD2DBitmapBrush::CommonInit(D2D1_BITMAP_BRUSH_PROPERTIES* pBitmapBrushProperties)
{
	m_pBitmapBrush = NULL;

	if (pBitmapBrushProperties != NULL)
	{
		m_pBitmapBrushProperties = new D2D1_BITMAP_BRUSH_PROPERTIES;
		*m_pBitmapBrushProperties = *pBitmapBrushProperties;
	}
	else
	{
		m_pBitmapBrushProperties = NULL;
	}
}

CD2DBitmapBrush::~CD2DBitmapBrush()
{
	Destroy();
}

HRESULT CD2DBitmapBrush::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pBrush != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (!pRenderTarget->VerifyResource(m_pBitmap))
	{
		return E_FAIL;
	}

	ID2D1BitmapBrush* pBitmapBrush = NULL;
	HRESULT hr = pRenderTarget->GetRenderTarget()->CreateBitmapBrush(m_pBitmap->m_pBitmap, m_pBitmapBrushProperties, m_pBrushProperties, &pBitmapBrush);

	if (SUCCEEDED(hr))
	{
		m_pBrush = m_pBitmapBrush = pBitmapBrush;
	}

	return hr;
}

void CD2DBitmapBrush::Destroy()
{
	CD2DBrush::Destroy();

	if (m_pBitmapBrushProperties != NULL)
	{
		delete m_pBitmapBrushProperties;
		m_pBitmapBrushProperties = NULL;
	}
}

void CD2DBitmapBrush::Attach(ID2D1BitmapBrush* pResource)
{
	ASSERT(m_pBrush == NULL);
	m_pBrush = m_pBitmapBrush = pResource;
}

ID2D1BitmapBrush* CD2DBitmapBrush::Detach()
{
	ID2D1BitmapBrush* pResource = m_pBitmapBrush;
	m_pBrush = m_pBitmapBrush = NULL;
	return pResource;
}

void CD2DBitmapBrush::SetExtendModeX(D2D1_EXTEND_MODE extendModeX)
{
	if (m_pBitmapBrushProperties != NULL)
	{
		m_pBitmapBrushProperties->extendModeX = extendModeX;
	}

	if (m_pBitmapBrush != NULL)
	{
		m_pBitmapBrush->SetExtendModeX(extendModeX);
	}
}

void CD2DBitmapBrush::SetExtendModeY(D2D1_EXTEND_MODE extendModeY)
{
	if (m_pBitmapBrushProperties != NULL)
	{
		m_pBitmapBrushProperties->extendModeY = extendModeY;
	}

	if (m_pBitmapBrush != NULL)
	{
		m_pBitmapBrush->SetExtendModeY(extendModeY);
	}
}

void CD2DBitmapBrush::SetInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE interpolationMode)
{
	if (m_pBitmapBrushProperties != NULL)
	{
		m_pBitmapBrushProperties->interpolationMode = interpolationMode;
	}

	if (m_pBitmapBrush != NULL)
	{
		m_pBitmapBrush->SetInterpolationMode(interpolationMode);
	}
}

void CD2DBitmapBrush::SetBitmap(CD2DBitmap* pBitmap)
{
	if (pBitmap == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pBitmap = pBitmap;

	if (m_pBitmapBrush != NULL)
	{
		return m_pBitmapBrush->SetBitmap(m_pBitmap->Get());
	}
}

D2D1_EXTEND_MODE CD2DBitmapBrush::GetExtendModeX() const
{
	if (m_pBitmapBrush != NULL)
	{
		return m_pBitmapBrush->GetExtendModeX();
	}

	if (m_pBitmapBrushProperties != NULL)
	{
		return m_pBitmapBrushProperties->extendModeX;
	}

	ASSERT(FALSE);
	return (D2D1_EXTEND_MODE)-1;
}

D2D1_EXTEND_MODE CD2DBitmapBrush::GetExtendModeY() const
{
	if (m_pBitmapBrush != NULL)
	{
		return m_pBitmapBrush->GetExtendModeY();
	}

	if (m_pBitmapBrushProperties != NULL)
	{
		return m_pBitmapBrushProperties->extendModeY;
	}

	ASSERT(FALSE);
	return (D2D1_EXTEND_MODE)-1;
}

D2D1_BITMAP_INTERPOLATION_MODE CD2DBitmapBrush::GetInterpolationMode() const
{
	if (m_pBitmapBrush != NULL)
	{
		return m_pBitmapBrush->GetInterpolationMode();
	}

	if (m_pBitmapBrushProperties != NULL)
	{
		return m_pBitmapBrushProperties->interpolationMode;
	}

	ASSERT(FALSE);
	return (D2D1_BITMAP_INTERPOLATION_MODE)-1;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DGradientBrush

IMPLEMENT_DYNAMIC(CD2DGradientBrush, CD2DBrush)

CD2DGradientBrush::CD2DGradientBrush(CRenderTarget* pParentTarget, const D2D1_GRADIENT_STOP* gradientStops, UINT gradientStopsCount, D2D1_GAMMA colorInterpolationGamma, D2D1_EXTEND_MODE extendMode, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DBrush(pParentTarget, pBrushProperties, bAutoDestroy)
{
	ASSERT(gradientStops != NULL);
	ASSERT(gradientStopsCount > 0);

	for (UINT i = 0; i < gradientStopsCount; i++)
	{
		m_arGradientStops.Add(gradientStops[i]);
	}

	m_colorInterpolationGamma = colorInterpolationGamma;
	m_extendMode = extendMode;

	m_pGradientStops = NULL;
}

CD2DGradientBrush::~CD2DGradientBrush()
{
	Destroy();
}

void CD2DGradientBrush::Destroy()
{
	CD2DBrush::Destroy();

	SafeRelease(&m_pGradientStops);
}

////////////////////////////////////////////////////////////////////////////////
// CD2DLinearGradientBrush

IMPLEMENT_DYNAMIC(CD2DLinearGradientBrush, CD2DGradientBrush)

CD2DLinearGradientBrush::CD2DLinearGradientBrush(CRenderTarget* pParentTarget, const D2D1_GRADIENT_STOP* gradientStops, UINT gradientStopsCount, D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES LinearGradientBrushProperties, D2D1_GAMMA colorInterpolationGamma, D2D1_EXTEND_MODE extendMode, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DGradientBrush(pParentTarget, gradientStops, gradientStopsCount, colorInterpolationGamma, extendMode, pBrushProperties, bAutoDestroy)
{
	m_LinearGradientBrushProperties = LinearGradientBrushProperties;
	m_pLinearGradientBrush = NULL;
}

HRESULT CD2DLinearGradientBrush::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pBrush != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_arGradientStops.GetSize() == 0)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	HRESULT hr = pRenderTarget->GetRenderTarget()->CreateGradientStopCollection(
    	m_arGradientStops.GetData(), (UINT)m_arGradientStops.GetSize(), m_colorInterpolationGamma, m_extendMode, &m_pGradientStops);
	if (FAILED(hr))
	{
		return hr;
	}

	ID2D1LinearGradientBrush* pBrush = NULL;
	hr = pRenderTarget->GetRenderTarget()->CreateLinearGradientBrush(&m_LinearGradientBrushProperties, m_pBrushProperties, m_pGradientStops, &pBrush);

	if (SUCCEEDED(hr))
	{
		m_pBrush = m_pLinearGradientBrush = pBrush;
	}

	return hr;
}

CD2DLinearGradientBrush::~CD2DLinearGradientBrush()
{
	Destroy();
}

void CD2DLinearGradientBrush::Destroy()
{
	CD2DGradientBrush::Destroy();
	m_pLinearGradientBrush = NULL;
}

void CD2DLinearGradientBrush::Attach(ID2D1LinearGradientBrush* pResource)
{
	ASSERT(m_pBrush == NULL);
	m_pBrush = m_pLinearGradientBrush = pResource;
}

ID2D1LinearGradientBrush* CD2DLinearGradientBrush::Detach()
{
	ID2D1LinearGradientBrush* pResource = m_pLinearGradientBrush;
	m_pBrush = m_pLinearGradientBrush = NULL;
	return pResource;
}

void CD2DLinearGradientBrush::SetStartPoint(CD2DPointF point)
{
	m_LinearGradientBrushProperties.startPoint = point;

	if (m_pLinearGradientBrush != NULL)
	{
		m_pLinearGradientBrush->SetStartPoint(point);
	}
}

void CD2DLinearGradientBrush::SetEndPoint(CD2DPointF point)
{
	m_LinearGradientBrushProperties.endPoint = point;

	if (m_pLinearGradientBrush != NULL)
	{
		m_pLinearGradientBrush->SetEndPoint(point);
	}
}

CD2DPointF CD2DLinearGradientBrush::GetStartPoint() const
{
	return (m_pLinearGradientBrush != NULL) ? m_pLinearGradientBrush->GetStartPoint() : m_LinearGradientBrushProperties.startPoint;
}

CD2DPointF CD2DLinearGradientBrush::GetEndPoint() const
{
	return (m_pLinearGradientBrush != NULL) ? m_pLinearGradientBrush->GetEndPoint() : m_LinearGradientBrushProperties.endPoint;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DRadialGradientBrush

IMPLEMENT_DYNAMIC(CD2DRadialGradientBrush, CD2DBrush)

CD2DRadialGradientBrush::CD2DRadialGradientBrush(CRenderTarget* pParentTarget, const D2D1_GRADIENT_STOP* gradientStops, UINT gradientStopsCount, D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES RadialGradientBrushProperties, D2D1_GAMMA colorInterpolationGamma, D2D1_EXTEND_MODE extendMode, CD2DBrushProperties* pBrushProperties, BOOL bAutoDestroy) :
	CD2DGradientBrush(pParentTarget, gradientStops, gradientStopsCount, colorInterpolationGamma, extendMode, pBrushProperties, bAutoDestroy)
{
	m_RadialGradientBrushProperties = RadialGradientBrushProperties;
	m_pRadialGradientBrush = NULL;
}

CD2DRadialGradientBrush::~CD2DRadialGradientBrush()
{
	Destroy();
}

HRESULT CD2DRadialGradientBrush::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pBrush != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_arGradientStops.GetSize() == 0)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	HRESULT hr = pRenderTarget->GetRenderTarget()->CreateGradientStopCollection(
		m_arGradientStops.GetData(), (UINT)m_arGradientStops.GetSize(), m_colorInterpolationGamma, m_extendMode, &m_pGradientStops);
	if (FAILED(hr))
	{
		return hr;
	}

	ID2D1RadialGradientBrush* pBrush = NULL;
	hr = pRenderTarget->GetRenderTarget()->CreateRadialGradientBrush(&m_RadialGradientBrushProperties, m_pBrushProperties, m_pGradientStops, &pBrush);

	if (SUCCEEDED(hr))
	{
		m_pBrush = m_pRadialGradientBrush = pBrush;
	}

	return hr;
}

void CD2DRadialGradientBrush::Destroy()
{
	CD2DGradientBrush::Destroy();
	m_pRadialGradientBrush = NULL;
}

void CD2DRadialGradientBrush::Attach(ID2D1RadialGradientBrush* pResource)
{
	ASSERT(m_pBrush == NULL);
	m_pBrush = m_pRadialGradientBrush = pResource;
}

ID2D1RadialGradientBrush* CD2DRadialGradientBrush::Detach()
{
	ID2D1RadialGradientBrush* pResource = m_pRadialGradientBrush;
	m_pBrush = m_pRadialGradientBrush = NULL;
	return pResource;
}

void CD2DRadialGradientBrush::SetCenter(CD2DPointF point)
{
	m_RadialGradientBrushProperties.center = point;

	if (m_pRadialGradientBrush != NULL)
	{
		m_pRadialGradientBrush->SetCenter(point);
	}
}

void CD2DRadialGradientBrush::SetGradientOriginOffset(CD2DPointF gradientOriginOffset)
{
	m_RadialGradientBrushProperties.gradientOriginOffset = gradientOriginOffset;

	if (m_pRadialGradientBrush != NULL)
	{
		m_pRadialGradientBrush->SetGradientOriginOffset(gradientOriginOffset);
	}
}

void CD2DRadialGradientBrush::SetRadiusX(FLOAT radiusX)
{
	m_RadialGradientBrushProperties.radiusX = radiusX;

	if (m_pRadialGradientBrush != NULL)
	{
		m_pRadialGradientBrush->SetRadiusX(radiusX);
	}
}

void CD2DRadialGradientBrush::SetRadiusY(FLOAT radiusY)
{
	m_RadialGradientBrushProperties.radiusY = radiusY;

	if (m_pRadialGradientBrush != NULL)
	{
		m_pRadialGradientBrush->SetRadiusY(radiusY);
	}
}

CD2DPointF CD2DRadialGradientBrush::GetCenter() const
{
	return (m_pRadialGradientBrush != NULL) ? m_pRadialGradientBrush->GetCenter() : m_RadialGradientBrushProperties.center;
}

CD2DPointF CD2DRadialGradientBrush::GetGradientOriginOffset() const
{
	return (m_pRadialGradientBrush != NULL) ? m_pRadialGradientBrush->GetGradientOriginOffset() : m_RadialGradientBrushProperties.gradientOriginOffset;
}

FLOAT CD2DRadialGradientBrush::GetRadiusX() const
{
	return (m_pRadialGradientBrush != NULL) ? m_pRadialGradientBrush->GetRadiusX() : m_RadialGradientBrushProperties.radiusX;
}

FLOAT CD2DRadialGradientBrush::GetRadiusY() const
{
	return (m_pRadialGradientBrush != NULL) ? m_pRadialGradientBrush->GetRadiusY() : m_RadialGradientBrushProperties.radiusY;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DBitmap

IMPLEMENT_DYNAMIC(CD2DBitmap, CD2DResource)

CD2DBitmap::CD2DBitmap(CRenderTarget* pParentTarget, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	CommonInit();
}

CD2DBitmap::CD2DBitmap(CRenderTarget* pParentTarget, UINT uiResID, LPCTSTR lpszType, CD2DSizeU sizeDest, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	CommonInit();
	m_uiResID = uiResID;
	m_lpszType = lpszType;
	m_sizeDest = sizeDest;
}

CD2DBitmap::CD2DBitmap(CRenderTarget* pParentTarget, HBITMAP hbmpSrc, CD2DSizeU sizeDest, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	CommonInit();

	if (pParentTarget->IsValid())
	{
		m_hBmpSrc = hbmpSrc;
		Create(pParentTarget);
	}
	else
	{
		m_hBmpSrc = (HBITMAP)::CopyImage(hbmpSrc, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		m_bAutoDestroyHBMP = TRUE;
	}

	m_sizeDest = sizeDest;
}

CD2DBitmap::CD2DBitmap(CRenderTarget* pParentTarget, LPCTSTR lpszPath, CD2DSizeU sizeDest, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	ASSERT(lpszPath != NULL);

	CommonInit();
	m_strPath = lpszPath;
	m_sizeDest = sizeDest;
}

CD2DBitmap::~CD2DBitmap()
{
	Destroy();
}

void CD2DBitmap::CommonInit()
{
	m_pBitmap = NULL;
	m_uiResID = 0;
	m_bAutoDestroyHBMP = FALSE;
}

CD2DSizeF CD2DBitmap::GetSize() const
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeF(0, 0);
	}

	return m_pBitmap->GetSize();
}

CD2DSizeU CD2DBitmap::GetPixelSize() const
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeU(0, 0);
	}

	return m_pBitmap->GetPixelSize();
}

D2D1_PIXEL_FORMAT CD2DBitmap::GetPixelFormat() const
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);

		D2D1_PIXEL_FORMAT format;
		format.alphaMode = D2D1_ALPHA_MODE_UNKNOWN;
		format.format = DXGI_FORMAT_UNKNOWN;
		return format;
	}

	return m_pBitmap->GetPixelFormat();
}

CD2DSizeF CD2DBitmap::GetDPI() const
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeF(0.0f, 0.0f);
	}

	FLOAT dipX = 0;
	FLOAT dipY = 0;

	m_pBitmap->GetDpi(&dipX, &dipY);

	return CD2DSizeF(dipX, dipY);
}

HRESULT CD2DBitmap::CopyFromBitmap(const CD2DBitmap* pBitmap, const CD2DPointU* destPoint, const CD2DRectU* srcRect)
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	return m_pBitmap->CopyFromBitmap(destPoint, pBitmap->m_pBitmap, srcRect);
}

HRESULT CD2DBitmap::CopyFromRenderTarget(const CRenderTarget* pRenderTarget, const CD2DPointU* destPoint, const CD2DRectU* srcRect)
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	return m_pBitmap->CopyFromRenderTarget(destPoint, pRenderTarget->m_pRenderTarget, srcRect);
}

HRESULT CD2DBitmap::CopyFromMemory(const void *srcData, UINT32 pitch, const CD2DRectU* destRect)
{
	if (m_pBitmap == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	return m_pBitmap->CopyFromMemory(destRect, srcData, pitch);
}

void CD2DBitmap::Attach(ID2D1Bitmap* pResource)
{
	ASSERT(m_pBitmap == NULL);
	m_pBitmap = pResource;
}

ID2D1Bitmap* CD2DBitmap::Detach()
{
	ID2D1Bitmap* pResource = m_pBitmap;
	m_pBitmap = NULL;
	return pResource;
}

HRESULT CD2DBitmap::Create(CRenderTarget* pRenderTarget)
{
	USES_CONVERSION;

	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pBitmap != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	HRESULT hr = S_OK;

	IWICBitmapDecoder* pDecoder = NULL;
	IWICBitmapFrameDecode* pSource = NULL;
	IWICFormatConverter* pConverter = NULL;
	IWICStream* pStream = NULL;
	IWICBitmapScaler* pScaler = NULL;
	IWICBitmap* pWICBitmap = NULL;

	if (!m_strPath.IsEmpty())
	{
		hr = _afxD2DState->GetWICFactory()->CreateDecoderFromFilename(
			T2CW(m_strPath),
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnLoad,
			&pDecoder
			);

		if (FAILED(hr))
		{
			return hr;
		}
	}
	else if (m_uiResID != 0)
	{
		HRSRC imageResHandle = NULL;
		HGLOBAL imageResDataHandle = NULL;
		void *pImageFile = NULL;
		DWORD imageFileSize = 0;

		LPCTSTR lpszResourceName = MAKEINTRESOURCE(m_uiResID);
		ASSERT(lpszResourceName != NULL);

		// Locate the resource.
		HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName, m_lpszType == NULL ? _T("image") : m_lpszType);
		imageResHandle = FindResource(hInst, lpszResourceName, m_lpszType == NULL ? _T("image") : m_lpszType);
		hr = imageResHandle ? S_OK : E_FAIL;

		if (SUCCEEDED(hr))
		{
			// Load the resource.
			imageResDataHandle = LoadResource(hInst, imageResHandle);

			hr = imageResDataHandle ? S_OK : E_FAIL;
		}

		if (SUCCEEDED(hr))
		{
			// Lock it to get a system memory pointer.
			pImageFile = LockResource(imageResDataHandle);

			hr = pImageFile ? S_OK : E_FAIL;
		}
		if (SUCCEEDED(hr))
		{
			// Calculate the size.
			imageFileSize = SizeofResource(hInst, imageResHandle);

			hr = imageFileSize ? S_OK : E_FAIL;

		}
		if (SUCCEEDED(hr))
		{
			// Create a WIC stream to map onto the memory.
			hr = _afxD2DState->GetWICFactory()->CreateStream(&pStream);
		}
		if (SUCCEEDED(hr))
		{
			// Initialize the stream with the memory pointer and size.
			hr = pStream->InitializeFromMemory(
				reinterpret_cast<BYTE*>(pImageFile),
				imageFileSize
				);
		}
		if (SUCCEEDED(hr))
		{
			// Create a decoder for the stream.
			hr = _afxD2DState->GetWICFactory()->CreateDecoderFromStream(
				pStream,
				NULL,
				WICDecodeMetadataCacheOnLoad,
				&pDecoder
				);
		}
	}
	else if (m_hBmpSrc != NULL)
	{
		hr = _afxD2DState->GetWICFactory()->CreateBitmapFromHBITMAP(m_hBmpSrc, NULL, WICBitmapUseAlpha, &pWICBitmap);

		if (SUCCEEDED(hr))
		{
			pRenderTarget->GetRenderTarget()->CreateBitmapFromWicBitmap (pWICBitmap, 0, &m_pBitmap);
		}
	}

	if (m_pBitmap == NULL)
	{
		if (SUCCEEDED(hr) && pDecoder != NULL)
		{
			// Create the initial frame.
			hr = pDecoder->GetFrame(0, &pSource);
			pWICBitmap = (IWICBitmap*)pSource;
		}

		if (SUCCEEDED(hr))
		{
			// Convert the image format to 32bppPBGRA
			// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
			hr = _afxD2DState->GetWICFactory()->CreateFormatConverter(&pConverter);
		}

		// If a new width or height was specified, create an
		// IWICBitmapScaler and use it to resize the image.
		UINT32 destinationWidth = m_sizeDest.width;
		UINT32 destinationHeight = m_sizeDest.height;

		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;

			hr = pWICBitmap->GetSize(&originalWidth, &originalHeight);

			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
					destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
				}
				else if (destinationHeight == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
					destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
				}

				hr = _afxD2DState->GetWICFactory()->CreateBitmapScaler(&pScaler);
				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(
						pWICBitmap,
						destinationWidth,
						destinationHeight,
						WICBitmapInterpolationModeCubic
						);
					if (SUCCEEDED(hr))
					{
						hr = pConverter->Initialize(
							pScaler,
							GUID_WICPixelFormat32bppPBGRA,
							WICBitmapDitherTypeNone,
							NULL,
							0.f,
							WICBitmapPaletteTypeMedianCut
							);
					}
				}
			}
		}
		else
		{
			if (SUCCEEDED(hr))
			{
				hr = pConverter->Initialize(pWICBitmap, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
					NULL, 0.f, WICBitmapPaletteTypeMedianCut);
			}
		}

		if (SUCCEEDED(hr))
		{
			// Create a Direct2D bitmap from the WIC bitmap.
			hr = pRenderTarget->GetRenderTarget()->CreateBitmapFromWicBitmap(pConverter, NULL, &m_pBitmap);
		}
	}

	if (pWICBitmap == (IWICBitmap*)pSource)
	{
		pWICBitmap = NULL;
	}

	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);
	SafeRelease(&pWICBitmap);

	if (m_bAutoDestroyHBMP && m_hBmpSrc != NULL)
	{
		::DeleteObject(m_hBmpSrc);
		m_hBmpSrc = NULL;
	}

	return hr;
}

void CD2DBitmap::Destroy()
{
	SafeRelease(&m_pBitmap);
}

////////////////////////////////////////////////////////////////////////////////
// CD2DTextFormat

IMPLEMENT_DYNAMIC(CD2DTextFormat, CD2DResource)

CD2DTextFormat::CD2DTextFormat(CRenderTarget* pParentTarget, const CString& strFontFamilyName, FLOAT fontSize,DWRITE_FONT_WEIGHT fontWeight,
	DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, const CString& strFontLocale, IDWriteFontCollection* pFontCollection, BOOL bAutoDestroy) :
CD2DResource(pParentTarget, bAutoDestroy)
{
	USES_CONVERSION;

	m_pTextFormat = NULL;

	if (_afxD2DState->GetWriteFactory() != NULL)
	{
		_afxD2DState->GetWriteFactory()->CreateTextFormat(T2CW(strFontFamilyName), pFontCollection, fontWeight, fontStyle,
			fontStretch, fontSize, T2CW(strFontLocale), &m_pTextFormat);
	}
}

CD2DTextFormat::~CD2DTextFormat()
{
	SafeRelease(&m_pTextFormat);
}

CString CD2DTextFormat::GetFontFamilyName() const
{
	if (m_pTextFormat == NULL)
	{
		ASSERT(FALSE);
		return _T("");
	}

	CStringW strFontFamilyNameW;

	UINT32 uSize = m_pTextFormat->GetFontFamilyNameLength();
	if (uSize > 0)
	{
		m_pTextFormat->GetFontFamilyName(strFontFamilyNameW.GetBuffer(uSize + 1), uSize + 1);
		strFontFamilyNameW.ReleaseBuffer();
	}

#ifdef _UNICODE
	return strFontFamilyNameW;
#else
	CString strFontFamilyName;
	_wcstombsz(strFontFamilyName.GetBuffer(uSize + 1), strFontFamilyNameW, uSize + 1);
	strFontFamilyName.ReleaseBuffer();
	return strFontFamilyName;
#endif
}

CString CD2DTextFormat::GetLocaleName() const
{
	if (m_pTextFormat == NULL)
	{
		ASSERT(FALSE);
		return _T("");
	}

	CStringW strLocaleNameW;

	UINT32 uSize = m_pTextFormat->GetLocaleNameLength();
	if (uSize > 0)
	{
		m_pTextFormat->GetLocaleName(strLocaleNameW.GetBuffer(uSize + 1), uSize + 1);
		strLocaleNameW.ReleaseBuffer();
	}

#ifdef _UNICODE
	return strLocaleNameW;
#else
	CString strLocaleName;
	_wcstombsz(strLocaleName.GetBuffer(uSize + 1), strLocaleNameW, uSize + 1);
	strLocaleName.ReleaseBuffer();
	return strLocaleName;
#endif
}

////////////////////////////////////////////////////////////////////////////////
// CD2DTextLayout

IMPLEMENT_DYNAMIC(CD2DTextLayout, CD2DResource)

CD2DTextLayout::CD2DTextLayout(	CRenderTarget* pParentTarget, const CString& strText, CD2DTextFormat& textFormat, const CD2DSizeF& sizeMax, BOOL bAutoDestroy) :
CD2DResource(pParentTarget, bAutoDestroy)
{
	USES_CONVERSION;

	m_pTextLayout = NULL;

	if (_afxD2DState->GetWriteFactory() != NULL)
	{
		_afxD2DState->GetWriteFactory()->CreateTextLayout(T2CW(strText), strText.GetLength(), textFormat,
			sizeMax.width, sizeMax.height, &m_pTextLayout);
	}
}

CD2DTextLayout::~CD2DTextLayout()
{
	SafeRelease(&m_pTextLayout);
}

BOOL CD2DTextLayout::SetFontFamilyName(LPCWSTR pwzFontFamilyName, DWRITE_TEXT_RANGE textRange)
{
	if (m_pTextLayout == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	USES_CONVERSION;
	return SUCCEEDED(m_pTextLayout->SetFontFamilyName(pwzFontFamilyName, textRange));
}

BOOL CD2DTextLayout::SetLocaleName(LPCWSTR pwzLocaleName, DWRITE_TEXT_RANGE textRange)
{
	if (m_pTextLayout == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	USES_CONVERSION;
	return SUCCEEDED(m_pTextLayout->SetLocaleName(pwzLocaleName, textRange));
}

CString CD2DTextLayout::GetFontFamilyName(UINT32 currentPosition, DWRITE_TEXT_RANGE* textRange) const
{
	if (m_pTextLayout == NULL)
	{
		ASSERT(FALSE);
		return _T("");
	}

	CStringW strFontFamilyNameW;

	UINT32 uSize = 0;
	m_pTextLayout->GetFontFamilyNameLength(currentPosition, &uSize, textRange);

	if (uSize > 0)
	{
		m_pTextLayout->GetFontFamilyName(currentPosition, strFontFamilyNameW.GetBuffer(uSize + 1), uSize + 1, textRange);
		strFontFamilyNameW.ReleaseBuffer();
	}

#ifdef _UNICODE
	return strFontFamilyNameW;
#else
	CString strFontFamilyName;
	_wcstombsz(strFontFamilyName.GetBuffer(uSize + 1), strFontFamilyNameW, uSize + 1);
	strFontFamilyName.ReleaseBuffer();
	return strFontFamilyName;
#endif
}

CString CD2DTextLayout::GetLocaleName(UINT32 currentPosition, DWRITE_TEXT_RANGE* textRange) const
{
	if (m_pTextLayout == NULL)
	{
		ASSERT(FALSE);
		return _T("");
	}

	CStringW strLocaleNameW;

	UINT32 uSize = 0;

	m_pTextLayout->GetLocaleNameLength(currentPosition, &uSize, textRange);
	if (uSize > 0)
	{
		m_pTextLayout->GetLocaleName(currentPosition, strLocaleNameW.GetBuffer(uSize + 1), uSize + 1, textRange);
		strLocaleNameW.ReleaseBuffer();
	}

#ifdef _UNICODE
	return strLocaleNameW;
#else
	CString strLocaleName;
	_wcstombsz(strLocaleName.GetBuffer(uSize + 1), strLocaleNameW, uSize + 1);
	strLocaleName.ReleaseBuffer();
	return strLocaleName;
#endif
}

////////////////////////////////////////////////////////////////////////////////
// CRenderTarget

IMPLEMENT_DYNAMIC(CRenderTarget, CObject)

CRenderTarget::CRenderTarget()
{
	m_pRenderTarget = NULL;
	m_pTextFormatDefault = NULL;
}

CRenderTarget::~CRenderTarget()
{
	Destroy();
}

BOOL CRenderTarget::Destroy(BOOL bDeleteResources)
{
	if (bDeleteResources)
	{
		while (!m_lstResources.IsEmpty())
		{
			CD2DResource* pRes = DYNAMIC_DOWNCAST(CD2DResource, m_lstResources.RemoveHead());
			if (pRes != NULL && pRes->IsAutoDestroy())
			{
				pRes->m_pParentTarget = NULL;
				delete pRes;
			}
		}
	}

	if (m_pRenderTarget != NULL)
	{
		SafeRelease(&m_pRenderTarget);
		return TRUE;
	}

	return FALSE;
}

CD2DSizeF CRenderTarget::GetSize() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeF(0, 0);
	}

	return m_pRenderTarget->GetSize();
}

void CRenderTarget::SetDpi(const CD2DSizeF& sizeDPI)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetDpi(sizeDPI.width, sizeDPI.height);
}

CD2DSizeF CRenderTarget::GetDpi() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeF(0, 0);
	}

	FLOAT xDPI = 0.;
	FLOAT yDPI = 0.;

	m_pRenderTarget->GetDpi(&xDPI, &yDPI);
	return CD2DSizeF(xDPI, yDPI);
}

D2D1_PIXEL_FORMAT CRenderTarget::GetPixelFormat() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);

		D2D1_PIXEL_FORMAT format;
		format.alphaMode = D2D1_ALPHA_MODE_UNKNOWN;
		format.format = DXGI_FORMAT_UNKNOWN;
		return format;
	}

	return m_pRenderTarget->GetPixelFormat();
}

CD2DSizeU CRenderTarget::GetPixelSize() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return CD2DSizeU(0, 0);
	}

	return m_pRenderTarget->GetPixelSize();
}

void CRenderTarget::GetTags(D2D1_TAG *tag1, D2D1_TAG *tag2) const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->GetTags(tag1, tag2);
}

void CRenderTarget::SetTags(D2D1_TAG tag1, D2D1_TAG tag2)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetTags(tag1, tag2);
}

BOOL CRenderTarget::IsSupported(const D2D1_RENDER_TARGET_PROPERTIES& renderTargetProperties) const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return m_pRenderTarget->IsSupported(&renderTargetProperties);
}

UINT32 CRenderTarget::GetMaximumBitmapSize() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return 0;
	}

	return m_pRenderTarget->GetMaximumBitmapSize();
}

void CRenderTarget::Attach(ID2D1RenderTarget* pRenderTarget)
{
	if (m_pRenderTarget != NULL)
	{
		ASSERT(FALSE);
		return;
	}

	ASSERT(pRenderTarget != NULL);
	m_pRenderTarget = pRenderTarget;
}

ID2D1RenderTarget* CRenderTarget::Detach ()
{
	ASSERT(m_pRenderTarget != NULL);

	ID2D1RenderTarget* pRenderTarget = m_pRenderTarget;
	m_pRenderTarget = NULL;

	return pRenderTarget;
}

void CRenderTarget::BeginDraw()
{
	if (m_pRenderTarget != NULL)
	{
		m_pRenderTarget->BeginDraw();

		for (POSITION pos = m_lstResources.GetHeadPosition(); pos != NULL;)
		{
			VerifyResource(DYNAMIC_DOWNCAST(CD2DResource, m_lstResources.GetNext(pos)));
		}
	}
}

HRESULT CRenderTarget::EndDraw()
{
	if (m_pRenderTarget != NULL)
	{
		return m_pRenderTarget->EndDraw();
	}

	return E_FAIL;
}

BOOL CRenderTarget::VerifyResource(CD2DResource* pResource)
{
	if (pResource == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	ASSERT_VALID(pResource);

	if (!pResource->IsValid())
	{
		if (FAILED(pResource->Create(this)))
		{
			return FALSE;
		}
	}

	return TRUE;
}

D2D1_COLOR_F CRenderTarget::COLORREF_TO_D2DCOLOR(COLORREF color, int nAlpha)
{
	return D2D1::ColorF(GetRValue(color) / 255.0f, GetGValue(color) / 255.0f, GetBValue(color) / 255.0f, nAlpha / 255.0f);
}

void CRenderTarget::Clear(D2D1_COLOR_F color)
{
	if (m_pRenderTarget != NULL)
	{
		m_pRenderTarget->Clear(color);
	}
}

void CRenderTarget::DrawRectangle(const CD2DRectF& rect, CD2DBrush* pBrush, FLOAT fStrokeWidth, ID2D1StrokeStyle *strokeStyle)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->DrawRectangle(rect, *pBrush, fStrokeWidth, strokeStyle);
	}
}

void CRenderTarget::FillRectangle(const CD2DRectF& rect, CD2DBrush* pBrush)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->FillRectangle(rect, *pBrush);
	}
}

void CRenderTarget::DrawLine(const CD2DPointF& ptFrom, const CD2DPointF& ptTo, CD2DBrush* pBrush, FLOAT fStrokeWidth, ID2D1StrokeStyle *strokeStyle)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->DrawLine(ptFrom, ptTo, *pBrush, fStrokeWidth, strokeStyle);
	}
}

void CRenderTarget::FillOpacityMask(CD2DBitmap* pOpacityMask, CD2DBrush* pBrush,
	D2D1_OPACITY_MASK_CONTENT content, const CD2DRectF& rectDest, const CD2DRectF& rectSrc)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush) && VerifyResource(pOpacityMask))
	{
		m_pRenderTarget->FillOpacityMask(*pOpacityMask, *pBrush, content, rectDest, rectSrc);
	}
}

void CRenderTarget::DrawText(const CString& strText,
	const CD2DRectF& rect, CD2DBrush* pForegroundBrush,
	CD2DTextFormat* textFormat,
	D2D1_DRAW_TEXT_OPTIONS options,
	DWRITE_MEASURING_MODE measuringMode)
{
	USES_CONVERSION;

	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (!VerifyResource(pForegroundBrush))
	{
		return;
	}

	if (textFormat == NULL)
	{
		// Use default text format
		if (m_pTextFormatDefault == NULL)
		{
			NONCLIENTMETRICS NonClientMetrics;
			NonClientMetrics.cbSize = sizeof(NONCLIENTMETRICS);

			::SystemParametersInfo(SPI_GETNONCLIENTMETRICS, NonClientMetrics.cbSize, &NonClientMetrics, 0);

			m_pTextFormatDefault = new CD2DTextFormat(this, NonClientMetrics.lfMenuFont.lfFaceName, (FLOAT)abs(NonClientMetrics.lfMenuFont.lfHeight));
		}

		textFormat = m_pTextFormatDefault;
	}

	if (!textFormat->IsValid())
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->DrawText(T2CW(strText), strText.GetLength(), textFormat->m_pTextFormat, &rect,
		*pForegroundBrush, options, measuringMode);
}

void CRenderTarget::DrawTextLayout(const CD2DPointF& ptOrigin, CD2DTextLayout* textLayout,
	CD2DBrush* pBrushForeground, D2D1_DRAW_TEXT_OPTIONS options)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(textLayout) && VerifyResource(pBrushForeground))
	{
		m_pRenderTarget->DrawTextLayout(ptOrigin, *textLayout, *pBrushForeground, options);
	}
}

void CRenderTarget::DrawBitmap(CD2DBitmap* pBitmap, const CD2DRectF& rect, float fOpacity,
	D2D1_BITMAP_INTERPOLATION_MODE interpolationMode,
	const CD2DRectF* pRectSrc)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBitmap))
	{
		m_pRenderTarget->DrawBitmap(*pBitmap, rect, fOpacity, interpolationMode, pRectSrc);
	}
}

void CRenderTarget::DrawRoundedRectangle(const CD2DRoundedRect& rectRounded, CD2DBrush* pBrush, FLOAT fStrokeWidth, ID2D1StrokeStyle *strokeStyle)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->DrawRoundedRectangle(rectRounded, (ID2D1Brush*)*pBrush, fStrokeWidth, strokeStyle);
	}
}

void CRenderTarget::FillRoundedRectangle(const CD2DRoundedRect& rectRounded, CD2DBrush* pBrush)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->FillRoundedRectangle(rectRounded, (ID2D1Brush*)*pBrush);
	}
}

void CRenderTarget::DrawEllipse(const CD2DEllipse& ellipse, CD2DBrush* pBrush, FLOAT fStrokeWidth, ID2D1StrokeStyle *strokeStyle)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->DrawEllipse(ellipse, (ID2D1Brush*)*pBrush, fStrokeWidth, strokeStyle);
	}
}

void CRenderTarget::FillEllipse(const CD2DEllipse& ellipse, CD2DBrush* pBrush)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->FillEllipse(ellipse, (ID2D1Brush*)*pBrush);
	}
}

void CRenderTarget::DrawGeometry(CD2DGeometry* pGeometry, CD2DBrush* pBrush, FLOAT fStrokeWidth, ID2D1StrokeStyle *strokeStyle)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		m_pRenderTarget->DrawGeometry((ID2D1Geometry*)*pGeometry, (ID2D1Brush*)*pBrush, fStrokeWidth, strokeStyle);
	}
}

void CRenderTarget::FillGeometry(CD2DGeometry* pGeometry, CD2DBrush* pBrush, CD2DBrush* pOpacityBrush)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pBrush))
	{
		if (pOpacityBrush != NULL)
		{
			VerifyResource(pOpacityBrush);
		}

		m_pRenderTarget->FillGeometry((ID2D1Geometry*)*pGeometry, (ID2D1Brush*)*pBrush, pOpacityBrush == NULL ? NULL : (ID2D1Brush*)*pOpacityBrush);
	}
}

void CRenderTarget::DrawGlyphRun(const CD2DPointF& ptBaseLineOrigin, const DWRITE_GLYPH_RUN& glyphRun, CD2DBrush* pForegroundBrush, DWRITE_MEASURING_MODE measuringMode)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pForegroundBrush))
	{
		m_pRenderTarget->DrawGlyphRun(ptBaseLineOrigin, &glyphRun, *pForegroundBrush, measuringMode);
	}
}

void CRenderTarget::FillMesh(CD2DMesh* pMesh, CD2DBrush* pBrush)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	if (VerifyResource(pMesh) && VerifyResource(pBrush))
	{
		m_pRenderTarget->FillMesh(*pMesh, *pBrush);
	}
}

void CRenderTarget::SetAntialiasMode(D2D1_ANTIALIAS_MODE antialiasMode)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetAntialiasMode(antialiasMode);
}

D2D1_ANTIALIAS_MODE CRenderTarget::GetAntialiasMode() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return (D2D1_ANTIALIAS_MODE)-1;
	}

	return m_pRenderTarget->GetAntialiasMode();
}

void CRenderTarget::SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetTextAntialiasMode(textAntialiasMode);
}

D2D1_TEXT_ANTIALIAS_MODE CRenderTarget::GetTextAntialiasMode() const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return (D2D1_TEXT_ANTIALIAS_MODE)-1;
	}

	return m_pRenderTarget->GetTextAntialiasMode();
}

void CRenderTarget::SetTextRenderingParams(IDWriteRenderingParams* textRenderingParams)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetTextRenderingParams(textRenderingParams);
}

void CRenderTarget::GetTextRenderingParams(IDWriteRenderingParams** textRenderingParams)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->GetTextRenderingParams(textRenderingParams);
}

void CRenderTarget::SetTransform(const D2D1_MATRIX_3X2_F* transform)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetTransform(transform);
}

void CRenderTarget::SetTransform(const D2D1_MATRIX_3X2_F& transform)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SetTransform(transform);
}

void CRenderTarget::GetTransform(D2D1_MATRIX_3X2_F* transform)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->GetTransform(transform);
}

BOOL CRenderTarget::CreateCompatibleRenderTarget(CBitmapRenderTarget& bitmapTarget, CD2DSizeF sizeDesired, CD2DSizeU sizePixelDesired,
	D2D1_PIXEL_FORMAT* desiredFormat, D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	HRESULT hr = m_pRenderTarget->CreateCompatibleRenderTarget(
		sizeDesired.IsNull() ? NULL : &sizeDesired,
		sizePixelDesired.IsNull() ? NULL : &sizePixelDesired,
		desiredFormat, options, &bitmapTarget.m_pBitmapRenderTarget);
	if (FAILED(hr))
	{
		return FALSE;
	}

	bitmapTarget.m_pRenderTarget =  bitmapTarget.m_pBitmapRenderTarget;
	return TRUE;
}

void CRenderTarget::PushLayer(const D2D1_LAYER_PARAMETERS& layerParameters, CD2DLayer& layer)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->PushLayer(layerParameters, layer);
}

void CRenderTarget::PopLayer()
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->PopLayer();
}

void CRenderTarget::Flush(D2D1_TAG *tag1, D2D1_TAG *tag2)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->Flush(tag1, tag2);
}

void CRenderTarget::SaveDrawingState(ID2D1DrawingStateBlock& drawingStateBlock) const
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->SaveDrawingState(&drawingStateBlock);
}

void CRenderTarget::RestoreDrawingState(ID2D1DrawingStateBlock& drawingStateBlock)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->RestoreDrawingState(&drawingStateBlock);
}

void CRenderTarget::PushAxisAlignedClip(const CD2DRectF& rect, D2D1_ANTIALIAS_MODE mode)
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->PushAxisAlignedClip(rect, mode);
}

void CRenderTarget::PopAxisAlignedClip()
{
	if (m_pRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget->PopAxisAlignedClip();
}

////////////////////////////////////////////////////////////////////////////////
// CHwndRenderTarget

IMPLEMENT_DYNAMIC(CHwndRenderTarget, CRenderTarget)

CHwndRenderTarget::CHwndRenderTarget(HWND hwnd)
{
	m_pHwndRenderTarget = NULL;
	Create(hwnd);
}

BOOL CHwndRenderTarget::Create(HWND hWnd)
{
	if (hWnd == NULL)
	{
		return FALSE;
	}

	if (m_pRenderTarget != NULL)
	{
		// Already created
		ASSERT(FALSE);
		return FALSE;
	}

	if (_afxD2DState->GetDirect2dFactory() == NULL)
	{
		// Not supported by system
		return FALSE;
	}

	CRect rectClient;
	::GetClientRect(hWnd, &rectClient);

	D2D1_SIZE_U size = D2D1::SizeU(rectClient.Width(), rectClient.Height());

	// Create a Direct2D render target.
	HRESULT hr = _afxD2DState->GetDirect2dFactory()->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, size),
		&m_pHwndRenderTarget);

	if (FAILED(hr))
	{
		return FALSE;
	}

	m_pRenderTarget = m_pHwndRenderTarget;
	return TRUE;
}

BOOL CHwndRenderTarget::ReCreate(HWND hWnd)
{
	if (m_pHwndRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	SafeRelease(&m_pHwndRenderTarget);
	m_pRenderTarget = NULL;

	if (!Create(hWnd))
	{
		return FALSE;
	}

	for (POSITION pos = m_lstResources.GetHeadPosition(); pos != NULL;)
	{
		CD2DResource* pRes = DYNAMIC_DOWNCAST(CD2DResource, m_lstResources.GetNext(pos));
		ASSERT_VALID(pRes);

		pRes->ReCreate(this);
	}

	return TRUE;
}

void CHwndRenderTarget::Attach(ID2D1HwndRenderTarget* pResource)
{
	if (m_pRenderTarget != NULL)
	{
		ASSERT(FALSE);
		return;
	}

	ASSERT(m_pHwndRenderTarget == NULL);
	m_pRenderTarget = m_pHwndRenderTarget = pResource;
}

ID2D1HwndRenderTarget* CHwndRenderTarget::Detach()
{
	ID2D1HwndRenderTarget* pResource = m_pHwndRenderTarget;
	m_pRenderTarget = m_pHwndRenderTarget = NULL;
	return pResource;
}


BOOL CHwndRenderTarget::Resize(const CD2DSizeU& size)
{
	if (m_pHwndRenderTarget != NULL)
	{
		return SUCCEEDED(m_pHwndRenderTarget->Resize(size));
	}

	return FALSE;
}

////////////////////////////////////////////////////////////////////////////////
// CDCRenderTarget

IMPLEMENT_DYNAMIC(CDCRenderTarget, CRenderTarget)

CDCRenderTarget::CDCRenderTarget()
{
	m_pDCRenderTarget = NULL;
}

BOOL CDCRenderTarget::Create(const D2D1_RENDER_TARGET_PROPERTIES& props)
{
	if (m_pRenderTarget != NULL)
	{
		// Already created
		ASSERT(FALSE);
		return FALSE;
	}

	if (_afxD2DState->GetDirect2dFactory() == NULL)
	{
		return FALSE;
	}

	HRESULT hr = _afxD2DState->GetDirect2dFactory()->CreateDCRenderTarget(&props, &m_pDCRenderTarget);
	if (FAILED(hr))
	{
		return FALSE;
	}

	m_pRenderTarget = m_pDCRenderTarget;
	return TRUE;
}

BOOL CDCRenderTarget::BindDC(const CDC& dc, const CRect& rect)
{
	if (m_pDCRenderTarget == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (dc.GetSafeHdc() == NULL)
	{
		return FALSE;
	}

	m_pDCRenderTarget->BindDC(dc.GetSafeHdc(), rect);
	return TRUE;
}

void CDCRenderTarget::Attach(ID2D1DCRenderTarget* pResource)
{
	if (m_pRenderTarget != NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pRenderTarget = m_pDCRenderTarget = pResource;
}

ID2D1DCRenderTarget* CDCRenderTarget::Detach()
{
	ID2D1DCRenderTarget* pResource = m_pDCRenderTarget;
	m_pRenderTarget = m_pDCRenderTarget = NULL;
	return pResource;
}

////////////////////////////////////////////////////////////////////////////////
// CBitmapRenderTarget

IMPLEMENT_DYNAMIC(CBitmapRenderTarget, CRenderTarget)

BOOL CBitmapRenderTarget::GetBitmap(CD2DBitmap& bitmap)
{
	if (m_pBitmapRenderTarget == NULL)
	{
		return FALSE;
	}

	HRESULT hr = m_pBitmapRenderTarget->GetBitmap(&bitmap.m_pBitmap);
	return SUCCEEDED(hr);
}

void CBitmapRenderTarget::Attach(ID2D1BitmapRenderTarget* pResource)
{
	if (m_pRenderTarget != NULL)
	{
		ASSERT(FALSE);
		return;
	}

	ASSERT(m_pBitmapRenderTarget == NULL);
	m_pRenderTarget = m_pBitmapRenderTarget = pResource;
}

ID2D1BitmapRenderTarget* CBitmapRenderTarget::Detach()
{
	ID2D1BitmapRenderTarget* pResource = m_pBitmapRenderTarget;
	m_pBitmapRenderTarget = NULL;
	return pResource;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DGeometry

IMPLEMENT_DYNAMIC(CD2DGeometry, CD2DResource)

CD2DGeometry::CD2DGeometry(CRenderTarget* pParentTarget, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	m_pGeometry = NULL;
}

CD2DGeometry::~CD2DGeometry()
{
	Destroy();
}

void CD2DGeometry::Destroy()
{
	SafeRelease(&m_pGeometry);
}

void CD2DGeometry::Attach(ID2D1Geometry* pResource)
{
	ASSERT(m_pGeometry == NULL);
	m_pGeometry = pResource;
}

ID2D1Geometry* CD2DGeometry::Detach()
{
	ID2D1Geometry* pResource = m_pGeometry;
	m_pGeometry = NULL;
	return pResource;
}

BOOL CD2DGeometry::CombineWithGeometry(CD2DGeometry& inputGeometry, D2D1_COMBINE_MODE combineMode, const D2D1_MATRIX_3X2_F& inputGeometryTransform, ID2D1SimplifiedGeometrySink* geometrySink, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	if (inputGeometry.Get() == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->CombineWithGeometry(inputGeometry.Get(), combineMode, inputGeometryTransform, flatteningTolerance, geometrySink));
}

D2D1_GEOMETRY_RELATION CD2DGeometry::CompareWithGeometry(CD2DGeometry& inputGeometry, const D2D1_MATRIX_3X2_F& inputGeometryTransform, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return D2D1_GEOMETRY_RELATION_UNKNOWN;
	}

	if (inputGeometry.Get() == NULL)
	{
		ASSERT(FALSE);
		return D2D1_GEOMETRY_RELATION_UNKNOWN;
	}

	D2D1_GEOMETRY_RELATION relation = D2D1_GEOMETRY_RELATION_UNKNOWN;
	if (SUCCEEDED(m_pGeometry->CompareWithGeometry(inputGeometry.Get(), inputGeometryTransform, flatteningTolerance, &relation)))
	{
		return relation;
	}

	return D2D1_GEOMETRY_RELATION_UNKNOWN;
}

BOOL CD2DGeometry::ComputeArea(const D2D1_MATRIX_3X2_F& worldTransform, FLOAT& area, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->ComputeArea(worldTransform, flatteningTolerance, &area));
}

BOOL CD2DGeometry::ComputeLength(const D2D1_MATRIX_3X2_F& worldTransform, FLOAT& length, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->ComputeLength(worldTransform, flatteningTolerance, &length));
}

BOOL CD2DGeometry::ComputePointAtLength(FLOAT length, const D2D1_MATRIX_3X2_F &worldTransform, CD2DPointF& point, CD2DPointF& unitTangentVector, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->ComputePointAtLength(length, worldTransform, flatteningTolerance, &point, &unitTangentVector));
}

BOOL CD2DGeometry::GetBounds(const D2D1_MATRIX_3X2_F& worldTransform, CD2DRectF& bounds) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->GetBounds(worldTransform, &bounds));
}

BOOL CD2DGeometry::GetWidenedBounds(FLOAT strokeWidth, ID2D1StrokeStyle* strokeStyle, const D2D1_MATRIX_3X2_F& worldTransform, CD2DRectF& bounds, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->GetWidenedBounds(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, &bounds));
}

BOOL CD2DGeometry::FillContainsPoint(CD2DPointF point, const D2D1_MATRIX_3X2_F& worldTransform, BOOL* contains, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->FillContainsPoint(point, worldTransform, flatteningTolerance, contains));
}

BOOL CD2DGeometry::StrokeContainsPoint(CD2DPointF point, FLOAT strokeWidth, ID2D1StrokeStyle *strokeStyle, const D2D1_MATRIX_3X2_F& worldTransform, BOOL *contains, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->StrokeContainsPoint(point, strokeWidth, strokeStyle, worldTransform, flatteningTolerance, contains));
}

BOOL CD2DGeometry::Outline(const D2D1_MATRIX_3X2_F &worldTransform, ID2D1SimplifiedGeometrySink* geometrySink, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->Outline(&worldTransform, flatteningTolerance, geometrySink));
}

BOOL CD2DGeometry::Simplify(D2D1_GEOMETRY_SIMPLIFICATION_OPTION simplificationOption, const D2D1_MATRIX_3X2_F& worldTransform, ID2D1SimplifiedGeometrySink* geometrySink, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->Simplify(simplificationOption, worldTransform, flatteningTolerance, geometrySink));
}

BOOL CD2DGeometry::Tessellate(const D2D1_MATRIX_3X2_F& worldTransform, ID2D1TessellationSink* tessellationSink, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->Tessellate(worldTransform, flatteningTolerance, tessellationSink));
}

BOOL CD2DGeometry::Widen(FLOAT strokeWidth, ID2D1StrokeStyle* strokeStyle, const D2D1_MATRIX_3X2_F& worldTransform, ID2D1SimplifiedGeometrySink* geometrySink, FLOAT flatteningTolerance) const
{
	if (m_pGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pGeometry->Widen(strokeWidth, strokeStyle, worldTransform, flatteningTolerance, geometrySink));
}

////////////////////////////////////////////////////////////////////////////////
// CD2DPathGeometry

IMPLEMENT_DYNAMIC(CD2DPathGeometry, CD2DGeometry)

CD2DPathGeometry::CD2DPathGeometry(CRenderTarget* pParentTarget, BOOL bAutoDestroy) :
	CD2DGeometry(pParentTarget, bAutoDestroy)
{
	m_pPathGeometry = NULL;
}

HRESULT CD2DPathGeometry::Create(CRenderTarget* /*pTarget*/)
{
	if (_afxD2DState->GetDirect2dFactory() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pPathGeometry != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	HRESULT hr = _afxD2DState->GetDirect2dFactory()->CreatePathGeometry(&m_pPathGeometry);
	if (FAILED(hr))
	{
		return hr;
	}

	m_pGeometry = m_pPathGeometry;
	return S_OK;
}

void CD2DPathGeometry::Destroy()
{
	SafeRelease(&m_pPathGeometry);
}

ID2D1GeometrySink* CD2DPathGeometry::Open()
{
	if (m_pPathGeometry == NULL)
	{
		ASSERT(FALSE);
		return NULL;
	}

	ID2D1GeometrySink* pSink = NULL;
	HRESULT hr = m_pPathGeometry->Open(&pSink);

	if (FAILED(hr))
	{
		return NULL;
	}

	return pSink;
}

BOOL CD2DPathGeometry::Stream(ID2D1GeometrySink* geometrySink)
{
	if (m_pPathGeometry == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pPathGeometry->Stream(geometrySink));
}

int CD2DPathGeometry::GetSegmentCount() const
{
	if (m_pPathGeometry == NULL)
	{
		ASSERT(FALSE);
		return -1;
	}

	UINT nCount = (UINT)-1;
	m_pPathGeometry->GetSegmentCount(&nCount);

	return (int)nCount;
}

int CD2DPathGeometry::GetFigureCount() const
{
	if (m_pPathGeometry == NULL)
	{
		ASSERT(FALSE);
		return -1;
	}

	UINT nCount = (UINT)-1;
	m_pPathGeometry->GetFigureCount(&nCount);

	return (int)nCount;
}

void CD2DPathGeometry::Attach(ID2D1PathGeometry* pResource)
{
	ASSERT(m_pGeometry == NULL);
	ASSERT(m_pPathGeometry == NULL);

	m_pGeometry = m_pPathGeometry = pResource;
}

ID2D1PathGeometry* CD2DPathGeometry::Detach()
{
	ID2D1PathGeometry* pResource = m_pPathGeometry;
	m_pGeometry = m_pPathGeometry = NULL;
	return pResource;
}

////////////////////////////////////////////////////////////////////////////////
// CD2DGeometrySink

CD2DGeometrySink::CD2DGeometrySink(CD2DPathGeometry& pathGeometry)
{
	m_pSink = pathGeometry.Open();
}

CD2DGeometrySink::~CD2DGeometrySink()
{
	if (m_pSink != NULL)
	{
		m_pSink->Close();
		m_pSink->Release();
		m_pSink = NULL;
	}
}

void CD2DGeometrySink::BeginFigure(CD2DPointF startPoint, D2D1_FIGURE_BEGIN figureBegin)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->BeginFigure(startPoint, figureBegin);
}

void CD2DGeometrySink::EndFigure(D2D1_FIGURE_END figureEnd)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->EndFigure(figureEnd);
}

void CD2DGeometrySink::AddArc(const D2D1_ARC_SEGMENT& arc)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddArc(arc);
}

void CD2DGeometrySink::AddBezier(const D2D1_BEZIER_SEGMENT& bezier)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddBezier(bezier);
}

void CD2DGeometrySink::AddBeziers(const CArray<D2D1_BEZIER_SEGMENT, D2D1_BEZIER_SEGMENT>& beziers)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddBeziers(beziers.GetData(), (UINT)beziers.GetSize());
}

void CD2DGeometrySink::AddQuadraticBezier(const D2D1_QUADRATIC_BEZIER_SEGMENT& bezier)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddQuadraticBezier(bezier);
}

void CD2DGeometrySink::AddQuadraticBeziers(const CArray<D2D1_QUADRATIC_BEZIER_SEGMENT, D2D1_QUADRATIC_BEZIER_SEGMENT>& beziers)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddQuadraticBeziers(beziers.GetData(), (UINT)beziers.GetSize());
}

void CD2DGeometrySink::AddLine(CD2DPointF point)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddLine(point);
}

void CD2DGeometrySink::AddLines(const CArray<CD2DPointF, CD2DPointF>& points)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->AddLines(reinterpret_cast<const D2D1_POINT_2F*>(points.GetData()), (UINT)points.GetSize());
}

BOOL CD2DGeometrySink::Close()
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return FALSE;
	}

	return SUCCEEDED(m_pSink->Close());
}

void CD2DGeometrySink::SetFillMode(D2D1_FILL_MODE fillMode)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->SetFillMode(fillMode);
}

void CD2DGeometrySink::SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags)
{
	if (m_pSink == NULL)
	{
		ASSERT(FALSE);
		return;
	}

	m_pSink->SetSegmentFlags(vertexFlags);
}

////////////////////////////////////////////////////////////////////////////////
// CD2DMesh

IMPLEMENT_DYNAMIC(CD2DMesh, CD2DResource)

CD2DMesh::CD2DMesh(CRenderTarget* pParentTarget, BOOL bAutoDestroy) :
	CD2DResource(pParentTarget, bAutoDestroy)
{
	m_pMesh = NULL;
}

CD2DMesh::~CD2DMesh()
{
	Destroy();
}

HRESULT CD2DMesh::Create(CRenderTarget* pRenderTarget)
{
	if (pRenderTarget == NULL || pRenderTarget->GetRenderTarget() == NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	if (m_pMesh != NULL)
	{
		ASSERT(FALSE);
		return E_FAIL;
	}

	return pRenderTarget->GetRenderTarget()->CreateMesh(&m_pMesh);
}

void CD2DMesh::Destroy()
{
	SafeRelease(&m_pMesh);
}

void CD2DMesh::Attach(ID2D1Mesh* pResource)
{
	ASSERT(m_pMesh == NULL);
	m_pMesh = pResource;
}

ID2D1Mesh* CD2DMesh::Detach()
{
	ID2D1Mesh* pResource = m_pMesh;
	m_pMesh = NULL;
	return pResource;
}

ID2D1TessellationSink* CD2DMesh::Open()
{
	if (m_pMesh == NULL)
	{
		return NULL;
	}

	ID2D1TessellationSink* pSink = NULL;

	HRESULT hr = m_pMesh->Open(&pSink);
	if (FAILED(hr))
	{
		return NULL;
	}

	return pSink;
}

PROCESS_LOCAL(_AFX_D2D_STATE, _afxD2DState)


// Privately define CLSID_WICImagingFactory1 so the MFC static library can link against both SDK 7.x and SDK 8.x

#include <initguid.h>

DEFINE_GUID(CLSID_WICImagingFactory1, 0xcacaf262, 0x9370, 0x4615, 0xa1, 0x3b, 0x9f, 0x55, 0x39, 0xda, 0x4c, 0xa);
