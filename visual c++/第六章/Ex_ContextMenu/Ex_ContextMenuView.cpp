// Ex_ContextMenuView.cpp : implementation of the CEx_ContextMenuView class
//

#include "stdafx.h"
#include "Ex_ContextMenu.h"

#include "Ex_ContextMenuDoc.h"
#include "Ex_ContextMenuView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView

IMPLEMENT_DYNCREATE(CEx_ContextMenuView, CView)

BEGIN_MESSAGE_MAP(CEx_ContextMenuView, CView)
	//{{AFX_MSG_MAP(CEx_ContextMenuView)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView construction/destruction

CEx_ContextMenuView::CEx_ContextMenuView()
{
	// TODO: add construction code here

}

CEx_ContextMenuView::~CEx_ContextMenuView()
{
}

BOOL CEx_ContextMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView drawing

void CEx_ContextMenuView::OnDraw(CDC* pDC)
{
	CEx_ContextMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView printing

BOOL CEx_ContextMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ContextMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ContextMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView diagnostics

#ifdef _DEBUG
void CEx_ContextMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_ContextMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_ContextMenuDoc* CEx_ContextMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ContextMenuDoc)));
	return (CEx_ContextMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuView message handlers

void CEx_ContextMenuView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	CMenu *pSysMenu=pFrame->GetMenu();
	int nCount=pSysMenu->GetMenuItemCount();
	int nSubMenuPos=-1;
	for(int i=0;i<nCount;i++)
	{
		CString str;
		pSysMenu->GetMenuString(i,str,MF_BYPOSITION);
		if(str.Left(4)=="нд╪Ч")
		{
			nSubMenuPos=i;
			break;
		}
	}
	if(nSubMenuPos<0) 
		return;
	pSysMenu->GetSubMenu(nSubMenuPos)
		->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
}
