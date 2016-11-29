#pragma once

#include "HelpView.h"
#include "resource.h"
#include <vector>
#include "Block.h"



class BlockViwer {
public:
	void SetSize(CRect rect) {
		mBlockSize = rect;
	}
	void OnDrew(CClientDC& dc) {

		dc.Rectangle(mBlockSize);
	}

	CRect mBlockSize;
};
class RunViwer {
public:
	RunViwer() {
		a.push_back(Block({ L"IMG",L"IMG HELP"}));
		a.push_back(Block({ L"SRC",L"SRC HELP" }));
	}
	void SetSize(CRect rect){
		mRunSize = rect;
	}
	void OnDrew(CClientDC& dc) {
		dc.Rectangle(mRunSize);
		a[0].rect.SetRect(mRunSize.left, mRunSize.top, mRunSize.left + 100, mRunSize.top + 100);
		dc.Rectangle(a[0].rect);
		a[1].rect.SetRect(mRunSize.left + 100, mRunSize.top + 100, mRunSize.left + 200, mRunSize.top + 200);
		dc.Rectangle(a[1].rect);
	}

	Block * OnMouseMove(CPoint &point) {
		for (auto i = a.begin(); i != a.end(); i++) {
			if (i->rect.PtInRect(point)) {
				return &(*i);
			}
		}
		return nullptr;
	}
public:

	std::vector<Block> a;
	CRect mRunSize;
};
class MainView
{
public:
	MainView(CWnd * wnd,CRect & mClient, HelpView helpView) :
		mWnd(wnd),
		mClientSize(mClient),
		mHelpView(helpView) {
	}

	void initClientSize() {
		mWnd->GetDlgItem(IDC_RUN_ANI)->GetWindowRect(&mClientSize);
		mWnd->ScreenToClient(&mClientSize);

		std::vector<CRect> viwerRect;
		int topLeftX = mClientSize.left;
		int BottomRightX = mClientSize.left;
		unsigned int cut = mClientSize.Width() / 2;
		for (auto i = 0; i < 2; ++i) {
			BottomRightX += cut;
			viwerRect.push_back(CRect(topLeftX, mClientSize.top, 
				BottomRightX, mClientSize.top+mClientSize.Height()));
			topLeftX += cut;
		}
		blockViwer.SetSize(viwerRect[0]);
		runViwer.SetSize(viwerRect[1]);
	}
	

	void OnDrew() {
		CClientDC dc(mWnd);

		blockViwer.OnDrew(dc);

		runViwer.OnDrew(dc);

	}


	void SetmHelpView(CString Tag, CString Explan) {
		mWnd->UpdateData(true);
		mHelpView.SetHelper(Tag, Explan);
		mWnd->UpdateData(false);
	}
	void SetmHelpView(Block Block) {
		mWnd->UpdateData(true);
		mHelpView.SetHelper(Block);
		mWnd->UpdateData(false);
	}

	void OnLButtonDown(CPoint &point) {


	}

	void OnMouseMove(CPoint &point) {
		Block * rect = runViwer.OnMouseMove(point);
		if (rect)
			SetmHelpView(*rect);

	}

	~MainView() {}


	


	CRect &mClientSize;
///
	CWnd * mWnd;
	HelpView mHelpView;
	RunViwer runViwer;
	BlockViwer blockViwer;
};

