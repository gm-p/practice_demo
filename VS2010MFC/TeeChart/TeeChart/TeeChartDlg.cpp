
// TeeChartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TeeChart.h"
#include "TeeChartDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTeeChartDlg �Ի���




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


// CTeeChartDlg ��Ϣ�������

BOOL CTeeChartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTeeChartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTeeChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTeeChartDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_nPointNum <= 0)
	{
		MessageBox("���ݵ�������С��0");
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
		MessageBox("���ļ�ʧ��");
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
	str.Format("��ʱ��%d ms", dwTimeE);
	SetDlgItemText(IDC_STATIC4, str);
	//CDialogEx::OnOK();
}
