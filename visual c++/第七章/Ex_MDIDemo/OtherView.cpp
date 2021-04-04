// OtherView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_MDIDemo.h"
#include "OtherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COtherView

IMPLEMENT_DYNCREATE(COtherView, CView)

COtherView::COtherView()
{
}

COtherView::~COtherView()
{
}


BEGIN_MESSAGE_MAP(COtherView, CView)
	//{{AFX_MSG_MAP(COtherView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COtherView drawing

void COtherView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// COtherView diagnostics

#ifdef _DEBUG
void COtherView::AssertValid() const
{
	CView::AssertValid();
}

void COtherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COtherView message handlers
