// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl1SDI.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog


CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputDlg)
	m_strName = _T("");
	m_strNO = _T("");
	m_fScore1 = 0.0f;
	m_fScore2 = 0.0f;
	m_fScore3 = 0.0f;
	//}}AFX_DATA_INIT
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_Control(pDX, IDC_SPIN_S3, m_spinScore3);
	DDX_Control(pDX, IDC_SPIN_S2, m_spinScore2);
	DDX_Control(pDX, IDC_SPIN_S1, m_spinScore1);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNO);
	DDV_MaxChars(pDX, m_strNO, 20);
	DDX_Text(pDX, IDC_EDIT_S1, m_fScore1);
	DDV_MinMaxFloat(pDX, m_fScore1, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_S2, m_fScore2);
	DDV_MinMaxFloat(pDX, m_fScore2, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_S3, m_fScore3);
	DDV_MinMaxFloat(pDX, m_fScore3, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_S1, OnDeltaposSpinS1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers

BOOL CInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_spinScore1.SetRange(0,100);
	m_spinScore2.SetRange(0,100);
	m_spinScore3.SetRange(0,100);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInputDlg::OnDeltaposSpinS1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_fScore1+=(float)pNMUpDown->iDelta*0.5f;
	if(m_fScore1<0.0)
		m_fScore1=0.0f;
	if(m_fScore1>100.0)
		m_fScore1=100.0f;
	UpdateData(FALSE);

	*pResult = 0;
}
