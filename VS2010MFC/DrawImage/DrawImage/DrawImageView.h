
// DrawImageView.h : CDrawImageView ��Ľӿ�
//

#pragma once
#include <opencv2/opencv.hpp>
#include "DrawImageDoc.h"
#include "CvvImage.h"

using namespace cv;

class CDrawImageView : public CView
{
protected: // �������л�����
	CDrawImageView();
	DECLARE_DYNCREATE(CDrawImageView)

// ����
public:
	CDrawImageDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	Mat src;
};

#ifndef _DEBUG  // DrawImageView.cpp �еĵ��԰汾
inline CDrawImageDoc* CDrawImageView::GetDocument() const
   { return reinterpret_cast<CDrawImageDoc*>(m_pDocument); }
#endif

