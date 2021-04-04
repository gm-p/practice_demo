// Ex_ArrayView.cpp : implementation of the CEx_ArrayView class
//

#include "stdafx.h"
#include "Ex_Array.h"

#include "Ex_ArrayDoc.h"
#include "Ex_ArrayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView

IMPLEMENT_DYNCREATE(CEx_ArrayView, CView)

BEGIN_MESSAGE_MAP(CEx_ArrayView, CView)
	//{{AFX_MSG_MAP(CEx_ArrayView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView construction/destruction

CEx_ArrayView::CEx_ArrayView()
{
	// TODO: add construction code here

}

CEx_ArrayView::~CEx_ArrayView()
{
}

BOOL CEx_ArrayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView drawing

void CEx_ArrayView::OnDraw(CDC* pDC)
{
	CEx_ArrayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int y=0;
	CString str;
	for(int i=0;i<pDoc->m_strContents.GetSize();i++)
	{
		str=pDoc->m_strContents.GetAt(i);
		pDC->TextOut(0,y,str);
		y+=16;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView printing

BOOL CEx_ArrayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ArrayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ArrayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView diagnostics

#ifdef _DEBUG
void CEx_ArrayView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_ArrayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_ArrayDoc* CEx_ArrayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ArrayDoc)));
	return (CEx_ArrayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayView message handlers
