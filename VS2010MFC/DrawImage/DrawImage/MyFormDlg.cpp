// MyFormDlg.cpp : 实现文件
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


// CMyFormDlg 诊断

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


// CMyFormDlg 消息处理程序


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
	CMainFrame* pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;   //获得框架类对象指针
	if(pMain == NULL)
		MessageBox("空指针1");
	CDrawImageView* pView = (CDrawImageView *)pMain->GetActiveView();  //获得视图类对象指针
	if(pView == NULL)
		MessageBox("空指针2");
	Mat srcimg = imread(strName); imshow("输出", srcimg);
	pView->src = srcimg.clone();  //imread(strName);  
	
	//if((pView->src).empty())
	//{
	//	MessageBox("读入图像失败！");
	//	return ;
	//}
	//imshow("输出", pView->src);
	//Invalidate();
}
