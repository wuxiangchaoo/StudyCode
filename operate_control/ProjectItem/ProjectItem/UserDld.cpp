// UserDld.cpp : 实现文件
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "UserDld.h"
#include "Information.h"

// CUserDld

IMPLEMENT_DYNCREATE(CUserDld, CFormView)

CUserDld::CUserDld()
	: CFormView(CUserDld::IDD)
	, m_kinds(_T(""))
	, m_name(_T(""))
	, m_newpwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDld::~CUserDld()
{
}

void CUserDld::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kinds);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newpwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDld, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDld::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDld::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserDld 诊断

#ifdef _DEBUG
void CUserDld::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDld::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDld 消息处理程序


void CUserDld::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_kinds = TEXT("销售员");

	Information info;
	CString name, pwd;
	info.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);

	// TODO:  在此添加专用代码和/或调用基类
}


void CUserDld::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_newpwd.IsEmpty()||m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
	if (m_newpwd != m_surePwd)
	{
		MessageBox(TEXT("两次密码不同，请重新输入"));
		return;
	}
	Information info;
	CString name, pwd;
	info.ReadLogin(name, pwd);
	if (pwd == m_newpwd)
	{
		MessageBox(TEXT("新密码不能和旧密码一样"));
		return;
	}

	CStringA tmp;
	CStringA tmp2;
	tmp = name;
	tmp2 = m_surePwd;
	info.WritePwd(tmp.GetBuffer(), tmp2.GetBuffer());
	MessageBox(TEXT("修改成功"));

	m_newpwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}


void CUserDld::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_newpwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}
