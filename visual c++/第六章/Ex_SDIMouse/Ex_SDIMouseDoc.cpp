// Ex_SDIMouseDoc.cpp : implementation of the CEx_SDIMouseDoc class
//

#include "stdafx.h"
#include "Ex_SDIMouse.h"

#include "Ex_SDIMouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseDoc

IMPLEMENT_DYNCREATE(CEx_SDIMouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_SDIMouseDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_SDIMouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseDoc construction/destruction

CEx_SDIMouseDoc::CEx_SDIMouseDoc()
{
	// TODO: add one-time construction code here

}

CEx_SDIMouseDoc::~CEx_SDIMouseDoc()
{
}

BOOL CEx_SDIMouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseDoc serialization

void CEx_SDIMouseDoc::Serialize(CArchive& ar)
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
// CEx_SDIMouseDoc diagnostics

#ifdef _DEBUG
void CEx_SDIMouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_SDIMouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIMouseDoc commands
