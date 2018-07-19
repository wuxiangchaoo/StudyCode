#pragma once
#include "afxwin.h"
#include "Information.h"


// CSeelDLg 窗体视图

class CSeelDLg : public CFormView
{
	DECLARE_DYNCREATE(CSeelDLg)

protected:
	CSeelDLg();           // 动态创建所使用的受保护的构造函数
	virtual ~CSeelDLg();

public:
	enum { IDD = IDD_SELLL };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combo;
	int m_price;
	int m_sellNum;
	int m_num;
	CString m_sellInfo;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};


