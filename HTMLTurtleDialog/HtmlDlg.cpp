// HtmlDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HTMLTurtleDialog.h"
#include "HtmlDlg.h"
#include "afxdialogex.h"


// CHtmlDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHtmlDlg, CDialogEx)

CHtmlDlg::CHtmlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CHtmlDlg::~CHtmlDlg()
{
}

void CHtmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_url);
}


BEGIN_MESSAGE_MAP(CHtmlDlg, CDialogEx)
END_MESSAGE_MAP()


// CHtmlDlg �޽��� ó�����Դϴ�.
BEGIN_EVENTSINK_MAP(CHtmlDlg, CDialogEx)

END_EVENTSINK_MAP()



BOOL CHtmlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CComVariant var(_T("www.naver.com"));
	m_url.Navigate2(&var, NULL, NULL, NULL, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
