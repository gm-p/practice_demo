// Ex_EditView.cpp : implementation of the CEx_EditView class
//

#include "stdafx.h"
#include "Ex_Edit.h"

#include "Ex_EditDoc.h"
#include "Ex_EditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView

IMPLEMENT_DYNCREATE(CEx_EditView, CEditView)

BEGIN_MESSAGE_MAP(CEx_EditView, CEditView)
	//{{AFX_MSG_MAP(CEx_EditView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView construction/destruction

CEx_EditView::CEx_EditView()
{
	// TODO: add construction code here

}

CEx_EditView::~CEx_EditView()
{
}

BOOL CEx_EditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView drawing

void CEx_EditView::OnDraw(CDC* pDC)
{
	CEx_EditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView printing

BOOL CEx_EditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CEx_EditView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CEx_EditView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView diagnostics

#ifdef _DEBUG
void CEx_EditView::AssertValid() const
{
	CEditView::AssertValid();
}

void CEx_EditView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CEx_EditDoc* CEx_EditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_EditDoc)));
	return (CEx_EditDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_EditView message handlers
