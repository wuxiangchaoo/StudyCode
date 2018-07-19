// SaleView.cpp : 实现文件
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


// CSaleView 诊断

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


// CSaleView 消息处理程序


void CSaleView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	m_treectl = &GetTreeCtrl();

	HICON icon = AfxGetApp()->LoadIconW(IDI_DOG);
	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
	m_imageList.Add(icon);

	m_treectl->SetImageList(&m_imageList, TVSIL_NORMAL);

	m_treectl->InsertItem(TEXT("个人信息"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("销售管理"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("库存管理"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("库存添加"), 0, 0, NULL);
	m_treectl->InsertItem(TEXT("库存删除"), 0, 0, NULL);


}


void CSaleView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	//获取当前选择项
	HTREEITEM item = m_treectl->GetSelectedItem();

	CString str = m_treectl->GetItemText(item);
	//MessageBox(str);
	if (str == TEXT("个人信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("销售管理"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (str == TEXT("库存管理"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("库存添加"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (str == TEXT("库存删除"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
