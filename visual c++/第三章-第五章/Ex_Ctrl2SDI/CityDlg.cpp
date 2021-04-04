// CityDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl2SDI.h"
#include "CityDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCityDlg dialog


CCityDlg::CCityDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCityDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCityDlg)
	m_strCity = _T("");
	m_dwZipCode = 0;
	//}}AFX_DATA_INIT
}


void CCityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCityDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Text(pDX, IDC_EDIT_CITY, m_strCity);
	DDV_MaxChars(pDX, m_strCity, 40);
	DDX_Text(pDX, IDC_EDIT_ZIP, m_dwZipCode);
	DDV_MinMaxDWord(pDX, m_dwZipCode, 100000, 999999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCityDlg, CDialog)
	//{{AFX_MSG_MAP(CCityDlg)
	ON_BN_CLICKED(IDC_BUTTON_AND, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCityDlg message handlers

BOOL CCityDlg::IsValidate()
{
	UpdateData();
	m_strCity.TrimLeft();
	if(m_strCity.IsEmpty())
	{
		MessageBox("城市名输入无效！");
		return FALSE;
	}
	return TRUE;

}

BOOL CCityDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dwZipCode=100000;
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON_DEL)->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCityDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	if(!IsValidate())  return;
	int nIndex=m_ListBox.FindStringExact(-1,m_strCity);
	if(nIndex!=LB_ERR)
	{
		MessageBox("该城市已添加！");
		return;
	}
	nIndex=m_ListBox.AddString(m_strCity);
	m_ListBox.SetItemData(nIndex,m_dwZipCode);
}

void CCityDlg::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_ListBox.GetCurSel();
	if(nIndex!=LB_ERR)
		m_ListBox.DeleteString(nIndex);
	else
		GetDlgItem(IDC_BUTTON_DEL)->EnableWindow(FALSE);
}

void CCityDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_ListBox.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		m_ListBox.GetText(nIndex,m_strCity);
		m_dwZipCode=m_ListBox.GetItemData(nIndex);
		UpdateData(FALSE);
		GetDlgItem(IDC_BUTTON_DEL)->EnableWindow(TRUE);
	}
}
