// Ex_ContextMenuDoc.cpp : implementation of the CEx_ContextMenuDoc class
//

#include "stdafx.h"
#include "Ex_ContextMenu.h"

#include "Ex_ContextMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuDoc

IMPLEMENT_DYNCREATE(CEx_ContextMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ContextMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ContextMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuDoc construction/destruction

CEx_ContextMenuDoc::CEx_ContextMenuDoc()
{
	// TODO: add one-time construction code here

}

CEx_ContextMenuDoc::~CEx_ContextMenuDoc()
{
}

BOOL CEx_ContextMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuDoc serialization

void CEx_ContextMenuDoc::Serialize(CArchive& ar)
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
// CEx_ContextMenuDoc diagnostics

#ifdef _DEBUG
void CEx_ContextMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ContextMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ContextMenuDoc commands
