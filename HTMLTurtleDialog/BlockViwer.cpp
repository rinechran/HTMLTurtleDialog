#include "stdafx.h"
#include "BlockViwer.h"

BlockViwer::BlockViwer() {
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

Block * BlockViwer::OnLButtonDown(CPoint & point) {
	for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
	{
		if ((*i)->mMainBlock.PtInRect(point)) {
			return (*i);
		}
	}
	return nullptr;
}

Block * BlockViwer::OnMouseMove(CPoint & point) {
	for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
	{
		if ((*i)->mMainBlock.PtInRect(point))
			return (*i);
	}
	return nullptr;

}

void BlockViwer::SetSize(CRect rect) {
	mBlockSize = rect;
}

void BlockViwer::initBlock() {
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
