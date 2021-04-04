// Ex_RectView.cpp : implementation of the CEx_RectView class
//

#include "stdafx.h"
#include "Ex_Rect.h"

#include "Ex_RectDoc.h"
#include "Ex_RectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_RectView

IMPLEMENT_DYNCREATE(CEx_RectView, CFormView)

BEGIN_MESSAGE_MAP(CEx_RectView, CFormView)
	//{{AFX_MSG_MAP(CEx_RectView)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_RectView construction/destruction

CEx_RectView::CEx_RectView()
	: CFormView(CEx_RectView::IDD)
{
	//{{AFX_DATA_INIT(CEx_RectView)
	m_CoorX = 0;
	m_CoorY = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_bEditOK=FALSE;

}

CEx_RectView::~CEx_RectView()
{
}

void CEx_RectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_RectView)
	DDX_Control(pDX, IDC_SPIN2, m_SpinY);
	DDX_Control(pDX, IDC_SPIN1, m_SpinX);
	DDX_Text(pDX, IDC_EDIT1, m_CoorX);
	DDX_Text(pDX, IDC_EDIT2, m_CoorY);
	//}}AFX_DATA_MAP
}

BOOL CEx_RectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEx_RectView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	CEx_RectDoc* pDoc=(CEx_RectDoc*)GetDocument();
	m_CoorX=pDoc->m_ptRect.x;
	m_CoorY=pDoc->m_ptRect.y;
	m_SpinX.SetRange(0,1024);
	m_SpinY.SetRange(0,768);
	UpdateData(FALSE);
	m_bEditOK=TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CEx_RectView printing

BOOL CEx_RectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_RectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_RectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEx_RectView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_RectView diagnostics

#ifdef _DEBUG
void CEx_RectView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEx_RectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEx_RectDoc* CEx_RectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_RectDoc)));
	return (CEx_RectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_RectView message handlers

void CEx_RectView::OnChangeEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	if(!m_bEditOK)  return;
	UpdateData(TRUE);
	CEx_RectDoc* pDoc=(CEx_RectDoc*)GetDocument();
	pDoc->m_ptRect.x=m_CoorX;
	pDoc->m_ptRect.y=m_CoorY;
	CPoint pt(m_CoorX,m_CoorY);
	pDoc->UpdateAllViews(NULL,2,(CObject*)&pt);
	
}

void CEx_RectView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(lHint==1)
	{
		CPoint* pPoint=(CPoint*)pHint;
		m_CoorX=pPoint->x;
		m_CoorY=pPoint->y;
		UpdateData(FALSE);
		CEx_RectDoc* pDoc=(CEx_RectDoc*)GetDocument();
		pDoc->m_ptRect=*pPoint;
	}
	
}
