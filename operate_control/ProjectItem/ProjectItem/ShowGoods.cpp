// ShowGoods.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "ShowGoods.h"
#include "Information.h"


// CShowGoods

IMPLEMENT_DYNCREATE(CShowGoods, CFormView)

CShowGoods::CShowGoods()
	: CFormView(CShowGoods::IDD)
{

}

CShowGoods::~CShowGoods()
{
}

void CShowGoods::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LISTGOODS, m_list);
	DDX_Control(pDX, IDC_LIST, m_listCtl);
}

BEGIN_MESSAGE_MAP(CShowGoods, CFormView)
END_MESSAGE_MAP()


// CShowGoods ���

#ifdef _DEBUG
void CShowGoods::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CShowGoods::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CShowGoods ��Ϣ�������


void CShowGoods::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO:  �ڴ����ר�ô����/����û���

	CString heads[] = { TEXT("��ƷID"),TEXT("��Ʒ��"), TEXT("��Ʒ����"), TEXT("���") };
	for (int i = 0; i < 4; ++i)
	{
		m_listCtl.InsertColumn(i, heads[i], LVCFMT_LEFT, 100);
	}
	Information file;
	file.ReadDocline();
	int i = 0;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int j = 0;
		CString str;
		str.Format(TEXT("%d"), it->id);
		m_listCtl.InsertItem(i, str);
		str= CString(it->name.c_str());
		m_listCtl.SetItemText(i, ++j, str);
		str.Format(TEXT("%d"), it->price);
		m_listCtl.SetItemText(i, ++j, str);
		str.Format(TEXT("%d"), it->num);
		m_listCtl.SetItemText(i, ++j, str);
		i++;
	}
	m_listCtl.SetExtendedStyle(m_listCtl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
}
