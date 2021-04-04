
// Example22Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example22.h"
#include "Example22Dlg.h"
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


// CExample22Dlg �Ի���




CExample22Dlg::CExample22Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample22Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample22Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
}

BEGIN_MESSAGE_MAP(CExample22Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PORTAL_RADIO, &CExample22Dlg::OnBnClickedPortalRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &CExample22Dlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDC__FORUM_RADIO, &CExample22Dlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDOK, &CExample22Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExample22Dlg ��Ϣ�������

BOOL CExample22Dlg::OnInitDialog()
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

	//Ĭ��ѡ�С��Ż�����ѡ��ť
	CheckDlgButton(IDC_PORTAL_RADIO,1);
	OnBnClickedPortalRadio();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample22Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExample22Dlg::OnPaint()
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
HCURSOR CExample22Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample22Dlg::OnBnClickedPortalRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���ѡ���ˡ��Ż�����ѡ��ť���򼤻ѡ�����ˡ��͡����ס�������ѡ����ò���ѡ��
	InitAllCheckBoxStatus();
	m_check2.EnableWindow(TRUE);
	m_check5.EnableWindow(TRUE);
}


void CExample22Dlg::OnBnClickedBlogRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ѡ���ˡ����͡���ѡ��ť���򼤻ѡ�򡰼����ס��͡��������͡�������ѡ����ò���ѡ��
	InitAllCheckBoxStatus();
	m_check1.EnableWindow(TRUE);
	m_check4.EnableWindow(TRUE);
}


void CExample22Dlg::OnBnClickedForumRadio()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ѡ���ˡ���̳����ѡ��ť���򼤻ѡ��������̳���͡��������̳��������ѡ����ò���ѡ��
	InitAllCheckBoxStatus();
	m_check3.EnableWindow(TRUE);
	m_check6.EnableWindow(TRUE);
}

//��ʼ�����и�ѡ���״̬����ȫ�����ã�ȫ����ѡ��
void CExample22Dlg::InitAllCheckBoxStatus(void)
{
	//ȫ������
	m_check1.EnableWindow(FALSE);
	m_check2.EnableWindow(FALSE);
	m_check3.EnableWindow(FALSE);
	m_check4.EnableWindow(FALSE);
	m_check5.EnableWindow(FALSE);
	m_check6.EnableWindow(FALSE);

	//ȫ����ѡ��
	m_check1.SetCheck(0);
	m_check2.SetCheck(0);
	m_check3.SetCheck(0);
	m_check4.SetCheck(0);
	m_check5.SetCheck(0);
	m_check6.SetCheck(0);
}


void CExample22Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strWebsiteSel;//ѡ�����վ

	//��ѡ�С������ס�����������ַ���
	if(m_check1.GetCheck()==1)
		strWebsiteSel+=_T("������");
	//��ѡ�С����ˡ�����������ַ���
	if(m_check2.GetCheck()==1)
		strWebsiteSel+=_T("����");
	//��ѡ�С�������̳������������ַ���
	if(m_check3.GetCheck()==1)
		strWebsiteSel+=_T("������̳");
	//��ѡ�С��������͡�����������ַ���
	if(m_check4.GetCheck()==1)
		strWebsiteSel+=_T("��������");
	//��ѡ�С����ס�����������ַ���
	if(m_check5.GetCheck()==1)
		strWebsiteSel+=_T("����");
	//��ѡ�С��������̳������������ַ���
	if(m_check6.GetCheck()==1)
		strWebsiteSel+=_T("�������̳");

	//������ַ�����ʾ�ڡ�ѡ�����վ����ı༭����
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT,strWebsiteSel);

	//CDialogEx::OnOK();Ϊ�˱���㡰ȷ������Ի����˳�����OnOKע��

}
