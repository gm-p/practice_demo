#include "TipDlg.h"
// AdditionDlg.h : ͷ�ļ�
//

#pragma once


// CAdditionDlg �Ի���
class CAdditionDlg : public CDialogEx
{
// ����
public:
	CAdditionDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CAdditionDlg();

// �Ի�������
	enum { IDD = IDD_ADDITION_DIALOG };

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
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnBnClickedAddButton();

private:
	CTipDlg *m_pTipDlg;
public:
	afx_msg void OnBnClickedInstructButton();
};
