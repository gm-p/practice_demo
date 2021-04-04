// Ex_ModelessDoc.cpp : implementation of the CEx_ModelessDoc class
//

#include "stdafx.h"
#include "Ex_Modeless.h"

#include "Ex_ModelessDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessDoc

IMPLEMENT_DYNCREATE(CEx_ModelessDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ModelessDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ModelessDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessDoc construction/destruction

CEx_ModelessDoc::CEx_ModelessDoc()
{
	// TODO: add one-time construction code here

}

CEx_ModelessDoc::~CEx_ModelessDoc()
{
}

BOOL CEx_ModelessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessDoc serialization

void CEx_ModelessDoc::Serialize(CArchive& ar)
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
// CEx_ModelessDoc diagnostics

#ifdef _DEBUG
void CEx_ModelessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ModelessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ModelessDoc commands
