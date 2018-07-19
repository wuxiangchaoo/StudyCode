
// domodalDlg.h : 头文件
//
#include "Show.h"

#pragma once


// CdomodalDlg 对话框
class CdomodalDlg : public CDialogEx
{
// 构造
public:
	CdomodalDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DOMODAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

private:
	CShow dlg;
public:
	afx_msg void OnBnClickedButton2();
};
