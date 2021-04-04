
// MearBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MearBook.h"
#include "MearBookDlg.h"
#include "afxdialogex.h"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

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


// CMearBookDlg 对话框




CMearBookDlg::CMearBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMearBookDlg::IDD, pParent)
	, width(0)
	, height(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMearBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_edcWidth, width);
	DDX_Text(pDX, IDC_edcHeight, height);
}

BEGIN_MESSAGE_MAP(CMearBookDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_btMeasure, &CMearBookDlg::OnBnClickedbtmeasure)
END_MESSAGE_MAP()


// CMearBookDlg 消息处理程序

BOOL CMearBookDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMearBookDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMearBookDlg::OnPaint()
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
HCURSOR CMearBookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMearBookDlg::DrawPicToHDC(Mat& mat, UINT ID)
{
	CDC* pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	IplImage img = mat;
	CvvImage cimg;
	cimg.CopyOf(&img);
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	cimg.DrawToHDC(hDC, &rect);

	ReleaseDC(pDC);
	cimg.Destroy();
}


void CMearBookDlg::OnBnClickedbtmeasure()
{
	// TODO: 在此添加控件通知处理程序代码
	mat = imread("C:/Users/asus/Desktop/173.jpg");
	if(!mat.data) 
	{
		MessageBox("读取文件失败，请检查目录下是否存在该文件！", MB_OK);
		return ;
	}

	Mat  src,gray=Mat(Size(mat.rows, mat.cols), CV_8UC3), dst=Mat(Size(mat.rows, mat.cols), CV_8UC1);
	//src = mat.clone();
	cvtColor(mat, gray, CV_BGR2GRAY);
	threshold(gray, dst, 140, 255, THRESH_BINARY);

	Canny(dst, dst, 3, 9, 3);
	vector<vector<Point> > contours;
	findContours(dst, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	vector<Point> points = contours.at(0);
	int max = points.size();
	Rect maxRect = boundingRect(points);
	for(int i=1; i<contours.size(); i++)
	{
		points = contours.at(i);
		if(points.size() > max)
			maxRect = boundingRect(points);
	}
	width = maxRect.width;
	height = maxRect.height;
	UpdateData(FALSE);
	rectangle(mat, maxRect, Scalar(0, 0, 255), 3);
	DrawPicToHDC(mat, IDC_picBook);
	
}
