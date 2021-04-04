// TextView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Form.h"
#include "TextView.h"
#include "Ex_FormDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CFormView)

CTextView::CTextView()
	: CFormView(CTextView::IDD)
{
	//{{AFX_DATA_INIT(CTextView)
	m_strText = _T("");
	//}}AFX_DATA_INIT
}

CTextView::~CTextView()
{
}

void CTextView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextView)
	DDX_Text(pDX, IDC_EDIT1, m_strText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextView, CFormView)
	//{{AFX_MSG_MAP(CTextView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers

void CTextView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CEx_FormDoc *pDoc=(CEx_FormDoc*)GetDocument();
	m_strText=pDoc->m_strContent;
	UpdateData(FALSE);
	
}

void CTextView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CWnd *pWnd=GetDlgItem(IDC_EDIT1);
	if(pWnd)
		pWnd->SetWindowPos(NULL,0,0,cx,cy,SWP_NOZORDER);
}
