// ProgressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl4SDI.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
	m_strPercent = _T("");
	//}}AFX_DATA_INIT
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Text(pDX, IDC_STATIC_TEXT, m_strPercent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_GOON, OnButtonGoon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

void CProgressDlg::UpdatePercentText()
{
	int nPos=m_Progress.GetPos();
	int nLow,nUp;
	m_Progress.GetRange(nLow,nUp);
	m_strPercent.Format("%4.0f%%",(float)nPos/(float)(nUp-nLow)*100.0);
	UpdateData(FALSE);
}

BOOL CProgressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Progress.SetRange(0,100);
	m_Progress.SetStep(5);
	m_Progress.SetPos(30);
	UpdatePercentText();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProgressDlg::OnButtonBack() 
{
	// TODO: Add your control notification handler code here
	int nPos=m_Progress.GetPos();
	int nLow,nUp;
	m_Progress.GetRange(nLow,nUp);
	nPos=nPos-5;
	if(nPos<nLow)
		nPos=nLow;
	m_Progress.SetPos(nPos);
	UpdatePercentText();
}

void CProgressDlg::OnButtonGoon() 
{
	// TODO: Add your control notification handler code here
	m_Progress.StepIt();
	UpdatePercentText();
}
