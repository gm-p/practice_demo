// Ex_TextView.cpp : implementation of the CEx_TextView class
//

#include "stdafx.h"
#include "Ex_Text.h"

#include "Ex_TextDoc.h"
#include "Ex_TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView

IMPLEMENT_DYNCREATE(CEx_TextView, CScrollView)

BEGIN_MESSAGE_MAP(CEx_TextView, CScrollView)
	//{{AFX_MSG_MAP(CEx_TextView)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView construction/destruction

CEx_TextView::CEx_TextView()
{
	// TODO: add construction code here
	memset(&m_lfText,0,sizeof(LOGFONT));
	m_lfText.lfHeight=-12;
	m_lfText.lfCharSet=GB2312_CHARSET;
	strcpy(m_lfText.lfFaceName,"ËÎÌו");
}

CEx_TextView::~CEx_TextView()
{
}

BOOL CEx_TextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView drawing

void CEx_TextView::OnDraw(CDC* pDC)
{
	CEx_TextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont cf;
	cf.CreateFontIndirect(&m_lfText);
	CFont *oldFont=pDC->SelectObject(&cf);
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int lineHeight=tm.tmHeight+tm.tmExternalLeading;
	int y=0;
	int tab=tm.tmAveCharWidth*4;
	int lineMaxWidth=0;
	CString str;
	CSize lineSize(0,0);
	for(int i=0;i<pDoc->m_strContents.GetSize();i++)
	{
		str=pDoc->m_strContents.GetAt(i);
		pDC->TabbedTextOut(0,y,str,1,&tab,0);
		str=str+"A";
		lineSize=pDC->GetTabbedTextExtent(str,1,&tab);
		if(lineMaxWidth<lineSize.cx)
			lineMaxWidth=lineSize.cx;
		y+=lineHeight;
	}
	pDC->SelectObject(oldFont);
	int nLines=pDoc->m_strContents.GetSize()+1;
	CSize sizeTotal;
	sizeTotal.cx=lineMaxWidth;
	sizeTotal.cy=lineHeight*nLines;
	SetScrollSizes(MM_TEXT,sizeTotal);
}

void CEx_TextView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView printing

BOOL CEx_TextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_TextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_TextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView diagnostics

#ifdef _DEBUG
void CEx_TextView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CEx_TextView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CEx_TextDoc* CEx_TextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_TextDoc)));
	return (CEx_TextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TextView message handlers

void CEx_TextView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CFontDialog dlg(&m_lfText);
	if(dlg.DoModal()==IDOK)
	{
		dlg.GetCurrentFont(&m_lfText);
		Invalidate();
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}
