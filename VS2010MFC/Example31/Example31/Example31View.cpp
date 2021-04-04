
// Example31View.cpp : CExample31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Example31.h"
#endif

#include "Example31Doc.h"
#include "Example31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample31View

IMPLEMENT_DYNCREATE(CExample31View, CView)

BEGIN_MESSAGE_MAP(CExample31View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExample31View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExample31View ����/����

CExample31View::CExample31View()
{
	// TODO: �ڴ˴���ӹ������

}

CExample31View::~CExample31View()
{
}

BOOL CExample31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExample31View ����

void CExample31View::OnDraw(CDC* /*pDC*/)
{
	CExample31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExample31View ��ӡ


void CExample31View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExample31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExample31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExample31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CExample31View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	/*
	ClientToScreen(&point);
	OnContextMenu(this, point);
	*/
}

void CExample31View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExample31View ���

#ifdef _DEBUG
void CExample31View::AssertValid() const
{
	CView::AssertValid();
}

void CExample31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample31Doc* CExample31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample31Doc)));
	return (CExample31Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample31View ��Ϣ�������


void CExample31View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	CMenu menu;     //�˵����������˵������Ӳ˵���
	CMenu* pSubMenu;   //�Ҽ��˵�

	//���ز˵���Դ��menu����
	menu.LoadMenuW(IDR_POPUP_EDIT);
	//��Ϊ�Ҽ��˵��ǵ���ʽ�˵������������˵���������ȡ�Ӳ˵�
	pSubMenu=menu.GetSubMenu(0);
	//������ֵ�ɿͻ�����ת��Ϊ��Ļ����
	ClientToScreen(&point);
	//�����Ҽ��˵����˵������point.x����ֵ����
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);


	CView::OnRButtonDown(nFlags, point);
}
