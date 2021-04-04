// Ex_Ctrl2SDIDoc.cpp : implementation of the CEx_Ctrl2SDIDoc class
//

#include "stdafx.h"
#include "Ex_Ctrl2SDI.h"

#include "Ex_Ctrl2SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl2SDIDoc

IMPLEMENT_DYNCREATE(CEx_Ctrl2SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Ctrl2SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_Ctrl2SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl2SDIDoc construction/destruction

CEx_Ctrl2SDIDoc::CEx_Ctrl2SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_Ctrl2SDIDoc::~CEx_Ctrl2SDIDoc()
{
}

BOOL CEx_Ctrl2SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl2SDIDoc serialization

void CEx_Ctrl2SDIDoc::Serialize(CArchive& ar)
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
// CEx_Ctrl2SDIDoc diagnostics

#ifdef _DEBUG
void CEx_Ctrl2SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Ctrl2SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl2SDIDoc commands
