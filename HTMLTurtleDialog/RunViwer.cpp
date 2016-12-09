#include "stdafx.h"
#include "RunViwer.h"

RunViwer::RunViwer() {
	runBlock = { EnrtyBlcok() };
}

void RunViwer::initRunViwer() {
	runBlock[0].initBlock(
		CRect(
			mRunSize.left, mRunSize.top,
			mRunSize.left + 100, mRunSize.top + 50
		)
	);
}

void RunViwer::SetSize(CRect rect) {
	mRunSize = rect;
}

CString RunViwer::getStringHtml() {
	CString str;
	for (auto i = runBlock.begin() + 1; i != runBlock.end(); ++i) {
		str += i->mStartTag + " " + i->mProperty + L" \n"; // 시작 태그
		str += i->mContext;
		for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {
			str += j->mStartTag + " " + j->mProperty + L" \n"; // 시작 태그
			str += j->mContext;
			str += j->mEndTag + L" \n"; //끝 태그
		}
		str += i->mEndTag + L" \n"; //끝 태그
	}
	return str;

}

std::vector<Block>* RunViwer::blockPush(CPoint & point, Block temp) {

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

std::vector<Block>* RunViwer::blockPop(CPoint & point) {

	auto &endBlock = runBlock[runBlock.size() - 1];

	if (endBlock.mMainBlock.PtInRect(point)) { //왼쪽지점..
		runBlock.pop_back();
	}
	else if (endBlock.dynamicBlock.size() != 0) { //오른쪽의 마지막...
		auto i = endBlock.dynamicBlock[endBlock.dynamicBlock.size() - 1];
		if (i.mMainBlock.PtInRect(point)) { //왼쪽지점..
			endBlock.LeftRectPop();
			endBlock.dynamicBlock.pop_back();
		}
	}
	else if (endBlock.mMainBlock.PtInRect(point)) { //오른쪽 지점.
		endBlock.LeftRectPop();
		endBlock.dynamicBlock.pop_back();
	}

	return false;
}

Block * RunViwer::FindBlock(CPoint & point) {
	if (runBlock.size() == 1)
		return nullptr;
	for (auto i = runBlock.begin() + 1; i != runBlock.end(); ++i) {

		if (i->mMainBlock.PtInRect(point))
			return &(*i);
		for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {

			if (j->mMainBlock.PtInRect(point))
				return &(*j);
		}
	}
	return nullptr;
}
