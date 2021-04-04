#pragma once
#include <string>


// CMyFormDlg 窗体视图

class CMyFormDlg : public CFormView
{
	DECLARE_DYNCREATE(CMyFormDlg)

protected:
	CMyFormDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyFormDlg();

public:
	enum { IDD = IDD_MYFORMDLG };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
};


