// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Information.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_user(_T(""))
	, m_pswd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pswd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LOGIN, &CLoginDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_CANCLE, &CLoginDlg::OnBnClickedCancle)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedLogin()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_user.IsEmpty() || m_pswd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
	//获取正确的值
	CString name, pwd;
	Information log;
	log.ReadLogin(name, pwd);
	if (m_user == name)
	{
		if (m_pswd == pwd)
		{
			CDialogEx::OnCancel();
		}
		else
		{
			MessageBox(TEXT("密码错误"));

		}
	}
	else
	{
		MessageBox(TEXT("用户名错误"));
	}

}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//CString nameStr, pwdStr;

	/*
	Information info;
	info.ReadLogin(m_user,m_pswd);
	UpdateData(FALSE);
	*/

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedCancle()
{
	// TODO:  在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);

}
