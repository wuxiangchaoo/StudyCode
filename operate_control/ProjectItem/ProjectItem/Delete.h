#pragma once
#include "afxwin.h"



// CDelete 窗体视图

class CDelete : public CFormView
{
	DECLARE_DYNCREATE(CDelete)

protected:
	CDelete();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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


