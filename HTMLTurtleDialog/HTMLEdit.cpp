// HTMLEdit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HTMLTurtleDialog.h"
#include "HTMLEdit.h"
#include "afxdialogex.h"


// HTMLEdit 대화 상자입니다.

IMPLEMENT_DYNAMIC(HTMLEdit, CDialogEx)

HTMLEdit::HTMLEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, mTag(_T(""))
	, mProperty(_T(""))
	, mContext(_T(""))
{

}

HTMLEdit::~HTMLEdit()
{
}

void HTMLEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_mTag, mTag);
	DDX_Text(pDX, IDC_EDIT1, mProperty);
	DDX_Text(pDX, IDC_EDIT2, mContext);
}


BEGIN_MESSAGE_MAP(HTMLEdit, CDialogEx)
END_MESSAGE_MAP()


// HTMLEdit 메시지 처리기입니다.
