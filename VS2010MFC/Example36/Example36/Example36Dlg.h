
// Example36Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample36Dlg �Ի���
class CExample36Dlg : public CDialogEx
{
// ����
public:
	CExample36Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE36_DIALOG };

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
	CStatic m_picColor;
	afx_msg void OnBnClickedColorSelButton();
};
