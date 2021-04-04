// Ex_SDIArchiveDoc.cpp : implementation of the CEx_SDIArchiveDoc class
//

#include "stdafx.h"
#include "Ex_SDIArchive.h"

#include "Ex_SDIArchiveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveDoc

IMPLEMENT_DYNCREATE(CEx_SDIArchiveDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_SDIArchiveDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_SDIArchiveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveDoc construction/destruction

CEx_SDIArchiveDoc::CEx_SDIArchiveDoc()
{
	// TODO: add one-time construction code here
	m_bIsMyDoc=FALSE;
}

CEx_SDIArchiveDoc::~CEx_SDIArchiveDoc()
{
}

BOOL CEx_SDIArchiveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	strcpy(m_chArchive,"&这是一个用于测试文档的内容！");
	m_strArchive="这是一行文本!";
	m_bIsMyDoc=TRUE;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveDoc serialization

void CEx_SDIArchiveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		if(m_bIsMyDoc)
		{
			for(int i=0;i<sizeof(m_chArchive);i++)
				ar<<m_chArchive[i];
			ar.WriteString(m_strArchive);
		}
		else
			AfxMessageBox("数据无法保存！");
	}
	else
	{
		// TODO: add loading code here
		ar>>m_chArchive[0];
		if(m_chArchive[0]=='&')
		{
			for(int i=1;i<sizeof(m_chArchive);i++)
				ar>>m_chArchive[i];
			ar.ReadString(m_strArchive);
			CString str;
			str.Format("%s%s",m_chArchive,m_strArchive);
			AfxMessageBox(str);
			m_bIsMyDoc=TRUE;
		}
		else
		{
			m_bIsMyDoc=FALSE;
			AfxMessageBox("打开的文档无效！");
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveDoc diagnostics

#ifdef _DEBUG
void CEx_SDIArchiveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_SDIArchiveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIArchiveDoc commands
