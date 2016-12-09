#pragma once

#include "HelpView.h"
#include "resource.h"
#include <vector>
#include "Block.h"
#include "Mouse.h"
#include "BlockViwer.h"
#include "CustomDC.h"
#include <algorithm>
#include "HTMLEdit.h"
#include "RunViwer.h"

class MainView
{
public:

	MainView(CWnd * wnd, CRect & mClient, HelpView helpView,CString &RawHtml) :
		mWnd(wnd),
		mClientSize(mClient),
		mHelpView(helpView),
		mRawHtml(RawHtml){
	}
	void init() {
		initClientSize();
		blockViwer.initBlock();
		runViwer.initRunViwer();

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
				BottomRightX, mClientSize.top + mClientSize.Height()));
			topLeftX += cut;
		}
		runViwer.SetSize(viwerRect[0]);
		blockViwer.SetSize(viwerRect[1]);

	}


	void OnDrew() {
		CClientDC dc(mWnd);
		blockViwer.OnDrew(dc);
		runViwer.OnDrew(dc);
		
		if (mouse.getLbutton())
			temp.OnDrew(dc);

		mWnd->UpdateData(true);
		mRawHtml = runViwer.getStringHtml();
		mWnd->UpdateData(false);
	}


	void SetmHelpView(CString Tag, CString Explan) {
		mWnd->UpdateData(true);
		mHelpView.SetHelper(Tag, Explan);
		mWnd->UpdateData(false);
	}
	void SetmHelpView(Block &Block) {
		mWnd->UpdateData(true);
		mHelpView.SetHelper(Block);
		mWnd->UpdateData(false);
	}

	void OnRButtonDown(CPoint &point) {
		runViwer.blockPop(point);
	}



	void OnLButtonDown(CPoint &point) {
		Block * rect = blockViwer.OnLButtonDown(point); 
		if (rect) {
			temp = *rect;
			mouse.SetLbutton(true);
		}

		//처리..
		rect = runViwer.FindBlock(point);
		if (rect) {
			mWnd->UpdateData(true);
			mHTMLEdit.mTag = rect->mTag;
			mHTMLEdit.mProperty = rect->mProperty;
			mHTMLEdit.mContext = rect->mContext;
			if (mHTMLEdit.DoModal() == IDOK) {
				rect->mTag = mHTMLEdit.mTag;
				rect->mProperty = mHTMLEdit.mProperty;
				rect->mContext = mHTMLEdit.mContext;
			}
			mWnd->UpdateData(false);
		}



	}
	void OnLButtonUp(CPoint &point) {
		if (mouse.getLbutton()) {
			runViwer.blockPush(point, temp);
			temp = Block();
		}
		mouse.SetLbutton(false);

	}

	void OnMouseMove(CPoint &point) {

		Block * rect = blockViwer.OnMouseMove(point); // 마우스 이동시..
		if (rect)
			SetmHelpView(*rect);

		
		if (mouse.getLbutton()){
			if (mClientSize.PtInRect(point)) {
				temp.BlockMoveXY(point);

			}
			else {
				mouse.SetLbutton(false);
				temp = Block();
			}
		}
	}



	~MainView() {}

	CRect &mClientSize;

	Block temp; //오른쪽마우스 클릭...
	///
	CString &mRawHtml;

	HTMLEdit mHTMLEdit;
	//
	CWnd * mWnd;
	HelpView mHelpView;
	RunViwer runViwer;
	BlockViwer blockViwer;
	Mouse mouse;
};

