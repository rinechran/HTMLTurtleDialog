#pragma once
#include "CWebBrowser2.h"


// CHtmlDlg ��ȭ �����Դϴ�.

class CHtmlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHtmlDlg)

public:
	CHtmlDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHtmlDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()

	CWebBrowser2 m_url;
	virtual BOOL OnInitDialog();
};
