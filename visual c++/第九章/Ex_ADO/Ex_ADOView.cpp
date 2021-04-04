// Ex_ADOView.cpp : implementation of the CEx_ADOView class
//

#include "stdafx.h"
#include "Ex_ADO.h"

#include "Ex_ADODoc.h"
#include "Ex_ADOView.h"
#include "StuInfoDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView

IMPLEMENT_DYNCREATE(CEx_ADOView, CListView)

BEGIN_MESSAGE_MAP(CEx_ADOView, CListView)
	//{{AFX_MSG_MAP(CEx_ADOView)
	ON_WM_DESTROY()
	//ON_COMMAND(ID_VIEW_COURSE, OnViewCourse)
	ON_COMMAND(ID_OP_ADD,OnOpAdd)
	ON_COMMAND(ID_OP_CHA,OnOpCha)
	ON_COMMAND(ID_OP_DEL,OnOpDel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView construction/destruction

CEx_ADOView::CEx_ADOView()
{
	// TODO: add construction code here
	/*try
	{
	m_pConnection->Open("Provider=SQLOLEDB;Data Source=asus-PC;Initial Catalog=C:\\Users\\asus\\Desktop\\visual c++\\Student.mdf;","sa","123456",0);
	MessageBox("连接数据库成功!");
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
		return;
	}*/
}

CEx_ADOView::~CEx_ADOView()
{
}

BOOL CEx_ADOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style|=LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView drawing

void CEx_ADOView::OnDraw(CDC* pDC)
{
	CEx_ADODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_ADOView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号","课程号", "成绩","学分"};
	int nLong[] = {80, 80, 60, 100, 180};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_CENTER,nLong[nCol]);


	::CoInitialize(NULL); // COM环境初始化
	m_pConnection.CreateInstance(__uuidof(Connection)); //初始化Connection指针
	m_pRecordset.CreateInstance(__uuidof(Recordset));	//初始化Recordset指针
	// 连接数据源为“Database Example For VC++”
	//m_pConnection->Open("DSN=Database Example For VC++","","",0);
	CString strSRC="Provider=SQLOLEDB;Data Source=127.0.0.1;Initial Catalog=Student;";
	_bstr_t bstrSRC(strSRC);
	try
	{
	m_pConnection->Open("Provider=SQLOLEDB;Data Source=asus-PC;Initial Catalog=Student"/*bstrSRC*/,"sa","123456",-1);
	MessageBox("连接数据库成功!");
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
		return;
	}	//ResetListItem();
	OnViewCourse();

}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView printing

BOOL CEx_ADOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ADOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ADOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView diagnostics

