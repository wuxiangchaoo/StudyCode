// DisplayView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "DisplayView.h"


// CDisplayView

IMPLEMENT_DYNCREATE(CDisplayView, CFormView)

CDisplayView::CDisplayView()
	: CFormView(CDisplayView::IDD)
{

}

CDisplayView::~CDisplayView()
{
}

void CDisplayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDisplayView, CFormView)
END_MESSAGE_MAP()


// CDisplayView ���

#ifdef _DEBUG
void CDisplayView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDisplayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDisplayView ��Ϣ�������
