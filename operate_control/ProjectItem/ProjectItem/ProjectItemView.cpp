
// ProjectItemView.cpp : CProjectItemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CProjectItemView ����/����

CProjectItemView::CProjectItemView()
{
	// TODO:  �ڴ˴���ӹ������

}

CProjectItemView::~CProjectItemView()
{
}

BOOL CProjectItemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CProjectItemView ����

void CProjectItemView::OnDraw(CDC* /*pDC*/)
{
	CProjectItemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CProjectItemView ��ӡ

BOOL CProjectItemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CProjectItemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CProjectItemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CProjectItemView ���

#ifdef _DEBUG
void CProjectItemView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectItemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectItemDoc* CProjectItemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectItemDoc)));
	return (CProjectItemDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectItemView ��Ϣ�������
