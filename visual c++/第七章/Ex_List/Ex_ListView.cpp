// Ex_ListView.cpp : implementation of the CEx_ListView class
//

#include "stdafx.h"
#include "Ex_List.h"

#include "Ex_ListDoc.h"
#include "Ex_ListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView

IMPLEMENT_DYNCREATE(CEx_ListView, CListView)

BEGIN_MESSAGE_MAP(CEx_ListView, CListView)
	//{{AFX_MSG_MAP(CEx_ListView)
	ON_COMMAND(ID_VIEW_CHANGE, OnViewChange)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView construction/destruction

CEx_ListView::CEx_ListView()
{
	// TODO: add construction code here

}

CEx_ListView::~CEx_ListView()
{
}

BOOL CEx_ListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView drawing

void CEx_ListView::OnDraw(CDC* pDC)
{
	CEx_ListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_ListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	m_ImageList.Create(32,32,ILC_COLOR8|ILC_MASK,1,1);
	m_ImageListSmall.Create(16,16,ILC_COLOR8|ILC_MASK,1,1);
	CListCtrl& m_ListCtrl=GetListCtrl();
	m_ListCtrl.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_ListCtrl.SetImageList(&m_ImageListSmall,LVSIL_SMALL);
	LV_COLUMN listCol;
	char *arCols[4]={"文件名","大小","类型","修改日期"};
	listCol.mask=LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	for(int nCol=0;nCol<4;nCol++)
	{
		listCol.iSubItem=nCol;
		listCol.pszText=arCols[nCol];
		if(nCol==1)
			listCol.fmt=LVCFMT_RIGHT;
		else
			listCol.fmt=LVCFMT_LEFT;
		m_ListCtrl.InsertColumn(nCol,&listCol);
	}
	CFileFind finder;
	BOOL bWorking=finder.FindFile("*.*");
	int nItem=0,nIndex,nImage;
	CTime m_time;
	CString str,strTypeName;
	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(finder.IsArchived())
		{
			str=finder.GetFilePath();
			SHFILEINFO fi;
			SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_LARGEICON|SHGFI_TYPENAME);
			strTypeName=fi.szTypeName;
			nImage=-1;
			for(int i=0;i<m_strArray.GetSize();i++)
			{
				if(m_strArray[i]==strTypeName)
				{
					nImage=i;
					break;
				}
			}
			if(nImage<0)
			{
				nImage=m_ImageList.Add(fi.hIcon);
				SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON);
				m_ImageListSmall.Add(fi.hIcon);
				m_strArray.Add(strTypeName);
			}
			nIndex=m_ListCtrl.InsertItem(nItem,finder.GetFileName(),nImage);
			DWORD dwSize=finder.GetLength();
			if(dwSize>1024)
				str.Format("%dK",dwSize/1024);
			else
				str.Format("%d",dwSize);
			m_ListCtrl.SetItemText(nIndex,1,str);
			m_ListCtrl.SetItemText(nIndex,2,strTypeName);
			finder.GetLastWriteTime(m_time);
			m_ListCtrl.SetItemText(nIndex,3,m_time.Format("%Y-%m-%d"));
			nItem++;
		}
	}
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),LVS_REPORT);
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ListCtrl.SetColumnWidth(0,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(1,100);
	m_ListCtrl.SetColumnWidth(2,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(3,200);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView printing

BOOL CEx_ListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView diagnostics

#ifdef _DEBUG
void CEx_ListView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_ListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_ListDoc* CEx_ListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ListDoc)));
	return (CEx_ListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ListView message handlers

void CEx_ListView::OnViewChange() 
{
	// TODO: Add your command handler code here
	static int nStyleIndex=1;
	DWORD style[4]={LVS_REPORT,LVS_ICON,LVS_SMALLICON,LVS_LIST};
	CListCtrl& m_ListCtrl=GetListCtrl();
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),style[nStyleIndex]);
	nStyleIndex++;
	if(nStyleIndex>3)
		nStyleIndex=0;
}

void CEx_ListView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMITEMACTIVATE lpItem=(LPNMITEMACTIVATE)pNMHDR;
	int nIndex=lpItem->iItem;
	if(nIndex>=0)
	{
		CListCtrl& m_ListCtrl=GetListCtrl();
		CString str=m_ListCtrl.GetItemText(nIndex,0);
		MessageBox(str);
	}
	*pResult = 0;
}
