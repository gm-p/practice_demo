// InputDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "InputDlg1.h"

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
	m_strID = _T("");
	m_fScore1 = 0.0f;
	m_fScore2 = 0.0f;
	m_fScore3 = 0.0f;
	//}}AFX_DATA_INIT
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT2, m_strID);
	DDV_MaxChars(pDX, m_strID, 20);
	DDX_Text(pDX, IDC_EDIT3, m_fScore1);
	DDV_MinMaxFloat(pDX, m_fScore1, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT4, m_fScore2);
	DDX_Text(pDX, IDC_EDIT5, m_fScore3);
	DDV_MinMaxFloat(pDX, m_fScore3, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers
