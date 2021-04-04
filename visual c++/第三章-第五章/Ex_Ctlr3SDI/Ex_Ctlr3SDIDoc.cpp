// Ex_Ctlr3SDIDoc.cpp : implementation of the CEx_Ctlr3SDIDoc class
//

#include "stdafx.h"
#include "Ex_Ctlr3SDI.h"

#include "Ex_Ctlr3SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIDoc

IMPLEMENT_DYNCREATE(CEx_Ctlr3SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Ctlr3SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_Ctlr3SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIDoc construction/destruction

CEx_Ctlr3SDIDoc::CEx_Ctlr3SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_Ctlr3SDIDoc::~CEx_Ctlr3SDIDoc()
{
}

BOOL CEx_Ctlr3SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIDoc serialization

void CEx_Ctlr3SDIDoc::Serialize(CArchive& ar)
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
// CEx_Ctlr3SDIDoc diagnostics

#ifdef _DEBUG
void CEx_Ctlr3SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Ctlr3SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctlr3SDIDoc commands
