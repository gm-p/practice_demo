// Ex_CursorDoc.cpp : implementation of the CEx_CursorDoc class
//

#include "stdafx.h"
#include "Ex_Cursor.h"

#include "Ex_CursorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorDoc

IMPLEMENT_DYNCREATE(CEx_CursorDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_CursorDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_CursorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorDoc construction/destruction

CEx_CursorDoc::CEx_CursorDoc()
{
	// TODO: add one-time construction code here

}

CEx_CursorDoc::~CEx_CursorDoc()
{
}

BOOL CEx_CursorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_CursorDoc serialization

void CEx_CursorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorDoc diagnostics

#ifdef _DEBUG
void CEx_CursorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_CursorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_CursorDoc commands
