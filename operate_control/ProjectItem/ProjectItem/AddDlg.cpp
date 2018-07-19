// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProjectItem.h"
#include "AddDlg.h"
#include "Information.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(CAddDlg::IDD)
	, m_price1(0)
	, m_num1(0)
	, m_name2(_T(""))
	, m_price2(0)
	, m_num2(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Text(pDX, IDC_EDIT1, m_price1);
	DDX_Text(pDX, IDC_EDIT2, m_num1);
	DDX_Text(pDX, IDC_EDIT3, m_name2);
	DDX_Text(pDX, IDC_EDIT4, m_price2);
	DDX_Text(pDX, IDC_EDIT5, m_num2);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAddDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAddDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combox.AddString(CString(it->name.c_str()));
	}
	m_combox.SetCurSel(0);

	OnCbnSelchangeCombo1();
}


void CAddDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int index = m_combox.GetCurSel();
	CString name;
	m_combox.GetLBText(index, name);
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ((CString)it->name.c_str() == name)
		{
			m_price1 = it->price;
			UpdateData(FALSE);
		}
	}
}

//���
void CAddDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if (m_num1 <= 0)
	{
		MessageBox(TEXT("�����������С�ڵ���0"));
		return;
	}

	int index = m_combox.GetCurSel();
	CString name;
	m_combox.GetLBText(index, name);
	Information file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str() )== name)
		{
			it->num += m_num1;
			m_num1 = 0;
			UpdateData(FALSE);
			MessageBox(TEXT("��ӳɹ�"));
		}
	}
	file.WriteDocline();
}


void CAddDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_num1 = 0;
	UpdateData(FALSE);
}

//�������Ʒ
void CAddDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_name2.IsEmpty()) 
	{
		MessageBox(TEXT("��Ʒ������Ϊ��"));
		return;
	}
	if (m_price2 <= 0)
	{
		MessageBox(TEXT("���۲���С�ڵ���0"));
		return;
	}
	if (m_num2 <=0)
	{
		MessageBox(TEXT("��Ʒ��������С�ڵ���0"));
		return;
	}
	Information file;
	file.ReadDocline();

	file.Addline(m_name2,  m_num2,m_price2);
	file.WriteDocline();
	MessageBox(TEXT("�������Ʒ�ɹ�"));

	//ͬ����������
	m_combox.InsertString(0, m_name2);
	m_combox.SetCurSel(0);
	OnCbnSelchangeCombo1();

	m_name2.Empty();
	m_price2 = 0;
	m_num2 = 0;
	UpdateData(FALSE);

}


void CAddDlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_name2.Empty();
	m_price2 = 0;
	m_num2 = 0;
	UpdateData(FALSE);
}
