
// Example28Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CExample28Dlg 对话框
class CExample28Dlg : public CDialogEx
{
// 构造
public:
	CExample28Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE28_DIALOG };

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
	CListCtrl m_programLangList;
	afx_msg void OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult);
};
