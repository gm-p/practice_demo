// Ex_SDIMouseView.cpp : implementation of the CEx_SDIMouseView class
//

#include "stdafx.h"
#include "Ex_SDIMouse.h"

#include "Ex_SDIMouseDoc.h"
#include "Ex_SDIMouseView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView

IMPLEMENT_DYNCREATE(CEx_SDIMouseView, CView)

BEGIN_MESSAGE_MAP(CEx_SDIMouseView, CView)
	//{{AFX_MSG_MAP(CEx_SDIMouseView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView construction/destruction

CEx_SDIMouseView::CEx_SDIMouseView()
{
	// TODO: add construction code here

}

CEx_SDIMouseView::~CEx_SDIMouseView()
{
}

BOOL CEx_SDIMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView drawing

void CEx_SDIMouseView::OnDraw(CDC* pDC)
{
	CEx_SDIMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView printing

BOOL CEx_SDIMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_SDIMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_SDIMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView diagnostics

#ifdef _DEBUG
void CEx_SDIMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIMouseDoc* CEx_SDIMouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIMouseDoc)));
	return (CEx_SDIMouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseView message handlers

void CEx_SDIMouseView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus=&pFrame->m_wndStatusBar;
	if(pStatus)
	{
		pStatus->SetPaneStyle(1,SBPS_POPOUT);
		str.Format("X=%d,Y=%d",point.x,point.y);
		pStatus->SetPaneText(1,str);
	}
	CView::OnMouseMove(nFlags, point);
}
