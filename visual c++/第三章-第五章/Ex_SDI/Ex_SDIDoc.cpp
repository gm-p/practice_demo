// Ex_SDIDoc.cpp : implementation of the CEx_SDIDoc class
//

#include "stdafx.h"
#include "Ex_SDI.h"

#include "Ex_SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIDoc

IMPLEMENT_DYNCREATE(CEx_SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIDoc construction/destruction

CEx_SDIDoc::CEx_SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_SDIDoc::~CEx_SDIDoc()
{
}

BOOL CEx_SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_SDIDoc serialization

void CEx_SDIDoc::Serialize(CArchive& ar)
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
// CEx_SDIDoc diagnostics

#ifdef _DEBUG
void CEx_SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIDoc commands
