
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "ProjectItem.h"

#include "MainFrm.h"
#include "Information.h"
#include "SaleView.h"
#include "DisplayView.h"
#include "UserDld.h"
#include "SeelDLg.h"
#include "AddDlg.h"
#include "ShowGoods.h"
#include "Delete.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()

	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//����ͼ��
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_WUMAN));

	//���ñ���
	SetTitle(TEXT("2018/04/02"));

	//���ô��ڴ�С
	MoveWindow(0, 0, 800, 500);

	//���ھ���
	CenterWindow();


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	m_spliter.CreateStatic(this, 1, 2);

	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSaleView), CSize(200, 500), pContext);
	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);
	return TRUE;//�Լ����

}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext context;
	if (wParam == NM_A)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CUserDld);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDld), CSize(600, 500), &context);
		CUserDld *pNewView = (CUserDld *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_B)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSeelDLg);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CSeelDLg), CSize(600, 500), &context);
		CSeelDLg *pNewView = (CSeelDLg  *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam ==NM_C )
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CShowGoods);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CShowGoods), CSize(600, 500), &context);
		CShowGoods *pNewView = (CShowGoods  *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_D)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 500), &context);
		CAddDlg *pNewView = (CAddDlg  *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_E)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CDelete);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDelete), CSize(600, 500), &context);
		CDelete *pNewView = (CDelete  *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	return 0;
}

void CMainFrame::On32771()
{
	// TODO:  �ڴ���������������
	exit(0);
}


void CMainFrame::On32772()
{
	// TODO:  �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);

}


void CMainFrame::On32773()
{
	// TODO:  �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CMainFrame::On32774()
{
	// TODO:  �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CMainFrame::On32775()
{
	// TODO:  �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
}


void CMainFrame::On32776()
{
	// TODO:  �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
}
