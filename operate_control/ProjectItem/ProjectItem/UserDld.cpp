// UserDld.cpp : ʵ���ļ�
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


// CUserDld ���

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


// CUserDld ��Ϣ�������


void CUserDld::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_kinds = TEXT("����Ա");

	Information info;
	CString name, pwd;
	info.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);

	// TODO:  �ڴ����ר�ô����/����û���
}


void CUserDld::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_newpwd.IsEmpty()||m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
	if (m_newpwd != m_surePwd)
	{
		MessageBox(TEXT("�������벻ͬ������������"));
		return;
	}
	Information info;
	CString name, pwd;
	info.ReadLogin(name, pwd);
	if (pwd == m_newpwd)
	{
		MessageBox(TEXT("�����벻�ܺ;�����һ��"));
		return;
	}

	CStringA tmp;
	CStringA tmp2;
	tmp = name;
	tmp2 = m_surePwd;
	info.WritePwd(tmp.GetBuffer(), tmp2.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ�"));

	m_newpwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}


void CUserDld::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_newpwd.Empty();
	m_surePwd.Empty();
	UpdateData(FALSE);
}
