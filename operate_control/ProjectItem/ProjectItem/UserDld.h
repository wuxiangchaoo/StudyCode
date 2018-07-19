#pragma once



// CUserDld 窗体视图

class CUserDld : public CFormView
{
	DECLARE_DYNCREATE(CUserDld)

protected:
	CUserDld();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserDld();

public:
	enum { IDD = IDD_DIALOG1 };
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
	CString m_kinds;
	CString m_name;
	CString m_newpwd;
	CString m_surePwd;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


