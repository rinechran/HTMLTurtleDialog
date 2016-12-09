#pragma once
#pragma once
#include "Block.h"
class BlockViwer {
public:
	BlockViwer();
	Block * OnLButtonDown(CPoint &point);
	Block * OnMouseMove(CPoint &point);

	void SetSize(CRect rect);

	void initBlock();
	template <typename T>
	void OnDrew(T& dc);

	CRect mBlockSize;
	std::vector<Block*> mBlockArr;
};


template<typename T>
void BlockViwer::OnDrew(T & dc) {
	dc.Rectangle(mBlockSize);
	for (auto i = mBlockArr.begin(); i < mBlockArr.end(); i++)
	{
		(*i)->OnDrew(dc);

	}


}
