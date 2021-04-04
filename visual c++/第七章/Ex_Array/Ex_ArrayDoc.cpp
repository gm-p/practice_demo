// Ex_ArrayDoc.cpp : implementation of the CEx_ArrayDoc class
//

#include "stdafx.h"
#include "Ex_Array.h"

#include "Ex_ArrayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayDoc

IMPLEMENT_DYNCREATE(CEx_ArrayDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ArrayDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ArrayDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayDoc construction/destruction

CEx_ArrayDoc::CEx_ArrayDoc()
{
	// TODO: add one-time construction code here

}

CEx_ArrayDoc::~CEx_ArrayDoc()
{
}

BOOL CEx_ArrayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayDoc serialization

void CEx_ArrayDoc::Serialize(CArchive& ar)
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
		{
			m_strContents.Add(str);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayDoc diagnostics

#ifdef _DEBUG
void CEx_ArrayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ArrayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayDoc commands
