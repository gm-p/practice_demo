// Ex_SDIArchiveView.cpp : implementation of the CEx_SDIArchiveView class
//

#include "stdafx.h"
#include "Ex_SDIArchive.h"

#include "Ex_SDIArchiveDoc.h"
#include "Ex_SDIArchiveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView

IMPLEMENT_DYNCREATE(CEx_SDIArchiveView, CView)

BEGIN_MESSAGE_MAP(CEx_SDIArchiveView, CView)
	//{{AFX_MSG_MAP(CEx_SDIArchiveView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView construction/destruction

CEx_SDIArchiveView::CEx_SDIArchiveView()
{
	// TODO: add construction code here

}

CEx_SDIArchiveView::~CEx_SDIArchiveView()
{
}

BOOL CEx_SDIArchiveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView drawing

void CEx_SDIArchiveView::OnDraw(CDC* pDC)
{
	CEx_SDIArchiveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView printing

BOOL CEx_SDIArchiveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_SDIArchiveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_SDIArchiveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView diagnostics

#ifdef _DEBUG
void CEx_SDIArchiveView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIArchiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIArchiveDoc* CEx_SDIArchiveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIArchiveDoc)));
	return (CEx_SDIArchiveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveView message handlers
