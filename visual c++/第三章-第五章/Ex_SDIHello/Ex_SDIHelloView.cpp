// Ex_SDIHelloView.cpp : implementation of the CEx_SDIHelloView class
//

#include "stdafx.h"
#include "Ex_SDIHello.h"

#include "Ex_SDIHelloDoc.h"
#include "Ex_SDIHelloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView

IMPLEMENT_DYNCREATE(CEx_SDIHelloView, CView)

BEGIN_MESSAGE_MAP(CEx_SDIHelloView, CView)
	//{{AFX_MSG_MAP(CEx_SDIHelloView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView construction/destruction

CEx_SDIHelloView::CEx_SDIHelloView()
{
	// TODO: add construction code here

}

CEx_SDIHelloView::~CEx_SDIHelloView()
{
}

BOOL CEx_SDIHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView drawing

void CEx_SDIHelloView::OnDraw(CDC* pDC)
{
	CEx_SDIHelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView printing

BOOL CEx_SDIHelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_SDIHelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_SDIHelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView diagnostics

#ifdef _DEBUG
void CEx_SDIHelloView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIHelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIHelloDoc* CEx_SDIHelloView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIHelloDoc)));
	return (CEx_SDIHelloDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloView message handlers
