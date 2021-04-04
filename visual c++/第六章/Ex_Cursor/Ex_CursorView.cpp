// Ex_CursorView.cpp : implementation of the CEx_CursorView class
//

#include "stdafx.h"
#include "Ex_Cursor.h"

#include "Ex_CursorDoc.h"
#include "Ex_CursorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView

IMPLEMENT_DYNCREATE(CEx_CursorView, CView)

BEGIN_MESSAGE_MAP(CEx_CursorView, CView)
	//{{AFX_MSG_MAP(CEx_CursorView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView construction/destruction

CEx_CursorView::CEx_CursorView()
{
	// TODO: add construction code here

}

CEx_CursorView::~CEx_CursorView()
{
}

BOOL CEx_CursorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView drawing

void CEx_CursorView::OnDraw(CDC* pDC)
{
	CEx_CursorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView printing

BOOL CEx_CursorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_CursorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_CursorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView diagnostics

#ifdef _DEBUG
void CEx_CursorView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_CursorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_CursorDoc* CEx_CursorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_CursorDoc)));
	return (CEx_CursorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorView message handlers
