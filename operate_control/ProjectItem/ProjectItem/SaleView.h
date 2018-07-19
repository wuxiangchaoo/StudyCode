#pragma once


// CSaleView 视图

class CSaleView : public CTreeView
{
	DECLARE_DYNCREATE(CSaleView)

protected:
	CSaleView();           // 动态创建所使用的受保护的构造函数
	virtual ~CSaleView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

private:
	CTreeCtrl *m_treectl;
	CImageList m_imageList;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


