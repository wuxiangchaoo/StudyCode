// Delete.cpp : ʵ���ļ�
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


// CDelete ���

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


// CDelete ��Ϣ�������


void CDelete::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
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
			m_sellNum = it->num;
			UpdateData(FALSE);
		}
	}
}


void CDelete::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("ɾ����������С�ڵ���0"));
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
				MessageBox(TEXT("ɾ���������������"));
				return;
			}
			
			//�д���������Ϊ0ʱ�����

			if (0 == it->num)
			{
				list<msg>::iterator pos;
				pos = it;
				  --it;
				file.ls.erase(pos);
			  
			}
			

			m_num = 0;
			UpdateData(FALSE);
			MessageBox(TEXT("ɾ���ɹ�"));
		}
	}
	file.WriteDocline();
}
