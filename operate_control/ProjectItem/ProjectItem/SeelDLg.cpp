// SeelDLg.cpp : ʵ���ļ�
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


// CSeelDLg ���

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


// CSeelDLg ��Ϣ�������


void CSeelDLg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num <= 0)
	{
		MessageBox(TEXT("��������С�ڵ���0"));
		return;
	}
	if (m_num >m_sellNum)
	{
		MessageBox(TEXT("�����������ܴ��ڿ��"));
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
			//ͬ�������
			it->num -= m_num;
			m_sellNum = it->num;

			CString str;
			str.Format(TEXT("��Ʒ:%s \r\n����: %d\r\n����:%d \r\n�ܼ�:%d"), name, m_price, m_num, m_price*m_num);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num = 0;
	UpdateData(FALSE);

}
