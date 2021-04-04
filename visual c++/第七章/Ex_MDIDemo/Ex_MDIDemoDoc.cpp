// Ex_MDIDemoDoc.cpp : implementation of the CEx_MDIDemoDoc class
//

#include "stdafx.h"
#include "Ex_MDIDemo.h"

#include "Ex_MDIDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoDoc

IMPLEMENT_DYNCREATE(CEx_MDIDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MDIDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MDIDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoDoc construction/destruction

CEx_MDIDemoDoc::CEx_MDIDemoDoc()
{
	// TODO: add one-time construction code here

}

CEx_MDIDemoDoc::~CEx_MDIDemoDoc()
{
}

BOOL CEx_MDIDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoDoc serialization

void CEx_MDIDemoDoc::Serialize(CArchive& ar)
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
// CEx_MDIDemoDoc diagnostics

#ifdef _DEBUG
void CEx_MDIDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MDIDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDemoDoc commands
