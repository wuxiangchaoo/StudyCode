
// Treectl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTreectlApp: 
// �йش����ʵ�֣������ Treectl.cpp
//

class CTreectlApp : public CWinApp
{
public:
	CTreectlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTreectlApp theApp;