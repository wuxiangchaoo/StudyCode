// SeelDLg.cpp : 实现文件
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "SeelDLg.h"


// CSeelDLg

IMPLEMENT_DYNCREATE(CSeelDLg, CFormView)

CSeelDLg::CSeelDLg()
	: CFormView(CSeelDLg::IDD)
	, m_price(0)
	, m_sellNum(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSeelDLg::~CSeelDLg()
{
}

void CSeelDLg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_sellNum);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSeelDLg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSeelDLg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSeelDLg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSeelDLg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CSeelDLg 诊断

#ifdef _DEBUG
void CSeelDLg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSeelDLg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSeelDLg 消息处理程序


void CSeelDLg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end();it++)
	{
		m_combo.AddString(CString(it->name.c_str()));
	}
	m_combo.SetCurSel(0);

	OnCbnSelchangeCombo1();
}


void CSeelDLg::OnCbnSelchangeCombo1()
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
			m_price = it->price;
			m_sellNum= it->num;
			UpdateData(FALSE);
		}
	}
}


void CSeelDLg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_num <= 0)
	{
		MessageBox(TEXT("购买数量小于等于0"));
		return;
	}
	if (m_num >m_sellNum)
	{
		MessageBox(TEXT("购买数量不能大于库存"));
		return;
	}
	int index = m_combo.GetCurSel();
	CString name;
	m_combo.GetLBText(index, name);
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			//同步库存量
			it->num -= m_num;
			m_sellNum = it->num;

			CString str;
			str.Format(TEXT("商品:%s \r\n单价: %d\r\n个数:%d \r\n总价:%d"), name, m_price, m_num, m_price*m_num);
			m_sellInfo = str;
			UpdateData(FALSE);
			MessageBox(str);
		}
	}
	m_num = 0;
	m_sellInfo.Empty();
	UpdateData(FALSE);

	file.WriteDocline();
}


void CSeelDLg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_num = 0;
	UpdateData(FALSE);

}
