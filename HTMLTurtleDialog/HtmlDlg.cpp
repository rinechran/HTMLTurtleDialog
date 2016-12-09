// HtmlDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HTMLTurtleDialog.h"
#include "HtmlDlg.h"
#include "afxdialogex.h"


// CHtmlDlg 대화 상자입니다.

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


// CHtmlDlg 메시지 처리기입니다.
BEGIN_EVENTSINK_MAP(CHtmlDlg, CDialogEx)

END_EVENTSINK_MAP()



BOOL CHtmlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	TCHAR szTemp[300];
	::GetModuleFileName(NULL, szTemp, 300);
	CString path = szTemp;
	if (0 < path.ReverseFind('\\')) {
		path = path.Left(path.ReverseFind('\\'));
	}

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CComVariant var(path+ L"\\temp.html");
	m_url.Navigate2(&var, NULL, NULL, NULL, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
