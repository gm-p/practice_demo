
// Example22Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample22Dlg �Ի���
class CExample22Dlg : public CDialogEx
{
// ����
public:
	CExample22Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE22_DIALOG };

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