// Ex_RectDoc.cpp : implementation of the CEx_RectDoc class
//

#include "stdafx.h"
#include "Ex_Rect.h"

#include "Ex_RectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_RectDoc

IMPLEMENT_DYNCREATE(CEx_RectDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_RectDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_RectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_RectDoc construction/destruction

CEx_RectDoc::CEx_RectDoc()
{
	// TODO: add one-time construction code here
	m_ptRect.x=m_ptRect.y=0;
}

CEx_RectDoc::~CEx_RectDoc()
{
}

BOOL CEx_RectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_RectDoc serialization

void CEx_RectDoc::Serialize(CArchive& ar)
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
// CEx_RectDoc diagnostics

#ifdef _DEBUG
void CEx_RectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_RectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_RectDoc commands
