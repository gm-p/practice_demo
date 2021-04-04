// Ex_TimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Time.h"
#include "Ex_TimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TimeDlg dialog

CEx_TimeDlg::CEx_TimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_TimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_TimeDlg)
	m_strData = _T("");
	m_bTime = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_TimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_TimeDlg)
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_dtCtrl);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_mnCtrl);
	DDX_Text(pDX, IDC_DATA, m_strData);
	DDX_Check(pDX, IDC_CHECK1, m_bTime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_TimeDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_TimeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_WM_TIMER()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, OnSelchangeMonthcalendar1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TimeDlg message handlers

BOOL CEx_TimeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_TimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEx_TimeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEx_TimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_TimeDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_bTime)
	{
		m_dtCtrl.ModifyStyle(DTS_SHORTDATEFORMAT,DTS_TIMEFORMAT);
		SetTimer(1,200,NULL);
	}
	else
	{
		m_dtCtrl.ModifyStyle(DTS_TIMEFORMAT,DTS_SHORTDATEFORMAT);
		KillTimer(1);
	}
}

void CEx_TimeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if((1==nIDEvent)&&(m_bTime))
	{
		CTime curTime=CTime::GetCurrentTime();
		m_dtCtrl.SetTime(&curTime);
	}
	CDialog::OnTimer(nIDEvent);
}

void CEx_TimeDlg::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(!m_bTime)
	{
		COleDateTime m_data;
		m_dtCtrl.GetTime(m_data);
		m_mnCtrl.SetCurSel(m_data);
	}
	*pResult = 0;
}

void CEx_TimeDlg::OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CTime m_date;
	if(m_mnCtrl.GetCurSel(m_date))
	{
		m_date=CTime(((NMSELCHANGE*)pNMHDR)->stSelStart);
		if(!m_bTime)
			m_dtCtrl.SetTime(&m_date);
		m_strData=m_date.Format("%A,%B %d,%Y");
		UpdateData(FALSE);
	}
	*pResult = 0;
}
