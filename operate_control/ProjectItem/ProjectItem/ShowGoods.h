#pragma once
#include "afxwin.h"
#include "afxcmn.h"



// CShowGoods 窗体视图

class CShowGoods : public CFormView
{
	DECLARE_DYNCREATE(CShowGoods)

protected:
	CShowGoods();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CListBox m_list;
	CListCtrl m_listCtl;
};


