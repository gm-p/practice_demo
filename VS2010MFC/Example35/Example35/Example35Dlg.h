
// Example35Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


#define POINT_COUNT 100

// CExample35Dlg �Ի���
class CExample35Dlg : public CDialogEx
{
// ����
public:
	CExample35Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE35_DIALOG };

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
	CStatic m_picDraw;

	int m_nzValues[POINT_COUNT];
	void DrawWave(CDC* pDC, CRect& rectPicture);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
