#pragma once

#include "HelpView.h"
#include "resource.h"
#include <vector>
#include "Block.h"





class BlockViwer {
public:
	BlockViwer() {
		mBlockArr = {
			new DoctypeTag ,
			new HtmlTag,
			new BodyTag,
			//new HTag 
			new DivTag,
			new OlTag,
			new UlTag,
			new LiTag,
			new ATag,
			new PTag,
			new BrTag,
			new InputTag,
		};


	}


	void SetSize(CRect rect) {
		mBlockSize = rect;
	}
	void OnDrew(CClientDC& dc) {


		dc.Rectangle(mBlockSize);
	}

	CRect mBlockSize;
	std::vector<Block*> mBlockArr;
};
class RunViwer {
public:
	RunViwer() {

	}
	void SetSize(CRect rect){
		mRunSize = rect;
	}
	void OnDrew(CClientDC& dc) {
		dc.Rectangle(mRunSize);
	}

	Block * OnMouseMove(CPoint &point) {
		return nullptr;
	}
public:

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
		runViwer.SetSize(viwerRect[0]);
		blockViwer.SetSize(viwerRect[1]);
	
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

