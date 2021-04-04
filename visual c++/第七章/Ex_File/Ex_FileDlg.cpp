// Ex_FileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_File.h"
#include "Ex_FileDlg.h"

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
// CEx_FileDlg dialog

CEx_FileDlg::CEx_FileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_FileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_FileDlg)
	m_strTitle = _T("");
	m_strContent = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_FileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_FileDlg)
	DDX_Text(pDX, IDC_STATIC_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT1, m_strContent);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_FileDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_FileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_FileDlg message handlers

BOOL CEx_FileDlg::OnInitDialog()
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

void CEx_FileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_FileDlg::OnPaint() 
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
HCURSOR CEx_FileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_FileDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	CString filter;
	filter="文本文件(*.txt)|*.txt|C++文件(*.h,*.cpp)|*.h;*.cpp||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	if(dlg.DoModal()!=IDOK) 
		return;
	CString strFileName=dlg.GetPathName();
	CFileStatus status;
	if(!CFile::GetStatus(strFileName,status))
	{
		MessageBox("此文件不存在！");
		return;
	}
	m_strTitle.Format("%s[%s,%ld字节]",strFileName,status.m_ctime.Format("%Y-%m-%d"),status.m_size);
	UpdateData(FALSE);
	m_strContent.Empty();
	CFile theFile;
	if(!theFile.Open(strFileName,CFile::modeRead))
	{
		MessageBox("该文件无法打开！");
		return;
	}
	char szBuffer[80];
	UINT nActual=0;
	while(nActual=theFile.Read(szBuffer,sizeof(szBuffer)))
	{
		CString str(szBuffer,nActual);
		m_strContent=m_strContent+str;
	}
	theFile.Close();
	UpdateData(FALSE);
}
