
// MearBookDlg.h : 头文件
//

#pragma once
#include "CvvImage.h"

using namespace cv;

// CMearBookDlg 对话框
class CMearBookDlg : public CDialogEx
{
// 构造
public:
	CMearBookDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MEARBOOK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	Mat mat;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void DrawPicToHDC(Mat& mat, UINT ID);
	afx_msg void OnBnClickedbtmeasure();
	int width;
	int height;
};
