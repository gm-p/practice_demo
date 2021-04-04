// Ex_FormView.cpp : implementation of the CEx_FormView class
//

#include "stdafx.h"
#include "Ex_Form.h"

#include "Ex_FormDoc.h"
#include "Ex_FormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView

IMPLEMENT_DYNCREATE(CEx_FormView, CView)

BEGIN_MESSAGE_MAP(CEx_FormView, CView)
	//{{AFX_MSG_MAP(CEx_FormView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView construction/destruction

CEx_FormView::CEx_FormView()
{
	// TODO: add construction code here

}

CEx_FormView::~CEx_FormView()
{
}

BOOL CEx_FormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView drawing

void CEx_FormView::OnDraw(CDC* pDC)
{
	CEx_FormDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView printing

BOOL CEx_FormView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_FormView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_FormView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView diagnostics

#ifdef _DEBUG
void CEx_FormView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_FormView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_FormDoc* CEx_FormView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_FormDoc)));
	return (CEx_FormDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_FormView message handlers
