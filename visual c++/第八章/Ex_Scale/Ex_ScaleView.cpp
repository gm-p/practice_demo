// Ex_ScaleView.cpp : implementation of the CEx_ScaleView class
//

#include "stdafx.h"
#include "Ex_Scale.h"

#include "Ex_ScaleDoc.h"
#include "Ex_ScaleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView

IMPLEMENT_DYNCREATE(CEx_ScaleView, CView)

BEGIN_MESSAGE_MAP(CEx_ScaleView, CView)
	//{{AFX_MSG_MAP(CEx_ScaleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView construction/destruction

CEx_ScaleView::CEx_ScaleView()
{
	// TODO: add construction code here

}

CEx_ScaleView::~CEx_ScaleView()
{
}

BOOL CEx_ScaleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView drawing

void CEx_ScaleView::OnDraw(CDC* pDC)
{
	CEx_ScaleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(1000,1000);
	int nViewLength=rectClient.Width()/2;
	int nViewHeight=rectClient.Height()/2;
	pDC->SetViewportExt(nViewLength,nViewHeight);
	pDC->SetViewportOrg(nViewLength,nViewHeight);
	pDC->Ellipse(CRect(-500,-500,500,500));
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView printing

BOOL CEx_ScaleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ScaleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ScaleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView diagnostics

#ifdef _DEBUG
void CEx_ScaleView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_ScaleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_ScaleDoc* CEx_ScaleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ScaleDoc)));
	return (CEx_ScaleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ScaleView message handlers
