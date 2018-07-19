// Delete.cpp : 实现文件
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "Delete.h"
#include "Information.h"


// CDelete

IMPLEMENT_DYNCREATE(CDelete, CFormView)

CDelete::CDelete()
	: CFormView(CDelete::IDD)
	, m_sellNum(0)
	, m_num(0)
{

}

CDelete::~CDelete()
{
}

void CDelete::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_sellNum);
	DDX_Text(pDX, IDC_EDIT2, m_num);
}

BEGIN_MESSAGE_MAP(CDelete, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelete::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelete::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDelete 诊断

#ifdef _DEBUG
void CDelete::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelete::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelete 消息处理程序


void CDelete::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}
	m_combo.SetCurSel(0);

	OnCbnSelchangeCombo1();
}


void CDelete::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			m_sellNum = it->num;
			UpdateData(FALSE);
		}
	}
}


void CDelete::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("删除数量不能小于等于0"));
		return;
	}

	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		if (CString(it->name.c_str()) == name)
		{
			it->num -= m_num;
			m_sellNum = it->num;
			if (it->num < 0)
			{
				MessageBox(TEXT("删除的数量超过库存"));
				return;
			}
			
			//有待解决，库存为0时的情况

			if (0 == it->num)
			{
				list<msg>::iterator pos;
				pos = it;
				  --it;
				file.ls.erase(pos);
			  
			}
			

			m_num = 0;
			UpdateData(FALSE);
			MessageBox(TEXT("删除成功"));
		}
	}
	file.WriteDocline();
}
