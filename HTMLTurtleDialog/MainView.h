#pragma once

#include "HelpView.h"
#include "resource.h"
#include <vector>
#include "Block.h"
#include "Mouse.h"
#include "BlockViwer.h"
#include "CustomDC.h"
#include <algorithm>

class RunViwer {
public:
	RunViwer() {
		runBlock = { EnrtyBlcok() };
	}

	void initRunViwer() {
		runBlock[0].initBlock(
			CRect(
				mRunSize.left, mRunSize.top,
				mRunSize.left + 100, mRunSize.top + 50
			)
		);
	}
	void SetSize(CRect rect) {
		mRunSize = rect;
	}
	template <typename T>
	void OnDrew(T& dc) {
		dc.Rectangle(mRunSize);
		for (auto i = runBlock.begin(); i != runBlock.end(); ++i) {
			i->OnDrew(dc);
			for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {
				j->OnDrew(dc);
			}
		}

	}

	Block recursiveSearch(std::vector<Block> &recur,CPoint &point, Block temp) {
		if (runBlock[runBlock.size() - 1].dynamicBlock.size() == 0) {
			
		}
	}

	CString&& getStringHtml() {
		CString str;
		for (auto i = runBlock.begin(); i != runBlock.end(); ++i) {
			str += i->mStartTag + L"\n";
			for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {
				
			}
		}

	}
	std::vector<Block>* blockPush(CPoint &point, Block temp) {

		auto &endBlock = runBlock[runBlock.size() - 1];

		if (endBlock.leftRect.PtInRect(point)) { //왼쪽지점..
			temp.BlockMoveXY(endBlock.leftRect.TopLeft());
			runBlock.push_back(temp);
		}
		else if (endBlock.dynamicBlock.size() != 0) { //오른쪽의 마지막...
			auto i = endBlock.dynamicBlock[endBlock.dynamicBlock.size() - 1];
			if (i.leftRect.PtInRect(point)) { //왼쪽지점..
				temp.BlockMoveXY(i.leftRect.TopLeft());
				endBlock.LeftRectPush();
				endBlock.dynamicBlock.push_back(temp);
			}
		}
		else if (endBlock.rightRect.PtInRect(point)) { //오른쪽 지점.
			temp.BlockMoveXY(endBlock.rightRect.TopLeft());
			endBlock.LeftRectPush();
			endBlock.dynamicBlock.push_back(temp);
		}


		return false;
	}
public:

	std::vector<Block> runBlock;
	CRect mRunSize;
};


class MainView
{
public:

	MainView(CWnd * wnd, CRect & mClient, HelpView helpView) :
		mWnd(wnd),
		mClientSize(mClient),
		mHelpView(helpView) {
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
		//CMemDC Cdc(dc, mWnd);
		//CCustomDC cdc(&dc);
		blockViwer.OnDrew(dc);
		runViwer.OnDrew(dc);

		if (mouse.getLbutton())
			temp.OnDrew(dc);

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



	void OnLButtonDown(CPoint &point) {
		Block * rect = blockViwer.OnLButtonDown(point);
		if (rect) {
			temp = *rect;
			mouse.SetLbutton(true);
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
	CWnd * mWnd;
	HelpView mHelpView;
	RunViwer runViwer;
	BlockViwer blockViwer;
	Mouse mouse;
};

