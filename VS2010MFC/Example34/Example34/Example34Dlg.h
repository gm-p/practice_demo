
// Example34Dlg.h : ͷ�ļ�
//

#pragma once


// CExample34Dlg �Ի���
class CExample34Dlg : public CDialogEx
{
// ����
public:
	CExample34Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE34_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;


	int m_nTextX;  //ˮƽ�����ı�����ʼ���x����
	int m_nTextY;  //��ֱ�����ı�����ʼ���y����
	CFont m_newFont;  //������
	CFont* m_pOldFont;//ѡ��������֮ǰ������


	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
