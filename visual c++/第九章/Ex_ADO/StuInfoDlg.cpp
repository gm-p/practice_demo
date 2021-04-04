// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_ADO.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog


CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuInfoDlg)
	m_strno = _T("");
	m_strCno = _T("");
	m_score = 0.0f;
	m_credit = 0.0f;
	//}}AFX_DATA_INIT
}


void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Text(pDX, IDC_EDIT_Sno, m_strno);
	DDX_Text(pDX, IDC_EDIT_Cno, m_strCno);
	DDX_Text(pDX, IDC_EDIT_Score, m_score);
	DDV_MinMaxFloat(pDX, m_score, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_Credit, m_credit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

void CStuInfoDlg::OnOK() 
{
	// TODO: Add extra validation here	UpdateData();
	/*m_strno.TrimLeft();
	m_strCno.TrimLeft();
	if(m_strno.IsEmpty())
		MessageBox("必须要有学号！");
	else if(m_strCno.IsEmpty())
		MessageBox("必须要有课程号！");
	else*/
		CDialog::OnOK();
}
