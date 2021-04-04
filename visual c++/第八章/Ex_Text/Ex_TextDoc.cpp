// Ex_TextDoc.cpp : implementation of the CEx_TextDoc class
//

#include "stdafx.h"
#include "Ex_Text.h"

#include "Ex_TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TextDoc

IMPLEMENT_DYNCREATE(CEx_TextDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_TextDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_TextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TextDoc construction/destruction

CEx_TextDoc::CEx_TextDoc()
{
	// TODO: add one-time construction code here

}

CEx_TextDoc::~CEx_TextDoc()
{
}

BOOL CEx_TextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_TextDoc serialization

void CEx_TextDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		CString str;
		m_strContents.RemoveAll();
		while(ar.ReadString(str))
			m_strContents.Add(str);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TextDoc diagnostics

#ifdef _DEBUG
void CEx_TextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_TextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TextDoc commands
