#pragma once
#include "CWebBrowser2.h"


// CHtmlDlg 대화 상자입니다.

class CHtmlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHtmlDlg)

public:
	CHtmlDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHtmlDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()

	CWebBrowser2 m_url;
	virtual BOOL OnInitDialog();
};
