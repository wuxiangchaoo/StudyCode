
// ProjectItemView.h : CProjectItemView 类的接口
//

#pragma once


class CProjectItemView : public CView
{
protected: // 仅从序列化创建
	CProjectItemView();
	DECLARE_DYNCREATE(CProjectItemView)

// 特性
public:
	CProjectItemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CProjectItemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ProjectItemView.cpp 中的调试版本
inline CProjectItemDoc* CProjectItemView::GetDocument() const
   { return reinterpret_cast<CProjectItemDoc*>(m_pDocument); }
#endif

