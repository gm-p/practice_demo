#include <afxwin.h>
class CHelloApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CHelloApp theApp;
class CMainFrame:public CFrameWnd
{
public:
	CMainFrame()
	{
		Create(NULL,"�ҵĴ���",WS_OVERLAPPEDWINDOW,CRect(0,0,400,300));
	}
protected:
	afx_msg void OnLButtonDown(UINT nFlags,CPoint point);
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMainFrame,CFrameWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
void CMainFrame::OnLButtonDown(UINT nFlags,CPoint point)
{
	MessageBox("��ã��ҵ�Visual C++���磡","�ʺ�",0);
	CFrameWnd::OnLButtonDown(nFlags,point);
}
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd=new CMainFrame();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}