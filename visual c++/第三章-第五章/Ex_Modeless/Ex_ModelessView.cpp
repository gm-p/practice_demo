// Ex_ModelessView.cpp : implementation of the CEx_ModelessView class
//

#include "stdafx.h"
#include "Ex_Modeless.h"

#include "Ex_ModelessDoc.h"
#include "Ex_ModelessView.h"
#include "LessDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView

IMPLEMENT_DYNCREATE(CEx_ModelessView, CView)

BEGIN_MESSAGE_MAP(CEx_ModelessView, CView)
	//{{AFX_MSG_MAP(CEx_ModelessView)
	ON_COMMAND(ID_DLG_MODELESS, OnDlgModeless)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView construction/destruction

CEx_ModelessView::CEx_ModelessView()
{
	// TODO: add construction code here

}

CEx_ModelessView::~CEx_ModelessView()
{
}

BOOL CEx_ModelessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView drawing

void CEx_ModelessView::OnDraw(CDC* pDC)
{
	CEx_ModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView printing

BOOL CEx_ModelessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ModelessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ModelessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView diagnostics

#ifdef _DEBUG
void CEx_ModelessView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_ModelessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_ModelessDoc* CEx_ModelessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ModelessDoc)));
	return (CEx_ModelessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessView message handlers

void CEx_ModelessView::OnDlgModeless() 
{
	// TODO: Add your command handler code here
	CLessDlg *pDlg=new CLessDlg;
	pDlg->Create(IDD_DIALOG1);
	pDlg->ShowWindow(SW_NORMAL);
}
