// Ex_EditDoc.cpp : implementation of the CEx_EditDoc class
//

#include "stdafx.h"
#include "Ex_Edit.h"

#include "Ex_EditDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_EditDoc

IMPLEMENT_DYNCREATE(CEx_EditDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_EditDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_EditDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_EditDoc construction/destruction

CEx_EditDoc::CEx_EditDoc()
{
	// TODO: add one-time construction code here

}

CEx_EditDoc::~CEx_EditDoc()
{
}

BOOL CEx_EditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_EditDoc serialization

void CEx_EditDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_EditDoc diagnostics

#ifdef _DEBUG
void CEx_EditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_EditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_EditDoc commands
