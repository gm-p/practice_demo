// Ex_MenuView.cpp : implementation of the CEx_MenuView class
//

#include "stdafx.h"
#include "Ex_Menu.h"

#include "Ex_MenuDoc.h"
#include "Ex_MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView

IMPLEMENT_DYNCREATE(CEx_MenuView, CView)

BEGIN_MESSAGE_MAP(CEx_MenuView, CView)
	//{{AFX_MSG_MAP(CEx_MenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView construction/destruction

CEx_MenuView::CEx_MenuView()
{
	// TODO: add construction code here

}

CEx_MenuView::~CEx_MenuView()
{
}

BOOL CEx_MenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView drawing

void CEx_MenuView::OnDraw(CDC* pDC)
{
	CEx_MenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView printing

BOOL CEx_MenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView diagnostics

#ifdef _DEBUG
void CEx_MenuView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MenuDoc* CEx_MenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MenuDoc)));
	return (CEx_MenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuView message handlers
