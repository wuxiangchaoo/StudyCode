#pragma once
#include "afxwin.h"



// CDelete ������ͼ

class CDelete : public CFormView
{
	DECLARE_DYNCREATE(CDelete)

protected:
	CDelete();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDelete();

public:
	enum { IDD = IDD_DELETE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combo;
	int m_sellNum;
	int m_num;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};


