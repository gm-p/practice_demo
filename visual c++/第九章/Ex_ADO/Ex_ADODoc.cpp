// Ex_ADODoc.cpp : implementation of the CEx_ADODoc class
//

#include "stdafx.h"
#include "Ex_ADO.h"

#include "Ex_ADODoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ADODoc

IMPLEMENT_DYNCREATE(CEx_ADODoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ADODoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ADODoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ADODoc construction/destruction

CEx_ADODoc::CEx_ADODoc()
{
	// TODO: add one-time construction code here

}

CEx_ADODoc::~CEx_ADODoc()
{
}

BOOL CEx_ADODoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ADODoc serialization

void CEx_ADODoc::Serialize(CArchive& ar)
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
// CEx_ADODoc diagnostics

#ifdef _DEBUG
void CEx_ADODoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ADODoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ADODoc commands
