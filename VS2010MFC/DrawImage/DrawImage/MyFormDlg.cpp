// MyFormDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawImage.h"
#include "MyFormDlg.h"
#include "DrawImageView.h"
#include "MainFrm.h"

using namespace std;


// CMyFormDlg

IMPLEMENT_DYNCREATE(CMyFormDlg, CFormView)

CMyFormDlg::CMyFormDlg()
	: CFormView(CMyFormDlg::IDD)
{

}

CMyFormDlg::~CMyFormDlg()
{
}

void CMyFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyFormDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyFormDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyFormDlg ���

#ifdef _DEBUG
void CMyFormDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyFormDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyFormDlg ��Ϣ�������


void CMyFormDlg::OnBnClickedButton3()
{
	CFileDialog dlg(TRUE);
	CString m_filePath;
	string strName;
	if(dlg.DoModal() == IDOK)
	{
		m_filePath = dlg.GetPathName();
		strName = m_filePath.GetBuffer(0);
	}
	CMainFrame* pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;   //��ÿ�������ָ��
	if(pMain == NULL)
		MessageBox("��ָ��1");
	CDrawImageView* pView = (CDrawImageView *)pMain->GetActiveView();  //�����ͼ�����ָ��
	if(pView == NULL)
		MessageBox("��ָ��2");
	Mat srcimg = imread(strName); imshow("���", srcimg);
	pView->src = srcimg.clone();  //imread(strName);  
	
	//if((pView->src).empty())
	//{
	//	MessageBox("����ͼ��ʧ�ܣ�");
	//	return ;
	//}
	//imshow("���", pView->src);
	//Invalidate();
}
