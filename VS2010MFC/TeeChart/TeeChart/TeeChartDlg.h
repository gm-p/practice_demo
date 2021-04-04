
// TeeChartDlg.h : 头文件
//

#pragma once
#include "ChartClass\ChartCtrl.h"
#include "ChartClass\ChartLineSerie.h"
#include "ChartClass\ChartAxis.h"
#include <vector>

using namespace std;

// CTeeChartDlg 对话框
class CTeeChartDlg : public CDialogEx
{
// 构造
public:
	CTeeChartDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEECHART_DIALOG };

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
	CMFCTabCtrl m_tab;
	CChartCtrl m_HSChartCtrl;
	CChartLineSerie* m_pLineSerie;

	long m_nPointNum;
	double m_X[2096];
	unsigned int m_count;
	const size_t m_c_arrayLength;

	afx_msg void OnBnClickedOk();
};
