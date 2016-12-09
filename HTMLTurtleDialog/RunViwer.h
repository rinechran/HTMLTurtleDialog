#pragma once
#include "Block.h"
class RunViwer {
public:
	RunViwer();

	void initRunViwer();
	void SetSize(CRect rect);
	template <typename T>
	void OnDrew(T& dc);
	CString getStringHtml();
	std::vector<Block>* blockPush(CPoint &point, Block temp);
	std::vector<Block>* blockPop(CPoint &point);
	Block * FindBlock(CPoint &point);
private:

	std::vector<Block> runBlock;
	CRect mRunSize;
};

template<typename T>
void RunViwer::OnDrew(T & dc) {
	dc.Rectangle(mRunSize);
	for (auto i = runBlock.begin(); i != runBlock.end(); ++i) {
		i->OnDrew(dc);
		for (auto j = (*i).dynamicBlock.begin(); j != (*i).dynamicBlock.end(); j++) {
			j->OnDrew(dc);
		}
	}

}
