// DrawView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Rect.h"
#include "DrawView.h"
#include "Ex_RectDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

CDrawView::CDrawView()
{
}

CDrawView::~CDrawView()
{
}


BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	CRect rc(m_ptDraw.x-5,m_ptDraw.y-5,m_ptDraw.x+5,m_ptDraw.y+5);
	pDC->Rectangle(rc);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CEx_RectDoc* pDoc=(CEx_RectDoc*)m_pDocument;
	m_ptDraw=pDoc->m_ptRect;
}

void CDrawView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(lHint==2)
	{
		CPoint *pPoint=(CPoint*)pHint;
		m_ptDraw=*pPoint;
		Invalidate();
	}
	
}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptDraw=point;
	GetDocument()->UpdateAllViews(NULL,1,(CObject*)&m_ptDraw);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
