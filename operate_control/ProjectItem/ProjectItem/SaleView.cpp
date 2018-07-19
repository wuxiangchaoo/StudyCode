// SaleView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "SaleView.h"
#include "MainFrm.h"


// CSaleView

IMPLEMENT_DYNCREATE(CSaleView, CTreeView)

CSaleView::CSaleView()
{

}

CSaleView::~CSaleView()
{
}

BEGIN_MESSAGE_MAP(CSaleView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSaleView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSaleView ���

#ifdef _DEBUG
void CSaleView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSaleView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSaleView ��Ϣ�������


void CSaleView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	m_treectl = &GetTreeCtrl();

	HICON icon = AfxGetApp()->LoadIconW(IDI_DOG);
	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
	m_imageList.Add(icon);

	m_treectl->SetImageList(&m_imageList, TVSIL_NORMAL);

	m_treectl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("���۹���"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("������"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);


}


void CSaleView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//��ȡ��ǰѡ����
	HTREEITEM item = m_treectl->GetSelectedItem();

	CString str = m_treectl->GetItemText(item);
	//MessageBox(str);
	if (str == TEXT("������Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("���۹���"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
