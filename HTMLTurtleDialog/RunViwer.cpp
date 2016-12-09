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
		str += i->mStartTag + " " + i->mProperty + L" \n"; // ���� �±�
		str += i->mContext;
		for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {
			str += j->mStartTag + " " + j->mProperty + L" \n"; // ���� �±�
			str += j->mContext;
			str += j->mEndTag + L" \n"; //�� �±�
		}
		str += i->mEndTag + L" \n"; //�� �±�
	}
	return str;

}

std::vector<Block>* RunViwer::blockPush(CPoint & point, Block temp) {

	auto &endBlock = runBlock[runBlock.size() - 1];

	if (endBlock.leftRect.PtInRect(point)) { //��������..
		temp.BlockMoveXY(endBlock.leftRect.TopLeft());
		runBlock.push_back(temp);
	}
	else if (endBlock.dynamicBlock.size() != 0) { //�������� ������...
		auto i = endBlock.dynamicBlock[endBlock.dynamicBlock.size() - 1];
		if (i.leftRect.PtInRect(point)) { //��������..
			temp.BlockMoveXY(i.leftRect.TopLeft());
			endBlock.LeftRectPush();
			endBlock.dynamicBlock.push_back(temp);
		}
	}
	else if (endBlock.rightRect.PtInRect(point)) { //������ ����.
		temp.BlockMoveXY(endBlock.rightRect.TopLeft());
		endBlock.LeftRectPush();
		endBlock.dynamicBlock.push_back(temp);
	}

	return false;
}

std::vector<Block>* RunViwer::blockPop(CPoint & point) {

	auto &endBlock = runBlock[runBlock.size() - 1];

	if (endBlock.mMainBlock.PtInRect(point)) { //��������..
		runBlock.pop_back();
	}
	else if (endBlock.dynamicBlock.size() != 0) { //�������� ������...
		auto i = endBlock.dynamicBlock[endBlock.dynamicBlock.size() - 1];
		if (i.mMainBlock.PtInRect(point)) { //��������..
			endBlock.LeftRectPop();
			endBlock.dynamicBlock.pop_back();
		}
	}
	else if (endBlock.mMainBlock.PtInRect(point)) { //������ ����.
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
