
// Example30Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "JzmDlg.h"
#include "AndroidDlg.h"

// CExample30Dlg 对话框
class CExample30Dlg : public CDialogEx
{
// 构造
public:
	CExample30Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE30_DIALOG };

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
	CTabCtrl m_tab;
	CJzmDlg m_jzmDlg;
	CAndroidDlg m_androidDlg;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
