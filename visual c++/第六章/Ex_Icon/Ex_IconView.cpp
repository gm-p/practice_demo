// Ex_IconView.cpp : implementation of the CEx_IconView class
//

#include "stdafx.h"
#include "Ex_Icon.h"

#include "Ex_IconDoc.h"
#include "Ex_IconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView

IMPLEMENT_DYNCREATE(CEx_IconView, CView)

BEGIN_MESSAGE_MAP(CEx_IconView, CView)
	//{{AFX_MSG_MAP(CEx_IconView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView construction/destruction

CEx_IconView::CEx_IconView()
{
	// TODO: add construction code here

}

CEx_IconView::~CEx_IconView()
{
}

BOOL CEx_IconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView drawing

void CEx_IconView::OnDraw(CDC* pDC)
{
	CEx_IconDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView printing

BOOL CEx_IconView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_IconView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_IconView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView diagnostics

#ifdef _DEBUG
void CEx_IconView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_IconView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_IconDoc* CEx_IconView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_IconDoc)));
	return (CEx_IconDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_IconView message handlers
