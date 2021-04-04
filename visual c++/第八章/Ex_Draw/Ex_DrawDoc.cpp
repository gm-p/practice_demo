// Ex_DrawDoc.cpp : implementation of the CEx_DrawDoc class
//

#include "stdafx.h"
#include "Ex_Draw.h"

#include "Ex_DrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawDoc

IMPLEMENT_DYNCREATE(CEx_DrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_DrawDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_DrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawDoc construction/destruction

CEx_DrawDoc::CEx_DrawDoc()
{
	// TODO: add one-time construction code here

}

CEx_DrawDoc::~CEx_DrawDoc()
{
}

BOOL CEx_DrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_DrawDoc serialization

void CEx_DrawDoc::Serialize(CArchive& ar)
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
// CEx_DrawDoc diagnostics

#ifdef _DEBUG
void CEx_DrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_DrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawDoc commands
