// HTMLEdit.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HTMLTurtleDialog.h"
#include "HTMLEdit.h"
#include "afxdialogex.h"


// HTMLEdit ��ȭ �����Դϴ�.

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


// HTMLEdit �޽��� ó�����Դϴ�.
