
// ProjectItemView.cpp : CProjectItemView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ProjectItem.h"
#endif

#include "ProjectItemDoc.h"
#include "ProjectItemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjectItemView

IMPLEMENT_DYNCREATE(CProjectItemView, CView)

BEGIN_MESSAGE_MAP(CProjectItemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProjectItemView 构造/析构

CProjectItemView::CProjectItemView()
{
	// TODO:  在此处添加构造代码

}

CProjectItemView::~CProjectItemView()
{
}

BOOL CProjectItemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CProjectItemView 绘制

void CProjectItemView::OnDraw(CDC* /*pDC*/)
{
	CProjectItemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CProjectItemView 打印

BOOL CProjectItemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CProjectItemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CProjectItemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CProjectItemView 诊断

#ifdef _DEBUG
void CProjectItemView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectItemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectItemDoc* CProjectItemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectItemDoc)));
	return (CProjectItemDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectItemView 消息处理程序
