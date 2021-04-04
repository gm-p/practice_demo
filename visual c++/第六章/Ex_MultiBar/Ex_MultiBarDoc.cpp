// Ex_MultiBarDoc.cpp : implementation of the CEx_MultiBarDoc class
//

#include "stdafx.h"
#include "Ex_MultiBar.h"

#include "Ex_MultiBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarDoc

IMPLEMENT_DYNCREATE(CEx_MultiBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MultiBarDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MultiBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarDoc construction/destruction

CEx_MultiBarDoc::CEx_MultiBarDoc()
{
	// TODO: add one-time construction code here

}

CEx_MultiBarDoc::~CEx_MultiBarDoc()
{
}

BOOL CEx_MultiBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarDoc serialization

void CEx_MultiBarDoc::Serialize(CArchive& ar)
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
// CEx_MultiBarDoc diagnostics

#ifdef _DEBUG
void CEx_MultiBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MultiBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MultiBarDoc commands
