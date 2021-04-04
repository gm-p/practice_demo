// Ex_ListDoc.cpp : implementation of the CEx_ListDoc class
//

#include "stdafx.h"
#include "Ex_List.h"

#include "Ex_ListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ListDoc

IMPLEMENT_DYNCREATE(CEx_ListDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ListDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ListDoc construction/destruction

CEx_ListDoc::CEx_ListDoc()
{
	// TODO: add one-time construction code here

}

CEx_ListDoc::~CEx_ListDoc()
{
}

BOOL CEx_ListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ListDoc serialization

void CEx_ListDoc::Serialize(CArchive& ar)
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
// CEx_ListDoc diagnostics

#ifdef _DEBUG
void CEx_ListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ListDoc commands
