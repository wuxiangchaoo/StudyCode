
// domodalDlg.h : ͷ�ļ�
//
#include "Show.h"

#pragma once


// CdomodalDlg �Ի���
class CdomodalDlg : public CDialogEx
{
// ����
public:
	CdomodalDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DOMODAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
