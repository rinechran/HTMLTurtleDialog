
// HTMLTurtleDialogDlg.h : ��� ����
//

#pragma once
#include "MainView.h"




// CHTMLTurtleDialogDlg ��ȭ ����
class CHTMLTurtleDialogDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHTMLTurtleDialogDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HTMLTURTLEDIALOG_DIALOG };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�	
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	MainView mainview;

	//HelpView member
	CString mTag;
	CString mTagExplan;
	CRect mClientSize;

	//

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedComplete();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
