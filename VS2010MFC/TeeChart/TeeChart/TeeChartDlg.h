
// TeeChartDlg.h : ͷ�ļ�
//

#pragma once
#include "ChartClass\ChartCtrl.h"
#include "ChartClass\ChartLineSerie.h"
#include "ChartClass\ChartAxis.h"
#include <vector>

using namespace std;

// CTeeChartDlg �Ի���
class CTeeChartDlg : public CDialogEx
{
// ����
public:
	CTeeChartDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEECHART_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
