#pragma once


// CDlgExec �Ի���

class CDlgExec : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgExec)

public:
	CDlgExec(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgExec();

// �Ի�������
	enum { IDD = IDD_EXEC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
