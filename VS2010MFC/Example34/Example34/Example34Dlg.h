
// Example34Dlg.h : 头文件
//

#pragma once


// CExample34Dlg 对话框
class CExample34Dlg : public CDialogEx
{
// 构造
public:
	CExample34Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE34_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;


	int m_nTextX;  //水平滚动文本的起始点的x坐标
	int m_nTextY;  //垂直滚动文本的起始点的y坐标
	CFont m_newFont;  //新字体
	CFont* m_pOldFont;//选择新字体之前的字体


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
