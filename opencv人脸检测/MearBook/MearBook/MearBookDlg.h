
// MearBookDlg.h : ͷ�ļ�
//

#pragma once
#include "CvvImage.h"

using namespace cv;

// CMearBookDlg �Ի���
class CMearBookDlg : public CDialogEx
{
// ����
public:
	CMearBookDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEARBOOK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	Mat mat;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void DrawPicToHDC(Mat& mat, UINT ID);
	afx_msg void OnBnClickedbtmeasure();
	int width;
	int height;
};
