// Ex_IconDoc.cpp : implementation of the CEx_IconDoc class
//

#include "stdafx.h"
#include "Ex_Icon.h"

#include "Ex_IconDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_IconDoc

IMPLEMENT_DYNCREATE(CEx_IconDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_IconDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_IconDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_IconDoc construction/destruction

CEx_IconDoc::CEx_IconDoc()
{
	// TODO: add one-time construction code here

}

CEx_IconDoc::~CEx_IconDoc()
{
}

BOOL CEx_IconDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_IconDoc serialization

void CEx_IconDoc::Serialize(CArchive& ar)
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
// CEx_IconDoc diagnostics

#ifdef _DEBUG
void CEx_IconDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_IconDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_IconDoc commands
