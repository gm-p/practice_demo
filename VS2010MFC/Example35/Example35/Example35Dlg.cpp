
// Example35Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example35.h"
#include "Example35Dlg.h"
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


// CExample35Dlg �Ի���




CExample35Dlg::CExample35Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample35Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


	//������m_nzValues��Ԫ�ض���ʼ��Ϊ0
	memset(m_nzValues,0,sizeof(int)*POINT_COUNT);
}

void CExample35Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WAVE_DRAW, m_picDraw);
}

BEGIN_MESSAGE_MAP(CExample35Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CExample35Dlg ��Ϣ�������

BOOL CExample35Dlg::OnInitDialog()
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

	//��ʱ��Ϊ���������������������
	srand((unsigned)time(NULL));
	//������ʱ����IDΪ1����ʱʱ��Ϊ200ms
	SetTimer(1,200,NULL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample35Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExample35Dlg::OnPaint()
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
HCURSOR CExample35Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample35Dlg::DrawWave(CDC* pDC, CRect& rectPicture)
{

	float fDeltaX;   //x������������ͼ����������
	float fDeltaY;	 //y��ÿ���߼���λ��Ӧ������ֵ
	int nX;			 //������ʱ���ڴ洢��ͼ��ĺ�����
	int nY;			 //������ʱ���ڴ洢��ͼ���������
	CPen newPen;	 //���ڴ����»���
	CPen* pOldPen;   //���ڴ�žɻ���
	CBrush newBrush; //���ڴ����»�ˢ
	CBrush* pOldBrush;//���ڴ�žɻ�ˢ

	//����fDeltaX��fDeltaY
	fDeltaX=(float)rectPicture.Width()/(POINT_COUNT-1);
	fDeltaY=(float)rectPicture.Height()/80;

	//������ɫ�»�ˢ
	newBrush.CreateSolidBrush(RGB(0,0,0));
	//ѡ���»�ˢ�������ɻ�ˢ��ָ�뱣�浽pOldBrush
	pOldBrush=pDC->SelectObject(&newBrush);
	//�Ժ�ɫ��ˢΪ��ͼ�ؼ�����ɫ���γɺ�ɫ����
	pDC->Rectangle(rectPicture);
	//�ָ��ɻ�ˢ
	pDC->SelectObject(pOldBrush);
	//ɾ���»�ˢ
	newBrush.DeleteObject();

	//����ʵ�Ļ��ʣ��ֶ�Ϊ1����ɫΪ��ɫ
	newPen.CreatePen(PS_SOLID,1,RGB(0,255,0));
	//ѡ���»��ʣ������ɻ��ʵ�ָ�뱣�浽pOldPen
	pOldPen=pDC->SelectObject(&newPen);

	//����ǰ���ƶ�����ͼ�ؼ����ڵ����½ǣ��Դ�Ϊ���ε���ʼ��
	pDC->MoveTo(rectPicture.left,rectPicture.bottom);
	//����m_nzValues������ÿ�����Ӧ������λ�ã����������ӣ������γ�����
	for(int i=0;i<POINT_COUNT;i++)
	{
	   nX=rectPicture.left+(int)(i*fDeltaX);
	   nY=rectPicture.bottom-(int)(m_nzValues[i]*fDeltaY);
	   pDC->LineTo(nX,nY);
	}

	//�ָ��ɻ���
	pDC->SelectObject(pOldPen);
	//ɾ���»���
	newPen.DeleteObject();
}


void CExample35Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rectPicture;

	//�������е�����Ԫ��ǰ��һ����λ����һ��Ԫ�ض���
	for(int i=0;i<POINT_COUNT-1;i++)
		m_nzValues[i]=m_nzValues[i+1];
	
	//Ϊ���һ��Ԫ�ظ�һ��80���ڵ������ֵ�����ͣ�
	m_nzValues[POINT_COUNT-1]=rand()%80;

	//��ȡ��ͼ�ؼ��Ŀͻ������꣨�ͻ��������Դ��ڵ����Ͻ�Ϊԭ�㣬������������Ļ���Ͻ�Ϊԭ�����Ļ���꣩
	m_picDraw.GetClientRect(&rectPicture);

	//���Ʋ���ͼ
	DrawWave(m_picDraw.GetDC(),rectPicture);


	CDialogEx::OnTimer(nIDEvent);
}


void CExample35Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������

	//�رն�ʱ��
	KillTimer(1);
}
