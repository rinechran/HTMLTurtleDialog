
// HTMLTurtleDialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHTMLTurtleDialogApp:
// �� Ŭ������ ������ ���ؼ��� HTMLTurtleDialog.cpp�� �����Ͻʽÿ�.
//

class CHTMLTurtleDialogApp : public CWinApp
{
public:
	CHTMLTurtleDialogApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHTMLTurtleDialogApp theApp;