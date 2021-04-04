
// Example36Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example36.h"
#include "Example36Dlg.h"
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


// CExample36Dlg �Ի���




CExample36Dlg::CExample36Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample36Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample36Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLOR_SHOW_STATIC, m_picColor);
}

BEGIN_MESSAGE_MAP(CExample36Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COLOR_SEL_BUTTON, &CExample36Dlg::OnBnClickedColorSelButton)
END_MESSAGE_MAP()


// CExample36Dlg ��Ϣ�������

BOOL CExample36Dlg::OnInitDialog()
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

void CExample36Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExample36Dlg::OnPaint()
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
HCURSOR CExample36Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample36Dlg::OnBnClickedColorSelButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	COLORREF color=RGB(255,0,0);	//��ɫ�Ի���ĳ�ʼ��ɫ
	CColorDialog colorDlg(color);	//������ɫ�Ի��򣬳�ʼ��ɫΪ��ɫ
	CRect rectPicture;				//ͼƬ�ؼ��ľ�����������
	CBrush newBrush;				//�������»�ˢ
	CBrush* pOldBrush;				//�ɻ�ˢ��ָ��
	CClientDC clientDC(this);		//����ͻ������豸�����Ķ���

	if(colorDlg.DoModal()==IDOK)	//��ʾ��ɫ�Ի���
	{
	   //����������ɫ�Ի���ġ�ȷ������ť����ִ��һ�²���

		//��ȡ��ɫ�Ի�����ѡ�����ɫ
		color=colorDlg.GetColor();
		//��ѡ�����ɫ�����»�ˢ
		newBrush.CreateSolidBrush(color);
		//��ȡͼƬ�ؼ������������Ļ����
		m_picColor.GetWindowRect(&rectPicture);
		//��ͼƬ�ؼ������������Ļ���껻Ϊ�丸���ڼ��Ի���Ŀͻ�������
		ScreenToClient(&rectPicture);

		//ѡ���»�ˢ��������ɻ�ˢ��ָ�뵽pOldBrush
		pOldBrush=clientDC.SelectObject(&newBrush);
		//���»�ˢΪͼƬ�ؼ������ɫ
		clientDC.Rectangle(rectPicture);

		//�ָ��ɻ�ˢ
		clientDC.SelectObject(pOldBrush);
		//ɾ���»�ˢ
		newBrush.DeleteObject();
	}
}
