// Ex_DySplitView.cpp : implementation of the CEx_DySplitView class
//

#include "stdafx.h"
#include "Ex_DySplit.h"

#include "Ex_DySplitDoc.h"
#include "Ex_DySplitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView

IMPLEMENT_DYNCREATE(CEx_DySplitView, CView)

BEGIN_MESSAGE_MAP(CEx_DySplitView, CView)
	//{{AFX_MSG_MAP(CEx_DySplitView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView construction/destruction

CEx_DySplitView::CEx_DySplitView()
{
	// TODO: add construction code here

}

CEx_DySplitView::~CEx_DySplitView()
{
}

BOOL CEx_DySplitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView drawing

void CEx_DySplitView::OnDraw(CDC* pDC)
{
	CEx_DySplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView printing

BOOL CEx_DySplitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_DySplitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_DySplitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView diagnostics

#ifdef _DEBUG
void CEx_DySplitView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_DySplitView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_DySplitDoc* CEx_DySplitView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_DySplitDoc)));
	return (CEx_DySplitDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DySplitView message handlers
