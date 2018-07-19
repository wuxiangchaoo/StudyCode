#pragma once
#include "afxwin.h"
#include "afxcmn.h"



// CShowGoods ������ͼ

class CShowGoods : public CFormView
{
	DECLARE_DYNCREATE(CShowGoods)

protected:
	CShowGoods();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CShowGoods();

public:
	enum { IDD = IDD_SHOW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CListBox m_list;
	CListCtrl m_listCtl;
};


