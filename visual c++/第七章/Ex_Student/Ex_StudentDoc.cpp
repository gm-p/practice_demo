// Ex_StudentDoc.cpp : implementation of the CEx_StudentDoc class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "InputDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc

IMPLEMENT_DYNCREATE(CEx_StudentDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_StudentDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_StudentDoc)
	ON_COMMAND(ID_STUREC_ADD, OnSturecAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc construction/destruction

CEx_StudentDoc::CEx_StudentDoc()
{
	// TODO: add one-time construction code here
}

CEx_StudentDoc::~CEx_StudentDoc()
{
	int nIndex=GetAllRecNum();
	while(nIndex--)
		delete m_stuObArray.GetAt(nIndex);
	m_stuObArray.RemoveAll();
}

BOOL CEx_StudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc serialization

void CEx_StudentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_stuObArray.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		m_stuObArray.Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc diagnostics

#ifdef _DEBUG
void CEx_StudentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_StudentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc commands
CStudent::CStudent(CString name,CString id,float f1,float f2,float f3)
{
	strName=name;
	strID=id;
	fScore1=f1;
	fScore2=f2;
	fScore3=f3;
	fAverage=(float)((f1+f2+f3)/3.0);
}
void CStudent::Display(int y,CDC *pDC)
{
	CString str;
	str.Format("%s %s %f %f %f %f",strName,strID,fScore1,fScore2,fScore3,fAverage);
	pDC->TextOut(0,y,str);
}
IMPLEMENT_SERIAL(CStudent,CObject,1)
void CStudent::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
		ar<<strName<<strID<<fScore1<<fScore2<<fScore3<<fAverage;
	else
		ar>>strName>>strID>>fScore1>>fScore2>>fScore3>>fAverage;
}

void CEx_StudentDoc::OnSturecAdd() 
{
	// TODO: Add your command handler code here
	CInputDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		CStudent *pStudent=new CStudent(dlg.m_strName,dlg.m_strID,dlg.m_fScore1,dlg.m_fScore2,dlg.m_fScore3);
		m_stuObArray.Add(pStudent);
		SetModifiedFlag();
		UpdateAllViews(NULL);
	}
}
CStudent* CEx_StudentDoc::GetStudentAt(int nIndex)
{
	if((nIndex<0)||nIndex>m_stuObArray.GetUpperBound())
		return 0;
	return (CStudent*)m_stuObArray.GetAt(nIndex);
}
int CEx_StudentDoc::GetAllRecNum()
{
	return m_stuObArray.GetSize();
}