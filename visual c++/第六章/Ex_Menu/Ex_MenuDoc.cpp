// Ex_MenuDoc.cpp : implementation of the CEx_MenuDoc class
//

#include "stdafx.h"
#include "Ex_Menu.h"

#include "Ex_MenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuDoc

IMPLEMENT_DYNCREATE(CEx_MenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MenuDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuDoc construction/destruction

CEx_MenuDoc::CEx_MenuDoc()
{
	// TODO: add one-time construction code here

}

CEx_MenuDoc::~CEx_MenuDoc()
{
}

BOOL CEx_MenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MenuDoc serialization

void CEx_MenuDoc::Serialize(CArchive& ar)
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
// CEx_MenuDoc diagnostics

#ifdef _DEBUG
void CEx_MenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuDoc commands
