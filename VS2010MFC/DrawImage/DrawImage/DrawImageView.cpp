
// DrawImageView.cpp : CDrawImageView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DrawImage.h"
#endif

#include "DrawImageDoc.h"
#include "DrawImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawImageView

IMPLEMENT_DYNCREATE(CDrawImageView, CView)

BEGIN_MESSAGE_MAP(CDrawImageView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawImageView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawImageView ����/����

CDrawImageView::CDrawImageView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawImageView::~CDrawImageView()
{
}

BOOL CDrawImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawImageView ����

void CDrawImageView::OnDraw(CDC* pDC)
{
	CDrawImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if(!src.empty())
	{
		CRect rc;
		GetClientRect(&rc);  //src = imread("C:\\Users\\asus\\Desktop\\14296978024588.png");
		SetRect(rc, 0, 0, src.cols, src.rows);  
		IplImage img = src;
		CvvImage cimg;
		cimg.CopyOf(&img);
		cimg.DrawToHDC(pDC->GetSafeHdc(), rc);
	}
}


// CDrawImageView ��ӡ


void CDrawImageView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CDrawImageView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawImageView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawImageView ���

#ifdef _DEBUG
void CDrawImageView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawImageDoc* CDrawImageView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawImageDoc)));
	return (CDrawImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawImageView ��Ϣ�������
