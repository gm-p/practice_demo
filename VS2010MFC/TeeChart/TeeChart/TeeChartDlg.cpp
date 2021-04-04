
// TeeChartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TeeChart.h"
#include "TeeChartDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTeeChartDlg 对话框




CTeeChartDlg::CTeeChartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeeChartDlg::IDD, pParent)
	, m_nPointNum(4000)
	, m_c_arrayLength(2096)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTeeChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nPointNum);
}

BEGIN_MESSAGE_MAP(CTeeChartDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTeeChartDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeeChartDlg 消息处理程序

BOOL CTeeChartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rect;
	//m_HSChartCtrl.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_TAB)->GetWindowRect(rect);
	GetDlgItem(IDC_STATIC_TAB)->ShowWindow(SW_HIDE);
	ScreenToClient(rect);
	m_tab.Create(CMFCTabCtrl::STYLE_3D_ONENOTE, rect, this, 1, CMFCTabCtrl::LOCATION_TOP);
	m_tab.AutoSizeWindow(TRUE);

	m_HSChartCtrl.Create(&m_tab, rect, 2);
	CChartAxis* pAxis = NULL;

	pAxis = m_HSChartCtrl.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_HSChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(false);
	m_pLineSerie = m_HSChartCtrl.CreateLineSerie();
	UpdateData(FALSE);
	m_tab.AddTab(&m_HSChartCtrl, "HightSpeedCtrl");
	m_tab.SetActiveTab(0);
	m_tab.ShowWindow(SW_SHOWNORMAL);
	CRect TabBRect, TabTRect;
	m_tab.GetWindowRect(rect);
	ScreenToClient(rect);
	m_tab.GetTabArea(TabTRect, TabBRect);
	rect.top += TabTRect.Height();
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTeeChartDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTeeChartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTeeChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTeeChartDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_nPointNum <= 0)
	{
		MessageBox("数据点数不能小于0");
		return ;
	}
	DWORD dwTimeS, dwTimeE;
	CString str = "";
	unsigned i(0);
	/*double* pDataX = new double[m_nPointNum];
	double* pDataY = new double[m_nPointNum];
	for(i=0; i<(unsigned)m_nPointNum; i++)
	{
		pDataY[i] = 10 + i / 10000;
		pDataX[i] = i;
	}*/
	vector<double> pDataX, pDataZ;
	pDataX.reserve(1200);
	pDataZ.reserve(1200);
	FILE* fr = fopen("result.txt", "r"); //fopen("c:/users/asus/desktop/result3.txt", "r");
	if(fr == NULL)
	{
		MessageBox("打开文件失败");
		return ;
	}
	float x, y, z;
	while(fscanf(fr, "%f,\t%f,\t%f", &x, &y, &z) != EOF)
	{
		pDataX.push_back(x);
		pDataZ.push_back(z);
	}
	//str.Format("x=%f, z=%f", pDataX[0], pDataZ[0]);
	//MessageBox(str);
	fclose(fr);
	m_nPointNum = pDataX.size();

	dwTimeS = GetTickCount();
	m_pLineSerie->ClearSerie();
	m_pLineSerie->AddPoints(&pDataX.front(), &pDataZ.front(), m_nPointNum);  //(pDataX, pDataY, m_nPointNum);
	dwTimeE = GetTickCount();
	dwTimeE -= dwTimeS;
	/*if(pDataX)
	{
		delete[] pDataX;
	}
	if(pDataY)
	{
		delete[] pDataY;
	}*/
	str.Format("耗时：%d ms", dwTimeE);
	SetDlgItemText(IDC_STATIC4, str);
	//CDialogEx::OnOK();
}
