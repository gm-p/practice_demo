
// Example29Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CExample29Dlg 对话框
class CExample29Dlg : public CDialogEx
{
// 构造
public:
	CExample29Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE29_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_webTree;
	CImageList m_imageList;
	afx_msg void OnTvnSelchangedWebTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnGetInfoTipWebTree(NMHDR *pNMHDR, LRESULT *pResult);
};
