// Ex_MultiBarView.cpp : implementation of the CEx_MultiBarView class
//

#include "stdafx.h"
#include "Ex_MultiBar.h"

#include "Ex_MultiBarDoc.h"
#include "Ex_MultiBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView

IMPLEMENT_DYNCREATE(CEx_MultiBarView, CView)

BEGIN_MESSAGE_MAP(CEx_MultiBarView, CView)
	//{{AFX_MSG_MAP(CEx_MultiBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView construction/destruction

CEx_MultiBarView::CEx_MultiBarView()
{
	// TODO: add construction code here

}

CEx_MultiBarView::~CEx_MultiBarView()
{
}

BOOL CEx_MultiBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView drawing

void CEx_MultiBarView::OnDraw(CDC* pDC)
{
	CEx_MultiBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView printing

BOOL CEx_MultiBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MultiBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MultiBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView diagnostics

#ifdef _DEBUG
void CEx_MultiBarView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MultiBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MultiBarDoc* CEx_MultiBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MultiBarDoc)));
	return (CEx_MultiBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarView message handlers
