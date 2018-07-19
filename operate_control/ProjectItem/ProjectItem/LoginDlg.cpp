// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Information.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedLogin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_user.IsEmpty() || m_pswd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
	//��ȡ��ȷ��ֵ
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
			MessageBox(TEXT("�������"));

		}
	}
	else
	{
		MessageBox(TEXT("�û�������"));
	}

}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//CString nameStr, pwdStr;

	/*
	Information info;
	info.ReadLogin(m_user,m_pswd);
	UpdateData(FALSE);
	*/

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnBnClickedCancle()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CLoginDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CDialogEx::OnClose();
	exit(0);

}
