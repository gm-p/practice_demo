// Ex_Ctrl5SDIView.cpp : implementation of the CEx_Ctrl5SDIView class
//

#include "stdafx.h"
#include "Ex_Ctrl5SDI.h"

#include "Ex_Ctrl5SDIDoc.h"
#include "Ex_Ctrl5SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView

IMPLEMENT_DYNCREATE(CEx_Ctrl5SDIView, CView)

BEGIN_MESSAGE_MAP(CEx_Ctrl5SDIView, CView)
	//{{AFX_MSG_MAP(CEx_Ctrl5SDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView construction/destruction

CEx_Ctrl5SDIView::CEx_Ctrl5SDIView()
{
	// TODO: add construction code here

}

CEx_Ctrl5SDIView::~CEx_Ctrl5SDIView()
{
}

BOOL CEx_Ctrl5SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView drawing

void CEx_Ctrl5SDIView::OnDraw(CDC* pDC)
{
	CEx_Ctrl5SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView printing

BOOL CEx_Ctrl5SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_Ctrl5SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_Ctrl5SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView diagnostics

#ifdef _DEBUG
void CEx_Ctrl5SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_Ctrl5SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_Ctrl5SDIDoc* CEx_Ctrl5SDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_Ctrl5SDIDoc)));
	return (CEx_Ctrl5SDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIView message handlers
