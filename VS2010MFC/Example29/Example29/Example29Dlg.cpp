
// Example29Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example29.h"
#include "Example29Dlg.h"
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


// CExample29Dlg �Ի���




CExample29Dlg::CExample29Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample29Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample29Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WEB_TREE, m_webTree);
}

BEGIN_MESSAGE_MAP(CExample29Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_WEB_TREE, &CExample29Dlg::OnTvnSelchangedWebTree)
	ON_NOTIFY(TVN_GETINFOTIP, IDC_WEB_TREE, &CExample29Dlg::OnTvnGetInfoTipWebTree)
END_MESSAGE_MAP()


// CExample29Dlg ��Ϣ��������

BOOL CExample29Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	HICON hIcon[3];  //ͼ��������
	HTREEITEM hRoot; //���ĸ��ڵ���
	HTREEITEM hCataItem;//�ɱ�ʾ��һ����ڵ�ľ��
	HTREEITEM hArtItem;//�ɱ�ʾ��һ���½ڵ�ľ��

	//��������ͼ�꣬�������ǵľ�����浽����
	hIcon[0]=theApp.LoadIconW(IDI_WEB_ICON);
	hIcon[1]=theApp.LoadIconW(IDI_CATALOG_ICON);
	hIcon[2]=theApp.LoadIconW(IDI_ARTICLE_ICON);

	//����ͼ������CImageList����
	m_imageList.Create(32,32,ILC_COLOR32,3,3);
	//������ͼ�����ӵ�ͼ������
	for(int i=0;i<3;i++)
	{
	   m_imageList.Add(hIcon[i]);
	}

	//Ϊ���οؼ�����ͼ������
	m_webTree.SetImageList(&m_imageList,TVSIL_NORMAL);

	//������ڵ�
	hRoot=m_webTree.InsertItem(_T("������"),0,0);
	//�ڸ��ڵ��²����ӽڵ�
	hCataItem=m_webTree.InsertItem(_T("IT������"),1,1,hRoot,TVI_LAST);
	//Ϊ��IT���������ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hCataItem,1);
	//�ڡ�IT���������ڵ��²����ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("�ٶ�����1"),2,2,hCataItem,TVI_LAST);
	//Ϊ���ٶ�����1���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,2);
	//�ڡ�IT���������ڵ��²�����һ���ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("�ȸ�����2"),2,2,hCataItem,TVI_LAST);
	//Ϊ���ȸ�����2���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,3);
	//�ڸ��ڵ��²���ڶ����ӽڵ�
	hCataItem=m_webTree.InsertItem(_T("��������"),1,1,hRoot,TVI_LAST);
	//Ϊ����������ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hCataItem,4);
	//�ڡ���������ڵ��²����ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("�����ֻ�����1"),2,2,hCataItem,TVI_LAST);
	//Ϊ�������ֻ�����1���ڵ����ӱ�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,5);
	//�ڡ���������ڵ��²�����һ���ڵ�
	hArtItem=m_webTree.InsertItem(_T("ƽ���������2"),2,2,hCataItem,TVI_LAST);
	//�ڡ�ƽ���������2���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,6);
	//�ڸ��ڵ��²���������ӽڵ�
	hCataItem=m_webTree.InsertItem(_T("��������"),1,1,hRoot,TVI_LAST);
	//Ϊ�������������ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hCataItem,7);
	//�ڡ������������ڵ��²����ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("C++�������ϵ��1"),2,2,hCataItem,TVI_LAST);
	//Ϊ��C++�������ϵ��1���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,8);
	//�ڡ������������ڵ��²�����һ�ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("VS2010/MFC�������2"),2,2,hCataItem,TVI_LAST);
	//Ϊ��VS2010/MFC�������2���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,9);
	//�ڸ��ڵ��²�����ĸ��ڵ�
	hCataItem=m_webTree.InsertItem(_T("��������"),1,1,hRoot,TVI_LAST);
	//Ϊ���������С��ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hCataItem,10);
	//�ڡ��������С��ڵ��²����ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("������������1"),2,2,hCataItem,TVI_LAST);
	//Ϊ��������������1���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,11);
	//�ڡ��������С��ڵ��²�����һ�ӽڵ�
	hArtItem=m_webTree.InsertItem(_T("ITЦ��2"),2,2,hCataItem,TVI_LAST);
	//Ϊ��ITЦ��2���ڵ����Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ
	m_webTree.SetItemData(hArtItem,12);





	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample29Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExample29Dlg::OnPaint()
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
HCURSOR CExample29Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample29Dlg::OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	*pResult = 0;

	CString strText;//���ڵ�ı�ǩ�ı��ַ���
	
	//��ȡ��ǰѡ�нڵ�ľ��
	HTREEITEM hItem=m_webTree.GetSelectedItem();
	//��ȡѡ�нڵ�ı�ǩ�ı��ַ���
	strText=m_webTree.GetItemText(hItem);
	//���ַ�����ʾ���༭����
	SetDlgItemText(IDC_ITEM_SEL_EDIT,strText);
}


void CExample29Dlg::OnTvnGetInfoTipWebTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	*pResult = 0;

	NMTVGETINFOTIP* pTVTipInfo=(NMTVGETINFOTIP*)pNMHDR;//�������pNMHDRת��ΪNMTVGETINFOTIPָ������
	HTREEITEM hRoot=m_webTree.GetRootItem();//��ȡ���ĸ��ڵ�
	CString strText; //ÿ�����ڵ����ʾ��Ϣ
	if(pTVTipInfo->hItem==hRoot)
	{
	   //�����껮���Ľڵ�ʱ���ڵ㣬����ʾ��ϢΪ��
		strText=_T("");
	}
	else
	{
	   //�����껮���Ľڵ㲻�Ǹ��ڵ㣬�򽫸ýڵ�ĸ���32λ���ݸ�ʽ��Ϊ�ַ���
		strText.Format(_T("%d"),pTVTipInfo->lParam);
	}

	//��strText�ַ���������pTVTipInfo�ṹ�������pszText��Ա�У�����������ʾ����ΪstrText����ʾ��Ϣ
	wcscpy(pTVTipInfo->pszText,strText);

}