#ifdef _DEBUG
void CEx_ADOView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_ADOView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_ADODoc* CEx_ADOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ADODoc)));
	return (CEx_ADODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView message handlers

void CEx_ADOView::OnDestroy() 
{
	CListView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(m_pConnection)
		m_pConnection->Close();
}

void CEx_ADOView::OnViewCourse() 
{
	// TODO: Add your command handler code here
	CListCtrl &m_ListCtrl=GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	int nColumnCount=m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	for(int i=0;i<nColumnCount;i++)
		m_ListCtrl.DeleteColumn(0);
	//	m_pRecordset->Open("score",m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdTable);
	m_pRecordset->Open("SELECT * FROM score where score>75 and credit>2.5",m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	FieldsPtr flds=m_pRecordset->GetFields();
	_variant_t Index;
	Index.vt=VT_I2;
	m_ListCtrl.InsertColumn(0,"序号",LVCFMT_LEFT,60);
	for(i=0;i<(int)flds->GetCount();i++)
	{
		Index.iVal=i;
		m_ListCtrl.InsertColumn(i+1,(LPSTR)flds->GetItem(Index)->GetName(),LVCFMT_LEFT,140);
	}
	_bstr_t str,value;
	int nItem=0;
	CString strItem;
	while(!m_pRecordset->adoEOF)
	{
		strItem.Format("%d",nItem+1);
		m_ListCtrl.InsertItem(nItem,strItem);
		for(i=0;i<(int)flds->GetCount();i++)
		{
			Index.iVal=i;
			str=flds->GetItem(Index)->GetName();
			value=m_pRecordset->GetCollect(str);
			m_ListCtrl.SetItemText(nItem,i+1,(LPCSTR)value);
		}
		m_pRecordset->MoveNext();
		nItem++;
	}
	m_pRecordset->Close();
}

void CEx_ADOView::OnOpAdd()
{
	CStuInfoDlg dlg;
	if(IDOK!=dlg.DoModal())
		return;
	CString strSql="select * from score";
	BSTR bstrSQL=strSql.AllocSysString();
	m_pRecordset->Open(bstrSQL,(IDispatch*)m_pConnection,adOpenDynamic,adLockOptimistic,adCmdText);
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect("studentno",_variant_t(dlg.m_strno));
	m_pRecordset->PutCollect("course",_variant_t(dlg.m_strCno));
	m_pRecordset->PutCollect("score",_variant_t(dlg.m_score));
	m_pRecordset->PutCollect("credit",_variant_t(dlg.m_credit));
	m_pRecordset->Update();
	m_pRecordset->Close();
	OnViewCourse();
}

void CEx_ADOView::OnOpCha()
{
	CListCtrl &m_ListCtrl=GetListCtrl();
	POSITION pos;
	pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		MessageBox("你没有选中列表项！");
		return;
	}
	int nItem=m_ListCtrl.GetNextSelectedItem(pos);
	CString sno,cno;
	sno=m_ListCtrl.GetItemText(nItem,1);
	cno=m_ListCtrl.GetItemText(nItem,2);
	CString strSql;
	strSql.Format("select * from score where studentno='%s' and course='%s'",sno,cno);
	BSTR bstrSQL=strSql.AllocSysString();
	m_pRecordset->Open(bstrSQL,(IDispatch*)m_pConnection,adOpenDynamic,adLockOptimistic,adCmdText);
	CStuInfoDlg dlg;
	dlg.m_strno=sno;
	_variant_t value;
	value=m_pRecordset->GetCollect("studentno");
	dlg.m_strno.Format("%s",(char*)_bstr_t(value));
	value=m_pRecordset->GetCollect("course");
	dlg.m_strCno.Format("%s",(char*)_bstr_t(value));
	value=m_pRecordset->GetCollect("score");
	dlg.m_score=value;
	value=m_pRecordset->GetCollect("credit");
	dlg.m_credit=value;
	if(IDOK!=dlg.DoModal())
		return;

	m_pRecordset->PutCollect("studentno",_variant_t(dlg.m_strno));
	m_pRecordset->PutCollect("course",_variant_t(dlg.m_strCno));
	m_pRecordset->PutCollect("score",_variant_t(dlg.m_score));
	m_pRecordset->PutCollect("credit",_variant_t(dlg.m_credit));
	m_pRecordset->Update();//使修改有效
	m_pRecordset->Close();
	OnViewCourse();
}

void CEx_ADOView::OnOpDel()
{
	CListCtrl &m_ListCtrl=GetListCtrl();
	POSITION pos;
	pos=m_ListCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem=m_ListCtrl.GetNextSelectedItem(pos);
	CString sno,cno;
	sno=m_ListCtrl.GetItemText(nItem,1);
	cno=m_ListCtrl.GetItemText(nItem,2);
	CString str;
	str.Format("你确实要删除学号:%s,课程号:%S列表项（记录）吗？",sno,cno);
	if(IDOK!=MessageBox(str,"删除确认",MB_ICONQUESTION|MB_OKCANCEL))
		return;
	_CommandPtr pCmd;
	pCmd.CreateInstance(__uuidof(Command));
	pCmd->ActiveConnection=m_pConnection;
	CString strComm;
	strComm.Format("delete from score where studentno='%s' and course='%s'",sno,cno);
	pCmd->CommandText=strComm.AllocSysString();
	pCmd->Execute(NULL,NULL,adCmdText);
	OnViewCourse();
}
