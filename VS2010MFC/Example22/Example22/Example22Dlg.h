
// Example22Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CExample22Dlg 对话框
class CExample22Dlg : public CDialogEx
{
// 构造
public:
	CExample22Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE22_DIALOG };

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
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	afx_msg void OnBnClickedPortalRadio();
	afx_msg void OnBnClickedBlogRadio();
	afx_msg void OnBnClickedForumRadio();
	void InitAllCheckBoxStatus(void);
	afx_msg void OnBnClickedOk();
};
