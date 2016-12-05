#pragma once

#include "HelpView.h"
#include "resource.h"
#include <vector>
#include "Block.h"
#include "Mouse.h"



class BlockViwer {
public:
	BlockViwer() {
		mBlockArr = {
			new DoctypeTag ,
			new HtmlTag,
			new HeadTag,
			new TitleTag,
			new BodyTag,
			new DivTag,
			new HTag(1),
			new HTag(2),
			new HTag(3),
			new HTag(4),
			new HTag(5),
			new HTag(6),
			new OlTag,
			new UlTag,
			new LiTag,
			new ATag,
			new PTag,
			new BrTag,
			new InputTag,
		};


	}
	Block * OnLButtonDown(CPoint &point) {
		for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
		{
			if ((*i)->mMainBlock.PtInRect(point)) {
				return (*i);
			}
		}
		return nullptr;
	}
	Block * OnMouseMove(CPoint &point) {
		for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
		{
			if ((*i)->mMainBlock.PtInRect(point))
				return (*i);
		}
		return nullptr;

	}

	void SetSize(CRect rect) {
		mBlockSize = rect;
	}

	void initBlock() {
		int x = 0;
		int y = 0;
		int maxCount = (mBlockSize.Height() / 50);
		for (int i = 0; i < mBlockArr.size(); i++)
		{
			if (i % (maxCount) == 0 && i != 0)
			{
				x += 101;
				y = 0;
			}
			CRect rect(mBlockSize.left + x, mBlockSize.top + y, mBlockSize.left + x + 100, mBlockSize.top + y + 50);
			mBlockArr[i]->initBlock(rect);
		
			y += 51;
		}


	}
	void OnDrew(CClientDC& dc) {
		dc.Rectangle(mBlockSize);
		for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
		{
			(*i)->OnDrew(dc);
			
		}

		
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

	bool OnLButtonUp(CPoint &point) {
		mRunSize.PtInRect(point);
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
	void init() {
		initClientSize();
		blockViwer.initBlock();
		
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
	void SetmHelpView(Block &Block) {
		mWnd->UpdateData(true);
		mHelpView.SetHelper(Block);
		mWnd->UpdateData(false);
	}



	void OnLButtonDown(CPoint &point) {
		Block * rect = blockViwer.OnLButtonDown(point);
		if (rect) {
			temp = *rect;
			mouse.SetLbutton();
		}

	}
	void OnLButtonUp(CPoint &point) {
		if (runViwer.OnLButtonUp(point)) {
			mouse.SetLbutton();
		}
		

	}

	void OnMouseMove(CPoint &point) {
		Block * rect = blockViwer.OnMouseMove(point);
		if (rect)
			SetmHelpView(*rect);

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

