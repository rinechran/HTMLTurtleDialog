#pragma once


// HTMLEdit ��ȭ �����Դϴ�.

class HTMLEdit : public CDialogEx
{
	DECLARE_DYNAMIC(HTMLEdit)

public:
	HTMLEdit(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~HTMLEdit();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString mTag;
	CString mProperty;
	CString mContext;
};
