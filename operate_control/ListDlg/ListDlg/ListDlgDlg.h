
// ListDlgDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CListDlgDlg �Ի���
class CListDlgDlg : public CDialogEx
{
// ����
public:
	CListDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LISTDLG_DIALOG };

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
	CComboBox m_cbx;
	afx_msg void OnCbnSelchangeCombo1();
};
