// Ex_FormDoc.cpp : implementation of the CEx_FormDoc class
//

#include "stdafx.h"
#include "Ex_Form.h"

#include "Ex_FormDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_FormDoc

IMPLEMENT_DYNCREATE(CEx_FormDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_FormDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_FormDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_FormDoc construction/destruction

CEx_FormDoc::CEx_FormDoc()
{
	// TODO: add one-time construction code here

}

CEx_FormDoc::~CEx_FormDoc()
{
}

BOOL CEx_FormDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_FormDoc serialization

void CEx_FormDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		CString str;
		m_strContent.Empty();
		while(ar.ReadString(str))
		{
			m_strContent=m_strContent+str;
			m_strContent=m_strContent+"\r\n";
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FormDoc diagnostics

#ifdef _DEBUG
void CEx_FormDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_FormDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_FormDoc commands
