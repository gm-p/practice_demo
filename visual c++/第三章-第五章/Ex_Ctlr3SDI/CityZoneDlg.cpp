// CityZoneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctlr3SDI.h"
#include "CityZoneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCityZoneDlg dialog


CCityZoneDlg::CCityZoneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCityZoneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCityZoneDlg)
	m_strCity = _T("");
	m_strZone = _T("");
	m_strZip = _T("");
	//}}AFX_DATA_INIT
}


void CCityZoneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCityZoneDlg)
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_CBString(pDX, IDC_COMBO1, m_strCity);
	DDV_MaxChars(pDX, m_strCity, 20);
	DDX_Text(pDX, IDC_EDIT_ZONE, m_strZone);
	DDV_MaxChars(pDX, m_strZone, 10);
	DDX_Text(pDX, IDC_EDIT_ZIP, m_strZip);
	DDV_MaxChars(pDX, m_strZip, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCityZoneDlg, CDialog)
	//{{AFX_MSG_MAP(CCityZoneDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCityZoneDlg message handlers

BOOL CCityZoneDlg::IsValidate()
{
	UpdateData();
	m_strCity.TrimLeft();
	if(m_strCity.IsEmpty())
	{
		MessageBox("城市名输入无效！");
		return FALSE;
	}
	m_strZip.TrimLeft();
	if(m_strZip.IsEmpty())
	{
		MessageBox("邮政编码输入无效！");
		return FALSE;
	}
	m_strZone.TrimLeft();
	if(m_strZone.IsEmpty())
	{
		MessageBox("区号输入无效！");
		return FALSE;
	}
	return TRUE;
}

void CCityZoneDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	if(!IsValidate()) return;
	int nIndex=m_ComboBox.FindStringExact(-1,m_strCity);
	if(nIndex!=CB_ERR)
	{
		MessageBox("该城市已添加！");
		return;
	}
	nIndex=m_ComboBox.AddString(m_strCity);
	CString strData;
	strData.Format("%s,%s",m_strZip,m_strZone);
	m_ComboBox.SetItemDataPtr(nIndex,new CString(strData));
}

void CCityZoneDlg::OnButtonChange() 
{
	// TODO: Add your control notification handler code here
	if(!IsValidate())	return;
	int nIndex=m_ComboBox.FindStringExact(-1,m_strCity);
	if(nIndex!=CB_ERR)
	{
		delete (CString *)m_ComboBox.GetItemDataPtr(nIndex);
		CString strData;
		strData.Format("%s,%s",m_strZip,m_strZone);
		m_ComboBox.SetItemDataPtr(nIndex,new CString(strData));
	}
}

void CCityZoneDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_ComboBox.GetCurSel();
	if(nIndex!=CB_ERR)
	{
		m_ComboBox.GetLBText(nIndex,m_strCity);
		CString strData;
		strData=*(CString*)m_ComboBox.GetItemDataPtr(nIndex);
		int n=strData.Find(',');
		m_strZip=strData.Left(n);
		m_strZone=strData.Mid(n+1);
		UpdateData(FALSE);
	}
}

void CCityZoneDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	for(int nIndex=m_ComboBox.GetCount()-1;nIndex>=0;nIndex--)
		delete (CString*)m_ComboBox.GetItemDataPtr(nIndex);
}
