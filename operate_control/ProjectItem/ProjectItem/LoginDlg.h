#pragma once


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_user;
	CString m_pswd;
public:
	afx_msg void OnBnClickedLogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancle();
	virtual void OnOK();
	afx_msg void OnClose();
};
