// Ex_Ctrl4SDIView.cpp : implementation of the CEx_Ctrl4SDIView class
//

#include "stdafx.h"
#include "Ex_Ctrl4SDI.h"

#include "Ex_Ctrl4SDIDoc.h"
#include "Ex_Ctrl4SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView

IMPLEMENT_DYNCREATE(CEx_Ctrl4SDIView, CView)

BEGIN_MESSAGE_MAP(CEx_Ctrl4SDIView, CView)
	//{{AFX_MSG_MAP(CEx_Ctrl4SDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView construction/destruction

CEx_Ctrl4SDIView::CEx_Ctrl4SDIView()
{
	// TODO: add construction code here

}

CEx_Ctrl4SDIView::~CEx_Ctrl4SDIView()
{
}

BOOL CEx_Ctrl4SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView drawing

void CEx_Ctrl4SDIView::OnDraw(CDC* pDC)
{
	CEx_Ctrl4SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView printing

BOOL CEx_Ctrl4SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_Ctrl4SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_Ctrl4SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView diagnostics

#ifdef _DEBUG
void CEx_Ctrl4SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_Ctrl4SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_Ctrl4SDIDoc* CEx_Ctrl4SDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_Ctrl4SDIDoc)));
	return (CEx_Ctrl4SDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl4SDIView message handlers
