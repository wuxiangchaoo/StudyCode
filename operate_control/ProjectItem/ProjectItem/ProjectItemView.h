
// ProjectItemView.h : CProjectItemView ��Ľӿ�
//

#pragma once


class CProjectItemView : public CView
{
protected: // �������л�����
	CProjectItemView();
	DECLARE_DYNCREATE(CProjectItemView)

// ����
public:
	CProjectItemDoc* GetDocument() const;

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
	virtual ~CProjectItemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ProjectItemView.cpp �еĵ��԰汾
inline CProjectItemDoc* CProjectItemView::GetDocument() const
   { return reinterpret_cast<CProjectItemDoc*>(m_pDocument); }
#endif

