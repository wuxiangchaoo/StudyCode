
// ProjectItem.h : ProjectItem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CProjectItemApp:
// �йش����ʵ�֣������ ProjectItem.cpp
//

class CProjectItemApp : public CWinApp
{
public:
	CProjectItemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectItemApp theApp;
