// Ex_DrawView.cpp : implementation of the CEx_DrawView class
//

#include "stdafx.h"
#include "Ex_Draw.h"

#include "Ex_DrawDoc.h"
#include "Ex_DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView

IMPLEMENT_DYNCREATE(CEx_DrawView, CView)

BEGIN_MESSAGE_MAP(CEx_DrawView, CView)
	//{{AFX_MSG_MAP(CEx_DrawView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView construction/destruction

CEx_DrawView::CEx_DrawView()
{
	// TODO: add construction code here

}

CEx_DrawView::~CEx_DrawView()
{
}

BOOL CEx_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView drawing

void CEx_DrawView::OnDraw(CDC* pDC)
{
	CEx_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	float fScore[]={66,82,79,74,86,82,67,60,45,44,77,98,65,90,66,76,66,
					62,83,84,97,43,67,57,60,60,71,74,60,72,81,69,79,91,69,71,81};
	DrawScore(pDC,fScore,sizeof(fScore)/sizeof(float));
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView printing

BOOL CEx_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView diagnostics

#ifdef _DEBUG
void CEx_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_DrawDoc* CEx_DrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_DrawDoc)));
	return (CEx_DrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawView message handlers

void CEx_DrawView::DrawScore(CDC *pDC, float *fScore, int nNum)
{
	int nScoreNum[]={0,0,0,0,0};
    for(int i=0;i<nNum;i++)
	{
		int nSeg=(int)(fScore[i])/10;
		if(nSeg<6) 
			nSeg=5;
		if(nSeg==10)
			nSeg=9;
		nScoreNum[nSeg-5]++;
	}	  
	int nSegNum=sizeof(nScoreNum)/sizeof(int);
	int  nNumMax=nScoreNum[0];
	for(i=1;i<nSegNum;i++)
	{
		if(nNumMax<nScoreNum[i])
			nNumMax=nScoreNum[i];
	}
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(40,40);
	int nSegWidth=rc.Width()/nSegNum;
	int nSegHeight=rc.Height()/nNumMax;
	COLORREF crSeg=RGB(0,0,192);
	CBrush brush1(HS_FDIAGONAL,crSeg);
	CBrush brush2(HS_BDIAGONAL,crSeg);
	CPen pen(PS_INSIDEFRAME,2,crSeg);
	CBrush *oldBrush=pDC->SelectObject(&brush1);
	CPen *oldPen=pDC->SelectObject(&pen);
	CRect rcSeg(rc);
	rcSeg.right=rcSeg.left+nSegWidth;
	CString strSeg[]={"<60","60-70","70-80","80-90",">=90"};
	CRect rcStr;
	for(i=0;i<nSegNum;i++)
	{
		if(i%2)
			pDC->SelectObject(&brush2);
		else
			pDC->SelectObject(&brush1);
		rcSeg.top=rcSeg.bottom-nScoreNum[i]*nSegHeight-2;
		pDC->Rectangle(rcSeg);
		if(nScoreNum[i]>0)
		{
			CString str;
			str.Format("%d ÈË",nScoreNum[i]);
			pDC->DrawText(str,rcSeg,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		}
		rcStr=rcSeg;
		rcStr.top=rcStr.bottom+2;
		rcStr.bottom+=20;
		pDC->DrawText(strSeg[i],rcStr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		rcSeg.OffsetRect(nSegWidth,0);
	}
	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);
}
