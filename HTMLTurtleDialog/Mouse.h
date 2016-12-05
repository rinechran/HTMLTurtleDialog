#pragma once

class Mouse {
public:
	Mouse();
	bool getLbutton();
	bool getRbutton();
	void SetRbutton();
	void SetLbutton();


private:

	bool mIsLbutton;
	bool mIsRbutton;
};
