
// MearBookDlg.cpp : ʵ���ļ�
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


// CMearBookDlg �Ի���




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


// CMearBookDlg ��Ϣ�������

BOOL CMearBookDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMearBookDlg::OnPaint()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mat = imread("C:/Users/asus/Desktop/173.jpg");
	if(!mat.data) 
	{
		MessageBox("��ȡ�ļ�ʧ�ܣ�����Ŀ¼���Ƿ���ڸ��ļ���", MB_OK);
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
