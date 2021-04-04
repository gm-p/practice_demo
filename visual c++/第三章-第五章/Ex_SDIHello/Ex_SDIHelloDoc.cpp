// Ex_SDIHelloDoc.cpp : implementation of the CEx_SDIHelloDoc class
//

#include "stdafx.h"
#include "Ex_SDIHello.h"

#include "Ex_SDIHelloDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloDoc

IMPLEMENT_DYNCREATE(CEx_SDIHelloDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_SDIHelloDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_SDIHelloDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloDoc construction/destruction

CEx_SDIHelloDoc::CEx_SDIHelloDoc()
{
	// TODO: add one-time construction code here

}

CEx_SDIHelloDoc::~CEx_SDIHelloDoc()
{
}

BOOL CEx_SDIHelloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloDoc serialization

void CEx_SDIHelloDoc::Serialize(CArchive& ar)
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
// CEx_SDIHelloDoc diagnostics

#ifdef _DEBUG
void CEx_SDIHelloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_SDIHelloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIHelloDoc commands
