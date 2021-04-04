// Ex_Ctrl5SDIDoc.cpp : implementation of the CEx_Ctrl5SDIDoc class
//

#include "stdafx.h"
#include "Ex_Ctrl5SDI.h"

#include "Ex_Ctrl5SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIDoc

IMPLEMENT_DYNCREATE(CEx_Ctrl5SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Ctrl5SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_Ctrl5SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIDoc construction/destruction

CEx_Ctrl5SDIDoc::CEx_Ctrl5SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_Ctrl5SDIDoc::~CEx_Ctrl5SDIDoc()
{
}

BOOL CEx_Ctrl5SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIDoc serialization

void CEx_Ctrl5SDIDoc::Serialize(CArchive& ar)
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
// CEx_Ctrl5SDIDoc diagnostics

#ifdef _DEBUG
void CEx_Ctrl5SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Ctrl5SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIDoc commands
