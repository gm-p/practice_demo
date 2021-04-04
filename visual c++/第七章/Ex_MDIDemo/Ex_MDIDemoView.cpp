// Ex_MDIDemoView.cpp : implementation of the CEx_MDIDemoView class
//

#include "stdafx.h"
#include "Ex_MDIDemo.h"

#include "Ex_MDIDemoDoc.h"
#include "Ex_MDIDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView

IMPLEMENT_DYNCREATE(CEx_MDIDemoView, CView)

BEGIN_MESSAGE_MAP(CEx_MDIDemoView, CView)
	//{{AFX_MSG_MAP(CEx_MDIDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView construction/destruction

CEx_MDIDemoView::CEx_MDIDemoView()
{
	// TODO: add construction code here

}

CEx_MDIDemoView::~CEx_MDIDemoView()
{
}

BOOL CEx_MDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView drawing

void CEx_MDIDemoView::OnDraw(CDC* pDC)
{
	CEx_MDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView printing

BOOL CEx_MDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView diagnostics

#ifdef _DEBUG
void CEx_MDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MDIDemoDoc* CEx_MDIDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MDIDemoDoc)));
	return (CEx_MDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoView message handlers
