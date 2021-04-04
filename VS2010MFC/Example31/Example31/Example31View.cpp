
// Example31View.cpp : CExample31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExample31View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExample31View 构造/析构

CExample31View::CExample31View()
{
	// TODO: 在此处添加构造代码

}

CExample31View::~CExample31View()
{
}

BOOL CExample31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExample31View 绘制

void CExample31View::OnDraw(CDC* /*pDC*/)
{
	CExample31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExample31View 打印


void CExample31View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExample31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExample31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExample31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CExample31View 诊断

#ifdef _DEBUG
void CExample31View::AssertValid() const
{
	CView::AssertValid();
}

void CExample31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample31Doc* CExample31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample31Doc)));
	return (CExample31Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample31View 消息处理程序


void CExample31View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	CMenu menu;     //菜单（包括主菜单栏和子菜单）
	CMenu* pSubMenu;   //右键菜单

	//加载菜单资源到menu对象
	menu.LoadMenuW(IDR_POPUP_EDIT);
	//因为右键菜单是弹出式菜单，不包括主菜单栏，所以取子菜单
	pSubMenu=menu.GetSubMenu(0);
	//将坐标值由客户坐标转换为屏幕坐标
	ClientToScreen(&point);
	//弹出右键菜单，菜单左侧与point.x坐标值对齐
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);


	CView::OnRButtonDown(nFlags, point);
}
