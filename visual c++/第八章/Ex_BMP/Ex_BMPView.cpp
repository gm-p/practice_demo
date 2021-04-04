// Ex_BMPView.cpp : implementation of the CEx_BMPView class
//

#include "stdafx.h"
#include "Ex_BMP.h"

#include "Ex_BMPDoc.h"
#include "Ex_BMPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView

IMPLEMENT_DYNCREATE(CEx_BMPView, CView)

BEGIN_MESSAGE_MAP(CEx_BMPView, CView)
	//{{AFX_MSG_MAP(CEx_BMPView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView construction/destruction

CEx_BMPView::CEx_BMPView()
{
	// TODO: add construction code here

}

CEx_BMPView::~CEx_BMPView()
{
}

BOOL CEx_BMPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView drawing

void CEx_BMPView::OnDraw(CDC* pDC)
{
	CEx_BMPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBitmap m_bmp;
	m_bmp.LoadBitmap(IDB_BITMAP1);
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm);
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CBitmap *pOldbmp=dcMem.SelectObject(&m_bmp);
	pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(pOldbmp);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView printing

BOOL CEx_BMPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_BMPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_BMPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView diagnostics

#ifdef _DEBUG
void CEx_BMPView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_BMPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_BMPDoc* CEx_BMPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_BMPDoc)));
	return (CEx_BMPDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_BMPView message handlers
