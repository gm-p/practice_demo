// Ex_TreeDoc.cpp : implementation of the CEx_TreeDoc class
//

#include "stdafx.h"
#include "Ex_Tree.h"

#include "Ex_TreeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeDoc

IMPLEMENT_DYNCREATE(CEx_TreeDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_TreeDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_TreeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeDoc construction/destruction

CEx_TreeDoc::CEx_TreeDoc()
{
	// TODO: add one-time construction code here

}

CEx_TreeDoc::~CEx_TreeDoc()
{
}

BOOL CEx_TreeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_TreeDoc serialization

void CEx_TreeDoc::Serialize(CArchive& ar)
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
// CEx_TreeDoc diagnostics

#ifdef _DEBUG
void CEx_TreeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_TreeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TreeDoc commands
