#pragma once
#include "Block.h"

class HelpView {
public:
	HelpView(CString &  tag, CString &  Explan) : mTag(tag), mExplan(Explan) {
	}


	void setTag(CString &str) {
		mTag = str;
	}

	void setExplan(CString &str) {
		mExplan = str;
	}

	void SetHelper(CString &Tag, CString &Explan) {
		setExplan(Explan);
		setTag(Tag);
	}
	void SetHelper(Block & block) {
		setExplan(block.mTag);
		setTag(block.Help);
	}

	

private:
	CString &mTag;
	CString &mExplan;
};