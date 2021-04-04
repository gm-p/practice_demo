// Ex_TreeView.cpp : implementation of the CEx_TreeView class
//

#include "stdafx.h"
#include "Ex_Tree.h"

#include "Ex_TreeDoc.h"
#include "Ex_TreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView

IMPLEMENT_DYNCREATE(CEx_TreeView, CTreeView)

BEGIN_MESSAGE_MAP(CEx_TreeView, CTreeView)
	//{{AFX_MSG_MAP(CEx_TreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView construction/destruction

CEx_TreeView::CEx_TreeView()
{
	// TODO: add construction code here

}

CEx_TreeView::~CEx_TreeView()
{
}

BOOL CEx_TreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style|=TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS;
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView drawing

void CEx_TreeView::OnDraw(CDC* pDC)
{
	CEx_TreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_TreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& treeCtrl=GetTreeCtrl();
	m_ImageList.Create(16,16,ILC_COLOR8|ILC_MASK,2,1);
	m_ImageList.SetBkColor(RGB(255,255,255));
	treeCtrl.SetImageList(&m_ImageList,TVSIL_NORMAL);
	CString strPath;
	GetWindowsDirectory((LPTSTR)(LPCTSTR)strPath,MAX_PATH+1);
	SHFILEINFO fi;
	SHGetFileInfo(strPath,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON);
	m_ImageList.Add(fi.hIcon);
	SHGetFileInfo(strPath,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_OPENICON);
	m_ImageList.Add(fi.hIcon);
	CString str;
	for(int i=0;i<32;i++)
	{
		str.Format("%c:\\",'A'+i);
		SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_DISPLAYNAME);
		if(fi.hIcon)
		{
			int nImage=m_ImageList.Add(fi.hIcon);
			HTREEITEM hItem=treeCtrl.InsertItem(fi.szDisplayName,nImage,nImage);
			treeCtrl.SetItemData(hItem,(DWORD)('A'+i));
		}
	}
	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView printing

BOOL CEx_TreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_TreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_TreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView diagnostics

#ifdef _DEBUG
void CEx_TreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CEx_TreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CEx_TreeDoc* CEx_TreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_TreeDoc)));
	return (CEx_TreeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeView message handlers

void CEx_TreeView::InsertFoldItem(HTREEITEM hItem, CString strPath)
{
	CTreeCtrl& treeCtrl=GetTreeCtrl();
	if(treeCtrl.ItemHasChildren(hItem))
		return;
	CFileFind finder;
	BOOL bWorking=finder.FindFile(strPath);
	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(finder.IsDirectory()&&!finder.IsHidden()&&!finder.IsDots())
			treeCtrl.InsertItem(finder.GetFileTitle(),0,1,hItem,TVI_SORT);
	}
}

CString CEx_TreeView::GetFoldItemPath(HTREEITEM hItem)
{
	CString strPath,str;
	strPath.Empty();
	CTreeCtrl& treeCtrl=GetTreeCtrl();
	HTREEITEM folderItem=hItem;
	while(folderItem)
	{
		int data=(int)treeCtrl.GetItemData(folderItem);
		if(data==0)
			str=treeCtrl.GetItemText(folderItem);
		else
			str.Format("%c:\\",data);
		strPath=str+"\\"+strPath;
		folderItem=treeCtrl.GetParentItem(folderItem);
	}
	strPath=strPath+"*.*";
	return strPath;
}

void CEx_TreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hSelItem=pNMTreeView->itemNew.hItem;
	CTreeCtrl& treeCtrl=GetTreeCtrl();
	CString strPath=GetFoldItemPath(hSelItem);
	if(!strPath.IsEmpty())
	{
		InsertFoldItem(hSelItem,strPath);
		treeCtrl.Expand(hSelItem,TVE_EXPAND);
	}
	*pResult = 0;
}
