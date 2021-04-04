// BkColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl5SDI.h"
#include "BkColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBkColorDlg dialog


CBkColorDlg::CBkColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBkColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBkColorDlg)
	m_nGreen = 0;
	m_nBlue = 0;
	//}}AFX_DATA_INIT
}


void CBkColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBkColorDlg)
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_scrollRed);
	DDX_Slider(pDX, IDC_SLIDER_GREEN, m_nGreen);
	DDX_Slider(pDX, IDC_SLIDER_BLUE, m_nBlue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBkColorDlg, CDialog)
	//{{AFX_MSG_MAP(CBkColorDlg)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBkColorDlg message handlers

BOOL CBkColorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_scrollRed.SetScrollRange(0,255);
	m_sliderBlue.SetRange(0,255);
	m_sliderGreen.SetRange(0,255);
	m_nBlue=m_nGreen=m_nRedValue=192;
	UpdateData(FALSE);
	m_scrollRed.SetScrollPos(m_nRedValue);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBkColorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int nID=pScrollBar->GetDlgCtrlID();
	if(nID==IDC_SCROLLBAR_RED)
	{
		switch(nSBCode)
		{
		case SB_LINELEFT:	m_nRedValue--;
							break;
		case SB_LINERIGHT:  m_nRedValue++;
							break;
		case SB_PAGELEFT:	m_nRedValue-=10;
							break;
		case SB_PAGERIGHT:  m_nRedValue+=10;
							break;
		case SB_THUMBTRACK: m_nRedValue=nPos;
							break;
		}
		if(m_nRedValue<0)
			m_nRedValue=0;
		if(m_nRedValue>255)
			m_nRedValue=255;
		m_scrollRed.SetScrollPos(m_nRedValue);
	}
	Invalidate();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

HBRUSH CBkColorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	UpdateData(TRUE);
	COLORREF color=RGB(m_nRedValue,m_nGreen,m_nBlue);
	m_Brush.Detach();
	m_Brush.CreateSolidBrush(color);
	pDC->SetBkColor(color);
	return (HBRUSH)m_Brush;
	// TODO: Return a different brush if the default is not desired
	//return hbr;
}
