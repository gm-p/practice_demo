// Ex_Ctlr3SDIView.cpp : implementation of the CEx_Ctlr3SDIView class
//

#include "stdafx.h"
#include "Ex_Ctlr3SDI.h"

#include "Ex_Ctlr3SDIDoc.h"
#include "Ex_Ctlr3SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView

IMPLEMENT_DYNCREATE(CEx_Ctlr3SDIView, CView)

BEGIN_MESSAGE_MAP(CEx_Ctlr3SDIView, CView)
	//{{AFX_MSG_MAP(CEx_Ctlr3SDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView construction/destruction

CEx_Ctlr3SDIView::CEx_Ctlr3SDIView()
{
	// TODO: add construction code here

}

CEx_Ctlr3SDIView::~CEx_Ctlr3SDIView()
{
}

BOOL CEx_Ctlr3SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView drawing

void CEx_Ctlr3SDIView::OnDraw(CDC* pDC)
{
	CEx_Ctlr3SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView printing

BOOL CEx_Ctlr3SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_Ctlr3SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_Ctlr3SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView diagnostics

#ifdef _DEBUG
void CEx_Ctlr3SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_Ctlr3SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_Ctlr3SDIDoc* CEx_Ctlr3SDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_Ctlr3SDIDoc)));
	return (CEx_Ctlr3SDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIView message handlers
