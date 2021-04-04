// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView

IMPLEMENT_DYNCREATE(CEx_StudentView, CView)

BEGIN_MESSAGE_MAP(CEx_StudentView, CView)
	//{{AFX_MSG_MAP(CEx_StudentView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView construction/destruction

CEx_StudentView::CEx_StudentView()
{
	// TODO: add construction code here

}

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView drawing

void CEx_StudentView::OnDraw(CDC* pDC)
{
	CEx_StudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int y=0;
	for(int nIndex=0;nIndex<pDoc->GetAllRecNum();nIndex++)
	{
		pDoc->GetStudentAt(nIndex)->Display(y,pDC);
		y+=16;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView printing

BOOL CEx_StudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_StudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_StudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView diagnostics

#ifdef _DEBUG
void CEx_StudentView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_StudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_StudentDoc* CEx_StudentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_StudentDoc)));
	return (CEx_StudentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView message handlers
